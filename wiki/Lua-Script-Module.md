# module `script`
Functions for script execution control

## Functions

| Signature | Description |
| --------------------------------------------------------- | ----------------------------------------------------------------------- |
| [on\_load(callback)](#func-on_load)                  | Register a function to call upon loading your script                    |
| [on\_init(callback)](#func-on_init)                  | Register a function to call upon starting a run                         |
| [on\_internal\_event(InternalEvent, callback)](#func-on_internal_event) | Register a function to call upon a specific internal event being called, available internal events and additional data comes from the [`Defines.InternalEvents`](Lua-Defines-module#internal-events) table |
| [on\_render\_event(RenderEvent, beforeCallback, afterCallback)](#func-on_render_event) | Register functions to call before & after a specific render layer/rendering event, a list of possible events comes from  the [`Defines.RenderEvents`](Lua-Defines-module#render-events) table |
| [on\_game\_event(eventName, onLoadOnly, callback)](#func-on_game_event) | Register a function to call upon a named XML game event or choice being loaded. Game event names are the `name=` attribute of an `<event>` or `<choice>` in the XML |

<a name="func-on_load"></a>
### on\_load(callback)
Register a function to call upon loading your script

#### Parameters:

*   callback `function`
    * Callback function to register

Your function will be called once upon loading the game (not upon starting a new run use on\_init for that)

Functions will be called in the order they are registered, lua entry scripts are executed in the order they are defined in the hyperspace.xml, so if your mod was defined before another in Slipstream it'll load before the other mod.

**Warning:** you can accidentally register your function multiple times and it will be called multiple times!

Actually currently runs on `AcheivementTracker::LoadAchievementDescriptions` (right after most of Hyperspace initalizes XML stuff)

#### Usage:

  ```lua
  function myModInitializationCode()
    log("My code was run after the game started")
    if not _G["myModLoaded"] then
      _G["myModLoaded"] = true
    end
          if not _G["otherModLoaded"] then
      warningWindow("Warning! MyMod depends on OtherMod!")
    end
  end

  script.on_load(myModInitializationCode)
  ```

<a name="func-on_init"></a>
### on\_init(callback)
Register a function to call upon starting a run

#### Parameters:

*   callback `function`
    * Callback function to register *note this function can take an argument which specifies whether it was called for starting a new game or loading a saved game*

Your function will be called once upon starting a new run (and/or loading a run)

Functions will be called in the order they are registered, lua entry scripts are executed in the order they are defined in the hyperspace.xml, so if your mod was defined before another in Slipstream it'll load before the other mod.

**Warning:** you can accidentally register your function multiple times and it will be called multiple times!

#### Usage:

  ```lua
  function myModGameStartCode(newGame)
    if (newGame) then
      log("My code was run after a new game started")
    else
      log("My code was run after a saved game loaded")
    end
  end

  script.on_init(myModGameStartCode)
  ```

<a name="func-on_internal_event"></a>
### on\_internal\_event([`InternalEvents`](Lua-Defines-module#internal-events) event, callback)
Register a function to call upon a specific internal event being called

#### Parameters:

* event [`InternalEvents`](Lua-Defines-module#internal-events) Event identifier to hook, see `InternalEvents` table linked for a full list of currently supported events.
*   callback `function`
    * Callback function to register *note this may require specific __arguments__ to be handled and specific __return__ values depending on the specific InternalEvent that is used*

Your function will be called upon the specified event being triggered inside the game **These are internal events** not events as described in XML files, so these are events like functions internal to the game (like ship loading) and not events as in popups or encounters in the game. You can think of these as game engine events. See [on\_game\_event](#func-on_game_event) for hooking gameplay events.

Functions will be called in the order they are registered. **Warning:** you can accidentally register your function multiple times and it will be called multiple times!

<a name="func-on_render_event"></a>
### on\_render\_event([`RenderEvents`](Lua-Defines-module#render-events) event, beforeCallback, afterCallback)
Register functions to call before & after a specific render layer/rendering event

#### Parameters:

* event [`RenderEvents`](Lua-Defines-module#render-events)
    * Event identifier to hook, see `RenderEvents` table linked for a full list of currently supported events.
*   beforeCallback `function`
    * Callback function to register that is called before the specific Render layer/event is executed
    * useful for setting up transformations & pushing matrices, or just drawing things on screen before a specific render has been drawn (drawing under that layer)
*   afterCallback `function`
    * Callback function to register that is called after the render layer/event has occurred
    * useful for cleaning up transformations & popping matrices to restore the state of before rendering or in general just drawing things on screen after a specific render has been drawn (drawing on top of that layer)

Your function will be called upon the specified event being triggered inside the game **These are internal events** not events as described in XML files, so these are events like functions internal to the game (like ship loading) and not events as in popups or encounters in the game. You can think of these as game engine events. See [on\_game\_event](#func-on_game_event) for hooking gameplay events.

Functions will be called in the order they are registered. **Warning:** you can accidentally register your function multiple times and it will be called multiple times!

#### Usage:
```lua
-- Make the background shift in size very poorly between two sizes every 5 seconds (10 second loop)
local tideMode_seconds = 0
function tidePod_renderEffects_before()
    if mods.hsFun.tideMode then
        tideMode_seconds = tideMode_seconds + (Hyperspace.FPS.SpeedFactor / 16) -- For some reason FTL's speed factor must be multiplied by 1/16 to get actual time
        if tideMode_seconds > 10 then
            tideMode_seconds = 0
        end

        if tideMode_seconds > 5 then
            Graphics.CSurface.GL_PushMatrix()
            Graphics.CSurface.GL_Scale(1.1, 1.1, 1.0)
        end
    else
end
function tidePod_renderEffects_after()
    if mods.hsFun.tideMode then
        if tideMode_seconds > 5 then
            Graphics.CSurface.GL_PopMatrix()
        end
    end
end
script.on_render_event(Defines.RenderEvents.LAYER_BACKGROUND, tidePod_renderEffects_before, tidePod_renderEffects_after)
```

<a name="func-on_game_event"></a>
### on\_game\_event(eventName, onLoadOnly, callback)
Register a function to call upon a named XML game event or choice being loaded.
Game event names are the `name=` attribute of an `<event>` or `<choice>` in the XML

#### Parameters:
* eventName [`string`](https://www.lua.org/manual/5.3/manual.html#6.4)
    * Event or Choice name to hook, the names matter based on what you set in the XML, you must not hook unnamed events or choices.
* onLoadOnly `boolean`
    * `true` to run only when re-loading from a save game
    * `false` to run only on first encountering this event (i.e. not on loading the event but only when the event actually runs in-game and pops the choice window or whatever)
*   callback `function`
    * Callback function to register

Functions will be called in the order they are registered. **Warning:** you can accidentally register your function multiple times and it will be called multiple times!

#### Usage:

```lua
-- Cut artillery system #2's power by 50% when hitting this event
-- You could easily make this random using random32
function loseArty2()
    local artillery = Hyperspace.ships.player.artillerySystems
    if artillery then
        if artillery:size() > 1 then
            local curMaxPower = artillery[1]:GetMaxPower() -- artillery is from C code, so the index starts at 0 not 1 like in normal Lua
            artillery[1]:SetPowerLoss(curMaxPower / 2)
        end
    end
end
script.on_game_event("SOME_EVENT_WHERE_WE_LOSE_ARTY_2", false, loseArty2)
```
