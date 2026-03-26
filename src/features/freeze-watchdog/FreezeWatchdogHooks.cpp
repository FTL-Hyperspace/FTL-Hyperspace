#ifdef __APPLE__

#include "Global.h"
#include "FreezeWatchdog.h"

// Send heartbeat - GenInputEvents runs even when window is unfocused
HOOK_METHOD(CApp, GenInputEvents, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CApp::GenInputEvents -> Begin (FreezeWatchdogHooks.cpp)\n")
    super();
    FreezeWatchdog::SendHeartbeat();
}

// Send heartbeat during loading screens
HOOK_METHOD(ResourceControl, RenderLoadingBar, (float initialProgress, float finalProgress) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ResourceControl::RenderLoadingBar -> Begin (FreezeWatchdogHooks.cpp)\n")
    super(initialProgress, finalProgress);
    FreezeWatchdog::SendHeartbeat();
}

// Signal clean shutdown to watchdog process
HOOK_METHOD(CApp, OnExit, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CApp::OnExit -> Begin (FreezeWatchdogHooks.cpp)\n")
    FreezeWatchdog::Stop();
    super();
}

#endif // __APPLE__
