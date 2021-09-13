#pragma once
#include "FTLGame.h"

struct ErosionEffect
{
    float systemDamageSpeed = 0.8f;
    float systemRepairMultiplier = 0.75f;
    int erosionTime = 10;
    std::string animation = "room_erosion";
};

struct CrewSpawn;

struct CustomDamage
{
    int sourceShipId = -1;

    int accuracyMod = 0;

    bool noSysDamage = false;
    bool noPersDamage = false;

    int erosionChance = 0;
    ErosionEffect erosionEffect;

    //int crewSpawnChance = 0;
    //std::vector<CrewSpawn*> crewSpawns; // if I try to include CrewSpawn.h it says that some other random thing is not declared??

    ~CustomDamage()
    {
        //for (auto i : crewSpawns)
        //{
        //    delete i;
        //}
    }
};




class CustomDamageManager
{
public:
    static CustomDamage* currentWeaponDmg;
};
