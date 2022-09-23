- I need to [Update Hyperspace](#updating)
- I need to [Install Hyperspace](#installation)
- I need to [Troubleshoot problems](#troubleshooting)

# Updating

Simply replace `Hyperspace.1.6.13.amd64.so` (For Steam) or `Hyperspace.1.6.12.amd64.so` (for GoG/Humble) with the new version from the hyperspace zip.
Updating the Hyperspace SO file is **crucial** for Multiverse updates as they always build for the latest hyperspace.

Patch the new `Hyperspace.ftl` with slipstream if you are using a mod that requires it (*do not patch `Hyperspace.ftl` for Multiverse*)

# Installation

<div class="selector-grid">
    <a class="item" href="steamdeck/select-game-copy">
        <img class="sub-item selector-grid-image" src="{{ '/assets/img/Steam_Deck_colored_logo.svg' | relative_url }}" alt="Steam Deck" />
        <div class="sub-item selector-item-text">Steam Deck Instructions</div>
    </a>
    <a class="item" href="genericlinux/select-game-copy">
        <img class="sub-item selector-grid-image" src="{{ '/assets/img/Tux.svg' | relative_url }}" alt="Generic Linux" />
        <div class="sub-item selector-item-text">Linux Desktop Instructions</div>
    </a>
</div>

# Troubleshooting

#### My game hangs on loading the last `E` in multiverse
- [You have a corrupt save file](#resolving-a-corrupt-save-file)

#### My game hangs on loading but doesn't crash and I hear music
- [You have a corrupt save file](#resolving-a-corrupt-save-file)

#### Resolving a corrupt save file
To potentially fix a corrupted save:
1. Go to `~/.local/share/FasterThanLight/`, you should have a `hs_mv_prof.sav` and `hs_mv_version.sav`
2. Delete the `hs_mv_version.sav`
3. Move the `hs_mv_prof.sav` to another folder (**do not delete it**)
4. Run the game and once it loads to the main menu close it again
5. Move your original `hs_mv_prof.sav` back where it was before, replacing the one that was created by the game
6. If this still doesn't work, delete the entire `~/.local/share/FasterThanLight/` folder
