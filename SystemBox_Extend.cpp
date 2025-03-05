#include "SystemBox_Extend.h"
#include "luaInclude.h"
#include "Global.h"
HOOK_METHOD_PRIORITY(SystemBox, constructor, 900, (Point pos, ShipSystem *sys, bool playerUI) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> SystemBox::constructor -> Begin (SystemBox_Extend.cpp)\n")
	super(pos, sys, playerUI);

	SystemBox_Extend* ex = nullptr;
    //Create proper subclass depnding on system ID
    switch (sys->iSystemType)
    {
        case SYS_ARTILLERY:
            ex = new ArtilleryBox_Extend();
            break;
        case SYS_CLONEBAY:
            ex = new CloneBox_Extend();
            break;
        default:
            ex = new SystemBox_Extend();
            break;
    }


    uintptr_t dEx = (uintptr_t)ex;

#ifdef __amd64__
    this->gap_ex_1[2] = (dEx >> 56) & 0xFF;
    this->gap_ex_1[3] = (dEx >> 48) & 0xFF;
    this->gap_ex_2[2] = (dEx >> 40) & 0xFF;
    this->gap_ex_2[3] = (dEx >> 32) & 0xFF;
#endif // __amd64__
	gap_ex_1[0] = (dEx >> 24) & 0xFF;
	gap_ex_1[1] = (dEx >> 16) & 0xFF;
	gap_ex_2[0] = (dEx >> 8) & 0xFF;
	gap_ex_2[1] = dEx & 0xFF;

	ex->orig = this;

    HS_MAKE_TABLE(this)

    //If necessary, pass constructor arguments, for now user can just access them via the members of the SystemBox*
    auto context = G_->getLuaContext();
    SWIG_NewPointerObj(context->GetLua(), this, context->getLibScript()->types.pSystemBox, 0);
    context->getLibScript()->call_on_internal_event_callbacks(InternalEvents::CONSTRUCT_SYSTEM_BOX, 1);
    lua_pop(context->GetLua(), 1);
}

HOOK_METHOD_PRIORITY(SystemBox, destructor, 900, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> SystemBox::destructor -> Begin (SystemBox_Extend.cpp)\n")
    HS_BREAK_TABLE(this)
	delete SB_EX(this);
    super();
}

SystemBox_Extend* Get_SystemBox_Extend(SystemBox* c)
{
    uintptr_t dEx = 0;
#ifdef __amd64__
    dEx <<= 8;
    dEx |= c->gap_ex_1[2];
    dEx <<= 8;
    dEx |= c->gap_ex_1[3];
    dEx <<= 8;
    dEx |= c->gap_ex_2[2];
    dEx <<= 8;
    dEx |= c->gap_ex_2[3];
#endif // __amd64__
    dEx <<= 8;
    dEx |= c->gap_ex_1[0];
    dEx <<= 8;
    dEx |= c->gap_ex_1[1];
    dEx <<= 8;
    dEx |= c->gap_ex_2[0];
    dEx <<= 8;
    dEx |= c->gap_ex_2[1];

    return (SystemBox_Extend*)dEx;
}

void SystemBox_Extend::OnScrollWheel(float direction)
{

}

void SystemBox_Extend::RButtonUp(int mX, int mY, bool shiftHeld)
{
    
}