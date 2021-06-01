#pragma once
#include "Global.h"
#include "ToggleValue.h"
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
    bool removeHazards = false;
    bool removeNebula = false;
    std::string secretSectorWarp = "";
    std::string eventLoad = "";
    bool eventLoadSeeded = true;
    EventGameOver gameOver = EventGameOver();
    bool disableScrapScore = false;
    std::string customStore;


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

class CustomReq
{
public:
    static int HasEquipment_Any(ShipObject& ship, const std::vector<std::string>& blueprintList)
    {
        int ret = 0;

        for (auto const& blueprint : blueprintList)
        {
            ret = std::max(ret, ship.HasEquipment(blueprint));
        }
        return ret;
    }

    static int HasEquipment_All(ShipObject& ship, const std::vector<std::string>& blueprintList)
    {
        int ret = 2147483647;

        for (auto const& blueprint : blueprintList)
        {
            ret = std::min(ret, ship.HasEquipment(blueprint));
        }
        return ret;
    }

    static int HasEquipment_Sum(ShipObject& ship, const std::vector<std::string>& blueprintList)
    {
        int ret = 0;

        for (auto const& blueprint : blueprintList)
        {
            ret += ship.HasEquipment(blueprint);
        }
        return ret;
    }

    enum REQ_TYPE
    {
        TYPE_ANY,
        TYPE_ALL,
        TYPE_SUM
    };

    std::string name = "";
    int type = TYPE_ANY;
    std::vector<std::string> blueprints = std::vector<std::string>();
    std::vector<CustomReq> children = std::vector<CustomReq>();
    int lvl = -1;
    int max_lvl = -1;
    int mult = 1;
    int constant = 0;

    int HasEquipment(ShipObject& ship)
    {
        int ret;

        switch(type)
        {
        case TYPE_ANY:
            ret = HasEquipment_Any(ship, blueprints);
            for (auto& child : children)
            {
                ret = std::max(ret, child.HasEquipment(ship));
            }
            break;
        case TYPE_ALL:
            ret = HasEquipment_All(ship, blueprints);
            for (auto& child : children)
            {
                ret = std::min(ret, child.HasEquipment(ship));
            }
            break;
        case TYPE_SUM:
            ret = HasEquipment_Sum(ship, blueprints);
            for (auto& child : children)
            {
                ret += child.HasEquipment(ship);
            }
            break;
        }

        if (lvl > -1 || max_lvl > -1)
        {
            int counter = ret;
            ret = counter >= lvl;
            if (max_lvl > -1) ret &= counter <= max_lvl;
        }

        return ret * mult + constant;
    }
};

class CustomEventsParser
{
public:
    CustomEventsParser()
    {

    }

    void ParseCustomEventNode(rapidxml::xml_node<char> *node);
    void ParseCustomQuestNode(rapidxml::xml_node<char> *node, CustomQuest *quest);
    void ParseCustomReqNode(rapidxml::xml_node<char> *node, CustomReq *req);

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
    CustomReq *GetCustomReq(const std::string& blueprint);

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
    std::unordered_map<std::string, CustomReq*> customReqs;
    static CustomEventsParser *instance;
};
