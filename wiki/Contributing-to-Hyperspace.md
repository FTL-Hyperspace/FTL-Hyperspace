# Opening a Pull Request

In GitHub, you can submit a request for the developers of a project to integrate your changes using something called a "pull request" (PR for short). In order to make one, if you don't have write access to the repository in question, you first have to create a fork.

[[/img/contribute-tut/create-fork.png]]

Once you have the fork, you'll need to clone it. The process for cloning will be different depending on whether you're using a command-line interface or an app with a graphical interface. There are a bunch of git apps out there, and if the process for cloning in the one you're using isn't obvious, it probably isn't a great app and you should use a different one. If you're using CLI, you'll need to use the following command:

```
git clone https://github.com/<your github account name here>/FTL-Hyperspace.git
```

The cloned repo will appear as a folder called FTL-Hyperspace in whichever directory you were in when you cloned. I recommend using VSCode as your IDE for Hyperspace development. Once you've made your changes, you can commit and push them with the following commands:

```
git commit -m "description of changes here"
git push
```

Once you've made the changes you want to submit and you're ready to open a PR, go to your fork in the browser, click the "Pull requests" tab and open a new pull request.

[[/img/contribute-tut/open-pr-tab.png]]

It should automatically pick the correct branch (`master`) on the main repo to open the PR to.

[[/img/contribute-tut/open-pr-branch.png]]

Be sure to write a description which explains the changes you made.

# Adding to the Wiki

All the files which make up the wiki are held in `FTL-Hyperspace/wiki`. Right now the LUA documentation is severely lacking, specifically the `Hyperspace` module page (`Lua-Hyperspace-Module.md`), which should have detail you can access through the `Hyperspace` module. The `Defines` and `Graphics` module pages (`Lua-Defines-module.md` and `Lua-Graphics-Module.md`, respectively) are also missing a number of events which can be hooked with callback functions. This section explains how to read the source code files relevant to these pages so you that they can be expanded.

## LUA Hyperspace Module

The [`hyperspace.i`](../blob/master/lua/modules/hyperspace.i) source file contains everything that is exposed to the `Hyperspace` module. For example, here's the section which exposes `ShipManager`:

```c
%rename("%s") ShipManager;
%nodefaultctor ShipManager;
%nodefaultdtor ShipManager;
```

If you want to document a class like `ShipManager`, first find where it's exposed in `hyperspace.i`. Next, you'll need to add all its exposed members and methods. Suppose you wanted to expose its `bDestroyed` member and its `DamageArea` method:

```c
%rename("%s") ShipManager::bDestroyed;
...
%rename("%s") ShipManager::DamageArea;
```

In order to get more information, we need to find these in the [`FTLGameWin32.h`](../blob/master/FTLGameWin32.h) file. First, find where `ShipManager` is defined.

```c
struct ShipManager : ShipObject
...
```

Now, find where the member and method in question are defined.

```c
LIBZHL_API bool DamageArea(Pointf location, Damage dmg, bool forceHit);
...
bool bDestroyed;
```

Now that we know what type `bDestroyed` has, as well as which type `DamageArea` returns as well as all the arguments it takes, we can document them in the .md markdown file.


