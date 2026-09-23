#include "luaApp.h"

// Set the global CApp variable for Lua

CApp *Global_CApp = nullptr;

HOOK_METHOD(CApp, OnInit, () -> bool)
{
    LOG_HOOK("HOOK_METHOD -> CApp::OnInit -> Begin (luaApp.cpp)\n")
    Global_CApp = this;
    return super();
}
