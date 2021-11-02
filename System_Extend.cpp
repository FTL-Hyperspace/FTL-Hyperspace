#include "System_Extend.h"
#include "CustomCrew.h"


HOOK_METHOD_PRIORITY(ShipSystem, constructor, 900, (int systemId, int roomId, int shipId, int startingPower) -> void)
{
	super(systemId, roomId, shipId, startingPower);

	auto ex = new ShipSystem_Extend();


    uint32_t dEx = (uint32_t)ex;

	gap_ex_1[0] = (dEx >> 24) & 0xFF;
	gap_ex_1[1] = (dEx >> 16) & 0xFF;
	gap_ex_2[0] = (dEx >> 8) & 0xFF;
	gap_ex_2[1] = dEx & 0xFF;
	ex->orig = this;
}

ShipSystem_Extend* Get_ShipSystem_Extend(ShipSystem* c)
{
    uint32_t dEx = 0;
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
