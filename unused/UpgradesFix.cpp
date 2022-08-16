#include "Global.h"

/* No longer needed, but will keep in case we need it for the future
HOOK_METHOD(Upgrades, OnLoop, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> Upgrades::OnLoop -> Begin (UpgradesFix.cpp)\n")
    if (bOpen)
    {
        bool tempUpgrading = reactorButton.tempUpgrade > 0;

        for (auto i : vUpgradeBoxes)
        {
            if (i->tempUpgrade > 0);
            {
                tempUpgrading = true;
                break;
            }
        }

        undoButton.SetActive(tempUpgrading);
        infoBox.SetSystemId(-1, -1, 0, 0, 0, 0);

        for (auto i : vUpgradeBoxes)
        {
            auto sys = i->system;
            if (sys)
            {
                if (sys->powerState.second + i->tempUpgrade == sys->maxLevel && i->tempUpgrade > 0)
                {
                    currentButton = maxButton;
                }
                else
                {
                    currentButton = boxButton;
                    boxButton->SetActive(sys->powerState.second != sys->maxLevel);
                }

                auto btn = i->currentButton;
                if (btn && (btn->bHover || btn->bSelected))
                {
                    infoBox.SetSystem(sys, i->tempUpgrade, 0, forceSystemInfoWidth);
                }
            }
        }

        if (reactorButton.bActive && reactorButton.bHover)
        {
            auto title = G_->GetTextLibrary()->GetText("upgrade_reactor");

            if (reactorButton.tempUpgrade + shipManager->GetAvailablePower().second <= 4)
            {
                auto descShort = G_->GetTextLibrary()->GetText("reactor_desc_short");

                infoBox.SetText(title, descShort, -1, -1, -1);

                infoBox.SetWarning()
            }
            else
            {
                auto desc = G_->GetTextLibrary()->GetText("reactor_desc");

                infoBox.SetText(title, desc, -1, -1, -1);
            }
        }
    }
}
*/
