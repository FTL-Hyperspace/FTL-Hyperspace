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

        // Call once upon starting the game
        void call_on_load_callbacks();

        // Call upon starting a new run (maybe also starting a loaded run? not sure)
        void call_on_init_callbacks();
        
        /*** Register a function to call upon loading your script
         * @function on_load
         * @tparam function callback Callback function to register
         *
         * Your function will be called once upon loading the game (not upon starting a new run use @{on_init} for that)
         *
         * Functions will be called in the order they are registered, lua entry scripts are executed in the order they are defined
         * in the hyperspace.xml, so if your mod was defined before another in Slipstream it'll load before the other mod.
         *
         * **Warning:** you can accidentally register your function multiple times and it will be called multiple times!
         *
         * Actually currently runs on `AcheivementTracker::LoadAchievementDescriptions` (right after most of Hyperspace initalizes XML stuff)
         *
         * @usage 
         * function myModInitializationCode()
         *   log("My code was run after the game started")
         *   if not _G["myModLoaded"] then
         *     _G["myModLoaded"] = true
         *   end
         *   -- Assuming "OtherMod" defines a global "otherModLoaded" value just like how
         *   -- "MyMod" declared a "myModLoaded" here, we can see if their code has already run.
         *   -- This is not a HS feature, it's up to other mods to do something like this.
         *   if not _G["otherModLoaded"] then
         *     warningWindow("Warning! MyMod depends on OtherMod!")
         *   end
         * end
         *
         * script.on_load(myModInitializationCode)
         */
        static int l_on_load(lua_State* lua);
        
        /*** Register a function to call upon starting a run
         * @function on_init
         * @tparam function callback Callback function to register
         *
         * Your function will be called once upon starting a new run (and/or loading a run)
         *
         *
         * Functions will be called in the order they are registered, lua entry scripts are executed in the order they are defined
         * in the hyperspace.xml, so if your mod was defined before another in Slipstream it'll load before the other mod.
         *
         * **Warning:** you can accidentally register your function multiple times and it will be called multiple times!
         *
         * Currently happens on `ScoreKeeper::LoadGame` so you might need to check if your values are already initialized in your code
         */
        static int l_on_init(lua_State* lua);

    protected:

    private:
        lua_State* m_Lua;
};

#endif // LUALIBSCRIPT_H
