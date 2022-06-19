set(VCPKG_TARGET_ARCHITECTURE x86)
set(VCPKG_CRT_LINKAGE static)
set(VCPKG_LIBRARY_LINKAGE static)

set(VCPKG_CMAKE_SYSTEM_NAME MinGW)
# Workaround for clang-created .lib files: "Could not find proper second linker member"
# REF: https://github.com/microsoft/vcpkg/issues/24095#issuecomment-1096705410
set(VCPKG_POLICY_SKIP_ARCHITECTURE_CHECK enabled)
set(VCPKG_CHAINLOAD_TOOLCHAIN_FILE "/vcpkg/scripts/toolchains/x86-windows-ftl.cmake")

