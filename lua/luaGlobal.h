#ifndef LUAGLOBAL_H_INCLUDED
#define LUAGLOBAL_H_INCLUDED

#include "luaInclude.h"
#include "../Global.h"
#include <string>
#include <assert.h>
#include <boost/algorithm/string.hpp>
#include <boost/format.hpp>

/*** Functions available outside a module
 * @module Global
 * @release 1.1.0
 * @author Mr. Doom
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
    assert(lua_isstring(lua, 1));
    const char* msg = lua_tostring(lua, 1);
    const char* logMessage = boost::str(boost::format("[Lua]: %s\n") % msg).c_str();
    printf(logMessage);
    hs_log_file(logMessage);
    return 0;
}

// TODO: Maybe restructure this as a class and have this be part of constructor?
// TODO: Or maybe constructor calls the global singleton of LuaScriptInit instance and gets the lua state?
void hsluaglobal_register(lua_State* lua)
{
    lua_register(lua, "log", hslua_g_printMessage);
}

#endif // LUAGLOBAL_H_INCLUDED
