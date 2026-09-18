#include "ScenarioParams.h"

namespace TestFramework
{
    ScenarioParams& ScenarioParams::setInt(const std::string& key, int value)
    {
        intParams[key] = value;
        return *this;
    }

    ScenarioParams& ScenarioParams::setString(const std::string& key, const std::string& value)
    {
        stringParams[key] = value;
        return *this;
    }

    int ScenarioParams::getInt(const std::string& key, int defaultValue) const
    {
        auto it = intParams.find(key);
        return (it != intParams.end()) ? it->second : defaultValue;
    }

    std::string ScenarioParams::getString(const std::string& key, const std::string& defaultValue) const
    {
        auto it = stringParams.find(key);
        return (it != stringParams.end()) ? it->second : defaultValue;
    }

    bool ScenarioParams::hasInt(const std::string& key) const
    {
        return intParams.find(key) != intParams.end();
    }

    bool ScenarioParams::hasString(const std::string& key) const
    {
        return stringParams.find(key) != stringParams.end();
    }

    void ScenarioParams::overrideWith(const ScenarioParams& other)
    {
        for (const auto& pair : other.intParams)
        {
            this->intParams[pair.first] = pair.second;
        }
        for (const auto& pair : other.stringParams)
        {
            this->stringParams[pair.first] = pair.second;
        }
    }
}
