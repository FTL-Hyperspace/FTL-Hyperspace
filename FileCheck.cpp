#include "FileCheck.h"

bool checkedHashes = false;

#ifdef DEBUG
void PrintHashes()
{
    SHA3 sha3;

    for (auto f : resourceFiles)
    {
        char* s = G_->GetResources()->LoadFile("data/" + f);
        hs_log_file("{\"%s\", \"%s\"},\n", f.c_str(), sha3(s, strlen(s)).c_str());
    }
}
#endif // DEBUG

#ifndef DEBUG
void CheckHashes()
{
    SHA3 sha3;
    for (auto const& f : hashKey)
    {
        char* s = G_->GetResources()->LoadFile("data/" + f.first);

        std::string sha256 = sha3(s, strlen(s));

        if (sha256 != f.second)
        {
            MessageBoxA(GetDesktopWindow(), "Wrong version of Irie Series Modpack detected. Please check that you are using the correct version of Hyperspace and the modpack.", "Error", MB_ICONERROR | MB_SETFOREGROUND);
            exit(1);
        }
    }
}
#endif // DEBUG

HOOK_METHOD_PRIORITY(AchievementTracker, LoadAchievementDescriptions, 1000, () -> void)
{
    if (!checkedHashes)
    {
        #ifdef DEBUG
        PrintHashes();
        #endif // DEBUG
        #ifndef DEBUG
        CheckHashes();
        #endif // DEBUG
        checkedHashes = true;
    }

    super();
}
