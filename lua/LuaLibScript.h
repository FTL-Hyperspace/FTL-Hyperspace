#ifndef LUALIBSCRIPT_H
#define LUALIBSCRIPT_H

#include "luaInclude.h"
#include "InternalEvents.h"
#include "RenderEvents.h"
#include <assert.h>
#include <string>
#include <algorithm>

typedef struct swig_type_info swig_type_info;

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

        // Call during initialization to load the type info
        void LoadTypeInfo();

        // Call once upon starting the game
        void call_on_load_callbacks();

        // Call upon starting a new run and loading a saved run
        void call_on_init_callbacks(bool newGame);

        int call_on_internal_event_callbacks(InternalEvents::Identifiers, int nArg=0, int nRet=0);
        bool call_on_internal_chain_event_callbacks(InternalEvents::Identifiers, int nArg=0, int nRet=0);

        int call_on_render_event_pre_callbacks(RenderEvents::Identifiers, int nArg);
        void call_on_render_event_post_callbacks(RenderEvents::Identifiers, int idx, int nArg);

        void call_on_game_event_callbacks(std::string eventName, bool isLoading);

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

        /*** Register a function to call upon a specific internal event being called
         * @function on_internal_event
         * @tparam string event Event name/identifier to hook, see @{Defines.InternalEvents} table for a full list of currently supported events.
         * @tparam function callback Callback function to register
         *
         * Your function will be called upon the specified event being triggered inside the game
         * **These are internal events** not events as described in XML files, so these are events like functions internal to the game
         * (like ship loading) and not events as in popups or encounters in the game. You can think of these as game engine events.
         * See @{on_game_event} for hooking gameplay events.
         *
         * Functions will be called in the order they are registered.
         * **Warning:** you can accidentally register your function multiple times and it will be called multiple times!
         */
        static int l_on_internal_event(lua_State* lua);

        /*** Register a function to call upon a specific render event being called
         * @function on_render_event
         * @tparam string event Event name/identifier to hook, see @{Defines.RenderEvents} table for a full list of currently supported events.
         * @tparam function before_callback Callback function to register for before the render event (such as for setting up a matrix transform)
         * @tparam function after_callback Callback function to register for after the render event (such as for cleaning up a matrix transform)
         *
         * Your function will be called upon the specified render stage event being triggered inside the game
         * **These are internal rendering functions** not events as described in XML files, so these are events like functions internal to the game
         * (like onSpaceBackgroundRender) and not events as in popups or encounters in the game. You can think of these as game engine events.
         * See @{on_game_event} for hooking gameplay events.
         * See @{on_internal_event} for hooking other internal events that are not for graphics rendering, like ship loading or something.
         *
         * Functions will be called in the order they are registered.
         * **Warning:** you can accidentally register your function multiple times and it will be called multiple times!
         */
        static int l_on_render_event(lua_State* lua);

        /***
         * @function on_game_event
         * @tparam string event name in XML, can only hook to named events (includes choices)
         * @tparam bool onLoad false to run only on initial encounter of the event, true to run if someone saves & continues at the event (such as to setup backgrounds or other basic needs)
         * @tparam function callback Callback function to register, will not receive any arguments
         */
        static int l_on_game_event(lua_State* lua);

    protected:

    private:
        lua_State* m_Lua;

    public:
        struct TypeInfo
        {
            swig_type_info *pActivatedPower;
            swig_type_info *pActivatedPowerResource;
            swig_type_info *pActivatedPowerRequirements;
            swig_type_info *pCollideable;
            swig_type_info *pCollisionResponse;
            swig_type_info *pCrewMember;
            swig_type_info *pDamage;
            swig_type_info *pPointf;
            swig_type_info *pProjectile[7]; // Projectile::GetType() can be used to index this array to get the correct derived class (except for CrewLaser)
            swig_type_info *pProjectileFactory;
            swig_type_info *pShip;
            swig_type_info *pShipBlueprint;
            swig_type_info *pShipEvent;
            swig_type_info *pShipManager;
            swig_type_info *pShipSystem;
            swig_type_info *pWeaponSystem;
            swig_type_info *pDroneSystem;
            swig_type_info *pWeaponBlueprint;
            swig_type_info *pRoom;
            swig_type_info *pChoiceBox;
            swig_type_info *pLocationEvent;

            swig_type_info *pShipSystemTypes[21];
            swig_type_info *pSpaceDrone;
            swig_type_info *pSpaceDroneTypes[8];
        };

        TypeInfo types;

        swig_type_info *GetShipSystemType(int id)
        {
            if (id >= 0 && id < 21) return types.pShipSystemTypes[id];
            return types.pShipSystem;
        }
};

#endif // LUALIBSCRIPT_H
