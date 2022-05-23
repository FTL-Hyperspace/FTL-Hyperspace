#include "luaDefines.h"

void hs_l_define_sdlkey(lua_State* lua) {
    lua_createtable(lua, 0, 137); /* SDLKey table */

    lua_pushliteral(lua, "UNKNOWN");
    lua_pushinteger(lua, SDLK_UNKNOWN);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "0");
    lua_pushinteger(lua, SDLK_0);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "1");
    lua_pushinteger(lua, SDLK_1);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "2");
    lua_pushinteger(lua, SDLK_2);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "3");
    lua_pushinteger(lua, SDLK_3);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "4");
    lua_pushinteger(lua, SDLK_4);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "5");
    lua_pushinteger(lua, SDLK_5);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "6");
    lua_pushinteger(lua, SDLK_6);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "7");
    lua_pushinteger(lua, SDLK_7);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "8");
    lua_pushinteger(lua, SDLK_8);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "9");
    lua_pushinteger(lua, SDLK_9);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "AT");
    lua_pushinteger(lua, SDLK_AT);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "AMPERSAND");
    lua_pushinteger(lua, SDLK_AMPERSAND);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "ASTERISK");
    lua_pushinteger(lua, SDLK_ASTERISK);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "BACKQUOTE");
    lua_pushinteger(lua, SDLK_BACKQUOTE);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "BACKSLASH");
    lua_pushinteger(lua, SDLK_BACKSLASH);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "BACKSPACE");
    lua_pushinteger(lua, SDLK_BACKSPACE);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "BREAK");
    lua_pushinteger(lua, SDLK_BREAK);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "CAPSLOCK");
    lua_pushinteger(lua, SDLK_CAPSLOCK);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "CARET");
    lua_pushinteger(lua, SDLK_CARET);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "CLEAR");
    lua_pushinteger(lua, SDLK_CLEAR);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "COLON");
    lua_pushinteger(lua, SDLK_COLON);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "COMMA");
    lua_pushinteger(lua, SDLK_COMMA);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "COMPOSE");
    lua_pushinteger(lua, SDLK_COMPOSE);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "DELETE");
    lua_pushinteger(lua, SDLK_DELETE);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "DOLLAR");
    lua_pushinteger(lua, SDLK_DOLLAR);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "DOWN");
    lua_pushinteger(lua, SDLK_DOWN);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "END");
    lua_pushinteger(lua, SDLK_END);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "EQUALS");
    lua_pushinteger(lua, SDLK_EQUALS);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "ESCAPE");
    lua_pushinteger(lua, SDLK_ESCAPE);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "EURO");
    lua_pushinteger(lua, SDLK_EURO);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "EXCLAIM");
    lua_pushinteger(lua, SDLK_EXCLAIM);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "F1");
    lua_pushinteger(lua, SDLK_F1);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "F10");
    lua_pushinteger(lua, SDLK_F10);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "F11");
    lua_pushinteger(lua, SDLK_F11);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "F12");
    lua_pushinteger(lua, SDLK_F12);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "F13");
    lua_pushinteger(lua, SDLK_F13);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "F14");
    lua_pushinteger(lua, SDLK_F14);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "F15");
    lua_pushinteger(lua, SDLK_F15);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "F2");
    lua_pushinteger(lua, SDLK_F2);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "F3");
    lua_pushinteger(lua, SDLK_F3);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "F4");
    lua_pushinteger(lua, SDLK_F4);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "F5");
    lua_pushinteger(lua, SDLK_F5);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "F6");
    lua_pushinteger(lua, SDLK_F6);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "F7");
    lua_pushinteger(lua, SDLK_F7);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "F8");
    lua_pushinteger(lua, SDLK_F8);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "F9");
    lua_pushinteger(lua, SDLK_F9);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "GREATER");
    lua_pushinteger(lua, SDLK_GREATER);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "HASH");
    lua_pushinteger(lua, SDLK_HASH);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "HELP");
    lua_pushinteger(lua, SDLK_HELP);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "HOME");
    lua_pushinteger(lua, SDLK_HOME);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "INSERT");
    lua_pushinteger(lua, SDLK_INSERT);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "KP0");
    lua_pushinteger(lua, SDLK_KP0);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "KP1");
    lua_pushinteger(lua, SDLK_KP1);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "KP2");
    lua_pushinteger(lua, SDLK_KP2);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "KP3");
    lua_pushinteger(lua, SDLK_KP3);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "KP4");
    lua_pushinteger(lua, SDLK_KP4);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "KP5");
    lua_pushinteger(lua, SDLK_KP5);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "KP6");
    lua_pushinteger(lua, SDLK_KP6);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "KP7");
    lua_pushinteger(lua, SDLK_KP7);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "KP8");
    lua_pushinteger(lua, SDLK_KP8);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "KP9");
    lua_pushinteger(lua, SDLK_KP9);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "KP_PERIOD");
    lua_pushinteger(lua, SDLK_KP_PERIOD);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "KP_DIVIDE");
    lua_pushinteger(lua, SDLK_KP_DIVIDE);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "KP_MULTIPLY");
    lua_pushinteger(lua, SDLK_KP_MULTIPLY);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "KP_MINUS");
    lua_pushinteger(lua, SDLK_KP_MINUS);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "KP_PLUS");
    lua_pushinteger(lua, SDLK_KP_PLUS);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "KP_ENTER");
    lua_pushinteger(lua, SDLK_KP_ENTER);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "KP_EQUALS");
    lua_pushinteger(lua, SDLK_KP_EQUALS);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "LALT");
    lua_pushinteger(lua, SDLK_LALT);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "LCTRL");
    lua_pushinteger(lua, SDLK_LCTRL);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "LEFT");
    lua_pushinteger(lua, SDLK_LEFT);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "LEFTBRACKET");
    lua_pushinteger(lua, SDLK_LEFTBRACKET);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "LEFTPAREN");
    lua_pushinteger(lua, SDLK_LEFTPAREN);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "LESS");
    lua_pushinteger(lua, SDLK_LESS);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "LMETA");
    lua_pushinteger(lua, SDLK_LMETA);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "LSHIFT");
    lua_pushinteger(lua, SDLK_LSHIFT);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "LSUPER");
    lua_pushinteger(lua, SDLK_LSUPER);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "MENU");
    lua_pushinteger(lua, SDLK_MENU);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "MINUS");
    lua_pushinteger(lua, SDLK_MINUS);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "MODE");
    lua_pushinteger(lua, SDLK_MODE);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "NUMLOCK");
    lua_pushinteger(lua, SDLK_NUMLOCK);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "PAGEDOWN");
    lua_pushinteger(lua, SDLK_PAGEDOWN);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "PAGEUP");
    lua_pushinteger(lua, SDLK_PAGEUP);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "PAUSE");
    lua_pushinteger(lua, SDLK_PAUSE);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "PERIOD");
    lua_pushinteger(lua, SDLK_PERIOD);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "PLUS");
    lua_pushinteger(lua, SDLK_PLUS);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "POWER");
    lua_pushinteger(lua, SDLK_POWER);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "PRINTSCREEN");
    lua_pushinteger(lua, SDLK_PRINTSCREEN);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "QUESTION");
    lua_pushinteger(lua, SDLK_QUESTION);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "QUOTEDBL");
    lua_pushinteger(lua, SDLK_QUOTEDBL);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "QUOTE");
    lua_pushinteger(lua, SDLK_QUOTE);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "RALT");
    lua_pushinteger(lua, SDLK_RALT);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "RCTRL");
    lua_pushinteger(lua, SDLK_RCTRL);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "RETURN");
    lua_pushinteger(lua, SDLK_RETURN);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "RIGHT");
    lua_pushinteger(lua, SDLK_RIGHT);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "RIGHTBRACKET");
    lua_pushinteger(lua, SDLK_RIGHTBRACKET);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "RIGHTPAREN");
    lua_pushinteger(lua, SDLK_RIGHTPAREN);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "RMETA");
    lua_pushinteger(lua, SDLK_RMETA);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "RSHIFT");
    lua_pushinteger(lua, SDLK_RSHIFT);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "RSUPER");
    lua_pushinteger(lua, SDLK_RSUPER);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "SCROLLOCK");
    lua_pushinteger(lua, SDLK_SCROLLOCK);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "SEMICOLON");
    lua_pushinteger(lua, SDLK_SEMICOLON);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "SLASH");
    lua_pushinteger(lua, SDLK_SLASH);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "SPACE");
    lua_pushinteger(lua, SDLK_SPACE);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "SYSREQ");
    lua_pushinteger(lua, SDLK_SYSREQ);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "TAB");
    lua_pushinteger(lua, SDLK_TAB);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "UNDERSCORE");
    lua_pushinteger(lua, SDLK_UNDERSCORE);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "UNDO");
    lua_pushinteger(lua, SDLK_UNDO);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "UP");
    lua_pushinteger(lua, SDLK_UP);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "a");
    lua_pushinteger(lua, SDLK_a);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "b");
    lua_pushinteger(lua, SDLK_b);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "c");
    lua_pushinteger(lua, SDLK_c);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "d");
    lua_pushinteger(lua, SDLK_d);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "e");
    lua_pushinteger(lua, SDLK_e);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "f");
    lua_pushinteger(lua, SDLK_f);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "g");
    lua_pushinteger(lua, SDLK_g);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "h");
    lua_pushinteger(lua, SDLK_h);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "i");
    lua_pushinteger(lua, SDLK_i);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "j");
    lua_pushinteger(lua, SDLK_j);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "k");
    lua_pushinteger(lua, SDLK_k);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "l");
    lua_pushinteger(lua, SDLK_l);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "m");
    lua_pushinteger(lua, SDLK_m);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "n");
    lua_pushinteger(lua, SDLK_n);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "o");
    lua_pushinteger(lua, SDLK_o);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "p");
    lua_pushinteger(lua, SDLK_p);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "q");
    lua_pushinteger(lua, SDLK_q);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "r");
    lua_pushinteger(lua, SDLK_r);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "s");
    lua_pushinteger(lua, SDLK_s);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "t");
    lua_pushinteger(lua, SDLK_t);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "u");
    lua_pushinteger(lua, SDLK_u);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "v");
    lua_pushinteger(lua, SDLK_v);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "w");
    lua_pushinteger(lua, SDLK_w);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "x");
    lua_pushinteger(lua, SDLK_x);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "y");
    lua_pushinteger(lua, SDLK_y);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "z");
    lua_pushinteger(lua, SDLK_z);
    lua_settable(lua, -3);

    lua_pushliteral(lua, "LAST");
    lua_pushinteger(lua, SDLK_LAST);
    lua_settable(lua, -3);
    
    lua_setfield(lua, -2, "SDLKey");
}

void hs_l_define_register(lua_State* lua) {
    lua_newtable(lua); /* Defines table */
    hs_l_define_sdlkey(lua);
    lua_setglobal(lua, "OldDefines"); // TODO: Move the SDLKey into `Defines` module
}
