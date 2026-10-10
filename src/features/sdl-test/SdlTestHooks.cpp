#include "SdlTest.h"

#ifdef HS_TEST_SDL

#include "Global.h"

HOOK_METHOD(CApp, OnInit, () -> bool)
{
    LOG_HOOK("HOOK_METHOD -> CApp::OnInit -> Begin (SdlTestHooks.cpp)\n")
    SdlTest::Init();
    return super();
}

// The cursor is drawn last, so rendering before it puts the report on top of everything
HOOK_METHOD(MouseControl, OnRender, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> MouseControl::OnRender -> Begin (SdlTestHooks.cpp)\n")
    SdlTest::Render();
    super();
}

#endif // HS_TEST_SDL
