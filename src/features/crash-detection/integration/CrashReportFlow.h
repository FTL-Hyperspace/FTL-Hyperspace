#pragma once

#include <string>
#include "Global.h"

/**
 * CrashReportFlow - ORCHESTRATION LAYER
 *
 * Dialog Flow:
 * 1. OnMenuOpen() -> ShowAskReportDialog() - "Do you want to report this crash?"
 *    └─ if Yes -> create bug report, show Dialog 2
 *    └─ if Skip -> flow ends
 *
 * 2. HandleAskReportResult() -> ShowChooseDestinationDialog() - "Discord or GitHub?"
 *    └─ stores user's choice in discordSelected
 *
 * 3. HandleChooseDestinationResult() -> ShowInstructionsDialog() - "Here's how to report"
 *    └─ if Open Folder -> opens folder, keeps dialog open
 *    └─ if Done -> flow ends
 *
 * Orchestrates: CrashDetector (core), CrashReporter (core), and CrashDialogManager (ui)
 */
class CrashReportFlow
{
public:
    static CrashReportFlow* GetInstance();

    // Called when main menu opens - checks for crashes and shows first dialog
    void OnMenuOpen();

    // Manually start the bug report flow (for button trigger)
    void StartManualReport();

    // Initialize bug report button (delegates to CrashDialogManager)
    void InitButton();

    // Render all dialogs and button
    void OnRender();

    // Handle mouse input for dialogs and button
    void OnMouseClick(int x, int y, bool& shouldPropagate);
    void OnMouseMove(int x, int y, bool& shouldPropagate);

    // Called when game exits normally
    void OnGameExit();

private:
    CrashReportFlow();
    static CrashReportFlow* instance;

    bool initialized = false;
    std::string lastBugReportPath = "";
    bool discordSelected = false;  // Stores Dialog 2 choice: true=Discord, false=GitHub

    // Dialog progression handlers
    void HandleAskReportResult();          // Dialog 1 -> Dialog 2
    void HandleChooseDestinationResult();  // Dialog 2 -> Dialog 3
    void HandleInstructionsResult();       // Dialog 3 actions
};
