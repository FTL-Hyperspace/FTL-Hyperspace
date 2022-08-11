#include "Global.h"

#include "TemporalSystem.h"

static GL_Primitive *moreTargetIcon[6];
static GL_Primitive *moreTargetIconYellow[6];

HOOK_METHOD(WeaponControl, constructor, () -> void)
{
    super();

    for (int i=0; i<6; ++i)
    {
        moreTargetIcon[i] = G_->GetResources()->CreateImagePrimitiveString("misc/crosshairs_placed" + std::to_string(i+5) + ".png", -26, -26, 0, GL_Color(1.f, 1.f, 1.f, 1.f), 1.f, false);
        moreTargetIconYellow[i] = G_->GetResources()->CreateImagePrimitiveString("misc/crosshairs_placed" + std::to_string(i+5) + "_yellow.png", -26, -26, 0, GL_Color(1.f, 1.f, 1.f, 1.f), 1.f, false);
    }
}

HOOK_METHOD_PRIORITY(WeaponControl, RenderAiming, 9999, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> WeaponControl::RenderAiming -> Begin (AdditionalWeaponSlots.cpp)\n")

    for (int i=0; i<boxes.size(); ++i)
    {
        ProjectileFactory *weapon = ((WeaponBox*)(boxes[i]))->pWeapon;
        if (weapon && !weapon->targets.empty() && weapon->targetId != 0)
        {
            if (weapon->blueprint->type == 2)
            {
                if (weapon->targets.size() >= 2)
                {
                    RenderBeamAiming(weapon->targets[1], weapon->targets[0], weapon->autoFiring);
                }
            }
            else
            {
                if (weapon->radius != 0)
                {
                    CSurface::GL_DrawCircle(weapon->targets[0].x, weapon->targets[0].y, weapon->radius, GL_Color(1.f, 0.f, 0.f, 0.25f));
                }

                GL_Primitive *prim;
                if (i<4)
                {
                    prim = weapon->autoFiring ? targetIconYellow[i] : targetIcon[i];
                }
                else if (i<10)
                {
                    prim = weapon->autoFiring ? moreTargetIconYellow[i-4] : moreTargetIcon[i-4];
                }
                else
                {
                    continue;
                }

                CSurface::GL_Translate(weapon->targets[0].x, weapon->targets[0].y, 0.f);
                CSurface::GL_RenderPrimitive(prim);
                CSurface::GL_Translate(-weapon->targets[0].x, -weapon->targets[0].y, 0.f);
            }
        }
    }
}

HOOK_METHOD_PRIORITY(WeaponControl, RenderSelfAiming, 9999, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> WeaponControl::RenderSelfAiming -> Begin (AdditionalWeaponSlots.cpp)\n")

    for (int i=0; i<boxes.size(); ++i)
    {
        ProjectileFactory *weapon = ((WeaponBox*)(boxes[i]))->pWeapon;
        if (weapon && !weapon->targets.empty() && weapon->targetId == 0)
        {
            if (weapon->blueprint->type == 2)
            {
                if (weapon->targets.size() >= 2)
                {
                    RenderBeamAiming(weapon->targets[1], weapon->targets[0], weapon->autoFiring);
                }
            }
            else
            {
                if (weapon->radius != 0)
                {
                    CSurface::GL_DrawCircle(weapon->targets[0].x, weapon->targets[0].y, weapon->radius, GL_Color(1.f, 0.f, 0.f, 0.25f));
                }

                GL_Primitive *prim;
                if (i<4)
                {
                    prim = weapon->autoFiring ? targetIconYellow[i] : targetIcon[i];
                }
                else if (i<10)
                {
                    prim = weapon->autoFiring ? moreTargetIconYellow[i-4] : moreTargetIcon[i-4];
                }
                else
                {
                    continue;
                }

                CSurface::GL_Translate(weapon->targets[0].x, weapon->targets[0].y, 0.f);
                CSurface::GL_RenderPrimitive(prim);
                CSurface::GL_Translate(-weapon->targets[0].x, -weapon->targets[0].y, 0.f);
            }
        }
    }
}

HOOK_METHOD(CombatControl, SetMouseCursor, () -> void)
{
    super();

    MouseControl *mouse = G_->GetMouseControl();

    if (mouse->aiming_required != 0)
    {
        mouse->aiming_required = (weapControl.armedSlot + 1);

        if (weapControl.autoFiring != G_->GetSettings()->holdingModifier)
        {
            mouse->aiming_required = -mouse->aiming_required;
        }
    }
}

HOOK_METHOD(CombatControl, OnRenderCombat, () -> void)
{
    super();

    MouseControl *mouse = G_->GetMouseControl();

    if (mouse->aiming_required != 0)
    {
        mouse->aiming_required = (weapControl.armedSlot + 1);

        if (weapControl.autoFiring != G_->GetSettings()->holdingModifier)
        {
            mouse->aiming_required = -mouse->aiming_required;
        }
    }
}

HOOK_METHOD_PRIORITY(MouseControl, OnRender, 9999, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> MouseControl::OnRender -> Begin (AdditionalWeaponSlots.cpp)\n")

    if (bHideMouse) return;

    if (valid && (!lastValid || newHover))
    {
        G_->GetSoundControl()->PlaySoundMix("hoverBeep", -1.f, false);
    }

    lastValid = valid;

    if (animateDoor > 0)
    {
        openDoor.Update();
        openDoor.position.x = position.x;
        openDoor.position.y = position.y;
        openDoor.OnRender(1.f, GL_Color(1.f, 1.f, 1.f, 1.f), false);
        return;
    }

    std::string s;
    GL_Texture *tex = nullptr;
    GL_Texture *tex2 = nullptr;

    if (g_iTemporal != TEMPORAL_ARM_NONE)
    {
        if (g_iTemporal == TEMPORAL_ARM_SLOW)
        {
            s = valid ? "mouse/mouse_temporal_slow.png" : "mouse/mouse_temporal_slow_valid.png";
        }
        else
        {
            s = valid ? "mouse/mouse_temporal_speed.png" : "mouse/mouse_temporal_speed_valid.png";
        }
    }
    else if (iMindControlling)
    {
        s = valid ? "mouse/mouse_mind.png" : "mouse/mouse_mind_valid.png";
    }
    else if (iTeleporting)
    {
        if (iTeleporting == 2)
        {
            s = valid ? "mouse/mouse_teleport_in1.png" : "mouse/mouse_teleport_in2.png";
        }
        else
        {
            s = valid ? "mouse/mouse_teleport_out1.png" : "mouse/mouse_teleport_out2.png";
        }
    }
    else if (iHacking)
    {
        s = valid ? "mouse/mouse_hacking.png" : "mouse/mouse_hacking_valid.png";
    }
    else if (bSellingStuff)
    {
        tex = selling;
    }
    else if (aiming_required != 0)
    {
        if (aiming_required < 0)
        {
            s = "mouse/mouse_crosshairs3_" + std::to_string(-aiming_required) + ".png";
            tex2 = G_->GetResources()->GetImageId(valid ? "mouse/mouse_crosshairs.png" : "mouse/mouse_crosshairs_valid2.png");
        }
        else
        {
            s = "mouse/mouse_crosshairs2_" + std::to_string(aiming_required) + ".png";
            tex2 = G_->GetResources()->GetImageId(valid ? "mouse/mouse_crosshairs.png" : "mouse/mouse_crosshairs_valid.png");
        }
    }
    else
    {
        tex = valid ? validPointer : invalidPointer;
    }
    if (tex == nullptr)
    {
        tex = G_->GetResources()->GetImageId(s);
    }

    if ((!bForceTooltip && tooltipTimer <= 0.15f) || tooltip.empty())
    {
        lastTooltipText = "";
    }
    else
    {
        lastTooltipText = tooltip;
        Point p = Point(position.x, position.y+22);
        if (staticTooltip.x != -1 && staticTooltip.y != -1)
        {
            p.x = staticTooltip.x;
            p.y = staticTooltip.y;
        }
        RenderTooltip(p, false);
    }

    CSurface::GL_BlitPixelImage(tex, position.x, position.y, 32.f, 32.f, 0.f, GL_Color(1.f, 1.f, 1.f, 1.f), false);
    if (tex2) CSurface::GL_BlitPixelImage(tex2, position.x, position.y, 32.f, 32.f, 0.f, GL_Color(1.f, 1.f, 1.f, 1.f), false);

    lastAddition = tex2;
    lastIcon = tex;

    lastPosition.x = position.x;
    lastPosition.y = position.y;
}
