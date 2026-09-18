#pragma once
#include "Test.h"
#include "Stages.h"
#include "ScenarioParams.h"
#include <functional>
#include <map>
#include <string>

/**
 * TestFramework::ScenarioRegistry
 *
 * Auto-registration system for scenarios.
 * Scenarios register themselves on startup, no central enum needed.
 */

namespace TestFramework
{
    /**
     * Registry for auto-registering scenarios
     */
    class ScenarioRegistry
    {
    public:
        using ScenarioFunc = std::function<void(Test*, TestStages*, const ScenarioParams&)>;

        struct ScenarioInfo
        {
            ScenarioFunc func;
            ScenarioParams defaultParams;
        };

        static ScenarioRegistry& getInstance();

        // Register a scenario
        void registerScenario(const std::string& name, ScenarioFunc func, const ScenarioParams& defaultParams = ScenarioParams());

        // Setup a scenario with optional param overrides
        void setupScenario(const std::string& name, Test* test, TestStages* stages, const ScenarioParams& paramOverrides = ScenarioParams());

        // Check if scenario exists
        bool hasScenario(const std::string& name) const;

    private:
        ScenarioRegistry() = default;
        std::map<std::string, ScenarioInfo> scenarios;

        // Merge default params with overrides
        ScenarioParams mergeParams(const ScenarioParams& defaults, const ScenarioParams& overrides) const;
    };

    /**
     * Helper for auto-registering scenarios
     * Use: static ScenarioRegistrar myScenario("MyScenario", myScenarioFunc, defaultParams);
     */
    struct ScenarioRegistrar
    {
        ScenarioRegistrar(const std::string& name, ScenarioRegistry::ScenarioFunc func, const ScenarioParams& defaultParams = ScenarioParams())
        {
            ScenarioRegistry::getInstance().registerScenario(name, func, defaultParams);
        }
    };
}
