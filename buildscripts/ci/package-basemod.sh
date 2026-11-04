#!/bin/bash
set -e

SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
REPO_ROOT=$(cd $SCRIPT_DIR/../.. && pwd)

# Output file, Hyperspace.ftl in the current folder by default
OUTPUT="${1:-Hyperspace.ftl}"
# Made absolute, since zip runs from inside Mod Files
OUTPUT="$(cd "$(dirname "$OUTPUT")" && pwd)/$(basename "$OUTPUT")"

# Package Hyperspace.ftl from Mod Files
rm -f "$OUTPUT"
cd "$REPO_ROOT/Mod Files"
zip -r "$OUTPUT" *

echo "=== Package created: $OUTPUT ==="
