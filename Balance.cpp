#include "Global.h"
#include <limits>

bool g_hackingDroneFix = true;
bool g_repairDroneRecoveryFix = true;
bool g_controllableIonDroneFix = false;
float g_controllableIonDroneFix_Delay = 6.0;

// hacking drone explodes on depower -- makes you unable to get past defense drones by powering + depowering

HOOK_METHOD(HackingSystem, OnLoop, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> HackingSystem::OnLoop -> Begin (Balance.cpp)\n")
    super();

    if (g_hackingDroneFix)
    {
        if (!this->drone.arrived && !this->Powered())
        {
            this->BlowHackingDrone();
        }
    }
}

// Jumping away while a repair drone is active with a repair arm will collect the drone part -- this removes it before the collection

HOOK_METHOD(DroneSystem, Jump, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> DroneSystem::Jump -> Begin (Balance.cpp)\n")

    if (g_repairDroneRecoveryFix)
    {
        for (auto drone : drones)
        {
            // type == 5 are SHIP_REPAIR
            if (drone->deployed && drone->type == 5)
            {
                drone->SetDestroyed(true, false);
                drone->deployed = false;
            }
        }
    }
    super();
}

HOOK_METHOD(IonDrone, constructor, (int iShipId, DroneBlueprint *blueprint) -> void)
{
    LOG_HOOK("HOOK_METHOD -> IonDrone::constructor -> Begin (Balance.cpp)\n")
    super(iShipId, blueprint);
    
    if (g_controllableIonDroneFix && iShipId == 0)
    {
        auto ex = CMA_EX(crewAnim);
        ex->ionTimer = TimerHelper(true);
        ex->ionTimer.ResetMinMax(g_controllableIonDroneFix_Delay*1000, g_controllableIonDroneFix_Delay*1000);
        ex->ionTimer.loop = true;
        ex->ionTimer.Start(-1);
    }
}

HOOK_METHOD(CrewDrone, OnLoop, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewDrone::OnLoop -> Begin (Balance.cpp)\n")
    super();

    if (g_controllableIonDroneFix && iShipId == 0)
    {
        auto ex = CMA_EX(crewAnim);
        if (ex->isIonDrone)
        {
            IonDroneAnimation* ionAnim = (IonDroneAnimation*)crewAnim;
            if (!ionAnim->ionAnimation.tracker.running)
            {   // Increment timer while not triggering
                ex->ionTimer.Update();
            }
            if (std::abs(x - goal_x) > 0.01 || std::abs(y - goal_y) > 0.01)
            {   // Reset glow progress if ordered to move
                ionAnim->ionEffect = 0.0;
            }
            if (!Functional())
            {   // Reset timer fully if turned off
                ex->ionTimer.currTime = 0;
                ionAnim->ionAnimation.tracker.running = false;
                ionAnim->ionEffect = 0.0;
            }
        }
    }
}

HOOK_METHOD(IonDroneAnimation, UpdateShooting, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> IonDroneAnimation::UpdateShooting -> Begin (Balance.cpp)\n")

    CrewAnimation_Extend* ex;
    if (g_controllableIonDroneFix && (ex = CMA_EX(this), ex->crew->iShipId == 0))
    {
        if (!bDoorTarget && ex->ionTimer.Done())
        {
            ionAnimation.Start(true);
            ionEffect = 0.0;
            G_->GetSoundControl()->PlaySoundMix("ionBoarderCharge", -1.f, false);
        }

        float ionEffectCurrent = ionEffect;
        bool ionAnimRunningCurrent = ionAnimation.tracker.running;

        shootTimer.running = false;
        super();

        // Undo the secondary trigger that happens at the end of the function
        if (status != 7 || bDoorTarget)
        {
            ionEffect = ionEffectCurrent;
            ionAnimation.tracker.running = ionAnimRunningCurrent;
        }

        return;
    }

    super();
}

/*
HOOK_METHOD(DefenseDrone, PickTarget, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> DefenseDrone::PickTarget -> Begin (Balance.cpp)\n")
    if (bDisrupted && powered)
    {
        if (aimingAngle == desiredAimingAngle)
        {
            desiredAimingAngle = rand() % 360;
        }
        //UpdateAimingAngle(currentLocation, )
    }
    else if (powered)
    {
        Pointf diff = Pointf(targetLocation.x - currentLocation.x, targetLocation.y - currentLocation.y);
        float projSpeed = weaponBlueprint->speed;
        float aimAhead = Globals::AimAhead(diff, targetSpeed, projSpeed * G_->GetCFPS()->GetSpeedFactor());

        if (aimAhead > 0.f)
        {
            targetLocation = Pointf(aimAhead * targetSpeed.x + targetLocation.x, aimAhead * targetSpeed.y + targetLocation.y);
        }

        if (targetLocation == currentLocation)
        {
            desiredAimingAngle = aimingAngle;
        }
        else
        {

        }
    }
}*/
