#include "System_Extend.h"
#include "CustomCrew.h"


HOOK_METHOD_PRIORITY(ShipSystem, constructor, 900, (int systemId, int roomId, int shipId, int startingPower) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> ShipSystem::constructor -> Begin (System_Extend.cpp)\n")
	super(systemId, roomId, shipId, startingPower);

	auto ex = new ShipSystem_Extend();


    uintptr_t dEx = (uintptr_t)ex;

#ifdef __amd64__
    gap_ex_1[2] = (dEx >> 56) & 0xFF;
    gap_ex_1[3] = (dEx >> 48) & 0xFF;
    gap_ex_2[2] = (dEx >> 40) & 0xFF;
    gap_ex_2[3] = (dEx >> 32) & 0xFF;
#endif // __amd64__
	gap_ex_1[0] = (dEx >> 24) & 0xFF;
	gap_ex_1[1] = (dEx >> 16) & 0xFF;
	gap_ex_2[0] = (dEx >> 8) & 0xFF;
	gap_ex_2[1] = dEx & 0xFF;
	ex->orig = this;

    HS_MAKE_TABLE(this)

    //Set up proper defaults for systemBox offsets
    switch (systemId)
    {
        //Armament systems
        case SYS_WEAPONS:
        case SYS_DRONES:
        {
            ex->xOffset = 48;
            break;
        }
        //Button systems
        case SYS_MIND:
        case SYS_HACKING:   
        case SYS_CLOAKING:
        case SYS_TELEPORTER:
        case SYS_TEMPORAL:
        case SYS_BATTERY:
        {
            ex->xOffset = 54;
            break;
        }
        
        //Basic systems
        case SYS_ARTILLERY:
        case SYS_CLONEBAY:
        case SYS_MEDBAY:
        case SYS_SHIELDS:
        case SYS_ENGINES:
        case SYS_OXYGEN:
        case SYS_PILOT:
        case SYS_SENSORS:
        {
            ex->xOffset = 36;
            break;
        }
        //Special case
        case SYS_DOORS:
        {
            ex->xOffset = 51;
            break;
        }
    
        //Custom systems are set via lua callback but this is present for in case the user forgets to set it
        default:
        {
            ex->xOffset = 36;
            break;
        }
    }

    //Push base class data only, to avoid garbage data (Derived class constructor not yet called)
    auto context = G_->getLuaContext();
    SWIG_NewPointerObj(context->GetLua(), this, context->getLibScript()->types.pShipSystem, 0);
    context->getLibScript()->call_on_internal_event_callbacks(InternalEvents::CONSTRUCT_SHIP_SYSTEM, 1);
    lua_pop(context->GetLua(), 1);
}

HOOK_METHOD_PRIORITY(ShipSystem, destructor, 900, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> ShipSystem::destructor -> Begin (System_Extend.cpp)\n")
    HS_BREAK_TABLE(this)
	delete SYS_EX(this);
    super();
}

ShipSystem_Extend* Get_ShipSystem_Extend(ShipSystem* c)
{
    uintptr_t dEx = 0;
#ifdef __amd64__
    dEx <<= 8;
    dEx |= c->gap_ex_1[2];
    dEx <<= 8;
    dEx |= c->gap_ex_1[3];
    dEx <<= 8;
    dEx |= c->gap_ex_2[2];
    dEx <<= 8;
    dEx |= c->gap_ex_2[3];
#endif // __amd64__
    dEx <<= 8;
    dEx |= c->gap_ex_1[0];
    dEx <<= 8;
    dEx |= c->gap_ex_1[1];
    dEx <<= 8;
    dEx |= c->gap_ex_2[0];
    dEx <<= 8;
    dEx |= c->gap_ex_2[1];

    return (ShipSystem_Extend*)dEx;
}
