# zhlscan

Checks ZHL signatures against FTL binaries without running the game.

`zhlscan` reads the code section of a game binary (Mach-O, PE or ELF, via LIEF)
and runs a `libftlgame-<platform>.so` module over it. Each module is one
platform's generated `FTLGame*.cpp` linked with the game's own definition
loading (`zhl_definitions.cpp`, `SigScan`, HDE), so the result is exactly what
`Definition::Init()` produces when Hyperspace starts: the same `zhl.log`.

`../verify_sigs.py` drives it: builds what is needed, scans each binary under
`ftl-bin/`, then runs `../compare_zhl_nm.py` to check every match against the
binary's symbols.

## Binaries

```
ftl-bin/<os>/FTL-<version>-<store>-<arch>
ftl-bin/darwin/FTL-1.6.13-steam-amd64
ftl-bin/linux/FTL-1.6.12-humble-x86
ftl-bin/windows/FTL-1.6.9-gog-x86
```

`ftl-bin/` is gitignored.

## Usage

### zhlscan

```
zhlscan <libftlgame-PLATFORM.so> <game binary> <zhl.log>
```

Loads the module, reads the binary's code section, resolves every definition
and writes `zhl.log`. Modules: `libftlgame-darwin.so`, `libftlgame-linux64.so`,
`libftlgame-linux32.so`, `libftlgame-win32.so`; use the one matching the game
binary. Exit code is 0 when every definition resolved, otherwise 1 with the
game's own error on stderr (`Failed to find address for function ...`) and
`zhl.log` holding the definitions resolved up to that point.

```
build-zhlscan/zhlscan build-zhlscan/libftlgame-darwin.so ftl-bin/darwin/FTL-1.6.13-steam-amd64 zhl.log
```

Addresses in `zhl.log` are pointers into the scanner's own copy of the code
section, not the game's; `compare_zhl_nm.py` derives the offset from a symbol
match. Distances (`dist`) are the same as in the game's log.

```
libzhlgen/compare_zhl_nm.py zhl.log ftl-bin/darwin/FTL-1.6.13-steam-amd64
```

### verify_sigs.py

```
libzhlgen/verify_sigs.py                    # all binaries
libzhlgen/verify_sigs.py linux              # one platform
libzhlgen/verify_sigs.py 1.6.13 steam x86   # any mix of os / version / store / arch
```

The first run configures and builds into `build-zhlscan/`; later runs rebuild
only what changed, so editing a signature costs one recompile. After editing
`.zhl` files run `libzhlgen/parsefuncs.sh` first; this tool never regenerates
`FTLGame*.cpp`.

Output per binary goes to `test_results/zhl_test/<os>-<name>/`:
`zhl.log`, `zhlscan.txt` (scanner messages), `compare.txt` (symbol comparison).

If the matching generated `tests/old_zhl_cpp/FTLGame<platform>.cpp` exists,
verification also builds and scans it. The old run writes `zhl-old.log`,
`zhlscan-old.txt`, and `compare-old.txt`. After both nm comparisons,
`find_new_zhl_mismap.py` runs with the old log first and writes
`find-new-zhl-mismap.txt`.

Exit code is 1 if any signature is unresolved or bound to the wrong function.

## Building

Needs CMake, Ninja, vcpkg and an x86_64 clang or gcc. The generated code uses
x86-only attributes, so the build targets x86_64 everywhere; on Windows that
means MinGW-w64, not MSVC.

```
libzhlgen/zhlscan/build.sh [VCPKG_ROOT]      # VCPKG_ROOT defaults to $VCPKG_ROOT, /vcpkg, ./vcpkg
```

### Docker

```
libzhlgen/zhlscan/run-in-docker.sh                              # build
libzhlgen/zhlscan/run-in-docker.sh libzhlgen/verify_sigs.py     # verify
```

Builds an image from the `Dockerfile` here (Ubuntu, clang, vcpkg with LIEF
prebuilt) and runs the command in it with the repository mounted. The
container builds into `build-zhlscan-docker/` so it does not interfere with a
native build. The Hyperspace devcontainer is not used: it pins GCC 4.8's
libstdc++, which cannot compile LIEF.

## Files

| | |
|---|---|
| `main.cpp` | `zhlscan`: loads a module, reads the binary, runs the scan |
| `CodeSection.*` | code section extraction with LIEF, mirroring each platform's `SigScan::Init()` |
| `DefinitionsModule.*` | the `zhlscan_run` entry point exported by every module |
| `CMakeLists.txt` | `zhlscan` plus `ftlgame-darwin`, `ftlgame-linux64`, `ftlgame-linux32`, `ftlgame-win32` |
| `stubs/` | `windows.h`/`io.h` stand-ins so `FTLGameWin32.cpp` compiles on other hosts |
