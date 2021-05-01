#include "Global.h"

class TestSystem : public ShipSystem
{
public:
    TestSystem(int systemId, int roomId, int shipId, int startingPower) : ShipSystem(systemId, roomId, shipId, startingPower)
    {

    }
};
