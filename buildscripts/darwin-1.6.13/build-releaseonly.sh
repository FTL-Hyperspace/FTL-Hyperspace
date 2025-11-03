#!/bin/bash
set -e

SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
REPO_ROOT=$(cd $SCRIPT_DIR/../.. && pwd)

$SCRIPT_DIR/../build-one-variant.sh build-darwin-1.6.13-release amd64-darwin-ftl ON Release "${REPO_ROOT}/vcpkg"