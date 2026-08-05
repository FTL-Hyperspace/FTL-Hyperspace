#include "Infinite.h"
#include "Global.h"

bool g_infiniteMode = false;
bool loadingInfinite = false;
int loadWorldLevel = 0;

unsigned int infiniteSectorMapSeed;

HOOK_METHOD(StarMap, GenerateSectorMap, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> StarMap::GenerateSectorMap -> Begin (Infinite.cpp)\n")
    if (g_infiniteMode)
    {
        this->bInfiniteMode = true;
    }

    super();
    infiniteSectorMapSeed = random32();

    if (loadingInfinite)
    {
        Sector dummySector = *currentSector;
        currentSector = &dummySector;

        for (dummySector.level=3; dummySector.level<=loadWorldLevel; ++dummySector.level)
        {
            PushSectorColumn();
        }

        currentSector = sectors[0];
    }
}

HOOK_METHOD(StarMap, PushSectorColumn, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> StarMap::PushSectorColumn -> Begin (Infinite.cpp)\n")
    srandom32(infiniteSectorMapSeed);
    super();
    infiniteSectorMapSeed = random32();
}

HOOK_METHOD(StarMap, LoadGame, (int fh) -> Location*)
{
    LOG_HOOK("HOOK_METHOD -> StarMap::LoadGame -> Begin (Infinite.cpp)\n")
    loadWorldLevel = FileHelper::readInteger(fh);

    if (g_infiniteMode) loadingInfinite = true;

    auto ret = super(fh);

    loadingInfinite = false;

    return ret;
}

HOOK_METHOD(StarMap, SaveGame, (int file) -> void)
{
    LOG_HOOK("HOOK_METHOD -> StarMap::SaveGame -> Begin (Infinite.cpp)\n")
    FileHelper::writeInt(file, worldLevel);

    super(file);
}

// Fixes sectors clipping out of sector box

HOOK_METHOD(ResourceControl, RenderImageString, (std::string& tex, int x, int y, int rotation, GL_Color color, float opacity, bool mirror) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ResourceControl::RenderImageString -> Begin (Infinite.cpp)\n")
    if (tex == "map/sector_box.png" && g_infiniteMode)
    {
        tex.assign("map/sector_box_infinite.png");
        x = 268;
    }

    return super(tex, x, y, rotation, color, opacity, mirror);
}

// Fixes exiting secret sector

bool infiniteMapClick = false;
bool infiniteSectorEight = false;
bool infiniteLeavingSecretSector = false;

HOOK_METHOD(StarMap, MouseClick, (int unk0, int unk1) -> void)
{
    LOG_HOOK("HOOK_METHOD -> StarMap::MouseClick -> Begin (Infinite.cpp)\n")
    if (!(bInfiniteMode && bSecretSector && !bChoosingNewSector && endButton.bActive && endButton.bHover)) return super(unk0,unk1);

    infiniteMapClick = true;
    if (worldLevel == 7)
    {
        worldLevel = 6;
        infiniteSectorEight = true;
    }

    super(unk0,unk1);

    if (infiniteSectorEight)
    {
        worldLevel = 7;
        infiniteSectorEight = false;
    }

    infiniteMapClick = false;
}

HOOK_METHOD(StarMap, OnTouch, (TouchAction unk0, int unk1, int unk2, int unk3, int unk4, int unk5) -> void)
{
    LOG_HOOK("HOOK_METHOD -> StarMap::OnTouch -> Begin (Infinite.cpp)\n")
    if (!(bInfiniteMode && bSecretSector && !bChoosingNewSector && endButton.bActivated)) return super(unk0, unk1, unk2, unk3, unk4, unk5);

    infiniteMapClick = true;
    if (worldLevel == 7)
    {
        worldLevel = 6;
        infiniteSectorEight = true;
    }

    super(unk0, unk1, unk2, unk3, unk4, unk5);

    if (infiniteSectorEight)
    {
        worldLevel = 7;
        infiniteSectorEight = false;
    }

    infiniteMapClick = false;
}

HOOK_METHOD(StarMap, AdvanceWorldLevel, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> StarMap::AdvanceWorldLevel -> Begin (Infinite.cpp)\n")
    if (infiniteMapClick) infiniteLeavingSecretSector = true;
    if (infiniteSectorEight)
    {
        worldLevel = 7;
        infiniteSectorEight = false;
    }
    super();
}

HOOK_METHOD(StarMap, UpdateSectorMap, (Sector *unk0) -> void)
{
    LOG_HOOK("HOOK_METHOD -> StarMap::UpdateSectorMap -> Begin (Infinite.cpp)\n")
    if (infiniteLeavingSecretSector)
    {
        infiniteLeavingSecretSector = false;
        if (currentSector->level > 2) PushSectorColumn();
    }
    super(unk0);
}
