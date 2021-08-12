#pragma once
#include "FTLGame.h"
#include "CustomDamage.h"

struct Projectile_Extend
{
    Projectile *orig;

    CustomDamage customDamage;

    ~Projectile_Extend()
    {

    }
};

Projectile_Extend* Get_Projectile_Extend(Projectile* c);

#define PR_EX Get_Projectile_Extend
