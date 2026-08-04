#!/bin/bash
set -e

# Applies fixes that an older devcontainer image is missing. Usage: devcontainer-fixes.sh <platform>...

SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

MINGW_HEADERS_VERSION=8.0.0

# Keep in sync with the SDL3 dependencies in Dockerfile-actual.
SDL3_LINUX_PACKAGES="libx11-dev libxext-dev libxcursor-dev libxi-dev libxfixes-dev libxrandr-dev \
libxrender-dev libxss-dev libxtst-dev libwayland-dev wayland-protocols libxkbcommon-dev \
libegl1-mesa-dev"

# Update toolchains
sync_toolchains() {
    cp "$SCRIPT_DIR"/toolchains/* /vcpkg/scripts/toolchains/
}

# Focal ships the mingw-w64 7.0.0 headers, which are too old for SDL3: the Direct3D renderers need
# dxgidebug.h and the WASAPI backend needs the stream options from a newer audioclient.h. Jammy has
# 8.0.0 with both, and they are architecture independent so the compiler itself stays untouched.
upgrade_mingw_headers() {
    local installed
    installed=$(dpkg-query -W -f='${Version}' mingw-w64-i686-dev 2>/dev/null || true)

    if [ -n "$installed" ] && dpkg --compare-versions "$installed" ge "$MINGW_HEADERS_VERSION"; then
        echo "mingw-w64 headers are $installed, nothing to fix"
        return
    fi

    echo "mingw-w64 headers are ${installed:-missing}, taking $MINGW_HEADERS_VERSION from jammy"

    cd /tmp
    echo "deb http://archive.ubuntu.com/ubuntu jammy universe" > /etc/apt/sources.list.d/jammy.list
    apt update
    apt-get download mingw-w64-common/jammy mingw-w64-i686-dev/jammy
    dpkg -i --force-overwrite mingw-w64-common_*.deb mingw-w64-i686-dev_*.deb
    rm -f mingw-w64-*.deb /etc/apt/sources.list.d/jammy.list
}

# vcpkg builds sdl3 from source on linux and needs the headers of the features it enables. Images
# built before SDL3 was added do not carry them.
install_sdl3_linux_deps() {
    local missing=""
    for package in $SDL3_LINUX_PACKAGES; do
        # The trailing newline matters, multi-arch packages report one status line per architecture
        dpkg-query -W -f='${Status}\n' "$package" 2>/dev/null | grep -q "^install ok installed$" \
            || missing="$missing $package"
    done

    if [ -z "$missing" ]; then
        echo "SDL3 linux dependencies are installed, nothing to fix"
        return
    fi

    echo "Installing missing SDL3 linux dependencies:$missing"
    apt update
    apt install -y --no-install-recommends $missing
}

for platform in "$@"; do
    case "$platform" in
        windows)
            sync_toolchains
            upgrade_mingw_headers
            ;;
        linux)
            install_sdl3_linux_deps
            ;;
        *)
            echo "Unknown platform: $platform" >&2
            exit 1
            ;;
    esac
done
