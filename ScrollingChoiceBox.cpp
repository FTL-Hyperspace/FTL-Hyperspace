#include "ScrollingChoiceBox.h"
#include "CustomColors.h"

int ScrollingChoiceBox::renderingEventBoxState = -1;
float ScrollingChoiceBox::scrollAmount = 0.f;
int ScrollingChoiceBox::dragging = -1;
bool ScrollingChoiceBox::barSelectState = false;
Button *ScrollingChoiceBox::scrollUpButton = nullptr;
Button *ScrollingChoiceBox::scrollDownButton = nullptr;

int ScrollingChoiceBox::scrollBarOption = 1; // 0 is outside box, 1 is inside box

int ScrollingChoiceBox::scrollButtonX = 940;
int ScrollingChoiceBox::scrollButtonY1 = 147;
int ScrollingChoiceBox::scrollButtonY2 = 510;
int ScrollingChoiceBox::scrollBarHeight = 347;
int ScrollingChoiceBox::scrollBarX = 941;
int ScrollingChoiceBox::scrollBarY1 = 162;
int ScrollingChoiceBox::scrollBarY2 = 509;

void ScrollingChoiceBox::OnInit()
{
    renderingEventBoxState = 0;

    if (scrollBarOption == 1)
    {
        scrollButtonX = 919;
        scrollButtonY1 = 158;
        scrollButtonY2 = 499;
        scrollBarHeight = 325;
        scrollBarX = 920;
        scrollBarY1 = 173;
        scrollBarY2 = 498;
    }
//    else if (scrollBarOption == 2)
//    {
//        scrollButtonX = 932;
//        scrollButtonY1 = 158;
//        scrollButtonY2 = 499;
//        scrollBarHeight = 325;
//        scrollBarX = 933;
//        scrollBarY1 = 173;
//        scrollBarY2 = 498;
//    }

    scrollUpButton = new Button();
    scrollUpButton->OnInit("statusUI/button_crew_up", Point(scrollButtonX, scrollButtonY1));

    scrollDownButton = new Button();
    scrollDownButton->OnInit("statusUI/button_crew_down", Point(scrollButtonX, scrollButtonY2));

    // fix a bug with ChoiceBox
    ChoiceBox &choiceBox = G_->GetWorld()->commandGui->choiceBox;
    if (!choiceBox.box)
    {
        choiceBox.box = new WindowFrame(7, 22, 602, 377);
    }
}

void ScrollingChoiceBox::Scroll(float amount)
{
    scrollAmount += amount;
    scrollAmount = std::max(0.f, std::min(scrollAmount, GetMaxScroll()));
}

void ScrollingChoiceBox::ScrollTo(float amount)
{
    scrollAmount = amount;
    scrollAmount = std::max(0.f, std::min(scrollAmount, GetMaxScroll()));
}

Globals::Rect ScrollingChoiceBox::GetScrollRect()
{
    ChoiceBox &choiceBox = G_->GetWorld()->commandGui->choiceBox;

    Globals::Rect rect;

    float current_top = ScrollingChoiceBox::scrollAmount;
    float current_bot = current_top + 369.f;
    float height = GetMaxScroll() + 369.f;

    rect.y = scrollBarY1 + scrollBarHeight*(current_top/height);
    rect.h = scrollBarY1 + scrollBarHeight*(current_bot/height);
    rect.h -= rect.y;
    rect.x = scrollBarX;
    rect.w = 10;
    if (!choiceBox.centered) rect.x -= 150;

    return rect;
}

bool ScrollingChoiceBox::OnScrollWheel(float direction)
{
    ChoiceBox &choiceBox = G_->GetWorld()->commandGui->choiceBox;

    if (choiceBox.bOpen)
    {
        Scroll(50.f*direction);
        return true;
    }

    return false;
}

float ScrollingChoiceBox::GetMaxScroll()
{
    ChoiceBox &choiceBox = G_->GetWorld()->commandGui->choiceBox;
    return choiceBox.lastChoice.y - 516.f;
}

HOOK_METHOD(ChoiceBox, OnRender, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ChoiceBox::OnRender -> Begin (ScrollingChoiceBox.cpp)\n")

    if (ScrollingChoiceBox::renderingEventBoxState == -1)
    {
        ScrollingChoiceBox::OnInit();
    }

    if (this == &(G_->GetWorld()->commandGui->choiceBox))
    {
        ScrollingChoiceBox::renderingEventBoxState = 1;
        super();
        if (ScrollingChoiceBox::renderingEventBoxState == 2)
        {
            CSurface::GL_SetStencilMode(STENCIL_IGNORE, 0, 0);
            CSurface::GL_PopMatrix();
        }
        ScrollingChoiceBox::renderingEventBoxState = 0;

        if (centered)
        {
            ScrollingChoiceBox::scrollUpButton->SetLocation({ScrollingChoiceBox::scrollButtonX, ScrollingChoiceBox::scrollButtonY1});
            ScrollingChoiceBox::scrollDownButton->SetLocation({ScrollingChoiceBox::scrollButtonX, ScrollingChoiceBox::scrollButtonY2});
        }
        else
        {
            ScrollingChoiceBox::scrollUpButton->SetLocation({ScrollingChoiceBox::scrollButtonX-150, ScrollingChoiceBox::scrollButtonY1});
            ScrollingChoiceBox::scrollDownButton->SetLocation({ScrollingChoiceBox::scrollButtonX-150, ScrollingChoiceBox::scrollButtonY2});
        }

        if (ScrollingChoiceBox::GetMaxScroll() > 0.f)
        {
            ScrollingChoiceBox::scrollUpButton->OnRender();
            ScrollingChoiceBox::scrollDownButton->OnRender();

            Globals::Rect rect = ScrollingChoiceBox::GetScrollRect();

            CSurface::GL_DrawRect(rect.x, rect.y, rect.w, rect.h, g_defaultTextButtonColors[ScrollingChoiceBox::barSelectState ? 2 : 1]);
        }
    }
    else
    {
        super();
    }
}

HOOK_METHOD(WindowFrame, Draw, (int x, int y) -> void)
{
    LOG_HOOK("HOOK_METHOD -> WindowFrame::Draw -> Begin (ScrollingChoiceBox.cpp)\n")
    super(x,y);
    if (ScrollingChoiceBox::renderingEventBoxState == 1)
    {
        ScrollingChoiceBox::renderingEventBoxState = 2;
        CSurface::GL_SetStencilMode(STENCIL_USE, 0x80, 0x80);
        CSurface::GL_PushMatrix();
        CSurface::GL_Translate(0.f, -ScrollingChoiceBox::scrollAmount, 0.f);
    }
}

HOOK_METHOD(ChoiceBox, MouseMove, (int mX, int mY) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ChoiceBox::MouseMove -> Begin (ScrollingChoiceBox.cpp)\n")
    if (this == &(G_->GetWorld()->commandGui->choiceBox))
    {
        // only register clicks within the window
        if (mY >= 147 && mY <= 524)
        {
            // offset by scroll amount
            super(mX,mY+ScrollingChoiceBox::scrollAmount);
        }
        else
        {
            // won't register any choice
            super(-1,-1);
        }

        if (ScrollingChoiceBox::renderingEventBoxState >= 0)
        {
            bool canScroll = ScrollingChoiceBox::GetMaxScroll() > 0.f;
            if (canScroll)
            {
                ScrollingChoiceBox::scrollUpButton->MouseMove(mX, mY, false);
                ScrollingChoiceBox::scrollDownButton->MouseMove(mX, mY, false);
            }
            else
            {
                ScrollingChoiceBox::scrollUpButton->bHover = false;
                ScrollingChoiceBox::scrollDownButton->bHover = false;
                ScrollingChoiceBox::barSelectState = false;
            }

            if (ScrollingChoiceBox::dragging != -1)
            {
                ScrollingChoiceBox::ScrollTo(((ScrollingChoiceBox::GetMaxScroll() + 369.f) * (mY - ScrollingChoiceBox::dragging - ScrollingChoiceBox::scrollBarY1)) / ScrollingChoiceBox::scrollBarHeight);
            }
            else if (canScroll)
            {
                Globals::Rect rect = ScrollingChoiceBox::GetScrollRect();
                ScrollingChoiceBox::barSelectState = mX >= rect.x-1 && mX < rect.x+rect.w+1 && mY >= rect.y && mY < rect.y+rect.h;
            }
        }
    }
    else
    {
        super(mX,mY);
    }
}

HOOK_METHOD(ChoiceBox, MouseClick, (int mX, int mY) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ChoiceBox::MouseClick -> Begin (ScrollingChoiceBox.cpp)\n")
    super(mX,mY);

    if (this == &(G_->GetWorld()->commandGui->choiceBox))
    {
        if (ScrollingChoiceBox::renderingEventBoxState >= 0)
        {
            if (ScrollingChoiceBox::scrollUpButton->bHover)
            {
                ScrollingChoiceBox::Scroll(-50.f);
            }
            else if (ScrollingChoiceBox::scrollDownButton->bHover)
            {
                ScrollingChoiceBox::Scroll(50.f);
            }
            else
            {
                Globals::Rect rect = ScrollingChoiceBox::GetScrollRect();
                if (mX >= rect.x-1 && mX < rect.x+rect.w+1)
                {
                    if (mY >= rect.y && mY < rect.y+rect.h)
                    {
                        ScrollingChoiceBox::dragging = mY - rect.y;
                        ScrollingChoiceBox::barSelectState = true;
                    }
                    else if (mY >= ScrollingChoiceBox::scrollBarY1-1 && mY < rect.y)
                    {
                        ScrollingChoiceBox::Scroll(-369.f);
                    }
                    else if (mY <= ScrollingChoiceBox::scrollBarY2)
                    {
                        ScrollingChoiceBox::Scroll(369.f);
                    }
                }
            }
        }
    }
}

HOOK_METHOD(WorldManager, CreateChoiceBox, (LocationEvent *event) -> void)
{
    LOG_HOOK("HOOK_METHOD -> WorldManager::CreateChoiceBox -> Begin (ScrollingChoiceBox.cpp)\n")
    ScrollingChoiceBox::scrollAmount = 0.f;
    super(event);
}

HOOK_METHOD(CommandGui, LButtonUp, (int mX, int mY, bool shift) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CommandGui::LButtonUp -> Begin (ScrollingChoiceBox.cpp)\n")
    super(mX,mY,shift);
    ScrollingChoiceBox::dragging = -1;
}
