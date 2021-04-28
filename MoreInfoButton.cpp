#include "MoreInfoButton.h"
#include "CustomOptions.h"

static Button* moreInfoButton;

HOOK_METHOD(CommandGui, OnInit, () -> void)
{
    super();

    moreInfoButton = new Button();
    moreInfoButton->OnInit("statusUI/moreInfoButtonOff", 1207, 656);
    moreInfoButton->bActive = true;
    moreInfoButton->SetLocation(Point(1207, 656));
}

HOOK_METHOD(ShipStatus, OnRender, () -> void)
{
    super();
    if (moreInfoButton)
    moreInfoButton->OnRender();
}

HOOK_METHOD(CommandGui, OnLoop, () -> void)
{
    super();

    auto custom = CustomOptionsManager::GetInstance();
    if (custom->altMode && custom->altModeChanged)
    {
        custom->altModeChanged = false;
        custom->showAllyPowers.currentValue = true;
        custom->showEnemyPowers.currentValue = true;
        if (custom->advancedCrewTooltipRounding.defaultAmount == 0 || custom->advancedCrewTooltipRounding.defaultAmount == 1)
        {
            custom->advancedCrewTooltipRounding.currentAmount = 2;
        }
        custom->showWeaponCooldown.currentValue = true;
        custom->redesignedWeaponTooltips.currentValue = true;
        moreInfoButton->SetImageBase("statusUI/moreInfoButtonOn");
    }
    else if (custom->altModeChanged)
    {
        custom->altModeChanged = false;
        custom->showAllyPowers.currentValue = custom->showAllyPowers.defaultValue;
        custom->showEnemyPowers.currentValue = custom->showEnemyPowers.defaultValue;
        custom->advancedCrewTooltipRounding.currentAmount = custom->advancedCrewTooltipRounding.defaultAmount;
        custom->showWeaponCooldown.currentValue = custom->showWeaponCooldown.defaultValue;
        custom->redesignedWeaponTooltips.currentValue = custom->redesignedWeaponTooltips.defaultValue;
        moreInfoButton->SetImageBase("statusUI/moreInfoButtonOff");
    }
}

HOOK_METHOD(CommandGui, MouseMove, (int mX, int mY) -> void)
{
    super(mX, mY);

    if (moreInfoButton)
    {
        moreInfoButton->MouseMove(mX, mY, false);
        if (moreInfoButton->bActive && moreInfoButton->bHover)
        {
            G_->GetMouseControl()->SetTooltip(G_->GetTextLibrary()->GetText("tooltip_more_info"));
        }
    }
}

HOOK_METHOD(CommandGui, LButtonDown, (int mX, int mY, bool shiftHeld) -> void)
{
    super(mX, mY, shiftHeld);

    if (moreInfoButton && moreInfoButton->bActive && moreInfoButton->bHover)
    {
        auto custom = CustomOptionsManager::GetInstance();
        custom->altMode = !custom->altMode;
        custom->altModeChanged = true;
    }
}
