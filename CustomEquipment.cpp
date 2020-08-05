#include "Global.h"

HOOK_METHOD(InfoBox, SetBlueprintWeapon, (const WeaponBlueprint* bp, int status, bool hasWeaponSystem, int yShift) -> void)
{
    if (hasWeaponSystem && status == 1)
    {
        return super(bp, 2, hasWeaponSystem, yShift);
    }

    super(bp, 2, hasWeaponSystem, yShift);
}

HOOK_METHOD(InfoBox, SetBlueprintDrone, (const DroneBlueprint* bp, int status, bool hasDroneSystem, int yShift) -> void)
{

    if (hasDroneSystem && status == 1)
    {
        return super(bp, 2, hasDroneSystem, yShift);
    }

    super(bp, 2, hasDroneSystem, yShift);
}
