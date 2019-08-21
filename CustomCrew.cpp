#include "Global.h"
#include <cstdlib>


HOOK_METHOD_PRIORITY(CrewMember, GetNewGoal, 2000, () -> bool)
{
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

                    int offset = rand() % 17;
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

