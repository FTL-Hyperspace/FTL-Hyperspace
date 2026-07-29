#!/bin/bash
set -e

SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
REPO_ROOT=$(cd $SCRIPT_DIR/../.. && pwd)

echo "=== Setting up macOS build environment ==="

# Check if Homebrew is installed
if ! command -v brew &> /dev/null; then
    echo "Installing Homebrew (arm64)..."
    /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
else
    echo "Homebrew (arm64) already installed"
fi

# Install required tools via arm64 Homebrew
echo "Installing arm64 build dependencies..."
brew install cmake git ninja lld swig


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
