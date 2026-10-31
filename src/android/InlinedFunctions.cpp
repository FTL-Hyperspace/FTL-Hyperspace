#include "Global.h"
#include "Systems.h"
#include <cmath>

std::vector<ProjectileFactory*> ShipManager::GetWeaponList()
{
    if (systemKey[SYS_WEAPONS] == -1) return std::vector<ProjectileFactory*>();
    return weaponSystem->weapons;
}

std::vector<Drone*> ShipManager::GetDroneList()
{
    if (systemKey[SYS_DRONES] == -1) return std::vector<Drone*>();
    return droneSystem->drones;
}

bool CrewMember::Sabotaging()
{
    return currentRepair && currentRepair->CanBeSabatoged() && CanSabotage();
}

bool CrewMember::AtGoal()
{
    if (std::fabs(x - goal_x) >= 0.5f || std::fabs(y - goal_y) >= 0.5f) return false;
    x = goal_x;
    y = goal_y;
    return true;
}

Point CrewMember::GetFinalGoal()
{
    if (path.distance == -1.f) return Point(-1, -1);
    return path.finish;
}

std::string CrewMember::GetLongName()
{
    return blueprint.crewNameLong.GetText();
}

std::string CombatControl::GetCrewTooltip(int x, int y)
{
    if (!currentTarget) return "";
    return currentTarget->shipManager->GetTooltip(x, y);
}

void ShipManager::RemoveCrewmember(CrewMember *crew)
{
    for (CrewMember *member : vCrewList)
    {
        if (member != crew) continue;
        crew->EmptySlot();
        crew->Kill(false);
        crew->SetCurrentShip(-1);
        G_->GetCrewFactory()->OnLoop();
        return;
    }
}

void freetype::easy_printAutoShrink(int fontId, float x, float y, int maxWidth, bool centered, const std::string& text)
{
    int smallest = -1;
    if ((fontId & ~1) == 0x34) smallest = 0x33;
    else if ((unsigned)(fontId - 0x3e) < 3) smallest = 0x3d;
    if (smallest != -1)
    {
        float height = easy_measurePrintLines(fontId, 0.f, 0.f, maxWidth + 999, text).y;
        while (fontId > smallest + 1 && easy_measurePrintLines(fontId, 0.f, 0.f, maxWidth + 999, text).x > maxWidth)
        {
            fontId--;
        }
        y += std::roundf((height - easy_measurePrintLines(fontId, 0.f, 0.f, maxWidth + 999, text).y) / 2.f);
    }
    if (centered) easy_printCenter(fontId, x, y, text);
    else easy_print(fontId, x, y, text);
}

void sys_graphics_set_window_title(char *title)
{
}
