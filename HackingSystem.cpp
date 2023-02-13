#include "Global.h"

HOOK_METHOD(HackingSystem, SoundLoop, () -> bool)
{
    LOG_HOOK("HOOK_METHOD -> HackingSystem::SoundLoop -> Begin (HackingSystem.cpp)\n")
    return drone.arrived && bHacking && iLockCount == -1;
}
