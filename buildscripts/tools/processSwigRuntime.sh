echo "#ifndef SWIGLUA" > lua/swigluarun.h.temp2
echo "#define SWIGLUA" >> lua/swigluarun.h.temp2
cat lua/swigluarun.h.temp1 >> lua/swigluarun.h.temp2
echo "#endif" >> lua/swigluarun.h.temp2
rm lua/swigluarun.h.temp1
cmp lua/swigluarun.h lua/swigluarun.h.temp2 && rm lua/swigluarun.h.temp2 || mv -f lua/swigluarun.h.temp2 lua/swigluarun.h
