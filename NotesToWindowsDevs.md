 
## Things to use different
 
 - `__int8`, `__int16`, `__int32`, `__int64` use C standard types of: `uint8_t`, `uint16_t`, `uint32_t`, `uint64_t` instead
 - `UINT` use C standard type of `unsigned int` instead
 - `DWORD` use C standard type of `uint32_t` instead
 - Instead of using `VirtualProtect` directly for memory protection & unprotection, use the macros in `PALMemoryProtection.h` for a cross-platform compatible way.
   - Note you need to always use `MEMPROT_SAVE_PROT` & `MEMPROT_PAGESIZE` although you might get no errors for forgetting one but both are required for proper cross platform use of the other macros.
   
### Unordered_map and Enum keys
If using an unordered_map and the key of the map is any Enum type you must also use EnumClassHash in its template for hash matching.
You will not get errors on Windows but it will cause errors for the Linux compile if you forget this change.

Example
```c++
std::unordered_map<CrewStat, std::vector<StatBoost>> statBoosts;
```
Must become
```c++
#include "EnumClassHash.h"
// ...
std::unordered_map<CrewStat, std::vector<StatBoost>, EnumClassHash> statBoosts;
```
Because `CrewStat` is an `enum`.

### Math.h
Turns out there's fun bugs between C99, early C++11 and the final implementations in GCC6+
Because of this some macros in `math.h` that differ from `<cmath>` like `isnan` and `isinf` provide an issue.
Rather than dealing with this nonsense please use the boost equivalents.

```c++
#include "math.h"
// ...
if(isnan(something))
```
Becomes
```c++
#include <boost/math/special_functions/fpclassify.hpp>
// ...
if(boost::math::isnan(something))
```

### C++11 Narrowing
In GCC C++11 Narrowing is only a warning; however, it is a error in the C++11 spec.
This is an error to LLVM-Clang following the proper C++11 spec but GCC has it as a warning by default.
Because of this It has been enabled as an error to the GCC builds (including Windows) by adding `-Werror=narrowing`.
Please make sure to obey it.

Here's an example of code that throws a narrowing error:
```c++
Pointf ppos = {lastTargetLocation.x + r*cos(theta), lastTargetLocation.y + r*sin(theta)};
```
LLVM-Clang will throw the error: `error: non-constant-expression cannot be narrowed from type 'double' to 'float' in initializer list [-Wc++11-narrowing]` in this case.
And it's pretty straightforward, C++ is yelling at you letting you know you might be dropping bits here which could be a precision/narrowing issue.
If you 100% intend this, you just have to be explicit in your code and cast it with a static cast
```c++
Pointf ppos = {static_cast<float>(lastTargetLocation.x + r*cos(theta)), static_cast<float>(lastTargetLocation.y + r*sin(theta))};
```

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
   
### Documentation generation

Install & use doxygen
