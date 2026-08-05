#include "FileSystem.h"
#include <cstdlib>

namespace TestFramework
{
    void FileSystem::ensureDirectory(const std::string& path)
    {
        #ifdef __APPLE__
            system(("mkdir -p " + path).c_str());
        #elif defined(__linux__)
            system(("mkdir -p " + path).c_str());
        #elif defined(_WIN32)
            system(("mkdir " + path + " 2>nul").c_str());
        #endif
    }
}
