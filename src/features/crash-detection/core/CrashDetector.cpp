#include "CrashDetector.h"
#include "Global.h"
#include "SaveFile.h"

CrashDetector* CrashDetector::instance = nullptr;

CrashDetector::CrashDetector() : crashDetected(false)
{
}

void CrashDetector::OnInit()
{
    // Check if game crashed on previous launch
    if (HasCrashedLastLaunch())
    {
        hs_log_file("CRASH DETECTED - Game did not exit normally on previous launch\n");
        crashDetected = true;
    }
    else
    {
        printf("No previous crash detected\n");
        crashDetected = false;
    }

    // Write crash flag for this session
    WriteCrashFlag();
}

void CrashDetector::OnExit()
{
    // Clear crash flag on normal exit
    ClearCrashFlag();
}

/// 


CrashDetector* CrashDetector::GetInstance()
{
    if (instance == nullptr)
    {
        instance = new CrashDetector();
    }
    return instance;
}

std::string CrashDetector::GetCrashFlagPath()
{
    std::string userFolder = FileHelper::getUserFolder();
    return userFolder + SaveFileHandler::instance->savePrefix + "_crash.flag";
}

bool CrashDetector::HasCrashedLastLaunch()
{
    return FileHelper::fileExists(GetCrashFlagPath());
}

void CrashDetector::WriteCrashFlag()
{
    std::string crashFlagPath = GetCrashFlagPath();
    int file = FileHelper::createBinaryFile(crashFlagPath);
    FileHelper::closeBinaryFile(file);
    hs_log_file("Crash detection flag written to: %s\n", crashFlagPath.c_str());
}

void CrashDetector::ClearCrashFlag()
{
    std::string crashFlagPath = GetCrashFlagPath();
    // delete if exists
    if (FileHelper::fileExists(crashFlagPath))
    {
        FileHelper::deleteFile(crashFlagPath);
        hs_log_file("Crash flag cleared - game exited normally (was: %s)\n", crashFlagPath.c_str());
    }
}

