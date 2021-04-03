#pragma once
#include "Global.h"
#include <algorithm>

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
    bool removeHazards = false;
    bool removeNebula = false;
    std::string secretSectorWarp = "";
    bool recallBoarders = false;
    int recallBoardersShip = 0;
    std::string eventLoad = "";
    bool eventLoadSeeded = true;
    EventGameOver gameOver = EventGameOver();
    bool disableScrapScore = false;


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


private:
    std::vector<CustomSector*> customSectors;
    std::unordered_map<std::string, CustomEvent*> customEvents;
    std::unordered_map<std::string, BossShipDefinition> bossShipIds;
    static CustomEventsParser *instance;
};

void RecallBoarders(int direction);
