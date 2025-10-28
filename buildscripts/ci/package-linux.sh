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

echo "=== Packaging Linux release $VERSION ==="

# Create package directory
rm -rf build-package-linux
mkdir -p build-package-linux/Linux

# Copy Release Files structure
cp -r "Release Files/Linux/"* build-package-linux/Linux/
cp "Release Files/README.txt" build-package-linux/

# Package Hyperspace.ftl from Mod Files
cd "Mod Files"
zip -r Hyperspace.ftl * -x Hyperspace.ftl
cd ..
mv "Mod Files/Hyperspace.ftl" build-package-linux/

# Copy built binaries
cp build-*/Hyperspace.*.so "build-package-linux/Linux/"

# Create final zip
cd build-package-linux
zip -r "../FTL.Hyperspace.${VERSION}-Linux.zip" * -x "Linux/IGNORE_THIS_FILE.txt"

echo "=== Package created: FTL.Hyperspace.${VERSION}-Linux.zip ==="
