#include "Global.h"

#pragma GCC push_options
#pragma GCC optimize ("O1")
#include "TemporalSystem.h"

const int g_temporalVTableSize = 22;
static void* g_temporalVTable[g_temporalVTableSize];

static int __attribute__((fastcall)) TemporalBox_GetCooldownLevel(TemporalBox *_this)
{
    if (_this->temporalSystem->bTurnedOn)
    {
        return _this->pSystem->GetEffectivePower();
    }

    return -1;
}

static float __attribute__((fastcall)) TemporalBox_GetCooldownFraction(TemporalBox *_this)
{
    if (_this->temporalSystem->IsReady() || !_this->temporalSystem->bTurnedOn)
    {
        return -1.f;
    }
    else
    {
        return 1.f - (_this->temporalSystem->timer.currTime / _this->temporalSystem->timer.currGoal);
    }
}

static bool __attribute__((fastcall)) TemporalBox_HasButton(TemporalBox *_this)
{
    return true;
}

static void __attribute__((fastcall)) TemporalBox_OnRender(TemporalBox *_this, bool ignoreStatus)
{
    _this->RenderBox(ignoreStatus);
    ((CooldownSystemBox*)_this)->OnRender(ignoreStatus);
}

static void __attribute__((fastcall)) TemporalBox_MouseMove(TemporalBox *_this, int x, int y)
{
    ((SystemBox*)_this)->MouseMove(x,y);
    _this->NewMouseMove(x,y);
}

static bool __attribute__((fastcall)) TemporalBox_MouseClick(TemporalBox *_this, bool shift)
{
    bool ret = ((SystemBox*)_this)->MouseClick(shift);
    _this->LeftMouseClick(shift);
    return ret;
}

static void __attribute__((fastcall)) TemporalBox_KeyDown(TemporalBox *_this, SDLKey key, bool shift)
{
    ((SystemBox*)_this)->KeyDown(key, shift);
    _this->OnKeyDown(key, shift);
}

void SetupVTable(TemporalBox* box)
{
    void** vtable = *(void***)box;

    DWORD dwOldProtect, dwBkup;
    VirtualProtect(&vtable[0], sizeof(void*) * g_temporalVTableSize, PAGE_EXECUTE_READWRITE, &dwOldProtect);

    for (int i = 0; i < g_temporalVTableSize; i++)
    {
        g_temporalVTable[i] = vtable[i];
    }

    VirtualProtect(&vtable[0], sizeof(void*) * g_temporalVTableSize, dwOldProtect, &dwBkup);

    g_temporalVTable[3] = (void*)&TemporalBox_HasButton;
    g_temporalVTable[7] = (void*)&TemporalBox_OnRender;
    g_temporalVTable[9] = (void*)&TemporalBox_MouseMove;
    g_temporalVTable[10] = (void*)&TemporalBox_MouseClick;
    g_temporalVTable[18] = (void*)&TemporalBox_KeyDown;
    g_temporalVTable[19] = (void*)&TemporalBox_GetCooldownLevel;
    g_temporalVTable[20] = (void*)&TemporalBox_GetCooldownFraction;

    *((void**)box)= &g_temporalVTable;
}

TemporalBox::TemporalBox(Point pos, ShipSystem *sys, ShipManager *ship)
{
    temporalSystem = SYS_EX(sys)->temporalSystem;
    CooldownSystemBox::constructor(pos, sys, false);
    SetupVTable(this);
    shipManager = ship;

    slowDownButton = new Button();
    slowDownButton->OnInit("systemUI/button_temporal_slow", 9, 35);
    speedUpButton = new Button();
    speedUpButton->OnInit("systemUI/button_temporal_speed", 9, 9);

    buttonOffset = Point(location.x + 34, location.y - 39);

    box = G_->GetResources()->GetImageId("systemUI/button_temporal_base.png");
}

#pragma GCC pop_options
