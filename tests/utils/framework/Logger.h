#pragma once
#include "Core.h"
#include <string>
#include <fstream>

/**
 * TestFramework::Logger
 *
 * File-based logging infrastructure - creates and writes to log files,
 * formats log messages with timestamps.
 *
 * NOTE: Test result tracking is handled by TestResultTracker, not Logger.
 */

namespace TestFramework
{
    /**
     * Logger - Handles file I/O and message formatting for test logs
     * Responsibilities:
     * - Creating log files
     * - Writing formatted messages to files
     * - Formatting timestamps
     */
    class Logger
    {
    public:
        explicit Logger(const std::string& testName);
        ~Logger();

        // Logging methods
        void log(const std::string& message);
        void section(const std::string& sectionName);

        // Getters
        std::string getLogPath() const { return logPath; }

    private:
        std::string logPath;
        std::ofstream logFile;
        std::ofstream centralLogFile;
        std::string currentTestName;
        static bool centralLogInitialized;

        void openCentralLog();
        std::string getCurrentTimestamp();
    };
}
