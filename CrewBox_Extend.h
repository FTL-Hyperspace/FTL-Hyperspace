#pragma once
#include "FTLGame.h"
#include "CrewMember_Extend.h"

struct CrewAbilityCooldownBar
{
    ActivatedPower *power;
    ActivatedPowerResource *resource;
    std::vector<ActivatedPower*> morePowers;

    GL_Primitive *prim = nullptr;

    Globals::Rect box;

    bool barActive = false;
    int lastCooldownHeight = 0;

    CrewAbilityCooldownBar(ActivatedPower *_power, Globals::Rect _box) :
    power{_power},
    box{_box}
    {
        resource = nullptr;
    }

    CrewAbilityCooldownBar(ActivatedPowerResource *_resource, Globals::Rect _box) :
    resource{_resource},
    box{_box}
    {
        power = nullptr;
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
    ActivatedPowerResource *resource;

    GL_Primitive *prim = nullptr;

    Globals::Rect box;

    std::pair<int,int> charges = {0,0};

    CrewAbilityChargesBar(ActivatedPower *_power, Globals::Rect _box) :
    power{_power},
    box{_box}
    {
        resource = nullptr;
    }

    CrewAbilityChargesBar(ActivatedPowerResource *_resource, Globals::Rect _box) :
    resource{_resource},
    box{_box}
    {
        power = nullptr;
    }

    ~CrewAbilityChargesBar()
    {
        CSurface::GL_DestroyPrimitive(prim);
    }

    void OnRender();
};

struct ActivatedPowerButton
{
    TextButton button;
    ActivatedPower *power;

    ActivatedPowerButton(TextButton _button) :
    button(_button)
    {
    }
};

struct CrewBox_Extend
{
public:
    CrewBox *orig;

    Point crewPos;
    int skillOffset;

    std::vector<CrewAbilityCooldownBar> cooldownBars;
    std::vector<CrewAbilityChargesBar> chargesBars;
    std::vector<ActivatedPowerButton> powerButtons;
};

CrewBox_Extend* Get_CrewBox_Extend(const CrewBox* c);

#define CBOX_EX Get_CrewBox_Extend
