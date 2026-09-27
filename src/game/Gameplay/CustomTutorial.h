#pragma once
#include "Global.h"


struct CustomTutorialState
{
    static bool allowJumping;
    static bool allowUpgrades;
};

struct TutorialArrow
{
    TutorialArrow(Pointf _position, float _rotation) : position(_position), rotation(_rotation)
    {
        arrow = G_->GetTutorialManager()->arrow;
        arrow2 = G_->GetTutorialManager()->arrow2;
    }

    void OnRender();

    GL_Texture *arrow;
    GL_Texture *arrow2;
    Pointf position;
    Pointf blitSize = Pointf(164.f, 38.f);
    float rotation;
    GL_Color arrow_color = COLOR_WHITE;
    GL_Color arrow2_color = COLOR_WHITE;
};
