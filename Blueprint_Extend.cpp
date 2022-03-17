#include "Global.h"

/*
NOT WORKING
HOOK_METHOD_PRIORITY(WeaponBlueprint, constructor, 900, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> WeaponBlueprint::constructor -> Begin (Blueprint_Extend.cpp)\n")
	super();

	auto ex = new Blueprint_Extend();
    uintptr_t dEx = (uintptr_t)ex;

#ifdef __amd64__
    desc.title.gap_ex[2] = (dEx >> 56) & 0xFF;
    desc.title.gap_ex[3] = (dEx >> 48) & 0xFF;
    desc.shortTitle.gap_ex[2] = (dEx >> 40) & 0xFF;
    desc.shortTitle.gap_ex[3] = (dEx >> 32) & 0xFF;
#endif // __amd64__
	desc.title.gap_ex[0] = (dEx >> 24) & 0xFF;
	desc.title.gap_ex[1] = (dEx >> 16) & 0xFF;
	desc.shortTitle.gap_ex[0] = (dEx >> 8) & 0xFF;
	desc.shortTitle.gap_ex[1] = dEx & 0xFF;
	ex->orig = this;
	ex->weapon = new WeaponBlueprint_Data();
}

Blueprint_Extend* Get_Blueprint_Extend(const Blueprint* c)
{
    uintptr_t dEx = 0;
#ifdef __amd64__
    dEx <<= 8;
    dEx |= c->desc.title.gap_ex[2];
    dEx <<= 8;
    dEx |= c->desc.title.gap_ex[3];
    dEx <<= 8;
    dEx |= c->desc.shortTitle.gap_ex[2];
    dEx <<= 8;
    dEx |= c->desc.shortTitle.gap_ex[3];
#endif // __amd64__
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

#ifdef __amd64__
    title.gap_ex[2] = other.title.gap_ex[2];
    title.gap_ex[3] = other.title.gap_ex[3];
    shortTitle.gap_ex[2] = other.shortTitle.gap_ex[2];
    shortTitle.gap_ex[3] = other.shortTitle.gap_ex[3];
#endif // __amd64__
    title.gap_ex[0] = other.title.gap_ex[0];
    title.gap_ex[1] = other.title.gap_ex[1];
    shortTitle.gap_ex[0] = other.shortTitle.gap_ex[0];
    shortTitle.gap_ex[1] = other.shortTitle.gap_ex[1];

    return ret;
}
*/

HOOK_METHOD(BlueprintManager, ProcessDescription, (rapidxml::xml_node<char>* node) -> Description)
{
    LOG_HOOK("HOOK_METHOD -> BlueprintManager::ProcessDescription -> Begin (Blueprint_Extend.cpp)\n")
    Description ret = super(node);
    ret.baseRarity = ret.rarity; // fixes undefined behaviour when modder forgets blueprint rarity
    return ret;
}
