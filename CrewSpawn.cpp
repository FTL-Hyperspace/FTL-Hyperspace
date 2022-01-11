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
        if (spawnName == "enemy")
        {
            crewSpawn.enemy = EventsParser::ParseBoolean(spawnNode->value());
        }
    }

    return crewSpawn;
}


static bool g_forceNoSlot = false;

HOOK_METHOD_PRIORITY(CrewMember, constructor, -1000, (CrewBlueprint& bp, int shipId, bool enemy, CrewAnimation *animation) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> CrewMember::constructor -> Begin (CrewSpawn.cpp)\n")
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
        if (crewSpawn.enemy) intruder = !intruder;

        int freeSlots = 0;

        for (auto i : ShipGraph::GetShipInfo(ship->iShipId)->rooms)
        {
            freeSlots += i->GetEmptySlots(intruder);
        }

        freeSlots = std::min(freeSlots, crewSpawn.number);

        for (int i = 0; i < freeSlots; i++)
        {
            Slot currentSlot;
            ShipGraph* graph = ShipGraph::GetShipInfo(ship->iShipId);

            if (tile)
            {
                currentSlot = graph->GetClosestSlot({spawnPos.x, spawnPos.y}, ship->iShipId, intruder);
            }

            g_forceNoSlot = crewSpawn.noSlot;
            auto crew = ship->AddCrewMemberFromString(crewSpawn.name, crewSpawn.race, intruder, room, false, random32() % 2 == 0);
            g_forceNoSlot = false;

            if (!tile)
            {
                currentSlot = crew->currentSlot;
            }
            crew->iRoomId = room;
            crew->x = spawnPos.x;
            crew->y = spawnPos.y;
            crew->goal_x = spawnPos.x;
            crew->goal_y = spawnPos.y;
            crew->crewAnim->lastPosition.x = spawnPos.x;
            crew->crewAnim->lastPosition.y = spawnPos.y;

            if (currentSlot.roomId != -1)
            {
                Path testPath = graph->FindPath({crew->x, crew->y}, graph->GetSlotWorldPosition(currentSlot.roomId, currentSlot.slotId), crew->iShipId);

                if (testPath.distance != -1.f)
                {
                    crew->ClearPath();
                    if (!tile || currentSlot.roomId != crew->currentSlot.roomId || currentSlot.slotId != crew->currentSlot.slotId)
                    {
                        crew->MoveToRoom(currentSlot.roomId, currentSlot.slotId, true);
                    }
                }
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


