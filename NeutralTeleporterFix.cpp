#include "Global.h"

HOOK_METHOD(ShipAI, GetTeleportCommand, () -> double)
{
    if (!ship->_targetable.hostile && iTeleportRequest != -1)
    {
        auto oldTarget = target;
        target = nullptr;
        double ret = super();
        target = oldTarget;
        return ret;
    }

    return super();
}
