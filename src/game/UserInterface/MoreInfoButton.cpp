#include "MoreInfoButton.h"
#include "CustomOptions.h"
#include <boost/algorithm/string.hpp>

static Button* moreInfoButton;

static void initMoreInfo(int x, int y)
{
    auto custom = CustomOptionsManager::GetInstance();
    if (moreInfoButton == nullptr)
    {
        moreInfoButton = new Button();
        moreInfoButton->OnInit((custom->altMode) ? "statusUI/moreInfoButtonOn" : "statusUI/moreInfoButtonOff", Point(x, y));
        moreInfoButton->bActive = true;
    }
    moreInfoButton->SetLocation(Point(x, y));
}

HOOK_METHOD(ShipBuilder, Open, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipBuilder::Open -> Begin (MoreInfoButton.cpp)\n")
    super();
    initMoreInfo(1196, 100);
}

HOOK_METHOD(CommandGui, OnInit, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CommandGui::OnInit -> Begin (MoreInfoButton.cpp)\n")
    super();
    initMoreInfo(1207, 656);
}

static void renderMoreInfo()
{
    if (moreInfoButton) moreInfoButton->OnRender();
}

HOOK_METHOD(ShipBuilder, OnRender, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipBuilder::OnRender -> Begin (MoreInfoButton.cpp)\n")
    super();
    renderMoreInfo();
}

HOOK_METHOD(ShipStatus, OnRender, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipStatus::OnRender -> Begin (MoreInfoButton.cpp)\n")
    super();
    renderMoreInfo();
}

static void mouseMoveMoreInfo(int x, int y)
{
    if (moreInfoButton)
    {
        moreInfoButton->MouseMove(x, y, false);
        if (moreInfoButton->bActive && moreInfoButton->bHover)
        {
            std::string tooltip = G_->GetTextLibrary()->GetText("tooltip_more_info");
            std::string replaceWith = Settings::GetHotkeyName("info");
            boost::algorithm::replace_all(tooltip, "\\1", replaceWith);
            G_->GetMouseControl()->SetTooltip(tooltip);
        }
    }
}

HOOK_METHOD(ShipBuilder, MouseMove, (int mX, int mY) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipBuilder::MouseMove -> Begin (MoreInfoButton.cpp)\n")
    super(mX, mY);
    mouseMoveMoreInfo(mX, mY);
}

HOOK_METHOD(CommandGui, MouseMove, (int mX, int mY) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CommandGui::MouseMove -> Begin (MoreInfoButton.cpp)\n")
    super(mX, mY);
    if (!this->menuBox.bOpen && !this->optionsBox.bOpen && !this->gameOverScreen.bOpen)
    {
        mouseMoveMoreInfo(mX, mY);
    }
}

static void toggleMoreInfo()
{
    auto custom = CustomOptionsManager::GetInstance();
    custom->altMode = !custom->altMode;
    custom->altModeChanged = true;
    G_->GetSoundControl()->PlaySoundMix(custom->altMode ? "moreInfoOn" : "moreInfoOff", -1.f, false);
}

HOOK_METHOD(ShipBuilder, MouseClick, (int mX, int mY) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipBuilder::MouseClick -> Begin (MoreInfoButton.cpp)\n")
    super(mX, mY);
    if (moreInfoButton && moreInfoButton->bActive && moreInfoButton->bHover)
    {
        toggleMoreInfo();
    }
}

HOOK_METHOD(CommandGui, LButtonDown, (int mX, int mY, bool shiftHeld) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CommandGui::LButtonDown -> Begin (MoreInfoButton.cpp)\n")
    super(mX, mY, shiftHeld);
    if (moreInfoButton && moreInfoButton->bActive && moreInfoButton->bHover)
    {
        toggleMoreInfo();
    }
}

HOOK_METHOD(ShipBuilder, OnKeyDown, (SDLKey key) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipBuilder::OnKeyDown -> Begin (MoreInfoButton.cpp)\n")
    if (key == Settings::GetHotkey("info"))
    {
        toggleMoreInfo();
    }
    super(key);
}

HOOK_METHOD(CommandGui, KeyDown, (SDLKey key, bool shiftHeld) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CommandGui::KeyDown -> Begin (MoreInfoButton.cpp)\n")
    if (key == Settings::GetHotkey("info"))
    {
        toggleMoreInfo();
    }
    super(key, shiftHeld);
}

static void toggleAltMode()
{
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

HOOK_METHOD(ShipBuilder, OnLoop, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipBuilder::OnLoop -> Begin (MoreInfoButton.cpp)\n")
    super();
    toggleAltMode();
}

HOOK_METHOD(CommandGui, OnLoop, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CommandGui::OnLoop -> Begin (MoreInfoButton.cpp)\n")
    super();
    toggleAltMode();
}
