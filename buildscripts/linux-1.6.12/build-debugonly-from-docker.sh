#!/bin/bash

SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
$SCRIPT_DIR/../docker-run-in-devcontainer.sh buildscripts/linux-1.6.12/build-debugonly.sh
