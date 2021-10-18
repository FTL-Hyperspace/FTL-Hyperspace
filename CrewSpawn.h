#pragma once
#include "Global.h"
#include "StatBoost.h"


struct CrewSpawn
{
    std::string race = "";
    std::string name = "";
    float healthPercentage = 1.f;
    std::vector<StatBoostDefinition*> statBoosts;
    bool noSlot = false;
    int number = 1;

    static std::vector<CrewMember*> SpawnCrew(CrewSpawn& crewSpawn, ShipManager *ship, bool intruder, Pointf spawnPos);
    static CrewSpawn ParseCrewSpawn(rapidxml::xml_node<char>* node);
};


