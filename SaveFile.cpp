#include "Global.h"

#include <boost/algorithm/string/predicate.hpp>
#include <boost/algorithm/string/replace.hpp>

static bool readFromAe = false;

HOOK_STATIC(FileHelper, readBinaryFile, (const std::string& fileName) -> int)
{
    if (boost::algorithm::ends_with(fileName, "ae_prof.sav") && !readFromAe)
    {
        std::string newFile = fileName;
        newFile.replace(fileName.size()-11, fileName.size(), "hs_prof.sav");

        return super(newFile);
    }

    return super(fileName);
}

HOOK_METHOD(ScoreKeeper, Save, (bool saveScore) -> void)
{


    std::string userFolder;
    FileHelper::getUserFolder(userFolder);

    super(saveScore);

    std::string newSave = userFolder;
    std::string oldSave = userFolder;



    newSave.append("hs_prof.new.sav");
    oldSave.append("hs_prof.sav");

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
}

HOOK_METHOD(ScoreKeeper, OnInit, () -> void)
{
    std::string userFolder;
    FileHelper::getUserFolder(userFolder);

    std::string newFile = userFolder;
    newFile.append("hs_prof.sav");
    std::string fileName = userFolder;
    fileName.append("ae_prof.sav");

    if (!FileHelper::fileExists(newFile) && FileHelper::fileExists(fileName))
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
    }

    super();

    std::string newSave;

    FileHelper::getUserFolder(newSave);
    newSave.append("hs_prof.sav");

    if (FileHelper::fileExists(newSave))
    {
        *Global::showWelcome = false;
    }
}

HOOK_STATIC(FileHelper, fileExists, (const std::string& fileName) -> bool)
{
    if (boost::algorithm::ends_with(fileName, "ae_prof.sav") && !readFromAe)
    {
        std::string newFile = fileName;
        newFile.replace(fileName.size()-11, fileName.size(), "hs_prof.sav");

        return super(newFile);
    }

    return super(fileName);
}


HOOK_STATIC(FileHelper, createBinaryFile, (const std::string& fileName) -> int)
{


    if (boost::algorithm::ends_with(fileName, "ae_prof.sav") && !readFromAe)
    {
        std::string newFile = fileName;
        newFile.replace(fileName.size()-11, fileName.size(), "hs_prof.sav");
        return super(newFile);
    }

    if (boost::algorithm::ends_with(fileName, "ae_prof.new.sav") && !readFromAe)
    {
        std::string newFile = fileName;
        newFile.replace(fileName.size()-15, fileName.size(), "hs_prof.new.sav");

        return super(newFile);
    }

    int ret = super(fileName);
    return ret;
}


HOOK_STATIC(FileHelper, getSaveFile, (std::string& str) -> std::string&)
{
    auto ret = super(str);

    str.replace(str.size()-12, str.size(), "hs_continue.sav");

    return ret;
}
