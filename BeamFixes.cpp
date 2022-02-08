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

HOOK_METHOD(WeaponSystem, OnLoop, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> WeaponSystem::OnLoop -> Begin (BeamFixes.cpp)\n")
    ShipManager *ship = G_->GetShipManager(_shipObj.iShipId);
    if (ship)
    {
        Targetable *target = ship->current_target ? &ship->current_target->_targetable : nullptr;
        for (auto i : weapons)
        {
            if (i->currentShipTarget && i->currentShipTarget != target)
            {
                hs_log_file("Weapon had incorrect target %x, changing to ship target %x\n", i->currentShipTarget, target);
                i->currentShipTarget = target;
            }
        }
    }

    super();
}
