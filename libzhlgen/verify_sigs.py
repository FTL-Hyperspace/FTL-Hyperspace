#!/usr/bin/env python3
"""Verify ZHL signatures against FTL binaries in ftl-bin/ without running the game.

Binaries are named ftl-bin/<os>/FTL-<version>-<store>-<arch>, e.g.
ftl-bin/darwin/FTL-1.6.12-gog-amd64, ftl-bin/windows/FTL-1.6.9-steam-x86.

    verify_sigs.py                       # everything under ftl-bin/ (or: verify_sigs.py all)
    verify_sigs.py linux                 # every linux binary
    verify_sigs.py linux-1.6.13-steam    # by any combination of os / version / store / arch,
    verify_sigs.py 1.6.13 steam x86      # separated by spaces or dashes

For each binary: run zhlscan with the platform's libftlgame module (the game's
own definition loading linked against that platform's generated FTLGame*.cpp)
to produce zhl.log, then run compare_zhl_nm.py on it. Both outputs land in
test_results/zhl_test/<os>-<binary name>/ (zhl.log, zhlscan.txt, compare.txt);
everything is also echoed to stdout.

zhlscan and the modules are built on demand in build-zhlscan/ (or
ZHLSCAN_BUILD_DIR): zhlscan/build.sh configures it the first time, after that
an incremental ninja build, so an edited signature costs one recompile. This
script never regenerates FTLGame*.cpp; run parsefuncs.sh after editing .zhl files.
zhlscan/run-in-docker.sh builds into its own build-zhlscan-docker/, so native
and container runs can share one checkout.
"""

import os
import subprocess
import sys
from dataclasses import dataclass
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parent
BIN_DIR = ROOT / 'ftl-bin'
BUILD_DIR = Path(os.environ.get('ZHLSCAN_BUILD_DIR', ROOT / 'build-zhlscan'))
CONFIGURE_SCRIPT = HERE / 'zhlscan' / 'build.sh'
COMPARE_SCRIPT = HERE / 'compare_zhl_nm.py'
RESULTS_DIR = ROOT / 'test_results' / 'zhl_test'

SCANNER_TARGET = 'zhlscan'

# Which generated FTLGame*.cpp applies to a binary, by (os directory, arch suffix).
MODULE_TARGETS = {
    ('darwin', 'amd64'): 'ftlgame-darwin',
    ('linux', 'amd64'): 'ftlgame-linux64',
    ('linux', 'x86'): 'ftlgame-linux32',
    ('windows', 'x86'): 'ftlgame-win32',
}

HEADER_RULE = '#' * 70


@dataclass
class GameBinary:
    """One file under ftl-bin/, e.g. ftl-bin/linux/FTL-1.6.13-steam-x86."""
    path: Path
    os_name: str
    version: str
    store: str
    arch: str

    @classmethod
    def from_path(cls, path):
        stem = path.name.removesuffix('.exe').removeprefix('FTL-')
        version, store, arch = stem.split('-')
        return cls(path, path.parent.name, version, store, arch)

    @property
    def display_name(self):
        return str(self.path.relative_to(BIN_DIR))

    @property
    def tokens(self):
        return {self.os_name, self.version, self.store, self.arch}

    @property
    def module_target(self):
        target = MODULE_TARGETS.get((self.os_name, self.arch))
        if target is None:
            sys.exit(f"{self.display_name}: no definitions module for os {self.os_name!r} arch {self.arch!r}")
        return target

    @property
    def results_dir(self):
        return RESULTS_DIR / f"{self.os_name}-{self.path.name.removesuffix('.exe')}"


def all_binaries():
    paths = sorted(path for path in BIN_DIR.glob('*/FTL-*') if path.is_file())
    return [GameBinary.from_path(path) for path in paths]


def select_binaries(filters):
    """Binaries whose {os, version, store, arch} contain every token in the filters."""
    wanted = set()
    for argument in filters:
        wanted.update(argument.replace('-', ' ').split())
    return [binary for binary in all_binaries() if wanted <= binary.tokens]


def ensure_configured():
    """Configure the build directory the first time; returns False if that fails."""
    if (BUILD_DIR / 'build.ninja').is_file():
        return True
    environment = dict(os.environ, ZHLSCAN_BUILD_DIR=str(BUILD_DIR))
    return subprocess.run([str(CONFIGURE_SCRIPT)], env=environment).returncode == 0


def build_targets(targets):
    """Incrementally build CMake targets; prints the compiler output and returns False on failure."""
    if not ensure_configured():
        return False
    result = subprocess.run(['ninja', '-C', str(BUILD_DIR), *targets], capture_output=True, text=True)
    if result.returncode != 0:
        print(result.stdout + result.stderr, end='', flush=True)
    return result.returncode == 0


def run_and_record(command, output_file):
    """Run a command, save its combined output next to the results, echo it; returns the process."""
    result = subprocess.run(command, capture_output=True, text=True)
    output = result.stdout + result.stderr
    output_file.write_text(output)
    print(output, end='', flush=True)
    return result


def scan(binary, log_path):
    """Run zhlscan with the binary's module; returns True if every signature resolved."""
    scanner = BUILD_DIR / SCANNER_TARGET
    module = BUILD_DIR / f'lib{binary.module_target}.so'
    result = run_and_record([str(scanner), str(module), str(binary.path), str(log_path)],
                            binary.results_dir / 'zhlscan.txt')
    if result.returncode != 0:
        print(f"zhlscan stopped at the first unresolved signature, see {log_path}", flush=True)
    return result.returncode == 0


def compare(binary, log_path):
    """Check the log against the binary's symbols; returns True if nothing is mis-bound."""
    result = run_and_record([sys.executable, str(COMPARE_SCRIPT), str(log_path), str(binary.path)],
                            binary.results_dir / 'compare.txt')
    return result.returncode == 0


def verify(binary):
    """True if the binary passes, False if it fails, None if its module cannot be built."""
    print(f"\n{HEADER_RULE}\n# {binary.display_name}\n{HEADER_RULE}", flush=True)
    binary.results_dir.mkdir(parents=True, exist_ok=True)

    if not build_targets([SCANNER_TARGET, binary.module_target]):
        print(f"SKIPPED: {binary.module_target} does not build", flush=True)
        return None

    log_path = binary.results_dir / 'zhl.log'
    scanned = scan(binary, log_path)
    compared = compare(binary, log_path)
    return scanned and compared


def report(outcomes):
    failed = [name for name, outcome in outcomes.items() if outcome is False]
    skipped = [name for name, outcome in outcomes.items() if outcome is None]
    verified = len(outcomes) - len(skipped)

    if skipped:
        print(f"\nSKIPPED: {', '.join(skipped)}")
    if failed:
        print(f"FAILED (unresolved or mis-bound signatures): {', '.join(failed)}", flush=True)
        sys.exit(1)
    if verified == 0:
        print("FAILED: nothing could be verified", flush=True)
        sys.exit(1)
    print(f"All {verified} scanned binaries bind every signature to the right function")


def main():
    arguments = sys.argv[1:]
    if arguments and arguments[0] in ('-h', '--help'):
        print(__doc__)
        return

    filters = [argument for argument in arguments if argument != 'all']
    binaries = select_binaries(filters)
    if not binaries:
        available = '\n  '.join(binary.display_name for binary in all_binaries())
        sys.exit(f"no binaries matching {' '.join(filters)!r} under {BIN_DIR}; available:\n  {available}")

    outcomes = {}
    for binary in binaries:
        outcomes[binary.display_name] = verify(binary)
    report(outcomes)


if __name__ == '__main__':
    main()
