#include "CustomEvents.h"

CustomEventsParser *CustomEventsParser::instance = new CustomEventsParser();


void CustomEventsParser::ParseCustomEventNode(rapidxml::xml_node<char> *node)
{
    for (auto eventNode = node->first_node(); eventNode; eventNode = eventNode->next_sibling())
    {
        if (eventNode->first_attribute("name"))
        {
            std::string eventName = std::string(eventNode->first_attribute("name")->value());

            for (auto child = eventNode->first_node(); child; child = child->next_sibling())
            {
                std::string nodeName(child->name());

                if (nodeName == "wormhole")
                {
                    //printf("w %s\n", eventName.c_str());
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
