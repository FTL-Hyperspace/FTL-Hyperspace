#!/usr/bin/env python3
"""
Compare HOOK_* declarations against FTLGame*.cpp definitions.
Catches return type mismatches like: bool vs int
"""

import re
import sys
from pathlib import Path

# Matches: "int ShipManager::CanUpgrade(int systemId, int amount)"
# Also:    "FUNC_NAKED bool ShipManager::CanFitSubsystem(int systemId)"
FUNC_DEF_RE = re.compile(r'''
    ^(?:FUNC_NAKED\s+)?   # optional FUNC_NAKED prefix
    ([\w\s\*&:<>]+?)      # return type (int, bool, void*, __int64, etc.)
    \s+
    (\w+)::(\w+)          # ClassName::FuncName
    \s*\([^)]*\)          # (params)
''', re.MULTILINE | re.VERBOSE)

# Matches: "HOOK_METHOD(ShipManager, CanUpgrade, (int systemId, int amount) -> int)"
HOOK_RE = re.compile(r'''
    HOOK_(METHOD|STATIC|GLOBAL)   # hook type
    \s*\(\s*
    (?:(\w+)\s*,\s*)?             # optional ClassName (not present for GLOBAL)
    (\w+)\s*,\s*                  # FuncName
    \([^)]*\)                     # (params)
    \s*->\s*
    ([^)]+)                       # return type
    \)
''', re.VERBOSE)

def normalize(t):
    t = ' '.join(t.split()).strip()
    t = t.replace('FUNC_NAKED ', '')  # calling convention, not a type
    return t

def extract_definitions(filepath):
    content = Path(filepath).read_text(errors='ignore')
    defs = {}
    for m in FUNC_DEF_RE.finditer(content):
        key = f"{m.group(2)}::{m.group(3)}"
        line = content[:m.start()].count('\n') + 1
        defs[key] = {'ret': normalize(m.group(1)), 'file': filepath, 'line': line}
    return defs

def extract_hooks(filepath):
    content = Path(filepath).read_text(errors='ignore')
    hooks = []
    for m in HOOK_RE.finditer(content):
        htype, cls, func, ret = m.groups()
        key = f"{cls}::{func}" if cls else func
        line = content[:m.start()].count('\n') + 1
        hooks.append({'type': f'HOOK_{htype}', 'key': key, 'ret': normalize(ret), 'file': filepath, 'line': line})
    return hooks

def main():
    root = Path(__file__).parent.parent

    # Collect definitions from platform files
    defs = {}
    for pf in root.glob('FTLGame*.cpp'):
        for k, v in extract_definitions(pf).items():
            defs.setdefault(k, []).append(v)

    # Collect hooks from source files
    hooks = []
    for ext in ['*.cpp', '*.h']:
        # Non-recursive in root
        for f in root.glob(ext):
            if not f.name.startswith('FTLGame'):
                hooks.extend(extract_hooks(f))
        # Recursive in src/ and tests/
        for d in ['src', 'tests']:
            for f in (root / d).glob(f'**/{ext}'):
                hooks.extend(extract_hooks(f))

    print(f"Definitions: {len(defs)} | Hooks: {len(hooks)}")

    # Find mismatches
    mismatches = {}
    for h in hooks:
        if h['key'] not in defs:
            continue
        for d in defs[h['key']]:
            if normalize(d['ret']).lower() != normalize(h['ret']).lower():
                loc = f"{h['file']}:{h['line']}"
                mismatches.setdefault(loc, {'hook': h, 'defs': []})['defs'].append(d)

    if not mismatches:
        print("No mismatches found!")
        return 0

    print(f"\n{'='*70}\nRETURN TYPE MISMATCHES: {len(mismatches)} unique\n{'='*70}")
    for loc, data in mismatches.items():
        h = data['hook']
        print(f"\n{h['type']} {h['key']}")
        print(f"  Hook: {h['file']}:{h['line']} -> {h['ret']}")
        for d in data['defs']:
            print(f"  Def:  {d['file']}:{d['line']} -> {d['ret']}")
    return 1

if __name__ == '__main__':
    sys.exit(main())
