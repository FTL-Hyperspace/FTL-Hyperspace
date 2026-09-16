#include "../utils/TestUtils.h"
#include "../../Global.h"
#include "../../CustomEvents.h"

/**
 * Test: Hull Repair Reward Window
 *
 * Verifies hull repair is clamped to 0 when hull is already full.
 * Uses RunCommand("EVENT ...") to go through the full game code path.
 */

static void HullRepairRewardTest(TestFramework::Test& test, TestFramework::TestStages& stages)
{
    test.section("Hull Repair Reward Window Test");

    stages.addStage("Verify game started", [&test]() {
        test.assertTrue(GameAccess::State::isInGame(), "Game is running");
        test.requireNotNull(GameAccess::State::getPlayerShip(), "Player ship exists");
    }, 0);

    stages.addStage("Verify hull is full", [&test]() {
        ShipManager* ship = G_->GetShipManager(0);
        test.requireNotNull(ship, "Player ship accessible");
        test.requireEquals(ship->ship.hullIntegrity.first, ship->ship.hullIntegrity.second, "Hull is at maximum");
    }, 0);

    stages.addStage("Register hull repair event", [&test]() {
        static bool registered = false;
        if (registered) return;

        EventTemplate* event = new EventTemplate();
        event->text.data = "Test hull repair event";
        event->text.isLiteral = true;
        event->eventName = "TEST_HULL_REPAIR_EVENT";

        EventDamage damage;
        damage.system = -1;
        damage.amount = -30;
        damage.effect = 0;
        event->damage.push_back(damage);

        G_->GetEventGenerator()->events["TEST_HULL_REPAIR_EVENT"] = event;
        registered = true;
    }, 0);

    stages.addStage("Load hull repair event", [&test]() {
        CommandGui* gui = GameAccess::State::getCommandGui();
        test.requireNotNull(gui, "CommandGui available");

        std::string cmd = "EVENT TEST_HULL_REPAIR_EVENT";
        gui->RunCommand(cmd);
    }, 50);

    stages.addStage("Verify hull repair is clamped", [&test]() {
        CommandGui* gui = GameAccess::State::getCommandGui();
        test.requireNotNull(gui, "CommandGui available");
        test.assertTrue(gui->choiceBox.bOpen, "Dialogue is open");

        int hullDamage = gui->choiceBox.rewards.hullDamage;
        test.log("hullDamage: " + std::to_string(hullDamage));
        test.assertTrue(hullDamage == 0, "Hull repair should be 0 when hull is full");
    }, 0);

    stages.addStage("Close dialogue", [&test]() {
        CommandGui* gui = GameAccess::State::getCommandGui();
        if (gui->choiceBox.bOpen)
        {
            gui->choiceBox.KeyDown(SDLK_1);
        }
    }, 10);
}

static TestFramework::TestRegistrar _("HullRepairReward", HullRepairRewardTest, "NewGameSeeded");
