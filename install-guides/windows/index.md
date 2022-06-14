---
layout: default
title: "Windows Hyperspace Install Instructions"
permalink: /install-guides/windows/
---

## Updating

Simply replace `Hyperspace.dll` (and any other DLLs included in the hyperspace ZIP) with the new one in your FTL installation directory.
Updating the `Hyperspace.dll` is **crucial** for Multiverse updates as they always build for the latest hyperspace.

Patch the new `Hyperspace.ftl` with slipstream if you are using a mod that requires it (*do not patch `Hyperspace.ftl` for Multiverse*)

## First time Installs

### What FTL installation do you have?

- [Steam](./steam-install)
- GoG
- Humble Bundle
- Epic Games
- Origin
- Microsoft Store/Xbox Game Pass

## Troubleshooting

#### My game crashes before loading Multiverse
- ***AMD & Intel*** GPUs need to start FTL with the `-opengl` option.
- ***Nvidia*** GPUs ***must not*** use `-opengl` or they will crash.

#### My game hangs on loading the last `E` in multiverse
- [You have a corrupt save file](#resolving-a-corrupt-save-file)
#### My game hangs on loading but doesn't crash and I hear music
- [You have a corrupt save file](#resolving-a-corrupt-save-file)

#### Resolving a corrupt save file
To potentially fix a corrupted save:
1. Go to `Documents/My Games/FasterThanLight`, you should have a `hs_mv_prof.sav` and `hs_mv_version.sav`
2. Delete the `hs_mv_version.sav`
3. Move the `hs_mv_prof.sav` to another folder (**do not delete it**)
4. Run the game and once it loads to the main menu close it again
5. Move your original `hs_mv_prof.sav` back where it was before, replacing the one that was created by the game
