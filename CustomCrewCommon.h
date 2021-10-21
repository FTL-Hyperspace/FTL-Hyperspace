#pragma once

#include "FTLGame.h"


struct StatBoostDefinition;

struct ExplosionDefinition
{
    Damage damage;
    bool shipFriendlyFire = false;
    std::vector<StatBoostDefinition*> statBoosts;
};

struct CrewSpawn
{
    std::string race = "";
    std::string name = "";
    float healthPercentage = 1.f;
    std::vector<StatBoostDefinition*> statBoosts;
    bool noSlot = false;
    int number = 1;

    static std::vector<CrewMember*> SpawnCrew(CrewSpawn& crewSpawn, ShipManager *ship, bool intruder, Pointf spawnPos, bool tile=false);
    static CrewSpawn ParseCrewSpawn(rapidxml::xml_node<char>* node, bool isCrew);
};
