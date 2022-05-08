#pragma GCC push_options
#pragma GCC optimize ("O3")

#include "CrewMember_Extend.h"
#include "Room_Extend.h"
#include "StatBoost.h"
#include "CustomCrew.h"
#include "CustomAugments.h"
#include <algorithm>
#include <boost/lexical_cast.hpp>
#include <math.h>
//#include <chrono>
//#include <iostream>

const std::array<std::string, numStats> crewStats =
{
    "maxHealth",
    "stunMultiplier",
    "moveSpeedMultiplier",
    "repairSpeed",
    "damageMultiplier",
    "rangedDamageMultiplier",
    "doorDamageMultiplier",
    "fireRepairMultiplier",
    "suffocationModifier",
    "fireDamageMultiplier",
    "oxygenChangeSpeed",
    "damageTakenMultiplier",
    "passiveHealAmount",
    "truePassiveHealAmount",
    "trueHealAmount",
    "passiveHealDelay",
    "healAmount",
    "sabotageSpeedMultiplier",
    "allDamageTakenMultiplier",
    "healSpeed",
    "healCrewAmount",
    "damageEnemiesAmount",
    "bonusPower",
    "powerDrain",
    "essential",
    "canFight",
    "canRepair",
    "canSabotage",
    "canMan",
    "canTeleport",
    "canSuffocate",
    "controllable",
    "canBurn",
    "isTelepathic",
    "resistsMindControl",
    "isAnaerobic",
    "canPhaseThroughDoors",
    "detectsLifeforms",
    "cloneLoseSkills",
    "powerDrainFriendly",
    "activateWhenReady",
    "defaultSkillLevel",
    "powerRechargeMultiplier",
    "powerCharges",
    "chargesPerJump",
    "hackDoors",
    "noClone",
    "noSlot",
    "noAI",
    "validTarget",
    "rooted",
    "teleportMove",
    "teleportMoveOtherShip",
    // non-cached stats
    "statBoost",
    "deathEffect",
    "powerEffect",
    "transformRace"
};

std::vector<StatBoostDefinition*> StatBoostDefinition::statBoostDefs = std::vector<StatBoostDefinition*>();
std::unordered_map<std::string,StatBoostDefinition*> StatBoostDefinition::savedStatBoostDefs = std::unordered_map<std::string,StatBoostDefinition*>();
unsigned int StatBoostManager::statCacheFrame = 1;

StatBoostManager StatBoostManager::instance = StatBoostManager();

StatBoostDefinition* StatBoostManager::ParseStatBoostNode(rapidxml::xml_node<char>* node, StatBoostDefinition::BoostSource boostSource, bool isRoomBased)
{
    StatBoostDefinition *def;
    bool newDef = false;

    if (node->first_attribute("load"))
    {
        auto savedDef = StatBoostDefinition::savedStatBoostDefs.find(node->first_attribute("load")->value());
        if (savedDef != StatBoostDefinition::savedStatBoostDefs.end())
        {
            if (node->first_attribute("name") || *(node->value()) || node->first_node()) // not empty statboost node
            {
                def = new StatBoostDefinition(*savedDef->second);
                newDef = true;
            }
            else
            {
                def = savedDef->second;
                if (boostSource != def->boostSource || isRoomBased != def->isRoomBased)
                {
                    newDef = true; // mismatched source needs a new def
                }
            }
        }
        else
        {
            ErrorMessage(std::string("Unable to load stat boost:\n") + std::string(node->first_attribute("load")->value()));
            def = new StatBoostDefinition();
            newDef = true;
        }
    }
    else
    {
        def = new StatBoostDefinition();
        newDef = true;
    }

    if (newDef)
    {
        def->GiveId();
        def->boostSource = boostSource;
        def->isRoomBased = isRoomBased;
        auto stat = std::find(crewStats.begin(), crewStats.end(), node->first_attribute("name")->value());
        if (stat != crewStats.end())
        {
            int statId = stat - crewStats.begin();
            def->stat = static_cast<CrewStat>(statId);
            for (auto child = node->first_node(); child; child = child->next_sibling())
            {
                std::string name = child->name();
                std::string val = child->value();
                if (name == "statBoost")
                {
                    def->providedStatBoosts.push_back(ParseStatBoostNode(child, StatBoostDefinition::BoostSource::CREW, false));
                }
                if (name == "boostType")
                {
                    if (val == "MULT")
                    {
                        def->boostType = StatBoostDefinition::BoostType::MULT;
                    }
                    if (val == "FLAT")
                    {
                        def->boostType = StatBoostDefinition::BoostType::FLAT;
                    }
                    if (val == "SET")
                    {
                        def->boostType = StatBoostDefinition::BoostType::SET;
                    }
                    if (val == "FLIP")
                    {
                        def->boostType = StatBoostDefinition::BoostType::FLIP;
                    }
                    if (val == "MIN")
                    {
                        def->boostType = StatBoostDefinition::BoostType::MIN;
                    }
                    if (val == "MAX")
                    {
                        def->boostType = StatBoostDefinition::BoostType::MAX;
                    }
                }

                if (name == "amount")
                {
                    def->amount = boost::lexical_cast<float>(val);
                }
                if (name == "value")
                {
                    def->value = EventsParser::ParseBoolean(val);
                }
                if (name == "dangerRating")
                {
                    def->dangerRating = boost::lexical_cast<float>(val);
                }

                if (name == "race" && def->stat == CrewStat::TRANSFORM_RACE)
                {
                    def->stringValue = val;
                }
                if (name == "permanent" && def->stat == CrewStat::TRANSFORM_RACE)
                {
                    def->value = EventsParser::ParseBoolean(val);
                }
                if (name == "duration")
                {
                    def->duration = boost::lexical_cast<float>(val);
                }
                if (name == "priority")
                {
                    def->priority = boost::lexical_cast<int>(val);
                }
                if (name == "boostAnim")
                {
                    def->boostAnim = val;
                }
                if (name == "roomAnim")
                {
                    def->roomAnim = new RoomAnimDef();
                    def->roomAnim->ParseRoomAnimNode(child);
                }
                if (name == "affectsSelf")
                {
                    def->affectsSelf = EventsParser::ParseBoolean(val);
                }
                if (name == "shipTarget")
                {
                    if (val == "PLAYER_SHIP")
                    {
                        def->shipTarget = StatBoostDefinition::ShipTarget::PLAYER_SHIP;
                    }
                    if (val == "ENEMY_SHIP")
                    {
                        def->shipTarget = StatBoostDefinition::ShipTarget::ENEMY_SHIP;
                    }
                    if (val == "CURRENT_ALL")
                    {
                        def->shipTarget = StatBoostDefinition::ShipTarget::CURRENT_ALL;
                    }
                    if (val == "CURRENT_ROOM")
                    {
                        def->shipTarget = StatBoostDefinition::ShipTarget::CURRENT_ROOM;
                    }
                    if (val == "OTHER_ALL")
                    {
                        def->shipTarget = StatBoostDefinition::ShipTarget::OTHER_ALL;
                    }
                    if (val == "ORIGINAL_SHIP")
                    {
                        def->shipTarget = StatBoostDefinition::ShipTarget::ORIGINAL_SHIP;
                    }
                    if (val == "ORIGINAL_OTHER_SHIP")
                    {
                        def->shipTarget = StatBoostDefinition::ShipTarget::ORIGINAL_OTHER_SHIP;
                    }
                    if (val == "ALL")
                    {
                        def->shipTarget = StatBoostDefinition::ShipTarget::ALL;
                    }
                    if (val == "CREW_TARGET")
                    {
                        def->shipTarget = StatBoostDefinition::ShipTarget::CREW_TARGET;
                    }
                    if (val == "TARGETS_ME")
                    {
                        def->shipTarget = StatBoostDefinition::ShipTarget::TARGETS_ME;
                    }
                }
                if (name == "systemRoomTarget")
                {
                    if (val == "ALL")
                    {
                        def->systemRoomTarget = StatBoostDefinition::SystemRoomTarget::ALL;
                    }
                    if (val == "NONE")
                    {
                        def->systemRoomTarget = StatBoostDefinition::SystemRoomTarget::NONE;
                    }
                }
                if (name == "crewTarget")
                {
                    if (val == "ALLIES")
                    {
                        def->crewTarget = StatBoostDefinition::CrewTarget::ALLIES;
                    }
                    if (val == "ENEMIES")
                    {
                        def->crewTarget = StatBoostDefinition::CrewTarget::ENEMIES;
                    }
                    if (val == "ALL")
                    {
                        def->crewTarget = StatBoostDefinition::CrewTarget::ALL;
                    }
                    if (val == "CURRENT_ALLIES")
                    {
                        def->crewTarget = StatBoostDefinition::CrewTarget::CURRENT_ALLIES;
                    }
                    if (val == "CURRENT_ENEMIES")
                    {
                        def->crewTarget = StatBoostDefinition::CrewTarget::CURRENT_ENEMIES;
                    }
                    if (val == "ORIGINAL_ALLIES")
                    {
                        def->crewTarget = StatBoostDefinition::CrewTarget::ORIGINAL_ALLIES;
                    }
                    if (val == "ORIGINAL_ENEMIES")
                    {
                        def->crewTarget = StatBoostDefinition::CrewTarget::ORIGINAL_ENEMIES;
                    }
                    if (val == "SELF")
                    {
                        def->crewTarget = StatBoostDefinition::CrewTarget::SELF;
                        def->affectsSelf = true;
                    }
                    if (val == "NONE")
                    {
                        def->crewTarget = StatBoostDefinition::CrewTarget::SELF;
                    }
                }
                if (name == "droneTarget")
                {
                    if (val == "DRONES")
                    {
                        def->droneTarget = StatBoostDefinition::DroneTarget::DRONES;
                    }
                    if (val == "CREW")
                    {
                        def->droneTarget = StatBoostDefinition::DroneTarget::CREW;
                    }
                    if (val == "ALL")
                    {
                        def->droneTarget = StatBoostDefinition::DroneTarget::ALL;
                    }
                }
                if (name == "functionalTarget")
                {
                    def->functionalTarget = EventsParser::ParseBoolean(val);;
                }
                if (name == "whiteList")
                {
                    if (child->first_attribute("load"))
                    {
                        def->whiteList = G_->GetBlueprints()->GetBlueprintList(child->first_attribute("load")->value());
                    }
                    for (auto crewChild = child->first_node(); crewChild; crewChild = crewChild->next_sibling())
                    {
                        if (strcmp(crewChild->name(), "blueprintList") == 0 && crewChild->first_attribute("load"))
                        {
                            std::vector<std::string> tempList = G_->GetBlueprints()->GetBlueprintList(crewChild->first_attribute("load")->value());
                            def->whiteList.insert(def->whiteList.end(),tempList.begin(),tempList.end());
                        }
                        else
                        {
                            def->whiteList.push_back(crewChild->name());
                        }
                    }
                    def->whiteList.shrink_to_fit();
                }
                if (name == "blackList")
                {
                    if (child->first_attribute("load"))
                    {
                        def->blackList = G_->GetBlueprints()->GetBlueprintList(child->first_attribute("load")->value());
                    }
                    for (auto crewChild = child->first_node(); crewChild; crewChild = crewChild->next_sibling())
                    {
                        if (strcmp(crewChild->name(), "blueprintList") == 0 && crewChild->first_attribute("load"))
                        {
                            std::vector<std::string> tempList = G_->GetBlueprints()->GetBlueprintList(crewChild->first_attribute("load")->value());
                            def->blackList.insert(def->blackList.end(),tempList.begin(),tempList.end());
                        }
                        else
                        {
                            def->blackList.push_back(crewChild->name());
                        }
                    }
                    def->blackList.shrink_to_fit();
                }
                if (name == "healthReq")
                {
                    if (child->first_attribute("min")) def->healthReq.first = boost::lexical_cast<float>(child->first_attribute("min")->value());
                    if (child->first_attribute("max")) def->healthReq.second = boost::lexical_cast<float>(child->first_attribute("max")->value());
                    if (child->first_attribute("above")) def->healthReq.first = std::nextafterf(boost::lexical_cast<float>(child->first_attribute("above")->value()), +HUGE_VAL);
                    if (child->first_attribute("below")) def->healthReq.second = std::nextafterf(boost::lexical_cast<float>(child->first_attribute("below")->value()), -HUGE_VAL);
                }
                if (name == "healthFractionReq")
                {
                    if (child->first_attribute("min")) def->healthFractionReq.first = boost::lexical_cast<float>(child->first_attribute("min")->value());
                    if (child->first_attribute("max")) def->healthFractionReq.second = boost::lexical_cast<float>(child->first_attribute("max")->value());
                    if (child->first_attribute("above")) def->healthFractionReq.first = std::nextafterf(boost::lexical_cast<float>(child->first_attribute("above")->value()), +HUGE_VAL);
                    if (child->first_attribute("below")) def->healthFractionReq.second = std::nextafterf(boost::lexical_cast<float>(child->first_attribute("below")->value()), -HUGE_VAL);
                }
                if (name == "oxygenReq")
                {
                    if (child->first_attribute("min")) def->oxygenReq.first = boost::lexical_cast<float>(child->first_attribute("min")->value());
                    if (child->first_attribute("max")) def->oxygenReq.second = boost::lexical_cast<float>(child->first_attribute("max")->value());
                    if (child->first_attribute("above")) def->oxygenReq.first = std::nextafterf(boost::lexical_cast<float>(child->first_attribute("above")->value()), +HUGE_VAL);
                    if (child->first_attribute("below")) def->oxygenReq.second = std::nextafterf(boost::lexical_cast<float>(child->first_attribute("below")->value()), -HUGE_VAL);
                }
                if (name == "fireCount")
                {
                    if (child->first_attribute("min")) def->fireCount.first = boost::lexical_cast<int>(child->first_attribute("min")->value());
                    if (child->first_attribute("max")) def->fireCount.second = boost::lexical_cast<int>(child->first_attribute("max")->value());
                }
                if (name == "extraConditions")
                {
                    auto &extraConditions = (child->first_attribute("type") && strcmp(child->first_attribute("type")->value(), "or") == 0) ? def->extraOrConditions : def->extraConditions;
                    CustomCrewManager::GetInstance()->ParseExtraConditionsNode(child, extraConditions);
                }
                if (name == "systemList")
                {
                    for (auto crewChild = child->first_node(); crewChild; crewChild = crewChild->next_sibling())
                    {
                        def->systemList.push_back(crewChild->name());
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
                                def->systemPowerScaling.push_back(i);
                            }
                        }
                        else if (systemChildName == "reactorMax")
                        {
                            def->systemPowerScaling.push_back(16);
                        }
                        else if (systemChildName == "reactorCurrent")
                        {
                            def->systemPowerScaling.push_back(17);
                        }
                        else
                        {
                            def->systemPowerScaling.push_back(ShipSystem::NameToSystemId(systemChildName));
                        }
                    }
                }
                if (name == "systemPowerScaling")
                {
                    bool noSys = false;
                    bool hackedSys = false;

                    for (auto systemChild = child->first_node(); systemChild; systemChild = systemChild->next_sibling())
                    {
                        std::string systemChildName = systemChild->name();

                        if (systemChildName == "noSys")
                        {
                            noSys = true;
                            def->powerScalingNoSys = boost::lexical_cast<float>(systemChild->value());
                        }
                        else if (systemChildName == "hackedSys")
                        {
                            hackedSys = true;
                            def->powerScalingHackedSys = boost::lexical_cast<float>(systemChild->value());
                        }
                        else
                        {
                            def->powerScaling.push_back(boost::lexical_cast<float>(systemChild->value()));
                        }
                    }

                    if (def->powerScaling.size())
                    {
                        if (!noSys)
                        {
                            def->powerScalingNoSys = def->powerScaling.at(0);
                        }
                        if (!hackedSys)
                        {
                            def->powerScalingHackedSys = def->powerScaling.at(0);
                        }
                    }
                }
                if (name == "maxStacks")
                {
                    if (!val.empty())
                    {
                        def->maxStacks = boost::lexical_cast<int>(val);
                    }
                    if (child->first_attribute("id"))
                    {
                        def->stackId = GiveStackId(child->first_attribute("id")->value());
                    }
                    else
                    {
                        def->stackId = GiveStackId();
                    }
                }
                if (name == "deathEffect")
                {
                    def->deathEffectChange = new ExplosionDefinition();

                    def->deathEffectChange->damage.ownerId = -1;
                    def->deathEffectChange->damage.selfId = -1;
                    def->deathEffectChange->damage.crystalShard = false;

                    if (def->boostType == StatBoostDefinition::BoostType::MULT)
                    {
                        def->deathEffectChange->damage.iDamage = 1;
                        def->deathEffectChange->damage.iShieldPiercing = 1;
                        def->deathEffectChange->damage.fireChance = 1;
                        def->deathEffectChange->damage.breachChance = 1;
                        def->deathEffectChange->damage.stunChance = 1;
                        def->deathEffectChange->damage.iIonDamage = 1;
                        def->deathEffectChange->damage.iSystemDamage = 1;
                        def->deathEffectChange->damage.iPersDamage = 1;
                        def->deathEffectChange->damage.bHullBuster = true;
                        def->deathEffectChange->damage.bLockdown = true;
                        def->deathEffectChange->damage.bFriendlyFire = true;
                        def->deathEffectChange->damage.iStun = 1;

                        def->deathEffectChange->shipFriendlyFire = true;
                        def->deathEffectChange->transformRaceDeathSound = true;
                        def->deathEffectChange->transformRaceHealth = 1.f;
                    }
                    else
                    {
                        def->deathEffectChange->damage.iDamage = 0;
                        def->deathEffectChange->damage.iShieldPiercing = 0;
                        def->deathEffectChange->damage.fireChance = 0;
                        def->deathEffectChange->damage.breachChance = 0;
                        def->deathEffectChange->damage.stunChance = 0;
                        def->deathEffectChange->damage.iIonDamage = 0;
                        def->deathEffectChange->damage.iSystemDamage = 0;
                        def->deathEffectChange->damage.iPersDamage = 0;
                        def->deathEffectChange->damage.bHullBuster = false;
                        def->deathEffectChange->damage.bLockdown = false;
                        def->deathEffectChange->damage.bFriendlyFire = false;
                        def->deathEffectChange->damage.iStun = 0;

                        if (def->boostType == StatBoostDefinition::BoostType::FLAT)
                        {
                            def->deathEffectChange->transformRaceHealthFraction = 0.f;
                        }
                    }

                    CustomCrewManager::GetInstance()->ParseDeathEffect(child, def->deathEffectChange);
                }
                if (name == "powerEffect")
                {
                    ActivatedPowerDefinition powerDef;
                    CustomCrewManager::GetInstance()->ParseAbilityEffect(child, &powerDef);
                    powerDef.AssignIndex();
                    def->powerChange = powerDef.index;
                }
            }
        }
        else
        {
            throw std::invalid_argument(std::string("Unrecognized stat boost stat name: ") + node->first_attribute("name")->value());
        }
    }
    if (node->first_attribute("save"))
    {
        StatBoostDefinition::savedStatBoostDefs[node->first_attribute("save")->value()] = def;
    }
    return def;
}

void StatBoostManager::CreateAugmentBoost(StatBoostDefinition* def, int shipId, int nStacks)
{
    StatBoost statBoost = StatBoost(def);
    statBoost.iStacks = nStacks;

    statBoost.sourceShipId = shipId;
    statBoost.crewSourceId = 0;

    if (!def->systemList.empty())
    {
        for (auto system : def->systemList)
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

    auto it = statBoosts.find(def->stat);
    if (statBoosts.find(def->stat) != statBoosts.end())
    {
        (*it).second.push_back(statBoost);
    }
    else
    {
        std::vector<StatBoost> newVector = std::vector<StatBoost>();

        newVector.push_back(statBoost);

        statBoosts[def->stat] = newVector;
    }

    if (statBoost.def->boostAnim != "")
    {
        animBoosts.push_back(statBoost);
    }

    if (statBoost.def->dangerRating != -1.f)
    {
        dangerBoosts.push_back(statBoost);
    }

    CreateRecursiveBoosts(statBoost, nStacks);
}

void StatBoostManager::CreateCrewBoost(StatBoostDefinition* def, CrewMember* otherCrew, CrewMember_Extend* ex, int nStacks)
{
    StatBoost statBoost = StatBoost(def);
    statBoost.iStacks = nStacks;

    statBoost.crewSource = otherCrew;
    statBoost.crewSourceId = ex->selfId;
    CreateCrewBoost(statBoost, otherCrew);
}

void StatBoostManager::CreateCrewBoost(StatBoost statBoost, CrewMember* otherCrew)
{
    statBoost.sourceShipId = otherCrew->iShipId; // the owner of the source crew
    if (!statBoost.def->systemList.empty())
    {
        for (auto system : statBoost.def->systemList)
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

    auto it = statBoosts.find(statBoost.def->stat);
    if (statBoosts.find(statBoost.def->stat) != statBoosts.end())
    {
        (*it).second.push_back(statBoost);
    }
    else
    {
        std::vector<StatBoost> newVector = std::vector<StatBoost>();

        newVector.push_back(statBoost);

        statBoosts[statBoost.def->stat] = newVector;
    }

    if (statBoost.def->boostAnim != "")
    {
        animBoosts.push_back(statBoost);
    }

    if (statBoost.def->dangerRating != -1.f)
    {
        dangerBoosts.push_back(statBoost);
    }

    CreateRecursiveBoosts(statBoost, 1);
}

void StatBoostManager::CreateRecursiveBoosts(StatBoost& statBoost, int nStacks, bool noCheck)
{
    if (!statBoost.def->providedStatBoosts.empty())
    {
        for (auto recursiveCrew : checkingCrewList)
        {
            auto ex = CM_EX(recursiveCrew);
            if (noCheck || ex->BoostCheck(statBoost))
            {
                int recursiveCrewStacks = nStacks;
                if (statBoost.def->stackId)
                {
                    int& currentStacks = recursiveStackCount[recursiveCrew][statBoost.def->stackId];
                    int maxStacks = statBoost.def->maxStacks - currentStacks;
                    if (maxStacks <= 0) continue;
                    if (recursiveCrewStacks > maxStacks) recursiveCrewStacks = maxStacks;
                    currentStacks += recursiveCrewStacks;
                }
                for (StatBoostDefinition* recursiveBoostDef : statBoost.def->providedStatBoosts)
                {
                    CreateCrewBoost(recursiveBoostDef, recursiveCrew, ex, recursiveCrewStacks);
                }
            }
        }
    }
}

void StatBoostManager::AddRoomStatBoosts(ShipManager *ship)
{
    for (Room *room : ship->ship.vRoomList)
    {
        for (RoomStatBoost &roomBoost : RM_EX(room)->statBoosts)
        {
            statBoosts[roomBoost.statBoost.def->stat].push_back(roomBoost.statBoost);

            if (roomBoost.statBoost.def->boostAnim != "")
            {
                animBoosts.push_back(roomBoost.statBoost);
            }

            if (roomBoost.statBoost.def->dangerRating != -1.f)
            {
                dangerBoosts.push_back(roomBoost.statBoost);
            }
        }
    }
}

void StatBoostManager::OnLoop(WorldManager* world)
{
    Clear();

    playerShip = world->playerShip->shipManager;
    enemyShip = world->playerShip->enemyShip ? world->playerShip->enemyShip->shipManager : nullptr;

    if (playerShip != nullptr)
    {
        std::copy_if(playerShip->vCrewList.begin(), playerShip->vCrewList.end(), std::back_inserter(checkingCrewList), [](CrewMember *i){return !i->bDead;});
        StatBoostManager::AddRoomStatBoosts(playerShip);
    }
    if (enemyShip != nullptr)
    {
        std::copy_if(enemyShip->vCrewList.begin(), enemyShip->vCrewList.end(), std::back_inserter(checkingCrewList), [](CrewMember *i){return !i->bDead;});
        StatBoostManager::AddRoomStatBoosts(enemyShip);
    }

    // Check augment stat boosts

    CustomAugmentManager* customAug = CustomAugmentManager::GetInstance();

    for (int shipId = 0; shipId < 2; shipId++)
    {
        if (G_->GetShipInfo(shipId) != nullptr)
        {
            std::unordered_map<std::string, int> *augMap = customAug->GetShipAugments(shipId);
            for (auto augPair : *augMap)
            {
                if (customAug->IsAugment(augPair.first) && augPair.second > 0)
                {
                    for (StatBoostDefinition* statBoostDef : customAug->GetAugmentDefinition(augPair.first)->statBoosts)
                    {
                        if (statBoostDef->duration == -1)
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
        bool functional = otherCrew->Functional();

        auto ex = CM_EX(otherCrew);

        if (functional)
        {
            auto currentStatBoosts = std::vector<StatBoost>();

            if (ex->temporaryPowerActive)
            {
                currentStatBoosts = ex->outgoingAbilityStatBoosts;
            }
            else
            {
                currentStatBoosts = ex->outgoingStatBoosts;
            }

            for (auto& statBoost : currentStatBoosts)
            {
                CreateCrewBoost(statBoost, otherCrew);
            }
        }

        auto vStatBoosts = ex->timedStatBoosts.find(CrewStat::STAT_BOOST);
        if (vStatBoosts != ex->timedStatBoosts.end())
        {
            for (StatBoost& statBoost : vStatBoosts->second)
            {
                CreateRecursiveBoosts(statBoost, statBoost.iStacks, true);
            }
        }
    }

    checkingCrewList.clear();
    recursiveStackCount.clear();
    statCacheFrame++;
}

void StatBoostManager::CreateTimedAugmentBoost(StatBoost statBoost, CrewMember* crew)
{
    auto ex = CM_EX(crew);

    if (ex->BoostCheck(statBoost))
    {
        statBoost.timerHelper = TimerHelper(false);

        if (statBoost.def->duration != -1.f)
        {
            statBoost.timerHelper.Start(statBoost.def->duration);
        }
        else
        {
            statBoost.timerHelper.currTime = 0.f;
            statBoost.timerHelper.currGoal = 0.f;
            statBoost.timerHelper.running = false;
        }

        auto &vStatBoosts = ex->timedStatBoosts[statBoost.def->stat];

        if (statBoost.def->duration == -1.f) // optimization for persistent stacking boosts
        {
            for (auto& otherBoost : vStatBoosts)
            {
                if (otherBoost.def == statBoost.def)
                {
                    otherBoost.iStacks = std::min(otherBoost.iStacks + statBoost.iStacks, statBoost.def->maxStacks);
                    return;
                }
            }
        }

        vStatBoosts.push_back(statBoost);
    }
}

HOOK_METHOD(WorldManager, CreateNewGame, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> WorldManager::CreateNewGame -> Begin (StatBoost.cpp)\n")
    StatBoostManager::GetInstance()->Clear();
    super();
}

HOOK_METHOD(WorldManager, LoadGame, (const std::string& fileName) -> void)
{
    LOG_HOOK("HOOK_METHOD -> WorldManager::LoadGame -> Begin (StatBoost.cpp)\n")
    StatBoostManager::GetInstance()->Clear();
    super(fileName);
}

HOOK_METHOD(WorldManager, OnLoop, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> WorldManager::OnLoop -> Begin (StatBoost.cpp)\n")
    StatBoostManager::GetInstance()->OnLoop(this);
    super();
//    using std::chrono::steady_clock;
//    using std::chrono::duration_cast;
//    using std::chrono::duration;
//    using std::chrono::milliseconds;
//    auto t1 = steady_clock::now();



//    auto t2 = steady_clock::now();
//    duration<double, std::nano> ms_double = t2 - t1;
//    std::cout << "World manager time: " << ms_double.count();
}

HOOK_METHOD(ShipBuilder, OnLoop, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipBuilder::OnLoop -> Begin (StatBoost.cpp)\n")
    StatBoostManager::GetInstance()->Clear();
    StatBoostManager::GetInstance()->statCacheFrame++;
    super();
//    using std::chrono::steady_clock;
//    using std::chrono::duration_cast;
//    using std::chrono::duration;
//    using std::chrono::milliseconds;
//    auto t1 = steady_clock::now();



//    auto t2 = steady_clock::now();
//    duration<double, std::nano> ms_double = t2 - t1;
//    std::cout << "World manager time: " << ms_double.count();
}

HOOK_METHOD(WorldManager, Restart, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> WorldManager::Restart -> Begin (StatBoost.cpp)\n")
    StatBoostManager::GetInstance()->Clear();
    StatBoostManager::GetInstance()->statCacheFrame++;
    super();
}

HOOK_METHOD(CrewMemberFactory, RemoveExcessCrew, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewMemberFactory::RemoveExcessCrew -> Begin (StatBoost.cpp)\n")

    // RemoveExcessCrew frees dead crew from memory; need to reset stat boosts in case a stat boost references such a crewmember
    super();

    WorldManager *worldManager = G_->GetWorld();
    StatBoostManager *statBoostManager = StatBoostManager::GetInstance();

    if (worldManager->bStartedGame)
    {
        statBoostManager->OnLoop(worldManager);
    }
    else
    {
        StatBoostManager::GetInstance()->Clear();
        statBoostManager->statCacheFrame++;
    }

    for (CrewMember *crew : crewMembers)
    {
        CrewMember_Extend *ex = CM_EX(crew);
        for (auto& vStatBoost : ex->timedStatBoosts)
        {
            for (StatBoost& statBoost : vStatBoost.second)
            {
                if (statBoost.def->boostSource == StatBoostDefinition::BoostSource::CREW)
                {
                    bool found = false;
                    for (CrewMember *crew2 : crewMembers)
                    {
                        CrewMember_Extend *ex2 = CM_EX(crew2);
                        if (ex2->selfId == statBoost.crewSourceId)
                        {
                            statBoost.crewSource = crew2;
                            found = true;
                            break;
                        }
                    }
                    if (!found) statBoost.crewSource = nullptr;
                }
            }
        }
    }
}

void StatBoost::FindCrewSource()
{
    if (def->boostSource == StatBoostDefinition::BoostSource::CREW)
    {
        CrewMemberFactory *crewFactory = G_->GetCrewFactory();

        crewSource = nullptr;
        for (CrewMember *crew : crewFactory->crewMembers)
        {
            CrewMember_Extend *ex = CM_EX(crew);
            if (ex->selfId == crewSourceId)
            {
                crewSource = crew;
                break;
            }
        }
    }
}

HOOK_METHOD(BossShip, LoadBoss, (int fh) -> void)
{
    LOG_HOOK("HOOK_METHOD -> BossShip::LoadBoss -> Begin (StatBoost.cpp)\n")
    super(fh);

    for (StatBoost *statBoost : StatBoostManager::GetInstance()->loadingStatBoosts)
    {
        statBoost->FindCrewSource();
    }

    StatBoostManager::GetInstance()->loadingStatBoosts.clear();
}

// Save/load stat boosts

void StatBoost::Save(int fd)
{
    FileHelper::writeInt(fd, def->realBoostId);
    FileHelper::writeInt(fd, iStacks);
    FileHelper::writeInt(fd, crewSourceId);
    FileHelper::writeInt(fd, sourceShipId);
    FileHelper::writeFloat(fd, timerHelper.currGoal);
    FileHelper::writeFloat(fd, timerHelper.currTime);
}

StatBoost StatBoost::LoadStatBoost(int fd)
{
    StatBoost statBoost(StatBoostDefinition::statBoostDefs.at(FileHelper::readInteger(fd)));
    statBoost.iStacks = FileHelper::readInteger(fd);
    statBoost.crewSourceId = FileHelper::readInteger(fd);
    statBoost.sourceShipId = FileHelper::readInteger(fd);

    if (statBoost.def->duration != -1.f)
    {
        statBoost.timerHelper.Start(FileHelper::readFloat(fd));
        statBoost.timerHelper.currTime = FileHelper::readFloat(fd);
    }
    else
    {
        statBoost.timerHelper.currGoal = FileHelper::readFloat(fd);
        statBoost.timerHelper.currTime = FileHelper::readFloat(fd);
        statBoost.timerHelper.running = false;
    }

    return statBoost;
}

// Room stat boosts

bool StatBoostDefinition::TestRoomStatBoostSystem(ShipManager *ship, int room)
{
    if (!systemList.empty())
    {
        ShipSystem *sys = ship->GetSystemInRoom(room);
        if (sys)
        {
            for (auto& systemName : systemList)
            {
                if (systemName == "all")
                {
                    if (systemRoomTarget == SystemRoomTarget::ALL) return true; // apply to any system room
                    else if (systemRoomTarget == SystemRoomTarget::NONE) return false; // don't apply to any system room
                }
                else
                {
                    if (ShipSystem::NameToSystemId(systemName) == sys->iSystemType)
                    {
                        if (systemRoomTarget == SystemRoomTarget::ALL) return true; // whitelisted system
                        else if (systemRoomTarget == SystemRoomTarget::NONE) return false; // blacklisted system
                    }
                }
            }
            if (systemRoomTarget == SystemRoomTarget::ALL) return false; // didn't find correct system so don't apply stat boost
        }
        else
        {
            if (systemRoomTarget == SystemRoomTarget::ALL) return false; // don't apply stat boost to empty room
        }
    }
    return true;
}

void ShipManager_Extend::CreateRoomStatBoost(StatBoost &&statBoost, int room)
{
    if (orig->iShipId == 1)
    {
        statBoost.sourceRoomIds.second.push_back(room);
    }
    else
    {
        statBoost.sourceRoomIds.first.push_back(room);
    }

    statBoost.timerHelper = TimerHelper(false);

    if (statBoost.def->duration != -1.f)
    {
        statBoost.timerHelper.Start(statBoost.def->duration);
    }
    else
    {
        statBoost.timerHelper.currTime = 0.f;
        statBoost.timerHelper.currGoal = 0.f;
        statBoost.timerHelper.running = false;
    }

    auto &vStatBoosts = RM_EX(orig->ship.vRoomList[room])->statBoosts;

    if (statBoost.def->duration == -1.f) // optimization for persistent stacking boosts
    {
        for (auto& otherBoost : vStatBoosts)
        {
            if (otherBoost.statBoost.crewSourceId == statBoost.crewSourceId && otherBoost.statBoost.sourceShipId == statBoost.sourceShipId)
            {
                // same boost; add stacks
                if (otherBoost.statBoost.def == statBoost.def)
                {
                    otherBoost.statBoost.iStacks = std::min(otherBoost.statBoost.iStacks + statBoost.iStacks, statBoost.def->maxStacks);
                    return;
                }
                // check for same stack id, lower priority
                else if ((statBoost.def->stackId == otherBoost.statBoost.def->stackId) &&
                         (statBoost.def->priority > otherBoost.statBoost.def->priority))
                {
                    // max stacks fewer than new boost's stacks
                    if (statBoost.iStacks >= otherBoost.statBoost.def->maxStacks)
                    {
                        // overwrite otherBoost
                        otherBoost = RoomStatBoost(std::move(statBoost), orig->ship.vRoomList[room]);
                        return;
                    }
                    else if (otherBoost.statBoost.def->maxStacks - statBoost.iStacks < otherBoost.statBoost.iStacks)
                    {
                        // other boost loses extraneous stacks that will be masked by the new boost
                        otherBoost.statBoost.iStacks = otherBoost.statBoost.def->maxStacks - statBoost.iStacks;
                    }
                }
            }
        }
    }
    else
    {
        for (auto& otherBoost : vStatBoosts)
        {
            if (otherBoost.statBoost.crewSourceId == statBoost.crewSourceId && otherBoost.statBoost.sourceShipId == statBoost.sourceShipId) // must be same crew/ship source
            {
                // same boost and has at least the max stacks
                if (otherBoost.statBoost.def == statBoost.def)
                {
                    if (statBoost.iStacks >= statBoost.def->maxStacks)
                    {
                        // refresh stacks and timer
                        otherBoost.statBoost.iStacks = statBoost.iStacks;
                        otherBoost.statBoost.timerHelper = statBoost.timerHelper;
                        return;
                    }
                }
                // check for same stack id, with less time left, lower priority, and max stacks fewer than new boost's stacks
                else if ((statBoost.def->stackId == otherBoost.statBoost.def->stackId) &&
                         (otherBoost.statBoost.def->duration != -1.f && otherBoost.statBoost.timerHelper.currGoal-otherBoost.statBoost.timerHelper.currTime <= statBoost.def->duration) &&
                         (statBoost.def->priority > otherBoost.statBoost.def->priority) &&
                         (statBoost.iStacks >= otherBoost.statBoost.def->maxStacks))
                {
                    // overwrite otherBoost
                    otherBoost = RoomStatBoost(std::move(statBoost), orig->ship.vRoomList[room]);
                    return;
                }
            }
        }
    }

    vStatBoosts.emplace_back(std::move(statBoost), orig->ship.vRoomList[room]);
}

void ShipManager_Extend::CreateRoomStatBoost(StatBoostDefinition &statBoostDef, int room, int nStacks, int sourceShipId)
{
    if (room < 0) return;

    switch (statBoostDef.shipTarget)
    {
    case StatBoostDefinition::ShipTarget::PLAYER_SHIP:
        if (orig->iShipId != 0) return;
        break;
    case StatBoostDefinition::ShipTarget::ORIGINAL_SHIP:
    case StatBoostDefinition::ShipTarget::CURRENT_ALL:
        if (orig->iShipId != sourceShipId) return;
        break;
    case StatBoostDefinition::ShipTarget::ORIGINAL_OTHER_SHIP:
    case StatBoostDefinition::ShipTarget::OTHER_ALL:
        if (orig->iShipId == sourceShipId) return;
        break;
    case StatBoostDefinition::ShipTarget::ENEMY_SHIP:
        if (orig->iShipId != 1) return;
        break;
    }

    if (!statBoostDef.TestRoomStatBoostSystem(orig, room)) return;

    StatBoost statBoost = StatBoost(statBoostDef);

    statBoost.iStacks = nStacks;
    statBoost.sourceShipId = sourceShipId;
    statBoost.crewSourceId = 0;

    CreateRoomStatBoost(std::move(statBoost), room);
}

void ShipManager_Extend::CreateRoomStatBoost(StatBoostDefinition &statBoostDef, int room, int nStacks, CrewMember *crewSource)
{
    if (room < 0) return;

    switch (statBoostDef.shipTarget)
    {
    case StatBoostDefinition::ShipTarget::PLAYER_SHIP:
        if (orig->iShipId != 0) return;
        break;
    case StatBoostDefinition::ShipTarget::ENEMY_SHIP:
        if (orig->iShipId != 1) return;
        break;
    }

    if (!statBoostDef.TestRoomStatBoostSystem(orig, room)) return;

    StatBoost statBoost = StatBoost(statBoostDef);

    statBoost.iStacks = nStacks;
    statBoost.crewSource = crewSource;
    statBoost.crewSourceId = CM_EX(crewSource)->selfId;
    statBoost.sourceShipId = crewSource->iShipId;

    CreateRoomStatBoost(std::move(statBoost), room);
}

HOOK_METHOD(ShipManager, OnLoop, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::OnLoop -> Begin (StatBoost.cpp)\n")
    super();

    for (Room *room : ship.vRoomList)
    {
        auto &vRoomStatBoosts = RM_EX(room)->statBoosts;
        for (RoomStatBoost& statBoost : vRoomStatBoosts)
        {
            statBoost.statBoost.timerHelper.Update();
            if (statBoost.roomAnim)
            {
                statBoost.roomAnim->OnUpdate();
            }
        }
        vRoomStatBoosts.erase(std::remove_if(vRoomStatBoosts.begin(),
                                             vRoomStatBoosts.end(),
                                             [](RoomStatBoost& statBoost) { return statBoost.statBoost.timerHelper.Done(); }),
                                             vRoomStatBoosts.end());
    }
}

HOOK_METHOD(Ship, OnInit, (ShipBlueprint* bp) -> void)
{
    LOG_HOOK("HOOK_METHOD -> Ship::OnInit -> Begin (StatBoost.cpp)\n")
    super(bp);

    for (Room *room : vRoomList)
    {
        RM_EX(room)->statBoosts.clear();
    }
}

HOOK_METHOD(ShipManager, ExportShip, (int fd) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::ExportShip -> Begin (StatBoost.cpp)\n")
    super(fd);

    for (Room *room : ship.vRoomList)
    {
        Room_Extend *ex = RM_EX(room);

        FileHelper::writeInt(fd, ex->statBoosts.size());
        for (RoomStatBoost &statBoost : ex->statBoosts)
        {
            statBoost.statBoost.Save(fd);
        }
    }
}

HOOK_METHOD(ShipManager, ImportShip, (int fd) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::ImportShip -> Begin (StatBoost.cpp)\n")
    super(fd);

    int n;

    for (Room *room : ship.vRoomList)
    {
        Room_Extend *ex = RM_EX(room);

        n = FileHelper::readInteger(fd);
        for (int i=0; i<n; ++i)
        {
            ex->statBoosts.emplace_back(StatBoost::LoadStatBoost(fd), room);

            // set room
            if (iShipId == 1)
            {
                ex->statBoosts.back().statBoost.sourceRoomIds.second.push_back(room->iRoomId);
            }
            else
            {
                ex->statBoosts.back().statBoost.sourceRoomIds.first.push_back(room->iRoomId);
            }
        }
    }
}

// Timed stat boosts

HOOK_METHOD(ShipManager, JumpArrive, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::JumpArrive -> Begin (StatBoost.cpp)\n")
    super();
    CustomAugmentManager* customAug = CustomAugmentManager::GetInstance();

    /*
    for (auto i : this->vCrewList)
    {
        auto ex = CM_EX(i);
        ex->timedStatBoosts.clear();
    }
    */

    if (G_->GetShipInfo(0) != nullptr)
    {
        std::unordered_map<std::string, int> *augMap = customAug->GetShipAugments(0);
        for (auto augPair : *augMap)
        {
            if (customAug->IsAugment(augPair.first))
            {
                for (StatBoostDefinition* statBoostDef : customAug->GetAugmentDefinition(augPair.first)->statBoosts)
                {
                    if (statBoostDef->duration != -1)
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
    LOG_HOOK("HOOK_METHOD -> CrewMember::constructor -> Begin (StatBoost.cpp)\n")
    super(bp, shipId, intruder, animation);

    if (loadingGame) return;

    CustomAugmentManager* customAug = CustomAugmentManager::GetInstance();
    if (G_->GetShipInfo(shipId) != nullptr)
    {
        std::unordered_map<std::string, int> *augMap = customAug->GetShipAugments(shipId);
        for (auto augPair : *augMap)
        {
            if (customAug->IsAugment(augPair.first))
            {
                for (StatBoostDefinition* statBoostDef : customAug->GetAugmentDefinition(augPair.first)->statBoosts)
                {
                    if (statBoostDef->duration != -1)
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

HOOK_METHOD(CrewMember, Restart, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewMember::Restart -> Begin (StatBoost.cpp)\n")
    // Occurs when a crewmember is cloned or when a crew drone is deployed/redeployed
    CM_EX(this)->timedStatBoosts.clear();
    super();
}

bool CrewMember_Extend::CheckExtraCondition(CrewExtraCondition condition)
{
    switch (condition)
    {
    case CrewExtraCondition::BURNING:
        return orig->iOnFire > 0;
    case CrewExtraCondition::SUFFOCATING:
        return orig->bSuffocating;
    case CrewExtraCondition::MIND_CONTROLLED:
        return orig->bMindControlled;
    case CrewExtraCondition::STUNNED:
        return orig->fStunTime > 0.f;
    case CrewExtraCondition::REPAIRING:
        return orig->Repairing() && !orig->intruder;
    case CrewExtraCondition::REPAIRING_SYSTEM:
        return orig->RepairingSystem();
    case CrewExtraCondition::REPAIRING_BREACH:
        return orig->Repairing() && !orig->intruder && (void**)(orig->currentRepair) == VTable_OuterHull;
    case CrewExtraCondition::SABOTAGING:
        return orig->Sabotaging();
    case CrewExtraCondition::FIGHTING:
        return orig->bFighting && orig->crewTarget != orig->blockingDoor;
    case CrewExtraCondition::SHOOTING:
        return orig->crewAnim->status == 7 && !orig->crewAnim->bFrozen && !orig->crewAnim->bStunned;
    case CrewExtraCondition::MOVING:
        return orig->crewAnim->status != 6 && orig->health.first > 0.f && !orig->AtFinalGoal();
    case CrewExtraCondition::IDLE:
        return orig->crewAnim->status != 6 && orig->health.first > 0.f && !orig->IsBusy();
    case CrewExtraCondition::MANNING:
        return orig->bActiveManning;
    case CrewExtraCondition::FIREFIGHTING:
        return orig->RepairingFire();
    case CrewExtraCondition::DYING:
        return orig->crewAnim->status == 3;
    case CrewExtraCondition::TELEPORTING:
        return customTele.teleporting;
    }
    return false;
}

bool CrewMember_Extend::BoostCheck(StatBoost& statBoost, int checkRoomId)
{
    int ownerShip;

    if (checkRoomId == -1)
    {
        checkRoomId = orig->iRoomId;
    }

    switch (statBoost.def->boostSource)
    {
    case StatBoostDefinition::BoostSource::CREW:
        if (statBoost.crewSource)
        {
            ownerShip = statBoost.crewSource->GetPowerOwner();
            statBoost.sourceShipId = statBoost.crewSource->iShipId;
        }
        else
        {
            ownerShip = statBoost.sourceShipId;
        }

        switch (statBoost.def->shipTarget)
        {
        case StatBoostDefinition::ShipTarget::PLAYER_SHIP:
            if (orig->currentShipId != 0) return false;
            break;
        case StatBoostDefinition::ShipTarget::ORIGINAL_SHIP:
            if (orig->currentShipId != ownerShip) return false;
            break;
        case StatBoostDefinition::ShipTarget::ORIGINAL_OTHER_SHIP:
            if (orig->currentShipId == ownerShip) return false;
            break;
        case StatBoostDefinition::ShipTarget::OTHER_ALL:
            if (!statBoost.crewSource || orig->currentShipId == statBoost.crewSource->currentShipId) return false;
            break;
        case StatBoostDefinition::ShipTarget::ENEMY_SHIP:
            if (orig->currentShipId != 1) return false;
            break;
        case StatBoostDefinition::ShipTarget::CURRENT_ALL:
            if (!statBoost.crewSource || orig->currentShipId != statBoost.crewSource->currentShipId) return false;
            break;
        case StatBoostDefinition::ShipTarget::CURRENT_ROOM:
            if (!statBoost.crewSource || orig->currentShipId != statBoost.crewSource->currentShipId || checkRoomId != statBoost.crewSource->iRoomId) return false;
            break;
        case StatBoostDefinition::ShipTarget::CREW_TARGET:
            if (!statBoost.crewSource || (CrewTarget*)orig != statBoost.crewSource->crewTarget) return false;
            break;
        case StatBoostDefinition::ShipTarget::TARGETS_ME:
            if (!statBoost.crewSource || orig->crewTarget != (CrewTarget*)statBoost.crewSource) return false;
            break;
        }

        if (statBoost.crewSourceId == selfId)
        {
            if (!statBoost.def->affectsSelf) return false;
        }
        else
        {
            switch (statBoost.def->crewTarget)
            {
            case StatBoostDefinition::CrewTarget::ALLIES:
                if (ownerShip != orig->iShipId) return false;
                break;
            case StatBoostDefinition::CrewTarget::ENEMIES:
                if (ownerShip == orig->iShipId) return false;
                break;
            case StatBoostDefinition::CrewTarget::SELF:
                return false;
                break;
            case StatBoostDefinition::CrewTarget::CURRENT_ALLIES:
                if (statBoost.crewSource)
                {
                    if ((statBoost.crewSource->iShipId != orig->iShipId) == (statBoost.crewSource->bMindControlled == orig->bMindControlled)) return false;
                }
                else
                {
                    if ((ownerShip != orig->iShipId) != (orig->bMindControlled)) return false;
                }
                break;
            case StatBoostDefinition::CrewTarget::CURRENT_ENEMIES:
                if (statBoost.crewSource)
                {
                    if ((statBoost.crewSource->iShipId == orig->iShipId) == (statBoost.crewSource->bMindControlled == orig->bMindControlled)) return false;
                }
                else
                {
                    if ((ownerShip == orig->iShipId) != (orig->bMindControlled)) return false;
                }
                break;
            case StatBoostDefinition::CrewTarget::ORIGINAL_ALLIES:
                if (statBoost.crewSource)
                {
                    if (statBoost.crewSource->iShipId != orig->iShipId) return false;
                }
                else
                {
                    if (ownerShip != orig->iShipId) return false;
                }
                break;
            case StatBoostDefinition::CrewTarget::ORIGINAL_ENEMIES:
                if (statBoost.crewSource)
                {
                    if (statBoost.crewSource->iShipId == orig->iShipId) return false;
                }
                else
                {
                    if (ownerShip != orig->iShipId) return false;
                }
                break;
            }

            if (!statBoost.def->whiteList.empty() && std::find(statBoost.def->whiteList.begin(), statBoost.def->whiteList.end(), orig->species) == statBoost.def->whiteList.end()) return false;
            if (!statBoost.def->blackList.empty() && std::find(statBoost.def->blackList.begin(), statBoost.def->blackList.end(), orig->species) != statBoost.def->blackList.end()) return false;
        }

        break;

    case StatBoostDefinition::BoostSource::AUGMENT:
        ownerShip = statBoost.sourceShipId;

        switch (statBoost.def->shipTarget)
        {
        case StatBoostDefinition::ShipTarget::PLAYER_SHIP:
            if (orig->currentShipId != 0) return false;
            break;
        case StatBoostDefinition::ShipTarget::ORIGINAL_SHIP:
        case StatBoostDefinition::ShipTarget::CURRENT_ALL:
            if (orig->currentShipId != ownerShip) return false;
            break;
        case StatBoostDefinition::ShipTarget::ORIGINAL_OTHER_SHIP:
        case StatBoostDefinition::ShipTarget::OTHER_ALL:
            if (orig->currentShipId == ownerShip) return false;
            break;
        case StatBoostDefinition::ShipTarget::ENEMY_SHIP:
            if (orig->currentShipId != 1) return false;
            break;
        }

        switch (statBoost.def->crewTarget)
        {
        case StatBoostDefinition::CrewTarget::ALLIES:
        case StatBoostDefinition::CrewTarget::ORIGINAL_ALLIES:
            if (ownerShip != orig->iShipId) return false;
            break;
        case StatBoostDefinition::CrewTarget::ENEMIES:
        case StatBoostDefinition::CrewTarget::ORIGINAL_ENEMIES:
            if (ownerShip == orig->iShipId) return false;
            break;
        case StatBoostDefinition::CrewTarget::SELF:
            return false;
            break;
        case StatBoostDefinition::CrewTarget::CURRENT_ALLIES:
            if ((ownerShip != orig->iShipId) != orig->bMindControlled) return false;
            break;
        case StatBoostDefinition::CrewTarget::CURRENT_ENEMIES:
            if ((ownerShip == orig->iShipId) != orig->bMindControlled) return false;
            break;
        }

        if (!statBoost.def->whiteList.empty() && std::find(statBoost.def->whiteList.begin(), statBoost.def->whiteList.end(), orig->species) == statBoost.def->whiteList.end()) return false;
        if (!statBoost.def->blackList.empty() && std::find(statBoost.def->blackList.begin(), statBoost.def->blackList.end(), orig->species) != statBoost.def->blackList.end()) return false;

        break;
    }

    if (statBoost.def->isRoomBased)
    {
        const std::vector<int> &sourceRoomIds = orig->currentShipId == 1 ? statBoost.sourceRoomIds.second : statBoost.sourceRoomIds.first;

        if (std::find(sourceRoomIds.begin(), sourceRoomIds.end(), checkRoomId) == sourceRoomIds.end()) return false;
    }
    else if (!statBoost.def->systemList.empty())
    {
        const std::vector<int> &sourceRoomIds = orig->currentShipId == 1 ? statBoost.sourceRoomIds.second : statBoost.sourceRoomIds.first;

        switch (statBoost.def->systemRoomTarget)
        {
        case StatBoostDefinition::SystemRoomTarget::ALL:
            if (std::find(sourceRoomIds.begin(), sourceRoomIds.end(), checkRoomId) == sourceRoomIds.end()) return false;
            break;
        case StatBoostDefinition::SystemRoomTarget::NONE:
            if (std::find(sourceRoomIds.begin(), sourceRoomIds.end(), checkRoomId) != sourceRoomIds.end()) return false;
            break;
        }
    }

    switch (statBoost.def->droneTarget)
    {
    case StatBoostDefinition::DroneTarget::DRONES:
        if (!orig->IsDrone()) return false;
        break;
    case StatBoostDefinition::DroneTarget::CREW:
        if (orig->IsDrone()) return false;
        break;
    }

    if (statBoost.def->functionalTarget && !orig->Functional()) return false;

    if (statBoost.def->healthReq.first != -1.f && orig->health.first < statBoost.def->healthReq.first) return false;
    if (statBoost.def->healthReq.second != -1.f && orig->health.first > statBoost.def->healthReq.second) return false;
    if (statBoost.def->healthFractionReq.first != -1.f && orig->health.first/orig->health.second < statBoost.def->healthFractionReq.first) return false;
    if (statBoost.def->healthFractionReq.second != -1.f && orig->health.first/orig->health.second > statBoost.def->healthFractionReq.second) return false;
    if (statBoost.def->oxygenReq.first != -1.f && (checkRoomId == -1 || ShipGraph::GetShipInfo(orig->currentShipId)->GetRoomOxygen(checkRoomId) < statBoost.def->oxygenReq.first)) return false;
    if (statBoost.def->oxygenReq.second != -1.f && (checkRoomId == -1 || ShipGraph::GetShipInfo(orig->currentShipId)->GetRoomOxygen(checkRoomId) > statBoost.def->oxygenReq.second)) return false;
    if (statBoost.def->fireCount.first != -1 && (checkRoomId == -1 || G_->GetShipManager(orig->currentShipId)->GetFireCount(checkRoomId) < statBoost.def->fireCount.first)) return false;
    if (statBoost.def->fireCount.second != -1 && (checkRoomId == -1 || G_->GetShipManager(orig->currentShipId)->GetFireCount(checkRoomId) > statBoost.def->fireCount.second)) return false;

    if (!statBoost.def->extraConditions.empty())
    {
        for (auto& condition : statBoost.def->extraConditions)
        {
            if (CheckExtraCondition(condition.first) != condition.second) return false;
        }
    }

    if (!statBoost.def->extraOrConditions.empty())
    {
        for (auto& condition : statBoost.def->extraOrConditions)
        {
            if (CheckExtraCondition(condition.first) == condition.second) return true;
        }
        return false;
    }

    return true;
}

int CrewMember_Extend::CalculateMaxHealth(const CrewDefinition* def)
{
    int maxHealth = CalculateStat(CrewStat::MAX_HEALTH, def);
    int actualMaxHealth = maxHealth + orig->healthBoost;
    if (actualMaxHealth != orig->health.second)
    {
        if (orig->health.second > 0)
        {
            orig->health.first = actualMaxHealth * (orig->health.first / orig->health.second);
        }
        else
        {
            orig->health.first = actualMaxHealth;
        }
        orig->health.second = actualMaxHealth;
    }

    return maxHealth;
}

float CrewMember_Extend::CalculateStat(CrewStat stat, const CrewDefinition* def, bool* boolValue)
{
//    using std::chrono::steady_clock;
//    using std::chrono::duration_cast;
//    using std::chrono::duration;
//    using std::chrono::milliseconds;
//    auto t1 = steady_clock::now();

    if ((unsigned int)stat < numCachedStats && statCache[(unsigned int)stat].second == StatBoostManager::statCacheFrame)
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
                if (statBoost.def->duration == -1 || statBoost.timerHelper.Running())
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
            //if (BoostCheck(statBoost)) // If the boost affects this ship and/or this room, and the boost comes from someone else or affects self, and the boost comes from an ally and affects allies or an enemy and affects enemies, and the boost specifically lets this race take it or doesn't ban it
            //{
                if (statBoost.def->duration == -1 || statBoost.timerHelper.Running())
                {
                    personalStatBoosts.push_back(statBoost);
                }
            //}
        }
    }

    float finalStat = 0.f;
    bool isBool = false;
    bool isEffect = false;
    switch(stat)
    {
        case CrewStat::MAX_HEALTH:
            finalStat = (temporaryPowerActive && GetPowerDef()->tempPower.maxHealth.enabled) ? GetPowerDef()->tempPower.maxHealth.value : def->maxHealth;
            break;
        case CrewStat::STUN_MULTIPLIER:
            finalStat = (temporaryPowerActive && GetPowerDef()->tempPower.stunMultiplier.enabled) ? GetPowerDef()->tempPower.stunMultiplier.value : def->stunMultiplier;
            break;
        case CrewStat::MOVE_SPEED_MULTIPLIER:
            finalStat = (temporaryPowerActive && GetPowerDef()->tempPower.moveSpeedMultiplier.enabled) ? GetPowerDef()->tempPower.moveSpeedMultiplier.value : def->moveSpeedMultiplier;
            break;
        case CrewStat::REPAIR_SPEED_MULTIPLIER:
            finalStat = (temporaryPowerActive && GetPowerDef()->tempPower.repairSpeed.enabled) ? GetPowerDef()->tempPower.repairSpeed.value : def->repairSpeed;
            break;
        case CrewStat::DAMAGE_MULTIPLIER:
            finalStat = (temporaryPowerActive && GetPowerDef()->tempPower.damageMultiplier.enabled) ? GetPowerDef()->tempPower.damageMultiplier.value : def->damageMultiplier;
            break;
        case CrewStat::RANGED_DAMAGE_MULTIPLIER:
            finalStat = (temporaryPowerActive && GetPowerDef()->tempPower.rangedDamageMultiplier.enabled) ? GetPowerDef()->tempPower.rangedDamageMultiplier.value : def->rangedDamageMultiplier;
            break;
        case CrewStat::DOOR_DAMAGE_MULTIPLIER:
            finalStat = (temporaryPowerActive && GetPowerDef()->tempPower.doorDamageMultiplier.enabled) ? GetPowerDef()->tempPower.doorDamageMultiplier.value : def->doorDamageMultiplier;
            break;
        case CrewStat::FIRE_REPAIR_MULTIPLIER:
            finalStat = (temporaryPowerActive && GetPowerDef()->tempPower.fireRepairMultiplier.enabled) ? GetPowerDef()->tempPower.fireRepairMultiplier.value : def->fireRepairMultiplier;
            break;
        case CrewStat::SUFFOCATION_MODIFIER:
            finalStat = (temporaryPowerActive && GetPowerDef()->tempPower.suffocationModifier.enabled) ? GetPowerDef()->tempPower.suffocationModifier.value : def->suffocationModifier;
            break;
        case CrewStat::FIRE_DAMAGE_MULTIPLIER:
            finalStat = (temporaryPowerActive && GetPowerDef()->tempPower.fireDamageMultiplier.enabled) ? GetPowerDef()->tempPower.fireDamageMultiplier.value : def->fireDamageMultiplier;
            break;
        case CrewStat::OXYGEN_CHANGE_SPEED:
            finalStat = (temporaryPowerActive && GetPowerDef()->tempPower.oxygenChangeSpeed.enabled) ? GetPowerDef()->tempPower.oxygenChangeSpeed.value : def->oxygenChangeSpeed;
            break;
        case CrewStat::DAMAGE_TAKEN_MULTIPLIER:
            finalStat = (temporaryPowerActive && GetPowerDef()->tempPower.damageTakenMultiplier.enabled) ? GetPowerDef()->tempPower.damageTakenMultiplier.value : def->damageTakenMultiplier;
            break;
        case CrewStat::PASSIVE_HEAL_AMOUNT:
            finalStat = orig->Functional() ? ((temporaryPowerActive && GetPowerDef()->tempPower.passiveHealAmount.enabled) ? GetPowerDef()->tempPower.passiveHealAmount.value : def->passiveHealAmount) : 0.f;
            break;
        case CrewStat::TRUE_PASSIVE_HEAL_AMOUNT:
            finalStat = orig->Functional() ? ((temporaryPowerActive && GetPowerDef()->tempPower.truePassiveHealAmount.enabled) ? GetPowerDef()->tempPower.truePassiveHealAmount.value : def->truePassiveHealAmount) : 0.f;
            break;
        case CrewStat::TRUE_HEAL_AMOUNT:
            finalStat = orig->Functional() ? ((temporaryPowerActive && GetPowerDef()->tempPower.trueHealAmount.enabled) ? GetPowerDef()->tempPower.trueHealAmount.value : def->trueHealAmount) : 0.f;
            break;
        case CrewStat::ACTIVE_HEAL_AMOUNT:
            finalStat = orig->Functional() ? ((temporaryPowerActive && GetPowerDef()->tempPower.healAmount.enabled) ? GetPowerDef()->tempPower.healAmount.value : def->healAmount) : 0.f;
            break;
        case CrewStat::PASSIVE_HEAL_DELAY:
            finalStat = (temporaryPowerActive && GetPowerDef()->tempPower.passiveHealDelay.enabled) ? GetPowerDef()->tempPower.passiveHealDelay.value : def->passiveHealDelay;
            break;
        case CrewStat::SABOTAGE_SPEED_MULTIPLIER:
            finalStat = (temporaryPowerActive && GetPowerDef()->tempPower.sabotageSpeedMultiplier.enabled) ? GetPowerDef()->tempPower.sabotageSpeedMultiplier.value : def->sabotageSpeedMultiplier;
            break;
        case CrewStat::ALL_DAMAGE_TAKEN_MULTIPLIER:
            finalStat = (temporaryPowerActive && GetPowerDef()->tempPower.allDamageTakenMultiplier.enabled) ? GetPowerDef()->tempPower.allDamageTakenMultiplier.value : def->allDamageTakenMultiplier;
            break;
        case CrewStat::HEAL_SPEED_MULTIPLIER:
            finalStat = (temporaryPowerActive && GetPowerDef()->tempPower.healSpeed.enabled) ? GetPowerDef()->tempPower.healSpeed.value : def->healSpeed;
            break;
        case CrewStat::HEAL_CREW_AMOUNT:
            finalStat = (temporaryPowerActive && GetPowerDef()->tempPower.healCrewAmount.enabled) ? GetPowerDef()->tempPower.healCrewAmount.value : def->healCrewAmount;
            break;
        case CrewStat::DAMAGE_ENEMIES_AMOUNT:
            finalStat = (temporaryPowerActive && GetPowerDef()->tempPower.damageEnemiesAmount.enabled) ? GetPowerDef()->tempPower.damageEnemiesAmount.value : def->damageEnemiesAmount;
            break;
        case CrewStat::BONUS_POWER:
            finalStat = (temporaryPowerActive && GetPowerDef()->tempPower.bonusPower.enabled) ? GetPowerDef()->tempPower.bonusPower.value : def->bonusPower;
            break;
        case CrewStat::POWER_DRAIN:
            finalStat = (temporaryPowerActive && GetPowerDef()->tempPower.powerDrain.enabled) ? GetPowerDef()->tempPower.powerDrain.value : def->powerDrain;
            break;
        case CrewStat::ESSENTIAL:
            finalStat = def->essential;
            break;
        case CrewStat::DEFAULT_SKILL_LEVEL:
            finalStat = def->defaultSkillLevel;
            break;
        case CrewStat::POWER_RECHARGE_MULTIPLIER:
            finalStat = (temporaryPowerActive && GetPowerDef()->tempPower.powerRechargeMultiplier.enabled) ? GetPowerDef()->tempPower.powerRechargeMultiplier.value : def->powerRechargeMultiplier;
            break;
        case CrewStat::POWER_MAX_CHARGES:
            finalStat = GetPowerDef()->powerCharges;
            break;
        case CrewStat::POWER_CHARGES_PER_JUMP:
            finalStat = GetPowerDef()->chargesPerJump;
            break;
        case CrewStat::CAN_FIGHT:
            *boolValue = (temporaryPowerActive && GetPowerDef()->tempPower.canFight.enabled) ? GetPowerDef()->tempPower.canFight.value : def->canFight;
            isBool = true;
            break;
        case CrewStat::CAN_REPAIR:
            *boolValue = (temporaryPowerActive && GetPowerDef()->tempPower.canRepair.enabled) ? GetPowerDef()->tempPower.canRepair.value : def->canRepair;
            isBool = true;
            break;
        case CrewStat::CAN_SABOTAGE:
            *boolValue = (temporaryPowerActive && GetPowerDef()->tempPower.canSabotage.enabled) ? GetPowerDef()->tempPower.canSabotage.value : def->canSabotage;
            isBool = true;
            break;
        case CrewStat::CAN_MAN:
            *boolValue = (temporaryPowerActive && GetPowerDef()->tempPower.canMan.enabled) ? GetPowerDef()->tempPower.canMan.value : def->canMan;
            isBool = true;
            break;
        case CrewStat::CAN_TELEPORT:
            *boolValue = (temporaryPowerActive && GetPowerDef()->tempPower.canTeleport.enabled) ? GetPowerDef()->tempPower.canTeleport.value : def->canTeleport;
            isBool = true;
            break;
        case CrewStat::CAN_SUFFOCATE:
            *boolValue = (temporaryPowerActive && GetPowerDef()->tempPower.canSuffocate.enabled) ? GetPowerDef()->tempPower.canSuffocate.value : def->canSuffocate;
            isBool = true;
            break;
        case CrewStat::CONTROLLABLE:
            *boolValue = (temporaryPowerActive && GetPowerDef()->tempPower.controllable.enabled) ? GetPowerDef()->tempPower.controllable.value : def->controllable;
            isBool = true;
            break;
        case CrewStat::CAN_BURN:
            *boolValue = (temporaryPowerActive && GetPowerDef()->tempPower.canBurn.enabled) ? GetPowerDef()->tempPower.canBurn.value : def->canBurn;
            isBool = true;
            break;
        case CrewStat::IS_TELEPATHIC:
            *boolValue = (temporaryPowerActive && GetPowerDef()->tempPower.isTelepathic.enabled) ? GetPowerDef()->tempPower.isTelepathic.value : def->isTelepathic;
            isBool = true;
            break;
        case CrewStat::RESISTS_MIND_CONTROL:
            *boolValue = (temporaryPowerActive && GetPowerDef()->tempPower.resistsMindControl.enabled) ? GetPowerDef()->tempPower.resistsMindControl.value : def->resistsMindControl;
            isBool = true;
            break;
        case CrewStat::IS_ANAEROBIC:
            *boolValue = (temporaryPowerActive && GetPowerDef()->tempPower.isAnaerobic.enabled) ? GetPowerDef()->tempPower.isAnaerobic.value : def->isAnaerobic;
            isBool = true;
            break;
        case CrewStat::CAN_PHASE_THROUGH_DOORS:
            *boolValue = (temporaryPowerActive && GetPowerDef()->tempPower.canPhaseThroughDoors.enabled) ? GetPowerDef()->tempPower.canPhaseThroughDoors.value : def->canPhaseThroughDoors;
            isBool = true;
            break;
        case CrewStat::DETECTS_LIFEFORMS:
            *boolValue = (temporaryPowerActive && GetPowerDef()->tempPower.detectsLifeforms.enabled) ? GetPowerDef()->tempPower.detectsLifeforms.value : def->detectsLifeforms;
            isBool = true;
            break;
        case CrewStat::CLONE_LOSE_SKILLS:
            *boolValue = def->cloneLoseSkills;
            isBool = true;
            break;
        case CrewStat::POWER_DRAIN_FRIENDLY:
            *boolValue = (temporaryPowerActive && GetPowerDef()->tempPower.powerDrainFriendly.enabled) ? GetPowerDef()->tempPower.powerDrainFriendly.value : def->powerDrainFriendly;
            isBool = true;
            break;
        case CrewStat::HACK_DOORS:
            *boolValue = (temporaryPowerActive && GetPowerDef()->tempPower.hackDoors.enabled) ? GetPowerDef()->tempPower.hackDoors.value : def->hackDoors;
            isBool = true;
            break;
        case CrewStat::NO_CLONE:
            *boolValue = (temporaryPowerActive && GetPowerDef()->tempPower.noClone.enabled) ? GetPowerDef()->tempPower.noClone.value : def->noClone;
            isBool = true;
            break;
        case CrewStat::NO_SLOT:
            *boolValue = noSlot;
            isBool = true;
            break;
        case CrewStat::NO_AI:
            *boolValue = (temporaryPowerActive && GetPowerDef()->tempPower.noAI.enabled) ? GetPowerDef()->tempPower.noAI.value : def->noAI;
            isBool = true;
            break;
        case CrewStat::VALID_TARGET:
            *boolValue = (temporaryPowerActive && GetPowerDef()->tempPower.validTarget.enabled) ? GetPowerDef()->tempPower.validTarget.value : def->validTarget;
            isBool = true;
            break;
        case CrewStat::ROOTED:
            *boolValue = (temporaryPowerActive && GetPowerDef()->tempPower.rooted.enabled) ? GetPowerDef()->tempPower.rooted.value : def->rooted;
            isBool = true;
            break;
        case CrewStat::TELEPORT_MOVE:
            *boolValue = (temporaryPowerActive && GetPowerDef()->tempPower.teleportMove.enabled) ? GetPowerDef()->tempPower.teleportMove.value : def->teleportMove;
            isBool = true;
            break;
        case CrewStat::TELEPORT_MOVE_OTHER_SHIP:
            *boolValue = (temporaryPowerActive && GetPowerDef()->tempPower.teleportMoveOtherShip.enabled) ? GetPowerDef()->tempPower.teleportMoveOtherShip.value : def->teleportMoveOtherShip;
            isBool = true;
            break;
        case CrewStat::ACTIVATE_WHEN_READY:
            *boolValue = GetPowerDef()->activateWhenReady;
            isBool = true;
            break;
        case CrewStat::DEATH_EFFECT:
            deathEffectChange = def->explosionDef;
            hasDeathExplosion = def->hasDeathExplosion;
            isEffect = true;
            break;
        case CrewStat::POWER_EFFECT:
            powerChange = def->powerDefIdx;
            isEffect = true;
            break;
        case CrewStat::TRANSFORM_RACE:
            transformRace = originalRace;
            isEffect = true;
            break;
    }

    std::sort(personalStatBoosts.begin(), personalStatBoosts.end(),
        [](const StatBoost &a, const StatBoost &b) -> bool
        {
            return a.def->priority < b.def->priority;
        });

    for (auto& statBoost : personalStatBoosts)
    {
        if (statBoost.def->stackId)
        {
            stackLimitedStatBoosts[statBoost.def->stackId].push_back(&statBoost);
        }
    }

    for (auto& statBoostsPair : stackLimitedStatBoosts)
    {
        auto& statBoosts = statBoostsPair.second;

        int stacks = 0;

        for (auto it = statBoosts.rbegin(); it != statBoosts.rend(); ++it)
        {
            auto statBoost = *it;
            statBoost->iStacks = std::min(statBoost->iStacks, std::max(statBoost->def->maxStacks - stacks, 0));
            stacks += statBoost->iStacks;
        }
    }

    for (StatBoost& statBoost : personalStatBoosts)
    {
        for (int i = 0; i < statBoost.iStacks; ++i)
        {
            if (statBoost.def->stat == stat)
            {
                // Calculate power scaling
                int numPower = 0;
                float sysPowerScaling = statBoost.def->powerScalingNoSys;
                bool systemExists = false;

                int statBoostSourceShipId;
                if (statBoost.def->boostSource == StatBoostDefinition::BoostSource::CREW && statBoost.crewSource)
                {
                    statBoostSourceShipId = statBoost.crewSource->GetPowerOwner();
                }
                else
                {
                    statBoostSourceShipId = statBoost.sourceShipId;
                }

                for (auto system : statBoost.def->systemPowerScaling)
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
                                    sysPowerScaling = statBoost.def->powerScalingHackedSys;
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
                    sysPowerScaling = statBoost.def->powerScaling.at(numPower < statBoost.def->powerScaling.size() ? numPower : statBoost.def->powerScaling.size()-1);
                }

                // Apply effect
                if (isBool)
                {
                    if (sysPowerScaling)
                    {
                        if (statBoost.def->boostType == StatBoostDefinition::BoostType::SET)
                        {
                            *boolValue = statBoost.def->value;
                        }
                        else if (statBoost.def->boostType == StatBoostDefinition::BoostType::FLIP)
                        {
                            *boolValue = !*boolValue;
                        }
                    }
                }
                else if (isEffect)
                {
                    if (stat == CrewStat::POWER_EFFECT)
                    {
                        if (sysPowerScaling)
                        {
                            if (statBoost.def->boostType == StatBoostDefinition::BoostType::MULT)
                            {

                            }
                            else if (statBoost.def->boostType == StatBoostDefinition::BoostType::FLAT)
                            {

                            }
                            else if (statBoost.def->boostType == StatBoostDefinition::BoostType::SET)
                            {
                                powerChange = statBoost.def->powerChange;
                            }
                            else if (statBoost.def->boostType == StatBoostDefinition::BoostType::SET_VALUE)
                            {

                            }
                        }
                    }
                    else if (stat == CrewStat::DEATH_EFFECT)
                    {
                        if (statBoost.def->boostType == StatBoostDefinition::BoostType::MULT)
                        {
                            if (statBoost.def->deathEffectChange)
                            {
                                hasDeathExplosion = true;
                                deathEffectChange.shipFriendlyFire &= statBoost.def->deathEffectChange->shipFriendlyFire || !sysPowerScaling;
                                deathEffectChange.damage.iDamage *= 1.f + (statBoost.def->deathEffectChange->damage.iDamage - 1.f) * sysPowerScaling;
                                deathEffectChange.damage.iShieldPiercing *= 1.f + (statBoost.def->deathEffectChange->damage.iShieldPiercing - 1.f) * sysPowerScaling;
                                deathEffectChange.damage.fireChance *= 1.f + (statBoost.def->deathEffectChange->damage.fireChance - 1.f) * sysPowerScaling;
                                deathEffectChange.damage.breachChance *= 1.f + (statBoost.def->deathEffectChange->damage.breachChance - 1.f) * sysPowerScaling;
                                deathEffectChange.damage.stunChance *= 1.f + (statBoost.def->deathEffectChange->damage.stunChance - 1.f) * sysPowerScaling;
                                deathEffectChange.damage.iIonDamage *= 1.f + (statBoost.def->deathEffectChange->damage.iIonDamage - 1.f) * sysPowerScaling;
                                deathEffectChange.damage.iSystemDamage *= 1.f + (statBoost.def->deathEffectChange->damage.iSystemDamage - 1.f) * sysPowerScaling;
                                deathEffectChange.damage.iPersDamage *= 1.f + (statBoost.def->deathEffectChange->damage.iPersDamage - 1.f) * sysPowerScaling;
                                deathEffectChange.damage.bHullBuster &= statBoost.def->deathEffectChange->damage.bHullBuster || !sysPowerScaling;
                                deathEffectChange.damage.bLockdown &= statBoost.def->deathEffectChange->damage.bLockdown || !sysPowerScaling;
                                deathEffectChange.damage.bFriendlyFire &= statBoost.def->deathEffectChange->damage.bFriendlyFire || !sysPowerScaling;
                                deathEffectChange.damage.iStun *= 1.f + (statBoost.def->deathEffectChange->damage.iStun - 1.f) * sysPowerScaling;

                                deathEffectChange.transformRaceHealth *= 1.f + (statBoost.def->deathEffectChange->transformRaceHealth - 1.f) * sysPowerScaling;
                                deathEffectChange.transformRaceHealthFraction *= 1.f + (statBoost.def->deathEffectChange->transformRaceHealthFraction - 1.f) * sysPowerScaling;
                            }
                        }
                        else if (statBoost.def->boostType == StatBoostDefinition::BoostType::FLAT)
                        {
                            if (statBoost.def->deathEffectChange)
                            {
                                hasDeathExplosion = true;
                                deathEffectChange.shipFriendlyFire |= statBoost.def->deathEffectChange->shipFriendlyFire && sysPowerScaling;
                                deathEffectChange.damage.iDamage += statBoost.def->deathEffectChange->damage.iDamage * sysPowerScaling;
                                deathEffectChange.damage.iShieldPiercing += statBoost.def->deathEffectChange->damage.iShieldPiercing * sysPowerScaling;
                                deathEffectChange.damage.fireChance += statBoost.def->deathEffectChange->damage.fireChance * sysPowerScaling;
                                deathEffectChange.damage.breachChance += statBoost.def->deathEffectChange->damage.breachChance * sysPowerScaling;
                                deathEffectChange.damage.stunChance += statBoost.def->deathEffectChange->damage.stunChance * sysPowerScaling;
                                deathEffectChange.damage.iIonDamage += statBoost.def->deathEffectChange->damage.iIonDamage * sysPowerScaling;
                                deathEffectChange.damage.iSystemDamage += statBoost.def->deathEffectChange->damage.iSystemDamage * sysPowerScaling;
                                deathEffectChange.damage.iPersDamage += statBoost.def->deathEffectChange->damage.iPersDamage * sysPowerScaling;
                                deathEffectChange.damage.bHullBuster |= statBoost.def->deathEffectChange->damage.bHullBuster && sysPowerScaling;
                                deathEffectChange.damage.bLockdown |= statBoost.def->deathEffectChange->damage.bLockdown && sysPowerScaling;
                                deathEffectChange.damage.bFriendlyFire |= statBoost.def->deathEffectChange->damage.bFriendlyFire && sysPowerScaling;
                                deathEffectChange.damage.iStun += statBoost.def->deathEffectChange->damage.iStun * sysPowerScaling;

                                deathEffectChange.transformRaceHealth += statBoost.def->deathEffectChange->transformRaceHealth * sysPowerScaling;
                                deathEffectChange.transformRaceHealthFraction += statBoost.def->deathEffectChange->transformRaceHealthFraction * sysPowerScaling;

                                if (sysPowerScaling)
                                {
                                    for (auto statBoostDef : statBoost.def->deathEffectChange->statBoosts)
                                    {
                                        deathEffectChange.statBoosts.push_back(statBoostDef);
                                    }

                                    for (auto statBoostDef : statBoost.def->deathEffectChange->roomStatBoosts)
                                    {
                                        deathEffectChange.roomStatBoosts.push_back(statBoostDef);
                                    }

                                    for (auto crewSpawn : statBoost.def->deathEffectChange->crewSpawns)
                                    {
                                        deathEffectChange.crewSpawns.push_back(crewSpawn);
                                    }

                                    if (!statBoost.def->deathEffectChange->transformRace.empty())
                                    {
                                        deathEffectChange.transformRace = statBoost.def->deathEffectChange->transformRace;
                                        deathEffectChange.transformRaceHealth = statBoost.def->deathEffectChange->transformRaceHealth * sysPowerScaling;
                                        deathEffectChange.transformRaceHealthFraction = statBoost.def->deathEffectChange->transformRaceHealthFraction * sysPowerScaling;
                                        deathEffectChange.transformRaceDeathSound = statBoost.def->deathEffectChange->transformRaceDeathSound;
                                    }

                                    // To do, make death events stack rather than overwrite?
                                    if (!statBoost.def->deathEffectChange->event[0].empty())
                                    {
                                        deathEffectChange.event[0] = statBoost.def->deathEffectChange->event[0];
                                    }
                                    if (!statBoost.def->deathEffectChange->event[1].empty())
                                    {
                                        deathEffectChange.event[1] = statBoost.def->deathEffectChange->event[1];
                                    }
                                }
                            }
                        }
                        else if (statBoost.def->boostType == StatBoostDefinition::BoostType::SET)
                        {
                            if (sysPowerScaling)
                            {
                                if (statBoost.def->deathEffectChange)
                                {
                                    hasDeathExplosion = true;
                                    deathEffectChange = *statBoost.def->deathEffectChange;
                                }
                                else
                                {
                                    hasDeathExplosion = false;
                                }
                            }
                        }
                        else if (statBoost.def->boostType == StatBoostDefinition::BoostType::SET_VALUE)
                        {

                        }
                    }
                    else if (stat == CrewStat::TRANSFORM_RACE)
                    {
                        if (sysPowerScaling)
                        {
                            if (statBoost.def->boostType == StatBoostDefinition::BoostType::MULT)
                            {

                            }
                            else if (statBoost.def->boostType == StatBoostDefinition::BoostType::FLAT)
                            {

                            }
                            else if (statBoost.def->boostType == StatBoostDefinition::BoostType::SET)
                            {
                                transformRace = statBoost.def->stringValue;
                                if (statBoost.def->value)
                                {
                                    originalRace = transformRace;
                                }
                            }
                            else if (statBoost.def->boostType == StatBoostDefinition::BoostType::SET_VALUE)
                            {

                            }
                        }
                    }
                }
                else
                {
                    if (statBoost.def->boostType == StatBoostDefinition::BoostType::MULT)
                    {
                        if (!statBoost.def->powerScaling.empty())
                        {
                            finalStat = finalStat * (1 + (statBoost.def->amount - 1) * sysPowerScaling);
                        }
                        else
                        {
                            finalStat *= statBoost.def->amount;
                        }
                    }
                    else if (statBoost.def->boostType == StatBoostDefinition::BoostType::FLAT)
                    {
                        finalStat += statBoost.def->amount * sysPowerScaling;
                    }
                    else if (statBoost.def->boostType == StatBoostDefinition::BoostType::SET)
                    {
                        finalStat = statBoost.def->amount * sysPowerScaling;
                    }
                    else if (statBoost.def->boostType == StatBoostDefinition::BoostType::MIN)
                    {
                        finalStat = std::min(finalStat, statBoost.def->amount * sysPowerScaling);
                    }
                    else if (statBoost.def->boostType == StatBoostDefinition::BoostType::MAX)
                    {
                        finalStat = std::max(finalStat, statBoost.def->amount * sysPowerScaling);
                    }
                }
            }
        }
    }
    if ((unsigned int)stat < numCachedStats)
    {
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
    }

//    auto t2 = steady_clock::now();
//    duration<double, std::nano> ms_double = t2 - t1;
//    std::cout << "Calculate stat time: " << ms_double.count();
    return finalStat;
}

int CrewMember_Extend::CalculateDangerRating(float health, int roomId)
{
    std::vector<StatBoost> personalStatBoosts;
    std::unordered_map<int, std::vector<StatBoost*>> stackLimitedStatBoosts;
    auto& statBoosts = StatBoostManager::GetInstance()->statBoosts;

    for (StatBoost& statBoost : StatBoostManager::GetInstance()->dangerBoosts)
    {
        if (BoostCheck(statBoost, roomId))
        {
            if (statBoost.def->duration == -1 || statBoost.timerHelper.Running())
            {
                personalStatBoosts.push_back(statBoost);
            }
        }
    }

    for (auto& timedBoosts : timedStatBoosts)
    {
        for (StatBoost& statBoost : timedBoosts.second)
        {
            if (statBoost.def->dangerRating != -1.f && (statBoost.def->duration == -1 || statBoost.timerHelper.Running()))
            {
                personalStatBoosts.push_back(statBoost);
            }
        }
    }

    std::sort(personalStatBoosts.begin(), personalStatBoosts.end(),
        [](const StatBoost &a, const StatBoost &b) -> bool
        {
            return a.def->priority < b.def->priority;
        });

    float dangerRating = -1.f;

    for (auto& statBoost : personalStatBoosts)
    {
        if (statBoost.def->stackId)
        {
            stackLimitedStatBoosts[statBoost.def->stackId].push_back(&statBoost);
        }
        else if (statBoost.iStacks > 0)
        {
            // we check non stack id stat boosts immediately
            if (statBoost.def->dangerRating > health) return 0;
        }
    }

    for (auto& statBoostsPair : stackLimitedStatBoosts)
    {
        auto& statBoosts = statBoostsPair.second;

        int stacks = 0;

        for (auto it = statBoosts.rbegin(); it != statBoosts.rend(); ++it)
        {
            auto statBoost = *it;
            statBoost->iStacks = std::min(statBoost->iStacks, std::max(statBoost->def->maxStacks - stacks, 0));
            stacks += statBoost->iStacks;

            if (statBoost->iStacks > 0)
            {
                // we check stack id stat boosts as we check them
                if (statBoost->def->dangerRating > health) return 0;
            }
        }
    }

    return 1;
}

HOOK_METHOD(CrewAI, DangerRating, (int roomId, int crewId) -> int)
{
    LOG_HOOK("HOOK_METHOD -> CrewAI::DangerRating -> Begin (StatBoost.cpp)\n")
    int ret = super(roomId, crewId);

    if (ret != 0)
    {
        CrewMember *crew = crewList[crewId];
        return CM_EX(crew)->CalculateDangerRating(crew->health.first/crew->health.second, roomId);
    }

    return ret;
}

HOOK_METHOD_PRIORITY(CrewMember, OnLoop, 1000, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> CrewMember::OnLoop -> Begin (StatBoost.cpp)\n")
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
                auto it = animKeep.find(statBoost.def->realBoostId);
                if (it == animKeep.end())
                {
                    Animation *anim = new Animation(G_->GetAnimationControl()->GetAnimation(statBoost.def->boostAnim));
                    aex->boostAnim[statBoost.def->realBoostId] = anim;
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
                if (statBoost.def->boostAnim != "")
                {
                    //bool result = ex->BoostCheck(statBoost);
                    //if (result)
                    //{
                        auto it = animKeep.find(statBoost.def->realBoostId);
                        if (it == animKeep.end())
                        {
                            Animation *anim = new Animation(G_->GetAnimationControl()->GetAnimation(statBoost.def->boostAnim));
                            aex->boostAnim[statBoost.def->realBoostId] = anim;
                            anim->SetCurrentFrame(0);
                            anim->tracker.SetLoop(true, 0);
                            anim->Start(true);
                        }
                        else
                        {
                            it->second = true;
                        }
                    //}
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
