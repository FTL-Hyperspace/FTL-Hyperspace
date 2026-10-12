#pragma once

#include "Global.h"
#include "CustomShipSelect.h"

class CustomShipGenerator
{
    struct SectorScaling
    {
        bool enabled = false;
        float minValue = 0.f;
        float maxValue = 1.f;
        float baseValue = 0.f;
        float sectorValue = 0.125f;

        float GetValue(int level)
        {
            return std::max(minValue, std::min(baseValue + level*sectorValue, maxValue));
        }

        void Parse(rapidxml::xml_node<char> *node);
    };

    struct SystemLevelScaling
    {
        bool enabled = false;
        SectorScaling sectorScaling;
        std::vector<std::pair<int,int>> randomScaling;

        int GetRandomScalingValue(int level)
        {
            int i=1;
            for (; i<randomScaling.size(); ++i)
            {
                if (randomScaling[i].first > level) break;
            }
            return randomScaling[i-1].second;
        }

        void Parse(rapidxml::xml_node<char> *node, int difficulty);
    };

public:
    std::array<float,3> difficultyMod = {-1.f, 0.f, 0.f};
    std::array<SectorScaling,3> defaultSectorScaling;
    std::unordered_map<int,std::array<SystemLevelScaling,3>> systemLevelScaling;


    ShipManager *CreateShip(const ShipBlueprint *shipBlueprint, int sector, ShipEvent& event);

    void RemoveAugments(ShipBlueprint &bp, int level);
    void SetMaximumHull(ShipBlueprint &bp, int level, CustomShipDefinition *customShip);
    int InitShip(ShipManager *ship, ShipBlueprint &bp, int level, ShipEvent& event, std::vector<CrewDesc> &crewOverride, CustomShipDefinition *customShip);
    std::vector<int> GenerateSystemMaxes(ShipBlueprint &bp, int level);
    std::vector<int> GenerateShipBudget(int level);
    void AddSystems(ShipManager *ship, int level, std::vector<int> &systemMaxes, std::vector<int> &budget);
    void UpgradeSystems(ShipManager *ship, std::vector<int> &systemMaxes, std::vector<int> &budget);
    std::vector<int> GetPossibleSystemUpgrades(ShipManager *ship, std::vector<int> &systemMaxes, int type);
    void AddOverrideWeapons(ShipManager *ship, ShipEvent& event);
    void AddOverrideDrones(ShipManager *ship, ShipEvent& event);
    void AddWeapons(ShipManager *ship, ShipBlueprint &bp, unsigned int &flags);
    void AddDrones(ShipManager *ship, ShipBlueprint &bp, unsigned int &flags);
    void AddCrew(ShipManager *ship, std::vector<CrewDesc> &crewOverride, int crewCount, unsigned int &flags);

    static bool enabled;
    static void Init();

    static void ParseGeneratorNode(rapidxml::xml_node<char> *node);
    static CustomShipGenerator *GetShipGenerator(const std::string &name);
    static CustomShipGenerator *GetShipGenerator();
private:
    static std::unordered_map<std::string,CustomShipGenerator> customShipGenerators;
    static CustomShipGenerator *defaultShipGenerator;

    static std::array<SystemLevelScaling,3> defaultSystemLevelScaling;

    SectorScaling *GetDefaultSectorScaling();
    SectorScaling *GetSectorScaling(SectorScaling *selectedScaling);
    SystemLevelScaling *GetSystemLevelScaling(int difficulty, int sysId);
};
