@echo off
set inputPath=%~dpnx1
set funcPath=%~dpnx2
set outputCPP=%~dpnx3
set outputH=%~dpnx4
set platform=%5
pushd %~dp0\lua
lua parsefuncs.lua "%inputPath%" "%funcPath%" "%outputCPP%" "%outputH%" %platform%
popd