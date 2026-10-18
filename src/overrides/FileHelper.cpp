#include "FileHelper.h"


void FileHelperExtension::setUserFolder(const std::string& folder) {
    user_folder_override = folder;
}

void FileHelperExtension::setContinueFile(const std::string& filename) {
    continue_file_override = filename;
}

#ifdef HS_ANDROID
#include <fcntl.h>
#include <unistd.h>

// The iPad build has no separate getUserFolder or getSaveFile to hook (they're inlined
// where it uses them), so Hyperspace provides them, overrides included, along with the
// other file helpers the iPad build doesn't have on their own. Real file descriptors
// work with the game's readData, writeData and closeBinaryFile.
std::string FileHelper::getUserFolder()
{
    if (!user_folder_override.empty()) return user_folder_override;
    return std::string(userdata_get_data_path());
}

std::string FileHelper::getSaveFile()
{
    std::string continueFile = continue_file_override.empty()
        ? SaveFileHandler::instance->savePrefix + "_continue.sav" : continue_file_override;
    return FileHelper::getUserFolder() + continueFile;
}

bool FileHelper::fileExists(const std::string& fileName)
{
    return access(fileName.c_str(), F_OK) == 0;
}

void FileHelper::renameFile(const std::string& fileName, const std::string& newName)
{
    rename(fileName.c_str(), newName.c_str());
}

void FileHelper::deleteFile(const std::string& fileName)
{
    if (fileExists(fileName)) remove(fileName.c_str());
}

int FileHelper::createBinaryFile(const std::string& fileName)
{
    deleteFile(fileName);
    return open(fileName.c_str(), O_RDWR | O_CREAT, 0640);
}

int FileHelper::readBinaryFile(const std::string& fileName)
{
    return open(fileName.c_str(), O_RDONLY);
}

char* FileHelper::readBuffer(int file, int len, bool nullTerminate)
{
    char *buffer = new char[len + (nullTerminate ? 1 : 0)];
    FileHelper::readData(file, buffer, len);
    if (nullTerminate) buffer[len] = 0;
    return buffer;
}
#else
// Override getUserFolder to use custom path when specified
HOOK_STATIC(FileHelper, getUserFolder, () -> std::string) {
    LOG_HOOK("HOOK_STATIC -> FileHelper::getUserFolder -> Begin (overrides/FileHelper.cpp)\n")
    
    if (!user_folder_override.empty()) {
        return user_folder_override;
    }
    
    return super();
}


/* Old getSaveFile Hook implementation:
    std::string str = super();
    str.replace(str.size()-12, str.size(), SaveFileHandler::instance->savePrefix + "_continue.sav");
    return str;
}*/

//  FileHelper::getSaveFile() (must return folder + prefix + "continue.sav")
HOOK_STATIC(FileHelper, getSaveFile, () -> std::string) {
    LOG_HOOK("HOOK_STATIC -> FileHelper::getSaveFile -> Begin (overrides/FileHelper.cpp)\n")

    
    std::string userFolder = FileHelper::getUserFolder();
    std::string savePrefix = SaveFileHandler::instance->savePrefix;
    // Default: userFolder + savePrefix + "_continue.sav"

    std::string continueFile;
    if (!continue_file_override.empty()) {
        continueFile = continue_file_override;
    } else {
        
        continueFile = savePrefix + "_continue.sav";
    }

    
    return userFolder + continueFile;
}
#endif // HS_ANDROID
