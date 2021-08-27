#include "CustomSectors.h"

std::unordered_map<int,std::vector<ReplacedSector>> replacedSectors = std::unordered_map<int,std::vector<ReplacedSector>>();

HOOK_METHOD(StarMap, NewGame, (bool unk) -> Location*)
{
    replacedSectors.clear();

    return super(unk);
}

HOOK_METHOD(StarMap, LoadGame, (int fh) -> Location*)
{
    replacedSectors.clear();
    int n_i = FileHelper::readInteger(fh);
    for (int i=0; i<n_i; ++i)
    {
        int when = FileHelper::readInteger(fh);
        int n_j = FileHelper::readInteger(fh);
        for (int j=0; j<n_j; ++j)
        {
            ReplacedSector sec;
            sec.sectorList = FileHelper::readString(fh);
            sec.level = FileHelper::readInteger(fh);
            sec.y = FileHelper::readInteger(fh);
            replacedSectors[when].push_back(sec);
        }
    }
    return super(fh);
}

HOOK_METHOD(StarMap, SaveGame, (int file) -> void)
{
    FileHelper::writeInt(file, replacedSectors.size());
    {
        for (auto i : replacedSectors)
        {
            FileHelper::writeInt(file, i.first);
            FileHelper::writeInt(file, i.second.size());
            for (auto j : i.second)
            {
                FileHelper::writeString(file, j.sectorList);
                FileHelper::writeInt(file, j.level);
                FileHelper::writeInt(file, j.y);
            }
        }
    }

    return super(file);
}

HOOK_METHOD(StarMap, AddSectorColumn, () -> void)
{
    super();

    if (bInfiniteMode)
    {
        int addedSector = lastSectors.empty() ? sectors.back()->level : lastSectors.back()->level;
        auto it = replacedSectors.find(addedSector);
        if (it != replacedSectors.end())
        {
            for (ReplacedSector& i : it->second)
            {
                for (auto sec : sectors)
                {
                    if (sec->level == i.level)
                    {
                        if (sec->location.y == i.y)
                        {
                            ReplaceSector(sec, i.sectorList, true);
                        }
                    }
                }
            }
        }
    }
}

HOOK_METHOD(StarMap, GenerateSectorMap, () -> void)
{
    super();

    if (!bInfiniteMode)
    {
        int addedSector = -1;
        auto it = replacedSectors.find(addedSector);
        if (it != replacedSectors.end())
        {
            for (ReplacedSector& i : it->second)
            {
                for (auto sec : sectors)
                {
                    if (sec->level == i.level)
                    {
                        if (sec->location.y == i.y)
                        {
                            ReplaceSector(sec, i.sectorList, true);
                        }
                    }
                }
            }
        }
    }
}

void ReplaceSector(SectorReplace &def)
{
    if (SeedInputBox::seedsEnabled) srandom32(Global::questSeed);

    StarMap& starMap = G_->GetWorld()->starMap;
    std::vector<Sector*> sectors;

    starMap.UpdateSectorMap(nullptr);

    for (auto sec : starMap.sectors)
    {
        if (sec->reachable && sec->description.type == def.targetSector)
        {
            sectors.push_back(sec);
        }
    }

    if (sectors.empty()) return;

    Sector *targetSector = sectors[random32()%sectors.size()];

    std::string sectorList = def.sectorList;
    if (sectorList == "ALL")
    {
        int rng = random32()%10;
        if (rng < 4)
        {
            sectorList = "CIVILIAN";
        }
        else if (rng < 8)
        {
            sectorList = "HOSTILE";
        }
        else
        {
            sectorList = "NEBULA";
        }
    }

    if (SeedInputBox::seedsEnabled) Global::questSeed = random32();

    ReplaceSector(targetSector, sectorList, false);
}

void ReplaceSector(Sector *sector, std::string sectorList, bool isLoading)
{
    StarMap &starMap = G_->GetWorld()->starMap;

    int seed = GenerateLocationSeed(sector->level, sector->location.y) ^ starMap.currentSectorSeed;
    srandom32(seed);

    if (sectorList.empty() || sectorList == "RANDOM")
    {
        switch (sector->type)
        {
        case 0:
            sectorList = "CIVILIAN";
            break;
        case 1:
            sectorList = "HOSTILE";
            break;
        case 2:
            sectorList = "NEBULA";
            break;
        default:
            sectorList = "UNKNOWN";
            break;
        }
    }

    if (sectorList == "CIVILIAN" || sectorList == "HOSTILE" || sectorList == "NEBULA" || sectorList == "UNKNOWN")
    {
        EventGenerator::GetSectorDescription(&sector->description, G_->GetEventGenerator(), sectorList, sector->level);
    }
    else
    {
        SectorDescription *desc = G_->GetEventGenerator()->GetSpecificSector(sectorList);
        sector->description = *desc;
        delete desc;
    }

    if (sectorList == "CIVILIAN")
    {
        sector->type = 0;
    }
    if (sectorList == "HOSTILE")
    {
        sector->type = 1;
    }
    if (sectorList == "NEBULA")
    {
        sector->type = 2;
    }
    if (sectorList == "UNKNOWN")
    {
        sector->type = 4;
    }

    if (!isLoading)
    {
        int highestLevel = starMap.bInfiniteMode ? (starMap.lastSectors.empty() ? starMap.sectors.back()->level : starMap.lastSectors.back()->level) : -1;
        replacedSectors[highestLevel].push_back(ReplacedSector({sectorList, sector->level, sector->location.y}));
    }
}
