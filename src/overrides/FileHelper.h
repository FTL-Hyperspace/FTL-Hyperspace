#include "Global.h"
#include "SaveFile.h"

#include <string>

namespace {
    // Anonymous namespace for internal linkage
    std::string user_folder_override = "";
    std::string continue_file_override = "";
}

// Extension to allow setting user folder override
struct FileHelperExtension : public FileHelper {
    static void setUserFolder(const std::string& folder);
    static void setContinueFile(const std::string& filename);
};
