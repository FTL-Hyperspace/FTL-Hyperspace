#include "Projectile_Extend.h"

HOOK_METHOD_PRIORITY(Projectile, constructor, 900, (Pointf position, int ownerId, int targetId, Pointf target) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> Projectile::constructor -> Begin (Projectile_Extend.cpp)\n")
	super(position, ownerId, targetId, target);

	auto ex = new Projectile_Extend();

    uintptr_t dEx = (uintptr_t)ex;

#ifdef __amd64__
    this->gap_ex_2[2] = (dEx >> 56) & 0xFF;
    this->gap_ex_2[3] = (dEx >> 48) & 0xFF;
    this->gap_ex_2[4] = (dEx >> 40) & 0xFF;
    this->gap_ex_2[5] = (dEx >> 32) & 0xFF;
#endif // __amd64__
	this->gap_ex_1[0] = (dEx >> 24) & 0xFF;
	this->gap_ex_1[1] = (dEx >> 16) & 0xFF;
	this->gap_ex_2[0] = (dEx >> 8) & 0xFF;
	this->gap_ex_2[1] = dEx & 0xFF;
	ex->orig = this;
}

HOOK_METHOD(Projectile, destructor, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> Projectile::destructor -> Begin (Projectile_Extend.cpp)\n")
    delete PR_EX(this);

    return super();
}

Projectile_Extend* Get_Projectile_Extend(Projectile* c)
{
    if (!c) return nullptr;

    uintptr_t dEx = 0;

#ifdef __amd64__
    dEx <<= 8;
    dEx |= c->gap_ex_2[2];
    dEx <<= 8;
    dEx |= c->gap_ex_2[3];
    dEx <<= 8;
    dEx |= c->gap_ex_2[4];
    dEx <<= 8;
    dEx |= c->gap_ex_2[5];
#endif // __amd64__
    dEx <<= 8;
    dEx |= c->gap_ex_1[0];
    dEx <<= 8;
    dEx |= c->gap_ex_1[1];
    dEx <<= 8;
    dEx |= c->gap_ex_2[0];
    dEx <<= 8;
    dEx |= c->gap_ex_2[1];

    return (Projectile_Extend*)dEx;
}
