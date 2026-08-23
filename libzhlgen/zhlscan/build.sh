#!/bin/bash
# Configure and build zhlscan plus every libftlgame-<platform> module for this
# host into <repo>/build-zhlscan/ (or $ZHLSCAN_BUILD_DIR). verify_sigs.py calls
# this the first time and runs incremental ninja builds afterwards. Needs
# CMake, Ninja, vcpkg and an x86_64 clang/gcc toolchain (MinGW-w64 on Windows;
# MSVC cannot compile the generated code). See run-in-docker.sh for a
# ready-made Linux environment.
#
# Usage: build.sh [VCPKG_ROOT]
#   VCPKG_ROOT defaults to $VCPKG_ROOT, then /vcpkg, then <repo>/vcpkg.

set -e

SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
REPO_ROOT=$(cd "$SCRIPT_DIR/../.." && pwd)

if [ -n "${VCPKG_ROOT:-}" ]; then DEFAULT_VCPKG="$VCPKG_ROOT"
elif [ -d /vcpkg ]; then DEFAULT_VCPKG=/vcpkg
else DEFAULT_VCPKG="$REPO_ROOT/vcpkg"; fi
VCPKG_ROOT="${1:-$DEFAULT_VCPKG}"

BUILD_DIR="${ZHLSCAN_BUILD_DIR:-$REPO_ROOT/build-zhlscan}"

cmake -S "$SCRIPT_DIR" -B "$BUILD_DIR" -G Ninja \
    -DCMAKE_TOOLCHAIN_FILE="$VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake" \
    -DCMAKE_BUILD_TYPE=Release
ninja -C "$BUILD_DIR"
