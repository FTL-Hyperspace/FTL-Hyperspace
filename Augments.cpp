#include "Global.h"

// NANOBOT_DEFENSE_SYSTEM Augment

HOOK_METHOD(ShipManager, UpdateCrewMembers, () -> void)
{
    for (auto i : vCrewList)
    {
        if (i->intruder && !i->bMindControlled && i->crewAnim->status != 6)
        {
            if (HasAugmentation("NANOBOT_DEFENSE_SYSTEM"))
            {
                float augSpeed = GetAugmentationValue("NANOBOT_DEFENSE_SYSTEM") / 500.f;
                float speed = G_->GetCFPS()->GetSpeedFactor() * -augSpeed;
                i->DirectModifyHealth(speed);
            }
        }
    }
    if (HasAugmentation("AUTOSHIP"))
    {
        bAutomated = true;
    }
    else
    {
        bAutomated = false;
    }
    super();
}




// FTL_JUMPER_GOOD Augment

static int fuelReq = 0;

HOOK_METHOD(StarMap, OnRender, () -> void)
{
    super();

    if (!bChoosingNewSector && !outOfFuel)
    {
        if (shipManager->HasAugmentation("FTL_JUMPER_GOOD"))
        {
            if (fuelReq > 0)
            {
                char buf[32];

                sprintf(buf, "-%d", fuelReq);

                if (fuelReq > shipManager->fuel_count)
                {
                    CSurface::GL_SetColor(GL_Color(253.f / 255.f, 84.f / 255.f, 70.f / 255.f, 1.f));
                }
                else
                {
                    CSurface::GL_SetColor(GL_Color(243.f / 255.f, 255.f / 255.f, 230.f / 255.f, 1.f));
                }

                freetype::easy_printCenter(0, 173, 83, buf);
            }
        }
    }
}

HOOK_METHOD(ShipManager, JumpLeave, () -> void)
{
    int oldFuelCount = fuel_count;

    super();

    if (HasAugmentation("FTL_JUMPER_GOOD") && fuelReq > 1)
    {
        fuel_count = oldFuelCount - fuelReq;
    }
}

HOOK_METHOD(StarMap, MouseMove, (int x, int y) -> void)
{
    super(x, y);

    if (shipManager->HasAugmentation("FTL_JUMPER_GOOD"))
    {
        std::vector<Location*> vec = std::vector<Location*>();

        StarMap::Dijkstra0(vec, this, currentLoc, hoverLoc, true);

        fuelReq = 0;

        if (std::floor(shipManager->GetAugmentationValue("FTL_JUMPER_GOOD")) == 0)
        {
            fuelReq = vec.size() - 1;
        }
        else if (vec.size() > 2)
        {
            fuelReq = std::floor(shipManager->GetAugmentationValue("FTL_JUMPER_GOOD"));
        }

        if (shipManager->fuel_count >= fuelReq && hoverLoc != currentLoc)
        {
            potentialLoc = hoverLoc;
        }
    }
}
