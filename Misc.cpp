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

//TODO: Move to appropriate file and cleanup a bit
static GL_Primitive* timerCircleMaxOcta = nullptr;
static GL_Primitive* timerCircleMaxRing = nullptr;
static bool initExtraPrimitive = false;

HOOK_METHOD(SystemBox, constructor, (Point pos, ShipSystem *sys, bool playerUI) -> void)
{
    LOG_HOOK("HOOK_METHOD -> SystemBox::constructor -> Begin (Misc.cpp)\n")
    if (!initExtraPrimitive)
    {
        timerCircleMaxOcta = G_->GetResources()->CreateImagePrimitiveString("icons/locking/s_octa_9+_base.png", 0, 0, 0, GL_Color(1.f, 1.f, 1.f, 1.f), 1.f, false);
        timerCircleMaxRing = G_->GetResources()->CreateImagePrimitiveString("icons/locking/s_ring_9+_base.png", 0, 0, 0, GL_Color(1.f, 1.f, 1.f, 1.f), 1.f, false);
        initExtraPrimitive = true;
    }

    super(pos, sys, playerUI);
}

HOOK_METHOD_PRIORITY(SystemBox, OnRender, 9999, (bool ignoreStatus) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> SystemBox::OnRender -> Begin (Misc.cpp)\n")
    bool bVar1;
    bool bVar2;
    int iVar1;
    GL_Primitive *prim;
    int iVar2;
    bool bVar3;
    int iVar3;
    int iVar4;
    bool bVar4;
    TimerHelper timer;
    ShipSystem *sys;
  
    bVar2 = bShowPower;
    tapButtonOffsetY = 0;
    cooldownOffsetY = 0;
    if (!bVar2 && 0 < pSystem->iHackEffect) 
    {
        bVar2 = pSystem->bUnderAttack;
    }
    bShowPower = bVar2;
    iVar1 = pSystem->iLockCount;
    if (iVar1 < 1) 
    {
        bVar1 = bShowPower;
        bVar3 = false;
LABEL_1:
        bVar4 = false;
        if (tapped) 
        {
            bVar4 = useLargeTapIcon;
        }
        if (!bVar1) 
        {
            if (!G_->GetSettings()->colorblind) 
            {
LABEL_2:
                iVar1 = topPower;
                iVar3 = 0;
                iVar4 = 0;
            }
            else 
            {
                if (pSystem->healthState.first == 0) 
                {
                    prim = brokenIcon;
                }
                else 
                {
                    bVar2 = pSystem->GetLocked();
                    if (!bVar2) goto LABEL_2;
                    prim = lockIcon;
                }
                CSurface::GL_RenderPrimitive(prim);
                iVar1 = topPower;
                iVar3 = 12;
                iVar4 = -12;
            }
            goto LABEL_3;
        }
    }
    else 
    {
        if (!ignoreStatus) 
        {
            bVar1 = bShowPower;
            bVar3 = true;
            goto LABEL_1;
        }
        bVar1 = bShowPower;
        bVar3 = bVar1;
        if (!bVar1) goto LABEL_1;
        bVar2 = tapped;
        bVar3 = bVar1;
        bVar4 = bVar2;
        if (bVar2) 
        {
            bVar4 = useLargeTapIcon;
            bVar3 = bVar2;
        }
    }
    if (powerAlpha < 1.0) 
    {
        GL_Color tint = CSurface::GetColorTint();
        CSurface::GL_SetColorTint(tint);
    }
    if (!bSimplePower) 
    {
        iVar1 = GetHeightModifier();
        iVar1 = pSystem->RenderPowerBoxes(location.x, location.y, 16, 6, 2, iVar1, false);
        topPower = iVar1;
    }
    else 
    {
        iVar1 = pSystem->powerState.second;
        iVar1 = ShipSystem::RenderPowerBoxesPlain(location.x, location.y, 16, 6, 2, iVar1, 0, iVar1);
        topPower = iVar1;
    }
    if (powerAlpha <= 1.0 && powerAlpha != 1.0) 
    {
        CSurface::GL_RemoveColorTint();
        iVar1 = topPower;
        iVar3 = 0;
        iVar4 = 0;
    }
    else 
    {
        iVar3 = 0;
        iVar4 = 0;
    }
    LABEL_3:
    if (!warning.tracker.done && warning.tracker.running) 
    {
        bVar2 = pSystem->bOnFire;
        iVar2 = pSystem->GetId();
        
        if (iVar2 == 0) 
        {
            iVar1 = -78;
        }
        iVar2 = location.y;
        CSurface::GL_PushMatrix();
        //CSurface::GL_Translate((float)location.x, (float)(iVar1 + iVar2 + ((-(unsigned int)(!bVar2) & 0b00010100) - 53)),0.0);
        CSurface::GL_Translate((float)location.x, (float)(iVar1 + iVar2 + (bVar2 ? -53 : -33)), 0.0);
        warning.OnRender();
        CSurface::GL_PopMatrix();
        iVar1 = topPower;
    }
    iVar2 = location.x;
    hitBox.w = 15;
    hitBox.x = iVar2 + 24;
    hitBox.y = iVar1 + 16;
    hitBox.h = location.y - iVar1 + 15;
    CSurface::GL_PushMatrix();
    CSurface::GL_Translate((float)location.x, (float)location.y, 0.0);
    if (!bVar3) {
        CSurface::GL_DestroyPrimitive(timerStencil);
        timerStencil = nullptr;
        lastTimerStencilCount = -1;
        if (!bSimplePower) 
        {
            if (!bVar4) 
            {
                pSystem->RenderSystemSymbol(bPlayerUI, -1);
            }
            else 
            {
                CSurface::GL_Translate((float)(largeTapIconOffset.x - 32), (float)(largeTapIconOffset.y - 32), 0.0);
                CSurface::GL_Scale(2.0, 2.0, 1.0);
                pSystem->RenderSystemSymbol(false, -1);
            }
        }
        else 
        {
            pSystem->RenderSystemSymbol(false, 0);
        }
    }
    else 
    {
        if (bVar4) 
        {
            CSurface::GL_PushMatrix();
            CSurface::GL_Translate(19.0, -14.0, 0.0);
        }
        iVar1 = pSystem->iLockCount;
        //Fix for ion greater than 9 rendering invalid primitive
        CSurface::GL_RenderPrimitive(iVar1 <= 9 ? timerCircle[iVar1] : (ShipSystem::IsSubsystem(pSystem->GetId()) ? timerCircleMaxOcta : timerCircleMaxRing));
        
        timer = pSystem->GetLockTimer();
        iVar1 = (int)((12.0 - (timer.currTime / timer.currGoal) * 12.0) + 1.0);
        if (iVar1 != lastTimerStencilCount) 
        {
            lastTimerStencilCount = iVar1;
            CSurface::GL_DestroyPrimitive(timerStencil);
            timer.currGoal = 1.0;
            timer.maxTime = 0;
            timer.minTime = 0;
            timer.currTime = 0.0;
            prim = CSurface::GL_CreatePiePartialPrimitive(0, 0, 17.0, -85.0, (float)(iVar1 * 30 - 85), 17.0, GL_Color(0.0, 0.0, 0.0, 1.0));
            timerStencil = prim;
        }
        CSurface::GL_SetStencilMode(STENCIL_SET, 1, 1);
        CSurface::GL_PushMatrix();
        CSurface::GL_Translate(32.0, 32.0, 0.0);
        CSurface::GL_RenderPrimitive(timerStencil);
        CSurface::GL_PopMatrix();
        CSurface::GL_SetStencilMode(STENCIL_USE, 1, 1);
        CSurface::GL_RenderPrimitive(timerLines);
        CSurface::GL_SetStencilMode(STENCIL_IGNORE, 0, 0);
        if (bVar4) 
        {
            CSurface::GL_PopMatrix();
        }
    }
    CSurface::GL_PopMatrix();
    if (0 < pSystem->iHackEffect && pSystem->bUnderAttack && !bShowPower) 
    {
        CSurface::GL_Translate(0.0, (float)iVar4, 0.0);
        CSurface::GL_RenderPrimitive(hackIcon);
        CSurface::GL_Translate(0.0, (float)iVar3, 0.0);
    }
    return;
}

//Not sure what file this should be in, move to appropriate location later
//Neutral ASB text
static GL_Primitive* warningPdsAll = nullptr;

HOOK_METHOD(SpaceStatus, OnInit, (SpaceManager *space, Point pos) -> void)
{
    LOG_HOOK("HOOK_METHOD -> SpaceStatus::OnInit -> Begin (Misc.cpp)\n")
    super(space, pos);
    warningPdsAll = G_->GetResources()->CreateImagePrimitiveString("warnings/danger_pds_neutral.png", position.x - 30, position.y, 0, GL_Color(1.f, 1.f, 1.f, 1.f), 1.f, false);
}

HOOK_METHOD(SpaceStatus, OnRender, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> SpaceStatus::OnRender -> Begin (Misc.cpp)\n")

    int idx = G_->getLuaContext()->getLibScript()->call_on_render_event_pre_callbacks(RenderEvents::SPACE_STATUS, 0);
    
    if (idx >= 0)
    {
        incomingFire->OnRender();
        if (currentEffect == 0)
        {
            G_->getLuaContext()->getLibScript()->call_on_render_event_post_callbacks(RenderEvents::SPACE_STATUS, std::abs(idx), 0);
            return;
        }
        CSurface::GL_PushMatrix();
        bool neutralAsb = (currentEffect == 6 || currentEffect == 9) && space->envTarget == 2; // Special case for neutral ASB
        CSurface::GL_RenderPrimitive(neutralAsb ? warningPdsAll : warningImages[currentEffect]);
        if (currentEffect2 != 0)
        {
            CSurface::GL_Translate(72.f, 0.f, 0.f);
            CSurface::GL_RenderPrimitive(warningImages[currentEffect2]);
        }
        CSurface::GL_PopMatrix();
        RenderWarningText(currentEffect, (currentEffect2 == 0) ? 0 : 36);
        if (touchedTooltip == 1)
        {
            int mX = hitbox.w / 2 + hitbox.x;
            int mY = hitbox.y + hitbox.h;
            MouseMove(mX, mY + -1);
            G_->GetMouseControl()->QueueStaticTooltip(Point(mX - 80, mY + 20));
        }
        if (((space->sunLevel == false) && (space->pulsarLevel == false)) && (space->bPDS == false))
        {
            G_->getLuaContext()->getLibScript()->call_on_render_event_post_callbacks(RenderEvents::SPACE_STATUS, std::abs(idx), 0);
            return;
        }
        warningMessage->OnRender();
    }

    G_->getLuaContext()->getLibScript()->call_on_render_event_post_callbacks(RenderEvents::SPACE_STATUS, std::abs(idx), 0);
}

HOOK_METHOD_PRIORITY(SpaceStatus, RenderWarningText, 9999, (int effect, int textOffset) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> SpaceStatus::RenderWarningText -> Begin (Misc.cpp)\n")
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
        color.b = 50.f / 255.f;
        color.g = 160.f / 255.f;
        color.r = 255.f / 255.f;

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
    LOG_HOOK("HOOK_METHOD_PRIORITY -> SpaceStatus::MouseMove -> Begin (Misc.cpp)\n")
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
