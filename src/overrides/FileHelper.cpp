#include "FileHelper.h"


void FileHelperExtension::setUserFolder(const std::string& folder) {
    user_folder_override = folder;
}

void FileHelperExtension::setContinueFile(const std::string& filename) {
    continue_file_override = filename;
}

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
