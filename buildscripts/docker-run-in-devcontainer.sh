#!/bin/bash
# Helper script to run commands inside the devcontainer
# Usage: docker-run-in-devcontainer.sh <command>
# Example: docker-run-in-devcontainer.sh buildscripts/buildall.sh

set -e

SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
source "$SCRIPT_DIR/../.devcontainer/devcontainer.sh"

COMMAND="${1:?Error: Command argument is required}"
PRE_COMMAND=""

case "$COMMAND" in
    buildscripts/windows/build-debugonly.sh)
        PRE_COMMAND="bash .devcontainer/devcontainer-fixes.sh build-windows-debug && "
        ;;
    buildscripts/windows/build-releaseonly.sh)
        PRE_COMMAND="bash .devcontainer/devcontainer-fixes.sh build-windows-release && "
        ;;
    buildscripts/buildall.sh)
        PRE_COMMAND="bash .devcontainer/devcontainer-fixes.sh build-windows-debug build-windows-release && "
        ;;
    buildscripts/buildall-release-only.sh)
        PRE_COMMAND="bash .devcontainer/devcontainer-fixes.sh build-windows-release && "
        ;;
esac

docker run --rm -v "$SCRIPT_DIR/..:/workspaces/FTL-Hyperspace" "$DEVCONTAINER_FULL" bash -c "cd /workspaces/FTL-Hyperspace && ${PRE_COMMAND}$COMMAND"
