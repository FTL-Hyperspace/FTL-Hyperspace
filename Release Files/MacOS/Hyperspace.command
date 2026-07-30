#!/bin/bash
DIR="$(cd "$(dirname "$0")" && pwd)"

# Ensure all logs end in the vanilla location (Can be removed to generate them in the launch directory)
SAVE_DIR="$HOME/Library/Application Support/FasterThanLight"
mkdir -p "$SAVE_DIR"
cd "$SAVE_DIR" || exit 1

# Find the Hyperspace dylib
files=("$DIR"/Hyperspace.1.6.1*.amd64.dylib)

# Ensure only one dylib is present
(( ${#files[@]} == 1 )) || {
     osascript -e 'display alert "Hyperspace Error" message "Please ensure exactly one Hyperspace dylib is present, matching your game version"'; 
     exit 1; 
    }

# Insert the dylib
export DYLD_INSERT_LIBRARIES="${files[0]}"

# Execute FTL itself
exec "$DIR/FTL" "$@"