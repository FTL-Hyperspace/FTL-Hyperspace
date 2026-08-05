#include "../utils/framework/ScenarioRegistry.h"
#include "../utils/game_access/State.h"
#include "../utils/game_access/Saves.h"
#include "../../Global.h"

/**
 * Saved Game Scenario
 *
 * Loads a saved game from the test saves folder.
 *
 * Parameters:
 *   - saveName (string): Name of the save folder (required)
 */

static void setupSavedGame(TestFramework::Test* test, TestFramework::TestStages* stages, const TestFramework::ScenarioParams& params)
{
    test->section("Scenario: Saved Game");

    // Get save name parameter (required)
    const std::string saveName = params.getString("saveName", "");

    if (saveName.empty())
    {
        throw std::invalid_argument("SavedGame scenario requires 'saveName' parameter");
    }

    // Stage 1: Load save folder and reopen menu
    stages->addStage("Load save folder", [test, saveName]() {
        bool loaded = GameAccess::Saves::loadTestSave(saveName);
        test->requireTrue(loaded, "Save folder set successfully");
        test->log("Save folder set to: " + saveName);
    }, 30);

    // Stage 2: Click continue button
    stages->addStage("Click continue", [test]() {
        MainMenu* menu = &G_->GetCApp()->menu;
        test->requireNotNull(menu, "Main menu is available");
        if (!menu->continueButton.bActive){
            test->skip("Save not available for this modpack.");
            return;
        }

        // Click a button using a safe utility
        GameAccess::State::clickButton(&menu->continueButton);
        test->log("Continue button clicked");
    }, 30);

    // Stage 3: Verify game started
    stages->addStage("Verify game started", [test]() {
        test->requireTrue(GameAccess::State::isInGame(), "Game started successfully");
        test->log("Game is running");
    }, 0);

    // Stage 4: Verify player ship exists
    stages->addStage("Verify player ship", [test]() {
        ShipManager* ship = GameAccess::State::getPlayerShip();
        test->requireNotNull(ship, "Player ship exists");
        // verify hull at least 1
        int hull = GameAccess::State::getPlayerHull();
        test->requireTrue(hull > 0, "Player ship has positive hull");
    }, 0);

    test->log("Saved game scenario ready with save: " + saveName);
}

// Auto-register this scenario
static TestFramework::ScenarioRegistrar _savedGameScenario(
    "SavedGame",
    setupSavedGame,
    TestFramework::ScenarioParams()
);
