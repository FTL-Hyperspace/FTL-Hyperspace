#include "CustomOptions.h"
#include <algorithm>


HOOK_METHOD_PRIORITY(CrewControl, RButton, 1000, (int x, int y, bool shiftHeld) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> CrewControl::RButton -> Begin (TileBasedCrewMovement.cpp)\n")
    if (selectedDoor != nullptr && !CustomOptionsManager::GetInstance()->rightClickDoorOpening.currentValue)
    {
        selectedDoor = nullptr;
    }

    if (selectedDoor == nullptr && CustomOptionsManager::GetInstance()->alternateCrewMovement.currentValue)
    {
        if (!selectedCrew.empty() && selectedRoom != -1)
        {
            ShipManager* ship;
            if (selectedPlayerShip)
            {
                ship = shipManager;
            }
            else
            {
                ship = combatControl->GetCurrentTarget();
            }

            int tile = 0;
            int wX,wY;
            if (selectedPlayerShip)
            {
                wX = worldCurrentMouse.x;
                wY = worldCurrentMouse.y;
            }
            else
            {
                wX = x - combatControl->position.x - combatControl->targetPosition.x;
                wY = y - combatControl->position.y - combatControl->targetPosition.y;
            }

            Room* room = ship->ship.vRoomList.at(selectedRoom);
            tile = ((wX - room->rect.x) / 35 + (room->rect.w / 35) * ((wY - room->rect.y) / 35) );
            if (tile < 0 || tile >= (room->rect.w / 35)*(room->rect.h / 35))
            {
                return super(x, y, shiftHeld);
            }

            // Find the crewmember currently in this slot
            bool occupiedSlot = room->slots[ship->iShipId][tile];
            CrewMember *swapCrew = nullptr;
            if (occupiedSlot)
            {
                for (CrewMember *crew : ship->vCrewList)
                {
                    if (crew->currentSlot.roomId == selectedRoom && crew->currentSlot.slotId == tile && crew->intruder == ship->iShipId)
                    {
                        swapCrew = crew;
                        break;
                    }
                }
            }

            bool roomIsFull = room->Full(ship->iShipId);
            bool tileAvailable = !occupiedSlot;
            if (swapCrew != nullptr) tileAvailable = swapCrew->GetControllable() && swapCrew->Functional() && (swapCrew->fStunTime <= 0.f || !swapCrew->AtFinalGoal()) && swapCrew->crewAnim->status != 3;

            // Check that slot is either empty or has a crew that can swap
            if (tileAvailable)
            {
                for (CrewMember *crew : selectedCrew)
                {
                    if (ship->iShipId == crew->currentShipId && crew->GetControllable() && crew->Functional() && (crew->fStunTime <= 0.f || !crew->AtFinalGoal()) && crew->crewAnim->status != 3)
                    {
                        if (swapCrew == nullptr)
                        {
                            // Destination slot is empty
                            bool moved = crew->MoveToRoom(selectedRoom, tile, true);
                            if (moved) break;
                        }
                        else if (swapCrew != crew)
                        {
                            if (crew->currentSlot.roomId == selectedRoom)
                            {
                                // Destination slot is occupied but the selected crewmember is in the same room to swap places
                                int oldTile = crew->currentSlot.slotId;
                                swapCrew->EmptySlot();
                                bool moved = crew->MoveToRoom(selectedRoom, tile, true);
                                swapCrew->MoveToRoom(selectedRoom, oldTile, true);
                                if (moved) break;
                            }
                            else if (!roomIsFull)
                            {
                                // Destination slot is occupied but there's another empty slot
                                bool moved = swapCrew->MoveToRoom(selectedRoom, -1, true);
                                if (moved) moved = crew->MoveToRoom(selectedRoom, tile, true);
                                if (moved) break;
                            }
                        }
                    }
                }
            }
        }
    }

    // Move the rest of the crew
    return super(x, y, shiftHeld);
}


/*
HOOK_METHOD(CrewControl, RButton, (int x, int y, bool shiftHeld) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewControl::RButton -> Begin (TileBasedCrewMovement.cpp)\n")
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
*/
