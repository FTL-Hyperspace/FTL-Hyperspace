#include "Global.h"


HOOK_METHOD(MainMenu, OnRender, () -> void)
{

    super();
    if (this->bCreditScreen || this->shipBuilder.bOpen) return;

    if (this->bScoreScreen || this->optionScreen.bOpen || this->bSelectSave || this->bChangedLogin)
    {
        GL_Color tint = GL_Color(0.15, 0.15, 0.15, 1);
        CSurface::GL_SetColorTint(tint);
    }
    std::string str("Hyperspace");
    freetype::easy_print(10, 10, 700, str);
    CSurface::GL_RemoveColorTint();
}

