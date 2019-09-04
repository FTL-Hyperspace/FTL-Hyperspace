#include "CustomEvents.h"

CustomEventsParser *CustomEventsParser::instance = new CustomEventsParser();


void CustomEventsParser::ParseCustomEventNode(rapidxml::xml_node<char> *node)
{
    for (auto eventNode = node->first_node(); eventNode; eventNode = eventNode->next_sibling())
    {
        if (eventNode->first_attribute("name"))
        {
            std::string eventName = std::string(eventNode->first_attribute("name")->value());

            for (auto eventNode = node->first_node(); eventNode; eventNode = eventNode->next_sibling())
            {
                std::string nodeName(eventNode->name());

                if (nodeName == "wormhole")
                {
                    this->wormholeEventNames.push_back(eventName);
                }
            }
        }
    }
}



HOOK_METHOD(WorldManager, CreateLocation, (Location *loc) -> void)
{
    auto custom = CustomEventsParser::GetInstance();

    printf("%s\n", loc->event->eventName.c_str());

    super(loc);
}
