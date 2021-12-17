#include "Global.h"
#include <limits>

bool g_hackingDroneFix = true;

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
