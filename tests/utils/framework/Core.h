#pragma once
#include <exception>
#include <string>

/**
 * TestFramework::Core
 *
 * Core testing framework types and exceptions.
 * This is the foundation that other framework components build upon.
 */

// Forward declarations for FTL game types
class CommandGui;
class ShipManager;
class StarMap;
class WorldManager;
class MainMenu;
class ShipBuilder;

namespace TestFramework
{
    /**
     * Exception thrown when a test fails with a REQUIRE assertion.
     * This causes immediate test termination.
     */
    class TestFailedException : public std::exception
    {
    public:
        explicit TestFailedException(const std::string& msg) : message(msg) {}
        const char* what() const noexcept override { return message.c_str(); }

    private:
        std::string message;
    };

    /**
     * Exception thrown when a test is skipped.
     * This causes immediate test termination without counting as failure.
     */
    class TestSkippedException : public std::exception
    {
    public:
        explicit TestSkippedException(const std::string& msg) : message(msg) {}
        const char* what() const noexcept override { return message.c_str(); }

    private:
        std::string message;
    };
}
