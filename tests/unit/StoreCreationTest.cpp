

#include "../utils/TestUtils.h"
#include "../../Global.h"

/**
 * Unit Test: Store Creation
 *
 * Tests that stores can be created without crashing
 * This was the original macOS Sequoia bug with memory protection
 */

static void RunStoreCreationTest(TestFramework::Test& test, TestFramework::TestStages& stages)
{
    test.section("Store Creation Test");



    // Verify dialogue closed
    stages.addStage("Verify dialogue closed", [&test]() {
        CommandGui* gui = GameAccess::State::getCommandGui();
        test.requireNotNull(gui, "CommandGui is accessible");
        test.assertFalse(gui->choiceBox.bOpen, "Dialogue is closed");
    }, 10); // Wait 0.5 seconds

    // Create store
    stages.addStage("Create store", [&test]() {
        CommandGui* gui = GameAccess::State::getCommandGui();
        test.requireNotNull(gui, "CommandGui is accessible");
        gui->CreateNewStore(1);
    }, 10); // Wait 0.5 seconds

    // Open store
    stages.addStage("Open store", [&test]() {
        CommandGui* gui = GameAccess::State::getCommandGui();
        gui->storeButton.OnClick();
    }, 10); // Wait 0.5 seconds for store to render

    // Take screenshot
    stages.addStage("Take screenshot of store", [&test]() {
        if (!TestHelpers::takeScreenshot("store_test.bmp"))
        {
            test.fail("Screenshot", "Failed to capture screenshot");
        }
    }, 0);

    // close store
    stages.addStage("Close store", [&test]() {
        CommandGui* gui = GameAccess::State::getCommandGui();
        test.requireNotNull(gui, "CommandGui is accessible");

        // Close the store screens (TabbedWindow containing the store)
        gui->storeScreens.Close();
        test.pass("Store closed via CommandGui");
    }, 10); // Wait 0.5 seconds
}

// Auto-register
static TestFramework::TestRegistrar _storeCreationTest("StoreCreation", RunStoreCreationTest, "NewGameSeeded");


