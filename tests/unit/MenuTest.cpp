

#include "../utils/TestUtils.h"
#include "../../Global.h"

/**
 * Unit Test: Menu Test
 * 
 * Test basic menu scenario to ensure menu opens without crashing.
 */

static void RunMenuTest(TestFramework::Test& test, TestFramework::TestStages& stages)
{
    test.section("MenuTest");

}

// Auto-register
static TestFramework::TestRegistrar _menuTest("MenuTest", RunMenuTest, "MainMenu");


