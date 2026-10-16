#include "Global.h"
#include "core/CrashDetector.h"
#include "integration/CrashReportFlow.h"
#include "ui/CrashDialogManager.h"

// === CApp Hooks ===

// Clear crash flag on normal game exit
HOOK_METHOD(CApp, OnExit, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CApp::OnExit -> Begin (CrashDetectionHooks.cpp)\n")
    CrashReportFlow::GetInstance()->OnGameExit();
    super();
}

HOOK_METHOD(CApp, OnRequestExit, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CApp::OnRequestExit -> Begin (CrashDetectionHooks.cpp)\n")
    CrashReportFlow::GetInstance()->OnGameExit();
    super();
}

#ifdef HS_ANDROID
// Android usually closes a backgrounded app by killing it, so the flag is cleared while
// the game is in the background and written again when it comes back
HOOK_METHOD(CApp, OnSuspend, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CApp::OnSuspend -> Begin (CrashDetectionHooks.cpp)\n")
    CrashDetector::GetInstance()->OnSuspend();
    super();
}

HOOK_METHOD(CApp, OnResume, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CApp::OnResume -> Begin (CrashDetectionHooks.cpp)\n")
    super();
    CrashDetector::GetInstance()->OnResume();
}
#endif

// Clear crash flag if user exits using menu options. (Fixes bug on Windows where OnExit is not called)
HOOK_METHOD_PRIORITY(CApp, OnLoop, -9999, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CApp::OnLoop -> Begin (CrashDetectionHooks.cpp)\n")

    if (this->menu.bOpen == true)
    {
        if (this->menu.finalChoice == 2)
        {
            CrashReportFlow::GetInstance()->OnGameExit();
        }
    }

    if (this->gui && this->gui->menuBox.command == 8)
    {
        CrashReportFlow::GetInstance()->OnGameExit();
    }

    super();
}

// === MainMenu Hooks ===

// Initialize crash detection and show dialog on menu open
HOOK_METHOD(MainMenu, Open, () -> bool)
{
    LOG_HOOK("HOOK_METHOD -> MainMenu::Open -> Begin (CrashDetectionHooks.cpp)\n")
    bool ret = super();
    CrashReportFlow::GetInstance()->OnMenuOpen();
    return ret;
}

// Render crash detection dialogs in menu
HOOK_METHOD(MainMenu, OnRender, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> MainMenu::OnRender -> Begin (CrashDetectionHooks.cpp)\n")
    super();
    CrashReportFlow::GetInstance()->OnRender();
}

// Handle crash detection dialog click
HOOK_METHOD(MainMenu, MouseClick, (int x, int y) -> void)
{
    LOG_HOOK("HOOK_METHOD -> MainMenu::MouseClick -> Begin (CrashDetectionHooks.cpp)\n")

    bool shouldPropagate = true;
    CrashReportFlow::GetInstance()->OnMouseClick(x, y, shouldPropagate);

    if (shouldPropagate)
    {
        super(x, y);
    }
}

// Handle crash detection dialog mouse move
HOOK_METHOD(MainMenu, MouseMove, (int x, int y) -> void)
{
    LOG_HOOK("HOOK_METHOD -> MainMenu::MouseMove -> Begin (CrashDetectionHooks.cpp)\n")

    bool shouldPropagate = true;
    CrashReportFlow::GetInstance()->OnMouseMove(x, y, shouldPropagate);

    if (shouldPropagate)
    {
        super(x, y);
    }
}

#ifdef HS_ANDROID
// FTL for iPad only takes touches, so its menus get them through OnTouch rather than the
// mouse functions above. The main menu passes touches on to its options screen, whose own
// hook below handles them.
HOOK_METHOD(MainMenu, OnTouch, (TouchAction action, int id, int x, int y, int initialX, int initialY) -> void)
{
    LOG_HOOK("HOOK_METHOD -> MainMenu::OnTouch -> Begin (CrashDetectionHooks.cpp)\n")

    bool shouldPropagate = true;
    if (!this->optionScreen.bOpen)
    {
        CrashReportFlow::GetInstance()->OnTouch(action, id, x, y, initialX, initialY, shouldPropagate);
    }

    if (shouldPropagate)
    {
        super(action, id, x, y, initialX, initialY);
    }
}
#endif

// === Initialize bug report button ===
HOOK_METHOD(CommandGui, OnInit, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CommandGui::OnInit -> Begin (CrashDetectionHooks.cpp)\n")
    super();
    CrashReportFlow::GetInstance()->InitButton();
}

// === MenuScreen Hooks (Esc menu UI) ===

HOOK_METHOD(MenuScreen, OnRender, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> MenuScreen::OnRender -> Begin (CrashDetectionHooks.cpp)\n")
    super();
    if (this->bOpen && !this->bShowControls)
    {
        CrashDialogManager::GetInstance()->RenderButton();
    }
    CrashReportFlow::GetInstance()->OnRender();
}

// Handle bug report button hover
HOOK_METHOD(MenuScreen, MouseMove, (int mX, int mY) -> void)
{
    LOG_HOOK("HOOK_METHOD -> MenuScreen::MouseMove -> Begin (CrashDetectionHooks.cpp)\n")

    bool shouldPropagate = true;
    CrashReportFlow::GetInstance()->OnMouseMove(mX, mY, shouldPropagate);

    if (shouldPropagate)
    {
        super(mX, mY);
    }
}

// Handle bug report button click
HOOK_METHOD(MenuScreen, MouseClick, (int mX, int mY) -> void)
{
    LOG_HOOK("HOOK_METHOD -> MenuScreen::MouseClick -> Begin (CrashDetectionHooks.cpp)\n")

    bool shouldPropagate = true;
    CrashReportFlow::GetInstance()->OnMouseClick(mX, mY, shouldPropagate);

    if (shouldPropagate)
    {
        super(mX, mY);
    }
}

#ifdef HS_ANDROID
HOOK_METHOD(MenuScreen, OnTouch, (TouchAction action, int id, int x, int y, int initialX, int initialY) -> void)
{
    LOG_HOOK("HOOK_METHOD -> MenuScreen::OnTouch -> Begin (CrashDetectionHooks.cpp)\n")

    bool shouldPropagate = true;
    CrashReportFlow::GetInstance()->OnTouch(action, id, x, y, initialX, initialY, shouldPropagate);

    if (shouldPropagate)
    {
        super(action, id, x, y, initialX, initialY);
    }
}
#endif

// === OptionsScreen Hooks ===

HOOK_METHOD(OptionsScreen, OnRender, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> OptionsScreen::OnRender -> Begin (CrashDetectionHooks.cpp)\n")
    super();
    if (this->bOpen)
    {
        CrashDialogManager::GetInstance()->RenderButton();
    }
    CrashReportFlow::GetInstance()->OnRender();
}

HOOK_METHOD(OptionsScreen, MouseMove, (int mX, int mY) -> void)
{
    LOG_HOOK("HOOK_METHOD -> OptionsScreen::MouseMove -> Begin (CrashDetectionHooks.cpp)\n")

    bool shouldPropagate = true;
    CrashReportFlow::GetInstance()->OnMouseMove(mX, mY, shouldPropagate);

    if (shouldPropagate)
    {
        super(mX, mY);
    }
}

HOOK_METHOD(OptionsScreen, MouseClick, (int mX, int mY) -> void)
{
    LOG_HOOK("HOOK_METHOD -> OptionsScreen::MouseClick -> Begin (CrashDetectionHooks.cpp)\n")

    bool shouldPropagate = true;
    CrashReportFlow::GetInstance()->OnMouseClick(mX, mY, shouldPropagate);

    if (shouldPropagate)
    {
        super(mX, mY);
    }
}

#ifdef HS_ANDROID
HOOK_METHOD(OptionsScreen, OnTouch, (TouchAction action, int id, int x, int y, int initialX, int initialY) -> void)
{
    LOG_HOOK("HOOK_METHOD -> OptionsScreen::OnTouch -> Begin (CrashDetectionHooks.cpp)\n")

    bool shouldPropagate = true;
    CrashReportFlow::GetInstance()->OnTouch(action, id, x, y, initialX, initialY, shouldPropagate);

    if (shouldPropagate)
    {
        super(action, id, x, y, initialX, initialY);
    }
}
#endif
