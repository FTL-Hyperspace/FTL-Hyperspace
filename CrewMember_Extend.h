#ifndef CM_EX
#include "FTLGame.h"

struct CrewMember_Extend
{
    CrewMember *orig;
    bool canPhaseThroughDoors = false;
    bool isHealing = false;
    TimerHelper* passiveHealTimer;
    //bool isCaptain;
};

CrewMember_Extend* Get_CrewMember_Extend(CrewMember* c);

#define CM_EX Get_CrewMember_Extend
#endif
