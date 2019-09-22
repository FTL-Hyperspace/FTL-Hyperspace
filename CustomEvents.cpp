#include "CustomEvents.h"

CustomEventsParser *CustomEventsParser::instance = new CustomEventsParser();


void CustomEventsParser::ParseCustomEventNode(rapidxml::xml_node<char> *node)
{
    for (auto eventNode = node->first_node(); eventNode; eventNode = eventNode->next_sibling())
    {
        if (strcmp(eventNode->name(), "event") == 0)
        {
            if (eventNode->first_attribute("name"))
            {
                std::string eventName = std::string(eventNode->first_attribute("name")->value());
                for (auto child = eventNode->first_node(); child; child = child->next_sibling())
                {
                    std::string nodeName(child->name());
                    if (nodeName == "checkCargo")
                    {
                        cargoEventNames.push_back(eventName);
                    }
                }
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


static bool g_checkCargo = false;

HOOK_METHOD(ShipObject, HasEquipment, (const std::string& equipment) -> int)
{
    int ret = super(equipment);

    if (g_checkCargo && ret <= 0)
    {
        Equipment equip = G_->GetWorld()->commandGui->equipScreen;
        auto boxes = equip.vEquipmentBoxes;

        auto blueprintList = std::vector<std::string>();
        BlueprintManager::GetBlueprintList(blueprintList, G_->GetBlueprints(), equipment);

        for (auto const& box: boxes)
        {
            bool isCargo = box->IsCargoBox();


            if (isCargo)
            {
                Blueprint* cargoItem = box->GetBlueprint();
                if (cargoItem)
                {
                    if (blueprintList.size() > 0)
                    {
                        for (auto const& x: blueprintList)
                        {
                            if (cargoItem->name == x)
                                return 1;
                        }
                    }
                    else
                    {
                        if (cargoItem->name == equipment)
                            return 1;
                    }
                }
            }
        }
    }

    return ret;
}

HOOK_METHOD(WorldManager, CreateChoiceBox, (LocationEvent *event) -> void)
{
    auto customEvents = CustomEventsParser::GetInstance();
    if (customEvents->IsCargoEvent(event->eventName))
    {
        g_checkCargo = true;
    }

    super(event);

    g_checkCargo = false;
}
