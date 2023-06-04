#include "Global.h"

HOOK_METHOD(ShipAI, GetTeleportCommand, () -> std::pair<int, int>)
{
    LOG_HOOK("HOOK_METHOD -> ShipAI::GetTeleportCommand -> Begin (NeutralTeleporterFix.cpp)\n")
    if (ship)
    {
        if (!ship->_targetable.hostile && iTeleportRequest != -1)
        {
            auto oldTarget = target;
            target = nullptr;
            std::pair<int, int> ret = super();
            target = oldTarget;
            return ret;
        }
    }

    return super();
}
