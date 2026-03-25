#include "../utils/TestUtils.h"
#include "../../Global.h"

/**
 * Test: Weapon Dialogue Display
 *
 * Tests displaying a dialogue with a weapon to isolate potential crash issues.
 * Uses NewGameSeeded scenario.
 */

static void WeaponDialogueTest(TestFramework::Test& test, TestFramework::TestStages& stages)
{
    test.section("Weapon Dialogue Test");

    // Verify game started
    stages.addStage("Verify game started", [&test]() {
        test.assertTrue(GameAccess::State::isInGame(), "Game is running");
        test.requireNotNull(GameAccess::State::getPlayerShip(), "Player ship exists");
    }, 0);

    // Create and show dialogue with weapon
    stages.addStage("Show weapon dialogue", [&test]() {
        CommandGui* gui = GameAccess::State::getCommandGui();
        test.requireNotNull(gui, "CommandGui available");

        // Get a weapon blueprint
        BlueprintManager* blueprints = G_->GetBlueprints();
        test.requireNotNull(blueprints, "BlueprintManager available");

        WeaponBlueprint* weapon = blueprints->GetWeaponBlueprint("LASER_BURST_1");
        test.requireNotNull(weapon, "Got LASER_BURST_1 blueprint");
        test.log("Weapon name: " + weapon->name);

        // Create ResourceEvent with weapon and scrap
        ResourceEvent resources = {};
        resources.weapon = weapon;
        resources.scrap = 50;

        // Create choice text
        std::vector<ChoiceText> choices;
        ChoiceText choice1(0, "Accept weapon", ResourceEvent());
        choices.push_back(choice1);

        ChoiceText choice2(0, "Decline", ResourceEvent());
        choices.push_back(choice2);

        // Show the dialogue
        std::string mainText = "A trader offers you a weapon!";
        gui->NewLocation(mainText, &choices, resources, false);
        test.log("Created weapon dialogue");
    }, 50);

    // Wait and take screenshot
    stages.addStage("Take screenshot", [&test]() {
        TestHelpers::takeScreenshot("weapon_dialogue_test.bmp");
        test.log("Screenshot taken");
    }, 20);
}

// Auto-register
static TestFramework::TestRegistrar _weaponDialogueTest("WeaponDialogue", WeaponDialogueTest, "NewGameSeeded");
