#include "Global.h"
#include "FTLGame.h"
#include "CrewNames.h"

static bool inGetUnusedCrewName = false;
static std::mt19937 crewNameRng;

HOOK_GLOBAL_PRIORITY(random32, -900, () -> unsigned int)
{
    if (inGetUnusedCrewName) return crewNameRng() >> 1;

    return super();
}

HOOK_METHOD(BlueprintManager, GetUnusedCrewName, (bool* isMale_ret) -> std::string)
{
    LOG_HOOK("HOOK_METHOD -> BlueprintManager::GetUnusedCrewName -> Begin (CrewNames.cpp)\n")
    crewNameRng = std::mt19937(random32());

    inGetUnusedCrewName = true;
    std::string ret = super(isMale_ret);
    inGetUnusedCrewName = false;
    return ret;
}
