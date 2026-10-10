#include "Stages.h"
#include "Test.h"
#include <cstdio>

namespace TestFramework
{
    TestStages::TestStages(Test* test)
        : test(test), currentStage(0), waitCounter(0), stageExecuted(false)
    {
    }

    void TestStages::addStage(const std::string& name, StageFunc action, int waitFramesAfter)
    {
        stages.push_back({name, action, waitFramesAfter});
    }

    bool TestStages::tick()
    {
        if (isComplete()) return true;

        // Execute current stage if not yet executed
        if (!stageExecuted)
        {
            const auto& stage = stages[currentStage];

            // Format stage log message using constant
            char stageLog[256];
            snprintf(stageLog, sizeof(stageLog), STAGE_LOG_FORMAT,
                    static_cast<int>(currentStage + 1),
                    static_cast<int>(stages.size()),
                    stage.name.c_str());
            test->log(stageLog);

            try
            {
                stage.action();
                stageExecuted = true;
                waitCounter = stage.waitFramesAfter;

                if (waitCounter > 0)
                {
                    char waitLog[64];
                    snprintf(waitLog, sizeof(waitLog), STAGE_WAIT_FORMAT, waitCounter);
                    test->log(waitLog);
                }
            }
            catch (const TestFailedException& e)
            {
                char errorLog[512];
                snprintf(errorLog, sizeof(errorLog), STAGE_ERROR_FORMAT, e.what());
                test->log(errorLog);
                throw; // Re-throw to be caught by Registry
            }
            catch (const TestSkippedException&)
            {
                throw; // Re-throw to be caught by Registry
            }
            catch (const std::exception& e)
            {
                test->fail("Stage exception", e.what());
                throw;
            }
        }

        // Wait if needed
        if (waitCounter > 0)
        {
            waitCounter--;
            return false;
        }

        // Move to next stage
        currentStage++;
        stageExecuted = false;

        return isComplete();
    }
}
