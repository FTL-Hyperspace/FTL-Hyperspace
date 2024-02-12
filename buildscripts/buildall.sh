#!/bin/bash
set -e

SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

$SCRIPT_DIR/build-one-variant.sh build-linux-1.6.13-debug amd64-linux-ftl ON Debug
$SCRIPT_DIR/build-one-variant.sh build-linux-1.6.12-debug amd64-linux-ftl OFF Debug
$SCRIPT_DIR/build-one-variant.sh build-windows-debug x86-windows-ftl OFF Debug

$SCRIPT_DIR/build-one-variant.sh build-linux-1.6.13-release amd64-linux-ftl ON Release
$SCRIPT_DIR/build-one-variant.sh build-linux-1.6.12-release amd64-linux-ftl OFF Release
$SCRIPT_DIR/build-one-variant.sh build-windows-release x86-windows-ftl OFF Release
