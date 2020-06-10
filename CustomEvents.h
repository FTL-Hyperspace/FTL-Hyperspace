#include "Global.h"
#include <algorithm>

struct BeaconType
{
    std::string eventName;
    std::string id;
    GL_Color color;
    bool global = false;
};

struct CustomEvent
{
    std::string eventName;
    BeaconType *beacon;
    bool hasCustomBeacon = false;
    bool checkCargo = false;
    bool recursive = true;
    bool preventQuest = false;
};

struct SectorExit
{
    std::string sectorName;
    std::string event = "";
    std::string rebelEvent = "";
    std::string nebulaEvent = "";
};

struct SectorFleet
{
    std::string sectorName;
    std::string event = "";
    std::string nebulaEvent = "";
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

    bool IsBossShip(const std::string& shipId)
    {
        return std::find(bossShipIds.begin(), bossShipIds.end(), shipId) != bossShipIds.end();
    }

    CustomEvent *GetCustomEvent(const std::string& event);

    SectorExit* GetSectorExit(const std::string& sectorName);
    SectorFleet* GetSectorFleet(const std::string& sectorName);

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


private:
    std::vector<SectorExit*> customExitBeacons;
    std::vector<SectorFleet*> customFleetBeacons;
    std::vector<CustomEvent*> customEvents;
    std::vector<std::string> bossShipIds;
    static CustomEventsParser *instance;
};
