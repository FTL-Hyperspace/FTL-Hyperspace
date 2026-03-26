#pragma once
#include <map>
#include <string>

/**
 * TestFramework::ScenarioParams
 *
 * Parameter container for scenario configuration.
 * Supports int and string parameters with defaults.
 */

namespace TestFramework
{
    /**
     * Parameter container with fluent API
     */
    class ScenarioParams
    {
    public:
        ScenarioParams() = default;

        // Fluent setters
        ScenarioParams& setInt(const std::string& key, int value);
        ScenarioParams& setString(const std::string& key, const std::string& value);

        // Getters with defaults
        int getInt(const std::string& key, int defaultValue = 0) const;
        std::string getString(const std::string& key, const std::string& defaultValue = "") const;

        // Check if parameter exists
        bool hasInt(const std::string& key) const;
        bool hasString(const std::string& key) const;

        void overrideWith(const ScenarioParams& other);

    private:
        std::map<std::string, int> intParams;
        std::map<std::string, std::string> stringParams;
    };
}
