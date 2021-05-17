#include "CustomEvents.h"
#include "freetype.h"
#include "Resources.h"
#include "Seeds.h"
#include "ShipUnlocks.h"
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>

CustomEventsParser *CustomEventsParser::instance = new CustomEventsParser();


void CustomEventsParser::ParseCustomEventNode(rapidxml::xml_node<char> *node)
{
    for (auto eventNode = node->first_node(); eventNode; eventNode = eventNode->next_sibling())
    {
        if (strcmp(eventNode->name(), "bossShip") == 0)
        {
            if (eventNode->value())
            {
                BossShipDefinition def = BossShipDefinition();
                def.shipId = eventNode->value();

                if (eventNode->first_attribute("yOffset"))
                {
                    def.yOffset = boost::lexical_cast<int>(eventNode->first_attribute("yOffset")->value());
                }

                bossShipIds[def.shipId] = def;
            }
        }

        if (strcmp(eventNode->name(), "eventFile") == 0)
        {
            if (eventNode->value())
            {
                eventFiles.push_back(std::string(eventNode->value()));
            }
        }

        if (strcmp(eventNode->name(), "sector") == 0)
        {
            std::string sectorName = eventNode->first_attribute("name")->value();

            if (!sectorName.empty())
            {
                CustomSector *sec = new CustomSector();

                sec->sectorName = sectorName;

                for (auto sectorNode = eventNode->first_node(); sectorNode; sectorNode = sectorNode->next_sibling())
                {
                    if (strcmp(sectorNode->name(), "exitBeacon") == 0)
                    {
                        SectorExit exit = SectorExit();

                        if (sectorNode->first_attribute("event"))
                        {
                            exit.event = sectorNode->first_attribute("event")->value();
                        }
                        if (sectorNode->first_attribute("rebelEvent"))
                        {
                            exit.rebelEvent = sectorNode->first_attribute("rebelEvent")->value();
                        }
                        if (sectorNode->first_attribute("nebulaEvent"))
                        {
                            exit.nebulaEvent = sectorNode->first_attribute("nebulaEvent")->value();
                        }

                        sec->exitBeacons = exit;
                    }

                    if (strcmp(sectorNode->name(), "rebelBeacon") == 0)
                    {
                        SectorFleet fleet = SectorFleet();

                        if (sectorNode->first_attribute("event"))
                        {
                            fleet.event = sectorNode->first_attribute("event")->value();
                        }
                        if (sectorNode->first_attribute("nebulaEvent"))
                        {
                            fleet.nebulaEvent = sectorNode->first_attribute("nebulaEvent")->value();
                        }

                        sec->fleetBeacons = fleet;
                    }

                    if (strcmp(sectorNode->name(), "removeFirstBeaconNebula") == 0)
                    {
                        sec->removeFirstBeaconNebula = true;
                    }

                    customSectors.push_back(sec);
                }
            }


        }

        if (strcmp(eventNode->name(), "event") == 0)
        {
            if (eventNode->first_attribute("name"))
            {
                std::string eventName = std::string(eventNode->first_attribute("name")->value());

                CustomEvent *customEvent;
                if (eventName == "default_victory")
                {
                    customEvent = defaultVictory;
                }
                else
                {
                    if (GetCustomEvent(eventName) == nullptr)
                    {
                        customEvent = new CustomEvent();
                    }
                    else
                    {
                        customEvent = GetCustomEvent(eventName);
                    }
                }

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

                    if (nodeName == "noQuestText")
                    {
                        customEvent->noQuestText = true;
                    }

                    if (nodeName == "nebulaQuest")
                    {
                        customEvent->questAllowNebula = true;

                        if (child->first_attribute("force"))
                        {
                            customEvent->questForceNebula = EventsParser::ParseBoolean(child->first_attribute("force")->value());
                            customEvent->questClearNebula = true;
                        }

                        if (child->first_attribute("nebulaEvent"))
                        {
                            customEvent->questNebulaQuest = child->first_attribute("nebulaEvent")->value();
                            customEvent->questClearNebula = true;
                        }

                        if (child->first_attribute("clear"))
                        {
                            customEvent->questClearNebula = EventsParser::ParseBoolean(child->first_attribute("clear")->value());
                        }
                    }

                    if (nodeName == "lastStandQuest")
                    {
                        customEvent->questLastStand = true;

                        if (child->first_attribute("noBoss"))
                        {
                            customEvent->questNoBoss = EventsParser::ParseBoolean(child->first_attribute("noBoss")->value());
                        }
                    }

                    if (nodeName == "noNextSectorQuest")
                    {
                        customEvent->questNoNextSector = true;

                        if (child->first_attribute("aggressive"))
                        {
                            customEvent->questAggressive = EventsParser::ParseBoolean(child->first_attribute("aggressive")->value());
                        }
                    }

                    if (nodeName == "secretSectorWarp")
                    {
                        customEvent->secretSectorWarp = child->value();
                    }

                    if (nodeName == "loadEvent")
                    {
                        customEvent->eventLoad = child->value();

                        if (child->first_attribute("seeded"))
                        {
                            customEvent->eventLoadSeeded = EventsParser::ParseBoolean(child->first_attribute("seeded")->value());
                        }
                    }

                    if (nodeName == "beaconType")
                    {
                        BeaconType* beaconType = new BeaconType();
                        beaconType->eventName = eventName;

                        if (child->first_attribute("id"))
                        {
                            beaconType->beaconText.data = child->first_attribute("id")->value();
                            beaconType->beaconText.isLiteral = false;
                        }
                        else if (child->first_attribute("text"))
                        {
                            beaconType->beaconText.data = child->first_attribute("text")->value();
                            beaconType->beaconText.isLiteral = true;
                        }
                        if (child->first_attribute("req"))
                        {
                            beaconType->equipmentReq = child->first_attribute("req")->value();
                        }

                        if (child->first_attribute("global"))
                        {
                            beaconType->global = EventsParser::ParseBoolean(child->first_attribute("global")->value());
                        }

                        GL_Color color = GL_Color(255.f, 255.f, 255.f, 1.f);

                        for (auto child2 = child->first_node(); child2; child2 = child2->next_sibling())
                        {
                            if (strcmp(child2->name(), "unvisitedTooltip") == 0)
                            {
                                if (child2->first_attribute("id"))
                                {
                                    beaconType->unvisitedTooltip.data = child2->first_attribute("id")->value();
                                    beaconType->unvisitedTooltip.isLiteral = false;
                                }
                                else
                                {
                                    beaconType->unvisitedTooltip.data = child2->value();
                                    beaconType->unvisitedTooltip.isLiteral = true;
                                }
                            }

                            if (strcmp(child2->name(), "visitedTooltip") == 0)
                            {
                                if (child2->first_attribute("id"))
                                {
                                    beaconType->visitedTooltip.data = child2->first_attribute("id")->value();
                                    beaconType->visitedTooltip.isLiteral = false;
                                }
                                else
                                {
                                    beaconType->visitedTooltip.data = child2->value();
                                    beaconType->visitedTooltip.isLiteral = true;
                                }
                            }

                            if (strcmp(child2->name(), "undiscoveredTooltip") == 0)
                            {
                                if (child2->first_attribute("id"))
                                {
                                    beaconType->undiscoveredTooltip.data = child2->first_attribute("id")->value();
                                    beaconType->undiscoveredTooltip.isLiteral = false;
                                }
                                else
                                {
                                    beaconType->undiscoveredTooltip.data = child2->value();
                                    beaconType->undiscoveredTooltip.isLiteral = true;
                                }
                            }

                            if (strcmp(child2->name(), "color") == 0)
                            {
                                ParseColorNode(color, child2);
                            }
                        }

                        beaconType->color = color;

                        customEvent->beacon = beaconType;
                        customEvent->hasCustomBeacon = true;
                    }
                    if (nodeName == "removeHazards")
                    {
                        customEvent->removeHazards = true;
                    }
                    if (nodeName == "removeNebula")
                    {
                        customEvent->removeNebula = true;
                    }
                    if (nodeName == "hiddenAug")
                    {
                        customEvent->hiddenAugs.push_back(child->value());
                    }
                    if (nodeName == "win")
                    {
                        customEvent->gameOver.enabled = true;
                        if (child->first_attribute("text"))
                        {
                            customEvent->gameOver.text = child->first_attribute("text")->value();
                        }
                        if (child->first_attribute("creditsText"))
                        {
                            customEvent->gameOver.creditsText = child->first_attribute("creditsText")->value();
                        }
                        if (child->first_attribute("creditsBackground"))
                        {
                            customEvent->gameOver.creditsBackground = child->first_attribute("creditsBackground")->value();
                        }
                    }
                    if (nodeName == "playSound")
                    {
                        customEvent->playSound = child->value();
                    }
                    if (nodeName == "changeBackground")
                    {
                        customEvent->changeBackground = child->value();
                    }
                    if (nodeName == "unlockShip")
                    {
                        customEvent->unlockShip = child->value();

                        if (child->first_attribute("silent"))
                        {
                            customEvent->unlockShipSilent = EventsParser::ParseBoolean(child->first_attribute("silent")->value());
                        }

                        if (child->first_attribute("shipReq"))
                        {
                            customEvent->unlockShipReq = child->first_attribute("shipReq")->value();
                        }
                    }
                    if (nodeName == "disableScrapScore")
                    {
                        customEvent->disableScrapScore = true;
                    }
                    if (nodeName == "removeItem")
                    {
                        customEvent->removeItems.push_back(child->value());
                    }
                    if (nodeName == "customStore")
                    {
                        customEvent->customStore = child->value();
                    }
                }

                customEvents[eventName] = customEvent;
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

    auto it = customEvents.find(baseEvent);

    if (it != customEvents.end())
    {
        CustomEvent* customEvent = customEvents[baseEvent];

        if (!customEvent->recursive && !isParent) return nullptr;
        else
        {
            return customEvent;
        }
    }

    return nullptr;
}

CustomSector *CustomEventsParser::GetCustomSector(const std::string& sectorName)
{
    for (auto i : customSectors)
    {
        if (i->sectorName == sectorName)
        {
            return i;
        }
    }

    return nullptr;
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

static std::string removeHiddenAug = "";

HOOK_METHOD(WorldManager, CreateChoiceBox, (LocationEvent *event) -> void)
{
    auto customEvents = CustomEventsParser::GetInstance();

    if (customEvents->GetCustomEvent(event->eventName))
    {
        g_checkCargo = customEvents->GetCustomEvent(event->eventName)->checkCargo;
    }

    if (!event->stuff.removeItem.empty())
    {
        if (boost::algorithm::starts_with(event->stuff.removeItem, "HIDDEN "))
        {
            removeHiddenAug = event->stuff.removeItem;
            event->stuff.removeItem = "";
        }
    }



    super(event);

    g_checkCargo = false;
}

// hidden augs, checkCargo
HOOK_METHOD(WorldManager, ModifyResources, (LocationEvent *event) -> LocationEvent*)
{
    auto customEvents = CustomEventsParser::GetInstance();
    auto customEvent = customEvents->GetCustomEvent(event->eventName);

    if (customEvent)
    {
        g_checkCargo = customEvents->GetCustomEvent(event->eventName)->checkCargo;

        for (auto i : customEvents->GetCustomEvent(event->eventName)->hiddenAugs)
        {
            auto augList = G_->GetShipInfo()->augList;

            if (augList.find("HIDDEN " + i) != augList.end())
            {
                G_->GetShipInfo()->augList["HIDDEN " + i]++;
            }
            else
            {
                G_->GetShipInfo()->augList["HIDDEN " + i] = 1;
            }
        }
    }


    auto ret = super(event);

    g_checkCargo = false;

    if (!removeHiddenAug.empty())
    {
        playerShip->shipManager->RemoveItem(removeHiddenAug);
    }


    if (customEvent)
    {
        for (auto i : customEvent->removeItems)
        {
            playerShip->shipManager->RemoveItem(i);
        }
    }

    removeHiddenAug = "";

    return ret;
}

HOOK_METHOD(ShipManager, RemoveItem, (const std::string& name) -> void)
{
    bool removedItem = false;

    if (HasAugmentation(name) || boost::algorithm::starts_with(name, "HIDDEN "))
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

    if (custom->GetBossShipDefinition(ship->shipManager->myBlueprint.blueprintName))
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

    if (custom->GetBossShipDefinition(ship->shipManager->myBlueprint.blueprintName))
    {
        boxPosition.x = 5;
        boxPosition.y = 7;

        targetPosition.x = boxPosition.x + 261 - ShipGraph::GetShipInfo(currentTarget->shipManager->iShipId)->shipBox.w / 2;
        targetPosition.y = boxPosition.y + custom->GetBossShipDefinition(ship->shipManager->myBlueprint.blueprintName)->yOffset;

        boss_visual = true;
    }
}

static GL_Texture* boxCustom[3];

HOOK_METHOD(StarMap, constructor, () -> void)
{
    super();
    boxCustom[0] = G_->GetResources()->GetImageId("map/map_box_custom_1.png");
    boxCustom[1] = G_->GetResources()->GetImageId("map/map_box_custom_2.png");
    boxCustom[2] = G_->GetResources()->GetImageId("map/map_box_custom_3.png");
}

static std::map<Location*, bool[2]> locValues = std::map<Location*, bool[2]>();
static bool questActuallyEnoughTime = false;
static bool questNextSectorPopped = false;
static int overrideWorldLevel = -1;

HOOK_METHOD(StarMap, AddQuest, (const std::string& questEvent, bool force) -> bool)
{
    int savedSeed = 0;
    int nextQuestSeed = Global::questSeed;
    overrideWorldLevel = worldLevel;
    int numAddedQuests = addedQuests.size();
    int numDelayedQuests = delayedQuests.size();

    if (SeedInputBox::seedsEnabled) savedSeed = random32();

    if (Global::lastDelayedQuestSeeds.size() > Global::delayedQuestIndex)
    {
        Global::questSeed = Global::lastDelayedQuestSeeds[Global::delayedQuestIndex++];
    }

    CustomEvent *questCustomEvent = CustomEventsParser::GetInstance()->GetCustomEvent(questEvent);

    questActuallyEnoughTime = false;
    questNextSectorPopped = false;
    locValues.clear();

    for (auto i : locations)
    {
        locValues[i][0] = i->questLoc;
        locValues[i][1] = i->nebula;
        CustomEvent *customEvent = CustomEventsParser::GetInstance()->GetCustomEvent(i->event->eventName);

        if (questCustomEvent) {
            if (questCustomEvent->questForceNebula)
            {
                i->nebula = !i->nebula;
            }
            else if (questCustomEvent->questAllowNebula)
            {
                i->nebula = false;
            }
        }
        if (customEvent && customEvent->preventQuest)
        {
            i->nebula = true;
        }
    }

    if ((bInfiniteMode || (questCustomEvent && questCustomEvent->questLastStand)) && (worldLevel > 5 || bossLevel))
    {
        worldLevel = 5;
        bool bossQuest = questCustomEvent && questCustomEvent->questLastStand && !questCustomEvent->questNoBoss;

        if (bInfiniteMode || bossQuest)
        {
            questActuallyEnoughTime = true;
        }
        if (bossLevel)
        {
            force = bossQuest;
        }
    }

    if (SeedInputBox::seedsEnabled) srandom32(Global::questSeed);
    bool ret = super(questEvent, force);
    if (SeedInputBox::seedsEnabled && !Global::delayedQuestIndex) nextQuestSeed = random32();

    if (!ret && questCustomEvent && questCustomEvent->questAggressive)
    {
        if (delayedQuests.size() > numDelayedQuests)
        {
            delayedQuests.pop_back();
        }
        if (SeedInputBox::seedsEnabled) srandom32(Global::questSeed);
        ret = super(questEvent, true);
        if (SeedInputBox::seedsEnabled && !Global::delayedQuestIndex) nextQuestSeed = random32();
    }

    if (!ret && questCustomEvent && questCustomEvent->questNoNextSector && delayedQuests.size() > numDelayedQuests)
    {
        delayedQuests.pop_back();
        questNextSectorPopped = true;
    }

    worldLevel = overrideWorldLevel;
    overrideWorldLevel = -1;

    for (auto i : locValues)
    {
        i.first->nebula = i.second[1];
    }

    if (ret)
    {
        for (auto i : locations)
        {
            if (i->questLoc != locValues[i][0]) //found the new quest location
            {
                if (questCustomEvent && i->nebula)
                {
                    if (!questCustomEvent->questNebulaQuest.empty())
                    {
                        if (SeedInputBox::seedsEnabled) srandom32(Global::questSeed);
                        i->event = G_->GetEventGenerator()->GetBaseEvent(questCustomEvent->questNebulaQuest, worldLevel, false, -1);
                        if (addedQuests.size() > numAddedQuests) {
                            addedQuests[numAddedQuests].first = questCustomEvent->questNebulaQuest;
                        }
                    }
                    if (!questCustomEvent->questClearNebula)
                    {
                        i->event->environment = 3;
                        i->event->statusEffects.push_back({2,7,0,2});
                    }
                }
                break;
            }
        }
    }

    if (ret && addedQuests.size() > numAddedQuests)
    {
        addedQuests[numAddedQuests].first = "QUEST " + std::to_string(Global::questSeed) + " " + addedQuests[numAddedQuests].first;
    }

    if (!ret && delayedQuests.size() > numDelayedQuests)
    {
        Global::delayedQuestSeeds.push_back(Global::questSeed);
    }

    if (SeedInputBox::seedsEnabled)
    {
        Global::questSeed = nextQuestSeed;
        srandom32(savedSeed);
    }

    return ret;
}

HOOK_METHOD(EventGenerator, GetBaseEvent, (const std::string& name, int worldLevel, char ignoreUnique, int seed) -> LocationEvent*)
{
    if (overrideWorldLevel > -1)
    {
        return super(name, overrideWorldLevel, ignoreUnique, seed);
    }

    return super(name, worldLevel, ignoreUnique, seed);
}

HOOK_METHOD(StarMap, RenderLabels, () -> void)
{
    CSurface::GL_PushMatrix();
    CSurface::GL_Translate(position.x, position.y, 0.f);
    CSurface::GL_Translate(translation.x, translation.y, 0.f);

    locValues.clear();

    if (!outOfFuel)
    {
        for (auto i : locations)
        {

            CustomEvent *customEvent = CustomEventsParser::GetInstance()->GetCustomEvent(i->event->eventName);

            if (customEvent && customEvent->hasCustomBeacon && (i->questLoc || i->beacon))
            {
                locValues[i][0] = i->questLoc;
                locValues[i][1] = i->beacon;

                i->questLoc = false;
                i->beacon = false;
            }

            if (customEvent && customEvent->hasCustomBeacon && (bMapRevealed || customEvent->beacon->global || i->known))
            {
                BeaconType *beaconType = customEvent->beacon;

                if (beaconType->equipmentReq.empty() || shipManager->HasEquipment(beaconType->equipmentReq))
                {
                    std::string text = std::string();

                    text = customEvent->beacon->beaconText.GetText();

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

                    CSurface::GL_SetColor(color);
                    freetype::easy_print(51, i->loc.x + 14.f, i->loc.y - 25.f, text);
                }
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

        if (custom->GetCustomSector(currentSector->description.type))
        {
            CustomSector* customSector = custom->GetCustomSector(currentSector->description.type);

            if (customSector)
            {
                SectorExit customBeacon = customSector->exitBeacons;

                EventGenerator *eventGenerator = G_->GetEventGenerator();
                for (auto i : locations)
                {
                    if (i->beacon)
                    {
                        std::string event = "";
                        if (i->dangerZone && !customBeacon.rebelEvent.empty())
                        {
                            event = customBeacon.rebelEvent;
                        }
                        else
                        {
                            if (i->nebula && !customBeacon.nebulaEvent.empty())
                            {
                                event = customBeacon.nebulaEvent;
                            }
                            else if (!customBeacon.event.empty())
                            {
                                event = customBeacon.event;
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

        if (loc->beacon)
        {
            event = "FLEET_EASY_BEACON";
        }
        else if (loc->nebula)
        {
            event = "FLEET_EASY_NEBULA";
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
            loc->event->statusEffects.push_back({2, 7, 0, 2});
        }
    }



    if (!bossLevel)
    {
        auto custom = CustomEventsParser::GetInstance();

        CustomSector *customSector = custom->GetCustomSector(currentSector->description.type);

        if (customSector)
        {
            SectorExit customBeacon = customSector->exitBeacons;
            if (loc->beacon && !customBeacon.rebelEvent.empty())
            {
                bool isNebula = loc->nebula;

                LocationEvent *newEvent = eventGenerator->GetBaseEvent(customBeacon.rebelEvent, worldLevel, false, -1);

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
    }

    if (!loc->beacon || bossLevel)
    {
        auto custom = CustomEventsParser::GetInstance();
        CustomSector *customSector = custom->GetCustomSector(currentSector->description.type);

        if (customSector)
        {
            SectorFleet customBeacon = customSector->fleetBeacons;

            std::string event = "";
            if (loc->nebula && !customBeacon.nebulaEvent.empty())
            {
                event = customBeacon.nebulaEvent;
            }
            else if (!customBeacon.event.empty())
            {
                event = customBeacon.event;
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


HOOK_METHOD(WorldManager, CreateChoiceBox, (LocationEvent *loc) -> void)
{
    CustomEvent *customEvent = CustomEventsParser::GetInstance()->GetCustomEvent(loc->eventName);
    if (customEvent)
    {
        if (!customEvent->unlockShip.empty())
        {
            if (customEvent->unlockShipReq.empty() || G_->GetAchievementTracker()->currentShip == customEvent->unlockShipReq)
            {
                CustomShipUnlocks::instance->UnlockShip(customEvent->unlockShip, customEvent->unlockShipSilent);
            }
        }

        if (customEvent->noQuestText)
        {
            std::string str;
            str = G_->GetTextLibrary()->GetText("added_quest");
            str.insert(0, "\n\n");
            loc->text.data = boost::algorithm::replace_first_copy(loc->text.data, str, "");
            str = G_->GetTextLibrary()->GetText("no_time");
            str.insert(0, "\n\n");
            loc->text.data = boost::algorithm::replace_first_copy(loc->text.data, str, "");
            str = G_->GetTextLibrary()->GetText("added_quest_sector");
            str.insert(0, "\n\n");
            loc->text.data = boost::algorithm::replace_first_copy(loc->text.data, str, "");
        }
    }
    if (questActuallyEnoughTime)
    {
        std::string str;
        std::string repl;

        str = G_->GetTextLibrary()->GetText("no_time");
        repl = G_->GetTextLibrary()->GetText("added_quest_sector");
        loc->text.data = boost::algorithm::replace_first_copy(loc->text.data, str, repl);
    }
    if (questNextSectorPopped)
    {
        std::string str;
        std::string repl;

        str = G_->GetTextLibrary()->GetText("added_quest_sector");
        repl = G_->GetTextLibrary()->GetText("no_time_sector");
        loc->text.data = boost::algorithm::replace_first_copy(loc->text.data, str, repl);
    }
    super(loc);
}

HOOK_METHOD(WorldManager, UpdateLocation, (LocationEvent *loc) -> void)
{
    super(loc);

    CustomEvent *customEvent = CustomEventsParser::GetInstance()->GetCustomEvent(loc->eventName);
    if (customEvent)
    {
        if (!customEvent->eventLoad.empty())
        {
            int seed = customEvent->eventLoadSeeded ? (int)(starMap.currentLoc->loc.x + starMap.currentLoc->loc.y) ^ starMap.currentSectorSeed : -1;

            super(G_->GetEventGenerator()->GetBaseEvent(customEvent->eventLoad, starMap.currentSector->level, true, seed));
        }

        if (customEvent->removeHazards)
        {
            space.asteroidGenerator.bRunning = false;
            space.SetPulsarLevel(false);
            space.SetPlanetaryDefense(false, 0);
            space.SetFireLevel(false);
            space.nebulaClouds.clear();
            space.bStorm = false;
            playerShip->shipManager->ClearStatusAll();
            if (space.bNebula)
            {
                space.SetNebula(true);
            }
        }
        if (customEvent->removeNebula)
        {
            space.bNebula = false;
            space.bStorm = false;
            space.nebulaClouds.clear();
        }
    }

    starMap.currentLoc->event->eventName = loc->eventName;
}

HOOK_STATIC(StarMap, GetLocationText, (std::string& strRef, StarMap *starMap, const Location* loc) -> std::string&)
{
    CustomEvent *customEvent = CustomEventsParser::GetInstance()->GetCustomEvent(loc->event->eventName);

    if (!customEvent) return super(strRef, starMap, loc);

    if (loc->fleetChanging || loc == starMap->currentLoc || !customEvent->beacon)
    {
        return super(strRef, starMap, loc);
    }

    TextString tooltip;

    if (loc->visited)
    {
        tooltip = customEvent->beacon->visitedTooltip;
    }
    else
    {
        tooltip = customEvent->beacon->unvisitedTooltip;
    }
    if (!customEvent->beacon->global && !loc->known && !starMap->bMapRevealed)
    {
        tooltip = customEvent->beacon->undiscoveredTooltip;
    }

    if (tooltip.data.empty())
    {
        return super(strRef, starMap, loc);
    }

    strRef.assign(tooltip.GetText());

    auto lib = G_->GetTextLibrary();

    if (loc->nebula)
    {
        if (starMap->bNebulaMap)
        {
            strRef += " \n" + lib->GetText("map_nebula_fleet_loc");
        }
        else
        {
            strRef += " \n" + lib->GetText("map_nebula_loc");
        }
    }

    if (!starMap->bMapRevealed && (!loc->known || !starMap->shipManager->HasAugmentation("ADV_SCANNERS")))
        return strRef;

    int env = loc->event->environment;

    if (env == 1)
    {
        strRef += " \n" + lib->GetText("map_asteroid_loc");
    }
    if (env == 2)
    {
        strRef += " \n" + lib->GetText("map_sun_loc");
    }
    if (env == 4)
    {
        strRef += " \n" + lib->GetText("map_ion_loc");
    }
    if (env == 5)
    {
        strRef += " \n" + lib->GetText("map_pulsar_loc");
    }
    if (env != 6 || loc->boss)
    {
        return strRef;
    }
    if (loc->dangerZone)
    {
        strRef += " \n" + lib->GetText("map_pds_fleet");
    }
    else
    {
        strRef += " \n" + lib->GetText("map_pds_loc");
    }

    return strRef;
}

HOOK_METHOD(StarMap, GenerateNebulas, (std::vector<std::string>& names) -> void)
{
    if (names.size() > locations.size())
    {
        names.resize(locations.size());
    }

    super(names);

    CustomSector* customSector = CustomEventsParser::GetInstance()->GetCustomSector(currentSector->description.type);

    if (customSector && customSector->removeFirstBeaconNebula)
    {
        if (currentLoc->nebula)
        {
            currentLoc->nebula = false;
            currentLoc->event->environment = 0;
            currentLoc->event->statusEffects.erase(
                std::remove_if(
                    currentLoc->event->statusEffects.begin(),
                    currentLoc->event->statusEffects.end(),
                    [](const StatusEffect& item) { return item.system == 7; }),
                currentLoc->event->statusEffects.end());
        }
    }
}


HOOK_METHOD(StarMap, StartSecretSector, () -> void)
{
    CustomEvent *customEvent = CustomEventsParser::GetInstance()->GetCustomEvent(currentLoc->event->eventName);

    if (customEvent && !customEvent->secretSectorWarp.empty())
    {
        bSecretSector = true;
        Sector *newSector = new Sector();

        newSector->description = *G_->GetEventGenerator()->GetSpecificSector(customEvent->secretSectorWarp);

        currentSector = newSector;
    }
    else
    {
        super();
    }
}


static std::string sectorChange = "";

HOOK_METHOD(StarMap, SaveGame, (int file) -> void)
{
    FileHelper::writeString(file, currentSector->description.type);
    super(file);
}

HOOK_METHOD(StarMap, LoadGame, (int file) -> Location*)
{
    sectorChange = FileHelper::readString(file);
    Location* ret = super(file);
    sectorChange = "";
    return ret;
}


HOOK_METHOD(StarMap, NewGame, (bool unk) -> Location*)
{
    bSecretSector = false;

    return super(unk);
}

HOOK_METHOD(StarMap, GenerateMap, (bool tutorial, bool seed) -> LocationEvent*)
{
    if (!sectorChange.empty() && bSecretSector)
    {
        Sector *newSector = new Sector();

        newSector->description = *G_->GetEventGenerator()->GetSpecificSector(sectorChange);

        currentSector = newSector;
    }

    return super(tutorial, seed);
}


static std::string replaceGameOverText = "";
static std::string replaceGameOverCreditsText = "";
static bool shouldReplaceCreditsText = false;
static bool shouldReplaceBackground = false;
static std::string replaceCreditsBackground = "";

HOOK_METHOD(GameOver, OpenText, (const std::string& text) -> void)
{
    if (!replaceGameOverText.empty()) return super(replaceGameOverText);

    return super(text);
}

HOOK_METHOD(CommandGui, OnLoop, () -> void)
{
    super();
}

static bool blockScrapCollected = false;

HOOK_METHOD(ScoreKeeper, AddScrapCollected, (int scrap) -> void)
{
    if (blockScrapCollected) return;

    super(scrap);
}

HOOK_METHOD(WorldManager, ModifyResources, (LocationEvent *event) -> LocationEvent*)
{
    CustomEvent *customEvent = CustomEventsParser::GetInstance()->GetCustomEvent(event->eventName);

    if (customEvent)
    {
        if (customEvent->disableScrapScore)
        {
            blockScrapCollected = true;
        }
    }

    LocationEvent *ret = super(event);

    blockScrapCollected = false;

    if (customEvent)
    {
        if (customEvent->gameOver.enabled)
        {
            G_->GetSoundControl()->StopPlaylist(100);
            G_->GetSoundControl()->PlaySoundMix("victory", -1.f, false);

            replaceGameOverText = customEvent->gameOver.text;
            replaceGameOverCreditsText = customEvent->gameOver.creditsText;
            replaceCreditsBackground = G_->GetEventGenerator()->GetImageFromList(customEvent->gameOver.creditsBackground);

            G_->GetScoreKeeper()->SetVictory(true);
            commandGui->gameover = true;
            commandGui->Victory();

            replaceGameOverText = "";
        }

        if (!customEvent->playSound.empty())
        {
            G_->GetSoundControl()->PlaySoundMix(customEvent->playSound, -1.f, false);
        }

        if (!customEvent->changeBackground.empty())
        {
            space.currentBack = G_->GetResources()->GetImageId(G_->GetEventGenerator()->GetImageFromList(customEvent->changeBackground));
        }
    }




    return ret;
}

HOOK_STATIC(TextLibrary, GetText, (std::string& str, TextLibrary *lib, const std::string& name, const std::string& lang) -> std::string&)
{
    if (!shouldReplaceCreditsText || replaceGameOverCreditsText.empty() || name != "credit_victory") return super(str, lib, name, lang);

    return super(str, lib, replaceGameOverCreditsText, lang);
}

HOOK_METHOD(ResourceControl, GetImageId, (const std::string& name) -> GL_Texture*)
{
    if (shouldReplaceBackground && !replaceCreditsBackground.empty() && name == "stars/bg_darknebula.png")
    {
        return super(replaceCreditsBackground);
    }

    return super(name);
}

HOOK_METHOD(CreditScreen, Start, (const std::string& shipName, const std::vector<std::string>& crewNames) -> void)
{
    auto defaultVictory = CustomEventsParser::GetInstance()->defaultVictory;
    if (defaultVictory)
    {
        if (replaceCreditsBackground.empty() && !defaultVictory->gameOver.creditsBackground.empty())
        {
            replaceCreditsBackground = G_->GetEventGenerator()->GetImageFromList(defaultVictory->gameOver.creditsBackground);
        }
        if (replaceGameOverCreditsText.empty() && !defaultVictory->gameOver.creditsText.empty())
        {
            replaceGameOverCreditsText = defaultVictory->gameOver.creditsText;
        }
    }

    return super(shipName, crewNames);
}

HOOK_METHOD(CreditScreen, Done, () -> bool)
{
    bool ret = super();

    if (ret)
    {
        replaceCreditsBackground = "";
        replaceGameOverCreditsText = "";
    }

    return ret;
}

HOOK_METHOD(CreditScreen, OnRender, () -> void)
{
    shouldReplaceBackground = true;
    shouldReplaceCreditsText = true;
    super();
    shouldReplaceCreditsText = false;
    shouldReplaceBackground = false;
}
