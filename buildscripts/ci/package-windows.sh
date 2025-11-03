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

echo "=== Packaging Windows release $VERSION ==="

# Create package directory
rm -rf build-package-windows
mkdir -p build-package-windows

# Copy Release Files structure
cp -r "Release Files/Windows - Extract these files into where FTLGame.exe is" build-package-windows/
cp "Release Files/README.txt" build-package-windows/

# Package Hyperspace.ftl from Mod Files
cd "Mod Files"
zip -r Hyperspace.ftl * -x Hyperspace.ftl
cd ..
mv "Mod Files/Hyperspace.ftl" build-package-windows/

# Copy built binaries
cp build-*/Hyperspace.dll "build-package-windows/Windows - Extract these files into where FTLGame.exe is/"

# Create final zip
cd build-package-windows
zip -r "../FTL.Hyperspace.${VERSION}-Windows.zip" *

echo "=== Package created: FTL.Hyperspace.${VERSION}-Windows.zip ==="
