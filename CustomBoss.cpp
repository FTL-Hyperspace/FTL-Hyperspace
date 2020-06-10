#include "CustomBoss.h"
#include <boost/lexical_cast.hpp>

std::vector<std::pair<std::string, int>> CustomBoss::initialCrewList = std::vector<std::pair<std::string, int>>();
std::vector<std::pair<std::string, int>> CustomBoss::currentCrewCounts = std::vector<std::pair<std::string, int>>();

void CustomBoss::ParseBossCrewNode(rapidxml::xml_node<char> *node)
{
    for (auto crewNode = node->first_node(); crewNode; crewNode = crewNode->next_sibling())
    {
        int roomId = 0;

        if (crewNode->first_attribute("room"))
        {
            roomId = boost::lexical_cast<int>(crewNode->first_attribute("room")->value());
        }

        auto crewDef = std::pair<std::string, int>(crewNode->name(), roomId);

        initialCrewList.push_back(crewDef);
    }
}



static bool isStartingStage = false;

HOOK_METHOD(BossShip, StartStage, () -> void)
{
    isStartingStage = true;

    super();

    isStartingStage = false;

    if (currentStage == 1)
    {
        for (int i = 0; i < CustomBoss::initialCrewList.size(); i++)
        {
            shipManager->AddCrewMemberFromString("", CustomBoss::initialCrewList[i].first, false, CustomBoss::initialCrewList[i].second, false, rand() % 2);
        }
    }
    else
    {
        int roomCount = ShipGraph::GetShipInfo(iShipId)->RoomCount();
        for (auto i : CustomBoss::currentCrewCounts)
        {
            if (i.second < roomCount)
            {
                shipManager->AddCrewMemberFromString("", i.first, false, i.second, false, rand() % 2);
            }
        }
    }
}

HOOK_METHOD(BossShip, OnLoop, () -> void)
{
    super();


    if (!shipManager->bJumping && !shipManager->bDestroyed)
    {
        CustomBoss::currentCrewCounts.clear();

        for (auto i : shipManager->vCrewList)
        {
            if (!i->bDead && !i->IsDrone() && iShipId == i->iShipId)
            {
                auto crewDef = std::pair<std::string, int>(i->species, i->iRoomId);
                CustomBoss::currentCrewCounts.push_back(crewDef);
            }
        }
    }

}

HOOK_METHOD(ShipManager, AddCrewMemberFromString, (const std::string& name, const std::string& race, bool intruder, int roomId, bool init, bool male) -> CrewMember*)
{
    if (!isStartingStage)
    {
        return super(name, race, intruder, roomId, init, male);
    }
}

