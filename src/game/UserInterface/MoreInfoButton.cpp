#include "MoreInfoButton.h"
#include "CustomOptions.h"
#include <boost/algorithm/string.hpp>

static Button* moreInfoButton;

static void toggleMoreInfo(bool playSound)
{
    auto custom = CustomOptionsManager::GetInstance();
    custom->altMode = !custom->altMode;
    if (custom->altMode)
    {
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
        if (playSound) G_->GetSoundControl()->PlaySoundMix("moreInfoOn", -1.f, false);
    }
    else
    {
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
        if (playSound) G_->GetSoundControl()->PlaySoundMix("moreInfoOff", -1.f, false);
    }
}

static void initMoreInfo(int x, int y)
{
    if (moreInfoButton == nullptr)
    {
        auto custom = CustomOptionsManager::GetInstance();
        moreInfoButton = new Button();
        moreInfoButton->OnInit("statusUI/moreInfoButtonOff", Point(x, y));
        moreInfoButton->bActive = true;
        // pretend to toggle (will also update image, so above image doesn't matter)
        custom->altMode = !custom->altMode;
        toggleMoreInfo(false);
    }
    moreInfoButton->SetLocation(Point(x, y));
}

HOOK_METHOD(ShipBuilder, Open, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipBuilder::Open -> Begin (MoreInfoButton.cpp)\n")
    super();
    initMoreInfo(-1, 58);
}

HOOK_METHOD(ShipStatus, OnInit, (Point point, float size) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipStatus::OnInit -> Begin (MoreInfoButton.cpp)\n")
    super(point, size);
    initMoreInfo(1207, 656);
}

HOOK_METHOD(ShipBuilder, OnRender, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipBuilder::OnRender -> Begin (MoreInfoButton.cpp)\n")
    super();
    if (moreInfoButton) moreInfoButton->OnRender();
}

HOOK_METHOD(ShipStatus, OnRender, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipStatus::OnRender -> Begin (MoreInfoButton.cpp)\n")
    super();
    if (moreInfoButton) moreInfoButton->OnRender();
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

HOOK_METHOD(ShipBuilder, MouseClick, (int mX, int mY) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipBuilder::MouseClick -> Begin (MoreInfoButton.cpp)\n")
    super(mX, mY);
    if (moreInfoButton && moreInfoButton->bActive && moreInfoButton->bHover)
    {
        toggleMoreInfo(true);
    }
}

HOOK_METHOD(CommandGui, LButtonDown, (int mX, int mY, bool shiftHeld) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CommandGui::LButtonDown -> Begin (MoreInfoButton.cpp)\n")
    super(mX, mY, shiftHeld);
    if (moreInfoButton && moreInfoButton->bActive && moreInfoButton->bHover)
    {
        toggleMoreInfo(true);
    }
}

HOOK_METHOD(ShipBuilder, OnKeyDown, (SDLKey key) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipBuilder::OnKeyDown -> Begin (MoreInfoButton.cpp)\n")
    if (key == Settings::GetHotkey("info"))
    {
        toggleMoreInfo(true);
    }
    super(key);
}

HOOK_METHOD(CommandGui, KeyDown, (SDLKey key, bool shiftHeld) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CommandGui::KeyDown -> Begin (MoreInfoButton.cpp)\n")
    if (key == Settings::GetHotkey("info"))
    {
        toggleMoreInfo(true);
    }
    super(key, shiftHeld);
}
