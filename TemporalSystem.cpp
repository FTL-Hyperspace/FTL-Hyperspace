#include "TemporalSystem.h"
#include "Room_Extend.h"
#include "boost/algorithm/string.hpp"
#include "boost/lexical_cast.hpp"
#include <sstream>
#include <iomanip>

std::map<int, TemporalSystemParser::TemporalLevel> TemporalSystemParser::levelSpeed = std::map<int, TemporalSystemParser::TemporalLevel>();
std::map<int, TemporalSystemParser::TemporalLevel> TemporalSystemParser::levelSlow = std::map<int, TemporalSystemParser::TemporalLevel>();

TemporalSystemParser::TemporalLevel ParseTemporalLevel(rapidxml::xml_node<char>* node)
{
    TemporalSystemParser::TemporalLevel def;

    for (auto child = node->first_node(); child; child = child->next_sibling())
    {
        std::string name = child->name();
        std::string val = child->value();

        if (name == "cooldown")
        {
            def.cooldown = boost::lexical_cast<int>(val);
        }
        if (name == "duration")
        {
            def.duration = boost::lexical_cast<int>(val);
        }
        if (name == "strength")
        {
            def.strength = boost::lexical_cast<float>(val);
        }
    }

    return def;
}

void TemporalSystemParser::ParseSystemNode(rapidxml::xml_node<char>* node)
{
    for (auto child = node->first_node(); child; child = child->next_sibling())
    {
        std::string name = child->name();

        for (auto subChild = child->first_node(); subChild; subChild = subChild->next_sibling())
        {
            if (boost::algorithm::starts_with(subChild->name(), "level"))
            {
                std::string levelStr = std::string(subChild->name()).substr(5);
                int level = boost::lexical_cast<int>(levelStr);

                auto temporalLevel = ParseTemporalLevel(subChild);

                if (name == "speed")
                {
                    levelSpeed[level] = temporalLevel;
                }
                if (name == "slow")
                {
                    levelSlow[level] = temporalLevel;
                }
            }
        }
    }
}

int TemporalSystemParser::GetDilationDuration(int level)
{
    auto chosenMap = level > 0 ? levelSpeed : levelSlow;
    auto absLevel = std::abs(level);

    if (chosenMap.find(absLevel) != chosenMap.end())
    {
        return chosenMap[absLevel].duration;
    }
    else
    {
        return 10;
    }
}

float TemporalSystemParser::GetDilationStrength(int level)
{
    auto chosenMap = level > 0 ? levelSpeed : levelSlow;
    auto absLevel = std::abs(level);

    if (chosenMap.find(absLevel) != chosenMap.end())
    {
        return chosenMap[absLevel].strength;
    }
    else
    {
        return std::pow(2, level);
    }
}

int TemporalSystemParser::GetDilationCooldown(int level)
{
    auto chosenMap = level > 0 ? levelSpeed : levelSlow;
    auto absLevel = std::abs(level);

    if (chosenMap.find(absLevel) != chosenMap.end())
    {
        return chosenMap[absLevel].cooldown;
    }
    else
    {
        return 2;
    }
}


static TemporalArmState g_iTemporal = TEMPORAL_ARM_NONE;

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
            std::string hotkey = Settings::GetHotkeyName("temporal_speed");
            std::string tooltip = G_->GetTextLibrary()->GetText("temporal_button_speed");
            boost::algorithm::replace_all(tooltip, "\\1", hotkey);
            boost::algorithm::replace_all(tooltip, "\\n", "\n");

            G_->GetMouseControl()->SetTooltip(tooltip);
        }
        if (slowDownButton->bActive && slowDownButton->bHover)
        {
            // tooltip
            std::string hotkey = Settings::GetHotkeyName("temporal_slow");
            std::string tooltip = G_->GetTextLibrary()->GetText("temporal_button_slow");
            boost::algorithm::replace_all(tooltip, "\\1", hotkey);
            boost::algorithm::replace_all(tooltip, "\\n", "\n");

            G_->GetMouseControl()->SetTooltip(tooltip);
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

void TemporalBox::OnKeyDown(SDLKey key, bool shift)
{
    if (!pSystem->GetLocked())
    {
        if (Settings::GetHotkey("temporal_speed") == key || Settings::GetHotkey("temporal_slow") == key)
        {
            bool speed = key == Settings::GetHotkey("temporal_speed");

            if (speed)
            {
                if (speedUpButton->bActive)
                {
                    temporalSystem->SetArmed(TEMPORAL_ARM_SPEED);
                }
            }
            else
            {
                if (slowDownButton->bActive)
                {
                    temporalSystem->SetArmed(TEMPORAL_ARM_SLOW);
                }
            }
        }
    }
}

void TemporalSystem_Wrapper::StartTimeDilation(int shipId, int roomId, bool speedUp)
{
    queuedShipId = -1;
    queuedRoomId = -1;

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

                    isSpeeding = speedUp;
                    dilationStrength = orig->GetEffectivePower();

                    orig->LockSystem(-1);

                    timer.Start(TemporalSystemParser::GetDilationDuration(GetRealDilation()));

                    currentRoom = room;
                    currentShipId = shipId;

                    auto rm_ex = RM_EX(room);
                    if (rm_ex->timeDilation != 0 && (speedUp ? (rm_ex->timeDilation < 0) : (rm_ex->timeDilation > 0)))
                    {
                        rm_ex->timeDilationSource = nullptr;
                        rm_ex->timeDilation = 0;
                        StopTimeDilation(); // temporal counter
                    }
                    else
                    {
                        rm_ex->timeDilationSource = this;
                        rm_ex->timeDilation = GetRealDilation();
                    }
                }
            }
        }
    }
}

void TemporalSystem_Wrapper::StopTimeDilation()
{
    if (bTurnedOn)
    {
        if (currentRoom)
        {
            auto rm_ex = RM_EX(currentRoom);
            if (rm_ex->timeDilationSource == this)
            {
                rm_ex->timeDilationSource = nullptr;
                rm_ex->timeDilation = 0;
            }
        }

        orig->AddLock(TemporalSystemParser::GetDilationCooldown(GetRealDilation()));
        bTurnedOn = false;
        currentRoom = nullptr;
        currentShipId = -1;
        dilationStrength = 0;
    }
}


void TemporalSystem_Wrapper::OnLoop()
{
    if (queuedShipId != -1 && queuedRoomId != -1)
    {
        StartTimeDilation(queuedShipId, queuedRoomId, queuedSpeedUp);
    }

    if (!orig->Functioning() || (orig->iHackEffect > 1 && orig->bUnderAttack) || currentShipId == -1 || G_->GetShipManager(currentShipId) == nullptr)
    {
        StopTimeDilation();
    }

    if (bTurnedOn)
    {
        dilationStrength = orig->GetEffectivePower();

        timer.SetMaxTime(TemporalSystemParser::GetDilationDuration(GetRealDilation()));
        timer.Update();

        if (currentRoom != nullptr && G_->GetShipManager(currentShipId) != nullptr)
        {
            auto rm_ex = RM_EX(currentRoom);
            if (rm_ex->timeDilationSource != this)
            {
                StopTimeDilation(); // cancel if overwritten
            }
            else
            {
                rm_ex->timeDilation = GetRealDilation();
            }
        }

        if (timer.Done())
        {
            StopTimeDilation();
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
    LOG_HOOK("HOOK_METHOD -> ShipManager::JumpArrive -> Begin (TemporalSystem.cpp)\n")
    if (bWasSafe && HasSystem(20))
    {
        GetSystem(20)->LockSystem(0);
    }

    super();

}

HOOK_METHOD(ShipManager, JumpLeave, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::JumpLeave -> Begin (TemporalSystem.cpp)\n")
    super();

    for (auto room : ship.vRoomList)
    {
        auto ex = RM_EX(room);
        if (ex->timeDilationSource)
        {
            ex->timeDilation = 0;
            ex->timeDilationSource = nullptr;
        }
    }
}

HOOK_METHOD(CombatControl, SelectTarget, () -> bool)
{
    LOG_HOOK("HOOK_METHOD -> CombatControl::SelectTarget -> Begin (TemporalSystem.cpp)\n")
    auto temporalArmed = GetTemporalArmed(shipManager);
    if (temporalArmed != TEMPORAL_ARM_NONE)
    {
        auto temporal = SYS_EX(shipManager->GetSystem(20))->temporalSystem;

        if (selectedSelfRoom != -1)
        {
            temporal->queuedShipId = 0;
            temporal->queuedRoomId = selectedSelfRoom;
            temporal->queuedSpeedUp = temporalArmed == TEMPORAL_ARM_SPEED;

            SetTemporalArmed(shipManager, TEMPORAL_ARM_NONE);
            selectedSelfRoom = -1;
            shipManager->ship.SetSelectedRoom(-1);
            return true;
        }
        else if (selectedRoom != -1 && currentTarget)
        {
            if (currentTarget && (currentTarget->shipManager->GetShieldPower().super.first <= 0 || shipManager->HasAugmentation("ZOLTAN_BYPASS")))
            {
                temporal->queuedShipId = 1;
                temporal->queuedRoomId = selectedRoom;
                temporal->queuedSpeedUp = temporalArmed == TEMPORAL_ARM_SPEED;
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
    LOG_HOOK("HOOK_METHOD -> CombatControl::WeaponsArmed -> Begin (TemporalSystem.cpp)\n")
    bool ret = super();

    return ret | (GetTemporalArmed(shipManager) != TEMPORAL_ARM_NONE);
}

static std::string RemoveTrailingZeros(std::string str)
{
    boost::trim_right_if(str, boost::is_any_of("0"));
    boost::trim_right_if(str, boost::is_any_of("."));

    return str;
}

static void ReplaceTemporalText(std::string& tooltipText, int power)
{
    std::stringstream stream;
    std::string valueStr;

    int counter = 0;


    for (int i = 0; i < 2; i++)
    {
        int realDilation = i == 0 ? power : -power;

        counter++;

        stream << std::fixed << std::setprecision(3) << TemporalSystemParser::GetDilationStrength(realDilation);
        valueStr = RemoveTrailingZeros(stream.str());
        boost::algorithm::replace_all(tooltipText, "\\" + std::to_string(counter), valueStr);
        stream.str(std::string());

        counter++;

        stream << TemporalSystemParser::GetDilationCooldown(realDilation) * 5;
        valueStr = stream.str();
        boost::algorithm::replace_all(tooltipText, "\\" + std::to_string(counter), valueStr);
        stream.str(std::string());

        counter++;

        stream << TemporalSystemParser::GetDilationDuration(realDilation);
        valueStr = stream.str();
        boost::algorithm::replace_all(tooltipText, "\\" + std::to_string(counter), valueStr);
        stream.str(std::string());
    }
}

HOOK_METHOD(CombatControl, UpdateTarget, () -> bool)
{
    LOG_HOOK("HOOK_METHOD -> CombatControl::UpdateTarget -> Begin (TemporalSystem.cpp)\n")
    bool ret = super();

    if (GetTemporalArmed(shipManager))
    {
        shipManager->ship.SetSelectedRoom(selectedSelfRoom);
        if (currentTarget)
        {
            currentTarget->shipManager->ship.SetSelectedRoom(selectedRoom);
        }

        if (selectedRoom != -1 || selectedSelfRoom != -1)
        {
            std::string tooltipText = "";
            if (selectedRoom != -1 && currentTarget && (currentTarget->shipManager->GetShieldPower().super.first > 0 && !shipManager->HasAugmentation("ZOLTAN_BYPASS")))
            {
                G_->GetMouseControl()->SetTooltip(G_->GetTextLibrary()->GetText("temporal_arm_super_shields"));
                G_->GetMouseControl()->InstantTooltip();
            }
            else if (GetTemporalArmed(shipManager) == TEMPORAL_ARM_SPEED)
            {
                tooltipText = G_->GetTextLibrary()->GetText("temporal_arm_speed");
            }
            else
            {
                tooltipText = G_->GetTextLibrary()->GetText("temporal_arm_slow");
            }

            if (!tooltipText.empty())
            {
                int power = shipManager->GetSystem(20)->GetEffectivePower();

                ReplaceTemporalText(tooltipText, power);

                G_->GetMouseControl()->SetTooltip(tooltipText);
                G_->GetMouseControl()->InstantTooltip();
            }
        }

        return true;
    }

    return ret;
}

CachedImage *temporalTarget_speed = nullptr;
CachedImage *temporalTarget_slow = nullptr;

HOOK_METHOD(CombatControl, constructor, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CombatControl::constructor -> Begin (TemporalSystem.cpp)\n")
    super();

    temporalTarget_speed = new CachedImage("misc/temporal_placed_speed.png", 0, 0);
    temporalTarget_slow = new CachedImage("misc/temporal_placed_slow.png", 0, 0);
}


HOOK_METHOD(ShipManager, RenderChargeBars, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::RenderChargeBars -> Begin (TemporalSystem.cpp)\n")
    super();
    auto& combatControl = G_->GetCApp()->gui->combatControl;
    auto playerShip = combatControl.shipManager;

    if (playerShip->HasSystem(SYS_TEMPORAL))
    {
        auto sys = SYS_EX(playerShip->GetSystem(SYS_TEMPORAL))->temporalSystem;

        if (sys->queuedShipId == 1 && sys->queuedRoomId != -1)
        {
            CachedImage *img = nullptr;

            if (sys->queuedSpeedUp)
            {
                img = temporalTarget_speed;
            }
            else
            {
                img = temporalTarget_slow;
            }

            if (img != nullptr)
            {
                auto pos = combatControl.currentTarget->shipManager->GetRoomCenter(sys->queuedRoomId);
                img->SetPosition(pos.x - 20, pos.y - 20);

                img->OnRender(COLOR_WHITE);
            }
        }
    }
}

HOOK_METHOD(CombatControl, OnRenderSelfAiming, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CombatControl::OnRenderSelfAiming -> Begin (TemporalSystem.cpp)\n")
    super();

    if (shipManager->HasSystem(SYS_TEMPORAL))
    {
        auto sys = SYS_EX(shipManager->GetSystem(SYS_TEMPORAL))->temporalSystem;

        if (sys->queuedShipId == 0 && sys->queuedRoomId != -1)
        {
            CachedImage *img = nullptr;

            if (sys->queuedSpeedUp)
            {
                img = temporalTarget_speed;
            }
            else
            {
                img = temporalTarget_slow;
            }

            if (img != nullptr)
            {
                auto pos = shipManager->GetRoomCenter(sys->queuedRoomId);
                img->SetPosition(pos.x - 20, pos.y - 20);

                img->OnRender(COLOR_WHITE);
            }
        }
    }
}

HOOK_METHOD(CombatControl, OnRenderCombat, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CombatControl::OnRenderCombat -> Begin (TemporalSystem.cpp)\n")
    super();
    if (open)
    {
        if (GetTemporalArmed(shipManager) != TEMPORAL_ARM_NONE && !weapControl.armedWeapon)
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
    LOG_HOOK("HOOK_METHOD -> CombatControl::DisarmAll -> Begin (TemporalSystem.cpp)\n")
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
    LOG_HOOK("HOOK_METHOD -> CombatControl::MouseRClick -> Begin (TemporalSystem.cpp)\n")
    bool temporalArmed = GetTemporalArmed(shipManager);

    bool ret = super(x, y);

    return ret | (temporalArmed != TEMPORAL_ARM_NONE);
}

static bool g_inMouseRender = false;

HOOK_METHOD(ResourceControl, GetImageId, (const std::string& name) -> GL_Texture*)
{
    LOG_HOOK("HOOK_METHOD -> ResourceControl::GetImageId -> Begin (TemporalSystem.cpp)\n")
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
    LOG_HOOK("HOOK_METHOD -> MouseControl::OnRender -> Begin (TemporalSystem.cpp)\n")
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

// AI

void TemporalSystem_Wrapper::AISelectTarget(CombatAI *ai)
{
    struct TemporalAI
    {
        int roomId;
        int shipId;
        bool speedUp;
    };

    struct RoomCounts
    {
        int crew = 0;
        int intruders = 0;
        int effectiveCrew = 0;
        int effectiveIntruders = 0;
        int mindCrew = 0;
        int mindIntruders = 0;
        int repairing = 0;
        int sabotaging = 0;
        int crewFighting = 0;
        int intrudersFighting = 0;
        int hurtCrew = 0;
    };

    struct TemporalTargetList
    {
        std::vector<TemporalAI> targets = {};
        int priority = 0;

        void AddTarget(Room* room, int roomId, int shipId, bool speedUp, int newPriority)
        {
            if (newPriority < priority) return;
            if (speedUp ? (RM_EX(room)->timeDilation > 0) : (RM_EX(room)->timeDilation < 0)) return;
            if (newPriority > priority)
            {
                priority = newPriority;
                targets.clear();
            }
            targets.push_back({roomId, shipId, speedUp});
        }

        bool empty()
        {
            return targets.empty();
        }

        TemporalAI& Select()
        {
            return targets[random32()%targets.size()];
        }
    };

    TemporalTargetList targetList;

    std::vector<RoomCounts> roomCounts;

    {
        roomCounts.reserve(ai->self->ship.vRoomList.size());
        roomCounts.resize(ai->self->ship.vRoomList.size());

        for (auto crew : ai->self->vCrewList)
        {
            if (!crew->IsDead() && !crew->OutOfGame() && crew->Functional() && crew->iRoomId >= 0 && crew->crewAnim->status != 6)
            {
                if (crew->intruder)
                {
                    roomCounts[crew->iRoomId].intruders += 1;
                    if (crew->bMindControlled) roomCounts[crew->iRoomId].mindIntruders += 1;
                    if (crew->bFighting || crew->Sabotaging()) roomCounts[crew->iRoomId].intrudersFighting += 1;
                    if (crew->fStunTime <= 0.f) roomCounts[crew->iRoomId].effectiveIntruders += 1;
                    if (crew->Sabotaging()) roomCounts[crew->iRoomId].sabotaging += 1;
                }
                else
                {
                    roomCounts[crew->iRoomId].crew += 1;
                    if (crew->bMindControlled) roomCounts[crew->iRoomId].mindCrew += 1;
                    if (crew->bFighting) roomCounts[crew->iRoomId].crewFighting += 1;
                    if (crew->fStunTime <= 0.f) roomCounts[crew->iRoomId].effectiveCrew += 1;
                    if (crew->Repairing()) roomCounts[crew->iRoomId].repairing += 1;
                    if (crew->health.second - crew->health.first >= 10.f) roomCounts[crew->iRoomId].hurtCrew += 1;
                }
            }
        }

        bool blastDoors = false;
        auto doors = ai->self->GetSystem(SYS_DOORS);
        if (doors && doors->GetEffectivePower() >= 2)
        {
            blastDoors = true;
        }

        for (auto room : ai->self->ship.vRoomList)
        {
            //targetList.AddTarget(room->iRoomId, ai->self->iShipId, false, 0);
            //targetList.AddTarget(room->iRoomId, ai->self->iShipId, true, 0);

            int fireCount = ai->self->GetFireCount(room->iRoomId);

            auto sys = ai->self->GetSystemInRoom(room->iRoomId);
            if (sys != nullptr)
            {
                if (sys->iSystemType == SYS_MEDBAY)
                {
                    if (fireCount < roomCounts[room->iRoomId].repairing) // don't speed up burning room
                    {
                        if (sys->Functioning() && sys->iHackEffect < 2 && roomCounts[room->iRoomId].hurtCrew > 0 && roomCounts[room->iRoomId].crew * sys->GetEffectivePower() > roomCounts[room->iRoomId].intruders)
                        {
                            targetList.AddTarget(room, room->iRoomId, ai->self->iShipId, true, 2); // speed up healing
                            continue;
                        }
                    }
                    if (sys->iHackEffect > 1 && roomCounts[room->iRoomId].crew > 0 && roomCounts[room->iRoomId].intrudersFighting > 0)
                    {
                        targetList.AddTarget(room, room->iRoomId, ai->self->iShipId, false, 2); // slow down medbay hack death if there are also intruders
                        continue;
                    }
                }
                else if (sys->iSystemType == SYS_CLONEBAY)
                {
                    if (fireCount < roomCounts[room->iRoomId].repairing) // don't speed up burning room
                    {
                        // cloning crew and not overwhelmed
                        if (sys->Functioning() && sys->iHackEffect < 2 && G_->GetCrewFactory()->CountCloneReadyCrew(ai->self->iShipId == 0) > 0 && roomCounts[room->iRoomId].effectiveCrew >= roomCounts[room->iRoomId].effectiveIntruders)
                        {
                            targetList.AddTarget(room, room->iRoomId, ai->self->iShipId, true, 2); // speed up cloning
                            continue;
                        }
                    }
                }

                if (roomCounts[room->iRoomId].intrudersFighting > roomCounts[room->iRoomId].effectiveCrew)
                {
                    targetList.AddTarget(room, room->iRoomId, ai->self->iShipId, true, 2); // slow down intruders
                }
                else if (roomCounts[room->iRoomId].repairing && roomCounts[room->iRoomId].repairing > fireCount)
                {
                    targetList.AddTarget(room, room->iRoomId, ai->self->iShipId, true, // speed up repairs, higher priority with damage/fire than breach
                                         (sys->bOnFire || sys->healthState.first < sys->healthState.second) ? 2 : 1);
                }
                else if (fireCount > 1 && fireCount > roomCounts[room->iRoomId].repairing && !sys->CompletelyDestroyed())
                {
                    targetList.AddTarget(room, room->iRoomId, ai->self->iShipId, false, 2); // slow down fire damage
                }
                else if (targetList.priority > 1)
                {
                    continue;
                }
                else if (roomCounts[room->iRoomId].mindIntruders > 0)
                {
                    targetList.AddTarget(room, room->iRoomId, ai->self->iShipId, false, 1); // slow down mind controlled crew
                }
                else if (ai->self->bAutomated && sys->fRepairOverTime > 0.f && !sys->bBreached && !sys->bOnFire)
                {
                    targetList.AddTarget(room, room->iRoomId, ai->self->iShipId, true, 1); // speed up autorepair
                }
            }
            else if (blastDoors) // empty room
            {
                if (roomCounts[room->iRoomId].intrudersFighting - roomCounts[room->iRoomId].mindIntruders >= 2)
                {
                    targetList.AddTarget(room, room->iRoomId, ai->self->iShipId, false, 1); // slow down enemy crew in empty room
                }
            }
        }
    }

    if (ai->target)
    {
        if (ai->target->GetShieldPower().super.first <= 0 || ai->self->HasAugmentation("ZOLTAN_BYPASS"))
        {
            roomCounts.clear();
            roomCounts.reserve(ai->target->ship.vRoomList.size());
            roomCounts.resize(ai->target->ship.vRoomList.size());

            for (auto crew : ai->target->vCrewList)
            {
                if (!crew->IsDead() && !crew->OutOfGame() && crew->Functional() && crew->iRoomId >= 0 && crew->crewAnim->status != 6)
                {
                    if (crew->intruder)
                    {
                        roomCounts[crew->iRoomId].intruders += 1;
                        if (crew->bMindControlled) roomCounts[crew->iRoomId].mindIntruders += 1;
                        if (crew->bFighting || crew->Sabotaging()) roomCounts[crew->iRoomId].intrudersFighting += 1;
                        if (crew->fStunTime <= 0.f) roomCounts[crew->iRoomId].effectiveIntruders += 1;
                        if (crew->Sabotaging()) roomCounts[crew->iRoomId].sabotaging += 1;
                    }
                    else
                    {
                        roomCounts[crew->iRoomId].crew += 1;
                        if (crew->bMindControlled) roomCounts[crew->iRoomId].mindCrew += 1;
                        if (crew->bFighting) roomCounts[crew->iRoomId].crewFighting += 1;
                        if (crew->fStunTime <= 0.f) roomCounts[crew->iRoomId].effectiveCrew += 1;
                        if (crew->Repairing()) roomCounts[crew->iRoomId].repairing += 1;
                    }
                }
            }

            bool blastDoors = false;
            auto doors = ai->target->GetSystem(SYS_DOORS);
            if (doors && doors->GetEffectivePower() >= 2)
            {
                blastDoors = true;
            }

            for (auto room : ai->target->ship.vRoomList)
            {
                //targetList.AddTarget(room->iRoomId, ai->target->iShipId, false, 0);
                //targetList.AddTarget(room->iRoomId, ai->target->iShipId, true, 0);

                int fireCount = ai->target->GetFireCount(room->iRoomId);

                auto sys = ai->target->GetSystemInRoom(room->iRoomId);
                if (sys != nullptr)
                {
                    if (sys->iSystemType == SYS_MEDBAY)
                    {
                        if (fireCount < roomCounts[room->iRoomId].effectiveCrew) // don't slow down burning room
                        {
                            if (sys->Functioning() && sys->iHackEffect < 2 && roomCounts[room->iRoomId].hurtCrew > 0 && roomCounts[room->iRoomId].crew * sys->GetEffectivePower() > roomCounts[room->iRoomId].intruders)
                            {
                                targetList.AddTarget(room, room->iRoomId, ai->target->iShipId, false, 2); // slow down healing
                                continue;
                            }
                        }
                        if (sys->iHackEffect > 1 && roomCounts[room->iRoomId].crew > 0)
                        {
                            targetList.AddTarget(room, room->iRoomId, ai->target->iShipId, true,
                                                 (roomCounts[room->iRoomId].intrudersFighting > 0 || roomCounts[room->iRoomId].crew > 1) ? 2 : 1); // speed up medbay hack death
                            continue;
                        }
                    }
                    else if (sys->iSystemType == SYS_CLONEBAY)
                    {
                        if (G_->GetCrewFactory()->CountCloneReadyCrew(ai->target->iShipId == 0) > 0) // cloning crew
                        {
                            if (fireCount < roomCounts[room->iRoomId].crew) // don't slow down burning room
                            {
                                // system functional; not overwhelmed
                                if (sys->Functioning() && sys->iHackEffect < 2 && roomCounts[room->iRoomId].effectiveCrew >= roomCounts[room->iRoomId].effectiveIntruders)
                                {
                                    targetList.AddTarget(room, room->iRoomId, ai->target->iShipId, false, 2); // slow down cloning
                                    continue;
                                }
                                else if (!ai->target->HasAugmentation("BACKUP_DNA"))
                                {
                                    // system broken or ioned, not about to be repaired or unlocked
                                    if (!sys->Functioning() &&
                                        ((sys->CompletelyDestroyed() && (roomCounts[room->iRoomId].intruders > 0 || sys->bOnFire || sys->bBreached || sys->fRepairOverTime < 50.f)) ||
                                         (sys->iLockCount>1 || sys->iLockCount==1 && sys->lockTimer.currTime < 2.5f)))
                                    {
                                        targetList.AddTarget(room, room->iRoomId, ai->target->iShipId, true, 2); // speed up clonebay death
                                        continue;
                                    }
                                    else if (sys->iHackEffect > 1 && ai->self->hackingSystem != nullptr &&
                                             ai->self->hackingSystem->effectTimer.second - ai->self->hackingSystem->effectTimer.first > 2.5f)
                                    {
                                        targetList.AddTarget(room, room->iRoomId, ai->target->iShipId, true, 2); // speed up clonebay death
                                        continue;
                                    }
                                }
                            }
                        }
                    }
                    if (roomCounts[room->iRoomId].intrudersFighting > roomCounts[room->iRoomId].effectiveCrew &&
                        (sys->iSystemType != SYS_MEDBAY || roomCounts[room->iRoomId].crew == 0 || sys->iHackEffect > 1 ||
                         (sys->CompletelyDestroyed() && (roomCounts[room->iRoomId].intruders > 0 || sys->bOnFire || sys->bBreached || sys->fRepairOverTime < 50.f)) ||
                         (sys->iLockCount>1 || sys->iLockCount==1 && sys->lockTimer.currTime < 2.5f)))
                    {
                        // extra conditions to prevent medbay power bait; don't speed up enemy medbays unless they're disabled or empty
                        targetList.AddTarget(room, room->iRoomId, ai->target->iShipId, true, 2); // speed up intruders
                    }
                    else if (roomCounts[room->iRoomId].repairing && roomCounts[room->iRoomId].repairing > fireCount)
                    {
                        targetList.AddTarget(room, room->iRoomId, ai->target->iShipId, false, // slow down repairs, higher priority with damage/fire than breach
                                             (sys->bOnFire || sys->healthState.first < sys->healthState.second) ? 2 : 1);
                    }
                    else if (room->lastO2 > 10.f && (fireCount > 2 ||
                                                     (fireCount > roomCounts[room->iRoomId].effectiveCrew) ||
                                                     (fireCount > 0 && roomCounts[room->iRoomId].intruders > 0))
                             && !sys->CompletelyDestroyed())
                    {
                        if (fireCount > 2 || (fireCount == 2 && roomCounts[room->iRoomId].effectiveCrew == 0) || (fireCount == 1 && roomCounts[room->iRoomId].intruders > 0))
                        {
                            targetList.AddTarget(room, room->iRoomId, ai->target->iShipId, true, 2); // speed up fires, 3+ fires or 2+ fires unattended or fire + boarders; o2 must be present
                        }
                        else
                        {
                            targetList.AddTarget(room, room->iRoomId, ai->target->iShipId, true, 1); // one fewer fire = less priority
                        }
                    }
                    else if (targetList.priority > 1)
                    {
                        continue;
                    }
                    else if (roomCounts[room->iRoomId].mindIntruders > 0 && roomCounts[room->iRoomId].intrudersFighting > 0)
                    {
                        targetList.AddTarget(room, room->iRoomId, ai->target->iShipId, true, 1); // speed up mind controlled crew; must be someone fighting
                    }
                    else if (ai->target->bAutomated && sys->fRepairOverTime > 0.f && !sys->bBreached && !sys->bOnFire)
                    {
                        targetList.AddTarget(room, room->iRoomId, ai->target->iShipId, false, 1); // slow down autorepair
                    }
                }
                else if (blastDoors) // empty room
                {
                    if (roomCounts[room->iRoomId].intrudersFighting - roomCounts[room->iRoomId].mindIntruders >= 2)
                    {
                        targetList.AddTarget(room, room->iRoomId, ai->target->iShipId, true, 1); // speed up boarders in room
                    }
                }
            }
        }
    }

    if (!targetList.empty())
    {
        TemporalAI selectedAction = targetList.Select();

        queuedRoomId = selectedAction.roomId;
        queuedShipId = selectedAction.shipId;
        queuedSpeedUp = selectedAction.speedUp;
    }
}

HOOK_METHOD(CombatAI, OnLoop, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CombatAI::OnLoop -> Begin (TemporalSystem.cpp)\n")
    super();
    if (self->HasSystem(20))
    {
        auto sys = self->GetSystem(20);
        auto temporal = SYS_EX(sys)->temporalSystem;
        if (temporal->IsReady())
        {
            temporal->AISelectTarget(this);
        }
    }
}

// Level Tooltip

HOOK_STATIC(ShipSystem, GetLevelDescription, (int systemId, int level, bool tooltip) -> std::string)
{
    LOG_HOOK("HOOK_STATIC -> ShipSystem::GetLevelDescription -> Begin (TemporalSystem.cpp)\n")
    std::string ret = super(systemId, level, tooltip);

    if (systemId == 20 && level != -1)
    {
        int realLevel = level + 1;

        std::string replStr = G_->GetTextLibrary()->GetText(tooltip ? "temporal_tooltip" : "temporal");

        ReplaceTemporalText(replStr, realLevel);
        boost::algorithm::replace_all(replStr, "\\n", "\n");

        ret.assign(replStr);
    }
    return ret;
}

// Animation

HOOK_METHOD(Ship, OnRenderWalls, (bool forceView, bool doorControlMode) -> void)
{
    LOG_HOOK("HOOK_METHOD -> Ship::OnRenderWalls -> Begin (TemporalSystem.cpp)\n")
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
                    ex->speedUpAnim = new Animation(G_->GetAnimationControl()->GetAnimation("room_temporal_speed"));
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
                    ex->slowDownAnim = new Animation(G_->GetAnimationControl()->GetAnimation("room_temporal_slow"));
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

            CSurface::GL_PopMatrix();
        }
    }

    super(forceView, doorControlMode);
}

// AI

HOOK_METHOD(CrewAI, PrioritizeTask, (CrewTask task, int crewId) -> int)
{
    LOG_HOOK("HOOK_METHOD -> CrewAI::PrioritizeTask -> Begin (TemporalSystem.cpp)\n")
    if (task.system == 20) task.system = 15;
    return super(task, crewId);
}

// Effects

static int g_dilationAmount = 0;
static float g_dilationExtraMul = 1.0;

HOOK_METHOD(CFPS, GetSpeedFactor, () -> float)
{
    LOG_HOOK("HOOK_METHOD -> CFPS::GetSpeedFactor -> Begin (TemporalSystem.cpp)\n")
    float ret = super();

    if (g_dilationAmount != 0)
    {
        ret *= TemporalSystemParser::GetDilationStrength(g_dilationAmount) * g_dilationExtraMul;
    }

    return ret;
}

static std::map<int, int> g_crewDilationRooms = std::map<int, int>();
static std::map<int, int> g_envDilationRooms = std::map<int, int>();
static std::map<int, int> g_sysDilationRooms = std::map<int, int>();
static std::map<int, int> g_shardDilationRooms = std::map<int, int>();

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
    LOG_HOOK("HOOK_METHOD -> OxygenSystem::ModifyRoomOxygen -> Begin (TemporalSystem.cpp)\n")
    int dilationAmount = GetRoomDilationAmount(g_envDilationRooms, changeRoomId);
    super(changeRoomId, amount * (float)TemporalSystemParser::GetDilationStrength(dilationAmount));
}

HOOK_METHOD(OxygenSystem, ComputeAirLoss, (int changeRoomId, float amount, bool unk) -> void)
{
    LOG_HOOK("HOOK_METHOD -> OxygenSystem::ComputeAirLoss -> Begin (TemporalSystem.cpp)\n")
    int dilationAmount = GetRoomDilationAmount(g_envDilationRooms, changeRoomId);
    super(changeRoomId, amount * (float)TemporalSystemParser::GetDilationStrength(dilationAmount), unk);
}

HOOK_METHOD(Fire, OnLoop, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> Fire::OnLoop -> Begin (TemporalSystem.cpp)\n")
    g_dilationAmount = GetRoomDilationAmount(g_envDilationRooms, roomId);
    super();
    g_dilationAmount = 0;
}

HOOK_METHOD(Fire, UpdateDeathTimer, (int connectedFires) -> void)
{
    LOG_HOOK("HOOK_METHOD -> Fire::UpdateDeathTimer -> Begin (TemporalSystem.cpp)\n")
    g_dilationAmount = GetRoomDilationAmount(g_envDilationRooms, roomId);
    super(connectedFires);
    g_dilationAmount = 0;
}

HOOK_METHOD(Fire, UpdateStartTimer, (int doorLevel) -> void)
{
    LOG_HOOK("HOOK_METHOD -> Fire::UpdateStartTimer -> Begin (TemporalSystem.cpp)\n")
    g_dilationAmount = GetRoomDilationAmount(g_envDilationRooms, roomId);
    super(doorLevel);
    g_dilationAmount = 0;
}


HOOK_METHOD(CrewAnimation, OnUpdate, (Pointf position, bool moving, bool fighting, bool repairing, bool dying, bool onFire) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewAnimation::OnUpdate -> Begin (TemporalSystem.cpp)\n")
    if (g_dilationAmount > 0)
    {
        float dilationMul = TemporalSystemParser::GetDilationStrength(g_dilationAmount);

        g_dilationExtraMul = 1.0 / std::ceil(dilationMul);

        for (int i = 0; i < std::ceil(dilationMul); i++)
        {
            super(position, moving, fighting, repairing, dying, onFire);
        }

        g_dilationExtraMul = 1.0;

        return;
    }

    super(position, moving, fighting, repairing, dying, onFire);
}



HOOK_METHOD(CrewMember, OnLoop, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewMember::OnLoop -> Begin (TemporalSystem.cpp)\n")
    g_dilationAmount = GetRoomDilationAmount(g_crewDilationRooms, iRoomId);
    super();
    g_dilationAmount = 0;
}

HOOK_METHOD(CloneSystem, OnLoop, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CloneSystem::OnLoop -> Begin (TemporalSystem.cpp)\n")
    g_dilationAmount = GetRoomDilationAmount(g_sysDilationRooms, roomId);
    super();
    g_dilationAmount = 0;
}

static bool g_inUpdateHealth = false;
static bool g_inApplyDamage = false;
static bool g_inUpdateCrewMembers = false;

/*
HOOK_METHOD(CrewMember, DirectModifyHealth, (float healthMod) -> bool)
{
    LOG_HOOK("HOOK_METHOD -> CrewMember::DirectModifyHealth -> Begin (TemporalSystem.cpp)\n")
    if (g_inUpdateCrewMembers && !g_inUpdateHealth && !g_inApplyDamage)
    {
        int dilationAmount = GetRoomDilationAmount(g_crewDilationRooms, iRoomId);

        return super(healthMod * (float)TemporalSystemParser::GetDilationStrength(dilationAmount));
    }

    return super(healthMod);
}
*/

HOOK_METHOD(CrewMember, UpdateHealth, () -> bool)
{
    LOG_HOOK("HOOK_METHOD -> CrewMember::UpdateHealth -> Begin (TemporalSystem.cpp)\n")
    g_inUpdateHealth = true;
    auto ret = super();
    g_inUpdateHealth = false;
    return ret;
}

HOOK_METHOD(CrewMember, ApplyDamage, (float damage) -> bool)
{
    LOG_HOOK("HOOK_METHOD -> CrewMember::ApplyDamage -> Begin (TemporalSystem.cpp)\n")
    g_inApplyDamage = true;
    auto ret = super(damage);
    g_inApplyDamage = false;
    return ret;
}

HOOK_METHOD_PRIORITY(ShipManager, UpdateCrewMembers, -900, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> ShipManager::UpdateCrewMembers -> Begin (TemporalSystem.cpp)\n")
    for (auto i : ship.vRoomList)
    {
        if (RM_EX(i)->timeDilation != 0)
        {
            g_crewDilationRooms[i->iRoomId] = RM_EX(i)->timeDilation;
        }
    }

    g_inUpdateCrewMembers = true;
    super();
    g_inUpdateCrewMembers = false;

    g_crewDilationRooms.clear();
}

static bool g_inSpreadDamage = false;

HOOK_METHOD(ShipSystem, DamageOverTime, (float amount) -> bool)
{
    LOG_HOOK("HOOK_METHOD -> ShipSystem::DamageOverTime -> Begin (TemporalSystem.cpp)\n")
    if (!g_inSpreadDamage) return super(amount);

    g_dilationAmount = GetRoomDilationAmount(g_envDilationRooms, roomId);
    auto ret = super(amount);
    g_dilationAmount = 0;
    return ret;
}

HOOK_METHOD(ShipManager, CheckSpreadDamage, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::CheckSpreadDamage -> Begin (TemporalSystem.cpp)\n")
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
    LOG_HOOK("HOOK_METHOD_PRIORITY -> ShipManager::UpdateEnvironment -> Begin (TemporalSystem.cpp)\n")
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

HOOK_METHOD(ShipSystem, PartialRepair, (float speed, bool autoRepair) -> bool)
{
    LOG_HOOK("HOOK_METHOD -> ShipSystem::PartialRepair -> Begin (TemporalSystem.cpp)\n")
    if (autoRepair)
    {
        g_dilationAmount = GetRoomDilationAmount(g_sysDilationRooms, roomId);

        bool ret = super(speed, autoRepair);

        g_dilationAmount = 0;

        return ret;
    }

    return super(speed, autoRepair);
}

HOOK_METHOD(LockdownShard, Update, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> LockdownShard::Update -> Begin (TemporalSystem.cpp)\n")
    g_dilationAmount = GetRoomDilationAmount(g_shardDilationRooms, lockingRoom);

    super();

    g_dilationAmount = 0;
}

HOOK_METHOD(Door, OnLoop, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> Door::OnLoop -> Begin (TemporalSystem.cpp)\n")
    if (lockedDown.running &&
        ((iRoom1 != -1 && GetRoomDilationAmount(g_shardDilationRooms, iRoom1) != 0) ||
         (iRoom2 != -1 && GetRoomDilationAmount(g_shardDilationRooms, iRoom2) != 0)))
    {
        ShipManager *shipManager = G_->GetShipManager(iShipId);
        if (shipManager)
        {
            float lockTime = 12.f;
            float speedFactor = 0.0625f * G_->GetCFPS()->GetSpeedFactor();
            Ship &ship = shipManager->ship;
            for (auto& shard : ship.lockdowns)
            {
                if (shard.lockingRoom == iRoom1 || shard.lockingRoom == iRoom2)
                {
                     lockTime = std::min(lockTime, shard.lifeTime + speedFactor * TemporalSystemParser::GetDilationStrength(GetRoomDilationAmount(g_shardDilationRooms, shard.lockingRoom)));
                }
            }
            if (lockTime == 12.f)
            {
                lockedDown.Start(lockTime);
                super(); // lockdown will expire in this call
            }
            else
            {
                lockedDown.current_time = 0.f; // don't expire in the super call
                super();
                lockedDown.current_time = lockTime;
            }
            return;
        }
    }
    super();
}

HOOK_METHOD_PRIORITY(ShipManager, OnLoop, -900,  () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> ShipManager::OnLoop -> Begin (TemporalSystem.cpp)\n")
    for (auto i : ship.vRoomList)
    {
        if (RM_EX(i)->timeDilation != 0)
        {
            g_sysDilationRooms[i->iRoomId] = RM_EX(i)->timeDilation;
            g_shardDilationRooms[i->iRoomId] = RM_EX(i)->timeDilation;
        }
    }

    super();

    g_sysDilationRooms.clear();
    g_shardDilationRooms.clear();

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

HOOK_METHOD(ShipManager, ExportShip, (int file) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::ExportShip -> Begin (TemporalSystem.cpp)\n")
    super(file);

    FileHelper::writeInt(file, HasSystem(20));

    if (HasSystem(20))
    {
        auto sys = GetSystem(20);

        FileHelper::writeInt(file, sys->powerState.second);
        FileHelper::writeInt(file, sys->powerState.first);
        FileHelper::writeInt(file, sys->healthState.second - sys->healthState.first);

        FileHelper::writeInt(file, sys->iLockCount);
        FileHelper::writeInt(file, std::floor(sys->lockTimer.currTime * 5000));
        FileHelper::writeInt(file, std::floor(sys->fRepairOverTime));
        FileHelper::writeInt(file, std::floor(sys->fDamageOverTime));
        FileHelper::writeInt(file, sys->iBatteryPower);
        FileHelper::writeInt(file, sys->bUnderAttack ? sys->iHackEffect : 0);
        FileHelper::writeInt(file, sys->iHackEffect > 0 ? sys->bUnderAttack : 0);
        sys->SaveState(file);
    }
}

HOOK_METHOD(ShipManager, ImportShip, (int file) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::ImportShip -> Begin (TemporalSystem.cpp)\n")
    super(file);

    bool hasTemporal = FileHelper::readInteger(file);

    if (hasTemporal)
    {
        if (!HasSystem(20)) AddSystem(20);
        auto sys = GetSystem(20);

        bool canDecrease = sys->DecreasePower(false);
        while (canDecrease)
        {
            canDecrease = sys->DecreasePower(false);
        }

        int maxPower = FileHelper::readInteger(file);
        while (sys->powerState.second < maxPower)
        {
            sys->UpgradeSystem(1);
        }

        sys->SetBonusPower(0, 0);

        int setPower = FileHelper::readInteger(file);

        while (sys->powerState.first != setPower)
        {
            if (!sys->IncreasePower(1, true)) break;
        }

        sys->AddDamage(FileHelper::readInteger(file));
        sys->AddLock(FileHelper::readInteger(file));
        sys->lockTimer.currTime = ((float)FileHelper::readInteger(file)) / 5000.f;

        sys->repairedLastFrame = true;
        sys->fRepairOverTime = FileHelper::readInteger(file);

        sys->damagedLastFrame = true;
        sys->fDamageOverTime = FileHelper::readInteger(file);

        sys->ForceBatteryPower(FileHelper::readInteger(file));
        sys->SetHackingLevel(FileHelper::readInteger(file));
        sys->bUnderAttack = FileHelper::readInteger(file);

        sys->LoadState(file);
    }
}

HOOK_METHOD(ShipManager, ExportBattleState, (int file) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::ExportBattleState -> Begin (TemporalSystem.cpp)\n")
    super(file);

    if (systemKey[20] != -1)
    {
        auto sys = SYS_EX(GetSystem(20))->temporalSystem;

        FileHelper::writeInt(file, sys->bTurnedOn);
        FileHelper::writeInt(file, sys->isSpeeding);
        FileHelper::writeInt(file, sys->timer.running);
        FileHelper::writeInt(file, std::floor(sys->timer.currGoal * 5000));
        FileHelper::writeInt(file, std::floor(sys->timer.currTime * 5000));
        FileHelper::writeInt(file, sys->currentShipId);
        FileHelper::writeInt(file, sys->dilationStrength);


        if (sys->currentRoom != nullptr)
        {
            FileHelper::writeInt(file, sys->currentRoom->iRoomId);
        }
        else
        {
            FileHelper::writeInt(file, -1);
        }
    }
}

HOOK_METHOD(ShipManager, ImportBattleState, (int file) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::ImportBattleState -> Begin (TemporalSystem.cpp)\n")
    super(file);

    if (systemKey[20] != -1)
    {
        auto sys = SYS_EX(GetSystem(20))->temporalSystem;

        sys->bTurnedOn = FileHelper::readInteger(file);
        sys->isSpeeding = FileHelper::readInteger(file);

        if (FileHelper::readInteger(file))
        {
            sys->timer.Start(-1);

        }
        sys->timer.SetMaxTime(((float)FileHelper::readInteger(file)) / 5000.f);
        sys->timer.currTime = ((float)FileHelper::readInteger(file)) / 5000.f;

        int shipId = FileHelper::readInteger(file);
        int strength = FileHelper::readInteger(file);
        int roomId = FileHelper::readInteger(file);

        sys->currentShipId = shipId;
        sys->dilationStrength = strength;


        if (roomId != -1 && shipId != -1)
        {
            if (shipId == iShipId)
            {
                auto rm_ex = RM_EX(ship.vRoomList[roomId]);
                rm_ex->timeDilation = sys->isSpeeding ? strength : -strength;
                sys->currentRoom = ship.vRoomList[roomId];
                rm_ex->timeDilationSource = sys;
            }
            else if (current_target)
            {
                auto rm_ex = RM_EX(current_target->ship.vRoomList[roomId]);
                rm_ex->timeDilation = sys->isSpeeding ? strength : -strength;;
                sys->currentRoom = current_target->ship.vRoomList[roomId];
                rm_ex->timeDilationSource = sys;
            }
        }
    }
}
