#include "State.h"
#include "../../../Global.h"
#include "../../../CustomAugments.h"

namespace GameAccess
{
    // ============================================
    // State Queries
    // ============================================

    bool State::isInGame()
    {
        return G_ && G_->GetWorld() && G_->GetWorld()->commandGui;
    }

    bool State::isInMenu()
    {
        return G_ && G_->GetCApp() && G_->GetCApp()->menu.bOpen;
    }

    // ============================================
    // Game Object Accessors
    // ============================================

    CommandGui* State::getCommandGui()
    {
        if (!isInGame()) return nullptr;
        return G_->GetWorld()->commandGui;
    }

    ShipManager* State::getPlayerShip()
    {
        CommandGui* gui = getCommandGui();
        if (!gui || !gui->shipComplete) return nullptr;
        return gui->shipComplete->shipManager;
    }

    StarMap* State::getStarMap()
    {
        if (!G_ || !G_->GetWorld()) return nullptr;
        return &G_->GetWorld()->starMap;
    }

    WorldManager* State::getWorld()
    {
        if (!G_) return nullptr;
        return G_->GetWorld();
    }

    MainMenu* State::getMainMenu()
    {
        if (G_ && G_->GetCApp())
        {
            return &G_->GetCApp()->menu;
        }
        return nullptr;
    }

    ShipBuilder* State::getShipBuilder()
    {
        MainMenu* menu = getMainMenu();
        if (menu)
        {
            return &menu->shipBuilder;
        }
        return nullptr;
    }

    // ============================================
    // Player Resource Modifiers
    // ============================================

    void State::setPlayerHull(int hull)
    {
        ShipManager* ship = getPlayerShip();
        if (ship)
        {
            ship->ship.hullIntegrity.first = hull;
        }
    }

    void State::setPlayerScrap(int scrap)
    {
        ShipManager* ship = getPlayerShip();
        if (ship)
        {
            ship->currentScrap = scrap;
        }
    }

    void State::setPlayerFuel(int fuel)
    {
        ShipManager* ship = getPlayerShip();
        if (ship)
        {
            ship->fuel_count = fuel;
        }
    }

    void State::setPlayerMissiles(int missiles)
    {
        ShipManager* ship = getPlayerShip();
        if (ship)
        {
            ship->tempMissileCount = missiles;
        }
    }

    void State::setPlayerDrones(int drones)
    {
        ShipManager* ship = getPlayerShip();
        if (ship)
        {
            ship->tempDroneCount = drones;
        }
    }

    // ============================================
    // Player Resource Getters
    // ============================================

    int State::getPlayerHull()
    {
        ShipManager* ship = getPlayerShip();
        return ship ? ship->ship.hullIntegrity.first : -1;
    }

    int State::getPlayerScrap()
    {
        ShipManager* ship = getPlayerShip();
        return ship ? ship->currentScrap : -1;
    }

    // ============================================
    // Test Isolation
    // ============================================

    // Always return to main menu between tests

    void State::returnToMainMenu()
    {
        if (G_ && G_->GetWorld())
        {
            G_->GetCApp()->menu.Open();
        }
    }

    // ============================================
    // UI Interaction
    // ============================================

    void State::clickButton(GenericButton* button)
    {
        if (!button || !G_ || !G_->GetCApp()) return;

        // Get button hitbox center
        Globals::Rect hitbox = button->hitbox;
        int clickX = hitbox.x + hitbox.w / 2;
        int clickY = hitbox.y + hitbox.h / 2;

        // MouseMove to set hover state, then click
        MainMenu* menu = &G_->GetCApp()->menu;
        menu->MouseMove(clickX, clickY);
        menu->MouseClick(clickX, clickY);
    }

    // ============================================
    // Combat Helpers
    // ============================================

    CompleteShip* State::getEnemyShip()
    {
        CommandGui* gui = getCommandGui();
        if (!gui) return nullptr;
        return gui->combatControl.currentTarget;
    }

    bool State::hasEnemyShip()
    {
        return getEnemyShip() != nullptr;
    }

    bool State::spawnEnemyShip(const std::string& blueprintName)
    {
        WorldManager* world = getWorld();
        if (!world) return false;

        // Create a ship event for the enemy
        ShipEvent shipEvent;
        shipEvent.present = true;
        shipEvent.name = blueprintName;
        shipEvent.blueprint = blueprintName;
        shipEvent.hostile = true;
        shipEvent.shipSeed = rand();

        // Create the enemy ship
        CompleteShip* enemy = world->CreateShip(&shipEvent, false);
        if (!enemy) return false;

        // Add to combat
        CommandGui* gui = getCommandGui();
        if (gui)
        {
            gui->AddEnemyShip(enemy);
        }

        return true;
    }

    bool State::addSuperShieldToEnemy(int shieldAmount)
    {
        CompleteShip* enemy = getEnemyShip();
        if (!enemy || !enemy->shipManager) return false;

        Shields* shields = enemy->shipManager->shieldSystem;
        if (!shields) return false;

        // Set super shield amount (max and current)
        shields->shields.power.super.second = shieldAmount;
        shields->shields.power.super.first = shieldAmount;

        // Add the super shield visual at ship center
        Point center;
        center.x = enemy->shipManager->ship.shipImage.x;
        center.y = enemy->shipManager->ship.shipImage.y;
        shields->AddSuperShield(center);

        return true;
    }

    bool State::setEnemyShieldBubbles(int bubbles)
    {
        CompleteShip* enemy = getEnemyShip();
        if (!enemy || !enemy->shipManager) return false;

        Shields* shields = enemy->shipManager->shieldSystem;
        if (!shields) return false;

        // Upgrade the shield system power capacity (2 power per bubble)
        int powerNeeded = bubbles * 2;
        shields->powerState.first = powerNeeded;
        shields->powerState.second = powerNeeded;

        // Set regular shield bubbles (first = current, second = max)
        shields->shields.power.first = bubbles;
        shields->shields.power.second = bubbles;

        return true;
    }

    bool State::addEnergyShieldToEnemy(int points)
    {
        CompleteShip* enemy = getEnemyShip();
        if (!enemy || !enemy->shipManager) return false;

        Shields* shields = enemy->shipManager->shieldSystem;
        if (!shields) return false;

        // Create a custom augment definition with super shield
        CustomAugmentManager* customAug = CustomAugmentManager::GetInstance();

        static AugmentDefinition* testAugDef = nullptr;
        if (!testAugDef)
        {
            testAugDef = new AugmentDefinition();
            testAugDef->name = "TEST_SUPER_SHIELD";
            testAugDef->superShield.present = true;
            testAugDef->superShield.value = points;
            testAugDef->superShield.customRender = true;
            testAugDef->superShield.shieldColor = GL_Color(0.5f, 0.0f, 1.0f, 1.0f);  // Purple
            customAug->AddAugmentDefinition("TEST_SUPER_SHIELD", testAugDef);
        }
        testAugDef->superShield.value = points;

        // Add the augment to enemy ship and sync the cached list
        G_->GetShipInfo(true)->augList["TEST_SUPER_SHIELD"] = 1;
        customAug->UpdateAugments(1);  // Sync to cached augListWithHidden

        // Set super shield directly (super.first = current, super.second = max)
        shields->shields.power.super.second = points;
        shields->shields.power.super.first = points;

        return true;
    }

    void State::clearEnemyShip()
    {
        CommandGui* gui = getCommandGui();
        if (gui)
        {
            gui->combatControl.Clear();
        }

        // Also clear the enemy ship reference from player ship
        WorldManager* world = getWorld();
        if (world && world->playerShip)
        {
            world->playerShip->enemyShip = nullptr;
        }
    }
}
