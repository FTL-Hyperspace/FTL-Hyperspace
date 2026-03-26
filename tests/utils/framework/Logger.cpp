#include "Logger.h"
#include "FileSystem.h"
#include "../../../Global.h"
#include <chrono>
#include <sstream>
#include <iomanip>
#include <ctime>

namespace TestFramework
{
    bool Logger::centralLogInitialized = false;

    Logger::Logger(const std::string& testName)
        : currentTestName(testName)
    {
        // Create tests/logs directory if it doesn't exist
        FileSystem::ensureDirectory("tests/logs");

        // Create log file path: tests/logs/TestName.log (no timestamp in filename)
        logPath = "tests/logs/" + testName + ".log";
        logFile.open(logPath, std::ios::out);

        // Initialize central log on first use
        if (!centralLogInitialized)
        {
            openCentralLog();
            centralLogInitialized = true;
        }
        else
        {
            // Open for appending
            centralLogFile.open("tests/all_tests.log", std::ios::app);
        }

        log("========================================");
        log("  TEST: " + testName);
        log("  TIME: " + getCurrentTimestamp());
        log("========================================");
        log("");
    }

    Logger::~Logger()
    {
        if (logFile.is_open())
        {
            logFile.close();
        }
    }

    void Logger::openCentralLog()
    {
        centralLogFile.open("tests/all_tests.log", std::ios::out);
        if (centralLogFile.is_open())
        {
            centralLogFile << "========================================\n";
            centralLogFile << "FTL HYPERSPACE TEST EXECUTION LOG\n";
            centralLogFile << "========================================\n";
            centralLogFile << "Started: " << getCurrentTimestamp() << "\n";
            centralLogFile << "\n";
            centralLogFile.flush();
        }
    }

    void Logger::log(const std::string& message)
    {
        std::string line = "[" + getCurrentTimestamp() + "] " + message;

        // Write to individual test log
        if (logFile.is_open())
        {
            logFile << line << std::endl;
        }

        // Write to central log (for real-time monitoring)
        if (centralLogFile.is_open())
        {
            centralLogFile << "[" + getCurrentTimestamp() + "] [" << currentTestName << "] " << message << "\n";
            centralLogFile.flush();
        }

        hs_log_file("%s\n", line.c_str());
    }

    void Logger::section(const std::string& sectionName)
    {
        log("");
        log("--- " + sectionName + " ---");
    }

    std::string Logger::getCurrentTimestamp()
    {
        auto now = std::chrono::system_clock::now();
        auto time = std::chrono::system_clock::to_time_t(now);
        auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(
            now.time_since_epoch()
        ).count() % 1000;

        char buffer[16];
        std::strftime(buffer, sizeof(buffer), "%H:%M:%S", std::localtime(&time));

        std::stringstream ss;
        ss << buffer << "." << std::setfill('0') << std::setw(3) << ms;
        return ss.str();
    }
}
