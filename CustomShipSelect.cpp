#include "CustomShipSelect.h"
#include "CustomOptions.h"
#include "freetype.h"
#include "Seeds.h"
#include "ShipUnlocks.h"
#include "EnemyShipIcons.h"
#include "Resources.h"
#include <algorithm>
#include <boost/lexical_cast.hpp>

CustomShipSelect CustomShipSelect::instance = CustomShipSelect();




void CustomShipSelect::ParseShipsNode(rapidxml::xml_node<char> *node)
{
    // parse <ships> node in hyperspace.xml
    try
    {
        shipDefs["default"] = CustomShipDefinition();

        if (node->first_attribute("hideFirstShipPage"))
        {
            hideFirstPage = EventsParser::ParseBoolean(node->first_attribute("hideFirstShipPage")->value());
        }

        for (auto child = node->first_node(); child; child = child->next_sibling())
        {
            CustomShipDefinition def;
            std::string name = child->name();


            if (name == "shipIcons")
            {
                ShipIconManager::instance->ParseShipIconNode(child);
            }

            if (name == "ship")
            {
                def = CustomShipDefinition(GetDefaultDefinition());

                if (child->first_attribute("name"))
                {
                    std::string shipName = std::string(child->first_attribute("name")->value());

                    bool typeB = false;
                    bool typeC = false;

                    ShipButtonDefinition buttonDef = ShipButtonDefinition();
                    buttonDef.name = shipName;

                    if (child->first_attribute("b"))
                    {
                        buttonDef.typeB = EventsParser::ParseBoolean(child->first_attribute("b")->value());
                    }
                    if (child->first_attribute("c"))
                    {
                        buttonDef.typeC = EventsParser::ParseBoolean(child->first_attribute("c")->value());
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

                    shipDefs[shipName] = def;

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

            if (name == "customShip")
            {
                std::string shipName;
                if (!child->first_attribute("name"))
                {
                    shipName = "default";
                }
                else
                {
                    shipName = child->first_attribute("name")->value();
                }

                def = CustomShipDefinition(GetDefaultDefinition());

                if (shipDefs.find(shipName) != shipDefs.end())
                {
                    def = shipDefs[shipName];
                }

                for (auto shipNode = child->first_node(); shipNode; shipNode = shipNode->next_sibling())
                {
                    std::string name = std::string(shipNode->name());
                    std::string val = std::string(shipNode->value());

                    if (name == "hiddenAug")
                    {
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
                        def.crewLimit = boost::lexical_cast<int>(val);
                    }
                    if (name == "shipIcons")
                    {
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
                        def.noJump = true;
                    }
                    if (name == "noFuelStalemate")
                    {
                        def.noFuelStalemate = true;
                    }
                    if (name == "hpCap")
                    {
                        def.hpCap = boost::lexical_cast<int>(val);
                    }
                    if (name == "startingFuel")
                    {
                        def.startingFuel = boost::lexical_cast<int>(val);
                    }
                    if (name == "startingScrap")
                    {
                        def.startingScrap = boost::lexical_cast<int>(val);
                    }
                    if (name == "autoShipForce")
                    {
                        def.forceAutomated = EventsParser::ParseBoolean(val);
                    }
                    if (name == "systemLimit")
                    {
                        def.systemLimit = boost::lexical_cast<int>(val);
                    }
                    if (name == "subsystemLimit")
                    {
                        def.subsystemLimit = boost::lexical_cast<int>(val);
                    }
                    if (name == "customReactor")
                    {
                        if(shipNode->first_attribute("maxLevel")) def.maxReactorLevel = boost::lexical_cast<int>(shipNode->first_attribute("maxLevel")->value());
                        if(def.maxReactorLevel < 0) def.maxReactorLevel = 0;
                        if(def.maxReactorLevel > 25) def.reactorPrices.resize(ceil(def.maxReactorLevel / 5), -1);
                        for (auto reactorNode = shipNode->first_node(); reactorNode; reactorNode = reactorNode->next_sibling())
                        {
                            std::string reactName = reactorNode->name();

                            if(reactName == "baseCost") def.reactorPrices[0] = boost::lexical_cast<int>(reactorNode->value());
                            if(reactName == "increment") def.reactorPriceIncrement = boost::lexical_cast<int>(reactorNode->value());
                            if(reactName == "overrideCost") {
                                int coloumn = boost::lexical_cast<int>(reactorNode->first_attribute("coloumn")->value());
                                def.reactorPrices[coloumn] = boost::lexical_cast<int>(reactorNode->value());
                            }
                        }
                    }

                }

                shipDefs[shipName] = def;
            }

        }
    }
    catch (std::exception)
    {
        MessageBoxA(GetDesktopWindow(), "Error parsing <ships> in hyperspace.xml", "Error", MB_ICONERROR | MB_SETFOREGROUND);
    }
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

            ShipButtonDefinition x = shipButtonDefs[shipId];

            // create and initialize ShipButtons for each of the blueprints
            int curPage = i / 10;

            ShipButton* aButton = new ShipButton(100 + shipId, 0);
            ShipButton* bButton;
            ShipButton* cButton;

            int onPage = i % 10;


            bButton = new ShipButton(100 + shipId, 1);

            if (!x.typeB)
            {
                bButton->bNoExist = true;
                bButton->bActive = false;
            }

            cButton = new ShipButton(100 + shipId, 2);

            if (!x.typeC)
            {
                cButton->bNoExist = true;
                cButton->bActive = false;
            }

            //aButton->bShipLocked = true;
            //aButton->bLayoutLocked = true;



            ShipButtonList* buttonList = new ShipButtonList(curPage, 100 + shipId, aButton, bButton, cButton);
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

            //if (!x.hasAchievements)

            if (CustomShipUnlocks::instance->CustomShipHasUnlock(x.name))
            {
                aButton->bShipLocked = !CustomShipUnlocks::instance->GetCustomShipUnlocked(x.name);
                aButton->bLayoutLocked = aButton->bShipLocked;
            }
            if (x.typeB)
            {
                if (CustomShipUnlocks::instance->CustomShipHasUnlock(x.name + "_2"))
                {
                    bButton->bShipLocked = !CustomShipUnlocks::instance->GetCustomShipUnlocked(x.name + "_2");
                    bButton->bLayoutLocked = bButton->bShipLocked;
                }
            }
            if (x.typeC)
            {
                if (CustomShipUnlocks::instance->CustomShipHasUnlock(x.name + "_3"))
                {
                    cButton->bShipLocked = !CustomShipUnlocks::instance->GetCustomShipUnlocked(x.name + "_3");
                    cButton->bLayoutLocked = cButton->bShipLocked;
                }
            }



            int oldY = pos.y;

            if (!aButton->bShipLocked)
                pos.y = oldY + 20;

            aButton->OnInit("customizeUI/ship_list_button", pos);

            if (!(bButton->bNoExist || bButton->bShipLocked))
                pos.y = oldY + 20;
            else
                pos.y = oldY;

            bButton->OnInit("customizeUI/ship_list_button", pos);

            if (!(cButton->bNoExist || cButton->bShipLocked))
                pos.y = oldY + 20;
            else
                pos.y = oldY;

            cButton->OnInit("customizeUI/ship_list_button", pos);
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

            if (CustomShipUnlocks::instance->CustomShipHasUnlock(shipName))
            {
                aButton->bShipLocked = !CustomShipUnlocks::instance->GetCustomShipUnlocked(shipName);
                aButton->bLayoutLocked = aButton->bShipLocked;
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

    initialized = true;
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

        if (!CustomShipUnlocks::instance->GetCustomShipUnlocked(def.name))
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
            Button::OnRender();
            GL_Color white = GL_Color(1.f, 1.f, 1.f, 1.f);
            G_->GetResources()->RenderImage(iShipImage, position.x, position.y, 0, white, 1.f, false);
        }
    }
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

        bool buttonsActive = false;

        buttonsActive = customSel->CountUnlockedShips(currentType) > 1;

        leftButton.SetActive(buttonsActive);
        rightButton.SetActive(buttonsActive);
        randomButton.SetActive(customSel->CountUnlockedShips(-1) > 1);
        startButton.SetActive(true);
    }
    else
    {
        startButton.SetActive(Settings::GetDlcEnabled() || (currentShipId != 9 && currentType != 2));
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
    CSurface::GL_RenderPrimitive(shipEquipBox);
    CSurface::GL_RenderPrimitive(shipSelectBox);
    if (isVanillaShip)
    {
        CSurface::GL_RenderPrimitive(shipAchBox);
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

    if (!Global::forceDlc)
    {
        freetype::easy_printCenter(13, 1109, 400, lib->GetText("hangar_advanced_title"));
    }

    CSurface::GL_SetColor(1.f, 1.f, 1.f, 1.f);
    CSurface::GL_PushMatrix();

    if (!Settings::GetDlcEnabled() && (currentShipId == 9 || currentType == 2) && isVanillaShip)
    {
        CSurface::GL_SetColorTint(COLOR_TINT);
    }

    CSurface::GL_Translate(currentShip->ship.horizontal_shift + 365.f, currentShip->ship.vertical_shift + 30.f);
    currentShip->OnRender(true, false);

    CSurface::GL_PopMatrix();
    CSurface::GL_RenderPrimitive(startButtonBox);

    if (!Settings::GetDlcEnabled() && (currentShipId == 9 || currentType == 2) && isVanillaShip)
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

    if (!shipSelect.bOpen && CustomOptionsManager::GetInstance()->showReactor.currentValue)
    {
        //show reactor
        CSurface::GL_SetColor(GL_Color(100.0/255, 1, 100.0/255, 1));
        //was at 310/450
        freetype::easy_print(52, 371, 380, "Reactor: " + std::to_string(PowerManager::GetPowerManager(0)->currentPower.second));
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
