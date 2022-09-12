set(CMAKE_SYSTEM_NAME Windows)

# Get clang version
execute_process(
    COMMAND clang-10 -v
    ERROR_VARIABLE _clang_v_output
    COMMAND_ERROR_IS_FATAL ANY
)
string(REGEX REPLACE ".*version ([0-9]+\\.[0-9]+\\.[0-9]+).*" "\\1" _clang_version "${_clang_v_output}")
message(STATUS "clang version: ${_clang_version}")

# Get mingw root
file(GLOB _mingw_versioned_root LIST_DIRECTORIES true "/usr/lib/gcc/i686-w64-mingw32/*-posix")
message(STATUS "mingw versioned root path: ${_mingw_versioned_root}")

string(CONCAT _compiler_flags
    "-target i686-w64-mingw32 -nostdinc"

    # clang++-10 -target i686-w64-mingw32 -E -x c -v - < /dev/null
    # This should override xmmintrin.h so that gcc intrinsics for vector instructions are not used
    " -isystem /usr/lib/llvm-10/lib/clang/${_clang_version}/include"
    # Force mingw to use clang intrinsics
    # REF: https://github.com/msys2/MINGW-packages/issues/9052#issuecomment-756456305
    " -D__MINGW_FORCE_SYS_INTRINS"

    # i686-w64-mingw32-g++-posix -E -x c++ - -v < /dev/null
    " -isystem ${_mingw_versioned_root}/include/c++"
    " -isystem ${_mingw_versioned_root}/include/c++/i686-w64-mingw32"
    " -isystem ${_mingw_versioned_root}/include/c++/backward"
    " -isystem ${_mingw_versioned_root}/include"
    # Do not include fixincludes
    # REF: https://codechecker.readthedocs.io/en/v6.9.0/gcc_incompatibilities/
    #" -isystem ${_mingw_versioned_root}/include-fixed"
    " -isystem /usr/i686-w64-mingw32/include"

    # Use utils starting with `i686-w64-mingw32-`
    " -Bi686-w64-mingw32-"

    # Use DWARF exceptions
    " -fdwarf-exceptions"
)
string(CONCAT _linker_flags
    "-static"
    " -L/usr/i686-w64-mingw32/lib -L${_mingw_versioned_root}"

    # Use lld instead of ld
    # " -fuse-ld=lld-10"
)


set(CMAKE_C_COMPILER "/usr/bin/clang-10" CACHE PATH "")
set(CMAKE_CXX_COMPILER "/usr/bin/clang++-10" CACHE PATH "")
set(CMAKE_RC_COMPILER "/usr/bin/i686-w64-mingw32-windres" CACHE PATH "")
set(CMAKE_C_FLAGS_INIT "${_compiler_flags}")
set(CMAKE_CXX_FLAGS_INIT "${_compiler_flags}")
set(CMAKE_SHARED_LINKER_FLAGS_INIT "${_linker_flags}")
set(CMAKE_EXE_LINKER_FLAGS_INIT "${_linker_flags}")
set(CMAKE_C_FLAGS_DEBUG_INIT "-DDEBUG")
set(CMAKE_CXX_FLAGS_DEBUG_INIT "-DDEBUG")
set(CMAKE_C_FLAGS_RELEASE_INIT "-DNDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE_INIT "-DNDEBUG")

# From mingw-w64-i686-dev package
list(APPEND CMAKE_FIND_ROOT_PATH "/usr/i686-w64-mingw32")
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM BOTH)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

