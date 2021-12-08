#include "CustomShipSelect.h"
#include "CustomOptions.h"
#include "freetype.h"
#include "Seeds.h"
#include "ShipUnlocks.h"
#include "EnemyShipIcons.h"
#include "Resources.h"
#include <algorithm>
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>

CustomShipSelect CustomShipSelect::instance = CustomShipSelect();


void CustomShipSelect::EarlyParseShipsNode(rapidxml::xml_node<char> *node)
{
    // parse <ships> node in hyperspace.xml
    try
    {
        for (auto child = node->first_node(); child; child = child->next_sibling())
        {
            std::string name = child->name();

            if (name == "customShip" && !child->first_attribute("name"))
            {
                CustomShipDefinition &def = GetDefaultDefinition();

                ParseCustomShipNode(child, def);
            }
        }
    }
    catch (std::exception)
    {
        MessageBoxA(GetDesktopWindow(), "Error parsing <ships> in hyperspace.xml", "Error", MB_ICONERROR | MB_SETFOREGROUND);
    }
}

void CustomShipSelect::ParseShipsNode(rapidxml::xml_node<char> *node)
{
    // parse <ships> node in hyperspace.xml
    try
    {
        if (node->first_attribute("hideFirstShipPage"))
        {
            hideFirstPage = EventsParser::ParseBoolean(node->first_attribute("hideFirstShipPage")->value());
        }

        for (auto child = node->first_node(); child; child = child->next_sibling())
        {
            std::string name = child->name();


            if (name == "shipIcons")
            {
                ShipIconManager::instance->ParseShipIconNode(child);
            }

            if (name == "ship")
            {
                if (child->first_attribute("name"))
                {
                    std::string shipName = std::string(child->first_attribute("name")->value());

                    ShipButtonDefinition buttonDef = ShipButtonDefinition();
                    buttonDef.name = shipName;

                    if (child->first_attribute("a"))
                    {
                        if (strcmp(child->first_attribute("a")->value(), "dlc") == 0)
                        {
                            buttonDef.typeA = 2;
                        }
                        else
                        {
                            buttonDef.typeA = EventsParser::ParseBoolean(child->first_attribute("a")->value()) ? 1 : 0;
                        }
                    }
                    if (child->first_attribute("b"))
                    {
                        if (strcmp(child->first_attribute("b")->value(), "dlc") == 0)
                        {
                            buttonDef.typeB = 2;
                        }
                        else
                        {
                            buttonDef.typeB = EventsParser::ParseBoolean(child->first_attribute("b")->value()) ? 1 : 0;
                        }
                    }
                    if (child->first_attribute("c"))
                    {
                        if (strcmp(child->first_attribute("c")->value(), "dlc") == 0)
                        {
                            buttonDef.typeC = 2;
                        }
                        else
                        {
                            buttonDef.typeC = EventsParser::ParseBoolean(child->first_attribute("c")->value()) ? 1 : 0;
                        }
                    }
                    if (child->first_attribute("secret"))
                    {
                        buttonDef.secretCruiser = EventsParser::ParseBoolean(child->first_attribute("secret")->value());
                    }
                    if (child->first_attribute("noAppend"))
                    {
                        buttonDef.noAppend = EventsParser::ParseBoolean(child->first_attribute("noAppend")->value());
                    }

                    if (G_->GetScoreKeeper()->GetShipId(shipName).first == -1)
                    {
                        shipButtonDefs.push_back(buttonDef);
                    }

                    for (auto shipChild = child->first_node(); shipChild; shipChild = shipChild->next_sibling())
                    {
                        if (strcmp(shipChild->name(), "unlock") == 0)
                        {
                            CustomShipUnlocks::instance->ParseUnlockNode(shipChild, shipName);
                        }
                    }
                }
            }

            if (name == "shipOrder")
            {
                for (auto shipChild = child->first_node(); shipChild; shipChild = shipChild->next_sibling())
                {
                    if (strcmp(shipChild->name(), "ship") == 0)
                    {
                        customShipOrder.push_back(shipChild->value());
                    }
                    if (strcmp(shipChild->name(), "empty") == 0)
                    {
                        customShipOrder.push_back("empty");
                    }
                }
            }

            if (name == "hangarAnims")
            {
                for (auto animChild = child->first_node(); animChild; animChild = animChild->next_sibling())
                {
                    if (strcmp(animChild->name(), "anim") == 0)
                    {
                        Point pos = Point();
                        if (animChild->first_attribute("x"))
                        {
                            pos.x = boost::lexical_cast<int>(animChild->first_attribute("x")->value());
                        }
                        if (animChild->first_attribute("y"))
                        {
                            pos.y = boost::lexical_cast<int>(animChild->first_attribute("y")->value());
                        }
                        customAnimDefs.push_back(std::pair<Point, std::string>(pos, animChild->value()));
                    }
                }
            }

            if (name == "customShip" && child->first_attribute("name"))
            {
                std::string shipName = child->first_attribute("name")->value();
                bool exists = shipDefs.find(shipName) != shipDefs.end();

                CustomShipDefinition &def = shipDefs[shipName];
                if (child->first_attribute("load"))
                {
                    std::string loadName = child->first_attribute("load")->value();
                    if (shipDefs.find(loadName) != shipDefs.end())
                    {
                        def = CustomShipDefinition(shipDefs[loadName]);
                    }
                }
                else if (!exists)
                {
                    def = CustomShipDefinition(GetDefaultDefinition());
                }

                def.name = shipName;

                ParseCustomShipNode(child, def);
            }
        }
    }
    catch (std::exception)
    {
        MessageBoxA(GetDesktopWindow(), "Error parsing <ships> in hyperspace.xml", "Error", MB_ICONERROR | MB_SETFOREGROUND);
    }
}

HOOK_METHOD(BlueprintManager, ProcessShipBlueprint, (ShipBlueprint* bp, BlueprintManager *bpM, rapidxml::xml_node<char>* node) -> ShipBlueprint*)
{
    auto ret = super(bp, bpM, node);

    CustomShipSelect::GetInstance()->ParseVanillaShipNode(node);

    return ret;
}

void CustomShipSelect::ParseVanillaShipNode(rapidxml::xml_node<char> *node)
{
    std::string shipName = node->first_attribute("name")->value();

    CustomShipDefinition &def = shipDefs[shipName];
    def = CustomShipDefinition(GetDefaultDefinition());

    bool isCustom = ParseCustomShipNode(node, def);

    if (!isCustom) shipDefs.erase(shipName);
}

bool CustomShipSelect::ParseCustomShipNode(rapidxml::xml_node<char> *node, CustomShipDefinition &def)
{
    bool isCustom = false;

    for (auto shipNode = node->first_node(); shipNode; shipNode = shipNode->next_sibling())
    {
        std::string name = std::string(shipNode->name());
        std::string val = std::string(shipNode->value());

        if (name == "hiddenAug")
        {
            isCustom = true;
            if (def.hiddenAugs.find(val) == def.hiddenAugs.end())
            {
                def.hiddenAugs[val] = 1;
            }
            else
            {
                def.hiddenAugs[val]++;
            }
        }
        if (name == "crewLimit")
        {
            isCustom = true;
            def.crewLimit = boost::lexical_cast<int>(val);
        }
        if (name == "shipIcons")
        {
            isCustom = true;
            for (auto iconNode = shipNode->first_node(); iconNode; iconNode = iconNode->next_sibling())
            {
                std::string iconName = iconNode->name();

                if (iconName == "shipIcon")
                {
                    def.shipIcons.push_back(iconNode->value());
                }
            }
        }
        if (name == "rooms")
        {
            isCustom = true;
            for (auto roomNode = shipNode->first_node(); roomNode; roomNode = roomNode->next_sibling())
            {
                if (strcmp(roomNode->name(), "room") == 0 && roomNode->first_attribute("id"))
                {
                    RoomDefinition* roomDef = new RoomDefinition();

                    int roomId = boost::lexical_cast<int>(roomNode->first_attribute("id")->value());

                    for (auto roomDefNode = roomNode->first_node(); roomDefNode; roomDefNode = roomDefNode->next_sibling())
                    {
                        std::string roomName = roomDefNode->name();
                        std::string roomValue = roomDefNode->value();

                        if (roomName == "roomAnim")
                        {
                            auto def = RoomAnimDef();

                            def.animName = roomValue;

                            if (roomDefNode->first_attribute("renderLayer"))
                            {
                                def.renderLayer = boost::lexical_cast<int>(roomDefNode->first_attribute("renderLayer")->value());
                            }

                            roomDef->roomAnims.push_back(def);
                        }
                        if (roomName == "sensorBlind")
                        {
                            roomDef->sensorBlind = EventsParser::ParseBoolean(roomValue);
                        }
                        if (roomName == "sysDamageResistChance")
                        {
                            roomDef->sysDamageResistChance = boost::lexical_cast<float>(roomValue);
                        }
                        if (roomName == "ionDamageResistChance")
                        {
                            roomDef->ionDamageResistChance = boost::lexical_cast<float>(roomValue);
                        }
                    }

                    def.roomDefs[roomId] = roomDef;
                }
            }
        }
        if (name == "crew")
        {
            isCustom = true;
            for (auto crewNode = shipNode->first_node(); crewNode; crewNode = crewNode->next_sibling())
            {
                int roomId = 0;
                std::string crewName = "";
                auto crewDef = CrewPlacementDefinition();

                crewDef.species = crewNode->name();

                if (crewNode->first_attribute("room"))
                {
                    crewDef.roomId = boost::lexical_cast<int>(crewNode->first_attribute("room")->value());
                }
                if (crewNode->first_attribute("name"))
                {
                    crewDef.name = crewNode->first_attribute("name")->value();
                }
                if (crewNode->first_attribute("list"))
                {
                    crewDef.isList = EventsParser::ParseBoolean(crewNode->first_attribute("list")->value());
                }

                def.crewList.push_back(crewDef);
            }
        }
        if (name == "noJump")
        {
            isCustom = true;
            def.noJump = true;
        }
        if (name == "noFuelStalemate")
        {
            isCustom = true;
            def.noFuelStalemate = true;
        }
        if (name == "hpCap")
        {
            isCustom = true;
            def.hpCap = boost::lexical_cast<int>(val);
        }
        if (name == "startingFuel")
        {
            isCustom = true;
            def.startingFuel = boost::lexical_cast<int>(val);
        }
        if (name == "startingScrap")
        {
            isCustom = true;
            def.startingScrap = boost::lexical_cast<int>(val);
        }
        if (name == "autoShipForce")
        {
            isCustom = true;
            def.forceAutomated = EventsParser::ParseBoolean(val);
        }
        if (name == "systemLimit")
        {
            isCustom = true;
            def.systemLimit = boost::lexical_cast<int>(val);
        }
        if (name == "subsystemLimit")
        {
            isCustom = true;
            def.subsystemLimit = boost::lexical_cast<int>(val);
        }
        if (name == "customReactor")
        {
            isCustom = true;
            if(shipNode->first_attribute("maxLevel")) def.maxReactorLevel = boost::lexical_cast<int>(shipNode->first_attribute("maxLevel")->value());
            if(def.maxReactorLevel < 0) def.maxReactorLevel = 0;
            if(def.maxReactorLevel > 25) def.reactorPrices.resize(ceil(def.maxReactorLevel / 5 + 1), -1);
            for (auto reactorNode = shipNode->first_node(); reactorNode; reactorNode = reactorNode->next_sibling())
            {
                std::string reactName = reactorNode->name();

                if(reactName == "baseCost") def.reactorPrices[0] = boost::lexical_cast<int>(reactorNode->value());
                if(reactName == "increment") def.reactorPriceIncrement = boost::lexical_cast<int>(reactorNode->value());
                if(reactName == "overrideCost") {
                    int coloumn = 0;
                    if (reactorNode->first_attribute("coloumn")) coloumn = boost::lexical_cast<int>(reactorNode->first_attribute("coloumn")->value());
                    if (reactorNode->first_attribute("column")) coloumn = boost::lexical_cast<int>(reactorNode->first_attribute("column")->value());
                    def.reactorPrices[coloumn] = boost::lexical_cast<int>(reactorNode->value());
                }
            }
        }
        if (name == "shipGenerator")
        {
            isCustom = true;
            def.shipGenerator = val;
        }

    }

    return isCustom;
}

void CustomShipSelect::OnInit(ShipSelect* shipSelect_)
{
    if (!initialized)
    {
        auto toAdd = std::vector<std::string>();

        for (const ShipButtonDefinition& i : shipButtonDefs)
        {
            if (!i.noAppend)
            {
                if (std::find(customShipOrder.begin(), customShipOrder.end(), i.name) == customShipOrder.end())
                {
                    toAdd.push_back(i.name);
                }
            }
        }

        customShipOrder.insert(customShipOrder.end(), toAdd.begin(), toAdd.end());

        for (auto i : customAnimDefs)
        {
            auto newAnim = new Animation();

            AnimationControl::GetAnimation(*newAnim, G_->GetAnimationControl(), i.second);
            newAnim->SetCurrentFrame(0);
            newAnim->tracker.SetLoop(true, 0);
            newAnim->Start(true);

            customAnims.push_back(std::pair<Point, Animation*>(i.first, newAnim));
        }
    }

    maxShipPage = std::ceil(customShipOrder.size() / 10.f);

    if (hideFirstPage && shipPage == 0)
    {
        shipPage = 1;
    }

    if (maxShipPage <= 0)
        maxShipPage = 0;
    else if (!initialized)
    {
        for (int i = 0; i < (customShipOrder.size()); i++)
        {
            int shipId = 0;
            shipId = GetShipButtonIdFromName(customShipOrder[i]);


            if (shipId == -1)
                continue;

            ShipButtonDefinition &x = shipButtonDefs[shipId];

            // create and initialize ShipButtons for each of the blueprints
            int curPage = i / 10;

            ShipButton* buttons[3];

            int onPage = i % 10;

            for (int variant = 0; variant < 3; ++variant)
            {
                buttons[variant] = new ShipButton(100 + shipId, variant);

                if (!x.VariantExists(variant))
                {
                    buttons[variant]->bNoExist = true;
                    buttons[variant]->bActive = false;
                }
            }

            ShipButtonList* buttonList = new ShipButtonList(curPage, 100 + shipId, buttons[0], buttons[1], buttons[2]);
            shipButtons.push_back(buttonList);


            Point pos = Point(0, 0);
            if (onPage < 4)
            {
                pos = Point(136 + 205 * onPage, 161);
            }
            else if (onPage < 8)
            {
                pos = Point(136 + 205 * 3 - 205 * (onPage - 4), 161 + 177);
            }
            else if (onPage == 8)
            {
                pos = Point(136 + 205 * 3 + 225, 161);
            }
            else if (onPage == 9)
            {
                pos = Point(136 + 205 * 3 + 225, 161 + 177);
            }

            //int oldY = pos.y;

            for (int variant = 0; variant < 3; ++variant)
            {
                if (x.VariantExists(variant))
                {
                    std::string finalName = GetVariantName(x.name, variant);

                    buttons[variant]->achievements.resize(5, nullptr);

                    if (CustomShipUnlocks::instance->CustomShipHasUnlock(finalName))
                    {
                        buttons[variant]->bShipLocked = !CustomShipUnlocks::instance->GetCustomShipUnlocked(finalName);
                        buttons[variant]->bLayoutLocked = buttons[variant]->bShipLocked;
                    }

                    if (x.splitVictoryAchievement)
                    {
                        buttons[variant]->achievements[3] = CustomShipUnlocks::instance->GetVictoryAchievement(finalName);
                    }
                    else
                    {
                        buttons[variant]->achievements[3] = CustomShipUnlocks::instance->GetVictoryAchievement(x.name);
                    }

                    if (x.splitUnlockQuestAchievement)
                    {
                        if (CustomShipUnlocks::instance->CustomShipHasUnlockQuest(finalName))
                        {
                            buttons[variant]->achievements[4] = CustomShipUnlocks::instance->GetQuestAchievement(finalName);
                        }
                    }
                    else
                    {
                        if (CustomShipUnlocks::instance->CustomShipHasUnlockQuestAnyLayout(x.name))
                        {
                            buttons[variant]->achievements[4] = CustomShipUnlocks::instance->GetQuestAchievement(x.name);
                        }
                    }

                    while (!buttons[variant]->achievements.empty() && buttons[variant]->achievements.back() == nullptr) buttons[variant]->achievements.pop_back();
                    buttons[variant]->achievements.shrink_to_fit();
                }

//                if (!(buttons[variant]->bNoExist || buttons[variant]->bShipLocked))
//                    pos.y = oldY + 20;
//                else
//                    pos.y = oldY;

                buttons[variant]->OnInit("customizeUI/ship_list_button", pos);
            }
        }
    }
    else
    {
        int i = 0;
        for (auto x : shipButtons)
        {
            std::string shipName = GetShipBlueprint(x->GetId());

            ShipButton *aButton = x->GetButton(0);
            ShipButton *bButton = x->GetButton(1);
            ShipButton *cButton = x->GetButton(2);

            if (!aButton->bNoExist)
            {
                if (CustomShipUnlocks::instance->CustomShipHasUnlock(shipName))
                {
                    aButton->bShipLocked = !CustomShipUnlocks::instance->GetCustomShipUnlocked(shipName);
                    aButton->bLayoutLocked = aButton->bShipLocked;
                }
            }
            if (!bButton->bNoExist)
            {
                if (CustomShipUnlocks::instance->CustomShipHasUnlock(shipName + "_2"))
                {
                    bButton->bShipLocked = !CustomShipUnlocks::instance->GetCustomShipUnlocked(shipName + "_2");
                    bButton->bLayoutLocked = bButton->bShipLocked;
                }
            }
            if (!cButton->bNoExist)
            {
                if (CustomShipUnlocks::instance->CustomShipHasUnlock(shipName + "_3"))
                {
                    cButton->bShipLocked = !CustomShipUnlocks::instance->GetCustomShipUnlocked(shipName + "_3");
                    cButton->bLayoutLocked = cButton->bShipLocked;
                }
            }
        }
    }




    std::string buttonImg("customizeUI/button_ship_arrow");
    leftButton = new Button();
    leftButton->OnInit(buttonImg, 1100, 119);

    rightButton = new Button();
    rightButton->OnInit(buttonImg, 1135, 119);

    rightButton->bMirror = true;

    if (maxShipPage == 0 || (maxShipPage == 1 && hideFirstPage))
    {
        leftButton->bActive = false;
        rightButton->bActive = false;
    }


    shipSelect = shipSelect_;
    oldShipButtons = shipSelect->shipButtons;

    UpdateFilteredAchievements();

    initialized = true;
}

void CustomShipSelect::UpdateFilteredAchievements()
{
    CustomShipUnlocks *customUnlocks = CustomShipUnlocks::instance;

    std::vector<std::string> victoryTypes;
    for (std::string &i : shipVictoryFilters)
    {
        if (!customUnlocks->customVictories[i].secret || (customUnlocks->customShipVictories.count(i) && !customUnlocks->customShipVictories[i].empty()))
        {
            victoryTypes.push_back(i);
        }
    }
    if (victoryTypes.size() > 3) victoryTypes.resize(3);

    for (auto x : shipButtons)
    {
        std::string shipName = GetShipBlueprint(x->GetId());

        int shipId = GetShipButtonIdFromName(shipName);

        if (shipId == -1)
            continue;

        ShipButtonDefinition &buttonDef = shipButtonDefs[shipId];

        for (auto variant=0; variant<3; ++variant)
        {
            ShipButton *button = x->GetButton(variant);

            if (!button->bNoExist)
            {
                std::string finalName = GetVariantName(shipName, variant);

                for (auto i=0; i<3; ++i)
                {
                    CAchievement *ach = nullptr;

                    if (i < victoryTypes.size())
                    {
                        CustomVictoryAchievement &victoryAch = CustomShipUnlocks::instance->customVictories[victoryTypes[i]];

                        if (buttonDef.splitVictoryAchievement)
                        {
                            ach = victoryAch.GetVictoryAchievement(finalName);
                        }
                        else
                        {
                            ach = victoryAch.GetVictoryAchievement(shipName);
                        }
                    }

                    if (button->achievements.size() > i)
                    {
                        button->achievements[i] = ach;
                    }
                    else
                    {
                        button->achievements.push_back(ach);
                    }
                }
            }
        }
    }
}

void CustomShipSelect::OnRender(bool renderSelect)
{
    if (shipSelect->tutorial.bOpen)
    {
        GL_Color tint(0.5f, 0.5f, 0.5f, 1.f);
        CSurface::GL_SetColorTint(tint);
    }

    if (renderSelect)
    {
        for (auto const &x: shipButtons)
        {
            if (x->GetPage() == shipPage - 1)
            {
                ShipButton* button = x->GetButton(shipSelect->currentType);

                if (button)
                    button->OnRender();
            }
        }
    }
    else
    {
        leftButton->OnRender();
        rightButton->OnRender();

        char buf[128];



        if (hideFirstPage)
        {
            sprintf(buf, "%d/%d", GetCurrentPage(), GetMaxPages());
        }
        else
        {
            sprintf(buf, "%d/%d", GetCurrentPage() + 1, GetMaxPages() + 1);
        }

        std::string text(buf);

        CSurface::GL_SetColor(COLOR_BUTTON_TEXT);
        CSurface::GL_RemoveColorTint();
        freetype::easy_printRightAlign(63, 1097, 118, text);
    }

    if (selectedShip == -1)
    {
        CustomShipUnlocks *customUnlocks = CustomShipUnlocks::instance;

        std::string imagePath = "customizeUI/box_shipach2.png";
        G_->GetResources()->RenderImageString(imagePath, 515, 525, 0, GL_Color(1.f,1.f,1.f,1.f), 1.f, false);
        freetype::easy_printCenter(13, 640, 544, G_->GetTextLibrary()->GetText("hangar_achievements_title_custom"));

        std::vector<std::string> victoryTypes;
        for (std::string &i : customUnlocks->customVictoryTypes)
        {
            if (!customUnlocks->customVictories[i].secret || (customUnlocks->customShipVictories.count(i) && !customUnlocks->customShipVictories[i].empty()))
            {
                victoryTypes.push_back(i);
            }
        }

        int max_a = victoryTypes.size()%6;
        int max_b = victoryTypes.size()/6;
        for (int i=0; i<victoryTypes.size(); ++i)
        {
            int a = i%6;
            int b = i/6;

            Point pos = Point(640 - 17*(b==max_b ? max_a : 6) + 34*a, 607 - 17*((victoryTypes.size()+5)/6) + 34*b);

            if (std::find(shipVictoryFilters.begin(), shipVictoryFilters.end(), victoryTypes[i]) != shipVictoryFilters.end())
            {
                imagePath = "achievements/"+customUnlocks->customVictories[victoryTypes[i]].icon+"_on.png";
            }
            else
            {
                imagePath = "achievements/"+customUnlocks->customVictories[victoryTypes[i]].icon+"_off.png";
            }

            G_->GetResources()->RenderImageString(imagePath, pos.x, pos.y, 0, GL_Color(1.f,1.f,1.f,1.f), 1.f, false);

            if (i == selectedVictoryFilter)
            {
                CSurface::GL_DrawRectOutline(pos.x, pos.y, 32, 32, GL_Color(255.f/255.f,230.f/255.f,94.f/255.f,1.f), 2);
            }
        }
    }

    shipSelect->infoBox.OnRender();

    if (shipSelect->tutorial.bOpen)
    {
        CSurface::GL_RemoveColorTint();
    }
}

void CustomShipSelect::MouseClick()
{
    if (leftButton->bActive && leftButton->bHover)
    {
        if (hideFirstPage)
        {
            if (shipPage == 1)
            {
                SwitchPage(maxShipPage);
            }
            else
            {
                SwitchPage(shipPage - 1);
            }
        }
        else
        {
            if (shipPage == 0)
            {
                SwitchPage(maxShipPage);
            }
            else
            {
                SwitchPage(shipPage - 1);
            }
        }
    }

    if (rightButton->bActive && rightButton->bHover)
    {
        if (hideFirstPage)
        {
            if (shipPage == maxShipPage)
            {
                SwitchPage(1);
            }
            else
            {
                SwitchPage(shipPage + 1);
            }
        }
        else
        {
            if (shipPage == maxShipPage)
            {
                SwitchPage(0);
            }
            else
            {
                SwitchPage(shipPage + 1);
            }
        }
    }

    if (selectedShip == -1 && selectedVictoryFilter != -1)
    {
        CustomShipUnlocks *customUnlocks = CustomShipUnlocks::instance;

        std::vector<std::string> victoryTypes;
        std::vector<std::string> enabledVictoryFilters;
        for (std::string &i : customUnlocks->customVictoryTypes)
        {
            if (!customUnlocks->customVictories[i].secret || (customUnlocks->customShipVictories.count(i) && !customUnlocks->customShipVictories[i].empty()))
            {
                victoryTypes.push_back(i);
            }
        }
        for (std::string &i : shipVictoryFilters)
        {
            if (!customUnlocks->customVictories[i].secret || (customUnlocks->customShipVictories.count(i) && !customUnlocks->customShipVictories[i].empty()))
            {
                enabledVictoryFilters.push_back(i);
            }
        }

        std::string clickedVictoryFilter = victoryTypes[selectedVictoryFilter];

        auto it = std::find(enabledVictoryFilters.begin(), enabledVictoryFilters.end(), clickedVictoryFilter);

        if (it != enabledVictoryFilters.end())
        {
            enabledVictoryFilters.erase(it);
            G_->GetSoundControl()->PlaySoundMix("powerDownSystem", -1.f, false);
        }
        else
        {
            if (enabledVictoryFilters.size() >= 3)
            {
                enabledVictoryFilters.erase(enabledVictoryFilters.begin());
            }
            enabledVictoryFilters.push_back(clickedVictoryFilter);
            G_->GetSoundControl()->PlaySoundMix("powerUpSystem", -1.f, false);
        }

        shipVictoryFilters = enabledVictoryFilters;
        UpdateFilteredAchievements();
    }
}

void CustomShipSelect::SwitchPage(int page)
{
    if (shipPage == page)
        return;


    if (shipPage == 0)
    {
        LeaveFirstPage();
    }

    if (page == 0)
    {
        EnterFirstPage();
    }

    shipPage = page;
}

void CustomShipSelect::LeaveFirstPage()
{
    for (auto const &x: oldShipButtons)
    {
        x->bActive = false;
    }
}

void CustomShipSelect::EnterFirstPage()
{
    for (auto const &x: oldShipButtons)
    {
        if (!x->bNoExist)
            x->bActive = true;
    }
}

bool CustomShipSelect::ShouldRenderButton(ShipButton *button)
{
    if (shipPage != 0 &&
            std::find(oldShipButtons.begin(), oldShipButtons.end(), button) != oldShipButtons.end())
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool CustomShipSelect::ShouldRenderArrow()
{
    return shipPage == 0;
}

bool CustomShipSelect::ShouldRenderButtonLower()
{
    return shipPage == 0;
}

void CustomShipSelect::MouseMove(int x, int y)
{
    if (shipSelect->tutorial.bOpen)
        return;
    leftButton->MouseMove(x, y, false);
    rightButton->MouseMove(x, y, false);

    selectedShip = -1;
    int lockedSelectedShip = -1;

    for (auto const &i: shipButtons)
    {
        if (i->GetPage() == shipPage - 1)
        {
            ShipButton* button = i->GetButton(shipSelect->currentType);

            if (button)
            {
                button->MouseMove(x, y);
                if (button->bHover && button->bActive)
                {
                    if (button->bLayoutLocked)
                    {
                        lockedSelectedShip = i->GetIndex();
                    }
                    else
                    {
                        selectedShip = i->GetIndex();
                        lastSelectedShip = selectedShip;
                    }
                }
            }
        }
    }

    if (!FirstPage())
    {
        if (selectedShip == -1 && lockedSelectedShip == -1)
            shipSelect->infoBox.Clear();
        else
        {
            bool showUnlock = false;

            int shipId = selectedShip;
            if (selectedShip == -1 && lockedSelectedShip != -1)
            {
                shipId = lockedSelectedShip;
                showUnlock = true;
            }

            std::string name(shipButtonDefs[shipId].name);

            if (shipSelect->currentType == 1)
            {
                name.append("_2");
            }
            else if (shipSelect->currentType == 2)
            {
                name.append("_3");
            }

            ShipBlueprint* bp = G_->GetBlueprints()->GetShipBlueprint(name, -1);

            if (showUnlock)
            {
                auto shipButton = GetShipButtonDefinition(lockedSelectedShip);

                std::string title = bp->shipClass.GetText();

                if (shipSelect->currentType == 0)
                {
                    title.append(" " + G_->GetTextLibrary()->GetText("type_a"));
                }
                if (shipSelect->currentType == 1)
                {
                    title.append(" " + G_->GetTextLibrary()->GetText("type_b"));
                }
                if (shipSelect->currentType == 2)
                {
                    title.append(" " + G_->GetTextLibrary()->GetText("type_c"));
                }

                if (shipButton.secretCruiser)
                {
                    title = G_->GetTextLibrary()->GetText("unidentified");
                }


                shipSelect->infoBox.SetText(title, bp->unlock.GetText(), 360, 176, InfoBox::ExpandDir::EXPAND_DOWN);
            }
            else
            {
                shipSelect->infoBox.SetDescription(&bp->desc, 360, 135, InfoBox::ExpandDir::EXPAND_DOWN);
            }
        }
    }


    shipSelect->typeA.MouseMove(x, y, false);
    shipSelect->typeB.MouseMove(x, y, false);
    shipSelect->typeC.MouseMove(x, y, false);

    if (selectedShip == -1)
    {
        CustomShipUnlocks *customUnlocks = CustomShipUnlocks::instance;

        selectedVictoryFilter = -1;
        std::vector<std::string> victoryTypes;
        for (std::string &i : customUnlocks->customVictoryTypes)
        {
            if (!customUnlocks->customVictories[i].secret || (customUnlocks->customShipVictories.count(i) && !customUnlocks->customShipVictories[i].empty()))
            {
                victoryTypes.push_back(i);
            }
        }

        int max_a = victoryTypes.size()%6;
        int max_b = victoryTypes.size()/6;
        for (int i=0; i<victoryTypes.size(); ++i)
        {
            int a = i%6;
            int b = i/6;

            Point pos(640 - 17*(b==max_b ? max_a : 6) + 34*a, 607 - 17*((victoryTypes.size()+5)/6) + 34*b);

            if (x > pos.x && x < pos.x+32 && y > pos.y && y < pos.y+32)
            {
                std::string name = customUnlocks->customVictories[victoryTypes[i]].name.GetText();
                boost::algorithm::replace_all(name, "\\1", "");
                boost::algorithm::trim(name);

                G_->GetMouseControl()->SetTooltip(name);
                G_->GetMouseControl()->InstantTooltip();
                selectedVictoryFilter = i;
            }
        }
    }
}

std::string CustomShipSelect::GetShipBlueprint(int shipId)
{
    int customIndex = shipId - 100;

    return shipButtonDefs[customIndex].name;
}


void CustomShipSelect::SwitchShip(ShipBuilder *builder, int type, int variant, bool force)
{
    if (type == builder->currentShipId && variant == builder->currentType && !(force))
        return;




    auto oldShip = builder->currentShip;

    ShipButtonDefinition def = shipButtonDefs[type - 100];
    std::string name( def.name );

    if (variant == 1)
    {
        name.append("_2");
    }
    else if (variant == 2)
    {
        name.append("_3");
    }

    ShipBlueprint* bp = G_->GetBlueprints()->GetShipBlueprint(name, -1);

    if (bp)
    {
        ShipManager *ship = new ShipManager(0);
        ship->OnInit(bp, 0);

        builder->currentShip = ship;
        builder->currentShipId = type;
        builder->currentType = variant;

        std::string shipRealName = std::string();
        shipRealName = ship->myBlueprint.name.GetText();

        builder->currentName.swap(shipRealName);
        builder->nameInput.SetText(builder->currentName);

        builder->CreateEquipmentBoxes();
        builder->CreateSystemBoxes();
        builder->SetupShipAchievements();

        builder->ClearShipAchievements();

        if (!def.typeA || !CustomShipUnlocks::instance->GetCustomShipUnlocked(def.name))
        {
            builder->typeA.bActive = false;
            builder->typeA.bRenderOff = true;
            builder->typeA.bRenderSelected = false;
        }
        else
        {
            builder->typeA.SetActive(variant != 0);
            builder->typeA.bRenderOff = false;
            builder->typeA.bRenderSelected = variant == 0;
        }

        if (!def.typeB || !CustomShipUnlocks::instance->GetCustomShipUnlocked(def.name + "_2"))
        {
            builder->typeB.bActive = false;
            builder->typeB.bRenderOff = true;
            builder->typeB.bRenderSelected = false;
        }
        else
        {
            builder->typeB.SetActive(variant != 1);

            builder->typeB.bRenderOff = false;
            builder->typeB.bRenderSelected = variant == 1;
        }

        if (!def.typeC || !CustomShipUnlocks::instance->GetCustomShipUnlocked(def.name + "_3"))
        {
            builder->typeC.bActive = false;
            builder->typeC.bRenderOff = true;
            builder->typeC.bRenderSelected = false;
        }
        else
        {
            builder->typeC.SetActive(variant != 2);
            builder->typeC.bRenderOff = false;
            builder->typeC.bRenderSelected = variant == 2;
        }

        Point typeAPos(builder->typeALoc.x + builder->typeAOffset, builder->typeALoc.y);
        builder->typeA.SetLocation(typeAPos);

        Point typeBPos(builder->typeBLoc.x + builder->typeBOffset, builder->typeBLoc.y);
        builder->typeB.SetLocation(typeBPos);

        Point typeCPos(builder->typeCLoc.x + builder->typeCOffset, builder->typeCLoc.y);
        builder->typeC.SetLocation(typeCPos);

        if (shipSelect && shipSelect->bOpen)
        {
            shipSelect->Close();
        }
    }
}

void CustomShipSelect::Open()
{
    open = true;
}

void CustomShipSelect::Close()
{
    open = false;
    selectedShip = -1;
}

int CustomShipSelect::CycleShipNext(int currentShipId, int currentType)
{
    int numShips = customShipOrder.size();

    int index = GetShipButtonOrderIndex(currentShipId - 100);
    if (index == -1) index = 0;

    if (index + 1 == numShips)
    {
        index = 0;
    }
    else
    {
        index++;
    }

    int counter = 0;
    while (true)
    {
        ShipButtonDefinition* def = GetOrderedShipButtonDefinition(index);

        if (!def || !def->VariantExists(currentType) || !CustomShipUnlocks::instance->GetCustomShipUnlocked(def->name, currentType))
        {
            if (index + 1 >= numShips)
            {
                index = 0;
            }
            else
            {
                index++;
            }

            counter++;
            if (counter > 1000)
            {
                printf("Infinite loop while getting next ship!");
                break;
            }
        }
        else
        {
            index = GetShipButtonIdFromName(def->name);
            break;
        }
    }

    return index + 100;
}

int CustomShipSelect::CycleShipPrevious(int currentShipId, int currentType)
{
    int numShips = customShipOrder.size() - 1;

    int index = GetShipButtonOrderIndex(currentShipId - 100);
    if (index == -1) index = numShips;

    if (index == 0)
    {
        index = numShips;
    }
    else
    {
        index--;
    }

    int counter = 0;
    while (true)
    {
        ShipButtonDefinition* def = GetOrderedShipButtonDefinition(index);

        if (!def || !def->VariantExists(currentType) || !CustomShipUnlocks::instance->GetCustomShipUnlocked(def->name, currentType))
        {
            if (index <= 0)
            {
                index = numShips;
            }
            else
            {
                index--;
            }

            counter++;
            if (counter > 1000)
            {
                printf("Infinite loop while getting next ship!");
                break;
            }
        }
        else
        {
            index = GetShipButtonIdFromName(def->name);

            break;
        }
    }

    return index + 100;
}

int CustomShipSelect::GetRandomShipIndex()
{
    return GetShipButtonOrderIndex(random32() % shipButtonDefs.size());
}

int CustomShipSelect::CountUnlockedShips(int variant=-1)
{
    int counter = 0;

    for (int i = 0; i < (customShipOrder.size()); i++)
    {
        ShipButtonDefinition* def = GetOrderedShipButtonDefinition(i);

        if (variant != -1)
        {
            if (def && CustomShipUnlocks::instance->GetCustomShipUnlocked(def->name, variant))
            {
                if (def->VariantExists(variant))
                {
                    counter++;
                }
            }
        }
        else
        {
            counter++;
        }
    }

    return counter;
}

//==========================

HOOK_STATIC(ScoreKeeper, GetShipBlueprint, (std::string* str, ScoreKeeper* scoreKeeper, int index) -> std::string*)
{
    std::string* ret;
    if (index >= 100)
        ret = super(str, scoreKeeper, 0);
    else
        ret = super(str, scoreKeeper, index);

    if (index >= 100)
    {
        auto customSel = CustomShipSelect::GetInstance();
        str->assign(customSel->GetShipBlueprint(index));
    }


    return ret;
}

HOOK_METHOD(UnlockArrow, MouseMove, (int x, int y) -> bool)
{
    auto customSel = CustomShipSelect::GetInstance();

    if (customSel->ShouldRenderArrow())
    {
        return super(x, y);
    }

    return false;
}

HOOK_METHOD(UnlockArrow, OnRender, () -> void)
{
    auto customSel = CustomShipSelect::GetInstance();

    if (customSel->ShouldRenderArrow())
    {
        super();
    }
}


HOOK_METHOD(ShipButton, OnRender, () -> void)
{
    auto customSel = CustomShipSelect::GetInstance();
    if (customSel->ShouldRenderButton(this))
    {
        if (customSel->ShouldRenderButtonLower() || bShipLocked || bNoExist)
        {
            super();
        }
        else
        {
            GL_Color white = GL_Color(1.f, 1.f, 1.f, 1.f);

            Point pos = {position.x, position.y+107};
            std::string buttonLower = ((bActive && bHover) || bSelected) ? "customizeUI/ship_list_button_lower_select2.png" : "customizeUI/ship_list_button_lower_on.png";
            G_->GetResources()->RenderImageString(buttonLower, pos.x, pos.y, 0, white, 1.f, false);
            pos.y += 16;
            pos.x += 6;
            for (int i=0; i<achievements.size(); ++i)
            {
                if (achievements[i]) achievements[i]->OnRender(pos, (iSelectedAch == i) ? 2 : 3, false);
                pos.x += 37;
            }

            Button::OnRender();
            G_->GetResources()->RenderImage(iShipImage, position.x, position.y, 0, white, 1.f, false);
        }
    }
}

HOOK_METHOD_PRIORITY(ShipButton, MouseMove, 9999, (int x, int y) -> void)
{
    iSelectedAch = -1;
    if (!bShipLocked)
    {
        int b_y = position.y;
        int b_x = position.x + 6;
        if (y > b_y + 123 && y < b_y + 155)
        {
            for (int i=0; i<achievements.size(); ++i, b_x+=37)
            {
                if (x > b_x && x < b_x + 32)
                {
                    if (achievements[i])
                    {
                        G_->GetAchievementTracker()->SetTooltip(achievements[i]);
                        iSelectedAch = i;
                    }
                    break;
                }
            }
        }
    }
    GenericButton::MouseMove(x, y, false);
}

HOOK_METHOD(ShipSelect, MouseClick, () -> void)
{
    super();

    auto customSel = CustomShipSelect::GetInstance();
    customSel->MouseClick();
}

HOOK_METHOD(ShipSelect, MouseMove, (int x, int y) -> int)
{
    auto customSel = CustomShipSelect::GetInstance();

    if (customSel->FirstPage())
    {
        super(x, y);
    }



    customSel->MouseMove(x, y);
}

HOOK_METHOD(ShipSelect, Open, (int currentLayout, int currentType) -> void)
{
    super(currentLayout, currentType);

    auto customSel = CustomShipSelect::GetInstance();
    customSel->OnInit(this);
    customSel->Open();
}

HOOK_METHOD(ShipSelect, OnRender, () -> void)
{
    auto customSel = CustomShipSelect::GetInstance();

    if (customSel->FirstPage())
    {
        super();
    }
    else
    {
        super();
        customSel->OnRender(true);
    }

    customSel->OnRender();
}



HOOK_METHOD(ShipBuilder, SwitchShip, (int shipType, int shipVariant) -> void)
{
    if (shipType >= 100)
    {
        auto customSel = CustomShipSelect::GetInstance();

        customSel->SwitchShip(this, shipType, shipVariant);

        return;
    }

    return super(shipType, shipVariant);
}

HOOK_STATIC(AchievementTracker, GetShipAchievements, (void* unk, AchievementTracker *tracker, std::string& id) -> void*)
{
    return super(unk, tracker, id);
}

HOOK_METHOD(ShipBuilder, MouseClick, (int x, int y) -> void)
{
    super(x, y);

    auto customSel = CustomShipSelect::GetInstance();

    if (customSel->Initialized() && customSel->GetSelection() != -1)
    {
        currentShip->destructor2();

        customSel->SwitchShip(this, customSel->GetSelectedId(), shipSelect.currentType, true);
        customSel->ClearSelection();
    }
}

HOOK_METHOD(ShipBuilder, SwapType, (int variant) -> int)
{
    return super(variant);
}

HOOK_METHOD(ShipSelect, Close, () -> void)
{
    super();
    auto customSel = CustomShipSelect::GetInstance();
    customSel->Close();
}

HOOK_METHOD(ShipBuilder, CycleShipNext, () -> void)
{
    auto customSel = CustomShipSelect::GetInstance();

    if (currentShipId >= 100)
    {
        currentShip->destructor2();

        customSel->SwitchShip(this, customSel->CycleShipNext(currentShipId, currentType), currentType);
    }
    else
    {
        super();
    }
}

HOOK_METHOD(ShipBuilder, CycleShipPrevious, () -> void)
{
    auto customSel = CustomShipSelect::GetInstance();

    if (currentShipId >= 100)
    {
        currentShip->destructor2();

        customSel->SwitchShip(this, customSel->CycleShipPrevious(currentShipId, currentType), currentType);
    }
    else
    {
        super();
    }

}

HOOK_METHOD(ShipBuilder, MouseClick, (int x, int y) -> void)
{
    if (randomButton.bActive && randomButton.bHover)
    {
        auto customSel = CustomShipSelect::GetInstance();

        if (currentShipId >= 100 && customSel->Initialized())
        {
            std::vector<std::pair<int, int>> unlocked = std::vector<std::pair<int, int>>();

            int counter = 0;

            while (unlocked.size() == 0)
            {
                int id = customSel->GetRandomShipIndex();

                std::string blueprintName = customSel->customShipOrder[id];

                for (int i = 0; i < 3; i++)
                {
                    if (customSel->GetOrderedShipButtonDefinition(id)->VariantExists(i) && CustomShipUnlocks::instance->GetCustomShipUnlocked(blueprintName, i))
                    {
                        unlocked.push_back(std::pair<int, int>(customSel->GetShipButtonIdFromName(blueprintName) + 100, i));
                    }
                }

                counter++;
                if (counter >= 100) break;

            }


            if (counter != 100)
            {
                auto randomShip = unlocked[random32() % unlocked.size()];

                currentShip->destructor2();

                customSel->SwitchShip(this, randomShip.first, randomShip.second, true);
            }
        }
        else
        {
            super(x, y);
        }
    }
    else
    {
        super(x, y);
    }
}

HOOK_METHOD(ShipBuilder, OnLoop, () -> void)
{
    if (Global::forceDlc)
    {
        *Global::dlcEnabled = true;
    }

    super();

    if (currentShipId >= 100)
    {
        auto customSel = CustomShipSelect::GetInstance();

        ShipButtonDefinition *def = &customSel->GetShipButtonDefinition(currentShipId-100);

        bool buttonsActive = false;

        buttonsActive = customSel->CountUnlockedShips(currentType) > 1;

        leftButton.SetActive(buttonsActive);
        rightButton.SetActive(buttonsActive);
        randomButton.SetActive(customSel->CountUnlockedShips(-1) > 1);
        startButton.SetActive(Settings::GetDlcEnabled() || !def->VariantNeedsDlc(currentType));
    }
    else
    {
        startButton.SetActive(Settings::GetDlcEnabled() || (currentShipId != 9 && currentType != 2));
    }

    for (auto i : CustomShipSelect::GetInstance()->customAnims)
    {
        i.second->Update();
    }
}

static GL_Texture* seedBox;
static GL_Primitive* unlocksDisabledPrimitive;


HOOK_METHOD(MenuScreen, constructor, () -> void)
{
    super();

    seedBox = G_->GetResources()->GetImageId("optionsUI/info_seed.png");
    auto unlocksDisabledTexture = G_->GetResources()->GetImageId("customizeUI/unlocks_disabled.png");
    unlocksDisabledPrimitive = CSurface::GL_CreateImagePrimitive(unlocksDisabledTexture, 1106.f - unlocksDisabledTexture->width_ / 2, 104, unlocksDisabledTexture->width_, unlocksDisabledTexture->height_, 0.f, COLOR_WHITE);
}

static Button* reactorInfoButton = nullptr;

HOOK_METHOD_PRIORITY(ShipBuilder, OnRender, 1000, () -> void)
{
    bool isVanillaShip = currentShipId < 100;

    if (Global::forceDlc)
    {
        advancedOffButton.bActive = false;
        advancedOnButton.bActive = false;

        advancedOffButton.position.x = 4000;
        advancedOnButton.position.x = 4000;
        advancedOffButton.hitbox.x = 4000;
        advancedOnButton.hitbox.x = 4000;
    }

    if (shipSelect.bOpen)
    {
        GL_Color tint(0.25f, 0.25f, 0.25f, 1.f);
        CSurface::GL_SetColorTint(tint);
    }

    CSurface::GL_DisableBlend();
    CSurface::GL_RenderPrimitive(baseImage);

    CSurface::GL_EnableBlend();

    for (auto i : CustomShipSelect::GetInstance()->customAnims)
    {
        CSurface::GL_PushMatrix();
        CSurface::GL_Translate(i.first.x, i.first.y);

        i.second->OnRender(1.f, COLOR_WHITE, false);

        CSurface::GL_PopMatrix();
    }

    CSurface::GL_RenderPrimitive(shipEquipBox);
    CSurface::GL_RenderPrimitive(shipSelectBox);
    if (isVanillaShip)
    {
        CSurface::GL_RenderPrimitive(shipAchBox);
    }
    else
    {
        CSurface::GL_RenderPrimitive(shipAchBox); //for now
    }

    if (!Global::forceDlc)
    {
        CSurface::GL_RenderPrimitive(advancedButtonBox);
    }

    CSurface::GL_SetColor(COLOR_BUTTON_TEXT);

    TextLibrary* lib = G_->GetTextLibrary();

    std::string langTxt;
    freetype::easy_print(62, 19, 117, lib->GetText("hangar_frame_ship"));
    freetype::easy_print(62, 19, 219, lib->GetText("hangar_frame_layout"));
    freetype::easy_print(62, 19, 489, lib->GetText("hangar_frame_crew"));
    freetype::easy_print(62, 388, 489, lib->GetText("equipment_frame_weapons"));
    freetype::easy_print(62, 388, 599, lib->GetText("equipment_frame_drones"));
    freetype::easy_print(62, 954, 489, lib->GetText("equipment_frame_augments"));

    CSurface::GL_SetColor(COLOR_BUTTON_ON);

    if (isVanillaShip)
    {
        freetype::easy_printCenter(13, 124, 374, lib->GetText("hangar_achievements_title"));
    }
    else
    {
        freetype::easy_printCenter(13, 124, 374, lib->GetText("hangar_achievements_title_custom"));
    }

    if (!Global::forceDlc)
    {
        freetype::easy_printCenter(13, 1109, 400, lib->GetText("hangar_advanced_title"));
    }

    CSurface::GL_SetColor(1.f, 1.f, 1.f, 1.f);

    CSurface::GL_PushMatrix();

    bool dlcLocked = !Settings::GetDlcEnabled();
    if (dlcLocked)
    {
        if (isVanillaShip)
        {
            dlcLocked = currentShipId == 9 || currentType == 2;
        }
        else
        {
            auto customSel = CustomShipSelect::GetInstance();
            ShipButtonDefinition *def = &customSel->GetShipButtonDefinition(currentShipId-100);
            dlcLocked = def->VariantNeedsDlc(currentType);
        }
    }

    if (dlcLocked)
    {
        CSurface::GL_SetColorTint(COLOR_TINT);
    }

    CSurface::GL_Translate(currentShip->ship.horizontal_shift + 365.f, currentShip->ship.vertical_shift + 30.f);
    currentShip->OnRender(true, false);

    CSurface::GL_PopMatrix();
    CSurface::GL_RenderPrimitive(startButtonBox);

    if (dlcLocked)
    {
        CSurface::GL_RemoveColorTint();
        CSurface::GL_RenderPrimitive(enableAdvancedPrimitive);
    }


    for (auto &anim: animations)
    {
        anim.OnRender(1.f, COLOR_WHITE, false);
    }

    walkingMan.OnRender(1.f, COLOR_WHITE, false);

    CSurface::GL_RenderPrimitive(nameBoxPrimitive);

    for (auto &box: vEquipmentBoxes)
    {
        if (box->CanDoJob())
        {
            if (bCustomizingCrew)
            {
                if (!box->CanHoldCrew())
                {
                    box->OnRender(false);
                    box->RenderLabels(false);
                }
            }
            else
            {
                box->OnRender(false);
                box->RenderLabels(false);
            }
        }

    }

    for (auto &box: vCrewBoxes)
    {
        if (box->bCustomizing)
        {
            box->OnRender(false);
            break;
        }
    }

    for (auto &button: buttons)
    {
        button->OnRender();
    }

    for (auto &sys: sysBoxes)
    {
        sys->OnRender(true);
    }


    if (encourageShipList)
    {
        int buttonX = listButton.position.x;
        int buttonY = listButton.position.y;


        CSurface::GL_BlitPixelImage(arrow, buttonX + 75, buttonY - 4, 164, 38, 0, COLOR_WHITE, true);
        descBox->Draw(buttonX + 245, buttonY - 47);
        freetype::easy_printAutoNewlines(12, buttonX + 265, buttonY - 27, 308, lib->GetText("tutorial_list_open"));
    }


    CSurface::GL_SetColor(COLOR_WHITE);

    Point shipNamePos = Point(273, 7);
    nameInput.OnRender(24, shipNamePos);

    // FIXED WTIH freetype_hack

    // This doesn't work because of easy_measurePrintLines returning a Pointf
    // Need a way to get the y value of the returned Pointf
    // The Pointf is returned split into eax and edx

    // FIXED WITH freetype_hack
    if (bRenaming)
    {
        Pointf ret = freetype_hack::easy_measurePrintLines(12, 0, 0, 999, lib->GetText("rename"));
        float x = 6.f;
        float x2 = 227.f - ret.x / 2;
        if (x2 > 5)
            x = x2;
        freetype::easy_print(12, x, 65.f, lib->GetText("rename"));
    }

    if (!currentShip->HasSystem(3))
    {
        freetype::easy_printCenter(63, 662, 539, lib->GetText("equipment_no_system"));
    }
    if (!currentShip->HasSystem(4))
    {
        freetype::easy_printCenter(63, 662, 649, lib->GetText("equipment_no_system"));
    }

    CSurface::GL_SetColor(COLOR_WHITE);


    if (isVanillaShip)
    {
        int counter = 0;
        for (auto &ach: shipAchievements)
        {
            Point pos(ach.position.x, ach.position.y);
            ach.achievement->OnRender(pos, selectedAch == counter, 1);
            counter++;
        }
    }
    else
    {
        auto customSel = CustomShipSelect::GetInstance();
        ShipButtonDefinition *shipButtonDef = &customSel->GetShipButtonDefinition(currentShipId-100);

        std::string finalName = customSel->GetVariantName(shipButtonDef->name, currentType);

        CAchievement *ach = nullptr;
        if (shipButtonDef->splitVictoryAchievement)
        {
            ach = CustomShipUnlocks::instance->GetVictoryAchievement(finalName);
        }
        else
        {
            ach = CustomShipUnlocks::instance->GetVictoryAchievement(shipButtonDef->name);
        }

        if (ach)
        {
            ach->OnRender(Point(244, 438), selectedAch == -2 ? 2 : 3, 1);
        }

        ach = nullptr;
        if (shipButtonDef->splitUnlockQuestAchievement)
        {
            if (CustomShipUnlocks::instance->CustomShipHasUnlockQuest(finalName))
            {
                ach = CustomShipUnlocks::instance->GetQuestAchievement(finalName);
            }
        }
        else
        {
            if (CustomShipUnlocks::instance->CustomShipHasUnlockQuestAnyLayout(shipButtonDef->name))
            {
                ach = CustomShipUnlocks::instance->GetQuestAchievement(shipButtonDef->name);
            }
        }

        if (ach)
        {
            ach->OnRender(Point(244, 404), selectedAch == -3 ? 2 : 3, 1);
        }

        std::vector<std::string> victoryTypes;
        for (std::string &i : CustomShipUnlocks::instance->customVictoryTypes)
        {
            if (!CustomShipUnlocks::instance->customVictories[i].secret || (CustomShipUnlocks::instance->customShipVictories.count(i) && !CustomShipUnlocks::instance->customShipVictories[i].empty()))
            {
                victoryTypes.push_back(i);
            }
        }

        int max_a = victoryTypes.size()%6;
        int max_b = victoryTypes.size()/6;
        for (int i=0; i<victoryTypes.size(); ++i)
        {
            if (shipButtonDef->splitVictoryAchievement)
            {
                ach = CustomShipUnlocks::instance->customVictories[victoryTypes[i]].GetVictoryAchievement(finalName);
            }
            else
            {
                ach = CustomShipUnlocks::instance->customVictories[victoryTypes[i]].GetVictoryAchievement(shipButtonDef->name);
            }

            int a = i%6;
            int b = i/6;

            ach->OnRender(Point(124 - 17*(b==max_b ? max_a : 6) + 34*a, 437 - 17*((victoryTypes.size()+5)/6) + 34*b), selectedAch == i ? 2 : 3, 1);
        }
    }

    if (SeedInputBox::seedInput)
	{
		SeedInputBox::seedInput->OnRender(0, Point((int)SeedInputBox::drawLocation.x+2+(SeedInputBox::width/2), (int)SeedInputBox::drawLocation.y+5));

		std::string inputSeed;

		TextInput::GetText(inputSeed, SeedInputBox::seedInput);

		if (inputSeed != "")
        {
            CSurface::GL_RenderPrimitive(unlocksDisabledPrimitive);
        }
	}


    CSurface::GL_RemoveColorTint();
    if (shipSelect.bOpen)
    {
        shipSelect.OnRender();
    }
    else
    {
        infoBox.OnRender();
    }

    introScreen.OnRender();

    if (!reactorInfoButton)
    {
        reactorInfoButton = new Button();
        reactorInfoButton->OnInit("customizeUI/reactor_info_button", 145, 426);
        reactorInfoButton->bActive = true;
        reactorInfoButton->SetLocation(Point(145, 426));
    }

    if (!shipSelect.bOpen && CustomOptionsManager::GetInstance()->showReactor.currentValue)
    {
        reactorInfoButton->OnRender();
        auto def = CustomShipSelect::GetInstance()->GetDefinition(currentShip->myBlueprint.blueprintName);
        //show reactor
        //was at 310/450
        CSurface::GL_SetColor(GL_Color(100.0/255, 1, 100.0/255, 1));
        freetype::easy_print(52, 151, 430, "Starting power: " + std::to_string(PowerManager::GetPowerManager(0)->currentPower.second));
        CSurface::GL_SetColor(GL_Color(100.0/255, 1, 100.0/255, 1));
        freetype::easy_print(52, 151, 450, "Maximum power: " + std::to_string(def.maxReactorLevel));
    }
}

HOOK_METHOD(ShipBuilder, MouseMove, (int x, int y) -> void)
{
    super(x,y);
    if (currentShipId >= 100)
    {
        auto customSel = CustomShipSelect::GetInstance();
        ShipButtonDefinition *shipButtonDef = &customSel->GetShipButtonDefinition(currentShipId-100);

        std::string finalName = customSel->GetVariantName(shipButtonDef->name, currentType);

        if (x > 244 && x < 276)
        {
            if (y > 404 && y < 436)
            {
                CAchievement *ach = nullptr;

                if (shipButtonDef->splitUnlockQuestAchievement)
                {
                    if (CustomShipUnlocks::instance->CustomShipHasUnlockQuest(finalName))
                    {
                        ach = CustomShipUnlocks::instance->GetQuestAchievement(finalName);
                    }
                }
                else
                {
                    if (CustomShipUnlocks::instance->CustomShipHasUnlockQuestAnyLayout(shipButtonDef->name))
                    {
                        ach = CustomShipUnlocks::instance->GetQuestAchievement(shipButtonDef->name);
                    }
                }

                if (ach)
                {
                    G_->GetAchievementTracker()->SetTooltip(ach);
                    selectedAch = -3;
                }
            }
            else if (y > 438 && y < 470)
            {
                CAchievement *ach = nullptr;

                if (shipButtonDef->splitVictoryAchievement)
                {
                    ach = CustomShipUnlocks::instance->GetVictoryAchievement(finalName);
                }
                else
                {
                    ach = CustomShipUnlocks::instance->GetVictoryAchievement(shipButtonDef->name);
                }

                if (ach)
                {
                    G_->GetAchievementTracker()->SetTooltip(ach);
                    selectedAch = -2;
                }
            }
        }
        else
        {
            std::vector<std::string> victoryTypes;
            for (std::string &i : CustomShipUnlocks::instance->customVictoryTypes)
            {
                if (!CustomShipUnlocks::instance->customVictories[i].secret || (CustomShipUnlocks::instance->customShipVictories.count(i) && !CustomShipUnlocks::instance->customShipVictories[i].empty()))
                {
                    victoryTypes.push_back(i);
                }
            }

            int max_a = victoryTypes.size()%6;
            int max_b = victoryTypes.size()/6;
            for (int i=0; i<victoryTypes.size(); ++i)
            {
                CAchievement *ach;
                if (shipButtonDef->splitVictoryAchievement)
                {
                    ach = CustomShipUnlocks::instance->customVictories[victoryTypes[i]].GetVictoryAchievement(finalName);
                }
                else
                {
                    ach = CustomShipUnlocks::instance->customVictories[victoryTypes[i]].GetVictoryAchievement(shipButtonDef->name);
                }

                int a = i%6;
                int b = i/6;

                Point pos(124 - 17*(b==max_b ? max_a : 6) + 34*a, 437 - 17*((victoryTypes.size()+5)/6) + 34*b);

                if (x > pos.x && x < pos.x+32 && y > pos.y && y < pos.y+32)
                {
                    G_->GetAchievementTracker()->SetTooltip(ach);
                    selectedAch = i;
                }
            }
        }
    }
}


HOOK_METHOD(GameOver, OnRender, () -> void)
{
    if (bShowStats)
    {
        CSurface::GL_SetColorTint(COLOR_TINT);
    }

    if (SeedInputBox::seedsEnabled)
    {
        CSurface::GL_BlitPixelImageWide(seedBox,
                                position.x + 160.f,
                                position.y + 325.f,
                                162,
                                72,
                                1.f,
                                COLOR_WHITE,
                                false);

        CSurface::GL_SetColor(COLOR_BUTTON_ON);

        freetype::easy_printCenter(13, position.x + 81.f + 160.f, position.y + 325.f + 16.f, G_->GetTextLibrary()->GetText("menu_status_seed"));

        CSurface::GL_SetColor(COLOR_BUTTON_TEXT);

        char buf[12];

        sprintf(buf, "%u", Global::currentSeed);

        freetype::easy_printCenter(62, position.x + 81.f + 160.f, position.y + 325.f + 40.f, std::string(buf));
    }

    if (bShowStats)
    {
        CSurface::GL_RemoveColorTint();
    }

    super();
}


HOOK_METHOD_PRIORITY(MenuScreen, OnRender, 1000, () -> void)
{
    if (G_->GetWorld()->playerShip)
    {
        if (!SM_EX(G_->GetWorld()->playerShip->shipManager)->isNewShip)
        {
            super();

            if (!bShowControls && !G_->GetTutorialManager()->Running())
            {
                if (confirmDialog.bOpen)
                {
                    CSurface::GL_SetColorTint(COLOR_TINT);
                }

                CSurface::GL_BlitPixelImageWide(seedBox,
                                        statusPosition.x + 66,
                                        statusPosition.y + 205,
                                        162,
                                        72,
                                        1.f,
                                        COLOR_WHITE,
                                        false);

                CSurface::GL_SetColor(COLOR_BUTTON_ON);

                freetype::easy_printCenter(13, statusPosition.x + 66.f + 81.f, statusPosition.y + 205.f + 16.f, G_->GetTextLibrary()->GetText("menu_status_seed"));

                CSurface::GL_SetColor(COLOR_BUTTON_TEXT);

                char buf[12] = "-";

                if (SeedInputBox::seedsEnabled)
                {
                    sprintf(buf, "%u", Global::currentSeed);
                }
                freetype::easy_printCenter(62, statusPosition.x + 66.f + 81.f, statusPosition.y + 205.f + 40, std::string(buf));

                if (confirmDialog.bOpen)
                {
                    CSurface::GL_RemoveColorTint();
                }
            }


            return;
        }
    }

    if (bShowControls || G_->GetTutorialManager()->Running())
    {
        return super();
    }

    if (!menuPrimitive)
    {
        std::vector<GL_TexVertex> texVertices = std::vector<GL_TexVertex>();
        GL_Texture *img = mainImage;
        float unk1 = 81.f;
        float unk2 = 1.f;
        float unk3 = 1.f;

        if (img)
        {
            unk1 = 81.f / img->width_;
            unk2 = img->width_;
            unk3 = img->height_;
        }

        CSurface::AddTexVertices(&texVertices, position.x, position.y, 81.f, unk3, 0, unk1, 0, 1.f);
        CSurface::AddTexVertices(&texVertices, position.x + 81.f, position.y, menuWidth - 161.f, unk3, unk1, 82.f / unk2, 0, 1.f);
        CSurface::AddTexVertices(&texVertices, (menuWidth + position.x) - 80.f, position.y, 80.f, unk3, 82.f / unk2, 162.f / unk2, 0, 1.f);
        menuPrimitive = CSurface::GL_CreateMultiImagePrimitive(mainImage, &texVertices, COLOR_WHITE);
    }


    if (confirmDialog.bOpen)
    {
        CSurface::GL_SetColorTint(COLOR_TINT);
    }

    CSurface::GL_RenderPrimitive(menuPrimitive);

    for (auto &button : buttons)
    {
        button->OnRender();
    }

    CSurface::GL_BlitPixelImageWide(difficultyBox,
                                    statusPosition.x,
                                    statusPosition.y,
                                    difficultyWidth,
                                    72,
                                    1.f,
                                    COLOR_WHITE,
                                    false);


    CSurface::GL_BlitPixelImageWide(dlcBox,
                                    statusPosition.x + difficultyWidth + 3,
                                    statusPosition.y,
                                    dlcWidth,
                                    72,
                                    1.f,
                                    COLOR_WHITE,
                                    false);



    CSurface::GL_SetColor(COLOR_BUTTON_ON);

    freetype::easy_printCenter(13, statusPosition.x + (difficultyWidth + 1.f) / 2.f, statusPosition.y + 16.f, difficultyLabel);
    freetype::easy_printCenter(13, statusPosition.x + difficultyWidth + (dlcWidth + 1.f) / 2.f + 3.f, statusPosition.y + 16.f, dlcLabel);

    CSurface::GL_SetColor(COLOR_BUTTON_TEXT);

    freetype::easy_printCenter(62, statusPosition.x + (difficultyWidth + 1.f) / 2.f, statusPosition.y + 40, difficultyText);
    freetype::easy_printCenter(62, statusPosition.x + difficultyWidth + (dlcWidth + 1.f) / 2.f + 3.f, statusPosition.y + 40.f, dlcText);


    CSurface::GL_BlitPixelImageWide(seedBox,
                                    statusPosition.x + 66,
                                    statusPosition.y + 72,
                                    162,
                                    72,
                                    1.f,
                                    COLOR_WHITE,
                                    false);



    CSurface::GL_SetColor(COLOR_BUTTON_ON);

    freetype::easy_printCenter(13, statusPosition.x + 81.f + 66.f, statusPosition.y + 72.f + 16.f, G_->GetTextLibrary()->GetText("menu_status_seed"));

    CSurface::GL_SetColor(COLOR_BUTTON_TEXT);

    char buf[12] = "-";
    if (SeedInputBox::seedsEnabled)
    {
        sprintf(buf, "%u", Global::currentSeed);
    }
    freetype::easy_printCenter(62, statusPosition.x + 81.f + 66.f, statusPosition.y + 72.f + 40, std::string(buf));


    if (confirmDialog.bOpen)
    {
        CSurface::GL_RemoveColorTint();
        confirmDialog.OnRender();
    }
}

HOOK_METHOD(ShipBuilder, Open, () -> void)
{
    auto customSel = CustomShipSelect::GetInstance();

    super();

    customSel->OnInit(&shipSelect);

    if (customSel->hideFirstPage)
    {
        currentShip->destructor2();

        customSel->SwitchShip(this, customSel->GetShipButtonIdFromName(customSel->customShipOrder[0]) + 100, 0);
    }
}

HOOK_METHOD(ShipBuilder, OnKeyDown, (SDLKey key) -> void)
{
    if (key == SDLKey::SDLK_UP
        || key == SDLKey::SDLK_LEFT
        || key == SDLKey::SDLK_RIGHT
        || key == SDLKey::SDLK_DOWN)
    {
        return;
    }

    super(key);
}
