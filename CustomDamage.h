#pragma once
#include "CrewSpawn.h"
#include "StatBoost.h"
#include "Global.h"

struct StatBoostDefinition;

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
    bool ionBeamFix = false;

    std::vector<StatBoostDefinition*> statBoosts;

    int erosionChance = 0;
    ErosionEffect erosionEffect;

    int crewSpawnChance = -1;
    std::vector<CrewSpawn> crewSpawns;

    ~CustomDamage()
    {

    }
};




class CustomDamageManager
{
public:
    static CustomDamage* currentWeaponDmg;
    static Projectile* currentProjectile;
};
