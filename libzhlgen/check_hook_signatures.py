#!/usr/bin/env python3
"""Check every HOOK_* declaration against the definition ZHL will bind it to.

A definition is registered under its name plus its mangled signature, and a hook
looks itself up the same way, so a hook installs only when some definition of that
name carries exactly the signature the hook declares: parameter types, const on a
reference, reference versus pointer, and the return type all count. A mismatch is
a refused hook and a dead build rather than a silent misbind.

That check runs per platform, on the machine that launches the game. This one runs
over every FTLGame*.cpp separately, so a signature that only diverges on darwin or
win32 shows up here instead of on a player's machine.
"""

import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent

PLATFORM_SOURCES = {
    'linux64': 'FTLGameELF64.cpp',
    'linux32': 'FTLGameELF32.cpp',
    'darwin': 'FTLGameMacOSAMD64.cpp',
    'win32': 'FTLGameWin32.cpp',
    'ios_arm64': 'FTLGameiOSARM64.cpp',
}

# FTL for iPad, which Hyperspace runs on through the Android port (HS_ANDROID). Its
# definitions don't cover every function yet, and a hook on one they lack is left
# out at start-up (zhl.cpp) rather than failing, so only a mismatch counts there.
ANDROID = 'ios_arm64'

# static FunctionDefinition funcObj("Class::name", typeid(void (Class::*)(int )), ".55", ...
DEFINITION_RE = re.compile(r'FunctionDefinition funcObj\("([^"]+)",\s*typeid\(([^;]*?)\),\s*"')

# HOOK_METHOD(Class, name, (int x) -> void), plus the _PRIORITY, STATIC and GLOBAL forms
HOOK_RE = re.compile(r'\bHOOK_(METHOD|STATIC|GLOBAL)(_PRIORITY)?\s*\(')

# Words the parameter-name stripper must not mistake for a parameter's name.
BUILTIN_TYPE_RE = re.compile(r'unsigned|signed|long|short|int|char|float|double|bool|void')

# The headers that define the hook macros; their #defines look like calls.
MACRO_SOURCES = {'zhl.h', 'zhl_private.h', 'zhl_internal.h'}

COMMENT_RE = re.compile(r'/\*.*?\*/|//[^\n]*', re.S)

# Hooks behind a platform guard, and the platforms that therefore never compile
# them. Absence of a definition there is expected, not a fault. Add an entry when
# a guarded hook is reported below, with the guard that puts it here.
# Keyed by name and argument count: overloads share a name, so LockdownShard has
# three hooks called constructor and only the three-argument one is guarded.
# HS_ANDROID guards are read from the source instead (see android_guards).
NOT_COMPILED_ON = {
    ('LockdownShard::constructor', 3): {'darwin', ANDROID},        # CustomLockdowns.cpp #ifndef HS_APPLE_GAME
    ('ShipManager::IsSystemHacked2', 1): {'darwin', ANDROID},      # OxygenWithoutSystem.cpp #ifndef HS_APPLE_GAME
    ('DebugHelper::CrashCatcher', 1): {'darwin', 'linux32', 'linux64', ANDROID},  # Debugging.cpp #ifdef _WIN32
    ('Globals::GetNextSpaceId_orig', 0): {'linux32', 'linux64', 'win32'},  # SpaceId.cpp #else of #ifndef HS_APPLE_GAME
}

# Directories built only for Android, and ones Android builds leave out (CMakeLists.txt)
ANDROID_ONLY_DIRS = ('src/android/',)
NOT_ON_ANDROID_DIRS = ('src/features/sdl-test/', 'src/features/crash-detection/')

IF_RE = re.compile(r'#\s*(if|ifdef|ifndef|elif|else|endif)\b(.*)')


def read_paren_group(text, open_index):
    """Return what sits between the parens opening at open_index, and its close."""
    depth = 0
    for index in range(open_index, len(text)):
        if text[index] == '(':
            depth += 1
        elif text[index] == ')':
            depth -= 1
            if depth == 0:
                return text[open_index + 1:index], index
    return None, len(text)


def split_top_level(text):
    """Split on commas that are not nested in parens, angle brackets or subscripts."""
    parts, depth, current, previous = [], 0, '', ''
    for char in text:
        if char in '(<[':
            depth += 1
        # The > of a trailing return type closes nothing; only a template's does.
        elif char in ')]' or (char == '>' and previous != '-'):
            depth -= 1
        if char == ',' and depth == 0:
            parts.append(current.strip())
            current = ''
        else:
            current += char
        previous = char
    if current.strip():
        parts.append(current.strip())
    return parts


def tidy(text):
    """One spelling for a type, so both sides compare equal and still read well.

    Spacing is the only thing that varies: a typeid prints "const std::string &"
    and "std::pair<int, int>" where a hook may write either with or without the
    spaces. Collapsing around the punctuation settles both without gluing words
    like "unsigned int" together.
    """
    collapsed = re.sub(r'\s+', ' ', text).strip()
    return re.sub(r'\s*([*&,<>])\s*', r'\1', collapsed)


def normalize_type(text):
    """Reduce a parameter to its type alone, so both sides compare like for like.

    A hook writes "const std::string &path" where a typeid prints "const std::string &".
    Top-level const on a by-value parameter is not part of a function's type in C++,
    so it is dropped rather than compared.
    """
    stripped = re.sub(r'\b(volatile|struct|class)\b', ' ', text).strip()
    # A parameter name follows either a sigil that binds to it ("Ship *ship")
    # or plain whitespace ("int upgrade").
    named = (re.match(r'^(.*[\*&])\s*([A-Za-z_]\w*)$', stripped)
             or re.match(r'^(.*[\w>\]])\s+([A-Za-z_]\w*)$', stripped))
    if named and not BUILTIN_TYPE_RE.fullmatch(named.group(2)):
        stripped = named.group(1)
    stripped = stripped.strip()
    if not stripped.endswith('&') and not stripped.endswith('*'):
        stripped = re.sub(r'^\s*const\b', '', stripped)
    return tidy(stripped)


# A signature is (return type, argument types, is a member function). Equal
# signatures mean equal mangled names, which is what ZHL matches on.
def from_typeid(text):
    """'CrewMember *(CrewBox::*)(int , int )' as written in a generated file."""
    params_open = text.rfind(')(')
    if params_open == -1:
        return None
    body, _ = read_paren_group(text, params_open + 1)
    if body is None:
        return None
    head = text[:params_open + 1]
    return (tidy(head[:head.rfind('(')]),
            tuple(normalize_type(p) for p in split_top_level(body)),
            '::*' in head)


def from_hook(text, is_member):
    """'(int mouseX, int mouseY) -> CrewMember*' as written in a HOOK_* macro."""
    if not text.startswith('('):
        return None
    body, close = read_paren_group(text, 0)
    tail = text[close + 1:].strip()
    if body is None or not tail.startswith('->'):
        return None
    return (tidy(tail[2:]),
            tuple(normalize_type(p) for p in split_top_level(body)),
            is_member)


def describe(signature):
    """What a signature actually is, split into the two halves that can differ."""
    if signature is None:
        return 'unreadable typeid'
    ret, params, _ = signature
    return f'return: {ret}   args: {", ".join(params) if params else "(none)"}'


def collect_definitions(path):
    """Every definition in a generated file, grouped by the name it registers under."""
    grouped = {}
    for number, line in enumerate(path.read_text(errors='replace').splitlines(), 1):
        match = DEFINITION_RE.search(line)
        if match:
            grouped.setdefault(match.group(1), []).append(
                (from_typeid(match.group(2).strip()), number))
    return grouped


def android_guards(text):
    """For each line: 1 if only Android builds compile it, -1 if Android builds don't, else 0.

    Only HS_ANDROID is followed: #ifdef HS_ANDROID and its #else, #ifndef HS_ANDROID
    and its #else, and #elif defined(HS_ANDROID) after some other condition.
    """
    states, frames = [], []  # frames: [this branch's state, an earlier branch was HS_ANDROID]
    for line in text.split('\n'):
        match = IF_RE.match(line.strip())
        if match:
            word, rest = match.group(1), match.group(2)
            # (an "or" with anything else also compiles elsewhere, so it decides nothing)
            if '||' in rest:
                condition = 0
            elif re.search(r'!\s*defined\s*\(?\s*HS_ANDROID\b', rest):
                condition = -1
            else:
                condition = 1 if re.search(r'defined\s*\(?\s*HS_ANDROID\b', rest) else 0
            if word == 'ifdef':
                frames.append([1 if rest.split()[:1] == ['HS_ANDROID'] else 0, False])
            elif word == 'ifndef':
                frames.append([-1 if rest.split()[:1] == ['HS_ANDROID'] else 0, False])
            elif word == 'if':
                frames.append([condition, False])
            elif frames and word == 'elif':
                frame = frames[-1]
                frame[1] = frame[1] or frame[0] == 1
                frame[0] = 1 if condition == 1 else -1 if frame[1] else 0
            elif frames and word == 'else':
                frame = frames[-1]
                frame[1] = frame[1] or frame[0] == 1
                frame[0] = -1 if frame[1] else 1 if frame[0] == -1 else 0
            elif frames and word == 'endif':
                frames.pop()
        values = [frame[0] for frame in frames]
        states.append(1 if 1 in values else -1 if -1 in values else 0)
    return states


def collect_hooks():
    """Every HOOK_* in the tree, with the signature its author declared."""
    hooks = []
    for source in sorted(list(ROOT.rglob('*.cpp')) + list(ROOT.rglob('*.h'))):
        parts = source.parts
        if '.git' in parts or any(part.startswith('build-') for part in parts):
            continue
        if source.name.startswith('FTLGame') or source.name in MACRO_SOURCES:
            continue
        # Blank the comments, keeping newlines so line numbers still line up:
        # a hook inside /* ... */ is not a hook.
        text = COMMENT_RE.sub(lambda m: re.sub(r'[^\n]', ' ', m.group()),
                              source.read_text(errors='replace'))
        relative = source.relative_to(ROOT).as_posix()
        guards = android_guards(text)
        for match in HOOK_RE.finditer(text):
            line_start = text.rfind('\n', 0, match.start()) + 1
            if text[line_start:match.start()].lstrip().startswith('#define'):
                continue  # this is the macro's own definition
            body, _ = read_paren_group(text, match.end() - 1)
            if body is None:
                continue
            arguments = split_top_level(body)
            kind, has_priority = match.group(1), bool(match.group(2))
            # HOOK_GLOBAL registers a bare name; the others prefix the class.
            leading = (1 if kind == 'GLOBAL' else 2) + (1 if has_priority else 0)
            if len(arguments) <= leading:
                continue
            line = text.count('\n', 0, match.start()) + 1
            hooks.append({
                'name': arguments[0] if kind == 'GLOBAL' else f'{arguments[0]}::{arguments[1]}',
                'declared': arguments[leading],
                'signature': from_hook(arguments[leading], is_member=(kind == 'METHOD')),
                'where': f'{relative}:{line}',
                'android': (1 if relative.startswith(ANDROID_ONLY_DIRS) else
                            -1 if relative.startswith(NOT_ON_ANDROID_DIRS) else guards[line - 1]),
            })
    return hooks


def main():
    definitions = {}
    for platform, filename in PLATFORM_SOURCES.items():
        path = ROOT / 'generated' / filename
        if path.exists():
            definitions[platform] = collect_definitions(path)
    if not definitions:
        print('No FTLGame*.cpp found; run libzhlgen/parsefuncs.sh first.')
        return 1

    hooks = collect_hooks()
    print(f'Hooks: {len(hooks)} | platforms: {", ".join(definitions)}')

    mismatched, undefined = {}, {}
    counts = {platform: [0, 0, 0] for platform in definitions}

    # Each platform is judged on its own definitions: a name that exists only on
    # darwin is still missing on linux, and must be reported that way.
    for hook in hooks:
        if hook['signature'] is None:
            continue
        for platform, grouped in definitions.items():
            guard = (hook['name'], len(hook['signature'][1]))
            if platform in NOT_COMPILED_ON.get(guard, ()):
                continue
            if (hook['android'] == 1 and platform != ANDROID) or (hook['android'] == -1 and platform == ANDROID):
                continue  # behind HS_ANDROID, or kept out of Android builds by it
            candidates = grouped.get(hook['name'])
            if not candidates:
                counts[platform][2] += 1
                if platform != ANDROID:  # left out at start-up there, see ANDROID
                    undefined.setdefault(hook['where'], (hook['name'], []))[1].append(platform)
            elif any(signature == hook['signature'] for signature, _ in candidates):
                counts[platform][0] += 1
            else:
                counts[platform][1] += 1
                mismatched.setdefault(hook['where'], (hook, {}))[1][platform] = candidates

    for platform, (resolved, bad, missing) in counts.items():
        print(f'  {platform:<9} resolve {resolved:>5}   MISMATCH {bad:>4}   name not defined {missing:>4}')

    unparsed = [hook for hook in hooks if hook['signature'] is None]
    if unparsed:
        print(f'\nSkipped, could not parse: {len(unparsed)}')
        for hook in unparsed:
            print(f'  {hook["name"]}  [{hook["where"]}]  {hook["declared"]}')

    if undefined:
        print(f'\nNAME NOT DEFINED ON SOME PLATFORM: {len(undefined)}'
              f'  (fails to install unless the hook is behind a platform guard)')
        for where, (name, platforms) in sorted(undefined.items()):
            print(f'  {name}  [{where}]  missing on {", ".join(sorted(platforms))}')

    if mismatched:
        print(f'\nSIGNATURE MISMATCHES: {len(mismatched)}')
        for where, (hook, per_platform) in sorted(mismatched.items()):
            print(f'\n{hook["name"]}  [{where}]')
            print(f'  declared  {hook["declared"]}')
            print(f'  hook      {describe(hook["signature"])}')
            for platform in sorted(per_platform):
                for signature, line in per_platform[platform]:
                    print(f'  {platform:<9}  {describe(signature)}'
                          f'   {PLATFORM_SOURCES[platform]}:{line}')
        return 1

    print('\nEvery hook matches a definition signature on every platform.')
    return 0


if __name__ == '__main__':
    sys.exit(main())
