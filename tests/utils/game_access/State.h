#pragma once
#include "../framework/Core.h"

struct GenericButton;
struct CompleteShip;

/**
 * GameAccess::State
 *
 * Safe access to game state and entities.
 * Provides methods to query game state, access game objects,
 * and modify player resources for testing purposes.
 */

namespace GameAccess
{
    /**
     * Provides safe access to game state and entities
     */
    class State
    {
    public:
        // State queries
        static bool isInGame();
        static bool isInMenu();

        // Game object accessors (return nullptr if not available)
        static CommandGui* getCommandGui();
        static ShipManager* getPlayerShip();
        static StarMap* getStarMap();
        static WorldManager* getWorld();
        static MainMenu* getMainMenu();
        static ShipBuilder* getShipBuilder();

        // Player resource modifiers
        static void setPlayerHull(int hull);
        static void setPlayerScrap(int scrap);
        static void setPlayerFuel(int fuel);
        static void setPlayerMissiles(int missiles);
        static void setPlayerDrones(int drones);

        // Player resource getters
        static int getPlayerHull();
        static int getPlayerScrap();

        // Test isolation - managing game state between tests
        static void returnToMainMenu();

        // UI interaction
        static void clickButton(GenericButton* button);

        // Combat helpers
        static CompleteShip* getEnemyShip();
        static bool spawnEnemyShip(const std::string& blueprintName);
        static bool hasEnemyShip();
        static bool addSuperShieldToEnemy(int shieldAmount);
        static bool setEnemyShieldBubbles(int bubbles);
        static bool addEnergyShieldToEnemy(int points = 5);
        static void clearEnemyShip();
    };
}
