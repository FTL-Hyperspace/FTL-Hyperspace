#include "Results.h"
#include "FileSystem.h"
#include "../../../Global.h"
#include <fstream>

namespace TestFramework
{
    ResultsAggregator& ResultsAggregator::getInstance()
    {
        static ResultsAggregator instance;
        return instance;
    }

    void ResultsAggregator::addTestResult(const TestResult& result)
    {
        results.push_back(result);
        if (result.skipped)
        {
            skippedCount++;
        }
        else if (result.passed)
        {
            passedCount++;
        }
        else
        {
            failedCount++;
        }
    }

    void ResultsAggregator::writeResults()
    {
        // Create tests directory if needed
        FileSystem::ensureDirectory("tests");

        // Write human-readable text format
        std::ofstream resultsFile("tests/test_results.txt");
        if (!resultsFile.is_open())
        {
            hs_log_file("[ERROR] Could not write test results file\n");
            return;
        }

        // Calculate total duration
        long long totalDuration = 0;
        for (const auto& r : results)
        {
            totalDuration += r.duration_ms;
        }

        // Write header
        resultsFile << "========================================\n";
        resultsFile << "FTL HYPERSPACE TEST RESULTS\n";
        resultsFile << "========================================\n";
        resultsFile << "\n";

        // Write summary
        resultsFile << "Total Tests:        " << getTotalTests() << "\n";
        resultsFile << "Passed:             " << getPassedTests() << "\n";
        resultsFile << "Skipped:            " << getSkippedTests() << "\n";
        resultsFile << "Failed:             " << getFailedTests() << "\n";
        resultsFile << "All Passed:         " << (allPassed() ? "Yes" : "No") << "\n";
        resultsFile << "Duration:           " << (totalDuration / 1000.0) << "s\n";
        resultsFile << "\n";

        // Write failed test names (if any)
        if (getFailedTests() > 0)
        {
            resultsFile << "Failed Test Names:\n";
            for (const auto& r : results)
            {
                if (!r.passed)
                {
                    resultsFile << "  - " << r.name << "\n";
                }
            }
            resultsFile << "\n";
        }

        // Write test details
        resultsFile << "Test Details:\n";
        for (const auto& r : results)
        {
            const char* status = r.skipped ? "SKIPPED" : (r.passed ? "PASSED" : "FAILED");
            resultsFile << "  " << r.name << ": " << status;
            if (!r.skipped)
            {
                resultsFile << " (" << r.duration_ms << "ms | "
                           << r.assertions_passed << " assertions passed, "
                           << r.assertions_failed << " failed)";
            }
            resultsFile << "\n";
        }

        resultsFile.close();

        hs_log_file("\n[TEST RESULTS] Written to tests/test_results.txt (human-readable)\n");
    }
}
