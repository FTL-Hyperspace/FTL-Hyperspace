# Wraps SWIG's external runtime header in an include guard.
# Usage: processSwigRuntime.sh <folder>   (the build folder, cmake passes it)
DIR="$1"

echo "#ifndef SWIGLUA" > "$DIR/swigluarun.h.temp2"
echo "#define SWIGLUA" >> "$DIR/swigluarun.h.temp2"
cat "$DIR/swigluarun.h.temp1" >> "$DIR/swigluarun.h.temp2"
echo "#endif" >> "$DIR/swigluarun.h.temp2"
rm "$DIR/swigluarun.h.temp1"
cmp -s "$DIR/swigluarun.h" "$DIR/swigluarun.h.temp2" && rm "$DIR/swigluarun.h.temp2" || mv -f "$DIR/swigluarun.h.temp2" "$DIR/swigluarun.h"
