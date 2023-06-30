@echo off
docker run --rm -v %~dp0..:/workspaces/FTL-Hyperspace ghcr.io/ftl-hyperspace/hs-devcontainer bash -c "cd /workspaces/FTL-Hyperspace && buildscripts/buildall.sh"
