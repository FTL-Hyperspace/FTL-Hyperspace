#include "Global.h"
#include <algorithm>

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




private:
    std::vector<std::string> cargoEventNames;
    static CustomEventsParser *instance;
};
