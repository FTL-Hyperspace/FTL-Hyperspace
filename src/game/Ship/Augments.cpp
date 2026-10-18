#include "Global.h"
#include "CustomEvents.h"
#include <cstdio>
// NANOBOT_DEFENSE_SYSTEM Augment

HOOK_METHOD(ShipManager, UpdateCrewmembers, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::UpdateCrewmembers -> Begin (Augments.cpp)\n")
    for (auto i : vCrewList)
    {
        if (i->intruder && !i->bMindControlled && i->crewAnim->status != 6)
        {
            float augVal = GetAugmentationValue("NANOBOT_DEFENSE_SYSTEM");
            if (augVal != 0.f)
            {
                float augSpeed = augVal / 500.f;
                float speed = G_->GetCFPS()->GetSpeedFactor() * -augSpeed;
                i->DirectModifyHealth(speed);
            }
        }
    }
    super();
}




// FTL_JUMPER_GOOD Augment

static int fuelReq = 0;

HOOK_METHOD(StarMap, OnRender, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> StarMap::OnRender -> Begin (Augments.cpp)\n")
    super();

    if (!bChoosingNewSector && !outOfFuel)
    {
        if (shipManager->HasAugmentation("FTL_JUMPER_GOOD"))
        {
            if (fuelReq > 0)
            {
                char buf[32];

                snprintf(buf, 32, "-%d", fuelReq);

                if (fuelReq > shipManager->fuel_count)
                {
                    CSurface::GL_SetColor(GL_Color(253.f / 255.f, 84.f / 255.f, 70.f / 255.f, 1.f));
                }
                else
                {
                    CSurface::GL_SetColor(GL_Color(243.f / 255.f, 255.f / 255.f, 230.f / 255.f, 1.f));
                }

#ifdef HS_ANDROID
                // FTL for iPad's map covers the fuel counter; show the cost by the JUMP button
                freetype::easy_printCenter(0, position.x + jumpButton.position.x - 24, position.y + jumpButton.position.y + 10, buf);
#else
                freetype::easy_printCenter(0, 173, 83, buf);
#endif
            }
        }
    }
}

HOOK_METHOD(ShipManager, JumpLeave, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::JumpLeave -> Begin (Augments.cpp)\n")
    int oldFuelCount = fuel_count;

    super();

    if (HasAugmentation("FTL_JUMPER_GOOD") && fuelReq > 1)
    {
        fuel_count = oldFuelCount - fuelReq;
        fuelReq = 0;
    }
}

static void FtlJumperGood(StarMap *map)
{
    ShipManager *shipManager = map->shipManager;
    Location *currentLoc = map->currentLoc;
    Location *hoverLoc = map->hoverLoc;
    if (shipManager->HasAugmentation("FTL_JUMPER_GOOD"))
    {
        std::vector<Location*> vec = map->Dijkstra(currentLoc, hoverLoc, true);

        fuelReq = 0;

        if (std::floor(shipManager->GetAugmentationValue("FTL_JUMPER_GOOD")) == 0)
        {
            fuelReq = vec.size() - 1;
        }
        else if (vec.size() > 2)
        {
            fuelReq = std::floor(shipManager->GetAugmentationValue("FTL_JUMPER_GOOD"));
        }

        if (hoverLoc && hoverLoc->visited > 0 && shipManager->HasAugmentation("FTL_JUMPER"))
        {
            fuelReq = 1;
        }

        if (shipManager->fuel_count >= fuelReq && hoverLoc != currentLoc)
        {
            map->potentialLoc = hoverLoc;
        }
    }
}

HOOK_METHOD(StarMap, MouseMove, (int x, int y) -> void)
{
    LOG_HOOK("HOOK_METHOD -> StarMap::MouseMove -> Begin (Augments.cpp)\n")
    super(x, y);
    FtlJumperGood(this);
}

#ifdef HS_ANDROID
// FTL for iPad picks the beacon under a tap here (hoverLoc), and the jump target when it is
// next to this one; with FTL_JUMPER_GOOD it can be further, as with the mouse
HOOK_METHOD(StarMap, OnTouch, (TouchAction action, int id, int x, int y, int initialX, int initialY) -> void)
{
    LOG_HOOK("HOOK_METHOD -> StarMap::OnTouch -> Begin (Augments.cpp)\n")
    super(action, id, x, y, initialX, initialY);
    if (bOpen && !bChoosingNewSector && !outOfFuel && hoverLoc) FtlJumperGood(this);
}
#endif

//SECTOR_SCANNER Augment
static bool SectorReachable(Sector* start, Sector* destination, int range)
{
    if (range < 0) return false;
    if (start == destination) return true;
    for (Sector* neighbor : start->neighbors)
    {
        if (SectorReachable(neighbor, destination, range - 1))
        {
            return true;
        }
    }
    return false;
}

HOOK_METHOD(StarMap, GetPotentialSectorChoiceName, () -> std::string)
{
    LOG_HOOK("HOOK_METHOD -> StarMap::GetPotentialSectorChoiceName -> Begin (Augments.cpp)\n")
    if (potentialSectorChoice != -1 && shipManager->HasAugmentation("SECTOR_SCANNER") && sectors[potentialSectorChoice]->level - currentSector->level > 1)
    {
        int range = shipManager->GetAugmentationValue("SECTOR_SCANNER"); 
        Sector* destination  = sectors[potentialSectorChoice];
        if (SectorReachable(currentSector, destination, range))
        {
            return destination->description.name.GetText();
        }
    }
    return super();
}

//TELEPORT_RECALL augment
HOOK_METHOD(ShipManager, OnLoop, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::OnLoop -> Begin (Augments.cpp)\n")
    ShipManager* otherShip = G_->GetShipManager(1 - iShipId);
    if (ship.hullIntegrity.first <= 0 && otherShip && otherShip->HasAugmentation("TELEPORT_RECALL"))
    {
        int direction = iShipId == 0 ? -1 : 1;
        RecallBoarders(direction, false, true);
    }
    super();
}
HOOK_METHOD(ShipManager, JumpLeave, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::JumpLeave -> Begin (Augments.cpp)\n")
    if (iShipId == 1)
    {
        if (G_->GetShipManager(0)->HasAugmentation("TELEPORT_RECALL")) RecallBoarders(1, false, true);
        if (HasAugmentation("TELEPORT_RECALL")) RecallBoarders(-1, false, true);
    }
    else if (iShipId == 0)
    {
        ShipManager* enemyShip = G_->GetShipManager(1);
        if (enemyShip && enemyShip->HasAugmentation("TELEPORT_RECALL")) RecallBoarders(-1, false, true);
        if (HasAugmentation("TELEPORT_RECALL")) RecallBoarders(1, false, true);
    }
    super();
}

