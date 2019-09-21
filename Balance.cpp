#include "Global.h"

bool g_hackingDroneFix = true;

// hacking drone explodes on depower -- makes you unable to get past defense drones by powering + depowering

HOOK_METHOD(HackingSystem, OnLoop, () -> void)
{
    super();

    if (g_hackingDroneFix)
    {
        if (!this->drone.arrived && !this->Powered())
        {
            this->BlowHackingDrone();
        }
    }

}
