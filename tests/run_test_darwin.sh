#!/bin/bash

# FTL Hyperspace Automated Test Runner
# Launches FTL with Hyperspace, monitors execution, displays results
# Returns 0 if all tests pass, non-zero otherwise
#
# Usage: run_test_darwin.sh <dylib_path> <ftl_binary_path> [test_name]

set -e

# ============================================
# Configuration & Constants
# ============================================

# Check arguments
if [ $# -lt 2 ]; then
    echo "Usage: $0 <dylib_path> <ftl_binary_path> [test_name]"
    echo ""
    echo "Example:"
    echo "  $0 build-darwin-1.6.13-debug/Hyperspace.1.6.13.amd64.dylib \$HOME/Games/FasterThanLight/FTL1.6.13-base.app/Contents/MacOS/FTL"
    echo "  $0 build-darwin-1.6.13-debug/Hyperspace.1.6.13.amd64.dylib \$HOME/Games/FasterThanLight/FTL1.6.13-base.app/Contents/MacOS/FTL StoreTest"
    exit 1
fi

FTL_DYLIB_PATH="$1"
FTL_BINARY_PATH="$2"
TEST_NAME="${3:-}"

PROJECT_DIR="$(pwd)"

# Convert relative paths to absolute
if [[ "$FTL_DYLIB_PATH" != /* ]]; then
    FTL_DYLIB_PATH="$PROJECT_DIR/$FTL_DYLIB_PATH"
fi

if [[ "$FTL_BINARY_PATH" != /* ]]; then
    FTL_BINARY_PATH="$PROJECT_DIR/$FTL_BINARY_PATH"
fi

TEST_DIR="$PROJECT_DIR/test_results"
TEST_RESULTS_FILE="$TEST_DIR/tests/test_results.txt"
CENTRAL_LOG="$TEST_DIR/tests/all_tests.log"

TIMEOUT_SECONDS=3600
FREEZE_THRESHOLD=10
FREEZE_MIN_ELAPSED=15  # Don't check for freeze before this many seconds

# Colors
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m'

# ============================================
# Helper Functions
# ============================================

log()    { echo -e "${GREEN}[TEST RUNNER]${NC} $1"; }
error()  { echo -e "${RED}[ERROR]${NC} $1" >&2; }
warning(){ echo -e "${YELLOW}[WARNING]${NC} $1"; }

show_new_logs() {
    # Display any new lines from the central log since last check
    if [ -f "$CENTRAL_LOG" ]; then
        CURRENT_LOG_LINES=$(wc -l < "$CENTRAL_LOG")
        if [ "$CURRENT_LOG_LINES" -gt "$LAST_LOG_LINES" ]; then
            tail -n +$((LAST_LOG_LINES + 1)) "$CENTRAL_LOG"
            LAST_LOG_LINES=$CURRENT_LOG_LINES
        fi
    fi
}

cleanup() {
    # Kill FTL process if still running
    if [ ! -z "$FTL_PID" ] && kill -0 "$FTL_PID" 2>/dev/null; then
        kill "$FTL_PID" 2>/dev/null || true
        sleep 1
        kill -9 "$FTL_PID" 2>/dev/null || true
    fi
    # Kill any other FTL processes
    pkill -9 "^FTL$" 2>/dev/null || true
}
trap cleanup EXIT

# ============================================
# Pre-flight
# ============================================

log "Checking prerequisites..."

if [ ! -f "$FTL_DYLIB_PATH" ]; then
    error "Dylib not found: $FTL_DYLIB_PATH"
    exit 1
fi

if [ ! -f "$FTL_BINARY_PATH" ]; then
    error "FTL binary not found: $FTL_BINARY_PATH"
    exit 1
fi

rm -rf "$TEST_DIR"
mkdir -p "$TEST_DIR"

# Copy and unzip saves to test_results/saves
SAVES_SRC="$PROJECT_DIR/tests/saves"
SAVES_DST="$TEST_DIR/saves"

if [ -d "$SAVES_SRC" ]; then
    mkdir -p "$SAVES_DST"
    # Copy all files from saves directory
    cp -r "$SAVES_SRC"/* "$SAVES_DST"/ 2>/dev/null || true
    # Unzip any .ftlsav files into folders named after the archive
    for savefile in "$SAVES_DST"/*.ftlsav; do
        if [ -f "$savefile" ]; then
            # Get basename without .ftlsav extension
            folder_name=$(basename "$savefile" .ftlsav)
            mkdir -p "$SAVES_DST/$folder_name"
            unzip -o -q "$savefile" -d "$SAVES_DST/$folder_name"
            rm "$savefile"
        fi
    done
    log "Saves copied to $SAVES_DST"
fi

log "Prerequisites OK"

# ============================================
# Launch FTL
# ============================================

log "Launching FTL with Hyperspace dylib..."
log "  Dylib: $FTL_DYLIB_PATH"
if [ ! -z "$TEST_NAME" ]; then
    log "  Test: $TEST_NAME (single test mode)"
else
    log "  Test: ALL (full suite)"
fi
log "  Timeout: ${TIMEOUT_SECONDS}s"

export DYLD_INSERT_LIBRARIES="$FTL_DYLIB_PATH"
# launch auto tests
export HYPERSPACE_AUTO_TEST=1

# optional: run specific test by name
if [ ! -z "$TEST_NAME" ]; then
    export HYPERSPACE_TEST_NAME="$TEST_NAME"
fi

# immediate exit on freeze detection
export HYPERSPACE_FORCE_EXIT_ON_FREEZE=1

# skip bug report dialog
export HYPERSPACE_SKIP_BUG_REPORT=1
(
    cd "$TEST_DIR" || exit 1
    exec "$FTL_BINARY_PATH" > /dev/null 2>&1
) &
FTL_PID=$!

log "FTL launched (PID: $FTL_PID)"
sleep 2

# ============================================
# Monitor execution
# ============================================

START_TIME=$(date +%s)
LAST_LOG_LINES=0

log "Monitoring test execution..."
echo ""

while true; do
    ELAPSED=$(($(date +%s) - START_TIME))

    # Display new logs
    show_new_logs

    # Check for completion
    if [ -f "$TEST_RESULTS_FILE" ]; then
        show_new_logs  # Show any final log lines
        log "Tests completed successfully after ${ELAPSED}s"
        break
    fi

    # Check for crash
    if ! kill -0 "$FTL_PID" 2>/dev/null; then
        show_new_logs
        error "FTL process crashed (${ELAPSED}s)"
        exit 2
    fi

    # Check for timeout
    if [ "$ELAPSED" -gt "$TIMEOUT_SECONDS" ]; then
        error "Test timeout after ${TIMEOUT_SECONDS}s"
        exit 3
    fi

    sleep 0.5
done

# ============================================
# Display results
# ============================================

echo ""
cat "$TEST_RESULTS_FILE"
echo ""

# Parse results
ALL_PASSED=$(grep "^All Passed:" "$TEST_RESULTS_FILE" | awk '{print $3}')

if [ "$ALL_PASSED" = "Yes" ]; then
    echo -e "${GREEN}========================================${NC}"
    echo -e "${GREEN}  ✓ ALL TESTS PASSED${NC}"
    echo -e "${GREEN}========================================${NC}"
    echo ""
    exit 0
else
    echo -e "${RED}========================================${NC}"
    echo -e "${RED}  ✗ TESTS FAILED${NC}"
    echo -e "${RED}========================================${NC}"
    echo ""
    exit 1
fi
