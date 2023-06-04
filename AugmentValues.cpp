#include "Global.h"

// Fixes value tag for EXPLOSIVE_REPLICATOR augment

HOOK_METHOD_PRIORITY(ProjectileFactory, SpendMissiles, 1000, () -> int)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> ProjectileFactory::SpendMissiles -> Begin (AugmentValues.cpp)\n")
    int ret = iSpendMissile;

    if (iSpendMissile > 0)
    {
        float augVal = GetAugmentationValue("EXPLOSIVE_REPLICATOR");
        if (augVal != 0.f)
        {
            int rng = 0;
            rng = random32();

            rng %= 100;

            int chance = std::floor(augVal * 100);

            if (rng < chance)
            {
                ret = 0;
                if (iShipId == 0) G_->GetEventSystem()->AddEvent(12);
            }
        }
    }

    iSpendMissile = 0;
    return ret;
}
