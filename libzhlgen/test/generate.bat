:: parsefuncs <input file> <function definitions path> <output cpp> <output h>
CALL ..\parsefuncs functions\win32\FTLGameStripped.h functions\win32\1.6.9 ..\..\FTLGameWin32.cpp ..\..\FTLGameWin32.h i386-w64-mingw32
CALL ..\parsefuncs functions\ELF_x86\FTLGameStripped.ELF32.h functions\ELF_x86\1.6.13 ..\..\FTLGameELF32.cpp ..\..\FTLGameELF32.h i386-pc-linux
pause