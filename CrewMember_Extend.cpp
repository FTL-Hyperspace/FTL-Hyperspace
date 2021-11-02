#include "Global.h"
#include "CustomCrew.h"

HOOK_METHOD_PRIORITY(CrewMember, constructor, 900, (CrewBlueprint& blueprint, int shipId, bool intruder, CrewAnimation *animation) -> void)
{
	super(blueprint, shipId, intruder, animation);

	auto ex = new CrewMember_Extend();
    uint32_t dEx = (uint32_t)ex;

	gap_ex_1[0] = (dEx >> 24) & 0xFF;
	gap_ex_1[1] = (dEx >> 16) & 0xFF;
	gap_ex_2[0] = (dEx >> 8) & 0xFF;
	gap_ex_2[1] = dEx & 0xFF;
	ex->orig = this;
}

HOOK_METHOD(CrewMember, destructor, () -> void)
{
    delete CM_EX(this);
    super();
}

CrewMember_Extend* Get_CrewMember_Extend(CrewMember* c)
{
    uint32_t dEx = 0;
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

HOOK_METHOD(CrewDrone, constructor, (const std::string& _type, const std::string& _name, int _iShipId, const DroneBlueprint* _blueprint, CrewAnimation *_anim) -> void)
{
    super(_type, _name, _iShipId, _blueprint, _anim);

    if (_blueprint->name == "BOARDER_ION")
    {
        CM_EX(this)->isIonDrone = true;
    }
}

HOOK_METHOD_PRIORITY(CrewAnimation, OnInit, 900, (const std::string& _race, Pointf position, bool enemy) -> void)
{
	auto ex = new CrewAnimation_Extend();
    uint32_t dEx = (uint32_t)ex;

	gap_ex_1[0] = (dEx >> 24) & 0xFF;
	gap_ex_1[1] = (dEx >> 16) & 0xFF;
	gap_ex_2[0] = (dEx >> 8) & 0xFF;
	gap_ex_2[1] = dEx & 0xFF;
	ex->orig = this;

	super(_race, position, enemy);
    ex->OnInit(_race, position, enemy);
    if (_race == "boarder_ion")
    {
        CMA_EX(this)->isIonDrone = true;
    }
}

HOOK_METHOD(CrewAnimation, destructor, () -> void)
{
    delete CMA_EX(this);
    super();
}

CrewAnimation_Extend* Get_CrewAnimation_Extend(CrewAnimation* c)
{
    uint32_t dEx = 0;
    dEx <<= 8;
    dEx |= c->gap_ex_1[0];
    dEx <<= 8;
    dEx |= c->gap_ex_1[1];
    dEx <<= 8;
    dEx |= c->gap_ex_2[0];
    dEx <<= 8;
    dEx |= c->gap_ex_2[1];

    return (CrewAnimation_Extend*)dEx;
}
