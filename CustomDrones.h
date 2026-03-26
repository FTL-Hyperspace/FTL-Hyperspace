#pragma once
#include "Global.h"
#include "AbilityDrone.h"
#include <rapidxml.hpp>

namespace DefenseDroneFix
{
    extern bool active;
    extern float boxRange[2];
    extern float ellipseRange[2];
};

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

struct ShieldDroneDefinition
{
    std::string chargeSound = "shieldDroneCharge";
    std::string activateSound = "shieldDroneActivate";
    float slowDuration = 1.f;
    float pulseDuration = 1.5f;
    std::vector<float> cooldowns;
    int layers = 1;
};

class ShieldDroneManager
{
public:
    static void ParseShieldDroneBlueprint(rapidxml::xml_node<char> *node);
    static const ShieldDroneDefinition* GetDefinition(const std::string& droneName);
private:
    static const ShieldDroneDefinition defaultDefinition;
    static std::unordered_map<std::string, ShieldDroneDefinition> defs;
};
