#include "Global.h"

static bool isStartingStage = false;
/*
HOOK_METHOD(BossShip, StartStage, () -> void)
{
    isStartingStage = true;

    super();

    isStartingStage = false;
}

HOOK_METHOD(ShipManager, AddCrewMemberFromString, (const std::string& race, bool unk1, int room, bool unk2, bool unk3) -> CrewMember*)
{
    if (!isStartingStage)
    {
        return super(race, unk1, room, unk2, unk3);
    }
}

*/
