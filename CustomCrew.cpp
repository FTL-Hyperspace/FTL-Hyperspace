#include "CustomCrew.h"

#include <boost/lexical_cast.hpp>
#include <algorithm>


CustomCrewManager CustomCrewManager::instance = CustomCrewManager();


void CustomCrewManager::AddCrewDefinition(CrewDefinition crew)
{
    blueprintNames[crew.race] = crew;
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
                            crew.canFight = EventsParser::ParseBoolean(val);
                        }
                        if (str == "canSuffocate")
                        {
                            crew.canSuffocate = EventsParser::ParseBoolean(val);
                        }
                        if (str == "canBurn")
                        {
                            crew.canBurn = EventsParser::ParseBoolean(val);
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
                            crew.providesPower = EventsParser::ParseBoolean(val);
                        }
                        if (str == "isTelepathic")
                        {
                            crew.isTelepathic = EventsParser::ParseBoolean(val);
                        }
                        if (str == "isAnaerobic")
                        {
                            crew.isAnaerobic = EventsParser::ParseBoolean(val);
                        }
                        if (str == "fireDamageMultiplier")
                        {
                            crew.fireDamageMultiplier = boost::lexical_cast<float>(val);
                        }
                        if (str == "canPhaseThroughDoors")
                        {
                            crew.canPhaseThroughDoors = EventsParser::ParseBoolean(val);
                        }
                    }
                }
                catch (boost::bad_lexical_cast const &e)
                {
                    MessageBoxA(NULL, e.what(), "Error", MB_ICONERROR);
                }

                AddCrewDefinition(crew);
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
    if (!IsRace(race))
        return 0;

    Pointf unk = Pointf(0.f, 0.f);
    CrewAnimation* animation = new CrewAnimation(shipId, race, unk, intruder);
    CrewMember *crew = new CrewMember(*bp, shipId, intruder, animation);



    return crew;
}

bool CustomCrewManager::IsRace(const std::string& race)
{
    return std::count_if(blueprintNames.begin(),
                         blueprintNames.end(),
                         [race](std::pair<std::string, CrewDefinition> i) { return i.first == race; } )
                          > 0;
}









//=================================

HOOK_METHOD_PRIORITY(CrewMember, UpdateHealth, 2000, () -> void)
{


    if (iOnFire && CanBurn())
    {
        CustomCrewManager *custom = CustomCrewManager::GetInstance();

        float fireMultiplier = 1.f;

        if (custom->IsRace(species))
        {
            fireMultiplier = custom->GetDefinition(species).fireDamageMultiplier;
        }

        DirectModifyHealth(G_->GetCFPS()->GetSpeedFactor() * -0.133f * fireMultiplier);
    }

    if (bSuffocating && !IsAnaerobic())
    {
        float mod = 1.f;
        if (GetShipObject()->HasAugmentation("O2_MASKS"))
        {
            mod = GetShipObject()->GetAugmentationValue("O2_MASKS");
        }

        float multiplier = GetSuffocationMultiplier();

        DirectModifyHealth(G_->GetCFPS()->GetSpeedFactor() * -0.4f * mod * multiplier);
    }

    float mod = 1.f;
    if (IsDrone())
    {
        mod = 0.2f;
    }

    DirectModifyHealth(G_->GetCFPS()->GetSpeedFactor() * fMedbay * mod * 0.4f);

    //super();
}

HOOK_METHOD_PRIORITY(CrewMember, GetNewGoal, 2000, () -> bool)
{
    auto ex = CM_EX(this);

    if (last_door && !ex->canPhaseThroughDoors)
    {
        last_door->FakeClose();
    }


    last_door = 0;

    bool result = false;


    if (path.distance != -1.f)
    {
        Point pos = Point(std::floor(x), std::floor(y));

        int roomId = iRoomId;
        ShipGraph* shipGraph = ShipGraph::GetShipInfo(currentShipId);
        Point intoRoom = shipGraph->GetIntoRoom(roomId, pos);

        if (path.doors.size() > 0)
        {
            Door* door = path.doors.front();

            Point doorPos = door->GetCenterPoint();
            Point entryWay = door->GetEntryWay(iRoomId);

            Point gridPos = ShipGraph::TranslateToGrid(pos.x, pos.y);
            Point entryPos = ShipGraph::TranslateToGrid(entryWay.x, entryWay.y);

            if (entryPos.x != gridPos.x || entryPos.y != gridPos.y)
            {
                if (intoRoom.x == -1 || intoRoom.y == -1)
                {
                    goal_x = entryWay.x;
                    goal_y = entryWay.y;
                }
                else
                {
                    goal_x = intoRoom.x;
                    goal_y = intoRoom.y;
                }
                return true;
            }

            if (door->IsSealed(iShipId) && (!bMindControlled || door->lockedDown.running) && !ex->canPhaseThroughDoors)
            {
                bool up = false;
                bool right = false;
                bool down = false;
                bool left = false;

                if (blockingDoor)
                {
                    blockingDoor = door;
                    SetCurrentTarget(door, false);
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
                            goal_x = doorPos.x + 8;
                        }
                        else
                        {
                            goal_x = doorPos.x - 8;
                        }

                        goal_y = offset + (doorPos.y - 8);

                    }
                    else
                    {
                        if (up)
                        {
                            goal_y = doorPos.y + 8;
                        }
                        else
                        {
                            goal_y = doorPos.y - 8;
                        }

                        goal_x = offset + (doorPos.x - 8);
                    }

                    blockingDoor = door;
                    SetCurrentTarget(door, false);
                    return true;
                }
            }

            if (door->bVertical)
            {
                if (std::abs(pos.y - entryWay.y) > 0.05)
                {
                    goal_x = x;
                    goal_y = entryWay.y;
                    return true;
                }
                if (doorPos.x < entryWay.x)
                {
                    goal_x = entryWay.x - 35;
                    goal_y = y;
                }
                if (doorPos.x > entryWay.x)
                {
                    goal_x = entryWay.x + 34;
                    goal_y = y;
                }
                path.doors.erase(path.doors.begin());
            }
            else
            {
                if (std::abs(pos.x - entryWay.x) > 0.05)
                {
                    goal_y = y;
                    goal_x = entryWay.x;
                    return true;
                }
                if (doorPos.y < entryWay.y)
                {
                    goal_y = entryWay.y - 35;
                    goal_x = x;
                }
                if (doorPos.y > entryWay.y)
                {
                    goal_y = entryWay.y + 34;
                    goal_x = x;
                }



                path.doors.erase(path.doors.begin());

            }

            if (!door->bOpen && !door->forcedOpen.running)
            {
                if (!ex->canPhaseThroughDoors)
                {
                    last_door = door;
                    door->FakeOpen();
                }
                else
                {
                    G_->GetSoundControl()->PlaySoundMix("phase", -1.f, false);
                }
            }


            return true;
        }
        else
        {
            if (intoRoom.x != -1 && intoRoom.y != -1)
            {
                goal_x = intoRoom.x;
                goal_y = intoRoom.y;

                return true;
            }
            else
            {
                Point finish = path.finish;
                goal_x = finish.x;
                goal_y = finish.y;

                if ( std::abs(path.finish.x - x) > 0.5 )
                {
                    return true;
                }

                x = path.finish.x;

                if ( std::abs(path.finish.y - y) > 0.5 )
                {
                    return true;
                }

                y = path.finish.y;

                path.distance = -1.f;
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
        crewMembers.push_back(newCrew);
        OnLoop();
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

HOOK_METHOD(CrewMember, constructor, (CrewBlueprint& blueprint, int shipId, bool intruder, CrewAnimation *animation) -> void)
{
	super(blueprint, shipId, intruder, animation);

    auto custom = CustomCrewManager::GetInstance();
    if (custom->IsRace(species))
    {
        CM_EX(this)->canPhaseThroughDoors = custom->GetDefinition(species).canPhaseThroughDoors;
    }
}
