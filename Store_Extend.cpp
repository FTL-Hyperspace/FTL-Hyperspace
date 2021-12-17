#include "Store_Extend.h"


HOOK_METHOD_PRIORITY(Store, constructor, 900, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> Store::constructor -> Begin (Store_Extend.cpp)\n")
	super();

	auto ex = new Store_Extend();

    uint32_t dEx = (uint32_t)ex;

	this->gap_ex_fw[0] = (dEx >> 24) & 0xFF;
	this->gap_ex_fw[1] = (dEx >> 16) & 0xFF;
	this->gap_ex_2[0] = (dEx >> 8) & 0xFF;
	this->gap_ex_2[1] = dEx & 0xFF;
	ex->orig = this;
}

HOOK_METHOD(Store, destructor, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> Store::destructor -> Begin (Store_Extend.cpp)\n")
    delete STORE_EX(this);

    return super();
}

Store_Extend* Get_Store_Extend(Store* c)
{
    if (!c) return nullptr;

    uint32_t dEx = 0;

    dEx <<= 8;
    dEx |= c->gap_ex_fw[0];
    dEx <<= 8;
    dEx |= c->gap_ex_fw[1];
    dEx <<= 8;
    dEx |= c->gap_ex_2[0];
    dEx <<= 8;
    dEx |= c->gap_ex_2[1];

    return (Store_Extend*)dEx;
}
