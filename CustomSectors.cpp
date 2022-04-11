#include "CustomSectors.h"

#include <boost/lexical_cast.hpp>

CustomSectorManager *CustomSectorManager::instance = new CustomSectorManager();

std::unordered_map<int,std::vector<ReplacedSector>> replacedSectors = std::unordered_map<int,std::vector<ReplacedSector>>();

static bool sectorColorOverride = false;

void CustomSectorManager::ParseCustomSectorMapNode(rapidxml::xml_node<char> *node)
{
    generators.clear();

    for (auto child = node->first_node(); child; child = child->next_sibling())
    {
        if (strcmp(child->name(), "sectorList") == 0)
        {
            CustomSectorGeneratorList sectorLists = CustomSectorGeneratorList();
            if (child->first_attribute("maxSector"))
            {
                sectorLists.maxSector = boost::lexical_cast<int>(child->first_attribute("maxSector")->value());
            }
            for (auto child2 = child->first_node(); child2; child2 = child2->next_sibling())
            {
                std::string sectorList = child2->name();
                int chance = 1;
                if (child2->first_attribute("chance"))
                {
                    chance = boost::lexical_cast<int>(child2->first_attribute("chance")->value());
                }
                sectorLists.totalChance += chance;
                sectorLists.sectorTypes.push_back({chance, sectorList});
            }
            if (sectorLists.totalChance > 0)
            {
                generators.push_back(sectorLists);
            }
        }
    }
}

HOOK_METHOD(StarMap, NewGame, (bool unk) -> Location*)
{
    LOG_HOOK("HOOK_METHOD -> StarMap::NewGame -> Begin (CustomSectors.cpp)\n")
    replacedSectors.clear();

    return super(unk);
}

HOOK_METHOD(StarMap, LoadGame, (int fh) -> Location*)
{
    LOG_HOOK("HOOK_METHOD -> StarMap::LoadGame -> Begin (CustomSectors.cpp)\n")
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
    LOG_HOOK("HOOK_METHOD -> StarMap::SaveGame -> Begin (CustomSectors.cpp)\n")
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

bool CustomSectorManager::SectorIsType(const std::string &name, const std::string &type)
{
    EventGenerator *_this = G_->GetEventGenerator();

    auto sectorListIt = _this->baseSectors.find(type);
    if (sectorListIt == _this->baseSectors.end())
    {
        return false;
    }

    std::vector<std::string>* pSectorList = &sectorListIt->second;

    if (Settings::GetDlcEnabled())
    {
        sectorListIt = _this->baseSectors.find("OVERRIDE_" + type);
        if (sectorListIt != _this->baseSectors.end())
        {
            pSectorList = &sectorListIt->second;
        }
    }

    for (auto& sectorName : *pSectorList)
    {
        if (sectorName == name) return true;
    }

    return false;
}

HOOK_METHOD(StarMap, AddSectorColumn, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> StarMap::AddSectorColumn -> Begin (CustomSectors.cpp)\n")
    super();

    if (sectorColorOverride)
    {
        sectorColorOverride = false;
        for (Sector* sec : lastSectors)
        {
            if (CustomSectorManager::SectorIsType(sec->description.type, "CIVILIAN"))
            {
                sec->type = 0;
                continue;
            }
            if (CustomSectorManager::SectorIsType(sec->description.type, "HOSTILE"))
            {
                sec->type = 1;
                continue;
            }
            if (CustomSectorManager::SectorIsType(sec->description.type, "NEBULA"))
            {
                sec->type = 2;
                continue;
            }
            sec->type = 4;
        }
    }

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
    LOG_HOOK("HOOK_METHOD -> StarMap::GenerateSectorMap -> Begin (CustomSectors.cpp)\n")
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

    //starMap.UpdateSectorMap(nullptr);

    for (auto sec : starMap.sectors)
    {
        if (sec->level > starMap.worldLevel && sec->description.type == def.targetSector)
        {
            sectors.push_back(sec);
        }
    }

    if (sectors.empty()) return;

    Sector *targetSector = sectors[random32()%sectors.size()];

    if (SeedInputBox::seedsEnabled) Global::questSeed = random32();

    ReplaceSector(targetSector, def.sectorList, false);
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

    if (sectorList == "ALL")
    {
        sectorList = CustomSectorManager::GetInstance()->GetSectorType(sector->level);

        if (sectorList.empty())
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
        sector->description = G_->GetEventGenerator()->GetSectorDescriptionCustom(sectorList, sector->level);
    }
    else if (sectorList == "CIVILIAN" || sectorList == "HOSTILE" || sectorList == "NEBULA" || sectorList == "UNKNOWN")
    {
        sector->description = G_->GetEventGenerator()->GetSectorDescriptionCustom(sectorList, sector->level);
    }
    else
    {
        sector->description = G_->GetEventGenerator()->GetSpecificSector(sectorList);
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

SectorDescription EventGenerator::GetSectorDescriptionCustom(const std::string& type, int level)
{
    SectorDescription ret = SectorDescription();

    auto sectorListIt = this->baseSectors.find(type);
    if (sectorListIt == this->baseSectors.end())
    {
        hs_log_file("INVALID SECTOR TYPE! %s\n", type.c_str());
        return ret;
    }

    std::vector<std::string>* pSectorList = &sectorListIt->second;

    if (Settings::GetDlcEnabled())
    {
        sectorListIt = this->baseSectors.find("OVERRIDE_" + type);
        if (sectorListIt != this->baseSectors.end())
        {
            pSectorList = &sectorListIt->second;
        }
    }

    std::vector<std::string> sectorList = std::vector<std::string>();
    for (auto& sectorName : *pSectorList)
    {
        SectorDescription& sectorDesc = this->sectors[sectorName];
        if (level < sectorDesc.minSector || sectorDesc.used)
        {
            continue;
        }

        CustomSector *custom = CustomEventsParser::GetInstance()->GetCustomSector(sectorName);
        if (custom)
        {
            if (custom->maxSector != -1 && level > custom->maxSector)
            {
                continue;
            }
        }

        sectorList.push_back(sectorName);
    }

    if (sectorList.size() == 0)
    {
        return this->GetSpecificSector("STANDARD_SPACE");
    }

    std::string selectedSectorName = sectorList[random32() % sectorList.size()];

    SectorDescription& sectorDesc = this->sectors[selectedSectorName];
    if (sectorDesc.unique) sectorDesc.used = true;

    ret = sectorDesc;

    int nameIndex = random32() % ret.names.size();

    ret.name = ret.names[nameIndex];
    ret.shortName = ret.shortNames[nameIndex];

    if (sectorDesc.names.size() > 1)
    {
        sectorDesc.names.erase(sectorDesc.names.begin() + nameIndex);
        sectorDesc.shortNames.erase(sectorDesc.shortNames.begin() + nameIndex);
    }

    return ret;
}

HOOK_METHOD_PRIORITY(EventGenerator, GetSectorDescription, 9999, (const std::string& type, int level) -> SectorDescription)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> EventGenerator::GetSectorDescription -> Begin (CustomSectors.cpp)\n")
    std::string newType = CustomSectorManager::GetInstance()->GetSectorType(level);
    if (!newType.empty())
    {
        sectorColorOverride = true;
        return this->GetSectorDescriptionCustom(newType, level);
    }

    return this->GetSectorDescriptionCustom(type, level);
}
