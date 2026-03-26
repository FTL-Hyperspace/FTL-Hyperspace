#include "Global.h"
#include "integration/CrashReportFlow.h"

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

// === CommandGui Hooks (In-Game UI) ===

// Initialize bug report button
HOOK_METHOD(CommandGui, OnInit, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CommandGui::OnInit -> Begin (CrashDetectionHooks.cpp)\n")
    super();
    CrashReportFlow::GetInstance()->InitButton();
}

// Handle bug report button hover
HOOK_METHOD(CommandGui, MouseMove, (int mX, int mY) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CommandGui::MouseMove -> Begin (CrashDetectionHooks.cpp)\n")

    bool shouldPropagate = true;
    CrashReportFlow::GetInstance()->OnMouseMove(mX, mY, shouldPropagate);

    if (shouldPropagate)
    {
        super(mX, mY);
    }
}

// Handle bug report button click
HOOK_METHOD(CommandGui, LButtonDown, (int mX, int mY, bool shiftHeld) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CommandGui::LButtonDown -> Begin (CrashDetectionHooks.cpp)\n")

    bool shouldPropagate = true;
    CrashReportFlow::GetInstance()->OnMouseClick(mX, mY, shouldPropagate);

    if (shouldPropagate)
    {
        super(mX, mY, shiftHeld);
    }
}

// === ShipStatus Hooks ===

// Render bug report button in game
HOOK_METHOD(ShipStatus, OnRender, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipStatus::OnRender -> Begin (CrashDetectionHooks.cpp)\n")
    super();
    CrashReportFlow::GetInstance()->OnRender();
}
