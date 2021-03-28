#include "StatBoost.h"
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
                for (auto crewChild = child->first_node(); crewChild; crewChild->next_sibling())
                {
                    def.whiteList.push_back(crewChild->name());
                }
            }
            if (name == "blackList")
            {
                for (auto crewChild = child->first_node(); crewChild; crewChild->next_sibling())
                {
                    def.blackList.push_back(crewChild->name());
                }
            }
        }
    }

    return def;
}
