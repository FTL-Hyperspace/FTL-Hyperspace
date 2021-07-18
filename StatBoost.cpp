#pragma GCC push_options
#pragma GCC optimize ("O3")

#include "StatBoost.h"
#include "CustomCrew.h"
#include "CustomAugments.h"
#include <algorithm>
#include <boost/lexical_cast.hpp>
//#include <chrono>
//#include <iostream>

uint64_t StatBoostDefinition::nextId = -1;
int StatBoostManager::statCacheFrame = 1;

StatBoostManager StatBoostManager::instance = StatBoostManager();

StatBoostDefinition StatBoostManager::ParseStatBoostNode(rapidxml::xml_node<char>* node, StatBoostDefinition::BoostSource boostSource)
{
    StatBoostDefinition def = StatBoostDefinition();
    def.GiveId();
    def.boostSource = boostSource;
    auto stat = std::find(crewStats.begin(), crewStats.end(), node->first_attribute("name")->value());
    if (stat != crewStats.end())
    {
        int statId = stat - crewStats.begin();
        def.stat = static_cast<CrewStat>(statId);
        for (auto child = node->first_node(); child; child = child->next_sibling())
        {
            std::string name = child->name();
            std::string val = child->value();
            if (name == "statBoost")
            {
                def.providedStatBoosts.push_back(ParseStatBoostNode(child, StatBoostDefinition::BoostSource::CREW));
            }
            if (name == "boostType")
            {
                if (val == "MULT")
                {
                    def.boostType = StatBoostDefinition::BoostType::MULT;
                }
                if (val == "FLAT")
                {
                    def.boostType = StatBoostDefinition::BoostType::FLAT;
                }
                if (val == "SET")
                {
                    def.boostType = StatBoostDefinition::BoostType::SET;
                }
                if (val == "FLIP")
                {
                    def.boostType = StatBoostDefinition::BoostType::FLIP;
                }
            }
            if (name == "amount")
            {
                def.amount = boost::lexical_cast<float>(val);

            }
            if (name == "value")
            {
                def.value = EventsParser::ParseBoolean(val);
            }
            if (name == "duration")
            {
                def.duration = boost::lexical_cast<float>(val);
            }
            if (name == "priority")
            {
                def.priority = boost::lexical_cast<int>(val);
            }
            if (name == "boostAnim")
            {
                def.boostAnim = val;
            }
            if (name == "affectsSelf")
            {
                def.affectsSelf = EventsParser::ParseBoolean(val);
            }
            if (name == "shipTarget")
            {
                if (val == "PLAYER_SHIP")
                {
                    def.shipTarget = StatBoostDefinition::ShipTarget::PLAYER_SHIP;
                }
                if (val == "ENEMY_SHIP")
                {
                    def.shipTarget = StatBoostDefinition::ShipTarget::ENEMY_SHIP;
                }
                if (val == "CURRENT_ALL")
                {
                    def.shipTarget = StatBoostDefinition::ShipTarget::CURRENT_ALL;
                }
                if (val == "CURRENT_ROOM")
                {
                    def.shipTarget = StatBoostDefinition::ShipTarget::CURRENT_ROOM;
                }
                if (val == "OTHER_ALL")
                {
                    def.shipTarget = StatBoostDefinition::ShipTarget::OTHER_ALL;
                }
                if (val == "ORIGINAL_SHIP")
                {
                    def.shipTarget = StatBoostDefinition::ShipTarget::ORIGINAL_SHIP;
                }
                if (val == "ORIGINAL_OTHER_SHIP")
                {
                    def.shipTarget = StatBoostDefinition::ShipTarget::ORIGINAL_OTHER_SHIP;
                }
                if (val == "ALL")
                {
                    def.shipTarget = StatBoostDefinition::ShipTarget::ALL;
                }
            }
            if (name == "systemRoomTarget")
            {
                if (val == "ALL")
                {
                    def.systemRoomTarget = StatBoostDefinition::SystemRoomTarget::ALL;
                }
                if (val == "NONE")
                {
                    def.systemRoomTarget = StatBoostDefinition::SystemRoomTarget::NONE;
                }
            }
            if (name == "crewTarget")
            {
                if (val == "ALLIES")
                {
                    def.crewTarget = StatBoostDefinition::CrewTarget::ALLIES;
                }
                if (val == "ENEMIES")
                {
                    def.crewTarget = StatBoostDefinition::CrewTarget::ENEMIES;
                }
                if (val == "ALL")
                {
                    def.crewTarget = StatBoostDefinition::CrewTarget::ALL;
                }
                if (val == "CURRENT_ALLIES")
                {
                    def.crewTarget = StatBoostDefinition::CrewTarget::CURRENT_ALLIES;
                }
                if (val == "CURRENT_ENEMIES")
                {
                    def.crewTarget = StatBoostDefinition::CrewTarget::CURRENT_ENEMIES;
                }
            }
            if (name == "droneTarget")
            {
                if (val == "DRONES")
                {
                    def.droneTarget = StatBoostDefinition::DroneTarget::DRONES;
                }
                if (val == "CREW")
                {
                    def.droneTarget = StatBoostDefinition::DroneTarget::CREW;
                }
                if (val == "ALL")
                {
                    def.droneTarget = StatBoostDefinition::DroneTarget::ALL;
                }
            }
            if (name == "whiteList")
            {
                for (auto crewChild = child->first_node(); crewChild; crewChild = crewChild->next_sibling())
                {
                    def.whiteList.push_back(crewChild->name());
                }
            }
            if (name == "blackList")
            {
                for (auto crewChild = child->first_node(); crewChild; crewChild = crewChild->next_sibling())
                {
                    def.blackList.push_back(crewChild->name());
                }
            }
            if (name == "systemList")
            {
                for (auto crewChild = child->first_node(); crewChild; crewChild = crewChild->next_sibling())
                {
                    def.systemList.push_back(crewChild->name());
                }
            }
            if (name == "systemPowerDependency")
            {
                for (auto systemChild = child->first_node(); systemChild; systemChild = systemChild->next_sibling())
                {
                    std::string systemChildName = systemChild->name();

                    if (systemChildName == "all")
                    {
                        for (int i = 0; i < 15; i++)
                        {
                            def.systemPowerScaling.push_back(i);
                        }
                    }
                    else if (systemChildName == "reactorMax")
                    {
                        def.systemPowerScaling.push_back(16);
                    }
                    else if (systemChildName == "reactorCurrent")
                    {
                        def.systemPowerScaling.push_back(17);
                    }
                    else
                    {
                        def.systemPowerScaling.push_back(ShipSystem::NameToSystemId(systemChildName));
                    }
                }
            }
            if (name == "systemPowerScaling")
            {
                for (auto systemChild = child->first_node(); systemChild; systemChild = systemChild->next_sibling())
                {
                    std::string systemChildName = systemChild->name();

                    bool noSys = false;
                    bool hackedSys = false;

                    if (systemChildName == "noSys")
                    {
                        noSys = true;
                        def.powerScalingNoSys = boost::lexical_cast<float>(systemChild->value());
                    }
                    else if (systemChildName == "hackedSys")
                    {
                        hackedSys = true;
                        def.powerScalingHackedSys = boost::lexical_cast<float>(systemChild->value());
                    }
                    else
                    {
                        def.powerScaling.push_back(boost::lexical_cast<float>(systemChild->value()));
                    }

                    if (def.powerScaling.size())
                    {
                        if (!noSys)
                        {
                            def.powerScalingNoSys = def.powerScaling.at(0);
                        }
                        if (!hackedSys)
                        {
                            def.powerScalingHackedSys = def.powerScaling.at(0);
                        }
                    }
                }
            }
            if (name == "maxStacks")
            {
                if (!val.empty())
                {
                    def.maxStacks = boost::lexical_cast<int>(val);
                }
                if (child->first_attribute("id"))
                {
                    def.stackId = GiveStackId(child->first_attribute("id")->value());
                }
                else
                {
                    def.stackId = GiveStackId();
                }
            }
            if (name == "deathEffect")
            {
                def.deathEffectChange = new Damage();

                def.deathEffectChange->ownerId = -1;
                def.deathEffectChange->selfId = -1;
                def.deathEffectChange->crystalShard = false;

                if (def.boostType == StatBoostDefinition::BoostType::MULT)
                {
                    def.deathEffectChange->iDamage = 1;
                    def.deathEffectChange->iShieldPiercing = 1;
                    def.deathEffectChange->fireChance = 1;
                    def.deathEffectChange->breachChance = 1;
                    def.deathEffectChange->stunChance = 1;
                    def.deathEffectChange->iIonDamage = 1;
                    def.deathEffectChange->iSystemDamage = 1;
                    def.deathEffectChange->iPersDamage = 1;
                    def.deathEffectChange->bHullBuster = true;
                    def.deathEffectChange->bLockdown = true;
                    def.deathEffectChange->bFriendlyFire = true;
                    def.deathEffectChange->iStun = 1;
                }
                else
                {
                    def.deathEffectChange->iDamage = 0;
                    def.deathEffectChange->iShieldPiercing = 0;
                    def.deathEffectChange->fireChance = 0;
                    def.deathEffectChange->breachChance = 0;
                    def.deathEffectChange->stunChance = 0;
                    def.deathEffectChange->iIonDamage = 0;
                    def.deathEffectChange->iSystemDamage = 0;
                    def.deathEffectChange->iPersDamage = 0;
                    def.deathEffectChange->bHullBuster = false;
                    def.deathEffectChange->bLockdown = false;
                    def.deathEffectChange->bFriendlyFire = false;
                    def.deathEffectChange->iStun = 0;
                }

                CustomCrewManager::GetInstance()->ParseDeathEffect(child, &def.explosionShipFriendlyFire, def.deathEffectChange);
            }
            if (name == "powerEffect")
            {
                ActivatedPowerDefinition powerDef;
                CustomCrewManager::GetInstance()->ParseAbilityEffect(child, &powerDef);
                powerDef.AssignIndex();
                def.powerChange = powerDef.index;
            }
        }
    }
    return def;
}

void StatBoostManager::CreateAugmentBoost(StatBoostDefinition& def, int shipId, int nStacks)
{
    StatBoost statBoost = StatBoost(def);
    statBoost.iStacks = nStacks;

    statBoost.sourceShipId = shipId;

    if (!def.systemList.empty())
    {
        for (auto system : def.systemList)
        {
            if (playerShip != nullptr)
            {
                if (system == "all")
                {
                    for (int i = 0; i < 15; i++)
                    {
                        statBoost.sourceRoomIds.first.push_back(playerShip->GetSystemRoom(i));
                    }
                }
                else
                {
                    statBoost.sourceRoomIds.first.push_back(playerShip->GetSystemRoom(ShipSystem::NameToSystemId(system)));
                }
            }
            if (enemyShip != nullptr)
            {
                if (system == "all")
                {
                    for (int i = 0; i < 15; i++)
                    {
                        statBoost.sourceRoomIds.second.push_back(enemyShip->GetSystemRoom(i));
                    }
                }
                else
                {
                    statBoost.sourceRoomIds.second.push_back(enemyShip->GetSystemRoom(ShipSystem::NameToSystemId(system)));
                }
            }
        }
    }

    auto it = statBoosts.find(def.stat);
    if (statBoosts.find(def.stat) != statBoosts.end())
    {
        (*it).second.push_back(statBoost);
    }
    else
    {
        std::vector<StatBoost> newVector = std::vector<StatBoost>();

        newVector.push_back(statBoost);

        statBoosts[def.stat] = newVector;
    }

    if (statBoost.def.boostAnim != "")
    {
        animBoosts.push_back(statBoost);
    }

    CreateRecursiveBoosts(statBoost, nStacks);
}

void StatBoostManager::CreateCrewBoost(StatBoostDefinition& def, CrewMember* otherCrew, int nStacks)
{
    StatBoost statBoost = StatBoost(def);
    statBoost.iStacks = nStacks;

    statBoost.crewSource = otherCrew;
    CreateCrewBoost(statBoost, otherCrew);
}

void StatBoostManager::CreateCrewBoost(StatBoost statBoost, CrewMember* otherCrew)
{
    statBoost.sourceShipId = otherCrew->currentShipId; // the ship that the crewmember providing the boost is on
    if (!statBoost.def.systemList.empty())
    {
        for (auto system : statBoost.def.systemList)
        {
            if (playerShip != nullptr)
            {
                if (system == "all")
                {
                    for (int i = 0; i < 15; i++)
                    {
                        statBoost.sourceRoomIds.first.push_back(playerShip->GetSystemRoom(i));
                    }
                }
                else
                {
                    statBoost.sourceRoomIds.first.push_back(playerShip->GetSystemRoom(ShipSystem::NameToSystemId(system)));
                }
            }
            if (enemyShip != nullptr)
            {
                if (system == "all")
                {
                    for (int i = 0; i < 15; i++)
                    {
                        statBoost.sourceRoomIds.second.push_back(enemyShip->GetSystemRoom(i));
                    }
                }
                else
                {
                    statBoost.sourceRoomIds.second.push_back(enemyShip->GetSystemRoom(ShipSystem::NameToSystemId(system)));
                }
            }
        }
    }

    auto it = statBoosts.find(statBoost.def.stat);
    if (statBoosts.find(statBoost.def.stat) != statBoosts.end())
    {
        (*it).second.push_back(statBoost);
    }
    else
    {
        std::vector<StatBoost> newVector = std::vector<StatBoost>();

        newVector.push_back(statBoost);

        statBoosts[statBoost.def.stat] = newVector;
    }

    if (statBoost.def.boostAnim != "")
    {
        animBoosts.push_back(statBoost);
    }

    CreateRecursiveBoosts(statBoost, 1);
}

void StatBoostManager::CreateRecursiveBoosts(StatBoost& statBoost, int nStacks)
{
    if (!statBoost.def.providedStatBoosts.empty())
    {
        for (auto recursiveCrew : checkingCrewList)
        {
            auto ex = CM_EX(recursiveCrew);
            if (ex->BoostCheck(statBoost))
            {
                for (StatBoostDefinition recursiveBoostDef : statBoost.def.providedStatBoosts)
                {
                    CreateCrewBoost(recursiveBoostDef, recursiveCrew, nStacks);
                }
            }
        }
    }
}

void StatBoostManager::OnLoop(WorldManager* world)
{
    statBoosts.clear();
    animBoosts.clear();
    playerShip = world->playerShip->shipManager;
    enemyShip = world->playerShip->enemyShip ? world->playerShip->enemyShip->shipManager : nullptr;

    if (playerShip != nullptr)
    {
        checkingCrewList.insert(checkingCrewList.end(), playerShip->vCrewList.begin(), playerShip->vCrewList.end());
    }
    if (enemyShip != nullptr)
    {
        checkingCrewList.insert(checkingCrewList.end(), enemyShip->vCrewList.begin(), enemyShip->vCrewList.end());
    }

    // Check augment stat boosts

    CustomAugmentManager* customAug = CustomAugmentManager::GetInstance();

    for (int shipId = 0; shipId < 2; shipId++)
    {
        if (G_->GetShipInfo(shipId) != nullptr)
        {
            std::map<std::string, int> augMap = CustomAugmentManager::CheckHiddenAugments(G_->GetShipInfo(shipId)->augList);
            for (auto augPair : augMap)
            {
                if (customAug->IsAugment(augPair.first))
                {
                    for (auto statBoostDef : customAug->GetAugmentDefinition(augPair.first)->statBoosts)
                    {
                        if (statBoostDef.duration == -1)
                        {
                            CreateAugmentBoost(statBoostDef, shipId, augPair.second);
                        }
                    }
                }
            }
        }
    }

    for (auto otherCrew : checkingCrewList)
    {
        auto ex = CM_EX(otherCrew);

        auto currentStatBoosts = std::vector<StatBoost>();

        if (ex->temporaryPowerActive)
        {
            currentStatBoosts = ex->outgoingAbilityStatBoosts;
        }
        else
        {
            currentStatBoosts = ex->outgoingStatBoosts;
        }

        for (auto statBoost : currentStatBoosts)
        {
            CreateCrewBoost(statBoost, otherCrew);
        }
    }

    checkingCrewList.clear();
    statCacheFrame++;
}

void StatBoostManager::CreateTimedAugmentBoost(StatBoost statBoost, CrewMember* crew)
{
    auto ex = CM_EX(crew);

    statBoost.timerHelper.Start(statBoost.def.duration);

    auto it = ex->timedStatBoosts.find(statBoost.def.stat);
    if (ex->timedStatBoosts.find(statBoost.def.stat) != ex->timedStatBoosts.end())
    {
        (*it).second.push_back(statBoost);
    }
    else
    {
        std::vector<StatBoost> newVector = std::vector<StatBoost>();

        newVector.push_back(statBoost);

        ex->timedStatBoosts[statBoost.def.stat] = newVector;
    }
}

HOOK_METHOD(WorldManager, OnLoop, () -> void)
{
    super();
//    using std::chrono::steady_clock;
//    using std::chrono::duration_cast;
//    using std::chrono::duration;
//    using std::chrono::milliseconds;
//    auto t1 = steady_clock::now();

    StatBoostManager::GetInstance()->OnLoop(this);

//    auto t2 = steady_clock::now();
//    duration<double, std::nano> ms_double = t2 - t1;
//    std::cout << "World manager time: " << ms_double.count();
}

HOOK_METHOD(ShipManager, JumpArrive, () -> void)
{
    super();
    CustomAugmentManager* customAug = CustomAugmentManager::GetInstance();

    for (auto i : this->vCrewList)
    {
        auto ex = CM_EX(i);
        ex->timedStatBoosts.clear();
    }

    if (G_->GetShipInfo(0) != nullptr)
    {
        std::map<std::string, int> augMap = CustomAugmentManager::CheckHiddenAugments(G_->GetShipInfo(0)->augList);
        for (auto augPair : augMap)
        {
            if (customAug->IsAugment(augPair.first))
            {
                for (auto statBoostDef : customAug->GetAugmentDefinition(augPair.first)->statBoosts)
                {
                    if (statBoostDef.duration != -1)
                    {
                        StatBoost statBoost = StatBoost(statBoostDef);
                        statBoost.iStacks = augPair.second;
                        statBoost.sourceShipId = 0;

                        for (auto i : this->vCrewList)
                        {
                            StatBoostManager::GetInstance()->CreateTimedAugmentBoost(statBoost, i);
                        }
                    }
                }
            }
        }
    }
}

HOOK_METHOD(CrewMember, constructor, (CrewBlueprint& bp, int shipId, bool intruder, CrewAnimation* animation) -> void)
{
    super(bp, shipId, intruder, animation);
    CustomAugmentManager* customAug = CustomAugmentManager::GetInstance();
    if (G_->GetShipInfo(shipId) != nullptr)
    {
        std::map<std::string, int> augMap = CustomAugmentManager::CheckHiddenAugments(G_->GetShipInfo(shipId)->augList);
        for (auto augPair : augMap)
        {
            if (customAug->IsAugment(augPair.first))
            {
                for (auto statBoostDef : customAug->GetAugmentDefinition(augPair.first)->statBoosts)
                {
                    if (statBoostDef.duration != -1)
                    {
                        StatBoost statBoost = StatBoost(statBoostDef);
                        statBoost.iStacks = augPair.second;
                        statBoost.sourceShipId = shipId;

                        StatBoostManager::GetInstance()->CreateTimedAugmentBoost(statBoost, this);
                    }
                }
            }
        }
    }
}

bool CrewMember_Extend::BoostCheck(const StatBoost& statBoost)
{
    if (statBoost.def.boostSource == StatBoostDefinition::BoostSource::CREW)
    {
        if(
            (statBoost.def.shipTarget == StatBoostDefinition::ShipTarget::PLAYER_SHIP && orig->currentShipId == 0)
            || (statBoost.def.shipTarget == StatBoostDefinition::ShipTarget::ORIGINAL_SHIP && orig->currentShipId == statBoost.crewSource->iShipId)
            || (statBoost.def.shipTarget == StatBoostDefinition::ShipTarget::ORIGINAL_OTHER_SHIP && orig->currentShipId != statBoost.crewSource->iShipId)
            || (statBoost.def.shipTarget == StatBoostDefinition::ShipTarget::OTHER_ALL && orig->currentShipId != statBoost.crewSource->currentShipId)
            || (statBoost.def.shipTarget == StatBoostDefinition::ShipTarget::ENEMY_SHIP && orig->currentShipId == 1)
            || (statBoost.def.shipTarget == StatBoostDefinition::ShipTarget::CURRENT_ALL && orig->currentShipId == statBoost.crewSource->currentShipId)
            || (statBoost.def.shipTarget == StatBoostDefinition::ShipTarget::CURRENT_ROOM && orig->iRoomId == statBoost.crewSource->iRoomId && orig->currentShipId == statBoost.crewSource->currentShipId)
            || (statBoost.def.shipTarget == StatBoostDefinition::ShipTarget::ALL)
           )
        {
            if(
                (statBoost.crewSource != orig)
                || (statBoost.def.affectsSelf)
                )
            {
                if(
                    (statBoost.crewSource->iShipId == orig->iShipId && statBoost.def.crewTarget == StatBoostDefinition::CrewTarget::ALLIES)
                    || (statBoost.crewSource->iShipId != orig->iShipId && statBoost.def.crewTarget == StatBoostDefinition::CrewTarget::ENEMIES)
                    || (statBoost.def.crewTarget == StatBoostDefinition::CrewTarget::ALL)
                    || (statBoost.crewSource == orig && statBoost.def.affectsSelf)
                    || ((statBoost.crewSource->iShipId == orig->iShipId) == (statBoost.crewSource->bMindControlled == orig->bMindControlled) && statBoost.def.crewTarget == StatBoostDefinition::CrewTarget::CURRENT_ALLIES)
                    || ((statBoost.crewSource->iShipId != orig->iShipId) == (statBoost.crewSource->bMindControlled == orig->bMindControlled) && statBoost.def.crewTarget == StatBoostDefinition::CrewTarget::CURRENT_ENEMIES)
                   )
                {
                    if(
                        (std::find(statBoost.def.whiteList.begin(), statBoost.def.whiteList.end(), orig->species) != statBoost.def.whiteList.end())
                        || (!statBoost.def.blackList.empty() && std::find(statBoost.def.blackList.begin(), statBoost.def.blackList.end(), orig->species) == statBoost.def.blackList.end())
                        || (statBoost.def.blackList.empty() && statBoost.def.whiteList.empty())
                        || (statBoost.crewSource == orig && statBoost.def.affectsSelf)
                       )
                    {
                        if(
                            (statBoost.def.systemList.empty())
                            || (std::find(statBoost.sourceRoomIds.first.begin(), statBoost.sourceRoomIds.first.end(), orig->iRoomId) != statBoost.sourceRoomIds.first.end() && statBoost.def.systemRoomTarget == StatBoostDefinition::SystemRoomTarget::ALL && orig->currentShipId == 0)
                            || (std::find(statBoost.sourceRoomIds.second.begin(), statBoost.sourceRoomIds.second.end(), orig->iRoomId) != statBoost.sourceRoomIds.second.end() && statBoost.def.systemRoomTarget == StatBoostDefinition::SystemRoomTarget::ALL && orig->currentShipId == 1)
                            || (std::find(statBoost.sourceRoomIds.first.begin(), statBoost.sourceRoomIds.first.end(), orig->iRoomId) == statBoost.sourceRoomIds.first.end() && statBoost.def.systemRoomTarget == StatBoostDefinition::SystemRoomTarget::NONE && orig->currentShipId == 0)
                            || (std::find(statBoost.sourceRoomIds.second.begin(), statBoost.sourceRoomIds.second.end(), orig->iRoomId) == statBoost.sourceRoomIds.second.end() && statBoost.def.systemRoomTarget == StatBoostDefinition::SystemRoomTarget::NONE && orig->currentShipId == 1)
                           )
                        {
                            if(
                               (statBoost.def.droneTarget == StatBoostDefinition::DroneTarget::DRONES && orig->IsDrone())
                               || (statBoost.def.droneTarget == StatBoostDefinition::DroneTarget::CREW && !orig->IsDrone())
                               || (statBoost.def.droneTarget == StatBoostDefinition::DroneTarget::ALL)
                               )
                            {
                                return true;
                            }
                        }
                    }
                }
            }
        }
    }
    else if (statBoost.def.boostSource == StatBoostDefinition::BoostSource::AUGMENT)
    {
        if(
            (statBoost.def.shipTarget == StatBoostDefinition::ShipTarget::PLAYER_SHIP && orig->currentShipId == 0)
            || (statBoost.def.shipTarget == StatBoostDefinition::ShipTarget::ORIGINAL_SHIP && orig->currentShipId == statBoost.sourceShipId)
            || (statBoost.def.shipTarget == StatBoostDefinition::ShipTarget::ORIGINAL_OTHER_SHIP && orig->currentShipId != statBoost.sourceShipId)
            || (statBoost.def.shipTarget == StatBoostDefinition::ShipTarget::ENEMY_SHIP && orig->currentShipId == 1)
            || (statBoost.def.shipTarget == StatBoostDefinition::ShipTarget::CURRENT_ALL && orig->currentShipId == statBoost.sourceShipId)
            || (statBoost.def.shipTarget == StatBoostDefinition::ShipTarget::ALL)
            )
        {
            if(
                (statBoost.sourceShipId == orig->iShipId && statBoost.def.crewTarget == StatBoostDefinition::CrewTarget::ALLIES)
                || (statBoost.sourceShipId != orig->iShipId && statBoost.def.crewTarget == StatBoostDefinition::CrewTarget::ENEMIES)
                || (statBoost.def.crewTarget == StatBoostDefinition::CrewTarget::ALL)
                || (statBoost.crewSource == orig && statBoost.def.affectsSelf)
                || (statBoost.sourceShipId == orig->iShipId != orig->bMindControlled && statBoost.def.crewTarget == StatBoostDefinition::CrewTarget::CURRENT_ALLIES)
                || (statBoost.sourceShipId != orig->iShipId != orig->bMindControlled && statBoost.def.crewTarget == StatBoostDefinition::CrewTarget::CURRENT_ENEMIES)
                )
            {
                if(
                    (std::find(statBoost.def.whiteList.begin(), statBoost.def.whiteList.end(), orig->species) != statBoost.def.whiteList.end())
                    || (!statBoost.def.blackList.empty() && std::find(statBoost.def.blackList.begin(), statBoost.def.blackList.end(), orig->species) == statBoost.def.blackList.end())
                    || (statBoost.def.blackList.empty() && statBoost.def.whiteList.empty())
                    || (statBoost.crewSource == orig && statBoost.def.affectsSelf)
                    )
                {
                    if(
                        (statBoost.def.systemList.empty())
                        || (std::find(statBoost.sourceRoomIds.first.begin(), statBoost.sourceRoomIds.first.end(), orig->iRoomId) != statBoost.sourceRoomIds.first.end() && statBoost.def.systemRoomTarget == StatBoostDefinition::SystemRoomTarget::ALL && orig->currentShipId == 0)
                        || (std::find(statBoost.sourceRoomIds.second.begin(), statBoost.sourceRoomIds.second.end(), orig->iRoomId) != statBoost.sourceRoomIds.second.end() && statBoost.def.systemRoomTarget == StatBoostDefinition::SystemRoomTarget::ALL && orig->currentShipId == 1)
                        || (std::find(statBoost.sourceRoomIds.first.begin(), statBoost.sourceRoomIds.first.end(), orig->iRoomId) == statBoost.sourceRoomIds.first.end() && statBoost.def.systemRoomTarget == StatBoostDefinition::SystemRoomTarget::NONE && orig->currentShipId == 0)
                        || (std::find(statBoost.sourceRoomIds.second.begin(), statBoost.sourceRoomIds.second.end(), orig->iRoomId) == statBoost.sourceRoomIds.second.end() && statBoost.def.systemRoomTarget == StatBoostDefinition::SystemRoomTarget::NONE && orig->currentShipId == 1)
                        )
                    {
                        if(
                             (statBoost.def.droneTarget == StatBoostDefinition::DroneTarget::DRONES && orig->IsDrone())
                             || (statBoost.def.droneTarget == StatBoostDefinition::DroneTarget::CREW && !orig->IsDrone())
                             || (statBoost.def.droneTarget == StatBoostDefinition::DroneTarget::ALL)
                             )
                        {
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

float CrewMember_Extend::CalculateStat(CrewStat stat, const CrewDefinition& def, bool* boolValue)
{
//    using std::chrono::steady_clock;
//    using std::chrono::duration_cast;
//    using std::chrono::duration;
//    using std::chrono::milliseconds;
//    auto t1 = steady_clock::now();

    if (statCache[(unsigned int)stat].second == StatBoostManager::statCacheFrame)
    {
        if (boolValue != nullptr) *boolValue = statCache[(unsigned int)stat].first;
        return statCache[(unsigned int)stat].first;
    }

    std::vector<StatBoost> personalStatBoosts;
    std::unordered_map<int, std::vector<StatBoost*>> stackLimitedStatBoosts;
    auto& statBoosts = StatBoostManager::GetInstance()->statBoosts;

//    personalStatBoosts.clear();
//    std::unordered_map<CrewStat, std::vector<StatBoost>> allStatBoosts;

//    allStatBoosts.reserve(statBoosts.size() + timedStatBoosts.size());
//    allStatBoosts.insert(statBoosts.begin(), statBoosts.end());
//    printf("size before: %i ", allStatBoosts.size());
//    allStatBoosts.insert(timedStatBoosts.begin(), timedStatBoosts.end());
//    printf("size after: %i ", allStatBoosts.size());

//    auto it = allStatBoosts.find(stat);
//    if (it != allStatBoosts.end())
//    {
//        for (StatBoost statBoost : (*it).second)
//        {
//            if (BoostCheck(statBoost)) // If the boost affects this ship and/or this room, and the boost comes from someone else or affects self, and the boost comes from an ally and affects allies or an enemy and affects enemies, and the boost specifically lets this race take it or doesn't ban it
//            {
//                if (statBoost.duration != -1 && statBoost.timerHelper.Running())
//                {
//                    personalStatBoosts.push_back(statBoost);
//                }
//                else if (statBoost.duration == -1)
//                {
//                    personalStatBoosts.push_back(statBoost);
//                }
//            }
//        }
//    }

    auto it = statBoosts.find(stat);
    if (it != statBoosts.end())
    {
        for (StatBoost& statBoost : (*it).second)
        {
            if (BoostCheck(statBoost)) // If the boost affects this ship and/or this room, and the boost comes from someone else or affects self, and the boost comes from an ally and affects allies or an enemy and affects enemies, and the boost specifically lets this race take it or doesn't ban it
            {
                if (statBoost.def.duration == -1 || statBoost.timerHelper.Running())
                {
                    personalStatBoosts.push_back(statBoost);
                }
            }
        }
    }

    it = timedStatBoosts.find(stat);
    if (it != timedStatBoosts.end())
    {
        for (StatBoost& statBoost : (*it).second)
        {
            if (BoostCheck(statBoost)) // If the boost affects this ship and/or this room, and the boost comes from someone else or affects self, and the boost comes from an ally and affects allies or an enemy and affects enemies, and the boost specifically lets this race take it or doesn't ban it
            {
                if (statBoost.def.duration == -1 || statBoost.timerHelper.Running())
                {
                    personalStatBoosts.push_back(statBoost);
                }
            }
        }
    }

    float finalStat = 0.f;
    bool isBool = false;
    bool isEffect = false;
    switch(stat)
    {
        case CrewStat::MAX_HEALTH:
            finalStat = (temporaryPowerActive && GetPowerDef()->tempPower.maxHealth.enabled) ? GetPowerDef()->tempPower.maxHealth.value : def.maxHealth;
            break;
        case CrewStat::STUN_MULTIPLIER:
            finalStat = (temporaryPowerActive && GetPowerDef()->tempPower.stunMultiplier.enabled) ? GetPowerDef()->tempPower.stunMultiplier.value : def.stunMultiplier;
            break;
        case CrewStat::MOVE_SPEED_MULTIPLIER:
            finalStat = (temporaryPowerActive && GetPowerDef()->tempPower.moveSpeedMultiplier.enabled) ? GetPowerDef()->tempPower.moveSpeedMultiplier.value : def.moveSpeedMultiplier;
            break;
        case CrewStat::REPAIR_SPEED_MULTIPLIER:
            finalStat = (temporaryPowerActive && GetPowerDef()->tempPower.repairSpeed.enabled) ? GetPowerDef()->tempPower.repairSpeed.value : def.repairSpeed;
            break;
        case CrewStat::DAMAGE_MULTIPLIER:
            finalStat = (temporaryPowerActive && GetPowerDef()->tempPower.damageMultiplier.enabled) ? GetPowerDef()->tempPower.damageMultiplier.value : def.damageMultiplier;
            break;
        case CrewStat::RANGED_DAMAGE_MULTIPLIER:
            finalStat = (temporaryPowerActive && GetPowerDef()->tempPower.rangedDamageMultiplier.enabled) ? GetPowerDef()->tempPower.rangedDamageMultiplier.value : def.rangedDamageMultiplier;
            break;
        case CrewStat::FIRE_REPAIR_MULTIPLIER:
            finalStat = (temporaryPowerActive && GetPowerDef()->tempPower.fireRepairMultiplier.enabled) ? GetPowerDef()->tempPower.fireRepairMultiplier.value : def.fireRepairMultiplier;
            break;
        case CrewStat::SUFFOCATION_MODIFIER:
            finalStat = (temporaryPowerActive && GetPowerDef()->tempPower.suffocationModifier.enabled) ? GetPowerDef()->tempPower.suffocationModifier.value : def.suffocationModifier;
            break;
        case CrewStat::FIRE_DAMAGE_MULTIPLIER:
            finalStat = (temporaryPowerActive && GetPowerDef()->tempPower.fireDamageMultiplier.enabled) ? GetPowerDef()->tempPower.fireDamageMultiplier.value : def.fireDamageMultiplier;
            break;
        case CrewStat::OXYGEN_CHANGE_SPEED:
            finalStat = (temporaryPowerActive && GetPowerDef()->tempPower.oxygenChangeSpeed.enabled) ? GetPowerDef()->tempPower.oxygenChangeSpeed.value : def.oxygenChangeSpeed;
            break;
        case CrewStat::DAMAGE_TAKEN_MULTIPLIER:
            finalStat = (temporaryPowerActive && GetPowerDef()->tempPower.damageTakenMultiplier.enabled) ? GetPowerDef()->tempPower.damageTakenMultiplier.value : def.damageTakenMultiplier;
            break;
        case CrewStat::PASSIVE_HEAL_AMOUNT:
            finalStat = (temporaryPowerActive && GetPowerDef()->tempPower.passiveHealAmount.enabled) ? GetPowerDef()->tempPower.passiveHealAmount.value : def.passiveHealAmount;
            break;
        case CrewStat::TRUE_PASSIVE_HEAL_AMOUNT:
            finalStat = (temporaryPowerActive && GetPowerDef()->tempPower.truePassiveHealAmount.enabled) ? GetPowerDef()->tempPower.truePassiveHealAmount.value : def.truePassiveHealAmount;
            break;
        case CrewStat::TRUE_HEAL_AMOUNT:
            finalStat = (temporaryPowerActive && GetPowerDef()->tempPower.trueHealAmount.enabled) ? GetPowerDef()->tempPower.trueHealAmount.value : def.trueHealAmount;
            break;
        case CrewStat::ACTIVE_HEAL_AMOUNT:
            finalStat = (temporaryPowerActive && GetPowerDef()->tempPower.healAmount.enabled) ? GetPowerDef()->tempPower.healAmount.value : def.healAmount;
            break;
        case CrewStat::PASSIVE_HEAL_DELAY:
            finalStat = (temporaryPowerActive && GetPowerDef()->tempPower.passiveHealDelay.enabled) ? GetPowerDef()->tempPower.passiveHealDelay.value : def.passiveHealDelay;
            break;
        case CrewStat::SABOTAGE_SPEED_MULTIPLIER:
            finalStat = (temporaryPowerActive && GetPowerDef()->tempPower.sabotageSpeedMultiplier.enabled) ? GetPowerDef()->tempPower.sabotageSpeedMultiplier.value : def.sabotageSpeedMultiplier;
            break;
        case CrewStat::ALL_DAMAGE_TAKEN_MULTIPLIER:
            finalStat = (temporaryPowerActive && GetPowerDef()->tempPower.allDamageTakenMultiplier.enabled) ? GetPowerDef()->tempPower.allDamageTakenMultiplier.value : def.allDamageTakenMultiplier;
            break;
        case CrewStat::HEAL_SPEED_MULTIPLIER:
            finalStat = (temporaryPowerActive && GetPowerDef()->tempPower.healSpeed.enabled) ? GetPowerDef()->tempPower.healSpeed.value : def.healSpeed;
            break;
        case CrewStat::HEAL_CREW_AMOUNT:
            finalStat = (temporaryPowerActive && GetPowerDef()->tempPower.healCrewAmount.enabled) ? GetPowerDef()->tempPower.healCrewAmount.value : def.healCrewAmount;
            break;
        case CrewStat::DAMAGE_ENEMIES_AMOUNT:
            finalStat = (temporaryPowerActive && GetPowerDef()->tempPower.damageEnemiesAmount.enabled) ? GetPowerDef()->tempPower.damageEnemiesAmount.value : def.damageEnemiesAmount;
            break;
        case CrewStat::BONUS_POWER:
            finalStat = (temporaryPowerActive && GetPowerDef()->tempPower.bonusPower.enabled) ? GetPowerDef()->tempPower.bonusPower.value : def.bonusPower;
            break;
        case CrewStat::POWER_DRAIN:
            finalStat = (temporaryPowerActive && GetPowerDef()->tempPower.powerDrain.enabled) ? GetPowerDef()->tempPower.powerDrain.value : def.powerDrain;
            break;
        case CrewStat::DEFAULT_SKILL_LEVEL:
            finalStat = def.defaultSkillLevel;
            break;
        case CrewStat::POWER_RECHARGE_MULTIPLIER:
            finalStat = 1.0;
            break;
        case CrewStat::CAN_FIGHT:
            *boolValue = (temporaryPowerActive && GetPowerDef()->tempPower.canFight.enabled) ? GetPowerDef()->tempPower.canFight.value : def.canFight;
            isBool = true;
            break;
        case CrewStat::CAN_REPAIR:
            *boolValue = (temporaryPowerActive && GetPowerDef()->tempPower.canRepair.enabled) ? GetPowerDef()->tempPower.canRepair.value : def.canRepair;
            isBool = true;
            break;
        case CrewStat::CAN_SABOTAGE:
            *boolValue = (temporaryPowerActive && GetPowerDef()->tempPower.canSabotage.enabled) ? GetPowerDef()->tempPower.canSabotage.value : def.canSabotage;
            isBool = true;
            break;
        case CrewStat::CAN_MAN:
            *boolValue = (temporaryPowerActive && GetPowerDef()->tempPower.canMan.enabled) ? GetPowerDef()->tempPower.canMan.value : def.canMan;
            isBool = true;
            break;
        case CrewStat::CAN_SUFFOCATE:
            *boolValue = (temporaryPowerActive && GetPowerDef()->tempPower.canSuffocate.enabled) ? GetPowerDef()->tempPower.canSuffocate.value : def.canSuffocate;
            isBool = true;
            break;
        case CrewStat::CONTROLLABLE:
            *boolValue = (temporaryPowerActive && GetPowerDef()->tempPower.controllable.enabled) ? GetPowerDef()->tempPower.controllable.value : def.controllable;
            isBool = true;
            break;
        case CrewStat::CAN_BURN:
            *boolValue = (temporaryPowerActive && GetPowerDef()->tempPower.canBurn.enabled) ? GetPowerDef()->tempPower.canBurn.value : def.canBurn;
            isBool = true;
            break;
        case CrewStat::IS_TELEPATHIC:
            *boolValue = (temporaryPowerActive && GetPowerDef()->tempPower.isTelepathic.enabled) ? GetPowerDef()->tempPower.isTelepathic.value : def.isTelepathic;
            isBool = true;
            break;
        case CrewStat::IS_ANAEROBIC:
            *boolValue = (temporaryPowerActive && GetPowerDef()->tempPower.isAnaerobic.enabled) ? GetPowerDef()->tempPower.isAnaerobic.value : def.isAnaerobic;
            isBool = true;
            break;
        case CrewStat::CAN_PHASE_THROUGH_DOORS:
            *boolValue = (temporaryPowerActive && GetPowerDef()->tempPower.canPhaseThroughDoors.enabled) ? GetPowerDef()->tempPower.canPhaseThroughDoors.value : def.canPhaseThroughDoors;
            isBool = true;
            break;
        case CrewStat::DETECTS_LIFEFORMS:
            *boolValue = (temporaryPowerActive && GetPowerDef()->tempPower.detectsLifeforms.enabled) ? GetPowerDef()->tempPower.detectsLifeforms.value : def.detectsLifeforms;
            isBool = true;
            break;
        case CrewStat::CLONE_LOSE_SKILLS:
            *boolValue = def.cloneLoseSkills;
            isBool = true;
            break;
        case CrewStat::POWER_DRAIN_FRIENDLY:
            *boolValue = (temporaryPowerActive && GetPowerDef()->tempPower.powerDrainFriendly.enabled) ? GetPowerDef()->tempPower.powerDrainFriendly.value : def.powerDrainFriendly;
            isBool = true;
            break;
        case CrewStat::HACK_DOORS:
            *boolValue = (temporaryPowerActive && GetPowerDef()->tempPower.hackDoors.enabled) ? GetPowerDef()->tempPower.hackDoors.value : def.hackDoors;
            isBool = true;
            break;
        case CrewStat::ACTIVATE_WHEN_READY:
            *boolValue = GetPowerDef()->activateWhenReady;
            isBool = true;
            break;
        case CrewStat::DEATH_EFFECT:
            deathEffectChange = def.explosionDef;
            explosionShipFriendlyFire = def.explosionShipFriendlyFire;
            hasDeathExplosion = def.hasDeathExplosion;
            isEffect = true;
            break;
        case CrewStat::POWER_EFFECT:
            powerChange = def.powerDefIdx;
            isEffect = true;
            break;
    }

    std::sort(personalStatBoosts.begin(), personalStatBoosts.end(),
        [](const StatBoost &a, const StatBoost &b) -> bool
        {
            return a.def.priority < b.def.priority;
        });

    for (auto& statBoost : personalStatBoosts)
    {
        if (statBoost.def.stackId)
        {
            stackLimitedStatBoosts[statBoost.def.stackId].push_back(&statBoost);
        }
    }

    for (auto& statBoostsPair : stackLimitedStatBoosts)
    {
        auto& statBoosts = statBoostsPair.second;

        int stacks = 0;

        for (auto it = statBoosts.rbegin(); it != statBoosts.rend(); ++it)
        {
            auto statBoost = *it;
            statBoost->iStacks = std::min(statBoost->iStacks, std::max(statBoost->def.maxStacks - stacks, 0));
            stacks += statBoost->iStacks;
        }
    }

    for (StatBoost& statBoost : personalStatBoosts)
    {
        for (int i = 0; i < statBoost.iStacks; ++i)
        {
            if (statBoost.def.stat == stat)
            {
                if (isBool)
                {
                    if (statBoost.def.boostType == StatBoostDefinition::BoostType::SET)
                    {
                        *boolValue = statBoost.def.value;
                    }
                    else if (statBoost.def.boostType == StatBoostDefinition::BoostType::FLIP)
                    {
                        *boolValue = !*boolValue;
                    }
                }
                else if (isEffect)
                {
                    if (stat == CrewStat::POWER_EFFECT)
                    {
                        if (statBoost.def.boostType == StatBoostDefinition::BoostType::MULT)
                        {

                        }
                        else if (statBoost.def.boostType == StatBoostDefinition::BoostType::FLAT)
                        {

                        }
                        else if (statBoost.def.boostType == StatBoostDefinition::BoostType::SET)
                        {
                            powerChange = statBoost.def.powerChange;
                        }
                        else if (statBoost.def.boostType == StatBoostDefinition::BoostType::SET_VALUE)
                        {

                        }
                    }
                    else if (stat == CrewStat::DEATH_EFFECT)
                    {
                        if (statBoost.def.boostType == StatBoostDefinition::BoostType::MULT)
                        {
                            if (statBoost.def.deathEffectChange)
                            {
                                hasDeathExplosion = true;
                                explosionShipFriendlyFire &= statBoost.def.explosionShipFriendlyFire;
                                deathEffectChange.iDamage *= statBoost.def.deathEffectChange->iDamage;
                                deathEffectChange.iShieldPiercing *= statBoost.def.deathEffectChange->iShieldPiercing;
                                deathEffectChange.fireChance *= statBoost.def.deathEffectChange->fireChance;
                                deathEffectChange.breachChance *= statBoost.def.deathEffectChange->breachChance;
                                deathEffectChange.stunChance *= statBoost.def.deathEffectChange->stunChance;
                                deathEffectChange.iIonDamage *= statBoost.def.deathEffectChange->iIonDamage;
                                deathEffectChange.iSystemDamage *= statBoost.def.deathEffectChange->iSystemDamage;
                                deathEffectChange.iPersDamage *= statBoost.def.deathEffectChange->iPersDamage;
                                deathEffectChange.bHullBuster &= statBoost.def.deathEffectChange->bHullBuster;
                                deathEffectChange.bLockdown &= statBoost.def.deathEffectChange->bLockdown;
                                deathEffectChange.bFriendlyFire &= statBoost.def.deathEffectChange->bFriendlyFire;
                                deathEffectChange.iStun *= statBoost.def.deathEffectChange->iStun;
                            }
                        }
                        else if (statBoost.def.boostType == StatBoostDefinition::BoostType::FLAT)
                        {
                            if (statBoost.def.deathEffectChange)
                            {
                                hasDeathExplosion = true;
                                explosionShipFriendlyFire |= statBoost.def.explosionShipFriendlyFire;
                                deathEffectChange.iDamage += statBoost.def.deathEffectChange->iDamage;
                                deathEffectChange.iShieldPiercing += statBoost.def.deathEffectChange->iShieldPiercing;
                                deathEffectChange.fireChance += statBoost.def.deathEffectChange->fireChance;
                                deathEffectChange.breachChance += statBoost.def.deathEffectChange->breachChance;
                                deathEffectChange.stunChance += statBoost.def.deathEffectChange->stunChance;
                                deathEffectChange.iIonDamage += statBoost.def.deathEffectChange->iIonDamage;
                                deathEffectChange.iSystemDamage += statBoost.def.deathEffectChange->iSystemDamage;
                                deathEffectChange.iPersDamage += statBoost.def.deathEffectChange->iPersDamage;
                                deathEffectChange.bHullBuster |= statBoost.def.deathEffectChange->bHullBuster;
                                deathEffectChange.bLockdown |= statBoost.def.deathEffectChange->bLockdown;
                                deathEffectChange.bFriendlyFire |= statBoost.def.deathEffectChange->bFriendlyFire;
                                deathEffectChange.iStun += statBoost.def.deathEffectChange->iStun;
                            }
                        }
                        else if (statBoost.def.boostType == StatBoostDefinition::BoostType::SET)
                        {
                            if (statBoost.def.deathEffectChange)
                            {
                                hasDeathExplosion = true;
                                explosionShipFriendlyFire = statBoost.def.explosionShipFriendlyFire;
                                deathEffectChange = *statBoost.def.deathEffectChange;
                            }
                            else
                            {
                                hasDeathExplosion = false;
                            }
                        }
                        else if (statBoost.def.boostType == StatBoostDefinition::BoostType::SET_VALUE)
                        {

                        }
                    }
                }
                else
                {
                    int numPower = 0;
                    float sysPowerScaling = statBoost.def.powerScalingNoSys;
                    bool systemExists = false;

                    int statBoostSourceShipId = 0;
                    if (statBoost.def.boostSource == StatBoostDefinition::BoostSource::AUGMENT)
                    {
                        statBoostSourceShipId = statBoost.sourceShipId;
                    }
                    else if (statBoost.def.boostSource == StatBoostDefinition::BoostSource::CREW)
                    {
                        statBoostSourceShipId = statBoost.crewSource->iShipId;
                    }

                    for (auto system : statBoost.def.systemPowerScaling)
                    {
                        if (system == 16)
                        {
                            systemExists = true;
                            numPower += PowerManager::GetPowerManager(statBoostSourceShipId)->currentPower.second;
                        }
                        else if (system == 17)
                        {
                            systemExists = true;
                            numPower += PowerManager::GetPowerManager(statBoostSourceShipId)->currentPower.first;
                        }
                        else
                        {
                            ShipManager* shipManager = G_->GetShipManager(statBoostSourceShipId);
                            if (shipManager != nullptr)
                            {
                                if (shipManager->GetSystemRoom(system) != -1)
                                {
                                    if (shipManager->GetSystem(system)->iHackEffect >= 2)
                                    {
                                        sysPowerScaling = statBoost.def.powerScalingHackedSys;
                                        systemExists = false;
                                        break;
                                    }
                                    else
                                    {
                                        systemExists = true;
                                        numPower += shipManager->GetSystem(system)->GetEffectivePower();
                                    }
                                }
                            }
                        }
                    }
                    if (systemExists)
                    {
                        sysPowerScaling = statBoost.def.powerScaling.at(numPower < statBoost.def.powerScaling.size() ? numPower : statBoost.def.powerScaling.size()-1);
                    }

                    if (statBoost.def.boostType == StatBoostDefinition::BoostType::MULT)
                    {
                        if (!statBoost.def.powerScaling.empty())
                        {
                            finalStat = finalStat * (1 + (statBoost.def.amount - 1) * sysPowerScaling);
                        }
                        else
                        {
                            finalStat *= statBoost.def.amount;
                        }
                    }
                    else if (statBoost.def.boostType == StatBoostDefinition::BoostType::FLAT)
                    {
                        finalStat += statBoost.def.amount * sysPowerScaling;
                    }
                    else if (statBoost.def.boostType == StatBoostDefinition::BoostType::SET)
                    {
                        finalStat = statBoost.def.amount * sysPowerScaling;
                    }
                }
            }
        }
    }
    if (stat == CrewStat::MAX_HEALTH)
    {
        if (orig->health.second > 0)
        {
            orig->health.first *= (int)finalStat / orig->health.second;
        }
        else
        {
            orig->health.first = finalStat;
        }
    }

    if (isBool)
    {
        statCache[(unsigned int)stat].first = *boolValue;
        statCache[(unsigned int)stat].second = StatBoostManager::statCacheFrame;
    }
    else if (!isEffect)
    {
        statCache[(unsigned int)stat].first = finalStat;
        statCache[(unsigned int)stat].second = StatBoostManager::statCacheFrame;
    }

//    auto t2 = steady_clock::now();
//    duration<double, std::nano> ms_double = t2 - t1;
//    std::cout << "Calculate stat time: " << ms_double.count();
    return finalStat;
}

HOOK_METHOD_PRIORITY(CrewMember, OnLoop, 1000, () -> void)
{
    super();
    auto custom = CustomCrewManager::GetInstance();
    CrewMember_Extend* ex = CM_EX(this);
    if (custom->IsRace(species))
    {
        for (auto& timedBoosts : ex->timedStatBoosts)
        {
            for (StatBoost& statBoost : timedBoosts.second)
            {
                statBoost.timerHelper.Update();
            }
            ex->timedStatBoosts[timedBoosts.first].erase(std::remove_if(ex->timedStatBoosts[timedBoosts.first].begin(),
                                       ex->timedStatBoosts[timedBoosts.first].end(),
                                       [](StatBoost& statBoost) { return statBoost.timerHelper.Done(); }),
                                       ex->timedStatBoosts[timedBoosts.first].end());
        }

        auto aex = CMA_EX(crewAnim);

        auto animKeep = std::unordered_map<uint64_t, bool>();

        for (auto animation : aex->boostAnim)
        {
            animKeep[animation.first] = false;
        }

        for (StatBoost& statBoost : StatBoostManager::GetInstance()->animBoosts)
        {
            bool result = ex->BoostCheck(statBoost);
            if (result)
            {
                auto it = animKeep.find(statBoost.def.realBoostId);
                if (it == animKeep.end())
                {
                    Animation* anim = new Animation();
                    AnimationControl::GetAnimation(*anim, G_->GetAnimationControl(), statBoost.def.boostAnim);
                    aex->boostAnim[statBoost.def.realBoostId] = anim;
                    anim->SetCurrentFrame(0);
                    anim->tracker.SetLoop(true, 0);
                    anim->Start(true);
                }
                else
                {
                    it->second = true;
                }
            }
        }
        for (auto& vStatBoost : ex->timedStatBoosts)
        {
            for (StatBoost& statBoost : vStatBoost.second)
            {
                if (statBoost.def.boostAnim != "")
                {
                    bool result = ex->BoostCheck(statBoost);
                    if (result)
                    {
                        auto it = animKeep.find(statBoost.def.realBoostId);
                        if (it == animKeep.end())
                        {
                            Animation* anim = new Animation();
                            AnimationControl::GetAnimation(*anim, G_->GetAnimationControl(), statBoost.def.boostAnim);
                            aex->boostAnim[statBoost.def.realBoostId] = anim;
                            anim->SetCurrentFrame(0);
                            anim->tracker.SetLoop(true, 0);
                            anim->Start(true);
                        }
                        else
                        {
                            it->second = true;
                        }
                    }
                }
            }
        }
        for (auto i : animKeep)
        {
            if (!i.second)
            {
                aex->boostAnim[i.first]->destructor();
                aex->boostAnim.erase(i.first);
            }
        }
        for (auto boostAnim : aex->boostAnim)
        {
            boostAnim.second->Update();
        }
    }
}

#pragma GCC pop_options
