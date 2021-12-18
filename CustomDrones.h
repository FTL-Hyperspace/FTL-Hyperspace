#pragma once
#include "Global.h"
#include "AbilityDrone.h"
#include <rapidxml.hpp>

static bool g_defenseDroneFix;
static float g_defenseDroneFix_BoxRange[2];
static float g_defenseDroneFix_EllipseRange[2];

//extern bool g_dronesCanTeleport;

struct CustomDroneDefinition
{
    std::string name;
    std::string tooltipName;
    std::string crewBlueprint;

    bool hasAbility = false;
    DroneAbilityDefinition ability;
};

class CustomDroneManager
{
public:
    CustomDroneManager()
    {
    }

    void ParseDroneNode(rapidxml::xml_node<char> *node);

    CustomDroneDefinition* GetDefinition(const std::string& droneName)
    {
        for (auto i : droneDefs)
        {
            if (i->name == droneName)
            {
                return i;
            }
        }

        return nullptr;
    }

    CustomDroneDefinition* GetDefinitionByRace(const std::string& raceName)
    {
        for (auto i : droneDefs)
        {
            if (i->crewBlueprint == raceName)
            {
                return i;
            }
        }

        return nullptr;
    }

    static CustomDroneManager *GetInstance()
    {
        return &_instance;
    }

private:

    std::vector<CustomDroneDefinition*> droneDefs = std::vector<CustomDroneDefinition*>();

    static CustomDroneManager _instance;
};
