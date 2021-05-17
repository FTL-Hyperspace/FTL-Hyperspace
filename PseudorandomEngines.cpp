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

static double CFromP(double p)
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

/*
static int factorial(int x)
{
    int product = 1;
    for (int i = 2; i <= x; i++) product *= i;
    return product;
}
*/

static double GetEngineProbability(int counter, int evasion)
{
    if (evasion == 0) return 0.0;

    double C = CFromP(std::min(evasion / 100.0, 1.0));
    /*
    double kFacC = factorial(counter) * C;

    double product = 1;
    for (int i = 1; i < counter; i++)
    {
        product *= ((1.0 / i) - C);
    }
    */

    return C * (counter + 1) * 100;
}

int hitCounter = 0;
int missCounter = 0;

HOOK_METHOD(ShipManager, GetDodged, () -> bool)
{
    if (!_targetable.hostile || bJumping)
    {
        return false;
    }

    bool cloaked = systemKey[10] != -1 && cloakSystem->bTurnedOn;

    int dodgeFactor = GetDodgeFactor();

    if (cloaked) dodgeFactor += 60;

    double engineProb = GetEngineProbability(failedDodgeCounter, dodgeFactor);
    printf("%f\n", engineProb);
    int rngDodgeFactor = std::floor(engineProb * 1000);
    int rng = random32() % 100000;

    printf("overall evasion percentage: %f\n", ((float)missCounter) / (missCounter + hitCounter));

    if (rng < rngDodgeFactor)
    {
        failedDodgeCounter = 0;
        SM_EX(this)->missCounter++;

        if (!cloaked)
        {
            if (current_target || iIntruderCount > 0)
            {
                G_->GetEventSystem()->AddEvent(7);
            }
        }

        printf("missed: %d\n", SM_EX(this)->missCounter);

        missCounter++;

        return true;
    }
    else
    {
        failedDodgeCounter++;
        SM_EX(this)->missCounter = 0;

        if (iShipId == 0 && systemKey[1] != -1 && GetSystem(1)->GetEffectivePower() >= 8)
        {
            if (failedDodgeCounter >= 5)
            {
                G_->GetAchievementTracker()->SetAchievement("ACH_BAD_DODGING", false, true);
            }
        }
        printf("hit: %d\n", SM_EX(this)->missCounter);

        hitCounter++;

        return false;
    }
}
