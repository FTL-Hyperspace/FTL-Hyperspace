#!/usr/bin/env python3
"""Compare ZHL bound addresses against nm symbol addresses to find mismatches."""

import subprocess
import sys
import re
import fnmatch
import shutil
from collections import defaultdict

# Intentional name mismatches: (ZHL name pattern, expected nm name pattern)
# Use * as wildcard for any characters (like glob patterns)
# Use {class} as placeholder for the class name extracted from ZHL name
# Use {method} as placeholder for the method name extracted from ZHL name
# Use {class_nm} as placeholder for the class name extracted from the nm name
# Use {method_nm} as placeholder for the method name extracted from the nm name
INTENTIONAL_MISMATCHES = [
    # A constructor cannot be declared as a named method, so ZHL calls it
    # constructor. Every overload keeps that one name: their arguments differ,
    # so their typeids differ, and signature matching tells them apart.
    # {class} expands to the class name, so Foo::constructor -> Foo::Foo.
    ('*::constructor', '{class}::{class}'),

    # Darwin is the exception. It emits two machine-code copies of each
    # constructor where the other platforms emit one, so the second copy needs
    # its own name. The name constructor goes to the copy the game calls, which
    # is the one to hook. This is the unused copy.
    ('*::constructorAbiCopy', '{class}::{class}'),

    # Destructors take no arguments, so all three share one typeid and the
    # number is the only thing separating them: D2, D1 and D0.
    ('*::destructor', '{class}::~{class}'),
    ('*::destructor1', '{class}::~{class}'),
    ('*::destructor2', '{class}::~{class}'),


    # These are published to Lua and were so before signature matching was created.
    # Renaming them to what the binary calls the function would break every mod
    # that calls them, so the rename of these functions are not possible.
    ('ShipManager::AddCrewMemberFromString', 'ShipManager::AddCrewMember'),
    ('ShipManager::AddCrewMemberFromBlueprint', 'ShipManager::AddCrewMember'),
    ('ShipManager::GetSelectedCrewPoint', 'ShipManager::GetSelectedCrew'),
    ('ShipManager::ClearStatusAll', 'ShipManager::ClearStatus'),
    ('ShipManager::ClearStatusSystem', 'ShipManager::ClearStatus'),
    ('ResourceControl::RenderImageString', 'ResourceControl::RenderImage'),
    ('ResourceControl::CreateImagePrimitiveString', 'ResourceControl::CreateImagePrimitive'),
    ('CrewMember::NeedsSlot', 'CrewMember::NeedSlot'),

    # Known binding issues (signature matches destructor)
    ('CrewMember::Cleanup', 'CrewMember::~CrewMember'),

    # Template naming differences
    ('Spreader_Fire::*', 'Spreader<Fire>::*'),

    # CSurface statics demangle without the class prefix, so the class is
    # allowed to differ but the method name still has to match. Matching the nm
    # name against a bare * here would switch off name checking for all ~70
    # CSurface bindings, and a drifted one would report as correct.
    ('CSurface::*', 'CSurface::{method}'),
    ('CSurface::*', '{method}'),
    ('CSurface::_CreateImagePrimitive', 'CreateImagePrimitive'),

    # CSurface names the binary disagrees with. These two only surface on x86,
    # which keeps symbols for the plain C functions they wrap.
    ('CSurface::FinishFrame', 'sys_graphics_finish_frame'),
    ('CSurface::GL_OrthoProjection', 'graphics_set_parallel_projection'),


    # additions by ranhai
    ('ShipGraph::ConnectedGridSquaresPoint', 'ShipGraph::ConnectedGridSquares'),
    ('TextLibrary::FormatText_template_TextString', '_ZN11TextLibrary10FormatTextII10TextStringEEE*'),
    ('{class}::copy_assign_*', '{class}::operator='),  # ZHL copy assignment functions
    ('{class}::add_assign', '{class}::operator+='),  # ZHL operator+= functions
    ('*::__STRUCT_OVERRIDE_ANCHOR_*', '*'),  # Internal ZHL anchor functions
    # The game's original, kept under a suffix because HS owns the plain name on
    # that class: either its own implementation (FileHelper::fileLength,
    # Globals::GetNextSpaceId) or a wrapper that unpacks a packed return
    # (TextButton::GetSize and the ShipGraph ones on win32). Hook this, or call
    # it from the wrapper. Everything else must use the default function
    ('{class}::{method_nm}_orig', '{class}::{method_nm}'),
    ('{class}::{method_nm}0', '{class}::{method_nm}'),  # ZHL numbered overloads
    ('{class}::{method_nm}1', '{class}::{method_nm}'),  # ZHL numbered overloads
    ('{class}::{method_nm}2', '{class}::{method_nm}'),  # ZHL numbered overloads
    ('{class}::{method_nm}3', '{class}::{method_nm}'),  # ZHL numbered overloads
]

# Names whose declared type says nothing about the address they hold: anchors
# only keep a relative scan in step, NoHook entries point somewhere deliberately,
# and a variadic template's parameter pack is not written out on the ZHL side.
UNCHECKED_CALL_RE = re.compile(r'DO_NOT_HOOK|NoHook|__STRUCT_OVERRIDE_ANCHOR|_template_')

# Argument counts that differ from the binary on purpose, or that this check
# cannot read correctly.
UNCHECKED_CALL_NAMES = {
    # binary: LineRectCollide(Globals::Rect, Point, Point)
    # win32 also declares the hidden pointer x86 returns the Point through.
    'Globals::LineRectCollide',
    # binary: ConnectedGridSquares(int, int, int, int) and ConnectingDoor likewise
    # Declared as two Points, which is the same stack layout on x86.
    'ShipGraph::ConnectedGridSquaresPoint',
    'ShipGraph::ConnectingDoor',
}

LIBCPP_STRING_RE = re.compile(
    r'std::(?:(?:__1|__cxx11)::)?basic_string\s*<\s*char\s*,\s*'
    r'std::(?:(?:__1|__cxx11)::)?char_traits\s*<\s*char\s*>\s*,\s*'
    r'std::(?:(?:__1|__cxx11)::)?allocator\s*<\s*char\s*>\s*>'
)


def normalize_standard_library_types(value):
    """Collapse ABI-specific standard-library spellings used by demanglers."""
    return LIBCPP_STRING_RE.sub('std::string', value)

def encode_template_arguments(arguments):
    """Encode template arguments exactly like parsefuncs.lua does.

    Concrete function specializations cannot be represented directly by the
    ZHL parser, so parsefuncs rewrites ``Method<std::string, int>`` to
    ``Method_template_std_string_int``. Apply the same lossy encoding to nm's
    demangled name before comparing it with the generated ZHL name.
    """
    arguments = normalize_standard_library_types(arguments)
    suffix = re.sub(r'[^A-Za-z0-9_]', '_', arguments)
    suffix = re.sub(r'_+', '_', suffix)
    return suffix.strip('_')

def normalize_nm_template_name(function_name):
    """Convert a demangled function template name to parsefuncs' ZHL form.

    Only the template argument list attached to the method is rewritten;
    templates in its class/namespace or parameter types are left untouched.
    ``function_name`` may be either a short name or a full nm signature.
    """
    angle_depth = 0
    parameter_start = -1
    method_start = 0
    index = 0
    while index < len(function_name):
        char = function_name[index]
        if char == '<':
            angle_depth += 1
        elif char == '>':
            angle_depth = max(0, angle_depth - 1)
        elif char == '(' and angle_depth == 0:
            parameter_start = index
            break
        elif (char == ':' and index + 1 < len(function_name)
              and function_name[index + 1] == ':' and angle_depth == 0):
            method_start = index + 2
            index += 1
        index += 1

    qualified_name = (function_name if parameter_start < 0
                      else function_name[:parameter_start])
    parameters = '' if parameter_start < 0 else function_name[parameter_start:]
    template_start = qualified_name.find('<', method_start)
    if template_start < 0:
        return function_name

    depth = 0
    template_end = None
    for index in range(template_start, len(qualified_name)):
        char = qualified_name[index]
        if char == '<':
            depth += 1
        elif char == '>':
            depth -= 1
            if depth == 0:
                template_end = index
                break
    if template_end is None:
        return function_name

    arguments = qualified_name[template_start + 1:template_end]
    suffix = encode_template_arguments(arguments)
    if not suffix:
        return function_name
    return (qualified_name[:template_start] + '_template_' + suffix
            + qualified_name[template_end + 1:] + parameters)

def strip_demangled_return_type(function_name):
    """Remove a demangled return type while preserving spaces inside templates.

    GNU/LLVM nm commonly prints the return type for function template
    specializations, for example ``std::vector<Foo> Class::Method<Foo>``.
    Non-template methods normally do not have that prefix. The last whitespace
    outside angle brackets separates the return type from the qualified name.
    """
    angle_depth = 0
    parameter_start = len(function_name)
    for index, char in enumerate(function_name):
        if char == '<':
            angle_depth += 1
        elif char == '>':
            angle_depth = max(0, angle_depth - 1)
        elif char == '(' and angle_depth == 0:
            parameter_start = index
            break

    callable_name = function_name[:parameter_start]
    parameters = function_name[parameter_start:]
    angle_depth = 0
    separator = -1
    for index, char in enumerate(callable_name):
        if char == '<':
            angle_depth += 1
        elif char == '>':
            angle_depth = max(0, angle_depth - 1)
        elif char.isspace() and angle_depth == 0:
            separator = index
    if separator < 0:
        return function_name
    return callable_name[separator + 1:] + parameters

def normalize_nm_template_callable(function_name):
    """Return a template symbol in the synthetic form used by parsefuncs."""
    normalized = normalize_nm_template_name(function_name)
    if normalized == function_name:
        return function_name
    return strip_demangled_return_type(normalized)

def parse_zhl_log(log_path):
    """Parse zhl.log into (name, address, mangled type) for every binding.

    A list rather than a name -> address dict because overloads share a name:
    ZHL tells them apart by type, so InfoBox::SetBlueprint is five bindings at
    five addresses. The type is absent from logs written before ZHL started
    reporting it, and is None then.
    """
    entries = []
    with open(log_path, 'r') as f:
        for line in f:
            # Found address for Class::Method: 0x..., dist ...[, type ...]
            m = re.match(r'Found address for (.+?): (0x[0-9a-fA-F]+),'
                         r'.*?(?:, type (\S+))?$', line.rstrip())
            if m:
                entries.append((m.group(1), int(m.group(2), 16), m.group(3)))
    return entries

# GNU nm only reads its host's formats; llvm-nm reads Mach-O, PE and ELF alike.
# macOS's nm already is llvm-nm, so this only matters on Linux (e.g. in Docker).
NM = shutil.which('llvm-nm') or 'nm'

# ---------------------------------------------------------------------------
# Call-compatibility check
#
# Landing on the right address only proves ZHL found the function, not that it
# describes it in a way that is safe to call. What makes a call go wrong is
# passing the wrong number of arguments, or passing them in the wrong kind of
# register, so that is what gets compared: how each parameter is passed, not how
# it is spelled. A reference, a pointer, an integer and a class passed by hidden
# reference all occupy one integer slot, which is why "const std::string &"
# against "std::string" is not a fault. Floating point by value is the one that
# lands somewhere else.
#
# Return types are not mangled for ordinary functions, so the binary says
# nothing about them and they cannot be checked here.

# GCC emits specialised copies under the original's name. The demangled name
# describes the original, not the copy, so its parameters say nothing about what
# the copy takes: .constprop drops arguments that were folded away.
# The suffixes chain, as in "(.part.220.constprop.330)".
CLONE_SUFFIX_RE = re.compile(r'\s*\((\.(part|constprop|isra|cold)\.\d+)+\)\s*$')

def split_parameters(text):
    """Split a parameter list on commas that are not nested in brackets."""
    parts, depth, current = [], 0, ''
    for char in text:
        if char in '<([':
            depth += 1
        elif char in '>)]':
            depth -= 1
        if char == ',' and depth == 0:
            parts.append(current.strip())
            current = ''
        else:
            current += char
    if current.strip():
        parts.append(current.strip())
    return parts

def passing_classes(parameters):
    """How each parameter is passed: F for floating point, W for a word."""
    classes = []
    for parameter in parameters:
        value = re.sub(r'\s+', ' ', parameter).strip()
        if not value or value == 'void':
            continue
        if '*' in value or '&' in value or '[' in value:
            classes.append('W')
            continue
        value = re.sub(r'\bconst\b', '', value).strip()
        classes.append('F' if value in ('float', 'double', 'long double') else 'W')
    return tuple(classes)

def trailing_parameter_list(text):
    """The parameter list of the call that closes the end of a signature."""
    value = re.sub(r'\s*\[abi:[^\]]*\]', '', text.strip())
    value = CLONE_SUFFIX_RE.sub('', value)
    value = re.sub(r'\s+const$', '', value)
    if not value.endswith(')'):
        return None
    depth = 0
    for index in range(len(value) - 1, -1, -1):
        if value[index] == ')':
            depth += 1
        elif value[index] == '(':
            depth -= 1
            if depth == 0:
                return split_parameters(value[index + 1:-1])
    return None

def declared_parameter_list(demangled_type):
    """'f(void (InfoBox::*)(A, B))' -> the parameters of the function type."""
    if not demangled_type.startswith('f(') or not demangled_type.endswith(')'):
        return None
    inner = demangled_type[2:-1].rstrip()
    opening = inner.rfind(')(')
    if opening == -1 or not inner.endswith(')'):
        return None
    return split_parameters(inner[opening + 2:-1])

def demangle_types(mangled_types):
    """Demangle bare type manglings by wrapping each as a function taking it.

    typeid gives a mangled type, and the two sides use different dialects for
    the same type: the scanner's standard library mangles std::string in full
    where the game's abbreviates it. Demangling puts both in one spelling.
    """
    if not mangled_types:
        return {}
    demangler = shutil.which('llvm-cxxfilt') or shutil.which('c++filt')
    if not demangler:
        return {}
    ordered = sorted(mangled_types)
    # Mach-O tools want the leading underscore that its symbols carry.
    for prefix in ('__Z1f', '_Z1f'):
        result = subprocess.run([demangler], input='\n'.join(prefix + t for t in ordered),
                                capture_output=True, text=True)
        lines = result.stdout.splitlines()
        if len(lines) == len(ordered) and lines[0].startswith('f('):
            return dict(zip(ordered, lines))
    return {}

def call_compatibility_fault(name, demangled_type, functions_at_address):
    """The mismatch when no function here can be called as declared."""
    parameters = declared_parameter_list(demangled_type)
    if parameters is None:
        return None
    declared = passing_classes(parameters)
    actual = []
    for function in functions_at_address:
        # A clone's demangled name describes the original, so it proves nothing.
        if CLONE_SUFFIX_RE.search(function):
            return None
        found = trailing_parameter_list(function)
        if found is None:
            return None  # nothing to compare against
        actual.append((passing_classes(found), function))
    if not actual:
        return None
    if any(classes == declared for classes, _ in actual):
        return None
    return {'name': name, 'declared': declared,
            'actual': actual[0][0], 'nm_name': actual[0][1]}



def parse_nm_output(binary_path):
    """Parse nm -C output and extract ALL function addresses."""
    result = subprocess.run([NM, '-C', binary_path], capture_output=True, text=True)

    # Map: address -> list of function names at that address
    addr_to_funcs = defaultdict(list)
    # Map: short name -> list of (address, full_name)
    name_to_addrs = defaultdict(list)
    # Sorted list of all addresses for finding nearest
    all_addrs = []

    for line in result.stdout.splitlines():
        # t/T: text symbols; w/W: weak ones, which is how GCC emits inline and
        # virtual methods defined in headers on Linux.
        m = re.match(r'([0-9a-fA-F]+)\s+[tTwW]\s+(.+)', line)
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
            normalized_template_name = normalize_nm_template_callable(short_name)
            if normalized_template_name != short_name:
                name_to_addrs[normalized_template_name].append((addr, full_name))

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

def itanium_mangled(qualified_name):
    """``Class::Method`` as it appears inside an Itanium-mangled symbol: ``5Class6Method``.

    nm -C cannot demangle stdcall-decorated symbols such as
    ``__ZN11DebugHelper12CrashCatcherEP19_EXCEPTION_POINTERS@4``, so match those raw."""
    return ''.join(f'{len(part)}{part}' for part in qualified_name.split('::'))

NOP_PREFIX = 'Global__NOP__'

def nop_target(zhl_name):
    """``Class::Method`` a NOP region is meant to patch, from ``Global__NOP__Class_Method[_N]``."""
    parts = zhl_name[len(NOP_PREFIX):].split('_')
    if parts and parts[-1].isdigit():
        parts.pop()
    return '::'.join(parts)

def nop_inside_target(zhl_name, nearest_funcs):
    """A NOP region sits inside a function by design; it must be the one it is named after."""
    target = nop_target(zhl_name)
    return any(func.split('(')[0] == target for func in nearest_funcs)

def normalize_name(zhl_name):
    """Convert ZHL name to possible nm names for matching.

    Constructors and destructors used to be rewritten here to Class::Class. That
    hid them from INTENTIONAL_MISMATCHES, so a spelling nobody had listed still
    passed silently, which is how constructor3 came to be checked by nothing at
    all. They are ordinary listed exceptions now.
    """
    return [zhl_name]

def extract_class_name(function_name):
    """Extract the immediate class name from ``Namespace::Class::method``."""
    parts = function_name.split('::')
    if len(parts) >= 2:
        # Return the part before the last :: (the class name)
        # For 'Class::method' -> 'Class'
        # For 'Namespace::Class::method' -> 'Class'
        return parts[-2]
    return ''

def extract_method_name(function_name):
    """Extract the method name from a qualified ZHL or nm function name."""
    return function_name.rsplit('::', 1)[-1]

def substitute_placeholders(pattern, zhl_name, nm_name=None):
    """Expand name placeholders in an intentional-mismatch pattern."""
    replacements = {
        '{class}': extract_class_name(zhl_name),
        '{method}': extract_method_name(zhl_name),
    }
    if nm_name is not None:
        replacements.update({
            '{class_nm}': extract_class_name(nm_name),
            '{method_nm}': extract_method_name(nm_name),
        })
    for placeholder, value in replacements.items():
        pattern = pattern.replace(placeholder, value)
    return pattern

def is_intentional_mismatch(zhl_name, actual_funcs):
    """Check if a mismatch is intentional (NoHook, naming variants, etc.)."""
    # NoHook functions are intentionally bound to arbitrary addresses
    if 'NoHook' in zhl_name:
        return True

    # Check against the intentional mismatches list
    for zhl_pattern, nm_pattern in INTENTIONAL_MISMATCHES:
        # nm-derived placeholders can occur on either side of the rule, so an
        # actual nm candidate must be selected before expanding both patterns.
        for func in actual_funcs:
            # Strip parameters for matching
            func_short = func.split('(')[0] if '(' in func else func
            expanded_zhl_pattern = substitute_placeholders(
                zhl_pattern, zhl_name, func_short)
            if not fnmatch.fnmatch(zhl_name, expanded_zhl_pattern):
                continue

            expected_pattern = substitute_placeholders(
                nm_pattern, zhl_name, func_short)
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
    for name, zhl_addr, _mangled_type in zhl_funcs:
        if 'DO_NOT_HOOK' in name or 'NoHook' in name:
            continue
        nm_names = normalize_name(name)
        for nm_name in nm_names:
            if nm_name in name_to_addrs:
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
    call_faults = []

    demangled_types = demangle_types({t for _, _, t in zhl_funcs if t})

    for name, zhl_addr, mangled_type in sorted(zhl_funcs):
        if 'DO_NOT_HOOK' in name:
            continue

        if (mangled_type and not UNCHECKED_CALL_RE.search(name)
                and name not in UNCHECKED_CALL_NAMES):
            here = addr_to_funcs.get(zhl_addr - slide, [])
            demangled = demangled_types.get(mangled_type)
            if here and demangled:
                fault = call_compatibility_fault(name, demangled, here)
                if fault:
                    call_faults.append(fault)

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
                # The name must end where the parameter list or an ABI tag begins
                # (a plain substring test let GetFlag match GetFlagValue). Mach-O
                # and PE prefix C symbols with an underscore.
                if re.match('_?' + re.escape(expected) + r'(\(|\[abi:|$)', func_at_addr):
                    found_match = True
                    break
                if itanium_mangled(expected) in func_at_addr:
                    found_match = True
                    break
                # Also check without parameters
                func_short = func_at_addr.split('(')[0] if '(' in func_at_addr else func_at_addr
                if expected == func_short:
                    found_match = True
                    break
                if expected == normalize_nm_template_callable(func_short).lstrip('_'):
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
                    if name.startswith(NOP_PREFIX):
                        misplaced = not nop_inside_target(name, nearest_funcs)
                    else:
                        misplaced = offset > 0  # Not at function start
                    if misplaced:
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
    print(f"UNSAFE TO CALL:       {len(call_faults)}")
    print(f"Not in nm (ok):       {len(not_in_nm_but_ok)}")

    if call_faults:
        print(f"\n{'='*70}")
        print(f"!!! CANNOT BE CALLED AS DECLARED ({len(call_faults)}) !!!")
        print(f"{'='*70}")
        print("W is a word (integer, pointer, reference), F is floating point.")
        for fault in call_faults:
            print(f"\n  {fault['name']}:")
            print(f"    declared takes: {' '.join(fault['declared']) or '(nothing)'}")
            print(f"    binary takes:   {' '.join(fault['actual']) or '(nothing)'}")
            print(f"    which is:       {fault['nm_name'][:66]}")

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

    sys.exit(1 if wrong_bindings or call_faults else 0)

if __name__ == '__main__':
    main()
