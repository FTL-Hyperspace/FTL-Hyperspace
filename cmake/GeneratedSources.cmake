# Rules for everything under generated/, which git does not track. Every generator
# runs on each build and rewrites a file only when its content changed.

include_guard(GLOBAL)

get_filename_component(HS_ROOT "${CMAKE_CURRENT_LIST_DIR}/.." ABSOLUTE)

# PATH only, vcpkg installs an interpreter of its own that carries no modules
find_program(HS_LUA NAMES lua lua5.4 lua5.3
    NO_CMAKE_PATH NO_CMAKE_ENVIRONMENT_PATH NO_CMAKE_SYSTEM_PATH)
if(NOT HS_LUA)
    message(FATAL_ERROR "No lua interpreter on PATH (apt install lua5.3; on macOS run buildscripts/ci/setup-macos.sh)")
endif()

foreach(module lpeg lfs)
    execute_process(COMMAND ${HS_LUA} -e "require('${module}')" RESULT_VARIABLE hs_module ERROR_QUIET)
    if(NOT hs_module EQUAL 0)
        message(FATAL_ERROR "${HS_LUA} cannot load ${module} (apt install lua-lpeg lua-filesystem; on macOS run buildscripts/ci/setup-macos.sh)")
    endif()
endforeach()

set(HS_ZHL_SOURCES "")
foreach(platform Win32 ELF32 ELF64 MacOSAMD64)
    list(APPEND HS_ZHL_SOURCES
        "${HS_ROOT}/generated/FTLGame${platform}.cpp"
        "${HS_ROOT}/generated/FTLGame${platform}.h")
endforeach()

add_custom_target(hs_zhl
    COMMAND ${CMAKE_COMMAND} -E env LUA=${HS_LUA} bash libzhlgen/parsefuncs.sh
    BYPRODUCTS ${HS_ZHL_SOURCES}
    WORKING_DIRECTORY "${HS_ROOT}"
    COMMENT "Generating ZHL hook definitions for every platform"
    VERBATIM
)

# Per build folder, its content depends on the swig version and would otherwise flip
# back and forth between builds made in different environments
set(HS_SWIG_RUNTIME_DIR "${CMAKE_CURRENT_BINARY_DIR}/generated")
set(HS_SWIG_RUNTIME "${HS_SWIG_RUNTIME_DIR}/swigluarun.h")

# Listing the .temp output keeps this dirty, it is deleted on every run
add_custom_command(
    OUTPUT "${HS_SWIG_RUNTIME}.temp1" "${HS_SWIG_RUNTIME}"
    COMMAND ${CMAKE_COMMAND} -E make_directory "${HS_SWIG_RUNTIME_DIR}"
    COMMAND swig -c++ -lua -external-runtime "${HS_SWIG_RUNTIME}.temp1"
    COMMAND bash buildscripts/tools/processSwigRuntime.sh "${HS_SWIG_RUNTIME_DIR}"
    WORKING_DIRECTORY "${HS_ROOT}"
    COMMENT "Generating swigluarun.h"
    VERBATIM
)

add_custom_command(
    OUTPUT "${HS_ROOT}/generated/Version.autogen.hpp.temp" "${HS_ROOT}/generated/Version.autogen.hpp"
    COMMAND ${CMAKE_COMMAND} -E make_directory generated
    COMMAND bash buildscripts/tools/generateVersion.sh
    WORKING_DIRECTORY "${HS_ROOT}"
    COMMENT "Generating Version.autogen.hpp"
    VERBATIM
)

# Swig includes the generated headers and runs as part of the Hyperspace target, so
# depend on this to have generated/ filled first
add_custom_target(hs_generated DEPENDS
    "${HS_SWIG_RUNTIME}"
    "${HS_ROOT}/generated/Version.autogen.hpp"
)
add_dependencies(hs_generated hs_zhl)
