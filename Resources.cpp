#include "rapidxml.hpp"
#include "Resources.h"
#include "CustomOptions.h"

#include "HullNumbers.h"
#include "CommandConsole.h"
#include "CustomShipSelect.h"
#include "CustomCrew.h"
#include "CustomEvents.h"
#include "CustomRewards.h"
#include "CustomSectors.h"
#include "EventTooltip.h"
#include "CooldownNumbers.h"
#include "CustomAugments.h"
#include "Infinite.h"
#include "Balance.h"
#include "MainMenu.h"
#include "CustomBoss.h"
#include "CustomStore.h"
#include "DiscordIntegration.h"
#include "CustomDrones.h"
#include "Seeds.h"
#include "SaveFile.h"
#include "CustomSystems.h"
#include "AlternateOxygenRendering.h"
#include "CustomColors.h"
#include "CustomShips.h"
#include "CustomCrystalShard.h"
#include "CustomShipGenerator.h"
#include "ShipUnlocks.h"
#include "CustomAchievements.h"

#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string/replace.hpp>

GL_Color& ParseColorNode(GL_Color& colorRef, rapidxml::xml_node<char>* node, bool divide)
{
    if (node->first_attribute("r")) { colorRef.r = boost::lexical_cast<float>(node->first_attribute("r")->value()) / (divide ? 255.f : 1.f); }
    if (node->first_attribute("g")) { colorRef.g = boost::lexical_cast<float>(node->first_attribute("g")->value()) / (divide ? 255.f : 1.f); }
    if (node->first_attribute("b")) { colorRef.b = boost::lexical_cast<float>(node->first_attribute("b")->value()) / (divide ? 255.f : 1.f); }
    if (node->first_attribute("a")) { colorRef.a = boost::lexical_cast<float>(node->first_attribute("a")->value()); }

    return colorRef;
}

HOOK_METHOD(ResourceControl, PreloadResources, (bool unk) -> bool)
{
    bool ret = super(unk);
    if (ret && G_)
    {
        G_->PreInitializeResources(this);
    }
    return ret;
}

HOOK_METHOD(AchievementTracker, LoadAchievementDescriptions, () -> void)
{
    if (G_ && !G_->AreResourcesInitialized())
    {
        G_->InitializeResources(G_->GetResources());
    }

    super();
}


// hyperspace.xml parsing
void Global::PreInitializeResources(ResourceControl *resources)
{
    char *hyperspacetext = resources->LoadFile("data/hyperspace.xml");

    try
    {
        if (!hyperspacetext)
        {
            __resourcesInitialized = true; // skip main pass
            throw "hyperspace.xml not found";
        }

        rapidxml::xml_document<> doc;
        doc.parse<0>(hyperspacetext);

        auto parentNode = doc.first_node("FTL");
        if (!parentNode)
        {
            __resourcesInitialized = true; // skip main pass
            throw "No parent node found in hyperspace.xml";
        }

        for (auto node = parentNode->first_node(); node; node = node->next_sibling())
        {
            if (strcmp(node->name(), "ships") == 0)
            {
                auto customShipManager = CustomShipSelect::GetInstance();
                customShipManager->EarlyParseShipsNode(node);
            }
        }

        doc.clear();
    }
    catch (rapidxml::parse_error& e)
    {
        std::string msg = std::string("Failed parsing hyperspace.xml\n") + std::string(e.what());
        MessageBoxA(GetDesktopWindow(), msg.c_str(), "Error", MB_ICONERROR | MB_SETFOREGROUND);
    }
    catch (std::exception &e)
    {
        std::string msg = std::string("Failed parsing hyperspace.xml\n") + std::string(e.what());
        MessageBoxA(GetDesktopWindow(), msg.c_str(), "Error", MB_ICONERROR | MB_SETFOREGROUND);
    }
    catch (const char* e)
    {
        MessageBoxA(GetDesktopWindow(), e, "Error", MB_ICONERROR | MB_SETFOREGROUND);
    }
}

void Global::InitializeResources(ResourceControl *resources)
{
    __resourcesInitialized = true;

    char *hyperspacetext = resources->LoadFile("data/hyperspace.xml");

    auto customOptions = CustomOptionsManager::GetInstance();

    try
    {
        if (!hyperspacetext)
        {
            throw "hyperspace.xml not found";
        }

        rapidxml::xml_document<> doc;
        doc.parse<0>(hyperspacetext);

        auto parentNode = doc.first_node("FTL");
        if (!parentNode)
            throw "No parent node found in hyperspace.xml";

        bool checkedVersion = false;

        std::string discordModName = "";

        // First Pass
        for (auto node = parentNode->first_node(); node; node = node->next_sibling())
        {
            if (strcmp(node->name(), "version") == 0)
            {
                checkedVersion = boost::lexical_cast<int>(node->value()) == G_->GetVersion();
            }
            if (strcmp(node->name(), "hullNumbers") == 0)
            {
                if (node->first_attribute("enabled"))
                {
                    auto enabled = node->first_attribute("enabled")->value();

                    if (EventsParser::ParseBoolean(enabled))
                    {
                        auto hullManager = HullNumbers::GetInstance();
                        hullManager->enabled = true;
                        hullManager->ParseHullNumbersNode(node);
                    }
                }
            }

            if (strcmp(node->name(), "hackingDroneFix") == 0)
            {
                auto enabled = node->first_attribute("enabled")->value();
                g_hackingDroneFix = EventsParser::ParseBoolean(enabled);
            }

            if (strcmp(node->name(), "enemyPreigniterFix") == 0) // enables enemies to have their weapons enabled and preignited
            {
                auto enabled = node->first_attribute("enabled")->value();
                g_enemyPreigniterFix = EventsParser::ParseBoolean(enabled);
            }

            if (strcmp(node->name(), "crystalShardFix") == 0) // fixes crystal shards being targeted by friendly defense drones; default true
            {
                auto enabled = node->first_attribute("enabled")->value();
                g_crystalShardFix = EventsParser::ParseBoolean(enabled);
            }

            if (strcmp(node->name(), "defenseDroneFix") == 0) // fixes defense drone blind spot by making the visible area resize with the ship
            {
                auto enabled = node->first_attribute("enabled")->value();
                g_defenseDroneFix = EventsParser::ParseBoolean(enabled);
                if (g_defenseDroneFix)
                {
                    for (auto child = node->first_node(); child; child = child->next_sibling())
                    {
                        if (strcmp(child->name(), "boxRange") == 0)
                        {
                            if (child->value())
                            {
                                g_defenseDroneFix_BoxRange[0] = boost::lexical_cast<float>(child->value());
                                g_defenseDroneFix_BoxRange[1] = g_defenseDroneFix_BoxRange[0];
                            }
                            if (child->first_attribute("player"))
                            {
                                g_defenseDroneFix_BoxRange[0] = boost::lexical_cast<float>(child->first_attribute("player")->value());
                            }
                            if (child->first_attribute("enemy"))
                            {
                                g_defenseDroneFix_BoxRange[1] = boost::lexical_cast<float>(child->first_attribute("enemy")->value());
                            }
                        }
                        if (strcmp(child->name(), "ellipseRange") == 0)
                        {
                            if (child->value())
                            {
                                g_defenseDroneFix_EllipseRange[0] = boost::lexical_cast<float>(child->value());
                                g_defenseDroneFix_EllipseRange[1] = g_defenseDroneFix_EllipseRange[0];
                            }
                            if (child->first_attribute("player"))
                            {
                                g_defenseDroneFix_EllipseRange[0] = boost::lexical_cast<float>(child->first_attribute("player")->value());
                            }
                            if (child->first_attribute("enemy"))
                            {
                                g_defenseDroneFix_EllipseRange[1] = boost::lexical_cast<float>(child->first_attribute("enemy")->value());
                            }
                        }
                    }
                }
            }

            if (strcmp(node->name(), "resistsMindControlStat") == 0)
            {
                auto enabled = node->first_attribute("enabled")->value();
                g_resistsMindControlStat = EventsParser::ParseBoolean(enabled);
            }

            /*
            if (strcmp(node->name(), "dronesCanTeleport") == 0)
            {
                auto enabled = node->first_attribute("enabled")->value();
                g_dronesCanTeleport = EventsParser::ParseBoolean(enabled);
            }
            */

            if (strcmp(node->name(), "redesignedWeaponTooltips") == 0)
            {
                auto enabled = node->first_attribute("enabled")->value();
                customOptions->redesignedWeaponTooltips.defaultValue = EventsParser::ParseBoolean(enabled);
                customOptions->redesignedWeaponTooltips.currentValue = EventsParser::ParseBoolean(enabled);
            }
            if (strcmp(node->name(), "redesignedCrewTooltips") == 0)
            {
                auto enabled = node->first_attribute("enabled")->value();
                customOptions->redesignedCrewTooltips.defaultValue = EventsParser::ParseBoolean(enabled);
                customOptions->redesignedCrewTooltips.currentValue = EventsParser::ParseBoolean(enabled);
            }
            if (strcmp(node->name(), "redesignedDroneTooltips") == 0)
            {
                auto enabled = node->first_attribute("enabled")->value();
                customOptions->redesignedDroneTooltips.defaultValue = EventsParser::ParseBoolean(enabled);
                customOptions->redesignedDroneTooltips.currentValue = EventsParser::ParseBoolean(enabled);
            }
            if (strcmp(node->name(), "redesignedAugmentTooltips") == 0)
            {
                auto enabled = node->first_attribute("enabled")->value();
                customOptions->redesignedAugmentTooltips.defaultValue = EventsParser::ParseBoolean(enabled);
                customOptions->redesignedAugmentTooltips.currentValue = EventsParser::ParseBoolean(enabled);
            }

            if (strcmp(node->name(), "eventTooltips") == 0)
            {
                auto enabled = node->first_attribute("enabled")->value();
                customOptions->eventTooltips.defaultValue = EventsParser::ParseBoolean(enabled);
                customOptions->eventTooltips.currentValue = EventsParser::ParseBoolean(enabled);
            }

            if (strcmp(node->name(), "showNumericalWeaponCooldown") == 0)
            {
                auto enabled = node->first_attribute("enabled")->value();
                customOptions->showWeaponCooldown.defaultValue = EventsParser::ParseBoolean(enabled);
                customOptions->showWeaponCooldown.currentValue = EventsParser::ParseBoolean(enabled);
            }

            if (strcmp(node->name(), "showReactor") == 0)
            {
                auto enabled = node->first_attribute("enabled")->value();
                customOptions->showReactor.defaultValue = EventsParser::ParseBoolean(enabled);
                customOptions->showReactor.currentValue = EventsParser::ParseBoolean(enabled);
            }

            if (strcmp(node->name(), "showAllConnections") == 0)
            {
                auto enabled = node->first_attribute("enabled")->value();
                customOptions->showAllConnections.defaultValue = EventsParser::ParseBoolean(enabled);
                customOptions->showAllConnections.currentValue = EventsParser::ParseBoolean(enabled);
            }

            if (strcmp(node->name(), "showScrapCollectorScrap") == 0)
            {
                auto enabled = node->first_attribute("enabled")->value();
                customOptions->showScrapCollectorScrap.defaultValue = EventsParser::ParseBoolean(enabled);
                customOptions->showScrapCollectorScrap.currentValue = EventsParser::ParseBoolean(enabled);
            }

            if (strcmp(node->name(), "alternateOxygenRendering") == 0)
            {
                auto enabled = node->first_attribute("enabled")->value();
                customOptions->alternateOxygenRendering.defaultValue = EventsParser::ParseBoolean(enabled);
                customOptions->alternateOxygenRendering.currentValue = EventsParser::ParseBoolean(enabled);
                if (EventsParser::ParseBoolean(enabled))
                {
                    for (auto child = node->first_node(); child; child = child->next_sibling())
                    {
                        if (strcmp(child->name(), "gradient") == 0)
                        {
                            AlternateOxygenManager::GetInstance()->ParseGradientNode(child);
                        }
                    }
                    if (AlternateOxygenManager::GetInstance()->IsGradientEmpty())
                    {
                        AlternateOxygenManager::GetInstance()->CreateDefaultGradient();
                    }
                }
            }

            if (strcmp(node->name(), "advancedCrewTooltips") == 0)
            {
                auto enabled = node->first_attribute("enabled")->value();
                customOptions->advancedCrewTooltips.defaultValue = EventsParser::ParseBoolean(enabled);
                customOptions->advancedCrewTooltips.currentValue = EventsParser::ParseBoolean(enabled);
                if(enabled)
                {
                    if(node->first_attribute("ally"))
                    {
                        customOptions->showAllyPowers.defaultValue = EventsParser::ParseBoolean(node->first_attribute("ally")->value());
                        customOptions->showAllyPowers.currentValue = EventsParser::ParseBoolean(node->first_attribute("ally")->value());
                    }
                    if(node->first_attribute("enemy"))
                    {
                        customOptions->showEnemyPowers.defaultValue = EventsParser::ParseBoolean(node->first_attribute("enemy")->value());
                        customOptions->showEnemyPowers.currentValue = EventsParser::ParseBoolean(node->first_attribute("enemy")->value());
                    }
                    if(node->first_attribute("rounding"))
                    {
                        customOptions->advancedCrewTooltipRounding.defaultAmount = boost::lexical_cast<int>(node->first_attribute("rounding")->value());
                        customOptions->advancedCrewTooltipRounding.currentAmount = boost::lexical_cast<int>(node->first_attribute("rounding")->value());
                    }
                }
            }

            if (strcmp(node->name(), "console") == 0)
            {
                auto enabled = node->first_attribute("enabled")->value();
                CommandConsole::GetInstance()->enabled = EventsParser::ParseBoolean(enabled);
            }

            if (strcmp(node->name(), "infinite") == 0)
            {
                auto enabled = node->first_attribute("enabled")->value();
                g_infiniteMode = EventsParser::ParseBoolean(enabled);
            }

            if (strcmp(node->name(), "transformColorMode") == 0)
            {
                if (strcmp(node->name(), "KEEP_COLORS") == 0)
                {
                    g_transformColorMode = TransformColorMode::KEEP_COLORS;
                }
                else if (strcmp(node->name(), "KEEP_INDICES") == 0)
                {
                    g_transformColorMode = TransformColorMode::KEEP_INDICES;
                }
            }

            if (strcmp(node->name(), "defaults") == 0)
            {
                for (auto child = node->first_node(); child; child = child->next_sibling())
                {
                    if (strcmp(child->name(), "checkCargo") == 0)
                    {
                        customOptions->defaults.checkCargo = EventsParser::ParseBoolean(child->value());
                    }
                    if (strcmp(child->name(), "beaconType_hideVanillaLabel") == 0)
                    {
                        customOptions->defaults.beaconType_hideVanillaLabel = EventsParser::ParseBoolean(child->value());
                    }
                }
            }

            if (strcmp(node->name(), "victories") == 0)
            {
                auto customUnlocks = CustomShipUnlocks::instance;
                customUnlocks->ParseVictoryAchievements(node);
            }

            if (strcmp(node->name(), "achievements") == 0)
            {
                auto customAchievements = CustomAchievementTracker::instance;
                customAchievements->ParseAchievements(node);
            }

            if (strcmp(node->name(), "ships") == 0)
            {
                auto customShipManager = CustomShipSelect::GetInstance();
                customShipManager->ParseShipsNode(node);
            }

            if (strcmp(node->name(), "shipGenerators") == 0)
            {
                CustomShipGenerator::Init();
                CustomShipGenerator::ParseGeneratorNode(node);
            }

            if (strcmp(node->name(), "crew") == 0)
            {
                auto customCrewManager = CustomCrewManager::GetInstance();
                customCrewManager->ParseCrewNode(node);
            }

            if (strcmp(node->name(), "rewards") == 0)
            {
                auto customRewardsManager = CustomRewardsManager::GetInstance();
                customRewardsManager->ParseRewardsNode(node);
            }

            if (strcmp(node->name(), "sectorMap") == 0)
            {
                auto customSectorParser = CustomSectorManager::GetInstance();
                customSectorParser->ParseCustomSectorMapNode(node);
            }

            if (strcmp(node->name(), "events") == 0)
            {
                auto customEventParser = CustomEventsParser::GetInstance();
                customEventParser->ParseCustomEventNodeFiles(node);
            }

            if (strcmp(node->name(), "augments") == 0)
            {
                auto customAugmentManager = CustomAugmentManager::GetInstance();
                customAugmentManager->ParseCustomAugmentNode(node);
            }

            if (strcmp(node->name(), "titleScreen") == 0)
            {
                CustomMainMenu::GetInstance()->ParseTitleScreenNode(node);
            }
            if (strcmp(node->name(), "forceDlc") == 0)
            {
                Global::forceDlc = EventsParser::ParseBoolean(node->first_attribute("enabled")->value());
            }
            if (strcmp(node->name(), "boss") == 0)
            {
                CustomBoss::instance->ParseBossNode(node);
            }
            if (strcmp(node->name(), "store") == 0)
            {
                CustomStore::instance->ParseStoreNode(node);
            }
            if (strcmp(node->name(), "drones") == 0)
            {
                CustomDroneManager::GetInstance()->ParseDroneNode(node);
            }
            if (strcmp(node->name(), "seeds") == 0)
            {
                if (node->first_attribute("enabled"))
                {
                    SeedInputBox::seedsEnabled = EventsParser::ParseBoolean(node->first_attribute("enabled")->value());
                }
            }
            if (strcmp(node->name(), "colors") == 0)
            {
                ParseCustomColorsNode(node);
            }
            if (strcmp(node->name(), "customSystems") == 0)
            {
                ParseSystemsNode(node);
            }
            if (strcmp(node->name(), "discord") == 0)
            {
                auto enabled = EventsParser::ParseBoolean(node->first_attribute("enabled")->value());

                if (enabled)
                {
                    DiscordHandler::GetInstance()->ParseDiscordNode(node);

                    DiscordHandler::GetInstance()->Initialize();

                    std::string modName = G_->GetTextLibrary()->GetText("discord_mod");

                    std::string details = "";

                    if (modName.empty())
                    {
                        details = G_->GetTextLibrary()->GetText("discord_playing_vanilla");
                        DiscordHandler::GetInstance()->vanilla = true;
                    }
                    else
                    {
                        details = G_->GetTextLibrary()->GetText("discord_playing_modded");
                        boost::replace_all(details, "\\1", modName);
                        DiscordHandler::GetInstance()->vanilla = false;
                    }

                    DiscordHandler::GetInstance()->SetLargeImageText(details);
                }
            }
            if (strcmp(node->name(), "saveFile") == 0)
            {
                SaveFileHandler::instance->ParseSaveFileNode(node);
            }
        }

        // Processing after first pass
        {
            auto customEventParser = CustomEventsParser::GetInstance();
            customEventParser->ReadCustomEventFiles();
        }

        // Second Pass
        for (auto node = parentNode->first_node(); node; node = node->next_sibling())
        {
            if (strcmp(node->name(), "events") == 0)
            {
                auto customEventParser = CustomEventsParser::GetInstance();
                customEventParser->ParseCustomEventNode(node);
            }
        }

        // Processing after second pass
        {
            auto customEventParser = CustomEventsParser::GetInstance();
            customEventParser->PostProcessCustomEvents();
        }


        if (!checkedVersion)
        {
            throw "Wrong version of Hyperspace detected. Please check that Hyperspace is installed correctly and you are using the correct version of Hyperspace for all of your mods. You can continue, but mods may function incorrectly.";
        }

        doc.clear();
    }
    catch (rapidxml::parse_error& e)
    {
        std::string msg = std::string("Failed parsing hyperspace.xml\n") + std::string(e.what());
        MessageBoxA(GetDesktopWindow(), msg.c_str(), "Error", MB_ICONERROR | MB_SETFOREGROUND);
    }
    catch (std::exception &e)
    {
        std::string msg = std::string("Failed parsing hyperspace.xml\n") + std::string(e.what());
        MessageBoxA(GetDesktopWindow(), msg.c_str(), "Error", MB_ICONERROR | MB_SETFOREGROUND);
    }
    catch (const char* e)
    {
        MessageBoxA(GetDesktopWindow(), e, "Error", MB_ICONERROR | MB_SETFOREGROUND);
    }

    //G_->lua = new LuaState;
}





