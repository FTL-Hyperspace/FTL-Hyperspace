#include "Global.h"

class CustomBoss
{
public:
    static std::vector<std::pair<std::string, int>> initialCrewList;
    static std::vector<std::pair<std::string, int>> currentCrewCounts;

    static void ParseBossCrewNode(rapidxml::xml_node<char> *node);
};
