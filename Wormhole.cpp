#include "Global.h"

static Location *wormhole;
static GL_Texture *wormholeTexture;

/*
HOOK_METHOD(StarMap, constructor, () -> void)
{
    super();
    wormholeTexture = G_->GetResources()->GetImageId("hyperspace/map/map_icon_wormhole.png");
}

HOOK_METHOD(StarMap, GenerateMap, (bool unk1, bool seed) -> Location*)
{
    auto ret = super(unk1, seed);

    if (currentSector->level > 0)
    {
        Location* rightmost = 0;

        for (auto const& location: locations)
        {
            if (((rightmost && location->loc.x > rightmost->loc.x) || (!rightmost)) && !location->beacon)
            {
                rightmost = location;
            }
        }

        wormhole = rightmost;

        if (wormhole)
        {
            wormhole->event = G_->GetEventGenerator()->GetBaseEvent("WORMHOLE", 0, 0, -1);
        }
    }


    return ret;
}


HOOK_METHOD(StarMap, OnRender, () -> void)
{
    super();

    //endButton.bActive = false;

    if (currentSector->level > 0 && wormhole && wormholeTexture && !bChoosingNewSector)
    {
        CSurface::GL_PushMatrix();
        CSurface::GL_Translate(position.x, position.y, 0);
        CSurface::GL_Translate(translation.x, translation.y, 0);

        auto tex = wormholeTexture;


        G_->GetResources()->RenderImage(tex, std::floor(wormhole->loc.x - tex->width_ / 2), std::floor(wormhole->loc.y - tex->height_ / 2), 0, COLOR_WHITE, 1.f, false);
        CSurface::GL_PopMatrix();
    }
}
*/
