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


