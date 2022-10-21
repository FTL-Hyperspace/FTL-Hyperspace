@echo off
docker run --rm -v %~dp0:/ftl ghcr.io/ftl-hyperspace/hs-devcontainer bash -c "cd /ftl && ./buildall.sh"
