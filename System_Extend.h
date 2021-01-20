#pragma once
#include "FTLGame.h"

struct ShipSystem_Extend
{
public:
    ShipSystem *orig;

    int additionalPowerLoss;
    int oldPowerLoss;

private:
};

ShipSystem_Extend* Get_ShipSystem_Extend(ShipSystem* c);

#define SYS_EX Get_ShipSystem_Extend
