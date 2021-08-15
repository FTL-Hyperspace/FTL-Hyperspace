#pragma once
#include "Global.h"

extern std::string droneSurgeOverride;

struct DroneCount
{
    std::string drone;
    int number;
};

class CustomBoss
{
public:
    std::vector<std::pair<std::string, int>> initialCrewList = std::vector<std::pair<std::string, int>>();
    std::vector<std::pair<std::string, int>> currentCrewCounts = std::vector<std::pair<std::string, int>>();
    std::array<std::vector<DroneCount>,3> droneSurgeDef;
    bool customSurgeDrones = false;

    std::unordered_map<std::string, std::array<std::vector<DroneCount>,3>*> droneSurgeDefs;

    void ParseBossNode(rapidxml::xml_node<char> *node);
    void ParseBossDroneNode(rapidxml::xml_node<char> *node, std::array<std::vector<DroneCount>,3> *def);

    static CustomBoss* instance;
};
