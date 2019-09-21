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
            }
        }
    }
}

HOOK_METHOD(EventGenerator, GetBaseEvent, (std::string& name, int unk1, char load, int unk3) -> LocationEvent*)
{
    LocationEvent *ret = super(name, unk1, load, unk3);
    return ret;
}

HOOK_METHOD(EventsParser, AddAllEvents, () -> void)
{
    super();
    char* eventText = G_->GetResources()->LoadFile("data/events_hyperspace.xml");

    if (eventText)
    {
        AddEvents(*G_->GetEventGenerator(), eventText, "data/events_hyperspace.xml");
    }
}

HOOK_METHOD(WorldManager, CreateLocation, (Location *loc) -> void)
{
    auto custom = CustomEventsParser::GetInstance();

    super(loc);
}
