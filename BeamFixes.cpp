#include "Global.h"


HOOK_METHOD(ShipManager, AddWeapon, (const WeaponBlueprint *bp, int slot) -> ProjectileFactory*)
{
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
    ShipManager *ship = G_->GetShipManager(_shipObj.iShipId);
    if (ship && ship->current_target)
    {
        Targetable *target = &ship->current_target->_targetable;
        for (auto i : weapons)
        {
            i->currentShipTarget = target;
        }
    }

    super();
}
