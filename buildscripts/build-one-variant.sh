#!/bin/bash
set -e

SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

BUILD_DIR="$1"
TOOLCHAIN_NAME="$2"
STEAM_1_6_13_BUILD="$3"
BUILD_TYPE="$4"

pushd $SCRIPT_DIR/..

cmake -DCMAKE_TOOLCHAIN_FILE=/vcpkg/scripts/buildsystems/vcpkg.cmake \
    "-DVCPKG_HOST_TRIPLET=$TOOLCHAIN_NAME" \
    "-DVCPKG_TARGET_TRIPLET=$TOOLCHAIN_NAME" \
    "-DVCPKG_CHAINLOAD_TOOLCHAIN_FILE=/vcpkg/scripts/toolchains/${TOOLCHAIN_NAME}.cmake" \
    "-DCMAKE_BUILD_TYPE=$BUILD_TYPE" \
    "-DSTEAM_1_6_13_BUILD=$STEAM_1_6_13_BUILD" \
    -S . -B $BUILD_DIR -G Ninja

ninja -C $BUILD_DIR

popd
