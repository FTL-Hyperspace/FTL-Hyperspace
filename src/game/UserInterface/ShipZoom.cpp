#include "ShipZoom.h"

/*
static float testVal = 0;

void OnScrollWheelZoom(float dir)
{
    if (dir == -1.f)
    {
        testVal += 0.1;
    }
    if (dir == 1.f)
    {
        testVal -= 0.1f;
    }
}

static bool renderingTarget = false;


HOOK_METHOD(CompleteShip, OnRenderShip, (bool unk1, bool unk2) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CompleteShip::OnRenderShip -> Begin (ShipZoom.cpp)\n")
    if (renderingTarget)
    {
        CSurface::GL_PushMatrix();
        CSurface::GL_Scale(1.f + testVal, 1.f + testVal, 1.f);
        super(unk1, unk2);
        CSurface::GL_PopMatrix();

        return;
    }

    super(unk1, unk2);
}

HOOK_METHOD(CombatControl, RenderTarget, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CombatControl::RenderTarget -> Begin (ShipZoom.cpp)\n")
    renderingTarget = true;
    super();
    renderingTarget = false;
}
*/
