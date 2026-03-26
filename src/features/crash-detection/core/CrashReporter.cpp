#include "CrashReporter.h"
#include "Global.h"
#include "SaveFile.h"

#include <time.h>
#include <zlib.h>
#include <minizip/zip.h>
#include <boost/format.hpp>
#include <boost/filesystem.hpp>

#ifdef _WIN32
    #include <windows.h>
    #include <shellapi.h>
#else
    #include <unistd.h>
    #include <sys/types.h>
#endif

namespace fs = boost::filesystem;

CrashReporter* CrashReporter::instance = nullptr;

CrashReporter::CrashReporter()
{
}

CrashReporter* CrashReporter::GetInstance()
{
    if (instance == nullptr)
    {
        instance = new CrashReporter();
    }
    return instance;
}

std::string CrashReporter::GenerateBugReportPath()
{
    fs::path userFolder(FileHelper::getUserFolder());
    fs::path bugreportsDir = userFolder / "bugreports";

    // Create bugreports directory if it doesn't exist
    fs::create_directories(bugreportsDir);

    // Create timestamped filename
    time_t timer;
    time(&timer);
    auto localTime = localtime(&timer);

    char filename[256];
    strftime(filename, 256, "hs_bugreport_%d-%m-%Y_%H%M%S.zip", localTime);

    return (bugreportsDir / filename).string();
}

std::string CrashReporter::CreateBugReportZip()
{
    fs::path userFolder(FileHelper::getUserFolder());
    std::string zipPath = GenerateBugReportPath();

    hs_log_file("Creating bug report zip: %s\n", zipPath.c_str());

    int err = 0;
    zipFile zf = zipOpen(zipPath.c_str(), APPEND_STATUS_CREATE);

    if (zf == nullptr)
    {
        hs_log_file("Failed to create zip file: %s\n", zipPath.c_str());
        return "";
    }

    try
    {
        std::string savePrefix = SaveFileHandler::instance->savePrefix;

        // Add each file if it exists (check user folder and current execution folder)
        // Currently execution folder is used on Windows and Linux
        fs::path currentFolder = fs::current_path();

        // Hardcoded files to include in bug report
        std::vector<std::string> filesToAdd = {
            "settings.ini",
            savePrefix + "_prof.sav",
            savePrefix + "_prof_backup.sav",
            savePrefix + "_version.sav",
            savePrefix + "_continue.sav",
            "FTL.log",
            "FTL_HS.log",
            "FTL_HS.log.bak",
            "zhl.log",
            "zhl.log.bak"
        };

        // Add each file if it exists
        for (const auto& filename : filesToAdd)
        {
            fs::path filePath = userFolder / filename;
            // If not in save folder -> probably in execution folder (like on Windows/Linux)
            if (!fs::exists(filePath))
                filePath = currentFolder / filename;

            if (fs::exists(filePath))
            {
                FILE* file = fopen(filePath.string().c_str(), "rb");
                if (file != nullptr)
                {
                    err = zipOpenNewFileInZip(zf, filename.c_str(), nullptr, nullptr, 0, nullptr, 0, nullptr, Z_DEFLATED, Z_DEFAULT_COMPRESSION);
                    if (err != ZIP_OK)
                    {
                        hs_log_file("Failed to add file to zip: %s (error: %d)\n", filename.c_str(), err);
                        fclose(file);
                        continue;
                    }

                    char buffer[4096];
                    size_t bytesRead;
                    while ((bytesRead = fread(buffer, 1, sizeof(buffer), file)) > 0)
                    {
                        zipWriteInFileInZip(zf, buffer, bytesRead);
                    }

                    zipCloseFileInZip(zf);
                    fclose(file);

                    printf("Added to zip: %s\n", filename.c_str());
                }
            }
        }

        err = zipClose(zf, nullptr);
        if (err == ZIP_OK)
        {
            hs_log_file("Bug report zip created successfully: %s\n", zipPath.c_str());
            return zipPath;
        }
        else
        {
            hs_log_file("Failed to close zip file (error code: %d)\n", err);
            return "";
        }
    }
    catch (const std::exception& e)
    {
        hs_log_file("Exception while creating zip: %s\n", e.what());
        zipClose(zf, nullptr);
        return "";
    }
}

void CrashReporter::OpenBugReport(const std::string& bugReportZipPath)
{
    // Extract folder path from zip file path
    size_t lastSlash = bugReportZipPath.find_last_of("\\/");
    if (lastSlash == std::string::npos)
    {
        hs_log_file("Invalid bug report path: %s\n", bugReportZipPath.c_str());
        return;
    }

    std::string folderPath = bugReportZipPath.substr(0, lastSlash);

    // Open folder in platform-specific file explorer (safe APIs)
    #ifdef _WIN32
        // ShellExecuteA is safer than system() - no command injection risk
        ShellExecuteA(NULL, "explore", folderPath.c_str(), NULL, NULL, SW_SHOWNORMAL);
    #elif __APPLE__
        // Use fork/exec to avoid command injection
        pid_t pid = fork();
        if (pid == 0)
        {
            // Child process
            execlp("open", "open", folderPath.c_str(), NULL);
            _exit(1); // Exit if exec fails
        }
    #else // Linux
        // Use fork/exec to avoid command injection
        pid_t pid = fork();
        if (pid == 0)
        {
            // Child process
            execlp("xdg-open", "xdg-open", folderPath.c_str(), NULL);
            _exit(1); // Exit if exec fails
        }
    #endif
}
