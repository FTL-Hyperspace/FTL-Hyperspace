#pragma once

#include "Global.h"
#include "CustomShipSelect.h"

class CustomShipGenerator
{
public:
    ShipManager *CreateShip(const ShipBlueprint *shipBlueprint, int sector, ShipEvent& event);

    void RemoveAugments(ShipBlueprint &bp, int level);
    void SetMaximumHull(ShipBlueprint &bp, int level, CustomShipDefinition *customShip);
    int InitShip(ShipManager *ship, ShipBlueprint &bp, int level, ShipEvent& event, std::vector<CrewDesc> &crewOverride, CustomShipDefinition *customShip);
    std::vector<int> GenerateShipBudget(int level);
    void AddSystems(ShipManager *ship, int level, std::vector<int> &systemMaxes, std::vector<int> &budget);
    void UpgradeSystems(ShipManager *ship, std::vector<int> &systemMaxes, std::vector<int> &budget);
    void AddOverrideWeapons(ShipManager *ship, ShipEvent& event);
    void AddOverrideDrones(ShipManager *ship, ShipEvent& event);
    void AddWeapons(ShipManager *ship, ShipBlueprint &bp, unsigned int &flags);
    void AddDrones(ShipManager *ship, ShipBlueprint &bp, unsigned int &flags);
    void AddCrew(ShipManager *ship, std::vector<CrewDesc> &crewOverride, int crewCount, unsigned int &flags);

    static bool enabled;
    static CustomShipGenerator *GetShipGenerator(const std::string &name);
private:
    static std::unordered_map<std::string,CustomShipGenerator> customShipGenerators;
    static CustomShipGenerator *defaultShipGenerator;
};
