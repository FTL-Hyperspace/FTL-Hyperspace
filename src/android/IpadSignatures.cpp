// Game functions whose iPad version takes different arguments from the PC one that
// Hyperspace's hooks are written for. The hooks here have the lowest priority, so they
// run before any of Hyperspace's others and hand them what the PC game would have.

#include "Global.h"

// The iPad's StarMap::GetLocationText takes no location: it always describes hoverLoc,
// the beacon being touched, and its callers leave the location argument unset. Hand
// hoverLoc down to Hyperspace's hooks (and Lua's GET_BEACON_HAZARD), which read it.
HOOK_METHOD_PRIORITY(StarMap, GetLocationText, -10000, (const Location* loc) -> std::string)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> StarMap::GetLocationText -> Begin (IpadSignatures.cpp)\n")
    return super(hoverLoc);
}
