#pragma once
#include <boost/optional/optional.hpp>
#include <cstdint>
#include <string>

struct Symbol {
    std::string name;            // symbol name
    std::string demangled_name;  // demangled symbol name
    std::uintptr_t address;      // address in memory or offset to module base
    std::size_t size;            // size in bytes, -1 if unknown
    bool ambiguous;              // true if multiple symbols with different addresses share the same name
    bool ambiguous_demangle;     // true if multiple symbols with different addresses share the same demangled name
    // indicates address is offset to module base rather than absolute
    static constexpr bool IsOffset() {
#if defined(__linux__)
        return false;
#elif defined(_WIN32) || defined(__APPLE__)
        return true;
#else
#error "Unsupported OS"
#endif
    }
};

// Get a symbol by exact name match
boost::optional<const Symbol&> GetSymbolByName(const std::string& name, bool allow_ambiguous = false);

// Get a symbol by regex name match
boost::optional<const Symbol&> GetSymbolByNameRegex(const std::string& pattern, bool allow_ambiguous = false);

// Get a symbol by simple pattern match with delimiter support
boost::optional<const Symbol&> GetSymbolByNameSimple(const std::string& pattern, char delimiter = ' ', bool allow_ambiguous = false);

// Get a symbol by exact demangled name match
boost::optional<const Symbol&> GetSymbolByDemangledName(const std::string& name, bool allow_ambiguous = false);

// Get a symbol by regex demangled name match
boost::optional<const Symbol&> GetSymbolByDemangledNameRegex(const std::string& pattern, bool allow_ambiguous = false);

// Get a symbol by simple pattern demangled name match with delimiter support
boost::optional<const Symbol&> GetSymbolByDemangledNameSimple(const std::string& pattern, char delimiter = ' ', bool allow_ambiguous = false);
