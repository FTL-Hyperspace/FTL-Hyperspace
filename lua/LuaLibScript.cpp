#include "LuaLibScript.h"

int LuaLibScript::l_onload(lua_State* lua) // TODO: Check if this can be called from private or protected by Lua, that would be ideal
{
    printf("Hello World, l_onload was called!\n");
    // TODO: Allow registering a lua function into some shared internal state so we can call this on load
    return 0;
}

static const struct luaL_Reg slib_funcs[] = {
   { "onload", LuaLibScript::l_onload },
   { NULL, NULL }
};
 
static int luaopen_scriptlib(lua_State* lua)
{
   luaL_newlib(lua, slib_funcs);
   return 1;
}

LuaLibScript::LuaLibScript(lua_State* lua)
{
   this->m_Lua = lua;
   luaL_requiref(lua, "script", luaopen_scriptlib, 1);
}
