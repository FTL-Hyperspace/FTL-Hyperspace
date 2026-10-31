#include "ShipManager_Extend.h"


HOOK_METHOD_PRIORITY(ShipManager, constructor, 900, (int iShipId) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> ShipManager::constructor -> Begin (ShipManager_Extend.cpp)\n")


	super(iShipId);

	auto ex = new ShipManager_Extend();

    uintptr_t dEx = (uintptr_t)ex;

#if defined(__amd64__) || defined(__aarch64__)
    this->gap_ex_1[2] = (dEx >> 56) & 0xFF;
    this->gap_ex_1[3] = (dEx >> 48) & 0xFF;
    this->gap_ex_2[2] = (dEx >> 40) & 0xFF;
    this->gap_ex_2[3] = (dEx >> 32) & 0xFF;
#endif // 64-bit
	this->gap_ex_1[0] = (dEx >> 24) & 0xFF;
	this->gap_ex_1[1] = (dEx >> 16) & 0xFF;
	this->gap_ex_2[0] = (dEx >> 8) & 0xFF;
	this->gap_ex_2[1] = dEx & 0xFF;
	ex->orig = this;

    HS_MAKE_TABLE(this)

    auto context = G_->getLuaContext();
    SWIG_NewPointerObj(context->GetLua(), this, context->getLibScript()->types.pShipManager, 0);
    context->getLibScript()->call_on_internal_event_callbacks(InternalEvents::CONSTRUCT_SHIP_MANAGER, 1);
    lua_pop(context->GetLua(), 1);
}

HOOK_METHOD(ShipManager, destructor, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::destructor -> Begin (ShipManager_Extend.cpp)\n")
    HS_BREAK_TABLE(this)
    delete SM_EX(this);

    return super();
}

ShipManager_Extend* Get_ShipManager_Extend(ShipManager* c)
{
    if (!c) return nullptr;

    uintptr_t dEx = 0;

#if defined(__amd64__) || defined(__aarch64__)
    dEx <<= 8;
    dEx |= c->gap_ex_1[2];
    dEx <<= 8;
    dEx |= c->gap_ex_1[3];
    dEx <<= 8;
    dEx |= c->gap_ex_2[2];
    dEx <<= 8;
    dEx |= c->gap_ex_2[3];
#endif // 64-bit
    dEx <<= 8;
    dEx |= c->gap_ex_1[0];
    dEx <<= 8;
    dEx |= c->gap_ex_1[1];
    dEx <<= 8;
    dEx |= c->gap_ex_2[0];
    dEx <<= 8;
    dEx |= c->gap_ex_2[1];

    return (ShipManager_Extend*)dEx;
}
