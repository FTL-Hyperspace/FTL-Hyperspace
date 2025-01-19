#include "Global.h"
#include "RoamingShip.h"
#include "rapidxml.hpp"
#include "FileHelper.h"

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

RoamingShipsManager* RoamingShipsManager::instance = RoamingShipsManager();

void RoamingShipManager::ParseShipsNode(rapidxml::xml_node<char>* node)
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

void RoamingShipManager::AddRoamingShip(std::string ship, Location* beacon)
{
    // Add the shipId into activeRoamingShips
    activeRoamingShips.push_back(ship);

    // Set the ship's currentLocation to beacon
    roamingShips[ship]->currentLocation = beacon;

    // Set all other values to default
    roamingShips[ship]->targetLocation = nullptr;
    roamingShips[ship]->beaconDegree = rand() % 361; // Random value between 0 and 360
    roamingShips[ship]->currentMoveTime = 0;
    roamingShips[ship]->timeToMove = 0;
}

void RoamingShipManager::RemoveRoamingShip(std::string ship)
{
    // Remove the shipId from activeRoamingShips
    activeRoamingShips.erase(std::remove(activeRoamingShips.begin(), activeRoamingShips.end(), ship), activeRoamingShips.end());
}

void RoamingShipManager::RenderShips()
{
    for (const auto& shipId : activeRoamingShips)
    {
        RoamingShip* ship = roamingShips[shipId];
        // Render the ship mapIcon rotating around the beacon, increment the rotation
        ship->beaconDegree = (ship->beaconDegree + 1) % 360;

        // If timeToMove == currentMoveTime && targetLocation exists, render the movement direction thing
        if (ship->timeToMove == ship->currentMoveTime && ship->targetLocation)
        {
            // Render movement direction
        }
    }
}

void RoamingShipManager::MoveShips()
{
    std::set<Location*> occupiedLocations;
    for (const auto& shipId : activeRoamingShips)
    {
        RoamingShip* ship = roamingShips[shipId];
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
        }
    }
}

void RoamingShipManager::LoadShips(int fd)
{
    // Load the number of roaming ships existing
    int numShips = FileHelper::readInteger(fd);
    
    // Loop through that number
    for (int i = 0; i < numShips; ++i)
    {
        std::string shipId = FileHelper::readString(fd);
        
        RoamingShip* ship = new RoamingShip();
        // Load currentLocation
        ship->currentLocation = FindLocationById(FileHelper::readInteger(fd));
        // Load targetLocation
        ship->targetLocation = FindLocationById(FileHelper::readInteger(fd));
        // Load currentMoveTime
        ship->currentMoveTime = FileHelper::readInteger(fd);
        // Load missingHP/crew
        ship->missingHP = FileHelper::readInteger(fd);
        ship->missingCrew = FileHelper::readInteger(fd);
        // Load behavior
        ship->behavior = FileHelper::readInteger(fd);
        // Load eventIndex
        ship->eventIndex = FileHelper::readInteger(fd);
        
        roamingShips[shipId] = ship;
    }
}

void RoamingShipManager::SaveShips(int fd)
{
    // Save the number of roaming ships existing
    int numShips = roamingShips.size();
    FileHelper::writeInteger(fd, numShips);
    
    // Loop through that number
    for (const auto& pair : roamingShips)
    {
        const std::string& shipId = pair.first;
        RoamingShip* ship = pair.second;
        // Save ship details
        FileHelper::writeString(fd, shipId);
        FileHelper::writeInteger(fd, ship->currentLocation->id);
        FileHelper::writeInteger(fd, ship->targetLocation->id);
        FileHelper::writeInteger(fd, ship->currentMoveTime);
        FileHelper::writeInteger(fd, ship->missingHP);
        FileHelper::writeInteger(fd, ship->missingCrew);
        FileHelper::writeInteger(fd, ship->behavior);
        FileHelper::writeInteger(fd, ship->eventIndex);
    }
}

Location* RoamingShipManager::FindLocationById(int id)
{
    for (auto& sector : G_->GetWorld()->sectors)
    {
        for (auto& location : sector->locations)
        {
            if (location->id == id)
            {
                return location;
            }
        }
    }
    return nullptr;
}

Location* RoamingShipManager::CalculateNewTargetLocation(RoamingShip* ship)
{
    // Use Dijkstra's algorithm to calculate the new target location based on ship behavior
    Point start = ship->currentLocation->GetPoint();
    Point goal = DetermineGoalPoint(ship); // Implement this function based on ship behavior
    Path path = G_->GetWorld()->GetShipGraph()->Dijkstra(start, goal, ship->id);
    
    if (!path.empty())
    {
        return FindLocationByPoint(path.back());
    }
    return nullptr;
}

Point RoamingShipManager::DetermineGoalPoint(RoamingShip* ship)
{
    // Implement logic to determine the goal point based on ship behavior and event IDs
    if (ship->behavior == RoamingShip::Behavior::Hunting && !ship->eventsList.empty())
    {
        // Use the event ID to find the goal location
        std::string eventId = ship->eventsList[ship->eventIndex];
        for (auto& sector : G_->GetWorld()->sectors)
        {
            for (auto& location : sector->locations)
            {
                if (location->event->eventId == eventId)
                {
                    return location->GetPoint();
                }
            }
        }
    }
    // Default to a random point if no specific behavior is defined
    return Point(rand() % 100, rand() % 100); // Replace with actual logic
}

Location* RoamingShipManager::FindLocationByPoint(Point point)
{
    for (auto& sector : G_->GetWorld()->sectors)
    {
        for (auto& location : sector->locations)
        {
            if (location->GetPoint() == point)
            {
                return location;
            }
        }
    }
    return nullptr;
}



/*HOOK_METHOD_PRIORITY(StarMap, LoadGame, 9999, (int fd) -> Location*)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> StarMap::LoadGame -> Begin (StarMap.cpp)\n")
    this->sectorMapSeed = FileHelper::readInteger(fd);
    this->currentSectorSeed = FileHelper::readInteger(fd);

    int _dangerZoneX = FileHelper::readInteger(fd);
    int _dangerZoneY = FileHelper::readInteger(fd);
    int _pursuitDelay = FileHelper::readInteger(fd);

    this->fuelEventSeed = -1;
    std::string fuelEventName = "";
    bool bNoFuel = false;

    int iCurrentLoc = 0;

    if (Global_Settings_Settings->loadingSaveVersion > 2)
    {
        iCurrentLoc = FileHelper::readInteger(fd);
        bNoFuel = FileHelper::readInteger(fd);
        this->fuelEventSeed = FileHelper::readInteger(fd);
        fuelEventName = FileHelper::readString(fd);
    }

    bool _bMapRevealed = FileHelper::readInteger(fd);
    bool _bossLevel = FileHelper::readInteger(fd);
    int _bossLoc = FileHelper::readInteger(fd);
    bool _bossJumping = FileHelper::readInteger(fd);
    bool _reverseBossPath = false;
    bool _arrivedAtBase = false;

    this->reversedPath = false; // vanilla bugfix

    if (Global_Settings_Settings->loadingSaveVersion > 2)
    {
        _reverseBossPath = FileHelper::readInteger(fd);
        if (Global_Settings_Settings->loadingSaveVersion > 3)
        {
            _arrivedAtBase = FileHelper::readInteger(fd);
        }
    }

    int nSectors = FileHelper::readInteger(fd);

    this->worldLevel = 0;
    this->bInfiniteMode = false;
    this->delayedQuests.clear();

    if (Globals_RNG)
    {
        srand(this->sectorMapSeed);
    }
    else
    {
        srandom32(this->sectorMapSeed);
    }
    GenerateSectorMap();

    if (nSectors != sectors.size())
    {
        ftl_log("Something went horribly wrong.. sector count doesn't match\n");
    }
    if (nSectors > 0)
    {
        for (int i=0; i<nSectors; ++i)
        {
            if (i < sectors.size())
            {
                sectors[i]->visited = FileHelper::readInteger(fd);
                if (sectors[i]->visited && worldLevel < sectors[i]->level)
                {
                    worldLevel = sectors[i]->level;
                    G_->GetScoreKeeper()->SetSector(sectors[i]->level + 1);
                    currentSector = sectors[i];
                    if (worldLevel > 7)
                    {
                        bInfiniteMode = true;
                    }
                }
            }
            else
            {
                FileHelper::readInteger(fd);
            }
        }
    }

    if (Global_Settings_Settings->loadingSaveVersion > 1)
    {
        this->worldLevel = FileHelper::readInteger(fd);
        this->bSecretSector = FileHelper::readInteger(fd);
        if (bSecretSector)
        {
            secretSector->level = worldLevel;
            currentSector = secretSector;
        }
    }

    GenerateMap(false,true);

    int nLocations = FileHelper::readInteger(fd);
    if (nLocations != locations.size())
    {
        ftl_log("Something went horribly wrong.. location count doesn't match\n");
    }

    if (_bossLevel)
    {
        this->bossLevel = true;

        if (_reverseBossPath)
        {
            ReverseBossPath();
        }

        boss_path[bossLoc]->boss = false;
        this->arrivedAtBase = _arrivedAtBase;

        if (_bossLoc >= boss_path.size())
        {
            _bossLoc = boss_path.size() - 3;
        }
        this->bossLoc = _bossLoc;
        bossPosition = boss_path[_bossLoc]->loc;
        boss_path[_bossLoc]->boss = true;
    }

    for (int i=0; i<nLocations; ++i)
    {
        Location* loc;
        LocationEvent *dummyEvent;
        if (i < locations.size())
        {
            loc = locations[i];
        }
        else
        {
            // we should really hook the constructors but these are dummy objects anyways
            loc = new Location();
            dummyEvent = new LocationEvent();
            loc->event = dummyEvent;
        }
        loc->visited = FileHelper::readInteger(fd);
        if (loc->visited)
        {
            loc->spaceImage = FileHelper::readString(fd);
            loc->planetImage = FileHelper::readString(fd);
            if (loc->spaceImage == "NONE")
            {
                loc->space.tex = nullptr;
            }
            else
            {
                loc->space = Global::GetInstance()->GetWorld()->space.SwitchBackground(loc->spaceImage);
            }
            if (loc->planetImage == "NONE")
            {
                loc->planet.tex = nullptr;
            }
            else
            {
                loc->planet.tex = G_->GetResources()->GetImageId(loc->planetImage);
            }
            loc->planet.x = FileHelper::readInteger(fd);
            loc->planet.y = FileHelper::readInteger(fd);
            loc->planet.rot = FileHelper::readInteger(fd);
        }
        loc->known = FileHelper::readInteger(fd);
        bool hasShip = FileHelper::readInteger(fd);
        if (!hasShip)
        {
            if (loc->visited)
            {
                loc->event->ship.hostile = false;
                loc->event->ship.present = false;
            }
        }
        else
        {
            ShipEvent shipEvent = G_->GetEventGenerator()->GetShipEvent(FileHelper::readString(fd));
            shipEvent.auto_blueprint = FileHelper::readString(fd);
            shipEvent.shipSeed = FileHelper::readInteger(fd);
            shipEvent.hostile = true;
            if (!shipEvent.name.empty())
            {
                loc->event->ship = shipEvent;
            }
        }
        int _fleetPosition = FileHelper::readInteger(fd);
        if (_fleetPosition == 1)
        {
            TurnIntoFleetLocation(loc);
        }
        loc->event->fleetPosition = _fleetPosition;
        loc->fleetChanging = FileHelper::readInteger(fd);
        bool isStore = FileHelper::readInteger(fd);
        if (loc->visited && (loc->visited > 1 || i != iCurrentLoc))
        {
            loc->event->ClearEvent(false);
        }
        if (isStore)
        {
            loc->event->pStore = new Store();
            storeTrash.push_back(loc->event->pStore);
            loc->event->pStore->LoadStore(fd, worldLevel);
        }
        if (i >= locations.size())
        {
            // Fixes a potential memory leak by destroying the dummy objects
            delete dummyEvent;
            delete loc;
        }
    }

    int nQuests = FileHelper::readInteger(fd);
    if (nQuests > 0)
    {
        for (int i=0; i<nQuests; ++i)
        {
            std::string questName = FileHelper::readString(fd);
            int questLoc = FileHelper::readInteger(fd);
            if (questLoc < locations.size()) // Added a bounds check
            {
                if (locations[questLoc]->visited == 0 || questLoc == iCurrentLoc)
                {
                    locations[questLoc]->questLoc = true;
                    locations[questLoc]->event = G_->GetEventGenerator()->GetBaseEvent(questName, worldLevel, false, -1);
                }
            }
            addedQuests.push_back({questName,questLoc});
        }
    }

    nQuests = FileHelper::readInteger(fd);
    if (nQuests > 0)
    {
        for (int i=0; i<nQuests; ++i)
        {
            delayedQuests.push_back(FileHelper::readString(fd));
        }
    }

    this->dangerZone.x = _dangerZoneX;
    if (Global_Settings_Settings->loadingSaveVersion < 3)
    {
        this->dangerZone.x -= 209;
        iCurrentLoc = FileHelper::readInteger(fd);
    }
    this->dangerZone.y = _dangerZoneY;
    this->bMapRevealed = _bMapRevealed;
    this->pursuitDelay = _pursuitDelay;
    this->bossJumping = _bossJumping;

    if (iCurrentLoc >= locations.size()) iCurrentLoc = locations.size()-1;
    this->currentLoc = locations[iCurrentLoc];
    if (bNoFuel)
    {
        if (fuelEventName.empty()) fuelEventName = "NONE";
        SetupNoFuel(fuelEventSeed,fuelEventName);
    }

    return currentLoc;
}

*/