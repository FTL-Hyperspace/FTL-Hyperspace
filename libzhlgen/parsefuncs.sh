#! /bin/bash

SOURCE="${BASH_SOURCE[0]}"
while [ -h "$SOURCE" ]; do # resolve $SOURCE until the file is no longer a symlink
  DIR="$( cd -P "$( dirname "$SOURCE" )" >/dev/null 2>&1 && pwd )"
  SOURCE="$(readlink "$SOURCE")"
  [[ $SOURCE != /* ]] && SOURCE="$DIR/$SOURCE" # if $SOURCE was a relative symlink, we need to resolve it relative to the path where the symlink file was located
done
DIR="$( cd -P "$( dirname "$SOURCE" )" >/dev/null 2>&1 && pwd )"

cd $DIR/lua
lua parsefuncs.lua ../test/FTLGameStripped.h ../test/functions/win32/1.6.9 ../../FTLGameWin32.cpp ../../FTLGameWin32.h WINDOWS
lua parsefuncs.lua ../test/FTLGameStripped.h ../test/functions/ELF_x86/1.6.13 ../../FTLGameELF32.cpp ../../FTLGameELF32.h POSIX
