#pragma once
#include "Global.h"

struct ShipIconDefinition
{
    std::string name;
    std::string tooltip;
};

class ShipIconManager
{
public:
    ShipIconManager()
    {

    }

    void ParseShipIconNode(rapidxml::xml_node<char>* node);

    Point normalBoxPos;
    Point bossBoxPos;

    ShipIconDefinition* GetShipIconDefinition(const std::string& name)
    {
        if (shipIcons.find(name) != shipIcons.end())
        {
            return &shipIcons[name];
        }

        return nullptr;
    }

    static ShipIconManager* instance;
private:
    std::map<std::string, ShipIconDefinition> shipIcons;
};
