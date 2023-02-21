#pragma once
#include "FTLGame.h"
#include "CrewMember_Extend.h"

struct CrewAbilityCooldownBar
{
    ActivatedPower *power;

    GL_Primitive *prim = nullptr;

    Globals::Rect box;

    bool barActive = false;
    int lastCooldownHeight = 0;

    CrewAbilityCooldownBar(ActivatedPower *_power, Globals::Rect _box) :
    power{_power},
    box{_box}
    {
    }

    ~CrewAbilityCooldownBar()
    {
        CSurface::GL_DestroyPrimitive(prim);
    }

    void OnRender();
};

struct CrewAbilityChargesBar
{
    ActivatedPower *power;

    GL_Primitive *prim = nullptr;

    Globals::Rect box;

    std::pair<int,int> charges = {0,0};

    CrewAbilityChargesBar(ActivatedPower *_power, Globals::Rect _box) :
    power{_power},
    box{_box}
    {
    }

    ~CrewAbilityChargesBar()
    {
        CSurface::GL_DestroyPrimitive(prim);
    }

    void OnRender();
};

struct CrewBox_Extend
{
public:
    CrewBox *orig;

    Point crewPos = {0,0};
    std::vector<CrewAbilityCooldownBar> cooldownBars;
    std::vector<CrewAbilityChargesBar> chargesBars;
};

CrewBox_Extend* Get_CrewBox_Extend(const CrewBox* c);

#define CBOX_EX Get_CrewBox_Extend
