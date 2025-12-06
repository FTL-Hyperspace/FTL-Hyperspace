# Symbol Lookups & Hybrid Signatures

## Overview

Traditionally, Hyperspace has relied on **byte signatures** (e.g., `578d7c...`) to find game functions. While effective, these signatures are "brittle". They are not compatible between different versions of FTL (Steam vs. GOG, Windows vs. Linux) and are unreadable to humans.

**Symbol Lookup** allows you to find functions by their **name** rather than their machine code.

* **Pros:** One signature often works for Linux, macOS, and older Windows versions simultaneously. It is much easier to read and debug.
* **Cons:** The newest Steam Windows version has stripped its symbols.
* **Solution:** Hyperspace supports a **hybrid** method. You can define a Symbol Lookup, but provide a byte signature as a fallback.

## Syntax Guide

The signature scanner determines the mode based on specific **prefix characters**.

### 1. Exact Matching

The fastest and safest method. Use this if you have the exact mangled or demangled name.

| Prefix | Type | Description | Example |
| :--- | :--- | :--- | :--- |
| **`@`** | **Symbol Name** | Matches the exact raw (mangled) symbol name. | `"@_ZN10ShipSystem15CheckDlcEnabledEv;"` |
| **`{}`** | **Demangled** | Matches the exact demangled name. Enclose in braces. | `"{ShipSystem::CheckDlcEnabled()}"` |

### 2. Pattern Matching (Search)

Useful if the exact name varies slightly between compiler versions, or if you only want to type part of the name.

| Prefix | Type | Description | Example |
| :--- | :--- | :--- | :--- |
| **`+`** | **Simple Match** | Search raw name for substrings (space-separated). | `"+ZN10ShipSystem 15CheckDlc"` |
| **`++`** | **Simple Match for Demangled** | Search human name for substrings (space-separated). | `"++ShipSystem CheckDlcEnabled"` |
| **`#`** | **Regex Match** | Search raw name using Regular Expressions. | `"#^_ZN10ShipSystem.*EnabledEv$"` |
| **`##`** | **Regex Match for Demangled** | Search human name using Regular Expressions. | `"##^ShipSystem::Get.*Description$"` |

> **Note:** "Simple Pattern" (`+`/`++`) is preferred over Regex (`#`/`##`) for performance reasons. It simply checks if the function name contains the words you provided.

---

## The Hybrid Fallback

If the version of FTL does not contain a symbol table, you must usually provide a generic byte signature as a fallback.

You can do this:

1. by adding a `>` character after the symbol name, followed by the old-style hex signature.
2. or before the match pattern, enclosed in `>Legacy_Hex_Signature<` syntax.

**Syntax:**
`"@Exact_Symbol_Name>Legacy_Hex_Signature"`
`"{Demangled_Name}>Legacy_Hex_Signature"`
`"+>Legacy_Hex_Signature<Simple_Symbol_Pattern"`
`"++>Legacy_Hex_Signature<Simple_Demangled_Pattern"`
`"#>Legacy_Hex_Signature<Regex_Symbol_Pattern"`
`"##>Legacy_Hex_Signature<Regex_Demangled_Pattern"`

**Example:**
We want to find `ShipSystem::DecreasePower`.

1. **Symbol:** `ShipSystem::DecreasePower(bool)` (Easy to read, works on Linux/Old Win).
2. **Fallback:** `578d7c...` (The raw bytes).

**Combined Signature:**

```zhl
"++>578d7c240883e4f0ff77fc5589e557565383ec1c0fb681180100008b1f84c0<ShipSystem::DecreasePower":
__thiscall bool ShipSystem::DecreasePower(ShipSystem *this, bool force);
```
