#include "CustomEvents.h"
#include "freetype.h"
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

        if (strcmp(eventNode->name(), "eventFile") == 0)
        {
            if (eventNode->value())
            {
                eventFiles.push_back(std::string(eventNode->value()));
            }
        }

        if (strcmp(eventNode->name(), "exitBeacon") == 0)
        {
            SectorExit* exit = new SectorExit();

            if (eventNode->first_attribute("sectorName"))
            {
                exit->sectorName = eventNode->first_attribute("sectorName")->value();
            }
            if (eventNode->first_attribute("event"))
            {
                exit->event = eventNode->first_attribute("event")->value();
            }
            if (eventNode->first_attribute("rebelEvent"))
            {
                exit->rebelEvent = eventNode->first_attribute("rebelEvent")->value();
            }
            if (eventNode->first_attribute("nebulaEvent"))
            {
                exit->nebulaEvent = eventNode->first_attribute("nebulaEvent")->value();
            }

            customExitBeacons.push_back(exit);
        }

        if (strcmp(eventNode->name(), "rebelBeacon") == 0)
        {
            SectorFleet* exit = new SectorFleet();

            if (eventNode->first_attribute("sectorName"))
            {
                exit->sectorName = eventNode->first_attribute("sectorName")->value();
            }
            if (eventNode->first_attribute("event"))
            {
                exit->event = eventNode->first_attribute("event")->value();
            }
            if (eventNode->first_attribute("nebulaEvent"))
            {
                exit->nebulaEvent = eventNode->first_attribute("nebulaEvent")->value();
            }

            customFleetBeacons.push_back(exit);
        }

        if (strcmp(eventNode->name(), "event") == 0)
        {
            if (eventNode->first_attribute("name"))
            {
                CustomEvent* customEvent = new CustomEvent();

                std::string eventName = std::string(eventNode->first_attribute("name")->value());
                customEvent->eventName = eventName;

                if (eventNode->first_attribute("recursive"))
                {
                    customEvent->recursive = EventsParser::ParseBoolean(eventNode->first_attribute("recursive")->value());
                }

                for (auto child = eventNode->first_node(); child; child = child->next_sibling())
                {
                    std::string nodeName(child->name());
                    if (nodeName == "checkCargo")
                    {
                        customEvent->checkCargo = true;
                    }

                    if (nodeName == "preventQuest")
                    {
                        customEvent->preventQuest = true;
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

                        customEvent->beacon = beaconType;
                        customEvent->hasCustomBeacon = true;
                    }
                }

                customEvents.push_back(customEvent);
            }
        }
    }

    char* eventText = G_->GetResources()->LoadFile("data/events_hyperspace.xml");

    if (eventText)
    {
        G_->GetEventsParser()->AddEvents(*G_->GetEventGenerator(), eventText, "data/events_hyperspace.xml");
    }

    for (auto i : CustomEventsParser::GetInstance()->eventFiles)
    {
        std::string fileName = "data/events_" + i + ".xml";

        char* eventText = G_->GetResources()->LoadFile(fileName);

        if (eventText)
        {
            G_->GetEventsParser()->AddEvents(*G_->GetEventGenerator(), eventText, fileName);
        }
    }
}

CustomEvent *CustomEventsParser::GetCustomEvent(const std::string& event)
{
    std::string baseEvent = CustomEventsParser::GetBaseEventName(event);
    bool isParent = baseEvent == event;

    auto it = std::find_if(customEvents.begin(), customEvents.end(), [&baseEvent](CustomEvent* x) { return baseEvent == x->eventName; });

    if (it != customEvents.end())
    {
        CustomEvent* customEvent = *it;
        if (!customEvent->recursive && !isParent) return NULL;
        else
        {
            return customEvent;
        }
    }

    return NULL;
}

SectorExit *CustomEventsParser::GetSectorExit(const std::string& sectorName)
{
    for (auto i : customExitBeacons)
    {
        if (i->sectorName == sectorName)
        {
            return i;
        }
    }

    return NULL;
}

SectorFleet *CustomEventsParser::GetSectorFleet(const std::string& sectorName)
{
    for (auto i : customFleetBeacons)
    {
        if (i->sectorName == sectorName)
        {
            return i;
        }
    }

    return NULL;
}

//=====================================================================================

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
                            {
                                return 1;
                            }
                        }
                    }
                    else
                    {
                        if (cargoItem->name == equipment)
                        {
                            return 1;
                        }
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

    if (customEvents->GetCustomEvent(event->eventName))
    {
        g_checkCargo = customEvents->GetCustomEvent(event->eventName)->checkCargo;
    }

    super(event);

    g_checkCargo = false;
}

HOOK_METHOD(WorldManager, ModifyResources, (LocationEvent *event) -> LocationEvent*)
{
    auto customEvents = CustomEventsParser::GetInstance();

    if (customEvents->GetCustomEvent(event->eventName))
    {
        g_checkCargo = customEvents->GetCustomEvent(event->eventName)->checkCargo;
    }

    auto ret = super(event);

    g_checkCargo = false;

    return ret;
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

GL_Texture* boxCustom[3];

HOOK_METHOD(StarMap, constructor, () -> void)
{
    super();
    boxCustom[0] = G_->GetResources()->GetImageId("map/map_box_custom_1.png");
    boxCustom[1] = G_->GetResources()->GetImageId("map/map_box_custom_2.png");
    boxCustom[2] = G_->GetResources()->GetImageId("map/map_box_custom_3.png");
}

static std::map<Location*, bool[2]> locValues = std::map<Location*, bool[2]>();

HOOK_METHOD(StarMap, AddQuest, (const std::string& questEvent, bool force) -> bool)
{
    locValues.empty();

    for (auto i : locations)
    {
        CustomEvent *customEvent = CustomEventsParser::GetInstance()->GetCustomEvent(i->event->eventName);
        if (customEvent && customEvent->preventQuest)
        {
            locValues[i][0] = i->questLoc;

            i->questLoc = true;
        }
    }

    super(questEvent, force);

    for (auto i : locValues)
    {
        i.first->questLoc = i.second[0];
        i.first->beacon = i.second[1];
    }
}

HOOK_METHOD(StarMap, RenderLabels, () -> void)
{
    CSurface::GL_PushMatrix();
    CSurface::GL_Translate(position.x, position.y, 0.f);
    CSurface::GL_Translate(translation.x, translation.y, 0.f);

    locValues.empty();

    if (!outOfFuel)
    {
        for (auto i : locations)
        {
            CustomEvent *customEvent = CustomEventsParser::GetInstance()->GetCustomEvent(i->event->eventName);

            if (!i->beacon && customEvent && customEvent->hasCustomBeacon && (bMapRevealed || customEvent->beacon->global || i->known))
            {
                locValues[i][0] = i->questLoc;
                locValues[i][1] = i->beacon;


                i->questLoc = false;

                BeaconType *beaconType = customEvent->beacon;
                std::string text = std::string();
                TextLibrary::GetText(text, G_->GetTextLibrary(), beaconType->id, G_->GetTextLibrary()->currentLanguage);

                Pointf printLines = freetype_hack::easy_measurePrintLines(51, 0, 0, 999, text);
                float x = i->loc.x - 1.f;
                float y = i->loc.y - 33.f;

                float x2 = 0.f;
                float y2 = 0.f;

                GL_Color color = beaconType->color;
                color.a = color.a * (i->flashTracker.GetAlphaLevel(false) * 0.5 + 0.5);

                GL_Texture** box;

                if (color.r == 255.f && color.g == 255.f && color.b == 255.f)
                {
                    box = boxWhite;
                }
                else
                {
                    box = boxCustom;
                }

                if (box[0])
                {
                    x2 = box[0]->width_;
                    y2 = box[0]->height_;
                }


                CSurface::GL_BlitPixelImage(box[0], x, y, x2, y2, 0.f, color, false);

                CSurface::GL_BlitPixelImage(box[1], x + box[0]->width_, y, printLines.x - 8, box[1]->height_, 0.f, color, false);

                CSurface::GL_BlitPixelImage(box[2], x + box[0]->width_ + printLines.x - 8, y, box[2]->width_, box[2]->height_, 0.f, color, false);

                color.r /= 255.f;
                color.g /= 255.f;
                color.b /= 255.f;

                CSurface::GL_SetColor(color);
                freetype::easy_print(51, i->loc.x + 14.f, i->loc.y - 25.f, text);
            }
        }
    }

    CSurface::GL_PopMatrix();

    super();

    for (auto i : locValues)
    {
        i.first->questLoc = i.second[0];
        i.first->beacon = i.second[1];
    }
}

HOOK_METHOD(StarMap, GenerateMap, (bool tutorial, bool seed) -> LocationEvent*)
{
    auto ret = super(tutorial, seed);

    if (!tutorial && !bossLevel)
    {
        auto custom = CustomEventsParser::GetInstance();
        SectorExit *customBeacon = custom->GetSectorExit(currentSector->description.type);

        if (customBeacon)
        {
            EventGenerator *eventGenerator = G_->GetEventGenerator();

            for (auto i : locations)
            {
                if (i->beacon)
                {
                    std::string event = "";
                    if (i->dangerZone && !customBeacon->rebelEvent.empty())
                    {
                        event = customBeacon->rebelEvent;
                    }
                    else
                    {
                        if (i->nebula && !customBeacon->nebulaEvent.empty())
                        {
                            event = customBeacon->nebulaEvent;
                        }
                        else if (!customBeacon->event.empty())
                        {
                            event = customBeacon->event;
                        }
                    }
                    if (!event.empty())
                    {
                        LocationEvent *newEvent = eventGenerator->GetBaseEvent(event, worldLevel, false, -1);

                        bool isNebula = i->nebula;

                        if (newEvent)
                        {
                            i->event = newEvent;
                            if (isNebula)
                            {
                                i->nebula = true;
                                newEvent->environment = 3;
                                //i->event->statusEffects.push_back(*StatusEffect::GetNebulaEffect());
                            }
                        }
                    }
                }
            }
        }
    }

    return ret;
}

HOOK_METHOD(StarMap, TurnIntoFleetLocation, (Location *loc) -> void)
{




    EventGenerator *eventGenerator = G_->GetEventGenerator();

    auto locEvent = loc->event;
    loc->dangerZone = true;
    loc->fleetChanging = false;

    if (locEvent)
    {
        locEvent->ClearEvent(false);
        std::string event;

        if (loc->nebula)
        {
            event = "FLEET_EASY_NEBULA";
        }
        else if (loc->beacon)
        {
            event = "FLEET_EASY_BEACON";
        }
        else
        {
            event = "FLEET_EASY";
        }


        if (Settings::GetDlcEnabled() && !loc->nebula)
        {
            event.append("_DLC");
        }
        auto replaceEvent = eventGenerator->GetBaseEvent(event, worldLevel, false, -1);

        if (replaceEvent)
        {
            loc->event = replaceEvent;
        }

        loc->event->repair = false;

        if (loc->beacon && loc->nebula)
        {
            loc->event->environment = 3;
        }
    }



    if (!bossLevel)
    {
        auto custom = CustomEventsParser::GetInstance();
        SectorExit *customBeacon = custom->GetSectorExit(currentSector->description.type);
        if (customBeacon && loc->beacon && !customBeacon->rebelEvent.empty())
        {
            bool isNebula = loc->nebula;

            LocationEvent *newEvent = eventGenerator->GetBaseEvent(customBeacon->rebelEvent, worldLevel, false, -1);

            if (newEvent)
            {
                loc->event->ClearEvent(false);
                loc->event = newEvent;

                if (isNebula)
                {
                    loc->nebula = true;
                    newEvent->environment = 3;
                }
            }
        }
    }

    if (!loc->beacon || bossLevel)
    {
        auto custom = CustomEventsParser::GetInstance();
        SectorFleet *customBeacon = custom->GetSectorFleet(currentSector->description.type);
        if (customBeacon)
        {
            std::string event = "";
            if (loc->nebula && !customBeacon->nebulaEvent.empty())
            {
                event = customBeacon->nebulaEvent;
            }
            else if (!customBeacon->event.empty())
            {
                event = customBeacon->event;
            }

            if (!event.empty())
            {
                LocationEvent *newEvent = eventGenerator->GetBaseEvent(event, worldLevel, false, -1);

                if (newEvent)
                {
                    loc->event->ClearEvent(false);
                    loc->event = newEvent;
                    loc->event->repair = false;
                }
            }
        }
    }
}

