#include "Global.h"
#include "Projectile_Extend.h"
#include "CustomWeapons.h"
#include "CrewSpawn.h"
#include "ShipManager_Extend.h"
#include <boost/lexical_cast.hpp>

CustomDamage* CustomDamageManager::currentWeaponDmg = nullptr;
Projectile* CustomDamageManager::currentProjectile = nullptr;

CustomDamageDefinition CustomDamageDefinition::defaultDef = CustomDamageDefinition();
std::vector<CustomDamageDefinition*> CustomDamageDefinition::customDamageDefs = {&CustomDamageDefinition::defaultDef};

HOOK_METHOD(ShipManager, DamageArea, (Pointf location, Damage dmg, bool forceHit) -> bool)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::DamageArea -> Begin (CustomDamage.cpp)\n")
    bool ret = super(location, dmg, forceHit);

    if (ret)
    {
        auto custom = CustomDamageManager::currentWeaponDmg;

        if (custom && custom->sourceShipId != -1)
        {
            int rng = random32() % 10;

            if (rng < custom->def->crewSpawnChance)
            {
                for (CrewSpawn *i : custom->def->crewSpawns)
                {
                    CrewSpawn::SpawnCrew(i, this, custom->sourceShipId != iShipId, location);
                }
            }

            int room = ship.GetSelectedRoomId(location.x, location.y, true);

            if (room > -1)
            {
                rng = random32() % 10;

                if (rng < custom->def->roomStatBoostChance)
                {
                    for (auto statBoostDef : custom->def->roomStatBoosts)
                    {
                        SM_EX(this)->CreateRoomStatBoost(*statBoostDef, room, 1, custom->sourceShipId);
                    }
                }
            }
        }
    }

    return ret;
}

HOOK_METHOD(ShipManager, DamageBeam, (Pointf location1, Pointf location2, Damage dmg) -> bool)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::DamageBeam -> Begin (CustomDamage.cpp)\n")
    bool ret = super(location1, location2, dmg);

    auto custom = CustomDamageManager::currentWeaponDmg;

    if (custom && custom->sourceShipId != -1 && custom->def->crewSpawnChance > 0)
    {
        Point grid1 = ShipGraph::TranslateToGrid(location1.x, location1.y);
        Point grid2 = ShipGraph::TranslateToGrid(location2.x, location2.y);

        if (grid1 != grid2)
        {
            int rng = random32() % 10;

            if (rng < custom->def->crewSpawnChance)
            {
                Pointf spawnLoc = {grid1.x * 35.f + 17.5f, grid1.y * 35.f + 17.5f};

                for (CrewSpawn *i : custom->def->crewSpawns)
                {
                    CrewSpawn::SpawnCrew(i, this, custom->sourceShipId != iShipId, spawnLoc, true);
                }
            }
        }

        int room1 = ship.GetSelectedRoomId(location1.x, location1.y, true);
        int room2 = ship.GetSelectedRoomId(location2.x, location2.y, true);

        if (room1 > -1 && room1 != room2)
        {
            int rng = random32() % 10;

            if (rng < custom->def->roomStatBoostChance)
            {
                for (auto statBoostDef : custom->def->roomStatBoosts)
                {
                    SM_EX(this)->CreateRoomStatBoost(*statBoostDef, room1, 1, custom->sourceShipId);
                }
            }
        }
    }

    return ret;
}

HOOK_METHOD(ShipManager, GetDodgeFactor, () -> int)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::GetDodgeFactor -> Begin (CustomDamage.cpp)\n")
    int ret = super();

    if (CustomDamageManager::currentWeaponDmg != nullptr)
    {
        ret -= CustomDamageManager::currentWeaponDmg->accuracyMod;
    }

    return ret;
}

HOOK_METHOD_PRIORITY(ShipManager, DamageSystem, -100, (int roomId, Damage dmg) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> ShipManager::DamageSystem -> Begin (CustomDamage.cpp)\n")
    if (CustomDamageManager::currentWeaponDmg != nullptr && CustomDamageManager::currentWeaponDmg->def->noSysDamage)
    {
        dmg.iSystemDamage -= dmg.iDamage;
    }

    super(roomId, dmg);
}

HOOK_METHOD_PRIORITY(ShipManager, DamageCrew, -100, (CrewMember *crew, Damage dmg) -> bool)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> ShipManager::DamageCrew -> Begin (CustomDamage.cpp)\n")
    if (CustomDamageManager::currentWeaponDmg != nullptr)
    {
        if (CustomDamageManager::currentWeaponDmg->def->noPersDamage)
        {
            dmg.iPersDamage -= dmg.iDamage;
        }

        int rng = random32() % 10;

        if (rng < CustomDamageManager::currentWeaponDmg->def->statBoostChance)
        {
            for (auto statBoostDef : CustomDamageManager::currentWeaponDmg->def->statBoosts)
            {
                StatBoost statBoost(statBoostDef);
                statBoost.sourceShipId = CustomDamageManager::currentWeaponDmg->sourceShipId;
                StatBoostManager::GetInstance()->CreateTimedAugmentBoost(statBoost, crew);
            }
        }
    }

    return super(crew, dmg);
}

HOOK_METHOD(ProjectileFactory, Update, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ProjectileFactory::Update -> Begin (CustomDamage.cpp)\n")
    // This only works if every weapon has a definition, if that changes then replace with the commented code below.
    CustomWeaponManager::currentWeapon = CustomWeaponManager::instance->GetWeaponDefinition(blueprint->name);
    //CustomDamageManager::currentWeaponDmg = &CustomWeaponManager::currentWeapon->customDamage;

    //auto def = CustomWeaponManager::instance->GetWeaponDefinition(blueprint->name)
    //if (def) CustomDamageManager::currentWeaponDmg = &def->customDamage;

    super();

    CustomWeaponManager::currentWeapon = nullptr;
    //CustomDamageManager::currentWeaponDmg = nullptr;
}

HOOK_METHOD(ShipManager, CollisionMoving, (Pointf start, Pointf finish, Damage damage, bool raytrace) -> CollisionResponse)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::CollisionMoving -> Begin (CustomDamage.cpp)\n")
    if (CustomDamageManager::currentWeaponDmg && CustomDamageManager::currentWeaponDmg->def->ionBeamFix && CustomDamageManager::currentProjectile)
    {
        BeamWeapon *proj = (BeamWeapon*) CustomDamageManager::currentProjectile; // ionBeamFix should only be used for beams
        if (proj->bDamageSuperShield)
        {
            return super(start, finish, damage, raytrace);
        }
        damage.iIonDamage = 0;
    }
    return super(start, finish, damage, raytrace);
}


//rewrite
HOOK_METHOD_PRIORITY(SpaceDrone, CollisionMoving, 9999, (Pointf start, Pointf finish, Damage damage, bool raytrace) -> CollisionResponse)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> SpaceDrone::CollisionMoving -> Begin (CustomDamage.cpp)\n")
	CollisionResponse ret = CollisionResponse();
    ret.collision_type = 0;
    ret.point = {-2147483648.f, -2147483648.f};
    ret.damage = 0;
    ret.superDamage = 0;

    if (!this->bDead && this->deployed && !this->explosion.tracker.running && finish.RelativeDistance(this->currentLocation) < 100.f)
    {
        Projectile_Extend *ex = nullptr;
        if (CustomDamageManager::currentProjectile)
        {
            ex = PR_EX(CustomDamageManager::currentProjectile);
            if (!ex->missedDrones.empty())
            {
                for (int missedDrone : ex->missedDrones)
                {
                    if (missedDrone == selfId)
                    {
                        return ret;
                    }
                }
            }
        }

        int dodgeFactor = this->blueprint->dodge * 10;
        if (CustomDamageManager::currentWeaponDmg != nullptr)
        {
            dodgeFactor -= CustomDamageManager::currentWeaponDmg->droneAccuracyMod;
        }

        if (random32()%100 < dodgeFactor) // miss
        {
            if (this->powered)
            {
                delete this->message;
                this->message = new DamageMessage(1.0,this->currentLocation,DamageMessage::MISS);
                if (ex) ex->missedDrones.push_back(selfId);
                return ret;
            }
            ret.collision_type = 1;
            if (damage.iIonDamage > 0)
            {
                return ret;
            }
        }
        else //hit
        {
            ret.collision_type = 1;
            if (damage.iIonDamage > 0)
            {
                if (this->powered)
                {
                    this->ionStun = damage.iIonDamage * 5;
                }
                return ret;
            }
        }
        if (damage.iDamage > 0)
        {
            this->BlowUp(false);
        }
    }

    return ret;
}

HOOK_STATIC(ProjectileFactory, LoadProjectile, (int fh) -> Projectile*)
{
    LOG_HOOK("HOOK_STATIC -> ProjectileFactory::LoadProjectile -> Begin (CustomDamage.cpp)\n")
    Projectile *ret = super(fh);

    Projectile_Extend *ex = PR_EX(ret);

    ex->customDamage.sourceShipId = ret->ownerId;

    ex->customDamage.def = CustomDamageDefinition::customDamageDefs.at(FileHelper::readInteger(fh));
    ex->customDamage.accuracyMod = FileHelper::readInteger(fh);
    ex->customDamage.droneAccuracyMod = FileHelper::readInteger(fh);

    int n = FileHelper::readInteger(fh);
    for (int i=0; i<n; ++i)
    {
        ex->missedDrones.push_back(FileHelper::readInteger(fh));
    }

    return ret;
}

HOOK_STATIC(ProjectileFactory, SaveProjectile, (Projectile *p, int fh) -> void)
{
    LOG_HOOK("HOOK_STATIC -> ProjectileFactory::SaveProjectile -> Begin (CustomDamage.cpp)\n")
    super(p, fh);

    Projectile_Extend *ex = PR_EX(p);

    FileHelper::writeInt(fh, ex->customDamage.def->idx);
    FileHelper::writeInt(fh, ex->customDamage.accuracyMod);
    FileHelper::writeInt(fh, ex->customDamage.droneAccuracyMod);

    FileHelper::writeInt(fh, ex->missedDrones.size());
    for (int i : ex->missedDrones)
    {
        FileHelper::writeInt(fh, i);
    }
}

HOOK_METHOD(Projectile, Initialize, (WeaponBlueprint& bp) -> void)
{
    LOG_HOOK("HOOK_METHOD -> Projectile::Initialize -> Begin (CustomDamage.cpp)\n")
    super(bp);

    auto customWeapon = CustomWeaponManager::instance->GetWeaponDefinition(bp.name);
    if (customWeapon)
    {
        CustomDamage &customDamage = PR_EX(this)->customDamage;
        customDamage.def = customWeapon->customDamage;
        customDamage.accuracyMod = customWeapon->customDamage->accuracyMod;
        customDamage.droneAccuracyMod = customWeapon->customDamage->droneAccuracyMod;
    }
}

HOOK_METHOD(Projectile, CollisionCheck, (Collideable *other) -> void)
{
    LOG_HOOK("HOOK_METHOD -> Projectile::CollisionCheck -> Begin (CustomDamage.cpp)\n")
    CustomDamageManager::currentWeaponDmg = &PR_EX(this)->customDamage;
    CustomDamageManager::currentWeaponDmg->sourceShipId = ownerId;
    CustomDamageManager::currentProjectile = this;

    super(other);

    CustomDamageManager::currentWeaponDmg = nullptr;
    CustomDamageManager::currentProjectile = nullptr;
}

HOOK_METHOD(BeamWeapon, CollisionCheck, (Collideable *other) -> void)
{
    LOG_HOOK("HOOK_METHOD -> BeamWeapon::CollisionCheck -> Begin (CustomDamage.cpp)\n")
    CustomDamageManager::currentWeaponDmg = &PR_EX(this)->customDamage;
    CustomDamageManager::currentWeaponDmg->sourceShipId = ownerId;
    CustomDamageManager::currentProjectile = this;

    super(other);

    CustomDamageManager::currentWeaponDmg = nullptr;
    CustomDamageManager::currentProjectile = nullptr;
}

HOOK_METHOD(BombProjectile, CollisionCheck, (Collideable *other) -> void)
{
    LOG_HOOK("HOOK_METHOD -> BombProjectile::CollisionCheck -> Begin (CustomDamage.cpp)\n")
    CustomDamageManager::currentWeaponDmg = &PR_EX(this)->customDamage;
    CustomDamageManager::currentWeaponDmg->sourceShipId = ownerId;
    CustomDamageManager::currentProjectile = this;

    super(other);

    CustomDamageManager::currentWeaponDmg = nullptr;
    CustomDamageManager::currentProjectile = nullptr;
}

HOOK_METHOD(PDSFire, CollisionCheck, (Collideable *other) -> void)
{
    LOG_HOOK("HOOK_METHOD -> PDSFire::CollisionCheck -> Begin (CustomDamage.cpp)\n")
    CustomDamageManager::currentWeaponDmg = &PR_EX(this)->customDamage;
    CustomDamageManager::currentWeaponDmg->sourceShipId = ownerId;
    CustomDamageManager::currentProjectile = this;

    super(other);

    CustomDamageManager::currentWeaponDmg = nullptr;
    CustomDamageManager::currentProjectile = nullptr;
}
