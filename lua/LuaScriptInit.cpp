#include "LuaScriptInit.h"
#include <string>
#include "luaGlobal.h"

/*
    TODO Stuff
    - Have a `global_run` (or `global`) table that contents is saved with the run (functions not allowed to be inserted into the table, data only)
    - Have a `profile` (or `global_profile`) table that contents is saved across runs (functions not allowed, data only)
    - Add serpent library to allow easy printing of Lua tables with `serpent.block()` for debugging for developers of Lua scripts
    - Add a print function to write messages to the in-game screen like a chat/console
    - Implement table_size() like Factorio does for tables with non-contiguous keys.?
    - Maybe add abilitly to pull localized string?
    - Re-implement require to load only .lua files from the dat, or maybe re-enable lua package (which contains require) and figure out how to restrict it.
    - Re-implement math.random to use FTL's random. (might want to use FTL's (SIL's) frandom)
    - Maybe add a story system like https://wiki.factorio.com/Tutorial:Scripting#Story_script ?
*/
void removeDangerousStuff(lua_State* lua)
{
    /* Remove the basic functions (if they're not removed already) of these:
        - collectgarbage
        - dofile
        - load
        - loadfile
        - newproxy (but might allow if really needed)
        - Since they bypass metatables, but maybe we'll allow these if needed:
          - rawequal
          - rawget
          - rawset
    */
    lua_pushnil(lua);
    lua_setglobal(lua, "collectgarbage");
    lua_pushnil(lua);
    lua_setglobal(lua, "dofile");
    lua_pushnil(lua);
    lua_setglobal(lua, "load");
    lua_pushnil(lua);
    lua_setglobal(lua, "loadfile");
    lua_pushnil(lua);
    lua_setglobal(lua, "newproxy");
    lua_pushnil(lua);
    lua_setglobal(lua, "rawequal");
    lua_pushnil(lua);
    lua_setglobal(lua, "rawget");
    lua_pushnil(lua);
    lua_setglobal(lua, "rawset");

    lua_getglobal(lua, "math");
    lua_pushnil(lua);
    lua_setfield(lua, -2, "randomseed");
    lua_pushnil(lua);
    lua_setfield(lua, -2, "random");
    lua_pop(lua, 1); // remove math table from stack
}
    /* TODO: Replace math.random with call to FTL's random32
    math.random ([m [, n]])
When called without arguments, returns a pseudo-random float with uniform distribution in the range [0,1). When called with two integers m and n, math.random returns a pseudo-random integer with uniform distribution in the range [m, n]. (The value n-m cannot be negative and must fit in a Lua integer.) The call math.random(n) is equivalent to math.random(1,n).

This function is an interface to the underling pseudo-random generator function provided by C.
*/

LuaScriptInit::LuaScriptInit()
{
    printf("Initializing Lua\n");
    lua_State* lua = luaL_newstate(); // Open Lua
    this->SetLua(lua);
    luaL_openlibs(lua); // Load Lua libraries (we restricted what libraries can load in linit.c)

    hsluaglobal_register(lua);
    this->m_libScript = new LuaLibScript(lua);
    luaopen_Hyperspace(lua);
    luaopen_Graphics(lua);
    luaopen_Defines(lua);
    luaopen_Saving(lua);
    removeDangerousStuff(lua);

    this->m_libScript->LoadTypeInfo(); // Preload all the SWIG typedata so we don't need to do it every time we want to push a class for a callback

    printf("Lua initialized!\n");
}

void LuaScriptInit::runLuaString(std::string code)
{
    int iErr = 0;
    if((iErr = luaL_loadbufferx(this->m_Lua, code.c_str(), code.size(), "=luaConsole", "t")) != 0)
    {
        const char* errorMessage = lua_tostring(this->m_Lua, -1);
        hs_log_file("Failed to load lua code from in-game console. Error: '%s'\n", errorMessage);
        ErrorMessage(errorMessage);
        lua_pop(this->m_Lua, 1);
        return;
    }
    // call Lua's Main from the script loaded above
    if((iErr = lua_pcall(this->m_Lua, 0, LUA_MULTRET, 0)) != 0)
    {
        const char* errorMessage = lua_tostring(this->m_Lua, -1);
        hs_log_file("in-game console lua execution failed. Error: '%s'\n", errorMessage);
        ErrorMessage(errorMessage);
        lua_pop(this->m_Lua, 1);
        return;
    }
}

void LuaScriptInit::runLuaFileFromDat(std::string filename)
{
    // TODO: Check the end of the filename to make sure it's .lua
    hs_log_file("Loading Lua file: %s\n", filename.c_str());
    char* code = Global::GetInstance()->GetResources()->LoadFile(filename);
    //printf("Lua file loaded: %s, contents: '%s'\n", filename.c_str(), code);

    int iErr = 0;
    if((iErr = luaL_loadbufferx(this->m_Lua, code, strlen(code), filename.c_str(), "t")) != 0) // the "t" with loadbufferx means text chunks only, default is "bt" but that would allow loading binary lua files, while cool, could be bad.
    {
        const char* errorMessage = lua_tostring(this->m_Lua, -1);
        hs_log_file("Failed to load lua code from file '%s'. Error: '%s'\n", filename.c_str(), errorMessage);
        ErrorMessage(errorMessage);
        lua_pop(this->m_Lua, 1);
        return;
    }
    // call Lua's Main from the script loaded above
    if((iErr = lua_pcall(this->m_Lua, 0, LUA_MULTRET, 0)) != 0)
    {
        const char* errorMessage = lua_tostring(this->m_Lua, -1);
        hs_log_file("Lua execution failed in file '%s'. Error: '%s'\n", filename.c_str(), errorMessage);
        ErrorMessage(errorMessage);
        lua_pop(this->m_Lua, 1);
        return;
    }
}
