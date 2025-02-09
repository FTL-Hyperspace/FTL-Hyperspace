#pragma once
#include "Global.h"
struct SystemBox_Extend
{
    SystemBox* orig = nullptr;
    int xOffset = 36; //Offset from previous systembox
    //For ArtilleryBox
    Button artilleryButton;
    bool isArtillery = false;
    Point offset;
};

SystemBox_Extend* Get_SystemBox_Extend(SystemBox* c);

#define SB_EX Get_SystemBox_Extend
