#include "Global.h"


HOOK_METHOD(ShipManager, UpdateCrewMembers, () -> void)
{
    for (auto i : vCrewList)
    {
        if (i->intruder && !i->bMindControlled)
        {
            if (HasAugmentation("NANOBOT_DEFENSE_SYSTEM"))
            {
                float augSpeed = GetAugmentationValue("NANOBOT_DEFENSE_SYSTEM") / 500.f;
                float speed = G_->GetCFPS()->GetSpeedFactor() * -augSpeed;
                i->DirectModifyHealth(speed);
            }
        }
    }
    super();
}

HOOK_METHOD(StarMap, MouseMove, (int x, int y) -> void)
{
    super(x, y);

    if (shipManager->HasAugmentation("FTL_JUMPER_GOOD"))
    {
        potentialLoc = hoverLoc;
    }
}
