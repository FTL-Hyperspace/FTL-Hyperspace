#!/bin/bash
set -e

# Applies fixes that an older devcontainer image is missing. Usage: devcontainer-fixes.sh <platform>...

SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

# Call this after editing the toolchain files, the image carries its own copies
sync_toolchains() {
    cp "$SCRIPT_DIR"/toolchains/* /vcpkg/scripts/toolchains/
}

sync_toolchains

for platform in "$@"; do
    case "$platform" in
        windows|linux)
            ;;
        *)
            echo "Unknown platform: $platform" >&2
            exit 1
            ;;
    esac
done
