#!/bin/bash
# Helper script to run commands inside the devcontainer
# Usage: docker-run-in-devcontainer.sh <command>
# Example: docker-run-in-devcontainer.sh buildscripts/buildall.sh

set -e

SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
source "$SCRIPT_DIR/../.devcontainer/devcontainer.sh"

COMMAND="${1:?Error: Command argument is required}"
PRE_COMMAND=""
PLATFORMS=""
DOCKER_ENV=""

# Emulating the amd64 image on an arm host makes vcpkg's own cmake hang waiting on children that
# already exited.
case "$(uname -m)" in
    arm64 | aarch64) DOCKER_ENV="-e VCPKG_FORCE_SYSTEM_BINARIES=1" ;;
esac

# generateVersion.sh runs inside the container and stamps these into the binary.
for stamp in HS_BUILD_BRANCH HS_BUILD_HASH; do
    if [ -n "${!stamp}" ]; then DOCKER_ENV="$DOCKER_ENV -e $stamp"; fi
done

case "$COMMAND" in
    buildscripts/windows/*) PLATFORMS="windows" ;;
    buildscripts/linux-*/*) PLATFORMS="linux" ;;
    buildscripts/buildall*.sh) PLATFORMS="windows linux" ;;
esac

if [ -n "$PLATFORMS" ]; then
    PRE_COMMAND="bash .devcontainer/devcontainer-fixes.sh $PLATFORMS && "
fi

docker run --rm $DOCKER_ENV -v "$SCRIPT_DIR/..:/workspaces/FTL-Hyperspace" "$DEVCONTAINER_FULL" bash -c "cd /workspaces/FTL-Hyperspace && ${PRE_COMMAND}$COMMAND"
