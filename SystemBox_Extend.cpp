#include "SystemBox_Extend.h"
#include "Global.h"

HOOK_METHOD_PRIORITY(SystemBox, constructor, 900, (Point pos, ShipSystem *sys, bool playerUI) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> SystemBox::constructor -> Begin (SystemBox_Extend.cpp)\n")
	super(pos, sys, playerUI);

	auto ex = new SystemBox_Extend();
    uintptr_t dEx = (uintptr_t)ex;

#ifdef __amd64__
    //TODO: Add padding bytes to linux structs
    //?? = (dEx >> 56) & 0xFF;
    //?? = (dEx >> 48) & 0xFF;
    //?? = (dEx >> 40) & 0xFF;
    //?? = (dEx >> 32) & 0xFF;
#endif // __amd64__
	gap_ex_1[0] = (dEx >> 24) & 0xFF;
	gap_ex_1[1] = (dEx >> 16) & 0xFF;
	gap_ex_2[0] = (dEx >> 8) & 0xFF;
	gap_ex_2[1] = dEx & 0xFF;

	ex->orig = this;
}

HOOK_METHOD_PRIORITY(SystemBox, destructor, 900, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> SystemBox::destructor -> Begin (SystemBox_Extend.cpp)\n")
	delete SB_EX(this);
    super();
}

SystemBox_Extend* Get_SystemBox_Extend(SystemBox* c)
{
    uintptr_t dEx = 0;
#ifdef __amd64__
    //TODO: Add padding bytes to linux structs
    //dEx <<= 8;
    //dEx |= ??;
    //dEx <<= 8;
    //dEx |= ??;
    //dEx <<= 8;
    //dEx |= ??;
    //dEx <<= 8;
    //dEx |= ??;
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
