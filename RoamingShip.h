#pragma once
#include "Global.h"

struct RoamingShip
{
    enum class Behavior
    {
        Idle, // 0: Isn't moving at all
        Roaming, // 1: Moves randomly
        Fleeing, // 2: Runs away from target
        Hunting // 3: Runs toward target
        Hyper // 4: Smart targetting toward the player.
    };

    std::string id;
    GL_Texture mapIcon;
    std::vector<std::string> eventsList;
    int eventIndex = 0;
    int behavior = Behavior::Idle;

    int timeToMove = 1;
    int currentMoveTime = 0;
    int beaconDegree = 0;

    Location targetLocation = nullptr; // since we need to save those we might make them int, it'll all depend if map generation index are stable on reload
    Location currentLocation = nullptr;

    int missingHP = 0;
    int missingCrew = 0; // we'll need a more precise way to handle crew
};

struct RoamingShipsManager
public:{
    static RoamingShipsManager* GetInstance()
    {
        return &instance;
    }

    std::map<std::string, RoamingShip*> roamingShips; // it's your library of ships, you pull them from here
    std::vector<std::string> activeRoamingShips; // which ships are currently in the sector

    void AddRoamingShip(std::string ship, Location beacon); // Adds in the roaming ship to the sector (i think)
    // add the shipId into activeRoamingShips
    // set the ship's currentLocation to beacon
    // set all other value to default
    // set targetLocation to nullptr
    // set beaconDegree to a random value 0-360

    void RemoveRoamingShip(std::string ship); // Removes it for whatever reason necessary
    // remove the shipId from activeRoamingShips

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

    void LoadShips(); // Cursed artifact
    void SaveShips(); // god forbid.*
    // number of roaming ship extisting
    // loop through that number
    // id of the ship
    // save currentlocation
    // save targetLocation
    // currentMoveTime
    // missingHP/crew
    // behaviour
    // eventIndex

    void ParseShipsNode(rapidxml::xml_node<char> *node) // probably keeping track of each Roaming Ship
}
private:{
    static RoamingShipsManager instance;
};