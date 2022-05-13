#include "ScriptFPS.h"
#include <string.h>

#include "../../Global.h"

/* __index metamethod (stack: 1 = table instance, 2 = desired index/key (string) ) */
int ScriptFPS::lua_index(lua_State* lua) {
    assert(lua_istable(lua, 1));
    const char* index = luaL_checkstring(lua, 2);
    printf("Lua Index Loaded: %s\n", index);
    
    int retArgs = 0;
    if(strcmp(index, "SpeedFactor") == 0)
    {
        lua_pushnumber(lua, Global::GetInstance()->GetCFPS()->SpeedFactor);
        retArgs++;
    }
    return retArgs;
}

/* __newindex metamethod (stack: 1 = table instance, 2 = desired index/key (string), 3 = new desired value) */
int ScriptFPS::lua_newindex(lua_State* lua) {
    assert(lua_istable(lua, 1));
    const char* index = luaL_checkstring(lua, 2);
    printf("Calling __newindex on FPS\n");
    if(index == "SpeedFactor")
    {
        assert(lua_isnumber(lua, 3));
        const float arg = lua_tonumber(lua, 3);
        printf("Attempt to change SpeedFactor to: %f\n", arg);
        return 0;
    }
    else
    {
        printf("Error read-only table index: %s\n", index);
        return 0;
    }
    //assert(lua_isstring(lua, 1));
    //const char* msg = lua_tostring(lua, 1);
}

const luaL_Reg ScriptFPS::lib[] = {
    { "__index", ScriptFPS::lua_index },
    { "__newindex", ScriptFPS::lua_newindex },
    { NULL, NULL }
};

ScriptFPS::ScriptFPS(lua_State* lua)
{
    this->m_Lua = lua;
    /*
    lua_pushstring(lua, "__index");
    lua_pushcfunction(lua, ScriptFPS::lua_index);
    lua_rawset(lua, -3);
    lua_pushstring(lua, "__newindex");
    lua_pushcfunction(lua, ScriptFPS::lua_newindex);
    lua_rawset(lua, -3);
    lua_setmetatable(lua, -2);
    */
    luaL_newlib(lua, lib);
    lua_pushvalue(lua, -1);
    lua_pushvalue(lua, -2);
    lua_setmetatable(lua, -3);
    lua_setglobal(lua, "FPS"); // We could remove this an allow `ScriptFPS` to be initialized by a `require` maybe?
}

ScriptFPS::~ScriptFPS()
{
    //dtor
}
