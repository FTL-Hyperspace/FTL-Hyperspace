#include "Global.h"

// ScoreKeeper is one of the first things loaded
// Save and load the next space id to avoid collisions

HOOK_METHOD(ScoreKeeper, LoadGame, (int fh) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ScoreKeeper::LoadGame -> Begin (SpaceId.cpp)\n")
    super(fh);

    *Globals_GetNextSpaceId_id = FileHelper::readInteger(fh);
}

HOOK_METHOD(ScoreKeeper, SaveGame, (int fh) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ScoreKeeper::SaveGame -> Begin (SpaceId.cpp)\n")
    super(fh);

    FileHelper::writeInt(fh, *Globals_GetNextSpaceId_id);
}

// need to reset when opening the hangar
HOOK_METHOD(ShipBuilder, Open, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipBuilder::Open -> Begin (SpaceId.cpp)\n")
    *Globals_GetNextSpaceId_id = 100;
    super();
}
