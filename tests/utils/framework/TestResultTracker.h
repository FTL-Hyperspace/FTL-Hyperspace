#pragma once
#include <string>
#include <chrono>

/**
 * TestFramework::TestResultTracker
 *
 * Tracks test execution results - pass/fail counts, timing, and test lifecycle.
 * Separate from Logger to avoid mixing concerns.
 */

namespace TestFramework
{
    /**
     * TestResultTracker - Tracks test results and lifecycle
     * Manages:
     * - Pass/fail counters
     * - Test timing information
     * - Test lifecycle (start/end)
     */
    class TestResultTracker
    {
    public:
        explicit TestResultTracker();
        ~TestResultTracker();

        // Result tracking
        void recordPass();
        void recordFail();

        // Test lifecycle
        void startTest();
        void endTest();

        // Getters
        int getPassCount() const { return passCount; }
        int getFailCount() const { return failCount; }
        long long getDuration() const;

    private:
        int passCount;
        int failCount;
        long long startTime;

        long long getCurrentTimeMs() const;
    };
}
