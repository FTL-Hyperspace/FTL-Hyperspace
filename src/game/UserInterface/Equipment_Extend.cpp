#include "Equipment_Extend.h"


HOOK_METHOD_PRIORITY(Equipment, constructor, 900, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> Equipment::constructor -> Begin (Equipment_Extend.cpp)\n")
	super();

	auto ex = new Equipment_Extend();
    ex->customEquipment = new CustomEquipment(this);

    uintptr_t dEx = (uintptr_t)ex;

#if defined(__amd64__) || defined(__aarch64__)
    this->gap_ex[2] = (dEx >> 56) & 0xFF;
    this->gap_ex[3] = (dEx >> 48) & 0xFF;
    this->gap_ex[4] = (dEx >> 40) & 0xFF;
    this->gap_ex[5] = (dEx >> 32) & 0xFF;
#endif // 64-bit
	this->gap_ex_fw[0] = (dEx >> 24) & 0xFF;
	this->gap_ex_fw[1] = (dEx >> 16) & 0xFF;
	this->gap_ex[0] = (dEx >> 8) & 0xFF;
	this->gap_ex[1] = dEx & 0xFF;
	ex->orig = this;
}

HOOK_METHOD(Equipment, destructor, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> Equipment::destructor -> Begin (Equipment_Extend.cpp)\n")
    delete EQ_EX(this);

    return super();
}

Equipment_Extend* Get_Equipment_Extend(Equipment* c)
{
    if (!c) return nullptr;

    uintptr_t dEx = 0;

#if defined(__amd64__) || defined(__aarch64__)
    dEx <<= 8;
    dEx |= c->gap_ex[2];
    dEx <<= 8;
    dEx |= c->gap_ex[3];
    dEx <<= 8;
    dEx |= c->gap_ex[4];
    dEx <<= 8;
    dEx |= c->gap_ex[5];
#endif // 64-bit
    dEx <<= 8;
    dEx |= c->gap_ex_fw[0];
    dEx <<= 8;
    dEx |= c->gap_ex_fw[1];
    dEx <<= 8;
    dEx |= c->gap_ex[0];
    dEx <<= 8;
    dEx |= c->gap_ex[1];

    return (Equipment_Extend*)dEx;
}
