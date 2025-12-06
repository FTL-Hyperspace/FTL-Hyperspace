#include "SymbolTable.h"
#include <algorithm>
#include <boost/algorithm/string/predicate.hpp>
// #include <boost/regex.hpp>
#include <iomanip>
#include <iostream>
#include <memory>
#include <regex>
#include <string>
#include <unordered_map>
#include <vector>

#ifdef USE_BOOST_DEMANGLE
#include <boost/core/demangle.hpp>
#else
#include <cxxabi.h>
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
using SymbolTable = std::unordered_map<std::string, Symbol&>;

// Check if text starts with any of the given prefixes
static bool starts_with_any(const std::string& text, std::initializer_list<const char*> prefixes) {
    return std::any_of(prefixes.begin(), prefixes.end(),
                       [&text](const char* prefix) {
                           return boost::algorithm::starts_with(text, prefix);
                       });
}

// Simple pattern matching function (non-regex) with delimiter support
bool simpleMatch(const std::string& text, const std::string& pattern, char delimiter = ' ') {
    if (pattern.empty())
        return true;

    size_t text_pos = 0;
    size_t pattern_pos = 0;
    size_t pattern_len = pattern.length();
    while (pattern_pos < pattern_len) {
        if (pattern[pattern_pos] == delimiter) {
            pattern_pos++;
            continue;
        }
        size_t next_delim_pos = pattern.find(delimiter, pattern_pos);
        size_t token_len = 0;
        if (next_delim_pos == std::string::npos) {
            token_len = pattern_len - pattern_pos;
        } else {
            token_len = next_delim_pos - pattern_pos;
        }
        size_t found_pos = text.find(&pattern[pattern_pos], text_pos, token_len);
        if (found_pos == std::string::npos) {
            return false;
        }
        text_pos = found_pos + token_len;
        pattern_pos += token_len;
    }
    return true;
}

static std::string demangle(const std::string& mangled_name) {
    const char* name_cstr = mangled_name.c_str();
#ifdef USE_BOOST_DEMANGLE
    return boost::core::demangle(name_cstr);
#else
    int status = -1;
    // Use std::unique_ptr for automatic memory management of the demangled name
    std::unique_ptr<char, decltype(&std::free)> demangled_name_ptr(
        abi::__cxa_demangle(name_cstr, nullptr, nullptr, &status),
        &std::free);
    if (status != 0) {
        return mangled_name;  // Demangling failed, return original name
    }
    return demangled_name_ptr.get();
#endif
}

static SymbolStorage sortSymbols(SymbolStorage&& symbols) {
    if (symbols.empty()) {
        return symbols;
    }
    std::sort(symbols.begin(), symbols.end(), [](const Symbol& a, const Symbol& b) {
        if (a.address == b.address) {
            return a.name < b.name;
        }
        return a.address < b.address;
    });
    auto n = static_cast<std::ptrdiff_t>(symbols.size());
    symbols[n - 1].size = -1;  // Size unknown for last symbol
    for (std::ptrdiff_t i = n - 2; i >= 0; --i) {
        if (symbols[i].address != symbols[i + 1].address) {
            symbols[i].size = symbols[i + 1].address - symbols[i].address;
        } else {
            symbols[i].size = symbols[i + 1].size;
        }
    }
    return symbols;
}

static SymbolTable toTable(SymbolStorage& symbols) {
    SymbolTable symbolTable{};
    for (auto& sym : symbols) {
        auto result = symbolTable.emplace(sym.name, sym);
        if (!result.second) {
            auto& existingSym = result.first->second;
            if (existingSym.address != sym.address) {
                existingSym.ambiguous = true;
            }
        }
    }
    for (auto& sym : symbols) {
        auto it = symbolTable.find(sym.name);
        if (it != symbolTable.end() && it->second.ambiguous) {
            sym.ambiguous = true;
        }
    }
    return symbolTable;
}

static SymbolTable toTableDemangled(SymbolStorage& symbols) {
    SymbolTable symbolTable{};
    for (auto& sym : symbols) {
        auto result = symbolTable.emplace(sym.demangled_name, sym);
        if (!result.second) {
            auto& existingSym = result.first->second;
            if (existingSym.address != sym.address) {
                existingSym.ambiguous_demangle = true;
            }
        }
    }
    for (auto& sym : symbols) {
        auto it = symbolTable.find(sym.demangled_name);
        if (it != symbolTable.end() && it->second.ambiguous_demangle) {
            sym.ambiguous_demangle = true;
        }
    }
    return symbolTable;
}

// ==========================================
//        Cross-Platform Mapped File
// ==========================================
class MappedFile {
   public:
    const char* data;
    size_t size;

#ifdef _WIN32
    HANDLE hFile;
    HANDLE hMap;

    MappedFile() = delete;
    MappedFile(const MappedFile&) = delete;
    MappedFile(MappedFile&&) = delete;
    MappedFile& operator=(const MappedFile&) = delete;
    MappedFile& operator=(MappedFile&&) = delete;
    MappedFile(const std::string& filename)
        : hFile(CreateFile(filename.c_str(), GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr)) {
        if (hFile == INVALID_HANDLE_VALUE)
            throw std::runtime_error("Could not open file");

        LARGE_INTEGER fs;
        if (!GetFileSizeEx(hFile, &fs)) {
            CloseHandle(hFile);
            throw std::runtime_error("Could not get file size");
        }
        size = static_cast<size_t>(fs.QuadPart);

        hMap = CreateFileMapping(hFile, NULL, PAGE_READONLY, 0, 0, NULL);
        if (!hMap) {
            CloseHandle(hFile);
            throw std::runtime_error("Could not create file mapping");
        }

        data = static_cast<const char*>(MapViewOfFile(hMap, FILE_MAP_READ, 0, 0, 0));
        if (!data) {
            CloseHandle(hMap);
            CloseHandle(hFile);
            throw std::runtime_error("Could not map view of file");
        }
    }

    ~MappedFile() {
        if (data)
            UnmapViewOfFile(data);
        if (hMap)
            CloseHandle(hMap);
        if (hFile != INVALID_HANDLE_VALUE)
            CloseHandle(hFile);
    }
#else
    // POSIX Implementation (Linux & macOS)
    int fd;

    MappedFile(const std::string& filename)
        : fd{open(filename.c_str(), O_RDONLY)} {
        if (fd < 0)
            throw std::runtime_error("Could not open file");

        struct stat st;
        if (fstat(fd, &st) < 0) {
            close(fd);
            throw std::runtime_error("Could not stat file");
        }
        size = st.st_size;

        void* ptr = mmap(NULL, size, PROT_READ, MAP_PRIVATE, fd, 0);
        if (ptr == MAP_FAILED) {
            close(fd);
            throw std::runtime_error("Could not mmap file");
        }
        data = static_cast<const char*>(ptr);
    }

    ~MappedFile() {
        if (data != MAP_FAILED)
            munmap((void*)data, size);
        if (fd >= 0)
            close(fd);
    }
#endif
};

#if defined(__linux__)
// ==========================================
//            LINUX ELF LOGIC
// ==========================================

template <typename Ehdr, typename Shdr, typename Sym>
static SymbolStorage process_elf(const char* data_ptr) {
    auto ehdr = reinterpret_cast<const Ehdr*>(data_ptr);
    auto section_headers = reinterpret_cast<const Shdr*>(data_ptr + ehdr->e_shoff);

    SymbolStorage storage{};
    for (int i = 0; i < ehdr->e_shnum; ++i) {
        const Shdr& shdr = section_headers[i];
        if (shdr.sh_type == SHT_SYMTAB || shdr.sh_type == SHT_DYNSYM) {
            const Sym* symbols = reinterpret_cast<const Sym*>(data_ptr + shdr.sh_offset);
            int symbol_count = shdr.sh_size / sizeof(Sym);

            const Shdr& str_shdr = section_headers[shdr.sh_link];
            const char* str_tab = data_ptr + str_shdr.sh_offset;

            for (int j = 0; j < symbol_count; ++j) {
                const Sym& sym = symbols[j];
                std::string sym_name = str_tab + sym.st_name;
                if (!sym_name.empty()) {
                    storage.emplace_back(Symbol{
                        sym_name,
                        demangle(sym_name),
                        sym.st_value,
                        static_cast<size_t>(-1),
                        false,
                        false});
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

static std::vector<Symbol> process_pe(const char* data) {
    const auto* dosHeader = reinterpret_cast<const IMAGE_DOS_HEADER*>(data);
    if (dosHeader->e_magic != IMAGE_DOS_SIGNATURE) {
        std::cerr << "Error: Not a valid DOS/PE header.\n";
        return {};
    }

    const auto* ntHeaders32 = reinterpret_cast<const IMAGE_NT_HEADERS32*>(data + dosHeader->e_lfanew);
    if (ntHeaders32->Signature != IMAGE_NT_SIGNATURE) {
        std::cerr << "Error: Not a valid PE signature.\n";
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
        std::cerr << "No COFF Symbol Table (stripped?).\n";
        return {};
    }

    const auto* symbolRoot = reinterpret_cast<const IMAGE_SYMBOL*>(data + pointerToSymbolTable);
    const char* stringTable = data + pointerToSymbolTable + (numberOfSymbols * IMAGE_SIZEOF_SYMBOL);

    std::vector<Symbol> symbols;
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
            std::string name;
            if (sym.N.Name.Short == 0) {
                name.assign(stringTable + sym.N.Name.Long);
            } else {
                name.assign(reinterpret_cast<const char*>(sym.N.ShortName), 8);
                size_t nullPos = name.find('\0');
                if (nullPos != std::string::npos)
                    name.resize(nullPos);
            }
            if (!name.empty() && name[0] == '_') {
                name = name.substr(1);  // Remove leading underscore
            }
            if (!name.empty() &&
                !starts_with_any(name, {".text", ".bss", ".debug", ".idata", ".rdata", ".data", ".ctors"})) {
                uintptr_t finalAddr = imageBase + sections[sym.SectionNumber - 1].VirtualAddress + sym.Value;
                symbols.emplace_back(Symbol{
                    name,
                    demangle(name),
                    finalAddr,
                    static_cast<size_t>(-1),
                    false,
                    false});
            }
        }
        i += sym.NumberOfAuxSymbols;
    }
    return symbols;
}

// ==========================================
//           MACOS MACH-O LOGIC
// ==========================================
#elif defined(__APPLE__)

// Template to handle both mach_header (32) and mach_header_64
template <typename MachHeader, typename Nlist>
static SymbolStorage process_macho_slice(const char* data_ptr) {
    auto header = reinterpret_cast<const MachHeader*>(data_ptr);
    int width = (sizeof(MachHeader) == sizeof(struct mach_header)) ? 8 : 16;

    // Load commands follow immediately after the header
    const char* cmd_ptr = data_ptr + sizeof(MachHeader);

    SymbolStorage symbols;
    // Iterate through Load Commands
    for (uint32_t i = 0; i < header->ncmds; ++i) {
        auto lc = reinterpret_cast<const struct load_command*>(cmd_ptr);

        // We are looking for the Symbol Table command
        if (lc->cmd == LC_SYMTAB) {
            auto symtab = reinterpret_cast<const struct symtab_command*>(lc);

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
                std::string name = raw_name;
                /* std::cout << "0x" << std::hex << std::setw(width) << std::setfill('0')
                          << sym.n_value << " " << name << std::dec << "\n"; */
                if (!name.empty())
                    symbols.emplace_back(name, sym.n_value, -1);
            }
        }

        // Move to next command
        cmd_ptr += lc->cmdsize;
    }
    return symbols;
}

#endif

static std::string getProcessFilePath() {
#if defined(_WIN32)
    char path[MAX_PATH]{};
    GetModuleFileNameA(nullptr, path, MAX_PATH);
    return path;
#elif defined(__linux__)
    char path[4096];
    ssize_t len = readlink("/proc/self/exe", path, sizeof(path) - 1);
    if (len != -1) {
        path[len] = '\0';
        return std::string(path);
    }
    return "";
#elif defined(__APPLE__)
    char path[4096];
    uint32_t size = sizeof(path);
    if (_NSGetExecutablePath(path, &size) == 0) {
        return std::string(path);
    }
    return "";
#else
#error "Unsupported OS"
#endif
}

static SymbolStorage process_file(const std::string& filename) {
    if (filename.empty()) {
        std::cerr << "Error: Filename is empty.\n";
        return {};
    }
#if defined(_WIN32)
    try {
        MappedFile file(filename);
        return process_pe(file.data);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
#elif defined(__linux__)
    try {
        MappedFile file(filename);
        if (std::memcmp(file.data, ELFMAG, SELFMAG) != 0) {
            std::cerr << "Error: Not a valid ELF file.\n";
            return {};
        }
        uint8_t elf_class = file.data[EI_CLASS];
        if (elf_class == ELFCLASS32)
            return process_elf<Elf32_Ehdr, Elf32_Shdr, Elf32_Sym>(file.data);
        else if (elf_class == ELFCLASS64)
            return process_elf<Elf64_Ehdr, Elf64_Shdr, Elf64_Sym>(file.data);
        else {
            std::cerr << "Error: Unknown ELF class.\n";
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
#elif defined(__APPLE__)
    try {
        MappedFile file(filename);
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
            return process_macho_slice<struct mach_header_64, struct nlist_64>(data_ptr);
        } else if (magic == MH_MAGIC) {
            return process_macho_slice<struct mach_header, struct nlist>(data_ptr);
        } else {
            std::cerr << "Error: Unknown Magic 0x" << std::hex << magic << ". Not a valid Mach-O file.\n";
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
#else
#error "Unsupported OS"
#endif
    return {};
}

SymbolStorage& GetSymbolStorage() {
    static SymbolStorage symbolStorage{sortSymbols(process_file(getProcessFilePath()))};
    return symbolStorage;
}

const SymbolTable& GetSymbolTableByName() {
    static const SymbolTable symbolTable{toTable(GetSymbolStorage())};
    return symbolTable;
}

const SymbolTable& GetSymbolTableByDemangledName() {
    static const SymbolTable symbolTable{toTableDemangled(GetSymbolStorage())};
    return symbolTable;
}

boost::optional<const Symbol&> GetSymbolByName(const std::string& name, bool allow_ambiguous) {
    const auto& table = GetSymbolTableByName();
    auto it = table.find(name);
    if (it != table.end() && (allow_ambiguous || !it->second.ambiguous)) {
        return it->second;
    }
    return boost::none;
}

boost::optional<const Symbol&> GetSymbolByDemangledName(const std::string& name, bool allow_ambiguous) {
    const auto& table = GetSymbolTableByDemangledName();
    auto it = table.find(name);
    if (it != table.end() && (allow_ambiguous || !it->second.ambiguous_demangle)) {
        return it->second;
    }
    return boost::none;
}

boost::optional<const Symbol&> GetSymbolByNameRegex(const std::string& pattern, bool allow_ambiguous) {
    const auto& storage = GetSymbolStorage();
    std::regex regex_pattern(pattern);
    const Symbol* match = nullptr;
    for (const auto& symbol : storage) {
        if (std::regex_search(symbol.name, regex_pattern)) {
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
}

boost::optional<const Symbol&> GetSymbolByDemangledNameRegex(const std::string& pattern, bool allow_ambiguous) {
    const auto& storage = GetSymbolStorage();
    std::regex regex_pattern(pattern);
    const Symbol* match = nullptr;
    for (const auto& symbol : storage) {
        if (std::regex_search(symbol.demangled_name, regex_pattern)) {
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
}

boost::optional<const Symbol&> GetSymbolByNameSimple(const std::string& pattern, char delimiter, bool allow_ambiguous) {
    const auto& storage = GetSymbolStorage();
    const Symbol* match = nullptr;
    for (const auto& symbol : storage) {
        if (simpleMatch(symbol.name, pattern, delimiter)) {
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
}

boost::optional<const Symbol&> GetSymbolByDemangledNameSimple(const std::string& pattern, char delimiter, bool allow_ambiguous) {
    const auto& storage = GetSymbolStorage();
    const Symbol* match = nullptr;
    for (const auto& symbol : storage) {
        if (simpleMatch(symbol.demangled_name, pattern, delimiter)) {
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
}

#ifdef IS_MAIN_EXE

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
    auto symbols = sortSymbols(process_file(filename));
    toTable(symbols);
    toTableDemangled(symbols);
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
            std::cout << "Found symbol by demangled name: " << sym.demangled_name << " at address 0x"
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
                  << sym.name << " {" << sym.demangled_name << "}\n";
    }
    return 0;
}

#endif
