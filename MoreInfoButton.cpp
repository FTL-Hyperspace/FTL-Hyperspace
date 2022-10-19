#include "MoreInfoButton.h"
#include "CustomOptions.h"
#include "CustomDrones.h"
#include <iomanip>
#include <sstream>
#include <boost/algorithm/string.hpp>

static Button* moreInfoButton;
static Button* shipInfoButton;

HOOK_METHOD(CommandGui, OnInit, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CommandGui::OnInit -> Begin (MoreInfoButton.cpp)\n")
    super();

    moreInfoButton = new Button();
    moreInfoButton->OnInit("statusUI/moreInfoButtonOff", Point(1207, 656));
    moreInfoButton->bActive = true;
    moreInfoButton->SetLocation(Point(1207, 656));

    shipInfoButton = new Button();
    shipInfoButton->OnInit("statusUI/moreInfoButtonOff", Point(1207, 15));
    shipInfoButton->bActive = true;
    shipInfoButton->SetLocation(Point(1207, 15));
}

HOOK_METHOD(ShipStatus, OnRender, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipStatus::OnRender -> Begin (MoreInfoButton.cpp)\n")
    super();
    if (moreInfoButton)
    moreInfoButton->OnRender();

    if (shipInfoButton)
    shipInfoButton->OnRender();
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

    if (shipInfoButton)
    {
        shipInfoButton->MouseMove(mX, mY, false);
        if (shipInfoButton->bActive && shipInfoButton->bHover)
        {
            ShipManager* enemyShip = G_->GetShipManager(1);
            if (enemyShip != nullptr)
            {
                std::string tooltip = "";
                int sensorsLevel = G_->GetShipManager(0)->GetSystemPower(SystemId::SYS_SENSORS);

                if (enemyShip->weaponSystem != nullptr || enemyShip->artillerySystems.size() != 0)
                {
                    tooltip += "Weapons: ";
                    if (enemyShip->weaponSystem != nullptr)
                    {
                        for (int i = 0; i < enemyShip->weaponSystem->weapons.size(); ++i)
                        {
                            tooltip = tooltip + "\n" + enemyShip->weaponSystem->weapons[i]->name;
                            if (sensorsLevel >= 3)
                            {
                                // show cooldown number
                                tooltip += "\n";
                                std::stringstream stream;
                                stream << std::fixed << std::setprecision(1) << " (" << (enemyShip->weaponSystem->weapons[i]->cooldown.first / (1 + enemyShip->weaponSystem->weapons[i]->GetAugmentationValue("AUTO_COOLDOWN"))) << " / " << (enemyShip->weaponSystem->weapons[i]->cooldown.second / (1 + enemyShip->weaponSystem->weapons[i]->GetAugmentationValue("AUTO_COOLDOWN"))) << ")";
                                tooltip = tooltip + stream.str();
                            }
                        }
                    }
                    if (enemyShip->artillerySystems.size() != 0)
                    {
                        for (int i = 0; i < enemyShip->artillerySystems.size(); ++i)
                        {
                            tooltip = tooltip + "\n" + "Artillery: " + enemyShip->artillerySystems[i]->projectileFactory->name;
                            if (sensorsLevel >= 3)
                            {
                                // show cooldown number
                                tooltip += "\n";
                                std::stringstream stream;
                                stream << std::fixed << std::setprecision(1) << " (" << (enemyShip->artillerySystems[i]->projectileFactory->cooldown.first / (1 + enemyShip->artillerySystems[i]->projectileFactory->GetAugmentationValue("AUTO_COOLDOWN"))) << " / " << (enemyShip->artillerySystems[i]->projectileFactory->cooldown.second / (1 + enemyShip->artillerySystems[i]->projectileFactory->GetAugmentationValue("AUTO_COOLDOWN"))) << ")";
                                tooltip = tooltip + stream.str();
                            }
                        }
                    }
                }

                if (sensorsLevel >= 2)
                {
                    auto crewList = G_->GetShipManager(1)->vCrewList;
                    G_->GetCrewFactory()->GetCloneReadyList(crewList,false);
                    int deadCrewCount = G_->GetCrewFactory()->CountCloneReadyCrew(false);
                    if (enemyShip->vCrewList.size() > 0 || deadCrewCount > 0)
                    {
                        if (tooltip != "")
                        tooltip += "\n\n";
                        tooltip += "Crew: ";
                        for (int i = 0; i < enemyShip->vCrewList.size(); ++i)
                        {
                            if (enemyShip->vCrewList[i] != nullptr && enemyShip->vCrewList[i]->iShipId == 1 && !(enemyShip->vCrewList[i]->IsDrone()))
                            {
                                tooltip = tooltip + "\n" + enemyShip->vCrewList[i]->blueprint.desc.title.GetText() + " (" + std::to_string((int)enemyShip->vCrewList[i]->health.first) + " / " + std::to_string((int)enemyShip->vCrewList[i]->health.second) + ")";
                            }
                        }
                        auto playerShip = G_->GetShipManager(0);
                        if (playerShip != nullptr)
                        {
                            for (int i = 0; i < playerShip->vCrewList.size(); ++i)
                            {
                                if (playerShip->vCrewList[i] != nullptr && playerShip->vCrewList[i]->iShipId == 1  && !(playerShip->vCrewList[i]->IsDrone()))
                                {
                                    tooltip = tooltip + "\n" + playerShip->vCrewList[i]->blueprint.desc.title.GetText() + " (" + std::to_string((int)playerShip->vCrewList[i]->health.first) + " / " + std::to_string((int)playerShip->vCrewList[i]->health.second) + ")";
                                }
                            }
                        }
                        for (int i = crewList.size()-deadCrewCount; i < crewList.size(); ++i)
                        {
                            if (i == crewList.size()-deadCrewCount)
                            {
                                std::stringstream stream;
                                if (sensorsLevel >= 4)
                                {
                                    float value = enemyShip->cloneSystem->fTimeGoal - enemyShip->cloneSystem->fTimeToClone;
                                    if (value < 0)
                                    {
                                        value = 0.f;
                                    }
                                    stream << std::fixed << std::setprecision(1) << value;
                                    tooltip = tooltip + "\n" + crewList[i]->blueprint.desc.title.GetText() + " (" + stream.str() + " sec left)";
                                }
                                else
                                {
                                    float value = enemyShip->cloneSystem->fTimeToClone + 1.f;
                                    stream << std::fixed << std::setprecision(1) << value;
                                    tooltip = tooltip + "\n" + crewList[i]->blueprint.desc.title.GetText() + " (Cloning for " + stream.str() + " sec)";
                                }
                            }
                            else
                            {
                                tooltip = tooltip + "\n" + crewList[i]->blueprint.desc.title.GetText() + " (Dead, in queue)";
                            }
                        }
                    }
                }
                else
                {
                    if (tooltip != "")
                    tooltip += "\n\n";
                    tooltip += "Crew: UNKNOWN";
                }

                if (enemyShip->droneSystem != nullptr)
                {
                    if (sensorsLevel >= 2)
                    {
                        if (tooltip != "")
                        tooltip += "\n\n";
                        tooltip += "Drones: ";
                        for (int i = 0; i < enemyShip->droneSystem->drones.size(); ++i)
                        {
                            tooltip = tooltip + "\n" + enemyShip->droneSystem->drones[i]->blueprint->desc.title.data;
                        }
                    }
                    else
                    {
                        if (tooltip != "")
                        tooltip += "\n\n";
                        tooltip += "Drones: UNKNOWN";
                    }
                }

                int tempFont = G_->GetMouseControl()->tooltipFont;
                G_->GetMouseControl()->tooltipFont = 51;
                G_->GetMouseControl()->SetTooltip(tooltip);
            }

            //std::string replaceWith = Settings::GetHotkeyName("info");
            //boost::algorithm::replace_all(tooltip, "\\1", replaceWith);
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
        G_->GetSoundControl()->PlaySoundMix(custom->altMode ? "moreInfoOn" : "moreInfoOff", -1.f, false);
    }
}
