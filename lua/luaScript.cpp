// TODO: Might be wise to rename this file, it's lua "Script" object library for FTL Hyperspace, not a specific script. Maybe luaLibScript.h?

#include "LuaScriptInit.h" // TODO: Is this needed since we import luaScript.h from LuaScriptInit.cpp?
#include <string>
#include <assert.h>
#include "../Global.h"

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

 /*** Log a message to the Hyperspace log file & standard out
 * @function log
 * @tparam string msg Message string you would like to log
 *
 * Lua's `print` still works but it will only log to standard out (the console/terminal) which might not be accessible for logging depending on how you're running FTL
 * This method dumps both to standard out & writes the message into the `ftl_hs.log` file.
 */
 
 static const struct luaL_Reg slib_funcs[] = {
    { "onload", LuaScript::l_onload },
    { NULL, NULL }
 };
 
 static int luaopen_scriptlib(lua_State* lua)
 {
    luaL_newlib(lua, slib_funcs);
    return 1;
 }
 
 LuaScript::LuaScript(lua_State* lua)
 {
    this->m_Lua = lua;
    luaL_requiref(lua, "script", luaopen_scriptlib, 1);
 }
