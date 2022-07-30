#include "CrewMember_Extend.h"
#include "CustomCrew.h"
#include "CustomEvents.h"
#include "ShipUnlocks.h"
#include "ShipManager_Extend.h"

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

void ActivatedPower::ActivateTemporaryPower()
{
    temporaryPowerDone = true;

    PrepareTemporaryAnimation();

    if (tempEffectAnim)
    {
        tempEffectAnim->SetCurrentFrame(0);
        tempEffectAnim->tracker.SetLoop(true, 0);
        tempEffectAnim->Start(true);
    }

    if (def->hasTemporaryPower)
    {
        temporaryPowerActive = true;
        temporaryPowerDuration.first = def->tempPower.duration;
        temporaryPowerDuration.second = def->tempPower.duration;
    }

    crew_ex->UpdateAbilityStatBoosts();
    StatBoostManager::GetInstance()->statCacheFrame++; // resets stat cache in case game is paused
}

void ActivatedPower::TemporaryPowerFinished()
{
    temporaryPowerActive = false;

    if (def->tempPower.sounds.size() > 0  && (def->tempPower.soundsEnemy || crew->iShipId == 0))
    {
        int rng = random32();

        std::string sound = def->tempPower.sounds[rng % def->tempPower.sounds.size()];

        G_->GetSoundControl()->PlaySoundMix(sound, -1, false);
    }

    if (tempEffectAnim)
    {
        tempEffectAnim->tracker.Stop(false);
    }

    if (effectFinishAnim)
    {
        effectFinishAnim->SetCurrentFrame(0);
        effectFinishAnim->tracker.SetLoop(false, -1);
        effectFinishAnim->Start(true);
    }

    crew_ex->UpdateAbilityStatBoosts();
    StatBoostManager::GetInstance()->statCacheFrame++; // resets stat cache in case game is paused
}

void ActivatedPower::PrepareAnimation()
{
    if (def->effectAnim.empty())
    {
        effectAnim.reset(nullptr);
    }
    else
    {
        effectAnim.reset(new Animation(G_->GetAnimationControl()->GetAnimation(def->effectAnim)));
    }
}

void ActivatedPower::PrepareTemporaryAnimation()
{
    if (temporaryPowerActive) // if power is already active and being changed to a different power
    {
        float goal;
        float progress;
        AnimationTracker tracker;

        if (def->tempPower.effectFinishAnim.empty())
        {
            effectFinishAnim.reset(nullptr);
        }
        else
        {
            tracker = effectFinishAnim->tracker;
            *effectFinishAnim = Animation(G_->GetAnimationControl()->GetAnimation(def->tempPower.effectFinishAnim));
            goal = effectFinishAnim->tracker.time;
            progress = tracker.current_time / tracker.time;
            effectFinishAnim->tracker = tracker;
            effectFinishAnim->tracker.current_time = progress * goal;
            effectFinishAnim->tracker.time = goal;

            effectFinishAnim->currentFrame = std::max(0, std::min(int(progress*effectFinishAnim->info.numFrames), effectFinishAnim->info.numFrames-1));
        }

        if (def->tempPower.effectAnim.empty())
        {
            tempEffectAnim.reset(nullptr);
        }
        else
        {
            tracker = tempEffectAnim->tracker;
            *tempEffectAnim = Animation(G_->GetAnimationControl()->GetAnimation(def->tempPower.effectAnim));
            goal = tempEffectAnim->tracker.time;
            progress = tracker.current_time / tracker.time;
            tempEffectAnim->tracker = tracker;
            tempEffectAnim->tracker.current_time = progress * goal;
            tempEffectAnim->tracker.time = goal;

            tempEffectAnim->currentFrame = std::max(0, std::min(int(progress*tempEffectAnim->info.numFrames), tempEffectAnim->info.numFrames-1));
        }
    }
    else // if power is not active and we just have to set up the animations
    {
        if (def->tempPower.effectFinishAnim.empty())
        {
            effectFinishAnim.reset(nullptr);
        }
        else
        {
            effectFinishAnim.reset(new Animation(G_->GetAnimationControl()->GetAnimation(def->tempPower.effectFinishAnim)));
        }
        if (def->tempPower.effectAnim.empty())
        {
            tempEffectAnim.reset(nullptr);
        }
        else
        {
            tempEffectAnim.reset(new Animation(G_->GetAnimationControl()->GetAnimation(def->tempPower.effectAnim)));
        }
    }

    if (def->tempPower.animSheet.empty())
    {
        tempEffectStrip = nullptr;
    }
    else
    {
        tempEffectStrip = G_->GetResources()->GetImageId("people/" + def->tempPower.animSheet + ".png");
    }
}

void ActivatedPower::PreparePower()
{
    PrepareAnimation();
    powerDone = false;

    int ownerShip = crew->GetPowerOwner();
    powerShip = crew->currentShipId;
    powerRoom = crew->iRoomId;
    effectWorldPos = Pointf(crew->x, crew->y);

    if (def->animFrame == -1)
    {
        ActivatePower();
    }
    if (def->tempPower.animFrame == -1)
    {
        ActivateTemporaryPower();
    }
    else
    {
        temporaryPowerDone = false;
    }

    if (effectAnim)
    {
        effectAnim->SetCurrentFrame(0);
        effectAnim->tracker.SetLoop(false, -1);
        effectAnim->Start(true);
    }

    if (def->sounds.size() > 0 && (def->soundsEnemy || crew->iShipId == 0 || ownerShip == 0))
    {
        int rng = random32();

        std::string sound = def->sounds[rng % def->sounds.size()];

        G_->GetSoundControl()->PlaySoundMix(sound, -1.f, false);
    }

    if (effectAnim)
    {
        effectPos = Pointf(crew->x - effectAnim->info.frameWidth / 2, crew->y - effectAnim->info.frameHeight / 2 + crew->PositionShift());
    }
}

void ActivatedPower::ActivatePower()
{
    // Get the ship that this power is activated on
    ShipManager *ship;
    if (powerShip == 0)
    {
        ship = G_->GetWorld()->playerShip->shipManager;
    }
    else
    {
        ship = G_->GetWorld()->playerShip->enemyShip ? G_->GetWorld()->playerShip->enemyShip->shipManager : nullptr;
    }

    // Update cooldown and charges
    powerCooldown.first = 0;
    powerCharges.first = std::max(0, powerCharges.first - 1);

    powerActivated = true;

    // Lockdown
    if (def->damage.bLockdown)
    {
        crew->ship->LockdownRoom(crew->iRoomId, Pointf(crew->x, crew->y));
    }

    // Win effect
    if (def->win)
    {
        G_->GetSoundControl()->StopPlaylist(100);
        G_->GetSoundControl()->PlaySoundMix("victory", -1.f, false);

        G_->GetScoreKeeper()->SetVictory(true);
        CustomShipUnlocks::instance->setCustomVictoryType = "";
        hs_log_file("def->win: Set custom victory type to null\n");
        G_->GetAchievementTracker()->SetVictoryAchievement();
        G_->GetCApp()->gui->gameover = true;
        G_->GetCApp()->gui->Victory();
    }

    // Get owner ship of ability
    int ownerShip = crew->GetPowerOwner();

    // Play effect sound
    if (def->effectSounds.size() > 0 && (def->effectSoundsEnemy || crew->iShipId == 0 || ownerShip == 0))
    {
        int rng = random32();

        std::string sound = def->effectSounds[rng % def->effectSounds.size()];

        G_->GetSoundControl()->PlaySoundMix(sound, -1.f, false);
    }

    // Apply health effects to friendly/enemy crew
    if ((def->crewHealth || def->enemyHealth) && ship)
    {
        for (auto i : ship->vCrewList)
        {
            if (i->iRoomId == powerRoom && i != crew)
            {
                if (i->iShipId == ownerShip)
                {
                    i->DirectModifyHealth(def->crewHealth);
                }
                else
                {
                    i->DirectModifyHealth(def->enemyHealth);
                }
            }
        }
    }

    // Apply health effect to self if in the room/ship
    if (crew->iRoomId == powerRoom && crew->currentShipId == powerShip && def->selfHealth)
    {
        crew->DirectModifyHealth(def->selfHealth);
    }

    // Set power done flag
    powerDone = true;

    // Create effectPostAnim in extraAnim
    if (!def->effectPostAnim.empty())
    {
        extraAnims.emplace_back(G_->GetAnimationControl()->GetAnimation(def->effectPostAnim));
        Animation &extraAnim = extraAnims.back();

        extraAnim.SetCurrentFrame(0);
        extraAnim.tracker.SetLoop(false, -1);
        extraAnim.Start(true);
    }

    // Transform Race
    if (!def->transformRace.empty())
    {
        crew_ex->originalRace = def->transformRace;
        crew_ex->TransformRace(def->transformRace);
    }

    // Apply timed stat boosts to other crew
    if (!def->statBoosts.empty())
    {
        for (auto i=0; i<2; ++i)
        {
            ShipManager *crewShip = G_->GetShipManager(i);
            if (crewShip)
            {
                for (auto otherCrew : crewShip->vCrewList)
                {
                    for (auto statBoostDef : def->statBoosts)
                    {
                        StatBoost statBoost(statBoostDef);
                        statBoost.crewSource = crew;
                        statBoost.crewSourceId = crew_ex->selfId;
                        statBoost.sourceShipId = ownerShip;
                        StatBoostManager::GetInstance()->CreateTimedAugmentBoost(statBoost, otherCrew);
                    }
                }
            }
        }
    }

    // Apply room stat boosts
    if (!def->roomStatBoosts.empty() && ship)
    {
        for (auto statBoostDef : def->roomStatBoosts)
        {
            SM_EX(ship)->CreateRoomStatBoost(*statBoostDef, powerRoom, 1, crew);
        }
    }

    // Crew spawns
    for (auto& i : def->crewSpawns)
    {
        if (ship)
        {
            CrewSpawn::SpawnCrew(i, ship, ship->iShipId != ownerShip, effectWorldPos);
        }
    }

    // Ability event
    if (!def->event[ownerShip].empty())
    {
        CustomEventsParser::QueueEvent(def->event[ownerShip], -1);
    }
}

void ActivatedPower::CancelPower(bool clearAnim)
{
    // Clear the animation and stop the effect from activating.
    if (!powerDone || clearAnim)
    {
        if (effectAnim) effectAnim.reset(nullptr);
        powerDone = true;
    }

    // Stop the temporary power.
    temporaryPowerDone = true;
    if (temporaryPowerActive)
    {
        temporaryPowerDuration.first = 0.f;
        TemporaryPowerFinished();
    }
}

void CrewMember_Extend::UpdateAbilityStatBoosts(CrewDefinition *def)
{
    outgoingStatBoosts.clear();

    bool noActiveAbility = true;

    // Get stat boosts from temporary effects
    for (ActivatedPower* &power : crewPowers)
    {
        if (power->temporaryPowerActive)
        {
            noActiveAbility = false;
            for (StatBoostDefinition* statBoostDef : power->def->tempPower.statBoosts)
            {
                StatBoost statBoost = StatBoost(statBoostDef);

                statBoost.crewSource = orig;
                statBoost.crewSourceId = selfId;
                statBoost.sourceShipId = orig->iShipId;
                outgoingStatBoosts.push_back(statBoost);
            }
        }
    }

    // Get passive (no temporary effect active) stat boosts
    if (noActiveAbility)
    {
        for (StatBoostDefinition* statBoostDef : def->passiveStatBoosts)
        {
            StatBoost statBoost = StatBoost(statBoostDef);

            statBoost.crewSource = orig;
            statBoost.crewSourceId = selfId;
            statBoost.sourceShipId = orig->iShipId;
            outgoingStatBoosts.push_back(statBoost);
        }
    }
}

void CrewMember_Extend::UpdateAbilityStatBoosts()
{
    UpdateAbilityStatBoosts(GetDefinition());
}

HOOK_METHOD_PRIORITY(WorldManager, PauseLoop, 100, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> WorldManager::PauseLoop -> Begin (CrewAbilities.cpp)\n")

    // Recalculate crew abilities for all living crew when paused (when unpaused this happens during the crewmember's normal loop)
    for (int shipId = 0; shipId < 2; shipId++)
    {
        ShipManager *shipManager = G_->GetShipManager(shipId);
        if (shipManager)
        {
            for (CrewMember *crew : shipManager->vCrewList)
            {
                CM_EX(crew)->CalculatePowerDef();
            }
        }
    }

    super();
}

void ActivatedPower::SaveState(int fd)
{
    FileHelper::writeInt(fd, def->index);

    FileHelper::writeFloat(fd, modifiedPowerCharges);

    FileHelper::writeFloat(fd, powerCooldown.first);
    FileHelper::writeFloat(fd, powerCooldown.second);
    FileHelper::writeFloat(fd, temporaryPowerDuration.first);
    FileHelper::writeFloat(fd, temporaryPowerDuration.second);
    FileHelper::writeInt(fd, powerCharges.first);
    FileHelper::writeInt(fd, powerCharges.second);

    FileHelper::writeInt(fd, powerRoom);
    FileHelper::writeInt(fd, powerShip);

    FileHelper::writeInt(fd, powerActivated);
    FileHelper::writeInt(fd, temporaryPowerActive);
    FileHelper::writeInt(fd, powerDone);
    FileHelper::writeInt(fd, temporaryPowerDone);

    if (effectAnim)
    {
        FileHelper::writeString(fd, effectAnim->animName);
        effectAnim->SaveState(fd);
    }
    else
    {
        FileHelper::writeString(fd, "");
    }

    if (tempEffectAnim)
    {
        FileHelper::writeString(fd, tempEffectAnim->animName);
        tempEffectAnim->SaveState(fd);
    }
    else
    {
        FileHelper::writeString(fd, "");
    }

    if (effectFinishAnim)
    {
        FileHelper::writeString(fd, effectFinishAnim->animName);
        effectFinishAnim->SaveState(fd);
    }
    else
    {
        FileHelper::writeString(fd, "");
    }

    FileHelper::writeInt(fd, extraAnims.size());
    for (Animation &anim : extraAnims)
    {
        FileHelper::writeString(fd, anim.animName);
        anim.SaveState(fd);
    }

    FileHelper::writeFloat(fd, effectPos.x);
    FileHelper::writeFloat(fd, effectPos.y);
    FileHelper::writeFloat(fd, effectWorldPos.x);
    FileHelper::writeFloat(fd, effectWorldPos.y);
}

void ActivatedPower::LoadState(int fd)
{
    def = &ActivatedPowerDefinition::powerDefs[FileHelper::readInteger(fd)];

    std::string s;

    modifiedPowerCharges = FileHelper::readFloat(fd);

    powerCooldown.first = FileHelper::readFloat(fd);
    powerCooldown.second = FileHelper::readFloat(fd);
    temporaryPowerDuration.first = FileHelper::readFloat(fd);
    temporaryPowerDuration.second = FileHelper::readFloat(fd);
    powerCharges.first = FileHelper::readInteger(fd);
    powerCharges.second = FileHelper::readInteger(fd);

    powerRoom = FileHelper::readInteger(fd);
    powerShip = FileHelper::readInteger(fd);

    powerActivated = FileHelper::readInteger(fd);
    temporaryPowerActive = FileHelper::readInteger(fd);
    powerDone = FileHelper::readInteger(fd);
    temporaryPowerDone = FileHelper::readInteger(fd);

    s = FileHelper::readString(fd);
    if (!s.empty())
    {
        effectAnim.reset(new Animation(G_->GetAnimationControl()->GetAnimation(s)));
        effectAnim->LoadState(fd);
    }

    s = FileHelper::readString(fd);
    if (!s.empty())
    {
        tempEffectAnim.reset(new Animation(G_->GetAnimationControl()->GetAnimation(s)));
        tempEffectAnim->LoadState(fd);
    }

    s = FileHelper::readString(fd);
    if (!s.empty())
    {
        effectFinishAnim.reset(new Animation(G_->GetAnimationControl()->GetAnimation(s)));
        effectFinishAnim->LoadState(fd);
    }

    int n = FileHelper::readInteger(fd);
    for (int i=0; i<n; ++i)
    {
        extraAnims.emplace_back(G_->GetAnimationControl()->GetAnimation(FileHelper::readString(fd)));
        extraAnims.back().LoadState(fd);
    }

    effectPos.x = FileHelper::readFloat(fd);
    effectPos.y = FileHelper::readFloat(fd);
    effectWorldPos.x = FileHelper::readFloat(fd);
    effectWorldPos.y = FileHelper::readFloat(fd);
}

void CrewMember_Extend::CalculatePowerDef()
{
    CrewDefinition* def = CustomCrewManager::GetInstance()->GetDefinition(orig->species);

    // First determine which abilities the crewmember should have
    if (crewPowers.empty() || (!crewPowers[0]->powerActivated && !crewPowers[0]->temporaryPowerActive && crewPowers[0]->powerDone && crewPowers[0]->temporaryPowerDone))
    {
        int currentPowerIndex = crewPowers.empty() ? 0 : crewPowers[0]->def->index;
        CalculateStat(CrewStat::POWER_EFFECT, def); //powerChange

        if (powerChange != currentPowerIndex)
        {
            ActivatedPowerDefinition *newDef = &ActivatedPowerDefinition::powerDefs[powerChange];

            if (newDef->hasSpecialPower) // def is an actual power and not a lack of a power
            {
                if (crewPowers.empty())
                {
                    ActivatedPower *power = new ActivatedPower(newDef, orig, this);
                    crewPowers.push_back(power);

                    power->powerCooldown.first = 0.f;
                    power->powerCooldown.second = newDef->cooldown;
                    power->powerCharges.first = newDef->initialCharges;
                    power->powerCharges.second = -1; // this will be updated after modifiedPowerCharges is fully calculated
                    power->modifiedPowerCharges = newDef->powerCharges;
                }
                else
                {
                    ActivatedPower *power = crewPowers[0];
                    power->def = newDef;

                    power->powerCooldown.first = (power->powerCooldown.first/power->powerCooldown.second) * newDef->cooldown;
                    power->powerCooldown.second = newDef->cooldown;

                    power->powerCharges.second = newDef->powerCharges;
                    power->modifiedPowerCharges = newDef->powerCharges;
                }
            }
            else
            {
                ClearCrewPowers();
            }

            // Had no power, still has no power
            if (currentPowerIndex == 0 && crewPowers.empty()) return;

            if (orig->iShipId == 0)
            {
                G_->GetCApp()->gui->crewControl.ClearCrewBoxes();
            }
        }
    }

    // Now calculate power definition modifiers (any that need to be updated every frame)
    if (!crewPowers.empty())
    {
        // Update the max charges
        CalculateStat(CrewStat::POWER_MAX_CHARGES, def);
        for (ActivatedPower *power : crewPowers)
        {
            int iMaxCharges = power->modifiedPowerCharges >= 2147483648.f ? -1 : power->modifiedPowerCharges;
            if (power->powerCharges.second != iMaxCharges)
            {
                power->powerCharges.second = iMaxCharges;
                if (iMaxCharges != -1)
                {
                    power->powerCharges.first = std::min(power->powerCharges.first, iMaxCharges);
                }
                G_->GetCApp()->gui->crewControl.ClearCrewBoxes();
            }
        }
    }
}
