#pragma once
#include "FTLGame.h"

struct CustomDamage
{
    int timeDilation = 0;
    int accuracyMod = 100;
};




class CustomDamageManager
{
public:
    static CustomDamage* currentWeaponDmg;
};
