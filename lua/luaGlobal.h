#ifndef LUAGLOBAL_H_INCLUDED
#define LUAGLOBAL_H_INCLUDED

#include "luaInclude.h"
#include "Global.h"
#include <string>
#include <assert.h>
#include <boost/algorithm/string.hpp>
#include <boost/format.hpp>
#include "CommandConsole.h"

/*** Functions available outside a module
 * @module global
 * These functions are available globally and are not within another specific module
 * They can be accessed without any prefix
 *
 * Please note *some* but not all of Lua's basic functions are available see [Lua 5.3 Docs - Section 6.1 Basic Functions](https://www.lua.org/manual/5.3/manual.html#6.1) for a list of all of them
 *#### Disabled Methods
 * Specifically the following basic methods are **disabled**:
 *
 * - `collectgarbage`
 * - `dofile`
 * - `load`
 * - `loadfile`
 *
 * Please see the Disabled Features topic for a list of other things disabled because of non-loaded libraries
 */

 /*** Log a message to the Hyperspace log file & standard out
 * @function log
 * @tparam string msg Message string you would like to log
 *
 * Lua's `print` still works but it will only log to standard out (the console/terminal) which might not be accessible for logging depending on how you're running FTL
 * This method dumps both to standard out & writes the message into the `ftl_hs.log` file.
 */
static int hslua_g_printMessage(lua_State* lua)
{
    std::string message = std::string();
    int argCount = lua_gettop(lua);
    lua_getglobal(lua, "tostring");
    for (int i = 1; i <= argCount; i++)
    {
        lua_pushvalue(lua, -1);
        lua_pushvalue(lua, i);
        lua_call(lua, 1, 1);
        const char* str = lua_tostring(lua, -1);
        if (str == NULL)
        {
            return luaL_error(lua, "'tostring' must return a string to 'log'");
        }
        
        message += str;
        message += "    ";
        lua_pop(lua, 1);
    }
    message = boost::str(boost::format("[Lua]: %s\n") % message);
    printf("%s", message.c_str());
    hs_log_file("%s", message.c_str());
    return 0;
}

static int hslua_g_printToScreen(lua_State* lua)
{
    std::string message = std::string();
    int argCount = lua_gettop(lua);
    lua_getglobal(lua, "tostring");
    for (int i = 1; i <= argCount; i++)
    {
        lua_pushvalue(lua, -1);
        lua_pushvalue(lua, i);
        lua_call(lua, 1, 1);
        const char* str = lua_tostring(lua, -1);
        if (str == NULL)
        {
            return luaL_error(lua, "'tostring' must return a string to 'print'");
        }
        
        message += str;
        message += "    ";
        lua_pop(lua, 1);
    }
    PrintHelper::GetInstance()->AddMessage(message);
    message = boost::str(boost::format("[Lua]: %s\n") % message);
    printf("%s", message.c_str());
    hs_log_file("%s", message.c_str());
    return 0;
}

// TODO: Maybe restructure this as a class and have this be part of constructor?
// TODO: Or maybe constructor calls the global singleton of LuaScriptInit instance and gets the lua state?
void hsluaglobal_register(lua_State* lua)
{
    lua_register(lua, "log", hslua_g_printMessage);
    lua_register(lua, "print", hslua_g_printToScreen);
}

#endif // LUAGLOBAL_H_INCLUDED
