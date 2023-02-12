#include "Global.h"

HOOK_METHOD(HackingSystem, SoundLoop, () -> bool)
{
    if (drone.arrived && bHacking && iLockCount == -1) // Original conditions
    {
        return true;
    }
    
    ShipManager* otherShip = G_->GetShipManager((_shipObj.iShipId + 1)%2);
    if (otherShip) for (auto system : otherShip->vSystemList) if (system->bUnderAttack && system->iHackEffect == 2)
    {
        return true;
    }
    
    return false;
}
