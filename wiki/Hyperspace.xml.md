# Hyperspace.xml

## Other
TODO: Document other parts of Hyperspace.xml as different sections here.

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