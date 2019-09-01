#include "FTLGame.h"


struct ShipManager_Extend
{
    ShipManager *orig;
    bool isCustomShip = false;
    //CrewMember *captain;
};

ShipManager_Extend* Get_ShipManager_Extend(ShipManager* c);

#define SM_EX Get_ShipManager_Extend
