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

EXTRACT_DIR="Windows - Extract these files into where FTLGame.exe is"

echo "=== Packaging Windows release $VERSION ==="

# --- Mod zip ---
rm -rf build-package-windows
mkdir -p "build-package-windows/${EXTRACT_DIR}"

cp -r "Release Files/Windows/mod/"* "build-package-windows/${EXTRACT_DIR}/"
cp "Release Files/Windows/README.txt" "build-package-windows/"

# Package Hyperspace.ftl from Mod Files
cd "Mod Files"
zip -r Hyperspace.ftl * -x Hyperspace.ftl
cd ..
mv "Mod Files/Hyperspace.ftl" build-package-windows/

# Built Hyperspace.dll
cp build-*/Hyperspace.dll "build-package-windows/${EXTRACT_DIR}/"

cd build-package-windows
zip -r "../FTL.Hyperspace.${VERSION}-Windows.zip" *
cd ..

echo "=== Package created: FTL.Hyperspace.${VERSION}-Windows.zip ==="

# --- Patcher zip ---
rm -rf build-package-windows-patcher
mkdir -p "build-package-windows-patcher/${EXTRACT_DIR}"

cp -r "Release Files/Windows/patcher/"* "build-package-windows-patcher/${EXTRACT_DIR}/"
cp "Release Files/Windows/README.txt" "build-package-windows-patcher/"

cd build-package-windows-patcher
zip -r "../FTL.Hyperspace.${VERSION}-Windows-Patcher.zip" *
cd ..

echo "=== Package created: FTL.Hyperspace.${VERSION}-Windows-Patcher.zip ==="
