#include "../utils/TestUtils.h"
#include "../../Global.h"
#include "../../CustomEvents.h"

/**
 * Test: Reactor Upgrade Reward
 *
 * Verifies that an event giving 2 reactor levels actually grants them.
 */

static void ReactorUpgradeRewardTest(TestFramework::Test& test, TestFramework::TestStages& stages)
{
    test.section("Reactor Upgrade Reward Test");

    static int initialReactor = 0;

    stages.addStage("Verify game started", [&test]() {
        test.assertTrue(GameAccess::State::isInGame(), "Game is running");
        test.requireNotNull(GameAccess::State::getPlayerShip(), "Player ship exists");
    }, 0);

    stages.addStage("Record initial reactor", [&test]() {
        PowerManager* power = PowerManager::GetPowerManager(0);
        test.requireNotNull(power, "PowerManager accessible");
        initialReactor = power->currentPower.second;
        test.log("Initial reactor: " + std::to_string(initialReactor));
    }, 0);

    stages.addStage("Register reactor upgrade event", [&test]() {
        static bool registered = false;
        if (registered) return;

        EventTemplate* event = new EventTemplate();
        event->text.data = "Test reactor upgrade event";
        event->text.isLiteral = true;
        event->eventName = "TEST_REACTOR_UPGRADE_EVENT";

        // upgradeId 17 = reactor, upgradeAmount = 2
        event->resources.upgradeId = 17;
        event->resources.upgradeAmount = 2;

        G_->GetEventGenerator()->events["TEST_REACTOR_UPGRADE_EVENT"] = event;
        registered = true;
    }, 0);

    stages.addStage("Load reactor upgrade event", [&test]() {
        CommandGui* gui = GameAccess::State::getCommandGui();
        test.requireNotNull(gui, "CommandGui available");

        std::string cmd = "EVENT TEST_REACTOR_UPGRADE_EVENT";
        gui->RunCommand(cmd);
    }, 50);

    stages.addStage("Close dialogue", [&test]() {
        CommandGui* gui = GameAccess::State::getCommandGui();
        if (gui->choiceBox.bOpen)
        {
            gui->choiceBox.KeyDown(SDLK_1);
        }
    }, 10);

    stages.addStage("Verify reactor increased", [&test]() {
        PowerManager* power = PowerManager::GetPowerManager(0);
        test.requireNotNull(power, "PowerManager accessible");

        int newReactor = power->currentPower.second;
        test.log("New reactor: " + std::to_string(newReactor));
        test.log("Expected: " + std::to_string(initialReactor + 2));

        test.assertTrue(newReactor == initialReactor + 2, "Reactor should increase by 2");
    }, 0);
}

static TestFramework::TestRegistrar _("ReactorUpgradeReward", ReactorUpgradeRewardTest, "NewGameSeeded");
