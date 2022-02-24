#include "MoreInfoButton.h"
#include "CustomOptions.h"
#include <boost/algorithm/string.hpp>

static Button* moreInfoButton;

HOOK_METHOD(CommandGui, OnInit, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CommandGui::OnInit -> Begin (MoreInfoButton.cpp)\n")
    super();

    moreInfoButton = new Button();
    moreInfoButton->OnInit("statusUI/moreInfoButtonOff", Point(1207, 656));
    moreInfoButton->bActive = true;
    moreInfoButton->SetLocation(Point(1207, 656));
}

HOOK_METHOD(ShipStatus, OnRender, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipStatus::OnRender -> Begin (MoreInfoButton.cpp)\n")
    super();
    if (moreInfoButton)
    moreInfoButton->OnRender();
}

HOOK_METHOD(CommandGui, OnLoop, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CommandGui::OnLoop -> Begin (MoreInfoButton.cpp)\n")
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
        custom->eventTooltips.currentValue = true;
        custom->showReactor.currentValue = true;
        custom->showAllConnections.currentValue = true;
        custom->alternateOxygenRendering.currentValue = false;
        custom->showWeaponCooldown.currentValue = true;
        custom->redesignedWeaponTooltips.currentValue = true;
        custom->redesignedDroneTooltips.currentValue = true;
        custom->redesignedAugmentTooltips.currentValue = true;
        moreInfoButton->SetImageBase("statusUI/moreInfoButtonOn");

        G_->GetSoundControl()->PlaySoundMix("moreInfoOn", -1.f, false);
    }
    else if (custom->altModeChanged)
    {
        custom->altModeChanged = false;
        custom->showAllyPowers.currentValue = custom->showAllyPowers.defaultValue;
        custom->showEnemyPowers.currentValue = custom->showEnemyPowers.defaultValue;
        custom->advancedCrewTooltipRounding.currentAmount = custom->advancedCrewTooltipRounding.defaultAmount;
        custom->eventTooltips.currentValue = custom->eventTooltips.defaultValue;
        custom->showReactor.currentValue = custom->showReactor.defaultValue;
        custom->showAllConnections.currentValue = custom->showAllConnections.defaultValue;
        custom->alternateOxygenRendering.currentValue = custom->alternateOxygenRendering.defaultValue;
        custom->showWeaponCooldown.currentValue = custom->showWeaponCooldown.defaultValue;
        custom->redesignedWeaponTooltips.currentValue = custom->redesignedWeaponTooltips.defaultValue;
        custom->redesignedDroneTooltips.currentValue = custom->redesignedDroneTooltips.defaultValue;
        custom->redesignedAugmentTooltips.currentValue = custom->redesignedAugmentTooltips.defaultValue;
        moreInfoButton->SetImageBase("statusUI/moreInfoButtonOff");

        G_->GetSoundControl()->PlaySoundMix("moreInfoOff", -1.f, false);
    }
}

HOOK_METHOD(CommandGui, MouseMove, (int mX, int mY) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CommandGui::MouseMove -> Begin (MoreInfoButton.cpp)\n")
    super(mX, mY);

    if (moreInfoButton)
    {
        moreInfoButton->MouseMove(mX, mY, false);
        if (moreInfoButton->bActive && moreInfoButton->bHover)
        {
            std::string tooltip = G_->GetTextLibrary()->GetText("tooltip_more_info");

            std::string replaceWith = Settings::GetHotkeyName("info");
            boost::algorithm::replace_all(tooltip, "\\1", replaceWith);
            G_->GetMouseControl()->SetTooltip(tooltip);
        }
    }
}

HOOK_METHOD(CommandGui, LButtonDown, (int mX, int mY, bool shiftHeld) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CommandGui::LButtonDown -> Begin (MoreInfoButton.cpp)\n")
    super(mX, mY, shiftHeld);

    if (moreInfoButton && moreInfoButton->bActive && moreInfoButton->bHover)
    {
        auto custom = CustomOptionsManager::GetInstance();
        custom->altMode = !custom->altMode;
        custom->altModeChanged = true;
    }
}
