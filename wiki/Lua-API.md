#### Hooking events
See [Scripts module & Event Control](Lua-Script-Module)

#### Loading your lua script
See [Lua Scripts from Hyperspace.xml](Hyperspace.xml#lua-scripts)

#### Hyperspace API
See [Hyperspace module](Lua-Hyperspace-Module)

## Editor extension for intellisense
You can install an additional intellisense (addon) for [Lua Language Server](https://luals.github.io) that adds all definitions for HS lua API (classes, functions and so on) to your editor.

### For VSCode
Lua Language Server supports Addon Manager to install addons easily.

1. Install [VSCode extension for Lua](https://marketplace.visualstudio.com/items/?itemName=sumneko.lua) in your VSCode.
2. Ctrl + P to open command pallet, then enter `>lua: open addon manager` to open addon manager.
3. In addon manager, search for `FTL: Hyperspace` then enable it.

### For other editors
1. Install [Lua Language Server](https://luals.github.io). Please refer to [the installation guide](https://luals.github.io/#install)
2. Follow [this guide](https://luals.github.io/wiki/addons/#installing-addons) to install HS addon to Lua Language Server. HS addon repository can be found [here](https://github.com/ranhai613/ftl-hs-lua-lls-addon/tree/publish).

TODO: Talk about Hyperspace basics

TODO: We need to define a custom sidebar so we can represent the lua module stuff in a hierarchy instead of a flat list of modules.
