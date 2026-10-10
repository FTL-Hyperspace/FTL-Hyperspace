#include "Global.h"
#include <array>

void ParseFleetShipNode(rapidxml::xml_node<char>* node);

struct CustomFleetShip
{
    SpaceManager::FleetShip fleetShip;
    bool mirror;
    int layer = 0;
    bool autoDarkening = false;
};

struct FleetDefinition
{
    std::string fleetName;
    std::array<std::vector<std::string>, 5> shipTextures;
    std::array<int, 5> numShips = { 0, 0, 0, 0, 0 };
    std::string bigShip;
};

