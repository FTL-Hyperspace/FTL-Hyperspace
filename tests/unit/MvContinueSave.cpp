#include "../utils/TestUtils.h"
#include "../../Global.h"



static void MvContinueSaveTest(TestFramework::Test& test, TestFramework::TestStages& stages)
{
    test.section("Mv Continue Save Test");

    // Verify starting state
    stages.addStage("Verify starting state", [&test]() {
        test.assertTrue(GameAccess::State::getPlayerHull() > 0, "Player has positive hull");
        test.assertTrue(GameAccess::State::getPlayerScrap() >= 0, "Player has valid scrap count");
    }, 0);


    // Take screenshot
    stages.addStage("Take screenshot", [&test]() {
        if (!TestHelpers::takeScreenshot("mv-continue-1.bmp"))
        {
            test.fail("Screenshot", "Failed to capture screenshot");
        }
    }, 30);
}

// Auto-register (commented out - for MV testing)
static TestFramework::TestRegistrar _("MvContinueSave", MvContinueSaveTest, "SavedGame",
    TestFramework::ScenarioParams().setString("saveName", "mv-continue-1"));
