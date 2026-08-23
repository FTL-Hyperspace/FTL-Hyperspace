# Offline ZHL signature scanning.
#
#   zhlscan                  reads a game binary (LIEF) and runs a definitions module over it
#   libftlgame-<platform>    one platform's generated FTLGame*.cpp linked with the game's own
#                            definition loading (zhl_definitions.cpp, SigScan, HDE) under
#                            ZHL_OFFLINE_SCAN, so resolving signatures is exactly Definition::Init()
#
# Editing a signature recompiles one module; zhlscan itself is untouched.
#
# Build with vcpkg (LIEF reads the binaries), e.g.:
#   cmake -S libzhlgen/zhlscan -B build-zhlscan -G Ninja \
#       -DCMAKE_TOOLCHAIN_FILE=$PWD/vcpkg/scripts/buildsystems/vcpkg.cmake
#   ninja -C build-zhlscan
# Targets x86_64 with vcpkg's stock x64 triplet: the generated code uses
# x86-only GCC/clang extensions (regparm/thiscall/naked asm), and none of it
# ever executes. On Windows that means a MinGW toolchain, not MSVC.

cmake_minimum_required(VERSION 3.21)

if(APPLE)
    set(CMAKE_OSX_ARCHITECTURES x86_64)
    set(VCPKG_TARGET_TRIPLET x64-osx CACHE STRING "")
elseif(WIN32)
    set(VCPKG_TARGET_TRIPLET x64-mingw-static CACHE STRING "")
    set(VCPKG_HOST_TRIPLET x64-mingw-static CACHE STRING "")
elseif(UNIX)
    set(VCPKG_TARGET_TRIPLET x64-linux CACHE STRING "")
endif()

project(zhlscan CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(LIEF CONFIG REQUIRED)

set(HYPERSPACE_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/../..)

add_executable(zhlscan main.cpp CodeSection.cpp)
target_link_libraries(zhlscan PRIVATE LIEF::LIEF ${CMAKE_DL_LIBS})

set(MODULE_SOURCES
    DefinitionsModule.cpp
    ${HYPERSPACE_ROOT}/zhl_definitions.cpp
    ${HYPERSPACE_ROOT}/SigScan.cpp
    ${HYPERSPACE_ROOT}/hde.cpp
)

# ZHL_TARGET_BITS selects the HDE decoder used to find function ends (see hde.h).
function(add_definitions_module platform generated_source target_bits)
    set(name ftlgame-${platform})
    add_library(${name} MODULE ${HYPERSPACE_ROOT}/${generated_source} ${MODULE_SOURCES})
    set_target_properties(${name} PROPERTIES PREFIX lib SUFFIX .so CXX_VISIBILITY_PRESET hidden)
    target_compile_definitions(${name} PRIVATE ZHL_OFFLINE_SCAN ZHL_TARGET_BITS=${target_bits})
    target_include_directories(${name} PRIVATE ${HYPERSPACE_ROOT} ${HYPERSPACE_ROOT}/rapidxml)
    # The generated headers use uint8_t without including <cstdint>; libc++ provides it
    # transitively, libstdc++ does not.
    target_compile_options(${name} PRIVATE -w -include cstdint)
endfunction()

add_definitions_module(darwin  FTLGameMacOSAMD64.cpp 64)
add_definitions_module(linux64 FTLGameELF64.cpp      64)
add_definitions_module(linux32 FTLGameELF32.cpp      32)
add_definitions_module(win32   FTLGameWin32.cpp      32)

# FTLGameWin32.cpp contains 32-bit inline asm in naked wrappers that cannot
# assemble in 64-bit mode; compile it out. Off Windows it also needs
# <windows.h>/<io.h> stand-ins.
target_compile_options(ftlgame-win32 PRIVATE "-D__asm__(...)=")
if(NOT WIN32)
    target_include_directories(ftlgame-win32 PRIVATE stubs)
endif()
