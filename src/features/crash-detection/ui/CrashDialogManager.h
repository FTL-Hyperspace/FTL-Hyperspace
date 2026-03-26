#pragma once

#include <string>
#include "Global.h"

/**
 * CrashDialogManager - Manages all crash reporting dialogs
 *
 * Dialog Flow:
 * 1. AskReportDialog - Ask if user wants to report crash
 * 2. ChooseDestinationDialog - Ask where to report (Discord or GitHub)
 * 3. ShowInstructionsDialog - Show instructions + Open folder option
 */
class CrashDialogManager
{
public:
    static CrashDialogManager* GetInstance();
    ~CrashDialogManager();

    // Bug report button
    void InitButton();
    void UpdateButtonHover(int x, int y);  // Updates hover state and shows tooltip
    bool IsBugButtonClicked() const;       // Returns true if button should trigger action

    // Dialog 1: "Do you want to report this crash?" (isManualReport = from button, not crash)
    void ShowAskReportDialog(bool isManualReport);

    // Dialog 2: "Report to Discord or GitHub?"
    void ShowChooseDestinationDialog();

    // Dialog 3: "Here's how to report + Open folder option"
    void ShowInstructionsDialog(const std::string& bugReportPath, bool discordSelected);

    // Error dialog: "Failed to create bug report"
    void ShowErrorDialog();

    // Rendering and input handling
    void OnRender();
    void OnMouseClick(int x, int y, bool& shouldPropagate);
    void OnMouseMove(int x, int y, bool& shouldPropagate);

    // Dialog state queries
    bool IsAskReportDialogOpen() const;
    bool IsChooseDestinationDialogOpen() const;
    bool IsInstructionsDialogOpen() const;
    bool IsErrorDialogOpen() const;
    bool AnyCrashDialogOpen() const;

    // Results from dialogs
    bool GetAskReportResult() const;         // true = "Create Report", false = "Skip"
    bool GetChooseDestinationResult() const; // true = Discord, false = GitHub
    bool GetInstructionsResult() const;      // true = "Open Folder", false = "Done"

private:
    CrashDialogManager();
    static CrashDialogManager* instance;

    class ConfirmWindow* askReportDialog = nullptr;
    class ConfirmWindow* chooseDestinationDialog = nullptr;
    class ConfirmWindow* instructionsDialog = nullptr;
    class ConfirmWindow* errorDialog = nullptr;

    // Bug report button (can be TextButton or image Button depending on mod resources)
    GenericButton* bugReportButton = nullptr;
    TextString bugReportLabel;
    bool useImageButton = false;
};
