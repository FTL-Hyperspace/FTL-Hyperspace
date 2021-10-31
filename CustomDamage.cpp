#include "Global.h"
#include "Projectile_Extend.h"
#include "CustomWeapons.h"
#include "CrewSpawn.h"
#include <boost/lexical_cast.hpp>

CustomDamage* CustomDamageManager::currentWeaponDmg = nullptr;
Projectile* CustomDamageManager::currentProjectile = nullptr;

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
                Pointf spawnLoc = {grid1.x * 35.f + 17.5f, grid1.y * 35.f + 17.5f};

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

        int rng = random32() % 10;

        if (rng < CustomDamageManager::currentWeaponDmg->statBoostChance)
        {
            for (auto statBoostDef : CustomDamageManager::currentWeaponDmg->statBoosts)
            {
                StatBoost statBoost(statBoostDef);
                statBoost.sourceShipId = dmgParameter.ownerId;
                StatBoostManager::GetInstance()->CreateTimedAugmentBoost(statBoost, crew);
            }
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

HOOK_STATIC(ShipManager, CollisionMoving, (CollisionResponse &_ret, ShipManager *ship, Pointf pos1, Pointf pos2, DamageParameter damage, bool unk) -> CollisionResponse*)
{
    if (CustomDamageManager::currentWeaponDmg && CustomDamageManager::currentWeaponDmg->ionBeamFix && CustomDamageManager::currentProjectile)
    {
        BeamWeapon *proj = (BeamWeapon*) CustomDamageManager::currentProjectile; // ionBeamFix should only be used for beams
        if (proj->bDamageSuperShield)
        {
            return super(_ret, ship, pos1, pos2, damage, unk);
        }
        damage.iIonDamage = 0;
    }
    return super(_ret, ship, pos1, pos2, damage, unk);
}


//rewrite
HOOK_STATIC_PRIORITY(SpaceDrone, CollisionMoving, 9999, (CollisionResponse &_ret, SpaceDrone *drone, Pointf pos1, Pointf pos2, DamageParameter damage, bool unk) -> CollisionResponse*)
{
    _ret.collision_type = 0;
    _ret.point = {-2147483648.f, -2147483648.f};
    _ret.damage = 0;
    _ret.superDamage = 0;

    if (!drone->bDead && drone->deployed && !drone->explosion.tracker.running && pos2.RelativeDistance(drone->currentLocation) < 100.f)
    {
        Projectile_Extend *ex = nullptr;
        if (CustomDamageManager::currentProjectile)
        {
            ex = PR_EX(CustomDamageManager::currentProjectile);
            if (!ex->missedDrones.empty())
            {
                for (auto missedDrone : ex->missedDrones)
                {
                    if (missedDrone == drone)
                    {
                        return &_ret;
                    }
                }
            }
        }

        int dodgeFactor = drone->blueprint->dodge * 10;
        if (CustomDamageManager::currentWeaponDmg != nullptr)
        {
            dodgeFactor -= CustomDamageManager::currentWeaponDmg->accuracyMod;
        }

        if (random32()%100 < dodgeFactor) // miss
        {
            if (drone->powered)
            {
                delete drone->message;
                drone->message = new DamageMessage(1.0,drone->currentLocation,DamageMessage::MISS);
                if (ex) ex->missedDrones.push_back(drone);
                return &_ret;
            }
            _ret.collision_type = 1;
            if (damage.iIonDamage > 0)
            {
                return &_ret;
            }
        }
        else //hit
        {
            _ret.collision_type = 1;
            if (damage.iIonDamage > 0)
            {
                if (drone->powered)
                {
                    drone->ionStun = damage.iIonDamage * 5;
                }
                return &_ret;
            }
        }
        if (damage.iDamage > 0)
        {
            drone->BlowUp(false);
        }
    }

    return &_ret;
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
    CustomDamageManager::currentProjectile = this;

    super(other);

    CustomDamageManager::currentWeaponDmg = nullptr;
    CustomDamageManager::currentProjectile = nullptr;
}

HOOK_METHOD(BeamWeapon, CollisionCheck, (Collideable *other) -> void)
{
    CustomDamageManager::currentWeaponDmg = &PR_EX(this)->customDamage;
    CustomDamageManager::currentWeaponDmg->sourceShipId = ownerId;
    CustomDamageManager::currentProjectile = this;

    super(other);

    CustomDamageManager::currentWeaponDmg = nullptr;
    CustomDamageManager::currentProjectile = nullptr;
}

HOOK_METHOD(BombProjectile, CollisionCheck, (Collideable *other) -> void)
{
    CustomDamageManager::currentWeaponDmg = &PR_EX(this)->customDamage;
    CustomDamageManager::currentWeaponDmg->sourceShipId = ownerId;
    CustomDamageManager::currentProjectile = this;

    super(other);

    CustomDamageManager::currentWeaponDmg = nullptr;
    CustomDamageManager::currentProjectile = nullptr;
}

HOOK_METHOD(PDSFire, CollisionCheck, (Collideable *other) -> void)
{
    CustomDamageManager::currentWeaponDmg = &PR_EX(this)->customDamage;
    CustomDamageManager::currentWeaponDmg->sourceShipId = ownerId;
    CustomDamageManager::currentProjectile = this;

    super(other);

    CustomDamageManager::currentWeaponDmg = nullptr;
    CustomDamageManager::currentProjectile = nullptr;
}
