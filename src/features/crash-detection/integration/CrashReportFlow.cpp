#include "CrashReportFlow.h"
#include "../core/CrashDetector.h"
#include "../core/CrashReporter.h"
#include "../ui/CrashDialogManager.h"
#include "Global.h"
#include <cstdlib>
#include <string>

static bool initSkipBugReport()
{
    const char* envVar = std::getenv("HYPERSPACE_SKIP_BUG_REPORT");
    return envVar != nullptr && std::string(envVar) == "1";
}

static const bool SKIP_BUG_REPORT = initSkipBugReport();

CrashReportFlow* CrashReportFlow::instance = nullptr;

CrashReportFlow::CrashReportFlow()
{
}

CrashReportFlow* CrashReportFlow::GetInstance()
{
    if (instance == nullptr)
    {
        instance = new CrashReportFlow();
    }
    return instance;
}

// Initialize bug report button (delegates to CrashDialogManager)
void CrashReportFlow::InitButton()
{
    CrashDialogManager::GetInstance()->InitButton();
}

// Render all crash reporting dialogs and button
void CrashReportFlow::OnRender()
{
    CrashDialogManager::GetInstance()->OnRender();
}

// Initialize crash detection on menu open
void CrashReportFlow::OnMenuOpen()
{
    if (initialized)
    {
        return;  // Only initialize once
    }

    CrashDetector::GetInstance()->OnInit();
    initialized = true;

    // Skip bug report dialog if env var is set
    if (SKIP_BUG_REPORT)
    {
        return;
    }

    // If crash detected, show Dialog 1: "Do you want to report this crash?"
    if (CrashDetector::GetInstance()->WasCrashDetected())
    {
        CrashDialogManager::GetInstance()->ShowAskReportDialog(false);
    }
}

// Manually start the bug report flow (for button trigger)
void CrashReportFlow::StartManualReport()
{
    CrashDialogManager::GetInstance()->ShowAskReportDialog(true);
}

// Handle dialog and button mouse click events
void CrashReportFlow::OnMouseClick(int x, int y, bool& shouldPropagate)
{
    // Dialog 1: "Do you want to report this crash?"
    if (CrashDialogManager::GetInstance()->IsAskReportDialogOpen())
    {
        CrashDialogManager::GetInstance()->OnMouseClick(x, y, shouldPropagate);

        if (!CrashDialogManager::GetInstance()->IsAskReportDialogOpen())
        {
            HandleAskReportResult();
        }
        return;
    }

    // Dialog 2: "Report to Discord or GitHub?"
    if (CrashDialogManager::GetInstance()->IsChooseDestinationDialogOpen())
    {
        CrashDialogManager::GetInstance()->OnMouseClick(x, y, shouldPropagate);

        if (!CrashDialogManager::GetInstance()->IsChooseDestinationDialogOpen())
        {
            HandleChooseDestinationResult();
        }
        return;
    }

    // Dialog 3: "Here's how to report + Open folder"
    if (CrashDialogManager::GetInstance()->IsInstructionsDialogOpen())
    {
        CrashDialogManager::GetInstance()->OnMouseClick(x, y, shouldPropagate);

        if (!CrashDialogManager::GetInstance()->IsInstructionsDialogOpen())
        {
            HandleInstructionsResult();
        }
        return;
    }

    // Error dialog: Just closes, no action needed
    if (CrashDialogManager::GetInstance()->IsErrorDialogOpen())
    {
        CrashDialogManager::GetInstance()->OnMouseClick(x, y, shouldPropagate);
        return;
    }

    // Handle bug report button click
    if (CrashDialogManager::GetInstance()->IsBugButtonClicked())
    {
        StartManualReport();
    }

    shouldPropagate = true;
}


// Handle dialog and button mouse move events
void CrashReportFlow::OnMouseMove(int x, int y, bool& shouldPropagate)
{
    // Handle dialogs
    if (CrashDialogManager::GetInstance()->AnyCrashDialogOpen())
    {
        CrashDialogManager::GetInstance()->OnMouseMove(x, y, shouldPropagate);
        return;
    }

    // Handle bug report button
    CrashDialogManager::GetInstance()->UpdateButtonHover(x, y);

    shouldPropagate = true;
}

void CrashReportFlow::OnGameExit()
{
    CrashDetector::GetInstance()->OnExit();
}

void CrashReportFlow::HandleAskReportResult()
{
    // Dialog 1 result: true = "Create Report", false = "Skip"
    if (CrashDialogManager::GetInstance()->GetAskReportResult())
    {
        // Create bug report and get the path
        lastBugReportPath = CrashReporter::GetInstance()->CreateBugReportZip();

        // Check if zip creation failed
        if (lastBugReportPath.empty())
        {
            // Show error dialog
            CrashDialogManager::GetInstance()->ShowErrorDialog();
            return;
        }

        // Show Dialog 2: "Report to Discord or GitHub?"
        CrashDialogManager::GetInstance()->ShowChooseDestinationDialog();
    }
    // else -> auto close dialog, do nothing
}

void CrashReportFlow::HandleChooseDestinationResult()
{
    // Dialog 2 result: true = Discord, false = GitHub
    discordSelected = CrashDialogManager::GetInstance()->GetChooseDestinationResult();

    // Show Dialog 3: "Here's how to report + Open folder"
    CrashDialogManager::GetInstance()->ShowInstructionsDialog(lastBugReportPath, discordSelected);
}

void CrashReportFlow::HandleInstructionsResult()
{
    // Dialog 3 result: true = "Open Folder", false = "Done"
    if (CrashDialogManager::GetInstance()->GetInstructionsResult())
    {
        // Open bug report folder
        CrashReporter::GetInstance()->OpenBugReport(lastBugReportPath);

        // Reopen Dialog 3 so user can click "Done" again
        CrashDialogManager::GetInstance()->ShowInstructionsDialog(lastBugReportPath, discordSelected);
    }
    // else -> auto close dialog, do nothing
}
