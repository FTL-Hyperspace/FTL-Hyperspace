#include "Global.h"

#include "TemporalSystem.h"

static GL_Primitive *moreTargetIcon[6];
static GL_Primitive *moreTargetIconYellow[6];

GL_Primitive *WeaponControl::GetAimingPrimitive(ProjectileFactory *weapon, int i)
{
    if (i<4)
    {
        return weapon->autoFiring ? targetIconYellow[i] : targetIcon[i];
    }
    else if (i<10)
    {
        return weapon->autoFiring ? moreTargetIconYellow[i-4] : moreTargetIcon[i-4];
    }
    return nullptr;
}

void WeaponControl::RenderAimingNew(bool player)
{
    for (int i=0; i<boxes.size(); ++i)
    {
        ProjectileFactory *weapon = ((WeaponBox*)(boxes[i]))->pWeapon;
        if (weapon && !weapon->targets.empty() && !((weapon->targetId == 0) ^ player))
        {
            if (weapon->blueprint->type == 2) // beam
            {
                if (weapon->targets.size() >= 2 && weapon->blueprint->length > 1) // real beam
                {
                    RenderBeamAiming(weapon->targets[1], weapon->targets[0], weapon->autoFiring);
                }
                else if (weapon->targets.size() >= 1 && weapon->blueprint->length == 1) // pinpoint beam
                {
                    GL_Primitive *prim = GetAimingPrimitive(weapon, i);
                    if (prim)
                    {
                        Point grid = ShipGraph::TranslateToGrid(weapon->targets[0].x, weapon->targets[0].y);
                        CSurface::GL_Translate((grid.x * 35.f + 17.5f), (grid.y * 35.f + 17.5f), 0.f);
                        CSurface::GL_RenderPrimitive(prim);
                        CSurface::GL_Translate(-(grid.x * 35.f + 17.5f), -(grid.y * 35.f + 17.5f), 0.f);
                    }
                }
            }
            else // not a beam
            {
                if (weapon->radius != 0) // flak radius
                {
                    CSurface::GL_DrawCircle(weapon->targets[0].x, weapon->targets[0].y, weapon->radius, GL_Color(1.f, 0.f, 0.f, 0.25f));
                }

                GL_Primitive *prim = GetAimingPrimitive(weapon, i);
                if (prim)
                {
                    CSurface::GL_Translate(weapon->targets[0].x, weapon->targets[0].y, 0.f);
                    CSurface::GL_RenderPrimitive(prim);
                    CSurface::GL_Translate(-weapon->targets[0].x, -weapon->targets[0].y, 0.f);
                }
            }
        }
    }
}

HOOK_METHOD(WeaponControl, constructor, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> WeaponControl::constructor -> Begin (AdditionalWeaponSlots.cpp)\n")
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
    RenderAimingNew(false);
}

HOOK_METHOD_PRIORITY(WeaponControl, RenderSelfAiming, 9999, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> WeaponControl::RenderSelfAiming -> Begin (AdditionalWeaponSlots.cpp)\n")
    RenderAimingNew(true);
}

HOOK_METHOD(CombatControl, SetMouseCursor, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CombatControl::SetMouseCursor -> Begin (AdditionalWeaponSlots.cpp)\n")
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
    LOG_HOOK("HOOK_METHOD -> CombatControl::OnRenderCombat -> Begin (AdditionalWeaponSlots.cpp)\n")
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
    LOG_HOOK("HOOK_METHOD_PRIORITY -> MouseControl::OnRender -> Begin (AdditionalWeaponSlots.cpp)\n")

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


HOOK_METHOD(WeaponControl, ArmamentHotkey, (unsigned int i) -> SDLKey)
{
    LOG_HOOK("HOOK_METHOD -> WeaponControl::ArmamentHotkey -> Begin (AdditionalWeaponSlots.cpp)\n")
    if (i >= 4)
    {
        return Settings::GetHotkey("drone" + std::to_string(i-3));
    }
    else
    {
        return super(i);
    }
}

HOOK_METHOD(DroneControl, ArmamentHotkey, (unsigned int i) -> SDLKey)
{
    LOG_HOOK("HOOK_METHOD -> DroneControl::ArmamentHotkey -> Begin (AdditionalWeaponSlots.cpp)\n")
    WeaponControl &weapControl = G_->GetWorld()->commandGui->combatControl.weapControl;

    if (weapControl.boxes.size() > 4)
    {
        return super(i+(weapControl.boxes.size()-4));
    }
    else if (weapControl.boxes.size() == 0)
    {
        if (i < 4)
        {
            return Settings::GetHotkey("weapon" + std::to_string(i+1));
        }
        else
        {
            return super(i-4);
        }
    }
    else if (boxes.size() > 6)
    {
        int n = std::max(weapControl.boxes.size(), 10-boxes.size()) + i;
        if (n < 4)
        {
            return Settings::GetHotkey("weapon" + std::to_string(n+1));
        }
        else
        {
            return super(n-4);
        }
    }

    return super(i);
}

HOOK_METHOD(DroneControl, OnLoop, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> DroneControl::OnLoop -> Begin (AdditionalWeaponSlots.cpp)\n")
    super();

    WeaponControl &weapControl = G_->GetWorld()->commandGui->combatControl.weapControl;

    if (weapControl.boxes.size() > 4)
    {
        for (int i=0; i<boxes.size(); ++i)
        {
            boxes[i]->hotKey = weapControl.boxes.size()+i+1;
        }
    }
    else if (weapControl.boxes.size() == 0)
    {
        for (int i=0; i<boxes.size(); ++i)
        {
            boxes[i]->hotKey = i+1;
        }
    }
    else if (boxes.size() > 6)
    {
        int n = std::max(weapControl.boxes.size(), 10-boxes.size());
        for (int i=0; i<boxes.size(); ++i)
        {
            boxes[i]->hotKey = n+i+1;
        }
    }
}

HOOK_METHOD(ArmamentControl, LinkShip, (ShipManager *ship) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ArmamentControl::LinkShip -> Begin (AdditionalWeaponSlots.cpp)\n")
    super(ship);

    int n = NumArmamentSlots();
    if (n == 1 || n > 4)
    {
        CSurface::GL_DestroyPrimitive(holder);
        CSurface::GL_DestroyPrimitive(holderTab);
        holderImage = G_->GetResources()->GetImageId("box_weapons_bottom" + std::to_string(n) + ".png");

        float size_x = 1.f;
        float size_y = 1.f;

        if (holderImage)
        {
            size_x = holderImage->width_;
            size_y = holderImage->height_;
        }

        holder = CSurface::GL_CreatePixelImagePrimitive(holderImage, 0.f, 0.f, size_x, size_y, 0.f, GL_Color(1.f, 1.f, 1.f, 1.f), false);

        CreateHolderTab();
    }
}

//HOOK_METHOD(WeaponControl, OnLanguageChange, () -> void)
//{
//    super();
//
//    int n = NumArmamentSlots();
//    if (n > 4)
//    {
//        autoFireButton.SetLocation(Point(autoFireButton.position.x + 97*(n-4), autoFireButton.position.y));
//    }
//}
