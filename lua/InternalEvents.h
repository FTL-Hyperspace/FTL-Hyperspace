#ifndef INTERNALEVENTS_H
#define INTERNALEVENTS_H

/**
    Internal Event enumerations
    Used for specifying a name to Lua that Lua can access via `Defines.InternalEvents.ON_TICK` (or other name in the Defines.InternalEvents table)
    And for specifying a name to C in our hooks (defined in InternalEvents.cpp right now but they could technically be called from anywhere)
    Eventually will include argument data for Lua to specify what we expect to send to and receive from Lua hooks

    You can have more than one actual C ZHL hook calling the same identifier (such as we would do for START_RUN, although currently that is handled by `scripts.on_init(` but maybe we accomplish that with an internal event instead and clean it up)
*/
struct InternalEvents
{
    enum Identifiers {
        UNKNOWN, // Must always be first, used to check for bounds of enum input value

        ON_TICK, // We'll use CApp::OnLoop for this ticking
        MAIN_MENU, // We'll use MainMenu::Open for this
        ON_KEY_DOWN, // CApp::OnKeyDown (Once we have arguments working since this will require passing the SDLKey that was pressed)
        CREW_LOOP,

        PROJECTILE_PRE,
        PROJECTILE_POST,
        PROJECTILE_UPDATE_PRE,
        PROJECTILE_UPDATE_POST,

        DRONE_COLLISION,
        PROJECTILE_COLLISION,
        SHIELD_COLLISION_PRE,
        SHIELD_COLLISION,


        // CREW_EQUIPMENT_BOX_REMOVE_ITEM, // CrewEquipBox::RemoveItem

        /*
        Once we support return values from InternalEvents (or maybe this moves to an InternalHooks in the future)
        Called upon hull damage to the player's ship
        @tparam int shipId the ID of the ship for now...
        @tparam int damage intended hull damage, negative values infer healing
        @treturn uint value of the hull, 0 and the ship explodes.
        // PLAYERSHIP_ON_HULL_DAMAGE,
        */

        /* TODO Maybe add
        ShipManager::JumpArrive
        ShipManager::JumpLeave
        */

        UNKNOWN_MAX // Must always be last, used to check for bounds of enum input value
    };
};

// TODO: Maybe we store an array using the Identifiers as the index and store the additional call data in there? Like number of arguments etc...?
/* Example
// NOTE: Should exclude/ignore this from Lua (defines.i) so that the CallData is not available
struct InternalEvent_CallData {
    unsigned int argCount;
    bool isVariableArgs;
}
static InternalEvent_CallData CallData[InternalEvents::UNKNOWN_MAX - 1];
CallData[ON_TICK] = { 0, false };
};
*/

struct Chain
{
    enum ChainValues {
        CONTINUE,
        HALT,
        PREEMPT
    };
};

#endif // INTERNALEVENTS_H
