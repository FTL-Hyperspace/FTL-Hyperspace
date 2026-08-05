#!/bin/bash

# Test ZHL signatures against multiple FTL binaries
# Launches each binary with Hyperspace, captures zhl.log, compares with nm
#
# Usage: ./test_all_binaries.sh [FTL_APP_DIR]
#   FTL_APP_DIR: Path to directory containing FTL binaries (default: $HOME/Games/Heroic/FasterThanLight/FTL-frank.app/Contents/MacOS)

set -e

# ============================================
# Configuration
# ============================================

PROJECT_DIR="$(pwd)"
FTL_APP_DIR="${1:-$HOME/Games/Heroic/FasterThanLight/FTL-frank.app/Contents/MacOS}"

# Dylib paths per version
DYLIB_12="$PROJECT_DIR/build-darwin-1.6.12-debug/Hyperspace.1.6.12.amd64.dylib"
DYLIB_13="$PROJECT_DIR/build-darwin-1.6.13-debug/Hyperspace.1.6.13.amd64.dylib"

COMPARE_SCRIPT="$PROJECT_DIR/libzhlgen/compare_zhl_nm.py"

TEST_RESULTS_BASE="$PROJECT_DIR/test_results/zhl_test"

# Binaries to test (name:binary:version)
declare -a BINARIES=(
    "12-steam:FTL-12-steam:12"
    "12-gog:FTL-12-gog:12"
    "12-epic:FTL-12-epic:12"
    "12-humble:FTL-12-humble:12"
    "13-steam:FTL-13-steam:13"
    "13-gog:FTL-13-gog:13"
)

# How long to wait for ZHL to initialize (seconds)
INIT_TIMEOUT=4

# Colors
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m'

# ============================================
# Helper Functions
# ============================================

log()     { echo -e "${GREEN}[TEST]${NC} $1"; }
error()   { echo -e "${RED}[ERROR]${NC} $1" >&2; }
warning() { echo -e "${YELLOW}[WARNING]${NC} $1"; }
header()  { echo -e "\n${BLUE}========================================${NC}"; echo -e "${BLUE}  $1${NC}"; echo -e "${BLUE}========================================${NC}"; }

cleanup() {
    # Kill any FTL processes
    pkill -9 -f "FTL-1[23]-" 2>/dev/null || true
    pkill -9 "^FTL$" 2>/dev/null || true
}

test_binary() {
    local name="$1"
    local binary="$2"
    local version="$3"
    local binary_path="$FTL_APP_DIR/$binary"
    local test_dir="$TEST_RESULTS_BASE/$name"
    local zhl_log="$test_dir/zhl.log"

    # Select correct dylib for version
    local dylib_path
    if [ "$version" = "12" ]; then
        dylib_path="$DYLIB_12"
    else
        dylib_path="$DYLIB_13"
    fi

    header "Testing: $name ($binary)"

    # Check binary exists
    if [ ! -f "$binary_path" ]; then
        warning "Binary not found: $binary_path - SKIPPING"
        return 1
    fi

    # Check dylib exists
    if [ ! -f "$dylib_path" ]; then
        warning "Dylib not found: $dylib_path - SKIPPING"
        return 1
    fi

    # Create test directory
    rm -rf "$test_dir"
    mkdir -p "$test_dir"

    log "Launching $binary with Hyperspace..."
    log "  Dylib: $dylib_path"

    (
        cd "$test_dir" || exit 1
        # Force x86_64 on Apple Silicon so dylib architecture matches
        exec arch -x86_64 /bin/bash -c "DYLD_INSERT_LIBRARIES='$dylib_path' HYPERSPACE_SKIP_BUG_REPORT=1 '$binary_path'" > stdout.log 2>&1
    ) &
    local pid=$!

    log "Process started (PID: $pid)"

    # Wait for ZHL to initialize
    sleep $INIT_TIMEOUT

    # Kill the process
    if kill -0 "$pid" 2>/dev/null; then
        log "Terminating FTL process..."
        kill "$pid" 2>/dev/null || true
        sleep 1
        kill -9 "$pid" 2>/dev/null || true
    fi

    # Check if we got the log
    if [ ! -f "$zhl_log" ] || [ ! -s "$zhl_log" ]; then
        error "No zhl.log produced for $name"
        if [ -f "$test_dir/stdout.log" ]; then
            error "stdout.log contents:"
            cat "$test_dir/stdout.log"
        fi
        return 1
    fi

    log "Running compare_zhl_nm.py..."

    # Run comparison (output to console)
    python3 "$COMPARE_SCRIPT" "$zhl_log" "$binary_path"
    echo ""

    return 0
}

# ============================================
# Main
# ============================================

trap cleanup EXIT

# Check prerequisites
if [ ! -f "$DYLIB_12" ] && [ ! -f "$DYLIB_13" ]; then
    error "No dylibs found. Build first:"
    error "  $DYLIB_12"
    error "  $DYLIB_13"
    exit 1
fi

if [ ! -f "$COMPARE_SCRIPT" ]; then
    error "Compare script not found: $COMPARE_SCRIPT"
    exit 1
fi

# Show which dylibs are available
log "Available dylibs:"
[ -f "$DYLIB_12" ] && log "  1.6.12: $DYLIB_12" || warning "  1.6.12: NOT FOUND"
[ -f "$DYLIB_13" ] && log "  1.6.13: $DYLIB_13" || warning "  1.6.13: NOT FOUND"

# Clean up any previous runs
cleanup
rm -rf "$TEST_RESULTS_BASE"
mkdir -p "$TEST_RESULTS_BASE"

log "Starting ZHL signature tests..."
log "App directory: $FTL_APP_DIR"
log "Dylib: $DYLIB_PATH"
echo ""

# Test each binary
for entry in "${BINARIES[@]}"; do
    IFS=':' read -r name binary version <<< "$entry"
    test_binary "$name" "$binary" "$version" || true
    cleanup
    sleep 1
done
