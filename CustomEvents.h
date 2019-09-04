#include "Global.h"


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




private:
    std::vector<std::string> wormholeEventNames;
    static CustomEventsParser *instance;
};
