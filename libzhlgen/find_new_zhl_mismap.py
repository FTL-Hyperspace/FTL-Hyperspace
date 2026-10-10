#!/usr/bin/env python3
"""Find ZHL function/variable bindings whose RVA changed between two logs.

Usage:
    python find_new_zhl_mismap.py <zhl.log A> <zhl.log B> <FTL binary>
"""

import re
import subprocess
import sys
import shutil
from collections import defaultdict


ADDRESS_RE = re.compile(
    r"Found address for (.+?):\s+(0x[0-9a-fA-F]+)"
    r"(?:.*,\s+type\s+(\S+))?"
)
VALUE_RE = re.compile(
    r"Found value for (.+?):\s+(0x[0-9a-fA-F]+),\s+"
    r"scan\s+(0x[0-9a-fA-F]+)"
)
LEGACY_VALUE_RE = re.compile(
    r"Found value for (.+?):\s+(0x[0-9a-fA-F]+),\s+dist\s+"
)

# GNU nm only reads its host's formats. llvm-nm handles ELF, PE and Mach-O,
# matching compare_zhl_nm.py and allowing this script to run in the scanner
# Docker image for every supported platform.
NM = shutil.which("llvm-nm") or "nm"


def parse_zhl_log(path):
    """Return function and global-variable runtime address indexes."""
    functions = defaultdict(list)
    variable_scan_hits = defaultdict(list)
    legacy_variables = set()
    with open(path, "r", encoding="utf-8", errors="replace") as stream:
        for line in stream:
            match = ADDRESS_RE.search(line)
            if match:
                functions[(match.group(1), match.group(3) or "")].append(
                    int(match.group(2), 16))
                continue
            match = VALUE_RE.search(line)
            if match:
                variable_scan_hits[match.group(1)].append(
                    int(match.group(3), 16))
                continue
            match = LEGACY_VALUE_RE.search(line)
            if match:
                legacy_variables.add(match.group(1))
    return functions, variable_scan_hits, legacy_variables


def nm_functions(binary):
    """Return text-name and all-address indexes from ``nm -C``."""
    try:
        result = subprocess.run(
            [NM, "-C", binary],
            capture_output=True,
            text=True,
            check=True,
        )
    except FileNotFoundError:
        raise RuntimeError("llvm-nm/nm was not found. Add LLVM or binutils to PATH.")
    except subprocess.CalledProcessError as exc:
        message = exc.stderr.strip() or "nm failed"
        raise RuntimeError(message)

    symbols = defaultdict(list)
    address_to_symbols = defaultdict(list)
    for line in result.stdout.splitlines():
        # Keep every defined symbol for diagnostics, but only text/weak-text
        # symbols are eligible for calculating the ASLR slide.
        match = re.match(r"^([0-9a-fA-F]+)\s+([A-Za-z])\s+(.+)$", line)
        if not match:
            continue
        address = int(match.group(1), 16)
        symbol_type = match.group(2)
        full_name = match.group(3)
        address_to_symbols[address].append(full_name)
        if symbol_type not in "tTwW":
            continue
        short_name = full_name.split("(", 1)[0]
        symbols[short_name].append(address)
    return symbols, address_to_symbols


def name_candidates(name):
    """Return common nm spellings for ZHL constructor/destructor aliases."""
    candidates = [name]
    constructor = re.search(r"::constructor\d*$", name)
    destructor = re.search(r"::destructor\d*$", name)
    if constructor:
        base = name[:constructor.start()]
        cls = base.rsplit("::", 1)[-1]
        candidates.extend((f"{base}::{cls}", base))
    elif destructor:
        base = name[:destructor.start()]
        cls = base.rsplit("::", 1)[-1]
        candidates.extend((f"{base}::~{cls}", base))
    return candidates


def drop_types(bindings):
    """Re-key bindings by name alone, merging the overloads back together."""
    merged = defaultdict(list)
    for key, addresses in bindings.items():
        merged[(binding_name(key), "")].extend(addresses)
    return merged


def binding_name(key):
    """The plain name of a binding. Functions are keyed by name and type."""
    return key[0] if isinstance(key, tuple) else key


def find_nm_address(name, symbols):
    for candidate in name_candidates(name):
        if candidate in symbols:
            return symbols[candidate][0]
    return None


def calculate_slide(functions, symbols):
    """Find the runtime-address minus nm-address load slide."""
    for key, runtime_addresses in functions.items():
        nm_address = find_nm_address(binding_name(key), symbols)
        if nm_address is not None:
            return runtime_addresses[0] - nm_address, binding_name(key)
    return None, None


def rvas(bindings, slide):
    """Convert log addresses to RVAs, using the calculated slide."""
    values = {}
    for name, runtime_addresses in bindings.items():
        values[name] = [runtime_address - slide for runtime_address in runtime_addresses]
    return values


def compare_rvas(bindings_a, bindings_b, slide_a, slide_b, ignored_name=None):
    """Return baseline-only names and entries with disjoint RVA sets."""
    rva_a = rvas(bindings_a, slide_a)
    rva_b = rvas(bindings_b, slide_b)
    missing = sorted(set(rva_a) - set(rva_b))
    if ignored_name is not None:
        missing = [key for key in missing if not ignored_name(binding_name(key))]
    mismatches = sorted(
        (name, rva_a[name], rva_b[name])
        for name in set(rva_a) & set(rva_b)
        if (ignored_name is None or not ignored_name(binding_name(name)))
        and not set(rva_a[name]) & set(rva_b[name])
    )
    return rva_a, rva_b, missing, mismatches


def print_comparison(label, missing_label, mismatches, missing,
                     rva_a, address_to_symbols):
    print(f"{label} RVA mismatches: {len(mismatches)}")
    for name, addresses_a, addresses_b in mismatches:
        print(f"  {binding_name(name)}")
        for side, addresses in (("A", addresses_a), ("B", addresses_b)):
            for address in addresses:
                actual = address_to_symbols.get(address, [])
                print(f"    {side}: 0x{address:x}")
                print(f"       nm: {', '.join(actual) if actual else '<no symbol at address>'}")

    print(f"{missing_label}: {len(missing)}")
    for name in missing:
        print(f"  {binding_name(name)}:")
        for address in rva_a[name]:
            actual = address_to_symbols.get(address, [])
            print(f"    A=0x{address:x}")
            print(f"      nm: {', '.join(actual) if actual else '<no symbol at address>'}")


def main():
    if len(sys.argv) != 4:
        print(f"Usage: {sys.argv[0]} <zhl.log A> <zhl.log B> <FTL binary>")
        return 2

    log_a, log_b, binary = sys.argv[1:]
    try:
        functions_a, variables_a, legacy_variables_a = parse_zhl_log(log_a)
        functions_b, variables_b, legacy_variables_b = parse_zhl_log(log_b)
        symbols, address_to_symbols = nm_functions(binary)
        if not address_to_symbols:
            raise RuntimeError("nm returned no defined symbols")

        slide_a, source_a = calculate_slide(functions_a, symbols)
        slide_b, source_b = calculate_slide(functions_b, symbols)
        if slide_a is None or slide_b is None:
            raise RuntimeError(
                "Could not calculate the load slide for A or B from a common function found by nm"
            )

        # Types only tell the overloads of one name apart when both logs carry
        # them. A log written before ZHL reported types has none, and keying on
        # a type one side lacks would make every binding look moved.
        if not any(key[1] for key in functions_a) or not any(key[1] for key in functions_b):
            functions_a = drop_types(functions_a)
            functions_b = drop_types(functions_b)

        ignored = lambda name: "DO_NOT_HOOK" in name or "NoHook" in name
        rva_a, _, missing_in_b, mismatches = compare_rvas(
            functions_a, functions_b, slide_a, slide_b, ignored)
        variable_rva_a, _, variables_missing_in_b, variable_mismatches = \
            compare_rvas(variables_a, variables_b, slide_a, slide_b)

        print(f"A: {len(functions_a)} functions, {len(variables_a)} variables, "
              f"slide 0x{slide_a:x} (from {source_a})")
        print(f"B: {len(functions_b)} functions, {len(variables_b)} variables, "
              f"slide 0x{slide_b:x} (from {source_b})")
        print(f"nm: {sum(len(v) for v in symbols.values())} text symbols")
        if legacy_variables_a or legacy_variables_b:
            print("WARNING: variable scan locations are unavailable in legacy "
                  "logs; regenerate both logs with the updated scanner "
                  f"(A: {len(legacy_variables_a)}, B: {len(legacy_variables_b)})")
        print()
        print_comparison("Function", "Functions missing in B", mismatches,
                         missing_in_b, rva_a, address_to_symbols)
        print()
        print_comparison("Global variable signature-hit",
                         "Global variable scan entries missing in B",
                         variable_mismatches, variables_missing_in_b,
                         variable_rva_a, address_to_symbols)

        # B is expected to contain A, so functions that exist only in B are
        # intentionally not reported.
        return 0
    except (OSError, RuntimeError) as exc:
        print(f"ERROR: {exc}", file=sys.stderr)
        return 1


if __name__ == "__main__":
    sys.exit(main())
