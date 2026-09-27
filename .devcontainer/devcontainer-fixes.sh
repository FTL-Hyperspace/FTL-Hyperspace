#!/bin/bash
set -e

# Applies fixes that an older devcontainer image is missing. Usage: devcontainer-fixes.sh <platform>...

SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

# Call this after editing the toolchain files, the image carries its own copies
sync_toolchains() {
    cp "$SCRIPT_DIR"/toolchains/* /vcpkg/scripts/toolchains/
}

# The build generates the hook definitions with libzhlgen/parsefuncs.sh, which needs the
# interpreter plus lpeg and lfs. Images built before that was wired into cmake carry none.
install_lua() {
    if lua5.3 -e "require('lpeg'); require('lfs')" 2>/dev/null; then
        echo "lua with lpeg and lfs is installed, nothing to fix"
        return
    fi

    echo "Installing lua5.3, lua-lpeg and lua-filesystem"
    apt update
    apt install -y --no-install-recommends lua5.3 lua-lpeg lua-filesystem
}

install_lua

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
