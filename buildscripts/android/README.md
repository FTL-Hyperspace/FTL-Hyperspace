# Hyperspace for FTL on Android (work in progress)

Hyperspace built as `libHyperspace.so` for the Android port of FTL for iPad
([ftl-android](https://github.com/Sidd065/ftl-android)). The port runs the iPad game's
arm64 binary (1.6.21) with its own Mach-O loader. With its Hyperspace setting on, it
loads this library after mapping the game and before any game code runs, and calls
`hs_android_init` (`src/android/HyperspaceHost.h`) with where the game is.

## What's here

- `libzhlgen/test/functions/ios_arm64/1.6.21/`: the definitions, converted from the Mac
  1.6.13 ones. Instead of byte patterns, every signature is `"@<address>"`, the
  function's address in the iPad binary (there is only one build; SigScan checks its
  LC_UUID before using any address). `"@0"` marks something not found yet or not present
  on the iPad; the comment says which. About 3,190 functions have an address and 650
  don't (most of those aren't used by Hyperspace). Variables: 41 of 45.
- `libzhlgen/test/functions/ios_arm64/FTLGameStripped.h`: class layouts, the Mac ones plus
  the fixes listed under "Layouts".
- `src/zhl/Arm64Detour.*`: hooking for arm64. A 4-byte branch at the function entry to a
  veneer placed next to the game (within the +-128MB a branch reaches), with the
  displaced instruction relocated (B/BL, B.cond, CBZ/TBZ, ADR/ADRP, LDR literal). Code is
  written with `mprotect`, keeping executable pages executable.
- `src/android/`: the entry point the port calls, a small reader for the game's Mach-O
  header (UUID, sections, segment protections), `InlinedFunctions.cpp` (see "Game
  functions the iPad build doesn't have"), `IpadSignatures.cpp` (hooks whose iPad function
  takes different arguments) and `TouchToLua.cpp` (touches as mouse events for Lua).
- `HS_ANDROID` and `HS_APPLE_GAME` (`src/helpers/PALPlatform.h`). Android also defines
  `__linux__`, so checks that are about the game build rather than the system use
  `HS_APPLE_GAME`: the iPad binary is a clang/libc++ build like the Mac one.

## Building (Linux)

Needs the Android NDK r28, cmake, ninja, swig, lua with lpeg and lfs, and the port's
libc++ (`libcxx/build.sh android` in ftl-android, which builds LLVM 19's libc++ with
Apple's arm64 ABI settings).

    buildscripts/android/setup.sh     # once: vcpkg, plus the Android toolchain and triplet
    ANDROID_NDK_HOME=/path/to/android-ndk-r28 FTL_LIBCXX=/path/to/port-libcxx \
        buildscripts/android/build.sh Release

`FTL_LIBCXX` is `libcxx/out/android` in ftl-android, after `libcxx/build.sh android` there.

The result is `build-android-release/libHyperspace.so`. To put it in the app, build the
APK with `HYPERSPACE_SO=<that file> android/build-apk.sh` in ftl-android. The app then
shows a "Hyperspace (experimental)" switch in Settings (off by default), and its Mods
screen accepts mods made for Hyperspace, starting with Hyperspace.ftl itself.

`detour-test/` tests the hooking code (build it with the NDK's clang as a static binary
and run it under `qemu-aarch64`, or on any arm64 Linux or Android device).

## Keeping it up to date

- A game function added to the definitions needs an entry in `ios_arm64/1.6.21` as
  well. Code that calls it doesn't compile for Android without one. A hook on a function
  the iPad definitions don't list is left out on Android (zhl.log names it), and so is a
  hook on one marked `"@0"`, which is how to add a function whose iPad address isn't
  known. Calling an `"@0"` function stops the game with its name.
- Field changes in `mac/FTLGameStripped.h` go into `ios_arm64/FTLGameStripped.h` too. The
  two only differ where "Layouts" below says.
- The iPad game never calls the mouse and keyboard handlers (`MouseMove`, `MouseClick`,
  `OnLButtonDown` and so on). New UI that relies on them needs a touch path through the
  iPad's `OnTouch` functions to work on Android; `CustomShipSelect.cpp` and
  `CustomStore.cpp` have examples. Screen positions for the iPad layout sit next to the
  PC ones in `#ifdef HS_ANDROID` blocks, and the PC values are unchanged.
- The addresses were found by matching functions between the Mac build, which has
  symbols, and the iPad one. Each entry's comment gives the Mac address and what the match
  rests on (calls, strings, vtables, order, or by hand).

## Logs and debugging

zhl.log and FTL_HS.log go to the app's log folder, next to the session logs, so "Save
logs" in the app's settings includes them. The working directory is the game's save
folder, where `settings_hs.ini` ends up.

A `hyperspace-debug.txt` in the log folder limits what starts, to find out which hook
breaks something:

    hook CApp::OnRender     install only hooks on the functions named (repeatable;
    hook ShipManager::*     a trailing * matches every name that starts with the rest);
    hook Global__NOP__*     the no-op patches go by their names and are filtered the same way
    skip ShipBuilder::Open  leave out hooks on the functions named (same matching), to
                            find which hook causes something
    no-init                 skip Hyperspace's own start-up (Lua, its data files)
    missing-continue        a game function the definitions don't have yet logs and
                            returns 0 instead of stopping the game

Without missing-continue, calling such a function stops the game with its name and the
callers in the log. Game addresses in those lists are iPad addresses; Hyperspace ones are
offsets into libHyperspace.so, for `llvm-symbolizer --obj=libHyperspace.so -f -C <offset>`.

## Testing on redroid

redroid on an x86 machine runs the arm64 app through libndk_translation, which can't run
FCVTZS/FCVTZU with a SIMD register result (clang emits it for float to int to float, about
a dozen times in Hyperspace). When the native bridge property says a translator is in use,
`hs_android_init` rewrites those instructions in Hyperspace's own `.text` into branches to
equivalent code that goes through x16 (`Arm64Detour::ReplaceUntranslatable`), and logs how
many. Real ARM devices skip this. Under the translator, /proc/self/maps doesn't show ARM
code as executable, so that code is rewritten with explicit read+execute protection.

## Where Android meets the game's Apple ABI

The game was built for Apple's arm64 ABI, Hyperspace with the NDK. Where they meet:

- C++ library: compiled against the port's libc++ headers (alternate string layout,
  Apple RTTI comparison and ctype tables), so `std::string`, `std::vector` and `std::map`
  match the game's. Hyperspace links its own static copy, kept private. Both copies
  allocate with bionic's malloc, as do the game's `operator new` and `malloc` (the port
  binds them that way), so memory can be freed on either side.
- `char` is signed on Apple: `-fsigned-char`, for the dependencies too.
- Constructors and destructors return `this` on Apple arm64, and game code uses that
  return value (for example a derived class constructor storing its vtable through the
  x0 its base constructor returned). Hooks on them are installed with
  `Arm64Detour::KeepThis`, whose veneer gives the caller its x0 back. Hyperspace's own
  classes are built with `-fc++-abi=arm` (this-returning constructors, ARM array cookies),
  as the port's libc++ is.
- Apple callers extend arguments narrower than 32 bits and Apple code relies on it; the
  call glue passes them as 32-bit ints.
- Apple packs stack arguments at their natural alignment. Four definitions take
  arguments on the stack in a way that differs (`CSurface::GL_BlitImagePartial`, used by
  Hyperspace, and three it doesn't use). The generator lays out the stack the Apple way
  when calling them and gives them adapters for hooks (`AppleStackAdapter`).
- Variadic functions: Apple passes variadic arguments on the stack. No game function in
  the definitions is variadic, so nothing calls one across the boundary.
- x18 is reserved on Apple platforms and also by the NDK's compiler for Android, so
  neither side uses it.

## Game functions the iPad build doesn't have

Clang inlined some small functions everywhere in the iPad build, so there is nothing to
call or hook. Where Hyperspace calls one, it has its own version written from what the
Mac build's copy does, against Hyperspace's structs (which have the iPad layout): short
ones in the struct blocks of the iPad .zhl files (`Ship::GetSelectedRoomId(Point, bool)`,
`Room::GetEmptySlots`, `CrewMember::SetResisted`/`MasterSkill`,
`HackingSystem::BlowHackingDrone`, `WarningMessage::SetSound`, `StarMap::ReverseBossPath`,
`ShipBuilder::ClearShipAchievements`, the FileHelper file functions), longer ones in
`src/android/InlinedFunctions.cpp` (`ShipManager::GetWeaponList`/`GetDroneList`,
`ShipManager::RemoveCrewmember(CrewMember*)`, `CrewMember::Sabotaging`,
`CombatControl::GetCrewTooltip`, `freetype::easy_printAutoShrink`). Their declarations in
the .zhl are commented out. An iOS build of these definitions would need that file as well.

Some functions differ from the PC ones. `CSurface::GL_BlitPixelImage` and
`_CreateImagePrimitive` take one more argument: when it's set, the image is drawn as part
of the background, 176 further left (the iPad's backgrounds are wider than its HUD).

`CSurface::GL_BlitMultiImage` isn't in the iPad build at all (the game never used it);
the "show all beacon connections" option draws the same thing with
`GL_BlitMultiColorImage` and white vertices instead.

## Layouts

Checked by pairing the `this` offsets of matched Mac/iPad methods, then against the iPad
constructors. All the differences found are fixed in `FTLGameStripped.h`: ShipSystem
(0xa0 extra bytes after `iconPrimitives`, so every system class moves), MainMenu (no Into
the Breach button), ScoreKeeper, ShipStatus, CrewControl, SystemControl, CombatControl,
FTLButton, OptionsScreen, CommandGui (0x5c28 bytes, as the iPad allocates), Upgrades,
CrewManifest, Equipment, Store, StarMap, WorldManager and CloneBox. About 1,300 field
offsets agree with the iPad code. Hyperspace keeps its own data in padding bytes
(`gap_ex_*`); all 29 of those are unused by the iPad code too.

## Where it stands

With Hyperspace.ftl installed through the app's Mods screen, a run goes from the main
menu through the hangar, START, events, the beacon map, jumps and fights to the game over
screen, on redroid and on a real phone (Android 16, arm64). A saved run made with
Hyperspace loads with CONTINUE.

FTL for iPad only takes touches, and its HUD is laid out differently from the PC one, so
Hyperspace's own UI is connected to the iPad's on Android:

- Title screen: Hyperspace's background and logo, its save transfer dialog by touch, the
  language screen with its added languages. Hyperspace's bug report button and crash
  question are left out: the port has its own crash notice and saves the logs,
  Hyperspace's included.
- Saves: each mod's run and profile in files of their own (hs_<mod>_continue.sav,
  hs_<mod>_prof.sav), as on PC, through SIL's userdata functions, which the iPad build
  saves and loads by file name.
- Hangar: Hyperspace's ship list pages (custom ships on the iPad's ship grid, selected by
  touch), the seed box (it opens the system keyboard), its system, equipment and crew
  boxes and the ship's missile, drone and crew counts at the iPad's places, augment pages
  and RANDOM SHIP with custom ships.
- Stats: the ship tab for custom ships; the pages of achievements that mods add follow
  the game's own in the achievements tab, with arrows in its corner.
- Combat HUD: system boxes for every system Hyperspace adds (temporal, custom systems,
  several artillery), placed and wired like the iPad's own; the temporal box opens on a
  tap like the teleporter's; crew list pages, every crew power (the buttons in the panel
  beside the selected crew member's box, and the iPad's own power button), the more info
  button, event buttons and hazard tooltips by touch; weapon cooldown numbers in the
  iPad's weapon boxes; enemy ship icons beside the iPad's enemy window, their tooltips
  while a finger is on them.
- Crew selection uses the iPad's own loop (Hyperspace's PC one only ran after mouse
  moves), and Hyperspace's health bars and power effects follow the iPad's larger drawing
  of selected crew. Move orders (a finger lifting off a room) go through `RButton` first,
  as a right click does on PC, so tile movement, crew who teleport instead of walking and
  the selectable/controllable split apply. With tile movement the iPad's power button
  sits beside the crew member's room rather than over it, and a tap in their own room
  moves them to that tile.
- Upgrades, equipment, crew manifest and stores (including custom stores): Hyperspace's
  pages and extra slots go through the iPad's own touch handling, BUY, SELL, UPGRADE and
  UNDO buttons and info boxes; the reactor uses the ship's own prices.
- Beacon map: FTL_JUMPER_GOOD by touch; long event choice lists scroll by dragging.
- Memory: mods' images (.png) load on first use instead of at start, as Hyperspace does on
  PC. Animation sheets too, which goes further than on PC: the game asks for every sheet
  while it reads animations.xml, so a sheet gets a stand-in of its size there, and the
  image loads when something first draws with it (`texture_apply`). With Multiverse that
  is 560 MB of GPU memory at the main menu instead of 3.1 GB (about 1 GB with the game's
  own memory), and reading animations.xml takes about a second instead of 15 to 45
  seconds. The iPad's own art (atlases) still loads at start.
- Lua: when a script listens for clicks, the first finger on the screen moves the cursor
  and raises ON_MOUSE_MOVE and ON_MOUSE_L_BUTTON_DOWN/UP, so buttons that mods draw from
  Lua work by touch (Multiverse's speed controls, for one). A touch a script takes doesn't
  reach the game, and neither does one on a button that a script hovered in that frame's
  ON_TICK (mods' buttons can sit on the game's on the iPad layout); the rest reach it a
  frame later.

### Mods tried

On the real phone, each set installed through the app's Mods screen in the order its
authors give, then played from the main menu through the hangar, START, events, the map,
jumps, a store and a fight. Multiverse alone was then played for several hours on redroid:
runs with three of its ships, every ship in the hangar, stores, upgrades, crew powers, the
temporal system, artillery, two sectors, a game over, the stats and its tutorial.

- Multiverse 5.5.1 (Assets 5.5 and Data 5.5.1)
- Multiverse with Fusion 0.1.5, The Renegade Collection 2.6 and Forgemaster 0.6.1.2.2
- Multiverse with Fusion, The Renegade Collection, Forgotten Races 17.0.47, The Outer
  Expansion 7.1.10, Darkest Desire 4.1.4, Trash Compactor Collection 1.3, Forgemaster,
  Fishier Than Light 1.2.3 and Lily's Innovations 1.8.5, all at once (through to the first
  event only)
- Arsenal+ 1.36, the English build from ftl-mv-translation (machine translated)
- Insurrection+ (7 Oct 2026 build) with its Augmented Weapons and Named Weapons modules

All of them loaded their scripts without Lua errors. What turned up:

- Multiverse draws its speed controls and addon icons from Lua where the PC puts them,
  which on the iPad layout is over the FTL button's label and the hull bar. They work by
  touch.
- Arsenal+'s main menu tips are in Russian; they come that way from the mod's
  hyperspace.xml.
- Darkest Desire's separate System Patcher file wasn't tried.

Where Hyperspace replaces a game function with the PC version of it, Android usually
keeps the iPad's own and adds Hyperspace's extras on top, since the PC version expects a
mouse or the PC layout.

Some of this follows The Dumb Dino's touch screen work on Hyperspace (the
`touchScreen-Support` branch of github.com/The-Dumb-Dino/FTL-Hyperspace-Dino): the
temporal box as a tap-to-open box with its buttons handled through the box's vtable, the
system boxes for Hyperspace's systems on a touch HUD, the larger drawing of selected crew
and FTL_JUMPER_GOOD by touch.

## Known gaps

- Hooks on mouse and keyboard handlers never fire on Android; the features above that
  need input have touch versions, others (hotkeys, scroll wheel, right clicks) don't.
  For Lua that means ON_MOUSE_R_BUTTON_* and ON_KEY_* never come: Fusion's augment boxes
  and Insurrection+'s enemy evasion display can't be dragged (right mouse button), and
  mod hotkeys do nothing.
- Definitions: `ArmamentControl::CreateHolderTab` and `Dragging`, `ShipBuilder::SwapType`
  and `UpgradeBox::MouseMove` have no iPad address but are only called from mouse handlers
  (or, for the holder tab, from PC layout code left out on Android). About 35 more are
  only reachable through Hyperspace's Lua API; none of the mods above call them (the ones
  they did call, like `CrewMember::AtGoal` and `sys_graphics_set_window_title`, have
  copies in `src/android/InlinedFunctions.cpp`). `ShipManager::GetOxygenLevels`,
  `ForceIncreaseSystemPower` and `AddEquipmentFromList` aren't in the iPad build, so
  features built on hooking them don't work.
- InfoBox detail bar colours are built inline on the iPad, so mods that recolour them
  (Multiverse does) keep the game's colours.
- Some iPad functions take different arguments from the PC ones Hyperspace's hooks
  expect; `src/android/IpadSignatures.cpp` hands those hooks what the PC would
  (`StarMap::GetLocationText`, which on the iPad always describes the touched beacon).
