#pragma GCC push_options
#pragma GCC optimize ("O2")

#include "StatBoost.h"
#include "CustomCrew.h"
#include "CustomAugments.h"
#include <algorithm>
#include <boost/lexical_cast.hpp>
//#include <chrono>
//#include <iostream>

StatBoost ParseStatBoostNode(rapidxml::xml_node<char>* node)
{
    StatBoost def = StatBoost();

    auto stat = std::find(crewStats.begin(), crewStats.end(), node->first_attribute("name")->value());
    if (stat != crewStats.end())
    {
        int statId = stat - crewStats.begin();
        def.stat = static_cast<CrewStat>(statId);
        for (auto child = node->first_node(); child; child = child->next_sibling())
        {
            std::string name = child->name();
            std::string val = child->value();
            if (name == "boostType")
            {
                if (val == "MULT")
                {
                    def.boostType = StatBoost::BoostType::MULT;
                }
                if (val == "FLAT")
                {
                    def.boostType = StatBoost::BoostType::FLAT;
                }
                if (val == "SET")
                {
                    def.boostType = StatBoost::BoostType::SET;
                }
                if (val == "FLIP")
                {
                    def.boostType = StatBoost::BoostType::FLIP;
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
            if (name == "priority")
            {
                def.priority = boost::lexical_cast<int>(val);
            }
            if (name == "affectsSelf")
            {
                def.affectsSelf = EventsParser::ParseBoolean(val);
            }
            if (name == "shipTarget")
            {
                if (val == "PLAYER_SHIP")
                {
                    def.shipTarget = StatBoost::ShipTarget::PLAYER_SHIP;
                }
                if (val == "ENEMY_SHIP")
                {
                    def.shipTarget = StatBoost::ShipTarget::ENEMY_SHIP;
                }
                if (val == "CURRENT_ALL")
                {
                    def.shipTarget = StatBoost::ShipTarget::CURRENT_ALL;
                }
                if (val == "CURRENT_ROOM")
                {
                    def.shipTarget = StatBoost::ShipTarget::CURRENT_ROOM;
                }
                if (val == "OTHER_ALL")
                {
                    def.shipTarget = StatBoost::ShipTarget::OTHER_ALL;
                }
                if (val == "ORIGINAL_SHIP")
                {
                    def.shipTarget = StatBoost::ShipTarget::ORIGINAL_SHIP;
                }
                if (val == "ORIGINAL_OTHER_SHIP")
                {
                    def.shipTarget = StatBoost::ShipTarget::ORIGINAL_OTHER_SHIP;
                }
                if (val == "ALL")
                {
                    def.shipTarget = StatBoost::ShipTarget::ALL;
                }
            }
            if (name == "systemRoomTarget")
            {
                if (val == "ALL")
                {
                    def.systemRoomTarget = StatBoost::SystemRoomTarget::ALL;
                }
                if (val == "NONE")
                {
                    def.systemRoomTarget = StatBoost::SystemRoomTarget::NONE;
                }
            }
            if (name == "crewTarget")
            {
                if (val == "ALLIES")
                {
                    def.crewTarget = StatBoost::CrewTarget::ALLIES;
                }
                if (val == "ENEMIES")
                {
                    def.crewTarget = StatBoost::CrewTarget::ENEMIES;
                }
                if (val == "ALL")
                {
                    def.crewTarget = StatBoost::CrewTarget::ALL;
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
        }
    }
    return def;
}

static std::unordered_map<CrewStat, std::vector<StatBoost>> statBoosts;
HOOK_METHOD(WorldManager, OnLoop, () -> void)
{
    super();
//    using std::chrono::steady_clock;
//    using std::chrono::duration_cast;
//    using std::chrono::duration;
//    using std::chrono::milliseconds;
//    auto t1 = steady_clock::now();

    statBoosts.clear();

    ShipManager* playerShip;
    ShipManager* enemyShip;
    playerShip = this->playerShip->shipManager;
    enemyShip = this->playerShip->shipManager->current_target;

    // Check crew stat boosts

    auto checkingCrewList = std::vector<CrewMember*>();

    if (playerShip != nullptr)
    {
        checkingCrewList.insert(checkingCrewList.end(), playerShip->vCrewList.begin(), playerShip->vCrewList.end());
    }
    if (enemyShip != nullptr)
    {
        checkingCrewList.insert(checkingCrewList.end(), enemyShip->vCrewList.begin(), enemyShip->vCrewList.end());
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

        for (StatBoost statBoost : currentStatBoosts)
        {
            statBoost.sourceShipId = otherCrew->currentShipId;
            if (!statBoost.systemList.empty())
            {
                for (auto system : statBoost.systemList)
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

            auto it = statBoosts.find(statBoost.stat);
            if (statBoosts.find(statBoost.stat) != statBoosts.end())
            {
                (*it).second.push_back(statBoost);
            }
            else
            {
                std::vector<StatBoost> newVector = std::vector<StatBoost>();
                newVector.push_back(statBoost);
                statBoosts[statBoost.stat] = newVector;
            }
        }
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
                    for (auto statBoost : customAug->GetAugmentDefinition(augPair.first)->statBoosts)
                    {
                        statBoost.boostSource = StatBoost::BoostSource::AUGMENT;
                        statBoost.sourceShipId = shipId;

                        auto it = statBoosts.find(statBoost.stat);
                        if (statBoosts.find(statBoost.stat) != statBoosts.end())
                        {
                            for (int i = 0; i < augPair.second; i++)
                                (*it).second.push_back(statBoost);
                        }
                        else
                        {
                            std::vector<StatBoost> newVector = std::vector<StatBoost>();

                            for (int i = 0; i < augPair.second; i++)
                                newVector.push_back(statBoost);

                            statBoosts[statBoost.stat] = newVector;
                        }
                    }
                }
            }
        }
    }
//    auto t2 = steady_clock::now();
//    duration<double, std::nano> ms_double = t2 - t1;
//    std::cout << "World manager time: " << ms_double.count();
}

bool CrewMember_Extend::BoostCheck(const StatBoost& statBoost)
{
    if (statBoost.boostSource == StatBoost::BoostSource::CREW)
    {
        if(((statBoost.shipTarget == StatBoost::ShipTarget::PLAYER_SHIP && orig->currentShipId == 0)
            || (statBoost.shipTarget == StatBoost::ShipTarget::ORIGINAL_SHIP && orig->currentShipId == statBoost.crewSource->iShipId)
            || (statBoost.shipTarget == StatBoost::ShipTarget::ORIGINAL_OTHER_SHIP && orig->currentShipId != statBoost.crewSource->iShipId)
            || (statBoost.shipTarget == StatBoost::ShipTarget::ENEMY_SHIP && orig->currentShipId == 1))
            || (statBoost.shipTarget == StatBoost::ShipTarget::CURRENT_ALL && orig->currentShipId == statBoost.crewSource->currentShipId)
            || (statBoost.shipTarget == StatBoost::ShipTarget::CURRENT_ROOM && orig->iRoomId == statBoost.crewSource->iRoomId && orig->currentShipId == statBoost.crewSource->currentShipId)
            || (statBoost.shipTarget == StatBoost::ShipTarget::ALL)
           )
        {
            if(
                (statBoost.crewSource != orig)
                || (statBoost.affectsSelf)
                )
            {
                if(
                    ((statBoost.crewSource->iShipId == orig->iShipId && statBoost.crewTarget == StatBoost::CrewTarget::ALLIES)
                    || (statBoost.crewSource->iShipId != orig->iShipId && statBoost.crewTarget == StatBoost::CrewTarget::ENEMIES)
                    || (statBoost.crewTarget == StatBoost::CrewTarget::ALL)
                    || (statBoost.crewSource == orig && statBoost.affectsSelf))
                   )
                {
                    if(
                        (std::find(statBoost.whiteList.begin(), statBoost.whiteList.end(), orig->species) != statBoost.whiteList.end())
                        || (!statBoost.blackList.empty() && std::find(statBoost.blackList.begin(), statBoost.blackList.end(), orig->species) == statBoost.blackList.end())
                        || (statBoost.blackList.empty() && statBoost.whiteList.empty())
                        || (statBoost.crewSource == orig && statBoost.affectsSelf)
                       )
                    {
                        if(
                            (statBoost.systemList.empty())
                            || (std::find(statBoost.sourceRoomIds.first.begin(), statBoost.sourceRoomIds.first.end(), orig->iRoomId) != statBoost.sourceRoomIds.first.end() && statBoost.systemRoomTarget == StatBoost::SystemRoomTarget::ALL && orig->currentShipId == 0)
                            || (std::find(statBoost.sourceRoomIds.second.begin(), statBoost.sourceRoomIds.second.end(), orig->iRoomId) != statBoost.sourceRoomIds.second.end() && statBoost.systemRoomTarget == StatBoost::SystemRoomTarget::ALL && orig->currentShipId == 1)
                            || (std::find(statBoost.sourceRoomIds.first.begin(), statBoost.sourceRoomIds.first.end(), orig->iRoomId) == statBoost.sourceRoomIds.first.end() && statBoost.systemRoomTarget == StatBoost::SystemRoomTarget::NONE && orig->currentShipId == 0)
                            || (std::find(statBoost.sourceRoomIds.second.begin(), statBoost.sourceRoomIds.second.end(), orig->iRoomId) == statBoost.sourceRoomIds.second.end() && statBoost.systemRoomTarget == StatBoost::SystemRoomTarget::NONE && orig->currentShipId == 1)
                           )
                        {
                            if(
                               (statBoost.droneTarget == StatBoost::DroneTarget::DRONES && orig->IsDrone())
                               || (statBoost.droneTarget == StatBoost::DroneTarget::CREW && !orig->IsDrone())
                               || (statBoost.droneTarget == StatBoost::DroneTarget::ALL)
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
    else if (statBoost.boostSource == StatBoost::BoostSource::AUGMENT)
    {
        if(
            (statBoost.shipTarget == StatBoost::ShipTarget::PLAYER_SHIP && orig->currentShipId == 0)
            || (statBoost.shipTarget == StatBoost::ShipTarget::ORIGINAL_SHIP && orig->currentShipId == statBoost.sourceShipId)
            || (statBoost.shipTarget == StatBoost::ShipTarget::ORIGINAL_OTHER_SHIP && orig->currentShipId != statBoost.sourceShipId)
            || (statBoost.shipTarget == StatBoost::ShipTarget::ENEMY_SHIP && orig->currentShipId == 1)
            || (statBoost.shipTarget == StatBoost::ShipTarget::CURRENT_ALL && orig->currentShipId == statBoost.sourceShipId)
            || (statBoost.shipTarget == StatBoost::ShipTarget::ALL)
            )
        {
            if(
                (statBoost.sourceShipId == orig->iShipId && statBoost.crewTarget == StatBoost::CrewTarget::ALLIES)
                || (statBoost.sourceShipId != orig->iShipId && statBoost.crewTarget == StatBoost::CrewTarget::ENEMIES)
                ||  (statBoost.crewTarget == StatBoost::CrewTarget::ALL)
                )
            {
                if(
                    (std::find(statBoost.whiteList.begin(), statBoost.whiteList.end(), orig->species) != statBoost.whiteList.end())
                    || (!statBoost.blackList.empty() && std::find(statBoost.blackList.begin(), statBoost.blackList.end(), orig->species) == statBoost.blackList.end())
                    || (statBoost.blackList.empty() && statBoost.whiteList.empty())
                    )
                {
                    if(
                        (statBoost.systemList.empty())
                        || (std::find(statBoost.sourceRoomIds.first.begin(), statBoost.sourceRoomIds.first.end(), orig->iRoomId) != statBoost.sourceRoomIds.first.end() && statBoost.systemRoomTarget == StatBoost::SystemRoomTarget::ALL && orig->currentShipId == 0)
                        || (std::find(statBoost.sourceRoomIds.second.begin(), statBoost.sourceRoomIds.second.end(), orig->iRoomId) != statBoost.sourceRoomIds.second.end() && statBoost.systemRoomTarget == StatBoost::SystemRoomTarget::ALL && orig->currentShipId == 1)
                        || (std::find(statBoost.sourceRoomIds.first.begin(), statBoost.sourceRoomIds.first.end(), orig->iRoomId) == statBoost.sourceRoomIds.first.end() && statBoost.systemRoomTarget == StatBoost::SystemRoomTarget::NONE && orig->currentShipId == 0)
                        || (std::find(statBoost.sourceRoomIds.second.begin(), statBoost.sourceRoomIds.second.end(), orig->iRoomId) == statBoost.sourceRoomIds.second.end() && statBoost.systemRoomTarget == StatBoost::SystemRoomTarget::NONE && orig->currentShipId == 1)
                        )
                    {
                        if(
                             (statBoost.droneTarget == StatBoost::DroneTarget::DRONES && orig->IsDrone())
                             || (statBoost.droneTarget == StatBoost::DroneTarget::CREW && !orig->IsDrone())
                             || (statBoost.droneTarget == StatBoost::DroneTarget::ALL)
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

    std::vector<StatBoost> personalStatBoosts;

    auto it = statBoosts.find(stat);
    if (it != statBoosts.end())
    {
        for (StatBoost statBoost : (*it).second)
        {
            if (BoostCheck(statBoost)) // If the boost affects this ship and/or this room, and the boost comes from someone else or affects self, and the boost comes from an ally and affects allies or an enemy and affects enemies, and the boost specifically lets this race take it or doesn't ban it
            {
                personalStatBoosts.push_back(statBoost);
            }
        }
    }

    float finalStat = 0.f;
    bool isBool = false;
    switch(stat)
    {
        case CrewStat::MAX_HEALTH:
            finalStat = (temporaryPowerActive && def.powerDef.tempPower.maxHealth.enabled) ? def.powerDef.tempPower.maxHealth.value : def.maxHealth;
            break;
        case CrewStat::STUN_MULTIPLIER:
            finalStat = (temporaryPowerActive && def.powerDef.tempPower.stunMultiplier.enabled) ? def.powerDef.tempPower.stunMultiplier.value : def.stunMultiplier;
            break;
        case CrewStat::MOVE_SPEED_MULTIPLIER:
            finalStat = (temporaryPowerActive && def.powerDef.tempPower.moveSpeedMultiplier.enabled) ? def.powerDef.tempPower.moveSpeedMultiplier.value : def.moveSpeedMultiplier;
            break;
        case CrewStat::REPAIR_SPEED_MULTIPLIER:
            finalStat = (temporaryPowerActive && def.powerDef.tempPower.repairSpeed.enabled) ? def.powerDef.tempPower.repairSpeed.value : def.repairSpeed;
            break;
        case CrewStat::DAMAGE_MULTIPLIER:
            finalStat = (temporaryPowerActive && def.powerDef.tempPower.damageMultiplier.enabled) ? def.powerDef.tempPower.damageMultiplier.value : def.damageMultiplier;
            break;
        case CrewStat::RANGED_DAMAGE_MULTIPLIER:
            finalStat = (temporaryPowerActive && def.powerDef.tempPower.damageMultiplier.enabled) ? def.powerDef.tempPower.damageMultiplier.value : def.damageMultiplier;
            finalStat *= (temporaryPowerActive && def.powerDef.tempPower.rangedDamageMultiplier.enabled) ? def.powerDef.tempPower.rangedDamageMultiplier.value : def.rangedDamageMultiplier;
            break;
        case CrewStat::FIRE_REPAIR_MULTIPLIER:
            finalStat = (temporaryPowerActive && def.powerDef.tempPower.fireRepairMultiplier.enabled) ? def.powerDef.tempPower.fireRepairMultiplier.value : def.fireRepairMultiplier;
            break;
        case CrewStat::SUFFOCATION_MODIFIER:
            finalStat = (temporaryPowerActive && def.powerDef.tempPower.suffocationModifier.enabled) ? def.powerDef.tempPower.suffocationModifier.value : def.suffocationModifier;
            break;
        case CrewStat::FIRE_DAMAGE_MULTIPLIER:
            finalStat = (temporaryPowerActive && def.powerDef.tempPower.fireDamageMultiplier.enabled) ? def.powerDef.tempPower.fireDamageMultiplier.value : def.fireDamageMultiplier;
            break;
        case CrewStat::OXYGEN_CHANGE_SPEED:
            finalStat = (temporaryPowerActive && def.powerDef.tempPower.oxygenChangeSpeed.enabled) ? def.powerDef.tempPower.oxygenChangeSpeed.value : def.oxygenChangeSpeed;
            break;
        case CrewStat::DAMAGE_TAKEN_MULTIPLIER:
            finalStat = (temporaryPowerActive && def.powerDef.tempPower.damageTakenMultiplier.enabled) ? def.powerDef.tempPower.damageTakenMultiplier.value : def.damageTakenMultiplier;
            break;
        case CrewStat::PASSIVE_HEAL_AMOUNT:
            finalStat = (temporaryPowerActive && def.powerDef.tempPower.passiveHealAmount.enabled) ? def.powerDef.tempPower.passiveHealAmount.value : def.passiveHealAmount;
            break;
        case CrewStat::ACTIVE_HEAL_AMOUNT:
            finalStat = (temporaryPowerActive) ? def.powerDef.tempPower.healAmount : 0.f;
            break;
        case CrewStat::PASSIVE_HEAL_DELAY:
            finalStat = (temporaryPowerActive && def.powerDef.tempPower.passiveHealDelay.enabled) ? def.powerDef.tempPower.passiveHealDelay.value : def.passiveHealDelay;
            break;
        case CrewStat::SABOTAGE_SPEED_MULTIPLIER:
            finalStat = (temporaryPowerActive && def.powerDef.tempPower.sabotageSpeedMultiplier.enabled) ? def.powerDef.tempPower.sabotageSpeedMultiplier.value : def.sabotageSpeedMultiplier;
            break;
        case CrewStat::ALL_DAMAGE_TAKEN_MULTIPLIER:
            finalStat = (temporaryPowerActive && def.powerDef.tempPower.allDamageTakenMultiplier.enabled) ? def.powerDef.tempPower.allDamageTakenMultiplier.value : def.allDamageTakenMultiplier;
            break;
        case CrewStat::HEAL_SPEED_MULTIPLIER:
            finalStat = (temporaryPowerActive && def.powerDef.tempPower.healSpeed.enabled) ? def.powerDef.tempPower.healSpeed.value : def.healSpeed;
            break;
        case CrewStat::HEAL_CREW_AMOUNT:
            finalStat = (temporaryPowerActive && def.powerDef.tempPower.healCrewAmount.enabled) ? def.powerDef.tempPower.healCrewAmount.value : def.healCrewAmount;
            break;
        case CrewStat::DAMAGE_ENEMIES_AMOUNT:
            finalStat = (temporaryPowerActive && def.powerDef.tempPower.damageEnemiesAmount.enabled) ? def.powerDef.tempPower.damageEnemiesAmount.value : def.damageEnemiesAmount;
            break;
        case CrewStat::BONUS_POWER:
            finalStat = (temporaryPowerActive && def.powerDef.tempPower.bonusPower.enabled) ? def.powerDef.tempPower.bonusPower.value : def.bonusPower;
            break;
        case CrewStat::POWER_DRAIN:
            finalStat = (temporaryPowerActive && def.powerDef.tempPower.powerDrain.enabled) ? def.powerDef.tempPower.powerDrain.value : def.powerDrain;
            break;
        case CrewStat::CAN_FIGHT:
            *boolValue = (temporaryPowerActive && def.powerDef.tempPower.canFight.enabled) ? def.powerDef.tempPower.canFight.value : def.canFight;
            isBool = true;
            break;
        case CrewStat::CAN_REPAIR:
            *boolValue = (temporaryPowerActive && def.powerDef.tempPower.canRepair.enabled) ? def.powerDef.tempPower.canRepair.value : def.canRepair;
            isBool = true;
            break;
        case CrewStat::CAN_SABOTAGE:
            *boolValue = (temporaryPowerActive && def.powerDef.tempPower.canSabotage.enabled) ? def.powerDef.tempPower.canSabotage.value : def.canSabotage;
            isBool = true;
            break;
        case CrewStat::CAN_MAN:
            *boolValue = (temporaryPowerActive && def.powerDef.tempPower.canMan.enabled) ? def.powerDef.tempPower.canMan.value : def.canMan;
            isBool = true;
            break;
        case CrewStat::CAN_SUFFOCATE:
            *boolValue = (temporaryPowerActive && def.powerDef.tempPower.canSuffocate.enabled) ? def.powerDef.tempPower.canSuffocate.value : def.canSuffocate;
            isBool = true;
            break;
        case CrewStat::CONTROLLABLE:
            *boolValue = (temporaryPowerActive && def.powerDef.tempPower.controllable.enabled) ? def.powerDef.tempPower.controllable.value : def.controllable;
            isBool = true;
            break;
        case CrewStat::CAN_BURN:
            *boolValue = (temporaryPowerActive && def.powerDef.tempPower.canBurn.enabled) ? def.powerDef.tempPower.canBurn.value : def.canBurn;
            isBool = true;
            break;
        case CrewStat::IS_TELEPATHIC:
            *boolValue = (temporaryPowerActive && def.powerDef.tempPower.isTelepathic.enabled) ? def.powerDef.tempPower.isTelepathic.value : def.isTelepathic;
            isBool = true;
            break;
        case CrewStat::IS_ANAEROBIC:
            *boolValue = (temporaryPowerActive && def.powerDef.tempPower.isAnaerobic.enabled) ? def.powerDef.tempPower.isAnaerobic.value : def.isAnaerobic;
            isBool = true;
            break;
        case CrewStat::CAN_PHASE_THROUGH_DOORS:
            *boolValue = (temporaryPowerActive && def.powerDef.tempPower.canPhaseThroughDoors.enabled) ? def.powerDef.tempPower.canPhaseThroughDoors.value : def.canPhaseThroughDoors;
            isBool = true;
            break;
        case CrewStat::DETECTS_LIFEFORMS:
            *boolValue = (temporaryPowerActive && def.powerDef.tempPower.detectsLifeforms.enabled) ? def.powerDef.tempPower.detectsLifeforms.value : def.detectsLifeforms;
            isBool = true;
            break;
        case CrewStat::CLONE_LOSE_SKILLS:
            *boolValue = def.cloneLoseSkills;
            isBool = true;
            break;
        case CrewStat::POWER_DRAIN_FRIENDLY:
            *boolValue = def.powerDrainFriendly;
            isBool = true;
            break;
    }

    std::sort(personalStatBoosts.begin(), personalStatBoosts.end(),
        [](const StatBoost &a, const StatBoost &b) -> bool
        {
            return a.priority > b.priority;
        });

    for (StatBoost statBoost : personalStatBoosts)
    {
        if (statBoost.stat == stat)
        {
            if (isBool)
            {
                if (statBoost.boostType == StatBoost::BoostType::SET)
                {
                    *boolValue = statBoost.value;
                }
                else if (statBoost.boostType == StatBoost::BoostType::FLIP)
                {
                    *boolValue = !*boolValue;
                }
            }
            else
            {
                if (statBoost.boostType == StatBoost::BoostType::MULT)
                {
                    finalStat *= statBoost.amount;
                }
                else if (statBoost.boostType == StatBoost::BoostType::FLAT)
                {
                    finalStat += statBoost.amount;
                }
                else if (statBoost.boostType == StatBoost::BoostType::SET)
                {
                    finalStat = statBoost.amount;
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
//    auto t2 = steady_clock::now();
//    duration<double, std::nano> ms_double = t2 - t1;
//    std::cout << "Calculate stat time: " << ms_double.count();
    return finalStat;
}

#pragma GCC pop_options
