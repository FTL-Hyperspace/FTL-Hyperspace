set(CMAKE_SYSTEM_NAME Windows)

# Info taken from `i686-w64-mingw32-g++ -v`
string(CONCAT _compiler_flags ""
#"-target i686-pc-windows-gnu -m32"
# " -I/usr/i686-w64-mingw32/include"
# " -Bi686-w64-mingw32-"
)

set(CMAKE_C_COMPILER "/usr/bin/i686-w64-mingw32-gcc-posix" CACHE PATH "")
set(CMAKE_CXX_COMPILER "/usr/bin/i686-w64-mingw32-g++-posix" CACHE PATH "")
set(CMAKE_C_FLAGS_INIT "${_compiler_flags}")
set(CMAKE_CXX_FLAGS_INIT "${_compiler_flags}")
set(CMAKE_C_FLAGS_DEBUG_INIT "-DDEBUG")
set(CMAKE_CXX_FLAGS_DEBUG_INIT "-DDEBUG")
set(CMAKE_C_FLAGS_RELEASE_INIT "-DNDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE_INIT "-DNDEBUG")
# set(CMAKE_SHARED_LINKER_FLAGS_INIT "-static -L/usr/lib/gcc/i686-w64-mingw32/9.3-posix")
# set(CMAKE_EXE_LINKER_FLAGS_INIT "-static -L/usr/lib/gcc/i686-w64-mingw32/9.3-posix")
set(CMAKE_SHARED_LINKER_FLAGS_INIT "-static")
set(CMAKE_EXE_LINKER_FLAGS_INIT "-static")

# From mingw-w64-i686-dev package
set(CMAKE_FIND_ROOT_PATH /usr/i686-w64-mingw32)
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM BOTH)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

