#ifdef HYPERSPACE_TESTING

#include "../Global.h"
#include "utils/TestUtils.h"
#include <cstdlib>
#include <string>

/**
 * FTL Hyperspace Testing Framework (Single Hook Version)
 *
 * This version centralizes all testing logic into the CApp::OnLoop hook,
 * eliminating the need for MainMenu::OnLoop.
 *
 * Behavior:
 * - Waits for the main menu to open before starting tests
 * - Runs all registered tests asynchronously
 * - Exits automatically when tests finish
 */

// ============================================
// CONFIGURATION
// ============================================

static bool initAutoTest()
{
    const char* envVar = std::getenv("HYPERSPACE_AUTO_TEST");
    return envVar != nullptr && std::string(envVar) == "1";
}

static std::string initTestName()
{
    const char* envVar = std::getenv("HYPERSPACE_TEST_NAME");
    return envVar != nullptr ? std::string(envVar) : "";
}

static const bool ENABLE_AUTO_TEST = initAutoTest();
static const std::string TEST_NAME_FILTER = initTestName();

// ============================================
// TEST STATE
// ============================================

static bool setupStarted = false;
static bool setupComplete = false;
static bool testsComplete = false;

// ============================================
// START TESTS
// ============================================

void StartAllTests()
{
    if (testsComplete) return;

    if (!TEST_NAME_FILTER.empty())
    {
        hs_log_file(("[TEST] Starting single test: " + TEST_NAME_FILTER + "\n").c_str());
    }
    else
    {
        hs_log_file("[TEST] Starting all tests asynchronously...\n");
    }

    TestFramework::Registry::getInstance().startTests(TEST_NAME_FILTER);
}

// ============================================
// MAIN TEST LOOP (HOOK)
// ============================================

HOOK_METHOD(CApp, OnLoop, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CApp::OnLoop -> Begin (TestScript.cpp)\n");
    super();

    if (!ENABLE_AUTO_TEST || testsComplete) return;

    try
    {
        // Wait until main menu is open before setup
        if (!setupComplete)
        {
            if (G_->GetCApp()->menu.bOpen && !setupStarted)
            {
                setupStarted = true;
                setupComplete = true;

                hs_log_file("\n");
                hs_log_file("========================================\n");
                hs_log_file("  HYPERSPACE TEST FRAMEWORK\n");
                hs_log_file("========================================\n");
                hs_log_file("[SETUP] Main menu ready, starting tests...\n");

                StartAllTests();
            }
            return;
        }

        // Tick test registry every frame after setup
        TestFramework::Registry::getInstance().tick();

        if (TestFramework::Registry::getInstance().isComplete())
        {
            hs_log_file("[TEST] All tests complete, exiting...\n");
            testsComplete = true;
            exit(0);
        }
    }
    catch (const std::exception& e)
    {
        hs_log_file(("[TEST ERROR] Exception during test tick: " + std::string(e.what()) + "\n").c_str());
        testsComplete = true;
        exit(1);
    }
}

#endif // HYPERSPACE_TESTING