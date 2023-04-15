#include "RenderEvents.h"
#include "../Global.h"

/** All the hook code for the various RenderEvents belongs here **/

HOOK_METHOD(MainMenu, OnRender, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> MainMenu::OnRender -> Begin (RenderEvents.cpp)\n")
    int idx = Global::GetInstance()->getLuaContext()->getLibScript()->call_on_render_event_pre_callbacks(RenderEvents::MAIN_MENU, 0);
    if (idx >= 0) super();
    Global::GetInstance()->getLuaContext()->getLibScript()->call_on_render_event_post_callbacks(RenderEvents::MAIN_MENU, std::abs(idx), 0);
}

HOOK_METHOD(CommandGui, RenderStatic, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CommandGui::RenderStatic -> Begin (RenderEvents.cpp)\n")
    int idx = Global::GetInstance()->getLuaContext()->getLibScript()->call_on_render_event_pre_callbacks(RenderEvents::GUI_CONTAINER, 0);
    if (idx >= 0) super();
    Global::GetInstance()->getLuaContext()->getLibScript()->call_on_render_event_post_callbacks(RenderEvents::GUI_CONTAINER, std::abs(idx), 0);
}

HOOK_METHOD(SpaceManager, OnRenderBackground, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> SpaceManager::OnRenderBackground -> Begin (RenderEvents.cpp)\n")
    int idx = Global::GetInstance()->getLuaContext()->getLibScript()->call_on_render_event_pre_callbacks(RenderEvents::LAYER_BACKGROUND, 0);
    if (idx >= 0) super();
    Global::GetInstance()->getLuaContext()->getLibScript()->call_on_render_event_post_callbacks(RenderEvents::LAYER_BACKGROUND, std::abs(idx), 0);
}

HOOK_METHOD(SpaceManager, OnRenderForeground, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> SpaceManager::OnRenderForeground -> Begin (RenderEvents.cpp)\n")
    int idx = Global::GetInstance()->getLuaContext()->getLibScript()->call_on_render_event_pre_callbacks(RenderEvents::LAYER_FOREGROUND, 0);
    if (idx >= 0) super();
    Global::GetInstance()->getLuaContext()->getLibScript()->call_on_render_event_post_callbacks(RenderEvents::LAYER_FOREGROUND, std::abs(idx), 0);
}

HOOK_METHOD(SpaceManager, OnRenderAsteroids, (int layers, float alpha) -> void)
{
    LOG_HOOK("HOOK_METHOD -> SpaceManager::OnRenderAsteroids -> Begin (RenderEvents.cpp)\n")
    int idx = Global::GetInstance()->getLuaContext()->getLibScript()->call_on_render_event_pre_callbacks(layers == 3 ? RenderEvents::LAYER_ASTEROIDS : RenderEvents::LAYER_FRONT, 0);
    if (idx >= 0) super(layers, alpha);
    Global::GetInstance()->getLuaContext()->getLibScript()->call_on_render_event_post_callbacks(layers == 3 ? RenderEvents::LAYER_ASTEROIDS : RenderEvents::LAYER_FRONT, std::abs(idx), 0);
}

HOOK_METHOD(CommandGui, RenderPlayerShip, (Point &shipCenter, float jumpScale) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CommandGui::RenderPlayerShip -> Begin (RenderEvents.cpp)\n")
    int idx = Global::GetInstance()->getLuaContext()->getLibScript()->call_on_render_event_pre_callbacks(RenderEvents::LAYER_PLAYER, 0);
    if (idx >= 0) super(shipCenter, jumpScale);
    Global::GetInstance()->getLuaContext()->getLibScript()->call_on_render_event_post_callbacks(RenderEvents::LAYER_PLAYER, std::abs(idx), 0);
}
//Room anim layer 0
HOOK_METHOD(Ship, OnRenderFloor, (bool experimental) -> void)
{
    LOG_HOOK("HOOK_METHOD -> Ship::OnRenderFloor -> Begin (RenderEvents.cpp)\n")
    auto context = Global::GetInstance()->getLuaContext();

    SWIG_NewPointerObj(context->GetLua(), this, context->getLibScript()->types.pShip, 0);
    lua_pushboolean(context->GetLua(), experimental);

    int idx = context->getLibScript()->call_on_render_event_pre_callbacks(RenderEvents::SHIP_FLOOR, 2);
    if (idx >= 0) super(experimental);
    context->getLibScript()->call_on_render_event_post_callbacks(RenderEvents::SHIP_FLOOR, std::abs(idx), 2);
    
    lua_pop(context->GetLua(), 2);
}

//Room anim layer 1
HOOK_METHOD(Ship, OnRenderBreaches, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> Ship::OnRenderBreaches -> Begin (RenderEvents.cpp)\n")
    auto context = Global::GetInstance()->getLuaContext();

    SWIG_NewPointerObj(context->GetLua(), this, context->getLibScript()->types.pShip, 0);

    int idx = context->getLibScript()->call_on_render_event_pre_callbacks(RenderEvents::SHIP_BREACHES, 1);
    if (idx >= 0) super();
    context->getLibScript()->call_on_render_event_post_callbacks(RenderEvents::SHIP_BREACHES, std::abs(idx), 1);

    lua_pop(context->GetLua(), 1);
}

//Room anim layer 2
HOOK_METHOD(Ship, OnRenderSparks, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> Ship::OnRenderSparks -> Begin (RenderEvents.cpp)\n")
    auto context = Global::GetInstance()->getLuaContext();

    SWIG_NewPointerObj(context->GetLua(), this, context->getLibScript()->types.pShip, 0);

    int idx = context->getLibScript()->call_on_render_event_pre_callbacks(RenderEvents::SHIP_SPARKS, 1);
    if (idx >= 0) super();
    context->getLibScript()->call_on_render_event_post_callbacks(RenderEvents::SHIP_SPARKS, std::abs(idx), 1);

    lua_pop(context->GetLua(), 1);
}

//Room anim layers 3 and 4
HOOK_METHOD(ShipManager, OnRender, (bool showInterior, bool doorControlMode) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::OnRender -> Begin (RenderEvents.cpp)\n")
    auto context = Global::GetInstance()->getLuaContext();

    SWIG_NewPointerObj(context->GetLua(), this, context->getLibScript()->types.pShipManager, 0);
    lua_pushboolean(context->GetLua(), showInterior);
    lua_pushboolean(context->GetLua(), doorControlMode);

    int idx = context->getLibScript()->call_on_render_event_pre_callbacks(RenderEvents::SHIP_MANAGER, 3);
    if (idx >= 0) super(showInterior, doorControlMode);
    context->getLibScript()->call_on_render_event_post_callbacks(RenderEvents::SHIP_MANAGER, std::abs(idx), 3);
    
    lua_pop(context->GetLua(), 3);
}




HOOK_METHOD(MouseControl, OnRender, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> MouseControl::OnRender -> Begin (RenderEvents.cpp)\n")
    int idx = Global::GetInstance()->getLuaContext()->getLibScript()->call_on_render_event_pre_callbacks(RenderEvents::MOUSE_CONTROL, 0);
    if (idx >= 0) super();
    Global::GetInstance()->getLuaContext()->getLibScript()->call_on_render_event_post_callbacks(RenderEvents::MOUSE_CONTROL, std::abs(idx), 0);
}
