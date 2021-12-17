#include "Global.h"


HOOK_METHOD(ShipManager, AddWeapon, (const WeaponBlueprint *bp, int slot) -> ProjectileFactory*)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::AddWeapon -> Begin (BeamFixes.cpp)\n")
    auto ret = super(bp, slot);

    if (current_target && HasSystem(3))
    {
        for (auto i : weaponSystem->weapons)
        {
            i->currentShipTarget = &current_target->_targetable;
        }
    }

    return ret;
}
