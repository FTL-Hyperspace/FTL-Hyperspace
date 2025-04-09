#pragma once
#include "Global.h"

struct CustomLockdownDefinition
{
    float duration = 12.0f;
    int health = 50;
    GL_Color color = GL_Color(1.f, 1.f, 1.f, 1.f); //The color to tint the shards
    void ParseNode(rapidxml::xml_node<char> *node);
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
    int doorIdx = -1; //Index of the door this shard is attached to, only used for saving/loading
    GL_Color color; //The color to tint the shard
};
LockdownShard_Extend* Get_LockdownShard_Extend(LockdownShard* c);
#define LD_EX Get_LockdownShard_Extend


class CustomLockdownManager
{
public:
    static CustomLockdownDefinition* currentLockdown;
private:
    static CustomLockdownDefinition defaultLockdown;

};
