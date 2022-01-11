#include "Global.h"

/*
NOT WORKING
HOOK_METHOD_PRIORITY(WeaponBlueprint, constructor, 900, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> WeaponBlueprint::constructor -> Begin (Blueprint_Extend.cpp)\n")
	super();

	auto ex = new Blueprint_Extend();
    DWORD dEx = (DWORD)ex;

	desc.title.gap_ex[0] = (dEx >> 24) & 0xFF;
	desc.title.gap_ex[1] = (dEx >> 16) & 0xFF;
	desc.shortTitle.gap_ex[0] = (dEx >> 8) & 0xFF;
	desc.shortTitle.gap_ex[1] = dEx & 0xFF;
	ex->orig = this;
	ex->weapon = new WeaponBlueprint_Data();
}

Blueprint_Extend* Get_Blueprint_Extend(const Blueprint* c)
{
    DWORD dEx = 0;
    dEx <<= 8;
    dEx |= c->desc.title.gap_ex[0];
    dEx <<= 8;
    dEx |= c->desc.title.gap_ex[1];
    dEx <<= 8;
    dEx |= c->desc.shortTitle.gap_ex[0];
    dEx <<= 8;
    dEx |= c->desc.shortTitle.gap_ex[1];

    return (Blueprint_Extend*)dEx;
}

HOOK_METHOD(Description, copy_assign_2, (const Description& other) -> Description&)
{
    LOG_HOOK("HOOK_METHOD -> Description::copy_assign_2 -> Begin (Blueprint_Extend.cpp)\n")
    auto ret = super(other);

    title.gap_ex[0] = other.title.gap_ex[0];
    title.gap_ex[1] = other.title.gap_ex[1];
    shortTitle.gap_ex[0] = other.shortTitle.gap_ex[0];
    shortTitle.gap_ex[1] = other.shortTitle.gap_ex[1];

    return ret;
}
*/

HOOK_METHOD(Description, constructor, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> Description::constructor -> Begin (Blueprint_Extend.cpp)\n")
    super();
    baseRarity = 0; // fixes undefined behaviour when modder forgets blueprint rarity
}
