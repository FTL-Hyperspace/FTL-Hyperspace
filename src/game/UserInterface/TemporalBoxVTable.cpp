#include "Global.h"
#include "helpers/PALMemoryProtection.h"

#pragma GCC push_options
#pragma GCC optimize ("O1")
#include "TemporalSystem.h"

const int g_temporalBoxVTableSize = 22;
static void* g_temporalBoxVTable[g_temporalBoxVTableSize];

int TemporalBox::_HS_GetCooldownLevel()
{
    if (this->temporalSystem->bTurnedOn)
    {
        return this->pSystem->GetEffectivePower();
    }

    return -1;
}

float TemporalBox::_HS_GetCooldownFraction()
{
    if (this->temporalSystem->IsReady() || !this->temporalSystem->bTurnedOn)
    {
        return -1.f;
    }
    else
    {
        return 1.f - (this->temporalSystem->timer.currTime / this->temporalSystem->timer.currGoal);
    }
}

bool TemporalBox::_HS_HasButton()
{
    return true;
}

void TemporalBox::_HS_OnRender(bool ignoreStatus)
{
#ifdef HS_ANDROID
    // As FTL for iPad's cloaking box: the box (and its frame when open) first, the buttons on it
    this->CooldownSystemBox::OnRender(ignoreStatus);
    if (this->tapped) this->RenderTouchButtons();
#else
    this->RenderBox(ignoreStatus);
    this->CooldownSystemBox::OnRender(ignoreStatus);
#endif
}

void TemporalBox::_HS_MouseMove(int x, int y)
{
    this->SystemBox::MouseMove(x,y);
    this->NewMouseMove(x,y);
}

bool TemporalBox::_HS_MouseClick(bool shift)
{
    bool ret = this->SystemBox::MouseClick(shift);
    this->LeftMouseClick(shift);
    return ret;
}

#ifdef HS_ANDROID
// FTL for iPad only takes touches. As with its cloaking box, the buttons are there only while
// the box is open, and get the touches inside them; arming closes the box so the next touch
// can pick the room.
void TemporalBox::_HS_OnTouch(TouchAction action, int id, int x, int y, int initialX, int initialY)
{
    if (!this->tapped || this->temporalSystem->bTurnedOn || this->pSystem->GetLocked())
    {
        this->speedUpButton->OnTouch(TOUCH_CANCEL, id, 0, 0, 0, 0);
        this->slowDownButton->OnTouch(TOUCH_CANCEL, id, 0, 0, 0, 0);
        return this->SystemBox::OnTouch(action, id, x, y, initialX, initialY);
    }

    int bx = x - this->buttonOffset.x, by = y - this->buttonOffset.y;
    int ix = initialX - this->buttonOffset.x, iy = initialY - this->buttonOffset.y;
    bool onButton = this->speedUpButton->OnTouch(action, id, bx, by, ix, iy);
    onButton = this->slowDownButton->OnTouch(action, id, bx, by, ix, iy) || onButton;
    TemporalArmState armed = TEMPORAL_ARM_NONE;
    if (this->speedUpButton->bActive && this->speedUpButton->bActivated) armed = TEMPORAL_ARM_SPEED;
    if (this->slowDownButton->bActive && this->slowDownButton->bActivated) armed = TEMPORAL_ARM_SLOW;
    if (armed != TEMPORAL_ARM_NONE)
    {
        this->temporalSystem->SetArmed(armed);
        this->CloseTapBox();
        return;
    }
    if (!onButton)
    {
        this->SystemBox::OnTouch(action, id, x, y, initialX, initialY);
    }
}
#endif

void TemporalBox::_HS_KeyDown(SDLKey key, bool shift)
{
    this->SystemBox::KeyDown(key, shift);
    this->OnKeyDown(key, shift);
}

void SetupVTable(TemporalBox* box)
{
    void** vtable = *(void***)box;

    MEMPROT_SAVE_PROT(dwOldProtect);
    MEMPROT_PAGESIZE();
    MEMPROT_UNPROTECT(&vtable[0], sizeof(void*) * g_temporalBoxVTableSize, dwOldProtect);

    for (int i = 0; i < g_temporalBoxVTableSize; i++)
    {
        g_temporalBoxVTable[i] = vtable[i];
    }

    MEMPROT_REPROTECT(&vtable[0], sizeof(void*) * g_temporalBoxVTableSize, dwOldProtect);

    {
        auto fptr = &TemporalBox::_HS_HasButton;
        g_temporalBoxVTable[3] = reinterpret_cast<void *&>(fptr);
    }
    {
        auto fptr = &TemporalBox::_HS_OnRender;
        g_temporalBoxVTable[7] = reinterpret_cast<void *&>(fptr);
    }
    {
        auto fptr = &TemporalBox::_HS_MouseMove;
        g_temporalBoxVTable[9] = reinterpret_cast<void *&>(fptr);
    }
    {
        auto fptr = &TemporalBox::_HS_MouseClick;
        g_temporalBoxVTable[10] = reinterpret_cast<void *&>(fptr);
    }
#ifdef HS_ANDROID
    {
        auto fptr = &TemporalBox::_HS_OnTouch;
        g_temporalBoxVTable[12] = reinterpret_cast<void *&>(fptr);
    }
#endif
    {
        auto fptr = &TemporalBox::_HS_KeyDown;
        g_temporalBoxVTable[18] = reinterpret_cast<void *&>(fptr);
    }
    {
        auto fptr = &TemporalBox::_HS_GetCooldownLevel;
        g_temporalBoxVTable[19] = reinterpret_cast<void *&>(fptr);
    }
    {
        auto fptr = &TemporalBox::_HS_GetCooldownFraction;
        g_temporalBoxVTable[20] = reinterpret_cast<void *&>(fptr);
    }

    *((void**)box)= &g_temporalBoxVTable;
}

TemporalBox::TemporalBox(Point pos, ShipSystem *sys, ShipManager *ship)
{
    temporalSystem = SYS_EX(sys)->temporalSystem;
    CooldownSystemBox::constructor(pos, sys, false);
    SetupVTable(this);
    shipManager = ship;

    slowDownButton = new Button();
    slowDownButton->OnInit("systemUI/button_temporal_slow", Point(9, 35));
    speedUpButton = new Button();
    speedUpButton->OnInit("systemUI/button_temporal_speed", Point(9, 9));
#ifdef HS_ANDROID
    // Laid out like the two buttons of FTL for iPad's teleporter box: 56x56 squares at 0 and 68
    // in the open box (RenderTouchButtons draws these 22x22 images at twice the size in them)
    speedUpButton->SetLocation(Point(0, 0));
    speedUpButton->hitbox = Globals::Rect(0, 0, 56, 56);
    slowDownButton->SetLocation(Point(0, 0));
    slowDownButton->hitbox = Globals::Rect(0, 68, 56, 56);
    tapButtonHeights.push_back(56); // the iPad makes the open box tall enough for them
    tapButtonHeights.push_back(56);
#endif

    buttonOffset = Point(location.x + 34, location.y - 39);

    box = G_->GetResources()->GetImageId("systemUI/button_temporal_base.png");
}

TemporalBox::~TemporalBox()
{
    delete slowDownButton;
    delete speedUpButton;
}

#pragma GCC pop_options
