#include "CustomDamage.h"












/*
HOOK_METHOD(ShipManager, DamageArea, (Pointf location,  int iDamage, int iShieldPiercing, int fireChance, int breachChance, int stunChance, int iIonDamage, int iSystemDamage, int iPersDamage, int bHullBuster, int ownerId, int selfId, int bLockdown, int iStun, bool forceHit) -> bool)
{
    Damage* dmg = (Damage*)&iDamage;

    auto custom = CustomDamageManager::GetCustomDamage(dmg);

    if (customDamage)
    {
        printf("%08X\n", custom);

        if (custom->timeDilation != 0)
        {
            int roomId = ship.GetSelectedRoomId(location.x, location.y, true);

            if (roomId != -1)
            {
                RM_EX(ship.vRoomList[roomId])->timeDilation = custom->timeDilation;
            }
        }
    }

    return super(location, iDamage, iShieldPiercing, fireChance, breachChance, stunChance, iIonDamage, iSystemDamage, iPersDamage, bHullBuster, ownerId, selfId, bLockdown, iStun, forceHit);
}
*/
