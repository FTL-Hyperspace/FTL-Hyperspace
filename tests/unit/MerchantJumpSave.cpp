#include "../utils/TestUtils.h"
#include "../../Global.h"
#include "../../Store_Extend.h"

/**
 * Integration Test: Merchant Jump Save to be used with Multiverse mod (will be moved to MV tests folder)
 *
 * Tests loading a save and jumping to a merchant beacon.
 * Uses the SavedGame scenario with mv-merchant save.
 */

static void MerchantJumpSaveTest(TestFramework::Test& test, TestFramework::TestStages& stages)
{
    test.section("Merchant Jump Save Test");

    // Verify starting state
    stages.addStage("Verify starting state", [&test]() {
        test.assertTrue(GameAccess::State::getPlayerHull() > 0, "Player has positive hull");
        test.assertTrue(GameAccess::State::getPlayerScrap() >= 0, "Player has valid scrap count");
    }, 0);

    // Open star map
    stages.addStage("Open star map", [&test]() {
        StarMap* starMap = GameAccess::State::getStarMap();
        test.requireNotNull(starMap, "StarMap is available");

        starMap->Open();
        test.log("Called starMap->Open()");
        test.log("bOpen: " + std::to_string(starMap->bOpen));
    }, 50);

    // Find and select merchant beacon
    stages.addStage("Select merchant beacon", [&test]() {
        StarMap* starMap = GameAccess::State::getStarMap();
        test.requireNotNull(starMap, "StarMap still available");

        Location* currentLoc = starMap->currentLoc;
        test.requireNotNull(currentLoc, "Current location exists");

        // Log all connected locations with screen coordinates
        test.log("Connected locations from current (with screen coords):");
        int idx = 0;
        for (auto& loc : currentLoc->connectedLocations)
        {
            int screenX = starMap->position.x + (int)loc->loc.x;
            int screenY = starMap->position.y + (int)loc->loc.y;
            std::string info = "  [" + std::to_string(idx) + "] ";
            info += "screen=(" + std::to_string(screenX) + "," + std::to_string(screenY) + ")";
            info += ", visited=" + std::to_string(loc->visited);
            if (loc->event)
            {
                info += ", store=" + std::to_string(loc->event->store);
            }
            test.log(info);
            idx++;
        }

        // Also log current location screen pos
        int curX = starMap->position.x + (int)currentLoc->loc.x;
        int curY = starMap->position.y + (int)currentLoc->loc.y;
        test.log("Current loc screen: (" + std::to_string(curX) + "," + std::to_string(curY) + ")");

        // Select location index 4 (merchant beacon in mv-merchant save)
        int merchantIndex = 4;
        test.requireTrue(currentLoc->connectedLocations.size() > merchantIndex,
            "Location index " + std::to_string(merchantIndex) + " exists");

        Location* merchantLoc = currentLoc->connectedLocations[merchantIndex];
        test.log("Selecting merchant beacon at index " + std::to_string(merchantIndex));

        // Need position + translation + loc to get screen coordinates
        int clickX = starMap->position.x + (int)starMap->translation.x + (int)merchantLoc->loc.x;
        int clickY = starMap->position.y + (int)starMap->translation.y + (int)merchantLoc->loc.y;
        test.log("Will click at: (" + std::to_string(clickX) + "," + std::to_string(clickY) + ")");

        // Draw debug marker and screenshot
        GL_Color red = {1.0f, 0.0f, 0.0f, 1.0f};
        CSurface::GL_DrawRect(clickX - 5, clickY - 5, 10, 10, red);
        TestHelpers::takeScreenshot("click_debug.bmp");

        // Now click through CommandGui
        CommandGui* gui = GameAccess::State::getCommandGui();
        gui->MouseMove(clickX, clickY);
        gui->LButtonDown(clickX, clickY, false);
        test.log("Clicked on location");
    }, 300);

    // Press key 1
    stages.addStage("Press key 1", [&test]() {
        CommandGui* gui = GameAccess::State::getCommandGui();
        test.requireNotNull(gui, "CommandGui is available");
        test.requireTrue(gui->choiceBox.bOpen, "Choice box is open");

        gui->choiceBox.KeyDown(SDLK_1);
        test.log("Pressed key 1");
    }, 50);

    // Press key 1 again
    stages.addStage("Press key 1 again", [&test]() {
        CommandGui* gui = GameAccess::State::getCommandGui();
        test.requireNotNull(gui, "CommandGui is available");
        test.requireTrue(gui->choiceBox.bOpen, "Choice box is open");

        gui->choiceBox.KeyDown(SDLK_1);
        test.log("Pressed key 1 again");
    }, 50);

    // Press key 1 (third time)
    stages.addStage("Press key 1 (third time)", [&test]() {
        CommandGui* gui = GameAccess::State::getCommandGui();
        test.requireNotNull(gui, "CommandGui is available");
        test.requireTrue(gui->choiceBox.bOpen, "Choice box is open");

        gui->choiceBox.KeyDown(SDLK_1);
    }, 50);

    // Take screenshot
    stages.addStage("Take screenshot", [&test]() {
        if (!TestHelpers::takeScreenshot("merchant_jump_test.bmp"))
        {
            test.fail("Screenshot", "Failed to capture screenshot");
        }
    }, 30);

    // Log all store items
    stages.addStage("Log all store items", [&test]() {
        CommandGui* gui = GameAccess::State::getCommandGui();
        test.requireNotNull(gui, "CommandGui is available");

        // Get the store from the tabbed window using current tab
        test.requireTrue(gui->storeScreens.windows.size() > 0, "Store windows exist");
        test.requireTrue(gui->storeScreens.currentTab < gui->storeScreens.windows.size(), "Current tab is valid");

        Store* store = static_cast<Store*>(gui->storeScreens.windows[gui->storeScreens.currentTab]);
        test.requireNotNull(store, "Store is available");

        test.log("\n========== STORE INVENTORY ==========");
        test.log("Current tab: " + std::to_string(gui->storeScreens.currentTab));
        test.log("Total windows: " + std::to_string(gui->storeScreens.windows.size()));
        test.log("Store screens open: " + std::to_string(gui->storeScreens.bOpen));
        test.log("Store world level: " + std::to_string(store->worldLevel));
        test.log("Store section count: " + std::to_string(store->sectionCount));
        test.log("Store page1 active: " + std::to_string(store->page1.bActive));
        test.log("Store page2 active: " + std::to_string(store->page2.bActive));
        test.log("Store show page2: " + std::to_string(store->bShowPage2));

        // Log store types
        test.log("Store types: [" +
            std::to_string(store->types[0]) + ", " +
            std::to_string(store->types[1]) + ", " +
            std::to_string(store->types[2]) + ", " +
            std::to_string(store->types[3]) + "]");

        // Check if it's a custom store
        auto storeEx = STORE_EX(store);
        test.log("Is custom store: " + std::to_string(storeEx->isCustomStore));

        if (storeEx->isCustomStore && storeEx->customStore)
        {
            test.log("\n--- CUSTOM STORE ---");
            auto& pages = storeEx->customStore->GetPages();
            test.log("Total pages: " + std::to_string(pages.size()));

            // Count total boxes and validate blueprints
            int totalBoxes = 0;
            for (auto& page : pages)
            {
                for (auto& section : page.sections)
                {
                    for (auto& boxRow : section.storeBoxes)
                    {
                        totalBoxes += boxRow.size();
                    }
                }
            }
            test.requireTrue(totalBoxes == 6, "Store has exactly 6 boxes (found " + std::to_string(totalBoxes) + ")");

            // Log all pages and sections
            for (int pageIdx = 0; pageIdx < pages.size(); pageIdx++)
            {
                auto& page = pages[pageIdx];
                test.log("\n--- Page " + std::to_string(pageIdx) + " (" + std::to_string(page.sections.size()) + " sections) ---");

                for (int secIdx = 0; secIdx < page.sections.size(); secIdx++)
                {
                    auto& section = page.sections[secIdx];
                    std::string catName;
                    switch(section.category)
                    {
                        case CategoryType::WEAPONS: catName = "WEAPONS"; break;
                        case CategoryType::DRONES: catName = "DRONES"; break;
                        case CategoryType::AUGMENTS: catName = "AUGMENTS"; break;
                        case CategoryType::CREW: catName = "CREW"; break;
                        case CategoryType::SYSTEMS: catName = "SYSTEMS"; break;
                    }

                    test.log("  Section " + std::to_string(secIdx) + " - " + catName);
                    if (!section.customTitle.empty())
                    {
                        test.log("    Custom title: " + section.customTitle);
                    }

                    test.log("    Total boxRows: " + std::to_string(section.storeBoxes.size()));

                    // Log all items in this section
                    int rowIdx = 0;
                    for (auto& boxRow : section.storeBoxes)
                    {
                        test.log("    BoxRow " + std::to_string(rowIdx) + " has " + std::to_string(boxRow.size()) + " items");
                        for (auto* customBox : boxRow)
                        {
                            test.requireNotNull(customBox, "CustomBox is not null");
                            test.requireNotNull(customBox->orig, "CustomBox->orig is not null");
                            test.requireNotNull(customBox->orig->pBlueprint, "Blueprint is not null");

                            auto* blueprint = customBox->orig->pBlueprint;
                            std::string logEntry = "      Item: " + blueprint->name;
                            logEntry += ", Cost: " + std::to_string(customBox->orig->desc.cost);

                            if (customBox->showSale)
                            {
                                logEntry += ", Original: " + std::to_string(customBox->originalPrice) + " (SALE)";
                            }

                            if (customBox->mysteryItem)
                            {
                                logEntry += " (MYSTERY)";
                            }

                            if (!blueprint->desc.title.data.empty())
                            {
                                logEntry += ", Title: " + blueprint->desc.title.data;
                            }

                            test.log(logEntry);
                        }
                        rowIdx++;
                    }
                }
            }

            test.pass("Custom store inventory logged");
            return;
        }

        // Vanilla store logging
        test.log("\n--- VANILLA STORE ---");

        // Log all store boxes
        test.log("\n--- All Store Boxes (" + std::to_string(store->vStoreBoxes.size()) + ") ---");
        int boxIndex = 0;
        for (auto* box : store->vStoreBoxes)
        {
            if (!box) continue;

            std::string logEntry = "[" + std::to_string(boxIndex) + "] ";

            if (box->pBlueprint)
            {
                logEntry += "Name: " + box->pBlueprint->name;
                logEntry += ", Cost: " + std::to_string(box->pBlueprint->desc.cost);
                logEntry += ", Type: " + std::to_string(box->pBlueprint->type);

                // Try to get title if available
                if (!box->pBlueprint->desc.title.data.empty())
                {
                    logEntry += ", Title: " + box->pBlueprint->desc.title.data;
                }
            }
            else
            {
                logEntry += "No blueprint";
            }

            test.log(logEntry);
            boxIndex++;
        }

        // Log item boxes specifically
        test.log("\n--- Item Boxes (" + std::to_string(store->vItemBoxes.size()) + ") ---");
        int itemIndex = 0;
        for (auto* box : store->vItemBoxes)
        {
            if (!box) continue;

            std::string logEntry = "[" + std::to_string(itemIndex) + "] ";

            if (box->pBlueprint)
            {
                logEntry += "Name: " + box->pBlueprint->name;
                logEntry += ", Cost: " + std::to_string(box->pBlueprint->desc.cost);

                // Check if it's a weapon, drone, augment, or crew by type
                int bpType = box->pBlueprint->type;
                std::string typeStr;
                switch(bpType)
                {
                    case 0: typeStr = "Weapon"; break;
                    case 1: typeStr = "Drone"; break;
                    case 2: typeStr = "Augment"; break;
                    case 3: typeStr = "Crew"; break;
                    case 4: typeStr = "System"; break;
                    default: typeStr = "Unknown(" + std::to_string(bpType) + ")"; break;
                }
                logEntry += ", Type: " + typeStr;

                if (!box->pBlueprint->desc.title.data.empty())
                {
                    logEntry += ", Title: " + box->pBlueprint->desc.title.data;
                }

                if (!box->pBlueprint->desc.description.data.empty())
                {
                    logEntry += ", Desc: " + box->pBlueprint->desc.description.data;
                }
            }
            else
            {
                logEntry += "No blueprint (possibly resource or hull repair)";
            }

            test.log(logEntry);
            itemIndex++;
        }

        test.log("\n========== END STORE INVENTORY ==========\n");
        test.pass("Logged all store items");
    }, 10);

    // Close store
    stages.addStage("Close store", [&test]() {
        CommandGui* gui = GameAccess::State::getCommandGui();
        test.requireNotNull(gui, "CommandGui is available");

        gui->storeScreens.Close();
        test.pass("Store closed via CommandGui");
    }, 10);
}

// Auto-register (commented out - for MV testing)
static TestFramework::TestRegistrar _("MerchantJump", MerchantJumpSaveTest, "SavedGame",
    TestFramework::ScenarioParams().setString("saveName", "mv-merchant"));
