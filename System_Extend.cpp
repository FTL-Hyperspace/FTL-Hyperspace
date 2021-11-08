#include "System_Extend.h"
#include "CustomCrew.h"


HOOK_METHOD_PRIORITY(ShipSystem, constructor, 900, (int systemId, int roomId, int shipId, int startingPower) -> void)
{
	super(systemId, roomId, shipId, startingPower);

	auto ex = new ShipSystem_Extend();


    DWORD dEx = (DWORD)ex;

	gap_ex_1[0] = (dEx >> 24) & 0xFF;
	gap_ex_1[1] = (dEx >> 16) & 0xFF;
	gap_ex_2[0] = (dEx >> 8) & 0xFF;
	gap_ex_2[1] = dEx & 0xFF;
	ex->orig = this;
}

HOOK_METHOD_PRIORITY(ShipSystem, destructor, 900, () -> void)
{
	delete SYS_EX(this);
    super();
}

ShipSystem_Extend* Get_ShipSystem_Extend(ShipSystem* c)
{
    DWORD dEx = 0;
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
