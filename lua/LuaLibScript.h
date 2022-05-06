#ifndef LUALIBSCRIPT_H
#define LUALIBSCRIPT_H

#include "luaInclude.h"
#include <assert.h>

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
        
        void call_on_load_callbacks(); // TODO: Change to loadGameCallCallbacks or something
        
        /*** Register a function to call upon loading your script
         * @function on_load
         * @tparam function callback Callback function to register
         *
         * Your function will be called once upon loading the game (not upon starting a new run use @{on_init} for that)
         *
         * **Warning:** you can accidentally register your function multiple times and it will be called multiple times!
         *
         * Actually currently runs on `AcheivementTracker::LoadAchievementDescriptions` (right after most of Hyperspace initalizes XML stuff)
         */
        static int l_on_load(lua_State* lua);
        
        /*** Register a function to call upon starting a run
         * @function on_init
         * @tparam function callback Callback function to register
         *
         * Your function will be called once upon starting a new run (it is not yet complete as to if this will also call upon loading/continuing a run)
         *
         * **Warning:** you can accidentally register your function multiple times and it will be called multiple times!
         */
        static int l_on_init(lua_State* lua);

    protected:

    private:
        lua_State* m_Lua;
};

#endif // LUALIBSCRIPT_H
