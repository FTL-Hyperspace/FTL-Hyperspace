#!/bin/bash
set -e

SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
REPO_ROOT=$(cd $SCRIPT_DIR/../.. && pwd)

echo "=== Setting up macOS build environment ==="

# Force --yes on Homebrew commands to avoid interactive prompts.
export NONINTERACTIVE=1
export HOMEBREW_NO_ASK=1
export HOMEBREW_NO_AUTO_UPDATE=1
export HOMEBREW_NO_INSTALL_CLEANUP=1

# Check if Homebrew is installed
if ! command -v brew &> /dev/null; then
    echo "Installing Homebrew (arm64)..."
    /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

    # On Apple Silicon brew lands in /opt/homebrew, which is not on the default PATH
    BREW_PREFIX=$([ -x /opt/homebrew/bin/brew ] && echo /opt/homebrew || echo /usr/local)
    echo "eval \"\$($BREW_PREFIX/bin/brew shellenv)\"" >> "$HOME/.zprofile"
    eval "$("$BREW_PREFIX/bin/brew" shellenv)"
else
    echo "Homebrew (arm64) already installed"
fi

# Install missing tools via arm64 Homebrew; tools already on PATH are left alone,
# installing over them would upgrade their dependencies (llvm, z3, pcre2, ...)
missing=""
for pair in cmake:cmake git:git ninja:ninja lld:ld64.lld swig:swig; do
    command -v "${pair#*:}" > /dev/null || missing="$missing ${pair%%:*}"
done
if [ -n "$missing" ]; then
    echo "Installing arm64 build dependencies:$missing"
    brew install $missing
fi

# Lua with lpeg and lfs generates the hook definitions; a working one is left alone
if ! lua -e "require('lpeg'); require('lfs')" 2> /dev/null; then
    brew install lua luarocks
    for rock in lpeg luafilesystem; do
        luarocks install --global "$rock"
    done
fi

# Clone and bootstrap vcpkg
if [ ! -d "$REPO_ROOT/vcpkg" ]; then
    echo "Cloning vcpkg..."
    cd "$REPO_ROOT"
    git clone https://github.com/microsoft/vcpkg.git

    echo "Bootstrapping vcpkg..."
    cd vcpkg
    ./bootstrap-vcpkg.sh
else
    echo "vcpkg already present at $REPO_ROOT/vcpkg"
    cd "$REPO_ROOT/vcpkg"

    echo "Updating vcpkg..."
    git pull
    ./bootstrap-vcpkg.sh
fi

# Copy toolchain and triplet files
echo "Setting up vcpkg toolchain and triplet files..."
cp "$REPO_ROOT/.devcontainer/toolchains/amd64-darwin-ftl.cmake" "$REPO_ROOT/vcpkg/scripts/toolchains/"
cp "$REPO_ROOT/.devcontainer/triplets/amd64-darwin-ftl.cmake" "$REPO_ROOT/vcpkg/triplets/"

cd "$REPO_ROOT"

echo "=== macOS build environment setup complete ==="
echo "You can now run: buildscripts/buildall-darwin.sh"
