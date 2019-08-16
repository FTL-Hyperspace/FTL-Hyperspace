#include "Global.h"


HOOK_METHOD(MainMenu, OnRender, () -> void)
{

    super();
    if (this->bCreditScreen) return;

    if (this->bScoreScreen || this->optionScreen.bOpen || this->bSelectSave || this->bChangedLogin)
    {
        CSurface::GL_SetColorTint(0.15, 0.15, 0.15, 1);
    }
    std::string str("Hyperspace");
    freetype::easy_print(10, 10, 700, str);
    CSurface::GL_RemoveColorTint();
}

