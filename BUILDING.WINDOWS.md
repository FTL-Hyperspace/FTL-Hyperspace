
1. Install CodeBlocks
2. Install mingw-builds mingw-w64 from http://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win32/Personal%20Builds/mingw-builds/installer/mingw-w64-install.exe/download
3. Setup the mingw-w64 GCC as CodeBlocks default GCC instead of CodeBlocks internal GCC as the built in GCC can't build for FTL correctly. (TODO: Add better steps of this)
4. While you can build Hyperspace with GCC it is not as optimized as building with LLVM-Clang, so also install LLVM-Clang 10 (not 11 or later) 32-bit
5. Set CodeBlocks to use the LLVM-Clang 32-bit instance you just installed as its default LLVM-Clang compiler.
6. Install Lua 5.3 & development headers (TODO: Provide more details)
7. Install `luarocks` and then install `luafilesystem` and `lpeg` with luarocks so you can generate code from the ZHL files.
8. Install Boost library (TODO: Provide details on where to install it to match other Hyperspace dev's paths)
9. Install SWIG 4 so it is somewhere on your path (https://www.swig.org/download.html) You probably have to download `swigwin-4.0.2` and place it somehwere on your system and add it to your PATH environment variable so Codeblocks can find it
10. Configure environment variables for Windows build (TODO: Provide details)
