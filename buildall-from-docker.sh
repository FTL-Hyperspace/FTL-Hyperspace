#!/usr/bin/env bash

SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
docker run --rm -v $SCRIPT_DIR:/ftl ghcr.io/ftl-hyperspace/hs-devcontainer bash -c "cd /ftl && ./buildall.sh"
