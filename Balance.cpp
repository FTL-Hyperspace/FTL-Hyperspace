#include "Global.h"


// hacking drone explodes on depower -- makes you unable to get past defense drones by powering + depowering

HOOK_METHOD(HackingSystem, OnLoop, () -> void)
{

    super();

    if (!this->drone.arrived && !this->Powered())
    {
        this->BlowHackingDrone();
    }
}
