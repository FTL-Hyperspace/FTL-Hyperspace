## Building

Note that these instructions are a WIP so if you follow them, please report any issues you find and propose any recommendations (e.g., if you needed to perform an additional step or if you were able to omit a step).

We currently build in CodeBlocks... someone could setup CMake and or GNU Autotools for us but currently we don't use a makefile at all...
So, you'll need *CodeBlocks* installed

Install several libraries needed for building
Boost C++ library
SWIG 4
Lua 5.3

You need `gcc` and all the basic C dev stuff
***NOTE*** Unlike the Linux version, the Windows version of FTL was built with GCC 5.3.1, and newer versions of GCC and libstdc++ should also work.

### Installing GCC/MinGW
CodeBlocks comes with its own version of MinGW which includes GNU compilers. However we need a different version to build for FTL correctly:

1. Install mingw-builds mingw-w64 from http://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win32/Personal%20Builds/mingw-builds/installer/mingw-w64-install.exe/download
2. Setup the mingw-w64 GCC as CodeBlocks default GCC. This can be done by going to Settings -> Compiler..., select GNU GCC Compiler, select the "Toolchain executables" tab, then change the installation directory to the mingw-w64 you installed.

mingw32 should also work as FTL on Windows is 32-bit.

### Installing Clang
In the end you need MinGW for the libstdc++ library but we'll use LLVM-Clang for the actual build, as Clang is able to build an optimized DLL that works, but GCC cannot.

1. Install LLVM-Clang 10 (not 11 or later), 32-bit or 64-bit.
2. Set CodeBlocks to use the LLVM-Clang instance you just installed as its default LLVM-Clang compiler (same method as step 2 for installing MinGW).

### Installing Lua
Download lua 5.3 from lua.org, extract and follow the build instructions.

For Windows you may use the following steps after extraction:

1. Create a new CodeBlocks DLL project in the lua directory and add every file in the src directory except for lua.c (interpreter) and luac.c (compiler).
2. Set the project's compiler/linker build options to match those for Hyperspace.
3. Set the library target directory to the lib subdirectory.
4. Build Lua (remember to build for 32-bit, not 64-bit, if you've followed step 2 you should get a 32-bit build).
5. Copy the DLL to your FTL installation directory. The DLL is needed to run Hyperspace.

### Installing Boost
Download and extract the Boost library (currently it needs to be placed directly in C:, so C:\boost). Version 1.70 is known to work.

(TODO: Change the Boost path to use an environment variable like with FTL and Lua)

### Installing SWIG 4
Download and extract swigwin-4.0.2. Then add it to your PATH (either in CodeBlocks or system-wide).

### Building Hyperspace
Before you build Hyperspace you will need to configure the following environment variables (in addition to adding SWIG to your PATH):

1. FTL_PATH = C:\Path\To\FasterThanLight (replace with your actual path to the directory containing FTLGame.exe)
2. LUA_DIR = C:\Path\To\lua-5.3.6 (replace with your actual path)

Note that spaces and quotation marks are not allowed in these paths. If any directory name has a space (e.g., "Program Files"), you must replace it with the directory's 8.3 filename. You can use the command `dir /x` to show the short filenames in a directory alongside the long names.

There should already be build targets set up for building with either GCC or LLVM-Clang, either an unoptimized debug build or an optimized release build (optimized only with Clang).
Any compiler options or #defines required for each build target should already be configured (at least for LLVM-Clang; the GCC targets are deprecated).

You must have installed all of the above dependencies, including building Lua. If you've done everything right you should just be able to click the "Build" button in CodeBlocks and build Hyperspace successfully.

The DLL will automatically be placed in your FTL directory, overwriting any existing DLL.

## Building ZHL files (not required to build Hyperspace)
Install Lua
You'll also need luarocks to install some lua libraries

Install `luarocks` and then install `luafilesystem` and `lpeg` with luarocks.
Then you will be able to run libzhlgen\test\generate.bat
