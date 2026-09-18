#include "../utils/TestUtils.h"
#include "../../Global.h"

/**
 * Enemy Shield Test
 *
 * Tests spawning an enemy ship with super shields (Zoltan shields).
 * Used to verify CachedPrimitive::OnRender works correctly on all platforms.
 */

static void EnemyShieldTest(TestFramework::Test& test, TestFramework::TestStages& stages)
{
    test.section("Enemy Shield Rendering Test");

    // Spawn an enemy ship with shields
    stages.addStage("Spawn enemy ship", [&test]() {
        bool spawned = GameAccess::State::spawnEnemyShip("CIRCLE_SCOUT");
        test.assertTrue(spawned, "Enemy ship spawned");
    }, 30);

    // Verify enemy has shield system
    stages.addStage("Verify shields", [&test]() {
        CompleteShip* enemy = GameAccess::State::getEnemyShip();
        test.requireNotNull(enemy, "Enemy ship exists");
        test.requireNotNull(enemy->shipManager->shieldSystem, "Enemy has shield system");
    }, 0);

    // Add ENERGY_SHIELD augment with 8 points (triggers custom super shield rendering)
    stages.addStage("Add energy shield", [&test]() {
        bool added = GameAccess::State::addEnergyShieldToEnemy(10);
        test.assertTrue(added, "Energy shield added with 8 points");
    }, 0);

    // Let the game render - this triggers CachedPrimitive::OnRender paths
    stages.addStage("Render frames", [&test]() {
        test.pass("Rendering custom super shields");
    }, 100);

    // Verify game didn't crash during rendering
    stages.addStage("Verify stability", [&test]() {
        test.requireTrue(GameAccess::State::isInGame(), "Game still running");
        test.requireNotNull(GameAccess::State::getEnemyShip(), "Enemy still exists");
    }, 0);

    // Cleanup - clear enemy ship before test ends
    stages.addStage("Cleanup", [&test]() {
        GameAccess::State::clearEnemyShip();
        test.pass("Combat cleared");
    }, 0);
}

// Auto-register with NewGameSeeded scenario
static TestFramework::TestRegistrar _enemyShieldTest("EnemyShield", EnemyShieldTest, "NewGameSeeded",
    TestFramework::ScenarioParams().setInt("seed", 42));
