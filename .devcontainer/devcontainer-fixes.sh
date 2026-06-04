#!/bin/bash
set -e

# This script applies fixes to a bug caused by a x86-windows-ftl.cmake triplet or/and toolchain.
# For some reason only boost_atomic library is being built with .lib naming instead of .a like all other boost libs.
# This causes linking errors when boost-filesystem (which depends on boost-atomic) is used in a MinGW build.
# As a workaround, we manually copy boost_atomic.lib to libboost

if [ "$#" -eq 0 ]; then
    BUILD_DIRS=(build-windows-debug build-windows-release)
else
    BUILD_DIRS=("$@")
fi

copy_boost_atomic_alias() {
    local build_dir="$1"
    local config_dir="$2"
    local src="$build_dir/vcpkg_installed/x86-windows-ftl/${config_dir}lib/boost_atomic.lib"
    local dst="$build_dir/vcpkg_installed/x86-windows-ftl/${config_dir}lib/libboost_atomic.a"

    if [ -f "$src" ] && ! cmp -s "$src" "$dst"; then
        cp "$src" "$dst"
    fi
}

for build_dir in "${BUILD_DIRS[@]}"; do
    /vcpkg/vcpkg install \
        --triplet=x86-windows-ftl \
        --host-triplet=x86-windows-ftl \
        --x-install-root="$build_dir/vcpkg_installed" || true

    copy_boost_atomic_alias "$build_dir" ""
    copy_boost_atomic_alias "$build_dir" "debug/"
done

echo "Devcontainer fixes applied successfully"
