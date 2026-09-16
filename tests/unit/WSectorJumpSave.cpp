#include "../utils/TestUtils.h"
#include "../../Global.h"

/**
 * Integration Test: Sector Jump Save to be used with Multiverse mod (will be moved to MV tests folder)
 *
 * Tests loading a save at sector exit and jumping to a new sector.
 * Uses the SavedGame scenario.
 */

static void SectorJumpSaveTest(TestFramework::Test& test, TestFramework::TestStages& stages)
{
    test.section("Sector Jump Save Test");

    // Verify starting state
    stages.addStage("Verify starting state", [&test]() {
        
        test.assertTrue(GameAccess::State::getPlayerHull() > 0, "Player has positive hull");
        test.assertTrue(GameAccess::State::getPlayerScrap() >= 0, "Player has valid scrap count");
    }, 0);

    // Open sector jump menu
    stages.addStage("Open sector jump menu", [&test]() {
        StarMap* starMap = GameAccess::State::getStarMap();
        test.requireNotNull(starMap, "StarMap is available");

        starMap->bOpen = true;
        starMap->bChoosingNewSector = true;
    }, 50);

    // Select and jump to sector
    stages.addStage("Jump to sector", [&test]() {
        StarMap* starMap = GameAccess::State::getStarMap();
        test.requireNotNull(starMap, "StarMap still available");

        // Find first valid neighboring sector
        int sectorChoice = -1;
        for (int i = 0; i < 20; i++)
        {
            if (starMap->NeighboringSector(i))
            {
                sectorChoice = i;
                break;
            }
        }
        test.requireTrue(sectorChoice >= 0, "Valid sector choice available");

        starMap->finalSectorChoice = sectorChoice; // top sector (+1 would a second choice)
        test.log("Jumping to sector " + std::to_string(sectorChoice));
    }, 300);

    // Verify sector jump (prev crashed before this)
    stages.addStage("Verify sector jump", [&test]() {
        StarMap* starMap = GameAccess::State::getStarMap();
        test.requireNotNull(starMap, "StarMap still available");

        test.assertTrue(starMap->worldLevel >= 1, "Advanced to next sector");
        test.assertTrue(GameAccess::State::isInGame(), "Still in game after jump");
        test.log("New world level: " + std::to_string(starMap->worldLevel));
    }, 100);

}

// Auto-register
// Crash save might be corrupted which causes crashes after loading a new game.
// Uses WW in name to run last and not cause issues for other tests. Remove in future.
// Disabled because of save corruption issues.
//static TestFramework::TestRegistrar _sectorJumpTest("SectorJump", SectorJumpSaveTest, "SavedGame",
//    TestFramework::ScenarioParams().setString("saveName", "mv-sector-jump"));
