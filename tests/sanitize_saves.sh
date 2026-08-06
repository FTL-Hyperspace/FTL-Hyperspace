#!/bin/bash

# Sanitize Save Files
# Extracts zip files in tests/saves, keeps only *.sav files,
# repacks them into a new zip named {savename}.ftlsav
#
# Usage: sanitize_saves.sh [saves_directory]
#   saves_directory: Optional path to saves folder (default: tests/saves)

set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
SAVES_DIR="${1:-$SCRIPT_DIR/saves}"

if [ ! -d "$SAVES_DIR" ]; then
    echo "Error: Saves directory not found: $SAVES_DIR"
    exit 1
fi

echo "Sanitizing saves in: $SAVES_DIR"

# Process each zip file
for zipfile in "$SAVES_DIR"/*.zip; do
    if [ ! -f "$zipfile" ]; then
        continue
    fi

    basename=$(basename "$zipfile" .zip)
    echo "Processing: $basename.zip"

    # Create temp directory for extraction
    tmpdir=$(mktemp -d)

    # Extract zip
    unzip -q "$zipfile" -d "$tmpdir"

    # Create temp directory for .sav files only
    savdir=$(mktemp -d)

    # Find all .sav files and copy to savdir
    find "$tmpdir" -name "*.sav" -type f | while read savfile; do
        savname=$(basename "$savfile")
        cp "$savfile" "$savdir/$savname"
        echo "  + $savname"
    done

    # Create new zip with only .sav files
    output_file="$SAVES_DIR/${basename}.ftlsav"
    rm -f "$output_file"
    (cd "$savdir" && zip -q "$output_file" *.sav 2>/dev/null || true)

    # Cleanup
    rm -rf "$tmpdir" "$savdir"
    rm "$zipfile"

    echo "  -> ${basename}.ftlsav"
done

echo "Done."
