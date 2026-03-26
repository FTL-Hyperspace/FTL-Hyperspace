#!/bin/bash
# Helper script to run commands inside the devcontainer
# Usage: docker-run-in-devcontainer.sh <command>
# Example: docker-run-in-devcontainer.sh buildscripts/buildall.sh

set -e

SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
source "$SCRIPT_DIR/../.devcontainer/devcontainer.sh"

COMMAND="${1:?Error: Command argument is required}"

docker run --rm -v $SCRIPT_DIR/..:/workspaces/FTL-Hyperspace "$DEVCONTAINER_FULL" bash -c "cd /workspaces/FTL-Hyperspace && source .devcontainer/devcontainer-fixes.sh && $COMMAND"
