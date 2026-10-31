#include "Global.h"

HOOK_METHOD_PRIORITY(StarMap, GetLocationText, -10000, (const Location* loc) -> std::string)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> StarMap::GetLocationText -> Begin (IpadSignatures.cpp)\n")
    return super(hoverLoc);
}
