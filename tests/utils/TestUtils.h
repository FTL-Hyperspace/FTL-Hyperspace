#pragma once

/**
 * FTL Hyperspace Test Utilities - Public API
 *
 * Self-documenting test framework with organized namespaces:
 *
 * NAMESPACES:
 *
 * TestFramework - Core testing infrastructure
 *   - Core: Exceptions and foundation types
 *   - Logger: Low-level logging infrastructure
 *   - Test: High-level test API (assertions, logging, pass/fail)
 *   - TestStages: Stage-based async test execution
 *   - Registry: Test registration and orchestration
 *   - ScenarioRegistry: Auto-registration system for scenarios
 *   - ScenarioParams: Parameter container for scenarios
 *   - FrameWaiter: Frame timing utilities
 *   - ResultsAggregator: Result aggregation and JSON reporting
 *
 * GameAccess - Game state interaction
 *   - State: Access game objects and modify resources
 *   - Saves: Manage test save files
 *   - Seeding: Deterministic RNG testing
 *
 * TestHelpers - High-level utilities
 *   - Screenshots, tick counting, etc.
 *
 * SCENARIOS:
 *
 * Tests specify a scenario by name. Available scenarios auto-register themselves:
 *   - "MainMenu": Start at main menu (no game running)
 *   - "NewGameSeeded": Start a new game with deterministic seed (default seed: 12345)
 *
 * Scenarios can accept parameters. New scenarios are added by creating files in tests/scenarios/
 * with no central code changes needed.
 *
 * USAGE EXAMPLES:
 *
 * #include "utils/TestUtils.h"
 *
 * void MyTest(TestFramework::Test& test, TestFramework::TestStages& stages)
 * {
 *     test.section("My Test");
 *
 *     // Scenario already initialized the game, just add test-specific stages
 *     stages.addStage("Check player", [&test]() {
 *         test.requireNotNull(GameAccess::State::getPlayerShip(), "Player ship exists");
 *         test.assertTrue(GameAccess::State::getPlayerHull() > 0, "Player has hull");
 *     });
 * }
 *
 * // Register with scenario (default params)
 * static TestFramework::TestRegistrar myTest("MyTest", MyTest, "NewGameSeeded");
 *
 * // Or override scenario parameters
 * static TestFramework::TestRegistrar myTest2("MyTest2", MyTest, "NewGameSeeded",
 *     TestFramework::ScenarioParams().setInt("seed", 99999));
 */

// TestFramework namespace - Core testing infrastructure
#include "framework/Core.h"
#include "framework/FileSystem.h"
#include "framework/Logger.h"
#include "framework/TestResultTracker.h"
#include "framework/Test.h"
#include "framework/Stages.h"
#include "framework/Registry.h"
#include "framework/ScenarioParams.h"
#include "framework/ScenarioRegistry.h"
#include "framework/FrameWaiter.h"
#include "framework/Results.h"

// GameAccess namespace - Game state interaction
#include "game_access/State.h"
#include "game_access/Saves.h"
#include "game_access/Seeding.h"

// TestHelpers namespace - High-level utilities
#include "helpers/Helpers.h"
