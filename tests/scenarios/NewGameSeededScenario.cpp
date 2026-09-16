#include "../utils/framework/ScenarioRegistry.h"
#include "../utils/game_access/Saves.h"
#include "../utils/TestUtils.h"
#include "../../Global.h"
#include <cstdlib>

/**
 * New Game Seeded Scenario
 *
 * Starts a new game with deterministic seed for reproducible tests.
 *
 * Parameters:
 *   - seed (int): RNG seed value (default: 12345)
 */

static void setupNewGameSeeded(TestFramework::Test* test, TestFramework::TestStages* stages, const TestFramework::ScenarioParams& params)
{
    test->section("Scenario: New Game Seeded");

    const int randomSeed = rand() % 100000;

    // Get seed parameter (default randomSeed)
    const int seed = params.getInt("seed", randomSeed);


    stages->addStage("Set custom save", [test, seed]() {
        const int randName = rand() % 100000;
        const std::string saveName = "NewGameSeeded_" + std::to_string(randName);
        // create save folder
        GameAccess::Saves::createNewSave(saveName);
        GameAccess::Saves::loadTestSave(saveName); // creates new save folder
        test->log("Created new save folder: " + saveName);
    }, 30);


    // Stage 1: Open ship builder
    stages->addStage("Open ship builder", [test]() {
        ShipBuilder* shipBuilder = GameAccess::State::getShipBuilder();
        test->requireNotNull(shipBuilder, "ShipBuilder is accessible");
        shipBuilder->Open();
        test->log("ShipBuilder opened");
    }, 10); // Wait 0.5 seconds

    // Stage 2: Set seed and finish
    stages->addStage("Set seed and start game", [test, seed]() {
        ShipBuilder* shipBuilder = GameAccess::State::getShipBuilder();
        test->requireNotNull(shipBuilder, "ShipBuilder still accessible");

        // Set seed between Open() and Finish()
        GameAccess::Seeding::setSeed(seed);
        test->log("Seed " + std::to_string(seed) + " set");

        // Finish to start the game
        shipBuilder->Finish();
        test->log("ShipBuilder finished - game starting");
    }, 30); // Wait 0.5 seconds

    // Stage 3: Verify game started
    stages->addStage("Verify game started", [test]() {
        test->requireTrue(GameAccess::State::isInGame(), "Game started successfully");
        test->log("Game is running");
    }, 0);

    // Stage 4: Verify player ship exists
    stages->addStage("Verify player ship", [test]() {
        ShipManager* ship = GameAccess::State::getPlayerShip();
        test->requireNotNull(ship, "Player ship exists");
        test->log("Player ship initialized");
    }, 10);

    // Close dialogues with specified key presses
    static const SDLKey dialogueKeys[] = {
        // FTL Hyperspace choice.
        SDLK_1,
        // Extra dialogues for Multiverse tests.
        SDLK_1, SDLK_1, SDLK_1, SDLK_4, SDLK_1, SDLK_2};

    for (int i = 0; i < 7; i++)
    {
        SDLKey key = dialogueKeys[i];
        stages->addStage("Close dialogue " + std::to_string(i + 1), [test, key]() {
            CommandGui* gui = GameAccess::State::getCommandGui();
            test->requireNotNull(gui, "CommandGui is accessible");

            if (gui->choiceBox.bOpen && !gui->choiceBox.choiceBoxes.empty())
            {
                gui->choiceBox.KeyDown(key);
                test->pass("Pressed key for dialogue choice");
            }
            else
            {
                test->pass("No dialogue to close");
            }
        }, 5);
    }
    

    test->log("New game seeded scenario ready");
}

// Auto-register this scenario with default seed
static TestFramework::ScenarioRegistrar _newGameSeededScenario(
    "NewGameSeeded",
    setupNewGameSeeded,
    TestFramework::ScenarioParams()
);
