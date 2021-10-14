#include "CustomWeapons.h"
#include "CustomOptions.h"
#include "CustomDamage.h"
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>
#include <iomanip>

CustomWeaponManager *CustomWeaponManager::instance = new CustomWeaponManager();
CustomWeaponDefinition *CustomWeaponManager::currentWeapon = nullptr;

HOOK_STATIC(BlueprintManager, ProcessWeaponBlueprint, (WeaponBlueprint* bp, BlueprintManager *bpM, rapidxml::xml_node<char>* node) -> WeaponBlueprint*)
{
    super(bp, bpM, node);

    auto weaponDef = CustomWeaponDefinition();
    weaponDef.name = node->first_attribute("name")->value();

    for (auto child = node->first_node(); child; child = child->next_sibling())
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
        if (name == "simultaneousFire")
        {
            weaponDef.simultaneousFire = EventsParser::ParseBoolean(val);
        }
        if (name == "fireTime")
        {
            weaponDef.fireTime = boost::lexical_cast<float>(val);
        }
    }

    CustomWeaponManager::instance->AddWeaponDefinition(weaponDef);

    return bp;
}

HOOK_METHOD(ShipManager, OnRender, (bool showInterior, bool doorControlMode) -> void)
{
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
    artillery = true;
    super();
    artillery = false;
}

HOOK_METHOD(ProjectileFactory, SpendMissiles, () -> int)
{
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
    super();

    smallAutoFireButton = new Button();
    smallAutoFireButton->OnInit("button_small_autofireOn", 0, 0);
    smallAutoFireButton->hitbox.w = 28;
    smallAutoFireButton->hitbox.h = 28;
}

HOOK_METHOD(WeaponControl, LinkShip, (ShipManager *ship) -> void)
{
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
    super(x, y);

    if (this->shipManager->myBlueprint.weaponSlots <= 2 && this->shipManager->myBlueprint.weaponSlots > 0 && this->shipManager->HasSystem(3) && !Dragging())
    {
        smallAutoFireButton->MouseMove(x, y, false);
        if(smallAutoFireButton->bHover){
            smallAutoFireButton->bRenderOff = false;
            smallAutoFireButton->bRenderSelected = true;

            std::string replaceWith;
            std::string tooltip = G_->GetTextLibrary()->GetText("tooltip_autofire");

            Settings::GetHotkeyName(replaceWith, "autofire");
            boost::algorithm::replace_all(tooltip, "\\1", replaceWith);

            Settings::GetHotkeyName(replaceWith, "force_autofire");
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

static ProjectileFactory *simultaneousFireWeapon = nullptr;
HOOK_METHOD(ProjectileFactory, GetProjectile, () -> Projectile*)
{
    bool fireShot = weaponVisual.bFireShot;
    Projectile* ret = super();

    if (!queuedProjectiles.empty())
    {
        if (fireShot && CustomWeaponManager::instance->GetWeaponDefinition(blueprint->name)->simultaneousFire)
        {
            simultaneousFireWeapon = this;
        }

        if (blueprint->type == 4 && !blueprint->miniProjectiles.empty())
        {
            if (!fireShot && ret == nullptr)
            {
                if (queuedProjectiles.size() % blueprint->miniProjectiles.size() != 0)
                {
                    ret = queuedProjectiles.back();
                    queuedProjectiles.pop_back();
                    return ret;
                }
                else if (simultaneousFireWeapon == this)
                {
                    ret = queuedProjectiles.back();
                    queuedProjectiles.pop_back();
                }
            }

            if (ret != nullptr)
            {
                // Offset fix for charge flak
                int i = (queuedProjectiles.size() / blueprint->miniProjectiles.size()) * blueprint->miniProjectiles.size();
                if (i < queuedProjectiles.size())
                {
                    for (int j=i+1; j<queuedProjectiles.size(); ++j)
                    {
                        queuedProjectiles[j]->position = queuedProjectiles[i]->position;
                        queuedProjectiles[j]->last_position = queuedProjectiles[i]->last_position;
                    }
                    ret->position = queuedProjectiles[i]->position;
                    ret->last_position = queuedProjectiles[i]->last_position;
                }
            }
        }
        else
        {
            if (simultaneousFireWeapon == this && !fireShot && ret == nullptr)
            {
                ret = queuedProjectiles.back();
                queuedProjectiles.pop_back();
            }
        }
    }
    else
    {
        if (simultaneousFireWeapon == this) simultaneousFireWeapon = nullptr;
    }

    return ret;
}

HOOK_METHOD(WeaponAnimation, StartFire, () -> bool)
{
    bool ret = super();

    if (ret && iChargeLevels > 1 && CustomWeaponManager::currentWeapon && CustomWeaponManager::currentWeapon->simultaneousFire)
    {
        int chargeLength = (anim.info.numFrames - iChargedFrame) / iChargeLevels;
        anim.SetCurrentFrame(iChargedFrame + chargeLength * boostLevel);
    }
}

HOOK_METHOD(ProjectileFactory, constructor, (const WeaponBlueprint* bp, int shipId) -> void)
{
    super(bp, shipId);

    if (bp->type != 2)
    {
        auto def = CustomWeaponManager::instance->GetWeaponDefinition(blueprint->name);
        if (def->fireTime)
        {
            weaponVisual.SetFireTime(def->fireTime);
        }
    }
}

// Fix for weapon animations with many frames.
HOOK_METHOD(WeaponAnimation, Update, () -> void)
{
    if (bFiring)
    {
        auto cFPS = G_->GetCFPS();
        float speedFactor = cFPS->SpeedFactor;
        float speed = speedFactor * 0.0625f * anim.info.numFrames/anim.tracker.time; // frame length * anim FPS
        if (speed > 1.f)
        {
            speed = std::ceil(speed);
            int iSpeed = speed;
            cFPS->SpeedFactor = speedFactor / speed;
            for (int i=1; i<iSpeed; ++i)
            {
                super();
            }
            cFPS->SpeedFactor = speedFactor;
        }
        else
        {
            super();
        }
    }
    else
    {
        super();
    }
}
