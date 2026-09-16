#pragma once
#include <string>
#include <vector>

/**
 * TestFramework::Results
 *
 * Test result aggregation and reporting.
 * Collects results from all tests and writes machine-readable JSON output.
 */

namespace TestFramework
{
    /**
     * Result data for a single test
     */
    struct TestResult
    {
        std::string name;
        bool passed;
        bool skipped = false;
        int duration_ms;
        int assertions_passed;
        int assertions_failed;
    };

    /**
     * Aggregates and reports test results
     * Singleton pattern for global access
     */
    class ResultsAggregator
    {
    public:
        static ResultsAggregator& getInstance();

        // Add a test result
        void addTestResult(const TestResult& result);

        // Write results to human-readable text file
        void writeResults();

        // Query methods (cached)
        bool allPassed() const { return failedCount == 0; }
        int getTotalTests() const { return static_cast<int>(results.size()); }
        int getPassedTests() const { return passedCount; }
        int getSkippedTests() const { return skippedCount; }
        int getFailedTests() const { return failedCount; }

    private:
        ResultsAggregator() = default;

        std::vector<TestResult> results;
        int passedCount = 0;
        int skippedCount = 0;
        int failedCount = 0;
    };
}
