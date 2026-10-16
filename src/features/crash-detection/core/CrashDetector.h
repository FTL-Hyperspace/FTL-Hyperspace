#pragma once

#include <string>

/**
 * CrashDetector - Detects if the game crashed on the last launch
 *
 * Crash detection flow:
 * 1. OnInit() - checks for previous crash, writes crash flag
 * 2. OnExit() - clears flag (normal exit)
 * 3. Next launch - OnInit() detects if flag exists (crash was detected)
 */
class CrashDetector
{
public:
    static CrashDetector* GetInstance();

    // Called on game initialization
    void OnInit();

    // Called on game exit
    void OnExit();

    // The app went to the background or came back. Android usually closes an app in the
    // background by killing it, which mustn't count as a crash next launch.
    void OnSuspend();
    void OnResume();

    // Returns true if a crash was detected on startup
    bool WasCrashDetected() const { return crashDetected; }

private:
    CrashDetector();
    static CrashDetector* instance;

    bool crashDetected;
    bool flagWritten = false;

    // Helper functions - do one thing only
    std::string GetCrashFlagPath();
    bool HasCrashedLastLaunch();
    void WriteCrashFlag();
    void ClearCrashFlag();
};

