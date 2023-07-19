#include "InternalEvents.h"
#include "../Global.h"
#include "swigluarun.h"

/** All the hook code for the various InternalEvents belongs here **/

HOOK_METHOD(CApp, OnLoop, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CApp::OnLoop -> Begin (InternalEvents.cpp)\n")
    super();
    Global::GetInstance()->getLuaContext()->getLibScript()->call_on_internal_event_callbacks(InternalEvents::ON_TICK);
}

HOOK_METHOD(MainMenu, Open, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> MainMenu::Open -> Begin (InternalEvents.cpp)\n")
    super();
    Global::GetInstance()->getLuaContext()->getLibScript()->call_on_internal_event_callbacks(InternalEvents::MAIN_MENU);
}

HOOK_METHOD(CApp, OnKeyDown, (SDLKey key) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CApp::OnKeyDown -> Begin (InternalEvents.cpp)\n")

    auto context = Global::GetInstance()->getLuaContext();

    lua_pushinteger(context->GetLua(), key);
    bool preempt = context->getLibScript()->call_on_internal_chain_event_callbacks(InternalEvents::ON_KEY_DOWN, 1, 0);
    lua_pop(context->GetLua(), 1);

    if (!preempt) super(key);
}

HOOK_METHOD(CApp, OnKeyUp, (SDLKey key) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CApp::OnKeyUp -> Begin (InternalEvents.cpp)\n")

    auto context = Global::GetInstance()->getLuaContext();

    lua_pushinteger(context->GetLua(), key);
    bool preempt = context->getLibScript()->call_on_internal_chain_event_callbacks(InternalEvents::ON_KEY_UP, 1, 0);
    lua_pop(context->GetLua(), 1);

    if (!preempt) super(key);
}

HOOK_METHOD(CApp, OnMouseMove, (int x, int y, int xdiff, int ydiff, bool holdingLMB, bool holdingRMB, bool holdingMMB) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CApp::OnMouseMove -> Begin (InternalEvents.cpp)\n")

    auto context = Global::GetInstance()->getLuaContext();

    lua_pushinteger(context->GetLua(), x);
    lua_pushinteger(context->GetLua(), y);
    lua_pushinteger(context->GetLua(), xdiff);
    lua_pushinteger(context->GetLua(), ydiff);
    lua_pushboolean(context->GetLua(), holdingLMB);
    lua_pushboolean(context->GetLua(), holdingRMB);
    lua_pushboolean(context->GetLua(), holdingMMB);
    bool preempt = context->getLibScript()->call_on_internal_chain_event_callbacks(InternalEvents::ON_MOUSE_MOVE, 7, 0);
    lua_pop(context->GetLua(), 7);

    if (!preempt) super(x, y, xdiff, ydiff, holdingLMB, holdingRMB, holdingMMB);
}

HOOK_METHOD(CApp, OnLButtonDown, (int x, int y) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CApp::OnLButtonDown -> Begin (InternalEvents.cpp)\n")

    auto context = Global::GetInstance()->getLuaContext();

    lua_pushinteger(context->GetLua(), x);
    lua_pushinteger(context->GetLua(), y);
    bool preempt = context->getLibScript()->call_on_internal_chain_event_callbacks(InternalEvents::ON_MOUSE_L_BUTTON_DOWN, 2, 0);
    lua_pop(context->GetLua(), 2);

    if (!preempt) super(x, y);
}

HOOK_METHOD(CApp, OnLButtonUp, (int x, int y) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CApp::OnLButtonUp -> Begin (InternalEvents.cpp)\n")

    auto context = Global::GetInstance()->getLuaContext();

    lua_pushinteger(context->GetLua(), x);
    lua_pushinteger(context->GetLua(), y);
    bool preempt = context->getLibScript()->call_on_internal_chain_event_callbacks(InternalEvents::ON_MOUSE_L_BUTTON_UP, 2, 0);
    lua_pop(context->GetLua(), 2);

    if (!preempt) super(x, y);
}

HOOK_METHOD(CApp, OnRButtonDown, (int x, int y) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CApp::OnRButtonDown -> Begin (InternalEvents.cpp)\n")

    auto context = Global::GetInstance()->getLuaContext();

    lua_pushinteger(context->GetLua(), x);
    lua_pushinteger(context->GetLua(), y);
    bool preempt = context->getLibScript()->call_on_internal_chain_event_callbacks(InternalEvents::ON_MOUSE_R_BUTTON_DOWN, 2, 0);
    lua_pop(context->GetLua(), 2);

    if (!preempt) super(x, y);
}

HOOK_METHOD_PRIORITY(CApp, OnRButtonUp, -100, (int x, int y) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> CApp::OnRButtonUp -> Begin (InternalEvents.cpp)\n")

    auto context = Global::GetInstance()->getLuaContext();

    lua_pushinteger(context->GetLua(), x);
    lua_pushinteger(context->GetLua(), y);
    bool preempt = context->getLibScript()->call_on_internal_chain_event_callbacks(InternalEvents::ON_MOUSE_R_BUTTON_UP, 2, 0);
    lua_pop(context->GetLua(), 2);

    if (!preempt) super(x, y);
}

HOOK_METHOD(CApp, OnMButtonDown, (int x, int y) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CApp::OnMButtonDown -> Begin (InternalEvents.cpp)\n")

    auto context = Global::GetInstance()->getLuaContext();

    lua_pushinteger(context->GetLua(), x);
    lua_pushinteger(context->GetLua(), y);
    bool preempt = context->getLibScript()->call_on_internal_chain_event_callbacks(InternalEvents::ON_MOUSE_M_BUTTON_DOWN, 2, 0);
    lua_pop(context->GetLua(), 2);

    if (!preempt) super(x, y);
}

HOOK_METHOD_PRIORITY(CrewMember, OnLoop, -100, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> CrewMember::OnLoop -> Begin (InternalEvents.cpp)\n")

    super();

    auto context = Global::GetInstance()->getLuaContext();

    SWIG_NewPointerObj(context->GetLua(), this, context->getLibScript()->types.pCrewMember, 0);
    context->getLibScript()->call_on_internal_event_callbacks(InternalEvents::CREW_LOOP, 1);
    lua_pop(context->GetLua(), 1);
}
//Priority was necessary to make this run after the hook for calculating stuff with additionalPowerLoss, so user can do stuff like modify that for weapon effects here.
HOOK_METHOD_PRIORITY(ShipManager, OnLoop, -100, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::OnLoop -> Begin (InternalEvents.cpp)\n")
    super();

    auto context = G_->getLuaContext();
    SWIG_NewPointerObj(context->GetLua(), this, context->getLibScript()->types.pShipManager, 0);
    context->getLibScript()->call_on_internal_event_callbacks(InternalEvents::SHIP_LOOP, 1);
    lua_pop(context->GetLua(), 1);
}

//Priority to run after callback in CustomDrones.cpp
HOOK_METHOD_PRIORITY(SpaceDrone, GetNextProjectile, -100, () -> Projectile*)
{
    LOG_HOOK("HOOK_METHOD -> SpaceDrone::GetNextProjectile -> Begin (InternalEvents.cpp)\n")
    
    Projectile* ret = super();
    if (ret != nullptr)
    {
        auto context = G_->getLuaContext();
        SWIG_NewPointerObj(context->GetLua(), ret, context->getLibScript()->types.pProjectile[ret->GetType()], 0);
        SWIG_NewPointerObj(context->GetLua(), this, context->getLibScript()->types.pSpaceDroneTypes[this->type], 0);
        bool preempt = context->getLibScript()->call_on_internal_chain_event_callbacks(InternalEvents::DRONE_FIRE, 2, 0);
        lua_pop(context->GetLua(), 2);
        //preempt prevents projectile from firing
        if (preempt)
        {
            delete ret;
            return nullptr;
        }
    }
    return ret;
}
