#include "TemporalSystem.h"

const int g_temporalVTableSize = 22;
static void* g_temporalVTable[g_temporalVTableSize];

static TemporalArmState g_iTemporal = TEMPORAL_ARM_NONE;


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
    g_temporalVTable[19] = (void*)&TemporalBox_GetCooldownLevel;
    g_temporalVTable[20] = (void*)&TemporalBox_GetCooldownFraction;

    *((void**)box)= &g_temporalVTable;
}


TemporalBox::TemporalBox(Point pos, ShipSystem *sys, ShipManager *ship)
{
    temporalSystem = SYS_EX(sys)->temporalSystem;
    CooldownSystemBox::constructor(pos, sys, false);
    shipManager = ship;

    slowDownButton = new Button();
    slowDownButton->OnInit("systemUI/button_temporal_slow", 9, 35);
    speedUpButton = new Button();
    speedUpButton->OnInit("systemUI/button_temporal_speed", 9, 10);

    buttonOffset = Point(location.x + 34, location.y - 39);

    box = G_->GetResources()->GetImageId("systemUI/button_temporal_base.png");
}

void TemporalBox::RenderBox(bool ignoreStatus)
{
    CSurface::GL_PushMatrix();
    CSurface::GL_Translate(buttonOffset.x, buttonOffset.y);

    if (!temporalSystem->bTurnedOn)
    {
        speedUpButton->bActive = temporalSystem->IsReady();
        slowDownButton->bActive = temporalSystem->IsReady();
        CSurface::GL_Translate(2.f, 0.f);
        CSurface::GL_BlitPixelImage(box, 0.f, 0.f, 40.f, 81.f, 0.f, COLOR_WHITE, false);

        speedUpButton->OnRender();
        slowDownButton->OnRender();
    }


    CSurface::GL_PopMatrix();
}

void TemporalBox::NewMouseMove(int x, int y)
{
    if (!pSystem->GetLocked())
    {
        speedUpButton->MouseMove(x - buttonOffset.x, y - buttonOffset.y, false);
        slowDownButton->MouseMove(x - buttonOffset.x, y - buttonOffset.y, false);

        if (speedUpButton->bActive && speedUpButton->bHover)
        {
            // tooltip
        }
        if (slowDownButton->bActive && slowDownButton->bHover)
        {
            // tooltip
        }
    }
}

void TemporalBox::LeftMouseClick(bool unk)
{
    if (!pSystem->GetLocked())
    {
        if (speedUpButton->bActive && speedUpButton->bHover)
        {
            temporalSystem->SetArmed(TEMPORAL_ARM_SPEED);
        }
        if (slowDownButton->bActive && slowDownButton->bHover)
        {
            temporalSystem->SetArmed(TEMPORAL_ARM_SLOW);
        }
    }
}

void TemporalSystem_Wrapper::StartTimeDilation(int shipId, int roomId, bool speedUp)
{
    if (!orig->GetLocked())
    {
        if (orig->Functioning())
        {
            auto ship = G_->GetShipManager(shipId);
            if (ship)
            {
                auto room = ship->ship.vRoomList[roomId];

                if (room)
                {
                    bTurnedOn = true;
                    orig->LockSystem(-1);
                    timer.Start(orig->GetEffectivePower() * 10.f);

                    RM_EX(room)->timeDilation = speedUp ? orig->GetEffectivePower() : -orig->GetEffectivePower();
                    currentRoom = room;

                    isSpeeding = speedUp;
                    currentShipId = shipId;
                }
            }
        }
    }
}

void TemporalSystem_Wrapper::StopTimeDilation()
{
    if (bTurnedOn)
    {
        RM_EX(currentRoom)->timeDilation = 0;

        orig->AddLock(4);
        bTurnedOn = false;
        currentRoom = nullptr;
        currentShipId = -1;
    }
}


void TemporalSystem_Wrapper::OnLoop()
{
    timer.SetMaxTime(orig->GetEffectivePower() * 5.f);

    if (!orig->Functioning() || (orig->iHackEffect > 1 && orig->bUnderAttack) || currentShipId == -1 || G_->GetShipManager(currentShipId) == nullptr)
    {
        // Stop time dilation
        StopTimeDilation();
    }

    if (bTurnedOn)
    {
        timer.Update();

        if (timer.Done())
        {
            StopTimeDilation();
        }


        if (currentRoom != nullptr && G_->GetShipManager(currentShipId) == nullptr) // not sure if this works
        {
            // Set time dilation for room

            RM_EX(currentRoom)->timeDilation = isSpeeding ? orig->GetEffectivePower() : -orig->GetEffectivePower();
        }
    }
}

TemporalArmState GetTemporalArmed(ShipManager *ship)
{
    if (ship->GetSystem(20) == nullptr) return TEMPORAL_ARM_NONE;

    return SYS_EX(ship->GetSystem(20))->temporalSystem->GetArmed();
}

void SetTemporalArmed(ShipManager *ship, TemporalArmState armState)
{
    if (ship->GetSystem(20) != nullptr) SYS_EX(ship->GetSystem(20))->temporalSystem->SetArmed(armState);
}

HOOK_METHOD(CooldownSystemBox, constructor, (Point pos, ShipSystem *sys, bool roundDown) -> void)
{
    super(pos, sys, roundDown);

    if (sys->iSystemType == 20)
    {
        SetupVTable((TemporalBox*)this);
    }
}

HOOK_METHOD(SystemBox, MouseMove, (int x, int y) -> void)
{
    super(x, y);

    if (pSystem->iSystemType == 20)
    {
        ((TemporalBox*)this)->NewMouseMove(x, y);
    }
}

HOOK_METHOD(SystemBox, MouseClick, (bool unk) -> bool)
{
    bool ret = super(unk);

    if (pSystem->iSystemType == 20)
    {
        ((TemporalBox*)this)->LeftMouseClick(unk);
    }
}

HOOK_METHOD(ShipSystem, OnLoop, () -> void)
{
    super();
    if (iSystemType == 20)
    {
        SYS_EX(this)->temporalSystem->OnLoop();
    }
}

HOOK_METHOD(CooldownSystemBox, OnRender, (bool ignoreStatus) -> void)
{
    if (pSystem->iSystemType == 20)
    {
        ((TemporalBox*)this)->RenderBox(ignoreStatus);
    }

    super(ignoreStatus);
}

HOOK_METHOD(ShipSystem, constructor, (int systemId, int roomId, int shipId, int startingPower) -> void)
{
	super(systemId, roomId, shipId, startingPower);

	if (systemId == 20)
    {
        SYS_EX(this)->temporalSystem = new TemporalSystem_Wrapper(this);
    }
}

HOOK_METHOD(CombatControl, SelectTarget, () -> bool)
{
    auto temporalArmed = GetTemporalArmed(shipManager);
    if (temporalArmed != TEMPORAL_ARM_NONE)
    {
        auto temporal = SYS_EX(shipManager->GetSystem(20))->temporalSystem;

        if (selectedSelfRoom != -1)
        {
            temporal->StartTimeDilation(0, selectedSelfRoom, temporalArmed == TEMPORAL_ARM_SPEED);

            SetTemporalArmed(shipManager, TEMPORAL_ARM_NONE);
            selectedSelfRoom = -1;
            shipManager->ship.SetSelectedRoom(-1);
            return true;
        }
        else if (selectedRoom != -1 && currentTarget)
        {
            temporal->StartTimeDilation(1, selectedRoom, temporalArmed == TEMPORAL_ARM_SLOW);

            SetTemporalArmed(shipManager, TEMPORAL_ARM_NONE);
            selectedSelfRoom = -1;
            currentTarget->shipManager->ship.SetSelectedRoom(-1);
            return true;
        }
    }

    return super();
}

HOOK_METHOD(CombatControl, WeaponsArmed, () -> bool)
{
    bool ret = super();

    return ret | (GetTemporalArmed(shipManager) != TEMPORAL_ARM_NONE);
}

HOOK_METHOD(CombatControl, UpdateTarget, () -> bool)
{
    bool ret = super();

    if (GetTemporalArmed(shipManager))
    {
        shipManager->ship.SetSelectedRoom(selectedSelfRoom);
        if (currentTarget)
        {
            currentTarget->shipManager->ship.SetSelectedRoom(selectedRoom);
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

        if (GetTemporalArmed(shipManager) != TEMPORAL_ARM_NONE)
        {
            g_iTemporal = GetTemporalArmed(shipManager);

            if (selectedSelfRoom != -1 || selectedRoom != -1)
            {
                G_->GetMouseControl()->valid = true;
                G_->GetMouseControl()->lastValid = true;
            }
        }
        else
        {
            g_iTemporal = TEMPORAL_ARM_NONE;
        }
    }
}

HOOK_METHOD(CombatControl, DisarmAll, () -> void)
{
    super();

    if (GetTemporalArmed(shipManager))
    {
        shipManager->ship.SetSelectedRoom(-1);

        if (currentTarget)
        {
            currentTarget->shipManager->ship.SetSelectedRoom(-1);
        }

        SetTemporalArmed(shipManager, TEMPORAL_ARM_NONE);
    }
}

HOOK_METHOD(CombatControl, MouseRClick, (int x, int y) -> bool)
{
    bool temporalArmed = GetTemporalArmed(shipManager);

    bool ret = super(x, y);

    return ret | (temporalArmed != TEMPORAL_ARM_NONE);
}

static bool g_inMouseRender = false;

HOOK_METHOD(ResourceControl, GetImageId, (const std::string& name) -> GL_Texture*)
{
    if (g_inMouseRender && name == "mouse/mouse_hacking.png" && g_iTemporal != TEMPORAL_ARM_NONE)
    {
        if (g_iTemporal == TEMPORAL_ARM_SLOW)
        {
            return super("mouse/mouse_temporal_slow.png");
        }
        else
        {
            return super("mouse/mouse_temporal_speed.png");
        }
    }

    return super(name);
}

HOOK_METHOD(MouseControl, OnRender, () -> void)
{
    if (g_iTemporal != TEMPORAL_ARM_NONE)
    {
        int oldHacking = iHacking;
        iHacking = true;
        g_inMouseRender = true;

        super();

        iHacking = oldHacking;
        g_inMouseRender = false;
        return;
    }

    super();
}


HOOK_METHOD(ShipManager, OnRender, (bool showInterior, bool doorControlMode) -> void)
{
    super(showInterior, doorControlMode);

    bool canSeeRooms = false;

    if (iShipId == 1)
    {
        bool hasCloakingSystem = systemKey[10] != -1;

        canSeeRooms = (_targetable.hostile && (!hasCloakingSystem || !cloakSystem->bTurnedOn)) || bContainsPlayerCrew;
    }
    else
    {
        canSeeRooms = bShowRoom;
    }

    canSeeRooms = canSeeRooms && !bDestroyed && !bJumping;

    if (canSeeRooms)
    {
        for (auto room : ship.vRoomList)
        {
            if (RM_EX(room)->timeDilation != 0)
            {
                CSurface::GL_PushMatrix();
                CSurface::GL_Translate(room->rect.x, room->rect.y);
                CSurface::GL_SetColor(255.f, 0.f, 0.f, 1.f);
                freetype::easy_print(0, 20.f, 20.f, std::to_string(RM_EX(room)->timeDilation));
                CSurface::GL_PopMatrix();
            }
        }
    }
}

static int g_dilationAmount = 0;

HOOK_METHOD(CFPS, GetSpeedFactor, () -> float)
{
    float ret = super();

    if (g_dilationAmount != 0)
    {
        if (g_dilationAmount > 0)
        {
            ret *= (g_dilationAmount * 1.5);
        }
        else
        {
            ret /= -(g_dilationAmount * 1.5);
        }
    }

    return ret;
}

static std::map<int, int> g_crewDilationRooms = std::map<int, int>();

HOOK_METHOD(CrewMember, OnLoop, () -> void)
{
    int dilationAmount = 0;

    if (g_crewDilationRooms.find(iRoomId) != g_crewDilationRooms.end())
    {
        dilationAmount = g_crewDilationRooms[iRoomId];
    }

    if (dilationAmount != 0)
    {
        g_dilationAmount = dilationAmount;
        super();
        g_dilationAmount = 0;

        return;
    }

    super();
}

HOOK_METHOD(ShipManager, UpdateCrewMembers, () -> void)
{
    for (auto i : ship.vRoomList)
    {
        if (RM_EX(i)->timeDilation != 0)
        {
            g_crewDilationRooms[i->iRoomId] = RM_EX(i)->timeDilation;
        }
    }

    super();

    g_crewDilationRooms.clear();
}
