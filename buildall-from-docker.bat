@echo off
docker run -it --rm -v %~dp0:/ftl ghcr.io/ftl-hyperspace/hs-devcontainer bash -c "cd /ftl && ./buildall.sh"
