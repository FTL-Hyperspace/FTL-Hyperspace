set(CMAKE_SYSTEM_NAME Windows)

string(CONCAT _compiler_flags
"-target i686-w64-mingw32 -nostdinc"

# clang++-10 -E -x c -v - < /dev/null
# This should override xmmintrin.h so that gcc intrinsics for vector instructions are not used
" -isystem /usr/lib/llvm-10/lib/clang/10.0.0/include"
# Force mingw to use clang intrinsics
# REF: https://github.com/msys2/MINGW-packages/issues/9052#issuecomment-756456305
" -D__MINGW_FORCE_SYS_INTRINS"

# i686-w64-mingw32-g++-posix -E -x c++ - -v < /dev/null
" -isystem /usr/lib/gcc/i686-w64-mingw32/9.3-posix/include/c++"
" -isystem /usr/lib/gcc/i686-w64-mingw32/9.3-posix/include/c++/i686-w64-mingw32"
" -isystem /usr/lib/gcc/i686-w64-mingw32/9.3-posix/include/c++/backward"
" -isystem /usr/lib/gcc/i686-w64-mingw32/9.3-posix/include"
# Do not include fixincludes
# REF: https://codechecker.readthedocs.io/en/v6.9.0/gcc_incompatibilities/
#" -isystem /usr/lib/gcc/i686-w64-mingw32/9.3-posix/include-fixed"
" -isystem /usr/i686-w64-mingw32/include"

# Use utils starting with `i686-w64-mingw32-`
" -Bi686-w64-mingw32-"

# Use DWARF exceptions
" -fdwarf-exceptions"
)

set(CMAKE_C_COMPILER "/usr/bin/clang-10" CACHE PATH "")
set(CMAKE_CXX_COMPILER "/usr/bin/clang++-10" CACHE PATH "")
set(CMAKE_C_FLAGS_INIT "${_compiler_flags}")
set(CMAKE_CXX_FLAGS_INIT "${_compiler_flags}")
set(CMAKE_C_FLAGS_DEBUG_INIT "-DDEBUG")
set(CMAKE_CXX_FLAGS_DEBUG_INIT "-DDEBUG")
set(CMAKE_C_FLAGS_RELEASE_INIT "-DNDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE_INIT "-DNDEBUG")
set(CMAKE_SHARED_LINKER_FLAGS_INIT "-static -L/usr/i686-w64-mingw32/lib -L/usr/lib/gcc/i686-w64-mingw32/9.3-posix")
set(CMAKE_EXE_LINKER_FLAGS_INIT "-static -L/usr/i686-w64-mingw32/lib -L/usr/lib/gcc/i686-w64-mingw32/9.3-posix")

# From mingw-w64-i686-dev package
set(CMAKE_FIND_ROOT_PATH /usr/i686-w64-mingw32)
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM BOTH)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

