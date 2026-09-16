#include "Test.h"

namespace TestFramework
{
    Test::Test(const std::string& testName)
        : logger(testName)
    {
    }

    Test::~Test()
    {
    }

    // ============================================
    // Internal Helper - Unified assertion recording
    // ============================================

    bool Test::recordAssertion(bool passed, const std::string& message, const std::string& failureReason)
    {
        if (passed)
        {
            tracker.recordPass();
            logger.log("[PASS] " + message);
        }
        else
        {
            tracker.recordFail();
            std::string logMsg = "[FAIL] " + message;
            if (!failureReason.empty())
            {
                logMsg += " - " + failureReason;
            }
            logger.log(logMsg);
        }
        return passed;
    }

    // ============================================
    // Logging (delegates to Logger)
    // ============================================

    void Test::log(const std::string& message)
    {
        logger.log(message);
    }

    void Test::section(const std::string& sectionName)
    {
        logger.section(sectionName);
    }

    void Test::pass(const std::string& message)
    {
        recordAssertion(true, message);
    }

    void Test::fail(const std::string& testName, const std::string& reason)
    {
        recordAssertion(false, testName, reason);
    }

    void Test::skip(const std::string& reason)
    {
        logger.log("[SKIP] " + reason);
        throw TestSkippedException(reason);
    }

    // ============================================
    // Soft Assertions (Continue on Failure)
    // ============================================

    bool Test::assertTrue(bool condition, const std::string& message)
    {
        return recordAssertion(condition, message,
            condition ? "" : "Expected true, got false");
    }

    bool Test::assertFalse(bool condition, const std::string& message)
    {
        return recordAssertion(!condition, message,
            !condition ? "" : "Expected false, got true");
    }

    bool Test::assertNotNull(void* ptr, const std::string& message)
    {
        bool passed = (ptr != nullptr);
        return recordAssertion(passed, message,
            passed ? "" : "Expected non-null pointer");
    }

    bool Test::assertEquals(int expected, int actual, const std::string& message)
    {
        bool passed = (expected == actual);
        return recordAssertion(passed, message,
            passed ? "" : "Expected " + std::to_string(expected) + ", got " + std::to_string(actual));
    }

    bool Test::assertInRange(int value, int min, int max, const std::string& message)
    {
        bool passed = (value >= min && value <= max);
        return recordAssertion(passed, message,
            passed ? "" : "Expected " + std::to_string(value) + " to be in range [" +
                          std::to_string(min) + ", " + std::to_string(max) + "]");
    }

    // ============================================
    // Hard Assertions (Halt on Failure)
    // ============================================

    void Test::requireTrue(bool condition, const std::string& message)
    {
        if (!assertTrue(condition, message))
        {
            throw TestFailedException(message);
        }
    }

    void Test::requireFalse(bool condition, const std::string& message)
    {
        if (!assertFalse(condition, message))
        {
            throw TestFailedException(message);
        }
    }

    void Test::requireNotNull(void* ptr, const std::string& message)
    {
        if (!assertNotNull(ptr, message))
        {
            throw TestFailedException(message);
        }
    }

    void Test::requireEquals(int expected, int actual, const std::string& message)
    {
        if (!assertEquals(expected, actual, message))
        {
            throw TestFailedException(message);
        }
    }

    void Test::requireInRange(int value, int min, int max, const std::string& message)
    {
        if (!assertInRange(value, min, max, message))
        {
            throw TestFailedException(message);
        }
    }
}
