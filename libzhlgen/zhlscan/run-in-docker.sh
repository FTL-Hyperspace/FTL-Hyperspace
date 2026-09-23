#!/bin/bash
# Run a command from the repository root inside the scanner build container
# (see Dockerfile). Without arguments, builds the scanners. For Linux and
# Windows (Docker Desktop / WSL2) hosts; on macOS the native build.sh is faster.
# The container builds into build-zhlscan-docker/ so it never collides with a
# native build-zhlscan/ on the same checkout.
#
#   run-in-docker.sh                                   # = build.sh
#   run-in-docker.sh libzhlgen/verify_sigs.py linux    # verify in the same environment

set -e

SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
REPO_ROOT=$(cd "$SCRIPT_DIR/../.." && pwd)
IMAGE=hyperspace-zhlscan

# The scanners must be x86_64 (the generated code is x86-only), hence the explicit platform.
docker build --platform linux/amd64 -t "$IMAGE" "$SCRIPT_DIR"
docker run --rm --platform linux/amd64 \
    -e ZHLSCAN_BUILD_DIR=/workspaces/FTL-Hyperspace/build-zhlscan-docker \
    -v "$REPO_ROOT:/workspaces/FTL-Hyperspace" "$IMAGE" \
    "${@:-libzhlgen/zhlscan/build.sh}"
