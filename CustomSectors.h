#pragma once

#include "Global.h"
#include "CustomEvents.h"
#include "Seeds.h"

struct ReplacedSector
{
    std::string sectorList;
    int level;
    int y;
};

extern std::unordered_map<int,std::vector<ReplacedSector>> replacedSectors;

void ReplaceSector(SectorReplace &def);
void ReplaceSector(Sector *sector, std::string sectorList, bool isLoading);
