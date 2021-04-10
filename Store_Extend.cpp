#include "Store_Extend.h"


HOOK_METHOD_PRIORITY(Store, constructor, 900, () -> void)
{
	super();

	auto ex = new Store_Extend();

    DWORD dEx = (DWORD)ex;

	this->gap_ex_fw[0] = (dEx >> 24) & 0xFF;
	this->gap_ex_fw[1] = (dEx >> 16) & 0xFF;
	this->gap_ex_2[0] = (dEx >> 8) & 0xFF;
	this->gap_ex_2[1] = dEx & 0xFF;
	ex->orig = this;
}

HOOK_METHOD(Store, destructor, () -> void)
{
    delete STORE_EX(this);

    return super();
}

Store_Extend* Get_Store_Extend(Store* c)
{
    if (!c) return nullptr;

    DWORD dEx = 0;

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
