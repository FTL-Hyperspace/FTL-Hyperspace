#include "CustomSystems.h"

/*
HOOK_STATIC(ShipSystem, NameToSystemId, (std::string& name) -> int)
{

    if (name == "test")
    {
        return 100;
    }

    return super(name);
}

HOOK_METHOD(ShipManager, CreateSystems, () -> int)
{
    for (auto const &x: this->systemKey)
    {
        printf("%d\n", x);
    }
    return super();
}

HOOK_METHOD(ShipSystem, constructor, (int systemId, int roomId, int shipId, int power) -> void)
{


    return super(systemId, roomId, shipId, power);
}
*/
