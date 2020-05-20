#ifndef CM_EX
#include "FTLGame.h"

struct CrewMember_Extend
{
    CrewMember *orig;
    bool canPhaseThroughDoors = false;
    bool isHealing = false;
    TimerHelper* passiveHealTimer;
    int lastRoom = -1;
    int lastShipId = -1;
    bool exploded = false;
    bool triggerExplosion = false;
    //bool isCaptain;
};

CrewMember_Extend* Get_CrewMember_Extend(CrewMember* c);

#define CM_EX Get_CrewMember_Extend
#endif
