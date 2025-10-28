#!/bin/bash
set -e

SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
REPO_ROOT=$(cd $SCRIPT_DIR/../.. && pwd)
VERSION="$1"

if [ -z "$VERSION" ]; then
    echo "Error: Version number required"
    echo "Usage: $0 <version>"
    exit 1
fi

cd "$REPO_ROOT"

echo "=== Packaging macOS release $VERSION ==="

# Create package directory
rm -rf build-package-macos
mkdir -p build-package-macos/MacOS

# Copy Release Files structure
cp -r "Release Files/MacOS/"* build-package-macos/MacOS/ 2>/dev/null || true
cp "Release Files/README.txt" build-package-macos/

# Package Hyperspace.ftl from Mod Files
cd "Mod Files"
zip -r Hyperspace.ftl * -x Hyperspace.ftl
cd ..
mv "Mod Files/Hyperspace.ftl" build-package-macos/

# Copy built binaries
cp build-darwin-*/Hyperspace.*.dylib "build-package-macos/MacOS/"

# Create final zip
cd build-package-macos
zip -r "../FTL.Hyperspace.${VERSION}-MacOS.zip" *

echo "=== Package created: FTL.Hyperspace.${VERSION}-MacOS.zip ==="
