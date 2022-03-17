#include "Store_Extend.h"


HOOK_METHOD_PRIORITY(Store, constructor, 900, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> Store::constructor -> Begin (Store_Extend.cpp)\n")
	super();

	auto ex = new Store_Extend();

    uintptr_t dEx = (uintptr_t)ex;

#ifdef __amd64__
    this->gap_ex_fw[2] = (dEx >> 56) & 0xFF;
    this->gap_ex_fw[3] = (dEx >> 48) & 0xFF;
    this->gap_ex_2[2] = (dEx >> 40) & 0xFF;
    this->gap_ex_2[3] = (dEx >> 32) & 0xFF;
#endif // __amd64__
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

    uintptr_t dEx = 0;

#ifdef __amd64__
    dEx <<= 8;
    dEx |= c->gap_ex_fw[2];
    dEx <<= 8;
    dEx |= c->gap_ex_fw[3];
    dEx <<= 8;
    dEx |= c->gap_ex_2[2];
    dEx <<= 8;
    dEx |= c->gap_ex_2[3];
#endif // __amd64__
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
