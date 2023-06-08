#include "Global.h"
#include "Room_Extend.h"

HOOK_METHOD_PRIORITY(Room, constructor, 900, (int shipId, int x, int y, int w, int h, int roomId) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> Room::constructor -> Begin (Room_Extend.cpp)\n")
	super(shipId, x, y, w, h, roomId);

	auto ex = new Room_Extend();

    uintptr_t dEx = (uintptr_t)ex;

#ifdef __amd64__
    this->gap_ex_1[2] = (dEx >> 56) & 0xFF;
    this->gap_ex_1[3] = (dEx >> 48) & 0xFF;
    this->gap_ex_2[2] = (dEx >> 40) & 0xFF;
    this->gap_ex_2[3] = (dEx >> 32) & 0xFF;
#endif // __amd64__
	this->gap_ex_1[0] = (dEx >> 24) & 0xFF;
	this->gap_ex_1[1] = (dEx >> 16) & 0xFF;
	this->gap_ex_2[0] = (dEx >> 8) & 0xFF;
	this->gap_ex_2[1] = dEx & 0xFF;

	ex->orig = this;

    HS_MAKE_TABLE(this)
}

HOOK_METHOD(Room, destructor, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> Room::destructor -> Begin (Room_Extend.cpp)\n")
    HS_BREAK_TABLE(this)
    delete RM_EX(this);

    return super();
}

Room_Extend* Get_Room_Extend(Room* c)
{
    if (!c) return nullptr;

    uintptr_t dEx = 0;

#ifdef __amd64__
    dEx <<= 8;
    dEx |= c->gap_ex_1[2];
    dEx <<= 8;
    dEx |= c->gap_ex_1[3];
    dEx <<= 8;
    dEx |= c->gap_ex_2[2];
    dEx <<= 8;
    dEx |= c->gap_ex_2[3];
#endif // __amd64__
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
    if (speedUpAnim) delete speedUpAnim;
    if (slowDownAnim) delete slowDownAnim;

    delete erosion.anim;
}
