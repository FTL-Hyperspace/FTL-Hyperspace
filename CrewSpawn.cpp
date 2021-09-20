#include "CrewSpawn.h"
#include <boost/lexical_cast.hpp>

CrewSpawn CrewSpawn::ParseCrewSpawn(rapidxml::xml_node<char>* node)
{
    CrewSpawn crewSpawn;

    for (auto spawnNode = node->first_node(); spawnNode; spawnNode = spawnNode->next_sibling())
    {
        std::string spawnName = spawnNode->name();
        if (spawnName == "race")
        {
            crewSpawn.race = spawnNode->value();
        }
        if (spawnName == "name")
        {
            crewSpawn.name = spawnNode->value();
        }
        if (spawnName == "healthPercentage")
        {
            crewSpawn.healthPercentage = boost::lexical_cast<float>(spawnNode->value());
        }
        if (spawnName == "statBoosts")
        {
            for (auto statBoostNode = spawnNode->first_node(); statBoostNode; statBoostNode = statBoostNode->next_sibling())
            {
                crewSpawn.statBoosts.push_back(StatBoostManager::GetInstance()->ParseStatBoostNode(statBoostNode, StatBoostDefinition::BoostSource::CREW));
            }
        }
        if (spawnName == "noSlot")
        {
            crewSpawn.noSlot = EventsParser::ParseBoolean(spawnNode->value());
        }
    }

    return crewSpawn;
}


static bool g_forceNoSlot = false;

HOOK_METHOD_PRIORITY(CrewMember, constructor, -1000, (CrewBlueprint& bp, int shipId, bool enemy, CrewAnimation *animation) -> void)
{
    super(bp, shipId, enemy, animation);

    if (g_forceNoSlot)
    {
        CM_EX(this)->noSlot = true;
    }

    g_forceNoSlot = false;
}

std::vector<CrewMember*> CrewSpawn::SpawnCrew(CrewSpawn& crewSpawn, ShipManager *ship, bool intruder, Pointf spawnPos)
{
    std::vector<CrewMember*> crewList;

    for (int i = 0; i < crewSpawn.number; i++)
    {
        int room = ship->ship.GetSelectedRoomId(spawnPos.x, spawnPos.y, true);

        g_forceNoSlot = crewSpawn.noSlot;
        auto crew = ship->AddCrewMemberFromString(crewSpawn.name, crewSpawn.race, intruder, room, false, random32() % 2 == 0);
        g_forceNoSlot = false;

        Slot currentSlot = crew->currentSlot;
        crew->x = spawnPos.x;
        crew->y = spawnPos.y;
        crew->crewAnim->lastPosition.x = spawnPos.x;
        crew->crewAnim->lastPosition.y = spawnPos.y;

        crew->MoveToRoom(currentSlot.roomId, currentSlot.slotId, true);

        for (auto statBoostDef : crewSpawn.statBoosts)
        {
            StatBoost statBoost = StatBoost(statBoostDef);

            statBoost.crewSource = crew;
            CM_EX(crew)->outgoingStatBoosts.push_back(statBoost);
        }

        crewList.push_back(crew);
    }

    return crewList;
}


