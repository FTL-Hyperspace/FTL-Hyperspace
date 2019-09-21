#include "MainMenu.h"
#include "Global.h"

extern bool g_titleScreen = false;


HOOK_METHOD(MainMenu, Open, () -> void)
{
    itbButtonActive = false;

    super();
}


HOOK_METHOD(ResourceControl, RenderImage, (GL_Texture* tex, int x, int y, int rotation, GL_Color color, float opacity, bool mirror) -> int)
{
    if (g_titleScreen)
    {
        if (tex == G_->GetCApp()->menu.glowy)
        {
            return super(tex, x + 42, y - 53, rotation, color, opacity, mirror);
        }
    }

    return super(tex, x, y, rotation, color, opacity, mirror);
}

HOOK_METHOD(ResourceControl, GetImageId, (const std::string& dir) -> GL_Texture*)
{
    if (g_titleScreen)
    {
        if (dir == "main_menus/main_base2.png")
        {
            return super("main_menus/main_base2_hyperspace.png");
        }
        if (dir == "main_menus/main_FTL2.png")
        {
            return super("main_menus/main_FTL2_hyperspace.png");
        }
    }

    return super(dir);
}
