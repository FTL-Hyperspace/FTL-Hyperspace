#include "CustomEvents.h"
#include "Seeds.h"
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>

std::vector<TriggeredEventDefinition> TriggeredEventDefinition::defs = std::vector<TriggeredEventDefinition>();
std::unordered_map<std::string, TriggeredEvent> TriggeredEvent::eventList = std::unordered_map<std::string, TriggeredEvent>();

std::unordered_map<std::string,std::vector<std::pair<float,std::string>>> TriggeredEventDefinition::timerSoundDefs = std::unordered_map<std::string,std::vector<std::pair<float,std::string>>>();

TriggeredEventGui *TriggeredEventGui::instance = new TriggeredEventGui();

std::deque<std::pair<std::string,int>> eventQueue = {};

int TriggeredEvent::playerCloneCount = 0;

void CustomEventsParser::ParseCustomTriggeredEventNode(rapidxml::xml_node<char> *node, TriggeredEventDefinition *def)
{
    if (node->first_attribute("event"))
    {
        def->event = node->first_attribute("event")->value();
        def->name = node->first_attribute("event")->value();
    }
    if (node->first_attribute("name"))
    {
        def->name = node->first_attribute("name")->value();
    }

    if (node->first_attribute("seeded"))
    {
        def->seeded = EventsParser::ParseBoolean(node->first_attribute("seeded")->value());
    }
    if (node->first_attribute("thisFight"))
    {
        def->thisFight = EventsParser::ParseBoolean(node->first_attribute("thisFight")->value());
        def->clearOnJump = def->thisFight;
    }
    if (node->first_attribute("clearOnJump"))
    {
        def->clearOnJump = EventsParser::ParseBoolean(node->first_attribute("clearOnJump")->value());
    }
    if (node->first_attribute("loops"))
    {
        def->minLoops = boost::lexical_cast<int>(node->first_attribute("loops")->value());
        def->maxLoops = boost::lexical_cast<int>(node->first_attribute("loops")->value());
    }
    if (node->first_attribute("minLoops"))
    {
        def->minLoops = boost::lexical_cast<int>(node->first_attribute("minLoops")->value());
    }
    if (node->first_attribute("maxLoops"))
    {
        def->maxLoops = boost::lexical_cast<int>(node->first_attribute("maxLoops")->value());
    }
    if (node->first_attribute("time"))
    {
        def->triggerMinTime = boost::lexical_cast<float>(node->first_attribute("time")->value());
        def->triggerMaxTime = boost::lexical_cast<float>(node->first_attribute("time")->value());
    }
    if (node->first_attribute("minTime"))
    {
        def->triggerMinTime = boost::lexical_cast<float>(node->first_attribute("minTime")->value());
    }
    if (node->first_attribute("maxTime"))
    {
        def->triggerMaxTime = boost::lexical_cast<float>(node->first_attribute("maxTime")->value());
    }
    if (node->first_attribute("jumps"))
    {
        def->triggerMinJumps = boost::lexical_cast<int>(node->first_attribute("jumps")->value());
        def->triggerMaxJumps = boost::lexical_cast<int>(node->first_attribute("jumps")->value());
    }
    if (node->first_attribute("minJumps"))
    {
        def->triggerMinJumps = boost::lexical_cast<int>(node->first_attribute("minJumps")->value());
    }
    if (node->first_attribute("maxJumps"))
    {
        def->triggerMaxJumps = boost::lexical_cast<int>(node->first_attribute("maxJumps")->value());
    }
    if (node->first_attribute("playerHull"))
    {
        def->minPlayerHull = boost::lexical_cast<int>(node->first_attribute("playerHull")->value());
        def->maxPlayerHull = boost::lexical_cast<int>(node->first_attribute("playerHull")->value());
    }
    if (node->first_attribute("minPlayerHull"))
    {
        def->minPlayerHull = boost::lexical_cast<int>(node->first_attribute("minPlayerHull")->value());
    }
    if (node->first_attribute("maxPlayerHull"))
    {
        def->maxPlayerHull = boost::lexical_cast<int>(node->first_attribute("maxPlayerHull")->value());
    }
    if (node->first_attribute("playerDamage"))
    {
        def->minPlayerDamage = boost::lexical_cast<int>(node->first_attribute("playerDamage")->value());
        def->maxPlayerDamage = boost::lexical_cast<int>(node->first_attribute("playerDamage")->value());
    }
    if (node->first_attribute("minPlayerDamage"))
    {
        def->minPlayerDamage = boost::lexical_cast<int>(node->first_attribute("minPlayerDamage")->value());
    }
    if (node->first_attribute("maxPlayerDamage"))
    {
        def->maxPlayerDamage = boost::lexical_cast<int>(node->first_attribute("maxPlayerDamage")->value());
    }
    if (node->first_attribute("enemyHull"))
    {
        def->minEnemyHull = boost::lexical_cast<int>(node->first_attribute("enemyHull")->value());
        def->maxEnemyHull = boost::lexical_cast<int>(node->first_attribute("enemyHull")->value());
    }
    if (node->first_attribute("minEnemyHull"))
    {
        def->minEnemyHull = boost::lexical_cast<int>(node->first_attribute("minEnemyHull")->value());
    }
    if (node->first_attribute("maxEnemyHull"))
    {
        def->maxEnemyHull = boost::lexical_cast<int>(node->first_attribute("maxEnemyHull")->value());
    }
    if (node->first_attribute("enemyDamage"))
    {
        def->minEnemyDamage = boost::lexical_cast<int>(node->first_attribute("enemyDamage")->value());
        def->maxEnemyDamage = boost::lexical_cast<int>(node->first_attribute("enemyDamage")->value());
    }
    if (node->first_attribute("minEnemyDamage"))
    {
        def->minEnemyDamage = boost::lexical_cast<int>(node->first_attribute("minEnemyDamage")->value());
    }
    if (node->first_attribute("maxEnemyDamage"))
    {
        def->maxEnemyDamage = boost::lexical_cast<int>(node->first_attribute("maxEnemyDamage")->value());
    }
    if (node->first_attribute("enemyHullScaling"))
    {
        def->enemyHullScaling = boost::lexical_cast<float>(node->first_attribute("enemyHullScaling")->value());
    }
    if (node->first_attribute("enemyDamageScaling"))
    {
        def->enemyDamageScaling = boost::lexical_cast<float>(node->first_attribute("enemyDamageScaling")->value());
    }

    if (node->first_attribute("playerCrew"))
    {
        def->minPlayerCrew = boost::lexical_cast<int>(node->first_attribute("playerCrew")->value());
        def->maxPlayerCrew = boost::lexical_cast<int>(node->first_attribute("playerCrew")->value());
    }
    if (node->first_attribute("minPlayerCrew"))
    {
        def->minPlayerCrew = boost::lexical_cast<int>(node->first_attribute("minPlayerCrew")->value());
    }
    if (node->first_attribute("maxPlayerCrew"))
    {
        def->maxPlayerCrew = boost::lexical_cast<int>(node->first_attribute("maxPlayerCrew")->value());
    }
    if (node->first_attribute("playerDeaths"))
    {
        def->minPlayerDeaths = boost::lexical_cast<int>(node->first_attribute("playerDeaths")->value());
        def->maxPlayerDeaths = boost::lexical_cast<int>(node->first_attribute("playerDeaths")->value());
    }
    if (node->first_attribute("minPlayerDeaths"))
    {
        def->minPlayerDeaths = boost::lexical_cast<int>(node->first_attribute("minPlayerDeaths")->value());
    }
    if (node->first_attribute("maxPlayerDeaths"))
    {
        def->maxPlayerDeaths = boost::lexical_cast<int>(node->first_attribute("maxPlayerDeaths")->value());
    }
    if (node->first_attribute("enemyCrew"))
    {
        def->minEnemyCrew = boost::lexical_cast<int>(node->first_attribute("enemyCrew")->value());
        def->maxEnemyCrew = boost::lexical_cast<int>(node->first_attribute("enemyCrew")->value());
    }
    if (node->first_attribute("minEnemyCrew"))
    {
        def->minEnemyCrew = boost::lexical_cast<int>(node->first_attribute("minEnemyCrew")->value());
    }
    if (node->first_attribute("maxEnemyCrew"))
    {
        def->maxEnemyCrew = boost::lexical_cast<int>(node->first_attribute("maxEnemyCrew")->value());
    }
    if (node->first_attribute("enemyDeaths"))
    {
        def->minEnemyDeaths = boost::lexical_cast<int>(node->first_attribute("enemyDeaths")->value());
        def->maxEnemyDeaths = boost::lexical_cast<int>(node->first_attribute("enemyDeaths")->value());
    }
    if (node->first_attribute("minEnemyDeaths"))
    {
        def->minEnemyDeaths = boost::lexical_cast<int>(node->first_attribute("minEnemyDeaths")->value());
    }
    if (node->first_attribute("maxEnemyDeaths"))
    {
        def->maxEnemyDeaths = boost::lexical_cast<int>(node->first_attribute("maxEnemyDeaths")->value());
    }

    for (auto child = node->first_node(); child; child = child->next_sibling())
    {
        if (strcmp(child->name(), "time") == 0)
        {
            if (child->first_attribute("amount"))
            {
                def->triggerMinTime = boost::lexical_cast<float>(child->first_attribute("amount")->value());
                def->triggerMaxTime = boost::lexical_cast<float>(child->first_attribute("amount")->value());
            }
            if (child->first_attribute("min"))
            {
                def->triggerMinTime = boost::lexical_cast<float>(child->first_attribute("min")->value());
            }
            if (child->first_attribute("max"))
            {
                def->triggerMaxTime = boost::lexical_cast<float>(child->first_attribute("max")->value());
            }
        }
        if (strcmp(child->name(), "jumps") == 0)
        {
            if (child->first_attribute("amount"))
            {
                def->triggerMinJumps = boost::lexical_cast<int>(child->first_attribute("amount")->value());
                def->triggerMaxJumps = boost::lexical_cast<int>(child->first_attribute("amount")->value());
            }
            if (child->first_attribute("min"))
            {
                def->triggerMinJumps = boost::lexical_cast<int>(child->first_attribute("min")->value());
            }
            if (child->first_attribute("max"))
            {
                def->triggerMaxJumps = boost::lexical_cast<int>(child->first_attribute("max")->value());
            }
        }
        if (strcmp(child->name(), "playerHull") == 0)
        {
            if (child->first_attribute("amount"))
            {
                def->minPlayerHull = boost::lexical_cast<int>(child->first_attribute("amount")->value());
                def->maxPlayerHull = boost::lexical_cast<int>(child->first_attribute("amount")->value());
            }
            if (child->first_attribute("min"))
            {
                def->minPlayerHull = boost::lexical_cast<int>(child->first_attribute("min")->value());
            }
            if (child->first_attribute("max"))
            {
                def->maxPlayerHull = boost::lexical_cast<int>(child->first_attribute("max")->value());
            }
        }
        if (strcmp(child->name(), "enemyHull") == 0)
        {
            if (child->first_attribute("amount"))
            {
                def->minEnemyHull = boost::lexical_cast<int>(child->first_attribute("amount")->value());
                def->maxEnemyHull = boost::lexical_cast<int>(child->first_attribute("amount")->value());
            }
            if (child->first_attribute("min"))
            {
                def->minEnemyHull = boost::lexical_cast<int>(child->first_attribute("min")->value());
            }
            if (child->first_attribute("max"))
            {
                def->maxEnemyHull = boost::lexical_cast<int>(child->first_attribute("max")->value());
            }
            if (child->first_attribute("scaling"))
            {
                def->enemyHullScaling = boost::lexical_cast<float>(child->first_attribute("scaling")->value());
            }
        }
        if (strcmp(child->name(), "playerDamage") == 0)
        {
            if (child->first_attribute("amount"))
            {
                def->minPlayerDamage = boost::lexical_cast<int>(child->first_attribute("amount")->value());
                def->maxPlayerDamage = boost::lexical_cast<int>(child->first_attribute("amount")->value());
            }
            if (child->first_attribute("min"))
            {
                def->minPlayerDamage = boost::lexical_cast<int>(child->first_attribute("min")->value());
            }
            if (child->first_attribute("max"))
            {
                def->maxPlayerDamage = boost::lexical_cast<int>(child->first_attribute("max")->value());
            }
            if (child->first_attribute("countRepairs"))
            {
                def->playerCountRepairs = EventsParser::ParseBoolean(child->first_attribute("countRepairs")->value());
            }
        }
        if (strcmp(child->name(), "enemyDamage") == 0)
        {
            if (child->first_attribute("amount"))
            {
                def->minEnemyDamage = boost::lexical_cast<int>(child->first_attribute("amount")->value());
                def->maxEnemyDamage = boost::lexical_cast<int>(child->first_attribute("amount")->value());
            }
            if (child->first_attribute("min"))
            {
                def->minEnemyDamage = boost::lexical_cast<int>(child->first_attribute("min")->value());
            }
            if (child->first_attribute("max"))
            {
                def->maxEnemyDamage = boost::lexical_cast<int>(child->first_attribute("max")->value());
            }
            if (child->first_attribute("scaling"))
            {
                def->enemyDamageScaling = boost::lexical_cast<float>(child->first_attribute("scaling")->value());
            }
            if (child->first_attribute("countRepairs"))
            {
                def->enemyCountRepairs = EventsParser::ParseBoolean(child->first_attribute("countRepairs")->value());
            }
        }
        if (strcmp(child->name(), "playerCrew") == 0)
        {
            if (child->first_attribute("amount"))
            {
                def->minPlayerCrew = boost::lexical_cast<int>(child->first_attribute("amount")->value());
                def->maxPlayerCrew = boost::lexical_cast<int>(child->first_attribute("amount")->value());
            }
            if (child->first_attribute("min"))
            {
                def->minPlayerCrew = boost::lexical_cast<int>(child->first_attribute("min")->value());
            }
            if (child->first_attribute("max"))
            {
                def->maxPlayerCrew = boost::lexical_cast<int>(child->first_attribute("max")->value());
            }
            if (child->first_attribute("includeClonebay"))
            {
                def->playerCrewCountClonebay = EventsParser::ParseBoolean(child->first_attribute("includeClonebay")->value());
            }
        }
        if (strcmp(child->name(), "enemyCrew") == 0)
        {
            if (child->first_attribute("amount"))
            {
                def->minEnemyCrew = boost::lexical_cast<int>(child->first_attribute("amount")->value());
                def->maxEnemyCrew = boost::lexical_cast<int>(child->first_attribute("amount")->value());
            }
            if (child->first_attribute("min"))
            {
                def->minEnemyCrew = boost::lexical_cast<int>(child->first_attribute("min")->value());
            }
            if (child->first_attribute("max"))
            {
                def->maxEnemyCrew = boost::lexical_cast<int>(child->first_attribute("max")->value());
            }
            if (child->first_attribute("includeClonebay"))
            {
                def->enemyCrewCountClonebay = EventsParser::ParseBoolean(child->first_attribute("includeClonebay")->value());
            }
        }
        if (strcmp(child->name(), "playerDeaths") == 0)
        {
            if (child->first_attribute("amount"))
            {
                def->minPlayerDeaths = boost::lexical_cast<int>(child->first_attribute("amount")->value());
                def->maxPlayerDeaths = boost::lexical_cast<int>(child->first_attribute("amount")->value());
            }
            if (child->first_attribute("min"))
            {
                def->minPlayerDeaths = boost::lexical_cast<int>(child->first_attribute("min")->value());
            }
            if (child->first_attribute("max"))
            {
                def->maxPlayerDeaths = boost::lexical_cast<int>(child->first_attribute("max")->value());
            }
            if (child->first_attribute("countNewCrew"))
            {
                def->playerCountNewCrew = EventsParser::ParseBoolean(child->first_attribute("countNewCrew")->value());
            }
            if (child->first_attribute("includeClonebay"))
            {
                def->playerDeathsCountClonebay = EventsParser::ParseBoolean(child->first_attribute("includeClonebay")->value());
            }
        }
        if (strcmp(child->name(), "enemyDeaths") == 0)
        {
            if (child->first_attribute("amount"))
            {
                def->minEnemyDeaths = boost::lexical_cast<int>(child->first_attribute("amount")->value());
                def->maxEnemyDeaths = boost::lexical_cast<int>(child->first_attribute("amount")->value());
            }
            if (child->first_attribute("min"))
            {
                def->minEnemyDeaths = boost::lexical_cast<int>(child->first_attribute("min")->value());
            }
            if (child->first_attribute("max"))
            {
                def->maxEnemyDeaths = boost::lexical_cast<int>(child->first_attribute("max")->value());
            }
            if (child->first_attribute("countNewCrew"))
            {
                def->enemyCountNewCrew = EventsParser::ParseBoolean(child->first_attribute("countNewCrew")->value());
            }
            if (child->first_attribute("includeClonebay"))
            {
                def->enemyDeathsCountClonebay = EventsParser::ParseBoolean(child->first_attribute("includeClonebay")->value());
            }
        }
        if (strcmp(child->name(), "triggeredEventBox") == 0)
        {
            def->box = new TriggeredEventBoxDefinition();
            if (child->first_attribute("load"))
            {
                std::string loadName = child->first_attribute("load")->value();
                auto it = TriggeredEventGui::GetInstance()->boxDefs.find(loadName);
                if (it != TriggeredEventGui::GetInstance()->boxDefs.end())
                {
                    *(def->box) = it->second;
                }
                else
                {
                    def->loadBox = new std::vector<char>();
                    rapidxml::print(std::back_inserter(*(def->loadBox)), *child, 0);
                    def->loadBox->push_back('\0');
                    continue;
                }
            }
            ParseCustomTriggeredEventBoxNode(child, def->box);
        }
        if (strcmp(child->name(), "timerSounds") == 0)
        {
            if (child->first_attribute("load"))
            {
                std::string loadName = child->first_attribute("load")->value();
                auto it = TriggeredEventDefinition::timerSoundDefs.find(loadName);
                if (it != TriggeredEventDefinition::timerSoundDefs.end())
                {
                    def->timerSounds = it->second;
                }
                else
                {
                    def->loadTimerSounds = loadName;
                }
            }
            ParseCustomTriggeredEventSounds(child, &(def->timerSounds));
        }
        if (strcmp(child->name(), "warningMessage") == 0)
        {
            def->warning = new TriggeredEventWarningDefinition();
            if (child->first_attribute("load"))
            {
                std::string loadName = child->first_attribute("load")->value();
                auto it = TriggeredEventGui::GetInstance()->warningDefs.find(loadName);
                if (it != TriggeredEventGui::GetInstance()->warningDefs.end())
                {
                    *(def->warning) = it->second;
                }
                else
                {
                    def->loadWarning = new std::vector<char>();
                    rapidxml::print(std::back_inserter(*(def->loadWarning)), *child, 0);
                    def->loadWarning->push_back('\0');
                    continue;
                }
            }
            ParseCustomTriggeredEventWarningNode(child, def->warning);
        }
    }
}

void CustomEventsParser::ParseCustomTriggeredEventBoxNode(rapidxml::xml_node<char> *node, TriggeredEventBoxDefinition *box)
{
    if (node->first_attribute("pos"))
    {
        std::string boxPos = node->first_attribute("pos")->value();
        boost::algorithm::to_lower(boxPos);
        if (boxPos == "default")
        {
            box->boxPosition = TriggeredEventBoxDefinition::BoxPosition::DEFAULT;
        }
        if (boxPos == "scrap")
        {
            box->boxPosition = TriggeredEventBoxDefinition::BoxPosition::SCRAP;
        }
        if (boxPos == "topright")
        {
            box->boxPosition = TriggeredEventBoxDefinition::BoxPosition::TOPRIGHT;
        }
        if (boxPos == "combat")
        {
            box->boxPosition = TriggeredEventBoxDefinition::BoxPosition::COMBAT;
        }
    }
    if (node->first_attribute("priority"))
    {
        box->priority = boost::lexical_cast<int>(node->first_attribute("priority")->value());
    }
    for (auto child = node->first_node(); child; child = child->next_sibling())
    {
        std::string nodeName(child->name());
        if (nodeName == "image")
        {
            if (child->first_attribute("name"))
            {
                box->image = child->first_attribute("name")->value();
            }
            if (child->first_attribute("x"))
            {
                box->x = boost::lexical_cast<int>(child->first_attribute("x")->value());
            }
            if (child->first_attribute("y"))
            {
                box->y = boost::lexical_cast<int>(child->first_attribute("y")->value());
            }
            if (child->first_attribute("w"))
            {
                box->w = boost::lexical_cast<int>(child->first_attribute("w")->value());
            }
            if (child->first_attribute("h"))
            {
                box->h = boost::lexical_cast<int>(child->first_attribute("h")->value());
            }
            if (child->first_attribute("left"))
            {
                box->left = boost::lexical_cast<int>(child->first_attribute("left")->value());
            }
            if (child->first_attribute("right"))
            {
                box->right = boost::lexical_cast<int>(child->first_attribute("right")->value());
            }
            if (child->first_attribute("top"))
            {
                box->top = boost::lexical_cast<int>(child->first_attribute("top")->value());
            }
            if (child->first_attribute("bottom"))
            {
                box->bottom = boost::lexical_cast<int>(child->first_attribute("bottom")->value());
            }
            if (child->first_attribute("r"))
            {
                box->imageColor.r = boost::lexical_cast<float>(child->first_attribute("r")->value()) / 255.f;
            }
            if (child->first_attribute("g"))
            {
                box->imageColor.g = boost::lexical_cast<float>(child->first_attribute("g")->value()) / 255.f;
            }
            if (child->first_attribute("b"))
            {
                box->imageColor.b = boost::lexical_cast<float>(child->first_attribute("b")->value()) / 255.f;
            }
            if (child->first_attribute("a"))
            {
                box->imageColor.a = boost::lexical_cast<float>(child->first_attribute("a")->value());
            }
        }
        if (nodeName == "image2")
        {
            if (child->first_attribute("name"))
            {
                box->image2 = child->first_attribute("name")->value();
            }
            if (child->first_attribute("r"))
            {
                box->imageColor2.r = boost::lexical_cast<float>(child->first_attribute("r")->value()) / 255.f;
            }
            if (child->first_attribute("g"))
            {
                box->imageColor2.g = boost::lexical_cast<float>(child->first_attribute("g")->value()) / 255.f;
            }
            if (child->first_attribute("b"))
            {
                box->imageColor2.b = boost::lexical_cast<float>(child->first_attribute("b")->value()) / 255.f;
            }
            if (child->first_attribute("a"))
            {
                box->imageColor2.a = boost::lexical_cast<float>(child->first_attribute("a")->value());
            }
        }
        if (nodeName == "icon")
        {
            if (child->first_attribute("name"))
            {
                box->imageFront = child->first_attribute("name")->value();
            }
            if (child->first_attribute("x"))
            {
                box->front_x = boost::lexical_cast<int>(child->first_attribute("x")->value());
            }
            if (child->first_attribute("y"))
            {
                box->front_y = boost::lexical_cast<int>(child->first_attribute("y")->value());
            }
            if (child->first_attribute("r"))
            {
                box->imageColorFront.r = boost::lexical_cast<float>(child->first_attribute("r")->value()) / 255.f;
            }
            if (child->first_attribute("g"))
            {
                box->imageColorFront.g = boost::lexical_cast<float>(child->first_attribute("g")->value()) / 255.f;
            }
            if (child->first_attribute("b"))
            {
                box->imageColorFront.b = boost::lexical_cast<float>(child->first_attribute("b")->value()) / 255.f;
            }
            if (child->first_attribute("a"))
            {
                box->imageColorFront.a = boost::lexical_cast<float>(child->first_attribute("a")->value());
            }
        }
        if (nodeName == "text")
        {
            if (child->first_attribute("type"))
            {
                std::string textType = child->first_attribute("type")->value();
                boost::algorithm::to_lower(textType);
                if (textType == "auto")
                {
                    box->textType = TriggeredEventBoxDefinition::TextType::TIME_AUTO;
                }
                if (textType == "clock")
                {
                    box->textType = TriggeredEventBoxDefinition::TextType::TIME_CLOCK;
                }
                if (textType == "seconds")
                {
                    box->textType = TriggeredEventBoxDefinition::TextType::TIME_SECONDS;
                }
                if (textType == "jumps")
                {
                    box->textType = TriggeredEventBoxDefinition::TextType::JUMPS;
                }
            }
            if (child->first_attribute("x"))
            {
                box->text_x = boost::lexical_cast<int>(child->first_attribute("x")->value());
            }
            if (child->first_attribute("y"))
            {
                box->text_y = boost::lexical_cast<int>(child->first_attribute("y")->value());
            }
            if (child->first_attribute("r"))
            {
                box->textColor.r = boost::lexical_cast<float>(child->first_attribute("r")->value()) / 255.f;
            }
            if (child->first_attribute("g"))
            {
                box->textColor.g = boost::lexical_cast<float>(child->first_attribute("g")->value()) / 255.f;
            }
            if (child->first_attribute("b"))
            {
                box->textColor.b = boost::lexical_cast<float>(child->first_attribute("b")->value()) / 255.f;
            }
            if (child->first_attribute("a"))
            {
                box->textColor.a = boost::lexical_cast<float>(child->first_attribute("a")->value());
            }
        }
        if (nodeName == "text2")
        {
            if (child->first_attribute("r"))
            {
                box->textColor2.r = boost::lexical_cast<float>(child->first_attribute("r")->value()) / 255.f;
            }
            if (child->first_attribute("g"))
            {
                box->textColor2.g = boost::lexical_cast<float>(child->first_attribute("g")->value()) / 255.f;
            }
            if (child->first_attribute("b"))
            {
                box->textColor2.b = boost::lexical_cast<float>(child->first_attribute("b")->value()) / 255.f;
            }
            if (child->first_attribute("a"))
            {
                box->textColor2.a = boost::lexical_cast<float>(child->first_attribute("a")->value());
            }
        }
        if (nodeName == "warning")
        {
            if (child->first_attribute("time"))
            {
                box->warningTime = boost::lexical_cast<float>(child->first_attribute("time")->value());
            }
            if (child->first_attribute("jumps"))
            {
                box->warningJumps = boost::lexical_cast<int>(child->first_attribute("jumps")->value());
            }
            if (child->first_attribute("flash"))
            {
                box->flash = EventsParser::ParseBoolean(child->first_attribute("flash")->value());
            }
        }
        if (nodeName == "tooltip")
        {
            if (child->first_attribute("id"))
            {
                box->tooltip.data = child->first_attribute("id")->value();
                box->tooltip.isLiteral = false;
            }
            else
            {
                box->tooltip.data = child->value();
                box->tooltip.isLiteral = true;
            }
        }
    }
}

void CustomEventsParser::ParseCustomTriggeredEventSounds(rapidxml::xml_node<char> *node, std::vector<std::pair<float,std::string>> *vec)
{
    for (auto child = node->first_node(); child; child = child->next_sibling())
    {
        if (strcmp(child->name(), "timerSound") == 0)
        {
            std::pair<float,std::string> timerSound;
            timerSound.second = child->value();
            if (child->first_attribute("t"))
            {
                timerSound.first = boost::lexical_cast<float>(child->first_attribute("t")->value());
            }
            vec->push_back(timerSound);
        }
    }
    std::sort(vec->begin(), vec->end(), [](const std::pair<float,std::string> &a, const std::pair<float,std::string> &b) -> bool {return a.first > b.first;});
}

void CustomEventsParser::ParseCustomTriggeredEventWarningNode(rapidxml::xml_node<char> *node, TriggeredEventWarningDefinition *warning)
{
    if (node->first_attribute("image"))
    {
        warning->image = node->first_attribute("image")->value();
    }

    if (node->first_attribute("id"))
    {
        warning->text.data = node->first_attribute("id")->value();
        warning->text.isLiteral = false;
    }
    else
    {
        warning->text.data = node->value();
        warning->text.isLiteral = true;
    }

    if (node->first_attribute("x"))
    {
        warning->position.x = boost::lexical_cast<int>(node->first_attribute("x")->value());
    }
    if (node->first_attribute("y"))
    {
        warning->position.y = boost::lexical_cast<int>(node->first_attribute("y")->value());
    }

    if (node->first_attribute("time"))
    {
        warning->time = boost::lexical_cast<float>(node->first_attribute("time")->value());
    }

    if (node->first_attribute("centerText"))
    {
        warning->centerText = EventsParser::ParseBoolean(node->first_attribute("centerText")->value());
    }

    if (node->first_attribute("flash"))
    {
        warning->flash = EventsParser::ParseBoolean(node->first_attribute("flash")->value());
    }

    if (node->first_attribute("r"))
    {
        warning->textColor.r = boost::lexical_cast<float>(node->first_attribute("r")->value());
    }
    if (node->first_attribute("g"))
    {
        warning->textColor.g = boost::lexical_cast<float>(node->first_attribute("g")->value());
    }
    if (node->first_attribute("b"))
    {
        warning->textColor.b = boost::lexical_cast<float>(node->first_attribute("b")->value());
    }

    if (node->first_attribute("sound"))
    {
        warning->sound = node->first_attribute("sound")->value();
    }

    if (node->first_attribute("useWarningLine"))
    {
        warning->useWarningLine = EventsParser::ParseBoolean(node->first_attribute("useWarningLine")->value());
    }
}

unsigned int TriggeredEventDefinition::PushDef(TriggeredEventDefinition& def)
{
    unsigned int ret = defs.size();
    def.idx = ret;
    defs.push_back(def);
    return ret;
}

void TriggeredEvent::NewEvent(TriggeredEventDefinition* def)
{
    if (def->seeded && SeedInputBox::seedsEnabled) srandom32(Global::questSeed);

    auto it = eventList.find(def->name);
    if (it != eventList.end())
    {
        eventList.erase(it);
    }
    eventList.emplace(std::piecewise_construct, std::forward_as_tuple(def->name), std::forward_as_tuple(def));

    TriggeredEventGui::GetInstance()->reset = true;

    if (def->seeded && SeedInputBox::seedsEnabled) Global::questSeed = random32();
}

void TriggeredEvent::DestroyEvent(const std::string& name)
{
    auto it = eventList.find(name);
    if (it != eventList.end())
    {
        eventList.erase(it);
        TriggeredEventGui::GetInstance()->reset = true;
    }
}

void TriggeredEvent::UpdateAll()
{
    playerCloneCount = 0;
    for (auto& crew : G_->GetCrewFactory()->crewMembers)
    {
        if (crew->iShipId == 0 && crew->CountForVictory() && crew->bOutOfGame && crew->clone_ready) playerCloneCount++;
    }

    for (auto it=eventList.begin(); it!=eventList.end(); )
    {
        if (it->second.def->thisFight)
        {
            ShipManager* enemy = G_->GetShipManager(1);

            if (enemy != nullptr && enemy->_targetable.hostile && !enemy->bDestroyed && !enemy->bJumping)
            {
                it->second.Update();
            }

            if ((enemy == nullptr || !enemy->_targetable.hostile) && !G_->GetWorld()->commandGui->choiceBox.bOpen)
            {
                it = eventList.erase(it);
                TriggeredEventGui::GetInstance()->reset = true;
            }
            else
            {
                ++it;
            }
        }
        else
        {
            it->second.Update();
            ++it;
        }
    }
}

void TriggeredEvent::RenderAll()
{
    for (auto it=eventList.begin(); it!=eventList.end(); ++it)
    {
        it->second.OnRender();
    }
}

void TriggeredEvent::JumpAll()
{
    for (auto it=eventList.begin(); it!=eventList.end(); )
    {
        it->second.Jump();
        if (it->second.def->clearOnJump)
        {
            it = eventList.erase(it);
            TriggeredEventGui::GetInstance()->reset = true;
        }
        else
        {
            ++it;
        }
    }
}

void TriggeredEvent::TriggerCheck()
{
    for (auto it=eventList.begin(); it!=eventList.end(); ++it)
    {
        if (it->second.triggered)
        {
            std::string eventName = it->second.def->event;
            int seed = it->second.seed;
            int level = G_->GetWorld()->starMap.currentSector->level;

            if (it->second.warning != nullptr)
            {
                it->second.warning->tracker.Stop(false);
            }

            if (--(it->second.loops) <= 0)
            {
                eventList.erase(it);
                TriggeredEventGui::GetInstance()->reset = true;
            }
            else
            {
                it->second.triggered = false;
                it->second.Reset();
            }

            G_->GetWorld()->UpdateLocation(G_->GetEventGenerator()->GetBaseEvent(eventName, level, false, seed));
            if (G_->GetWorld()->commandGui->choiceBox.bOpen) break;
        }
    }
}

void TriggeredEvent::Reset()
{
    if (triggerTimer != nullptr)
    {
        float goal = def->triggerMinTime;
        if (def->triggerMaxTime > def->triggerMinTime)
        {
            int minTime = def->triggerMinTime * 1000.f;
            int maxTime = def->triggerMaxTime * 1000.f;
            goal = (minTime + random32()%(maxTime-minTime+1)) / 1000.f;
        }
        triggerTimer->currTime = 0.f;
        triggerTimer->currGoal = goal;
        triggerTimer->running = true;

        for (timerSoundIndex = 0; timerSoundIndex < def->timerSounds.size(); ++timerSoundIndex)
        {
            if (goal > def->timerSounds[timerSoundIndex].first) break;
        }
    }

    if (def->triggerMaxJumps > def->triggerMinJumps)
    {
        triggerJumps = def->triggerMinJumps + random32()%(def->triggerMaxJumps-def->triggerMinJumps+1);
    }
    else
    {
        triggerJumps = def->triggerMinJumps;
    }

    triggerPlayerHull = -1;
    if (def->minPlayerHull > -1)
    {
        if (def->maxPlayerHull > def->minPlayerHull)
        {
            triggerPlayerHull = std::max(triggerPlayerHull, def->minPlayerHull + random32()%(def->maxPlayerHull-def->minPlayerHull+1));
        }
        else
        {
            triggerPlayerHull = std::max(triggerPlayerHull, def->minPlayerHull);
        }
    }

    triggerEnemyHull = -1;
    if (def->minEnemyHull > -1)
    {
        int enemyHullScaling = G_->GetWorld()->starMap.worldLevel * def->enemyHullScaling;
        if (def->maxEnemyHull > def->minEnemyHull)
        {
            triggerEnemyHull = std::max(triggerEnemyHull, def->minEnemyHull + random32()%(def->maxEnemyHull-def->minEnemyHull+1) + enemyHullScaling);
        }
        else
        {
            triggerEnemyHull = std::max(triggerEnemyHull, def->minEnemyHull + enemyHullScaling);
        }
    }

    triggerPlayerDamage = -1;
    if (def->minPlayerDamage > -1)
    {
        ShipManager* ship = G_->GetShipManager(0);
        if (ship != nullptr)
        {
            currentPlayerHull = ship->ship.hullIntegrity.first;
            if (def->maxPlayerDamage > def->minPlayerDamage)
            {
                triggerPlayerDamage = def->minPlayerDamage + random32()%(def->maxPlayerDamage-def->minPlayerDamage+1);
            }
            else
            {
                triggerPlayerDamage = def->minPlayerDamage;
            }
        }
    }
    triggerEnemyDamage = -1;
    if (def->minEnemyDamage > -1)
    {
        ShipManager* ship = G_->GetShipManager(1);
        if (ship != nullptr)
        {
            currentEnemyHull = ship->ship.hullIntegrity.first;
            int enemyDamageScaling = G_->GetWorld()->starMap.worldLevel * def->enemyDamageScaling;
            if (def->maxEnemyDamage > def->minEnemyDamage)
            {
                triggerEnemyDamage = def->minEnemyDamage + random32()%(def->maxEnemyDamage-def->minEnemyDamage+1) + enemyDamageScaling;
            }
            else
            {
                triggerEnemyDamage = def->minEnemyDamage + enemyDamageScaling;
            }
        }
    }

    triggerPlayerCrew = -1;
    if (def->minPlayerCrew > -1)
    {
        if (def->maxPlayerCrew > def->minPlayerCrew)
        {
            triggerPlayerCrew = std::max(triggerPlayerCrew, def->minPlayerCrew + random32()%(def->maxPlayerCrew-def->minPlayerCrew+1));
        }
        else
        {
            triggerPlayerCrew = std::max(triggerPlayerCrew, def->minPlayerCrew);
        }
    }

    triggerEnemyCrew = -1;
    if (def->minEnemyCrew > -1)
    {
        if (def->maxEnemyCrew > def->minEnemyCrew)
        {
            triggerEnemyCrew = std::max(triggerEnemyCrew, def->minEnemyCrew + random32()%(def->maxEnemyCrew-def->minEnemyCrew+1));
        }
        else
        {
            triggerEnemyCrew = std::max(triggerEnemyCrew, def->minEnemyCrew);
        }
    }

    triggerPlayerDeaths = -1;
    if (def->minPlayerDeaths > -1)
    {
        currentPlayerCrew = GetPlayerCrew(def->playerDeathsCountClonebay);
        if (def->maxPlayerDeaths > def->minPlayerDeaths)
        {
            triggerPlayerDeaths = def->minPlayerDeaths + random32()%(def->maxPlayerDeaths-def->minPlayerDeaths+1);
        }
        else
        {
            triggerPlayerDeaths = def->minPlayerDeaths;
        }
    }

    triggerEnemyDeaths = -1;
    if (def->minEnemyDeaths > -1)
    {
        currentEnemyCrew = GetEnemyCrew(def->enemyDeathsCountClonebay);
        if (def->maxEnemyDeaths > def->minEnemyDeaths)
        {
            triggerEnemyDeaths = def->minEnemyDeaths + random32()%(def->maxEnemyDeaths-def->minEnemyDeaths+1);
        }
        else
        {
            triggerEnemyDeaths = def->minEnemyDeaths;
        }
    }
}

void TriggeredEvent::Update()
{
    ShipManager* ship;

    if (triggerTimer != nullptr)
    {
        triggerTimer->Update();

        float remainingTime = triggerTimer->currGoal - triggerTimer->currTime;
        for ( ; timerSoundIndex < def->timerSounds.size() && remainingTime <= def->timerSounds[timerSoundIndex].first; ++timerSoundIndex)
        {
            G_->GetSoundControl()->PlaySoundMix(def->timerSounds[timerSoundIndex].second, -1.f, false);
        }

        if (warning != nullptr)
        {
            if (remainingTime < warningTime) warning->Start();
        }

        if (triggerTimer->Done())
        {
            triggered = true;
        }
    }

    if (triggerPlayerHull >= 0)
    {
        ship = G_->GetShipManager(0);
        if (ship != nullptr)
        {
            if (ship->ship.hullIntegrity.first <= triggerPlayerHull)
            {
                triggered = true;
            }
        }
    }

    if (triggerEnemyHull >= 0)
    {
        ship = G_->GetShipManager(1);
        if (ship != nullptr)
        {
            if (ship->ship.hullIntegrity.first <= triggerEnemyHull)
            {
                triggered = true;
            }
        }
    }

    if (triggerPlayerCrew >= 0 && GetPlayerCrew(def->playerCrewCountClonebay) <= triggerPlayerCrew)
    {
        triggered = true;
    }

    if (triggerEnemyCrew >= 0 && GetEnemyCrew(def->enemyCrewCountClonebay) <= triggerEnemyCrew)
    {
        triggered = true;
    }

    if (triggerPlayerDamage >= 0)
    {
        ship = G_->GetShipManager(0);
        if (ship != nullptr)
        {
            int hull = ship->ship.hullIntegrity.first;
            int change = currentPlayerHull - hull;
            if (change<0 && !def->playerCountRepairs) change=0;
            currentPlayerHull = hull;
            triggerPlayerDamage -= change;
            if (triggerPlayerDamage <= 0)
            {
                triggered = true;
            }
        }
    }

    if (triggerEnemyDamage >= 0)
    {
        ship = G_->GetShipManager(1);
        if (ship != nullptr)
        {
            int hull = ship->ship.hullIntegrity.first;
            int change = currentEnemyHull - hull;
            if (change<0 && !def->enemyCountRepairs) change=0;
            currentEnemyHull = hull;
            triggerEnemyDamage -= change;
            if (triggerEnemyDamage <= 0)
            {
                triggered = true;
            }
        }
    }

    if (triggerPlayerDeaths >= 0)
    {
        int crew = GetPlayerCrew(def->playerDeathsCountClonebay);
        int change = currentPlayerCrew - crew;
        if (change<0 && !def->playerCountNewCrew) change=0;
        currentPlayerCrew = crew;
        triggerPlayerDeaths -= change;
        if (triggerPlayerDeaths <= 0)
        {
            triggered = true;
        }
    }

    if (triggerEnemyDeaths >= 0)
    {
        int crew = GetEnemyCrew(def->enemyDeathsCountClonebay);
        int change = currentEnemyCrew - crew;
        if (change<0 && !def->enemyCountNewCrew) change=0;
        currentEnemyCrew = crew;
        triggerEnemyDeaths -= change;
        if (triggerEnemyDeaths <= 0)
        {
            triggered = true;
        }
    }
}

void TriggeredEvent::OnRender()
{
    if (warning != nullptr)
    {
        warning->OnLoop();
        warning->OnRender();
    }
}

void TriggeredEvent::Jump()
{
    if (triggerJumps > 0)
    {
        if (--triggerJumps == 0)
        {
            triggered = true;
        }
    }
}

void TriggeredEvent::SaveAll(int file)
{
    FileHelper::writeInt(file, eventList.size());
    for (auto it=eventList.begin(); it!=eventList.end(); ++it)
    {
        FileHelper::writeString(file, it->first);
        it->second.Save(file);
    }
}

void TriggeredEvent::LoadAll(int file)
{
    TriggeredEvent::eventList.clear();
    TriggeredEventGui::GetInstance()->reset = true;

    int n = FileHelper::readInteger(file);

    for (unsigned int i=0; i<n; ++i)
    {
        std::string name = FileHelper::readString(file);
        TriggeredEventDefinition* def = &(TriggeredEventDefinition::defs.at(FileHelper::readInteger(file)));
        auto it = eventList.emplace(std::piecewise_construct, std::forward_as_tuple(def->name), std::forward_as_tuple(def));
        it.first->second.Load(file);
    }
}

void TriggeredEvent::Save(int file)
{
    FileHelper::writeInt(file, def->idx);
    FileHelper::writeInt(file, seed);
    FileHelper::writeInt(file, loops);
    if (triggerTimer != nullptr)
    {
        FileHelper::writeFloat(file, triggerTimer->currTime);
        FileHelper::writeFloat(file, triggerTimer->currGoal);
    }
    FileHelper::writeInt(file, triggerJumps);
    FileHelper::writeInt(file, triggerPlayerHull);
    FileHelper::writeInt(file, triggerEnemyHull);
    FileHelper::writeInt(file, triggerPlayerCrew);
    FileHelper::writeInt(file, triggerEnemyCrew);
    FileHelper::writeInt(file, triggerPlayerDamage);
    FileHelper::writeInt(file, triggerEnemyDamage);
    FileHelper::writeInt(file, triggerPlayerDeaths);
    FileHelper::writeInt(file, triggerEnemyDeaths);

    FileHelper::writeInt(file, currentPlayerHull);
    FileHelper::writeInt(file, currentEnemyHull);
    FileHelper::writeInt(file, currentPlayerCrew);
    FileHelper::writeInt(file, currentEnemyCrew);

    FileHelper::writeInt(file, triggered);
}

void TriggeredEvent::Load(int file)
{
    // def is read in LoadAll
    seed = FileHelper::readInteger(file);
    loops = FileHelper::readInteger(file);
    if (triggerTimer != nullptr)
    {
        triggerTimer->currTime = FileHelper::readFloat(file);
        triggerTimer->currGoal = FileHelper::readFloat(file);

        float remainingTime = triggerTimer->currGoal - triggerTimer->currTime;
        for (timerSoundIndex = 0; timerSoundIndex < def->timerSounds.size(); ++timerSoundIndex)
        {
            if (remainingTime > def->timerSounds[timerSoundIndex].first) break;
        }
    }
    triggerJumps = FileHelper::readInteger(file);
    triggerPlayerHull = FileHelper::readInteger(file);
    triggerEnemyHull = FileHelper::readInteger(file);
    triggerPlayerCrew = FileHelper::readInteger(file);
    triggerEnemyCrew = FileHelper::readInteger(file);
    triggerPlayerDamage = FileHelper::readInteger(file);
    triggerEnemyDamage = FileHelper::readInteger(file);
    triggerPlayerDeaths = FileHelper::readInteger(file);
    triggerEnemyDeaths = FileHelper::readInteger(file);

    currentPlayerHull = FileHelper::readInteger(file);
    currentEnemyHull = FileHelper::readInteger(file);
    currentPlayerCrew = FileHelper::readInteger(file);
    currentEnemyCrew = FileHelper::readInteger(file);

    triggered = FileHelper::readInteger(file);
}

HOOK_METHOD(WorldManager, CreateNewGame, () -> void)
{
    TriggeredEvent::eventList.clear();
    TriggeredEventGui::GetInstance()->reset = true;

    eventQueue.clear();

    super();
}

HOOK_METHOD_PRIORITY(StarMap, LoadGame, 100, (int file) -> Location*)
{
    auto ret = super(file);

    TriggeredEvent::LoadAll(file); // also clears

    eventQueue.clear();

    int eventQueueSize = FileHelper::readInteger(file);

    for (int i=0; i<eventQueueSize; ++i)
    {
        std::pair<std::string,int> event;
        event.first = FileHelper::readString(file);
        event.second = FileHelper::readInteger(file);
        eventQueue.push_back(event);
    }

    return ret;
}

HOOK_METHOD_PRIORITY(StarMap, SaveGame, 100, (int file) -> void)
{
    super(file);

    TriggeredEvent::SaveAll(file);

    FileHelper::writeInt(file, eventQueue.size());
    for (auto& event : eventQueue)
    {
        FileHelper::writeString(file, event.first);
        FileHelper::writeInt(file, event.second);
    }
}

void CheckEventQueue(WorldManager *world)
{
    while (!eventQueue.empty())
    {
        auto &nextEvent = eventQueue.front();

        CustomEventsParser::GetInstance()->LoadEvent(world, nextEvent.first, false, nextEvent.second);

        eventQueue.pop_front();

        if (world->commandGui->choiceBox.bOpen) return;
    }

    if (world->playerShip && !world->playerShip->shipManager->bJumping) TriggeredEvent::TriggerCheck();
}

HOOK_METHOD(WorldManager, OnLoop, () -> void)
{
    super();

    TriggeredEvent::UpdateAll();

    if (!commandGui->choiceBox.bOpen)
    {
        CheckEventQueue(this);
    }
}

HOOK_METHOD(WorldManager, PauseLoop, () -> void)
{
    super();

    if (!commandGui->choiceBox.bOpen)
    {
        CheckEventQueue(this);
    }
}

HOOK_METHOD(StarMap, UpdateDangerZone, () -> void)
{
    TriggeredEvent::JumpAll();
    super();
}

HOOK_METHOD(StarMap, StartSecretSector, () -> void)
{
    TriggeredEvent::JumpAll();
    super();
}

std::string TriggeredEventBox::GetTimeTextClock(int t)
{
    if (t >= 3600)
    {
        int h = t/3600;
        int m = (t/60)%60;
        int s = t%60;
        return boost::str(boost::format("%d:%02d:%02d") % h % m % s);
    }
    else
    {
        int m = t/60;
        int s = t%60;
        return boost::str(boost::format("%d:%02d") % m % s);
    }
}

std::string TriggeredEventBox::GetTimeTextSeconds(float t)
{
    return boost::str(boost::format("%.1f") % t);
}

void TriggeredEventBox::OnRender(bool flash)
{
    std::string text;

    bool useIcon2 = (event->triggerTimer != nullptr && event->GetTimeLeft() < boxDef->warningTime) || (event->triggerJumps <= boxDef->warningJumps);
    if (boxDef->flash) useIcon2 = useIcon2 && flash;

    if (useIcon2)
    {
        if (backgroundIcon2.get() != nullptr) CSurface::GL_RenderPrimitive(backgroundIcon2.get());
        CSurface::GL_SetColor(boxDef->textColor2);
    }
    else
    {
        if (backgroundIcon.get() != nullptr) CSurface::GL_RenderPrimitive(backgroundIcon.get());
        CSurface::GL_SetColor(boxDef->textColor);
    }

    if (foregroundIcon.get() != nullptr) CSurface::GL_RenderPrimitive(foregroundIcon.get());

    if (boxDef->textType == TriggeredEventBoxDefinition::TextType::JUMPS)
    {
        text = std::to_string(event->triggerJumps);
    }
    else
    {
        float t = event->GetTimeLeft();
        if (boxDef->textType == TriggeredEventBoxDefinition::TextType::TIME_CLOCK || t >= 60.f)
        {
            text = GetTimeTextClock(t);
        }
        else
        {
            text = GetTimeTextSeconds(t);
        }
    }

    freetype::easy_printCenter(0, text_x, text_y, text);
}

void TriggeredEventBox::MouseMove(int mx, int my)
{
    if (!boxDef->tooltip.data.empty() && mx > x && mx < x + width && my > y && my < y + height)
    {
        G_->GetMouseControl()->SetTooltip(boxDef->tooltip.GetText());
        G_->GetMouseControl()->InstantTooltip();
    }
}

void TriggeredEventGui::CreateBoxes()
{
    boxes.clear();
    delete scrapBox;
    scrapBox = nullptr;
    topRightBoxes.clear();
    combatBoxes.clear();

    std::vector<TriggeredEvent*> default_box_events;
    std::vector<TriggeredEvent*> scrap_box_events;
    std::vector<TriggeredEvent*> topright_box_events;
    std::vector<TriggeredEvent*> combat_box_events;

    for (auto& event: TriggeredEvent::eventList)
    {
        TriggeredEventBoxDefinition* box = event.second.def->box;
        if (box != nullptr)
        {
            if (box->boxPosition == TriggeredEventBoxDefinition::BoxPosition::SCRAP)
            {
                scrap_box_events.push_back(&event.second);
            }
            else if (box->boxPosition == TriggeredEventBoxDefinition::BoxPosition::TOPRIGHT)
            {
                topright_box_events.push_back(&event.second);
            }
            else if (box->boxPosition == TriggeredEventBoxDefinition::BoxPosition::COMBAT)
            {
                combat_box_events.push_back(&event.second);
            }
            else
            {
                default_box_events.push_back(&event.second);
            }
        }
    }

    std::sort(default_box_events.begin(), default_box_events.end(), [](const TriggeredEvent* a, const TriggeredEvent* b) -> bool {return a->def->box->priority > b->def->box->priority;});
    std::sort(scrap_box_events.begin(), scrap_box_events.end(), [](const TriggeredEvent* a, const TriggeredEvent* b) -> bool {return a->def->box->priority > b->def->box->priority;});
    std::sort(topright_box_events.begin(), topright_box_events.end(), [](const TriggeredEvent* a, const TriggeredEvent* b) -> bool {return a->def->box->priority > b->def->box->priority;});
    std::sort(combat_box_events.begin(), combat_box_events.end(), [](const TriggeredEvent* a, const TriggeredEvent* b) -> bool {return a->def->box->priority > b->def->box->priority;});

    int i = 0;
    int x = 132;
    int y = 82;
    for (auto event: default_box_events)
    {
        if (i>0) x += event->def->box->left;
        boxes.emplace_back(event, x, y);
        x += event->def->box->w + event->def->box->right;
        i++;
    }

    for (auto event: scrap_box_events)
    {
        x = (889 - event->def->box->w) / 2;
        y = 50 + event->def->box->top;
        scrapBox = new TriggeredEventBox(event, x, y);
        break;
    }

    i = 0;
    x = 1277;
    y = 3;
    for (auto event: topright_box_events)
    {
        if (i>0) x -= event->def->box->right;
        x -= event->def->box->w;
        topRightBoxes.emplace_back(event, x, y);
        x -= event->def->box->left;
        i++;
    }

    i = 0;
    y = 0;
    for (auto event: combat_box_events)
    {
        if (i>0) y += event->def->box->top;
        combatBoxes.emplace_back(event, -event->def->box->right-event->def->box->w, y);
        y += event->def->box->h + event->def->box->bottom;
        i++;
    }

    reset = false;
}

void TriggeredEventGui::OnRender()
{
    if (reset) CreateBoxes();

    flashTracker.Update();
    bool flash = flashTracker.current_time < 0.5f;

    for (auto& box: boxes)
    {
        box.OnRender(flash);
    }

    if (scrapBox != nullptr)
    {
        scrapBox->OnRender(flash);
    }

    for (auto& box: topRightBoxes)
    {
        box.OnRender(flash);
    }
}

void TriggeredEventGui::OnRenderCombat(CombatControl* this2)
{
    if (reset) CreateBoxes();

    bool flash = flashTracker.current_time < 0.5f;

    if (this2->currentTarget)
    {
        Point combatOffset = this2->boss_visual ? bossBoxPos : normalBoxPos;

        CSurface::GL_PushMatrix();
        CSurface::GL_Translate(combatOffset.x, combatOffset.y, 0.0);
        for (auto& box: combatBoxes)
        {
            box.OnRender(flash);
        }
        CSurface::GL_PopMatrix();
    }
}

void TriggeredEventGui::MouseMove(int x, int y)
{
    for (auto& box: boxes)
    {
        box.MouseMove(x, y);
    }

    if (scrapBox != nullptr)
    {
        scrapBox->MouseMove(x, y);
    }

    for (auto& box: topRightBoxes)
    {
        box.MouseMove(x, y);
    }

    if (G_->GetWorld()->commandGui->combatControl.currentTarget)
    {
        Point combatOffset = G_->GetWorld()->commandGui->combatControl.boss_visual ? bossBoxPos : normalBoxPos;

        for (auto& box: combatBoxes)
        {
            box.MouseMove(x - combatOffset.x, y - combatOffset.y);
        }
    }
}

HOOK_METHOD(ShipStatus, OnRender, () -> void)
{
    super();
    TriggeredEventGui::GetInstance()->OnRender();
    TriggeredEvent::RenderAll();
}

HOOK_METHOD(CombatControl, RenderTarget, () -> void)
{
    super();
    TriggeredEventGui::GetInstance()->OnRenderCombat(this);
}

HOOK_METHOD(CommandGui, MouseMove, (int x, int y) -> void)
{
    super(x, y);
    TriggeredEventGui::GetInstance()->MouseMove(x, y);
}
