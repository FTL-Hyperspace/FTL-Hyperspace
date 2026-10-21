#pragma once

// Logs the game, OS and renderer details that bug reports need
#include <string>

namespace SystemInfo
{
    std::string Describe();
    void Log();
}
