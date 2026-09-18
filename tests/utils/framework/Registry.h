#pragma once
#include "Stages.h"
#include "Test.h"
#include "ScenarioParams.h"
#include <vector>
#include <string>

/**
 * TestFramework::Registry
 *
 * Test registration and orchestration.
 * Manages the full test suite lifecycle including registration, execution,
 * test isolation, and exception handling.
 */

namespace TestFramework
{
    /**
     * Registry for auto-registering and orchestrating test execution
     */
    class Registry
    {
    public:
        using TestFunc = void(*)(Test&, TestStages&);

        struct TestInfo
        {
            std::string name;
            TestFunc func;
            std::string scenarioName;
            ScenarioParams scenarioParams;
        };

        static Registry& getInstance();

        // Register a test
        void registerTest(const std::string& name, TestFunc func, const std::string& scenarioName, const ScenarioParams& scenarioParams = ScenarioParams());

        // Start executing all registered tests (optionally filter by test name)
        void startTests(const std::string& testNameFilter = "");

        // Tick test execution (call every frame)
        void tick();

        // Check if all tests are complete
        bool isComplete() const;

    private:
        Registry();

        enum class State
        {
            IDLE,
            INITIALIZING_TEST,
            RUNNING_STAGES,
            WAITING_BETWEEN_TESTS,
            COMPLETE
        };

        // Cleanup after test completion/failure/skip
        void cleanupCurrentTest();

        std::vector<TestInfo> tests;
        State state;
        size_t currentTestIndex;
        Test* currentTest;
        TestStages* currentStages;
        int waitCounter;
    };

    /**
     * Helper for auto-registering tests
     * Use: static TestRegistrar myTest("MyTest", myTestFunc, "NewGameSeeded");
     * Or with params: static TestRegistrar myTest("MyTest", myTestFunc, "NewGameSeeded", ScenarioParams().setInt("seed", 99999));
     */
    struct TestRegistrar
    {
        TestRegistrar(const std::string& name, Registry::TestFunc func, const std::string& scenarioName, const ScenarioParams& scenarioParams = ScenarioParams())
        {
            Registry::getInstance().registerTest(name, func, scenarioName, scenarioParams);
        }
    };
}
