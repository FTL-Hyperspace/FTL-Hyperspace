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

if(APPLE)
    # explicitly link the x86_64 SDL2 static library on macOS (needs to be installed via x86 Homebrew)
    set(SDL2_LIBRARIES "/usr/local/lib/libSDL2.a")
    set(SDL2_INCLUDE_DIRS "/usr/local/include/SDL2")
elseif(UNIX)
    find_package(SDL2 REQUIRED) # From system
elseif(WIN32)
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

if(APPLE)
    target_compile_features(Hyperspace PRIVATE cxx_std_14)
else()
    target_compile_features(Hyperspace PRIVATE cxx_std_11)
endif()

target_include_directories(
    Hyperspace PRIVATE

    ${Boost_INCLUDE_DIRS}
    ${LUA_INCLUDE_DIR}

    # Note: Don't vcpkg-fy rapidxml. It's already more than a decade old and we've customized the code to avoid its bug
    #       that leads to a compilation failure. See https://sourceforge.net/p/rapidxml/bugs/16/ for more info.
    rapidxml

    # Internal directories
    lua
    lua/objects

    # Workaround for SWIG (add source directory itself to the include directory)
    ${CMAKE_CURRENT_SOURCE_DIR}
)
target_link_libraries(
    Hyperspace PRIVATE
    ${LUA_LIBRARIES}
    minizip::minizip
    ZLIB::ZLIB
    Boost::filesystem
    Threads::Threads
)

# Automatically include all source files from root directory
# TODO: Move sources to src/ directory? (Original project had them in root)
file(GLOB ROOT_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.h"
)

# Exclude platform-specific files (they are #included by FTLGame.cpp)
list(FILTER ROOT_SOURCES EXCLUDE REGEX "FTLGame.*\\.cpp$")

# Exclude Discord files (added conditionally later based on USE_DISCORD option)
list(FILTER ROOT_SOURCES EXCLUDE REGEX "DiscordIntegration\\.")

# Exclude zhl.cpp (added at end to ensure proper static initialization order)
list(FILTER ROOT_SOURCES EXCLUDE REGEX "zhl\\.cpp$")

# Include lua sources
file(GLOB LUA_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/lua/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/lua/*.h"
)

# Include src/ sources
file(GLOB_RECURSE SRC_SOURCES
     "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
     "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h"
)

# Enable testing - controlled by ENABLE_TESTING option
option(ENABLE_TESTING "Enable Hyperspace automated testing" OFF)

if(ENABLE_TESTING)
    # Automatically include all test files recursively
    file(GLOB_RECURSE TEST_SOURCES
     "${CMAKE_CURRENT_SOURCE_DIR}/tests/*.cpp"
     "${CMAKE_CURRENT_SOURCE_DIR}/tests/*.h"
    )
    target_compile_definitions(Hyperspace PRIVATE HYPERSPACE_TESTING)
    message(STATUS "Hyperspace Testing: ENABLED")
else()
    set(TEST_SOURCES "")
    message(STATUS "Hyperspace Testing: DISABLED")
endif()

# Add all sources in a single target_sources call to ensure proper linking order
# TEST_SOURCES must come first to ensure TestScript hooks into the game loop first
target_sources(
    Hyperspace PRIVATE

    # Main junction for os-specific code
    FTLGame.h
    FTLGame.cpp

    # Test sources first (if enabled) - ensures TestScript initializes first
    ${TEST_SOURCES}

    # All src/ files (in future, consider moving ROOT_SOURCES to src/)
    ${SRC_SOURCES}

    # all root source files (will be deprecated in future)
    ${ROOT_SOURCES}

    # all lua files
    ${LUA_SOURCES}

    # Generated files
    ${CMAKE_CURRENT_SOURCE_DIR}/lua/swigluarun.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Version.autogen.hpp

    # zhl.cpp MUST be last to ensure all hooks are registered before ZHL::Init() runs
    zhl.cpp
)

add_custom_command(
	OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/lua/swigluarun.h.temp1 ${CMAKE_CURRENT_SOURCE_DIR}/lua/swigluarun.h
	COMMAND swig -c++ -lua -external-runtime lua/swigluarun.h.temp1
	COMMAND bash ./processSwigRuntime.sh
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

# TODO: https://stackoverflow.com/a/61814218/3567518
add_custom_command(
    OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/Version.autogen.hpp.temp ${CMAKE_CURRENT_SOURCE_DIR}/Version.autogen.hpp
    COMMAND bash ./generateVersion.sh
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_options(
    Hyperspace PRIVATE

    # Enable SSE2
    -msse -msse2 -mfpmath=sse

    # Error on narrowing conversion
    -Werror=narrowing

    # No warning for this == nullptr (can be removed once ShipSystem::GetPowerCap workaround is replaced)
    -fno-delete-null-pointer-checks

    # Warn everything
    # TODO: Check if it's meaningful (original .cbp defined it)
    # -Wall
)

if(APPLE)
    target_compile_options(Hyperspace PRIVATE -std=c++14 -Wno-deprecated-declarations)
else()
    target_compile_options(Hyperspace PRIVATE -std=c++11)
endif()

target_compile_definitions(Hyperspace PRIVATE _REENTRANT)
if(UNIX)
    # SDL2
    target_include_directories(Hyperspace PRIVATE ${SDL2_INCLUDE_DIRS})
    target_link_libraries(Hyperspace PRIVATE ${SDL2_LIBRARIES})

    if (APPLE)
        target_link_libraries(Hyperspace PRIVATE
            "-framework Cocoa"
            "-framework IOKit"
            "-framework CoreFoundation"
            "-framework CoreVideo"
            "-framework CoreAudio"
            "-framework OpenGL"
            "-framework AudioToolbox"
            "-framework ForceFeedback"
            "-framework Carbon"
            "-framework Metal"
            "-framework QuartzCore"
            "-framework GameController"
            "-framework CoreHaptics"
        )
    endif()

    # Disable Discord integration by default
    set(USE_DISCORD_DEFAULT OFF)

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
    # Enable the Discord integration on Windows by default
    set(USE_DISCORD_DEFAULT ON)

    # OpenGL, just raw OpenGL goodness
    target_link_libraries(Hyperspace PRIVATE OpenGL::GL)

    target_compile_definitions(Hyperspace PRIVATE BUILD_DLL)
endif()

option(USE_DISCORD "Enable the Discord Rich Presence integration" ${USE_DISCORD_DEFAULT})

if(USE_DISCORD)
    find_package(DiscordRpc REQUIRED) # From vcpkg & our custom find module

    target_sources(Hyperspace PRIVATE DiscordIntegration.h DiscordIntegration.cpp)
    target_compile_definitions(Hyperspace PRIVATE USE_DISCORD)
    target_link_libraries(Hyperspace PRIVATE DiscordRpc::DiscordRpc)
endif()

