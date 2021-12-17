#include "Global.h"


HOOK_METHOD_PRIORITY(Room, constructor, 900, (int shipId, int x, int y, int w, int h, int roomId) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> Room::constructor -> Begin (Room_Extend.cpp)\n")
	super(shipId, x, y, w, h, roomId);

	auto ex = new Room_Extend();

    uint32_t dEx = (uint32_t)ex;

	this->gap_ex_1[0] = (dEx >> 24) & 0xFF;
	this->gap_ex_1[1] = (dEx >> 16) & 0xFF;
	this->gap_ex_2[0] = (dEx >> 8) & 0xFF;
	this->gap_ex_2[1] = dEx & 0xFF;
	ex->orig = this;
}

HOOK_METHOD(Room, destructor, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> Room::destructor -> Begin (Room_Extend.cpp)\n")
    delete RM_EX(this);

    return super();
}

Room_Extend* Get_Room_Extend(Room* c)
{
    if (!c) return nullptr;

    uint32_t dEx = 0;

    dEx <<= 8;
    dEx |= c->gap_ex_1[0];
    dEx <<= 8;
    dEx |= c->gap_ex_1[1];
    dEx <<= 8;
    dEx |= c->gap_ex_2[0];
    dEx <<= 8;
    dEx |= c->gap_ex_2[1];

    return (Room_Extend*)dEx;
}

Room_Extend::~Room_Extend()
{
    if (speedUpAnim)
        speedUpAnim->destructor();

    if (slowDownAnim)
        slowDownAnim->destructor();

    if (erosionAnim)
        erosionAnim->destructor();

    delete currentErosion;

    for (auto i : roomAnims)
    {
        delete i.anim;
    }
}
