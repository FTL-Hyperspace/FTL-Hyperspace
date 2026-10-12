#pragma once
#include "Global.h"

extern std::string droneSurgeOverride;
extern std::string barrageOverride;

struct DroneCount
{
    std::string drone;
    int number;
};

struct BarrageCount
{
    std::string weapon;
    int number;
};

class CustomBoss
{
public:
    std::vector<std::pair<std::string, int>> initialCrewList = std::vector<std::pair<std::string, int>>();
    std::vector<std::pair<std::string, int>> currentCrewCounts = std::vector<std::pair<std::string, int>>();
    std::array<std::vector<DroneCount>,3> droneSurgeDef;
    bool customSurgeDrones = false;

    std::array<std::vector<BarrageCount>,3> barrageDef;
    bool customBarrage = false;

    std::unordered_map<std::string, std::array<std::vector<DroneCount>,3>*> droneSurgeDefs;
    std::unordered_map<std::string, std::array<std::vector<BarrageCount>,3>*> barrageDefs;

    void ParseBossNode(rapidxml::xml_node<char> *node);
    void ParseBossDroneNode(rapidxml::xml_node<char> *node, std::array<std::vector<DroneCount>,3> *def);
    void ParseBossBarrageNode(rapidxml::xml_node<char> *node, std::array<std::vector<BarrageCount>,3> *def);

    static CustomBoss* instance;
};
