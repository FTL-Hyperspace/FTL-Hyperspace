#include "LuaLibScript.h"
#include "../Global.h"

int refNumber = 0; // TODO: We need to store a linked list (or vector) of reference numbers, I'm not sure if we need to update them in-place but it seems like we might as the number might change each time?

int LuaLibScript::l_on_load(lua_State* lua)
{
    assert(lua_isfunction(lua, 1));
    printf("Hello World, l_on_load was called!\n");
    int callbackReference = luaL_ref(lua, LUA_REGISTRYINDEX);
    refNumber = callbackReference;
    // TODO: Allow registering a lua function into some shared internal state so we can call this on load
    return 0;
}

void LuaLibScript::call_on_load_callbacks()
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

// TODO: This hook to kick it off, could potentially move if needed? Or maybe we should of done a singleton pattern initialized by LuaScriptInit instead of passing the object back to LuaScriptInit and getting it from the global context there?
HOOK_METHOD(AchievementTracker, LoadAchievementDescriptions, () -> void)
{
    super();
    Global::GetInstance()->getLuaContext()->getLibScript()->call_on_load_callbacks();
}

static const struct luaL_Reg slib_funcs[] = {
   { "on_load", LuaLibScript::l_on_load },
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
