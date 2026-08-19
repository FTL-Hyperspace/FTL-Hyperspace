# Hyperspace.xml

## Other
TODO: Document other parts of Hyperspace.xml as different sections here.

## Overhaul detection

On startup Hyperspace warns the player when an overhaul mod's files are present in `ftl.dat` but the Hyperspace base mod's own `hyperspace.xml` is the active config. This means `hyperspace.ftl` was patched *after* the overhaul, overwriting some of its files, and the player should re-patch with the overhaul last.

Two signals are used for this:

### `<isBasemod>`

The base mod's `hyperspace.xml` declares `<isBasemod>true</isBasemod>`. Mods that ship their own full `hyperspace.xml` (overhauls like Multiverse) must set `<isBasemod>false</isBasemod>`, or simply leave the tag out since it defaults to false. When the overhaul is patched last (the correct order), its `hyperspace.xml` replaces the base mod's and the tag disappears, so no warning is shown.

### `data/is_overhaul_mod.xml`

If your mod is an overhaul (ships its own full `hyperspace.xml`), also include a file named `data/is_overhaul_mod.xml` (its contents don't matter, it can be empty). Its presence in `ftl.dat` tells Hyperspace that an overhaul was patched in, without your mod needing to be hardcoded in Hyperspace's fingerprint list. If it is present while the base mod's `hyperspace.xml` is still the active one, the patch-order warning is shown.

## Lua Scripts
### To load your script

You must declare your script in hyperspace.xml or it will never be loaded.

For now because `require` is not yet implemented you can only load files from hyperspace.xml and not from inside lua files.

You may declare more than one script in hyperspace.xml, they will be loaded in-order of declaration.

```xml
<scripts>
    <script>myLibraryName.lua</script>
    <script>myOtherScriptName.lua</script>
</scripts>
```

Only **one** `<scripts>` is permitted, multiple scripts tags will result in undefined behavior and/or an error loading Hyperspace.

### Additional mods

You should declare your scripts as appending on to (or prepending if slipstream supports it) the `<scripts>` tag and add additional `<script>` tags to load your scripts. Execution order is the order they appear in the final XML so it will match the patching order in Slipstream if appended.

### When is my script loaded

Scripts are loaded during hyperspace.xml parsing, so during the loading screen of the game, however this is subject to change (but unlikely).

You should not rely on **any** game functionality to be available at the time of script loading and should instead rely on the script hooks like `on_load` and `on_init` for any variable setup or game setup you must perform. Other functions should rely on event callbacks to perform script actions upon in-game actions.