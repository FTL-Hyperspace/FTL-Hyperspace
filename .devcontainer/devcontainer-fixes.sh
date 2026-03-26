#!/bin/bash
set -e

# Update vcpkg to get latest package versions to avoid issues with old cached versions
# Note: remove when new devcontainer image will be built
# Not needed anymore. Devcontainer image is up to date. # (cd /vcpkg && git pull && ./bootstrap-vcpkg.sh)


# This script applies fixes to a bug caused by a x86-windows-ftl.cmake triplet or/and toolchain.
# For some reason only boost_atomic library is being built with .lib naming instead of .a like all other boost libs.
# This causes linking errors when boost-filesystem (which depends on boost-atomic) is used in a MinGW build.
# As a workaround, we manually copy boost_atomic.lib to libboost

# Try to install all packages to both Windows build directories
# boost-filesystem will fail due to boost-atomic lib naming, that's expected
/vcpkg/vcpkg install --triplet=x86-windows-ftl --x-install-root=build-windows-debug/vcpkg_installed || true

# Repeat the process for release build (skip vcpkg install to save time)
cp -r build-windows-debug build-windows-release

# Fix boost_atomic.lib naming in both build directories so filesystem can link
for build_dir in build-windows-debug build-windows-release; do
    cp "$build_dir/vcpkg_installed/x86-windows-ftl/lib/boost_atomic.lib" "$build_dir/vcpkg_installed/x86-windows-ftl/lib/libboost_atomic.a"
    cp "$build_dir/vcpkg_installed/x86-windows-ftl/debug/lib/boost_atomic.lib" "$build_dir/vcpkg_installed/x86-windows-ftl/debug/lib/libboost_atomic.a"
done

echo "Devcontainer fixes applied successfully"
