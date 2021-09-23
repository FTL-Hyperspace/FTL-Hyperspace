#include "CustomAugments.h"
#include "CustomEvents.h"
#include "freetype.h"
#include "Resources.h"
#include "Seeds.h"
#include "ShipUnlocks.h"
#include "CustomFleetShips.h"
#include "CustomBoss.h"
#include "CustomCrew.h"
#include "CustomSectors.h"
#include "CustomOptions.h"
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>

CustomEventsParser *CustomEventsParser::instance = new CustomEventsParser();
bool alreadyWonCustom = false;
bool bossDefeated = false;

TimerHelper *restartMusicTimer = nullptr;

std::unordered_map<std::string, EventAlias> eventAliases = std::unordered_map<std::string, EventAlias>();

std::unordered_map<int, std::string> renamedBeacons = std::unordered_map<int, std::string>();

std::unordered_map<int, std::pair<std::string, int>> regeneratedBeacons = std::unordered_map<int, std::pair<std::string, int>>();

CustomEvent::CustomEvent()
{
    checkCargo = CustomOptionsManager::GetInstance()->defaults.checkCargo;
}

void CustomEventsParser::ParseCustomEventNodeFiles(rapidxml::xml_node<char> *node)
{
    for (auto eventNode = node->first_node(); eventNode; eventNode = eventNode->next_sibling())
    {
        if (strcmp(eventNode->name(), "eventFile") == 0)
        {
            if (eventNode->value())
            {
                eventFiles.push_back(std::string(eventNode->value()));
            }
        }
    }
}

void CustomEventsParser::ReadCustomEventFiles()
{
    char* eventText = G_->GetResources()->LoadFile("data/events_hyperspace.xml");

    if (eventText)
    {
        try
        {
            G_->GetEventsParser()->AddEvents(*G_->GetEventGenerator(), eventText, "data/events_hyperspace.xml");
        }
        catch (rapidxml::parse_error& e)
        {
            std::string msg = std::string("Failed parsing events_hyperspace.xml\n") + std::string(e.what());
            MessageBoxA(GetDesktopWindow(), msg.c_str(), "Error", MB_ICONERROR | MB_SETFOREGROUND);
        }
        catch (std::exception &e)
        {
            std::string msg = std::string("Failed parsing events_hyperspace.xml\n") + std::string(e.what());
            MessageBoxA(GetDesktopWindow(), msg.c_str(), "Error", MB_ICONERROR | MB_SETFOREGROUND);
        }
        catch (const char* e)
        {
            std::string msg = std::string("Failed parsing events_hyperspace.xml\n") + std::string(e);
            MessageBoxA(GetDesktopWindow(), msg.c_str(), "Error", MB_ICONERROR | MB_SETFOREGROUND);
        }
    }

    for (auto i : CustomEventsParser::GetInstance()->eventFiles)
    {
        std::string fileName = "data/events_" + i + ".xml";

        char* eventText = G_->GetResources()->LoadFile(fileName);

        if (eventText)
        {
            try
            {
                G_->GetEventsParser()->AddEvents(*G_->GetEventGenerator(), eventText, fileName);
            }
            catch (rapidxml::parse_error& e)
            {
                std::string msg = std::string("Failed parsing ") + fileName + std::string("\n") + std::string(e.what());
                MessageBoxA(GetDesktopWindow(), msg.c_str(), "Error", MB_ICONERROR | MB_SETFOREGROUND);
            }
            catch (std::exception &e)
            {
                std::string msg = std::string("Failed parsing ") + fileName + std::string("\n") + std::string(e.what());
                MessageBoxA(GetDesktopWindow(), msg.c_str(), "Error", MB_ICONERROR | MB_SETFOREGROUND);
            }
            catch (const char* e)
            {
                std::string msg = std::string("Failed parsing ") + fileName + std::string("\n") + std::string(e);
                MessageBoxA(GetDesktopWindow(), msg.c_str(), "Error", MB_ICONERROR | MB_SETFOREGROUND);
            }
        }
    }
}

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

        if (strcmp(eventNode->name(), "fleetDef") == 0)
        {
            ParseFleetShipNode(eventNode);
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

                    if (strcmp(sectorNode->name(), "noExit") == 0)
                    {
                        sec->noExit = true;
                    }

                    if (strcmp(sectorNode->name(), "nebulaSector") == 0)
                    {
                        sec->nebulaSector = EventsParser::ParseBoolean(sectorNode->value());
                    }

                    customSectors.push_back(sec);
                }
            }
        }

        if (strcmp(eventNode->name(), "revisitEvent") == 0)
        {
            defaultRevisit = eventNode->value();

            if (eventNode->first_attribute("seeded"))
            {
                defaultRevisitSeeded = EventsParser::ParseBoolean(eventNode->first_attribute("seeded")->value());
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
                    customEvent->eventName = "default_victory";
                    ParseCustomEvent(eventNode, customEvent);
                }
                else
                {
                    if (eventNode->first_attribute("recursive") && !EventsParser::ParseBoolean(eventNode->first_attribute("recursive")->value()))
                    {
                        auto it = customEvents.find(eventName);
                        if (it == customEvents.end())
                        {
                            auto it2 = customRecursiveEvents.find(eventName);
                            if (it2 != customRecursiveEvents.end())
                            {
                                customEvent = new CustomEvent(*it2->second);
                            }
                            else
                            {
                                customEvent = new CustomEvent();
                            }
                            customEvent->eventName = eventName;
                            customEvent->recursive = false;
                            ParseCustomEvent(eventNode, customEvent);
                            customEvents[eventName] = customEvent;
                            vCustomEvents[eventName].push_back(customEvent);
                        }
                        else
                        {
                            customEvent = it->second;
                            ParseCustomEvent(eventNode, customEvent);
                        }
                    }
                    else
                    {
                        auto it = customRecursiveEvents.find(eventName);
                        if (it == customRecursiveEvents.end())
                        {
                            customEvent = new CustomEvent();
                            customEvent->eventName = eventName;
                            ParseCustomEvent(eventNode, customEvent);
                            customRecursiveEvents[eventName] = customEvent;
                        }
                        else
                        {
                            customEvent = it->second;
                            ParseCustomEvent(eventNode, customEvent);
                        }

                        auto it2 = vCustomEvents.find(eventName);
                        if (it2 != vCustomEvents.end())
                        {
                            std::vector<CustomEvent*>& vCustomEvent = it2->second;
                            for (CustomEvent* customEvent : vCustomEvent)
                            {
                                ParseCustomEvent(eventNode, customEvent);
                            }
                        }
                    }
                }
            }
        }

        if (strcmp(eventNode->name(), "shipEvent") == 0)
        {
            if (eventNode->first_attribute("name"))
            {
                std::string eventName = std::string(eventNode->first_attribute("name")->value());
                CustomShipEvent *customEvent;

                auto it = customShipEvents.find(eventName);
                if (it == customShipEvents.end())
                {
                    customEvent = new CustomShipEvent();
                    customEvent->eventName = eventName;
                    ParseCustomShipEvent(eventNode, customEvent);
                    customShipEvents[eventName] = customEvent;
                }
                else
                {
                    customEvent = it->second;
                    ParseCustomShipEvent(eventNode, customEvent);
                }
			}
		}

        if (strcmp(eventNode->name(), "quest") == 0)
        {
            ParseCustomQuestNode(eventNode, defaultQuest);
        }

        if (strcmp(eventNode->name(), "req") == 0)
        {
            if (eventNode->first_attribute("name"))
            {
                std::string reqName = std::string(eventNode->first_attribute("name")->value());

                CustomReq *customReq;
                if (GetCustomReq(reqName) == nullptr)
                {
                    customReq = new CustomReq();
                }
                else
                {
                    customReq = GetCustomReq(reqName);
                    delete customReq;
                    customReq = new CustomReq();
                }

                ParseCustomReqNode(eventNode, customReq);

                customReqs[reqName] = customReq;
            }
            else
            {
                MessageBoxA(GetDesktopWindow(), "Custom req is missing a name!", "Error", MB_ICONERROR | MB_SETFOREGROUND);
            }
        }

        if (strcmp(eventNode->name(), "loadEventList") == 0)
        {

            EventLoadList *eventLoadList = new EventLoadList();
            std::string loadEventListName = "";
            if (eventNode->first_attribute("name"))
            {
                loadEventListName = eventNode->first_attribute("name")->value();
            }
            ParseCustomEventLoadList(eventNode, eventLoadList, loadEventListName);
            if (!loadEventListName.empty())
            {
                customEventLoadLists[loadEventListName] = eventLoadList;
            }
        }

        if (strcmp(eventNode->name(), "triggeredEventBox") == 0)
        {
            TriggeredEventBoxDefinition boxDef;
            ParseCustomTriggeredEventBoxNode(eventNode, &boxDef);
            if (eventNode->first_attribute("name"))
            {
                TriggeredEventGui::GetInstance()->boxDefs[eventNode->first_attribute("name")->value()] = boxDef;
            }
        }

        if (strcmp(eventNode->name(), "timerSounds") == 0)
        {
            std::vector<std::pair<float,std::string>> timerSounds;
            ParseCustomTriggeredEventSounds(eventNode, &timerSounds);
            if (eventNode->first_attribute("name"))
            {
                TriggeredEventDefinition::timerSoundDefs[eventNode->first_attribute("name")->value()] = timerSounds;
            }
        }

        if (strcmp(eventNode->name(), "warningMessage") == 0)
        {
            TriggeredEventWarningDefinition warningDef;
            ParseCustomTriggeredEventWarningNode(eventNode, &warningDef);
            if (eventNode->first_attribute("name"))
            {
                TriggeredEventGui::GetInstance()->warningDefs[eventNode->first_attribute("name")->value()] = warningDef;
            }
        }

        if (strcmp(eventNode->name(), "combatTimerPosition") == 0)
        {
            for (auto child = eventNode->first_node(); child; child = child->next_sibling())
            {
                std::string nodeName(child->name());
                if (nodeName == "normalPos")
                {
                    if (child->first_attribute("x"))
                    {
                        TriggeredEventGui::GetInstance()->normalBoxPos.x = boost::lexical_cast<int>(child->first_attribute("x")->value());
                    }
                    if (child->first_attribute("y"))
                    {
                        TriggeredEventGui::GetInstance()->normalBoxPos.y = boost::lexical_cast<int>(child->first_attribute("y")->value());
                    }
                }
                if (nodeName == "bossPos")
                {
                    if (child->first_attribute("x"))
                    {
                        TriggeredEventGui::GetInstance()->bossBoxPos.x = boost::lexical_cast<int>(child->first_attribute("x")->value());
                    }
                    if (child->first_attribute("y"))
                    {
                        TriggeredEventGui::GetInstance()->bossBoxPos.y = boost::lexical_cast<int>(child->first_attribute("y")->value());
                    }
                }
            }
        }

        if (strcmp(eventNode->name(), "beaconType") == 0)
        {
            if (eventNode->first_attribute("name"))
            {
                std::string beaconName = std::string(eventNode->first_attribute("name")->value());

                BeaconType *beaconType = new BeaconType();
                beaconType->eventName = beaconName;

                ParseCustomBeaconType(eventNode, beaconType);

                customBeacons[beaconName] = beaconType;
            }
        }
    }
}

void CustomEventsParser::PostProcessCustomEvents()
{
    for (auto& def : TriggeredEventDefinition::defs)
    {
        if (def.loadBox)
        {
            rapidxml::xml_document<> doc;
            doc.parse<0>(def.loadBox->data());
            auto node = doc.first_node("triggeredEventBox");
            if (node)
            {
                if (node->first_attribute("load"))
                {
                    std::string loadName = node->first_attribute("load")->value();
                    auto it = TriggeredEventGui::GetInstance()->boxDefs.find(loadName);
                    if (it != TriggeredEventGui::GetInstance()->boxDefs.end())
                    {
                        *(def.box) = it->second;
                    }
                    else
                    {
                        std::string msg = std::string("Failed to load triggeredEventBox ") + loadName;
                        MessageBoxA(GetDesktopWindow(), msg.c_str(), "Error", MB_ICONERROR | MB_SETFOREGROUND);
                    }
                }
                ParseCustomTriggeredEventBoxNode(node, def.box);
            }

            doc.clear();
            delete def.loadBox;
            def.loadBox = nullptr;
        }
        if (!def.loadTimerSounds.empty())
        {
            auto it = TriggeredEventDefinition::timerSoundDefs.find(def.loadTimerSounds);
            if (it != TriggeredEventDefinition::timerSoundDefs.end())
            {
                for (std::pair<float,std::string>& timerSound : it->second)
                {
                    def.timerSounds.push_back(timerSound);
                }
                std::sort(def.timerSounds.begin(), def.timerSounds.end(), [](const std::pair<float,std::string> &a, const std::pair<float,std::string> &b) -> bool {return a.first > b.first;});
            }
            else
            {
                std::string msg = std::string("Failed to load timerSounds ") + def.loadTimerSounds;
                MessageBoxA(GetDesktopWindow(), msg.c_str(), "Error", MB_ICONERROR | MB_SETFOREGROUND);
            }
        }
        if (def.loadWarning)
        {
            rapidxml::xml_document<> doc;
            doc.parse<0>(def.loadWarning->data());
            auto node = doc.first_node("warningMessage");
            if (node)
            {
                if (node->first_attribute("load"))
                {
                    std::string loadName = node->first_attribute("load")->value();
                    auto it = TriggeredEventGui::GetInstance()->warningDefs.find(loadName);
                    if (it != TriggeredEventGui::GetInstance()->warningDefs.end())
                    {
                        *(def.warning) = it->second;
                    }
                    else
                    {
                        std::string msg = std::string("Failed to load warningMessage ") + loadName;
                        MessageBoxA(GetDesktopWindow(), msg.c_str(), "Error", MB_ICONERROR | MB_SETFOREGROUND);
                    }
                }
                ParseCustomTriggeredEventWarningNode(node, def.warning);
            }

            doc.clear();
            delete def.loadWarning;
            def.loadWarning = nullptr;
        }
    }

    for (auto& def : customEvents)
    {
        if (!def.second->loadBeacon.empty())
        {
            auto it = customBeacons.find(def.second->loadBeacon);
            if (it != customBeacons.end())
            {
                def.second->beacon = it->second;
            }
        }
        def.second->loadBeacon = "";
    }
    for (auto& def : customRecursiveEvents)
    {
        if (!def.second->loadBeacon.empty())
        {
            auto it = customBeacons.find(def.second->loadBeacon);
            if (it != customBeacons.end())
            {
                def.second->beacon = it->second;
            }
        }
        def.second->loadBeacon = "";
    }
}

bool CustomEventsParser::ParseCustomEvent(rapidxml::xml_node<char> *node, CustomEvent *customEvent, bool parsingVanilla)
{
    bool isDefault = true;

    for (auto child = node->first_node(); child; child = child->next_sibling())
    {
        std::string nodeName(child->name());
        if (nodeName == "checkCargo")
        {
            isDefault = false;
            std::string nodeValue = child->value();
            if (nodeValue.empty())
            {
                customEvent->checkCargo = true;
            }
            else
            {
                customEvent->checkCargo = EventsParser::ParseBoolean(nodeValue);
            }
        }

        if (nodeName == "preventQuest")
        {
            isDefault = false;
            customEvent->preventQuest = true;
        }

        if (nodeName == "noQuestText")
        {
            isDefault = false;
            customEvent->noQuestText = true;
        }

        if (nodeName == "quest")
        {
            std::string questEventName;
            if (child->first_attribute("event"))
            {
                questEventName = child->first_attribute("event")->value();
            }
            else
            {
                questEventName = customEvent->eventName;
            }

            CustomQuest* newCustomQuest = new CustomQuest();
            bool questIsDefault = ParseCustomQuestNode(child, newCustomQuest);
            if (questIsDefault)
            {
                delete newCustomQuest;
            }
            else
            {
                customQuests[questEventName] = newCustomQuest;
            }
        }

        if (nodeName == "triggeredEvent")
        {
            isDefault = false;
            TriggeredEventDefinition def;

            ParseCustomTriggeredEventNode(child, &def);

            customEvent->triggeredEvents.push_back(TriggeredEventDefinition::PushDef(def));
        }

        if (nodeName == "clearTriggeredEvent")
        {
            if (child->first_attribute("name"))
            {
                isDefault = false;
                customEvent->clearTriggeredEvents.push_back(child->first_attribute("name")->value());
            }
            else
            {
                MessageBoxA(GetDesktopWindow(), "clearTriggeredEvent is missing a name!", "Error", MB_ICONERROR | MB_SETFOREGROUND);
            }
        }

        if (nodeName == "triggeredEventModifier")
        {
            if (child->first_attribute("name"))
            {
                isDefault = false;
                TriggeredEventModifier def;
                if (child->first_attribute("name"))
                {
                    def.name = child->first_attribute("name")->value();
                }
                if (child->first_attribute("time"))
                {
                    def.minTime = boost::lexical_cast<float>(child->first_attribute("time")->value());
                    def.maxTime = boost::lexical_cast<float>(child->first_attribute("time")->value());
                }
                if (child->first_attribute("minTime"))
                {
                    def.minTime = boost::lexical_cast<float>(child->first_attribute("minTime")->value());
                }
                if (child->first_attribute("maxTime"))
                {
                    def.maxTime = boost::lexical_cast<float>(child->first_attribute("maxTime")->value());
                }
                if (child->first_attribute("jumps"))
                {
                    def.minJumps = boost::lexical_cast<int>(child->first_attribute("jumps")->value());
                    def.maxJumps = boost::lexical_cast<int>(child->first_attribute("jumps")->value());
                }
                if (child->first_attribute("minJumps"))
                {
                    def.minJumps = boost::lexical_cast<int>(child->first_attribute("minJumps")->value());
                }
                if (child->first_attribute("maxJumps"))
                {
                    def.maxJumps = boost::lexical_cast<int>(child->first_attribute("maxJumps")->value());
                }
                customEvent->triggeredEventModifiers.push_back(def);
            }
            else
            {
                MessageBoxA(GetDesktopWindow(), "triggeredEventModifier is missing a name!", "Error", MB_ICONERROR | MB_SETFOREGROUND);
            }
        }

        if (nodeName == "preventFleet")
        {
            isDefault = false;
            customEvent->preventFleet = true;
        }

        if (nodeName == "preventBossFleet")
        {
            isDefault = false;
            customEvent->preventBossFleet = 1;
            if (child->first_attribute("forever") && EventsParser::ParseBoolean(child->first_attribute("forever")->value()))
            {
                customEvent->preventBossFleet = 2;
            }
        }

        if (nodeName == "runFromFleet")
        {
            isDefault = false;
            customEvent->runFromFleet = 2;
            if (child->first_attribute("closest") && EventsParser::ParseBoolean(child->first_attribute("closest")->value()))
            {
                customEvent->runFromFleet = 1;
            }
        }

        if (nodeName == "secretSectorWarp" || nodeName == "secretSector")
        {
            std::string sec = child->value();
            if (!sec.empty())
            {
                isDefault = false;
                customEvent->secretSectorWarp = sec;
            }
        }

        if (nodeName == "loadEvent")
        {
            isDefault = false;
            customEvent->eventLoad = child->value();

            if (child->first_attribute("seeded"))
            {
                customEvent->eventLoadSeeded = EventsParser::ParseBoolean(child->first_attribute("seeded")->value());
            }
        }

        if (nodeName == "revisitEvent")
        {
            isDefault = false;
            customEvent->eventRevisit = child->value();

            if (child->first_attribute("seeded"))
            {
                customEvent->eventRevisitSeeded = EventsParser::ParseBoolean(child->first_attribute("seeded")->value());
            }
        }

        if (nodeName == "loadEventList")
        {
            isDefault = false;
            customEvent->eventLoadList = new EventLoadList();
            ParseCustomEventLoadList(child, customEvent->eventLoadList, customEvent->eventName);
        }

        if (nodeName == "eventAlias")
        {
            isDefault = false;
            std::pair<std::string, EventAlias> alias;
            if (child->first_attribute("name"))
            {
                alias.first = child->first_attribute("name")->value();
            }
            alias.second.event = child->value();
            if (child->first_attribute("jumpClear"))
            {
                alias.second.jumpClear = EventsParser::ParseBoolean(child->first_attribute("jumpClear")->value());
            }
            if (child->first_attribute("once"))
            {
                alias.second.once = EventsParser::ParseBoolean(child->first_attribute("once")->value());
            }
            customEvent->eventAlias.push_back(alias);
        }

        if (nodeName == "restartEvent")
        {
            isDefault = false;
            customEvent->restartEvent = true;
        }

        if (nodeName == "renameBeacon")
        {
            isDefault = false;
            customEvent->renameBeacon = child->value();
        }

        if (nodeName == "jumpEvent")
        {
            isDefault = false;
            customEvent->jumpEvent = child->value();
            if (child->first_attribute("loop"))
            {
                customEvent->jumpEventLoop = EventsParser::ParseBoolean(child->first_attribute("loop")->value());
            }
        }

        if (nodeName == "clearJumpEvent")
        {
            isDefault = false;
            customEvent->jumpEventClear = true;
        }

        if (nodeName == "replaceSector")
        {
            isDefault = false;
            if (child->first_attribute("name"))
            {
                customEvent->replaceSector.targetSector = child->first_attribute("name")->value();
            }
            customEvent->replaceSector.sectorList = child->value();
        }

        if (nodeName == "resetFtl")
        {
            isDefault = false;
            customEvent->resetFtl = true;
        }

        if (nodeName == "instantEscape")
        {
            isDefault = false;
            customEvent->instantEscape = true;
        }

        if (nodeName == "escape")
        {
            isDefault = false;
            customEvent->escape = true;
        }

        if (nodeName == "surrender")
        {
            isDefault = false;
            customEvent->surrender = true;
        }

        if (nodeName == "loadEscape")
        {
            isDefault = false;
            customEvent->loadEscape = true;
            if (child->first_attribute("force"))
            {
                customEvent->loadEscapeForced = EventsParser::ParseBoolean(child->first_attribute("force")->value());
            }
        }

        if (nodeName == "loadSurrender")
        {
            isDefault = false;
            customEvent->loadSurrender = true;
            if (child->first_attribute("force"))
            {
                customEvent->loadSurrenderForced = EventsParser::ParseBoolean(child->first_attribute("force")->value());
            }
        }

        if (nodeName == "disableEscape")
        {
            isDefault = false;
            customEvent->disableEscape = true;
            if (child->first_attribute("force"))
            {
                customEvent->disableEscapeForced = EventsParser::ParseBoolean(child->first_attribute("force")->value());
            }
        }

        if (nodeName == "disableSurrender")
        {
            isDefault = false;
            customEvent->disableSurrender = true;
            if (child->first_attribute("force"))
            {
                customEvent->disableSurrenderForced = EventsParser::ParseBoolean(child->first_attribute("force")->value());
            }
        }

        if (nodeName == "goToFlagship")
        {
            isDefault = false;
            customEvent->goToFlagship = true;
            if (child->first_attribute("atBase"))
            {
                customEvent->goToFlagshipBase = EventsParser::ParseBoolean(child->first_attribute("atBase")->value());
            }
            if (child->first_attribute("allFleet"))
            {
                customEvent->goToFlagshipFleet = EventsParser::ParseBoolean(child->first_attribute("allFleet")->value());
            }
        }

        if (nodeName == "transformRace")
        {
            isDefault = false;
            customEvent->transformRace.second = child->value();

            if (child->first_attribute("class"))
            {
                customEvent->transformRace.first = child->first_attribute("class")->value();
            }
        }

        if (nodeName == "beaconType")
        {
            isDefault = false;

            if (child->first_attribute("load"))
            {
                customEvent->loadBeacon = child->first_attribute("load")->value();
            }
            else
            {
                BeaconType* beaconType = new BeaconType();
                beaconType->eventName = customEvent->eventName;

                ParseCustomBeaconType(child, beaconType);

                customEvent->beacon = beaconType;
            }
        }
        if (nodeName == "removeHazards")
        {
            isDefault = false;
            customEvent->removeHazards = true;
        }
        if (nodeName == "removeNebula")
        {
            isDefault = false;
            customEvent->removeNebula = true;
        }
        if (nodeName == "hiddenAug")
        {
            isDefault = false;
            customEvent->hiddenAugs.push_back(child->value());
        }
        if (nodeName == "win")
        {
            isDefault = false;
            customEvent->gameOver.enabled = true;
            customEvent->gameOver.victory = true;
            customEvent->gameOver.sound = "victory";
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
            if (child->first_attribute("music"))
            {
                customEvent->gameOver.creditsMusic = child->first_attribute("music")->value();
            }
            if (child->first_attribute("sound"))
            {
                customEvent->gameOver.sound = child->first_attribute("sound")->value();
            }
        }
        if (nodeName == "lose")
        {
            isDefault = false;
            customEvent->gameOver.enabled = true;
            if (child->first_attribute("text"))
            {
                customEvent->gameOver.text = child->first_attribute("text")->value();
            }
            if (child->first_attribute("sound"))
            {
                customEvent->gameOver.sound = child->first_attribute("sound")->value();
            }
        }
        if (nodeName == "playSound")
        {
            isDefault = false;
            customEvent->playSound = child->value();
        }
        if (nodeName == "playMusic")
        {
            isDefault = false;
            std::string track = child->value();
            if (track.empty())
            {
                customEvent->resetMusic = true;
            }
            else
            {
                customEvent->playMusic = child->value();
            }
        }
        if (nodeName == "changeBackground")
        {
            isDefault = false;
            customEvent->changeBackground = child->value();
        }
        if (nodeName == "unlockCustomShip" || (!parsingVanilla && nodeName == "unlockShip"))
        {
            std::string shipName = child->value();
            if (!shipName.empty())
            {
                isDefault = false;
                customEvent->unlockShip = shipName;

                if (child->first_attribute("silent"))
                {
                    customEvent->unlockShipSilent = EventsParser::ParseBoolean(child->first_attribute("silent")->value());
                }

                if (child->first_attribute("shipReq"))
                {
                    customEvent->unlockShipReq = child->first_attribute("shipReq")->value();
                }
            }
        }
        if (nodeName == "disableScrapScore")
        {
            isDefault = false;
            customEvent->disableScrapScore = true;
        }
        if (nodeName == "removeItem")
        {
            isDefault = false;
            customEvent->removeItems.push_back(child->value());
        }
        if (nodeName == "customStore" || nodeName == "store")
        {
            std::string storeName = child->value();
            if (!storeName.empty())
            {
                isDefault = false;
                customEvent->customStore = storeName;
            }
        }
        if (nodeName == "customFleet")
        {
            isDefault = false;
            bool right = false;
            bool firing = false;
            bool autoDarkening = false;

            if (child->first_attribute("right"))
            {
                right = EventsParser::ParseBoolean(child->first_attribute("right")->value());
            }
            if (child->first_attribute("firing"))
            {
                firing = EventsParser::ParseBoolean(child->first_attribute("firing")->value());
            }
            if (child->first_attribute("autoDarkening"))
            {
                autoDarkening = EventsParser::ParseBoolean(child->first_attribute("autoDarkening")->value());
            }

            if (!right)
            {
                customEvent->leftFleet.fleetDefName = child->value();
                customEvent->leftFleet.firing = firing;
                customEvent->leftFleet.autoDarkening = autoDarkening;
            }
            else
            {
                customEvent->rightFleet.fleetDefName = child->value();
                customEvent->rightFleet.firing = firing;
                customEvent->rightFleet.autoDarkening = autoDarkening;
            }
        }
        if (nodeName == "clearCustomFleet")
        {
            isDefault = false;
            customEvent->clearCustomFleet = true;
        }
        if (nodeName == "enemyDamage")
        {
            isDefault = false;
            EventDamage eventDamage{-1,0,0};
            if (child->first_attribute("amount"))
            {
                eventDamage.amount = boost::lexical_cast<int>(child->first_attribute("amount")->value());
            }
            if (child->first_attribute("system"))
            {
                eventDamage.system = ShipSystem::NameToSystemId(child->first_attribute("system")->value());
            }
            if (child->first_attribute("effect"))
            {
                std::string damageEffect = child->first_attribute("effect")->value();
                if (damageEffect == "fire")
                {
                    eventDamage.effect = 1;
                }
                if (damageEffect == "breach")
                {
                    eventDamage.effect = 2;
                }
                if (damageEffect == "all")
                {
                    eventDamage.effect = 3;
                }
                if (damageEffect == "random")
                {
                    eventDamage.effect = 4;
                }
            }
            if (child->first_attribute("force") && EventsParser::ParseBoolean(child->first_attribute("force")->value()))
            {
                eventDamage.effect |= 8;
            }
            if (child->first_attribute("damageHull") && !EventsParser::ParseBoolean(child->first_attribute("damageHull")->value()))
            {
                eventDamage.effect |= 16;
            }
            customEvent->enemyDamage.push_back(eventDamage);
        }
        if (nodeName == "superDrones")
        {
            isDefault = false;
            if (child->first_attribute("player"))
            {
                customEvent->superDrones = EventsParser::ParseBoolean(child->first_attribute("player")->value()) ? 0 : 1;
            }
            else
            {
                customEvent->superDrones = 1;
            }
            if (child->first_attribute("name"))
            {
                customEvent->superDronesName = child->first_attribute("name")->value();
            }
        }
        if (nodeName == "clearSuperDrones")
        {
            isDefault = false;
            if (child->first_attribute("player"))
            {
                customEvent->clearSuperDrones = EventsParser::ParseBoolean(child->first_attribute("player")->value()) ? 0 : 1;
            }
            else
            {
                customEvent->clearSuperDrones = 1;
            }
        }
        if (nodeName == "superBarrage")
        {
            isDefault = false;
            if (child->first_attribute("player"))
            {
                customEvent->superBarrage = EventsParser::ParseBoolean(child->first_attribute("player")->value()) ? 0 : 1;
            }
            else
            {
                customEvent->superBarrage = 1;
            }
            if (child->first_attribute("name"))
            {
                customEvent->superBarrageName = child->first_attribute("name")->value();
            }
        }
        if (nodeName == "superShields")
        {
            isDefault = false;
            if (child->first_attribute("player"))
            {
                customEvent->powerSuperShields = EventsParser::ParseBoolean(child->first_attribute("player")->value()) ? 0 : 1;
            }
            else
            {
                customEvent->powerSuperShields = 1;
            }
            if (child->first_attribute("amount"))
            {
                customEvent->powerSuperShieldsSet = boost::lexical_cast<int>(child->first_attribute("amount")->value());
            }
            if (child->first_attribute("add"))
            {
                customEvent->powerSuperShieldsAdd = boost::lexical_cast<int>(child->first_attribute("add")->value());
            }
        }
        if (nodeName == "noASBPlanet")
        {
            isDefault = false;
            customEvent->noASBPlanet = true;
        }
    }

    return isDefault;
}

bool CustomEventsParser::ParseCustomShipEvent(rapidxml::xml_node<char> *node, CustomShipEvent *customEvent)
{
    bool isDefault = true;

    for (auto child = node->first_node(); child; child = child->next_sibling())
    {
        std::string nodeName(child->name());

        if (nodeName == "triggeredEvent")
        {
            isDefault = false;

            TriggeredEventDefinition def;

            ParseCustomTriggeredEventNode(child, &def);

            customEvent->triggeredEvents.push_back(TriggeredEventDefinition::PushDef(def));
        }

        if (nodeName == "clearTriggeredEvent")
        {
            isDefault = false;
            customEvent->clearTriggeredEvents.push_back(child->first_attribute("name")->value());
        }

        if (nodeName == "triggeredEventModifier")
        {
            isDefault = false;
            TriggeredEventModifier def;
            if (child->first_attribute("name"))
            {
                def.name = child->first_attribute("name")->value();
            }
            if (child->first_attribute("time"))
            {
                def.minTime = boost::lexical_cast<float>(child->first_attribute("time")->value());
                def.maxTime = boost::lexical_cast<float>(child->first_attribute("time")->value());
            }
            if (child->first_attribute("minTime"))
            {
                def.minTime = boost::lexical_cast<float>(child->first_attribute("minTime")->value());
            }
            if (child->first_attribute("maxTime"))
            {
                def.maxTime = boost::lexical_cast<float>(child->first_attribute("maxTime")->value());
            }
            if (child->first_attribute("jumps"))
            {
                def.minJumps = boost::lexical_cast<int>(child->first_attribute("jumps")->value());
                def.maxJumps = boost::lexical_cast<int>(child->first_attribute("jumps")->value());
            }
            if (child->first_attribute("minJumps"))
            {
                def.minJumps = boost::lexical_cast<int>(child->first_attribute("minJumps")->value());
            }
            if (child->first_attribute("maxJumps"))
            {
                def.maxJumps = boost::lexical_cast<int>(child->first_attribute("maxJumps")->value());
            }
            customEvent->triggeredEventModifiers.push_back(def);
        }

        if (nodeName == "jumpEvent")
        {
            isDefault = false;
            customEvent->jumpEvent = child->value();
            if (child->first_attribute("loop"))
            {
                customEvent->jumpEventLoop = EventsParser::ParseBoolean(child->first_attribute("loop")->value());
            }
        }

        if (nodeName == "clearJumpEvent")
        {
            isDefault = false;
            customEvent->jumpEventClear = true;
        }

        if (nodeName == "invincible")
        {
            isDefault = false;
            customEvent->invincible = true;
        }

        if (nodeName == "deadCrewAuto")
        {
            isDefault = false;
            customEvent->deadCrewAuto = true;
        }
        if (nodeName == "finalBoss" || nodeName == "miniBoss")
        {
            isDefault = false;
            customEvent->finalBoss.enabled = true;
            customEvent->finalBoss.victory = (nodeName == "finalBoss");
            customEvent->finalBoss.sound = "victory";
            if (child->first_attribute("text"))
            {
                customEvent->finalBoss.text = child->first_attribute("text")->value();
            }
            if (child->first_attribute("creditsText"))
            {
                customEvent->finalBoss.creditsText = child->first_attribute("creditsText")->value();
            }
            if (child->first_attribute("creditsBackground"))
            {
                customEvent->finalBoss.creditsBackground = child->first_attribute("creditsBackground")->value();
            }
            if (child->first_attribute("music"))
            {
                customEvent->finalBoss.creditsMusic = child->first_attribute("music")->value();
            }
            if (child->first_attribute("sound"))
            {
                customEvent->finalBoss.sound = child->first_attribute("sound")->value();
            }
            if (child->first_attribute("musicDelay"))
            {
                customEvent->bossMusicDelay = boost::lexical_cast<int>(child->first_attribute("musicDelay")->value());
            }
        }
    }

    return isDefault;
}

bool CustomEventsParser::ParseCustomQuestNode(rapidxml::xml_node<char> *node, CustomQuest *quest)
{
    bool isDefault = true;

    for (auto child = node->first_node(); child; child = child->next_sibling())
    {
        std::string nodeName(child->name());
        if (nodeName == "nonNebulaBeacon")
        {
            isDefault = false;
            quest->nonNebulaBeacon = EventsParser::ParseBoolean(child->value());
        }

        if (nodeName == "nebulaBeacon")
        {
            isDefault = false;
            quest->nebulaBeacon = EventsParser::ParseBoolean(child->value());
        }

        if (nodeName == "createNebula")
        {
            isDefault = false;
            quest->createNebula = EventsParser::ParseBoolean(child->value());
        }

        if (nodeName == "nebulaEvent")
        {
            isDefault = false;
            quest->nebulaEvent = child->value();
        }

        if (nodeName == "currentSector")
        {
            isDefault = false;
            quest->currentSector = EventsParser::ParseBoolean(child->value());
        }

        if (nodeName == "nextSector")
        {
            isDefault = false;
            quest->nextSector = EventsParser::ParseBoolean(child->value());
        }

        if (nodeName == "aggressive")
        {
            isDefault = false;
            quest->aggressive = boost::lexical_cast<int>(child->value());
        }

        if (nodeName == "sectorEight")
        {
            isDefault = false;
            quest->sectorEight = EventsParser::ParseBoolean(child->value());
        }

        if (nodeName == "lastStand")
        {
            isDefault = false;
            quest->lastStand = EventsParser::ParseBoolean(child->value());
        }
    }
    return isDefault;
}

void CustomEventsParser::ParseCustomBeaconType(rapidxml::xml_node<char> *node, BeaconType *beaconType)
{
    beaconType->hideVanillaLabel = CustomOptionsManager::GetInstance()->defaults.beaconType_hideVanillaLabel;

    if (node->first_attribute("id"))
    {
        beaconType->beaconText.data = node->first_attribute("id")->value();
        beaconType->beaconText.isLiteral = false;
    }
    else if (node->first_attribute("text"))
    {
        beaconType->beaconText.data = node->first_attribute("text")->value();
        beaconType->beaconText.isLiteral = true;
    }
    if (node->first_attribute("req"))
    {
        beaconType->equipmentReq = node->first_attribute("req")->value();
    }

    if (node->first_attribute("global"))
    {
        beaconType->global = EventsParser::ParseBoolean(node->first_attribute("global")->value());
    }

    if (node->first_attribute("persist"))
    {
        beaconType->persistent = EventsParser::ParseBoolean(node->first_attribute("persist")->value());
    }

    if (node->first_attribute("hideVanillaLabel"))
    {
        beaconType->hideVanillaLabel = EventsParser::ParseBoolean(node->first_attribute("hideVanillaLabel")->value());
    }

    GL_Color color = GL_Color(255.f, 255.f, 255.f, 1.f);

    for (auto child = node->first_node(); child; child = child->next_sibling())
    {
        if (strcmp(child->name(), "unvisitedTooltip") == 0)
        {
            if (child->first_attribute("id"))
            {
                beaconType->unvisitedTooltip.data = child->first_attribute("id")->value();
                beaconType->unvisitedTooltip.isLiteral = false;
            }
            else
            {
                beaconType->unvisitedTooltip.data = child->value();
                beaconType->unvisitedTooltip.isLiteral = true;
            }
        }

        if (strcmp(child->name(), "visitedTooltip") == 0)
        {
            if (child->first_attribute("id"))
            {
                beaconType->visitedTooltip.data = child->first_attribute("id")->value();
                beaconType->visitedTooltip.isLiteral = false;
            }
            else
            {
                beaconType->visitedTooltip.data = child->value();
                beaconType->visitedTooltip.isLiteral = true;
            }
        }

        if (strcmp(child->name(), "undiscoveredTooltip") == 0)
        {
            if (child->first_attribute("id"))
            {
                beaconType->undiscoveredTooltip.data = child->first_attribute("id")->value();
                beaconType->undiscoveredTooltip.isLiteral = false;
            }
            else
            {
                beaconType->undiscoveredTooltip.data = child->value();
                beaconType->undiscoveredTooltip.isLiteral = true;
            }
        }

        if (strcmp(child->name(), "color") == 0)
        {
            ParseColorNode(color, child);
        }
    }

    beaconType->color = color;
}

void CustomEventsParser::ParseCustomReqNode(rapidxml::xml_node<char> *node, CustomReq *req)
{
    if (node->first_attribute("name"))
    {
        req->name = node->first_attribute("name")->value();
    }
    if (node->first_attribute("type"))
    {
        std::string reqtype = node->first_attribute("type")->value();
        boost::algorithm::to_lower(reqtype);
        if (reqtype == "any" || reqtype=="max")
        {
            req->type = CustomReq::TYPE_ANY;
        }
        else if (reqtype == "all" || reqtype=="min")
        {
            req->type = CustomReq::TYPE_ALL;
        }
        else if (reqtype == "sum" || reqtype=="count")
        {
            req->type = CustomReq::TYPE_SUM;
        }
        else
        {
            MessageBoxA(GetDesktopWindow(), ("Invalid Custom Req Type found: "+reqtype).c_str(), "Error", MB_ICONERROR | MB_SETFOREGROUND);
        }
    }
    if (node->first_attribute("lvl"))
    {
        req->lvl = boost::lexical_cast<int>(node->first_attribute("lvl")->value());
    }
    if (node->first_attribute("max_lvl"))
    {
        req->max_lvl = boost::lexical_cast<int>(node->first_attribute("max_lvl")->value());
    }
    if (node->first_attribute("mult"))
    {
        req->mult = boost::lexical_cast<int>(node->first_attribute("mult")->value());
    }
    if (node->first_attribute("const"))
    {
        req->constant = boost::lexical_cast<int>(node->first_attribute("const")->value());
    }
    if (node->first_attribute("load"))
    {
        BlueprintManager::GetBlueprintList(req->blueprints, G_->GetBlueprints(), node->first_attribute("load")->value());
    }
    for (auto child = node->first_node(); child; child = child->next_sibling())
    {
        std::string nodeName(child->name());
        if (nodeName == "name")
        {
            req->blueprints.push_back(child->value());
        }
        if (nodeName == "req")
        {
            req->children.emplace_back();
            ParseCustomReqNode(child, &(req->children.back()));
        }
    }
}

void CustomEventsParser::ParseCustomEventLoadList(rapidxml::xml_node<char> *node, EventLoadList *eventList, std::string& eventName)
{
    if (node->first_attribute("seeded"))
    {
        eventList->seeded = EventsParser::ParseBoolean(node->first_attribute("seeded")->value());
    }
    if (node->first_attribute("first"))
    {
        eventList->useFirst = EventsParser::ParseBoolean(node->first_attribute("first")->value());
    }
    if (node->first_attribute("default"))
    {
        eventList->defaultEvent = node->first_attribute("default")->value();
    }
    if (node->first_attribute("generate"))
    {
        eventList->onGenerate = EventsParser::ParseBoolean(node->first_attribute("generate")->value());
    }
    for (auto child = node->first_node(); child; child = child->next_sibling())
    {
        std::string nodeName(child->name());
        if (nodeName == "event")
        {
            EventLoadListEvent event;

            if (child->first_attribute("name"))
            {
                event.event = child->first_attribute("name")->value();
            }
            if (child->first_attribute("load"))
            {
                event.event = child->first_attribute("load")->value();
            }
            if (child->first_attribute("req"))
            {
                event.req = child->first_attribute("req")->value();
            }
            if (child->first_attribute("max_lvl"))
            {
                event.max_lvl = boost::lexical_cast<int>(child->first_attribute("max_lvl")->value());
                event.lvl = -2147483648;
            }
            if (child->first_attribute("lvl"))
            {
                event.lvl = boost::lexical_cast<int>(child->first_attribute("lvl")->value());
            }
            if (child->first_attribute("max_group"))
            {
                event.max_group = boost::lexical_cast<int>(child->first_attribute("max_group")->value());
            }

            if (event.event.empty())
            {
                std::string newEventName;
                EventsParser::ProcessEvent(newEventName, G_->GetEventsParser(), child, eventName);
                event.event = newEventName;
            }

            eventList->events.push_back(event);
        }
    }
}

CustomEvent *CustomEventsParser::GetCustomEvent(const std::string& event)
{
    auto it = customEvents.find(event);
    if (it != customEvents.end())
    {
        return it->second;
    }

    std::string baseEvent = CustomEventsParser::GetBaseEventName(event);

    it = customRecursiveEvents.find(baseEvent);
    if (it != customRecursiveEvents.end())
    {
        return it->second;
    }

    return nullptr;
}

CustomShipEvent *CustomEventsParser::GetCustomShipEvent(const std::string& event)
{
    auto it = customShipEvents.find(event);

    if (it != customShipEvents.end())
    {
        CustomShipEvent* customEvent = customShipEvents[event];
        return customEvent;
    }

    return nullptr;
}

CustomQuest *CustomEventsParser::GetCustomQuest(const std::string& event)
{
    auto it = customQuests.find(event);
    if (it != customQuests.end()) return it->second;
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

CustomReq *CustomEventsParser::GetCustomReq(const std::string& blueprint)
{
    auto it = customReqs.find(blueprint);

    if (it != customReqs.end())
    {
        return it->second;
    }

    return nullptr;
}

void CustomEventsParser::ParseVanillaEventNode(rapidxml::xml_node<char> *node, const std::string &eventName, const std::string &baseEventName)
{
    CustomEvent* customEvent;

    auto it = customEvents.find(eventName);
    if (it == customEvents.end())
    {
        customEvent = new CustomEvent();
        customEvent->eventName = eventName;
        customEvent->recursive = false;
        bool isDefault = ParseCustomEvent(node, customEvent, true);
        if (isDefault)
        {
            delete customEvent;
        }
        else
        {
            customEvents[eventName] = customEvent;
            vCustomEvents[baseEventName].push_back(customEvent);
        }
    }
    else
    {
        customEvent = it->second;
        *customEvent = CustomEvent(); // Reset the customEvent
        ParseCustomEvent(node, customEvent, true);
    }
}

void CustomEventsParser::ParseVanillaShipEventNode(rapidxml::xml_node<char> *node, const std::string &eventName)
{
    CustomShipEvent* customEvent;

    auto it = customShipEvents.find(eventName);
    if (it == customShipEvents.end())
    {
        customEvent = new CustomShipEvent();
        customEvent->eventName = eventName;
        bool isDefault = ParseCustomShipEvent(node, customEvent);
        if (isDefault)
        {
            delete customEvent;
        }
        else
        {
            customShipEvents[eventName] = customEvent;
        }
    }
    else
    {
        customEvent = it->second;
        *customEvent = CustomShipEvent(); // Reset the customEvent
        ParseCustomShipEvent(node, customEvent);
    }
}

HOOK_STATIC(EventsParser, ProcessEvent, (std::string &strRef, EventsParser *eventsParser, rapidxml::xml_node<char> *node, const std::string &eventName) -> void)
{
    super(strRef, eventsParser, node, eventName);
    if (!node->first_attribute("load"))
    {
        CustomEventsParser::GetInstance()->ParseVanillaEventNode(node, strRef, eventName);
    }
}

HOOK_STATIC(EventsParser, ProcessEventList, (std::vector<std::string> &vecRef, EventsParser *eventsParser, rapidxml::xml_node<char> *node, const std::string &listName) -> void)
{
    super(vecRef, eventsParser, node, listName);
    CustomEventsParser::GetInstance()->ParseVanillaEventNode(node, listName, listName);
}

HOOK_STATIC(EventsParser, ProcessShipEvent, (ShipTemplate &shipEvent, EventsParser *eventsParser, rapidxml::xml_node<char> *node) -> void)
{
    super(shipEvent, eventsParser, node);
    if (node->first_attribute("name"))
    {
        CustomEventsParser::GetInstance()->ParseVanillaShipEventNode(node, shipEvent.shipEventName);
    }
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

static bool advancedCheckEquipment = false;

HOOK_METHOD_PRIORITY(ShipObject, HasEquipment, -100, (const std::string& equipment) -> int)
{
    if (advancedCheckEquipment)
    {
        if (boost::algorithm::starts_with(equipment, "ANY "))
        {
            std::string child = equipment.substr(4);
            auto blueprintList = std::vector<std::string>();
            BlueprintManager::GetBlueprintList(blueprintList, G_->GetBlueprints(), child);
            if (!blueprintList.size()) blueprintList.push_back(child);
            return CustomReq::HasEquipment_Any(*(ShipObject*)this, blueprintList);
        }
        if (boost::algorithm::starts_with(equipment, "ALL "))
        {
            std::string child = equipment.substr(4);
            auto blueprintList = std::vector<std::string>();
            BlueprintManager::GetBlueprintList(blueprintList, G_->GetBlueprints(), child);
            if (!blueprintList.size()) blueprintList.push_back(child);
            return CustomReq::HasEquipment_All(*(ShipObject*)this, blueprintList);
        }
        if (boost::algorithm::starts_with(equipment, "SUM "))
        {
            std::string child = equipment.substr(4);
            auto blueprintList = std::vector<std::string>();
            BlueprintManager::GetBlueprintList(blueprintList, G_->GetBlueprints(), child);
            if (!blueprintList.size()) blueprintList.push_back(child);
            return CustomReq::HasEquipment_Sum(*(ShipObject*)this, blueprintList);
        }
        if (boost::algorithm::starts_with(equipment, "SEC "))
        {
            return G_->GetWorld()->starMap.currentSector->description.type == equipment.substr(4);
        }

        auto customReq = CustomEventsParser::GetInstance()->GetCustomReq(equipment);

        if (customReq != nullptr)
        {
            return customReq->HasEquipment(*(ShipObject*)this);
        }
    }

    return super(equipment);
}

static std::string removeHiddenAug = "";

HOOK_METHOD(WorldManager, CreateChoiceBox, (LocationEvent *event) -> void)
{
    auto customEvents = CustomEventsParser::GetInstance();

    if (customEvents->GetCustomEvent(event->eventName))
    {
        g_checkCargo = customEvents->GetCustomEvent(event->eventName)->checkCargo;
    }
    else
    {
        g_checkCargo = CustomOptionsManager::GetInstance()->defaults.checkCargo;
    }

    if (!event->stuff.removeItem.empty())
    {
        if (boost::algorithm::starts_with(event->stuff.removeItem, "HIDDEN "))
        {
            removeHiddenAug = event->stuff.removeItem;
            event->stuff.removeItem = "";
        }
    }

    advancedCheckEquipment = true;

    super(event);

    advancedCheckEquipment = false;

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
            CustomAugmentManager::GetInstance()->UpdateAugments(0);
        }
    }
    else
    {
        g_checkCargo = CustomOptionsManager::GetInstance()->defaults.checkCargo;
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

    // If we're generating a new sector then we should load the seeds from here.
    if (Global::lastDelayedQuestSeeds.size() > Global::delayedQuestIndex)
    {
        Global::questSeed = Global::lastDelayedQuestSeeds[Global::delayedQuestIndex++];
    }

    // Get the custom quest options (default and event-specific).
    CustomQuest quest = *(CustomEventsParser::GetInstance()->defaultQuest);
    CustomQuest *eventCustomQuest = CustomEventsParser::GetInstance()->GetCustomQuest(questEvent);
    if (eventCustomQuest) quest.add(eventCustomQuest);

    // Set dynamic defaults.
    if (!quest.createNebula.enabled)
    {
        quest.createNebula = quest.nonNebulaBeacon.value && quest.nebulaEvent.value.empty();
    }
    if (!quest.sectorEight.enabled)
    {
        quest.sectorEight = quest.lastStand.value;
    }

    // quest.sectorEight is forced true if infinite mode is on.
    if (bInfiniteMode)
    {
        quest.sectorEight = true;
    }

    questActuallyEnoughTime = false;
    questNextSectorPopped = false;
    locValues.clear();

    // Set the restricted beacons.
    for (auto i : locations)
    {
        locValues[i][0] = i->questLoc;
        locValues[i][1] = i->nebula;
        CustomEvent *customEvent = CustomEventsParser::GetInstance()->GetCustomEvent(i->event->eventName);

        if (i->nebula)
        {
            i->nebula = !quest.nebulaBeacon.value;
        }
        else
        {
            i->nebula = !quest.nonNebulaBeacon.value;
        }

        if (!quest.currentSector.value && !force)
        {
            i->nebula = true;
        }

        if (customEvent && customEvent->preventQuest)
        {
            i->nebula = true;
        }
    }

    // Override to allow quests to spawn in s8 and later.
    if (quest.sectorEight.value && (worldLevel > 5 || bossLevel))
    {
        worldLevel = 5;

        if (bInfiniteMode || quest.lastStand.value)
        {
            questActuallyEnoughTime = true;
        }
    }

    // Override for last stand.
    if (bossLevel) force = quest.lastStand.value;

    // Don't let quests spawn at beacons taken over or about to be taken over.
    if (force)
    {
        for (auto i : locations)
        {
            i->nebula = i->nebula || i->fleetChanging || i->dangerZone;
        }
    }

    // Seed the quest then try to spawn it normally.
    if (SeedInputBox::seedsEnabled) srandom32(Global::questSeed);
    bool ret = super(questEvent, force);
    if (SeedInputBox::seedsEnabled && !Global::delayedQuestIndex) nextQuestSeed = random32();

    // Don't let aggressive quests spawn at beacons taken over or about to be taken over.
    if (!ret && quest.aggressive.value)
    {
        for (auto i : locations)
        {
            i->nebula = i->nebula || i->fleetChanging || i->dangerZone;
        }
    }

    // aggressive == 2: Remove the quest from delayedQuests and try to spawn it again.
    if (!ret && (quest.aggressive.value == 2))
    {
        if (delayedQuests.size() > numDelayedQuests) delayedQuests.pop_back();

        if (SeedInputBox::seedsEnabled) srandom32(Global::questSeed);
        ret = super(questEvent, true);
        if (SeedInputBox::seedsEnabled && !Global::delayedQuestIndex) nextQuestSeed = random32();
    }

    // Remove the quest from delayedQuests if nextSector is false.
    if (!ret && !quest.nextSector.value && delayedQuests.size() > numDelayedQuests)
    {
        delayedQuests.pop_back();
        questNextSectorPopped = true;
    }

    // aggressive == 1: Try to spawn the quest again if it can't spawn in the next sector.
    if (!ret && (quest.aggressive.value == 1) && delayedQuests.size() == numDelayedQuests)
    {
        if (SeedInputBox::seedsEnabled) srandom32(Global::questSeed);
        ret = super(questEvent, true);
        if (SeedInputBox::seedsEnabled && !Global::delayedQuestIndex) nextQuestSeed = random32();
    }

    worldLevel = overrideWorldLevel;
    overrideWorldLevel = -1;

    // Reset restricted beacons.
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
                if (i->nebula)
                {
                    if (!quest.nebulaEvent.value.empty()) //replace event with nebula event
                    {
                        if (SeedInputBox::seedsEnabled) srandom32(Global::questSeed);
                        i->event = G_->GetEventGenerator()->GetBaseEvent(quest.nebulaEvent.value, worldLevel, false, -1);
                        if (addedQuests.size() > numAddedQuests) {
                            addedQuests[numAddedQuests].first = quest.nebulaEvent.value;
                        }
                    }
                    if (quest.createNebula.value) //add nebula environment
                    {
                        i->event->environment = 3;
                        i->event->statusEffects.push_back({2,7,0,2});
                    }
                }
                break;
            }
        }
    }

    // Override formatting for addedQuests vector to save the quest's seed.
    if (ret && addedQuests.size() > numAddedQuests)
    {
        addedQuests[numAddedQuests].first = "QUEST " + std::to_string(Global::questSeed) + " " + addedQuests[numAddedQuests].first;
    }

    // If the quest is delayed to the next sector, save the quest's seed.
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
    struct LocLabelValues
    {
        bool questLoc;
        bool beacon;
        bool repair;
        Store *pStore;
        bool store;
        bool distressBeacon;
    };
    std::unordered_map<Location*, LocLabelValues> locLabelValues = std::unordered_map<Location*, LocLabelValues>();

    CSurface::GL_PushMatrix();
    CSurface::GL_Translate(position.x, position.y, 0.f);
    CSurface::GL_Translate(translation.x, translation.y, 0.f);

    advancedCheckEquipment = true;

    if (!outOfFuel)
    {
        for (auto i : locations)
        {
            if (i->event == nullptr) continue;
            CustomEvent *customEvent = CustomEventsParser::GetInstance()->GetCustomEvent(i->event->eventName);

            bool hideVanillaLabel = (customEvent && customEvent->beacon && customEvent->beacon->hideVanillaLabel && (i->visited < 1 || customEvent->beacon->persistent));

            if (customEvent && customEvent->beacon && (i->visited < 1 || customEvent->beacon->persistent) && (bMapRevealed || customEvent->beacon->global || i->known))
            {
                BeaconType *beaconType = customEvent->beacon;

                if (beaconType->equipmentReq.empty() || (shipManager->HasEquipment(beaconType->equipmentReq) > 0) )
                {
                    hideVanillaLabel = true;

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

            if (hideVanillaLabel && (i->questLoc || i->beacon || i->event->repair || i->event->pStore || i->event->store || i->event->distressBeacon))
            {
                locLabelValues[i].questLoc = i->questLoc;
                locLabelValues[i].beacon = i->beacon;
                locLabelValues[i].repair = i->event->repair;
                locLabelValues[i].pStore = i->event->pStore;
                locLabelValues[i].store = i->event->store;
                locLabelValues[i].distressBeacon = i->event->distressBeacon;

                i->questLoc = false;
                i->beacon = false;
                i->event->repair = false;
                i->event->pStore = nullptr;
                i->event->store = false;
                i->event->distressBeacon = false;
            }
        }
    }

    CSurface::GL_PopMatrix();

    advancedCheckEquipment = false;

    super();

    for (auto i : locations)
    {
        if (i->fleetChanging && i->visited < 1 && i->event)
        {
            LocationEvent *locEvent = i->event;
            auto customEvent = CustomEventsParser::GetInstance()->GetCustomEvent(locEvent->eventName);
            if (customEvent && customEvent->preventFleet)
            {
                i->fleetChanging = false;
            }
        }
    }

    for (auto i : locLabelValues)
    {
        i.first->questLoc = i.second.questLoc;
        i.first->beacon = i.second.beacon;
        if (i.first->event != nullptr)
        {
            i.first->event->repair = i.second.repair;
            i.first->event->pStore = i.second.pStore;
            i.first->event->store = i.second.store;
            i.first->event->distressBeacon = i.second.distressBeacon;
        }
    }
}

static Location* originalExit = nullptr;

HOOK_METHOD(StarMap, GenerateMap, (bool tutorial, bool seed) -> LocationEvent*)
{
    originalExit = nullptr;

    if (!loadingGame)
    {
        regeneratedBeacons.clear();
        renamedBeacons.clear();
    }

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
                                    newEvent->statusEffects.push_back({2, 7, 0, 2});
                                }
                            }
                        }
                        if (customSector->noExit)
                        {
                            originalExit = i;
                            i->beacon = false;
                        }
                    }
                }

                if (customSector->nebulaSector.enabled)
                {
                    bNebulaMap = customSector->nebulaSector.value;
                }
            }
        }
    }

    if (!loadingGame)
    {
        auto custom = CustomEventsParser::GetInstance();

        for (int i=0; i<locations.size(); ++i)
        {
            Location *loc = locations[i];
            if (loc->event == nullptr) continue;

            auto customEvent = custom->GetCustomEvent(loc->event->eventName);
            if (customEvent && customEvent->eventLoadList && customEvent->eventLoadList->onGenerate)
            {
                int seed = customEvent->eventLoadList->seeded ? (int)(loc->loc.x + loc->loc.y) ^ currentSectorSeed : -1;
                auto newEvent = custom->GetEvent(G_->GetWorld(), customEvent->eventLoadList, seed);
                if (newEvent)
                {
                    //delete loc->event;
                    loc->event->ClearEvent(false);
                    loc->event = newEvent;
                    regeneratedBeacons[i] = std::pair<std::string,int>(newEvent->eventName, seed); // Note: doesn't respect nested "seeded" attributes in eventLoadLists.
                }
            }
        }
    }
    else
    {
        for (auto i : regeneratedBeacons)
        {
            if (i.first < locations.size() && !locations[i.first]->questLoc && !locations[i.first]->dangerZone) // currently don't operate on dives/quests
            {
                locations[i.first]->event = G_->GetEventGenerator()->GetBaseEvent(i.second.first, worldLevel, true, i.second.second);
            }
        }
    }

    for (auto i : renamedBeacons)
    {
        if (i.first < locations.size())
        {
            LocationEvent *event = locations[i.first]->event;
            if (event)
            {
                event->eventName = i.second;
            }
        }
    }

    return ret;
}

HOOK_METHOD_PRIORITY(StarMap, TurnIntoFleetLocation, 9999, (Location *loc) -> void)
{
    EventGenerator *eventGenerator = G_->GetEventGenerator();

    auto locEvent = loc->event;
    loc->dangerZone = true;
    loc->fleetChanging = false;

    if (locEvent)
    {
        locEvent->ClearEvent(false);
        std::string event;

        if ((loc->beacon || loc == originalExit) && !bossLevel)
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

        loc->event->fleetPosition = 1;
        loc->event->repair = false;

        if ((loc->beacon || loc == originalExit) && loc->nebula)
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
            if ((loc->beacon || loc == originalExit) && !customBeacon.rebelEvent.empty())
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
                        newEvent->statusEffects.push_back({2, 7, 0, 2});
                    }
                }
            }
        }
    }

    if (!(loc->beacon || loc == originalExit) || bossLevel)
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

    if (customEvent)
    {
        if (!customEvent->transformRace.second.empty() && G_->GetCrewFactory()->playerCrew > 0)
        {
            if (lastSelectedCrewSeed == -1) lastSelectedCrewSeed = random32();

            CrewBlueprint crewBlue;
            ShipManager::SelectRandomCrew(crewBlue, playerShip->shipManager, lastSelectedCrewSeed, customEvent->transformRace.first);

            CrewBlueprint* newBlueprint = G_->GetBlueprints()->GetCrewBlueprint(customEvent->transformRace.second);

            crewBlue.powers = newBlueprint->powers;
            crewBlue.name = newBlueprint->name;
            crewBlue.desc = newBlueprint->desc;
            crewBlue.type = newBlueprint->type;

            if (g_transformColorMode == TransformColorMode::KEEP_INDICES)
            {
                CrewMember_Extend::TransformColors(crewBlue, newBlueprint);
            }
            else
            {
                if (newBlueprint->colorLayers.size() < crewBlue.colorLayers.size()) crewBlue.colorLayers.resize(newBlueprint->colorLayers.size());
                if (newBlueprint->colorChoices.size() < crewBlue.colorChoices.size()) crewBlue.colorChoices.resize(newBlueprint->colorChoices.size());
            }

            delete newBlueprint;

            commandGui->choiceBox.rewards.crew = 1;
            commandGui->choiceBox.rewards.crewType = crewBlue.name;
            commandGui->choiceBox.rewards.crewBlue = crewBlue;
        }
    }
}

static std::string jumpEvent = "";
static bool jumpEventLoop = false;

void EventDamageEnemy(EventDamage eventDamage)
{
    ShipManager* enemyShip = G_->GetShipManager(1);
    if (enemyShip != nullptr)
    {
        if (enemyShip->bJumping) return;
        if (!(eventDamage.effect & 16)) enemyShip->DamageHull(eventDamage.amount,true);
        if (eventDamage.system == -1) return;
        int room = -1;
        if (eventDamage.system == 18)
        {
            ShipSystem* randomSystem = enemyShip->vSystemList[random32() % enemyShip->vSystemList.size()];
            room = randomSystem->GetRoomId();
        }
        else if (eventDamage.system == 19)
        {
            room = random32() % ShipGraph::GetShipInfo(1)->RoomCount();
        }
        else
        {
            room = enemyShip->GetSystemRoom(eventDamage.system);
        }
        if (room == -1) return;

        if (eventDamage.effect & 8)
        {
            ShipSystem* sys = enemyShip->GetSystemInRoom(room);
            if (sys)
            {
                sys->AddDamage(eventDamage.amount);
                DamageMessage *msg = new DamageMessage(1.f, eventDamage.amount, enemyShip->ship.GetRoomCenter(room), false);
                msg->color = GL_Color(1.f, 0.3921569f, 0.3921569f, 1.f);
                enemyShip->damMessages.push_back(msg);
            }
        }
        else
        {
            enemyShip->DamageSystem(room, DamageParameter{0, 0, 0, 0, 0, 0, eventDamage.amount, 0, false, -1, -1, false, 0});
        }

        if (eventDamage.effect & 4)
        {
            int effect = random32();
            if (effect&1)
            {
                enemyShip->StartFire(room);
            }
            else
            {
                enemyShip->ship.BreachRandomHull(room);
            }
        }
        else
        {
            if (eventDamage.effect&1) enemyShip->StartFire(room);
            if (eventDamage.effect&2) enemyShip->ship.BreachRandomHull(room);
        }
    }
}

void CustomCreateLocation(WorldManager* world, LocationEvent* event, CustomEvent* customEvent)
{
    for (auto& alias : customEvent->eventAlias)
    {
        if (alias.second.event.empty())
        {
            auto it = eventAliases.find(alias.first);
            if (it != eventAliases.end())
            {
                eventAliases.erase(it);
            }
        }
        else
        {
            eventAliases[alias.first] = alias.second;
        }
    }

    if (!customEvent->changeBackground.empty())
    {
        ImageDesc* image;

        image = world->space.SwitchBackground(customEvent->changeBackground);
        world->starMap.currentLoc->space = *image;
        delete image;

        world->starMap.currentLoc->spaceImage = customEvent->changeBackground;
    }

    if (!customEvent->enemyDamage.empty() && event->damage.empty())
    {
        G_->GetSoundControl()->PlaySoundMix("eventDamage", -1, false);
    }

    for (EventDamage& eventDamage: customEvent->enemyDamage)
    {
        EventDamageEnemy(eventDamage);
    }

    if (customEvent->instantEscape)
    {
        CompleteShip* enemyShip = world->playerShip->enemyShip;
        if (enemyShip != nullptr && !enemyShip->shipManager->bDestroyed)
        {
            enemyShip->shipAI.escaping = true;
            enemyShip->shipManager->JumpLeave();
        }
    }

    if (customEvent->escape)
    {
        CompleteShip* enemyShip = world->playerShip->enemyShip;
        if (enemyShip != nullptr && !enemyShip->shipManager->bDestroyed)
        {
            enemyShip->shipAI.escaping = true;
        }
    }

    if (customEvent->surrender)
    {
        CompleteShip* enemyShip = world->playerShip->enemyShip;
        if (enemyShip != nullptr && !enemyShip->shipManager->bDestroyed)
        {
            enemyShip->shipAI.surrendered = true;
        }
    }

    if (customEvent->loadEscape)
    {
        CompleteShip* enemyShip = world->playerShip->enemyShip;
        if (enemyShip != nullptr && (customEvent->loadEscapeForced || enemyShip->shipAI.escapeThreshold > 0))
        {
            enemyShip->shipAI.escapeThreshold = 2147483647;
        }
    }

    if (customEvent->loadSurrender)
    {
        CompleteShip* enemyShip = world->playerShip->enemyShip;
        if (enemyShip != nullptr && (customEvent->loadSurrenderForced || enemyShip->shipAI.surrenderThreshold > 0))
        {
            enemyShip->shipAI.surrenderThreshold = 2147483647;
        }
    }

    if (customEvent->disableEscape)
    {
        CompleteShip* enemyShip = world->playerShip->enemyShip;
        if (enemyShip != nullptr)
        {
            enemyShip->shipAI.escapeThreshold = 0;
            if (customEvent->disableEscapeForced)
            {
                enemyShip->shipAI.escaping = false;
            }
        }
    }

    if (customEvent->disableSurrender)
    {
        CompleteShip* enemyShip = world->playerShip->enemyShip;
        if (enemyShip != nullptr)
        {
            enemyShip->shipAI.surrenderThreshold = 0;
            if (customEvent->disableSurrenderForced)
            {
                enemyShip->shipAI.surrendered = false;
            }
        }
    }

    if (customEvent->superDrones != -1)
    {
        ShipManager* shipManager = G_->GetShipManager(customEvent->superDrones);
        if (shipManager != nullptr)
        {
            droneSurgeOverride = customEvent->superDronesName;
            shipManager->PrepareSuperDrones();
        }
    }

    if (customEvent->clearSuperDrones != -1)
    {
        ShipManager* shipManager = G_->GetShipManager(customEvent->clearSuperDrones);
        if (shipManager != nullptr)
        {
            /*
            for (auto i : shipManager->superDrones)
            {
                delete i;
            }
            */
            shipManager->superDrones.clear();
        }
    }

    if (customEvent->superBarrage != -1)
    {
        ShipManager* shipManager = G_->GetShipManager(customEvent->superBarrage);
        if (shipManager != nullptr)
        {
            barrageOverride = customEvent->superBarrageName;
            shipManager->PrepareSuperBarrage();
        }
    }

    if (customEvent->powerSuperShields != -1)
    {
        ShipManager* shipManager = G_->GetShipManager(customEvent->powerSuperShields);
        if (shipManager != nullptr)
        {
            Shields *shields = shipManager->shieldSystem;
            if (shields != nullptr)
            {
                if (customEvent->powerSuperShieldsSet > shields->shields.power.super.second)
                {
                    shields->shields.power.super.second = customEvent->powerSuperShieldsSet;
                }
                if (customEvent->powerSuperShieldsSet == -1)
                {
                    shields->shields.power.super.first = shields->shields.power.super.second;
                }
                else if (customEvent->powerSuperShieldsSet > shields->shields.power.super.first)
                {
                    shields->shields.power.super.first = customEvent->powerSuperShieldsSet;
                }
                shields->shields.power.super.first = std::min(shields->shields.power.super.second, shields->shields.power.super.first + customEvent->powerSuperShieldsAdd);
            }
        }
    }

    if (!customEvent->renameBeacon.empty())
    {
        world->starMap.currentLoc->event->eventName = customEvent->renameBeacon;
        auto it = std::find(world->starMap.locations.begin(), world->starMap.locations.end(), world->starMap.currentLoc);
        if (it != world->starMap.locations.end())
        {
            renamedBeacons[std::distance(world->starMap.locations.begin(), it)] = customEvent->renameBeacon;
        }
    }
}

LocationEvent* CustomEventsParser::GetEvent(WorldManager *world, EventLoadList *eventList, int seed)
{
    if (!eventList->seeded) seed = -1;

    ShipManager* player = G_->GetShipManager(0);
    std::unordered_set<int> used_groups;
    std::vector<LocationEvent*> candidateEvents;

    for (auto& event : eventList->events)
    {
        if (event.max_group != -1 && used_groups.count(event.max_group)) continue;

        if (!event.req.empty())
        {
            int result = player->HasEquipment(event.req);
            if (result < event.lvl || result > event.max_lvl) continue;
            if (event.max_group != -1) used_groups.insert(event.max_group);
        }

        LocationEvent* locEvent = GetEvent(world, event.event, seed);
        if (locEvent && world->CheckRequirements(locEvent))
        {
            if (eventList->useFirst) return locEvent;
            candidateEvents.push_back(locEvent);
        }
        else
        {
            locEvent->ClearEvent(false);
            //delete locEvent;
        }
    }

    if (candidateEvents.empty())
    {
        if (eventList->defaultEvent.empty()) return nullptr;
        return GetEvent(world, eventList->defaultEvent, seed);
    }
    if (candidateEvents.size() == 1) return candidateEvents[0];

    if (seed != -1) srandom32(seed);
    LocationEvent* ret = candidateEvents[random32()%candidateEvents.size()];
    for (LocationEvent* event : candidateEvents)
    {
        if (event != ret) event->ClearEvent(false);
    }

    return ret;
}

LocationEvent* CustomEventsParser::GetEvent(WorldManager *world, std::string eventName, int seed)
{
    auto it_alias = eventAliases.find(eventName);
    if (it_alias != eventAliases.end())
    {
        eventName = it_alias->second.event;
        if (it_alias->second.once)
        {
            eventAliases.erase(it_alias);
        }
    }
    auto it = customEventLoadLists.find(eventName);
    if (it != customEventLoadLists.end())
    {
        return GetEvent(world, it->second, seed);
    }
    return G_->GetEventGenerator()->GetBaseEvent(eventName, world->starMap.currentSector->level, true, seed);
}

void CustomEventsParser::LoadEvent(WorldManager *world, EventLoadList *eventList, int seed)
{
    LocationEvent *event = GetEvent(world, eventList, seed);
    if (event) world->UpdateLocation(event);
}

void CustomEventsParser::LoadEvent(WorldManager *world, std::string eventName, int seed)
{
    LocationEvent *event = GetEvent(world, eventName, seed);
    if (event) world->UpdateLocation(event);
}

HOOK_METHOD(WorldManager, CreateLocation, (Location *location) -> void)
{
    if (!loadingGame)
    {
        for (auto it = eventAliases.begin(); it != eventAliases.end(); )
        {
            if (it->second.jumpClear)
            {
                it = eventAliases.erase(it);
            }
            else
            {
                ++it;
            }
        }
    }

    bool needsBackground = location->space.tex == nullptr && location->planet.tex == nullptr;

    super(location);

    if (loadingGame) return;

    // Load correct federation base background if the boss got there first
    if (needsBackground && location->boss && location->beacon && location->event != nullptr)
    {
        ImageDesc* image;

        image = space.SwitchBackground(location->event->spaceImage);
        location->space = *image;
        delete image;

        image = space.SwitchPlanet(location->event->planetImage);
        location->planet = *image;
        delete image;

        location->spaceImage = location->event->spaceImage;
        location->planetImage = location->event->planetImage;
    }

    if (location->visited > 1 && !location->boss && !location->dangerZone)
    {
        std::string revisitEvent = CustomEventsParser::GetInstance()->defaultRevisit;
        bool revisitSeeded = CustomEventsParser::GetInstance()->defaultRevisitSeeded;

        auto loc = location->event;
        if (loc)
        {
            if (loc->ship.present && loc->ship.hostile) return; // left behind an enemy ship

            CustomEvent *customEvent = CustomEventsParser::GetInstance()->GetCustomEvent(loc->eventName);
            if (customEvent && !customEvent->eventRevisit.empty())
            {
                revisitEvent = customEvent->eventRevisit;
                revisitSeeded = customEvent->eventRevisitSeeded;
            }
        }

        CustomEvent *customEvent = CustomEventsParser::GetInstance()->GetCustomEvent(loc->eventName);
        if (!revisitEvent.empty())
        {
            int seed = revisitSeeded ? (int)(location->loc.x + location->loc.y) ^ (starMap.currentSectorSeed*location->visited + location->visited) : -1;
            CustomEventsParser::GetInstance()->LoadEvent(this, revisitEvent, seed);
        }
        return;
    }

    auto loc = location->event;
    if (!loc) return;

    CustomEvent *customEvent = CustomEventsParser::GetInstance()->GetCustomEvent(loc->eventName);

    if (customEvent)
    {
        CustomCreateLocation(this, loc, customEvent);

        if (customEvent->eventLoadList != nullptr)
        {
            int seed = customEvent->eventLoadList->seeded ? (int)(location->loc.x + location->loc.y) ^ starMap.currentSectorSeed : -1;
            CustomEventsParser::GetInstance()->LoadEvent(this, customEvent->eventLoadList, seed);
        }

        if (!customEvent->eventLoad.empty())
        {
            int seed = customEvent->eventLoadSeeded ? (int)(location->loc.x + location->loc.y) ^ starMap.currentSectorSeed : -1;
            CustomEventsParser::GetInstance()->LoadEvent(this, customEvent->eventLoad, seed);
        }

        if (!customEvent->secretSectorWarp.empty())
        {
            location->event->eventName = loc->eventName;
        }
    }
}

static bool g_noASBPlanet = false;

HOOK_METHOD(WorldManager, UpdateLocation, (LocationEvent *loc) -> void)
{
    CustomEvent *customEvent = CustomEventsParser::GetInstance()->GetCustomEvent(loc->eventName);

    if (!loadingGame)
    {
        lastSelectedCrewSeed = -1;
    }

    if (customEvent)
    {
        if (customEvent->noASBPlanet)
        {
            g_noASBPlanet = true;
        }
    }

    super(loc);

    if (customEvent)
    {
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

        if (customEvent->resetFtl)
        {
            playerShip->shipManager->jump_timer.first = 0.f;
        }

        CustomCreateLocation(this, loc, customEvent);

        if (customEvent->eventLoadList != nullptr)
        {
            int seed = customEvent->eventLoadList->seeded ? (int)(starMap.currentLoc->loc.x + starMap.currentLoc->loc.y) ^ starMap.currentSectorSeed : -1;
            CustomEventsParser::GetInstance()->LoadEvent(this, customEvent->eventLoadList, seed);
        }

        if (!customEvent->eventLoad.empty())
        {
            int seed = customEvent->eventLoadSeeded ? (int)(starMap.currentLoc->loc.x + starMap.currentLoc->loc.y) ^ starMap.currentSectorSeed : -1;
            CustomEventsParser::GetInstance()->LoadEvent(this, customEvent->eventLoad, seed);
        }

        if (customEvent->restartEvent)
        {
            super(starMap.currentLoc->event);
        }

        if (!customEvent->secretSectorWarp.empty())
        {
            starMap.currentLoc->event->eventName = loc->eventName;
        }
    }

    g_noASBPlanet = false;
}

HOOK_METHOD(WorldManager, CreateShip, (ShipEvent* shipEvent, bool boss) -> CompleteShip*)
{

    auto ret = super(shipEvent, boss);

    bossDefeated = false;

    if (loadingGame) return ret;

    CustomShipEvent *customEvent = CustomEventsParser::GetInstance()->GetCustomShipEvent(shipEvent->name);

    if (customEvent)
    {
        if (customEvent->jumpEventClear)
        {
            jumpEvent = "";
            jumpEventLoop = false;
        }

        if (!customEvent->jumpEvent.empty())
        {
            jumpEvent = customEvent->jumpEvent;
            jumpEventLoop = customEvent->jumpEventLoop;
        }

        for (auto& triggeredEvent: customEvent->clearTriggeredEvents)
        {
            TriggeredEvent::DestroyEvent(triggeredEvent);
        }

        for (auto& triggeredEvent: customEvent->triggeredEvents)
        {
            TriggeredEvent::NewEvent(&TriggeredEventDefinition::defs.at(triggeredEvent));
        }

        for (auto& triggeredEvent: customEvent->triggeredEventModifiers)
        {
            triggeredEvent.ApplyModifier();
        }

        if (customEvent->invincible)
        {
            ret->shipManager->bInvincible = true;
        }
    }

    return ret;
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
    // Close store window to prevent crashes.
    TabbedWindow& storeScreens = G_->GetWorld()->commandGui->storeScreens;
    if (storeScreens.currentTab >= 0 && storeScreens.currentTab < storeScreens.windows.size() && storeScreens.windows[storeScreens.currentTab])
    {
        storeScreens.Close();
    }
    storeScreens.bOpen = false;

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
    pursuitDelay = 0;
    reversedPath = false;

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
std::string replaceCreditsMusic = "";

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
            if (customEvent->gameOver.victory)
            {
                G_->GetSoundControl()->StopPlaylist(100);
                if (!customEvent->gameOver.sound.empty())
                {
                    G_->GetSoundControl()->PlaySoundMix(customEvent->gameOver.sound, -1.f, false);
                }
                replaceGameOverText = customEvent->gameOver.text;
                replaceGameOverCreditsText = customEvent->gameOver.creditsText;
                replaceCreditsBackground = G_->GetEventGenerator()->GetImageFromList(customEvent->gameOver.creditsBackground);
                replaceCreditsMusic = customEvent->gameOver.creditsMusic;

                G_->GetScoreKeeper()->SetVictory(true);
                commandGui->gameover = true;
                commandGui->Victory();

                replaceGameOverText = "";
            }
            else
            {
                if (!customEvent->gameOver.sound.empty())
                {
                    G_->GetSoundControl()->StopPlaylist(100);
                    G_->GetSoundControl()->PlaySoundMix(customEvent->gameOver.sound, -1.f, false);
                }
                replaceGameOverText = customEvent->gameOver.text;

                G_->GetScoreKeeper()->SetVictory(false);
                commandGui->gameover = true;
                commandGui->CheckGameover();

                replaceGameOverText = "";
            }
        }

        if (!customEvent->playSound.empty())
        {
            G_->GetSoundControl()->PlaySoundMix(customEvent->playSound, -1.f, false);
        }

        if (customEvent->resetMusic)
        {
            G_->GetSoundControl()->StartPlaylist(starMap.currentSector->description.musicTracks);
        }

        if (!customEvent->playMusic.empty())
        {
            std::vector<std::string> track = {customEvent->playMusic};
            G_->GetSoundControl()->StartPlaylist(track);
        }

        if (customEvent->jumpEventClear)
        {
            jumpEvent = "";
            jumpEventLoop = false;
        }

        if (!customEvent->jumpEvent.empty())
        {
            jumpEvent = customEvent->jumpEvent;
            jumpEventLoop = customEvent->jumpEventLoop;
        }

        if (customEvent->goToFlagship)
        {
            GoToFlagship(customEvent->goToFlagshipBase, customEvent->goToFlagshipFleet);
        }

        if (!customEvent->transformRace.second.empty() && G_->GetCrewFactory()->playerCrew > 0)
        {
            if (lastSelectedCrewSeed == -1) lastSelectedCrewSeed = random32();

            CrewBlueprint crewBlue;
            ShipManager::SelectRandomCrew(crewBlue, playerShip->shipManager, lastSelectedCrewSeed, customEvent->transformRace.first);

            // Select the race now for consistent seeding with the event box generation.
            CrewBlueprint* newBlueprint = G_->GetBlueprints()->GetCrewBlueprint(customEvent->transformRace.second);
            std::string newSpecies = newBlueprint->name;
            delete newBlueprint;

            CrewMember* crew = playerShip->shipManager->FindCrew(&crewBlue);
            if (crew != nullptr)
            {
                auto ex = CM_EX(crew);
                ex->TransformRace(newSpecies);
            }
        }

        for (auto& triggeredEvent: customEvent->clearTriggeredEvents)
        {
            TriggeredEvent::DestroyEvent(triggeredEvent);
        }

        for (auto& triggeredEvent: customEvent->triggeredEvents)
        {
            TriggeredEvent::NewEvent(&TriggeredEventDefinition::defs.at(triggeredEvent));
        }

        for (auto& triggeredEvent: customEvent->triggeredEventModifiers)
        {
            triggeredEvent.ApplyModifier();
        }

        if (!customEvent->replaceSector.targetSector.empty())
        {
            ReplaceSector(customEvent->replaceSector);
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

HOOK_METHOD(StarMap, NewGame, (bool unk) -> Location*)
{
    bossDefeated = false;
    delete restartMusicTimer;
    restartMusicTimer = nullptr;

    // jumpEvent
    jumpEvent = "";
    jumpEventLoop = false;

    // eventAlias
    eventAliases.clear();

    // regeneratedBeacons
    regeneratedBeacons.clear();

    // renamedBeacons
    renamedBeacons.clear();

    // Game Over
    G_->GetWorld()->commandGui->alreadyWon = false;
    alreadyWonCustom = false;
    replaceGameOverText = "";
    replaceGameOverCreditsText = "";
    replaceCreditsBackground = "";
    replaceCreditsMusic = "";

    return super(unk);
}

HOOK_METHOD(StarMap, LoadGame, (int fh) -> Location*)
{
    bossDefeated = false;
    delete restartMusicTimer;
    restartMusicTimer = nullptr;

    // jumpEvent
    jumpEvent = FileHelper::readString(fh);
    jumpEventLoop = FileHelper::readInteger(fh);

    // eventAlias
    eventAliases.clear();
    int n = FileHelper::readInteger(fh);
    for (int i=0; i<n; ++i)
    {
        std::string alias_name = FileHelper::readString(fh);
        EventAlias alias;
        alias.event = FileHelper::readString(fh);
        alias.jumpClear = FileHelper::readInteger(fh);
        alias.once = FileHelper::readInteger(fh);
        eventAliases[alias_name] = alias;
    }

    // regeneratedBeacons
    regeneratedBeacons.clear();
    n = FileHelper::readInteger(fh);
    for (int i=0; i<n; ++i)
    {
        int idx = FileHelper::readInteger(fh);
        std::string eventName = FileHelper::readString(fh);
        int seed = FileHelper::readInteger(fh);
        regeneratedBeacons[idx] = std::pair<std::string,int>(eventName, seed);
    }

    // renamedBeacons
    renamedBeacons.clear();
    n = FileHelper::readInteger(fh);
    for (int i=0; i<n; ++i)
    {
        int idx = FileHelper::readInteger(fh);
        renamedBeacons[idx] = FileHelper::readString(fh);
    }

    // Game Over
    G_->GetWorld()->commandGui->alreadyWon = FileHelper::readInteger(fh);
    alreadyWonCustom = FileHelper::readInteger(fh);
    replaceGameOverText = FileHelper::readString(fh);
    replaceGameOverCreditsText = FileHelper::readString(fh);
    replaceCreditsBackground = FileHelper::readString(fh);
    replaceCreditsMusic = FileHelper::readString(fh);

    return super(fh);
}

HOOK_METHOD(StarMap, SaveGame, (int file) -> void)
{
    // jumpEvent
    FileHelper::writeString(file, jumpEvent);
    FileHelper::writeInt(file, jumpEventLoop);

    // eventAlias
    FileHelper::writeInt(file, eventAliases.size());
    for (auto& i : eventAliases)
    {
        FileHelper::writeString(file, i.first);
        FileHelper::writeString(file, i.second.event);
        FileHelper::writeInt(file, i.second.jumpClear);
        FileHelper::writeInt(file, i.second.once);
    }

    // regeneratedBeacons
    FileHelper::writeInt(file, regeneratedBeacons.size());
    for (auto& i : regeneratedBeacons)
    {
        FileHelper::writeInt(file, i.first);
        FileHelper::writeString(file, i.second.first);
        FileHelper::writeInt(file, i.second.second);
    }

    // renamedBeacons
    FileHelper::writeInt(file, renamedBeacons.size());
    for (auto& i : renamedBeacons)
    {
        FileHelper::writeInt(file, i.first);
        if (i.first < locations.size() && locations[i.first]->event)
        {
            FileHelper::writeString(file, locations[i.first]->event->eventName);
        }
        else
        {
            FileHelper::writeString(file, i.second);
        }
    }

    // Game Over
    FileHelper::writeInt(file, G_->GetWorld()->commandGui->alreadyWon);
    FileHelper::writeInt(file, alreadyWonCustom);
    FileHelper::writeString(file, replaceGameOverText);
    FileHelper::writeString(file, replaceGameOverCreditsText);
    FileHelper::writeString(file, replaceCreditsBackground);
    FileHelper::writeString(file, replaceCreditsMusic);

    return super(file);
}

HOOK_METHOD(StarMap, Open, () -> void)
{
    if (!jumpEvent.empty())
    {
        LocationEvent* event = G_->GetEventGenerator()->GetBaseEvent(jumpEvent, currentSector->level, true, -1);
        if (!jumpEventLoop) jumpEvent = "";
        G_->GetWorld()->UpdateLocation(event);
        return;
    }

    super();
}

HOOK_METHOD_PRIORITY(StarMap, Open, 9999, () -> void)
{
    if (!bOpen)
    {
        closeButton.SetActive(true);

        finalSectorChoice = -1;
        potentialSectorChoice = -1;

        int rng = random32();
        shipRotation[0] = rng % 360;
        rng = random32();
        shipRotation[1] = rng % 360;

        if (shipManager->fuel_count == 0)
        {
            hoverLoc = nullptr;
        }
        else
        {
            hoverLoc = currentLoc;
            targetBoxTimer.Start(0.f);
        }
        potentialLoc = nullptr;

        bOpen = true;
    }

    return;
}

static BossFleetPrevention bossFleetPrevention = BossFleetPrevention();
static bool inUpdateBoss = false;

HOOK_METHOD(StarMap, UpdateBoss, () -> void)
{
    inUpdateBoss = true;

    bossFleetPrevention.starMap = this;
    bossFleetPrevention.Set();

    super();

    bossFleetPrevention.Clear();

    inUpdateBoss = false;
}

HOOK_METHOD(StarMap, GenerateMap, (bool unk, bool seed) -> Location*)
{
    auto ret = super(unk, seed);

    if (!loadingMap)
    {
        for (auto i : locations)
        {
            if (!i->dangerZone && i->fleetChanging)
            {
                auto locEvent = i->event;
                auto customEvents = CustomEventsParser::GetInstance();
                auto customEvent = customEvents->GetCustomEvent(locEvent->eventName);

                if (customEvent && customEvent->preventBossFleet)
                {
                    i->fleetChanging = false;
                }
            }
        }
    }

    return ret;
}

HOOK_METHOD(StarMap, TurnIntoFleetLocation, (Location *loc) -> void)
{
    auto locEvent = loc->event;
    auto customEvents = CustomEventsParser::GetInstance();
    auto customEvent = customEvents->GetCustomEvent(locEvent->eventName);

    if (customEvent && customEvent->preventFleet && loc->visited < 1) return;

    if (!loadingMap) {
        if (!loc->visited && customEvent && customEvent->runFromFleet)
        {
            bool requireClosest = customEvent->runFromFleet == 1;
            int closestDistance = 9999;

            auto allowedDestinations = std::vector<Location*>();
            auto path = std::vector<Location*>();

            for (auto i : locations)
            {
                if (!i->beacon && !i->visited && (!i->dangerZone || bossFleetPrevention.fleetBlockedLocs.count(i)) && !i->newSector && !i->questLoc && !i->fleetChanging && i->nebula == loc->nebula && i != currentLoc && i != potentialLoc && !i->event->store && !i->event->repair)
                {
                    auto destinationEvent = customEvents->GetCustomEvent(i->event->eventName);

                    if (!(destinationEvent && destinationEvent->preventQuest))
                    {
                        if (requireClosest)
                        {
                            path.clear();
                            Dijkstra0(path, this, loc, i);
                            if (path.size() < closestDistance)
                            {
                                allowedDestinations.clear();
                                closestDistance = path.size();
                            }
                            if (path.size() <= closestDistance)
                            {
                                allowedDestinations.push_back(i);
                            }
                        }
                        else
                        {
                            allowedDestinations.push_back(i);
                        }
                    }
                }
            }
            if (allowedDestinations.size())
            {
                loc->questLoc = false;

                auto dest = allowedDestinations[random32()%allowedDestinations.size()];
                unsigned int seed = random32();
                dest->event = G_->GetEventGenerator()->GetBaseEvent(locEvent->eventName, worldLevel, true, seed);
                dest->questLoc = true;
                dest->visited = 0;

                if (inUpdateBoss)
                {
                    bossFleetPrevention.Clear();
                    bossFleetPrevention.Set();
                }

                auto destIt = std::find(locations.begin(), locations.end(), dest);
                addedQuests.push_back({"QUEST " + std::to_string(seed) + " " + locEvent->eventName, std::distance(locations.begin(), destIt)});
            }
        }
    }

    super(loc);
}

HOOK_STATIC_PRIORITY(ShipManager, SelectRandomCrew, 100, (CrewBlueprint &bp, ShipManager *ship, int seed, const std::string &unk) -> CrewBlueprint*)
{
    std::string species = unk;
    super(bp, ship, seed, species); // species is not const?!

    species = unk;

    auto blueprintList = std::vector<std::string>();
    auto blueprintList2 = std::vector<std::string>();

    BlueprintManager::GetBlueprintList(blueprintList, G_->GetBlueprints(), species);

    for (int i=0; i<blueprintList.size(); ++i)
    {
        BlueprintManager::GetBlueprintList(blueprintList2, G_->GetBlueprints(), blueprintList[i]);
        for (auto j : blueprintList2)
        {
            blueprintList.push_back(j);
        }
    }

    if (!blueprintList.size()) return &bp;

    if (seed != -1) srandom32(seed);

    auto eligibleCrewList = std::vector<CrewMember*>();
    auto crewList = std::vector<CrewMember*>();
    G_->GetCrewFactory()->GetCrewList(&crewList, 0, false);

    for (auto crew: crewList)
    {
        if (!crew->IsDrone())
        {
            for (auto i : blueprintList)
            {
                if (crew->species == i)
                {
                    eligibleCrewList.push_back(crew);
                    break;
                }
            }
        }
    }

    if (eligibleCrewList.size())
    {
        bp = eligibleCrewList[((unsigned int)random32()) % eligibleCrewList.size()]->blueprint;
    }

    return &bp;
}

HOOK_STATIC(ShipManager, SelectRandomCrew, (CrewBlueprint &bp, ShipManager *ship, int seed, const std::string &unk) -> CrewBlueprint*)
{
    if (ship->CountCrew(false) == 0 && ship->bAutomated)
    {
        CrewMember* crew;
        crew = ship->AddCrewMemberFromString(G_->GetTextLibrary()->GetText("autoship_dismissed_crew_name"), "human", false, 0, false, false);
        super(bp, ship, seed, unk);
    }
    else
    {
        super(bp, ship, seed, unk);
    }
}

HOOK_METHOD_PRIORITY(ShipManager, FindCrew, 9999, (const CrewBlueprint* bp) -> CrewMember*)
{
    std::vector<CrewMember*> crewList = std::vector<CrewMember*>();
    G_->GetCrewFactory()->GetCrewList(&crewList, 0, false);

    for (CrewMember* crew: crewList)
    {
        if (crew->blueprint.crewNameLong.isLiteral != bp->crewNameLong.isLiteral) continue;
        if (crew->blueprint.crewNameLong.data != bp->crewNameLong.data) continue;
        if (crew->blueprint.colorChoices.size() != bp->colorChoices.size()) continue;
        for (unsigned int i=0; i<bp->colorChoices.size(); ++i)
        {
            if (crew->blueprint.colorChoices[i] != bp->colorChoices[i]) goto ShipManager__FindCrew__continue_crewList_loop;
        }
        if (crew->blueprint.male != bp->male) continue;
        if (crew->blueprint.name != bp->name) continue;
        return crew;
        ShipManager__FindCrew__continue_crewList_loop:
        ;
    }

    return nullptr;
}

HOOK_METHOD(ShipObject, HasEquipment, (const std::string& name) -> int)
{
    if (name == "difficulty")
    {
        return *G_->difficulty;
    }

    return super(name);
}

void GoToFlagship(bool atBase, bool allFleet)
{
    StarMap& starMap = G_->GetWorld()->starMap;

    if (!starMap.bossLevel) return;

    // Advance Flagship to base.
    if (atBase && !starMap.boss_path[starMap.bossLoc]->beacon)
    {
        Location* base = nullptr;
        unsigned int bossLoc;
        for (bossLoc=0; bossLoc<starMap.boss_path.size(); ++bossLoc)
        {
            if (starMap.boss_path[bossLoc]->beacon)
            {
                base = starMap.boss_path[bossLoc];
                break;
            }
        }

        if (base != nullptr)
        {
            starMap.boss_path[starMap.bossLoc]->boss = false;

            starMap.bossJumping = false;
            starMap.arrivedAtBase = 3;
            starMap.bossLoc = bossLoc;
            base->boss = true;
            LocationEvent* baseEvent = base->event;
            if (baseEvent != nullptr)
            {
                baseEvent->pStore = nullptr;
                baseEvent->store = false;
                baseEvent->repair = false;
                baseEvent->distressBeacon = false;
            }
            starMap.bossPosition = base->loc;
        }
    }

    // Fleet overtakes entire sector (except base).
    if (allFleet)
    {
        for (Location* loc : starMap.locations)
        {
            if (!loc->beacon)
            {
                starMap.TurnIntoFleetLocation(loc);
            }
        }
    }

    Location* dest = starMap.boss_path[starMap.bossLoc];
    if (starMap.bossJumping && starMap.bossLoc+1 < starMap.boss_path.size())
    {
        dest = starMap.boss_path[starMap.bossLoc + 1];
    }

    CommandGui* commandGui = G_->GetWorld()->commandGui;

    starMap.potentialLoc = dest;
    starMap.readyToTravel = true;
    starMap.outOfFuel = false;
    commandGui->waitLocation = false;
}

HOOK_METHOD(CompleteShip, DeadCrew, () -> bool)
{
    bool ret = super();

    if (ret && !bPlayerShip)
    {
        ShipEvent& event = G_->GetWorld()->currentShipEvent;

        CustomShipEvent *customEvent = CustomEventsParser::GetInstance()->GetCustomShipEvent(event.name);
        if (customEvent)
        {
            if (customEvent->deadCrewAuto)
            {
                shipManager->bAutomated = true;
                eventQueue.push_back({event.deadCrew, event.shipSeed});
                return false;
            }

            if (customEvent->finalBoss.enabled && !bossDefeated)
            {
                bossDefeated = true;

                CommandGui* commandGui = G_->GetWorld()->commandGui;

                if (!customEvent->finalBoss.sound.empty())
                {
                    G_->GetSoundControl()->StopPlaylist(100);
                    G_->GetSoundControl()->PlaySoundMix(customEvent->finalBoss.sound, -1.f, false);

                    delete restartMusicTimer;
                    if (customEvent->bossMusicDelay != -1)
                    {
                        restartMusicTimer = new TimerHelper(false);
                        restartMusicTimer->Start(customEvent->bossMusicDelay);
                    }
                }

                if (customEvent->finalBoss.victory)
                {
                    commandGui->alreadyWon = true;
                    alreadyWonCustom = true;
                    replaceGameOverText = customEvent->finalBoss.text;
                    replaceGameOverCreditsText = customEvent->finalBoss.creditsText;
                    replaceCreditsMusic = customEvent->finalBoss.creditsMusic;
                    replaceCreditsBackground = G_->GetEventGenerator()->GetImageFromList(customEvent->finalBoss.creditsBackground);
                }
            }
        }
    }

    return ret;
}

HOOK_METHOD(WorldManager, OnLoop, () -> void)
{
    super();

    if (!playerShip) return;

    if (alreadyWonCustom && commandGui->alreadyWon)
    {
        if (playerShip->DeadCrew() || (playerShip->shipManager->bDestroyed && playerShip->shipManager->ship.explosion.done))
        {
            ShipManager *enemy = playerShip->shipManager->current_target;
            if (!enemy || !enemy->bDestroyed || enemy->ship.explosion.done)
            {
                G_->GetSoundControl()->StopPlaylist(100);
                G_->GetScoreKeeper()->SetVictory(true);
                commandGui->gameover = true;
                commandGui->Victory();
                replaceGameOverText = "";
            }
        }
    }
    if (!bossDefeated)
    {
        ShipManager *enemy = playerShip->shipManager->current_target;
        if (!enemy) return;

        CustomShipEvent *customEvent = CustomEventsParser::GetInstance()->GetCustomShipEvent(currentShipEvent.name);
        if (customEvent && customEvent->finalBoss.enabled && enemy->bDestroyed)
        {
            bossDefeated = true;
            enemy->ship.explosion.time = 6.0;

            if (!customEvent->finalBoss.sound.empty())
            {
                G_->GetSoundControl()->StopPlaylist(100);
                G_->GetSoundControl()->PlaySoundMix(customEvent->finalBoss.sound, -1.f, false);

                delete restartMusicTimer;
                if (customEvent->bossMusicDelay != -1)
                {
                    restartMusicTimer = new TimerHelper(false);
                    restartMusicTimer->Start(customEvent->bossMusicDelay);
                }
            }

            if (customEvent->finalBoss.victory)
            {
                commandGui->alreadyWon = true;
                alreadyWonCustom = true;
                replaceGameOverText = customEvent->finalBoss.text;
                replaceGameOverCreditsText = customEvent->finalBoss.creditsText;
                replaceCreditsMusic = customEvent->finalBoss.creditsMusic;
                replaceCreditsBackground = G_->GetEventGenerator()->GetImageFromList(customEvent->finalBoss.creditsBackground);
            }

            commandGui->alreadyWon = true;
            alreadyWonCustom = true;
        }
    }
}

HOOK_METHOD(CApp, OnLoop, () -> void)
{
    super();
    if (restartMusicTimer != nullptr)
    {
        restartMusicTimer->Update();
        if (restartMusicTimer->Done())
        {
            delete restartMusicTimer;
            restartMusicTimer = nullptr;

            if (!menu.bOpen)
            {
                Sector *sec = G_->GetWorld()->starMap.currentSector;
                if (sec != nullptr)
                {
                    G_->GetSoundControl()->StartPlaylist(sec->description.musicTracks);
                }
            }
        }
    }
}


HOOK_METHOD(SpaceManager, SetPlanetaryDefense, (bool state, int target) -> void)
{
    bool dangerSet = false;
    if (g_noASBPlanet && !dangerZone)
    {
        dangerSet = true;
        dangerZone = true;
    }

    super(state, target);

    if (dangerSet)
    {
        dangerZone = false;
    }
}
