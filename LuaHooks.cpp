#include "LuaState.h"
#include "Global.h"

HOOK_METHOD(ShipManager, OnLoop, () -> void)
{
	super();

	G_->lua->PushHook("OnLoop");
	G_->lua->CallHook(0, 0);
}
