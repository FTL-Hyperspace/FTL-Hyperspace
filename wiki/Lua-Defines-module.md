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

| Name | Arguments | Description |
| :--- | --- | --- |
| MAIN_MENU | `None` | On rendering the main menu |
| GUI_CONTAINER | `None` | On rendering the main game, this is a wrapper around the entire game UI |
| LAYER_BACKGROUND | `None` | The space background layer |
| LAYER_FOREGROUND | `None` | The space foreground layer, includes the planet/solar flare/ion storm/nebula but not asteroids |
| LAYER_ASTEROIDS | `None` | The space asteroids layer, in front of the the space foreground |
| LAYER_PLAYER | `None` | The player ship, you can render things on top the player ship by using the after method of the callbacks |
| SHIP | `Ship ship` | Any active ship, you can render things on top the ship by using the after method of the callbacks |
| SHIP_MANAGER | `ShipManager ship` `bool showInterior` `bool doorControlMode` | `before_function` is equivalent to `roomAnim` layer 3, `after_function` is equivalent to `roomAnim` layer 4 |
| SHIP_JUMP | `Ship ship` `float animationProgress` | Any active ship that is jumping, you can render things on top the ship by using the after method of the callbacks |
| SHIP_HULL | `Ship ship` `float alphaCloak` | On rendering the ship hull, cloak and thruster animations |
| SHIP_ENGINES | `Ship ship` `bool showEngines` `float alpha` | Thruster animations |
| SHIP_FLOOR | `Ship ship` `bool experimental` | Equivalent to `roomAnim` layer 0 |
| SHIP_BREACHES | `Ship ship` | Equivalent to `roomAnim` layer 1 |
| SHIP_SPARKS | `Ship ship` | Equivalent to `roomAnim` layer 2 |
| CREW_MEMBER_HEALTH | `CrewMember crew` | Runs for each `CrewMember` regardless of whether their health bar is visible |
| LAYER_FRONT | `None` | In front of player ship, where asteroids above the ship are rendered but you can draw whatever you want |
| FTL_BUTTON | `None` | Same layer as the FTL jump button and most of the player UI |
| SYSTEM_BOX | `SystemBox systemBox` `bool ignoreStatus` | Called for each individual SystemBox, passed under the `systemBox` arg. Render coordinates are in the reference frame of the SystemBox. Unsure what `ignoreStatus` does.|
| SPACE_STATUS | `None` | On rendering hazard environment icons |
| SHIP_STATUS | `None` | On rendering player element like hull and ressources |
| CHOICE_BOX | `ChoiceBox choiceBox` | When any choiceBox related window is on screen |
| TABBED_WINDOW | `int currentTab` | On rendering a tab in the upgrade interface |
| MOUSE_CONTROL | `None` | Rendering at the highest layer above everything else where the mouse cursor is finally drawn |

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

| Name | Arguments | Must Return | Description |
| :--- | --- | --- | --- |
| ON_TICK | `None` | `None` | Run code every in-game tick (frame), use in combination with other events to turn logic on and off in your code that runs every tick |
| MAIN_MENU | `None` | `None` | Run code when the main menu opens |
| DANGEROUS_ENVIRONMENT | `bool danger` | `bool danger` | Can be used to change the state of the environment, affecting music and ability to upgrade |
| GET_BEACON_HAZARD | `Location loc` | `string hazardText` | If a value is returned, can be used to mark a beacon as a hazard with an icon and tooltip on the beacon map |
| GET_HAZARD_FLASH | `float alpha` | `float red`, `float green`, `float blue`, `float alpha` | Can be used to alter the opacity and color of the flash used for suns and pulsars |
| GET_RUN_SEED | `bool isCustomSeed`, `int seed` | `bool isCustomSeed`, `int seed` | Run code when the seed for the run is set |
| ON_KEY_DOWN | [`Defines.SDL`](#sdl-keys)` Key` | `Defines.Chain chain` | Detect keyboard key is pressed |
| ON_KEY_UP | [`Defines.SDL`](#sdl-keys)` Key` | `Defines.Chain chain` | Detect keyboard key is unpressed |
| ON_MOUSE_MOVE | `int x`, `int y`, `int xdiff`, `int ydiff`, `bool holdingLMB`, `bool holdingRMB`, `bool holdingMMB` | `Defines.Chain chain` | Detect mouse movement |
| ON_MOUSE_L_BUTTON_DOWN | `int x`, `int y` | `Defines.Chain chain` | Detect left mouse button is pressed |
| ON_MOUSE_L_BUTTON_UP | `int x`, `int y` | `Defines.Chain chain` | Detect left mouse button is unpressed |
| ON_MOUSE_R_BUTTON_DOWN | `int x`, `int y` | `Defines.Chain chain` | Detect right mouse button is pressed |
| ON_MOUSE_R_BUTTON_UP | `int x`, `int y` | `Defines.Chain chain` | Detect right mouse button is unpressed |
| ON_MOUSE_M_BUTTON_DOWN | `int x`, `int y` | `Defines.Chain chain` | Detect middle mouse button is pressed |
| ON_MOUSE_SCROLL | `float direction` | `Defines.Chain chain` | Detect mouse scrolling. `direction` will be 1.0 when scrolling down, -1.0 when scrolling up.|
| GUI_MOUSE_MOVE | `int x`, `int y` | `Defines.Chain chain` | Detect mouse movement (to be used for `GenericButton`'s `MouseMove` method) |
| CREW_LOOP | `CrewMember crew` | `None` | While unpaused, run code every in-game tick for each crew member |
| CREW_CLONE | `CrewMember crew` | `None` | Called at the start of creating a `CrewMember` after the cloning process |
| SHIP_LOOP | `ShipManager ship` | `None` | While unpaused, run code every in-game tick for each ship |
| HAS_EQUIPMENT | `ShipManager ship`, `string equipment`, `int value` | `Defines.Chain chain`, `int value` | Run every hasEquipment check |
| HAS_AUGMENTATION | `ShipManager ship`, `string augment`, `int value` | `Defines.Chain chain`, `int value` | Run every hasAugmentation check |
| GET_AUGMENTATION_VALUE | `ShipManager ship`, `string augment`, `float value` | `Defines.Chain chain`, `float value` | Called when checking an augmentation's value |
| GET_DODGE_FACTOR | `ShipManager ship`, `int value` | `Defines.Chain chain`, `int value` | Can be used to alter the dodge factor for the given ship |
| SET_BONUS_POWER | `ShipSystem system`, `int amount` | `Defines.Chain chain`, `int amount` | Can be used to alter the bonus power for the given system |
| SELECT_ARMAMENT_PRE | `uint armamentSlot` | `Defines.Chain chain`, `uint armamentSlot` | Triggered when selecting a weapon to fire, can be used to alter or block the selected weapon |
| SELECT_ARMAMENT_POST | `uint armamentSlot` | `Defines.Chain chain` | Triggered after selecting a weapon to fire |
| PROJECTILE_INITIALIZE | `Projectile projectile`, `WeaponBlueprint bp` | `None` | Called when a projectile is initialized |
| PROJECTILE_FIRE | `Projectile projectile`, `ProjectileFactory weapon` | `None` | Called when a projectile is fired |
| PROJECTILE_PRE | `Projectile projectile` | `Defines.Chain chain` | Called before projectile processing |
| PROJECTILE_POST | `Projectile projectile`, `bool preempted` | `Defines.Chain chain` | Called after projectile processing |
| PROJECTILE_UPDATE_PRE | `Projectile projectile` | `Defines.Chain chain` | Called before projectile update |
| PROJECTILE_UPDATE_POST | `Projectile projectile`, `bool preempted` | `Defines.Chain chain` | Called after projectile update |
| WEAPON_COOLDOWN_MOD | `ProjectileFactory weapon`, `float cooldownMod`, `bool isArtillery` | `Defines.Chain chain`, `float cooldownMod` | Check and possibly alter the cooldown modifier being applied to a weapon. Return value cannot be greater than 1 for non-artillery weapons. |
| WEAPON_STATBOX | `WeaponBlueprint bp`, `string stats` | `string stats` | Change the text displayed for the player weapon stats (only works if `redesignedWeaponTooltips` is enabled) |
| WEAPON_DESCBOX | `WeaponBlueprint bp`, `string desc` | `string desc` | Change the text displayed for the player weapon description |
| WEAPON_RENDERBOX | `ProjectileFactory weapon`, `int cooldown`, `int maxCooldown`, `string firstLine`, `string secondLine`, `string thirdLine` | `Defines.Chain chain`, `string firstLine`, `string secondLine`, `string thirdLine` | Change the text displayed for the player weapon cooldown timers |
| DRONE_FIRE | `Projectile projectile`, `SpaceDrone spacedrone` | `Defines.Chain chain` | Called when a drone fires |
| DRONE_COLLISION | `SpaceDrone drone`, `Projectile projectile`, `Damage damage`, `CollisionResponse response` | `Defines.Chain chain` | Called when a drone collides with a projectile |
| PROJECTILE_COLLISION | `Projectile thisProjectile`, `Projectile otherProjectile`, `Damage damage`, `CollisionResponse response` | `Defines.Chain chain` | Called when projectiles collide |
| SHIELD_COLLISION_PRE | `ShipManager ship`, `Projectile projectile`, `Damage damage`, `CollisionResponse response` | `Defines.Chain chain` | Called before shield collision logic |
| SHIELD_COLLISION | `ShipManager ship`, `Projectile projectile`, `Damage damage`, `CollisionResponse response` | `Defines.Chain chain` | Called after shield collision |
| DAMAGE_AREA | `ShipManager ship`, `Projectile projectile`, `Pointf location`, `Damage damage`, `Evasion forceHit`, `bool shipFriendlyFire` | `Defines.Chain chain`, `Evasion forceHit`, `bool shipFriendlyFire` | Called when an is about to be hit by a projectile |
| DAMAGE_AREA_HIT | `ShipManager ship`, `Projectile projectile`, `Pointf location`, `Damage damage`, `bool shipFriendlyFire` | `Defines.Chain chain` | Called when an area is hit by a projectile |
| DAMAGE_BEAM | `ShipManager ship`, `Projectile projectile`, `Pointf location`, `Damage damage`, `bool newTile`, `BeamHit beamHit` | `Defines.Chain chain`, `BeamHit beamHit` | Called when a beam deals damage |
| DAMAGE_SYSTEM | `ShipManager ship`, `Projectile projectile`, `int roomId`, `Damage damage` | `Defines.Chain chain` | Called when a system takes damage |
| SYSTEM_ADD_DAMAGE | `ShipSystem sys`, `Projectile projectile`, `int amount` | `Defines.Chain chain`, `int amount` | Called when damage is added to a system, occurs after all resist calculations |
| ACTIVATE_POWER | `ActivatedPower power`, `ShipManager ship` | `Defines.Chain chain` | Called when a crew activates a power |
| PREPARE_POWER | `ActivatedPower power` | `Defines.Chain chain` | Called when preparing a power activation |
| CANCEL_POWER | `ActivatedPower power`, `bool clearAnim` | `Defines.Chain chain` | Called when canceling a power |
| POWER_ON_UPDATE | `ActivatedPower power` | `Defines.Chain chain` | Called when updating a power |
| POWER_RESOURCE_ON_UPDATE | `ActivatedPowerResource power` | `Defines.Chain chain` | Called when updating a resource power |
| POWER_ENABLE_INIT | `ActivatedPower power` | `Defines.Chain chain` | Called when initializing power enable state |
| POWER_RESOURCE_ENABLE_INIT | `ActivatedPowerResource power` | `Defines.Chain chain` | Called when initializing resource power enable state |
| POWER_REQ | `ActivatedPower power`, `ActivatedPowerRequirements req`, `PowerReadyState result` | `Defines.Chain chain`, `PowerReadyState result` | Called when checking power requirements |
| POWER_READY | `ActivatedPower power`, `PowerReadyState result` | `Defines.Chain chain`, `PowerReadyState result` | Called when checking if power is ready |
| POWER_TOOLTIP | `ActivatedPower power`, `PowerReadyState state` | `string tooltip`, `bool skipAppend` | Called when rendering power tooltip |
| GENERATOR_CREATE_SHIP | `string name`, `int sector`, `ShipEvent event`, `ShipBlueprint bp`, `ShipManager ret` | `Defines.Chain chain`, `int sector`, `ShipEvent event`, `ShipBlueprint bp`, `ShipManager ret` | Called when generating a new ship from an event |
| GENERATOR_CREATE_SHIP_POST | `string name`, `int sector`, `ShipEvent event`, `ShipBlueprint bp`, `ShipManager ret` | `Defines.Chain chain` | Called after generating a new ship from an event |
| PRE_CREATE_CHOICEBOX | `LocationEvent event` | `None` | Called before the creation of a `ChoiceBox` by a `LocationEvent` |
| POST_CREATE_CHOICEBOX | `ChoiceBox choiceBox`, `LocationEvent event` | `None` | Called after the creation of a `ChoiceBox` by a `LocationEvent` |
| TABBED_WINDOW_CONFIRM | `string currentTabName` | `None` | Called for every event that closes the current tab in the upgrade menu |
| TABBED_WINDOW_UNDO | `string currentTabName` | `None` | Called when the UNDO button is activated in the upgrade menu |
| JUMP_ARRIVE | `ShipManager ship` | `None` | Called when a ship arrives at a beacon |
| JUMP_LEAVE | `ShipManager ship` | `None` | Called when a ship leaves a beacon |
| ON_WAIT | `ShipManager ship` | `None` | Run code every time the ship waits (Spending a jump cycle without moving beacons, either when out of fuel or at last stand) |
| SYSTEM_BOX_MOUSE_MOVE | `SystemBox systemBox`, `int x`, `int y` | `Defines.Chain chain` | Called when the mouse is moved at coordinates (`x`, `y`). Coordinates are relative to the SystemBox in question. |
| SYSTEM_BOX_MOUSE_CLICK | `SystemBox systemBox`, `bool shift` | `Defines.Chain chain` | Called when the mouse is clicked. `shift` indicates whether the shift key is held on click. |
| SYSTEM_BOX_KEY_DOWN | `SystemBox systemBox`, [`Defines.SDL`](#sdl-keys)` Key`, `bool shift` | `Defines.Chain chain` | Called when a key is pressed. `Key` argument indicates the specific key pressed, and `shift` argument indicates whether the shift key is held on click. |
| GET_LEVEL_DESCRIPTION | `int systemId`, `int level`, `bool tooltip` | `string level_description` | Called to get the description of what a system does at a certain level. `systemId` indicates the ID of the system, `level` indicates the power level, and `tooltip` indicates whether the string being generated is in the context of a mouseover tooltip. |
| CALCULATE_LEAK_MODIFIER | `ShipManager ship`, `float modifier` | `Defines.Chain chain`, `float modifier` | Called once per ship every game tick to calculate a multiplier to the rate at which airlocks and breaches drain oxygen. |
| CONSTRUCT_CREWMEMBER | `CrewMember crew` | `None` | Called when constructing a crew member |
| CONSTRUCT_SPACEDRONE | `SpaceDrone drone` | `None` | Called when constructing a space drone |
| CONSTRUCT_PROJECTILE_FACTORY | `ProjectileFactory weapon` | `None` | Called when constructing a weapon |
| CONSTRUCT_PROJECTILE | `Projectile projectile` | `None` | Called when constructing a projectile |
| CONSTRUCT_ROOM | `Room room` | `None` | Called when constructing a room |
| CONSTRUCT_SHIP_MANAGER | `ShipManager ship` | `None` | Called when constructing a ShipManager |
| CONSTRUCT_SHIP_SYSTEM | `ShipSystem system` | `None` | Called when constructing a ship system |
| CONSTRUCT_SYSTEM_BOX | `SystemBox systemBox` | `None` | Called when constructing a GUI system box |

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

For example `Defines.SDL.KEY_AMPERSAND`(equivalent to 38)
| Name | Value | Description |
| :--- | --- | --- |
| KEY_UNKNOWN | 0 | Unknown key was pressed |
| KEY_0 | 48 | 0 key |
| KEY_1 | 49 | 1 key |
| KEY_2 | 50 | 2 key |
| KEY_3 | 51 | 3 key |
| KEY_4 | 52 | 4 key |
| KEY_5 | 53 | 5 key |
| KEY_6 | 54 | 6 key |
| KEY_7 | 55 | 7 key |
| KEY_8 | 56 | 8 key |
| KEY_9 | 57 | 9 key |
| KEY_AT | 64 | @ at-sign |
| KEY_AMPERSAND | 38 | `&` Ampersand key |
| KEY_ASTERISK | 42 | `*` Asterisk key |
| KEY_BACKQUOTE | 96 | `` ` `` Backquote/Backtick key |
| KEY_BACKSLASH | 92 | `\` Backslash key |
| KEY_BACKSPACE | 8 | Backspace key |
| KEY_BREAK | 318 | Break key (the "break" of "pause/break") |
| KEY_CAPSLOCK | 301 | Capslock key |
| KEY_CARET | 94 | `^` Caret key |
| KEY_CLEAR | 12 | CLEAR key |
| KEY_COLON | 58 | `:` COLON key |
| KEY_COMMA | 44 | `,` COMMA key |
| KEY_COMPOSE | 314 | COMPOSE key |
| KEY_DELETE | 127 | DELETE key |
| KEY_DOLLAR | 36 | `$` DOLLAR key |
| KEY_DOWN | 274 | DOWN Arrow key |
| KEY_END | 279 | END key |
| KEY_EQUALS | 61 | `=` EQUALS key |
| KEY_ESCAPE | 27 | ESCAPE key |
| KEY_EURO | 321 | EURO key |
| KEY_EXCLAIM | 33 | `!` Exclamation point/mark key |
| KEY_F1 | 282 | F1 key |
| KEY_F2 | 283 | F2 key |
| KEY_F3 | 284 | F3 key |
| KEY_F4 | 285 | F4 key |
| KEY_F5 | 286 | F5 key |
| KEY_F6 | 287 | F6 key |
| KEY_F7 | 288 | F7 key |
| KEY_F8 | 289 | F8 key |
| KEY_F9 | 290 | F9 key |
| KEY_F10 | 291 | F10 key |
| KEY_F11 | 292 | F11 key |
| KEY_F12 | 293 | F12 key |
| KEY_F13 | 294 | F13 key |
| KEY_F14 | 295 | F14 key |
| KEY_F15 | 296 | F15 key |
| KEY_GREATER | 62 |  `>` GREATER key |
| KEY_HASH | 36 | `#` HASH key |
| KEY_HELP | 315 | HELP key |
| KEY_HOME | 278 | HOME key |
| KEY_INSERT | 277 | INSERT key |
| KEY_KP0 | 256 | Numpad `0` key |
| KEY_KP1 | 257 | Numpad `1` key |
| KEY_KP2 | 258 | Numpad `2` key |
| KEY_KP3 | 259 | Numpad `3` key |
| KEY_KP4 | 260 | Numpad `4` key |
| KEY_KP5 | 261 | Numpad `5` key |
| KEY_KP6 | 262 | Numpad `6` key |
| KEY_KP7 | 263 | Numpad `7` key |
| KEY_KP8 | 264 | Numpad `8` key |
| KEY_KP9 | 265 | Numpad `9` key |
| KEY_KP_PERIOD | 266 | Numpad `.` period key |
| KEY_KP_DIVIDE | 267 | Numpad `/` divide key |
| KEY_KP_MULTIPLY | 268 | Numpad `*` multiply key |
| KEY_KP_MINUS | 269 | Numpad `-` minus key |
| KEY_KP_PLUS | 270 | Numpad `+` plus key |
| KEY_KP_ENTER | 271 | Numpad Enter key |
| KEY_KP_EQUALS | 272 | Numpad `=` Equals key |
| KEY_LALT | 308 | Left ALT key |
| KEY_LCTRL | 306 | Left CTRL key |
| KEY_LEFT | 276 | LEFT Arrow key |
| KEY_LEFTBRACKET | 91 | `[` key |
| KEY_LEFTPAREN | 40 | `(` key |
| KEY_LESS | 60 | LESS key |
| KEY_LMETA | 310 | Left META key |
| KEY_LSHIFT | 304 | Left SHIFT key |
| KEY_LSUPER | 311 | Left SUPER key |
| KEY_MENU | 319 | Menu/Context Menu key |
| KEY_MINUS | 45 | `-` key |
| KEY_MODE | 313 | MODE key |
| KEY_NUMLOCK | 300 | NUMLOCK key |
| KEY_PAGEDOWN | 281 | PAGE DOWN key |
| KEY_PAGEUP | 280 | PAGE UP key |
| KEY_PAUSE | 19 | PAUSE key (of "pause/break") |
| KEY_PERIOD | 46 | `.` key |
| KEY_PLUS | 43 | `+` key |
| KEY_POWER | 320 | POWER key |
| KEY_PRINTSCREEN | 316 | PRINT SCREEN key |
| KEY_QUESTION | 63 | `?` key |
| KEY_QUOTEDBL | 34 | `"` key |
| KEY_QUOTE | 39 | `'` key |
| KEY_RALT | 307 | Right ALT key |
| KEY_RCTRL | 305 | Right CTRL key |
| KEY_RETURN | 13 | RETURN key |
| KEY_RIGHT | 275 | RIGHT Arrow key |
| KEY_RIGHTBRACKET | 93 | `]` key |
| KEY_RIGHTPAREN | 41 | `)` key |
| KEY_RMETA | 309 | Right META key |
| KEY_RSHIFT | 303 | Right SHIFT key |
| KEY_RSUPER | 312 | Right SUPER key |
| KEY_SCROLLOCK | 302 | SCROL LOCK key |
| KEY_SEMICOLON | 59 | `;` key |
| KEY_SLASH | 47 | `/` key |
| KEY_SPACE | 32 | SPACE key |
| KEY_SYSREQ | 317 | System Request key |
| KEY_TAB | 9 | TAB key |
| KEY_UNDERSCORE | 95 | `_` key |
| KEY_UNDO | 322 | UNDO key (this is not ctrl+z) |
| KEY_UP | 273 | UP Arrow key |
| KEY_a | 97 | a key |
| KEY_b | 98 | b key |
| KEY_c | 99 | c key |
| KEY_d | 100 | d key |
| KEY_e | 101 | e key |
| KEY_f | 102 | f key |
| KEY_g | 103 | g key |
| KEY_h | 104 | h key |
| KEY_i | 105 | i key |
| KEY_j | 106 | j key |
| KEY_k | 107 | k key |
| KEY_l | 108 | l key |
| KEY_m | 109 | m key |
| KEY_n | 110 | n key |
| KEY_o | 111 | o key |
| KEY_p | 112 | p key |
| KEY_q | 113 | q key |
| KEY_r | 114 | r key |
| KEY_s | 115 | s key |
| KEY_t | 116 | t key |
| KEY_u | 117 | u key |
| KEY_v | 118 | v key |
| KEY_w | 119 | w key |
| KEY_x | 120 | x key |
| KEY_y | 121 | y key |
| KEY_z | 122 | z key |

