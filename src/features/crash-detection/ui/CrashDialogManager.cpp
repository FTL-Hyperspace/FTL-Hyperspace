#include "CrashDialogManager.h"
#include "Global.h"

#include <boost/algorithm/string.hpp>

CrashDialogManager* CrashDialogManager::instance = nullptr;

CrashDialogManager::CrashDialogManager()
{
}

CrashDialogManager::~CrashDialogManager()
{
    delete askReportDialog;
    delete chooseDestinationDialog;
    delete instructionsDialog;
    delete errorDialog;
    delete bugReportButton;
}

CrashDialogManager* CrashDialogManager::GetInstance()
{
    if (instance == nullptr)
    {
        instance = new CrashDialogManager();
    }
    return instance;
}

void CrashDialogManager::InitButton()
{

    Point buttonPos(1239, 664);
    // Check if the image button resource exists
    if (G_->GetResources()->ImageExists("BugReport/bug_on.png"))
    {
        useImageButton = true;
        Button* imageButton = new Button();
        imageButton->OnInit("BugReport/bug", buttonPos);
        imageButton->bActive = true;
        bugReportButton = imageButton;
    }
    else
    {
        // fallback
        useImageButton = false;
        bugReportLabel.data = "B";
        bugReportLabel.isLiteral = true;
        TextButton* textButton = new TextButton();
        int borderSize = 8;
        Point buttonPosWithBorder = buttonPos + Point(borderSize/2, borderSize/2);
        textButton->OnInit(buttonPosWithBorder, Point(36-borderSize,36-borderSize), 6, &bugReportLabel, 62);
        textButton->bActive = true;
        bugReportButton = textButton;
    }
}

void CrashDialogManager::UpdateButtonHover(int x, int y)
{
    if (bugReportButton)
    {
        bugReportButton->MouseMove(x, y, false);
        if (bugReportButton->bActive && bugReportButton->bHover)
        {
            G_->GetMouseControl()->SetTooltip(G_->GetTextLibrary()->GetText("tooltip_bugreport"));
        }
    }
}

bool CrashDialogManager::IsBugButtonClicked() const
{
    return bugReportButton && bugReportButton->bActive && bugReportButton->bHover;
}

void CrashDialogManager::ShowAskReportDialog(bool isManualReport)
{
    if (askReportDialog == nullptr)
    {
        askReportDialog = new ConfirmWindow();
    }

    std::string translated;


    TextString text = TextString(G_->GetTextLibrary()->GetText((isManualReport) ? "confirm_report_bug" : "confirm_report_crash"), true);

    TextString yes = TextString(G_->GetTextLibrary()->GetText("confirm_report_create"), true);

    TextString no = TextString(G_->GetTextLibrary()->GetText("confirm_report_skip"), true);

    askReportDialog->SetText(text, 400, true, yes, no);
    askReportDialog->Open();
}

void CrashDialogManager::ShowChooseDestinationDialog()
{
    if (chooseDestinationDialog == nullptr)
    {
        chooseDestinationDialog = new ConfirmWindow();
    }

    std::string translated;


    TextString text = TextString(G_->GetTextLibrary()->GetText("confirm_report_where"), true);

    TextString yes = TextString(G_->GetTextLibrary()->GetText("confirm_report_discord"), true);

    TextString no = TextString(G_->GetTextLibrary()->GetText("confirm_report_github"), true);

    chooseDestinationDialog->SetText(text, 400, true, yes, no);
    chooseDestinationDialog->Open();
}

void CrashDialogManager::ShowInstructionsDialog(const std::string& bugReportPath, bool discordSelected)
{
    if (instructionsDialog == nullptr)
    {
        instructionsDialog = new ConfirmWindow();
    }

    std::string translated;


    TextString text = TextString(boost::algorithm::replace_all_copy(G_->GetTextLibrary()->GetText((discordSelected) ? "confirm_report_instructions_discord" : "confirm_report_instructions_github"), "\\1", bugReportPath), true);

    TextString yes = TextString(G_->GetTextLibrary()->GetText("confirm_report_view"), true);

    TextString no = TextString(G_->GetTextLibrary()->GetText("confirm_report_done"), true);

    instructionsDialog->SetText(text, 450, true, yes, no);
    instructionsDialog->Open();
}

void CrashDialogManager::ShowErrorDialog()
{
    if (errorDialog == nullptr)
    {
        errorDialog = new ConfirmWindow();
    }

    std::string translated;


    TextString text = TextString(G_->GetTextLibrary()->GetText("confirm_report_failed"), true);

    TextString yes = TextString(G_->GetTextLibrary()->GetText("confirm_report_failed_yes"), true);

    TextString no = TextString(G_->GetTextLibrary()->GetText("confirm_report_failed_no"), true);

    errorDialog->SetText(text, 400, true, yes, no);
    errorDialog->Open();
}

void CrashDialogManager::OnRender()
{
    // Render dialogs
    if (askReportDialog != nullptr && askReportDialog->bOpen)
    {
        askReportDialog->OnRender();
    }

    if (chooseDestinationDialog != nullptr && chooseDestinationDialog->bOpen)
    {
        chooseDestinationDialog->OnRender();
    }

    if (instructionsDialog != nullptr && instructionsDialog->bOpen)
    {
        instructionsDialog->OnRender();
    }

    if (errorDialog != nullptr && errorDialog->bOpen)
    {
        errorDialog->OnRender();
    }
}

void CrashDialogManager::OnMouseClick(int x, int y, bool& shouldPropagate)
{
    if (askReportDialog != nullptr && askReportDialog->bOpen)
    {
        askReportDialog->MouseClick(x, y);
        shouldPropagate = false;
        return;
    }

    if (chooseDestinationDialog != nullptr && chooseDestinationDialog->bOpen)
    {
        chooseDestinationDialog->MouseClick(x, y);
        shouldPropagate = false;
        return;
    }

    if (instructionsDialog != nullptr && instructionsDialog->bOpen)
    {
        instructionsDialog->MouseClick(x, y);
        shouldPropagate = false;
        return;
    }

    if (errorDialog != nullptr && errorDialog->bOpen)
    {
        errorDialog->MouseClick(x, y);
        shouldPropagate = false;
        return;
    }

    shouldPropagate = true;
}

void CrashDialogManager::OnMouseMove(int x, int y, bool& shouldPropagate)
{
    if (askReportDialog != nullptr && askReportDialog->bOpen)
    {
        askReportDialog->MouseMove(x, y);
        shouldPropagate = false;
        return;
    }

    if (chooseDestinationDialog != nullptr && chooseDestinationDialog->bOpen)
    {
        chooseDestinationDialog->MouseMove(x, y);
        shouldPropagate = false;
        return;
    }

    if (instructionsDialog != nullptr && instructionsDialog->bOpen)
    {
        instructionsDialog->MouseMove(x, y);
        shouldPropagate = false;
        return;
    }

    if (errorDialog != nullptr && errorDialog->bOpen)
    {
        errorDialog->MouseMove(x, y);
        shouldPropagate = false;
        return;
    }

    shouldPropagate = true;
}

bool CrashDialogManager::IsAskReportDialogOpen() const
{
    return askReportDialog != nullptr && askReportDialog->bOpen;
}

bool CrashDialogManager::IsChooseDestinationDialogOpen() const
{
    return chooseDestinationDialog != nullptr && chooseDestinationDialog->bOpen;
}

bool CrashDialogManager::IsInstructionsDialogOpen() const
{
    return instructionsDialog != nullptr && instructionsDialog->bOpen;
}

bool CrashDialogManager::IsErrorDialogOpen() const
{
    return errorDialog != nullptr && errorDialog->bOpen;
}

bool CrashDialogManager::AnyCrashDialogOpen() const
{
    return IsAskReportDialogOpen() || IsChooseDestinationDialogOpen() || IsInstructionsDialogOpen() || IsErrorDialogOpen();
}

bool CrashDialogManager::GetAskReportResult() const
{
    return askReportDialog != nullptr ? askReportDialog->result : false;
}

bool CrashDialogManager::GetChooseDestinationResult() const
{
    return chooseDestinationDialog != nullptr ? chooseDestinationDialog->result : false;
}

bool CrashDialogManager::GetInstructionsResult() const
{
    return instructionsDialog != nullptr ? instructionsDialog->result : false;
}
