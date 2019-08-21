#include "CustomShips.h"
#include <algorithm>


CustomShipSelect CustomShipSelect::instance = CustomShipSelect(0);

void CustomShipSelect::OnInit(ShipSelect* shipSelect_)
{
    std::string buttonImg("customizeUI/button_ship_arrow");
    this->leftButton = new Button();
    Point leftButtonPos(1100, 119);
    this->leftButton->OnInit(buttonImg, leftButtonPos);

    this->rightButton = new Button();
    Point rightButtonPos(1135, 119);
    this->rightButton->OnInit(buttonImg, rightButtonPos);

    this->rightButton->bMirror = true;


    this->shipSelect = shipSelect_;

    this->oldShipButtons = new std::vector<ShipButton*>(this->shipSelect->shipButtons);
}

void CustomShipSelect::OnRender(bool renderSelect)
{
    if (renderSelect)
    {

    }
    else
    {
        this->leftButton->OnRender();
        this->rightButton->OnRender();



        char buf[128];



        sprintf(buf, "%d/%d", this->GetCurrentPage() + 1 , this->GetMaxPages() + 1 );
        std::string text(buf);


        CSurface::GL_SetColor(25 / 255.f, 49 / 255.f, 51 / 255.f, 1.f);
        CSurface::GL_RemoveColorTint();
        freetype::easy_printRightAlign(63, 1097, 118, text);
    }
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
    if (this->shipPage == page) return;


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
        super(x, y);


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
