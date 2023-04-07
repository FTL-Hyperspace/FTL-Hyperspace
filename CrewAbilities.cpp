#include "CrewMember_Extend.h"
#include "CrewBox_Extend.h"
#include "CustomCrew.h"
#include "CustomEvents.h"
#include "ShipUnlocks.h"
#include "ShipManager_Extend.h"

std::vector<ActivatedPowerDefinition*> ActivatedPowerDefinition::powerDefs = std::vector<ActivatedPowerDefinition*>();
std::unordered_map<std::string,ActivatedPowerDefinition*> ActivatedPowerDefinition::nameDefList;
std::unordered_map<std::string,ActivatedPowerDefinition*> ActivatedPowerDefinition::undefinedNameDefList;
std::unordered_map<std::string,unsigned int> ActivatedPowerDefinition::activateGroupNameIndexList;
std::unordered_map<std::string,unsigned int> ActivatedPowerDefinition::replaceGroupNameIndexList;
unsigned int ActivatedPowerDefinition::nextActivateGroupNameIndex = 1;
unsigned int ActivatedPowerDefinition::nextReplaceGroupNameIndex = 1;

std::vector<PowerResourceDefinition*> PowerResourceDefinition::powerDefs = std::vector<PowerResourceDefinition*>();
std::unordered_map<std::string,PowerResourceDefinition*> PowerResourceDefinition::nameDefList;
std::unordered_map<std::string,PowerResourceDefinition*> PowerResourceDefinition::undefinedNameDefList;

ActivatedPower::ActivatedPower(ActivatedPowerDefinition *_def, CrewMember *_crew) : def{_def}, crew{_crew}
{
    crew_ex = CM_EX(_crew);
}

ActivatedPower::ActivatedPower(ActivatedPowerDefinition *_def, CrewMember_Extend *_ex) : def{_def}, crew_ex{_ex}
{
    crew = _ex->orig;
}

template <class T> PowerReadyState ActivatedPower::PowerReqStatic(const T *power, const ActivatedPowerRequirements *req)
{
    ShipManager *currentShip = G_->GetShipManager(power->crew->currentShipId);
    ShipManager *crewShip = G_->GetShipManager(power->crew->iShipId);
    int ownerId = power->crew->GetPowerOwner();
    ShipManager *ownerShip = G_->GetShipManager(ownerId);

    if (!power->crew->intruder && req->enemyShip)
    {
        return POWER_NOT_READY_ENEMY_SHIP;
    }
    if (power->crew->intruder && req->playerShip)
    {
        return POWER_NOT_READY_PLAYER_SHIP;
    }
    // known bug: GetSystemInRoom rarely crashes upon loading a saved run, usually on chargeReq (it crashes trying to dereference a system in vSystemList)
    if (currentShip && req->systemInRoom && !currentShip->GetSystemInRoom(power->crew->iRoomId))
    {
        return POWER_NOT_READY_SYSTEM_IN_ROOM;
    }
    else if (currentShip && req->systemDamaged)
    {
        auto sys = currentShip->GetSystemInRoom(power->crew->iRoomId);

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
            if (i->iRoomId == power->crew->iRoomId && i != power->crew && !i->bDead)
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
    if (req->minHealth.enabled && power->crew->health.first < req->minHealth.value)
    {
        return POWER_NOT_READY_MIN_HEALTH;
    }
    if (req->maxHealth.enabled && power->crew->health.first > req->maxHealth.value)
    {
        return POWER_NOT_READY_MAX_HEALTH;
    }

    if (!req->extraConditions.empty())
    {
        for (auto& condition : req->extraConditions)
        {
            if (power->crew_ex->CheckExtraCondition(condition.first) != condition.second)
            {
                return (PowerReadyState)((condition.second ? POWER_NOT_READY_EXTRACONDITION_FALSE : POWER_NOT_READY_EXTRACONDITION_TRUE) + (PowerReadyState)condition.first);
            }
        }
    }

    if (!req->extraOrConditions.empty())
    {
        for (auto& condition : req->extraOrConditions)
        {
            if (power->crew_ex->CheckExtraCondition(condition.first) == condition.second) return POWER_READY;
        }
        return POWER_NOT_READY_EXTRACONDITION_OR;
    }

    return POWER_READY;
}

PowerReadyState ActivatedPower::PowerReq(const ActivatedPowerRequirements *req)
{
    return PowerReqStatic(this, req);
}

PowerReadyState ActivatedPowerResource::PowerReq(const ActivatedPowerRequirements *req)
{
    return ActivatedPower::PowerReqStatic(this, req);
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
    for (ActivatedPowerResource* resource : powerResources)
    {
        if (resource->powerCharges.second >= 0 && resource->powerCharges.first <= 0)
        {
            return POWER_NOT_READY_CHARGES;
        }
    }
    if (powerCooldown.first < powerCooldown.second)
    {
        return POWER_NOT_READY_COOLDOWN;
    }
    for (ActivatedPowerResource* resource : powerResources)
    {
        if (resource->powerCooldown.first < resource->powerCooldown.second)
        {
            return POWER_NOT_READY_COOLDOWN;
        }
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

    // Update cooldown and charges
    powerCooldown.first = 0;
    powerCharges.first = std::max(0, powerCharges.first - 1);
    for (ActivatedPowerResource* resource : powerResources)
    {
        resource->powerCooldown.first = 0;
        resource->powerCharges.first = std::max(0, resource->powerCharges.first - 1);
    }

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

    // Lua callback - has two arguments: ActivatedPower, ship
    auto context = Global::GetInstance()->getLuaContext();
    SWIG_NewPointerObj(context->GetLua(), this, context->getLibScript()->types.pActivatedPower, 0);
    SWIG_NewPointerObj(context->GetLua(), ship, context->getLibScript()->types.pShipManager, 0);

    bool preempt = context->getLibScript()->call_on_internal_chain_event_callbacks(InternalEvents::ACTIVATE_POWER, 2, 0);

    lua_pop(context->GetLua(), 2);

    if (preempt) return;

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

        // set the position
        extraAnim.position.x += effectPos.x;
        extraAnim.position.y += effectPos.y;

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

void ActivatedPower::OnUpdate()
{
    if (crew->crewAnim->status == 3 && this->def->onDeath == ActivatedPowerDefinition::ON_DEATH_CANCEL)
    {
        this->CancelPower(false);
    }
    if (this->temporaryPowerActive)
    {
        this->temporaryPowerDuration.first = std::max(0.f, this->temporaryPowerDuration.first - (float)(G_->GetCFPS()->GetSpeedFactor() * 0.0625));

        if (this->temporaryPowerDuration.first <= 0.f)
        {
            this->TemporaryPowerFinished();
        }
    }
    else if (this->enabled || this->def->disabledCooldown == ActivatedPowerDefinition::DISABLED_COOLDOWN_CONTINUE)
    {
        CrewDefinition *crewdef = crew_ex->GetDefinition();

        // power recharge and auto-activation requires power to be enabled (or recharge to continue when disabled)
        if (this->powerCharges.second >= 0 && this->powerCharges.first <= 0)
        {
            this->powerCooldown.first = 0.f;
        }
        else if (this->def->chargeReq == nullptr || this->PowerReq(this->def->chargeReq) == POWER_READY)
        {
            this->powerCooldown.first = std::max(0.f, std::min(this->powerCooldown.second, (float)(G_->GetCFPS()->GetSpeedFactor() * 0.0625 * crew_ex->CalculateStat(CrewStat::POWER_RECHARGE_MULTIPLIER, crewdef)) + this->powerCooldown.first));
        }

        if (this->enabled && !crew->IsDead() && crew->Functional())
        {
            bool activateWhenReady = this->def->activateWhenReady && (!this->def->activateReadyEnemies || (crew->GetPowerOwner() == 1));
            // Only check activateWhenReady if not dying
            if (crew->crewAnim->status != 3) crew_ex->CalculateStat(CrewStat::ACTIVATE_WHEN_READY, crewdef, &activateWhenReady);
            if (activateWhenReady)
            {
                if (this->PowerReady() == POWER_READY)
                {
                    this->PreparePower();
                }
            }
            else // vanilla condition but for enemy controlling your crew with MIND_ORDER
            {
                if (crew->iShipId == 0 && crew->crewTarget && crew->CanFight() && crew->crewTarget->IsCrew() && this->PowerReady() == POWER_READY &&
                    crew->GetPowerOwner() == 1 && crew->health.first > 0.5f*crew->health.second)
                {
                    if (!crew->ship->RoomLocked(crew->iRoomId))
                    {
                        this->PreparePower();
                    }
                }
            }
        }
    }

    if (!this->powerDone && this->def->followCrew)
    {
        this->powerShip = crew->currentShipId;
        this->powerRoom = crew->iRoomId;
        if (this->effectAnim) this->effectPos = Pointf(crew->x - this->effectAnim->info.frameWidth / 2, crew->y - this->effectAnim->info.frameHeight / 2 + crew->PositionShift());
        this->effectWorldPos = Pointf(crew->x, crew->y);
    }

    // Delayed activation of active and temporary effects (animFrame)
    if (this->effectAnim)
    {
        this->effectAnim->Update();

        if (!this->powerDone && this->def->animFrame != -1 && this->effectAnim->tracker.running && this->effectAnim->currentFrame >= this->def->animFrame)
        {
            this->ActivatePower();
        }

        if (!this->temporaryPowerDone && this->def->tempPower.animFrame != -1 && this->effectAnim->tracker.running && this->effectAnim->currentFrame >= this->def->tempPower.animFrame)
        {
            this->ActivateTemporaryPower();
        }
    }

    if (this->tempEffectAnim)
    {
        this->tempEffectAnim->Update();
    }
    if (this->effectFinishAnim)
    {
        this->effectFinishAnim->Update();
    }

    for (auto anim = this->extraAnims.begin(); anim != this->extraAnims.end(); )
    {
        anim->Update();
        if (anim->Done())
        {
            anim = this->extraAnims.erase(anim);
        }
        else
        {
            ++anim;
        }
    }
}

void ActivatedPowerResource::OnUpdate()
{
    if (this->enabled || this->def->disabledCooldown == ActivatedPowerDefinition::DISABLED_COOLDOWN_CONTINUE)
    {
        // power recharge and auto-activation requires power to be enabled or disabledCooldown to be CONTINUE
        if (this->powerCharges.second >= 0 && this->powerCharges.first <= 0)
        {
            this->powerCooldown.first = 0.f;
        }
        else if (this->def->chargeReq == nullptr || this->PowerReq(this->def->chargeReq) == POWER_READY)
        {
            this->powerCooldown.first = std::max(0.f, std::min(this->powerCooldown.second, (float)(G_->GetCFPS()->GetSpeedFactor() * 0.0625 * crew_ex->CalculateStat(CrewStat::POWER_RECHARGE_MULTIPLIER)) + this->powerCooldown.first));
        }
    }
}

void CrewMember_Extend::UpdateAbilityStatBoosts(CrewDefinition *def)
{
    outgoingStatBoosts.clear();

    bool noActiveAbility = true;

    // Get stat boosts from temporary effects
    for (ActivatedPower* power : crewPowers)
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

    FileHelper::writeInt(fd, enabled);

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
    def = ActivatedPowerDefinition::powerDefs[FileHelper::readInteger(fd)];
    PrepareTemporaryAnimation(); // for tempEffectStrip

    std::string s;

    enabled = FileHelper::readInteger(fd);

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

void ActivatedPowerResource::SaveState(int fd)
{
    FileHelper::writeInt(fd, def->index);

    FileHelper::writeInt(fd, enabled);

    FileHelper::writeFloat(fd, modifiedPowerCharges);

    FileHelper::writeFloat(fd, powerCooldown.first);
    FileHelper::writeFloat(fd, powerCooldown.second);
    FileHelper::writeInt(fd, powerCharges.first);
    FileHelper::writeInt(fd, powerCharges.second);
}

void ActivatedPowerResource::LoadState(int fd)
{
    def = PowerResourceDefinition::powerDefs[FileHelper::readInteger(fd)];

    enabled = FileHelper::readInteger(fd);

    modifiedPowerCharges = FileHelper::readFloat(fd);

    powerCooldown.first = FileHelper::readFloat(fd);
    powerCooldown.second = FileHelper::readFloat(fd);
    powerCharges.first = FileHelper::readInteger(fd);
    powerCharges.second = FileHelper::readInteger(fd);
}


void CrewMember_Extend::CalculatePowerDef()
{
    CrewDefinition* def = CustomCrewManager::GetInstance()->GetDefinition(orig->species);

    // First determine which abilities the crewmember should have
    CalculateStat(CrewStat::POWER_EFFECT, def); //powerChange

    for (ActivatedPower* power : crewPowers)
    {
        power->tempEnabled = false;
    }
    for (ActivatedPowerResource* resource : powerResources)
    {
        resource->lastEnabled = resource->enabled;
        resource->enabled = false;
    }
    hasSpecialPower = false;
    bool powerChanged = false; // tracks if any powers have changed
    tempAddedPowerResource = false;

    // Loop 1: Check for existing powers matching exact definitions
    for (auto powerDef = powerChange.begin(); powerDef != powerChange.end();)
    {
        [&]{
            for (ActivatedPower* power : crewPowers)
            {
                if (!power->tempEnabled && power->enabled && power->def == *powerDef)
                {
                    hasSpecialPower = true;
                    power->tempEnabled = true;
                    power->EnablePowerResources();
                    powerDef = powerChange.erase(powerDef);
                    return;
                }
            }
            powerDef++;
        }();
    }

    // Most likely scenario is that no powers need changing/addition so check here to skip everything
    if (!powerChange.empty())
    {
        // Loop 2: Check for existing powers in the same group (direct replacement)
        for (auto powerDef = powerChange.begin(); powerDef != powerChange.end();)
        {
            [&]{
                if ((*powerDef)->replaceGroupIndex != 0)
                {
                    for (ActivatedPower* power : crewPowers)
                    {
                        if (!power->tempEnabled && power->enabled && power->def->replaceGroupIndex == (*powerDef)->replaceGroupIndex)
                        {
                            hasSpecialPower = true;
                            power->tempEnabled = true;
                            powerChanged = true;
                            power->ChangePowerDef(*powerDef);
                            powerDef = powerChange.erase(powerDef);
                            return;
                        }
                    }
                }
                powerDef++;
            }();
        }

        // Loop 3: Check for dormant powers matching exact definition, if so then re-enable that power
        for (auto powerDef = powerChange.begin(); powerDef != powerChange.end();)
        {
            [&]{
                for (ActivatedPower* power : crewPowers)
                {
                    if (!power->tempEnabled && power->def == *powerDef)
                    {
                        hasSpecialPower = true;
                        power->tempEnabled = true;
                        power->EnablePower();
                        power->EnablePowerResources();
                        powerChanged = true;
                        powerDef = powerChange.erase(powerDef);
                        return;
                    }
                }
                powerDef++;
            }();
        }

        // Loop 4: Check for dormant powers in the same group but previously disabled, if so then change the definition and enable
        for (auto powerDef = powerChange.begin(); powerDef != powerChange.end();)
        {
            [&]{
                if ((*powerDef)->replaceGroupIndex != 0)
                {
                    for (ActivatedPower* power : crewPowers)
                    {
                        if (!power->tempEnabled && power->def->replaceGroupIndex == (*powerDef)->replaceGroupIndex)
                        {
                            hasSpecialPower = true;
                            power->tempEnabled = true;
                            power->EnablePower();
                            powerChanged = true;
                            power->ChangePowerDef(*powerDef);
                            powerDef = powerChange.erase(powerDef);
                            return;
                        }
                    }
                }
                powerDef++;
            }();
        }
    }

    // Now any powers that still have tempEnabled = false should be disabled
    for (ActivatedPower* power : crewPowers)
    {
        if (!power->tempEnabled && power->enabled)
        {
            power->DisablePower();
            powerChanged = true;
        }
    }

    // Any remaining definitions in powerChange are brand new
    if (!powerChange.empty())
    {
        hasSpecialPower = true;
        for (ActivatedPowerDefinition* powerDef : powerChange)
        {
            ActivatedPower *power = new ActivatedPower(powerDef, orig, this);
            crewPowers.push_back(power);

            power->powerCooldown.first = powerDef->cooldown * powerDef->initialCooldownFraction;
            power->powerCooldown.second = powerDef->cooldown;
            power->powerCharges.first = powerDef->initialCharges;
            power->powerCharges.second = -1; // this will be updated after modifiedPowerCharges is fully calculated
            power->modifiedPowerCharges = powerDef->powerCharges;

            power->LinkPowerResources();
        }
    }

    if (powerChanged)
    {
        std::stable_sort(crewPowers.begin(), crewPowers.end(),
        [](const ActivatedPower *a, const ActivatedPower *b) -> bool
        {
            return a->def->sortOrder < b->def->sortOrder;
        });

        if (tempAddedPowerResource)
        {
            std::stable_sort(powerResources.begin(), powerResources.end(),
            [](const ActivatedPowerResource *a, const ActivatedPowerResource *b) -> bool
            {
                return a->def->sortOrder < b->def->sortOrder;
            });
        }

        if (orig->iShipId == 0 || orig->bMindControlled)
        {
            G_->GetCApp()->gui->crewControl.ClearCrewBoxes();
        }
    }

    // Now calculate power definition modifiers (any that need to be updated every frame)
    if (!crewPowers.empty() || !powerResources.empty())
    {
        // Update the max charges
        CalculateStat(CrewStat::POWER_MAX_CHARGES, def);

        for (ActivatedPower *power : crewPowers)
        {
            if (!power->enabled) continue;
            int iMaxCharges = power->modifiedPowerCharges >= 2147483648.f ? -1 : power->modifiedPowerCharges;
            if (power->powerCharges.second != iMaxCharges)
            {
                // If changing from or to -1 then clear crew boxes
                if ((power->powerCharges.second == -1) != (iMaxCharges == -1)) G_->GetCApp()->gui->crewControl.ClearCrewBoxes();

                power->powerCharges.second = iMaxCharges;
                if (iMaxCharges != -1)
                {
                    power->powerCharges.first = std::min(power->powerCharges.first, iMaxCharges);
                }
            }
        }
        for (ActivatedPowerResource *resource : powerResources)
        {
            if (!resource->enabled) continue;
            int iMaxCharges = resource->modifiedPowerCharges >= 2147483648.f ? -1 : resource->modifiedPowerCharges;
            if (resource->powerCharges.second != iMaxCharges)
            {
                // If changing from or to -1 then clear crew boxes
                if ((resource->powerCharges.second == -1) != (iMaxCharges == -1)) G_->GetCApp()->gui->crewControl.ClearCrewBoxes();

                resource->powerCharges.second = iMaxCharges;
                if (iMaxCharges != -1)
                {
                    resource->powerCharges.first = std::min(resource->powerCharges.first, iMaxCharges);
                }
            }
        }

        // Now reinitialize any power cooldowns/charges that need to be reinitialized when enabled
        for (ActivatedPower *power : crewPowers)
        {
            if (power->enabledInit) power->EnableInit();
        }
        for (ActivatedPowerResource *power : powerResources)
        {
            if (power->enabled && !power->lastEnabled) power->EnableInit();
        }
    }
}

void ActivatedPower::ChangePowerDef(ActivatedPowerDefinition *newDef)
{
    // If new definition has no temp power but current one is active then end it
    if (!newDef->hasTemporaryPower && temporaryPowerActive)
    {
        temporaryPowerDuration.first = 0.f;
        TemporaryPowerFinished();
    }

    // Set the new definition
    def = newDef;

    // If new definition has temp power and current one is active then reset the animations and duration
    if (newDef->hasTemporaryPower && temporaryPowerActive)
    {
        PrepareTemporaryAnimation();

        temporaryPowerDuration.first = def->tempPower.duration * (temporaryPowerDuration.first/temporaryPowerDuration.second);
        temporaryPowerDuration.second = def->tempPower.duration;

        crew_ex->UpdateAbilityStatBoosts();
        StatBoostManager::GetInstance()->statCacheFrame++; // resets stat cache in case game is paused
    }

    // Update cooldown
    if (powerCooldown.second > 0.f)
    {
        powerCooldown.first = (powerCooldown.first/powerCooldown.second) * newDef->cooldown;
    }
    else
    {
        powerCooldown.first = powerCooldown.second;
    }
    powerCooldown.second = newDef->cooldown;

    // Redefine resources
    powerResources.clear();
    LinkPowerResources();
}

void ActivatedPower::EnablePower()
{
    enabled = true;
    enabledInit = true;
}

void ActivatedPowerResource::EnablePower()
{
    enabled = true;
}

void ActivatedPower::EnableInit()
{
    if (def->disabledCooldown == ActivatedPowerDefinition::DISABLED_COOLDOWN_FULL) powerCooldown.first = powerCooldown.second;
    else if (def->disabledCooldown == ActivatedPowerDefinition::DISABLED_COOLDOWN_ZERO) powerCooldown.first = 0.f;
    else if (def->disabledCooldown == ActivatedPowerDefinition::DISABLED_COOLDOWN_RESET) powerCooldown.first = powerCooldown.second * def->initialCooldownFraction;

    if (def->disabledCharges == ActivatedPowerDefinition::DISABLED_COOLDOWN_FULL)
    {
        if (powerCharges.second > 0) powerCharges.first = powerCharges.second;
    }
    else if (def->disabledCharges == ActivatedPowerDefinition::DISABLED_COOLDOWN_ZERO) powerCharges.first = 0;
    else if (def->disabledCharges == ActivatedPowerDefinition::DISABLED_COOLDOWN_RESET) powerCharges.first = def->initialCharges;

    enabledInit = false;
}

void ActivatedPowerResource::EnableInit()
{
    if (def->disabledCooldown == PowerResourceDefinition::DISABLED_COOLDOWN_FULL) powerCooldown.first = powerCooldown.second;
    else if (def->disabledCooldown == PowerResourceDefinition::DISABLED_COOLDOWN_ZERO) powerCooldown.first = 0.f;
    else if (def->disabledCooldown == PowerResourceDefinition::DISABLED_COOLDOWN_RESET) powerCooldown.first = powerCooldown.second * def->initialCooldownFraction;

    if (def->disabledCharges == PowerResourceDefinition::DISABLED_COOLDOWN_FULL)
    {
        if (powerCharges.second > 0) powerCharges.first = powerCharges.second;
    }
    else if (def->disabledCharges == PowerResourceDefinition::DISABLED_COOLDOWN_ZERO) powerCharges.first = 0;
    else if (def->disabledCharges == PowerResourceDefinition::DISABLED_COOLDOWN_RESET) powerCharges.first = def->initialCharges;
}

void ActivatedPower::DisablePower()
{
    enabled = false;

    // Note that in this version the active effect continues when the power is disabled
    // But the temporary effect is terminated

    if (temporaryPowerActive)
    {
        temporaryPowerDuration.first = 0.f;
        TemporaryPowerFinished();
    }
}

void ActivatedPowerResource::DisablePower()
{
    enabled = false;
}

void ActivatedPower::LinkPowerResources()
{
    for (PowerResourceDefinition *resourceDef : def->powerResources)
    {
        ActivatedPowerResource *resource;

        auto it = crew_ex->powerResourceMap.find(resourceDef->index);
        if (it == crew_ex->powerResourceMap.end()) // need to create new
        {
            resource = new ActivatedPowerResource(resourceDef, crew, crew_ex);
            crew_ex->powerResources.push_back(resource);
            crew_ex->powerResourceMap[resourceDef->index] = resource;
            crew_ex->tempAddedPowerResource = true;

            resource->powerCooldown.first = resourceDef->cooldown * resourceDef->initialCooldownFraction;
            resource->powerCooldown.second = resourceDef->cooldown;
            resource->powerCharges.first = resourceDef->initialCharges;
            resource->powerCharges.second = -1; // this will be updated after modifiedPowerCharges is fully calculated
            resource->modifiedPowerCharges = resourceDef->powerCharges;
        }
        else
        {
            resource = it->second;
        }

        resource->enabled = true;
        powerResources.push_back(resource);
    }
}

void ActivatedPower::EnablePowerResources()
{
    for (ActivatedPowerResource *resource : powerResources)
    {
        resource->EnablePower();
    }
}

void ActivatedPowerResource::GetLinkedPowers()
{
    tempLinkedPowers.clear();

    for (ActivatedPower* power : crew_ex->crewPowers)
    {
        if (!power->enabled) continue; // at this time just skip disabled powers

        for (ActivatedPowerResource* resource : power->powerResources)
        {
            if (resource == this) // power is linked to this resource
            {
                tempLinkedPowers.push_back(power);
                break;
            }
        }
    }
}

static std::array<int,5> cooldownWidthsArray = {4,3,2,2,1};
static std::array<int,5> chargesWidthsArray = {3,2,2,1,1};

int ActivatedPower::GetCrewBoxResourceWidth(int mode)
{
    bool hasCooldown = !def->hideCooldown && powerCooldown.second > 0.f;
    bool hasCharges = !def->hideCharges && powerCharges.second > 0;

    int cooldownWidth = hasCooldown ? cooldownWidthsArray[mode]+1 : 0;
    int chargesWidth = hasCharges ? chargesWidthsArray[mode]+1 : 0;

    int width = cooldownWidth + chargesWidth;
    return width > 0 ? width + 3 : 0; // add the inter-ability margin if needed (3 px)
}

int ActivatedPowerResource::GetCrewBoxResourceWidth(int mode)
{
    int hasCooldown = !def->hideCooldown && powerCooldown.second > 0.f;
    int hasCharges = !def->hideCharges && powerCharges.second > 0;

    if (def->showLinkedCooldowns || def->showLinkedCharges)
    {
        for (ActivatedPower *power : tempLinkedPowers)
        {
            if (def->showLinkedCooldowns && power->powerCooldown.second > 0.f) hasCooldown++;
            if (def->showLinkedCharges && power->powerCharges.second > 0) hasCharges++;
        }
    }

    int cooldownWidth = hasCooldown*(cooldownWidthsArray[mode]+1);
    int chargesWidth = hasCharges*(chargesWidthsArray[mode]+1);

    int width = cooldownWidth + chargesWidth;
    return width > 0 ? width + 3 : 0; // add the inter-ability margin if needed (3 px)
}

int CrewBox_Extend::GetTotalCooldownWidth(int mode, CrewMember_Extend *ex)
{
    int width = 0;

    // Loop over powers
    for (ActivatedPower* power : ex->crewPowers)
    {
        if (!power->enabled) continue;
        width += power->GetCrewBoxResourceWidth(mode);
    }
    for (ActivatedPowerResource* power : ex->powerResources)
    {
        if (!power->enabled) continue;
        width += power->GetCrewBoxResourceWidth(mode);
    }

    return width;
}

void CrewBox_Extend::EmplacePower(ActivatedPower *power, int mode, int &offset, std::vector<int> &cooldownBorders)
{
    bool hasCooldown = !power->def->hideCooldown && power->powerCooldown.second > 0.f;
    bool hasCharges = !power->def->hideCharges && power->powerCharges.second > 0;
    if (!(hasCooldown || hasCharges)) return;

    // first calculate how much width we need
    int cooldownWidth = cooldownWidthsArray[mode];
    int chargesWidth = chargesWidthsArray[mode];

    // add charge bar
    if (hasCharges)
    {
        chargesBars.emplace_back(power, Globals::Rect({orig->box.x+offset+3, orig->box.y+3, chargesWidth, orig->box.h-6}));
        offset += chargesWidth+1;
    }

    // add cooldown bar
    if (hasCooldown)
    {
        cooldownBars.emplace_back(power, Globals::Rect({orig->box.x+offset+3, orig->box.y+3, cooldownWidth, orig->box.h-6}));
        offset += cooldownWidth+1;
    }

    // add border
    cooldownBorders.push_back(offset+4);
    offset += 3;
}

void CrewBox_Extend::EmplacePower(ActivatedPowerResource *resource, int mode, int &offset, std::vector<int> &cooldownBorders)
{
    bool hasCooldown = !resource->def->hideCooldown && resource->powerCooldown.second > 0.f;
    bool hasCharges = !resource->def->hideCharges && resource->powerCharges.second > 0;
    int oldOffset = offset;

    // first calculate how much width we need
    int cooldownWidth = cooldownWidthsArray[mode];
    int chargesWidth = chargesWidthsArray[mode];

    // add linked charge bars
    if (resource->def->showLinkedCharges)
    {
        for (ActivatedPower *power : resource->tempLinkedPowers)
        {
            if (power->powerCharges.second > 0)
            {
                chargesBars.emplace_back(power, Globals::Rect({orig->box.x+offset+3, orig->box.y+3, chargesWidth, orig->box.h-6}));
                offset += chargesWidth+1;
            }
        }
    }

    // add charge bar
    if (hasCharges)
    {
        chargesBars.emplace_back(resource, Globals::Rect({orig->box.x+offset+3, orig->box.y+3, chargesWidth, orig->box.h-6}));
        offset += chargesWidth+1;
    }

    // add linked cooldown bars
    if (resource->def->showLinkedCooldowns)
    {
        for (ActivatedPower *power : resource->tempLinkedPowers)
        {
            if (power->powerCooldown.second > 0.f)
            {
                cooldownBars.emplace_back(power, Globals::Rect({orig->box.x+offset+3, orig->box.y+3, cooldownWidth, orig->box.h-6}));
                offset += cooldownWidth+1;
            }
        }
    }

    // add cooldown bar
    if (hasCooldown)
    {
        cooldownBars.emplace_back(resource, Globals::Rect({orig->box.x+offset+3, orig->box.y+3, cooldownWidth, orig->box.h-6}));
        offset += cooldownWidth+1;

        if (resource->def->showTemporaryBars)
        {
            CrewAbilityCooldownBar &cooldownBar = cooldownBars.back(); // get the cooldownBar that was most recently emplaced
            cooldownBar.morePowers = std::move(resource->tempLinkedPowers); // shouldn't need tempLinkedPowers anymore
        }
    }

    // add border
    if (offset != oldOffset)
    {
        cooldownBorders.push_back(offset+4);
        offset += 3;
    }
}
