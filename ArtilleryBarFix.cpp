#include "Global.h"

HOOK_METHOD(ArtilleryBox, OnRender, (bool ignoreStatus) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ArtilleryBox::OnRender -> Begin (ArtilleryBarFix.cpp)\n")
    CooldownSystemBox::OnRender(ignoreStatus);

    CSurface::GL_PushMatrix();
    CSurface::GL_Translate(buttonOffset.x, buttonOffset.y);

    int power = std::max(1, artSystem->GetEffectivePower());
    auto weapon = artSystem->projectileFactory;

    float frac = weapon->cooldown.first / weapon->cooldown.second;
    auto backTex = G_->GetResources()->GetImageId("systemUI/button_artillery_" + std::to_string(power) + ".png");

    CSurface::GL_BlitPixelImage(backTex, 0.f, 0.f, 23.f, 75.f, 0.f, COLOR_WHITE, false);

    GL_Color color = COLOR_WHITE;

    if (artSystem->iHackEffect > 1 && artSystem->bUnderAttack)
    {
        color = GL_Color(207.f / 255.f, 70.f / 255.f, 253.f / 255.f, 1.f);
    }

    int barHeight = std::floor(frac * 10.f * (6 - power));

    CSurface::GL_DrawRect(9.f, 59.f, 5.f, -barHeight, color);

    CSurface::GL_PopMatrix();
}
