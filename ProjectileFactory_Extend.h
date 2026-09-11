#pragma once
#include "FTLGame.h"

struct ProjectileFactory_Extend
{
    ProjectileFactory *orig;
    const WeaponBlueprint *detachedBlueprint = nullptr;

    ~ProjectileFactory_Extend()
    {
        if (this->detachedBlueprint) {
            if (this->orig && this->orig->blueprint == this->detachedBlueprint) {
                this->orig->blueprint = nullptr;
            }
            delete this->detachedBlueprint;
        }
    }
};

ProjectileFactory_Extend* Get_ProjectileFactory_Extend(ProjectileFactory* c);

#define PF_EX Get_ProjectileFactory_Extend
