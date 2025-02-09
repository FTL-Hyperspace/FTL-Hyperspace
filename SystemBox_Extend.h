#pragma once
#include "FTLGame.h"
struct SystemBox_Extend
{
    SystemBox* orig = nullptr;
    int xOffset = 36; //Offest from previous systembox
};

SystemBox_Extend* Get_SystemBox_Extend(SystemBox* c);

#define SB_EX Get_SystemBox_Extend
