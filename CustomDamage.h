#pragma once
#include "CrewMember_Extend.h"
#include "Global.h"

#include "LuaScriptInit.h"

#include "swigluarun.h"

struct RoomAnimDef;
struct StatBoostDefinition;

struct ErosionEffect
{
    float erosionSpeed = 0.63f;
    float erosionSpeedMax = 3.15f;

    float systemRepairMultiplier = 0.75f;

    float erosionTime = 10.f;
    float erosionTimeMax = 25.f;

    bool erodeShields = false;

    RoomAnimDef *animation = nullptr;

    void ParseErosionEffect(rapidxml::xml_node<char>* node);

    static float growBreachMultiplier;
    static float newBreachDamage;
    static float newBreachRequirement;
    static bool canDilate;

    static ErosionEffect defaultErosionEffect;
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

    int erosionChance = -1;
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
