#pragma GCC push_options
#pragma GCC optimize ("O3")

#include "StatBoost.h"
#include "CustomCrew.h"
#include "CustomAugments.h"
#include <algorithm>
#include <boost/lexical_cast.hpp>

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
                            statBoost.sourceRoomIds.push_back(playerShip->GetSystemRoom(ShipSystem::NameToSystemId("artillery")));
                            statBoost.sourceRoomIds.push_back(playerShip->GetSystemRoom(ShipSystem::NameToSystemId("battery")));
                            statBoost.sourceRoomIds.push_back(playerShip->GetSystemRoom(ShipSystem::NameToSystemId("cloaking")));
                            statBoost.sourceRoomIds.push_back(playerShip->GetSystemRoom(ShipSystem::NameToSystemId("clonebay")));
                            statBoost.sourceRoomIds.push_back(playerShip->GetSystemRoom(ShipSystem::NameToSystemId("doors")));
                            statBoost.sourceRoomIds.push_back(playerShip->GetSystemRoom(ShipSystem::NameToSystemId("drones")));
                            statBoost.sourceRoomIds.push_back(playerShip->GetSystemRoom(ShipSystem::NameToSystemId("engines")));
                            statBoost.sourceRoomIds.push_back(playerShip->GetSystemRoom(ShipSystem::NameToSystemId("hacking")));
                            statBoost.sourceRoomIds.push_back(playerShip->GetSystemRoom(ShipSystem::NameToSystemId("medbay")));
                            statBoost.sourceRoomIds.push_back(playerShip->GetSystemRoom(ShipSystem::NameToSystemId("mind")));
                            statBoost.sourceRoomIds.push_back(playerShip->GetSystemRoom(ShipSystem::NameToSystemId("oxygen")));
                            statBoost.sourceRoomIds.push_back(playerShip->GetSystemRoom(ShipSystem::NameToSystemId("pilot")));
                            statBoost.sourceRoomIds.push_back(playerShip->GetSystemRoom(ShipSystem::NameToSystemId("sensors")));
                            statBoost.sourceRoomIds.push_back(playerShip->GetSystemRoom(ShipSystem::NameToSystemId("shields")));
                            statBoost.sourceRoomIds.push_back(playerShip->GetSystemRoom(ShipSystem::NameToSystemId("teleporter")));
                            statBoost.sourceRoomIds.push_back(playerShip->GetSystemRoom(ShipSystem::NameToSystemId("weapons")));
                        }
                        else
                        {
                            statBoost.sourceRoomIds.push_back(playerShip->GetSystemRoom(ShipSystem::NameToSystemId(system)));
                        }
                    }
                    if (enemyShip != nullptr)
                    {
                        if (system == "all")
                        {
                            statBoost.sourceRoomIds.push_back(enemyShip->GetSystemRoom(ShipSystem::NameToSystemId("artillery")));
                            statBoost.sourceRoomIds.push_back(enemyShip->GetSystemRoom(ShipSystem::NameToSystemId("battery")));
                            statBoost.sourceRoomIds.push_back(enemyShip->GetSystemRoom(ShipSystem::NameToSystemId("cloaking")));
                            statBoost.sourceRoomIds.push_back(enemyShip->GetSystemRoom(ShipSystem::NameToSystemId("clonebay")));
                            statBoost.sourceRoomIds.push_back(enemyShip->GetSystemRoom(ShipSystem::NameToSystemId("doors")));
                            statBoost.sourceRoomIds.push_back(enemyShip->GetSystemRoom(ShipSystem::NameToSystemId("drones")));
                            statBoost.sourceRoomIds.push_back(enemyShip->GetSystemRoom(ShipSystem::NameToSystemId("engines")));
                            statBoost.sourceRoomIds.push_back(enemyShip->GetSystemRoom(ShipSystem::NameToSystemId("hacking")));
                            statBoost.sourceRoomIds.push_back(enemyShip->GetSystemRoom(ShipSystem::NameToSystemId("medbay")));
                            statBoost.sourceRoomIds.push_back(enemyShip->GetSystemRoom(ShipSystem::NameToSystemId("mind")));
                            statBoost.sourceRoomIds.push_back(enemyShip->GetSystemRoom(ShipSystem::NameToSystemId("oxygen")));
                            statBoost.sourceRoomIds.push_back(enemyShip->GetSystemRoom(ShipSystem::NameToSystemId("pilot")));
                            statBoost.sourceRoomIds.push_back(enemyShip->GetSystemRoom(ShipSystem::NameToSystemId("sensors")));
                            statBoost.sourceRoomIds.push_back(enemyShip->GetSystemRoom(ShipSystem::NameToSystemId("shields")));
                            statBoost.sourceRoomIds.push_back(enemyShip->GetSystemRoom(ShipSystem::NameToSystemId("teleporter")));
                            statBoost.sourceRoomIds.push_back(enemyShip->GetSystemRoom(ShipSystem::NameToSystemId("weapons")));
                        }
                        else
                        {
                            statBoost.sourceRoomIds.push_back(enemyShip->GetSystemRoom(ShipSystem::NameToSystemId(system)));
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
}

float CrewMember_Extend::CalculateStat(CrewStat stat, bool &boolValue)
{
    CustomCrewManager *custom = CustomCrewManager::GetInstance();
    auto def = custom->GetDefinition(orig->species);

    std::vector<StatBoost> personalStatBoosts;

    auto it = statBoosts.find(stat);
    if (it != statBoosts.end())
    {
        for (StatBoost statBoost : (*it).second)
        {
            if (statBoost.boostSource == StatBoost::BoostSource::CREW)
            {
                if ((((statBoost.shipTarget == StatBoost::ShipTarget::PLAYER_SHIP && orig->currentShipId == 0) || (statBoost.shipTarget == StatBoost::ShipTarget::ENEMY_SHIP && orig->currentShipId == 1)) || (statBoost.shipTarget == StatBoost::ShipTarget::CURRENT_ALL && orig->currentShipId == statBoost.crewSource->currentShipId) || (statBoost.shipTarget == StatBoost::ShipTarget::CURRENT_ROOM && orig->iRoomId == statBoost.crewSource->iRoomId && orig->currentShipId == statBoost.crewSource->currentShipId) || (statBoost.shipTarget == StatBoost::ShipTarget::ALL))
                    && (statBoost.crewSource != orig || statBoost.affectsSelf)
                    && ((statBoost.crewSource->iShipId == orig->iShipId && statBoost.crewTarget == StatBoost::CrewTarget::ALLIES) || (statBoost.crewSource->iShipId != orig->iShipId && statBoost.crewTarget == StatBoost::CrewTarget::ENEMIES) || statBoost.crewTarget == StatBoost::CrewTarget::ALL)
                    && ((std::find(statBoost.whiteList.begin(), statBoost.whiteList.end(), orig->species) != statBoost.whiteList.end()) || (!statBoost.blackList.empty() && std::find(statBoost.blackList.begin(), statBoost.blackList.end(), orig->species) == statBoost.blackList.end()) || (statBoost.blackList.empty() && statBoost.whiteList.empty()))
                    && (statBoost.systemList.empty() || (std::find(statBoost.sourceRoomIds.begin(), statBoost.sourceRoomIds.end(), orig->iRoomId) != statBoost.sourceRoomIds.end() && statBoost.systemRoomTarget == StatBoost::SystemRoomTarget::ALL) || (std::find(statBoost.sourceRoomIds.begin(), statBoost.sourceRoomIds.end(), orig->iRoomId) == statBoost.sourceRoomIds.end() && statBoost.systemRoomTarget == StatBoost::SystemRoomTarget::NONE))
                    ) // If the boost affects this ship and/or this room, and the boost comes from someone else or affects self, and the boost comes from an ally and affects allies or an enemy and affects enemies, and the boost specifically lets this race take it or doesn't ban it
                {
                    personalStatBoosts.push_back(statBoost);
                }
            }

            if (statBoost.boostSource == StatBoost::BoostSource::AUGMENT)
            {
                if (((statBoost.shipTarget == StatBoost::ShipTarget::PLAYER_SHIP && orig->currentShipId == 0) || (statBoost.shipTarget == StatBoost::ShipTarget::ENEMY_SHIP && orig->currentShipId == 1) || (statBoost.shipTarget == StatBoost::ShipTarget::CURRENT_ALL && orig->currentShipId == statBoost.sourceShipId) || (statBoost.shipTarget == StatBoost::ShipTarget::ALL))
                    && ((statBoost.sourceShipId == orig->iShipId && statBoost.crewTarget == StatBoost::CrewTarget::ALLIES) || (statBoost.sourceShipId != orig->iShipId && statBoost.crewTarget == StatBoost::CrewTarget::ENEMIES) ||  (statBoost.crewTarget == StatBoost::CrewTarget::ALL))
                    && ((std::find(statBoost.whiteList.begin(), statBoost.whiteList.end(), orig->species) != statBoost.whiteList.end()) || (!statBoost.blackList.empty() && std::find(statBoost.blackList.begin(), statBoost.blackList.end(), orig->species) == statBoost.blackList.end()) || (statBoost.blackList.empty() && statBoost.whiteList.empty()))
                    && (statBoost.systemList.empty() || (std::find(statBoost.sourceRoomIds.begin(), statBoost.sourceRoomIds.end(), orig->iRoomId) != statBoost.sourceRoomIds.end() && statBoost.systemRoomTarget == StatBoost::SystemRoomTarget::ALL) || (std::find(statBoost.sourceRoomIds.begin(), statBoost.sourceRoomIds.end(), orig->iRoomId) == statBoost.sourceRoomIds.end() && statBoost.systemRoomTarget == StatBoost::SystemRoomTarget::NONE))
                    )
                {
                    personalStatBoosts.push_back(statBoost);
                }
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
        case CrewStat::CAN_FIGHT:
            boolValue = (temporaryPowerActive && def.powerDef.tempPower.canFight.enabled) ? def.powerDef.tempPower.canFight.value : def.canFight;
            isBool = true;
            break;
        case CrewStat::CAN_REPAIR:
            boolValue = (temporaryPowerActive && def.powerDef.tempPower.canFight.enabled) ? def.powerDef.tempPower.canFight.value : def.canFight;
            isBool = true;
            break;
        case CrewStat::CAN_SABOTAGE:
            boolValue = (temporaryPowerActive && def.powerDef.tempPower.canFight.enabled) ? def.powerDef.tempPower.canFight.value : def.canFight;
            isBool = true;
            break;
        case CrewStat::CAN_MAN:
            boolValue = (temporaryPowerActive && def.powerDef.tempPower.canMan.enabled) ? def.powerDef.tempPower.canMan.value : def.canMan;
            isBool = true;
            break;
        case CrewStat::CAN_SUFFOCATE:
            boolValue = (temporaryPowerActive && def.powerDef.tempPower.canFight.enabled) ? def.powerDef.tempPower.canFight.value : def.canFight;
            isBool = true;
            break;
        case CrewStat::CONTROLLABLE:
            boolValue = (temporaryPowerActive && def.powerDef.tempPower.canFight.enabled) ? def.powerDef.tempPower.canFight.value : def.canFight;
            isBool = true;
            break;
        case CrewStat::CAN_BURN:
            boolValue = (temporaryPowerActive && def.powerDef.tempPower.canFight.enabled) ? def.powerDef.tempPower.canFight.value : def.canFight;
            isBool = true;
            break;
        case CrewStat::IS_TELEPATHIC:
            boolValue = (temporaryPowerActive && def.powerDef.tempPower.canFight.enabled) ? def.powerDef.tempPower.canFight.value : def.canFight;
            isBool = true;
            break;
        case CrewStat::IS_ANAEROBIC:
            boolValue = (temporaryPowerActive && def.powerDef.tempPower.canFight.enabled) ? def.powerDef.tempPower.canFight.value : def.canFight;
            isBool = true;
            break;
        case CrewStat::CAN_PHASE_THROUGH_DOORS:
            boolValue = (temporaryPowerActive && def.powerDef.tempPower.canFight.enabled) ? def.powerDef.tempPower.canFight.value : def.canFight;
            isBool = true;
            break;
        case CrewStat::DETECTS_LIFEFORMS:
            boolValue = (temporaryPowerActive && def.powerDef.tempPower.canFight.enabled) ? def.powerDef.tempPower.canFight.value : def.canFight;
            isBool = true;
            break;
        case CrewStat::CLONE_LOSE_SKILLS:
            boolValue = (temporaryPowerActive && def.powerDef.tempPower.canFight.enabled) ? def.powerDef.tempPower.canFight.value : def.canFight;
            isBool = true;
            break;
        case CrewStat::POWER_DRAIN_FRIENDLY:
            boolValue = (temporaryPowerActive && def.powerDef.tempPower.canFight.enabled) ? def.powerDef.tempPower.canFight.value : def.canFight;
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
                    boolValue = statBoost.value;
                }
                else if (statBoost.boostType == StatBoost::BoostType::FLIP)
                {
                    boolValue = !boolValue;
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
        orig->health.first *= (int)finalStat / orig->health.second;
    }
    return finalStat;
}

#pragma GCC pop_options
