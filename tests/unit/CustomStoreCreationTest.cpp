
#include "../utils/TestUtils.h"
#include "../../Global.h"
#include "../../CustomStore.h"

/**
 * Unit Test: Custom Store Creation
 *
 * Tests that custom stores can be created without crashing
 * Creates a minimal custom store definition programmatically
 */

static Store* createdStore = nullptr;

static void RunCustomStoreCreationTest(TestFramework::Test& test, TestFramework::TestStages& stages)
{
    test.section("Custom Store Creation Test");



    // Verify dialogue closed
    stages.addStage("Verify dialogue closed", [&test]() {
        CommandGui* gui = GameAccess::State::getCommandGui();
        test.requireNotNull(gui, "CommandGui is accessible");
        test.assertFalse(gui->choiceBox.bOpen, "Dialogue is closed");
    }, 10);

    // Register a custom store definition with various items
    stages.addStage("Create custom store", [&test]() {
        CommandGui* gui = GameAccess::State::getCommandGui();
        test.requireNotNull(gui, "CommandGui is accessible");

        StoreDefinition testStoreDef;
        testStoreDef.purchaseLimit = 10;

        // Hull repair
        testStoreDef.hullRepair.visible = true;
        testStoreDef.hullRepair.price.price = 3;

        // Resources: fuel and missiles
        ResourceItem fuel;
        fuel.type = "fuel";
        fuel.minMaxCount = {3, 5};
        fuel.price.price = 3;
        testStoreDef.resources.push_back(fuel);

        ResourceItem missiles;
        missiles.type = "missiles";
        missiles.minMaxCount = {2, 4};
        missiles.price.price = 6;
        testStoreDef.resources.push_back(missiles);

        ResourceItem droneParts;
        droneParts.type = "drones";
        droneParts.minMaxCount = {1, 3};
        droneParts.price.price = 8;
        testStoreDef.resources.push_back(droneParts);

        // Weapons category (empty blueprint = random from default pool)
        StoreCategory weaponsCat;
        weaponsCat.categoryType = CategoryType::WEAPONS;
        weaponsCat.chance = 100;
        StoreItem weapon1, weapon2;
        weapon1.blueprint = ""; // Random weapon
        weapon2.blueprint = ""; // Random weapon
        weaponsCat.items.push_back(weapon1);
        weaponsCat.items.push_back(weapon2);
        testStoreDef.categories[-1].push_back(weaponsCat);

        // Drones category
        StoreCategory dronesCat;
        dronesCat.categoryType = CategoryType::DRONES;
        dronesCat.chance = 100;
        StoreItem drone1;
        drone1.blueprint = ""; // Random drone
        dronesCat.items.push_back(drone1);
        testStoreDef.categories[-1].push_back(dronesCat);

        // Crew category
        StoreCategory crewCat;
        crewCat.categoryType = CategoryType::CREW;
        crewCat.chance = 100;
        StoreItem crew1;
        crew1.blueprint = ""; // Random crew
        crewCat.items.push_back(crew1);
        testStoreDef.categories[-1].push_back(crewCat);

        // Augments category
        StoreCategory augmentsCat;
        augmentsCat.categoryType = CategoryType::AUGMENTS;
        augmentsCat.chance = 100;
        StoreItem aug1;
        aug1.blueprint = ""; // Random augment
        augmentsCat.items.push_back(aug1);
        testStoreDef.categories[-1].push_back(augmentsCat);

        // Systems category
        StoreCategory systemsCat;
        systemsCat.categoryType = CategoryType::SYSTEMS;
        systemsCat.chance = 100;
        StoreItem sys1;
        sys1.blueprint = ""; // Random system
        systemsCat.items.push_back(sys1);
        testStoreDef.categories[-1].push_back(systemsCat);

        // Register the store definition
        CustomStore::instance->RegisterStoreDefinition("TEST_STORE", testStoreDef);

        // Force custom store creation
        CustomStore::instance->forceCustomStore = "TEST_STORE";
        createdStore = gui->CreateNewStore(1);

        test.requireNotNull(createdStore, "Store was created");
        test.pass("Custom store created with resources, weapons, drones, and crew");
    }, 10);
    

    // Open store
    stages.addStage("Open custom store", [&test]() {
        CommandGui* gui = GameAccess::State::getCommandGui();
        gui->storeButton.OnClick();
    }, 10);

    // Verify it's a custom store
    stages.addStage("Verify custom store", [&test]() {
        test.requireNotNull(createdStore, "Store pointer is valid");

        bool isCustom = STORE_EX(createdStore)->isCustomStore;
        test.assertTrue(isCustom, "Store is a custom store");
    }, 10);

    // Take screenshot
    stages.addStage("Take screenshot of custom store", [&test]() {
        if (!TestHelpers::takeScreenshot("custom_store_test.bmp"))
        {
            test.fail("Screenshot", "Failed to capture screenshot");
        }
    }, 30);

    // Close the store through CommandGui
    stages.addStage("Close custom store", [&test]() {
        CommandGui* gui = GameAccess::State::getCommandGui();
        test.requireNotNull(gui, "CommandGui is accessible");

        // Close the store screens (TabbedWindow containing the store)
        gui->storeScreens.Close();
        test.pass("Store closed via CommandGui");
    }, 10);

    // Cleanup global state
    stages.addStage("Cleanup", [&test]() {
        CustomStore::instance->UnregisterStoreDefinition("TEST_STORE");
        CustomStore::instance->forceCustomStore = "";
        createdStore = nullptr;
        test.pass("Cleanup completed");
    }, 0);
}

// Auto-register
static TestFramework::TestRegistrar _customStoreCreationTest("CustomStoreCreation", RunCustomStoreCreationTest, "NewGameSeeded");
