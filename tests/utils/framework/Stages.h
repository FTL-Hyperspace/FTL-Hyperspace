#pragma once
#include "Test.h"
#include <functional>
#include <vector>
#include <string>

/**
 * TestFramework::Stages
 *
 * Stage-based test execution for asynchronous tests.
 * Allows tests to define multiple stages that execute sequentially over time,
 * with optional wait periods between stages.
 */

namespace TestFramework
{
    /**
     * Manages stage-based test execution for asynchronous tests
     */
    class TestStages
    {
    public:
        using StageFunc = std::function<void()>;

        struct Stage
        {
            std::string name;
            StageFunc action;
            int waitFramesAfter;
        };

        // Logging constants
        static constexpr const char* STAGE_LOG_FORMAT = "[STAGE %d/%d] %s";
        static constexpr const char* STAGE_WAIT_FORMAT = "Waiting %d frames...";
        static constexpr const char* STAGE_ERROR_FORMAT = "Stage failed: %s";

        explicit TestStages(Test* test);

        // Add a stage to execute
        void addStage(const std::string& name, StageFunc action, int waitFramesAfter = 0);

        // Execute next stage (call every frame)
        // Returns true if all stages complete
        bool tick();

        // Check if all stages are complete
        bool isComplete() const { return currentStage >= stages.size(); }

        // Get current stage index
        int getCurrentStageIndex() const { return currentStage; }

    private:
        Test* test;
        std::vector<Stage> stages;
        int currentStage;
        int waitCounter;
        bool stageExecuted;
    };
}
