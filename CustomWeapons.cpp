#include "CustomWeapons.h"
#include "CustomOptions.h"
#include "CustomDamage.h"
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>
#include <iomanip>

CustomWeaponManager *CustomWeaponManager::instance = new CustomWeaponManager();

HOOK_METHOD(BlueprintManager, ProcessWeaponBlueprint, (rapidxml::xml_node<char>* node) -> WeaponBlueprint)
{
    LOG_HOOK("HOOK_METHOD -> BlueprintManager::ProcessWeaponBlueprint -> Begin (CustomWeapons.cpp)\n")
    WeaponBlueprint ret = super(node);

    auto weaponDef = CustomWeaponDefinition();
    weaponDef.name = node->first_attribute("name")->value();

    for (auto child = node->first_node(); child = child->next_sibling(); child)
    {
        std::string name = child->name();
        std::string val = child->value();

        if (name == "freeMissileChance")
        {
            weaponDef.freeMissileChance = boost::lexical_cast<int>(val);
        }
        if (name == "descriptionOverride")
        {
            weaponDef.descriptionOverride = val;
        }
        if (name == "hideEventTooltip")
        {
            weaponDef.hideEventTooltip = EventsParser::ParseBoolean(val);
        }
        if (name == "accuracyMod")
        {
            weaponDef.customDamage.accuracyMod = boost::lexical_cast<int>(val);
        }
        if (name == "noSysDamage")
        {
            weaponDef.customDamage.noSysDamage = EventsParser::ParseBoolean(val);
        }
        if (name == "noPersDamage")
        {
            weaponDef.customDamage.noPersDamage = EventsParser::ParseBoolean(val);
        }
    }

    CustomWeaponManager::instance->AddWeaponDefinition(weaponDef);

    return ret;
}

HOOK_METHOD(ShipManager, OnRender, (bool showInterior, bool doorControlMode) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::OnRender -> Begin (CustomWeapons.cpp)\n")
    if (bJumping)
    {
        auto time = jumpAnimation.current_time;
        if (time >= 1.0)
        {
            CSurface::GL_SetColorTint(255.f, 255.f, 255.f, 1.f - ((time - 1.f) * 2.f));
            RenderWeapons();
            CSurface::GL_RemoveColorTint();
        }
        else
        {
            RenderWeapons();
        }
    }
    super(showInterior, doorControlMode);

}

static bool artillery = false;

HOOK_METHOD(ProjectileFactory, NumTargetsRequired, () -> int)
{
    LOG_HOOK("HOOK_METHOD -> ProjectileFactory::NumTargetsRequired -> Begin (CustomWeapons.cpp)\n")
    int ret = super();

    if (artillery)
    {
        int rooms = ShipGraph::GetShipInfo(!iShipId)->rooms.size();
        if (ret > rooms)
        {
            return rooms;
        }
    }

    return ret;
}

HOOK_METHOD(ArtillerySystem, OnLoop, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ArtillerySystem::OnLoop -> Begin (CustomWeapons.cpp)\n")
    artillery = true;
    super();
    artillery = false;
}

HOOK_METHOD(ProjectileFactory, SpendMissiles, () -> int)
{
    LOG_HOOK("HOOK_METHOD -> ProjectileFactory::SpendMissiles -> Begin (CustomWeapons.cpp)\n")
    if (iSpendMissile > 0)
    {
        int randomNum = random32() % 100;

        if (randomNum < CustomWeaponManager::instance->GetWeaponDefinition(blueprint->name)->freeMissileChance)
        {
            iSpendMissile = 0;
        }
    }

    return super();
}

// Weapon Types:
// 0: LASER
// 1: MISSILES
// 2: BEAM
// 3: BOMB
// 4: BURST

static Button* smallAutoFireButton;

HOOK_METHOD(WeaponControl, constructor, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> WeaponControl::constructor -> Begin (CustomWeapons.cpp)\n")
    super();

    smallAutoFireButton = new Button();
    smallAutoFireButton->OnInit("button_small_autofireOn", 0, 0);
    smallAutoFireButton->hitbox.w = 28;
    smallAutoFireButton->hitbox.h = 28;
}

HOOK_METHOD(WeaponControl, LinkShip, (ShipManager *ship) -> void)
{
    LOG_HOOK("HOOK_METHOD -> WeaponControl::LinkShip -> Begin (CustomWeapons.cpp)\n")
    super(ship);

    if(autoFiring){
        smallAutoFireButton->SetImageBase("button_small_autofireOn");
        smallAutoFireButton->bRenderOff = true;
    }
    else {
        smallAutoFireButton->SetImageBase("button_small_autofireOff");
        smallAutoFireButton->bRenderOff = true;
    }
}

HOOK_METHOD(WeaponControl, OnRender, (bool unk) -> void)
{
    LOG_HOOK("HOOK_METHOD -> WeaponControl::OnRender -> Begin (CustomWeapons.cpp)\n")
    super(unk);

    if (this->shipManager->myBlueprint.weaponSlots <= 2 && this->shipManager->myBlueprint.weaponSlots > 0 && this->shipManager->HasSystem(3))
    {
        smallAutoFireButton->hitbox.x = this->location.x + 184;
        smallAutoFireButton->hitbox.y = this->location.y + 61;

        CSurface::GL_PushMatrix();
        CSurface::GL_Translate(this->location.x + 184, this->location.y + 61, 0.0);
        smallAutoFireButton->OnRender();
        CSurface::GL_PopMatrix();
    }
}

HOOK_METHOD(WeaponControl, MouseMove, (int x, int y) -> void)
{
    LOG_HOOK("HOOK_METHOD -> WeaponControl::MouseMove -> Begin (CustomWeapons.cpp)\n")
    super(x, y);

    if (this->shipManager->myBlueprint.weaponSlots <= 2 && this->shipManager->myBlueprint.weaponSlots > 0 && this->shipManager->HasSystem(3) && !Dragging())
    {
        smallAutoFireButton->MouseMove(x, y, false);
        if(smallAutoFireButton->bHover){
            smallAutoFireButton->bRenderOff = false;
            smallAutoFireButton->bRenderSelected = true;

            std::string replaceWith;
            std::string tooltip = G_->GetTextLibrary()->GetText("tooltip_autofire");

            replaceWith = Settings::GetHotkeyName("autofire");
            boost::algorithm::replace_all(tooltip, "\\1", replaceWith);

            replaceWith = Settings::GetHotkeyName("force_autofire");
            boost::algorithm::replace_all(tooltip, "\\2", replaceWith);

            G_->GetMouseControl()->bForceTooltip = true;
            G_->GetMouseControl()->SetTooltip(tooltip);
        }
        else {
            smallAutoFireButton->bRenderOff = true;
            smallAutoFireButton->bRenderSelected = false;

        }

    }
}

HOOK_METHOD(WeaponControl, LButton, (int x, int y, bool holdingShift) -> bool)
{
    LOG_HOOK("HOOK_METHOD -> WeaponControl::LButton -> Begin (CustomWeapons.cpp)\n")
    bool ret = super(x, y, holdingShift);

    if (this->shipManager->myBlueprint.weaponSlots <= 2 && this->shipManager->myBlueprint.weaponSlots > 0 && this->shipManager->HasSystem(3))
    {
        if (smallAutoFireButton->bActive && smallAutoFireButton->bHover)
        {
            SetAutofiring(!autoFiring, false);
            if (autoFiring) {
                smallAutoFireButton->SetImageBase("button_small_autofireOn");
                smallAutoFireButton->bRenderSelected = false;
                smallAutoFireButton->bRenderOff = true;
            }
            else {
                smallAutoFireButton->SetImageBase("button_small_autofireOff");
                smallAutoFireButton->bRenderSelected = false;
                smallAutoFireButton->bRenderOff = true;
            }
            return autoFiring;
        }
    }

    return ret;
}

HOOK_METHOD(WeaponControl, KeyDown, (SDLKey key) -> bool)
{
    LOG_HOOK("HOOK_METHOD -> WeaponControl::KeyDown -> Begin (CustomWeapons.cpp)\n")
    bool ret = super(key);

    if (this->shipManager->myBlueprint.weaponSlots <= 2 && this->shipManager->myBlueprint.weaponSlots > 0 && this->shipManager->HasSystem(3))
    {
        if (key == Settings::GetHotkey("autofire"))
        {
            if (smallAutoFireButton->bActive)
            {
                SetAutofiring(!autoFiring, false);
                if (autoFiring)
                {
                    smallAutoFireButton->SetImageBase("button_small_autofireOn");
                    smallAutoFireButton->bRenderSelected = false;
                    smallAutoFireButton->bRenderOff = true;
                }
                else
                {
                    smallAutoFireButton->SetImageBase("button_small_autofireOff");
                    smallAutoFireButton->bRenderSelected = false;
                    smallAutoFireButton->bRenderOff = true;
                }
                return autoFiring;
            }
        }
    }

    return ret;
}

