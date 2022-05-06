#ifndef LUALIBSCRIPT_H
#define LUALIBSCRIPT_H

#include "LuaScriptInit.h"
#include <string>
#include <assert.h>
#include "../Global.h"

/*** Functions for script execution control
 * @module script
 * @release 1.1.0
 * @author Mr. Doom
 * Functions related to script execution control
 */
class LuaLibScript
{
    public:
        LuaLibScript(lua_State* lua);
        
        /*** Register a function to call upon loading your script
         * @function onload
         * @tparam function callback Callback function to register
         *
         * Your function will be called once upon loading the game (not upon starting a new run use @{oninit} for that)
         */
        static int l_onload(lua_State* lua); // TODO: Check if this can be called from private or protected by Lua, that would be ideal

    protected:

    private:
        lua_State* m_Lua;
};

#endif // LUALIBSCRIPT_H
