#include "CustomOptions.h"

CustomOptionsManager CustomOptionsManager::instance = CustomOptionsManager();

/*
HOOK_METHOD(OptionsScreen, Open, (bool mainMenu) -> void)
{
    super(mainMenu);
}
*/

/*
HOOK_STATIC(Settings, SaveSettings, () -> void)
{
    super();

    std::ofstream file;
    file.open("settings_hs.ini");

    if (file.is_open())
    {
        SettingValues *settings = G_->GetSettings();

        file << "#List of all hotkeys (including Hyperspace and custom hotkeys)\n";

        for (std::vector<HotkeyDesc> &hotkeyPage : settings->hotkeys)
        {
            for (HotkeyDesc &hotkey : hotkeyPage)
            {
                file << hotkey.name << "=" << hotkey.key << "\n";
            }
        }

        file.close();
    }
    else
    {
        hs_log_file("Failed to open settings_hs.ini for writing\n");
    }
}

HOOK_STATIC(Settings, LoadSettings, () -> void)
{
    super();

    std::ifstream file;
    file.open("settings_hs.ini");

    if (file.is_open())
    {
        SettingValues *settings = G_->GetSettings();

        // do stuff here

        file.close();
    }
    else
    {
        hs_log_file("Failed to open settings_hs.ini for reading\n");
    }
}
*/
