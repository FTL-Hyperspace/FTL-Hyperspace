#include "Global.h"
#include "LuaCommon.h"

LUA_LIBFUNC(world, GetPlayerShip)
{
    if (G_->GetWorld()->playerShip)
    {
        Push_ShipManager(G_->GetWorld()->playerShip->shipManager);
    }
    else
    {
        return 0;
    }

    return 1;
}
