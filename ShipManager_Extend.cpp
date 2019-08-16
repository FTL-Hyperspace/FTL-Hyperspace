#include "ShipManager_Extend.h"


HOOK_METHOD_PRIORITY(ShipManager, constructor, 2000, (int iShipId) -> void)
{


	super(iShipId);

	auto ex = new ShipManager_Extend();

    DWORD dEx = (DWORD)ex;

	this->gap_ex_1[0] = (dEx >> 24) & 0xFF;
	this->gap_ex_1[1] = (dEx >> 16) & 0xFF;
	this->gap_ex_2[0] = (dEx >> 8) & 0xFF;
	this->gap_ex_2[1] = dEx & 0xFF;
	ex->orig = this;


	auto test = SM_EX(this);

}

ShipManager_Extend* Get_ShipManager_Extend(ShipManager* c)
{\
    DWORD dEx = 0;
    dEx <<= 8;
    dEx |= c->gap_ex_1[0];
    dEx <<= 8;
    dEx |= c->gap_ex_1[1];
    dEx <<= 8;
    dEx |= c->gap_ex_2[0];
    dEx <<= 8;
    dEx |= c->gap_ex_2[1];

    return (ShipManager_Extend*)dEx;
}
