#include "Global.h"
#include "zhl.h"
#include "RoamingShip.h"
#include <math.h>
#define MAP G_->GetWorld()->starMap

/*
<roamingShips>
    <add id="ship_rebel" icon="path/to/icon" behaviour="1" timeToMove="2">
        <event>EVENT_FIGHT_1</event>
        <event>EVENT_FIGHT_2</event>
        <event>EVENT_FIGHT_3</event>
    </add>
</roamingShips>
*/

RoamingShipsManager *RoamingShipsManager::instance = new RoamingShipsManager();

void RoamingShipsManager::ParseShipsNode(rapidxml::xml_node<char>* node)
{
    for (auto child = node->first_node(); child; child = child->next_sibling())
    {
        std::string name = child->name();

        if (name == "add" && child->first_attribute("id"))
        {
            RoamingShip *ship = new RoamingShip();
            ship->id = child->first_attribute("id")->value();

            if (child->first_attribute("icon"))
            {
                // Load the icon as a texture
                GL_Texture* texture = G_->GetResources()->GetImageId(child->first_attribute("icon")->value());

                // Create a primitive using the loaded texture
                ship->mapIcon = CSurface::GL_CreateImagePrimitive(texture, 0.0f, 0.0f, texture->width_, texture->height_, 0.0f, GL_Color(1.0, 1.0, 1.0, 1.0));

                // Set the texture as antialiased
                ship->mapIcon->textureAntialias = true;
            }

            if (child->first_attribute("behaviour"))
            {
                ship->behavior = std::stoi(child->first_attribute("behaviour")->value());
            }

            if (child->first_attribute("timeToMove"))
            {
                ship->timeToMove = std::stoi(child->first_attribute("timeToMove")->value());
            }

            for (auto event = child->first_node("event"); event; event = event->next_sibling("event"))
            {
                ship->eventsList.push_back(event->value());
            }

            if (child->first_attribute("targetEvent"))
            {
                ship->targetEvent = child->first_attribute("targetEvent")->value();
            }

            RoamingShipsManager::GetInstance()->roamingShips[ship->id] = ship;
        }
    }
}

void RoamingShipsManager::AddRoamingShip(const std::string ship, Location* beacon)
{
    // Add the shipId into activeRoamingShips
    activeRoamingShips.push_back(ship);

    // Set the ship's currentLocation to beacon
    roamingShips[ship]->currentLocation = beacon;

    // Set all other values to default
    roamingShips[ship]->targetLocation = nullptr;
    roamingShips[ship]->beaconDegree = (float)(rand() % 361); // Random value between 0 and 360
    roamingShips[ship]->currentMoveTime = 0;
    roamingShips[ship]->timeToMove = 0;

    // figure out the event its looking for
    roamingShips[ship]->eventTargetLocation = nullptr;

    for (auto location : G_->GetWorld()->starMap.locations)
    {
        if (location->event->eventName == roamingShips[ship]->targetEvent)
        {
            roamingShips[ship]->eventTargetLocation = location;

            break;
        }
    }
}

void RoamingShipsManager::RemoveRoamingShip(const std::string ship)
{
    // Remove the shipId from activeRoamingShips
    activeRoamingShips.erase(std::remove(activeRoamingShips.begin(), activeRoamingShips.end(), ship), activeRoamingShips.end());
}

void RoamingShipsManager::RenderShips()
{
    for (const auto& shipId : activeRoamingShips)
    {
        RoamingShip* ship = roamingShips[shipId]; // finds the specific ship in the RoamingShips collection
        Pointf locationPos = ship->currentLocation->loc; // find the location of the ship

        if (ship->timeToMove < ship->currentMoveTime && ship->targetLocation != nullptr) // checks if its time to move and if the ship has a target location to move to 
        {
            Pointf targetPos = ship->targetLocation->loc;
            // Render the line between current location and target location using GL_DrawRect
            float lineWidth = 8.0f; // Set the line width
            float dx = targetPos.x - locationPos.x;
            float dy = targetPos.y - locationPos.y;
            float length = sqrt(dx * dx + dy * dy);
            float angle = atan2(dy, dx) * (180.0f / M_PI);

            CSurface::GL_PushMatrix();
            CSurface::GL_Translate(locationPos.x, locationPos.y);
            CSurface::GL_Rotate(angle, 0.0f, 0.0f, 1.0f);
            CSurface::GL_DrawRect(0, -lineWidth / 2, length, lineWidth, GL_Color(1.0f, 0.0f, 0.0f, 0.5f));
            CSurface::GL_PopMatrix();

            // Update progress and fade timer
            ship->progress += 0.005f; // Adjust the speed as needed
            if (ship->progress >= 0.20f)
            {
                ship->progress = 0.0f;
                ship->fadeTimer = 1.0f;
            }
            ship->fadeTimer -= 0.05f; // Adjust the fade speed as needed
            if (ship->fadeTimer < 0.0f)
            {
                ship->fadeTimer = 0.0f;
            }

            // Calculate the position of the icon along the line
            float iconX = locationPos.x + dx * ship->progress;
            float iconY = locationPos.y + dy * ship->progress;

            // Assuming ship->mapIcon is a pointer to a GL_Primitive object with an associated GL_Texture
            GL_Texture* iconTexture = ship->mapIcon->texture;

            // Render the icon with fading effect
            CSurface::GL_PushMatrix();
            CSurface::GL_Translate(iconX - iconTexture->width_ / 2, iconY - iconTexture->height_ / 2); // Translate to the center of the icon
            CSurface::GL_Rotate(angle + 90.0f, 0.0f, 0.0f, 1.0f); // Rotate the icon 90 degrees to align with the line
            CSurface::GL_RenderPrimitiveWithAlpha(ship->mapIcon, ship->fadeTimer);
            CSurface::GL_PopMatrix();
        }
        else
        {
            ship->beaconDegree = (ship->beaconDegree + 0.5); // increments the rotation by 0.5
            if (ship->beaconDegree > 360) ship->beaconDegree = 0; // if the rotation is greater than 360, reset it to 0
            // Render the ship mapIcon rotating around the beacon, increment the rotation
            float radian = ship->beaconDegree * (M_PI / 180.f); // trying to get the ship to go in a circle
            int newX = locationPos.x + 20 * cos(radian); // figures out where the x position is
            int newY = locationPos.y + 20 * sin(radian); // figures out where the y position is
            CSurface::GL_PushMatrix();
            CSurface::GL_Translate(newX - ship->mapIcon->texture->width_ / 2, newY - ship->mapIcon->texture->height_ / 2); // Translate to the center of the icon
            CSurface::GL_Rotate(ship->beaconDegree, 0.0f, 0.0f, 1.0f); // Rotate around the center
            CSurface::GL_RenderPrimitive(ship->mapIcon);
            CSurface::GL_PopMatrix();
        }
    }
}
// okay no testing yet i need to figure out a moving thing
void RoamingShipsManager::MoveShips()
{
    for (const auto& shipId : activeRoamingShips)
    {
        RoamingShip* ship = roamingShips[shipId];

        if (ship->timeToMove == ship->currentMoveTime)
        {
            Location* nextLocation = nullptr;

            switch (ship->behavior)
            {
            case 0:
                // nullptr means you do not move
                break;

            case 1:
                nextLocation = ship->currentLocation->connectedLocations[random32() % ship->currentLocation->connectedLocations.size()];
                break;

            case 2:
                if (ship->eventTargetLocation != nullptr) { // this one is for hunting down the target event
                    // Use Dijkstra to get the path and select the next location
                    std::vector<Location*> path = G_->GetWorld()->starMap.Dijkstra(ship->currentLocation, ship->eventTargetLocation, true);
                    if (!path.empty() && path.size() > 1) {
                        nextLocation = path[1];
                    }
                }
                break;

            case 3:
                { // this one is hunting the player
                    std::vector<Location*> path = G_->GetWorld()->starMap.Dijkstra(ship->currentLocation, MAP.currentLoc, true);
                    if (!path.empty() && path.size() > 1) {
                        nextLocation = path[1];
                    }
                }
                break;

            case 4:
                { // this one is hunting the player mostly just filler to let the real logic run in StarMap::OnLoop
                    std::vector<Location*> path = G_->GetWorld()->starMap.Dijkstra(ship->currentLocation, MAP.currentLoc, true);
                    if (!path.empty() && path.size() > 1) {
                        nextLocation = path[1];
                    }
                }
                break;

            case 5:
                { // Roamer looking for the exit beacon
                    // Find the path to the exit beacon
                    Location* exitBeacon = nullptr;
                    for (auto& location : G_->GetWorld()->starMap.locations)
                    {
                        if (location->beacon == true)
                        {
                            hs_log_file("HEYYY I FOUND THE FUCKING EXIT BEACON");
                            exitBeacon = location;
                            break;
                        }
                    }

                    if (exitBeacon != nullptr)
                    {
                        // Use Dijkstra to get the path and select the next location
                        std::vector<Location*> path = G_->GetWorld()->starMap.Dijkstra(ship->currentLocation, exitBeacon, true);
                        hs_log_file("I AM MOVING TOWARDS IT");
                        if (!path.empty() && path.size() > 1) {
                            nextLocation = path[1];
                        }
                    }
                }
                break;

            default:
                break;
            }
            bool locationOccupied = false;
            for (const auto& otherShipId : activeRoamingShips)
            {
                if (otherShipId != shipId)
                {
                    RoamingShip* otherShip = roamingShips[otherShipId];
                    if (otherShip->currentLocation == nextLocation || otherShip->targetLocation == nextLocation)
                    {
                        locationOccupied = true;
                        break;
                    }
                }
            }

            if (!locationOccupied) // i'm like relatively sure that this should work for movement stuff, i mean it kinda works anyway since i havent seen anything wrong
            {
                ship->targetLocation = nextLocation;
            }
            else
            {
                if (ship->behavior == 1) // Random movement behavior
                {
                    // Try to find another random location
                    std::vector<Location*> connectedLocations = ship->currentLocation->connectedLocations;
                    std::random_shuffle(connectedLocations.begin(), connectedLocations.end());
                    for (auto& location : connectedLocations)
                    {
                        locationOccupied = false;
                        for (const auto& otherShipId : activeRoamingShips)
                        {
                            if (otherShipId != shipId)
                            {
                                RoamingShip* otherShip = roamingShips[otherShipId];
                                if (otherShip->currentLocation == location || otherShip->targetLocation == location)
                                {
                                    locationOccupied = true;
                                    break;
                                }
                            }
                        }
                        if (!locationOccupied)
                        {
                            ship->targetLocation = location;
                            break;
                        }
                    }
                    // If no unoccupied location is found, do not move
                    if (locationOccupied)
                    {
                        ship->targetLocation = nullptr;
                    }
                }
                else // Behavior with a goal
                {
                    // Try to find an alternative path around the occupied location
                    std::vector<Location*> path = G_->GetWorld()->starMap.Dijkstra(ship->currentLocation, ship->eventTargetLocation, true);
                    for (size_t i = 1; i < path.size(); ++i)
                    {
                        locationOccupied = false;
                        for (const auto& otherShipId : activeRoamingShips)
                        {
                            if (otherShipId != shipId)
                            {
                                RoamingShip* otherShip = roamingShips[otherShipId];
                                if (otherShip->currentLocation == path[i] || otherShip->targetLocation == path[i])
                                {
                                    locationOccupied = true;
                                    break;
                                }
                            }
                        }
                        if (!locationOccupied)
                        {
                            ship->targetLocation = path[i];
                            break;
                        }
                    }
                    // If no unoccupied location is found, do not move
                    if (locationOccupied)
                    {
                        ship->targetLocation = nullptr;
                    }
                }
            }
        }
        else if (ship->timeToMove < ship->currentMoveTime && ship->targetLocation != nullptr)
        {
            // Move the ship and reset the currentMoveTime
            ship->currentLocation = ship->targetLocation;
            ship->currentMoveTime = -1;
            ship->targetLocation = nullptr;
            ship->exploding = false;
        }
        ship->currentMoveTime += 1;
    }
}

void RoamingShipsManager::SaveShips(int fd)
{
    // Save the number of roaming ships existing
    int numShips = activeRoamingShips.size();
    FileHelper::writeInt(fd, numShips);
    
    // Loop through that number
    for (std::string shipId : activeRoamingShips)
    {
        RoamingShip* ship = roamingShips[shipId];
        // Save ship details
        FileHelper::writeString(fd, shipId);

        for (int i = 0; i < G_->GetWorld()->starMap.locations.size(); ++i)
        {
            if (ship->currentLocation == G_->GetWorld()->starMap.locations[i])
            {
                FileHelper::writeInt(fd, i);
                break;
            }
        }

        if (ship->targetLocation != nullptr)
        {
            for (int i = 0; i < G_->GetWorld()->starMap.locations.size(); ++i)
            {
                if (ship->targetLocation == G_->GetWorld()->starMap.locations[i])
                {
                    FileHelper::writeInt(fd, i);
                    break;
                }
            }
        }
        else
        {
            FileHelper::writeInt(fd, -1);
        }

        if (ship->eventTargetLocation != nullptr)
        {
            for (int i = 0; i < G_->GetWorld()->starMap.locations.size(); ++i)
            {
                if (ship->eventTargetLocation == G_->GetWorld()->starMap.locations[i])
                {
                    FileHelper::writeInt(fd, i);
                    break;
                }
            }
        }
        else
        {
            FileHelper::writeInt(fd, -1);
        }
        
        FileHelper::writeInt(fd, ship->currentMoveTime);
        FileHelper::writeInt(fd, ship->missingHP);
        FileHelper::writeInt(fd, ship->missingCrew);
        FileHelper::writeInt(fd, ship->behavior);
        FileHelper::writeInt(fd, ship->eventIndex);
    }
}

void RoamingShipsManager::LoadShips(int fd)
{
    int numShips = FileHelper::readInteger(fd);

    for (int i = 0; i < numShips; ++i)
    {
        std::string shipId = FileHelper::readString(fd);
        
        RoamingShip* ship = roamingShips[shipId];
        ship->currentLocation = G_->GetWorld()->starMap.locations[FileHelper::readInteger(fd)];
        int targetIndex = FileHelper::readInteger(fd);
        if (targetIndex != -1)
        {
            ship->targetLocation = G_->GetWorld()->starMap.locations[targetIndex];
        }
        else
        {
            ship->targetLocation = nullptr;
        }
        targetIndex = FileHelper::readInteger(fd);
        if (targetIndex != -1)
        {
            ship->eventTargetLocation = G_->GetWorld()->starMap.locations[targetIndex];
        }
        else
        {
            ship->eventTargetLocation = nullptr;
        }
        ship->currentMoveTime = FileHelper::readInteger(fd);
        ship->missingHP = FileHelper::readInteger(fd);
        ship->missingCrew = FileHelper::readInteger(fd);
        ship->behavior = FileHelper::readInteger(fd);
        ship->eventIndex = FileHelper::readInteger(fd);

        if ((activeRoamingShips.end() == std::find(activeRoamingShips.begin(), activeRoamingShips.end(), shipId)))
        {
            activeRoamingShips.push_back(shipId);
        }
    }
}

/*            for (const auto& event : ship->eventsList)
            {
                if (ship->currentLocation->event && ship->currentLocation->event->eventName == event)
                {
                    G_->GetWorld()->UpdateLocation(ship->currentLocation->event);
                    break;
                }
            } // new location for the thing :O
            
                for (const auto& shipId : roamingShipsManager->activeRoamingShips)
    {
         RoamingShip* ship = roamingShipsManager->roamingShips[shipId];
          if (ship->currentLocation == loc)
          {
                ship->currentLocation = loc;
          }    
    }
            */

HOOK_METHOD(WorldManager, CreateLocation, (Location *loc) -> void)
{
    LOG_HOOK("HOOK_METHOD -> WorldManager::CreateLocation -> Begin (RoamingShip.h)\n")
    super(loc);
    RoamingShipsManager* roamingManager = RoamingShipsManager::GetInstance();
    roamingManager->MoveShips();
}

Location* previousHoverLoc = nullptr;

HOOK_METHOD(StarMap, OnLoop, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> StarMap::OnLoop -> Begin (RoamingShip.h)\n")
    super();
    RoamingShipsManager* roamingManager = RoamingShipsManager::GetInstance();
    for (const auto& shipId : roamingManager->activeRoamingShips)
    {
        RoamingShip* ship = roamingManager->roamingShips[shipId];

        if (ship->behavior == 4 && hoverLoc != nullptr && hoverLoc != previousHoverLoc) // To save resources, only calculate path when hoverLoc changes
        {
            std::vector<Location*> path = Dijkstra(ship->currentLocation, hoverLoc, true);
            if (hoverLoc == ship->currentLocation)
            {
                ship->targetLocation = nullptr;
                previousHoverLoc = hoverLoc;                
            }
            if (!path.empty() && path.size() > 1) {
                ship->targetLocation = path[1];
                previousHoverLoc = hoverLoc;
            }
        }
    }
}

HOOK_METHOD(StarMap, OnRender, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> StarMap::OnRender -> Begin (RoamingShip.h)\n")
    super();
    CSurface::GL_PushMatrix();
    CSurface::GL_Translate(position.x + 42, position.y+ 33); // <- i will assume this is pointless with what primitives do now
    RoamingShipsManager::GetInstance()->RenderShips();
    CSurface::GL_PopMatrix();
}

HOOK_METHOD(StarMap, SaveGame, (int file) -> void)
{
    LOG_HOOK("HOOK_METHOD -> StarMap::SaveGame -> Begin (RoamingShip.h)\n")
    super(file);
    RoamingShipsManager::GetInstance()->SaveShips(file);
}

HOOK_METHOD(StarMap, LoadGame, (int file) -> Location*)
{
    LOG_HOOK("HOOK_METHOD -> StarMap::SaveGame -> Begin (RoamingShip.h)\n")
    Location* ret = super(file);
    RoamingShipsManager::GetInstance()->LoadShips(file);
    return ret;
}

/*
HOOK_METHOD_PRIORITY(WorldManager, CreateLocation, -9999, (Location *loc) -> void)
{
    LOG_HOOK("HOOK_METHOD -> WorldManager::CreateLocation -> Begin (RoamingShip.h)\n")
    RoamingShipsManager* roamingManager = RoamingShipsManager::GetInstance();
    LocationEvent* eventOverride = nullptr;
    LocationEvent* eventSave = nullptr;
    for (const auto& shipId : roamingManager->activeRoamingShips)
    { 
        RoamingShip* ship = roamingManager->roamingShips[shipId];
        if (ship->currentLocation != nullptr && ship->currentLocation == starMap.currentLoc)
        {
            std::string eventName = ship->eventsList[ship->eventIndex];
            LocationEvent *eventCheck = G_->GetEventGenerator()->CreateEvent(eventName , starMap.worldLevel, false);
            if (eventCheck != nullptr)
            {
                eventOverride = eventCheck;
                break;
            }
        }
        if (ship->currentLocation != nullptr && ship->targetLocation == starMap.currentLoc)
        {
            std::string eventName = ship->eventsList[ship->eventIndex];
            LocationEvent *eventCheck = G_->GetEventGenerator()->CreateEvent(eventName , starMap.worldLevel, false);
            if (eventCheck != nullptr)
            {
                eventOverride = eventCheck;
                break;
            }
        } 
    }
    if (eventOverride != nullptr)
    {
        eventSave = loc->event;
        loc->event = eventOverride;
    }
    super(loc);
    if (eventOverride != nullptr)
    {
        loc->event = eventSave;
    }
}
*/

HOOK_METHOD(WorldManager, StartGame, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> WorldManager::StartGame -> Begin (RoamingShip.cpp)\n")
    RoamingShipsManager::GetInstance()->activeRoamingShips.clear();       
    super();
}

HOOK_METHOD(StarMap, UpdateSectorMap, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> StarMap::UpdateSectorMap -> Begin (RoamingShip.cpp)\n")
    RoamingShipsManager::GetInstance()->activeRoamingShips.clear();   
    super();
}

HOOK_METHOD(Ship, SetDestroyed, (bool animation, bool bossAnimation) -> void)
{
    LOG_HOOK("HOOK_METHOD -> Ship::SetDestroyed -> Begin (RoamingShip.cpp)\n")
    RoamingShipsManager* roamingManager = RoamingShipsManager::GetInstance();
    hs_log_file("GOING ONCE\n");
    for (const auto& shipId : roamingManager->activeRoamingShips)
    { 
        RoamingShip* ship = roamingManager->roamingShips[shipId];
        hs_log_file("FOR EACH SHIP\n");
        if (MAP.currentLoc == ship->currentLocation && ship->exploding == false)
        {
            if (ship->eventIndex < ship->eventsList.size() - 2)
            {
                hs_log_file("INDEX IS LESS THAN SIZE, UPDATING INDEX\n");
                ship->eventIndex++;
                animation = true;
                bossAnimation = true;
                //ship->currentMoveTime = ship->timeToMove;
                ship->exploding = true;
                hs_log_file("BEFOREIF\n");
                /*if (ship->eventTargetLocation != nullptr && ship->currentLocation == ship->eventTargetLocation)
                {
                    Location* nextLocation = ship->currentLocation->connectedLocations[random32() % ship->currentLocation->connectedLocations.size()];
                    ship->targetLocation = nextLocation; // Update the ship's current location
                    hs_log_file("RUNNING AWAY\n");
                }*/
            }
            else
            {
                roamingManager->RemoveRoamingShip(shipId);
                hs_log_file("IF PLAYER IS IN THE SAME LOCATION\n");
            }
        }
    }
    hs_log_file("SUPER TIME\n");
    super(animation, bossAnimation);
}

HOOK_METHOD_PRIORITY(WorldManager, CreateLocation, -9999, (Location *loc) -> void)
{
    LOG_HOOK("HOOK_METHOD -> WorldManager::CreateLocation -> Begin (RoamingShip.h)\n")
    RoamingShipsManager* roamingManager = RoamingShipsManager::GetInstance();
    LocationEvent* eventOverride = nullptr;
    LocationEvent* eventSave = nullptr;

    for (const auto& shipId : roamingManager->activeRoamingShips)
    { 
        RoamingShip* ship = roamingManager->roamingShips[shipId];

        if (ship->timeToMove < ship->currentMoveTime)
        {
            // Ship is moving, check target location
            if (ship->targetLocation != nullptr && ship->targetLocation == starMap.currentLoc)
            {
                std::string eventName = ship->eventsList[ship->eventIndex];
                LocationEvent *eventCheck = G_->GetEventGenerator()->CreateEvent(eventName, starMap.worldLevel, false);
                if (eventCheck != nullptr)
                {
                    eventOverride = eventCheck;
                    break;
                }
            }
        }
        else
        {
            // Ship is not moving, check current location
            if (ship->currentLocation != nullptr && ship->currentLocation == starMap.currentLoc)
            {
                std::string eventName = ship->eventsList[ship->eventIndex];
                LocationEvent *eventCheck = G_->GetEventGenerator()->CreateEvent(eventName, starMap.worldLevel, false);
                if (eventCheck != nullptr)
                {
                    eventOverride = eventCheck;
                    break;
                }
            }
        }
    }

    if (eventOverride != nullptr)
    {
        eventSave = loc->event;
        loc->event = eventOverride;
    }
    super(loc);
    if (eventOverride != nullptr)
    {
        loc->event = eventSave;
    }
}
