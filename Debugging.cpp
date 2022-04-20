#include "Global.h"
#include <time.h>
#include <boost/algorithm/string.hpp>
#include <boost/format.hpp>
#include "CustomOptions.h"
#define BUILD_IDENTIFIER_HASH "unknown_build"
#include "Version.autogen.hpp"

#ifdef __linux__
    #ifdef __i386__
        #define BUILD_TGT " x86"
    #else
        #define BUILD_TGT " x64"
    #endif // __arch
#else
#define BUILD_TGT ""
#endif // __linux__

// Code for creation of FTL_HS.log and crashlogs

void copy_log(const char *oldName, const char *newName)
{
    FILE *f = fopen(oldName, "rb");
    fseek(f, 0, SEEK_END);
    long fsize = ftell(f);
    fseek(f, 0, SEEK_SET);

    char str[fsize + 1];
    fread(str, 1, fsize, f);
    fclose(f);

    str[fsize] = 0;

    auto file = fopen(newName, "w");

    if (file != nullptr)
    {
        fputs(str, file);
        fclose(file);
    }
}

#ifdef _WIN32
// Not Available in Linux version, or at least the crash handler is different and hasn't been figured out yet.
HOOK_STATIC(DebugHelper, CrashCatcher, (void *exception_pointers) -> int)
{
    LOG_HOOK("HOOK_STATIC -> DebugHelper::CrashCatcher -> Begin (Debugging.cpp)\n")
    int ret = super(exception_pointers);

    char ftlLogName[256];
    char hsLogName[256];

    time_t timer;
    time(&timer);
    auto localTime = localtime(&timer);

    strftime(ftlLogName, 256, "crashlogs/crash.%m.%d.%H.%M.log.txt", localTime);
    strftime(hsLogName, 256, "crashlogs/crash.%m.%d.%H.%M.hs_log.txt", localTime);

    copy_log("FTL.log", ftlLogName);
    copy_log("FTL_HS.log", hsLogName);

    return ret;
}
#endif // _WIN32

HOOK_METHOD(WorldManager, CreateChoiceBox, (LocationEvent *event) -> void)
{
    LOG_HOOK("HOOK_METHOD -> WorldManager::CreateChoiceBox -> Begin (Debugging.cpp)\n")
    hs_log_file("Creating event: %s\n", event->eventName.c_str());

    super(event);
}

HOOK_METHOD(WorldManager, CreateShip, (ShipEvent* shipEvent, bool boss) -> CompleteShip*)
{
    LOG_HOOK("HOOK_METHOD -> WorldManager::CreateShip -> Begin (Debugging.cpp)\n")

    auto ret = super(shipEvent, boss);

    hs_log_file("Creating ShipEvent: %s %s %s %s\n",
                 shipEvent->name.empty() ? ".." : shipEvent->name.c_str(),
                 shipEvent->blueprint.empty() ? ".." : shipEvent->blueprint.c_str(),
                 shipEvent->auto_blueprint.empty() ? ".." : shipEvent->auto_blueprint.c_str(),
                 ret && ret->shipManager->myBlueprint.blueprintName.empty() ?  ".." : ret->shipManager->myBlueprint.blueprintName.c_str());

    return ret;
}

static bool generatingEvents = false;

HOOK_METHOD(StarMap, GenerateEvents, (bool unk) -> void)
{
    LOG_HOOK("HOOK_METHOD -> StarMap::GenerateEvents -> Begin (Debugging.cpp)\n")
    hs_log_file("\n-- Generating Events --\n");

    if (!forceSectorChoice.empty())
    {
        hs_log_file("Sector: %s\n", forceSectorChoice.c_str());
    }
    else if (currentSector)
    {
        hs_log_file("Sector: %s\n", currentSector->description.type.c_str());
    }

    generatingEvents = true;
    super(unk);
    generatingEvents = false;

    hs_log_file("-- Done Generating Events --\n\n");
}

HOOK_METHOD(EventGenerator, GetBaseEvent, (const std::string& name, int worldLevel, char ignoreUnique, int seed) -> LocationEvent*)
{
    LOG_HOOK("HOOK_METHOD -> EventGenerator::GetBaseEvent -> Begin (Debugging.cpp)\n")
    if (generatingEvents)
    {
        hs_log_file("Getting Event: %s\n", name.c_str());
    }

    return super(name, worldLevel, ignoreUnique, seed);
}

HOOK_METHOD(StarMap, GenerateNebulas, (std::vector<std::string>& names) -> void)
{
    LOG_HOOK("HOOK_METHOD -> StarMap::GenerateNebulas -> Begin (Debugging.cpp)\n")
    hs_log_file("Generating nebulas: %s\n", boost::algorithm::join(names, ", ").c_str());

    super(names);
}

HOOK_METHOD(CApp, OnInit, () -> bool)
{
    LOG_HOOK("HOOK_METHOD -> CApp::OnInit -> Begin (Debugging.cpp)\n")
    bool ret = super();
    std::string date = __DATE__;
    std::string time = __TIME__;
    std::string identifier = BUILD_IDENTIFIER_HASH;
    std::string tgtSystem = BUILD_TGT;

    hs_log_file(boost::str(boost::format("Hyperspace: v%s%s %s Compiled: %s %s\n") % G_->GetVersionString() % tgtSystem % identifier % date % time).c_str());
    return ret;
}

HOOK_METHOD(MouseControl, OnRender, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> MouseControl::OnRender -> Begin (Debugging.cpp)\n")
    std::string identifier = BUILD_IDENTIFIER_HASH;
    std::string tgtSystem = BUILD_TGT;
    if(CustomOptionsManager::GetInstance()->altMode)
    {
        freetype::easy_printRightAlign(51, 1280.f, 0.f, boost::str(boost::format("HS-%s%s %s") % G_->GetVersionString() % tgtSystem % identifier).c_str());
    }
    super();
}

HOOK_METHOD(ResourceControl, RenderLoadingBar, (float initialProgress, float finalProgress) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ResourceControl::RenderLoadingBar -> Begin (Debugging.cpp)\n")
    std::string identifier = BUILD_IDENTIFIER_HASH;
    std::string tgtSystem = BUILD_TGT;
    freetype::easy_printRightAlign(51, 1280.f, 0.f, boost::str(boost::format("HS-%s%s %s") % G_->GetVersionString() % tgtSystem % identifier).c_str());
    super(initialProgress, finalProgress);
}
