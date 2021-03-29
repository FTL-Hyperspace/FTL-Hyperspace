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
            }
            if (name == "amount")
            {
                def.amount = boost::lexical_cast<float>(val);

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

float CrewMember_Extend::CalculateStat(CrewStat stat)
{
    CustomCrewManager *custom = CustomCrewManager::GetInstance();
    auto def = custom->GetDefinition(orig->species);

    float otherCrewStatMultiplier = 1.f;
    float otherCrewStatModifier = 0.f;
    float augMultAmount = 1.f;
    float augAmount = 0.f;
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
                    )
                {
                    personalStatBoosts.push_back(statBoost);
                }
            }
        }
    }

    float finalStat = 0.f;
    switch(stat)
    {
        case CrewStat::MAX_HEALTH:
            break;
        case CrewStat::STUN_MULTIPLIER:
            break;
        case CrewStat::MOVE_SPEED_MULTIPLIER:
            finalStat = (temporaryPowerActive && def.powerDef.tempPower.moveSpeedMultiplier.enabled) ? def.powerDef.tempPower.moveSpeedMultiplier.value : def.moveSpeedMultiplier;
            break;
        case CrewStat::REPAIR_SPEED_MULTIPLIER:
            break;
        case CrewStat::DAMAGE_MULTIPLIER:
            finalStat = (temporaryPowerActive && def.powerDef.tempPower.damageMultiplier.enabled) ? def.powerDef.tempPower.damageMultiplier.value : def.damageMultiplier;
            break;
        case CrewStat::RANGED_DAMAGE_MULTIPLIER:
            finalStat = (temporaryPowerActive && def.powerDef.tempPower.rangedDamageMultiplier.enabled) ? def.powerDef.tempPower.rangedDamageMultiplier.value : def.rangedDamageMultiplier;
            break;
    }

//    std::sort(personalStatBoosts.begin(), personalStatBoosts.end(),
//        [](const StatBoost &a, const StatBoost &b) -> bool
//        {
//            return a.priority > b.priority;
//        });

    for (StatBoost statBoost : personalStatBoosts)
    {
        if (statBoost.stat == stat)
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
    return finalStat;
}
