#include "Projectile_Extend.h"

/*
HOOK_METHOD_PRIORITY(Projectile, constructor, 900, (Pointf position, int ownerId, int targetId, Pointf target) -> void)
{
	super(position, ownerId, targetId, target);

	auto ex = new Projectile_Extend();

    DWORD dEx = (DWORD)ex;

	this->gap_ex_1[0] = (dEx >> 24) & 0xFF;
	this->gap_ex_1[1] = (dEx >> 16) & 0xFF;
	this->gap_ex_2[0] = (dEx >> 8) & 0xFF;
	this->gap_ex_2[1] = dEx & 0xFF;
	ex->orig = this;
}

HOOK_METHOD(Projectile, destructor, () -> void)
{
    delete PR_EX(this);

    return super();
}

Projectile_Extend* Get_Projectile_Extend(Projectile* c)
{
    if (!c) return nullptr;

    DWORD dEx = 0;

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
*/
