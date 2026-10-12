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

SectorDescription* EventGenerator_GetSectorDescriptionCustom(SectorDescription* ret, EventGenerator* _this, const std::string& type, int level);



struct CustomSectorGeneratorList
{
    int maxSector = -1;
    int totalChance = 0;
    std::vector<std::pair<int,std::string>> sectorTypes;
};

class CustomSectorManager
{
public:
    CustomSectorManager()
    {

    }

    void ParseCustomSectorMapNode(rapidxml::xml_node<char> *node);

    static bool SectorIsType(const std::string &name, const std::string &type);

    std::string GetSectorType(int level)
    {
        for (CustomSectorGeneratorList& generator : generators)
        {
            if (generator.maxSector == -1 || generator.maxSector >= level)
            {
                int rng = random32() % generator.totalChance;
                for (auto& it : generator.sectorTypes)
                {
                    rng -= it.first;
                    if (rng < 0) return it.second;
                }
                return "";
            }
        }
        return "";
    }

    static CustomSectorManager *GetInstance()
    {
        return instance;
    }

private:
    static CustomSectorManager *instance;
    std::vector<CustomSectorGeneratorList> generators;
};
