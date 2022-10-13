#!/usr/bin/env bash

SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
docker run -it --rm -v $SCRIPT_DIR:/ftl ghcr.io/FTL-Hyperspace/hs-devcontainer bash -c "cd /ftl && ./buildall.sh"
