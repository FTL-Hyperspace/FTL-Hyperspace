#include "Global.h"
#include "CustomSectors.h"

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

HOOK_METHOD_PRIORITY(StarMap, GenerateMap, 9999, (bool bTutorial, bool useOldSeed) -> Location*)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> StarMap::GenerateMap -> Begin (StarMap.cpp)\n")
    const int MAX_PATH_GENERATION_ATTEMPTS = 16;
    //Seed rng for map generation
    if (!useOldSeed) currentSectorSeed = random32();
    srandom32(currentSectorSeed);
    bTutorialGenerated = bTutorial;
    hoverLoc = nullptr;
    potentialLoc = nullptr;
    currentLoc = nullptr;
    bMapRevealed = false;

    //Initialize dangerZone
    dangerZone.x = -959;
    dangerZone.y = random32() % 250 + 50;

    //Repeat until valid map is generated
    while (true)
    {
        //Clear map, generate beacons and connections
        do
        {
            DeleteMap();
            G_->GetEventGenerator()->Clear();
            {
                for (int x = 0; x < 6; ++x)
                {
                    for (int y = 0; y < 4; ++y)
                    {
                        Point gridPos(x, y);
                        PopulateGrid(gridPos);
                    }
                }
            }
        } while (!MapConnected());

        //Determine random starting location on the left of the map
        Point gridSegment = Point(0, random32() % 4);
        const auto& potentialStartLocations = locations_grid[gridSegment];
        currentLoc = potentialStartLocations.empty() ? locations[0] : potentialStartLocations[0];

        //Determine if this is a boss sector
        bossLevel = false;
        if (!forceSectorChoice.empty())
        {
            currentSector->description = G_->GetEventGenerator()->GetSpecificSector(forceSectorChoice);
            if (currentSector->description.type == "FINAL") bossLevel = true;
        }
        if (currentSector->level == 7 && !bInfiniteMode) bossLevel = true;

        //Override boss behavior for custom sectors that specify it
        CustomSector* customSector = CustomEventsParser::GetInstance()->GetCurrentCustomSector(this);
        if (customSector != nullptr && customSector->bossSector.enabled)
        {
            bossLevel = customSector->bossSector.value;
        }

        //Set item rarity for the sector
        G_->GetBlueprints()->ResetRarities();
        for (const auto& rarity : currentSector->description.rarities)
        {
            G_->GetBlueprints()->SetRarity(rarity.first, rarity.second);
        }

        //Set
        currentLoc->event = G_->GetEventGenerator()->GetBaseEvent(currentSector->description.firstEvent, worldLevel, false, -1);
        int pathGenerationAttempts = 0;
        do
        {
            int maxPathSize;
            int minPathSize;
            Point finishLoc;

            //Determine pathing to exit/federation base
            do
            {
                //Pick map segment for base/exit
                finishLoc.y = random32() % 4;
                finishLoc.x = random32() % 2 + 4;
                if (bossLevel)
                {
                    //Hard difficulty has federation base further away
                    if (*Global::difficulty == 2)
                    {
                        maxPathSize = 7;
                        minPathSize = 4;
                        finishLoc.x = random32() % 2 + 3;
                    }
                    else
                    {
                        maxPathSize = 5;
                        minPathSize = 3;
                        finishLoc.x = random32() % 2 + 2;
                    }
                }
                else
                {
                    maxPathSize = 100;
                    minPathSize = 4;
                }
            } while (locations_grid[finishLoc].empty());

            Location* destination = locations_grid[finishLoc][0];
            temp_path = Dijkstra(currentLoc, destination, true);
            boss_path = temp_path;
            ++pathGenerationAttempts;

            //Use path if size is within a valid range
            if (temp_path.size() < maxPathSize && temp_path.size() > minPathSize)
            {
                temp_path.clear();
                //Assign exit beacon
                destination->beacon = true;
                destination->event = G_->GetEventGenerator()->GetBaseEvent("FINISH_BEACON", worldLevel, false, -1);
                destination->event->beacon = true;
                //Generate events
                GenerateEvents(bTutorial);
                //GenerateEvents sets bossLevel again so the override needs to be applied again
                if (customSector != nullptr && customSector->bossSector.enabled)
                {
                    bossLevel = customSector->bossSector.value;
                }
                //Start appropriate playlist for the sector
                if (bTutorial)
                {
                    std::vector<std::string> playList{"civilian", "cosmos"};
                    G_->GetSoundControl()->StartPlaylist(playList);
                }
                else
                {
                    G_->GetSoundControl()->StartPlaylist(currentSector->description.musicTracks);
                }

                //Add quest marker to rock homeworld for crystal quest when appropriate
                if (currentSector->description.type == "ROCK_HOME" && crystalAlienFound && !locations.empty())
                {
                        for (Location* loc : locations)
                        {
                            if (loc->event->eventName == "ROCK_CRYSTAL_BEACON")
                            {
                                loc->questLoc = true;
                                break;
                            }
                        }

                }
                arrivedAtBase = 0;
                if (!bossLevel)
                {
                    //Start Sector
                    TravelToLocation(currentLoc);
                    for (const std::string& quest : delayedQuests)
                    {
                        AddQuest(quest, true);
                    }
                    forceSectorChoice = "";
                    waitedLast = false;
                    return currentLoc;
                }
                else
                {
                    //Overtake sector
                    dangerZone.x = 60;
                    dangerZone.y = 200;
                    //Give fleet control to one random location
                    Location* randomLocation = locations[random32() % locations.size()];
                    if (!randomLocation->beacon) randomLocation->fleetChanging = true;
                    do
                    {
                        //Generate boss start location and boss path
                        std::vector<Location*> bossStartCandidates;
                        do
                        {
                            Point boss_start_loc;
                            boss_start_loc.y = random32() % 4;
                            boss_start_loc.x = random32() % 2 + 4;
                            bossStartCandidates = locations_grid[boss_start_loc];
                        } while (bossStartCandidates.empty());

                        Location* bossStartLocation = bossStartCandidates[0];
                        temp_path = Dijkstra(bossStartLocation, destination, true);
                        boss_path = temp_path;
                        ++pathGenerationAttempts;

                        //If boss path is a valid size, initialize sector
                        if (temp_path.size() > 3 && temp_path.size() < 7)
                        {
                            bossLoc = 0;
                            bossStartLocation->boss = true;
                            TurnIntoFleetLocation(bossStartLocation);
                            destination->event = G_->GetEventGenerator()->GetBaseEvent("FEDERATION_BASE", worldLevel, false, -1);
                            currentLoc->event = G_->GetEventGenerator()->GetBaseEvent("LAST_STAND_START", worldLevel, false, -1);
                            bossJumping = false;
                            bossPosition = boss_path[bossLoc]->loc;
                            //Start Sector
                            TravelToLocation(currentLoc);
                            for (const std::string& quest : delayedQuests)
                            {
                                AddQuest(quest, true);
                            }
                            forceSectorChoice = "";
                            waitedLast = false;
                            return currentLoc;
                        }
                    } while (pathGenerationAttempts < MAX_PATH_GENERATION_ATTEMPTS);
                }
            }
        } while (pathGenerationAttempts < MAX_PATH_GENERATION_ATTEMPTS);
        temp_path.clear();
    }
}

bool StarMap::WillBeOvertaken(Location *loc)
{
    //NOTE: This is an inlined call to another GetNextDangerMove() function that is identical to this one except it returns 0 when dangerZone.x >= 60.
    int dangerMove = 0;
    if (dangerZone.x < 60) dangerMove = GetNextDangerMove();
    Pointf nextDangerZone = Pointf(dangerZone.x + dangerMove, dangerZone.y);
    return loc->loc.RelativeDistance(nextDangerZone) < (dangerZoneRadius * dangerZoneRadius);
}
