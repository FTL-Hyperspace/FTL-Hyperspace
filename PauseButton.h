#pragma once
#include "FTLGame.h"
#include <cstdint>

struct PauseButton
{
    PauseButton()
    {
        this->constructor3();
    }
    PauseButton(GL_Primitive* baseImg, GL_Primitive* topImg)
    {
        this->constructor2(baseImg, topImg);
    }
    PauseButton(const std::string& baseImg, const std::string& topImg)
    {
        this->constructor1(baseImg, topImg);
    }
    ~PauseButton()
    {
        delete pauseButtonBase;
        delete pauseButtonTop;
    }

    void constructor1(const std::string& baseImg, const std::string& topImg);
    void constructor2(GL_Primitive* baseImg, GL_Primitive* topImg);
    void constructor3();

    void OnRender(bool flash);
    void OnLanguageChange();
    bool OnTouch(TouchAction action, int id, int x, int y, int initialX, int initialY);
    void MouseClick(int mX, int mY);
    void MouseMove(int mX, int mY);
    inline bool Hovering() {return bActive && bHover;}

	Point position;
	Globals::Rect hitbox;
    std::string text;
    GL_Color white;
    GL_Color yellow;
    GL_Color grey;
    GL_Primitive* pauseButtonBase = nullptr;
    GL_Primitive* pauseButtonTop = nullptr;
    float animDuration;
    float animState;
    float anim_ex;
	bool bActive;
	bool bHover;
    uint8_t font;
    uint8_t yTextShift;
	int activeTouch;
};
