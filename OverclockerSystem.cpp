/* Scarpped for now
#include "OverclockerSystem.h"

const int g_overclockerVTableSize = 22;
static void* g_overclockerVTable[g_overclockerVTableSize];

static int g_iOverclocking = 0;


static int __attribute__((fastcall)) OverclockerBox_GetCooldownLevel(OverclockerBox *_this)
{
    if (_this->overclockerSystem->bTurnedOn)
    {
        return _this->pSystem->GetEffectivePower();
    }

    return -1;
}

static float __attribute__((fastcall)) OverclockerBox_GetCooldownFraction(OverclockerBox *_this)
{
    if (_this->overclockerSystem->IsReady() || !_this->overclockerSystem->bTurnedOn)
    {
        return -1.f;
    }
    else
    {
        return 1.f - (_this->overclockerSystem->timer.currTime / _this->overclockerSystem->timer.currGoal);
    }
}

static bool __attribute__((fastcall)) OverclockerBox_HasButton(OverclockerBox *_this)
{
    return true;
}
void SetupVTable(OverclockerBox* box)
{
    void** vtable = *(void***)box;

    DWORD dwOldProtect, dwBkup;
    VirtualProtect(&vtable[0], sizeof(void*) * g_overclockerVTableSize, PAGE_EXECUTE_READWRITE, &dwOldProtect);

    for (int i = 0; i < g_overclockerVTableSize; i++)
    {
        g_overclockerVTable[i] = vtable[i];
    }

    VirtualProtect(&vtable[0], sizeof(void*) * g_overclockerVTableSize, dwOldProtect, &dwBkup);

    g_overclockerVTable[3] = (void*)&OverclockerBox_HasButton;
    g_overclockerVTable[19] = (void*)&OverclockerBox_GetCooldownLevel;
    g_overclockerVTable[20] = (void*)&OverclockerBox_GetCooldownFraction;

    *((void**)box)= &g_overclockerVTable;
}


OverclockerBox::OverclockerBox(Point pos, ShipSystem *sys, ShipManager *ship)
{
    overclockerSystem = SYS_EX(sys)->overclockerSystem;
    CooldownSystemBox::constructor(pos, sys, false);
    shipManager = ship;

    overclockButton = new Button();
    overclockButton->OnInit("systemUI/button_overclocker_start", 9, 35);

    buttonOffset = Point(location.x + 34, location.y - 39);

    box = G_->GetResources()->GetImageId("systemUI/button_overclocker_base.png");
}

void OverclockerBox::RenderBox(bool ignoreStatus)
{
    CSurface::GL_PushMatrix();
    CSurface::GL_Translate(buttonOffset.x, buttonOffset.y);

    if (!overclockerSystem->bTurnedOn)
    {
        overclockButton->bActive = overclockerSystem->IsReady();
        CSurface::GL_Translate(2.f, 0.f);
        CSurface::GL_BlitPixelImage(box, 0.f, 0.f, 40.f, 81.f, 0.f, COLOR_WHITE, false);

        overclockButton->OnRender();
    }


    CSurface::GL_PopMatrix();
}

void OverclockerBox::NewMouseMove(int x, int y)
{
    if (!pSystem->GetLocked())
    {
        overclockButton->MouseMove(x - buttonOffset.x, y - buttonOffset.y, false);

        if (overclockButton->bActive && overclockButton->bHover)
        {
            // tooltip
        }
    }
}

void OverclockerBox::LeftMouseClick(bool unk)
{
    if (!pSystem->GetLocked() && overclockButton->bActive && overclockButton->bHover)
    {
        overclockerSystem->SetArmed(true);
    }
}

void OverclockerSystem_Wrapper::StartOverclock(ShipSystem *sys)
{
    if (!orig->GetLocked())
    {
        if (orig->Functioning())
        {
            bTurnedOn = true;
            orig->LockSystem(-1);
            currentSystem = sys;
            timer.Start(orig->GetEffectivePower() * 5.f);
        }
    }
}

void OverclockerSystem_Wrapper::StopOverclock()
{
    if (bTurnedOn)
    {
        SYS_EX(currentSystem)->iOverclockEffect = 0;
        currentSystem = nullptr;

        orig->AddLock(4);
        bTurnedOn = false;

    }
}

void OverclockerSystem_Wrapper::OnLoop()
{
    timer.SetMaxTime(orig->GetEffectivePower() * 5.f);

    if (!orig->Functioning() || (orig->iHackEffect > 1 && orig->bUnderAttack))
    {
        StopOverclock();
    }

    if (bTurnedOn)
    {
        timer.Update();
        if (timer.Done())
        {
            StopOverclock();
        }

        if (currentSystem != nullptr)
        {
            SYS_EX(currentSystem)->iOverclockEffect = orig->GetEffectivePower();
        }
    }

}

bool GetOverclockerArmed(ShipManager *ship)
{
    return ship->GetSystem(20) != nullptr && SYS_EX(ship->GetSystem(20))->overclockerSystem->GetArmed();
}

void SetOverclockerArmed(ShipManager *ship, bool armed)
{
    if (ship->GetSystem(20) != nullptr) SYS_EX(ship->GetSystem(20))->overclockerSystem->SetArmed(armed);
}

HOOK_METHOD(CooldownSystemBox, constructor, (Point pos, ShipSystem *sys, bool roundDown) -> void)
{
    super(pos, sys, roundDown);

    if (sys->iSystemType == 20)
    {
        SetupVTable((OverclockerBox*)this);
    }
}

HOOK_METHOD(SystemBox, MouseMove, (int x, int y) -> void)
{
    super(x, y);

    if (pSystem->iSystemType == 20)
    {
        ((OverclockerBox*)this)->NewMouseMove(x, y);
    }
}

HOOK_METHOD(SystemBox, MouseClick, (bool unk) -> bool)
{
    bool ret = super(unk);

    if (pSystem->iSystemType == 20)
    {
        ((OverclockerBox*)this)->LeftMouseClick(unk);
    }
}

HOOK_METHOD(ShipSystem, OnLoop, () -> void)
{
    super();
    if (iSystemType == 20)
    {
        SYS_EX(this)->overclockerSystem->OnLoop();
    }
}

HOOK_METHOD(CooldownSystemBox, OnRender, (bool ignoreStatus) -> void)
{
    if (pSystem->iSystemType == 20)
    {
        ((OverclockerBox*)this)->RenderBox(ignoreStatus);
    }

    super(ignoreStatus);
}

HOOK_METHOD(ShipSystem, constructor, (int systemId, int roomId, int shipId, int startingPower) -> void)
{
	super(systemId, roomId, shipId, startingPower);

	if (systemId == 20)
    {
        SYS_EX(this)->overclockerSystem = new OverclockerSystem_Wrapper(this);
    }
}
HOOK_METHOD(CombatControl, SelectTarget, () -> bool)
{
    if (GetOverclockerArmed(shipManager) && selectedSelfRoom != -1)
    {
        auto sys = shipManager->GetSystemInRoom(selectedSelfRoom);
        if (sys)
        {
            auto overclocker = SYS_EX(shipManager->GetSystem(20))->overclockerSystem;
            overclocker->StartOverclock(sys);
        }

        SetOverclockerArmed(shipManager, false);
        selectedSelfRoom = -1;
        shipManager->ship.SetSelectedRoom(-1);
        return true;
    }

    return super();
}

HOOK_METHOD(CombatControl, WeaponsArmed, () -> bool)
{
    bool ret = super();

    return ret | GetOverclockerArmed(shipManager);
}

HOOK_METHOD(CombatControl, UpdateTarget, () -> bool)
{
    bool ret = super();

    if (GetOverclockerArmed(shipManager))
    {
        shipManager->ship.SetSelectedRoom(selectedSelfRoom);

        auto sys = shipManager->GetSystemInRoom(selectedSelfRoom);

        if (sys)
        {
            if (sys->iSystemType == 5)
            {
                G_->GetMouseControl()->SetTooltip(G_->GetTextLibrary()->GetText("overclock_medbay"));
                G_->GetMouseControl()->InstantTooltip();
            }
        }

        // sys tooltip

        return true;
    }

    return ret;
}

HOOK_METHOD(CombatControl, OnRenderCombat, () -> void)
{
    super();
    if (open && !weapControl.armedWeapon)
    {
        if (GetOverclockerArmed(shipManager))
        {
            g_iOverclocking = 1;

            if (selectedSelfRoom != -1)
            {
                G_->GetMouseControl()->valid = true;
                G_->GetMouseControl()->lastValid = true;
            }
        }
        else
        {
            g_iOverclocking = 0;
        }
    }
}

HOOK_METHOD(CombatControl, DisarmAll, () -> void)
{
    super();

    if (GetOverclockerArmed(shipManager))
    {
        shipManager->ship.SetSelectedRoom(-1);
        SetOverclockerArmed(shipManager, false);
    }
}

HOOK_METHOD(CombatControl, MouseRClick, (int x, int y) -> bool)
{
    bool overclockerArmed = GetOverclockerArmed(shipManager);

    bool ret = super(x, y);

    return ret | overclockerArmed;
}

static bool g_inMouseRender = false;

HOOK_METHOD(ResourceControl, GetImageId, (const std::string& name) -> GL_Texture*)
{
    if (g_inMouseRender && name == "mouse/mouse_hacking.png" && g_iOverclocking != 0)
    {
        return super("mouse/mouse_overclocking.png");
    }

    return super(name);
}

HOOK_METHOD(MouseControl, OnRender, () -> void)
{
    if (g_iOverclocking != 0)
    {
        int oldHacking = iHacking;
        iHacking = true;

        super();

        iHacking = oldHacking;
        return;
    }

    super();
}


// Overclocking effects

HOOK_METHOD(ShipManager, UpdateCrewMembers, () -> void)
{

    for (auto i : vCrewList)
    {
        CM_EX(i)->extraMedbay = 0.f;
    }

    auto medbay = GetSystem(5);
    if (medbay)
    {
        int medbayEffect = SYS_EX(medbay)->iOverclockEffect;

        if (medbayEffect > 0)
        {
            for (auto i : vCrewList)
            {
                CM_EX(i)->extraMedbay = SYS_EX(medbay)->iOverclockEffect * 0.5f;
                i->fMedbay += 0.00000001f;
            }
        }
    }

    super();
}
*/
