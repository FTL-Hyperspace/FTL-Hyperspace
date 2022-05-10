#ifndef LUADEFINES_H_INCLUDED
#define LUADEFINES_H_INCLUDED

#include "luaInclude.h"
#include "../FTLGame.h"

/***
@module Events
Event names (in the table) and event callback methods & their arguments

From this you can see what events to reference in the @{script.on_internal_event} callback registration function

@todo might rename to InteralEvents or Events.Internal or something
*/

/*** Registerable Internal Events
@section internalEventSignatures
The functions below may be registered to @{script.on_internal_event} by using the function's name (in this documentation) as the event name but you name your actual handling function whatever you want.
@usage
-- The `CApp::OnKeyDown` function in this documentation
-- shows us to expect a SDLKey entry as input and to
-- not return any value from this callback function.
-- It does not matter what we name the arguments.
function myCallback(keyPressed)
    if keyPressed == Defines.SDLKey.BACKSPACE then
        log("We saw them do it, they hit backspace")
    end
end
script.on_internal_event("CApp::OnKeyDown", myCallback)
*/
/*** Called upon any keypress
@function CApp::OnKeyDown
across the entire game, but may not be specific to a certain window or input.
@tparam SDLKey key
@return nothing
*/
/***
@function CrewEquipBox::RemoveItem
@return nothing
*/
/*** Called every game tick.
@function game_tick
@tparam uint64_t tickCount
@return nothing
Probably a terrible idea for ***EVERYTHING EVER***, will probably remove or never implement.
*/
/*** Called upon hull damage to the player's ship
@function PlayerShip_HullDamage
@tparam int shipId the ID of the ship for now...
@tparam int damage intended hull damage, negative values infer healing
@treturn uint value of the hull, 0 and the ship explodes.
*/
/*** @section end
*/


/***
@table SDLKey
@remark Move to defines module
@usage
function MyCallback(key)
    if key == Defines.SDLKey.DELETE then
        print("Delete was pressed")
    end
end

script.on_internal_event("CApp::OnKeyDown", MyCallback)

@field UNKNOWN 0
@field 0 30
@field 1 31
@field 2 32
@field 3 33
@field 4 34
@field 5 35
@field 6 36
@field 7 37
@field 8 38
@field 9 39
@field AT 40
@field AMPERSAND 26
@field ASTERISK 2A
@field BACKQUOTE 60
@field BACKSLASH 5C
@field BACKSPACE 8
@field BREAK 13E
@field CAPSLOCK 12D
@field CARET 5E
@field CLEAR C
@field COLON 3A
@field COMMA 2C
@field COMPOSE 13A
@field DELETE 7F
@field DOLLAR 24
@field DOWN 112
@field END 117
@field EQUALS 3D
@field ESCAPE 1B
@field EURO 141
@field EXCLAIM 21
@field F1 11A
@field F10 123
@field F11 124
@field F12 125
@field F13 126
@field F14 127
@field F15 128
@field F2 11B
@field F3 11C
@field F4 11D
@field F5 11E
@field F6 11F
@field F7 120
@field F8 121
@field F9 122
@field GREATER 3E
@field HASH 24
@field HELP 13B
@field HOME 116
@field INSERT 115
@field KP0 100
@field KP1 101
@field KP2 102
@field KP3 103
@field KP4 104
@field KP5 105
@field KP6 106
@field KP7 107
@field KP8 108
@field KP9 109
@field KP_PERIOD 10A
@field KP_DIVIDE 10B
@field KP_MULTIPLY 10C
@field KP_MINUS 10D
@field KP_PLUS 10E
@field KP_ENTER 10F
@field KP_EQUALS 110
@field LALT 134
@field LCTRL 132
@field LEFT 114
@field LEFTBRACKET 5B
@field LEFTPAREN 28
@field LESS 3C
@field LMETA 136
@field LSHIFT 130
@field LSUPER 137
@field MENU 13F
@field MINUS 2D
@field MODE 139
@field NUMLOCK 12C
@field PAGEDOWN 119
@field PAGEUP 118
@field PAUSE 13
@field PERIOD 2E
@field PLUS 2B
@field POWER 140
@field PRINTSCREEN 13C
@field QUESTION 3F
@field QUOTEDBL 22
@field QUOTE 27
@field RALT 133
@field RCTRL 131
@field RETURN D
@field RIGHT 113
@field RIGHTBRACKET 5D
@field RIGHTPAREN 29
@field RMETA 135
@field RSHIFT 12F
@field RSUPER 138
@field SCROLLOCK 12E
@field SEMICOLON 3B
@field SLASH 2F
@field SPACE 20
@field SYSREQ 13D
@field TAB 9
@field UNDERSCORE 5F
@field UNDO 142
@field UP 111
@field a 61
@field b 62
@field c 63
@field d 64
@field e 65
@field f 66
@field g 67
@field h 68
@field i 69
@field j 6A
@field k 6B
@field l 6C
@field m 6D
@field n 6E
@field o 6F
@field p 70
@field q 71
@field r 72
@field s 73
@field t 74
@field u 75
@field v 76
@field w 77
@field x 78
@field y 79
@field z 7A
@field LAST 143
*/
void hs_l_define_sdlkey(lua_State* lua);

void hs_l_define_register(lua_State* lua);

#endif // LUADEFINES_H_INCLUDED
