#!/bin/bash
set -e

SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

$SCRIPT_DIR/darwin-1.6.13/build-debugonly.sh
$SCRIPT_DIR/darwin-1.6.12/build-debugonly.sh

$SCRIPT_DIR/darwin-1.6.13/build-releaseonly.sh
$SCRIPT_DIR/darwin-1.6.12/build-releaseonly.sh
