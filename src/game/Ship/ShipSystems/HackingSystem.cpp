#include "CustomOptions.h"
#include "Global.h"

static bool FreeHackingFix()
{
    return CustomOptionsManager::GetInstance()->freeHackingFix.currentValue;
}

static bool TargetHackWithoutDrones()
{
    return CustomOptionsManager::GetInstance()->targetHackWithoutDrones.currentValue;
}

HOOK_METHOD(HackBox, KeyDown, (SDLKey key, bool shift) -> void)
{
    LOG_HOOK("HOOK_METHOD -> HackBox::KeyDown -> Begin (HackingSystem.cpp)\n")
    if (TargetHackWithoutDrones())
    {
        shipManager->ModifyDroneCount(1); // pretend we have 1 more dronepart
        super(key, shift);
        shipManager->ModifyDroneCount(-1);
    }
    else
    {
        super(key, shift);
    }
}

HOOK_METHOD(HackBox, OnLoop, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> HackBox::OnLoop -> Begin (HackingSystem.cpp)\n")
    flashTracker.Update();
    SystemBox::OnLoop();
    bool canHack;
    if (!TargetHackWithoutDrones() && shipManager->GetDroneCount() < 1)
    {
        canHack = false;
    }
    else
    {
        canHack = hackSys->CanHack();
    }
    hackButton.SetActive(canHack);
}

HOOK_METHOD(HackingSystem, GetSpendDrone, () -> int)
{
    LOG_HOOK("HOOK_METHOD -> HackingSystem::GetSpendDrone -> Begin (HackingSystem.cpp)\n")
    if (spendDrone != 0)
    {
        ShipManager *shipManager = G_->GetShipManager(_shipObj.iShipId);
        if (!FreeHackingFix() || shipManager->GetDroneCount() >= spendDrone)
        {
            shipManager->ModifyDroneCount(-spendDrone);
        }
        else
        {
            BlowHackingDrone();
        }
        spendDrone = 0;
    }
    return 0; // just do everything above instead of in ShipManager::OnLoop
}

HOOK_METHOD(HackingSystem, SoundLoop, () -> bool)
{
    LOG_HOOK("HOOK_METHOD -> HackingSystem::SoundLoop -> Begin (HackingSystem.cpp)\n")
    return drone.arrived && bHacking && iLockCount == -1;
}
