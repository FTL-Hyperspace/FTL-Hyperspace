#include "LuaLibScript.h"

int refNumber = 0; // TODO: We need to store a linked list (or vector) of reference numbers, I'm not sure if we need to update them in-place but it seems like we might as the number might change each time?

int LuaLibScript::l_onload(lua_State* lua)
{
    assert(lua_isfunction(lua, 1));
    printf("Hello World, l_onload was called!\n");
    int callbackReference = luaL_ref(lua, LUA_REGISTRYINDEX);
    refNumber = callbackReference;
    // TODO: Allow registering a lua function into some shared internal state so we can call this on load
    return 0;
}

void LuaLibScript::call_callback()
{
    lua_State* lua = this->m_Lua;
    // Load the callback by reference number
    printf("Fetching Calling callback\n");
    lua_rawgeti(lua, LUA_REGISTRYINDEX, refNumber);
    //lua_pushvalue(lua, 1);
    printf("Calling callback\n");
    if(lua_pcall(lua, 0, 0, 0) != 0) {
        printf("Failed to call the callback!\n %s\n", lua_tostring(lua, -1));
        return;
    }
    //refNumber = luaL_ref(lua, LUA_REGISTRYINDEX); // Get new reference to callback again, what the fuck lua.
}

static const struct luaL_Reg slib_funcs[] = {
   { "on_load", LuaLibScript::l_onload },
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
