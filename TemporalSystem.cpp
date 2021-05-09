#include "TemporalSystem.h"
#include "boost/algorithm/string.hpp"
#include "boost/lexical_cast.hpp"
#include <sstream>
#include <iomanip>

 std::map<int, float> TemporalSystemParser::levelSpeed = std::map<int, float>();
 std::map<int, float> TemporalSystemParser::levelSlow = std::map<int, float>();
 std::map<int, float> TemporalSystemParser::levelDurations = std::map<int, float>();
 std::map<int, int> TemporalSystemParser::levelCooldowns = std::map<int, int>();

void TemporalSystemParser::ParseSystemNode(rapidxml::xml_node<char>* node)
{
    for (auto child = node->first_node(); child; child = child->next_sibling())
    {
        std::string name = child->name();

        if (boost::algorithm::starts_with(name, "level"))
        {
            std::string levelStr = name.substr(5);

            if (child->first_attribute("duration"))
            {
                TemporalSystemParser::levelDurations[boost::lexical_cast<int>(levelStr)] = boost::lexical_cast<float>(child->first_attribute("duration")->value());
            }
            if (child->first_attribute("slowValue"))
            {
                TemporalSystemParser::levelSlow[boost::lexical_cast<int>(levelStr)] = boost::lexical_cast<float>(child->first_attribute("slowValue")->value());
            }
            if (child->first_attribute("speedValue"))
            {
                TemporalSystemParser::levelSpeed[boost::lexical_cast<int>(levelStr)] = boost::lexical_cast<float>(child->first_attribute("speedValue")->value());
            }
            if (child->first_attribute("cooldown"))
            {
                TemporalSystemParser::levelCooldowns[boost::lexical_cast<int>(levelStr)] = boost::lexical_cast<int>(child->first_attribute("cooldown")->value());
            }
        }
    }
}

float TemporalSystemParser::GetLevelDuration(int level)
{
    if (levelDurations.find(level) != levelDurations.end())
    {
        return levelDurations[level];
    }
    else
    {
        return 10.f;
    }
}

float TemporalSystemParser::GetDilationStrength(int level)
{
    auto timeMap = level > 0 ? levelSpeed : levelSlow;
    auto absLevel = std::abs(level);

    if (timeMap.find(level) != timeMap.end())
    {
        return timeMap[level];
    }
    else
    {
        return std::pow(2, level);
    }
}

int TemporalSystemParser::GetLevelCooldown(int level)
{
    printf("%d\n", levelCooldowns[level]);

    if (levelCooldowns.find(level) != levelCooldowns.end())
    {
        return levelCooldowns[level];
    }
    else
    {
        return 4;
    }
}


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
    speedUpButton->OnInit("systemUI/button_temporal_speed", 9, 9);

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
                    timer.Start(TemporalSystemParser::GetLevelDuration(orig->GetEffectivePower()));

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

        orig->AddLock(TemporalSystemParser::GetLevelCooldown(orig->GetEffectivePower()));
        bTurnedOn = false;
        currentRoom = nullptr;
        currentShipId = -1;
    }
}


void TemporalSystem_Wrapper::OnLoop()
{
    timer.SetMaxTime(TemporalSystemParser::GetLevelDuration(orig->GetEffectivePower()));

    if (!orig->Functioning() || (orig->iHackEffect > 1 && orig->bUnderAttack) || currentShipId == -1 || G_->GetShipManager(currentShipId) == nullptr)
    {
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

HOOK_METHOD(ShipManager, JumpArrive, () -> void)
{
    super();

    if (bWasSafe && HasSystem(20))
    {
        GetSystem(20)->LockSystem(0);
    }
}

HOOK_METHOD(ShipManager, JumpLeave, () -> void)
{
    super();

    if (HasSystem(20))
    {
        GetSystem(20)->LockSystem(0);
    }
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
            if (currentTarget && currentTarget->shipManager->GetShieldPower().super.first <= 0)
            {
                temporal->StartTimeDilation(1, selectedRoom, temporalArmed == TEMPORAL_ARM_SPEED);
            }

            SetTemporalArmed(shipManager, TEMPORAL_ARM_NONE);
            selectedRoom = -1;
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

HOOK_STATIC(ShipSystem, GetLevelDescription, (void* unk, std::string &retStr, int systemId, int level, bool tooltip) -> void)
{
    super(unk, retStr, systemId, level, tooltip);

    if (systemId == 20 && level != -1)
    {
        int realLevel = level + 1;

        std::string replStr = G_->GetTextLibrary()->GetText(tooltip ? "temporal_tooltip" : "temporal");

        std::stringstream stream;
        stream << std::fixed << std::setprecision(3) << TemporalSystemParser::GetDilationStrength(realLevel);

        std::string valueStr = stream.str();

        boost::trim_right_if(valueStr, boost::is_any_of("0"));
        boost::trim_right_if(valueStr, boost::is_any_of("."));

        boost::algorithm::replace_all(replStr, "\\1", valueStr);

        stream.str(std::string());

        stream << std::fixed << std::setprecision(3) << TemporalSystemParser::GetLevelDuration(realLevel);

        valueStr = stream.str();

        boost::trim_right_if(valueStr, boost::is_any_of("0"));
        boost::trim_right_if(valueStr, boost::is_any_of("."));

        boost::algorithm::replace_all(replStr, "\\2", valueStr);
        boost::algorithm::replace_all(replStr, "\\3", std::to_string(TemporalSystemParser::GetLevelCooldown(realLevel) * 5));
        boost::algorithm::replace_all(replStr, "\\n", "\n");

        retStr.assign(replStr);
    }
}

// Animation

HOOK_METHOD(Ship, OnRenderWalls, (bool forceView, bool doorControlMode) -> void)
{
    for (auto i : vRoomList)
    {
        auto ex = RM_EX(i);
        int timeDilation = ex->timeDilation;

        if (timeDilation != 0)
        {
            Animation* anim = nullptr;

            if (timeDilation > 0)
            {
                if (!ex->speedUpAnim)
                {
                    auto newAnim = new Animation();

                    AnimationControl::GetAnimation(*newAnim, G_->GetAnimationControl(), "room_temporal_speed");

                    ex->speedUpAnim = newAnim;
                    ex->speedUpAnim->SetCurrentFrame(0);
                    ex->speedUpAnim->tracker.SetLoop(true, 0);
                    ex->speedUpAnim->Start(true);
                }

                anim = ex->speedUpAnim;
            }
            else if (timeDilation < 0)
            {
                if (!ex->slowDownAnim)
                {
                    ex->slowDownAnim = new Animation();
                    AnimationControl::GetAnimation(*ex->slowDownAnim, G_->GetAnimationControl(), "room_temporal_slow");

                    ex->slowDownAnim->SetCurrentFrame(0);
                    ex->slowDownAnim->tracker.SetLoop(true, 0);
                    ex->slowDownAnim->Start(true);
                }

                anim = ex->slowDownAnim;
            }

            CSurface::GL_PushMatrix();

            // top

            for (int xPos = 0; xPos < i->rect.w / 35; xPos++)
            {
                CSurface::GL_PushMatrix();

                CSurface::GL_Translate(i->rect.x + xPos * 35, i->rect.y + i->rect.h - 35);
                anim->OnRender(1.f, COLOR_WHITE, false);

                CSurface::GL_PopMatrix();
            }

            // bottom

            for (int xPos = 0; xPos < i->rect.w / 35; xPos++)
            {
                CSurface::GL_PushMatrix();

                CSurface::GL_Translate(i->rect.x + xPos * 35 + 35, i->rect.y + 35.f);
                CSurface::GL_Rotate(180.f, 0.f, 0.f, 1.f);
                anim->OnRender(1.f, COLOR_WHITE, false);

                CSurface::GL_PopMatrix();
            }

            // left

            for (int yPos = 0; yPos < i->rect.h / 35; yPos++)
            {
                CSurface::GL_PushMatrix();

                CSurface::GL_Translate(i->rect.x + 35, i->rect.y + yPos * 35.f);
                CSurface::GL_Rotate(90.f, 0.f, 0.f, 1.f);
                anim->OnRender(1.f, COLOR_WHITE, false);

                CSurface::GL_PopMatrix();
            }

            // right

            for (int yPos = 0; yPos < i->rect.h / 35; yPos++)
            {
                CSurface::GL_PushMatrix();

                CSurface::GL_Translate(i->rect.x + i->rect.w - 35.f, i->rect.y + yPos * 35.f + 35.f);
                CSurface::GL_Rotate(-90.f, 0.f, 0.f, 1.f);
                anim->OnRender(1.f, COLOR_WHITE, false);

                CSurface::GL_PopMatrix();
            }

            /*
            for (int xPos = 0; xPos < i->rect.w / 35; xPos++)
            {
                CSurface::GL_PushMatrix();

                CSurface::GL_Translate(i->rect.x + xPos * 35 + 35, i->rect.y + 35.f);
                CSurface::GL_Rotate(180.f, 0.f, 0.f, 1.f);
                anim->OnRender(1.f, COLOR_WHITE, false);

                CSurface::GL_PopMatrix();
            }
            */


            // left & right

            /*
            for (int yPos = 0; yPos < i->rect.h / 35; yPos++)
            {
                CSurface::GL_PushMatrix();

                CSurface::GL_Translate(i->rect.x + i->rect.w - 35, i->rect.y + yPos * 35);
                CSurface::GL_Rotate(90.f, 0.f, 0.f, 1.f);
                anim->OnRender(1.f, COLOR_WHITE, false);

                CSurface::GL_Rotate(180.f, i->rect.w / 2.f, i->rect.h / 2.f, 1.f);
                anim->OnRender(1.f, COLOR_WHITE, false);

                CSurface::GL_PopMatrix();
            }
            */

            CSurface::GL_PopMatrix();
        }
    }

    super(forceView, doorControlMode);
}

HOOK_METHOD(CrewAI, PrioritizeTask, (CrewTask task, int crewId) -> int)
{
    if (task.system == 20) task.system = 15;
    return super(task, crewId);
}

// Effects

static int g_dilationAmount = 0;

HOOK_METHOD(CFPS, GetSpeedFactor, () -> float)
{
    float ret = super();

    if (g_dilationAmount != 0)
    {
        ret *= TemporalSystemParser::GetDilationStrength(g_dilationAmount);
    }

    return ret;
}

static std::map<int, int> g_crewDilationRooms = std::map<int, int>();
static std::map<int, int> g_envDilationRooms = std::map<int, int>();
static std::map<int, int> g_cloneDilationRooms = std::map<int, int>();

int GetRoomDilationAmount(std::map<int, int> roomMap, int roomId)
{
    int dilationAmount = 0;

    if (roomMap.find(roomId) != roomMap.end())
    {
        dilationAmount = roomMap[roomId];
    }

    return dilationAmount;
}

HOOK_METHOD(OxygenSystem, ModifyRoomOxygen, (int changeRoomId, float amount) -> void)
{
    int dilationAmount = GetRoomDilationAmount(g_envDilationRooms, changeRoomId);
    super(changeRoomId, amount * (float)TemporalSystemParser::GetDilationStrength(dilationAmount));
}

HOOK_METHOD(OxygenSystem, ComputeAirLoss, (int changeRoomId, float amount, bool unk) -> void)
{
    int dilationAmount = GetRoomDilationAmount(g_envDilationRooms, changeRoomId);
    if (dilationAmount > 0) printf("%d\n", dilationAmount);
    super(changeRoomId, amount * (float)TemporalSystemParser::GetDilationStrength(dilationAmount), unk);
}

HOOK_METHOD(Fire, OnLoop, () -> void)
{
    g_dilationAmount = GetRoomDilationAmount(g_envDilationRooms, roomId);
    super();
    g_dilationAmount = 0;
}

HOOK_METHOD(Fire, UpdateDeathTimer, (int connectedFires) -> void)
{
    g_dilationAmount = GetRoomDilationAmount(g_envDilationRooms, roomId);
    super(connectedFires);
    g_dilationAmount = 0;
}

HOOK_METHOD(Fire, UpdateStartTimer, (int doorLevel) -> void)
{
    g_dilationAmount = GetRoomDilationAmount(g_envDilationRooms, roomId);
    super(doorLevel);
    g_dilationAmount = 0;
}

/* fix this
HOOK_METHOD(CrewAnimation, OnUpdate, (Pointf position, bool moving, bool fighting, bool repairing, bool dying, bool onFire) -> void)
{
    if (g_dilationAmount > 0)
    {
        float dilationMul = TemporalSystemParser::GetDilationStrength(g_dilationAmount);
        int oldDilation = g_dilationAmount;
        g_dilationAmount = 0;

        for (int i = 0; i < std::floor(dilationMul); i++)
        {
            super(position, moving, fighting, repairing, dying, onFire);
        }

        g_dilationAmount = oldDilation;

        return;
    }

    super(position, moving, fighting, repairing, dying, onFire);
}
*/

HOOK_METHOD(CrewMember, OnLoop, () -> void)
{
    g_dilationAmount = GetRoomDilationAmount(g_crewDilationRooms, iRoomId);
    super();
    g_dilationAmount = 0;
}

HOOK_METHOD(CloneSystem, OnLoop, () -> void)
{
    g_dilationAmount = GetRoomDilationAmount(g_cloneDilationRooms, roomId);
    super();
    g_dilationAmount = 0;
}

HOOK_METHOD_PRIORITY(ShipManager, UpdateCrewMembers, -900, () -> void)
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

static bool g_inSpreadDamage = false;

HOOK_METHOD(ShipSystem, DamageOverTime, (float amount) -> void)
{
    if (!g_inSpreadDamage) return super(amount);

    g_dilationAmount = GetRoomDilationAmount(g_envDilationRooms, roomId);
    super(amount);
    g_dilationAmount = 0;
}

HOOK_METHOD(ShipManager, CheckSpreadDamage, () -> void)
{
    for (auto i : ship.vRoomList)
    {
        if (RM_EX(i)->timeDilation != 0)
        {
            g_envDilationRooms[i->iRoomId] = RM_EX(i)->timeDilation;
        }
    }

    g_inSpreadDamage = true;
    super();
    g_inSpreadDamage = false;

    g_envDilationRooms.clear();
}

HOOK_METHOD_PRIORITY(ShipManager, UpdateEnvironment, -900, () -> void)
{
    for (auto i : ship.vRoomList)
    {
        if (RM_EX(i)->timeDilation != 0)
        {
            g_envDilationRooms[i->iRoomId] = RM_EX(i)->timeDilation;
        }
    }

    super();

    g_envDilationRooms.clear();
}

HOOK_METHOD_PRIORITY(ShipManager, OnLoop, -900,  () -> void)
{
    for (auto i : ship.vRoomList)
    {
        if (RM_EX(i)->timeDilation != 0)
        {
            g_cloneDilationRooms[i->iRoomId] = RM_EX(i)->timeDilation;
        }
    }

    super();

    g_cloneDilationRooms.clear();

    for (auto i : ship.vRoomList)
    {
        auto ex = RM_EX(i);
        int timeDilation = ex->timeDilation;

        if (timeDilation > 0)
        {
            if (ex->speedUpAnim)
            {
                ex->speedUpAnim->Update();
            }
        }
        else if (timeDilation < 0)
        {
            if (ex->slowDownAnim)
            {
                ex->slowDownAnim->Update();
            }
        }
    }
}
