#pragma once
#include "Global.h"
#include "EventTooltip.h"
#include "CustomWeapons.h"

static InfoBox* infoBox;
bool g_eventTooltips = true;

HOOK_METHOD(CommandGui, constructor, () -> void)
{
    super();
    infoBox = new InfoBox();
}

HOOK_METHOD(ChoiceBox, MouseMove, (int x, int y) -> void)
{
    super(x,y);

    if (g_eventTooltips)
    {
        infoBox->Clear();

        if (potentialChoice != -1)
        {
            ResourceEvent resource = choices.at(potentialChoice).rewards;

            if (resource.weapon != nullptr && !CustomWeaponManager::instance->GetWeaponDefinition(resource.weapon->name)->hideEventTooltip)
            {
                infoBox->SetBlueprintWeapon(resource.weapon, 0, true, 0);
            }
            else if (resource.drone != nullptr)
            {
                infoBox->SetBlueprintDrone(resource.drone, 0, true, 0);
            }
            else if (resource.augment != nullptr)
            {
                infoBox->SetBlueprintAugment(resource.augment);
            }
            else if (!resource.crewBlue.name.empty() && resource.removeItem.empty())
            {
                infoBox->SetBlueprintCrew(&resource.crewBlue, 0, false);
            }
        }
    }
}

HOOK_METHOD(ChoiceBox, OnRender, () -> void)
{
    super();

    if (g_eventTooltips)
    {
        CSurface::GL_PushMatrix();
        if (centered)
        {
            CSurface::GL_Translate(946, 73);
        }
        else
        {
            CSurface::GL_Translate(796, 73);
        }
        infoBox->OnRender();
        CSurface::GL_PopMatrix();
    }
}
