#include "Global.h"
#include "PALMemoryProtection.h"
#include "InputManager.h"

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
    if (InputManager::GetInstance()->currentInputDevice == InputManager::TOUCHSCREEN)
    {
        this->RenderTouchBox(ignoreStatus);
    }
    else
    {
        this->RenderPCBox(ignoreStatus);
    }
    this->CooldownSystemBox::OnRender(ignoreStatus);
}

void TemporalBox::_HS_OnTouch(TouchAction action, int id, int x, int y, int initialX, int initialY)
{
    this->SystemBox::OnTouch(action, id, x, y, initialX, initialY);
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
    {
        auto fptr = &TemporalBox::_HS_OnTouch;
        g_temporalBoxVTable[12] = reinterpret_cast<void *&>(fptr);
    }
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

    buttonOffset = Point(location.x + 34, location.y - 39);

    box = G_->GetResources()->GetImageId("systemUI/button_temporal_base.png");
}

TemporalBox::~TemporalBox()
{
    delete slowDownButton;
    delete speedUpButton;
}

#pragma GCC pop_options
