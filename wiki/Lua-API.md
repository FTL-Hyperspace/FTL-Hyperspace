#### Hooking events
See [Scripts module & Event Control](Lua-Script-Module)

#### Loading your lua script
See [Lua Scripts from Hyperspace.xml](Hyperspace.xml#lua-scripts)

#### Hyperspace API
See [Hyperspace module](Lua-Hyperspace-Module)

## Editor extension for IntelliSense
You can install an additional IntelliSense addon for [Lua Language Server](https://luals.github.io) that adds definitions for the HS Lua API (classes, functions, etc.) to your editor.

### For VS Code
Lua Language Server supports the Addon Manager to install addons easily.

1. Install [VSCode extension for Lua](https://marketplace.visualstudio.com/items/?itemName=sumneko.lua) in your VSCode.
2. Press Ctrl + P to open the command palette, then enter `>lua: open Addon Manager` to open the Addon Manager.
3. In the Addon Manager, search for `FTL: Hyperspace` and enable it.

### For other editors
1. Install [Lua Language Server](https://luals.github.io). Please refer to [the installation guide](https://luals.github.io/#install)
2. Follow [this guide](https://luals.github.io/wiki/addons/#installing-addons) to install the HS addon for the Lua Language Server. The HS addon repository can be found [here](https://github.com/ranhai613/ftl-hs-lua-lls-addon/tree/publish).

TODO: Talk about Hyperspace basics

TODO: We need to define a custom sidebar so we can represent the lua module stuff in a hierarchy instead of a flat list of modules.
