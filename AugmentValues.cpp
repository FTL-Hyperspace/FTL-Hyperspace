#include "Global.h"


HOOK_METHOD_PRIORITY(ProjectileFactory, SpendMissiles, 1000, () -> int)
{
    int ret = iSpendMissile;

    if (iSpendMissile > 0)
    {
        if (HasEquipment("EXPLOSIVE_REPLICATOR"))
        {
            int rng = 0;
            if (G_->GetRNG())
            {
                rng = rand();
            }
            else
            {
                rng = random32();
            }

            rng %= 100;

            int chance = std::floor(this->GetAugmentationValue("EXPLOSIVE_REPLICATOR") * 100);

            if (rng < chance)
            {
                ret = 0;
                G_->GetEventSystem()->AddEvent(12);
            }
        }
    }

    iSpendMissile = 0;
    return ret;
}
