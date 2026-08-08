#pragma once
#include "FTLGame.h"

struct ProjectileFactory_Extend
{
    ProjectileFactory *orig;
    bool cleanUpBlueprint = false;

    ~ProjectileFactory_Extend()
    {
        if (this->cleanUpBlueprint && this->orig) {
            delete this->orig->blueprint;
            this->orig->blueprint = nullptr;
        }
    }
};

ProjectileFactory_Extend* Get_ProjectileFactory_Extend(ProjectileFactory* c);

#define PF_EX Get_ProjectileFactory_Extend
