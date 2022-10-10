echo #ifndef SWIGLUA > lua\swigluarun.h.temp2
echo #define SWIGLUA >> lua\swigluarun.h.temp2
type lua\swigluarun.h.temp1 >> lua\swigluarun.h.temp2
echo #endif >> lua\swigluarun.h.temp2
del lua\swigluarun.h.temp1
fc /L lua\swigluarun.h lua\swigluarun.h.temp2
if not errorlevel 0 move /Y lua\swigluarun.h.temp2 lua\swigluarun.h
del lua\swigluarun.h.temp2
