#pragma once
#include "FTLGame.h"

struct OverclockerSystem_Wrapper
{
    ShipSystem *orig = nullptr;
    bool bTurnedOn = false;
    TimerHelper timer;
    bool bArmed = false;
    ShipSystem *currentSystem = nullptr;

    bool IsReady()
    {
        return !bTurnedOn && !orig->GetLocked();
    }

    bool GetArmed()
    {
        return bArmed;
    }

    void SetArmed(bool armed)
    {
        bArmed = armed;
    }

    void StartOverclock(ShipSystem *sys);
    void StopOverclock();
    void OnLoop();

    OverclockerSystem_Wrapper(ShipSystem *sys) : orig(sys)
    {

    }
};

struct ShipSystem_Extend
{
public:
    ShipSystem *orig = nullptr;

    int additionalPowerLoss;
    int oldPowerLoss;

    int iOverclockEffect = 0;

    OverclockerSystem_Wrapper *overclockerSystem = nullptr;

private:
};

ShipSystem_Extend* Get_ShipSystem_Extend(ShipSystem* c);

#define SYS_EX Get_ShipSystem_Extend
