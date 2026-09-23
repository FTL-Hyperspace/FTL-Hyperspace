cmake_minimum_required(VERSION 3.16)
project(Hyperspace CXX)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

if(APPLE)
    # Prefer static libraries for dependencies on macOS
    set(BUILD_SHARED_LIBS OFF)
endif()

# Let vcpkg handle Boost automatically
find_package(Boost REQUIRED COMPONENTS filesystem system)

# Let vcpkg handle Lua automatically
find_package(Lua REQUIRED)

# Let vcpkg handle minizip automatically
find_package(minizip REQUIRED)
find_package(ZLIB REQUIRED)

# Let vcpkg handle SDL3 automatically
find_package(SDL3 CONFIG REQUIRED)

if(WIN32)
    find_package(OpenGL REQUIRED)
endif()

# pthread
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

# SWIG
find_package(SWIG REQUIRED COMPONENTS lua)
include(UseSWIG)

# Setup SWIG *.i files
set(
    swigfiles
        lua/modules/defines.i
        lua/modules/graphics.i
        lua/modules/hyperspace.i
        lua/modules/rapidxml.i
)
set_property(SOURCE ${swigfiles} PROPERTY USE_TARGET_INCLUDE_DIRECTORIES TRUE)
set_property(SOURCE ${swigfiles} PROPERTY CPLUSPLUS ON)

# Name the binary as Hyperspace.dll instead of libHyperspace.dll
set(CMAKE_SHARED_LIBRARY_PREFIX_CXX "")

swig_add_library(
    Hyperspace
    TYPE SHARED
    LANGUAGE lua
    SOURCES ${swigfiles}
)

target_compile_features(Hyperspace PRIVATE cxx_std_11)

target_include_directories(
    Hyperspace PRIVATE

    ${Boost_INCLUDE_DIRS}
    ${LUA_INCLUDE_DIR}

    # Include roots; include from a root and not with "../"
    src/game               # "CustomCrew.h"
    src/zhl                # "zhl.h", "SigScan.h"
    src                    # "Global.h", "FTLGame.h", "features/freeze-watchdog/FreezeWatchdog.h"
    lua                    # "LuaScriptInit.h"
    generated              # "Version.autogen.hpp", "swigluarun.h", FTLGame<Platform>.*
    third_party/detours    # "detours.h", "hde.h"

    # Note: Don't vcpkg-fy rapidxml. It's already more than a decade old and we've customized the code to avoid its bug
    #       that leads to a compilation failure. See https://sourceforge.net/p/rapidxml/bugs/16/ for more info.
    third_party/rapidxml   # "rapidxml.hpp"
)
target_link_libraries(
    Hyperspace PRIVATE
    ${LUA_LIBRARIES}
    minizip::minizip
    ZLIB::ZLIB
    Boost::filesystem
    Threads::Threads
    SDL3::SDL3
)

# Sources belong in src/
file(GLOB ROOT_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/*.h")
if(ROOT_SOURCES)
    message(FATAL_ERROR "Move these files from the repository root into src/game: ${ROOT_SOURCES}")
endif()

# All src/ sources; path order is hook registration order
file(GLOB_RECURSE HS_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h"
)

# Placed explicitly below
list(FILTER HS_SOURCES EXCLUDE REGEX "/src/(zhl/|main\\.cpp$)")

# Hooking engine
file(GLOB ZHL_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/zhl/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/zhl/*.h"
)

# Generated hook definitions for this platform
if(WIN32)
    set(FTLGAME_PLATFORM Win32)
elseif(APPLE)
    set(FTLGAME_PLATFORM MacOSAMD64)
elseif(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(FTLGAME_PLATFORM ELF64)
else()
    set(FTLGAME_PLATFORM ELF32)
endif()

# Include lua sources
file(GLOB LUA_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/lua/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/lua/*.h"
)

# Enable testing - controlled by ENABLE_TESTING option
option(ENABLE_TESTING "Enable Hyperspace automated testing" OFF)

if(ENABLE_TESTING)
    # Automatically include all test files recursively
    file(GLOB_RECURSE TEST_SOURCES CONFIGURE_DEPENDS
     "${CMAKE_CURRENT_SOURCE_DIR}/tests/*.cpp"
     "${CMAKE_CURRENT_SOURCE_DIR}/tests/*.h"
    )
    target_compile_definitions(Hyperspace PRIVATE HYPERSPACE_TESTING)
    message(STATUS "Hyperspace Testing: ENABLED")
else()
    set(TEST_SOURCES "")
    message(STATUS "Hyperspace Testing: DISABLED")
endif()

# Link order is hook registration order
target_sources(
    Hyperspace PRIVATE

    # Hook definitions for this platform
    generated/FTLGame${FTLGAME_PLATFORM}.h
    generated/FTLGame${FTLGAME_PLATFORM}.cpp

    # Test sources first (if enabled) - ensures TestScript hooks into the game loop first
    ${TEST_SOURCES}

    # All src/ sources
    ${HS_SOURCES}

    # all lua files
    ${LUA_SOURCES}

    # Vendored sources
    third_party/detours/hde.cpp

    # Generated files
    ${CMAKE_CURRENT_SOURCE_DIR}/generated/swigluarun.h
    ${CMAKE_CURRENT_SOURCE_DIR}/generated/Version.autogen.hpp

    ${ZHL_SOURCES}

    # Calls ZHL::Init() at load on Linux/macOS, so after every hook and definition
    src/main.cpp
)

add_custom_command(
	OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/generated/swigluarun.h.temp1 ${CMAKE_CURRENT_SOURCE_DIR}/generated/swigluarun.h
	COMMAND ${CMAKE_COMMAND} -E make_directory generated
	COMMAND swig -c++ -lua -external-runtime generated/swigluarun.h.temp1
	COMMAND bash buildscripts/tools/processSwigRuntime.sh
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

# TODO: https://stackoverflow.com/a/61814218/3567518
add_custom_command(
    OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/generated/Version.autogen.hpp.temp ${CMAKE_CURRENT_SOURCE_DIR}/generated/Version.autogen.hpp
    COMMAND ${CMAKE_COMMAND} -E make_directory generated
    COMMAND bash buildscripts/tools/generateVersion.sh
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_options(
    Hyperspace PRIVATE

    # Enable SSE2
    -msse -msse2 -mfpmath=sse

    # Error on narrowing conversion
    -Werror=narrowing

    # Error on missing return
    -Werror=return-type

    # No warning for this == nullptr (can be removed once ShipSystem::GetPowerCap workaround is replaced)
    -fno-delete-null-pointer-checks

    # Warn everything
    # TODO: Check if it's meaningful
    # -Wall
)

target_compile_options(Hyperspace PRIVATE -std=c++11)
if(APPLE)
    target_compile_options(Hyperspace PRIVATE -Wno-deprecated-declarations)
endif()

target_compile_definitions(Hyperspace PRIVATE _REENTRANT)
if(UNIX)
    if (APPLE)
        # SDL3 loads OpenGL dynamically on macOS. 
        target_link_libraries(Hyperspace PRIVATE "-framework OpenGL")
    endif()

    # Naming the binary
    if(CMAKE_SIZEOF_VOID_P EQUAL 8)
        set(name_suffix "amd64")
    else()
        set(name_suffix "x86")
    endif()

    if(STEAM_1_6_13_BUILD)
        target_compile_definitions(Hyperspace PRIVATE STEAM_1_6_13_BUILD)
        set_target_properties(Hyperspace PROPERTIES OUTPUT_NAME "Hyperspace.1.6.13.${name_suffix}")
    else()
        set_target_properties(Hyperspace PROPERTIES OUTPUT_NAME "Hyperspace.1.6.12.${name_suffix}")
    endif()
elseif(WIN32)
    # OpenGL, just raw OpenGL goodness
    target_link_libraries(Hyperspace PRIVATE OpenGL::GL)

    target_compile_definitions(Hyperspace PRIVATE BUILD_DLL)
endif()

# Discord Rich Presence, on by default on Windows
option(USE_DISCORD "Enable the Discord Rich Presence integration" ${WIN32})

if(USE_DISCORD)
    find_package(DiscordRpc REQUIRED) # From vcpkg & our custom find module

    target_compile_definitions(Hyperspace PRIVATE USE_DISCORD)
    target_link_libraries(Hyperspace PRIVATE DiscordRpc::DiscordRpc)
endif()

