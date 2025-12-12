#include "SymbolTable.h"
#include <array>
#include <boost/regex.hpp>
#include <string>
#include <unordered_map>
#include <vector>
#if defined(DEBUG)
#include <iostream>
#endif

// ==========================================
//           OS-Specific Includes
// ==========================================
#if defined(_WIN32)
#include <windows.h>
#elif defined(__APPLE__)
#include <fcntl.h>
#include <libkern/OSByteOrder.h>  // For endian swapping
#include <mach-o/fat.h>
#include <mach-o/loader.h>
#include <mach-o/nlist.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#elif defined(__linux__)
#include <elf.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#endif

using SymbolStorage = std::vector<Symbol>;
using SymbolTable = std::unordered_map<StringView, Symbol&, HashStringView>;

// Check if text starts with any of the given prefixes
[[maybe_unused]]
static bool starts_with_any(StringView text, std::initializer_list<StringView> prefixes) noexcept {
    for (auto prefix : prefixes) {
        if (text.starts_with(prefix)) {
            return true;
        }
    }
    return false;
}

static bool is_space_char(char c) noexcept {
    return c == '\t' || c == '\n' || c == '\v' ||
           c == '\f' || c == '\r' || c == ' ';
}

static bool is_word_char(char c) noexcept {
    return (c >= 'a' && c <= 'z') ||
           (c >= 'A' && c <= 'Z') ||
           (c >= '0' && c <= '9') ||
           c == '_' || c == ':' || c == '~';
}

/**
 * Simple pattern matching function (non-regex)
 * Checks if the source string matches the sequence of tokens defined in the query.
 * Rules:
 * 1. Tokens are words ([0-9a-zA-Z_:~]+) or single non-space characters.
 * 2. Spaces are ignored/delimiters.
 * 3. '^' at start: First token must match the start of source.
 * 4. '$' at end: Last token must match the end of source.
 * 5. Tokens must appear in order (non-overlapping).
 */
static bool simpleMatch(StringView source, StringView query) noexcept {
    if (query.empty())
        return true;

    const size_t qLen = query.length();
    size_t qIdx = 0;

    // Check Anchors
    bool anchorStart = false;
    bool anchorEnd = false;
    size_t effectiveQLen = qLen;
    if (qLen > 0 && query[0] == '^') {
        anchorStart = true;
        qIdx = 1;
    }
    if (qLen > qIdx && query[qLen - 1] == '$') {
        anchorEnd = true;
        effectiveQLen--;
    }

    size_t sIdx = 0;  // Source Index
    const size_t sLen = source.length();
    bool isFirstToken = true;
    while (qIdx < effectiveQLen) {
        while (qIdx < effectiveQLen && is_space_char(query[qIdx])) {
            qIdx++;
        }
        if (qIdx == effectiveQLen)
            break;
        size_t tokStart = qIdx;
        if (is_word_char(query[qIdx])) {
            qIdx++;
            while (qIdx < effectiveQLen) {
                if (!is_word_char(query[qIdx]))
                    break;
                qIdx++;
            }
        } else {
            qIdx++;
        }
        size_t tokLen = qIdx - tokStart;
        bool isLastToken = (anchorEnd && qIdx == effectiveQLen);
        if (anchorEnd && !isLastToken) {
            // Edge case: query might be "word1 word2 $".
            // We just consumed "word1". qIdx is at space.
            // We need to peek to see if only spaces remain.
            size_t temp = qIdx;
            while (temp < effectiveQLen && is_space_char(query[temp]))
                temp++;
            if (temp == effectiveQLen)
                isLastToken = true;
        }
        if (isFirstToken && anchorStart) {
            if (sIdx + tokLen > sLen)
                return false;
            // Compare substring directly
            if (source.compare(sIdx, tokLen, query, tokStart, tokLen) != 0)
                return false;
            sIdx += tokLen;
        } else if (isLastToken) {  // implicitly && anchorEnd due to bool definition above
            if (tokLen > sLen)
                return false;
            size_t matchPos = sLen - tokLen;
            if (matchPos < sIdx)
                return false;  // Overlap check
            if (source.compare(matchPos, tokLen, query, tokStart, tokLen) != 0)
                return false;
            return true;
        } else {
            size_t foundPos = 0;
            if (tokLen == 1) {
                foundPos = source.find(query[tokStart], sIdx);
            } else {
                foundPos = source.find(&query[tokStart], sIdx, tokLen);
            }
            if (foundPos == StringView::npos)
                return false;
            sIdx = foundPos + tokLen;
        }
        isFirstToken = false;
    }
    return true;
}

static SymbolStorage sortSymbols(SymbolStorage&& symbols) noexcept {
    if (symbols.empty()) {
        return symbols;
    }
    std::sort(symbols.begin(), symbols.end(), [](const Symbol& a, const Symbol& b) noexcept {
        if (a.address == b.address) {
            return a.name < b.name;
        }
        return a.address < b.address;
    });
#ifndef SYMBOL_TABLE_CPP_USE_REAL_SIZE
    auto n = static_cast<std::ptrdiff_t>(symbols.size());
    symbols[n - 1].size = -1;  // Size unknown for last symbol
    for (std::ptrdiff_t i = n - 2; i >= 0; --i) {
        if (symbols[i].address != symbols[i + 1].address) {
            symbols[i].size = symbols[i + 1].address - symbols[i].address;
        } else {
            symbols[i].size = symbols[i + 1].size;
        }
    }
#endif
    return symbols;
}

static SymbolTable toTable(SymbolStorage& symbols) {
    SymbolTable symbolTable{};
    for (auto& sym : symbols) {
        const auto& name = sym.name;
        auto result = symbolTable.emplace(StringView{name.data(), name.size()}, sym);
        if (!result.second) {
            auto& existingSym = result.first->second;
            if (existingSym.address != sym.address) {
                existingSym.ambiguous = true;
            }
        }
    }
    for (auto& sym : symbols) {
        const auto& name = sym.name;
        auto it = symbolTable.find(StringView{name.data(), name.size()});
        if (it != symbolTable.end() && it->second.ambiguous) {
            sym.ambiguous = true;
        }
    }
    return symbolTable;
}

static SymbolTable toTableDemangled(SymbolStorage& symbols) {
    SymbolTable symbolTable{};
    for (auto& sym : symbols) {
        const auto& name = sym.demangled;
        auto result = symbolTable.emplace(StringView{name.data(), name.size()}, sym);
        if (!result.second) {
            auto& existingSym = result.first->second;
            if (existingSym.address != sym.address) {
                existingSym.ambiguous_demangle = true;
            }
        }
    }
    for (auto& sym : symbols) {
        const auto& name = sym.demangled;
        auto it = symbolTable.find(StringView{name.data(), name.size()});
        if (it != symbolTable.end() && it->second.ambiguous_demangle) {
            sym.ambiguous_demangle = true;
        }
    }
    return symbolTable;
}

// ==========================================
//        Cross-Platform Mapped File
// ==========================================
struct MappedFile {
    const char* data;
    size_t size;
    bool success;

#ifdef _WIN32
    HANDLE hFile;
    HANDLE hMap;

    MappedFile() = delete;
    MappedFile(const MappedFile&) = delete;
    MappedFile(MappedFile&&) = delete;
    MappedFile& operator=(const MappedFile&) = delete;
    MappedFile& operator=(MappedFile&&) = delete;
    MappedFile(const char* filename) noexcept
        : data(nullptr),
          size(0),
          success(false),
          hFile(CreateFile(filename, GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr)),
          hMap(nullptr) {
        if (hFile == INVALID_HANDLE_VALUE) {
            // Could not open file
            return;
        }
        LARGE_INTEGER fs;
        if (!GetFileSizeEx(hFile, &fs)) {
            // Could not get file size
            return;
        }
        size = static_cast<size_t>(fs.QuadPart);
        hMap = CreateFileMapping(hFile, nullptr, PAGE_READONLY, 0, 0, nullptr);
        if (!hMap) {
            // Could not create file mapping
            return;
        }
        data = static_cast<const char*>(MapViewOfFile(hMap, FILE_MAP_READ, 0, 0, 0));
        if (!data) {
            // Could not map view of file
            return;
        }
        success = true;
    }

    ~MappedFile() noexcept {
        if (data) {
            UnmapViewOfFile(data);
        }
        if (hMap) {
            CloseHandle(hMap);
        }
        if (hFile != INVALID_HANDLE_VALUE) {
            CloseHandle(hFile);
        }
    }
#else
    // POSIX Implementation (Linux & macOS)
    int fd;

    MappedFile(const char* filename) noexcept
        : data(nullptr),
          size(0),
          success(false),
          fd{open(filename, O_RDONLY)} {
        if (fd < 0) {
            // Could not open file
            return;
        }
        struct stat st;
        if (fstat(fd, &st) < 0) {
            // Could not stat file
            return;
        }
        size = st.st_size;
        void* ptr = mmap(NULL, size, PROT_READ, MAP_PRIVATE, fd, 0);
        if (ptr == MAP_FAILED) {
            // Could not mmap file
            return;
        }
        data = static_cast<const char*>(ptr);
        success = true;
    }

    ~MappedFile() noexcept {
        if (data != MAP_FAILED) {
            munmap(const_cast<char*>(data), size);
        }
        if (fd >= 0) {
            close(fd);
        }
    }
#endif
};

#if defined(__linux__)
// ==========================================
//            LINUX ELF LOGIC
// ==========================================

template <typename Ehdr, typename Shdr, typename Sym>
static SymbolStorage processELF(const char* data_ptr) noexcept {
    const auto* ehdr = reinterpret_cast<const Ehdr*>(data_ptr);
    const auto* section_headers = reinterpret_cast<const Shdr*>(data_ptr + ehdr->e_shoff);

    SymbolStorage storage{};
    for (size_t i = 0; i < ehdr->e_shnum; ++i) {
        const Shdr& shdr = section_headers[i];
        if (shdr.sh_type == SHT_SYMTAB) {
            const Sym* symbols = reinterpret_cast<const Sym*>(data_ptr + shdr.sh_offset);
            size_t symbol_count = shdr.sh_size / sizeof(Sym);

            const Shdr& str_shdr = section_headers[shdr.sh_link];
            const char* str_tab = data_ptr + str_shdr.sh_offset;

            for (size_t j = 0; j < symbol_count; ++j) {
                const Sym& sym = symbols[j];
                if (sym.st_value == 0) {
                    continue;
                }
                StringView sym_name{str_tab + sym.st_name};
                if (!sym_name.empty() && !starts_with_any(sym_name, {".L", "._"})) {
                    try {
#ifdef SYMBOL_TABLE_CPP_USE_REAL_SIZE
                        storage.emplace_back(std::string{sym_name.data(), sym_name.size()}, sym.st_value, sym.st_size);
#else
                        storage.emplace_back(std::string{sym_name.data(), sym_name.size()}, sym.st_value);
#endif
                    } catch (...) {
                    }
                }
            }
        }
    }
    return storage;
}

#elif defined(_WIN32)
// ==========================================
//           WINDOWS PE LOGIC
// ==========================================

static std::vector<Symbol> processPE(const char* data) noexcept {
    const auto* dosHeader = reinterpret_cast<const IMAGE_DOS_HEADER*>(data);
    if (dosHeader->e_magic != IMAGE_DOS_SIGNATURE) {
        // Error: Not a valid DOS/PE header.
        return {};
    }

    const auto* ntHeaders32 = reinterpret_cast<const IMAGE_NT_HEADERS32*>(data + dosHeader->e_lfanew);
    if (ntHeaders32->Signature != IMAGE_NT_SIGNATURE) {
        // Error: Not a valid PE signature.
        return {};
    }

    bool is64 = (ntHeaders32->OptionalHeader.Magic == IMAGE_NT_OPTIONAL_HDR64_MAGIC);

    uint64_t imageBase = 0;
    DWORD pointerToSymbolTable = 0;
    DWORD numberOfSymbols = 0;
    const IMAGE_SECTION_HEADER* sections = nullptr;
    int numSections = 0;

    if (is64) {
        const auto* ntHeaders64 = reinterpret_cast<const IMAGE_NT_HEADERS64*>(ntHeaders32);
        // imageBase = ntHeaders64->OptionalHeader.ImageBase;
        pointerToSymbolTable = ntHeaders64->FileHeader.PointerToSymbolTable;
        numberOfSymbols = ntHeaders64->FileHeader.NumberOfSymbols;
        sections = IMAGE_FIRST_SECTION(ntHeaders64);
        numSections = ntHeaders64->FileHeader.NumberOfSections;
    } else {
        // imageBase = ntHeaders32->OptionalHeader.ImageBase;
        pointerToSymbolTable = ntHeaders32->FileHeader.PointerToSymbolTable;
        numberOfSymbols = ntHeaders32->FileHeader.NumberOfSymbols;
        sections = IMAGE_FIRST_SECTION(ntHeaders32);
        numSections = ntHeaders32->FileHeader.NumberOfSections;
    }

    if (pointerToSymbolTable == 0) {
        // Error: No COFF Symbol Table (stripped?).
        return {};
    }

    const auto* symbolRoot = reinterpret_cast<const IMAGE_SYMBOL*>(data + pointerToSymbolTable);
    const char* stringTable = data + pointerToSymbolTable + (numberOfSymbols * IMAGE_SIZEOF_SYMBOL);

    SymbolStorage symbols{};
    std::array<char, 16> buffer{};
    for (DWORD i = 0; i < numberOfSymbols; ++i) {
        const IMAGE_SYMBOL& sym = symbolRoot[i];
        /* https://learn.microsoft.com/en-us/windows/win32/debug/pe-format
          SectionNumber:
          Normally, the Section Value field in a symbol table entry is a one-based index into the section table.
          However, this field is a signed integer and can take negative values. The following values, less than one, have special meanings.
          IMAGE_SYM_UNDEFINED = 0
          IMAGE_SYM_ABSOLUTE = -1
          IMAGE_SYM_DEBUG = -2
          StorageClass:
          IMAGE_SYM_CLASS_EXTERNAL = 2
          A value that Microsoft tools use for external symbols.
          The Value field indicates the size if the section number is IMAGE_SYM_UNDEFINED (0).
          If the section number is not zero, then the Value field specifies the offset within the section.
          IMAGE_SYM_CLASS_STATIC = 3
          The offset of the symbol within the section. If the Value field is zero, then the symbol represents a section name.*/
        if (sym.SectionNumber > 0 && sym.SectionNumber <= numSections &&
            (sym.StorageClass == IMAGE_SYM_CLASS_EXTERNAL || sym.StorageClass == IMAGE_SYM_CLASS_STATIC)) {
            StringView nameView{"", 0};
            if (sym.N.Name.Short == 0) {
                nameView = stringTable + sym.N.Name.Long;
            } else {
                buffer.fill('\0');
                std::memcpy(buffer.data(), sym.N.ShortName, sizeof(sym.N.ShortName));
                nameView = buffer.data();
            }
            if (!nameView.empty() && nameView[0] == '_') {
                nameView.remove_prefix(1);  // Remove leading underscore
            }
            if (!nameView.empty() &&
                !starts_with_any(nameView, {".text", ".bss", ".debug", ".idata", ".rdata", ".data", ".ctors"})) {
                uintptr_t finalAddr = imageBase + sections[sym.SectionNumber - 1].VirtualAddress + sym.Value;
                try {
                    symbols.emplace_back(std::string{nameView.data(), nameView.size()}, finalAddr);
                } catch (...) {
                }
            }
        }
        i += sym.NumberOfAuxSymbols;
    }
    return symbols;
}

#elif defined(__APPLE__)
// ==========================================
//           MACOS MACH-O LOGIC
// ==========================================

// Template to handle both mach_header (32) and mach_header_64
template <typename MachHeader, typename Nlist>
static SymbolStorage processMac(const char* data_ptr) noexcept {
    auto* header = reinterpret_cast<const MachHeader*>(data_ptr);

    // Load commands follow immediately after the header
    const char* cmd_ptr = data_ptr + sizeof(MachHeader);

    SymbolStorage symbols{};
    // Iterate through Load Commands
    for (uint32_t i = 0; i < header->ncmds; ++i) {
        auto* lc = reinterpret_cast<const load_command*>(cmd_ptr);

        // We are looking for the Symbol Table command
        if (lc->cmd == LC_SYMTAB) {
            auto* symtab = reinterpret_cast<const symtab_command*>(lc);

            // Pointers to Symbol table and String table
            // Offsets are from the start of the file (or the start of the fat slice)
            // Note: If this is inside a FAT binary, data_ptr is already offset,
            // but symtab->symoff is usually relative to the start of the object file.
            // In Mach-O, offsets in LC_SYMTAB are file offsets.
            const char* str_table = data_ptr + symtab->stroff;
            const Nlist* symbol_table = reinterpret_cast<const Nlist*>(data_ptr + symtab->symoff);

            for (uint32_t j = 0; j < symtab->nsyms; ++j) {
                const Nlist& sym = symbol_table[j];

                // n_strx is index into string table
                // If n_strx is 0, there is no name
                if (sym.n_un.n_strx == 0)
                    continue;

                // n_type includes flags (like N_STAB for debugging).
                // We usually want to skip debug symbols for basic nm-like output.
                if (sym.n_type & N_STAB)
                    continue;

                // Mach-O symbols usually have a leading underscore in the string table
                const char* raw_name = str_table + sym.n_un.n_strx;
                try {
                    std::string name = raw_name;
                    if (!name.empty())
                        symbols.emplace_back(std::move(name), sym.n_value);
                } catch (...) {
                }
            }
        }

        // Move to next command
        cmd_ptr += lc->cmdsize;
    }
    return symbols;
}

#endif

static std::string getProcessFilePath() noexcept {
    try {
        char path[4096]{};
#if defined(_WIN32)
        if (GetModuleFileName(nullptr, path, sizeof(path) - 1)) {
            return path;
        }
#elif defined(__linux__)
        ssize_t len = readlink("/proc/self/exe", path, sizeof(path) - 1);
        if (len != -1) {
            path[len] = '\0';
            return path;
        }
#elif defined(__APPLE__)
        uint32_t size = sizeof(path);
        if (_NSGetExecutablePath(path, &size) == 0) {
            return path;
        }
#else
#error "Unsupported OS"
#endif
        return {};
    } catch (...) {
        return {};
    }
}

static SymbolStorage processFile(const std::string& filenameString) noexcept {
    if (filenameString.empty()) {
        // Error: Filename is empty.
        return {};
    }
    const char* filename = filenameString.c_str();
    MappedFile file(filename);
    if (file.success) {
#if defined(_WIN32)
        return processPE(file.data);
#elif defined(__linux__)
        if (std::memcmp(file.data, ELFMAG, SELFMAG) != 0) {
            // Error: Not a valid ELF file.
            return {};
        }
        uint8_t elf_class = file.data[EI_CLASS];
        if (elf_class == ELFCLASS32)
            return processELF<Elf32_Ehdr, Elf32_Shdr, Elf32_Sym>(file.data);
        else if (elf_class == ELFCLASS64)
            return processELF<Elf64_Ehdr, Elf64_Shdr, Elf64_Sym>(file.data);
        else {
            // Error: Unknown ELF class.
        }
#elif defined(__APPLE__)
        const char* data_ptr = file.data;

        // Check for Universal (Fat) Binary
        uint32_t magic = *reinterpret_cast<const uint32_t*>(data_ptr);

        // Helper to swap endianness if needed
        bool is_fat = (magic == FAT_MAGIC || magic == FAT_CIGAM);

        if (is_fat) {
            // It's a FAT binary. We need to find the offset of a supported architecture.
            // FAT headers are always Big Endian.
            auto fat_hdr = reinterpret_cast<const struct fat_header*>(data_ptr);
            uint32_t nfat_arch = OSSwapBigToHostInt32(fat_hdr->nfat_arch);

            // Pointer to first arch struct
            auto archs = reinterpret_cast<const struct fat_arch*>(data_ptr + sizeof(struct fat_header));

            // For simplicity, we just pick the FIRST architecture in the fat binary.
            // Real tools match the host architecture (x86_64 vs arm64).
            if (nfat_arch > 0) {
                uint32_t offset = OSSwapBigToHostInt32(archs[0].offset);
                // Shift our base pointer to the start of the specific object file
                data_ptr += offset;
                // Update magic to the magic of the slice
                magic = *reinterpret_cast<const uint32_t*>(data_ptr);
            }
        }

        // 2. Process Mach-O (Thin)
        if (magic == MH_MAGIC_64) {
            return processMac<struct mach_header_64, struct nlist_64>(data_ptr);
        } else if (magic == MH_MAGIC) {
            return processMac<struct mach_header, struct nlist>(data_ptr);
        } else {
            // Error: Not a valid Mach-O file.
        }
#else
#error "Unsupported OS"
#endif
    }
    return {};
}

SymbolStorage& GetStaticSymbolStorage(const std::string& filename = getProcessFilePath()) {
    static SymbolStorage symbolStorage{sortSymbols(processFile(filename))};
    return symbolStorage;
}

const SymbolTable& GetSymbolTableByName() {
    static const SymbolTable symbolTable{toTable(GetStaticSymbolStorage())};
    return symbolTable;
}

const SymbolTable& GetSymbolTableByDemangledName() {
    static const SymbolTable symbolTable{toTableDemangled(GetStaticSymbolStorage())};
    return symbolTable;
}

boost::optional<const Symbol&> GetSymbolByName(StringView name, bool allow_ambiguous) noexcept {
    try {
        const auto& table = GetSymbolTableByName();
        auto it = table.find(name);
        if (it != table.end() && (allow_ambiguous || !it->second.ambiguous)) {
            return it->second;
        }
        return boost::none;
    } catch (...) {
        return boost::none;
    }
}

boost::optional<const Symbol&> GetSymbolByDemangledName(StringView name, bool allow_ambiguous) noexcept {
    try {
        const auto& table = GetSymbolTableByDemangledName();
        auto it = table.find(name);
        if (it != table.end() && (allow_ambiguous || !it->second.ambiguous_demangle)) {
            return it->second;
        }
        return boost::none;
    } catch (...) {
        return boost::none;
    }
}

boost::optional<const Symbol&> GetSymbolByNameRegex(StringView pattern, bool allow_ambiguous) noexcept {
    try {
        const auto& storage = GetStaticSymbolStorage();
        boost::regex regex_pattern(pattern.cbegin(), pattern.cend());
        const Symbol* match = nullptr;
        constexpr boost::match_flag_type flags = boost::match_default;
        for (const auto& symbol : storage) {
            if (boost::regex_search(symbol.name, regex_pattern, flags)) {
                if (allow_ambiguous) {
                    return symbol;
                }
                if (match && match->address != symbol.address) {
                    return boost::none;  // Multiple matches found
                }
                match = &symbol;
            }
        }
        if (match) {
            return *match;
        }
        return boost::none;
#ifdef DEBUG
    } catch (std::exception& e) {
        std::cerr << "Error while name regex search:" << pattern << ':' << e.what() << '\n';
        return boost::none;
#endif
    } catch (...) {
        return boost::none;
    }
}

boost::optional<const Symbol&> GetSymbolByDemangledNameRegex(StringView pattern, bool allow_ambiguous) noexcept {
    try {
        const auto& storage = GetStaticSymbolStorage();
        boost::regex regex_pattern(pattern.cbegin(), pattern.cend());
        const Symbol* match = nullptr;
        constexpr boost::match_flag_type flags = boost::match_default;
        for (const auto& symbol : storage) {
            if (boost::regex_search(symbol.demangled, regex_pattern, flags)) {
                if (allow_ambiguous) {
                    return symbol;
                }
                if (match && match->address != symbol.address) {
                    return boost::none;  // Multiple matches found
                }
                match = &symbol;
            }
        }
        if (match) {
            return *match;
        }
        return boost::none;
#ifdef DEBUG
    } catch (std::exception& e) {
        std::cerr << "Error while demangled regex search:" << pattern << ':' << e.what() << '\n';
        return boost::none;
#endif
    } catch (...) {
        return boost::none;
    }
}

boost::optional<const Symbol&> GetSymbolByNameSimple(StringView pattern, bool allow_ambiguous) noexcept {
    try {
        const auto& storage = GetStaticSymbolStorage();
        const Symbol* match = nullptr;
        for (const auto& symbol : storage) {
            if (simpleMatch(symbol.name, pattern)) {
                if (allow_ambiguous) {
                    return symbol;
                }
                if (match && match->address != symbol.address) {
                    return boost::none;  // Multiple matches found
                }
                match = &symbol;
            }
        }
        if (match) {
            return *match;
        }
        return boost::none;
    } catch (...) {
        return boost::none;
    }
}

boost::optional<const Symbol&> GetSymbolByDemangledNameSimple(StringView pattern, bool allow_ambiguous) noexcept {
    try {
        const auto& storage = GetStaticSymbolStorage();
        const Symbol* match = nullptr;
        for (const auto& symbol : storage) {
            if (simpleMatch(symbol.demangled, pattern)) {
                if (allow_ambiguous) {
                    return symbol;
                }
                if (match && match->address != symbol.address) {
                    return boost::none;  // Multiple matches found
                }
                match = &symbol;
            }
        }
        if (match) {
            return *match;
        }
        return boost::none;
    } catch (...) {
        return boost::none;
    }
}

#ifdef SYMBOL_TABLE_CPP_AS_MAIN_EXE
#include <iomanip>
#include <iostream>

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <binary_path>\n";
        return 1;
    }
    std::string filename = argv[1];
    if (filename.empty()) {
        std::cerr << "Error: Filename is empty.\n";
        return 1;
    }
    const auto& symbols = GetStaticSymbolStorage(filename);
    GetSymbolTableByName();
    GetSymbolTableByDemangledName();
    if (argc >= 3) {
        std::string query = argv[2];
        auto opt_sym = GetSymbolByNameRegex(query, true);
        if (opt_sym.has_value()) {
            const Symbol& sym = opt_sym.value();
            std::cout << "Found symbol by name: " << sym.name << " at address 0x"
                      << std::hex << sym.address << "\n";
        } else {
            std::cout << "Symbol not found by name: " << query << "\n";
        }
        auto opt_sym2 = GetSymbolByDemangledNameRegex(query, true);
        if (opt_sym2.has_value()) {
            const Symbol& sym = opt_sym2.value();
            std::cout << "Found symbol by demangled name: " << sym.demangled << " at address 0x"
                      << std::hex << sym.address << "\n";
        } else {
            std::cout << "Symbol not found by demangled name: " << query << "\n";
        }
        return 0;
    }
    for (const auto& sym : symbols) {
        if (sym.ambiguous && sym.ambiguous_demangle) {
            std::cout << "*|* ";
        } else if (sym.ambiguous) {
            std::cout << "*|   ";
        } else if (sym.ambiguous_demangle) {
            std::cout << " |* ";
        } else
            std::cout << " |  ";
        std::cout << std::hex << std::setw(16) << std::setfill('0') << sym.address << " +"
                  << std::hex << std::setw(4) << std::setfill('0') << sym.size << " "
                  << sym.name << " {" << sym.demangled << "}\n";
    }
    return 0;
}

#endif
