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

#### My game crashes before loading Multiverse
- ***Nvidia*** GPUs ***must not*** use `-opengl` or they will crash.
- ***AMD & Intel*** GPUs need to start FTL with the `-opengl` option.
   - If creating the shortcut you just create a shortcut to the game and add `-opengl` after the last `"`
      - ![image](https://user-images.githubusercontent.com/1423894/173691599-b8fa5b9a-0663-437b-99a4-48216602700c.png)
   - If using steam you can use the launch options
      - ![image](https://user-images.githubusercontent.com/1423894/173692491-3e2a597a-29b3-44a0-9e3b-c8843708054e.png)


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
