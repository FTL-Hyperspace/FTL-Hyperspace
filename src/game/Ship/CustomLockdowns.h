#pragma once
#include "FTLGame.h"
#include "helpers/RunWithValue.h"
//Replicates vanilla values
struct CustomLockdownDefinition
{
    float duration = 12.f;
    int health = 50;
    GL_Color color = GL_Color(1.f, 1.f, 1.f, 1.f);
    std::vector<std::string> anims = {"crystal_1", "crystal_2"};
    bool canDilate = true;
    void ParseNode(rapidxml::xml_node<char> *node);
};

struct CustomLockdownManager
{
    static CustomLockdownDefinition defaultLockdown; //Used by every lockdown without a <customLockdown>, mods can change it
    static CustomLockdownDefinition* currentLockdown; //The lockdown that new shards are created with

    //Fields missing from a <customLockdown> node are taken from the default lockdown
    static CustomLockdownDefinition* ParseDefinition(rapidxml::xml_node<char> *node);
    //custom is null for a weapon, crew power or explosion without a <customLockdown>
    static CustomLockdownDefinition* GetDefinition(CustomLockdownDefinition *custom);

    //Runs action with def as the lockdown that new shards are created with
    template <typename Action>
    static void RunWithCustomLockdown(CustomLockdownDefinition *def, Action action)
    {
        RunWithValue(currentLockdown, def, action);
    }
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
    int health; //Int for parity with door health
    Door* door = nullptr; //Pointer to the door this shard is attached to, if any
    int doorId = -1; //Id of the door this shard is attached to, only used for saving/loading
    GL_Color color; //The color to tint the shard
    std::string anim; //The name of the animation, for save/load purposes
    bool canDilate; //Whether this shard is affected by time dilation
};
LockdownShard_Extend* Get_LockdownShard_Extend(LockdownShard* c);
#define LD_EX Get_LockdownShard_Extend
