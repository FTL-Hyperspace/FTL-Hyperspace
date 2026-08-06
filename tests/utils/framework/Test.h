#pragma once
#include "Logger.h"
#include "TestResultTracker.h"
#include <string>

/**
 * TestFramework::Test
 *
 * High-level test API that test writers interact with.
 * Provides assertions, logging, and pass/fail tracking.
 * Uses Logger for output and TestResultTracker for result tracking.
 */

namespace TestFramework
{
    /**
     * Test - Main interface for writing tests
     * Combines logging and assertions into a single, clean API
     */
    class Test
    {
    public:
        explicit Test(const std::string& testName);
        ~Test();

        // Logging
        void log(const std::string& message);
        void section(const std::string& sectionName);

        // Pass/fail/skip (optional - implicit pass if no failures)
        void pass(const std::string& message);
        void fail(const std::string& testName, const std::string& reason);
        void skip(const std::string& reason);

        // Soft assertions - log but continue execution
        bool assertTrue(bool condition, const std::string& message);
        bool assertFalse(bool condition, const std::string& message);
        bool assertNotNull(void* ptr, const std::string& message);
        bool assertEquals(int expected, int actual, const std::string& message);
        bool assertInRange(int value, int min, int max, const std::string& message);

        // Hard assertions - fail test immediately if condition fails
        void requireTrue(bool condition, const std::string& message);
        void requireFalse(bool condition, const std::string& message);
        void requireNotNull(void* ptr, const std::string& message);
        void requireEquals(int expected, int actual, const std::string& message);
        void requireInRange(int value, int min, int max, const std::string& message);

        // Access to underlying logger and tracker (for framework internals)
        Logger& getLogger() { return logger; }
        const TestResultTracker& getTracker() const { return tracker; }
        TestResultTracker& getTracker() { return tracker; }

    private:
        // Internal helper - records assertion result with auto logging
        bool recordAssertion(bool passed, const std::string& message, const std::string& failureReason = "");

        Logger logger;
        TestResultTracker tracker;
    };
}
