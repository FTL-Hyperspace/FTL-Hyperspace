#pragma once
#include "FTLGame.h"

enum TemporalArmState
{
    TEMPORAL_ARM_NONE = 0,
    TEMPORAL_ARM_SPEED = 1,
    TEMPORAL_ARM_SLOW = 2
};

struct TemporalSystem_Wrapper
{
    ShipSystem *orig = nullptr;
    bool bTurnedOn = false;
    bool isSpeeding = false;
    TimerHelper timer;
    TemporalArmState armState = TEMPORAL_ARM_NONE;

    Room* currentRoom = nullptr;
    int currentShipId = -1;

    bool IsReady()
    {
        return !bTurnedOn && !orig->GetLocked() && orig->Functioning();
    }

    TemporalArmState GetArmed()
    {
        return armState;
    }

    void SetArmed(TemporalArmState newArmState)
    {
        armState = newArmState;
    }

    void StartTimeDilation(int shipId, int roomId, bool speedUp);
    void StopTimeDilation();
    void OnLoop();

    TemporalSystem_Wrapper(ShipSystem *sys) : orig(sys)
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

    TemporalSystem_Wrapper *temporalSystem = nullptr;

private:
};

ShipSystem_Extend* Get_ShipSystem_Extend(ShipSystem* c);

#define SYS_EX Get_ShipSystem_Extend
