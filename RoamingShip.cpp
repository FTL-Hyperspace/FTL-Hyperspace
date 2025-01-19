#include "Global.h"
#include "RoamingShip.h"
#include <math.h>

/*
<roamingShips>
    <add id="ship_rebel" icon="path/to/icon" behaviour="1" timeToMove="2">
        <event>EVENT_FIGHT_1</event>
        <event>EVENT_FIGHT_2</event>
        <event>EVENT_FIGHT_3</event>
    </add>
    <add id="ship_zoltan" icon="path/to/icon" behaviour="3" timeToMove="2">
        <event>EVENT_FIGHT_1</event>
        <event>EVENT_FIGHT_2</event>
        <event>EVENT_FIGHT_3</event>
    </add>
    <add id="ship_idk" icon="path/to/icon" behaviour="2" timeToMove="1">
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
                ship->mapIcon = G_->GetResources()->GetImageId(child->first_attribute("icon")->value());
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

            RoamingShipsManager::GetInstance()->roamingShips[ship->id] = ship;
        }
    }
}

void RoamingShipsManager::AddRoamingShip(std::string ship, Location* beacon)
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
}

void RoamingShipsManager::RemoveRoamingShip(std::string ship)
{
    // Remove the shipId from activeRoamingShips
    activeRoamingShips.erase(std::remove(activeRoamingShips.begin(), activeRoamingShips.end(), ship), activeRoamingShips.end());
}

void RoamingShipsManager::RenderShips()
{
    for (const auto& shipId : activeRoamingShips)
    {
        RoamingShip* ship = roamingShips[shipId];
        // Render the ship mapIcon rotating around the beacon, increment the rotation
        Pointf locationPos = ship->currentLocation->loc;

        // If timeToMove == currentMoveTime && targetLocation exists, render the movement direction thing
        if (ship->timeToMove == ship->currentMoveTime && ship->targetLocation)
        {
            Pointf targetPos = ship->targetLocation->loc;
            G_->GetResources()->RenderImage(ship->mapIcon, locationPos.x, locationPos.y, 0, GL_Color(1.0,1.0,1.0,1.0), 1.0, false);

        }else
        {
            ship->beaconDegree = (ship->beaconDegree + 0.5);
            if (ship->beaconDegree > 360) ship->beaconDegree = 0;
            // Render the ship mapIcon rotating around the beacon, increment the rotation
            float radian = ship->beaconDegree * (M_PI / 180.f);
            int newX = locationPos.x + 20 * cos(radian);
            int newY = locationPos.y + 20 * sin(radian);
            G_->GetResources()->RenderImage(ship->mapIcon, newX, newY, ((int)ship->beaconDegree + 90) % 360, GL_Color(1.0,1.0,1.0,1.0), 1.0, false);
        }
    }
}

void RoamingShipsManager::MoveShips()
{
    std::set<Location*> occupiedLocations;
    for (const auto& shipId : activeRoamingShips)
    {
        RoamingShip* ship = roamingShips[shipId];
        int behavior = ship->behavior;
        Location* targetLocation = nullptr;

        switch(behavior):
        {
        case 0:
            {
                // Do nothing
                break;
            }
            
        case 1:
            // Hunt
            break;
        default:
            // Roam
            break;
        }

        if (ship->timeToMove == ship->currentMoveTime)
        {
            // Calculate using Dijkstra and the behavior defined the targetLocation
            Location* newTargetLocation = CalculateNewTargetLocation(ship);
            if (newTargetLocation && occupiedLocations.find(newTargetLocation) == occupiedLocations.end())
            {
                ship->targetLocation = newTargetLocation;
                occupiedLocations.insert(newTargetLocation);
            }
        }
        else if (ship->timeToMove < ship->currentMoveTime)
        {
            // Move the ship and reset the currentMoveTime
            ship->currentLocation = ship->targetLocation;
            ship->currentMoveTime = 0;
            ship->targetLocation = nullptr;
        }
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

//Location* RoamingShipsManager::CalculateNewTargetLocation(RoamingShip* ship)
//{
//    // Use Dijkstra's algorithm to calculate the new target location based on ship behavior
//    Point start = ship->currentLocation->GetPoint();
//    Point goal = DetermineGoalPoint(ship); // Implement this function based on ship behavior
//    Path path = G_->GetWorld()->GetShipGraph()->Dijkstra(start, goal, ship->id);
//    
//    if (!path.empty())
//    {
//        return FindLocationByPoint(path.back());
//    }
//    return nullptr;
//}
//
//Point RoamingShipsManager::DetermineGoalPoint(RoamingShip* ship)
//{
//    // Implement logic to determine the goal point based on ship behavior and event IDs
//    if (ship->behavior == RoamingShip::Behavior::Hunting && !ship->eventsList.empty())
//    {
//        // Use the event ID to find the goal location
//        std::string eventId = ship->eventsList[ship->eventIndex];
//        for (auto& sector : G_->GetWorld()->sectors)
//        {
//            for (auto& location : sector->locations)
//            {
//                if (location->event->eventId == eventId)
//                {
//                    return location->GetPoint();
//                }
//            }
//        }
//    }
//    // Default to a random point if no specific behavior is defined
//    return Point(rand() % 100, rand() % 100); // Replace with actual logic
//}
//
//Location* RoamingShipsManager::FindLocationByPoint(Point point)
//{
//    for (auto& sector : G_->GetWorld()->sectors)
//    {
//        for (auto& location : sector->locations)
//        {
//            if (location->GetPoint() == point)
//            {
//                return location;
//            }
//        }
//    }
//    return nullptr;
//}

HOOK_METHOD(StarMap, OnRender, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> StarMap::OnRender -> Begin (RoamingShip.h)\n")
    super();
    CSurface::GL_PushMatrix();
    CSurface::GL_Translate(position.x + 42, position.y+ 33);
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

