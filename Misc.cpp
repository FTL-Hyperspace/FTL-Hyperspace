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

//Not sure what file this should be in, move to appropriate location later
//Neutral ASB text
HOOK_METHOD_PRIORITY(SpaceStatus, RenderWarningText, 9999, (int effect, int textOffset) -> void)
{
    LOG_HOOK("HOOK_METHOD -> SpaceManager::SwitchBackground -> Begin (Misc.cpp)\n")
    GL_Texture *tex;
    GL_Color color;
    std::string text;
  
    color.g = 1.0;
    color.a = 1.0;
    if (effect == 9) 
    {
        color.r = 0.4705882;
        color.b = 0.4705882;
        tex = G_->GetResources()->GetImageId("warnings/backglow_warning_green.png");
        text = G_->GetTextLibrary()->GetText("warning_pds_allies");
    }
    else 
    {
        //TODO: Hook Global COLOR_RED_WARNING
        /*
        color.b = COLOR_RED_WARNING.b / 255.0;
        color.g = COLOR_RED_WARNING.g / 255.0;
        color.r = COLOR_RED_WARNING.r / 255.0;
        */
        color.b = 50.f / 255.f;
        color.g = 50.f / 255.f;
        color.r = 255.f / 255.f;


        tex = G_->GetResources()->GetImageId("warnings/backglow_warning_red.png");
        text = G_->GetTextLibrary()->GetText("warning_environment_danger");
    }

    if ((effect == 6 || effect == 9) && space->envTarget == 2) //If ASB and targetting both ships
    {
        text = G_->GetTextLibrary()->GetText("warning_pds_all");
    }

    Point point1 = Point(textOffset + position.x, position.y + 51);
    Pointf pointf1 = freetype::easy_measurePrintLines(52, 0.0, 0.0, 999, text);
    float fVar1 = roundf(pointf1.x);
    float fVar2 = roundf(pointf1.y);
    Point point2 = Point((int) fVar1, (int) fVar2);
    CSurface::GL_BlitImage(tex, point1.x - point2.x / 2, point1.y - 1, point2.x, point2.y, 0.0, GL_Color(1.0, 1.0, 1.0, 1.0), false);
    CSurface::GL_SetColor(color);
    freetype::easy_printCenter(52, point1.x, point1.y, text);
    CSurface::GL_SetColor(GL_Color(1.0, 1.0, 1.0, 1.0));
    return;
}

HOOK_METHOD_PRIORITY(SpaceStatus, MouseMove, 9999, (int mX, int mY) -> void)
{
    LOG_HOOK("HOOK_METHOD -> SpaceManager::MouseMove -> Begin (Misc.cpp)\n")
    std::string tip;

    if (mX <= hitbox.x || hitbox.x + hitbox.w <= mX || mY <= hitbox.y || hitbox.y + hitbox.h <= mY)
    {
        goto LABEL_TWO;
    }
  
    if (currentEffect == 2) 
    {
        tip = "sun";
    }
    else if (currentEffect == 6 || currentEffect == 9) 
    {
        bool inFleet = space->dangerZone;    
        if (space->envTarget == 0) 
        {
            tip = inFleet ? "PDS_FLEET" : "PDS_PLAYER";
        }
        else if (space->envTarget == 1)
        { 
            tip = inFleet ? "PDS_FLEET_ENEMY" : "PDS_ENEMY";
        }
        else
        {
            tip = inFleet ? "PDS_FLEET_ALL" : "PDS_ALL";
        }
    }
    else 
    {
        if (currentEffect == 5) 
        {
            tip = "pulsar";
        }
        else 
        {
            if (currentEffect == 1) 
            {
                tip = "asteroids";
                goto LABEL_ONE;
            }
            if (currentEffect != 3) goto LABEL_TWO;
            tip = "nebula";
        }
    }
LABEL_ONE:
  G_->GetMouseControl()->LoadTooltip(tip);
  
  
LABEL_TWO:
    if (hitbox2.x < mX && mX < hitbox2.x + hitbox2.w && hitbox2.y < mY && mY < hitbox2.y + hitbox2.h && currentEffect2 == 4)
    {
        tip = "storm";
        G_->GetMouseControl()->LoadTooltip(tip);
    }
    return;
}



