#include "../utils/TestUtils.h"
#include "../../Global.h"
#include "../../CustomEvents.h"

/**
 * Test: Death Test
 *
 * Deals 30 hull damage, presses OK, waits 300 frames, then screenshots.
 */

static void DeathTest(TestFramework::Test& test, TestFramework::TestStages& stages)
{
    test.section("Death Test");

    stages.addStage("Verify game started", [&test]() {
        test.assertTrue(GameAccess::State::isInGame(), "Game is running");
        test.requireNotNull(GameAccess::State::getPlayerShip(), "Player ship exists");
    }, 0);

    stages.addStage("Register hull damage event", [&test]() {
        static bool registered = false;
        if (registered) return;

        EventTemplate* event = new EventTemplate();
        event->text.data = "Your ship takes critical damage!";
        event->text.isLiteral = true;
        event->eventName = "TEST_DEATH_DAMAGE";

        EventDamage damage;
        damage.system = -1;
        damage.amount = 30;
        damage.effect = 0;
        event->damage.push_back(damage);

        G_->GetEventGenerator()->events["TEST_DEATH_DAMAGE"] = event;
        registered = true;
    }, 0);

    stages.addStage("Load hull damage event", [&test]() {
        CommandGui* gui = GameAccess::State::getCommandGui();
        test.requireNotNull(gui, "CommandGui available");

        std::string cmd = "EVENT TEST_DEATH_DAMAGE";
        gui->RunCommand(cmd);
    }, 50);

    stages.addStage("Press OK", [&test]() {
        CommandGui* gui = GameAccess::State::getCommandGui();
        test.requireNotNull(gui, "CommandGui available");

        if (gui->choiceBox.bOpen && !gui->choiceBox.choiceBoxes.empty())
        {
            Globals::Rect& rect = gui->choiceBox.choiceBoxes[0];
            int x = rect.x + rect.w / 2;
            int y = rect.y + rect.h / 2;
            gui->choiceBox.MouseClick(x, y);
        }
    }, 50);

    stages.addStage("Wait and screenshot", [&test]() {
        TestHelpers::takeScreenshot("death_test_gameover");
        test.log("Screenshot taken after game over");
    }, 500);

    stages.addStage("Close game over dialogue", [&test]() {
        auto& gameOver = G_->GetCApp()->gui->gameOverScreen;
        if (gameOver.bOpen)
        {
            // Go to menu and close game over dialogue
            G_->GetCApp()->menu.Open();
            gameOver.Close();
            test.log("Opened menu and closed game over dialogue");
        }
    }, 50);
}

static TestFramework::TestRegistrar _("DeathTest", DeathTest, "NewGameSeeded");
