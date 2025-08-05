#!/bin/bash
DIR="$(cd "$(dirname "$0")" && pwd)"

# Ensure all logs end in the vanilla location (Can be removed to generat them in the launch directory)
SAVE_DIR="$HOME/Library/Application Support/FasterThanLight"
mkdir -p "$SAVE_DIR"
cd "$SAVE_DIR" || exit 1

# Insert the Hyperspace dylib into the launch process 
export DYLD_INSERT_LIBRARIES="$DIR/Hyperspace.1.6.13.amd64.dylib"

# Execute FTL itself
exec "$DIR/FTL" "$@"
