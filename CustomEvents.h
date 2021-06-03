#pragma once
#include "Global.h"
#include "ToggleValue.h"
#include <algorithm>
#include <unordered_set>

struct BeaconType
{
    std::string eventName;
    GL_Color color;
    bool global = false;
    TextString beaconText;
    TextString undiscoveredTooltip;
    TextString unvisitedTooltip;
    TextString visitedTooltip;
    std::string equipmentReq;
};

struct EventGameOver
{
    bool enabled = false;
    std::string text = "";
    std::string creditsText = "";
    std::string creditsBackground = "";
};

struct CustomQuest
{
    ToggleValue<bool> nonNebulaBeacon;
    ToggleValue<bool> nebulaBeacon;
    ToggleValue<bool> createNebula;
    ToggleValue<std::string> nebulaEvent;
    ToggleValue<bool> currentSector;
    ToggleValue<bool> nextSector;
    ToggleValue<int> aggressive;
    ToggleValue<bool> sectorEight;
    ToggleValue<bool> lastStand;

    CustomQuest()
    {
        nonNebulaBeacon.value = true;
        nebulaBeacon.value = false;
        createNebula.value = true;
        nebulaEvent.value = "";
        currentSector.value = true;
        nextSector.value = true;
        aggressive.value = 0;
        sectorEight.value = false;
        lastStand.value = false;
    }

    void add(CustomQuest *other)
    {
        if (other->nonNebulaBeacon.enabled) nonNebulaBeacon = other->nonNebulaBeacon;
        if (other->nebulaBeacon.enabled) nebulaBeacon = other->nebulaBeacon;
        if (other->createNebula.enabled) createNebula = other->createNebula;
        if (other->nebulaEvent.enabled) nebulaEvent = other->nebulaEvent;
        if (other->currentSector.enabled) currentSector = other->currentSector;
        if (other->nextSector.enabled) nextSector = other->nextSector;
        if (other->aggressive.enabled) aggressive = other->aggressive;
        if (other->sectorEight.enabled) sectorEight = other->sectorEight;
        if (other->lastStand.enabled) lastStand = other->lastStand;
    }
};

struct EventFleet
{
    std::string fleetDefName;
    bool firing;
    bool autoDarkening;
};

struct CustomEvent
{
    std::string eventName;
    std::string unlockShip;
    bool unlockShipSilent;
    std::string unlockShipReq;
    BeaconType *beacon;
    bool hasCustomBeacon = false;
    bool checkCargo = false;
    bool recursive = true;
    bool preventQuest = false;
    bool noQuestText = false;
    CustomQuest *customQuest;
    int preventBossFleet = 0;
    int runFromFleet = 0;
    bool removeHazards = false;
    bool removeNebula = false;
    std::string secretSectorWarp = "";
    std::string eventLoad = "";
    bool eventLoadSeeded = true;
    EventGameOver gameOver = EventGameOver();
    bool disableScrapScore = false;
    std::string customStore;

    EventFleet leftFleet;
    EventFleet rightFleet;
    bool clearCustomFleet;

    std::vector<std::string> hiddenAugs = std::vector<std::string>();
    std::vector<std::string> removeItems = std::vector<std::string>();
    std::string playSound = "";
    std::string changeBackground = "";

};

struct SectorExit
{
    std::string event = "";
    std::string rebelEvent = "";
    std::string nebulaEvent = "";
};

struct SectorFleet
{
    std::string event = "";
    std::string nebulaEvent = "";
};

struct CustomSector
{
    std::string sectorName;
    SectorExit exitBeacons;
    SectorFleet fleetBeacons;
    bool removeFirstBeaconNebula = false;
};

struct BossShipDefinition
{
    std::string shipId;
    int yOffset = 120;
};

class CustomEventsParser
{
public:
    CustomEventsParser()
    {

    }

    void ParseCustomEventNode(rapidxml::xml_node<char> *node);
    void ParseCustomQuestNode(rapidxml::xml_node<char> *node, CustomQuest *quest);

    static CustomEventsParser *GetInstance()
    {
        return instance;
    }

    BossShipDefinition *GetBossShipDefinition(const std::string& shipId)
    {
        if (bossShipIds.find(shipId) != bossShipIds.end())
        {
            return &bossShipIds[shipId];
        }

        return nullptr;
    }

    CustomEvent *GetCustomEvent(const std::string& event);
    CustomSector *GetCustomSector(const std::string& sectorName);

    static std::string GetBaseEventName(const std::string& event)
    {
        if (event.find(' ') == std::string::npos)
        {
            return event;
        }
        else
        {
            return event.substr(0, event.find(' '));
        }
    }

    std::vector<std::string> eventFiles;
    CustomEvent *defaultVictory = new CustomEvent();
    CustomQuest *defaultQuest = new CustomQuest();

private:
    std::vector<CustomSector*> customSectors;
    std::unordered_map<std::string, CustomEvent*> customEvents;
    std::unordered_map<std::string, BossShipDefinition> bossShipIds;
    static CustomEventsParser *instance;
};

class BossFleetPrevention
{
public:
    StarMap* starMap;
    std::unordered_map<Location*, int> potentialFleetLocs = std::unordered_map<Location*, int>();
    std::unordered_set<Location*> fleetBlockedLocs = std::unordered_set<Location*>();

    void Clear()
    {
        for (auto i : fleetBlockedLocs)
        {
            if (i->beacon || !i->boss)
            {
                i->dangerZone = false;
            }
        }
        potentialFleetLocs.clear();
        fleetBlockedLocs.clear();
    }

    void Set()
    {
        bool hasVulnerableLoc = false;

        for (auto i : starMap->locations)
        {
            if (!i->dangerZone && !i->fleetChanging && !i->beacon)
            {
                if (i->visited)
                {
                    potentialFleetLocs[i] = 0;
                    hasVulnerableLoc = true;
                }
                else
                {
                    auto locEvent = i->event;
                    auto customEvents = CustomEventsParser::GetInstance();
                    auto customEvent = customEvents->GetCustomEvent(locEvent->eventName);

                    if (customEvent && customEvent->preventBossFleet)
                    {
                        potentialFleetLocs[i] = customEvent->preventBossFleet;
                    }
                    else
                    {
                        potentialFleetLocs[i] = 0;
                        hasVulnerableLoc = true;
                    }
                }
            }
        }

        for (auto i : potentialFleetLocs)
        {
            if (i.second && (hasVulnerableLoc || i.second == 2))
            {
                fleetBlockedLocs.insert(i.first);
                i.first->dangerZone = true;
            }
        }
    }
};
