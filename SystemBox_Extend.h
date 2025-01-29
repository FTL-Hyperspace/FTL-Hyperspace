#pragma once
#include "Global.h"
struct SystemBox_Extend
{
    SystemBox* orig = nullptr;
    //For ArtilleryBox
    Button artilleryButton;
    bool isArtillery = false;
    Point offset;
};

SystemBox_Extend* Get_SystemBox_Extend(SystemBox* c);

#define SB_EX Get_SystemBox_Extend
