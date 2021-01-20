#pragma once
#include "Global.h"

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
    std::vector<DroneCount> droneSurgeDef[3];
    bool customSurgeDrones = false;


    void ParseBossNode(rapidxml::xml_node<char> *node);


    static CustomBoss* instance;
};
