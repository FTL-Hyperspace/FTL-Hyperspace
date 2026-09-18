#include "../utils/framework/ScenarioRegistry.h"
#include "../utils/game_access/State.h"

/**
 * Main Menu Scenario
 *
 * Ensures test starts at the main menu (no game running)
 * No parameters needed.
 */

static void setupMainMenu(TestFramework::Test* test, TestFramework::TestStages* stages, const TestFramework::ScenarioParams& params)
{
    test->section("Scenario: Main Menu");

    // Verify we're at main menu
    stages->addStage("Verify main menu state", [test]() {
        test->requireTrue(GameAccess::State::isInMenu(), "At main menu");
        test->log("Main menu scenario ready");
    }, 30);
}

// Auto-register this scenario
static TestFramework::ScenarioRegistrar _mainMenuScenario("MainMenu", setupMainMenu);
