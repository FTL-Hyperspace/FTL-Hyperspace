#pragma once

#include "FTLGame.h"


struct StatBoostDefinition;

struct CrewSpawn
{
    int idx = -1;
    std::string race = "";
    std::string name = "";
    float healthPercentage = 1.f;
    float lifetime = -1.f;
    std::vector<StatBoostDefinition*> statBoosts;
    bool noSlot = false;
    bool enemy = false;
    int number = 1;

    static std::vector<CrewMember*> SpawnCrew(CrewSpawn *crewSpawn, ShipManager *ship, bool intruder, Pointf spawnPos, bool tile=false);
    static CrewSpawn *ParseCrewSpawn(rapidxml::xml_node<char>* node, bool isCrew);

    static std::vector<CrewSpawn*> crewSpawnDefs;

    void GiveId()
    {
        idx = crewSpawnDefs.size();
        crewSpawnDefs.push_back(this);
    }
};

struct ExplosionDefinition
{
    Damage damage;
    bool shipFriendlyFire = false;
    std::vector<StatBoostDefinition*> statBoosts;
    std::vector<CrewSpawn*> crewSpawns;
    std::string transformRace = "";
    float transformRaceHealth = 0.f;
    float transformRaceHealthFraction = 1.f;
    bool transformRaceDeathSound = false;
    std::array<std::string,2> event = {"",""};
};
