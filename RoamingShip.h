#pragma once
#include "Global.h"

struct RoamingShip
{
    enum class Behavior
    {
        Idle, // 0: Isn't moving at all
        Roaming, // 1: Moves randomly
        Hunting, // 2: Runs toward target
        Player, // 3: Runs towards Player
        Aggressive, // 4: Smart targetting toward the player.
        FleetRandom, // 5: Capable of only jumping between fleet beacons
        FleetPlayer, // 6: Targets the Player when in the fleet
        FleetAggressive, // 7: Smart targetting toward the player when in the fleet
        Escape // 8: Flees toward the Exit beacon
    };

    std::string id;
    GL_Texture* mapIcon;
    std::vector<std::string> eventsList;
    int eventIndex = 0;
    int behavior = 0;

    int timeToMove = 1;
    int currentMoveTime = 0;
    float beaconDegree = 0;

    Location* targetLocation = nullptr; // since we need to save those we might make them int, it'll all depend if map generation index are stable on reload
    Location* currentLocation = nullptr;

    int missingHP = 0;
    int missingCrew = 0; // we'll need a more precise way to handle crew
};

struct RoamingShipsManager
{
public:
    static RoamingShipsManager* GetInstance()
    {
        return instance;
    }

    std::map<std::string, RoamingShip*> roamingShips; // it's your library of ships, you pull them from here
    std::vector<std::string> activeRoamingShips; // which ships are currently in the sector

    void AddRoamingShip(std::string ship, Location* beacon);

    void RemoveRoamingShip(std::string ship);

    void RenderShips(); // Renders the map icon and movement direction thing
    // loop through activeRoamingShips
    // render the ship mapIcon rotating around the beacon, increment the rotation
    // timeToMove == currentMoveTime && targetLocation exists, render the movement direction thing

    void MoveShips(); // Translates the behavior into movement 
    // loop through activeRoamingShips
    // if timeToMove == currentMoveTime
    // calculate using djikstra and the behaviour defined the targetLocation
    // add the security where two ship won't go tp the same beacon
    // timeToMove < currentMoveTime, move the ship and reset the currentMoveTime

    void LoadShips(int fd);
    void SaveShips(int fd); 

    void ParseShipsNode(rapidxml::xml_node<char> *node); // probably keeping track of each Roaming Ship
    static RoamingShipsManager *instance;
private:
    
};
