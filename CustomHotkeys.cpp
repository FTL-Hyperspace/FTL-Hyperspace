#include "CustomHotkeys.h"
#include <boost/lexical_cast.hpp>
std::vector<CustomHotkey> CustomHotkeyManager::customHotkeys =
{
    {"weapon1", SDLKey::SDLK_1, 1, 8},
    {"weapon2", SDLKey::SDLK_2, 1, 9},
    {"weapon3", SDLKey::SDLK_3, 1, 10},
    {"weapon4", SDLKey::SDLK_4, 1, 11},
    {"drone4", SDLKey::SDLK_8, 1, 15},
    {"drone5", SDLKey::SDLK_9, 1, 16},
    {"drone6", SDLKey::SDLK_0, 1, 17},
    {"console", SDLKey::SDLK_BACKSLASH, 0, -1},
    {"speed", SDLKey::SDLK_BACKQUOTE, 0, -1},
    {"info", SDLKey::SDLK_RALT, 0, 11},
    {"temporal", SDLKey::SDLK_SEMICOLON, 2, 11},
    {"un_temporal", SDLKey::SDLK_UNKNOWN, 2, -1},
    {"temporal_speed", SDLKey::SDLK_PERIOD, 1, 8},
    {"temporal_slow", SDLKey::SDLK_COMMA, 1, 9},
    {"artillery1", SDLKey::SDLK_UNKNOWN, 3, 8},
    {"artillery2", SDLKey::SDLK_UNKNOWN, 3, 9},
    {"artillery3", SDLKey::SDLK_UNKNOWN, 3, -1},
    {"artillery4", SDLKey::SDLK_UNKNOWN, 3, -1}
};

bool CustomHotkeyManager::IsDuplicateHotkey(const std::string& hotkeyName)
{
    //Check native hotkeys for duplicate registration
    const auto& hotkeys = Global::GetInstance()->GetSettings()->hotkeys;
    for (const auto& descVector : hotkeys)
    {
        for (const auto& desc : descVector)
        {
            if (hotkeyName == desc.name)
            {
                return true;
            }
        }
    }
    //Check custom hotkeys for duplicate registration
    for (const auto& customHotkey : customHotkeys)
    {
        if (hotkeyName == customHotkey.hotkeyName)
        {
            return true;
        }
    }
    return false;
}

SDLKey CustomHotkeyManager::StringToKey(const std::string& keyName)
{
    if (keyName == "KEY_0") return SDLK_0;
    else if (keyName == "KEY_1") return SDLK_1;
    else if (keyName == "KEY_2") return SDLK_2;
    else if (keyName == "KEY_3") return SDLK_3;
    else if (keyName == "KEY_4") return SDLK_4;
    else if (keyName == "KEY_5") return SDLK_5;
    else if (keyName == "KEY_6") return SDLK_6;
    else if (keyName == "KEY_7") return SDLK_7;
    else if (keyName == "KEY_8") return SDLK_8;
    else if (keyName == "KEY_9") return SDLK_9;
    else if (keyName == "KEY_AT") return SDLK_AT;
    else if (keyName == "KEY_AMPERSAND") return SDLK_AMPERSAND;
    else if (keyName == "KEY_ASTERISK") return SDLK_ASTERISK;
    else if (keyName == "KEY_BACKQUOTE") return SDLK_BACKQUOTE;
    else if (keyName == "KEY_BACKSLASH") return SDLK_BACKSLASH;
    else if (keyName == "KEY_BACKSPACE") return SDLK_BACKSPACE;
    else if (keyName == "KEY_BREAK") return SDLK_BREAK;
    else if (keyName == "KEY_CAPSLOCK") return SDLK_CAPSLOCK;
    else if (keyName == "KEY_CARET") return SDLK_CARET;
    else if (keyName == "KEY_CLEAR") return SDLK_CLEAR;
    else if (keyName == "KEY_COLON") return SDLK_COLON;
    else if (keyName == "KEY_COMMA") return SDLK_COMMA;
    else if (keyName == "KEY_COMPOSE") return SDLK_COMPOSE;
    else if (keyName == "KEY_DELETE") return SDLK_DELETE;
    else if (keyName == "KEY_DOLLAR") return SDLK_DOLLAR;
    else if (keyName == "KEY_DOWN") return SDLK_DOWN;
    else if (keyName == "KEY_END") return SDLK_END;
    else if (keyName == "KEY_EQUALS") return SDLK_EQUALS;
    else if (keyName == "KEY_ESCAPE") return SDLK_ESCAPE;
    else if (keyName == "KEY_EURO") return SDLK_EURO;
    else if (keyName == "KEY_EXCLAIM") return SDLK_EXCLAIM;
    else if (keyName == "KEY_F1") return SDLK_F1;
    else if (keyName == "KEY_F10") return SDLK_F10;
    else if (keyName == "KEY_F11") return SDLK_F11;
    else if (keyName == "KEY_F12") return SDLK_F12;
    else if (keyName == "KEY_F13") return SDLK_F13;
    else if (keyName == "KEY_F14") return SDLK_F14;
    else if (keyName == "KEY_F15") return SDLK_F15;
    else if (keyName == "KEY_F2") return SDLK_F2;
    else if (keyName == "KEY_F3") return SDLK_F3;
    else if (keyName == "KEY_F4") return SDLK_F4;
    else if (keyName == "KEY_F5") return SDLK_F5;
    else if (keyName == "KEY_F6") return SDLK_F6;
    else if (keyName == "KEY_F7") return SDLK_F7;
    else if (keyName == "KEY_F8") return SDLK_F8;
    else if (keyName == "KEY_F9") return SDLK_F9;
    else if (keyName == "KEY_GREATER") return SDLK_GREATER;
    else if (keyName == "KEY_HASH") return SDLK_HASH;
    else if (keyName == "KEY_HELP") return SDLK_HELP;
    else if (keyName == "KEY_HOME") return SDLK_HOME;
    else if (keyName == "KEY_INSERT") return SDLK_INSERT;
    else if (keyName == "KEY_KP0") return SDLK_KP0;
    else if (keyName == "KEY_KP1") return SDLK_KP1;
    else if (keyName == "KEY_KP2") return SDLK_KP2;
    else if (keyName == "KEY_KP3") return SDLK_KP3;
    else if (keyName == "KEY_KP4") return SDLK_KP4;
    else if (keyName == "KEY_KP5") return SDLK_KP5;
    else if (keyName == "KEY_KP6") return SDLK_KP6;
    else if (keyName == "KEY_KP7") return SDLK_KP7;
    else if (keyName == "KEY_KP8") return SDLK_KP8;
    else if (keyName == "KEY_KP9") return SDLK_KP9;
    else if (keyName == "KEY_KP_PERIOD") return SDLK_KP_PERIOD;
    else if (keyName == "KEY_KP_DIVIDE") return SDLK_KP_DIVIDE;
    else if (keyName == "KEY_KP_MULTIPLY") return SDLK_KP_MULTIPLY;
    else if (keyName == "KEY_KP_MINUS") return SDLK_KP_MINUS;
    else if (keyName == "KEY_KP_PLUS") return SDLK_KP_PLUS;
    else if (keyName == "KEY_KP_ENTER") return SDLK_KP_ENTER;
    else if (keyName == "KEY_KP_EQUALS") return SDLK_KP_EQUALS;
    else if (keyName == "KEY_LALT") return SDLK_LALT;
    else if (keyName == "KEY_LCTRL") return SDLK_LCTRL;
    else if (keyName == "KEY_LEFT") return SDLK_LEFT;
    else if (keyName == "KEY_LEFTBRACKET") return SDLK_LEFTBRACKET;
    else if (keyName == "KEY_LEFTPAREN") return SDLK_LEFTPAREN;
    else if (keyName == "KEY_LESS") return SDLK_LESS;
    else if (keyName == "KEY_LMETA") return SDLK_LMETA;
    else if (keyName == "KEY_LSHIFT") return SDLK_LSHIFT;
    else if (keyName == "KEY_LSUPER") return SDLK_LSUPER;
    else if (keyName == "KEY_MENU") return SDLK_MENU;
    else if (keyName == "KEY_MINUS") return SDLK_MINUS;
    else if (keyName == "KEY_MODE") return SDLK_MODE;
    else if (keyName == "KEY_NUMLOCK") return SDLK_NUMLOCK;
    else if (keyName == "KEY_PAGEDOWN") return SDLK_PAGEDOWN;
    else if (keyName == "KEY_PAGEUP") return SDLK_PAGEUP;
    else if (keyName == "KEY_PAUSE") return SDLK_PAUSE;
    else if (keyName == "KEY_PERIOD") return SDLK_PERIOD;
    else if (keyName == "KEY_PLUS") return SDLK_PLUS;
    else if (keyName == "KEY_POWER") return SDLK_POWER;
    else if (keyName == "KEY_PRINTSCREEN") return SDLK_PRINTSCREEN;
    else if (keyName == "KEY_QUESTION") return SDLK_QUESTION;
    else if (keyName == "KEY_QUOTEDBL") return SDLK_QUOTEDBL;
    else if (keyName == "KEY_QUOTE") return SDLK_QUOTE;
    else if (keyName == "KEY_RALT") return SDLK_RALT;
    else if (keyName == "KEY_RCTRL") return SDLK_RCTRL;
    else if (keyName == "KEY_RETURN") return SDLK_RETURN;
    else if (keyName == "KEY_RIGHT") return SDLK_RIGHT;
    else if (keyName == "KEY_RIGHTBRACKET") return SDLK_RIGHTBRACKET;
    else if (keyName == "KEY_RIGHTPAREN") return SDLK_RIGHTPAREN;
    else if (keyName == "KEY_RMETA") return SDLK_RMETA;
    else if (keyName == "KEY_RSHIFT") return SDLK_RSHIFT;
    else if (keyName == "KEY_RSUPER") return SDLK_RSUPER;
    else if (keyName == "KEY_SCROLLOCK") return SDLK_SCROLLOCK;
    else if (keyName == "KEY_SEMICOLON") return SDLK_SEMICOLON;
    else if (keyName == "KEY_SLASH") return SDLK_SLASH;
    else if (keyName == "KEY_SPACE") return SDLK_SPACE;
    else if (keyName == "KEY_SYSREQ") return SDLK_SYSREQ;
    else if (keyName == "KEY_TAB") return SDLK_TAB;
    else if (keyName == "KEY_UNDERSCORE") return SDLK_UNDERSCORE;
    else if (keyName == "KEY_UNDO") return SDLK_UNDO;
    else if (keyName == "KEY_UP") return SDLK_UP;
    else if (keyName == "KEY_a") return SDLK_a;
    else if (keyName == "KEY_b") return SDLK_b;
    else if (keyName == "KEY_c") return SDLK_c;
    else if (keyName == "KEY_d") return SDLK_d;
    else if (keyName == "KEY_e") return SDLK_e;
    else if (keyName == "KEY_f") return SDLK_f;
    else if (keyName == "KEY_g") return SDLK_g;
    else if (keyName == "KEY_h") return SDLK_h;
    else if (keyName == "KEY_i") return SDLK_i;
    else if (keyName == "KEY_j") return SDLK_j;
    else if (keyName == "KEY_k") return SDLK_k;
    else if (keyName == "KEY_l") return SDLK_l;
    else if (keyName == "KEY_m") return SDLK_m;
    else if (keyName == "KEY_n") return SDLK_n;
    else if (keyName == "KEY_o") return SDLK_o;
    else if (keyName == "KEY_p") return SDLK_p;
    else if (keyName == "KEY_q") return SDLK_q;
    else if (keyName == "KEY_r") return SDLK_r;
    else if (keyName == "KEY_s") return SDLK_s;
    else if (keyName == "KEY_t") return SDLK_t;
    else if (keyName == "KEY_u") return SDLK_u;
    else if (keyName == "KEY_v") return SDLK_v;
    else if (keyName == "KEY_w") return SDLK_w;
    else if (keyName == "KEY_x") return SDLK_x;
    else if (keyName == "KEY_y") return SDLK_y;
    else if (keyName == "KEY_z") return SDLK_z;
    else throw std::runtime_error("Invalid hotkey: " + keyName);
}
void CustomHotkeyManager::ParseCustomHotkeyNode(rapidxml::xml_node<char>* node)
{
    for (auto hotkeyNode = node->first_node(); hotkeyNode; hotkeyNode = hotkeyNode->next_sibling())
    {
        //TODO: Use rapidxml errors to include line numbers?
        if (!hotkeyNode->first_attribute("name")) throw std::runtime_error("Hotkey missing name attribute!");
        if (!hotkeyNode->first_attribute("page")) throw std::runtime_error("Hotkey missing page attribute!");

        int page = boost::lexical_cast<int>(hotkeyNode->first_attribute("page")->value());
        if (page < 0 || page > 3) throw std::runtime_error("Hotkey is registered to page: " + std::to_string(page) + ", only pages 0-3 are valid!");

        std::string hotkeyName = hotkeyNode->first_attribute("name")->value();
        if (IsDuplicateHotkey(hotkeyName)) throw std::runtime_error("Attempted to register hotkey under name: " + hotkeyName + " while this name is already in use!");

        SDLKey defaultKey = hotkeyNode->first_attribute("default") ? StringToKey(hotkeyNode->first_attribute("default")->value()) : SDLK_UNKNOWN;
        int position = hotkeyNode->first_attribute("position") ? boost::lexical_cast<int>(hotkeyNode->first_attribute("position")->value()) : -1;
        
        CustomHotkey newKey{hotkeyName, defaultKey, page, position};
        customHotkeys.push_back(newKey);
    }
    Settings::RegenerateHotkeys();
}

HOOK_METHOD(ControlsScreen, OnInit, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ControlsScreen::OnInit -> Begin (CustomHotkeys.cpp)\n")
    for (int i = 0; i < 4; i++)
    {
        buttons[i].clear();
    }

    super();

    Point origin = Point(480, 130);
    int btnsPerColumn = 10;
    for (int page = 0; page < 3; page++)
    {
        if (page == 0)
        {
            btnsPerColumn = 12;
        }
        else if (page == 1)
        {
            btnsPerColumn = 10;
        }
        else if (page == 2)
        {
            btnsPerColumn = 12;
        }

        for (int i = 0; i < buttons[page].size(); i++)
        {
            auto& button = buttons[page][i];

            button.rect.x = origin.x + ((i >= btnsPerColumn) ? 440 : 0);
            button.rect.y = origin.y + (40 * (i >= btnsPerColumn ? i - btnsPerColumn : i));
        }

    }
}

void Settings::RegenerateHotkeys()
{
    SettingValues* settings = G_->GetSettings();

    for (auto i : CustomHotkeyManager::customHotkeys)
    {
        HotkeyDesc hk = HotkeyDesc();
        hk.name = i.hotkeyName;
        hk.key = i.defaultValue;

        for (auto it = settings->hotkeys[i.page].begin(); it != settings->hotkeys[i.page].end(); ++it)
        {
            if (it->name == i.hotkeyName)
            {
                hk = *it;
                settings->hotkeys[i.page].erase(it);
                break;
            }
        }

        if (i.index == -1)
        {
            settings->hotkeys[i.page].push_back(hk);
        }
        else
        {
            settings->hotkeys[i.page].insert(settings->hotkeys[i.page].begin() + i.index, hk);
        }
    }
}

HOOK_STATIC(Settings, ResetHotkeys, () -> void)
{
    LOG_HOOK("HOOK_STATIC -> Settings::ResetHotkeys -> Begin (CustomHotkeys.cpp)\n")
    super();

    RegenerateHotkeys();
}
