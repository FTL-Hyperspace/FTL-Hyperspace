if(NOT _FTL_TOOLCHAIN)
set(_FTL_TOOLCHAIN 1)

set(CMAKE_SYSTEM_NAME Linux)

string(CONCAT _compiler_flags 
    "--gcc-toolchain=/usr/gcc-4.8-clang-toolchain/"
    " -D_GLIBCXX_USE_CXX11_ABI=0"

    # Note on -fPIC:
    # * As the final output of Hyperspace is a shared lib the deps are required to be compiled with -fPIC
    #   even when they're static by themselves.
    # * Normally the deps are automatically built with -fPIC when VCPKG_LIBRARY_LINKAGE is dynamic
    #   but when it's static there's no written law whether it'll be enabled or not.
    # * Setting CMAKE_POSITION_INDEPENDENT_CODE doesn't propagate on building deps on vcpkg for some reason.
    " -fPIC"
)
string(CONCAT _linker_flags
    # Workaround for Lua
    "-lm"

    # Use lld instead of ld
    " -fuse-ld=lld"
)


set(CMAKE_C_COMPILER "clang" CACHE PATH "")
set(CMAKE_CXX_COMPILER "clang++" CACHE PATH "")
foreach(lang C CXX)
    set(CMAKE_${lang}_FLAGS_DEBUG_INIT "-DDEBUG")
    set(CMAKE_${lang}_FLAGS_RELEASE_INIT "-DNDEBUG")
    set(CMAKE_${lang}_FLAGS_MINSIZEREL_INIT "-DNDEBUG")
    set(CMAKE_${lang}_FLAGS_RELWITHDEBINFO_INIT "-DNDEBUG")
    # Setting CMAKE_*_FLAGS_INIT will ignore -fPIC under certain circumstances.
    # Setting CMAKE_*_FLAGS directly prevents this (see https://github.com/microsoft/vcpkg/pull/12097 for a similar case).
    string(APPEND CMAKE_${lang}_FLAGS " ${_compiler_flags}")
endforeach()
set(CMAKE_SHARED_LINKER_FLAGS_INIT "${_linker_flags}")
set(CMAKE_EXE_LINKER_FLAGS_INIT "${_linker_flags}")

# Workaround for Lua: FindLua module in CMake seems to invoke `find_library(... m)` which doesn't work if anything is
# defined in CMAKE_FIND_ROOT_PATH. In that case the path to libm MUST be specified in both CMAKE_FIND_ROOT_PATH
# and CMAKE_SYSTEM_LIBRARY_PATH.
list(APPEND CMAKE_FIND_ROOT_PATH "/usr/gcc-4.8-clang-toolchain" "/usr/lib/x86_64-linux-gnu")
list(APPEND CMAKE_SYSTEM_LIBRARY_PATH "/usr/lib/x86_64-linux-gnu")
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

endif()
