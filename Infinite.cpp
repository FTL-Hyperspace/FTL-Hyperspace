#include "Infinite.h"
#include "Global.h"

bool g_infiniteMode = false;

HOOK_METHOD(StarMap, GenerateSectorMap, () -> void)
{
    if (g_infiniteMode)
    {
        this->bInfiniteMode = true;
    }

    super();
}

HOOK_METHOD(ResourceControl, RenderImageString, (std::string& tex, int x, int y, int rotation, GL_Color color, float opacity, bool mirror) -> int)
{
    if (tex == "map/sector_box.png" && g_infiniteMode)
    {
        tex.assign("map/sector_box_infinite.png");
        x = 268;
    }

    return super(tex, x, y, rotation, color, opacity, mirror);
}
