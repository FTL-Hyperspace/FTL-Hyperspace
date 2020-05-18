#include "CrewMember_Extend.h"
#include "CustomCrew.h"


HOOK_METHOD_PRIORITY(CrewMember, constructor, 900, (CrewBlueprint& blueprint, int shipId, bool intruder, CrewAnimation *animation) -> void)
{
	super(blueprint, shipId, intruder, animation);

	CustomCrewManager* custom = CustomCrewManager::GetInstance();
	auto ex = new CrewMember_Extend();

    DWORD dEx = (DWORD)ex;

	gap_ex_1[0] = (dEx >> 24) & 0xFF;
	gap_ex_1[1] = (dEx >> 16) & 0xFF;
	gap_ex_2[0] = (dEx >> 8) & 0xFF;
	gap_ex_2[1] = dEx & 0xFF;
	ex->orig = this;
}

CrewMember_Extend* Get_CrewMember_Extend(CrewMember* c)
{
    DWORD dEx = 0;
    dEx <<= 8;
    dEx |= c->gap_ex_1[0];
    dEx <<= 8;
    dEx |= c->gap_ex_1[1];
    dEx <<= 8;
    dEx |= c->gap_ex_2[0];
    dEx <<= 8;
    dEx |= c->gap_ex_2[1];

    return (CrewMember_Extend*)dEx;
}
