#pragma once
#include "FTLGame.h"

struct ArmamentControl_Extend
{
public:
    ArmamentControl* orig = nullptr;
    
    GL_Primitive* touchWeaponBoxTop;
    GL_Primitive* touchWeaponBoxMid;
    GL_Primitive* touchWeaponBoxBottom;
    GL_Primitive* touchWeaponBoxSingle;

    ~ArmamentControl_Extend()
    {
        delete touchWeaponBoxTop;
        delete touchWeaponBoxMid;
        delete touchWeaponBoxBottom;
    }
};

ArmamentControl_Extend* Get_ArmamentControl_Extend(ArmamentControl* c);

#define AC_EX Get_ArmamentControl_Extend