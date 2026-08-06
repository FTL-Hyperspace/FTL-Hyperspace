#pragma once

#include <string>

/**
 * CrashReporter - CORE BUSINESS LOGIC
 *
 * Handles bug report creation and utilities:
 * - Creates zip archive of saves and logs
 * - Opens bug report folder (cross-platform)
 */
class CrashReporter
{
public:
    static CrashReporter* GetInstance();

    // Create a zip archive of all saves and logs
    // Returns the path to the created zip file, or empty string if failed
    std::string CreateBugReportZip();

    // Open folder containing the bug report in file explorer/finder (cross-platform)
    void OpenBugReport(const std::string& bugReportZipPath);

private:
    CrashReporter();
    static CrashReporter* instance;

    // Generate a new timestamped bug report path
    std::string GenerateBugReportPath();
};
