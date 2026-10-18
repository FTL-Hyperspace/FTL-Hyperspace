if(NOT _FTL_TOOLCHAIN)
set(_FTL_TOOLCHAIN 1)

# FTL for iPad running on Android (see buildscripts/android/README.md): an arm64-v8a
# shared library built with the NDK. The port loads the iPad game and links it
# against its own libc++, built with Apple's arm64 C++ ABI; Hyperspace is compiled
# against that same libc++ so std::string and friends match the game's.
#
# ANDROID_NDK_HOME: the Android NDK (r28)
# FTL_LIBCXX: output of the port's `libcxx/build.sh android` (include/ and lib/)
foreach(var ANDROID_NDK_HOME FTL_LIBCXX)
    if(NOT DEFINED ENV{${var}})
        message(FATAL_ERROR "${var} is not set (see buildscripts/android/README.md)")
    endif()
endforeach()

set(ANDROID_ABI arm64-v8a)
set(ANDROID_PLATFORM android-26)
set(ANDROID_STL none)
include("$ENV{ANDROID_NDK_HOME}/build/cmake/android.toolchain.cmake")

set(FTL_LIBCXX "$ENV{FTL_LIBCXX}" CACHE PATH "The Android port's libc++ build (include/ and lib/)")
set(_ftl_libcxx "${FTL_LIBCXX}")

# Where Apple's arm64 ABI differs from Android's and the difference crosses into the
# game: char is signed; constructors return `this` and arrays carry ARM cookies
# (-fc++-abi=arm, as the port's libc++ is built); RTTI and ctype tables use the
# Apple layout, matching how the port configured libc++.
string(CONCAT _ftl_c_flags
    " -fsigned-char"
    " -fPIC"
)
string(CONCAT _ftl_cxx_flags
    " -nostdinc++ -isystem ${_ftl_libcxx}/include/c++/v1"
    " -fc++-abi=arm"
    " -D_LIBCPP_TYPEINFO_COMPARISON_IMPLEMENTATION=3"
    " -D_LIBCPP_DARWIN_CTYPE_ABI"
)

foreach(lang C CXX)
    set(CMAKE_${lang}_FLAGS_DEBUG_INIT "-DDEBUG -g")
    set(CMAKE_${lang}_FLAGS_RELEASE_INIT "-DNDEBUG -O2")
    set(CMAKE_${lang}_FLAGS_MINSIZEREL_INIT "-DNDEBUG -Os")
    set(CMAKE_${lang}_FLAGS_RELWITHDEBINFO_INIT "-DNDEBUG -O2 -g")
    # Set directly rather than through _INIT, as the Linux toolchain does, so -fPIC
    # reaches the dependencies vcpkg builds too
    string(APPEND CMAKE_${lang}_FLAGS "${_ftl_c_flags}")
endforeach()
string(APPEND CMAKE_CXX_FLAGS "${_ftl_cxx_flags}")

# The port's libc++ instead of the NDK's (lld doesn't mind libraries coming before the
# objects that use them). libunwind is added by Hyperspace itself, as it needs the
# port's Mach-O aware build; the programs CMake and vcpkg build to check the compiler
# use the NDK's.
foreach(kind EXE SHARED MODULE)
    string(APPEND CMAKE_${kind}_LINKER_FLAGS " -nostdlib++ ${_ftl_libcxx}/lib/libc++.a ${_ftl_libcxx}/lib/libc++abi.a")
endforeach()

list(APPEND CMAKE_PREFIX_PATH "${CMAKE_BINARY_DIR}/vcpkg_installed/${VCPKG_TARGET_TRIPLET}")
list(APPEND CMAKE_FIND_ROOT_PATH "${CMAKE_BINARY_DIR}/vcpkg_installed/${VCPKG_TARGET_TRIPLET}")
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE BOTH)

endif()
