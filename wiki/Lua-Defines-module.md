# Defines module
Predefined values for use in other functions


## Render Events
Defines for referencing a specific rendering layer/event for hooking with `script.on_render_event(`

You access these with `Defines.RenderEvents.NAME_OF_EVENT_HERE` in your code.
They are only used for the `on_render_event` method.

For example, doing some rendering before & after the background layer:
```lua
script.on_render_event(Defines.RenderEvents.LAYER_BACKGROUND, before_function, after_function)
```

`Defines.RenderEvents` table:

"N/A" indicates this is a planned render event that has not been added yet, if you need it you can ask for it in an issue (enhancement) and it can be worked towards. Other unplanned events can also be asked for.
| Available Since | Name | Description |
| :--- | --- | --- |
| N/A | ~~LANGUAGE_CHOOSER~~ | ~~On rendering the language chooser menu at the start of a fresh install~~ |
| 1.2.0 | MAIN_MENU | On rendering the main menu |
| 1.2.0 | GUI_CONTAINER | On rendering the main game, this is a wrapper around the entire game UI |
| 1.2.0 | LAYER_BACKGROUND | The space background layer |
| 1.2.0 | LAYER_FOREGROUND | The space foreground layer, includes the planet/solar flare/ion storm/nebula but not asteroids |
| 1.2.0 | LAYER_ASTEROIDS | The space asteroids layer, in front of the the space foreground |
| 1.2.0 | LAYER_PLAYER | The player ship, you can render things on top the player ship by using the after method of the callbacks |
| 1.4.0 | SHIP | Any active ship, you can render things on top the ship by using the after method of the callbacks |
| N/A | ~~LAYER_ENEMY~~ | ~~The enemy ship~~ |
| 1.4.0 | SHIP_MANAGER | `before_function` is equivalent to `roomAnim` layer 3, `after_function` is equivalent to `roomAnim` layer 4 |
| 1.4.0 | SHIP_JUMP | Any active ship that is jumping, you can render things on top the ship by using the after method of the callbacks |
| N/A | ~~PROJECTILE~~ | ~~Projectile rendering, not a layer but per each individual projectile~~ |
| N/A | ~~SHIELDS_BASE~~ | ~~Shield base rendering (not sure if player & enemy yet)~~ |
| 1.4.0 | SHIP_HULL | On rendering the ship hull, cloak and thruster animations |
| 1.4.0 | SHIP_FLOOR | Equivalent to `roomAnim` layer 0 |
| 1.4.0 | SHIP_BREACHES | Equivalent to `roomAnim` layer 1 |
| 1.3.0 | SHIP_SPARKS | Equivalent to `roomAnim` layer 2 |
| 1.10.0 | SHIP_ENGINES | Thruster animations |
| N/A | ~~SHIP_EXPLOSION~~ | ~~Probably affects both player & enemy, I think this is when the ship is destroyed~~ |        
| 1.2.0 | LAYER_FRONT | In front of player ship, where asteroids above the ship are rendered but you can draw whatever you want |
| N/A | ~~PAUSE~~ | ~~Pause menu rendering, might be useful for also stopping some other renders~~ |
| 1.10.0 | SPACE_STATUS | On rendering hazard environment icons |
| N/A | ~~CHOICE~~ | ~~ConfirmWindow/ChoiceBox, when a choice window is on screen~~ |
| 1.2.0 | MOUSE_CONTROL | Rendering at the highest layer above everything else where the mouse cursor is finally drawn |

## Internal Events
Defines for referencing a specific game engine internal event for hooking with `script.on_internal_event(`

You access these with `Defines.InternalEvents.NAME_OF_EVENT_HERE` in your code.
They are only used for the `on_internal_event` method.

For example, doing something every tick:
```lua
script.on_internal_event(Defines.InternalEvents.ON_TICK, callback_function)
```

_**NOTE:** Currently internal events do not expect any arguments or return values from an event but this will change in future versions_

`Defines.InternalEvents` table:

| Available Since | Name | Arguments | Must Return | Description |
| :--- | --- | --- | --- | --- |
| 1.2.0 | ON_TICK | `None` | `None` | Run code every in-game tick (frame), use in combination with other events to turn logic on and off in your code that runs every tick |
| 1.2.0 | MAIN_MENU | `None` | `None` | Run code when the main menu opens |
| 1.10.0 | GET_RUN_SEED | `bool isCustomSeed`, `int seed` | `bool isCustomSeed`, `int seed` | Run code when the seed for the run is set |
| 1.4.0 | ON_KEY_DOWN | [`Defines.SDL`](#sdl-keys)` Key` | `None` | Detect keyboard key is pressed |
| 1.4.0 | ON_KEY_UP | [`Defines.SDL`](#sdl-keys)` Key` | `None` | Detect keyboard key is unpressed |
| 1.4.0 | ON_MOUSE_MOVE | `int x`, `int y`, `int xdiff`, `int ydiff`, `bool holdingLMB`, `bool holdingRMB`, `bool holdingMMB` | `None` | Detect mouse movement |
| 1.9.0 | GUI_MOUSE_MOVE | `int x`, `int y` | `Defines.Chain` chain | Detect mouse movement (to be used for `GenericButton`'s `MouseMove` method) |
| 1.4.0 | ON_MOUSE_L_BUTTON_DOWN | `int x`, `int y` | `None` | Detect left mouse button is pressed |
| 1.4.0 | ON_MOUSE_L_BUTTON_UP | `int x`, `int y` | `None` | Detect left mouse button is unpressed |
| 1.4.0 | ON_MOUSE_R_BUTTON_DOWN | `int x`, `int y` | `None` | Detect right mouse button is pressed |
| 1.4.0 | ON_MOUSE_R_BUTTON_UP | `int x`, `int y` | `None` | Detect right mouse button is unpressed |
| 1.4.0 | ON_MOUSE_M_BUTTON_DOWN | `int x`, `int y` | `None` | Detect middle mouse button is pressed |
| 1.3.0 | CREW_LOOP | `CrewMember crew` | `None` | While unpaused, run code every in-game tick for each crew member |
| 1.4.0 | SHIP_LOOP | `ShipManager ship` | `None` | While unpaused, run code every in-game tick for each ship |
| 1.8.0 | GET_DODGE_FACTOR | `ShipManager ship`, `int value` | `Defines.Chain` chain, `int` value | Can be used to alter the dodge factor for the given ship |
| 1.13.0 | SET_BONUS_POWER | `ShipSystem system`, `int amount`, `int permanentPower` | `Defines.Chain` chain, `int` amount, `int` permanentPower | Can be used to alter the bonus power for the given system |
| 1.10.0 | ON_WAIT | `ShipManager ship` | `None` | Run code every time the ship waits (Spending a jump cycle without moving beacons, either when out of fuel or at last stand) |
| N/A | ~~ON_INIT~~ | ~~`None`~~ | ~~`None`~~ | ~~Run code on the start of a run (and loading a run), currently handled by `script.on_init` this internal event will potentially replace it~~ |
| N/A | ~~ON_LOAD~~ | ~~`None`~~ | ~~`None`~~ | ~~Run code after the game is loaded (currently after hyperspace.xml is initialized but might change to on main menu loading so all Lua is ready first), currently handled by `script.on_load` this internal event will potentially replace it~~ |
| N/A | ~~PLAYERSHIP_ON_HULL_DAMAGE~~ | ~~`int damage`~~ | ~~`int` hull value~~ | ~~Detect damage to the player ship & return a value of the final hull hitpoints, returning 0 will blow up the ship. Receiving a negative value implies healing~~ |
| 1.11.0 | WEAPON_STATBOX | `WeaponBlueprint bp`, `string stats` | `string stats` | Change the text displayed for the player weapon stats (only works if `redesignedWeaponTooltips` is enabled) |
| 1.11.0 | WEAPON_DESCBOX | `WeaponBlueprint bp`, `string desc` | `string desc` | Change the text displayed for the player weapon description |
| 1.10.0 | WEAPON_RENDERBOX | `ProjectileFactory weapon`, `int cooldown`, `int maxCooldown`, `string firstLine`, `string secondLine` | `string firstLine`, `string secondLine` | Change the text displayed for the player weapon cooldown timers |
| 1.11.0 | PRE_CREATE_CHOICEBOX | `LocationEvent event` | `None` | Called before the creation of a `ChoiceBox` by a `LocationEvent` |
| 1.11.0 | POST_CREATE_CHOICEBOX | `ChoiceBox choiceBox`, `LocationEvent event` | `None` | Called after the creation of a `ChoiceBox` by a `LocationEvent` |

## Other predefined values

### Chain
Used by callbacks to determine how to continue code execution.
`Defines.Chain` table:

For example `Defines.Chain.CONTINUE`
| Name | Description |
| :--- | --- |
| CONTINUE | Call the next callback in the sequence if there is one |
| HALT | Halt the callback loop, but still run subsequent C++ code |
| PREEMPT | Halt the callback loop and skip subsequent C++ code |

### Evasion
Used by callbacks to determine whether a projectile hits or misses.
`Defines.Evasion` table:

For example `Defines.Evasion.HIT`
| Name | Description |
| :--- | --- |
| NONE | Indicates evasion still needs to be checked |
| HIT | Force projectile to hit |
| MISS | Force projectile to miss |

### BeamHit
Used by beam damage callbacks to determine what type of hit is currently being processed.
`Defines.BeamHit` table:

For example `Defines.BeamHit.NEW_ROOM`
| Name | Description |
| :--- | --- |
| SAME_TILE | Treat beam hit as same tile as last frame |
| NEW_TILE | Treat beam hit as new tile but same room as last frame |
| NEW_ROOM | Treat beam hit as new room from last frame |

### SDL keys
`Defines.SDL` table:

For example `Defines.SDL.KEY_AMPERSAND`
| Name | Description |
| :--- | --- |
| KEY_UNKNOWN | Unknown key was pressed |
| KEY_0 | 0 key |
| KEY_1 | 1 key |
| KEY_2 | 2 key |
| KEY_3 | 3 key |
| KEY_4 | 4 key |
| KEY_5 | 5 key |
| KEY_6 | 6 key |
| KEY_7 | 7 key |
| KEY_8 | 8 key |
| KEY_9 | 9 key |
| KEY_AT | @ at-sign |
| KEY_AMPERSAND | `&` Ampersand key |
| KEY_ASTERISK | `*` Asterisk key |
| KEY_BACKQUOTE | `` ` `` Backquote/Backtick key |
| KEY_BACKSLASH | `\` Backslash key |
| KEY_BACKSPACE | Backspace key |
| KEY_BREAK | Break key (the "break" of "pause/break") |
| KEY_CAPSLOCK | Capslock key |
| KEY_CARET | `^` Caret key |
| KEY_CLEAR | CLEAR key |
| KEY_COLON | `:` COLON key |
| KEY_COMMA | `,` COMMA key |
| KEY_COMPOSE | COMPOSE key |
| KEY_DELETE | DELETE key |
| KEY_DOLLAR | `$` DOLLAR key |
| KEY_DOWN | DOWN Arrow key |
| KEY_END | END key |
| KEY_EQUALS | `=` EQUALS key |
| KEY_ESCAPE | ESCAPE key |
| KEY_EURO | EURO key |
| KEY_EXCLAIM | `!` Exclamation point/mark key |
| KEY_F1 | F1 key |
| KEY_F2 | F2 key |
| KEY_F3 | F3 key |
| KEY_F4 | F4 key |
| KEY_F5 | F5 key |
| KEY_F6 | F6 key |
| KEY_F7 | F7 key |
| KEY_F8 | F8 key |
| KEY_F9 | F9 key |
| KEY_F10 | F10 key |
| KEY_F11 | F11 key |
| KEY_F12 | F12 key |
| KEY_F13 | F13 key |
| KEY_F14 | F14 key |
| KEY_F15 | F15 key |
| KEY_GREATER | `>` GREATER key |
| KEY_HASH | `#` HASH key |
| KEY_HELP | HELP key |
| KEY_HOME | HOME key |
| KEY_INSERT | INSERT key |
| KEY_KP0 | Numpad `0` key |
| KEY_KP1 | Numpad `1` key |
| KEY_KP2 | Numpad `2` key |
| KEY_KP3 | Numpad `3` key |
| KEY_KP4 | Numpad `4` key |
| KEY_KP5 | Numpad `5` key |
| KEY_KP6 | Numpad `6` key |
| KEY_KP7 | Numpad `7` key |
| KEY_KP8 | Numpad `8` key |
| KEY_KP9 | Numpad `9` key |
| KEY_KP_PERIOD | Numpad `.` period key |
| KEY_KP_DIVIDE | Numpad `/` divide key |
| KEY_KP_MULTIPLY | Numpad `*` multiply key |
| KEY_KP_MINUS | Numpad `-` minus key |
| KEY_KP_PLUS | Numpad `+` plus key |
| KEY_KP_ENTER | Numpad Enter key |
| KEY_KP_EQUALS | Numpad `=` Equals key |
| KEY_LALT | Left ALT key |
| KEY_LCTRL | Left CTRL key |
| KEY_LEFT | LEFT Arrow key |
| KEY_LEFTBRACKET | `[` key |
| KEY_LEFTPAREN | `(` key |
| KEY_LESS | LESS key |
| KEY_LMETA | Left META key |
| KEY_LSHIFT | Left SHIFT key |
| KEY_LSUPER | Left SUPER key |
| KEY_MENU | Menu/Context Menu key |
| KEY_MINUS | `-` key |
| KEY_MODE | MODE key |
| KEY_NUMLOCK | NUMLOCK key |
| KEY_PAGEDOWN | PAGE DOWN key |
| KEY_PAGEUP | PAGE UP key |
| KEY_PAUSE | PAUSE key (of "pause/break") |
| KEY_PERIOD | `.` key |
| KEY_PLUS | `+` key |
| KEY_POWER | POWER key |
| KEY_PRINTSCREEN | PRINT SCREEN key |
| KEY_QUESTION | `?` key |
| KEY_QUOTEDBL | `"` key |
| KEY_QUOTE | `'` key |
| KEY_RALT | Right ALT key |
| KEY_RCTRL | Right CTRL key |
| KEY_RETURN | RETURN key |
| KEY_RIGHT | RIGHT Arrow key |
| KEY_RIGHTBRACKET | `]` key |
| KEY_RIGHTPAREN | `)` key |
| KEY_RMETA | Right META key |
| KEY_RSHIFT | Right SHIFT key |
| KEY_RSUPER | Right SUPER key |
| KEY_SCROLLOCK | SCROL LOCK key |
| KEY_SEMICOLON | `;` key |
| KEY_SLASH | `/` key |
| KEY_SPACE | SPACE key |
| KEY_SYSREQ | System Request key |
| KEY_TAB | TAB key |
| KEY_UNDERSCORE | `_` key |
| KEY_UNDO | UNDO key (this is not ctrl+z) |
| KEY_UP | UP Arrow key |
| KEY_a | a key |
| KEY_b | b key |
| KEY_c | c key |
| KEY_d | d key |
| KEY_e | e key |
| KEY_f | f key |
| KEY_g | g key |
| KEY_h | h key |
| KEY_i | i key |
| KEY_j | j key |
| KEY_k | k key |
| KEY_l | l key |
| KEY_m | m key |
| KEY_n | n key |
| KEY_o | o key |
| KEY_p | p key |
| KEY_q | q key |
| KEY_r | r key |
| KEY_s | s key |
| KEY_t | t key |
| KEY_u | u key |
| KEY_v | v key |
| KEY_w | w key |
| KEY_x | x key |
| KEY_y | y key |
| KEY_z | z key |

