#include "TestResultTracker.h"
#include <chrono>

namespace TestFramework
{
    TestResultTracker::TestResultTracker()
        : passCount(0), failCount(0)
    {
        startTime = getCurrentTimeMs();
    }

    TestResultTracker::~TestResultTracker()
    {
    }

    void TestResultTracker::recordPass()
    {
        passCount++;
    }

    void TestResultTracker::recordFail()
    {
        failCount++;
    }

    void TestResultTracker::startTest()
    {
        // Test is starting, timing already began in constructor
    }

    void TestResultTracker::endTest()
    {
        // Test is ending, duration can be queried
    }

    long long TestResultTracker::getDuration() const
    {
        return getCurrentTimeMs() - startTime;
    }

    long long TestResultTracker::getCurrentTimeMs() const
    {
        return std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch()
        ).count();
    }
}
