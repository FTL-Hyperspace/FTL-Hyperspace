#include "Global.h"
#include "CustomCrew.h"
#include "ShipUnlocks.h"
#include "EnemyShipIcons.h"
#include "CustomOptions.h"

// Plays airlock sound when crew have been "dismissed"

HOOK_METHOD(CrewEquipBox, RemoveItem, () -> int)
{
    LOG_HOOK("HOOK_METHOD -> CrewEquipBox::RemoveItem -> Begin (Misc.cpp)\n")
    int ret = super();
    if (!CustomOptionsManager::GetInstance()->dismissSound.currentValue.empty())
    {
        G_->GetSoundControl()->PlaySoundMix(CustomOptionsManager::GetInstance()->dismissSound.currentValue, -1.f, false);
    }
    return ret;
}



// Doesn't do anything, but I usually use this to test random stuff by changing what the numpad buttons do

static int testVal = 0;

HOOK_METHOD(CApp, OnKeyDown, (SDLKey key) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CApp::OnKeyDown -> Begin (Misc.cpp)\n")
    if (key == SDLKey::SDLK_LEFTBRACKET) testVal -= 1;
    if (key == SDLKey::SDLK_RIGHTBRACKET) testVal += 1;

    if (key == SDLKey::SDLK_KP_MINUS)
    {
        testVal--;
    }
    if (key == SDLKey::SDLK_KP_PLUS)
    {
        testVal++;
    }

    super(key);
}



// Don't display low O2 warning if ship does not have an oxygen system

static bool displayWarning = true;

HOOK_METHOD(ShipStatus, RenderEvadeOxygen, (bool unk) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipStatus::RenderEvadeOxygen -> Begin (Misc.cpp)\n")
    if (!ship->HasSystem(ShipSystem::NameToSystemId("oxygen")) && ship->GetOxygenPercentage() <= 24)
    {
        displayWarning = false;
        oxygenMessage->flash = false;
    }

    super(unk);

    displayWarning = true;
    oxygenMessage->flash = true;
}

HOOK_METHOD(WarningMessage, OnRender, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> WarningMessage::OnRender -> Begin (Misc.cpp)\n")
    if (displayWarning)
    {
        super();
    }
}



// Bugfix for switching to the same background

HOOK_METHOD(SpaceManager, SwitchBackground, (const std::string& backgroundList) -> ImageDesc)
{
    LOG_HOOK("HOOK_METHOD -> SpaceManager::SwitchBackground -> Begin (Misc.cpp)\n")
    ImageDesc ret = ImageDesc();
    auto img = G_->GetEventGenerator()->GetImageFromList(backgroundList);
    auto tex = G_->GetResources()->GetImageId(img);

    if (!tex)
    {
        return ret;
    }


    ret.tex = tex;
    ret.resId = tex->id_;
    ret.x = 0;
    ret.y = 0;
    ret.w = tex->width_;
    ret.h = tex->height_;
    ret.rot = 0;

    this->currentBack = tex;
    return ret;
}
