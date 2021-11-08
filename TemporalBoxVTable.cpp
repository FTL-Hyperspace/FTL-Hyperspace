#include "Global.h"

#pragma GCC push_options
#pragma GCC optimize ("O1")
#include "TemporalSystem.h"

const int g_temporalBoxVTableSize = 22;
static void* g_temporalBoxVTable[g_temporalBoxVTableSize];

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

static void __attribute__((fastcall)) TemporalBox_OnRender(TemporalBox *_this, int _edx, bool ignoreStatus)
{
    _this->RenderBox(ignoreStatus);
    _this->CooldownSystemBox::OnRender(ignoreStatus);
}

static void __attribute__((fastcall)) TemporalBox_MouseMove(TemporalBox *_this, int _edx, int x, int y)
{
    _this->SystemBox::MouseMove(x,y);
    _this->NewMouseMove(x,y);
}

static bool __attribute__((fastcall)) TemporalBox_MouseClick(TemporalBox *_this, int _edx, bool shift)
{
    bool ret = _this->SystemBox::MouseClick(shift);
    _this->LeftMouseClick(shift);
    return ret;
}

static void __attribute__((fastcall)) TemporalBox_KeyDown(TemporalBox *_this, int _edx, SDLKey key, bool shift)
{
    _this->SystemBox::KeyDown(key, shift);
    _this->OnKeyDown(key, shift);
}

void SetupVTable(TemporalBox* box)
{
    void** vtable = *(void***)box;

    DWORD dwOldProtect, dwBkup;
    VirtualProtect(&vtable[0], sizeof(void*) * g_temporalBoxVTableSize, PAGE_EXECUTE_READWRITE, &dwOldProtect);

    for (int i = 0; i < g_temporalBoxVTableSize; i++)
    {
        g_temporalBoxVTable[i] = vtable[i];
    }

    VirtualProtect(&vtable[0], sizeof(void*) * g_temporalBoxVTableSize, dwOldProtect, &dwBkup);

    g_temporalBoxVTable[3] = (void*)&TemporalBox_HasButton;
    g_temporalBoxVTable[7] = (void*)&TemporalBox_OnRender;
    g_temporalBoxVTable[9] = (void*)&TemporalBox_MouseMove;
    g_temporalBoxVTable[10] = (void*)&TemporalBox_MouseClick;
    g_temporalBoxVTable[18] = (void*)&TemporalBox_KeyDown;
    g_temporalBoxVTable[19] = (void*)&TemporalBox_GetCooldownLevel;
    g_temporalBoxVTable[20] = (void*)&TemporalBox_GetCooldownFraction;

    *((void**)box)= &g_temporalBoxVTable;
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

TemporalBox::~TemporalBox()
{
    delete slowDownButton;
    delete speedUpButton;
}

#pragma GCC pop_options
