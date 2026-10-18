// Game functions FTL for iPad has no copy of: its compiler inlined them everywhere the
// game uses them. Hyperspace calls them, so these follow what the Mac build's copies do,
// written against Hyperspace's structs (which have the iPad layout). The ones short enough
// to sit in the headers are in the struct blocks of the iPad .zhl files.

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

// Within half a pixel of the goal counts as there, and snaps the crew member onto it
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

// Prints the text with the font given or, for the fonts that come in steps (0x34/0x35 and
// 0x3e to 0x40), a smaller one of the same kind when the text is wider than maxWidth
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
        // Keep the smaller text centred on the same line
        y += std::roundf((height - easy_measurePrintLines(fontId, 0.f, 0.f, maxWidth + 999, text).y) / 2.f);
    }
    if (centered) easy_printCenter(fontId, x, y, text);
    else easy_print(fontId, x, y, text);
}

// SIL's window title, which Multiverse sets from Lua. A phone has no window title to set.
void sys_graphics_set_window_title(char *title)
{
}
