#pragma once
#include <initializer_list>
#include "StringView.h"

namespace Scanner {

inline constexpr bool IsSpace(char c) {
    return c == '\t' || c == '\n' || c == '\v' ||
           c == '\f' || c == '\r' || c == ' ';
}

inline bool SkipSpace(const char*& p) {
    if (!IsSpace(*p)) {
        return false;
    }
    while (IsSpace(*p)) {
        p++;
    }
    return true;
}

// Return a pointer next to the last non-space char within [start, end).
inline const char* FindNonSpaceEnd(const char* start, const char* end) {
    while (end > start && IsSpace(*(end - 1))) {
        end--;
    }
    return end;
}

// Check if null-terminated p starts with token.
inline bool StartsWith(const char* p, StringView token) {
    for (char c : token) {
        if (*p == '\0' || *p != c)
            return false;
        p++;
    }
    return true;
}

// If it did consume a token string, move p to next char of token, return true.
inline bool Consume(const char*& p, StringView token) {
    if (token.empty()) {
        return true;  // Empty token always matches
    }
    if (StartsWith(p, token)) {
        p += token.size();
        return true;
    }
    return false;
}

// Consume a single specific character.
inline bool Consume(const char*& p, char expected) {
    if (*p == expected) {
        p++;
        return true;
    }
    return false;
}

// Consumes the first matching token from the list.
// Returns the index (0-based) of the matching token.
// If no token matches, p remains unchanged, and the function returns tokenList.size().
// NOTE: Order matters! If tokens overlap, put longer ones first.
// Example: ConsumeAnyOf(p, {">=", ">"}) ensures ">=" is checked before ">".
inline size_t ConsumeAnyOf(const char*& p, std::initializer_list<StringView> tokenList) {
    size_t index = 0;
    for (const auto& token : tokenList) {
        if (token.empty()) {
            continue;
        }
        if (StartsWith(p, token)) {
            p += token.size();
            return index;
        }
        index++;
    }
    return index;  // Returns size() (index of end) if failure
}

// Move p forward until token found.
// If found: consume the token, set p to char after token, return true.
// If not found: move p to end of string, return false.
inline bool Until(const char*& p, const char* pEnd, StringView token) {
    if (token.empty())
        return true;
    StringView text(p, pEnd - p);
    size_t pos = text.find(token);
    if (pos != StringView::npos) {
        p += pos + token.size();
        return true;
    }
    // Move to end
    p += text.size();
    return false;
}

// Same as Until, but for a single char.
inline bool Until(const char*& p, char c) {
    const char* curr = p;
    while (*curr) {
        if (*curr == c) {
            p = curr + 1;
            return true;
        }
        curr++;
    }
    p = curr;  // Move to end
    return false;
}

// Scans from current 'p' until 'token' is found.
// Template Param 'AlwaysTrim':
//   - true:  Output the trimmed string even if the token is NOT found (until end).
//   - false: Only output if the token IS found. If not found, output is empty.
// Returns: true if token was found and consumed, false otherwise.
// Note: 'p' is always moved. If found, p is after token. If not, p is at \0.
template <bool AlwaysTrim = true>
inline bool MatchTrimmedUntil(const char*& p, const char* pEnd, StringView token, StringView& out) {
    const char* searchStart = p;
    StringView text(p, pEnd - p);
    size_t pos = text.find(token);
    bool foundToken = (pos != StringView::npos);
    const char* extractionLimit = nullptr;
    if (foundToken) {
        extractionLimit = p + pos;
        p += pos + token.size();  // Consume token
    } else {
        // Not found: Move p to the absolute end
        p += text.size();
        extractionLimit = p;
    }
    // Determine if we should output the trimmed string
    if (AlwaysTrim || foundToken) {
        const char* s = searchStart;
        const char* e = extractionLimit;
        // Trim Front
        while (s < e && IsSpace(*s)) {
            s++;
        }
        // Trim Back
        while (e > s && IsSpace(*(e - 1))) {
            e--;
        }
        out = StringView(s, e - s);
    } else {
        out.clear();
    }
    return foundToken;
}

// Scans forward searching for 'token'.
// If found: Moves p to AFTER the token, returns true.
// If NOT found: p remains UNCHANGED, returns false.
inline bool ConsumeEndsWith(const char*& p, const char* pEnd, StringView token) {
    if (token.empty())
        return true;
    StringView text(p, pEnd - p);
    size_t pos = text.find(token);
    if (pos != StringView::npos) {
        p += pos + token.size();
        return true;
    }
    return false;
}

// Similar to ConsumeEndsWith, but returns the content *before* the token, trimmed.
inline bool MatchTrimmedEndsWith(const char*& p, const char* pEnd, StringView token, StringView& out) {
    StringView text(p, pEnd - p);
    size_t pos = text.find(token);
    if (pos != StringView::npos) {
        const char* s = p;
        const char* e = p + pos;
        // Trim Front
        while (s < e && IsSpace(*s)) {
            s++;
        }
        // Trim Back
        while (e > s && IsSpace(*(e - 1))) {
            e--;
        }
        out = StringView(s, e - s);
        // Advance p past the token
        p += pos + token.size();
        return true;
    }
    // Not found: Don't change p, return empty range
    out.clear();
    return false;
}

}  // namespace Scanner
