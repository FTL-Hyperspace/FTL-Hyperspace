#include "Global.h"

// ScoreKeeper is one of the first things loaded
// Save and load the next space id to avoid collisions

#ifndef __APPLE__
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

#else

static int spaceId = 100;
int Globals::GetNextSpaceId(void)
{
    if (spaceId == 0)
    {
        spaceId = 100;
    }
    spaceId++;
}

void Globals::SetNextSpaceId(int id)
{
    spaceId = id;
}

// Replace original function with mine
HOOK_STATIC(Globals, GetNextSpaceId_orig, () -> int)
{
    LOG_HOOK("HOOK_STATIC -> Globals::GetNextSpaceId_orig -> Begin (Misc.cpp)\n")
    
    return GetNextSpaceId();
}

// I don't know what matchamp did here but I just copied it and adjusted it to my GetNextSpaceId fix
HOOK_METHOD(ScoreKeeper, LoadGame, (int fh) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ScoreKeeper::LoadGame -> Begin (SpaceId.cpp)\n")
    super(fh);

    Globals::SetNextSpaceId(FileHelper::readInteger(fh));
}

HOOK_METHOD(ScoreKeeper, SaveGame, (int fh) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ScoreKeeper::SaveGame -> Begin (SpaceId.cpp)\n")
    super(fh);

    FileHelper::writeInt(fh, Globals::GetNextSpaceId());
}

// need to reset when opening the hangar
HOOK_METHOD(ShipBuilder, Open, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipBuilder::Open -> Begin (SpaceId.cpp)\n")
    Globals::SetNextSpaceId(100);
    super();
}
#endif
