#!/usr/bin/env python3
"""Find ZHL bindings whose RVA changed between two zhl.log files (A should be the baseline).

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
)

# GNU nm only reads its host's formats. llvm-nm handles ELF, PE and Mach-O,
# matching compare_zhl_nm.py and allowing this script to run in the scanner
# Docker image for every supported platform.
NM = shutil.which("llvm-nm") or "nm"


def parse_zhl_log(path):
    """Return {ZHL function name: [runtime addresses]} from a zhl.log."""
    functions = defaultdict(list)
    with open(path, "r", encoding="utf-8", errors="replace") as stream:
        for line in stream:
            match = ADDRESS_RE.search(line)
            if match:
                functions[match.group(1)].append(int(match.group(2), 16))
    return functions


def nm_functions(binary):
    """Return symbol-name and address indexes from ``nm -C``."""
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
        # Include text symbols, including weak text symbols where available.
        match = re.match(r"^([0-9a-fA-F]+)\s+[tTwW]\s+(.+)$", line)
        if not match:
            continue
        address = int(match.group(1), 16)
        full_name = match.group(2)
        short_name = full_name.split("(", 1)[0]
        symbols[short_name].append(address)
        address_to_symbols[address].append(full_name)
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


def find_nm_address(name, symbols):
    for candidate in name_candidates(name):
        if candidate in symbols:
            return symbols[candidate][0]
    return None


def calculate_slide(functions, symbols):
    """Find the runtime-address minus nm-address load slide."""
    for name, runtime_addresses in functions.items():
        nm_address = find_nm_address(name, symbols)
        if nm_address is not None:
            return runtime_addresses[0] - nm_address, name
    return None, None


def rvas(functions, symbols, slide):
    """Convert log addresses to RVAs, using the calculated slide."""
    values = {}
    for name, runtime_addresses in functions.items():
        values[name] = [runtime_address - slide for runtime_address in runtime_addresses]
    return values


def main():
    if len(sys.argv) != 4:
        print(f"Usage: {sys.argv[0]} <zhl.log A> <zhl.log B> <FTL binary>")
        return 2

    log_a, log_b, binary = sys.argv[1:]
    try:
        functions_a = parse_zhl_log(log_a)
        functions_b = parse_zhl_log(log_b)
        symbols, address_to_symbols = nm_functions(binary)

        slide_a, source_a = calculate_slide(functions_a, symbols)
        slide_b, source_b = calculate_slide(functions_b, symbols)
        if slide_a is None or slide_b is None:
            raise RuntimeError(
                "Could not calculate the load slide for A or B from a common function found by nm"
            )

        rva_a = rvas(functions_a, symbols, slide_a)
        rva_b = rvas(functions_b, symbols, slide_b)

        missing_in_b = sorted(set(rva_a) - set(rva_b))
        missing_in_b = [name for name in missing_in_b if "DO_NOT_HOOK" not in name and "NoHook" not in name]
        mismatches = sorted(
            (name, rva_a[name], rva_b[name])
            for name in set(rva_a) & set(rva_b)
            if "DO_NOT_HOOK" not in name and "NoHook" not in name
            and not set(rva_a[name]) & set(rva_b[name])
        )

        print(f"A: {len(functions_a)} functions, slide 0x{slide_a:x} (from {source_a})")
        print(f"B: {len(functions_b)} functions, slide 0x{slide_b:x} (from {source_b})")
        print(f"nm: {sum(len(v) for v in symbols.values())} text symbols")
        print()
        print(f"RVA mismatches: {len(mismatches)}")
        for name, addresses_a, addresses_b in mismatches:
            print(f"  {name}")
            for address_a in addresses_a:
                actual_a = address_to_symbols.get(address_a, [])
                print(f"    A: 0x{address_a:x}")
                print(f"       nm: {', '.join(actual_a) if actual_a else '<no symbol at address>'}")
            for address_b in addresses_b:
                actual_b = address_to_symbols.get(address_b, [])
                print(f"    B: 0x{address_b:x}")
                print(f"       nm: {', '.join(actual_b) if actual_b else '<no symbol at address>'}")

        print(f"Missing in B: {len(missing_in_b)}")
        for name in missing_in_b:
            print(f"  {name}:")
            for address in rva_a[name]:
                actual = address_to_symbols.get(address, [])
                print(f"    A=0x{address:x}")
                print(f"      nm: {', '.join(actual) if actual else '<no symbol at address>'}")

        # B is expected to contain A, so functions that exist only in B are
        # intentionally not reported.
        return 0
    except (OSError, RuntimeError) as exc:
        print(f"ERROR: {exc}", file=sys.stderr)
        return 1


if __name__ == "__main__":
    sys.exit(main())
