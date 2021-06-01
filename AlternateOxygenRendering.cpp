#include "CustomOptions.h"

HOOK_METHOD(Room, OnRenderFloor, (float alpha, bool experimental) -> void)
{
    if (CustomOptionsManager::GetInstance()->alternateOxygenRendering.currentValue == true)
    {
        GL_Color newColor;
        newColor.r = (this->lastO2 * 2.55 * (230.0/255)) / 255;
        newColor.g = (this->lastO2 * 2.55 * (226.0/255)) / 255;
        newColor.b = (255 * (219.0/255)) / 255;
//        printf("%f is lastO2 ", this->lastO2);
        return CSurface::GL_RenderPrimitiveWithColor(this->floorPrimitive, newColor);
    }
    else
    {
        super(alpha, experimental);
    }
}
