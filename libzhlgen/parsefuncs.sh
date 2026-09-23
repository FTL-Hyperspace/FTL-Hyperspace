#! /bin/bash

SOURCE="${BASH_SOURCE[0]}"
while [ -h "$SOURCE" ]; do # resolve $SOURCE until the file is no longer a symlink
  DIR="$( cd -P "$( dirname "$SOURCE" )" >/dev/null 2>&1 && pwd )"
  SOURCE="$(readlink "$SOURCE")"
  [[ $SOURCE != /* ]] && SOURCE="$DIR/$SOURCE" # if $SOURCE was a relative symlink, we need to resolve it relative to the path where the symlink file was located
done
DIR="$( cd -P "$( dirname "$SOURCE" )" >/dev/null 2>&1 && pwd )"

mkdir -p $DIR/../generated
cd $DIR/lua
lua parsefuncs.lua ../test/functions/win32/FTLGameStripped.h ../test/functions/win32/1.6.9 ../../generated/FTLGameWin32.cpp ../../generated/FTLGameWin32.h i386-w64-mingw32
lua parsefuncs.lua ../test/functions/ELF_x86/FTLGameStripped.ELF32.h ../test/functions/ELF_x86/1.6.13 ../../generated/FTLGameELF32.cpp ../../generated/FTLGameELF32.h i386-pc-linux
lua parsefuncs.lua ../test/functions/ELF_amd64/FTLGameStripped.h ../test/functions/ELF_amd64/1.6.13 ../../generated/FTLGameELF64.cpp ../../generated/FTLGameELF64.h x86_64-pc-linux
lua parsefuncs.lua ../test/functions/mac/FTLGameStripped.h ../test/functions/mac/1.6.13 ../../generated/FTLGameMacOSAMD64.cpp ../../generated/FTLGameMacOSAMD64.h x86_64-pc-darwin
