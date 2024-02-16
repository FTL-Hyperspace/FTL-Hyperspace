#!/bin/bash
set -e

SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

$SCRIPT_DIR/../build-one-variant.sh build-linux-1.6.12-release amd64-linux-ftl OFF Release
