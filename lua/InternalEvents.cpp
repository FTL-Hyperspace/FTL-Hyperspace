#include "InternalEvents.h"
#include "../Global.h"

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
