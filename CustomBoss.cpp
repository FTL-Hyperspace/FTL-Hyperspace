#include "Global.h"

static bool isStartingStage = false;

HOOK_METHOD(BossShip, StartStage, () -> void)
{
    isStartingStage = true;

    super();

    isStartingStage = false;
}

HOOK_METHOD(ShipManager, AddCrewMemberFromString, (const std::string& name, const std::string& race, bool intruder, int roomId, bool init, bool male) -> CrewMember*)
{
    if (!isStartingStage)
    {
        return super(name, race, intruder, roomId, init, male);
    }
}

