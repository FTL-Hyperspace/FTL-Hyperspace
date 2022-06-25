#include "CrewMember_Extend.h"
#include "CustomCrew.h"

inline ActivatedPower::ActivatedPower(ActivatedPowerDefinition *_def, CrewMember *_crew) : def{_def}, crew{_crew}
{
    crew_ex = CM_EX(_crew);
}

inline ActivatedPower::ActivatedPower(ActivatedPowerDefinition *_def, CrewMember_Extend *_ex) : def{_def}, crew_ex{_ex}
{
    crew = _ex->orig;
}

PowerReadyState ActivatedPower::PowerReq(const ActivatedPowerRequirements *req)
{
    ShipManager *currentShip = G_->GetShipManager(crew->currentShipId);
    ShipManager *crewShip = G_->GetShipManager(crew->iShipId);
    int ownerId = crew->GetPowerOwner();
    ShipManager *ownerShip = G_->GetShipManager(ownerId);

    if (!crew->intruder && req->enemyShip)
    {
        return POWER_NOT_READY_ENEMY_SHIP;
    }
    if (crew->intruder && req->playerShip)
    {
        return POWER_NOT_READY_PLAYER_SHIP;
    }
    // known bug: GetSystemInRoom rarely crashes upon loading a saved run, usually on chargeReq (it crashes trying to dereference a system in vSystemList)
    if (currentShip && req->systemInRoom && !currentShip->GetSystemInRoom(crew->iRoomId))
    {
        return POWER_NOT_READY_SYSTEM_IN_ROOM;
    }
    else if (currentShip && req->systemDamaged)
    {
        auto sys = currentShip->GetSystemInRoom(crew->iRoomId);

        if (sys && sys->healthState.first == sys->healthState.second) return POWER_NOT_READY_SYSTEM_DAMAGED;
    }
    if (req->checkRoomCrew && currentShip)
    {
        bool enemyInRoom = !req->enemyInRoom;
        bool friendlyInRoom = !req->friendlyInRoom;
        bool whiteList = req->whiteList.empty();
        bool enemyWhiteList = req->enemyWhiteList.empty();
        bool friendlyWhiteList = req->friendlyWhiteList.empty();
        bool enemyBlackList = true;
        bool friendlyBlackList = true;

        for (auto i : currentShip->vCrewList)
        {
            if (i->iRoomId == crew->iRoomId && i != crew && !i->bDead)
            {
                if (i->iShipId != ownerId)
                {
                    enemyInRoom = true;
                    if (!whiteList)
                    {
                        for (const std::string& race : req->whiteList)
                        {
                            if (i->species == race)
                            {
                                whiteList = true;
                                break;
                            }
                        }
                    }
                    if (!enemyWhiteList)
                    {
                        for (const std::string& race : req->enemyWhiteList)
                        {
                            if (i->species == race)
                            {
                                enemyWhiteList = true;
                                break;
                            }
                        }
                    }
                    if (enemyBlackList)
                    {
                        for (const std::string& race : req->enemyBlackList)
                        {
                            if (i->species == race)
                            {
                                enemyBlackList = false;
                                break;
                            }
                        }
                    }
                }
                else
                {
                    friendlyInRoom = true;
                    if (!whiteList)
                    {
                        for (const std::string& race : req->whiteList)
                        {
                            if (i->species == race)
                            {
                                whiteList = true;
                                break;
                            }
                        }
                    }
                    if (!friendlyWhiteList)
                    {
                        for (const std::string& race : req->friendlyWhiteList)
                        {
                            if (i->species == race)
                            {
                                friendlyWhiteList = true;
                                break;
                            }
                        }
                    }
                    if (friendlyBlackList)
                    {
                        for (const std::string& race : req->friendlyBlackList)
                        {
                            if (i->species == race)
                            {
                                friendlyBlackList = false;
                                break;
                            }
                        }
                    }
                }
            }
        }

        if (!enemyInRoom)
        {
            return POWER_NOT_READY_ENEMY_IN_ROOM;
        }
        else if (!friendlyInRoom)
        {
            return POWER_NOT_READY_FRIENDLY_IN_ROOM;
        }
        else if (!whiteList)
        {
            return POWER_NOT_READY_WHITELIST;
        }
        else if (!enemyWhiteList)
        {
            return POWER_NOT_READY_ENEMY_WHITELIST;
        }
        else if (!friendlyWhiteList)
        {
            return POWER_NOT_READY_FRIENDLY_WHITELIST;
        }
        else if (!enemyBlackList)
        {
            return POWER_NOT_READY_ENEMY_BLACKLIST;
        }
        else if (!friendlyBlackList)
        {
            return POWER_NOT_READY_FRIENDLY_BLACKLIST;
        }
    }
    if ((!crewShip || !crewShip->HasSystem(13)) && req->hasClonebay)
    {
        return POWER_NOT_READY_HAS_CLONEBAY;
    }
    if (req->aiDisabled && ownerId == 1)
    {
        return POWER_NOT_READY_AI_DISABLED;
    }
    if (req->outOfCombat && (crewShip && crewShip->current_target && crewShip->current_target->_targetable.hostile))
    {
        return POWER_NOT_READY_OUT_OF_COMBAT;
    }
    if (req->inCombat && (crewShip && (!crewShip->current_target || !crewShip->current_target->_targetable.hostile)))
    {
        return POWER_NOT_READY_IN_COMBAT;
    }
    if (req->requiredSystem != -1)
    {
        if (!ownerShip || !ownerShip->HasSystem(req->requiredSystem))
        {
            return POWER_NOT_READY_SYSTEM;
        }
        ShipSystem* sys = ownerShip->GetSystem(req->requiredSystem);
        if (sys == nullptr)
        {
            return POWER_NOT_READY_SYSTEM;
        }
        if (req->requiredSystemFunctional && (sys->iHackEffect > 1 || sys->GetEffectivePower() == 0))
        {
            return POWER_NOT_READY_SYSTEM_FUNCTIONAL;
        }
    }
    if (req->minHealth.enabled && crew->health.first < req->minHealth.value)
    {
        return POWER_NOT_READY_MIN_HEALTH;
    }
    if (req->maxHealth.enabled && crew->health.first > req->maxHealth.value)
    {
        return POWER_NOT_READY_MAX_HEALTH;
    }

    if (!req->extraConditions.empty())
    {
        for (auto& condition : req->extraConditions)
        {
            if (crew_ex->CheckExtraCondition(condition.first) != condition.second)
            {
                return (PowerReadyState)((condition.second ? POWER_NOT_READY_EXTRACONDITION_FALSE : POWER_NOT_READY_EXTRACONDITION_TRUE) + (PowerReadyState)condition.first);
            }
        }
    }

    if (!req->extraOrConditions.empty())
    {
        for (auto& condition : req->extraOrConditions)
        {
            if (crew_ex->CheckExtraCondition(condition.first) == condition.second) return POWER_READY;
        }
        return POWER_NOT_READY_EXTRACONDITION_OR;
    }

    return POWER_READY;
}

PowerReadyState ActivatedPower::PowerReady()
{
    if (loadingGame) return POWER_NOT_READY_COOLDOWN;

    if (temporaryPowerActive)
    {
        return POWER_NOT_READY_ACTIVATED;
    }
    if (powerCharges.second >= 0 && powerCharges.first <= 0)
    {
        return POWER_NOT_READY_CHARGES;
    }
    if (powerCooldown.first < powerCooldown.second)
    {
        return POWER_NOT_READY_COOLDOWN;
    }

    bool silenced;
    crew_ex->CalculateStat(CrewStat::SILENCED, &silenced);
    if (silenced)
    {
        return POWER_NOT_READY_SILENCED;
    }

    return PowerReq(crew->GetPowerOwner() == 0 ? &def->playerReq : &def->enemyReq);
}

Damage* ActivatedPower::GetPowerDamage()
{
    auto custom = CustomCrewManager::GetInstance();

    Damage* damage = new Damage;

    Damage* newDamage = &(def->damage);

    damage->iDamage = newDamage->iDamage;
    damage->fireChance = newDamage->fireChance;
    damage->breachChance = newDamage->breachChance;
    damage->stunChance = newDamage->stunChance;
    damage->iIonDamage = newDamage->iIonDamage;
    damage->iSystemDamage = newDamage->iSystemDamage;
    damage->iPersDamage = newDamage->iPersDamage;
    damage->bHullBuster = newDamage->bHullBuster;
    damage->ownerId = crew->GetPowerOwner();
    damage->selfId = crew_ex->selfId;
    damage->bLockdown = false;
    damage->crystalShard = newDamage->crystalShard;
    damage->bFriendlyFire = newDamage->bFriendlyFire;
    damage->iStun = newDamage->iStun;

    return damage;
}
