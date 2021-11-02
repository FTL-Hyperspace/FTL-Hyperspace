 
## Things to use different
 
 - `__int8`, `__int16`, `__int32`, `__int64` use C standard types of: `uint8_t`, `uint16_t`, `uint32_t`, `uint64_t` instead
 - Instead of using `VirtualProtect` directly for memory protection & unprotection, use the macros in `PALMemoryProtection.h` for a cross-platform compatible way.
   - Note you need to always use `MEMPROT_SAVE_PROT` & `MEMPROT_PAGESIZE` although you might get no errors for forgetting one but both are required for proper cross platform use of the other macros.
   
#### VirtualProtect replacement
Instead of
```c
DWORD dwOldProtect;
VirtualProtect(&vtable[0], sizeof(void*) * g_temporalVTableSize, PAGE_EXECUTE_READWRITE, &dwOldProtect);
// stuff
VirtualProtect(&vtable[0], sizeof(void*) * g_temporalVTableSize, dwOldProtect, &dwOldProtect);
```
Do
```c
#import "PALMemoryProtection.h"
// ...
MEMPROT_SAVE_PROT(dwOldProtect);
MEMPROT_PAGESIZE();

MEMPROT_UNPROTECT(&vtable[0], sizeof(void*) * g_temporalVTableSize, dwOldProtect);
// stuff
MEMPROT_REPROTECT(&vtable[0], sizeof(void*) * g_temporalVTableSize, dwOldProtect);
```
   
### Things not yet reimplemented but planned

 - `MessageBoxA` and `MessageBox` have not been reimplemented yet; however, when they are it is likely we will need to use SDL's MessageBox instead for a nice cross-platform method, this might render them slightly differently than the current Windows MessageBox, more information will be added here when a reimplementation is available.
   - On this same note it is likely I will need to add the build requirement of having libsdl on Windows.
   - For now any instance of MessageBox was replaced with writing to standard error when on Linux but that's not ideal.
