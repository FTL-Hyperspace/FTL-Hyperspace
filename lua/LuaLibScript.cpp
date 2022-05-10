#include <vector>
#include "LuaLibScript.h"
#include "../Global.h"

static std::vector<LuaFunctionRef> m_on_load_callbacks;
static std::vector<LuaFunctionRef> m_on_init_callbacks;

int LuaLibScript::l_on_load(lua_State* lua)
{
    assert(lua_isfunction(lua, 1));
    LuaFunctionRef callbackReference = luaL_ref(lua, LUA_REGISTRYINDEX);
    m_on_load_callbacks.push_back(callbackReference);
    return 0;
}

void LuaLibScript::call_on_load_callbacks()
{
    lua_State* lua = this->m_Lua;
    // Load the callback by reference number
    printf("Fetching %u on_load callbacks\n", m_on_load_callbacks.size());
    for(auto i = m_on_load_callbacks.cbegin(); i != m_on_load_callbacks.cend(); ++i)
    {
        LuaFunctionRef refL = *i;
        lua_rawgeti(lua, LUA_REGISTRYINDEX, refL);
        if(lua_pcall(lua, 0, 0, 0) != 0) {
            printf("Failed to call the callback!\n %s\n", lua_tostring(lua, -1)); // TODO: Log to HS log?
            return;
        }
    }
}

int LuaLibScript::l_on_init(lua_State* lua)
{
    assert(lua_isfunction(lua, 1));
    LuaFunctionRef callbackReference = luaL_ref(lua, LUA_REGISTRYINDEX);
    m_on_init_callbacks.push_back(callbackReference);
    return 0;
}

void LuaLibScript::call_on_init_callbacks()
{
    lua_State* lua = this->m_Lua;
    // Load the callback by reference number
    printf("Fetching %u on_init callbacks\n", m_on_init_callbacks.size());
    for(auto i = m_on_init_callbacks.cbegin(); i != m_on_init_callbacks.cend(); ++i)
    {
        LuaFunctionRef refL = *i;
        lua_rawgeti(lua, LUA_REGISTRYINDEX, refL);
        if(lua_pcall(lua, 0, 0, 0) != 0) {
            printf("Failed to call the callback!\n %s\n", lua_tostring(lua, -1)); // TODO: Log to HS log?
            return;
        }
    }
}

// TODO: This hook to kick it off, could potentially move if needed? Or maybe we should of done a singleton pattern initialized by LuaScriptInit instead of passing the object back to LuaScriptInit and getting it from the global context there?
HOOK_METHOD(AchievementTracker, LoadAchievementDescriptions, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> AchievementTracker::LoadAchievementDescriptions -> Begin (LuaLibScript.cpp)\n")
    super();
    Global::GetInstance()->getLuaContext()->getLibScript()->call_on_load_callbacks();
}

HOOK_METHOD(ScoreKeeper, LoadGame, (int fh) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ScoreKeeper::LoadGame -> Begin (LuaLibScript.cpp)\n")
    super(fh);
    // TODO: Probably need LoadGame, Opening the ship editor & game restart hooks to all call this
    // TODO: Or maybe we can use StarMap::NewGame ?
    Global::GetInstance()->getLuaContext()->getLibScript()->call_on_init_callbacks();
}

static const struct luaL_Reg slib_funcs[] = {
   { "on_load", LuaLibScript::l_on_load },
   { "on_init", LuaLibScript::l_on_init },
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
