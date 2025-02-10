#include "CustomOptions.h"
#include "Global.h"
#include "SystemBox_Extend.h"

HOOK_METHOD(ArtillerySystem, Jump, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ArtillerySystem::Jump -> Begin (ArtillerySystem.cpp)\n")
    super();

    // fixes exploits and potential crash bugs with artillery when jumping while firing
    projectileFactory->ClearAiming();
    projectileFactory->ClearProjectiles();
}

static const Point baseOffset(22, -5);
HOOK_METHOD(ArtilleryBox, constructor, (Point pos, ArtillerySystem* sys) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ArtilleryBox::constructor -> Begin (ArtillerySystem.cpp)\n")
    super(pos, sys);

    SystemBox_Extend* extend = SB_EX(this);
    extend->artilleryButton.OnInit("systemUI/artilleryButton", location);
    extend->artilleryButton.hitbox.w = 17;
    extend->artilleryButton.hitbox.h = 19;
    extend->isArtillery = true;
    extend->offset = baseOffset;
}

HOOK_METHOD(ArtilleryBox, OnRender, (bool ignoreStatus) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ArtilleryBox::OnRender -> Begin (ArtillerySystem.cpp)\n")
    super(ignoreStatus);
    if (CustomOptionsManager::GetInstance()->targetableArtillery.currentValue || pSystem->_shipObj.HasAugmentation("ARTILLERY_ORDER"))
    {
        SystemBox_Extend* extend = SB_EX(this);
        extend->artilleryButton.bActive = artSystem->Functioning();
        ProjectileFactory* armedWeapon = G_->GetCApp()->gui->combatControl.weapControl.armedWeapon;
        extend->artilleryButton.bRenderSelected = armedWeapon == artSystem->projectileFactory;
        extend->offset.y = baseOffset.y - 8 * pSystem->healthState.second;

        CSurface::GL_Translate(extend->offset.x, extend->offset.y);
        extend->artilleryButton.OnRender();
        CSurface::GL_Translate(-extend->offset.x, -extend->offset.y);
        if (extend->artilleryButton.Hovering())
        {
            //TODO: Use GetOverrideTooltip (Not working)
            TextString tooltip = artSystem->projectileFactory->blueprint->desc.tooltip; 
            G_->GetMouseControl()->SetTooltip(tooltip.GetText());
        }
    }
}

HOOK_METHOD(SystemBox, MouseMove, (int x, int y) -> void)
{
    LOG_HOOK("HOOK_METHOD -> SystemBox::MouseMove -> Begin (ArtillerySystem.cpp)\n")
    super(x, y);
    if (CustomOptionsManager::GetInstance()->targetableArtillery.currentValue || pSystem->_shipObj.HasAugmentation("ARTILLERY_ORDER"))
    {
        SystemBox_Extend* extend = SB_EX(this);
        if (extend->isArtillery) extend->artilleryButton.MouseMove(x - extend->offset.x, y - extend->offset.y, false);
    }
}

void CombatControl::ArmArtillery(ArtillerySystem* artillerySystem)
{
    ProjectileFactory* artilleryWeapon = artillerySystem->projectileFactory;
    artilleryWeapon->ClearAiming();
    weapControl.armedWeapon = artilleryWeapon;
    weapControl.armedSlot = -1;
    UpdateAiming();
}

HOOK_METHOD(CombatControl, KeyDown, (SDLKey key) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CombatControl::KeyDown -> Begin (ArtillerySystem.cpp)\n")
    super(key);
    const auto& artillerySystems = shipManager->artillerySystems;
    bool targetableArtillery = CustomOptionsManager::GetInstance()->targetableArtillery.currentValue || shipManager->HasAugmentation("ARTILLERY_ORDER");
    if (key == Settings::GetHotkey("artillery1") && artillerySystems.size() >= 1 && targetableArtillery)
    {
        ArmArtillery(artillerySystems[0]);
    }
    else if (key == Settings::GetHotkey("artillery2") && artillerySystems.size() >= 2 && targetableArtillery)
    {
        ArmArtillery(artillerySystems[1]);
    }
    else if (key == Settings::GetHotkey("artillery3") && artillerySystems.size() >= 3 && targetableArtillery)
    {
        ArmArtillery(artillerySystems[2]);
    }
    else if (key == Settings::GetHotkey("artillery4") && artillerySystems.size() >= 4 && targetableArtillery)
    {
        ArmArtillery(artillerySystems[3]);
    }
}

HOOK_METHOD(SystemBox, MouseClick, (bool shift) -> bool)
{
    LOG_HOOK("HOOK_METHOD -> SystemBox::MouseClick -> Begin (ArtillerySystem.cpp)\n")
    bool ret = super(shift);

    bool targetableArtillery = CustomOptionsManager::GetInstance()->targetableArtillery.currentValue || pSystem->_shipObj.HasAugmentation("ARTILLERY_ORDER");
    SystemBox_Extend* extend = SB_EX(this);
    if (extend->isArtillery && targetableArtillery && extend->artilleryButton.Hovering())
    {  
        ArtillerySystem* artillerySystem = static_cast<ArtillerySystem*>(pSystem);
        G_->GetCApp()->gui->combatControl.ArmArtillery(artillerySystem);
    }
    return ret;
}

void ArtillerySystem::OnLoop_HS_ManualTarget()
{
    ShipSystem::OnLoop();
    int power = GetEffectivePower();
    projectileFactory->powered = power > 0; //TODO: Hook SetPowered
    projectileFactory->SetCooldownModifier(1.5f - 0.25f * power);
    projectileFactory->Update();
    projectileFactory->SetCurrentShip(target);
  
    /* Begin: inline int GetHackLevel(ShipSystem * this) */
    int iHacked = bUnderAttack ? iHackEffect : 0;
    projectileFactory->SetHacked(iHacked);
    projectileFactory->isArtillery = true;
    /*
    if (projectileFactory->ReadyToFire()) 
    {
        if (target->IsCloaked()) return;
        //Vanilla code would have automatic targetting and firing here, instead manual firing is handled through WeaponControl
    
    
    }
    */
}
HOOK_METHOD_PRIORITY(ArtillerySystem, OnLoop, 9998, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> ArtillerySystem::OnLoop -> Begin (CustomWeapons.cpp)\n")
    if (_shipObj.iShipId == 0 && (CustomOptionsManager::GetInstance()->targetableArtillery.currentValue || _shipObj.HasAugmentation("ARTILLERY_ORDER")))
    {
        OnLoop_HS_ManualTarget();
    }
    else
    {
        super();
    }
}
