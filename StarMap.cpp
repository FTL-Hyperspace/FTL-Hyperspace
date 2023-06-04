#include "Global.h"

HOOK_METHOD_PRIORITY(StarMap, LoadGame, 9999, (int fd) -> Location*)
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

