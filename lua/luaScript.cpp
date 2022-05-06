// TODO: Might be wise to rename this file, it's lua "Script" object library for FTL Hyperspace, not a specific script. Maybe luaLibScript.h?

#include "LuaScriptInit.h" // TODO: Is this needed since we import luaScript.h from LuaScriptInit.cpp?
#include <string>
#include <assert.h>
#include "../Global.h"

#if _DISABLED_
/*** Functions for script execution control
 * @module script
 * @release 1.1.0
 * @author Mr. Doom
 * Functions related to script execution control
 */
class LuaScript
{
    public:
        LuaScript(lua_State* lua);
        virtual ~LuaScript();

        /*** Register a function to call upon loading your script
         @function onload
         @tparam function callback Callback function to register
         Your function will be called once upon loading the game (not upon starting a new run use @{oninit} for that)
         */
        static int l_onload(lua_State* lua) // TODO: Check if this can be called from private or protected by Lua, that would be ideal
        {
            printf("Hello World, l_onload was called!\n");
            // TODO: Allow registering a lua function into some shared internal state so we can call this on load
            return 0;
        }

    protected:

    private:
        lua_State* m_Lua;
};
#endif // _DISABLED_

/*** Register a function to call upon loading your script
 @function onload
 @tparam function callback Callback function to register
 Your function will be called once upon loading the game (not upon starting a new run use @{oninit} for that)
 */
static int l_hs_script_onload(lua_State* lua) // TODO: Check if this can be called from private or protected by Lua, that would be ideal
{
    printf("Hello World, l_onload was called!\n");
    // TODO: Allow registering a lua function into some shared internal state so we can call this on load
    return 0;
}
 
static const struct luaL_Reg slib_funcs[] = {
   { "onload", l_hs_script_onload },
   { NULL, NULL }
};
 
static int luaopen_scriptlib(lua_State* lua)
{
   luaL_newlib(lua, slib_funcs);
   return 1;
}

void hs_script_register(lua_State* lua)
{
   luaL_requiref(lua, "script", luaopen_scriptlib, 1);
}
 
 #if _DISABLED_
LuaScript::LuaScript(lua_State* lua)
{
   this->m_Lua = lua;
   luaL_requiref(lua, "script", luaopen_scriptlib, 1);
}
#endif
