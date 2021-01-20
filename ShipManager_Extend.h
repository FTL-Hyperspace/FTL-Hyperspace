#pragma once
#include "FTLGame.h"


struct ShipManager_Extend
{
    ShipManager *orig;
    bool isNewShip = false;
    bool hasCustomDef = false;
    std::map<std::string, int> hiddenAugs = std::map<std::string, int>();

    std::map<std::string, int> GetAugmentList();

    void Initialize(bool restarting=false);

    ~ShipManager_Extend()
    {
    }

    //CrewMember *captain;
};

ShipManager_Extend* Get_ShipManager_Extend(ShipManager* c);

#define SM_EX Get_ShipManager_Extend
