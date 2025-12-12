# Symbol Lookups & Hybrid Signatures

## Overview

Traditionally, Hyperspace has relied on **byte signatures** (e.g., `578d7c...`) to find game functions. While effective, these signatures are "brittle". They are not compatible between different versions of FTL (Steam vs. GOG, Windows vs. Linux) and are unreadable to humans.

**Symbol Lookup** allows you to find functions by their **name** rather than their machine code.

* **Pros:** One signature often works for Linux, macOS, and older Windows versions simultaneously. It is much easier to read and debug.
* **Cons:** The newest Steam Windows version has stripped its symbols.
* **Solution:** Hyperspace supports a **hybrid** method. You can define a Symbol Lookup, but also provide a byte signature as a fallback.

## Syntax Guide

The signature scanner determines the mode based on specific **prefix characters** at the start of the string.

> **Note:** Spaces can be added before or after the pattern text for readability; the scanner will ignore them.

### 1. Exact Matching

The fastest and safest method. Use this if you have the exact mangled or demangled name.

| Prefix | Type | Description | Example |
| :--- | :--- | :--- | :--- |
| **`@`** | **Raw Name** | Matches the exact raw (mangled) symbol name | `"@ _ZN10ShipSystem15CheckDlcEnabledEv "` |
| **`@@`** | **Demangled** | Matches the **exact demangled name** (as returned by `abi::__cxa_demangle`) | `"@@ ShipSystem::CheckDlcEnabled() "` |

### 2. Pattern Matching (Search)

Useful if the exact name varies slightly between versions, or if you only want to type part of the name.

| Prefix | Type | Description | Example |
| :--- | :--- | :--- | :--- |
| **`+`** | **Simple Match** | Search raw name using **Simple Match** rules. | `"+ _ZN ShipSystem CheckDlcEnabled "` |
| **`++`** | **Simple Match for Demangled** | Search demangled name for **Simple Match** rules. | `"++ ^ShipSystem CheckDlcEnabled "` |
| **`#`** | **Regex Match** | Search raw name using `boost::regex`. | `"# ^_ZN10ShipSystem.*CheckDlcEnabledEv$ "` |
| **`##`** | **Regex Match for Demangled** | Search demangled name using `boost::regex`. | `"## ^ShipSystem.*CheckDlcEnabled "` |

> **Note:** Always prefer "Simple Match" (`+`/`++`) over Regex (`#`/`##`) unless you specifically need complex expression logic. Simple Match is significantly faster.

## Simple Match Rules

When using `+` or `++`, the scanner checks if the source string matches a sequence of tokens.

**Token Definition:**
A token is defined as a *word* (`[0-9a-zA-Z_:~]+`) or any single non-space character.

**Rules:**

1. **Delimiters:** Spaces are ignored and act as delimiters between tokens.
2. **Order:** Tokens must appear in the target string in the same order they are written (non-overlapping).
3. **Start Anchor (`^`):** If the pattern starts with `^`, the first token must match the *start* of the target string.
4. **End Anchor (`$`):** If the pattern ends with `$`, the last token must match the *end* of the target string.

**Example:**

* Pattern: `"++ ^ShipSystem GetManned "`
* Matches: `ShipSystem::GetMannedDescription(...)`
* Fails: `Other::ShipSystem::GetMannedDescription(...)` (because `ShipSystem` was not at the very start).

## Finding Symbols

To write these signatures, you need to know the symbol names. You can get the symbol table by:

* **Project Files:** Check the `.txt` files located in the `symtab/` folder of the Hyperspace project.
* **Using `nm`:** On Linux/macOS/Msys2, you can run `nm <FTLexeFile>` or `nm -C <FTLexeFile>` in a terminal to list all symbols in raw name or demangled name.
* **Ghidra:** Import the game executable binary to view the Symbol Table.

> **Important Note:** On Windows and macOS, raw mangled symbols often contain an extra leading underscore (`_`) compared to Linux. (Example: `_ZN10Ship...` vs `__ZN10Ship...`)
>
> When writing a Hyperspace signature, **remove the extra leading underscore** to ensure it matches across all platforms (and also because the internal symbol table of Hyperspace already removed them).
>
> The symbol table txt files in `symtab/` folder already removed these underscores, so you don't need to remove underscores if you get the symbol names there.

## The Hybrid Fallback

If the version of FTL does not contain a symbol table, you must usually provide a byte signature as a fallback.

You can do this by adding a separator (`||` or `->`) after the symbol name, followed by the legacy hex signature.

### Fallback Types

| Operator | Type | Behavior |
| :--- | :--- | :--- |
| **`\|\|`** | **Optional** | **"OR" Logic:** The scanner attempts Symbol Lookup first. If the symbol is found, the hex signature is ignored. If the symbol is missing, it runs the hex signature scan. |
| **`->`** | **Chained** | **"Anchor" Logic:** If the symbol is found, the scanner uses the symbol's address as the *start* point for the hex signature scan. If the symbol is missing, it behaves like `\|\|` (runs the hex scan globally). |

> **Note:** Do not use `->` if you are looking up a **global variable**. Use `||` for globals.

### Example: Hybrid Signature

We want to find `ShipSystem::DecreasePower`.

1. **Symbol:** `ShipSystem::DecreasePower(bool)`
2. **Fallback:** `578d7c...`

**Combined Signature:**

```zhl
// "++" searches for the demangled name using Simple Match.
// "||" tells it to use the hex string ONLY if the symbol isn't found.
"++ ShipSystem::DecreasePower || 578d7c240883e4f0ff77fc5589e557565383ec1c0fb681180100008b1f84c0":
__thiscall bool ShipSystem::DecreasePower(ShipSystem *this, bool force);
```

## Formal Grammar

```peg
# Root Definition
Signature       ← _ Lookup _ Fallback? EOF

# 1. The Lookup Segment
Lookup          ← Prefix _ Pattern

# Prefixes determine the internal search logic
Prefix          ← "@@"  # Exact Demangled
                / "@"   # Exact Raw
                / "##"  # Regex Demangled
                / "#"   # Regex Raw
                / "++"  # Simple Match Demangled
                / "+"   # Simple Match Raw

# The Pattern is the content used for the search.
# It consumes characters until it hits a Separator or EOF.
Pattern         ← (!Separator .)+

# 2. The Fallback Segment
Fallback        ← Separator _ HexSignature
Separator       ← "||" / "->"       # Optional / Chained

# 3. Primitives
_               ← [\t\n\v\f\r ]*    # Optional whitespace (ignored)
EOF             ← !.                # End of string
```
