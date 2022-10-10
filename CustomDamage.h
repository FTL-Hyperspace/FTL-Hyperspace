#pragma once
#include "CrewMember_Extend.h"
#include "Global.h"

#include "LuaScriptInit.h"

#include "swigluarun.h"

struct StatBoostDefinition;

struct ErosionEffect
{
    float systemDamageSpeed = 0.8f;
    float systemRepairMultiplier = 0.75f;
    int erosionTime = 10;
    std::string animation = "room_erosion";
};

struct CrewSpawn;

struct CustomDamageDefinition
{
    int idx = 0;

    int accuracyMod = 0;
    int droneAccuracyMod = 0;

    bool noSysDamage = false;
    bool noPersDamage = false;
    bool ionBeamFix = false;

    int statBoostChance = -1;
    int roomStatBoostChance = -1;
    std::vector<StatBoostDefinition*> statBoosts;
    std::vector<StatBoostDefinition*> roomStatBoosts;

    int erosionChance = 0;
    ErosionEffect erosionEffect;

    int crewSpawnChance = -1;
    std::vector<CrewSpawn*> crewSpawns;

    ~CustomDamageDefinition()
    {

    }

    static std::vector<CustomDamageDefinition*> customDamageDefs;
    static CustomDamageDefinition defaultDef;

    void GiveId()
    {
        idx = customDamageDefs.size();
        customDamageDefs.push_back(this);
    }
};

struct CustomDamage
{
    CustomDamageDefinition *def;

    int sourceShipId = -1;
    int accuracyMod = 0;
    int droneAccuracyMod = 0;

    CustomDamage() : def(&CustomDamageDefinition::defaultDef)
    {
    }

    void Clear()
    {
        def = &CustomDamageDefinition::defaultDef;
    }
};


class CustomDamageManager
{
public:
    static CustomDamage* currentWeaponDmg;
    static Projectile* currentProjectile;

    static void lua_PushCurrentProjectile(LuaScriptInit* context)
    {
        // Lua library: pushes the current projectile (or nil if there is none) with the correct type
        if (currentProjectile)
        {
            SWIG_NewPointerObj(context->GetLua(), currentProjectile, context->getLibScript()->types.pProjectile[currentProjectile->GetType()], 0);
        }
        else
        {
            lua_pushnil(context->GetLua());
        }
    }
};
