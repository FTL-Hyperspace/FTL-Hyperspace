#!/usr/bin/env python3
"""Compare ZHL bound addresses against nm symbol addresses to find mismatches."""

import subprocess
import sys
import re
import fnmatch
from collections import defaultdict

# Intentional name mismatches: (ZHL name pattern, expected nm name pattern)
# Use * as wildcard for any characters (like glob patterns)
# Use {class} as placeholder for the class name extracted from ZHL name
# Use {method} as placeholder for the method name extracted from ZHL name
INTENTIONAL_MISMATCHES = [
    # Constructor/destructor overloads - ZHL uses numbered suffixes
    # {class} expands to the class name, so Foo::constructor -> Foo::Foo
    ('*::constructor', '{class}::{class}'),
    ('*::constructor1', '{class}::{class}'),
    ('*::constructor2', '{class}::{class}'),
    ('*::constructor_copy', '{class}::{class}'),
    ('*::constructorEmpty', '{class}::{class}'),
    ('*::constructorSystem', '{class}::{class}'),
    ('*::COPIED_constructor', '{class}::{class}'),
    ('*::destructor', '{class}::~{class}'),
    ('*::destructor2', '{class}::~{class}'),

    # Method overload naming variants
    ('ShipManager::AddCrewMember1', 'ShipManager::AddCrewMember'),
    ('ShipManager::AddCrewMember2', 'ShipManager::AddCrewMember'),
    ('ShipManager::AddCrewMemberFromString', 'ShipManager::AddCrewMember'),
    ('ShipManager::AddCrewMemberFromBlueprint', 'ShipManager::AddCrewMember'),
    ('ShipManager::GetSelectedCrewPoint', 'ShipManager::GetSelectedCrew'),
    ('ShipManager::ClearStatusAll', 'ShipManager::ClearStatus'),
    ('ShipManager::ClearStatusSystem', 'ShipManager::ClearStatus'),
    ('ShipSelect::GetSelectedShip', 'ShipSelect::GetSelection'),
    ('CompleteShip::AddCrewMember1', 'CompleteShip::AddCrewMember'),
    ('CompleteShip::AddCrewMember2', 'CompleteShip::AddCrewMember'),
    ('ScoreKeeper::AddTopScoreList', 'ScoreKeeper::AddTopScore'),
    ('ScoreKeeper::AddTopScoreType', 'ScoreKeeper::AddTopScore'),
    ('ResourceControl::GetImageId1', 'ResourceControl::GetImageId'),
    ('ResourceControl::RenderImageString', 'ResourceControl::RenderImage'),
    ('ResourceControl::CreateImagePrimitiveString', 'ResourceControl::CreateImagePrimitive'),
    ('InfoBox::SetSystemId', 'InfoBox::SetSystem'),
    ('InfoBox::SetBlueprintWeapon', 'InfoBox::SetBlueprint'),
    ('InfoBox::SetBlueprintDrone', 'InfoBox::SetBlueprint'),
    ('InfoBox::SetBlueprintAugment', 'InfoBox::SetBlueprint'),
    ('InfoBox::SetBlueprintCrew', 'InfoBox::SetBlueprint'),
    ('GL_Primitive::SetImagePath', 'GL_Primitive::SetImage'),
    ('CachedImage::SetImagePath', 'CachedImage::SetImage'),
    ('Button::OnInitRect', 'Button::OnInit'),
    ('TextButton::OnInitRect', 'TextButton::OnInit'),

    # Capitalization/spelling differences
    ('ShipManager::UpdateCrewMembers', 'ShipManager::UpdateCrewmembers'),
    ('CrewMemberFactory::CreateCrewMember', 'CrewMemberFactory::CreateCrewmember'),
    ('CrewMember::NeedsSlot', 'CrewMember::NeedSlot'),

    # Known binding issues (signature matches destructor)
    ('CrewMember::Cleanup', 'CrewMember::~CrewMember'),

    # Template naming differences
    ('Spreader_Fire::*', 'Spreader<Fire>::*'),

    # _orig suffix for hooked original functions
    ('*_orig', '*'),

    # CSurface static functions (appear without class prefix in nm)
    ('CSurface::*', '*'),
]

def parse_zhl_log(log_path):
    """Parse zhl.log and extract function name -> address mappings."""
    funcs = {}
    with open(log_path, 'r') as f:
        for line in f:
            # Match: Found address for Class::Method: 0x..., dist ...
            m = re.match(r'Found address for (.+): (0x[0-9a-fA-F]+)', line)
            if m:
                name = m.group(1)
                addr = int(m.group(2), 16)
                funcs[name] = addr
    return funcs

def parse_nm_output(binary_path):
    """Parse nm -C output and extract ALL function addresses."""
    result = subprocess.run(['nm', '-C', binary_path], capture_output=True, text=True)

    # Map: address -> list of function names at that address
    addr_to_funcs = defaultdict(list)
    # Map: short name -> list of (address, full_name)
    name_to_addrs = defaultdict(list)
    # Sorted list of all addresses for finding nearest
    all_addrs = []

    for line in result.stdout.splitlines():
        m = re.match(r'([0-9a-fA-F]+)\s+[tT]\s+(.+)', line)
        if m:
            addr = int(m.group(1), 16)
            full_name = m.group(2)
            addr_to_funcs[addr].append(full_name)
            all_addrs.append(addr)

            # Extract short name (Class::Method) - remove parameters
            paren_idx = full_name.find('(')
            if paren_idx > 0:
                short_name = full_name[:paren_idx]
            else:
                short_name = full_name
            name_to_addrs[short_name].append((addr, full_name))

    all_addrs = sorted(set(all_addrs))
    return addr_to_funcs, name_to_addrs, all_addrs

def find_nearest_function(addr, all_addrs, addr_to_funcs):
    """Find the function at or just before the given address."""
    # Binary search for nearest address <= target
    left, right = 0, len(all_addrs) - 1
    result_addr = None

    while left <= right:
        mid = (left + right) // 2
        if all_addrs[mid] <= addr:
            result_addr = all_addrs[mid]
            left = mid + 1
        else:
            right = mid - 1

    if result_addr is not None:
        funcs = addr_to_funcs.get(result_addr, [])
        offset = addr - result_addr
        return result_addr, funcs, offset
    return None, [], 0

def normalize_name(zhl_name):
    """Convert ZHL name to possible nm names for matching."""
    results = []

    # Handle numbered constructors (constructor1, constructor2, etc.)
    if '::constructor' in zhl_name:
        # Remove any trailing numbers
        base = re.sub(r'::constructor\d*', '', zhl_name)
        class_name = base.split('::')[-1]
        results.append(f'{base}::{class_name}')  # Class::Class
        results.append(base)  # Just the class name for matching
    elif '::destructor' in zhl_name:
        # Remove any trailing numbers
        base = re.sub(r'::destructor\d*', '', zhl_name)
        class_name = base.split('::')[-1]
        results.append(f'{base}::~{class_name}')  # Class::~Class
        results.append(base)
    else:
        results.append(zhl_name)

    return results

def extract_class_name(zhl_name):
    """Extract the class name from a ZHL function name like 'Namespace::Class::method'."""
    parts = zhl_name.split('::')
    if len(parts) >= 2:
        # Return the part before the last :: (the class name)
        # For 'Class::method' -> 'Class'
        # For 'Namespace::Class::method' -> 'Class'
        return parts[-2]
    return ''

def is_intentional_mismatch(zhl_name, actual_funcs):
    """Check if a mismatch is intentional (NoHook, naming variants, etc.)."""
    # NoHook functions are intentionally bound to arbitrary addresses
    if 'NoHook' in zhl_name:
        return True

    # Extract class name for {class} substitution
    class_name = extract_class_name(zhl_name)

    # Check against the intentional mismatches list
    for zhl_pattern, nm_pattern in INTENTIONAL_MISMATCHES:
        if fnmatch.fnmatch(zhl_name, zhl_pattern):
            # Substitute {class} placeholder with actual class name
            expected_pattern = nm_pattern.replace('{class}', class_name)

            # Check if any actual function matches the expected nm pattern
            for func in actual_funcs:
                # Strip parameters for matching
                func_short = func.split('(')[0] if '(' in func else func
                if fnmatch.fnmatch(func_short, expected_pattern):
                    return True
                # Also try matching without leading underscore (CSurface functions)
                if fnmatch.fnmatch(func_short.lstrip('_'), expected_pattern):
                    return True

    return False

def main():
    if len(sys.argv) < 3:
        print(f"Usage: {sys.argv[0]} <zhl.log> <binary>")
        sys.exit(1)

    zhl_path = sys.argv[1]
    binary_path = sys.argv[2]

    print(f"Parsing {zhl_path}...")
    zhl_funcs = parse_zhl_log(zhl_path)
    print(f"Found {len(zhl_funcs)} functions in zhl.log")

    print(f"Parsing nm output for {binary_path}...")
    addr_to_funcs, name_to_addrs, all_addrs = parse_nm_output(binary_path)
    print(f"Found {len(addr_to_funcs)} unique addresses in nm output")

    # Calculate ASLR slide using a known function
    slide = None
    for name in zhl_funcs:
        if 'DO_NOT_HOOK' in name or 'NoHook' in name:
            continue
        nm_names = normalize_name(name)
        for nm_name in nm_names:
            if nm_name in name_to_addrs:
                zhl_addr = zhl_funcs[name]
                nm_addr = name_to_addrs[nm_name][0][0]  # First match
                slide = zhl_addr - nm_addr
                print(f"\nCalculated ASLR slide: 0x{slide:x} (from {name})")
                break
        if slide is not None:
            break

    if slide is None:
        print("ERROR: Could not calculate ASLR slide")
        sys.exit(1)

    # Now verify each ZHL binding
    wrong_bindings = []
    correct = 0
    intentional = 0
    not_in_nm_but_ok = []  # Functions in middle of other functions (inlined, etc.)

    for name, zhl_addr in sorted(zhl_funcs.items()):
        if 'DO_NOT_HOOK' in name:
            continue

        # Convert ZHL address to file offset
        file_offset = zhl_addr - slide

        # Check what function is at that EXACT address according to nm
        funcs_at_addr = addr_to_funcs.get(file_offset, [])

        # Get expected nm names for this ZHL name
        expected_nm_names = normalize_name(name)

        # Check if any expected name matches what's at the bound address
        found_match = False
        for expected in expected_nm_names:
            for func_at_addr in funcs_at_addr:
                # Check if expected name is in the function name (handles overloads)
                if expected in func_at_addr or func_at_addr.startswith(expected + '('):
                    found_match = True
                    break
                # Also check without parameters
                func_short = func_at_addr.split('(')[0] if '(' in func_at_addr else func_at_addr
                if expected == func_short:
                    found_match = True
                    break
            if found_match:
                break

        if found_match:
            correct += 1
        elif funcs_at_addr:
            # Address has a function, but it's different from expected
            if is_intentional_mismatch(name, funcs_at_addr):
                intentional += 1
            else:
                wrong_bindings.append({
                    'name': name,
                    'zhl_addr': zhl_addr,
                    'file_offset': file_offset,
                    'expected': expected_nm_names,
                    'actual': funcs_at_addr,
                    'type': 'different_function',
                })
        else:
            # No function at exact address - find what's there
            nearest_addr, nearest_funcs, offset = find_nearest_function(file_offset, all_addrs, addr_to_funcs)

            # Check if function exists elsewhere in nm
            found_elsewhere = False
            for expected in expected_nm_names:
                if expected in name_to_addrs:
                    correct_addrs = [a for a, _ in name_to_addrs[expected]]
                    if file_offset not in correct_addrs:
                        # Function exists at different address!
                        wrong_bindings.append({
                            'name': name,
                            'zhl_addr': zhl_addr,
                            'file_offset': file_offset,
                            'expected': expected_nm_names,
                            'actual': [f"WRONG ADDR! Should be at: {', '.join(f'0x{a:x}' for a in correct_addrs[:3])}"],
                            'correct_addrs': correct_addrs,
                            'nearest': (nearest_addr, nearest_funcs, offset) if nearest_addr else None,
                            'type': 'wrong_address',
                        })
                        found_elsewhere = True
                        break

            if not found_elsewhere:
                # Address is in middle of another function or truly not in nm
                if nearest_addr and offset < 0x1000:  # Within 4KB of another function
                    # Could be inlined or internal - but let's report it
                    if offset > 0:  # Not at function start
                        wrong_bindings.append({
                            'name': name,
                            'zhl_addr': zhl_addr,
                            'file_offset': file_offset,
                            'expected': expected_nm_names,
                            'actual': [f"INSIDE: {nearest_funcs[0][:50]}... +0x{offset:x}"],
                            'nearest': (nearest_addr, nearest_funcs, offset),
                            'type': 'inside_other_function',
                        })
                    else:
                        not_in_nm_but_ok.append((name, nearest_addr, nearest_funcs, offset))
                else:
                    not_in_nm_but_ok.append((name, nearest_addr, nearest_funcs, offset))

    # Report results
    print(f"\n{'='*70}")
    print(f"RESULTS")
    print(f"{'='*70}")
    print(f"Correctly bound:      {correct}")
    print(f"Intentional naming:   {intentional}")
    print(f"PROBLEMS FOUND:       {len(wrong_bindings)}")
    print(f"Not in nm (ok):       {len(not_in_nm_but_ok)}")

    if wrong_bindings:
        # Group by type
        different_func = [w for w in wrong_bindings if w.get('type') == 'different_function']
        wrong_addr = [w for w in wrong_bindings if w.get('type') == 'wrong_address']
        inside_other = [w for w in wrong_bindings if w.get('type') == 'inside_other_function']

        if different_func:
            print(f"\n{'='*70}")
            print(f"!!! BOUND TO DIFFERENT FUNCTION ({len(different_func)}) !!!")
            print(f"{'='*70}")
            for wb in different_func:
                print(f"\n  {wb['name']}:")
                print(f"    ZHL bound to: 0x{wb['file_offset']:x}")
                print(f"    Expected:     {wb['expected']}")
                print(f"    ACTUALLY IS:  {wb['actual'][0][:70]}")
                for a in wb['actual'][1:2]:
                    print(f"                  {a[:70]}")

        if wrong_addr:
            print(f"\n{'='*70}")
            print(f"!!! BOUND TO WRONG ADDRESS ({len(wrong_addr)}) !!!")
            print(f"{'='*70}")
            for wb in wrong_addr:
                print(f"\n  {wb['name']}:")
                print(f"    ZHL bound to: 0x{wb['file_offset']:x}")
                print(f"    {wb['actual'][0]}")
                if wb.get('nearest'):
                    n_addr, n_funcs, n_off = wb['nearest']
                    print(f"    At bound addr: {n_funcs[0][:50]}... +0x{n_off:x}")

        if inside_other:
            print(f"\n{'='*70}")
            print(f"!!! BOUND INSIDE OTHER FUNCTION ({len(inside_other)}) !!!")
            print(f"{'='*70}")
            for wb in inside_other:
                print(f"\n  {wb['name']}:")
                print(f"    ZHL bound to: 0x{wb['file_offset']:x}")
                print(f"    {wb['actual'][0]}")

    if not_in_nm_but_ok:
        print(f"\n{'='*70}")
        print(f"Not found in nm (internal/synthetic): {len(not_in_nm_but_ok)}")
        print(f"{'='*70}")
        for name, nearest_addr, nearest_funcs, offset in not_in_nm_but_ok[:20]:
            if nearest_funcs:
                print(f"  {name}")
                print(f"    -> near: {nearest_funcs[0][:50]}...")
            else:
                print(f"  {name}")
        if len(not_in_nm_but_ok) > 20:
            print(f"  ... and {len(not_in_nm_but_ok) - 20} more")

if __name__ == '__main__':
    main()
