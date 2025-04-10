#pragma once
#include "FTLGame.h"
struct CustomLockdownDefinition
{
    CustomLockdownDefinition(float duration_, int health_, GL_Color color_, std::vector<std::string> anims_) :
    duration(duration_), health(health_), color(color_), anims(anims_) {};
    CustomLockdownDefinition()
    {
        *this = defaultLockdown;
    };

    float duration;
    int health;
    GL_Color color;
    std::vector<std::string> anims;
    void ParseNode(rapidxml::xml_node<char> *node);

    static CustomLockdownDefinition* currentLockdown;
    static CustomLockdownDefinition defaultLockdown;
};

struct Door_Extend
{
    Door* orig;
    bool wasLockedDown = false; //For tracking when to reset door health
};
Door_Extend* Get_Door_Extend(Door* c);
#define DOOR_EX Get_Door_Extend

struct LockdownShard_Extend
{
    LockdownShard* orig;
    int health; //Int for parity with door health
    Door* door = nullptr; //Pointer to the door this shard is attached to, if any
    int doorId = -1; //Id of the door this shard is attached to, only used for saving/loading
    GL_Color color; //The color to tint the shard
    std::string anim; //The name of the animation, for save/load purposes
};
LockdownShard_Extend* Get_LockdownShard_Extend(LockdownShard* c);
#define LD_EX Get_LockdownShard_Extend
