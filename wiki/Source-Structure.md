# Source Structure

## `src/`

| Folder | What goes there |
|---|---|
| `src/game/` | Code that extends or fixes FTL itself, sorted into FTL's own source folders: `Gameplay/`, `Gameplay/AI/`, `Gameplay/World/`, `Ship/`, `Ship/ShipSystems/`, `UserInterface/`, `Utilities/`, `Debug/`. A file goes in the folder of the FTL class it works on; look the class up in [FTL Source Layout](FTL-Source-Layout). |
| `src/features/` | New features that don't exist in FTL, one folder each (`crash-detection/`, `discord/`, `freeze-watchdog/`, ...). They hook FTL functions like the rest of the code but are self-contained. |
| `src/overrides/` | Hooks that replace an FTL function's result, such as the save and user folder paths in `FileHelper`. |
| `src/zhl/` | ZHL, the hooking engine: installs `HOOK_*` functions and finds game functions by signature. |
| `src/helpers/` | Cross-platform helpers, such as `PALMemoryProtection.h`. |
| `src/` | `Global` (the `G_` state), `main` (entry points per OS), `FTLGame.h` (game class definitions for the current platform), `HSVersion.h`. |

Every `.cpp` under `src/` is compiled automatically, so a new file needs no CMake change. Sources placed in the repository root stop the build.

## Includes

Include headers by name or by path from `src/`, never with `../`:

```cpp
#include "Global.h"                               // src/
#include "CustomCrew.h"                           // any src/game folder, by name
#include "features/discord/DiscordIntegration.h"  // from src/
#include "helpers/PALMemoryProtection.h"          // from src/
```

Every `src/game` folder is an include root, so its headers are included by name wherever they live. Header names under `src/game` must be unique; the build fails on a duplicate.

## Outside `src/`

| Folder | What it is |
|---|---|
| `lua/` | Lua scripting: the runtime, the hooks that fire Lua events, and the SWIG modules in `lua/modules/` |
| `libzhlgen/` | Game function definitions (`test/functions/<platform>/*.zhl`) and the generator that turns them into `generated/FTLGame<Platform>.cpp/.h` |
| `generated/` | Build output: hook definitions and the version header. Not tracked by git; every build regenerates it |
| `third_party/` | Vendored libraries: `detours/` (with `hde32/`, `hde64/`) and `rapidxml/` |
| `tests/` | Automated tests, built into debug builds |
| `buildscripts/` | Build scripts per platform, CI helpers in `ci/`, tools in `tools/` |
| `Mod Files/` | The `Hyperspace.ftl` mod data |
| `Release Files/` | Per-platform files packed into release zips |
