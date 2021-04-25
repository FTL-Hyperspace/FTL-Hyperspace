#include "rapidxml.hpp"
#include "Resources.h"
#include "CustomOptions.h"

#include "HullNumbers.h"
#include "CommandConsole.h"
#include "CustomShipSelect.h"
#include "CustomCrew.h"
#include "CustomEvents.h"
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

#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string/replace.hpp>

GL_Color& ParseColorNode(GL_Color& colorRef, rapidxml::xml_node<char>* node)
{
    if (node->first_attribute("r")) { colorRef.r = boost::lexical_cast<float>(node->first_attribute("r")->value()) / 255.f; }
    if (node->first_attribute("g")) { colorRef.g = boost::lexical_cast<float>(node->first_attribute("g")->value()) / 255.f; }
    if (node->first_attribute("b")) { colorRef.b = boost::lexical_cast<float>(node->first_attribute("b")->value()) / 255.f; }
    if (node->first_attribute("a")) { colorRef.a = boost::lexical_cast<float>(node->first_attribute("a")->value()); }

    return colorRef;
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

        auto node = doc.first_node("FTL");
        if (!node)
            throw "No parent node found in hyperspace.xml";

        bool checkedVersion = false;

        std::string discordModName = "";

        for (node = node->first_node(); node; node = node->next_sibling())
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

            if (strcmp(node->name(), "redesignedWeaponTooltips") == 0)
            {
                auto enabled = node->first_attribute("enabled")->value();
                customOptions->redesignedWeaponTooltips.defaultValue = EventsParser::ParseBoolean(enabled);
                customOptions->redesignedWeaponTooltips.currentValue = EventsParser::ParseBoolean(enabled);
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


            if (strcmp(node->name(), "ships") == 0)
            {
                auto customShipManager = CustomShipSelect::GetInstance();
                customShipManager->ParseShipsNode(node);
            }

            if (strcmp(node->name(), "crew") == 0)
            {
                auto customCrewManager = CustomCrewManager::GetInstance();
                customCrewManager->ParseCrewNode(node);
            }

            if (strcmp(node->name(), "events") == 0)
            {
                auto customEventParser = CustomEventsParser::GetInstance();
                customEventParser->ParseCustomEventNode(node);
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


        if (!checkedVersion)
        {
            throw "Wrong version of Hyperspace detected. Please check that Hyperspace is installed correctly and you are using the correct version of Hyperspace for all of your mods. You can continue, but mods may function incorrectly.";
        }

        doc.clear();
    }
    catch (std::exception &e)
    {
        MessageBoxA(GetDesktopWindow(), "Failed parsing hyperspace.xml", "Error", MB_ICONERROR | MB_SETFOREGROUND);
    }
    catch (const char* e)
    {
        MessageBoxA(GetDesktopWindow(), e, "Error", MB_ICONERROR | MB_SETFOREGROUND);
    }

    //G_->lua = new LuaState;
}





