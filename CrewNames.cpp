#include "Global.h"
#include "FTLGame.h"
#include "CrewNames.h"

static bool inGetUnusedCrewName = false;
static std::mt19937 crewNameRng;

HOOK_GLOBAL_PRIORITY(random32, -900, () -> int)
{
    if (inGetUnusedCrewName) return crewNameRng() >> 1;

    return super();
}

HOOK_STATIC(BlueprintManager, GetUnusedCrewName, (std::string& ref, BlueprintManager* bpM, bool* isMale_ret) -> void)
{
    crewNameRng = std::mt19937(random32());

    inGetUnusedCrewName = true;
    super(ref, bpM, isMale_ret);
    inGetUnusedCrewName = false;
}
