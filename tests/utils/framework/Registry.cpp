#include "Registry.h"
#include "Results.h"
#include "ScenarioRegistry.h"
#include "../game_access/State.h"
#include "../../../Global.h"
#include <algorithm>

namespace TestFramework
{
    // Helper function to report test results
    static void reportTestResults(const std::string& testName, const Test& test)
    {
        const TestResultTracker& tracker = test.getTracker();
        TestResult result;
        result.name = testName;
        result.passed = (tracker.getFailCount() == 0);
        result.duration_ms = tracker.getDuration();
        result.assertions_passed = tracker.getPassCount();
        result.assertions_failed = tracker.getFailCount();
        ResultsAggregator::getInstance().addTestResult(result);

        hs_log_file("\n[%s] Tests: %d passed, %d failed (%.2fs)\n",
            testName.c_str(), tracker.getPassCount(), tracker.getFailCount(), tracker.getDuration() / 1000.0f);
    }

    static void reportTestSkipped(const std::string& testName, const std::string& reason)
    {
        TestResult result;
        result.name = testName;
        result.passed = true;
        result.skipped = true;
        result.duration_ms = 0;
        result.assertions_passed = 0;
        result.assertions_failed = 0;
        ResultsAggregator::getInstance().addTestResult(result);

        hs_log_file("\n[%s] SKIPPED: %s\n", testName.c_str(), reason.c_str());
    }

    Registry::Registry()
        : state(State::IDLE), currentTestIndex(0), currentTest(nullptr),
          currentStages(nullptr), waitCounter(0)
    {
    }

    Registry& Registry::getInstance()
    {
        static Registry instance;
        return instance;
    }

    void Registry::registerTest(const std::string& name, TestFunc func, const std::string& scenarioName, const ScenarioParams& scenarioParams)
    {
        tests.push_back({name, func, scenarioName, scenarioParams});
    }

    void Registry::startTests(const std::string& testNameFilter)
    {
        hs_log_file("\n========================================\n");
        hs_log_file("  STARTING TEST SUITE\n");

        if (!testNameFilter.empty())
        {
            hs_log_file(("  Mode: Single Test (" + testNameFilter + ")\n").c_str());

            // Filter tests to only include the requested test
            auto it = std::find_if(tests.begin(), tests.end(),
                [&testNameFilter](const TestInfo& test) {
                    return test.name == testNameFilter;
                });

            if (it != tests.end())
            {
                // Keep only the matching test
                TestInfo matchedTest = *it;
                tests.clear();
                tests.push_back(matchedTest);
                hs_log_file("  Tests: 1 (found)\n");
            }
            else
            {
                hs_log_file(("  ERROR: Test '" + testNameFilter + "' not found!\n").c_str());
                hs_log_file("  Available tests:\n");
                for (const auto& test : tests)
                {
                    hs_log_file(("    - " + test.name + "\n").c_str());
                }
                tests.clear();  // Clear all tests so nothing runs
                hs_log_file("  Tests: 0 (no match)\n");
            }
        }
        else
        {
            hs_log_file("  Mode: Full Suite\n");
            hs_log_file(("  Tests: " + std::to_string(tests.size()) + "\n").c_str());
        }

        hs_log_file("========================================\n\n");

        state = State::INITIALIZING_TEST;
        currentTestIndex = 0;
        currentTest = nullptr;
        currentStages = nullptr;
        waitCounter = 0;
    }

    void Registry::cleanupCurrentTest()
    {
        delete currentStages;
        delete currentTest;
        currentStages = nullptr;
        currentTest = nullptr;
        currentTestIndex++;
        state = State::WAITING_BETWEEN_TESTS;
        waitCounter = 60;
    }

    void Registry::tick()
    {
        if (state == State::IDLE || state == State::COMPLETE) return;

        switch (state)
        {
            case State::INITIALIZING_TEST:
            {
                if (currentTestIndex >= tests.size())
                {
                    ResultsAggregator::getInstance().writeResults();

                    auto& aggregator = ResultsAggregator::getInstance();
                    hs_log_file("\n========================================\n");
                    hs_log_file("  TEST SUITE COMPLETE\n");
                    hs_log_file(("  Total:   " + std::to_string(aggregator.getTotalTests()) + "\n").c_str());
                    hs_log_file(("  Passed:  " + std::to_string(aggregator.getPassedTests()) + "\n").c_str());
                    hs_log_file(("  Skipped: " + std::to_string(aggregator.getSkippedTests()) + "\n").c_str());
                    hs_log_file(("  Failed:  " + std::to_string(aggregator.getFailedTests()) + "\n").c_str());
                    hs_log_file("========================================\n");

                    state = State::COMPLETE;
                    break;
                }

                const auto& testInfo = tests[currentTestIndex];
                currentTest = new Test(testInfo.name);
                currentStages = new TestStages(currentTest);

                try
                {
                    ScenarioRegistry::getInstance().setupScenario(
                        testInfo.scenarioName, currentTest, currentStages, testInfo.scenarioParams);
                    testInfo.func(*currentTest, *currentStages);
                    state = State::RUNNING_STAGES;
                }
                catch (const TestSkippedException& e)
                {
                    reportTestSkipped(testInfo.name, e.what());
                    cleanupCurrentTest();
                }
                catch (const TestFailedException& e)
                {
                    currentTest->log("Test failed during setup: " + std::string(e.what()));
                    reportTestResults(testInfo.name, *currentTest);
                    cleanupCurrentTest();
                }
                catch (const std::exception& e)
                {
                    currentTest->fail("Test exception during setup", e.what());
                    reportTestResults(testInfo.name, *currentTest);
                    cleanupCurrentTest();
                }
                catch (...)
                {
                    currentTest->fail("Unknown exception during setup", "Non-standard exception");
                    reportTestResults(testInfo.name, *currentTest);
                    cleanupCurrentTest();
                }
                break;
            }

            case State::RUNNING_STAGES:
            {
                const auto& testInfo = tests[currentTestIndex];
                try
                {
                    if (currentStages->tick())
                    {
                        reportTestResults(testInfo.name, *currentTest);
                        delete currentStages;
                        delete currentTest;
                        currentStages = nullptr;
                        currentTest = nullptr;
                        currentTestIndex++;

                        if (currentTestIndex < tests.size())
                        {
                            hs_log_file("\n[TEST ISOLATION] Returning to main menu...\n");
                            GameAccess::State::returnToMainMenu();
                            state = State::WAITING_BETWEEN_TESTS;
                            waitCounter = 60;
                        }
                        else
                        {
                            state = State::INITIALIZING_TEST;
                        }
                    }
                }
                catch (const TestSkippedException& e)
                {
                    reportTestSkipped(testInfo.name, e.what());
                    cleanupCurrentTest();
                }
                catch (const TestFailedException& e)
                {
                    currentTest->log("Test failed: " + std::string(e.what()));
                    reportTestResults(testInfo.name, *currentTest);
                    cleanupCurrentTest();
                }
                catch (const std::exception& e)
                {
                    currentTest->fail("Test exception", e.what());
                    reportTestResults(testInfo.name, *currentTest);
                    cleanupCurrentTest();
                }
                catch (...)
                {
                    currentTest->fail("Unknown exception", "Non-standard exception");
                    reportTestResults(testInfo.name, *currentTest);
                    cleanupCurrentTest();
                }
                break;
            }

            case State::WAITING_BETWEEN_TESTS:
            {
                if (waitCounter > 0)
                {
                    if (waitCounter % 120 == 0)
                    {
                        hs_log_file(("[TEST ISOLATION] Waiting... " + std::to_string(waitCounter / 60) + "s remaining\n").c_str());
                    }
                    waitCounter--;
                }
                else
                {
                    state = State::INITIALIZING_TEST;
                }
                break;
            }

            default:
                break;
        }
    }

    bool Registry::isComplete() const
    {
        return state == State::COMPLETE;
    }
}
