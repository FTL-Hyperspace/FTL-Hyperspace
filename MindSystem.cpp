#include "MindSystem.h"
#include <algorithm>

HOOK_METHOD(CrewControl, SelectPotentialCrew, (CrewMember *crew, bool allowTeleportLeaving) -> void)
{
    if (!crew) return;

    if (!crew->GetControllable()) return;

    if (allowTeleportLeaving || (crew->crewAnim->status != 6) || crew->crewAnim->anims[0][6].tracker.reverse)
    {
        if (std::find(potentialSelectedCrew.begin(), potentialSelectedCrew.end(), crew) == potentialSelectedCrew.end())
        {
            potentialSelectedCrew.push_back(crew);
        }
    }
}
