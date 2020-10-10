#include "FTLGame.h"


struct Room_Extend
{
    Room *orig;

    Animation* roomAnim;
    Animation* iconAnim;
    bool sensorBlind = false;

    ~Room_Extend()
    {
        delete roomAnim;
        delete iconAnim;
    }

    //CrewMember *captain;
};

Room_Extend* Get_Room_Extend(Room* c);

#define RM_EX Get_Room_Extend
