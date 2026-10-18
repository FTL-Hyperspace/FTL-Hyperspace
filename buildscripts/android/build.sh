#!/bin/bash
# Build libHyperspace.so for FTL for iPad running on Android.
#   ANDROID_NDK_HOME=... FTL_LIBCXX=... buildscripts/android/build.sh [Release|Debug]
set -e
SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
REPO_ROOT=$(cd "$SCRIPT_DIR/../.." && pwd)
BUILD_TYPE="${1:-Release}"
BUILD_DIR="$REPO_ROOT/build-android-$(echo "$BUILD_TYPE" | tr '[:upper:]' '[:lower:]')"
VCPKG_ROOT="$REPO_ROOT/vcpkg"

: "${ANDROID_NDK_HOME:?set ANDROID_NDK_HOME to the Android NDK}"
: "${FTL_LIBCXX:?set FTL_LIBCXX to the libc++ build of the Android port (see buildscripts/android/README.md)}"
export ANDROID_NDK_HOME FTL_LIBCXX

cd "$REPO_ROOT"
cmake -DCMAKE_TOOLCHAIN_FILE="$VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake" \
    -DVCPKG_TARGET_TRIPLET=arm64-android-ftl \
    -DVCPKG_CHAINLOAD_TOOLCHAIN_FILE="$VCPKG_ROOT/scripts/toolchains/arm64-android-ftl.cmake" \
    -DCMAKE_BUILD_TYPE="$BUILD_TYPE" \
    -S . -B "$BUILD_DIR" -G Ninja
ninja -C "$BUILD_DIR"
echo "Built: $BUILD_DIR/libHyperspace.so"
