#include "SystemBox_Extend.h"
#include "luaInclude.h"
#include "Global.h"
HOOK_METHOD_PRIORITY(SystemBox, constructor, 900, (Point pos, ShipSystem *sys, bool playerUI) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> SystemBox::constructor -> Begin (SystemBox_Extend.cpp)\n")
	super(pos, sys, playerUI);

	SystemBox_Extend* ex = nullptr;
    //Create proper subclass depnding on system ID
    switch (sys->iSystemType)
    {
        case SYS_ARTILLERY:
            ex = new ArtilleryBox_Extend();
            break;
        case SYS_CLONEBAY:
            ex = new CloneBox_Extend();
            break;
        default:
            ex = new SystemBox_Extend();
            break;
    }
  

    uintptr_t dEx = (uintptr_t)ex;

#ifdef __amd64__
    this->gap_ex_1[2] = (dEx >> 56) & 0xFF;
    this->gap_ex_1[3] = (dEx >> 48) & 0xFF;
    this->gap_ex_2[2] = (dEx >> 40) & 0xFF;
    this->gap_ex_2[3] = (dEx >> 32) & 0xFF;
#endif // __amd64__
	gap_ex_1[0] = (dEx >> 24) & 0xFF;
	gap_ex_1[1] = (dEx >> 16) & 0xFF;
	gap_ex_2[0] = (dEx >> 8) & 0xFF;
	gap_ex_2[1] = dEx & 0xFF;

	ex->orig = this;

    HS_MAKE_TABLE(this)

    //If necessary, pass constructor arguments, for now user can just access them via the members of the SystemBox*
    auto context = G_->getLuaContext();
    SWIG_NewPointerObj(context->GetLua(), this, context->getLibScript()->types.pSystemBox, 0);
    context->getLibScript()->call_on_internal_event_callbacks(InternalEvents::CONSTRUCT_SYSTEM_BOX, 1);
    lua_pop(context->GetLua(), 1);
}

HOOK_METHOD_PRIORITY(SystemBox, destructor, 900, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> SystemBox::destructor -> Begin (SystemBox_Extend.cpp)\n")
    HS_BREAK_TABLE(this)
	delete SB_EX(this);
    super();
}

SystemBox_Extend* Get_SystemBox_Extend(SystemBox* c)
{
    uintptr_t dEx = 0;
#ifdef __amd64__
    dEx <<= 8;
    dEx |= c->gap_ex_1[2];
    dEx <<= 8;
    dEx |= c->gap_ex_1[3];
    dEx <<= 8;
    dEx |= c->gap_ex_2[2];
    dEx <<= 8;
    dEx |= c->gap_ex_2[3];
#endif // __amd64__
    dEx <<= 8;
    dEx |= c->gap_ex_1[0];
    dEx <<= 8;
    dEx |= c->gap_ex_1[1];
    dEx <<= 8;
    dEx |= c->gap_ex_2[0];
    dEx <<= 8;
    dEx |= c->gap_ex_2[1];

    return (SystemBox_Extend*)dEx;
}

void SystemBox_Extend::OnScrollWheel(float direction)
{

}

void SystemBox_Extend::RButtonUp(int mX, int mY, bool shiftHeld)
{
    
}

static GL_Primitive* timerCircleMaxOcta = nullptr;
static GL_Primitive* timerCircleMaxRing = nullptr;
static bool initExtraPrimitive = false;

HOOK_METHOD(SystemBox, constructor, (Point pos, ShipSystem *sys, bool playerUI) -> void)
{
    LOG_HOOK("HOOK_METHOD -> SystemBox::constructor -> Begin (SystemBox_Extend.cpp)\n")
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
    LOG_HOOK("HOOK_METHOD_PRIORITY -> SystemBox::OnRender -> Begin (SystemBox_Extend.cpp)\n")
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
