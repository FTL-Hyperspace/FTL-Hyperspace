if(NOT _FTL_TOOLCHAIN)
    set(_FTL_TOOLCHAIN 1)

    # System definition for macOS
    set(CMAKE_SYSTEM_NAME Darwin)

    # Define flags for compiler and linker
    string(CONCAT _compiler_flags
        # Force build for AMD64 (x86_64)
        "-target x86_64-apple-macos10.13"

        # Position Independent Code (PIC) required for macOS
        " -fPIC"
    )
    string(CONCAT _linker_flags
        # Force use of LLD as linker
        " -fuse-ld=lld"

        # Link against system framework on macOS
        " -framework CoreFoundation"
    )

    # Compilers for macOS
    set(CMAKE_C_COMPILER "clang" CACHE PATH "")
    set(CMAKE_CXX_COMPILER "clang++" CACHE PATH "")

    # Compiler flags for different build configurations
        set(CMAKE_${lang}_FLAGS_DEBUG_INIT "-DDEBUG")
        set(CMAKE_${lang}_FLAGS_RELEASE_INIT "-DNDEBUG")
        set(CMAKE_${lang}_FLAGS_MINSIZEREL_INIT "-DNDEBUG")
        set(CMAKE_${lang}_FLAGS_RELWITHDEBINFO_INIT "-DNDEBUG")

        # Add the custom compiler flags
        string(APPEND CMAKE_${lang}_FLAGS " ${_compiler_flags}")
    endforeach()

    # Linker flags
    set(CMAKE_SHARED_LINKER_FLAGS_INIT "${_linker_flags}")
    set(CMAKE_EXE_LINKER_FLAGS_INIT "${_linker_flags}")

    # Add vcpkg paths with highest priority FIRST
    list(APPEND CMAKE_PREFIX_PATH "${CMAKE_BINARY_DIR}/vcpkg_installed/amd64-darwin-ftl")
    list(APPEND CMAKE_LIBRARY_PATH "${CMAKE_BINARY_DIR}/vcpkg_installed/amd64-darwin-ftl/lib")
    list(APPEND CMAKE_INCLUDE_PATH "${CMAKE_BINARY_DIR}/vcpkg_installed/amd64-darwin-ftl/include")

    # Set up FIND_ROOT_PATH if you want to use it (optional)
    # But with BOTH mode, PREFIX_PATH and LIBRARY_PATH are usually sufficient
    list(APPEND CMAKE_FIND_ROOT_PATH
        "${CMAKE_BINARY_DIR}/vcpkg_installed/amd64-darwin-ftl"  # vcpkg first
        "/usr/local"       # Homebrew second
        "/Library/Frameworks"  # macOS Frameworks
    )

    # Search in both vcpkg and system paths (vcpkg first due to list order)
    set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
    set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY BOTH)
    set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE BOTH)
    set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE BOTH)

    # System paths (lower priority)
    list(APPEND CMAKE_SYSTEM_PREFIX_PATH
        "/usr/local"       # Homebrew
        "/Library/Frameworks"  
    )
endif()