#!/bin/bash

# FTL Hyperspace Test Runner for Darwin (macOS) - FTL 1.6.12
# Usage: run_test_darwin_1.6.12.sh [test_name]

# Load environment configuration
TEST_ENV_DIR="$(dirname "$0")/.."
if [ -f "$TEST_ENV_DIR/.test.env" ]; then
    source "$TEST_ENV_DIR/.test.env"
fi

DYLIB_PATH="build-darwin-1.6.12-debug/Hyperspace.1.6.12.amd64.dylib"
FTL_BINARY_PATH="${FTL_DARWIN_1_6_12_DIR}/Contents/MacOS/FTL"
TEST_NAME="${1:-}"

"$TEST_ENV_DIR/run_test_darwin.sh" "$DYLIB_PATH" "$FTL_BINARY_PATH" "$TEST_NAME"
