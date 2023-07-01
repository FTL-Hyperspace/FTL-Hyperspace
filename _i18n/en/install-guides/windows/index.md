## Updating

Simply replace `Hyperspace.dll` (and any other DLLs included in the hyperspace ZIP) with the new one in your FTL installation directory.
Updating the `Hyperspace.dll` is **crucial** for Multiverse updates as they always build for the latest hyperspace.

Patch the new `Hyperspace.ftl` with slipstream if you are using a mod that requires it (*do not patch `Hyperspace.ftl` for Multiverse*)

## First time Installs

Hyperspace only works with FTL 1.6.9, the following will guide you on both installation & downgrading for your install of FTL depending on where you bought FTL from:

### What FTL installation do you have?

- [Steam](./steam-install)
- [GoG](./gog-install)
- [Humble Bundle](./humble-install)
- [Epic Games](./other-install#epic)
- [Origin](./other-install#origin)
- [Microsoft Store/Xbox Game Pass](./other-install#microsoft-storexbox-game-pass)

## Troubleshooting

#### My game complains about `-opengl`
- Stop using `-opengl` flag, it was removed in Hyperspace 1.5.0 and is no longer needed

#### My game crashes before loading Multiverse
- ***Ensure you're on the latest version of Hyperspace, the Multiverse installer is frequently not up to date!***
- This problem should be pretty much eliminated unless your save file is corrupt but there are some instances where this can still occur on ***laptops only***
- If you're not using a laptop, **your save file is corrupt** and that's why it's not launching, see below.
- If your laptop does not have dedicated graphics (i.e. AMD or Nvidia GPU, not the one built into the CPU) then **your save file is corrupt** and that's the problem.
- If your laptop **DOES** actually have a dedicated GPU, you may need to force FTL to run on either the dedicated or internal GPU, one of them might be causing you a problem.

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
