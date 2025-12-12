#pragma once
#include <boost/optional/optional.hpp>
#include <cstdint>
#include <string>
#include "StringView.h"

#ifdef SYMBOL_TABLE_H_USE_BOOST_DEMANGLE
#include <boost/core/demangle.hpp>
#else
#include <cxxabi.h>
#endif

inline std::string DemangleRawName(const std::string& name) noexcept {
    try {
        const char* cstr = name.c_str();
#ifdef USE_BOOST_DEMANGLE
        return boost::core::demangle(cstr);
#else
        int status = -1;
        // Use std::unique_ptr for automatic memory management of the demangled name
        std::unique_ptr<char, decltype(&std::free)> ptr(
            abi::__cxa_demangle(cstr, nullptr, nullptr, &status),
            &std::free);
        if (status != 0) {
            return name;  // Demangling failed, return original name
        }
        return ptr.get();
#endif
    } catch (...) {
        return {};
    }
}

struct Symbol {
    std::string name;                // symbol name
    std::string demangled;           // demangled symbol name
    std::uintptr_t address;          // address in memory or offset to module base
    std::size_t size;                // size in bytes, -1 if unknown
    bool ambiguous{false};           // true if multiple symbols with different addresses share the same name
    bool ambiguous_demangle{false};  // true if multiple symbols with different addresses share the same demangled name
    Symbol(std::string&& name_, std::uintptr_t address_, std::size_t size_ = -1) noexcept
        : name{std::move(name_)}, demangled{DemangleRawName(name)}, address{address_}, size{size_} {}
    // indicates address is offset to module base rather than absolute
    static constexpr bool IsOffset() noexcept {
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
boost::optional<const Symbol&> GetSymbolByName(StringView name, bool allow_ambiguous = false) noexcept;

// Get a symbol by regex name match
boost::optional<const Symbol&> GetSymbolByNameRegex(StringView pattern, bool allow_ambiguous = false) noexcept;

// Get a symbol by simple pattern match
boost::optional<const Symbol&> GetSymbolByNameSimple(StringView pattern, bool allow_ambiguous = false) noexcept;

// Get a symbol by exact demangled name match
boost::optional<const Symbol&> GetSymbolByDemangledName(StringView name, bool allow_ambiguous = false) noexcept;

// Get a symbol by regex demangled name match
boost::optional<const Symbol&> GetSymbolByDemangledNameRegex(StringView pattern, bool allow_ambiguous = false) noexcept;

// Get a symbol by simple pattern demangled name match
boost::optional<const Symbol&> GetSymbolByDemangledNameSimple(StringView pattern, bool allow_ambiguous = false) noexcept;
