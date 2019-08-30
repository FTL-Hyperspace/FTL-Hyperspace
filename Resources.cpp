#include "rapidxml.hpp"
#include "Resources.h"

#include "HullNumbers.h"
#include "CommandConsole.h"
#include "CustomShips.h"
#include "CustomCrew.h"

#include <boost/lexical_cast.hpp>

HOOK_METHOD(CApp, OnLoop, () -> int)
{
    if (G_ && !G_->AreResourcesInitialized())
    {
        G_->InitializeResources(G_->GetResources());
    }
    return super();

}


// hyperspace.xml parsing
void Global::InitializeResources(ResourceControl *resources)
{
    this->__resourcesInitialized = true;

    std::string fileName("data/hyperspace.xml");
    char *hyperspacetext = resources->LoadFile(fileName);



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

                    if (strcmp(enabled, "true") == 0)
                    {
                        auto hullManager = HullNumbers::GetInstance();
                        hullManager->enabled = true;
                        hullManager->ParseHullNumbersNode(node);
                    }
                }
            }
            if (strcmp(node->name(), "console") == 0)
            {
                auto enabled = node->first_attribute("enabled")->value();
                CommandConsole::GetInstance()->enabled = strcmp(enabled, "true") == 0;
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
}





