#ifndef BP_EX
#include "FTLGame.h"

struct WeaponBlueprint_Data
{
    bool rainbow = false;
    AnimationTracker* rainbowTracker;
};

struct Blueprint_Extend
{
public:
    WeaponBlueprint_Data* weapon;

    Blueprint *orig;
};

Blueprint_Extend* Get_Blueprint_Extend(const Blueprint* c);

#define BP_EX Get_Blueprint_Extend
#endif
