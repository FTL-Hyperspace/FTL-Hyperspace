#! /bin/bash

SOURCE="${BASH_SOURCE[0]}"
while [ -h "$SOURCE" ]; do # resolve $SOURCE until the file is no longer a symlink
  DIR="$( cd -P "$( dirname "$SOURCE" )" >/dev/null 2>&1 && pwd )"
  SOURCE="$(readlink "$SOURCE")"
  [[ $SOURCE != /* ]] && SOURCE="$DIR/$SOURCE" # if $SOURCE was a relative symlink, we need to resolve it relative to the path where the symlink file was located
done
DIR="$( cd -P "$( dirname "$SOURCE" )" >/dev/null 2>&1 && pwd )"

# Ubuntu names the interpreter lua5.3, so let the caller say which one to use
LUA="${LUA:-lua}"

GENERATED="$DIR/../generated"
mkdir -p "$GENERATED"

TEMP=$(mktemp -d)
trap 'rm -rf "$TEMP"' EXIT

cd $DIR/lua

# Generates under the final names, the .cpp includes its header by name, then keeps the
# old file when nothing changed so build folders sharing generated/ don't recompile
# after a run that produced the same code
generate() {
    local stripped_header=$1 signatures=$2 name=$3 triple=$4

    # The generator prints every file it writes, which is all of them, every run
    $LUA parsefuncs.lua "$stripped_header" "$signatures" "$TEMP/$name.cpp" "$TEMP/$name.h" "$triple" > /dev/null

    for ext in cpp h; do
        if ! cmp -s "$TEMP/$name.$ext" "$GENERATED/$name.$ext"; then
            mv -f "$TEMP/$name.$ext" "$GENERATED/$name.$ext"
            echo "updated $name.$ext"
        fi
    done
}

generate ../test/functions/win32/FTLGameStripped.h        ../test/functions/win32/1.6.9      FTLGameWin32       i386-w64-mingw32
generate ../test/functions/ELF_x86/FTLGameStripped.ELF32.h ../test/functions/ELF_x86/1.6.13  FTLGameELF32       i386-pc-linux
generate ../test/functions/ELF_amd64/FTLGameStripped.h     ../test/functions/ELF_amd64/1.6.13 FTLGameELF64      x86_64-pc-linux
generate ../test/functions/mac/FTLGameStripped.h           ../test/functions/mac/1.6.13      FTLGameMacOSAMD64  x86_64-pc-darwin
