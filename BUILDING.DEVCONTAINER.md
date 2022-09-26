## Current support matrix

```
                          Windows            Linux 64 bit       Linux 32 bit
clang-10 Debug (ld)       link fails (*1-1)  MV runs            Crashes at startup (*2)
clang-10 Release (ld)     MV runs (*3)       MV runs            Crashes at startup (*2)
clang-10 Debug (lld)      link fails (*1-2)  MV runs
clang-10 Release (lld)    link fails (*1-2)  MV runs            Crashes at startup (*2)
clang-14 Debug            ICE (*4)           ICE (*4)           ICE (*4)
clang-14 Release (lld)    MV runs            MV runs            Crashes at startup (*2)
```
ld: `ld` or `i686-w64-mingw32-ld`
lld: LLVM linker

*1: See https://github.com/msys2/MINGW-packages/issues/6855#issuecomment-680859662 for analysis on the similar issue

*1-1: `/usr/lib/gcc/i686-w64-mingw32/9.4-posix/libstdc++.a(...): duplicate section '.rdata$<mangled name from libstdc++, e.g., _ZTSSt9exception[__ZTSSt9exception]>' has different size`

*1-2: `lld-link: error: duplicate symbol: typeinfo name for <something from libstdc++ e.g., std::exception>`

*2: ```
ELF Relocation addr: 0x00000000
ELF Loaded at 0x08048000, 0x08048000
SEG SIZE: 0x0000000000001000                       <- repeats for nearly 1100 times
Fatal Error Failed to find address for function OptionsScreen::Open:```

*3: Spews out mostly the same linker messages as 1-1 but weirdly it does build and run fine.

*4: Compiler crashes (https://github.com/llvm/llvm-project/issues/56126)

## Building on VSCode devcontainer 

Open the directory using VSCode w/ Remote Container extension enabled and active. That's all!

## Manually building without VSCode

Requires Docker.

1. `docker build -t hyperspace .devcontainer`

2. `docker run -it --rm -v $PWD:/ftl hyperspace`
(`$PWD` may vary by your shell, e.g. if it's cmd then use `%cd%` instead)

3. `cd /ftl`

4. Configure with CMake. The exact command should depend on what build you're targeting. For example, Linux amd64 Release build is:
```
cmake -DCMAKE_TOOLCHAIN_FILE=/vcpkg/scripts/buildsystems/vcpkg.cmake -DVCPKG_HOST_TRIPLET=amd64-linux-ftl -DVCPKG_TARGET_TRIPLET=amd64-linux-ftl -DVCPKG_CHAINLOAD_TOOLCHAIN_FILE=/vcpkg/scripts/toolchains/amd64-linux-ftl.cmake -DCMAKE_BUILD_TYPE=Release -S . -B build -G Ninja
```
`-DCMAKE_BUILD_TYPE=Release` controls if it's debug or release build. Replace those `amd64-linux-ftl` to either `x86-linux-ftl` or `x86-windows-ftl` to change the platform target.

5. `ninja -C build`

### Rebuilding steps

- On changing source code, just redo the step 5 (`ninja`).
- On changing CMakeLists.txt (adding source files or macro definitions, etc.), redo from step 4 (`cmake`).
- On changing the build target (like changing to linux build or debug build), delete build/ directory (for clean rebuild) and then redo from step 4 (`cmake`).
- On changing the compiler toolchain files in the .devcontainer folder, delete build/ directory (for clean rebuild) and then redo from step 1 (`docker build`).
