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

HOOK_METHOD(MouseControl, OnRender, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> MouseControl::OnRender -> Begin (RenderEvents.cpp)\n")
    int idx = Global::GetInstance()->getLuaContext()->getLibScript()->call_on_render_event_pre_callbacks(RenderEvents::MOUSE_CONTROL, 0);
    if (idx >= 0) super();
    Global::GetInstance()->getLuaContext()->getLibScript()->call_on_render_event_post_callbacks(RenderEvents::MOUSE_CONTROL, std::abs(idx), 0);
}
