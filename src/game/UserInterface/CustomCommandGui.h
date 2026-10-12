#pragma once
#include "Global.h"

class CustomCommandGui
{
public:
    static CustomCommandGui* GetInstance()
    {
        return &instance;
    }

    void OnScrollWheel(float direction);
    void OnInit();
    void MouseMove(int mX, int mY);
    void LButtonDown(int mX, int mY, bool shiftHeld);
    void RButtonUp(int mX, int mY, bool shiftHeld);

    Button* crewUpButton;
    Button* crewDownButton;
    CommandGui *gui;
    int currentCrewPage = 0;
    int maxPage = 0;

    CrewMember *draggingCrewMember = nullptr;

private:

    static CustomCommandGui instance;
};
