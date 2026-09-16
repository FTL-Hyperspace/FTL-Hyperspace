#include "ScenarioRegistry.h"
#include "../../../Global.h"

namespace TestFramework
{
    ScenarioRegistry& ScenarioRegistry::getInstance()
    {
        static ScenarioRegistry instance;
        return instance;
    }

    void ScenarioRegistry::registerScenario(const std::string& name, ScenarioFunc func, const ScenarioParams& defaultParams)
    {
        scenarios[name] = {func, defaultParams};
    }

    void ScenarioRegistry::setupScenario(const std::string& name, Test* test, TestStages* stages, const ScenarioParams& paramOverrides)
    {
        auto it = scenarios.find(name);
        if (it == scenarios.end())
        {
            test->fail("Unknown scenario", "Scenario '" + name + "' not registered");
            return;
        }

        const ScenarioInfo& info = it->second;
        ScenarioParams mergedParams = ScenarioParams();

        mergedParams.overrideWith(info.defaultParams);
        mergedParams.overrideWith(paramOverrides);

        // Call scenario setup function
        info.func(test, stages, mergedParams);
    }

    bool ScenarioRegistry::hasScenario(const std::string& name) const
    {
        return scenarios.find(name) != scenarios.end();
    }
}
