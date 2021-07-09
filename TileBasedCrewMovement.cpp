#include "CustomOptions.h"
#include <algorithm>

HOOK_METHOD(CrewControl, RButton, (int x, int y, bool shiftHeld) -> void)
{
    if(!CustomOptionsManager::GetInstance()->alternateCrewMovement.currentValue)
    {
        ShipManager* ship;
        if(this->selectedPlayerShip)
        {
            ship = this->shipManager;
        }
        else
        {
            ship = this->combatControl->GetCurrentTarget();
        }
        if(!(CustomOptionsManager::GetInstance()->rightClickDoorOpening.currentValue) && this->selectedDoor)
        {
            if (ship->DoorsFunction())
            {
                this->selectedDoor->Manipulate();
            }
        }
        if(!this->selectedDoor)
        {
            if(!selectedCrew.empty() && this->selectedRoom != -1)
            {
                if(selectedCrew.size() == 1)
                {
                    // move to tile
                    int tile = 0;
                    int baseLineX;
                    int baseLineY;
                    if(this->selectedPlayerShip)
                    {
                        baseLineX = x - this->worldCurrentMouse.x; // used to offset the x/y coordinates to whatever the rooms are
                        baseLineY = y - this->worldCurrentMouse.y;
                    }
                    else
                    {
                        baseLineX = this->combatControl->position.x + this->combatControl->targetPosition.x; // used to offset the x/y coordinates to whatever the rooms are for enemy ships
                        baseLineY = this->combatControl->position.y + this->combatControl->targetPosition.y;
                    }
                    for (int i = 0; i < ship->ship.vRoomList.size(); ++i)
                    {
                        int smallestXOffset = 0;
                        int smallestYOffset = 0;
                        if (smallestXOffset > ship->ship.vRoomList.at(i)->rect.x)
                        {
                            smallestXOffset = ship->ship.vRoomList.at(i)->rect.x;
                        }
                        if (smallestYOffset > ship->ship.vRoomList.at(i)->rect.y)
                        {
                            smallestYOffset = ship->ship.vRoomList.at(i)->rect.y;
                        }
                        baseLineX += smallestXOffset;
                        baseLineY += smallestYOffset;
                    }

                    Room* room = ship->ship.vRoomList.at(this->selectedRoom);
                    tile = ((x - baseLineX - room->rect.x) / 35 + (room->rect.w / 35) * ((y - baseLineY - room->rect.y) / 35) );
//                    printf("Tile: %i XPos: %i YPos: %i BaseLineX: %i BaselineY: %i \n", tile, (x - baseLineX - room->rect.x) / 35, (y - baseLineY - room->rect.y) / 35, baseLineX, baseLineY);
                    if(tile < 0)
                    {
                        tile = 0; // crash handler
                    }
                    if(this->selectedPlayerShip && selectedCrew.at(0)->currentShipId == 0 || (!this->selectedPlayerShip) && selectedCrew.at(0)->currentShipId == 1)
                    {
                        for(int i = 0; i < ship->ship.vRoomList.size(); ++i)
                        {
                            if(ship->ship.vRoomList.at(i)->iRoomId == this->selectedRoom)
                            {
                                room = ship->ship.vRoomList.at(i);
                                if(room->GetEmptySlots(false) < room->rect.h * room->rect.w / 35 / 35 && std::find(room->filledSlots.begin(), room->filledSlots.end(), tile) != room->filledSlots.end())
                                {
                                    CrewMember* swapCrew;
                                    for (int j = 0; j < ship->vCrewList.size(); ++j)
                                    {
                                        if(ship->vCrewList.at(j)->iRoomId == selectedRoom && ship->vCrewList.at(j)->currentSlot.slotId == tile)
                                        {
                                            swapCrew = ship->vCrewList.at(j);
                                            break;
                                        }
                                    }
                                    if(swapCrew != selectedCrew.at(0))
                                    {
                                        swapCrew->EmptySlot();
                                        Slot temp;
                                        temp = selectedCrew.at(0)->currentSlot;
                                        printf("Slot stuff: room ID: %i, slot ID: %i \n", temp.roomId, temp.slotId);
                                        selectedCrew.at(0)->MoveToRoom(this->selectedRoom, tile, true);
                                        swapCrew->MoveToRoom(temp.roomId, temp.slotId, true);
                                    }
//                                    printf("How%i \n", 0);
                                }
                                else
                                {
                                    selectedCrew.at(0)->MoveToRoom(this->selectedRoom, tile, true); // only move if clicking on the same ship
                                }
                                break;
                            }
                        }
                    }
                    //delete room;
                }
                else
                {
                    // move to room but also swap?
                    super(x, y, shiftHeld);
                }
            }
        }
    }
    else
    {
        super(x, y, shiftHeld);
    }
}
