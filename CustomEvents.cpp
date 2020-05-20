#include "CustomEvents.h"
#include <boost/lexical_cast.hpp>

CustomEventsParser *CustomEventsParser::instance = new CustomEventsParser();


void CustomEventsParser::ParseCustomEventNode(rapidxml::xml_node<char> *node)
{
    for (auto eventNode = node->first_node(); eventNode; eventNode = eventNode->next_sibling())
    {
        if (strcmp(eventNode->name(), "bossShip") == 0)
        {
            if (eventNode->value())
            {
                bossShipIds.push_back(std::string(eventNode->value()));
            }
        }

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

                    if  (nodeName == "beaconType")
                    {
                        BeaconType* beaconType = new BeaconType();
                        beaconType->eventName = eventName;
                        beaconType->id = child->first_attribute("id")->value();

                        if (child->first_attribute("global"))
                        {
                            beaconType->global = EventsParser::ParseBoolean(child->first_attribute("global")->value());
                        }

                        GL_Color color = GL_Color(255.f, 255.f, 255.f, 1.f);

                        for (auto child2 = child->first_node(); child2; child2 = child2->next_sibling())
                        {
                            if (strcmp(child2->name(), "color") == 0)
                            {
                                if (child2->first_attribute("r")) { color.r = boost::lexical_cast<float>(child2->first_attribute("r")->value()); }
                                if (child2->first_attribute("g")) { color.g = boost::lexical_cast<float>(child2->first_attribute("g")->value()); }
                                if (child2->first_attribute("b")) { color.b = boost::lexical_cast<float>(child2->first_attribute("b")->value()); }
                                if (child2->first_attribute("a")) { color.a = boost::lexical_cast<float>(child2->first_attribute("a")->value()); }
                            }
                        }

                        beaconType->color = color;

                        beaconTypeEvents.push_back(beaconType);
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

HOOK_METHOD(WorldManager, ModifyResources, (LocationEvent *event) -> LocationEvent*)
{
    auto customEvents = CustomEventsParser::GetInstance();

    if (customEvents->IsCargoEvent(event->eventName))
    {
        g_checkCargo = true;
    }

    super(event);

    g_checkCargo = false;
}

HOOK_METHOD(ShipManager, RemoveItem, (const std::string& name) -> void)
{
    bool removedItem = false;

    if (HasAugmentation(name))
    {
        RemoveAugmentation(name);
        removedItem = true;
    }

    if (systemKey[3] != -1)
    {
        auto weaponList = weaponSystem->weapons;

        int counter = 0;
        for (auto i: weaponList)
        {
            if (name == i->blueprint->name)
            {
                weaponSystem->RemoveWeapon(counter);
                removedItem = true;
                break;
            }

            counter++;
        }
    }

    if (systemKey[4] != -1)
    {
        auto droneList = droneSystem->drones;

        int counter = 0;
        for (auto i: droneList)
        {
            if (name == i->blueprint->name)
            {
                droneSystem->RemoveDrone(counter);
                removedItem = true;
                break;
            }

            counter++;
        }
    }


    if (!removedItem && g_checkCargo)
    {
        Equipment equip = G_->GetWorld()->commandGui->equipScreen;
        auto boxes = equip.vEquipmentBoxes;

        for (auto const& box: boxes)
        {
            bool isCargo = box->IsCargoBox();

            if (isCargo)
            {
                Blueprint* cargoItem = box->GetBlueprint();
                if (cargoItem)
                {
                    if (cargoItem->name == name)
                    {
                        box->RemoveItem();
                        return;
                    }
                }
            }
        }
    }
}

HOOK_METHOD(CommandGui, AddEnemyShip, (CompleteShip *ship) -> void)
{
    super(ship);
    auto custom = CustomEventsParser::GetInstance();

    if (custom->IsBossShip(ship->shipManager->myBlueprint.blueprintName))
    {
        shipPosition.x = 150;
        ftlButton.bBossFight = true;
        shipStatus.bBossFight = true;
    }
}


HOOK_METHOD(CombatControl, AddEnemyShip, (CompleteShip *ship) -> void)
{
    super(ship);
    auto custom = CustomEventsParser::GetInstance();

    if (custom->IsBossShip(ship->shipManager->myBlueprint.blueprintName))
    {
        boxPosition.x = 5;
        boxPosition.y = 7;

        targetPosition.x = boxPosition.x + 261 - ShipGraph::GetShipInfo(currentTarget->shipManager->iShipId)->shipBox.w / 2;
        targetPosition.y = boxPosition.y + 120;

        boss_visual = true;
    }
}

