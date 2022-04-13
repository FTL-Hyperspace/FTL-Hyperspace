#include "SaveFile.h"
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string/predicate.hpp>
#include <boost/algorithm/string/replace.hpp>

SaveFileHandler* SaveFileHandler::instance = new SaveFileHandler();

static bool readFromAe = false;

void SaveFileHandler::ParseSaveFileNode(rapidxml::xml_node<char>* node)
{
    for (auto child = node->first_node(); child; child = child->next_sibling())
    {
        std::string name = child->name();
        std::string value = child->value();

        if (name == "prefix")
        {
            if (value != "hs")
            {
                savePrefix = "hs_" + value;
            }
            else
            {
                savePrefix = value;
            }
        }
        if (name == "inheritMode")
        {
            inheritMode = (SaveFileHandler::InheritMode)boost::lexical_cast<int>(value);
        }
        if (name == "welcomeDialog")
        {
            welcomeDialog = EventsParser::ParseBoolean(value);
        }
    }
}

void SaveFileHandler::CreateTransferFile()
{
    std::string userFolder = FileHelper::getUserFolder();

    int f = FileHelper::createBinaryFile(userFolder + SaveFileHandler::instance->savePrefix + "_not_selected_transfer");
    FileHelper::closeBinaryFile(f);
}

void SaveFileHandler::DeleteTransferFile()
{
    std::string userFolder = FileHelper::getUserFolder();

    FileHelper::deleteFile(userFolder + SaveFileHandler::instance->savePrefix + "_not_selected_transfer");
}

bool SaveFileHandler::TransferFileExists()
{
    std::string userFolder = FileHelper::getUserFolder();

    return FileHelper::fileExists(userFolder + SaveFileHandler::instance->savePrefix + "_not_selected_transfer");
}

HOOK_METHOD(ScoreKeeper, Save, (bool saveScore) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ScoreKeeper::Save -> Begin (SaveFile.cpp)\n")
    std::string versionFileName = FileHelper::getUserFolder();

    versionFileName.append(SaveFileHandler::instance->savePrefix + "_version.sav");
    int versionFile = FileHelper::createBinaryFile(versionFileName);
    FileHelper::writeInt(versionFile, SaveFileHandler::version);
    FileHelper::closeBinaryFile(versionFile);

    std::string userFolder = FileHelper::getUserFolder();

    if (FileHelper::fileExists(userFolder + SaveFileHandler::instance->savePrefix + "_prof.sav"))
    {
        int file = FileHelper::readBinaryFile(userFolder + SaveFileHandler::instance->savePrefix + "_prof.sav");

        int fileLen = FileHelper::fileLength(file);
        if (fileLen > 0)
        {
            char* bin = FileHelper::readBuffer(file, fileLen, false);
            FileHelper::closeBinaryFile(file);

            file = FileHelper::createBinaryFile(userFolder + SaveFileHandler::instance->savePrefix + "_prof_backup.sav");
            FileHelper::writeData(file, bin, fileLen);
            FileHelper::closeBinaryFile(file);
        }
    }

    super(saveScore);

    std::string newSave = userFolder;
    std::string oldSave = userFolder;

    newSave.append(SaveFileHandler::instance->savePrefix + "_prof.new.sav");
    oldSave.append(SaveFileHandler::instance->savePrefix + "_prof.sav");

    if (FileHelper::fileExists(newSave))
    {
        int file = FileHelper::readBinaryFile(newSave);
        int fileLength = FileHelper::fileLength(file);
        FileHelper::closeBinaryFile(file);

        if (fileLength > 0)
        {
            FileHelper::deleteFile(oldSave);
            FileHelper::renameFile(newSave, oldSave);
            return;
        }
    }
    printf("Something went wrong while saving Hyperspace!\n");

    /*
    // unused rewrite - can't figure out why the saving is screwed
    if (!G_->GetTutorialManager()->Running())
    {

        float scoreModifier = 1.f;
        int difficulty = *Global::difficulty;

        if (difficulty == 1)
        {
            scoreModifier = 1.25f;
        }
        if (difficulty == 2)
        {
            scoreModifier = 1.5f;
        }

        currentScore.difficulty = difficulty;
        currentScore.score = std::floor(scoreModifier * (stats[2].current + 20 * stats[0].current + 10 * stats[1].current));
        currentScore.advancedContent = Settings::GetDlcEnabled();

        if (saveScore && !bSavedScore)
        {
            for (int i = 0; i < 3; i++)
            {
                if (stats[i].current > stats[i].max)
                {
                    stats[i].max = stats[i].current;
                }
            }

            TopScore newCopy = TopScore(currentScore);
            AddTopScoreType(newCopy, 0);
            bSavedScore = true;
        }

        std::string userFolder = FileHelper::getUserFolder();

        std::string newSave = userFolder + SaveFileHandler::instance->savePrefix + "_prof.new.sav";
        std::string oldSave = userFolder + SaveFileHandler::instance->savePrefix + "_prof.sav";

        int newFile = FileHelper::createBinaryFile(newSave);

        if (newFile < 0)
        {
            hs_log_file("!ERROR!: Couldn't save data.\n");
        }
        else
        {
            FileHelper::writeInt(newFile, 9);
            FileHelper::writeInt(newFile, *Global::firstTimeShips);
            G_->GetAchievementTracker()->SaveProfile(newFile);

            for (int i = 0; i < 12; i++)
            {
                FileHelper::writeInt(newFile, unlocked[i][0]);
                FileHelper::writeInt(newFile, unlocked[i][2]);
            }

            FileHelper::writeInt(newFile, topScores.size());
            SaveScores(newFile, topScores);
            FileHelper::writeInt(newFile, shipScores.size());
            for (int i = 0; i < shipScores.size(); i++)
            {
                SaveScores(newFile, shipScores[i][0]);
                SaveScores(newFile, shipScores[i][1]);
                SaveScores(newFile, shipScores[i][2]);
            }

            for (int i = 0; i < 4; i++)
            {
                FileHelper::writeInt(newFile, stats[i].max);
                FileHelper::writeInt(newFile, stats[i].total);
            }

            FileHelper::writeInt(newFile, gamesPlayed);
            FileHelper::writeInt(newFile, victories);

            for (auto i : crewStats)
            {
                FileHelper::writeInt(newFile, i.max);
                FileHelper::writeString(newFile, i.name);
                FileHelper::writeString(newFile, i.species);
                FileHelper::writeInt(newFile, i.male);
            }

            int length = FileHelper::fileLength(newFile);
            FileHelper::closeBinaryFile(newFile);

            if (length > 0 && FileHelper::fileExists(oldSave))
            {
                FileHelper::deleteFile(oldSave);
                FileHelper::renameFile(newSave, oldSave);
            }
            else
            {
                hs_log_file("!ERROR!: Something went wrong in saving Hyperspace profile!\n");
            }
        }
    }
    */
}

HOOK_METHOD(ScoreKeeper, OnInit, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ScoreKeeper::OnInit -> Begin (SaveFile.cpp)\n")
    std::string userFolder = FileHelper::getUserFolder();

    std::string newFile = userFolder;
    newFile.append(SaveFileHandler::instance->savePrefix + "_prof.sav");
    std::string fileName = userFolder;
    fileName.append("ae_prof.sav");

    readFromAe = true;
    bool aeFileExists = FileHelper::fileExists(fileName);
    readFromAe = false;

    SaveFileHandler::instance->firstTime = SaveFileHandler::instance->TransferFileExists();

    if (!FileHelper::fileExists(newFile) && aeFileExists)
    {
        readFromAe = true;
        int file = FileHelper::readBinaryFile(fileName);
        readFromAe = false;

        int fileLen = FileHelper::fileLength(file);
        char* bin = FileHelper::readBuffer(file, fileLen, false);
        FileHelper::closeBinaryFile(file);

        file = FileHelper::createBinaryFile(newFile);
        FileHelper::writeData(file, bin, fileLen);
        FileHelper::closeBinaryFile(file);

        SaveFileHandler::instance->firstTime = true;
    }

    super();

    std::string newSave = FileHelper::getUserFolder();
    newSave.append(SaveFileHandler::instance->savePrefix + "_prof.sav");

    if (FileHelper::fileExists(newSave))
    {
        *Global::showWelcome = false;
    }
}

HOOK_STATIC(FileHelper, readBinaryFile, (const std::string& fileName) -> int)
{
    LOG_HOOK("HOOK_STATIC -> FileHelper::readBinaryFile -> Begin (SaveFile.cpp)\n")
    if (boost::algorithm::ends_with(fileName, "ae_prof.sav") && !readFromAe)
    {
        std::string newFile = fileName;
        newFile.replace(fileName.size()-11, fileName.size(), SaveFileHandler::instance->savePrefix + "_prof.sav");

        return super(newFile);
    }

    return super(fileName);
}

HOOK_STATIC(FileHelper, fileExists, (const std::string& fileName) -> bool)
{
    LOG_HOOK("HOOK_STATIC -> FileHelper::fileExists -> Begin (SaveFile.cpp)\n")
    if (boost::algorithm::ends_with(fileName, "ae_prof.sav") && !readFromAe)
    {
        std::string newFile = fileName;
        newFile.replace(fileName.size()-11, fileName.size(), SaveFileHandler::instance->savePrefix + "_prof.sav");

        return super(newFile);
    }

    return super(fileName);
}


HOOK_STATIC(FileHelper, createBinaryFile, (const std::string& fileName) -> int)
{
    LOG_HOOK("HOOK_STATIC -> FileHelper::createBinaryFile -> Begin (SaveFile.cpp)\n")
    if (boost::algorithm::ends_with(fileName, "ae_prof.sav") && !readFromAe)
    {
        std::string newFile = fileName;
        newFile.replace(fileName.size()-11, fileName.size(), SaveFileHandler::instance->savePrefix + "_prof.sav");
        return super(newFile);
    }

    if (boost::algorithm::ends_with(fileName, "ae_prof.new.sav") && !readFromAe)
    {
        std::string newFile = fileName;
        newFile.replace(fileName.size()-15, fileName.size(), SaveFileHandler::instance->savePrefix + "_prof.new.sav");

        return super(newFile);
    }

    int ret = super(fileName);
    return ret;
}


HOOK_STATIC(FileHelper, getSaveFile, () -> std::string)
{
    LOG_HOOK("HOOK_STATIC -> FileHelper::getSaveFile -> Begin (SaveFile.cpp)\n")
    std::string str = super();

    str.replace(str.size()-12, str.size(), SaveFileHandler::instance->savePrefix + "_continue.sav");

    return str;
}

HOOK_STATIC(FileHelper, deleteAllSaveFiles, () -> void)
{
    LOG_HOOK("HOOK_STATIC -> FileHelper::deleteAllSaveFiles -> Begin (SaveFile.cpp)\n")
    deleteFile(FileHelper::getSaveFile()); // Because deleteAllSaveFiles in Linux inlines this, we just re-implement deleteALlSaveFiles
}

static ConfirmWindow* confirmWipeSave;
static WindowFrame* welcomeDialog;
static TextButton* welcomeDialogButton;
static bool welcomeDialogOpen;
static float welcomeDialogHeight;

HOOK_METHOD(MainMenu, constructor, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> MainMenu::constructor -> Begin (SaveFile.cpp)\n")
    super();
    confirmWipeSave = new ConfirmWindow();
}

HOOK_METHOD(MainMenu, Open, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> MainMenu::Open -> Begin (SaveFile.cpp)\n")
    super();
    /*
    std::string text = G_->GetTextLibrary()->GetText("transfer_save_dialog");
    auto printLines = freetype::easy_measurePrintLines(52, 0, 0, 400, text);

    welcomeDialogHeight = printLines.y + 10.f;

    welcomeDialog = new WindowFrame(0, 0, 410, printLines.y + 10.f);
    welcomeDialogButton = new TextButton();
    TextString welcomeDialogButtonText = TextString();
    //welcomeDialogButtonText.isLiteral = false;
    //welcomeDialogButtonText.data = "hyperspace_welcome_continue";

    welcomeDialogButtonText.isLiteral = false;
    welcomeDialogButtonText.data = "mainmenu_continue";
    Globals::Rect rect = Globals::Rect();

    rect.x = 440 + 220;
    rect.y = std::floor((720 - welcomeDialogHeight) / 2 + welcomeDialogHeight);
    rect.w = 170;
    rect.h = 32;
    welcomeDialogButton->OnInit(Point(0, 0), Point(100, 80), 4, &welcomeDialogButtonText, 63);
    */


    auto saveHandler = SaveFileHandler::instance;

    if (saveHandler->firstTime)
    {
        if (saveHandler->inheritMode == SaveFileHandler::InheritMode::FORCE_NEW)
        {
            G_->GetScoreKeeper()->WipeProfile(true);

            saveHandler->firstTime = false;
        }
        if (saveHandler->inheritMode == SaveFileHandler::InheritMode::ASK_PLAYER)
        {
            TextString text = TextString();
            TextString yes = TextString();
            TextString no = TextString();
            text.data = G_->GetTextLibrary()->GetText("transfer_save_dialog");
            text.isLiteral = true;
            yes.data =G_->GetTextLibrary()->GetText("transfer_save_yes");
            yes.isLiteral = true;
            no.data = G_->GetTextLibrary()->GetText("transfer_save_no");
            no.isLiteral = true;

            saveHandler->CreateTransferFile();

            confirmWipeSave->SetText(text, 400, true, yes, no);
            confirmWipeSave->Open();
        }
        else if (saveHandler->welcomeDialog)
        {
            welcomeDialogOpen = true;
        }
    }

    welcomeDialogOpen = true;
}

HOOK_METHOD(MainMenu, OnRender, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> MainMenu::OnRender -> Begin (SaveFile.cpp)\n")
    super();

    if (confirmWipeSave->bOpen)
    {
        confirmWipeSave->OnRender();
    }

    /*
    if (welcomeDialogOpen)
    {
        welcomeDialog->Draw(435, (720 - welcomeDialogHeight) / 2);
        freetype::easy_printNewlinesCentered(52, 440 + 200, (720 - welcomeDialogHeight) / 2 + 5, 400, G_->GetTextLibrary()->GetText("transfer_save_dialog"));
        welcomeDialogButton->OnRender();
    }
    */
}

HOOK_METHOD(MainMenu, MouseClick, (int x, int y) -> void)
{
    LOG_HOOK("HOOK_METHOD -> MainMenu::MouseClick -> Begin (SaveFile.cpp)\n")
    if (confirmWipeSave->bOpen)
    {
        confirmWipeSave->MouseClick(x, y);

        if (!confirmWipeSave->bOpen)
        {
            if (!confirmWipeSave->result)
            {
                G_->GetScoreKeeper()->WipeProfile(true);
            }

            SaveFileHandler::instance->firstTime = false;

            SaveFileHandler::instance->DeleteTransferFile();
        }

        return;
    }

    super(x, y);
}

HOOK_METHOD(MainMenu, MouseMove, (int x, int y) -> void)
{
    LOG_HOOK("HOOK_METHOD -> MainMenu::MouseMove -> Begin (SaveFile.cpp)\n")
    if (confirmWipeSave->bOpen)
    {
        confirmWipeSave->MouseMove(x, y);

        return;
    }

    super(x, y);
}
