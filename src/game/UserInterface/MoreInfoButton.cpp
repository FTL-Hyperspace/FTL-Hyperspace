#include "MoreInfoButton.h"
#include "CustomOptions.h"
#include <boost/algorithm/string.hpp>
#ifdef HS_ANDROID
#include "android/IpadUI.h"
#endif

static Button* moreInfoButton;

HOOK_METHOD(CommandGui, OnInit, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CommandGui::OnInit -> Begin (MoreInfoButton.cpp)\n")
    super();

#ifdef HS_ANDROID
    // FTL for iPad's HUD has no room at the bottom right, and the hazard icons take the free
    // part of its top bar: under the top bar on the left, ahead of any event buttons
    Point place(18, 62);
#else
    Point place(1207, 656);
#endif
    moreInfoButton = new Button();
    moreInfoButton->OnInit("statusUI/moreInfoButtonOff", place);
    moreInfoButton->bActive = true;
    moreInfoButton->SetLocation(place);
}

HOOK_METHOD(ShipStatus, OnRender, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipStatus::OnRender -> Begin (MoreInfoButton.cpp)\n")
    super();
#ifdef HS_ANDROID
    // FTL for iPad draws its top bar over the corner of the upgrade and other windows, where
    // the button can't be used
    if (IpadUI::WindowOpen()) return;
#endif
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
        if (custom->advancedCrewTooltipRounding.defaultValue == 0 || custom->advancedCrewTooltipRounding.defaultValue == 1)
        {
            custom->advancedCrewTooltipRounding.currentValue = 2;
        }
        custom->eventTooltips.currentValue = true;
        custom->showReactor.currentValue = true;
        if (!custom->splitAllNodeView.currentValue)
        {
            custom->showAllConnections.currentValue = true;
        }
        custom->alternateOxygenRendering.currentValue = false;
        custom->showWeaponCooldown.currentValue = true;
        custom->redesignedWeaponTooltips.currentValue = true;
        custom->redesignedDroneTooltips.currentValue = true;
        custom->redesignedAugmentTooltips.currentValue = true;
        moreInfoButton->SetImageBase("statusUI/moreInfoButtonOn");
    }
    else if (custom->altModeChanged)
    {
        custom->altModeChanged = false;
        custom->showAllyPowers.currentValue = custom->showAllyPowers.defaultValue;
        custom->showEnemyPowers.currentValue = custom->showEnemyPowers.defaultValue;
        custom->advancedCrewTooltipRounding.currentValue = custom->advancedCrewTooltipRounding.defaultValue;
        custom->eventTooltips.currentValue = custom->eventTooltips.defaultValue;
        custom->showReactor.currentValue = custom->showReactor.defaultValue;
        if (!custom->splitAllNodeView.currentValue)
        {
            custom->showAllConnections.currentValue = custom->showAllConnections.defaultValue;
        }
        custom->alternateOxygenRendering.currentValue = custom->alternateOxygenRendering.defaultValue;
        custom->showWeaponCooldown.currentValue = custom->showWeaponCooldown.defaultValue;
        custom->redesignedWeaponTooltips.currentValue = custom->redesignedWeaponTooltips.defaultValue;
        custom->redesignedDroneTooltips.currentValue = custom->redesignedDroneTooltips.defaultValue;
        custom->redesignedAugmentTooltips.currentValue = custom->redesignedAugmentTooltips.defaultValue;
        moreInfoButton->SetImageBase("statusUI/moreInfoButtonOff");
    }
}

HOOK_METHOD(CommandGui, MouseMove, (int mX, int mY) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CommandGui::MouseMove -> Begin (MoreInfoButton.cpp)\n")
    super(mX, mY);

    if (moreInfoButton && !this->menuBox.bOpen && !this->optionsBox.bOpen && !this->gameOverScreen.bOpen)
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

static void ToggleMoreInfo()
{
    auto custom = CustomOptionsManager::GetInstance();
    custom->altMode = !custom->altMode;
    custom->altModeChanged = true;
    G_->GetSoundControl()->PlaySoundMix(custom->altMode ? "moreInfoOn" : "moreInfoOff", -1.f, false);
}

HOOK_METHOD(CommandGui, LButtonDown, (int mX, int mY, bool shiftHeld) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CommandGui::LButtonDown -> Begin (MoreInfoButton.cpp)\n")
    super(mX, mY, shiftHeld);

    if (moreInfoButton && moreInfoButton->bActive && moreInfoButton->bHover)
    {
        ToggleMoreInfo();
    }
}

#ifdef HS_ANDROID
HOOK_METHOD(CommandGui, OnTouch, (TouchAction action, int id, int x, int y, int initialX, int initialY) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CommandGui::OnTouch -> Begin (MoreInfoButton.cpp)\n")
    super(action, id, x, y, initialX, initialY);

    if (!moreInfoButton) return;
    // Only on the HUD itself: the map and other windows cover the top bar
    if (IpadUI::WindowOpen()) return;
    moreInfoButton->OnTouch(action, id, x, y, initialX, initialY);
    if (moreInfoButton->bActive && moreInfoButton->bActivated)
    {
        ToggleMoreInfo();
    }
}
#endif
