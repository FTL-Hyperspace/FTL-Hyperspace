#include "LuaState.h"
#include "Global.h"

HOOK_METHOD(ShipManager, OnLoop, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::OnLoop -> Begin (LuaHooks.cpp)\n")
	super();

	G_->lua->PushHook("OnLoop");
	G_->lua->CallHook(0, 0);
}
