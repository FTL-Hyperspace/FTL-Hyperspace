#include "CrewMember_Extend.h"



HOOK_METHOD_PRIORITY(CrewMember, constructor, 900, (const CrewBlueprint& blueprint, int unk1, bool unk2, CrewAnimation* anim) -> void)
{
	super(blueprint, unk1, unk2, anim);


	auto ex = new CrewMember_Extend();




    ex->canPhaseThroughDoors = this->species == "ghost";





    DWORD dEx = (DWORD)ex;

	this->gap_ex_1[0] = (dEx >> 24) & 0xFF;
	this->gap_ex_1[1] = (dEx >> 16) & 0xFF;
	this->gap_ex_2[0] = (dEx >> 8) & 0xFF;
	this->gap_ex_2[1] = dEx & 0xFF;
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
