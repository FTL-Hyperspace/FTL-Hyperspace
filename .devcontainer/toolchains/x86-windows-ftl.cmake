if(NOT _FTL_TOOLCHAIN)
set(_FTL_TOOLCHAIN 1)

set(CMAKE_SYSTEM_NAME Windows)

# Get clang version
execute_process(
    COMMAND clang -v
    ERROR_VARIABLE _clang_v_output
    COMMAND_ERROR_IS_FATAL ANY
)
string(REGEX REPLACE ".*version ([0-9]+\\.[0-9]+\\.[0-9]+).*" "\\1" _clang_version "${_clang_v_output}")
message(STATUS "clang version: ${_clang_version}")

# Get mingw root
file(GLOB _mingw_versioned_root LIST_DIRECTORIES true "/usr/lib/gcc/i686-w64-mingw32/*-posix")
message(STATUS "mingw versioned root path: ${_mingw_versioned_root}")

string(CONCAT _compiler_flags
    "-nostdinc"

    # Force mingw to use clang intrinsics
    # REF: https://github.com/msys2/MINGW-packages/issues/9052#issuecomment-756456305
    " -D__MINGW_FORCE_SYS_INTRINS"

    # Disable multiple definition of std::type_info::operator==
    " -D__GXX_TYPEINFO_EQUALITY_INLINE=0"

    # Use DWARF exceptions
    " -fdwarf-exceptions"
)
string(CONCAT _linker_flags
    "-static"
    " -L/usr/i686-w64-mingw32/lib -L${_mingw_versioned_root}"

    # Use lld instead of ld
    " -fuse-ld=lld"
)

set(CMAKE_C_COMPILER "clang" CACHE PATH "")
set(CMAKE_CXX_COMPILER "clang++" CACHE PATH "")
set(CMAKE_RC_COMPILER "/usr/bin/i686-w64-mingw32-windres" CACHE PATH "")
set(CMAKE_SHARED_LINKER_FLAGS_INIT "${_linker_flags}")
set(CMAKE_SHARED_LINKER_FLAGS_DEBUG_INIT "-debug")
set(CMAKE_EXE_LINKER_FLAGS_INIT "${_linker_flags}")
set(CMAKE_EXE_LINKER_FLAGS_DEBUG_INIT "-debug")
foreach(lang C CXX)
    set(CMAKE_${lang}_FLAGS_INIT "${_compiler_flags}")
    set(CMAKE_${lang}_FLAGS_DEBUG_INIT "-DDEBUG")
    set(CMAKE_${lang}_FLAGS_RELEASE_INIT "-DNDEBUG")
    set(CMAKE_${lang}_FLAGS_MINSIZEREL_INIT "-DNDEBUG")
    set(CMAKE_${lang}_FLAGS_RELWITHDEBINFO_INIT "-DNDEBUG")

    set(CMAKE_${lang}_COMPILER_TARGET "i686-w64-windows-gnu")
    list(APPEND CMAKE_${lang}_STANDARD_INCLUDE_DIRECTORIES
        # clang++ -target i686-w64-windows-gnu -E -x c -v - < /dev/null
        # This should override xmmintrin.h so that gcc intrinsics for vector instructions are not used
        "/usr/local/lib/clang/${_clang_version}/include"
        
        # i686-w64-mingw32-g++-posix -E -x c++ - -v < /dev/null
        "${_mingw_versioned_root}/include/c++"
        "${_mingw_versioned_root}/include/c++/i686-w64-mingw32"
        "${_mingw_versioned_root}/include/c++/backward"
        "${_mingw_versioned_root}/include"
        # Do not include fixincludes, REF: https://codechecker.readthedocs.io/en/v6.9.0/gcc_incompatibilities/
        # "${_mingw_versioned_root}/include-fixed"
        "/usr/i686-w64-mingw32/include"
    )

    # Workaround for boost: b2 seems to convert -isystem flags to -I which causes some include order problems.
    # We'll add them manually though it results in duplication in the end.
    foreach(ipath ${CMAKE_${lang}_STANDARD_INCLUDE_DIRECTORIES})
        string(APPEND CMAKE_${lang}_FLAGS_INIT " -isystem ${ipath}")
    endforeach()
endforeach()

list(APPEND CMAKE_FIND_ROOT_PATH "/usr/i686-w64-mingw32")
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM BOTH)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

endif()
