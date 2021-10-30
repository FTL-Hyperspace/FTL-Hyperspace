#include "CrewSpawn.h"
#include <boost/lexical_cast.hpp>

CrewSpawn CrewSpawn::ParseCrewSpawn(rapidxml::xml_node<char>* node, bool isCrew)
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
        if (spawnName == "number")
        {
            crewSpawn.number = boost::lexical_cast<int>(spawnNode->value());
        }
        if (spawnName == "healthPercentage")
        {
            crewSpawn.healthPercentage = boost::lexical_cast<float>(spawnNode->value());
        }
        if (spawnName == "lifetime")
        {
            crewSpawn.lifetime = boost::lexical_cast<float>(spawnNode->value());
        }
        if (spawnName == "statBoosts")
        {
            for (auto statBoostNode = spawnNode->first_node(); statBoostNode; statBoostNode = statBoostNode->next_sibling())
            {
                crewSpawn.statBoosts.push_back(StatBoostManager::GetInstance()->ParseStatBoostNode(statBoostNode, isCrew ? StatBoostDefinition::BoostSource::CREW : StatBoostDefinition::BoostSource::AUGMENT));
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

std::vector<CrewMember*> CrewSpawn::SpawnCrew(CrewSpawn& crewSpawn, ShipManager *ship, bool intruder, Pointf spawnPos, bool tile)
{
    std::vector<CrewMember*> crewList;

    int room = ship->ship.GetSelectedRoomId(spawnPos.x, spawnPos.y, true);

    if (room != -1)
    {
        for (int i = 0; i < crewSpawn.number; i++)
        {
            Slot currentSlot;

            if (tile)
            {
                ShipGraph* graph = ShipGraph::GetShipInfo(ship->iShipId);
                ShipGraph::GetClosestSlot(&currentSlot, graph, {spawnPos.x, spawnPos.y}, ship->iShipId, intruder);
            }

            g_forceNoSlot = crewSpawn.noSlot;
            auto crew = ship->AddCrewMemberFromString(crewSpawn.name, crewSpawn.race, intruder, room, false, random32() % 2 == 0);
            g_forceNoSlot = false;

            if (!tile)
            {
                currentSlot = crew->currentSlot;
            }
            crew->x = spawnPos.x;
            crew->y = spawnPos.y;
            crew->crewAnim->lastPosition.x = spawnPos.x;
            crew->crewAnim->lastPosition.y = spawnPos.y;

            if (!tile || currentSlot.roomId != crew->currentSlot.roomId || currentSlot.slotId != crew->currentSlot.slotId)
            {
                crew->MoveToRoom(currentSlot.roomId, currentSlot.slotId, true);
            }

            crew->health.first = crew->health.second * crewSpawn.healthPercentage;

            if (crewSpawn.lifetime != -1.f)
            {
                CrewMember_Extend* ex = CM_EX(crew);
                ex->deathTimer = new TimerHelper(false);
                ex->deathTimer->Start(crewSpawn.lifetime);
            }

            for (auto statBoostDef : crewSpawn.statBoosts)
            {
                StatBoost statBoost(statBoostDef);
                statBoost.crewSource = crew;
                statBoost.sourceShipId = crew->iShipId;
                StatBoostManager::GetInstance()->CreateTimedAugmentBoost(statBoost, crew);
            }

            crewList.push_back(crew);
        }
    }

    return crewList;
}


