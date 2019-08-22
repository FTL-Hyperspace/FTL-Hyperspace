#include "CustomShips.h"
#include <algorithm>

const std::array<std::string, 10> SHIP_NAMES =
{
    "PLAYER_SHIP_HARD",
    "PLAYER_SHIP_STEALTH",
    "PLAYER_SHIP_MANTIS",
    "PLAYER_SHIP_CIRCLE",
    "PLAYER_SHIP_FED",
    "PLAYER_SHIP_JELLY",
    "PLAYER_SHIP_ROCK",
    "PLAYER_SHIP_ENERGY",
    "PLAYER_SHIP_CRYSTAL",
    "PLAYER_SHIP_ANAEROBIC"
};

CustomShipSelect CustomShipSelect::instance = CustomShipSelect();



void CustomShipSelect::AddShip(const std::string& name, bool typeB, bool typeC)
{
    this->blueprintNames.push_back( ShipDefinition { name, typeB, typeC } );
}

ShipButton* testButton;

void CustomShipSelect::OnInit(ShipSelect* shipSelect_)
{
    maxShipPage = std::ceil(this->blueprintNames.size() / 10.f);

    if (maxShipPage <= 0)
        maxShipPage = 0;
    else if (!initialized)
    {
        int i = 0;
        for (auto const &x: blueprintNames)
        {
            int curPage = i / 10;

            ShipButton* aButton = new ShipButton(100 + i, 0);
            ShipButton* bButton;
            ShipButton* cButton;

            int onPage = i % 10;


            bButton = new ShipButton(100 + i, 1);

            if (!x.typeB)
            {
                bButton = new ShipButton(100 + i, 1);
                bButton->bNoExist = true;
                bButton->bActive = false;
            }

            cButton = new ShipButton(100 + i, 2);

            if (!x.typeC)
            {
                cButton->bNoExist = true;
                cButton->bActive = false;
            }

            ShipButtonList* buttonList = new ShipButtonList(curPage, 100 + i, aButton, bButton, cButton);
            this->shipButtons.push_back(buttonList);

            std::string shipButtonImg("customizeUI/ship_list_button");

            Point pos = Point(0, 0);
            if (onPage < 5)
            {
                printf("yes\n");

                if (onPage == 4)
                {
                    pos = Point(136 + 205 * 3 + 225, 161);
                }
                else
                {
                    pos = Point(136 + 205 * onPage, 161);
                }
            }
            else
            {
                printf("no\n");

                if (onPage == 9)
                {
                    pos = Point(136 + 205 * 3 + 225, 161 + 177);
                }
                else
                {
                    pos = Point(136 + 205 * (onPage - 5), 161 + 177);
                }
            }

            printf("%d\n", onPage);

            aButton->OnInit(shipButtonImg, pos);
            bButton->OnInit(shipButtonImg, pos);
            cButton->OnInit(shipButtonImg, pos);


            i++;
        }
    }




    std::string buttonImg("customizeUI/button_ship_arrow");
    this->leftButton = new Button();
    Point leftButtonPos(1100, 119);
    this->leftButton->OnInit(buttonImg, leftButtonPos);

    this->rightButton = new Button();
    Point rightButtonPos(1135, 119);
    this->rightButton->OnInit(buttonImg, rightButtonPos);

    this->rightButton->bMirror = true;

    if (this->maxShipPage == 0)
    {
        this->leftButton->bActive = false;
        this->rightButton->bActive = false;
    }


    this->shipSelect = shipSelect_;

    this->oldShipButtons = new std::vector<ShipButton*>(this->shipSelect->shipButtons);

    initialized = true;
}

void CustomShipSelect::OnRender(bool renderSelect)
{
    if (renderSelect)
    {
        for (auto const &x: this->shipButtons)
        {
            if (x->GetPage() == this->shipPage - 1)
            {
                ShipButton* button = x->GetButton(shipSelect->currentType);

                if (button)
                    button->OnRender();
            }
        }


    }
    else
    {
        this->leftButton->OnRender();
        this->rightButton->OnRender();



        char buf[128];



        sprintf(buf, "%d/%d", this->GetCurrentPage() + 1, this->GetMaxPages() + 1 );
        std::string text(buf);


        CSurface::GL_SetColor(25 / 255.f, 49 / 255.f, 51 / 255.f, 1.f);
        CSurface::GL_RemoveColorTint();
        freetype::easy_printRightAlign(63, 1097, 118, text);
    }

    shipSelect->infoBox.OnRender();
}

void CustomShipSelect::MouseClick()
{
    if (this->leftButton->bActive && this->leftButton->bHover)
    {
        if (this->shipPage == 0)
        {
            this->SwitchPage(this->maxShipPage);
        }
        else
        {
            this->SwitchPage(this->shipPage - 1);
        }
    }

    if (this->rightButton->bActive && this->rightButton->bHover)
    {
        if (this->shipPage == this->maxShipPage)
        {
            this->SwitchPage(0);
        }
        else
        {
            this->SwitchPage(this->shipPage + 1);
        }
    }
}

void CustomShipSelect::SwitchPage(int page)
{
    if (this->shipPage == page)
        return;


    if (this->shipPage == 0)
    {
        this->LeaveFirstPage();
    }

    if (page == 0)
    {
        this->EnterFirstPage();
    }

    this->shipPage = page;
}

void CustomShipSelect::LeaveFirstPage()
{
    for (auto const &x: *this->oldShipButtons)
    {
        x->bActive = false;
    }

}

void CustomShipSelect::EnterFirstPage()
{
    for (auto const &x: *this->oldShipButtons)
    {
        if (!x->bNoExist)
            x->bActive = true;
    }
}

bool CustomShipSelect::ShouldRenderButton(ShipButton *button)
{
    if (this->shipPage != 0 &&
            std::find(this->oldShipButtons->begin(), this->oldShipButtons->end(), button) != this->oldShipButtons->end())
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
    return this->shipPage == 0;
}

void CustomShipSelect::MouseMove(int x, int y)
{
    this->leftButton->MouseMove(x, y, false);
    this->rightButton->MouseMove(x, y, false);

    this->selectedShip = -1;

    for (auto const &i: this->shipButtons)
    {
        if (i->GetPage() == this->shipPage - 1)
        {
            ShipButton* button = i->GetButton(shipSelect->currentType);

            if (button)
            {
                char hover = button->MouseMove(x, y);
                if (hover == 1)
                {
                    this->selectedShip = i->GetIndex();
                    this->lastSelectedShip = this->selectedShip;
                }
            }

        }
    }

    if (!this->FirstPage())
    {
        if (this->selectedShip == -1)
            shipSelect->infoBox.Clear();
        else
        {
            std::string name( this->blueprintNames[this->selectedShip].name );
            ShipBlueprint* bp = G_->GetBlueprints()->GetShipBlueprint(name, -1);

            shipSelect->infoBox.SetDescription(&bp->desc, 360, 135, InfoBox::ExpandDir::EXPAND_DOWN);
        }
    }


    shipSelect->typeA.MouseMove(x, y, false);
    shipSelect->typeB.MouseMove(x, y, false);
    shipSelect->typeC.MouseMove(x, y, false);
}

std::string& CustomShipSelect::GetShipBlueprint(int shipId)
{
    int customIndex = shipId - 100;

    return this->blueprintNames[customIndex].name;
}

void CustomShipSelect::SwitchShip(ShipBuilder *builder, int type, int variant)
{
    if (type == builder->currentShipId && variant == builder->currentType) return;
    builder->currentType = variant;

    ShipManager *ship = new ShipManager(0);
    builder->currentShip = ship;
    builder->currentShipId = type;
    ShipDefinition def = this->blueprintNames[type - 100];

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
        ship->OnInit(bp, 0);
        std::string shipRealName = std::string();

        if (ship->myBlueprint.name.isLiteral)
        {
            shipRealName.assign(ship->myBlueprint.name.data);
        }
        else
        {
            TextLibrary::GetText(shipRealName, G_->GetTextLibrary(), ship->myBlueprint.name.data, G_->GetTextLibrary()->currentLanguage);
        }

        builder->currentName.swap(shipRealName);
        builder->nameInput.SetText(builder->currentName);

        builder->CreateEquipmentBoxes();
        builder->CreateSystemBoxes();
        builder->SetupShipAchievements();

        builder->ClearShipAchievements();

        builder->typeA.SetActive(variant != 0);
        builder->typeA.bRenderSelected = variant == 0;

        if (!def.typeB)
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

        if (!def.typeC)
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


        shipSelect->Close();
    }
}

void CustomShipSelect::Open()
{
    this->open = true;
}

void CustomShipSelect::Close()
{
    this->open = false;
}

bool CustomShipSelect::CycleShipNext(ShipBuilder *builder)
{
    if (builder->currentShipId < 100)
        return true;

    int index = builder->currentShipId - 100;

    int num = this->blueprintNames.size();

    if (builder->currentType == 1)
    {
        if (index + 1 == num)
        {
            index = 0;
        }
        else
        {
            index++;
        }

        while (index >= num || !this->blueprintNames[index].typeB)
        {
            if (index == num)
            {
                index = 0;
            }
            else
            {
                index++;
            }
        }
    }
    else if (builder->currentType == 2)
    {
        if (index + 1 == num)
        {
            index = 0;
        }
        else
        {
            index++;
        }

        while (index >= num || !this->blueprintNames[index].typeC)
        {
            if (index == num)
            {
                index = 0;
            }
            else
            {
                index++;
            }
        }
    }
    else
    {
        if (index + 1 == num)
        {
            index = 0;
        }
        else
        {
            index++;
        }
    }

    if (index > num)
    {
        index = 0;
    }

    builder->SwitchShip(index + 100, builder->currentType);


    return false;
}

bool CustomShipSelect::CycleShipPrevious(ShipBuilder *builder)
{
    if (builder->currentShipId < 100)
        return true;


    int index = builder->currentShipId - 100;

    int num = this->blueprintNames.size() - 1;

    if (builder->currentType == 1)
    {
        if (index - 1 < 0)
        {
            index = num;
        }
        else
        {
            index--;
        }

        while (index < 0 || !this->blueprintNames[index].typeB)
        {
            if (index < 0)
            {
                index = num;
            }
            else
            {
                index--;
            }
        }
    }
    else if (builder->currentType == 2)
    {
        if (index - 1 < 0)
        {
            index = num;
        }
        else
        {
            index--;
        }

        while (index < 0 || !this->blueprintNames[index].typeC)
        {
            if (index < 0)
            {
                index = num;
            }
            else
            {
                index--;
            }
        }
    }
    else
    {
        if (index - 1 < 0)
        {
            index = num;
        }
        else
        {
            index--;
        }
    }

    if (index < 0)
    {
        index = num;
    }

    builder->SwitchShip(index + 100, builder->currentType);


    return false;
}


//==========================


HOOK_METHOD(ShipButton, constructor, (int shipType, int shipVariant) -> void)
{
    super(shipType, shipVariant);
}

HOOK_METHOD(ResourceControl, GetImageId, (std::string& name) -> void*)
{
    return super(name);
}

HOOK_METHOD(ScoreKeeper, GetShipUnlocked, (int shipId, int shipVariant) -> bool)
{
    if (shipId >= 100)
        return true;
    return super(shipId, shipVariant);
}


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
    //printf("%08X\n", str2);

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
        super();
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

HOOK_METHOD(ShipSelect, Open, () -> void)
{
    super();

    auto customSel = CustomShipSelect::GetInstance();
    customSel->OnInit(this);
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

        if (customSel->GetLastSelected() != -1)
        {
            customSel->SwitchShip(this, shipType, shipVariant);
            return;
        }
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
        this->SwitchShip(customSel->GetSelectedId(), this->shipSelect.currentType);
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

    if (customSel->CycleShipNext(this))
        super();

}

HOOK_METHOD(ShipBuilder, CycleShipPrevious, () -> void)
{
    auto customSel = CustomShipSelect::GetInstance();

    if (customSel->CycleShipPrevious(this))
        super();

}
