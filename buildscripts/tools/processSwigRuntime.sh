echo "#ifndef SWIGLUA" > generated/swigluarun.h.temp2
echo "#define SWIGLUA" >> generated/swigluarun.h.temp2
cat generated/swigluarun.h.temp1 >> generated/swigluarun.h.temp2
echo "#endif" >> generated/swigluarun.h.temp2
rm generated/swigluarun.h.temp1
cmp generated/swigluarun.h generated/swigluarun.h.temp2 && rm generated/swigluarun.h.temp2 || mv -f generated/swigluarun.h.temp2 generated/swigluarun.h
