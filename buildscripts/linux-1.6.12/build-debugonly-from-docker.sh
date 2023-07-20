#!/bin/bash

SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
docker run --rm -v $SCRIPT_DIR/../..:/workspaces/FTL-Hyperspace ghcr.io/ftl-hyperspace/hs-devcontainer bash -c "cd /workspaces/FTL-Hyperspace && buildscripts/linux-1.6.12/build-debugonly.sh"
