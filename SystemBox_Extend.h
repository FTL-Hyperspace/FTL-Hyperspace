#pragma once
#include "Global.h"
struct SystemBox_Extend
{
    SystemBox* orig = nullptr;
    int xOffset = 36; //Offset from previous systembox

    virtual ~SystemBox_Extend() {}; //Virtual destructor

    //Input events that aren't handled by the native SystemBox class
    virtual void OnScrollWheel(float direction);
    virtual void RButtonUp(int mX, int mY, bool shiftHeld);
};

struct ArtilleryBox_Extend : SystemBox_Extend
{
    Button artilleryButton;
    Point offset;
};

struct CloneBox_Extend : SystemBox_Extend
{
    Button pageUp;
    Button pageDown;
    int displayShift = 0;
    CrewMember* selectedCrew = nullptr;
    int hoverCrew = -1;
    int newCrewIdx = 0;

    virtual void OnScrollWheel(float direction);
    virtual void RButtonUp(int mX, int mY, bool shiftHeld);
};

SystemBox_Extend* Get_SystemBox_Extend(SystemBox* c);

#define SB_EX Get_SystemBox_Extend
