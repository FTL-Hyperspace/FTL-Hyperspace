#include "Saves.h"
#include "State.h"
#include "../../../Global.h"
#include "../../../src/overrides/FileHelper.h"
#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;

namespace GameAccess
{

    bool Saves::loadTestSave(const std::string& saveName)
    {
        fs::path savePath = fs::path(getTestSavePath()) / saveName;
        FileHelperExtension::setUserFolder(savePath.string() + "/");
        return true;
    }

    std::string Saves::getTestSavePath()
    {
        return fs::path("saves").string();
    }

    bool Saves::createNewSave(const std::string& saveName)
    {
        fs::path savePath = fs::path(getTestSavePath()) / saveName;
        return fs::create_directories(savePath);
    }

}
