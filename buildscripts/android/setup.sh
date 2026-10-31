#!/bin/bash
# One-time setup on Linux: vcpkg plus the Android toolchain and triplet.
# Also needs: cmake, ninja, swig, lua with lpeg and lfs (apt install swig lua5.3
# lua-lpeg lua-filesystem), the Android NDK, and the port's libc++ (see README.md).
set -e
SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
REPO_ROOT=$(cd "$SCRIPT_DIR/../.." && pwd)

if [ ! -d "$REPO_ROOT/vcpkg" ]; then
    git clone https://github.com/microsoft/vcpkg.git "$REPO_ROOT/vcpkg"
fi
(cd "$REPO_ROOT/vcpkg" && ./bootstrap-vcpkg.sh -disableMetrics)
cp "$REPO_ROOT/.devcontainer/toolchains/arm64-android-ftl.cmake" "$REPO_ROOT/vcpkg/scripts/toolchains/"
cp "$REPO_ROOT/.devcontainer/triplets/arm64-android-ftl.cmake" "$REPO_ROOT/vcpkg/triplets/"
