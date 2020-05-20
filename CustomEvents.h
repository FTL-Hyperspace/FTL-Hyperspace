#include "Global.h"
#include <algorithm>

struct BeaconType
{
    std::string eventName;
    std::string id;
    GL_Color color;
    bool global = false;
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

    bool IsCargoEvent(std::string eventName)
    {
        return std::find(cargoEventNames.begin(), cargoEventNames.end(), eventName) != cargoEventNames.end();
    }

    BeaconType* GetBeaconType(std::string eventName)
    {
        for (auto i : beaconTypeEvents)
        {
            if (i->eventName == eventName) return i;
        }
        return NULL;
    }

    bool IsBossShip(std::string shipId)
    {
        return std::find(bossShipIds.begin(), bossShipIds.end(), shipId) != bossShipIds.end();
    }




private:
    std::vector<std::string> cargoEventNames;
    std::vector<BeaconType*> beaconTypeEvents;
    std::vector<std::string> bossShipIds;
    static CustomEventsParser *instance;
};
