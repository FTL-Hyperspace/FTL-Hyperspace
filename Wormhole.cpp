#include "Global.h"

static Location *wormhole;
static GL_Texture *wormholeTexture;
static AnimationTracker *wormholeTracker;

HOOK_METHOD(StarMap, constructor, () -> void)
{
    super();

    std::string dir("hyperspace/map/map_icon_wormhole.png");
    wormholeTexture = G_->GetResources()->GetImageId(dir);

}

HOOK_METHOD(StarMap, GenerateMap, (bool unk1, bool seed) -> Location*)
{
    auto ret = super(unk1, seed);

    if (this->currentSector->level > 0)
    {
        Location* rightmost = 0;

        for (auto const& location: this->locations)
        {
            if (((rightmost && location->loc.x > rightmost->loc.x) || (!rightmost)) && !location->beacon)
            {
                rightmost = location;
            }
        }

        wormhole = rightmost;
    }


    return ret;
}


HOOK_METHOD(StarMap, OnRender, () -> void)
{
    super();

    //printf("%d %d\n", wormhole, wormholeTexture);

    if (this->currentSector->level > 0 && wormhole && wormholeTexture)
    {
        CSurface::GL_PushMatrix();
        CSurface::GL_Translate(this->position.x, this->position.y, 0);
        CSurface::GL_Translate(this->translation.x, this->translation.y, 0);

        auto tex = wormholeTexture;


        G_->GetResources()->RenderImage(tex, std::floor(wormhole->loc.x - tex->width_ / 2), std::floor(wormhole->loc.y - tex->height_ / 2), 0, COLOR_WHITE, 1.f, false);
        CSurface::GL_PopMatrix();
    }

}
