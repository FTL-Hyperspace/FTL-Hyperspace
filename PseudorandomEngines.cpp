#include "Global.h"
#include <cmath>


static double PFromC(double c)
{
    double pProcOnN = 0;
    double pProcByN = 0;
    double sumNpProcOnN = 0;

    int maxFails = (int)std::ceil(1/c);
    for (int N = 1; N <= maxFails; ++N)
    {
        pProcOnN = std::min(1., N*c) * (1 - pProcByN);
        pProcByN += pProcOnN;
        sumNpProcOnN += N * pProcOnN;
    }

    return (1/sumNpProcOnN);
}

static double CFromP(int p)
{
    double Cupper = p;
    double Clower = 0;
    double Cmid;
    double p1;
    double p2 = 1;
    while(true)
    {
        Cmid = (Cupper + Clower) / 2;
        p1 = PFromC(Cmid);
        if ( std::abs(p1 - p2) <= 0) break;

        if (p1 > p)
        {
            Cupper = Cmid;
        }
        else
        {
            Clower = Cmid;
        }
        p2 = p1;
    }
    return Cmid;
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
