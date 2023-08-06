#include "LuaScriptInit.h"
#include <string>
#include "luaGlobal.h"

/*
    TODO Stuff
    - Have a `global_run` (or `global`) table that contents is saved with the run (functions not allowed to be inserted into the table, data only)
    - Have a `profile` (or `global_profile`) table that contents is saved across runs (functions not allowed, data only)
    - Add serpent library to allow easy printing of Lua tables with `serpent.block()` for debugging for developers of Lua scripts
    - Implement table_size() like Factorio does for tables with non-contiguous keys.?
    - Maybe add abilitly to pull localized string?
    - Re-implement require to load only .lua files from the dat, or maybe re-enable lua package (which contains require) and figure out how to restrict it.
    - Maybe add a story system like https://wiki.factorio.com/Tutorial:Scripting#Story_script ?
*/

// Copied from https://www.lua.org/source/5.3/lmathlib.c.html and edited to use FTL's random32 instead

/*
** This function uses 'double' (instead of 'lua_Number') to ensure that
** all bits from 'random32' can be represented, and that 'RANDMAX + 1.0'
** will keep full precision (ensuring that 'r' is always less than 1.0.)
*/
static int math_random (lua_State *L) {
  lua_Integer low, up;
  double r = (double)random32() * (1.0 / ((double)2147483647 + 1.0));
  switch (lua_gettop(L)) {  /* check number of arguments */
    case 0: {  /* no arguments */
      lua_pushnumber(L, (lua_Number)r);  /* Number between 0 and 1 */
      return 1;
    }
    case 1: {  /* only upper limit */
      low = 1;
      up = luaL_checkinteger(L, 1);
      break;
    }
    case 2: {  /* lower and upper limits */
      low = luaL_checkinteger(L, 1);
      up = luaL_checkinteger(L, 2);
      break;
    }
    default: return luaL_error(L, "wrong number of arguments");
  }
  /* random integer in the interval [low, up] */
  luaL_argcheck(L, low <= up, 1, "interval is empty");
  luaL_argcheck(L, low >= 0 || up <= LUA_MAXINTEGER + low, 1,
                   "interval too large");
  r *= (double)(up - low) + 1.0;
  lua_pushinteger(L, (lua_Integer)r + low);
  return 1;
}

static int math_randomseed (lua_State *L) {
  srandom32((unsigned int)(lua_Integer)luaL_checknumber(L, 1));
  (void)random32(); /* discard first value to avoid undesirable correlations */
  return 0;
}


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
    lua_pushcfunction(lua, math_random);
    lua_setfield(lua, -2, "random");
    lua_pushcfunction(lua, math_randomseed);
    lua_setfield(lua, -2, "randomseed");
    lua_pop(lua, 1); // remove math table from stack
}


LuaScriptInit::LuaScriptInit()
{
    printf("Initializing Lua\n");
    lua_State* lua = luaL_newstate(); // Open Lua
    this->SetLua(lua);
    luaL_openlibs(lua); // Load Lua libraries (we restricted what libraries can load in linit.c)

    hsluaglobal_register(lua);
    this->m_libScript = new LuaLibScript(lua);
    luaopen_Hyperspace(lua);
    lua_pop(lua, 2);
    luaopen_Graphics(lua);
    lua_pop(lua, 2);
    luaopen_Defines(lua);
    lua_pop(lua, 2);
    luaopen_RapidXML(lua);
    lua_pop(lua, 2);
    removeDangerousStuff(lua);

    this->m_libScript->LoadTypeInfo(); // Preload all the SWIG typedata so we don't need to do it every time we want to push a class for a callback

    // set modified defaults for garbage collector
    lua_gc(lua, LUA_GCSETPAUSE, 100);

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

    int iErr = luaL_loadbufferx(this->m_Lua, code, strlen(code), filename.c_str(), "t");
    delete [] code;
    if(iErr != 0) // the "t" with loadbufferx means text chunks only, default is "bt" but that would allow loading binary lua files, while cool, could be bad.
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
