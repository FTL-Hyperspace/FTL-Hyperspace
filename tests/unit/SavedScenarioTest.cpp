#include "../utils/TestUtils.h"
#include "../../Global.h"

/**
 * Integration Test: Saved Scenario
 *
 * Tests loading a saved game and verifying expected state.
 * Uses the SavedGame scenario with hull-28 save.
 */

static void SavedScenarioTest(TestFramework::Test& test, TestFramework::TestStages& stages)
{
    test.section("Saved Scenario Test");

    // Verify starting resources
    stages.addStage("Verify starting resources", [&test]() {
        int hull = GameAccess::State::getPlayerHull();
        int scrap = GameAccess::State::getPlayerScrap();

        test.log("Starting hull: " + std::to_string(hull));
        test.log("Starting scrap: " + std::to_string(scrap));

        test.assertTrue(hull == 28, "Player has 28 hull (saved scenario)");
        test.assertTrue(scrap == 18, "Player has 18 scrap (saved scenario)");
    }, 50);
}

// Auto-register
static TestFramework::TestRegistrar _("SavedScenario", SavedScenarioTest, "SavedGame", 
 TestFramework::ScenarioParams().setString("saveName", "hull-28-scrap-18"));


