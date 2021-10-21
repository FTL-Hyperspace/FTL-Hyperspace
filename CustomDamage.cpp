#include "Global.h"
#include "Projectile_Extend.h"
#include "CustomWeapons.h"
#include "CrewSpawn.h"
#include <boost/lexical_cast.hpp>

CustomDamage* CustomDamageManager::currentWeaponDmg = nullptr;

HOOK_METHOD(ShipManager, DamageArea, (Pointf location, DamageParameter dmgParam, bool forceHit) -> bool)
{
    //Damage* dmg = (Damage*)&dmgParam;
    bool ret = super(location, dmgParam, forceHit);

    if (ret)
    {
        auto custom = CustomDamageManager::currentWeaponDmg;

        if (custom && custom->sourceShipId != -1)
        {
            int rng = random32() % 10;

            if (rng < custom->crewSpawnChance)
            {
                for (auto& i : custom->crewSpawns)
                {
                    CrewSpawn::SpawnCrew(i, this, custom->sourceShipId != iShipId, location);
                }
            }
        }
    }

    return ret;
}

HOOK_METHOD(ShipManager, DamageBeam, (Pointf location1, Pointf location2, DamageParameter dmgParam) -> bool)
{
    //Damage* dmg = (Damage*)&dmgParam;
    bool ret = super(location1, location2, dmgParam);

    auto custom = CustomDamageManager::currentWeaponDmg;

    if (custom && custom->sourceShipId != -1 && custom->crewSpawnChance > 0)
    {
        Point grid1 = ShipGraph::TranslateToGrid(location1.x, location1.y);
        Point grid2 = ShipGraph::TranslateToGrid(location2.x, location2.y);

        if (grid1 != grid2)
        {
            int rng = random32() % 10;

            if (rng < custom->crewSpawnChance)
            {
                Pointf spawnLoc = {grid1.x * 35.0 + 17.5, grid1.y * 35.0 + 17.5};

                for (auto& i : custom->crewSpawns)
                {
                    CrewSpawn::SpawnCrew(i, this, custom->sourceShipId != iShipId, spawnLoc, true);
                }
            }
        }
    }

    return ret;
}

HOOK_METHOD(ShipManager, GetDodgeFactor, () -> int)
{
    int ret = super();

    if (CustomDamageManager::currentWeaponDmg != nullptr)
    {
        ret -= CustomDamageManager::currentWeaponDmg->accuracyMod;
    }

    return ret;
}

HOOK_METHOD_PRIORITY(ShipManager, DamageSystem, -100, (int roomId, DamageParameter dmgParam) -> void)
{
    if (CustomDamageManager::currentWeaponDmg != nullptr && CustomDamageManager::currentWeaponDmg->noSysDamage)
    {
        dmgParam.iSystemDamage -= dmgParam.iDamage;
    }

    super(roomId, dmgParam);
}

HOOK_METHOD_PRIORITY(ShipManager, DamageCrew, -100, (CrewMember *crew, DamageParameter dmgParameter) -> char)
{
    if (CustomDamageManager::currentWeaponDmg != nullptr)
    {
        if (CustomDamageManager::currentWeaponDmg->noPersDamage)
        {
            dmgParameter.iPersDamage -= dmgParameter.iDamage;
        }

        for (auto statBoostDef : CustomDamageManager::currentWeaponDmg->statBoosts)
        {
            StatBoost statBoost(statBoostDef);
            statBoost.sourceShipId = dmgParameter.ownerId;
            StatBoostManager::GetInstance()->CreateTimedAugmentBoost(statBoost, crew);
        }
    }

    return super(crew, dmgParameter);
}

HOOK_METHOD(ProjectileFactory, Update, () -> void)
{
    // This only works if every weapon has a definition, if that changes then replace with the commented code below.
    CustomWeaponManager::currentWeapon = CustomWeaponManager::instance->GetWeaponDefinition(blueprint->name);
    CustomDamageManager::currentWeaponDmg = &CustomWeaponManager::currentWeapon->customDamage;

    //auto def = CustomWeaponManager::instance->GetWeaponDefinition(blueprint->name)
    //if (def) CustomDamageManager::currentWeaponDmg = &def->customDamage;

    super();

    CustomWeaponManager::currentWeapon = nullptr;
    CustomDamageManager::currentWeaponDmg = nullptr;
}

HOOK_METHOD(Projectile, Initialize, (WeaponBlueprint& bp) -> void)
{
    super(bp);

    auto customDmg = CustomDamageManager::currentWeaponDmg;

    if (customDmg != nullptr)
    {
        PR_EX(this)->customDamage = *customDmg;
    }
}

HOOK_METHOD(Projectile, CollisionCheck, (Collideable *other) -> void)
{
    CustomDamageManager::currentWeaponDmg = &PR_EX(this)->customDamage;
    CustomDamageManager::currentWeaponDmg->sourceShipId = ownerId;

    super(other);

    CustomDamageManager::currentWeaponDmg = nullptr;
}

HOOK_METHOD(BeamWeapon, CollisionCheck, (Collideable *other) -> void)
{
    CustomDamageManager::currentWeaponDmg = &PR_EX(this)->customDamage;
    CustomDamageManager::currentWeaponDmg->sourceShipId = ownerId;

    super(other);

    CustomDamageManager::currentWeaponDmg = nullptr;
}

HOOK_METHOD(BombProjectile, CollisionCheck, (Collideable *other) -> void)
{
    CustomDamageManager::currentWeaponDmg = &PR_EX(this)->customDamage;
    CustomDamageManager::currentWeaponDmg->sourceShipId = ownerId;

    super(other);

    CustomDamageManager::currentWeaponDmg = nullptr;
}

HOOK_METHOD(PDSFire, CollisionCheck, (Collideable *other) -> void)
{
    CustomDamageManager::currentWeaponDmg = &PR_EX(this)->customDamage;
    CustomDamageManager::currentWeaponDmg->sourceShipId = ownerId;

    super(other);

    CustomDamageManager::currentWeaponDmg = nullptr;
}
