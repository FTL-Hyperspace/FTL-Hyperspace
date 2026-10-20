# Hyperspace on Android (FTL for iPad)

Hyperspace built as `libHyperspace.so` for [ftl-android](https://github.com/Sidd065/ftl-android),
which runs the arm64 binary of FTL for iPad (1.6.21) on Android with its own Mach-O loader.
The app loads this library after mapping the game, before any game code runs, and calls
`hs_android_init` (`src/android/HyperspaceHost.h`) with where the game is. It does so
while `Hyperspace.ftl` is among the mods applied in the app.

## What's here

- `libzhlgen/test/functions/ios_arm64/1.6.21/`: the definitions, converted from the Mac
  1.6.13 ones. Instead of byte patterns, every signature is `"@<address>"`, the function's
  address in the iPad binary: there is only one build, and SigScan checks its LC_UUID
  before using any address. `"@0"` marks a function whose iPad address isn't known yet,
  or that the iPad build doesn't have; the comment says which, after the Mac address.
- `libzhlgen/test/functions/ios_arm64/FTLGameStripped.h`: class layouts, the Mac ones with
  the differences listed under "Layouts".
- `src/zhl/Arm64Detour.*`: hooking for arm64. A 4-byte branch at the function entry goes
  to a veneer placed next to the game (within the +-128MB a branch reaches); the displaced
  instruction is relocated (B/BL, B.cond, CBZ/TBZ, ADR/ADRP, LDR literal).
- `src/android/`: the entry point the app calls, a reader for the game's Mach-O header,
  `InlinedFunctions.cpp` (see "Game functions the iPad build doesn't have"),
  `IpadSignatures.cpp` (hooks whose iPad function takes different arguments) and
  `TouchToLua.cpp` (touches as mouse events for Lua scripts).
- `HS_ANDROID` and `HS_APPLE_GAME` (`src/helpers/PALPlatform.h`). Android also defines
  `__linux__`, so checks that are about the game build rather than the system use
  `HS_APPLE_GAME`: the iPad binary is a clang and libc++ build like the Mac one.

## Building (Linux)

Needs the Android NDK r28, cmake, ninja, swig, Lua with lpeg and lfs, and the app's
libc++: `libcxx/build.sh android` in ftl-android builds LLVM 19's libc++ with Apple's arm64
ABI settings into `libcxx/out/android`, which is `FTL_LIBCXX` below.

    buildscripts/android/setup.sh     # once: vcpkg, plus the Android toolchain and triplet
    ANDROID_NDK_HOME=/path/to/android-ndk-r28 FTL_LIBCXX=/path/to/libcxx/out/android \
        buildscripts/android/build.sh Release

The result is `build-android-release/libHyperspace.so`. ftl-android puts it in the app
with `HYPERSPACE_SO=<that file> android/build-apk.sh`.

`detour-test/` checks the instruction relocation the hooks rely on. Build it as a static
binary and run it on any arm64 Linux or Android device, or under `qemu-aarch64`:

    $ANDROID_NDK_HOME/toolchains/llvm/prebuilt/linux-x86_64/bin/clang++ --target=aarch64-linux-android26 \
        -static -O1 -Isrc -Isrc/zhl buildscripts/android/detour-test/test.cpp src/zhl/Arm64Detour.cpp -o detour-test
    qemu-aarch64 ./detour-test

## Keeping it up to date

- A game function added to the definitions needs an entry in `ios_arm64/1.6.21` as well,
  or code that calls it doesn't compile for Android. A hook on a function the iPad
  definitions don't list, or list as `"@0"`, is left out on Android (zhl.log names it);
  calling an `"@0"` function stops the game with its name in the log.
- To find an iPad address: look the function up in the Mac build, which has symbols, then
  find the same code in the iPad binary through what it calls, who calls it, the strings
  and constants it uses or its vtable slot. Both builds keep most functions of a class in
  the same order, so the neighbouring entries narrow it down.
- Field changes in `mac/FTLGameStripped.h` go into `ios_arm64/FTLGameStripped.h` too.
- `libzhlgen/check_hook_signatures.py` checks hooks against the iPad definitions as well,
  for hooks that Android builds compile (outside `#ifndef HS_ANDROID`, and everything in
  `src/android/`). A signature mismatch there stops Hyperspace from starting.
- A game function that takes a new type by value needs that type in `appleArgs` in
  `libzhlgen/lua/parsefuncs.lua` (the generator stops with an error naming it).
- The iPad game never calls the mouse and keyboard handlers (`MouseMove`, `MouseClick`,
  `OnLButtonDown` and so on). New UI that relies on them needs a touch path through the
  iPad's `OnTouch` functions to work on Android; `CustomShipSelect.cpp` and
  `CustomStore.cpp` have examples. Screen positions for the iPad layout sit next to the PC
  ones in `#ifdef HS_ANDROID` blocks.

## Logs

zhl.log and FTL_HS.log go to the app's log folder, so "Save logs" in the app's settings
includes them. The working directory is the game's save folder, where `settings_hs.ini`
ends up. When the game stops on an `"@0"` function, the log lists the callers: game
addresses are iPad addresses, Hyperspace ones offsets into libHyperspace.so, for
`llvm-symbolizer --obj=libHyperspace.so -f -C <offset>`.

## x86 devices and emulators

x86 devices and emulators run the arm64 app through a translator (a native bridge), and
libndk_translation can't run FCVTZS/FCVTZU with a SIMD register result, which clang emits
for float to int to float conversions. When a native bridge is in use, `hs_android_init`
rewrites those instructions in Hyperspace's own `.text` into branches to equivalent code
(`Arm64Detour::ReplaceUntranslatable`). ARM devices skip this.

## Where Android meets the game's Apple ABI

The game was built for Apple's arm64 ABI, Hyperspace with the NDK. Where they meet:

- C++ library: Hyperspace is compiled against the app's libc++ headers (alternate string
  layout, Apple RTTI comparison and ctype tables), so `std::string`, `std::vector` and
  `std::map` match the game's. It links its own static copy, kept private. Both copies
  allocate with bionic's malloc, as do the game's `operator new` and `malloc`, so memory
  can be freed on either side.
- `char` is signed on Apple: `-fsigned-char`, for the dependencies too.
- Constructors and destructors return `this` on Apple arm64, and game code uses that
  return value. Hooks on them are installed with `Arm64Detour::KeepThis`, whose veneer
  gives the caller its x0 back. Hyperspace's own classes are built with `-fc++-abi=arm`
  (this-returning constructors, ARM array cookies), like the app's libc++.
- Apple callers extend arguments narrower than 32 bits and Apple code relies on it; the
  call glue passes them as 32-bit ints. Apple callers also expect bool, char and short
  return values extended, which NDK-built hooks don't guarantee (clang returns bools as 0
  or 1 in practice).
- Apple packs stack arguments at their natural alignment. Four definitions take arguments
  on the stack in a way that differs (`CSurface::GL_BlitImagePartial`, used by Hyperspace,
  and three it doesn't use). The generator lays out the stack the Apple way when calling
  them and gives them adapters for hooks (`AppleStackAdapter`).
- No game function in the definitions is variadic, so Apple's variadic convention never
  crosses the boundary.
- x18 is reserved on Apple platforms and also by the NDK's compiler, so neither side uses
  it.

## Game functions the iPad build doesn't have

Clang inlined some small functions everywhere in the iPad build, so there is nothing to
call or hook. Where Hyperspace calls one, it has its own version, written from what the
Mac build's copy does: short ones in the struct blocks of the iPad .zhl files, longer ones
in `src/android/InlinedFunctions.cpp`. Their declarations in the .zhl files are commented
out.

Some functions differ from the PC ones. `CSurface::GL_BlitPixelImage` and
`_CreateImagePrimitive` take one more argument: when it's set, the image is drawn as part
of the background, 176 further left (the iPad's backgrounds are wider than its HUD).
`CSurface::GL_BlitMultiImage` isn't in the iPad build at all; the "show all beacon
connections" option draws the same thing with `GL_BlitMultiColorImage` instead.

## Layouts

These classes differ from the Mac layout, and `FTLGameStripped.h` has the iPad's:
ShipSystem (0xa0 more bytes after `iconPrimitives`, so every system class moves),
MainMenu (no Into the Breach button), ScoreKeeper, ShipStatus, CrewControl, SystemControl,
CombatControl, FTLButton, OptionsScreen, CommandGui, Upgrades, CrewManifest, Equipment,
Store, StarMap, WorldManager and CloneBox. Hyperspace keeps its own data in padding bytes
(`gap_ex_*`), which the iPad code doesn't use either.

## Known gaps

- Hooks on mouse handlers never fire on Android, and keyboard handlers only with a hardware
  keyboard. The features that need input have touch versions; others (the scroll wheel,
  dragging crew boxes) don't. Hyperspace's own hotkeys have no keys on Android, except the
  command console (backslash). Lua scripts get clicks from touches and right clicks from
  the app (one finger held, a tap with another), but ON_KEY_* only from a hardware
  keyboard, so mod hotkeys do nothing on a phone alone.
- `ShipManager::GetOxygenLevels`, `ForceIncreaseSystemPower` and `AddEquipmentFromList`
  aren't in the iPad build, so features built on hooking them don't work.
- InfoBox detail bar colours are built inline on the iPad, so mods that recolour them keep
  the game's colours.
- Some iPad functions take different arguments from the PC ones Hyperspace's hooks expect;
  `src/android/IpadSignatures.cpp` hands those hooks what the PC would.

The touch versions of the temporal box, the system boxes for Hyperspace's systems, the
larger drawing of selected crew and FTL_JUMPER_GOOD follow The Dumb Dino's
[touch screen work](https://github.com/The-Dumb-Dino/FTL-Hyperspace-Dino/tree/touchScreen-Support).
