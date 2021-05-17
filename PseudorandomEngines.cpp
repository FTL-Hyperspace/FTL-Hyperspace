#include "Global.h"

static float CFromP(float p)
{
    return 0.f;
}

static float PFromC(float c)
{
    return 0.f;
}

static float GetEngineProbability(int counter, float evasion)
{
    return 0.f;
}


HOOK_METHOD(ShipManager, GetDodged, () -> float)
{
    if (!_targetable.hostile || bJumping)
    {
        return false;
    }

    bool cloaked = systemKey[10] != -1 && cloakSystem->bTurnedOn;

    int dodgeFactor = GetDodgeFactor();

    if (cloaked) dodgeFactor += 60;

    int rngDodgeFactor = std::floor(GetEngineProbability() * 1000);
    int rng = random32() % 100000;

    if (rng < rngDodgeFactor)
    {
        failedDodgeCounter = 0;

        if (!cloaked)
        {
            if (current_target || iIntruderCount > 0)
            {
                G_->GetEventSystem()->AddEvent(7);
            }
        }

        return true;
    }
    else
    {
        failedDodgeCounter++;

        if (iShipId == 0 && systemKey[1] != -1 && GetSystem(1)->GetEffectivePower() >= 8)
        {
            if (failedDodgeCounter >= 5)
            {
                G_->GetAchievementTracker()->SetAchievement("ACH_BAD_DODGING", false, true);
            }
        }

        return false;
    }
}
