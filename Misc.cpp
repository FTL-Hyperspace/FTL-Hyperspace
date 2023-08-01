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
static GL_Primitive* timerCircleMax = nullptr;
static bool initExtraPrimitive = false;

HOOK_METHOD(SystemBox, constructor, (Point pos, ShipSystem *sys, bool playerUI) -> void)
{
    LOG_HOOK("HOOK_METHOD -> SystemBox::constructor -> Begin (Misc.cpp)\n")
    if (!initExtraPrimitive)
    {
        timerCircleMax = G_->GetResources()->CreateImagePrimitiveString("icons/locking/s_ring_9+_base.png",0,0,0,GL_Color(1.0, 1.0, 1.0, 1.0),1.f,false);
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
        CSurface::GL_RenderPrimitive(iVar1 <= 9 ? timerCircle[iVar1] : timerCircleMax);
        
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
