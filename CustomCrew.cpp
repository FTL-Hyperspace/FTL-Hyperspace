#include "CustomCrew.h"

#include <boost/lexical_cast.hpp>
#include <algorithm>


CustomCrewManager CustomCrewManager::instance = CustomCrewManager();


void CustomCrewManager::AddCrewDefinition(CrewDefinition crew)
{
    this->blueprintNames[crew.race] = crew;
}


void CustomCrewManager::ParseCrewNode(rapidxml::xml_node<char> *node)
{
    try
    {
        for (auto child = node->first_node(); child; child = child->next_sibling())
        {
            if (child->first_attribute("name"))
            {
                std::string name = std::string(child->first_attribute("name")->value());

                CrewDefinition crew;

                crew.race = name;
                try
                {
                    for (auto stat = child->first_node(); stat; stat = stat->next_sibling())
                    {
                        std::string str = std::string(stat->name());
                        std::string val = std::string(stat->value());

                        if (str == "canFight")
                        {
                            crew.canFight = val == "true";
                        }
                        if (str == "canSuffocate")
                        {
                            crew.canSuffocate = val == "true";
                        }
                        if (str == "canBurn")
                        {
                            crew.canBurn = val == "true";
                        }
                        if (str == "maxHealth")
                        {
                            crew.maxHealth = boost::lexical_cast<int>(val);
                        }
                        if (str == "moveSpeedMultiplier")
                        {
                            crew.moveSpeedMultiplier = boost::lexical_cast<float>(val);
                        }
                        if (str == "repairSpeed")
                        {
                            crew.repairSpeed = boost::lexical_cast<float>(val);
                        }
                        if (str == "damageMultiplier")
                        {
                            crew.damageMultiplier = boost::lexical_cast<float>(val);
                        }
                        if (str == "fireRepairMultiplier")
                        {
                            crew.fireRepairMultiplier = boost::lexical_cast<float>(val);
                        }
                        if (str == "suffocationModifier")
                        {
                            crew.suffocationModifier = boost::lexical_cast<float>(val);
                        }
                        if (str == "providesPower")
                        {
                            crew.providesPower = val == "true";
                        }
                        if (str == "isTelepathic")
                        {
                            crew.isTelepathic = val == "true";
                        }
                        if (str == "isAnaerobic")
                        {
                            crew.isAnaerobic = val == "true";
                        }
                    }
                }
                catch (boost::bad_lexical_cast const &e)
                {
                    MessageBoxA(NULL, e.what(), "Error", MB_ICONERROR);
                }

                this->AddCrewDefinition(crew);
            }
        }
    }
    catch (...)
    {
        MessageBoxA(NULL, "Error parsing <crew> in hyperspace.xml", "Error", MB_ICONERROR);
    }

}






CrewMember* CustomCrewManager::CreateCrewMember(CrewBlueprint* bp, int shipId, bool intruder)
{
    std::string race = bp->name;
    if (!this->IsRace(race))
        return 0;

    Pointf unk = Pointf(0.f, 0.f);
    CrewAnimation* animation = new CrewAnimation(shipId, race, unk, intruder);
    CrewMember *crew = new CrewMember(*bp, shipId, intruder, animation);



    return crew;
}

bool CustomCrewManager::IsRace(const std::string& race)
{
    return std::count_if(this->blueprintNames.begin(),
                         this->blueprintNames.end(),
                         [race](std::pair<std::string, CrewDefinition> i) { return i.first == race; } )
                          > 0;
}









//=================================

HOOK_METHOD_PRIORITY(CrewMember, GetNewGoal, 2000, () -> bool)
{
    return super();
    auto ex = CM_EX(this);

    if (this->last_door && !ex->canPhaseThroughDoors)
        this->last_door->FakeClose();
    this->last_door = 0;

    bool result = false;


    if (this->path.distance != -1.f)
    {
        Point pos = Point(std::floor(this->x), std::floor(this->y));

        int roomId = this->iRoomId;
        ShipGraph* shipGraph = ShipGraph::GetShipInfo(this->currentShipId);
        Point intoRoom = shipGraph->GetIntoRoom(roomId, pos);

        if (this->path.doors.size() > 0)
        {
            Door* door = this->path.doors.front();

            Point doorPos = door->GetCenterPoint();
            Point entryWay = door->GetEntryWay(this->iRoomId);

            Point gridPos = ShipGraph::TranslateToGrid(pos.x, pos.y);
            Point entryPos = ShipGraph::TranslateToGrid(entryWay.x, entryWay.y);

            if (entryPos.x != gridPos.x || entryPos.y != gridPos.y)
            {
                if (intoRoom.x == -1 || intoRoom.y == -1)
                {
                    this->goal_x = entryWay.x;
                    this->goal_y = entryWay.y;
                }
                else
                {
                    this->goal_x = intoRoom.x;
                    this->goal_y = intoRoom.y;
                }
                return true;
            }

            if (door->IsSealed(this->iShipId) && (!this->bMindControlled || door->lockedDown.running) && !ex->canPhaseThroughDoors)
            {
                bool up = false;
                bool right = false;
                bool down = false;
                bool left = false;

                if (this->blockingDoor)
                {
                    this->blockingDoor = door;
                    this->SetCurrentTarget(door, false);
                    return true;
                }
                else
                {
                    if (doorPos.y > entryWay.y)
                    {
                        down = true;
                    }
                    else if (doorPos.y < entryWay.y)
                    {
                        up = true;
                    }

                    if (doorPos.x > entryWay.x)
                    {
                        right = true;
                    }
                    else if (doorPos.x < entryWay.x)
                    {
                        left = true;
                    }

                    int offset = (G_->GetRNG() ? rand() : random32()) % 17;
                    if (door->bVertical)
                    {
                        if (left)
                        {
                            this->goal_x = doorPos.x + 8;
                        }
                        else
                        {
                            this->goal_x = doorPos.x - 8;
                        }

                        this->goal_y = offset + (doorPos.y - 8);

                    }
                    else
                    {
                        if (up)
                        {
                            this->goal_y = doorPos.y + 8;
                        }
                        else
                        {
                            this->goal_y = doorPos.y - 8;
                        }

                        this->goal_x = offset + (doorPos.x - 8);
                    }

                    this->blockingDoor = door;
                    this->SetCurrentTarget(door, false);
                    return true;
                }
            }

            if (door->bVertical)
            {
                if (std::abs(pos.y - entryWay.y) > 0.05)
                {
                    this->goal_x = this->x;
                    this->goal_y = entryWay.y;
                    return true;
                }
                if (doorPos.x < entryWay.x)
                {
                    this->goal_x = entryWay.x - 35;
                    this->goal_y = this->y;
                }
                if (doorPos.x > entryWay.x)
                {
                    this->goal_x = entryWay.x + 34;
                    this->goal_y = this->y;
                }
                this->path.doors.erase(this->path.doors.begin());
            }
            else
            {
                if (std::abs(pos.x - entryWay.x) > 0.05)
                {
                    this->goal_y = this->y;
                    this->goal_x = entryWay.x;
                    return true;
                }
                if (doorPos.y < entryWay.y)
                {
                    this->goal_y = entryWay.y - 35;
                    this->goal_x = this->x;
                }
                if (doorPos.y > entryWay.y)
                {
                    this->goal_y = entryWay.y + 34;
                    this->goal_x = this->x;
                }



                this->path.doors.erase(this->path.doors.begin());

            }

            if (!door->bOpen && !door->forcedOpen.running && !ex->canPhaseThroughDoors)
            {
                this->last_door = door;
                door->FakeOpen();
            }

            return true;
        }
        else
        {
            if (intoRoom.x != -1 && intoRoom.y != -1)
            {
                this->goal_x = intoRoom.x;
                this->goal_y = intoRoom.y;

                return true;
            }
            else
            {
                Point finish = this->path.finish;
                this->goal_x = finish.x;
                this->goal_y = finish.y;

                if ( std::abs(this->path.finish.x - this->x) > 0.5 )
                {
                    return true;
                }

                this->x = this->path.finish.x;

                if ( std::abs(this->path.finish.y - this->y) > 0.5 )
                {
                    return true;
                }

                this->y = this->path.finish.y;

                this->path.distance = -1.f;
            }
        }
    }

    return result;
}



HOOK_METHOD(CrewMemberFactory, CreateCrewMember, (CrewBlueprint* bp, int shipId, bool intruder) -> CrewMember*)
{
    //printf("%s\n", bp->name.c_str());
    auto custom = CustomCrewManager::GetInstance();
    CrewMember *newCrew = custom->CreateCrewMember(bp, shipId, intruder);

    if (newCrew)
    {
        this->crewMembers.push_back(newCrew);
        this->OnLoop();
        return newCrew;
    }

    return super(bp, shipId, intruder);
}

HOOK_STATIC(CrewMemberFactory, IsRace, (std::string& race) -> bool)
{
    auto custom = CustomCrewManager::GetInstance();

    if (custom->IsRace(race))
        return true;
    return super(race);
}

