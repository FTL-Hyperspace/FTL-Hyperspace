#include "PauseButton.h"
#include "FTLGameELF64.h"
#include "Global.h"

void PauseButton::constructor1(const std::string& baseImg, const std::string& topImg)
{
    pauseButtonBase = G_->GetResources()->CreateImagePrimitiveString(baseImg, 0, 0, 0, COLOR_WHITE, 1.f, false);
    pauseButtonTop = G_->GetResources()->CreateImagePrimitiveString(topImg, 0, 0, 0, COLOR_WHITE, 1.f, false);
    this->constructor3();
}

void PauseButton::constructor2(GL_Primitive* baseImg, GL_Primitive* topImg)
{
    this->pauseButtonBase = baseImg;
    this->pauseButtonTop = topImg;
    this->constructor3();
}

void PauseButton::constructor3()
{
    this->position = Point(1101, 641);
    this->hitbox = Globals::Rect(position.x + 4, position.y + 4, 160, 60);
    this->white = GL_Color(235.f / 255, 245.f / 255, 229.f / 255, 1.f);
    this->yellow = GL_Color(1.f, 230.f / 255, 94.f / 255, 1.f); // GL_Color(247.f / 255, 203.f / 255, 42.f / 255, 1.f); // old yellow used on older iPad versions
    this->grey = GL_Color(164.f / 255, 171.f / 255, 160.f / 255, 1.f);
    this->text = G_->GetTextLibrary()->GetText("button_pause", G_->GetTextLibrary()->currentLanguage);
    this->animDuration = 1.f;
    this->anim_ex = 2.5f;
    this->animState = 0.f;
    this->bActive = true;
    this->bHover = false;
    this->activeTouch = -1;
}

void PauseButton::OnRender(bool flash)
{
    // Color flashing (has to run all the time even if not displayed)
    this->animState += G_->GetCFPS()->GetSpeedFactor() * (0.0625f * this->anim_ex);
    if (this->animState >= this->animDuration) 
    {
        this->animState = this->animDuration;
        this->anim_ex = -this->anim_ex;
    }
    else if (this->animState <= 0.f)
    {
        this->animState = 0.f;
        this->anim_ex = -this->anim_ex;
    }

    // Prepare rendering actions
    CSurface::GL_PushMatrix();
    CSurface::GL_Translate(this->position.x, this->position.y);

    // Render the button base (frame)
    if (this->pauseButtonBase)
    {
        CSurface::GL_RenderPrimitive(this->pauseButtonBase);
    }

    // Determine the color for the top button
    GL_Color topColor;
    if (this->bActive)
    {
        if (this->bHover)
        {
            topColor = this->yellow;
        }
        else
        {
            topColor = flash ? GL_Color::Lerp(this->white, this->yellow, this->animState) : this->white;
        }
    }
    else
    {
        topColor = this->grey;
    }

    // Render the top button with the determined color
    if (this->pauseButtonTop)
    {
        CSurface::GL_RenderPrimitiveWithColor(this->pauseButtonTop, topColor);
    }

    // Render the text
    CSurface::GL_SetColor(GL_Color(53.f / 255, 75.f / 255, 89.f / 255, 1.f));
    freetype::easy_printCenter(font, 84, 14 + this->yTextShift, this->text);

    CSurface::GL_PopMatrix();
}

void PauseButton::OnLanguageChange()
{
    if (G_->GetTextLibrary()->currentLanguage == "ru" || G_->GetTextLibrary()->currentLanguage == "pl")
    {
        this->font = 63;
        this->yTextShift = 5;
    }
    else if (G_->GetTextLibrary()->currentLanguage == "ja")
    {
        this->font = 64;
        this->yTextShift = 1;
    }
    else
    {
        this->font = 64;
        this->yTextShift = 0;
    }
    
    this->text = G_->GetTextLibrary()->GetText("button_pause", G_->GetTextLibrary()->currentLanguage);
}

bool PauseButton::OnTouch(TouchAction action, int id, int x, int y, int initialX, int initialY)
{
    switch (action) 
    {
        case TOUCH_UP:
            this->bHover = false;
            this->activeTouch = 0;
            if (this->hitbox.Contains(x, y))
            {
                return true;
            }
        case TOUCH_DOWN:
            if (this->hitbox.Contains(x, y))
            {
                this->activeTouch = id;
                this->bHover = true;
            }
            return false;
        case TOUCH_MOVE:
            if (this->hitbox.Contains(x, y))
            {
                this->activeTouch = id;
                this->bHover = true;
            }
            else
            {
                this->bHover = false;
                this->activeTouch = 0;
            }
            return false;
        case TOUCH_CANCEL:
            this->bHover = false;
            this->activeTouch = 0;
            return false;
    }
}

void PauseButton::MouseClick(int mX, int mY)
{
    return;
}

void PauseButton::MouseMove(int mX, int mY)
{
    return;
}
