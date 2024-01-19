echo "#ifndef SWIGLUA" > swigluarun.h.temp2
echo "#define SWIGLUA" >> swigluarun.h.temp2
cat swigluarun.h.temp1 >> swigluarun.h.temp2
echo "#endif" >> swigluarun.h.temp2
rm swigluarun.h.temp1
cmp swigluarun.h swigluarun.h.temp2 && rm swigluarun.h.temp2 || mv -f swigluarun.h.temp2 swigluarun.h
