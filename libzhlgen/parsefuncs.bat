@echo off
set inputPath=%~dpnx1
set funcPath=%~dpnx2
set outputCPP=%~dpnx3
set outputH=%~dpnx4
pushd %~dp0\lua
lua parsefuncs.lua "%inputPath%" "%funcPath%" "%outputCPP%" "%outputH%"
popd