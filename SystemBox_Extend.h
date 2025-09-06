#pragma once
#include "FTLGame.h"

struct SystemBox_Extend
{
public:
    SystemBox* orig = nullptr;

    // For custom systems by Silly 
    int xOffset = 36; //Offset from previous systembox
    //For ArtilleryBox
    Button artilleryButton;
    bool isArtillery = false;
    Point offset;

    // For Dino's touch stuff
	GL_Primitive* touchSystemIcon; // Contains the system icon
	GL_Primitive* scaledPcSystemIcon; // Contains the PC-like white icon 
	GL_Primitive* touchTimerCircle[10]; // Contains all lockdown textures from 1-9 & +
	GL_Primitive* touchTimerLines; // this is the actual texture of the countown lines
	GL_Primitive* touchTimerStencil; // this primitive clears the lines wheen counting down
    GL_Primitive* tappedBoxBottom;
    GL_Primitive* tappedBoxMiddle;
    GL_Primitive* tappedBoxSeparator;
    GL_Primitive* tappedBoxTop;



    ~SystemBox_Extend()
    {
        delete touchSystemIcon;
        delete touchTimerCircle[0];
        delete touchTimerCircle[1];
        delete touchTimerCircle[2];
        delete touchTimerCircle[3];
        delete touchTimerCircle[4];
        delete touchTimerCircle[5];
        delete touchTimerCircle[6];
        delete touchTimerCircle[7];
        delete touchTimerCircle[8];
        delete touchTimerCircle[9];
        delete touchTimerLines;
        delete touchTimerStencil;
    }
    
    void RenderTouchSystemSymbol();
};

SystemBox_Extend* Get_SystemBox_Extend(SystemBox* c);

#define SB_EX Get_SystemBox_Extend