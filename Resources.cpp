#include "rapidxml.hpp"
#include "Resources.h"

#include "HullNumbers.h"
#include "CommandConsole.h"
#include "CustomShips.h"
#include "CustomCrew.h"
#include "CustomEvents.h"
#include "CustomAugments.h"
#include "Infinite.h"
#include "Balance.h"
#include "MainMenu.h"

#include <boost/lexical_cast.hpp>

HOOK_METHOD(ScoreKeeper, OnInit, () -> void)
{
    // last thing that happens before game initialization is complete
    super();

    if (G_ && !G_->AreResourcesInitialized())
    {
        G_->InitializeResources(G_->GetResources());
    }

}


// hyperspace.xml parsing
void Global::InitializeResources(ResourceControl *resources)
{
    __resourcesInitialized = true;

    char *hyperspacetext = resources->LoadFile("data/hyperspace.xml");



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
        node = node->first_node();

        while (node)
        {
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
                auto enabled = node->first_attribute("enabled")->value();
                g_titleScreen = EventsParser::ParseBoolean(enabled);
                if (node->first_attribute("logo_x"))
                {
                    g_logoX = boost::lexical_cast<int>(node->first_attribute("logo_x")->value());
                }
                if (node->first_attribute("logo_y"))
                {
                    g_logoY = boost::lexical_cast<int>(node->first_attribute("logo_y")->value());
                }
            }

            if (strcmp(node->name(), "forceDlc") == 0)
            {
                Global::forceDlc = EventsParser::ParseBoolean(node->first_attribute("enabled")->value());
            }


            node = node->next_sibling();
        }

        doc.clear();
    }
    catch (std::exception &e)
    {
        MessageBoxA(NULL, "Failed parsing hyperspace.xml", "Error", MB_ICONERROR);
    }
    catch (const char* e)
    {
        MessageBoxA(NULL, e, "Error", MB_ICONERROR);
    }

    //G_->lua = new LuaState;
}





