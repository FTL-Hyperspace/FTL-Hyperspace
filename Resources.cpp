#include "rapidxml.hpp"
#include "Resources.h"

#include "HullNumbers.h"
#include "CommandConsole.h"

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
        if (!hyperspacetext) throw "No xml found";

        rapidxml::xml_document<> doc;
        doc.parse<0>(hyperspacetext);

        auto node = doc.first_node("FTL");
        if (!node)
            throw "No parent node found";
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
                        auto manager = HullNumbers::GetInstance();
                        manager->enabled = true;
                        try
                        {
                            auto child = node->first_node("playerText");

                            auto playerX = boost::lexical_cast<int>(child->first_attribute("x")->value());
                            auto playerY = boost::lexical_cast<int>(child->first_attribute("y")->value());
                            auto playerType = boost::lexical_cast<int>(child->first_attribute("type")->value());

                            child = node->first_node("enemyText");

                            auto enemyX = boost::lexical_cast<int>(child->first_attribute("x")->value());
                            auto enemyY = boost::lexical_cast<int>(child->first_attribute("y")->value());
                            auto enemyType = boost::lexical_cast<int>(child->first_attribute("type")->value());

                            child = node->first_node("bossText");

                            auto bossX = boost::lexical_cast<int>(child->first_attribute("x")->value());
                            auto bossY = boost::lexical_cast<int>(child->first_attribute("y")->value());
                            auto bossType = boost::lexical_cast<int>(child->first_attribute("type")->value());


                            manager->playerIndicator = { playerX, playerY, playerType };
                            manager->enemyIndicator = { enemyX, enemyY, enemyType };
                            manager->bossIndicator = { bossX, bossY, bossType };
                        }
                        catch (boost::bad_lexical_cast const &e)
                        {
                            MessageBoxA(NULL, "boost::bad_lexical_cast in hyperspace.xml", "Error", MB_ICONERROR);
                        }
                    }
                }
            }
            if (strcmp(node->name(), "console") == 0)
            {
                auto enabled = node->first_attribute("enabled")->value();
                CommandConsole::GetInstance()->enabled = strcmp(enabled, "true") == 0;
            }

            node = node->next_sibling();
        }

        doc.clear();
    }
    catch (std::exception &e)
    {
        MessageBoxA(NULL, "Failed parsing hyperspace.xml", "Error", MB_ICONERROR);
    }
}





