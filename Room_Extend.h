#pragma once
#include "FTLGame.h"

struct RoomAnim
{
    Animation *anim;
    int renderLayer;
};

struct Room_Extend
{
    Room *orig;

    std::vector<RoomAnim> roomAnims;
    bool sensorBlind = false;

    float sysDamageResistChance = 0.f;
    float ionDamageResistChance = 0.f;

    int timeDilation = 0;

    ~Room_Extend()
    {

    }

    //CrewMember *captain;
};

Room_Extend* Get_Room_Extend(Room* c);

#define RM_EX Get_Room_Extend
