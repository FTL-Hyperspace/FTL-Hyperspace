#include "CustomColors.h"
#include "Resources.h"
#include "PALMemoryProtection.h"
#include <regex>
#include <codecvt>

GL_Color g_defaultTextButtonColors[4] =
{
    GL_Color(164.f / 255.f, 171.f / 255.f, 160.f / 255.f, 1.f), // inactive
    GL_Color(235.f / 255.f, 245.f / 255.f, 229.f / 255.f, 1.f), // active
    GL_Color(255.f / 255.f, 230.f / 255.f, 94.f / 255.f, 1.f),  // selected
    GL_Color(25.f / 255.f, 49.f / 255.f, 51.f / 255.f, 1.f),    // text
};

GL_Color g_autofireButtonColors[4] =
{
    GL_Color(164.f / 255.f, 171.f / 255.f, 160.f / 255.f, 1.f), // off
    GL_Color(200.f / 255.f, 205.f / 255.f, 198.f / 255.f, 1.f), // offSelected
    GL_Color(255.f / 255.f, 230.f / 255.f, 94.f / 255.f, 1.f),  // on
    GL_Color(255.f / 255.f, 240.f / 255.f, 158.f / 255.f, 1.f), // onSelected
};

GL_Color g_jumpButtonColors[8] =
{
    GL_Color(164.f / 255.f, 171.f / 255.f, 160.f / 255.f, 1.f), // jumpNoEngines
    GL_Color(25.f / 255.f, 49.f / 255.f, 51.f / 255.f, 1.f),    // jumpNoEnginesText
    GL_Color(235.f / 255.f, 245.f / 255.f, 0.f / 255.f, 1.f),   // jumpActive
    GL_Color(235.f / 255.f, 245.f / 255.f, 0.f / 255.f, 1.f),   // jumpSelected
    GL_Color(37.f / 255.f, 74.f / 255.f, 77.f / 255.f, 1.f),    // jumpText
    GL_Color(62.f / 255.f, 125.f / 255.f, 131.f / 255.f, 1.f),  // jumpTextSelected
    GL_Color(253.f / 255.f, 84.f / 255.f, 70.f / 255.f, 1.f),   // jumpNoFuel
    GL_Color(25.f / 255.f, 49.f / 255.f, 51.f / 255.f, 1.f),    // jumpNoFuelText
};

void SetColorPointerValues(rapidxml::xml_node<char>* node, int index, bool divide=false)
{
    GL_Color color;
    ParseColorNode(color, node, divide);
    for (auto i : Global::colorPointers[index])
    {
        MEMPROT_SAVE_PROT(dwOldProtect);
        MEMPROT_PAGESIZE();

        MEMPROT_UNPROTECT(i, sizeof(GL_Color), dwOldProtect);

        *i = color;

        MEMPROT_REPROTECT(i, sizeof(GL_Color), dwOldProtect);
    }
}

void ParseCustomColorsNode(rapidxml::xml_node<char>* node)
{
    for (auto parent = node->first_node(); parent; parent = parent->next_sibling())
    {
        if (strcmp(parent->name(), "textButtons") == 0)
        {
            for (auto child = parent->first_node(); child; child = child->next_sibling())
            {
                std::string name = child->name();

                int arrayIndex = 0;
                int buttonType = 0; // 0: most TextButtons, 1: autofire button, 2: jump button

                if (name == "inactive")
                {
                    arrayIndex = 0;
                }
                else if (name == "active")
                {
                    arrayIndex = 1;
                }
                else if (name == "selected")
                {
                    arrayIndex = 2;
                }
                else if (name == "text")
                {
                    arrayIndex = 3;
                }
                else if (name == "autofireOff")
                {
                    arrayIndex = 0;
                    buttonType = 1;
                }
                else if (name == "autofireOffSelected")
                {
                    arrayIndex = 1;
                    buttonType = 1;
                }
                else if (name == "autofireOn")
                {
                    arrayIndex = 2;
                    buttonType = 1;
                }
                else if (name == "autofireOnSelected")
                {
                    arrayIndex = 3;
                    buttonType = 1;
                }
                else if (name == "jumpNoEngines")
                {
                    arrayIndex = 0;
                    buttonType = 2;
                }
                else if (name == "jumpNoEnginesText")
                {
                    arrayIndex = 1;
                    buttonType = 2;
                }
                else if (name == "jumpActive")
                {
                    arrayIndex = 2;
                    buttonType = 2;
                }
                else if (name == "jumpSelected")
                {
                    arrayIndex = 3;
                    buttonType = 2;
                }
                else if (name == "jumpText")
                {
                    arrayIndex = 4;
                    buttonType = 2;
                }
                else if (name == "jumpTextSelected")
                {
                    arrayIndex = 5;
                    buttonType = 2;
                }
                else if (name == "jumpNoFuel")
                {
                    arrayIndex = 6;
                    buttonType = 2;
                }
                else if (name == "jumpNoFuelText")
                {
                    arrayIndex = 7;
                    buttonType = 2;
                }
                else
                {
                    arrayIndex = -1;
                }

                if (arrayIndex != -1)
                {
                    switch (buttonType)
                    {
                    case 0:
                        ParseColorNode(g_defaultTextButtonColors[arrayIndex], child);
                        break;
                    case 1:
                        ParseColorNode(g_autofireButtonColors[arrayIndex], child);
                        break;
                    case 2:
                        ParseColorNode(g_jumpButtonColors[arrayIndex], child);
                        break;
                    }
                }
            }
        }

        if (strcmp(parent->name(), "systemDetails") == 0)
        {
            for (auto child = parent->first_node(); child; child = child->next_sibling())
            {
                std::string name = child->name();

                if (name == "detailsBarOn")
                {
                    SetColorPointerValues(child, 0);
                }
                if (name == "detailsBarOff")
                {
                    SetColorPointerValues(child, 1);
                }
            }
        }
    }
}

void SetTextButtonDefaultColors(TextButton *btn, bool force=false)
{
    if (!btn->colorsSet || force)
    {
        btn->colorsSet = true;

        btn->colors[0] = g_defaultTextButtonColors[0];
        btn->colors[1] = g_defaultTextButtonColors[1];
        btn->colors[2] = g_defaultTextButtonColors[2];
        btn->textColor = g_defaultTextButtonColors[3];
    }
}

HOOK_METHOD(TextButton, InitPrimitives, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> TextButton::InitPrimitives -> Begin (CustomColors.cpp)\n")
    SetTextButtonDefaultColors(this);
    super();
}

HOOK_METHOD(TextButton, SetInactiveColor, (GL_Color color) -> void)
{
    LOG_HOOK("HOOK_METHOD -> TextButton::SetInactiveColor -> Begin (CustomColors.cpp)\n")
    SetTextButtonDefaultColors(this);
    super(color);
}

HOOK_METHOD(TextButton, SetActiveColor, (GL_Color color) -> void)
{
    LOG_HOOK("HOOK_METHOD -> TextButton::SetActiveColor -> Begin (CustomColors.cpp)\n")
    SetTextButtonDefaultColors(this);
    super(color);
}

HOOK_METHOD(TextButton, SetSelectedColor, (GL_Color color) -> void)
{
    LOG_HOOK("HOOK_METHOD -> TextButton::SetSelectedColor -> Begin (CustomColors.cpp)\n")
    SetTextButtonDefaultColors(this);
    super(color);
}

HOOK_METHOD(TextButton, SetTextColor, (GL_Color color) -> void)
{
    LOG_HOOK("HOOK_METHOD -> TextButton::SetTextColor -> Begin (CustomColors.cpp)\n")
    SetTextButtonDefaultColors(this);
    super(color);
}

HOOK_METHOD(ShipBuilder, Open, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipBuilder::Open -> Begin (CustomColors.cpp)\n")
    super();

    easyButton.SetInactiveColor(g_defaultTextButtonColors[2]);
    normalButton.SetInactiveColor(g_defaultTextButtonColors[2]);
    hardButton.SetInactiveColor(g_defaultTextButtonColors[2]);
    advancedOffButton.SetInactiveColor(g_defaultTextButtonColors[2]);
    advancedOnButton.SetInactiveColor(g_defaultTextButtonColors[2]);
}

HOOK_METHOD(ShipSelect, Open, (int currentLayout, int currentType) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipSelect::Open -> Begin (CustomColors.cpp)\n")
    super(currentLayout, currentType);

    typeA.SetInactiveColor(g_defaultTextButtonColors[2]);
    typeB.SetInactiveColor(g_defaultTextButtonColors[2]);
    typeC.SetInactiveColor(g_defaultTextButtonColors[2]);
}


HOOK_METHOD(WeaponControl, SetAutofiring, (bool on, bool simple) -> void)
{
    LOG_HOOK("HOOK_METHOD -> WeaponControl::SetAutofiring -> Begin (CustomColors.cpp)\n")
    super(on, simple);

    if (on)
    {
        autoFireButton.SetActiveColor(g_autofireButtonColors[2]);
        autoFireButton.SetSelectedColor(g_autofireButtonColors[3]);
    }
    else
    {
        autoFireButton.SetActiveColor(g_autofireButtonColors[0]);
        autoFireButton.SetSelectedColor(g_autofireButtonColors[1]);
    }
}


static bool g_isFTLButton = false;
static bool g_ftlButtonDown = false;
static bool g_ftlButtonHover = false;
static bool g_ftlNoFuel = false;

HOOK_METHOD(TextButton, OnRender, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> TextButton::OnRender -> Begin (CustomColors.cpp)\n")
    if (g_isFTLButton)
    {
        if (!g_ftlButtonDown)
        {
            SetActiveColor(g_jumpButtonColors[2]);
            SetSelectedColor(g_jumpButtonColors[3]);

            if (bHover)
            {
                SetTextColor(g_jumpButtonColors[5]);
            }
            else
            {
                SetTextColor(g_jumpButtonColors[4]);
            }
        }
        else
        {
            SetActiveColor(g_jumpButtonColors[0]);
            SetTextColor(g_jumpButtonColors[1]);
        }

        if (g_ftlNoFuel && !bActive)
        {
            SetActiveColor(g_jumpButtonColors[6]);
            SetTextColor(g_jumpButtonColors[7]);
        }
    }

    super();
}

HOOK_METHOD_PRIORITY(FTLButton, OnRender, 5000, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> FTLButton::OnRender -> Begin (CustomColors.cpp)\n")
    g_isFTLButton = true;
    g_ftlNoFuel = bOutOfFuel;
    g_ftlButtonDown = !ship->SystemFunctions(SYS_PILOT) || ship->IsSystemHacked(SYS_PILOT) > 1 || !ship->SystemFunctions(SYS_ENGINES) || ship->IsSystemHacked(SYS_ENGINES) > 1;

    super();

    g_isFTLButton = false;
}

// custom color

static std::wstring ConvertUTF8ToWstring(const std::string& src)
{
	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
	return converter.from_bytes(src);
}

static std::string ConvertWstringToUTF8(const std::wstring& src)
{
	std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
	return converter.to_bytes(src);
}

bool g_colorEventText = false;
bool g_isMainText = false;
int g_currentFontSize;
int g_currentLineLength;

HOOK_METHOD(ChoiceBox, OnRender, () -> void)
{
    g_isMainText = true;
    g_colorEventText = true;
    super();
    g_colorEventText = false;
}

std::string repeat(int n)
{
    std::string ret;
    for (int i = 0; i < n; i++)
    {
        ret += "§"; //TODO: make dummy characters settable in hyperspace.xml
    }
    return ret;
}

std::string adjustTooLongWord(const std::string& word) // WIP. Didnt test yet.
{
    std::wstring w_word = ConvertUTF8ToWstring(word);
    size_t start = 0;
    
    std::string ret = "\n";
    for (size_t i = 0; i < w_word.length(); i++)
    {
        if (freetype::easy_measureWidth(g_currentFontSize, ConvertWstringToUTF8(w_word.substr(start, i - start))) > g_currentLineLength)
        {
            ret += "\n" + ConvertWstringToUTF8(std::wstring(1, w_word[i]));
            start = i;
        }
        else
        {
            ret += repeat(freetype::easy_measureWidth(g_currentFontSize, ConvertWstringToUTF8(std::wstring(1, w_word[i]))));
        }
    }
    return ret;
}

std::string replaceWithDummyCharacters(const std::string& text, bool begin, bool end)
{
    std::regex re("(\\S+)|(\\s+)");
    std::sregex_iterator it(std::begin(text), std::end(text), re), iter_end;
    if (it == iter_end) return text;

    std::string ret;
    std::string word;
    std::string spaces;
    bool first = true;
    while (true)
    {
        auto&& m = *it;

        word = m.str(1);
        spaces = m.str(2);

        ++it;

        if (it == iter_end)
        {
            if (first)
            {
                if(!word.empty())
                {
                    if (begin && end) ret += repeat(freetype::easy_measureWidth(g_currentFontSize, word));
                    else if (begin && !end) ret += repeat(freetype::easy_measureWidth(g_currentFontSize, word + "§") - 1);
                    else if (!begin && end) ret += repeat(freetype::easy_measureWidth(g_currentFontSize, "§" + word) - 1);
                    else ret += repeat(freetype::easy_measureWidth(g_currentFontSize, "§" + word + "§") - 2);
                }
                else if(!spaces.empty()) ret += spaces;
            }
            else
            {
                if(!word.empty())
                {
                    if (end) ret += repeat(freetype::easy_measureWidth(g_currentFontSize, "§" + word) - 1);
                    else ret += repeat(freetype::easy_measureWidth(g_currentFontSize, "§" + word + "§") - 2);
                }
                else if(!spaces.empty()) ret += spaces;
            }
            break;
        }
        else
        {
            if (first)
            {
                if(!word.empty())
                {
                    if (begin) ret += repeat(freetype::easy_measureWidth(g_currentFontSize, word + "§") - 1);
                    else ret += repeat(freetype::easy_measureWidth(g_currentFontSize, "§" + word + "§") - 2);
                }
                else if(!spaces.empty()) ret += spaces;
            }
            else
            {
                if(!word.empty())
                {
                    ret += repeat(freetype::easy_measureWidth(g_currentFontSize, "§" + word + "§") - 2);
                }
                else if(!spaces.empty()) ret += spaces;
            }
        }
        first = false;
    }
    return  ret;
}

std::string adjustColorHex(std::string hex)// WIP. 1. convert lower to higher: abcdef -> ABCDEF. 2. if a(opacity) is omitted, add FF(255).
{
    return hex;
}

int hexCharToInt(char ch)
{
    if (65 <= ch && ch <= 70) // ABCDEF
    {
        return ch - 55;
    }
    else if (48 <= ch && ch <= 57) // 0123456789
    {
        return ch - 48;
    }
    else return 15; // undefined
}

GL_Color getColorFromHex(const std::string& hex)
{
    float r = (hexCharToInt(hex[0]) * 16 + hexCharToInt(hex[1])) / 255.f;
    float g = (hexCharToInt(hex[2]) * 16 + hexCharToInt(hex[3])) / 255.f;
    float b = (hexCharToInt(hex[4]) * 16 + hexCharToInt(hex[5])) / 255.f;
    float a = (hexCharToInt(hex[6]) * 16 + hexCharToInt(hex[7])) / 255.f;
    return GL_Color(r, g, b, a);
}

bool cmpColors(std::string first, std::string second)
{
    return first == second;
}

struct ColorTextCache;
struct ColorTextCache
{
    ColorTextCache(std::string base, std::unordered_map<std::string, std::string> map)
    {
        base_text = base;
        colorMap = map;
    }
    std::string base_text;
    std::unordered_map<std::string, std::string> colorMap;
};

std::unordered_map<std::string, ColorTextCache*> ColorTextCacheMap;

HOOK_STATIC(freetype, easy_printAutoNewlines, (int fontSize, float x, float y, int line_length, const std::string &text) -> Pointf)
{
    if (!g_colorEventText || !g_isMainText) return super(fontSize, x, y, line_length, text);

    if (ColorTextCacheMap[text] != nullptr)
    {
        ColorTextCache *cache = ColorTextCacheMap[text];
        GL_Color originalColor = CSurface::GL_GetColor();
        Pointf ret = super(fontSize, x, y, line_length, cache->base_text);
        for (auto item : cache->colorMap)
        {
            CSurface::GL_SetColor(getColorFromHex(item.first));
            super(fontSize, x, y, line_length, item.second);
        }
        CSurface::GL_SetColor(originalColor);

        return ret;
    }
    
    std::regex re("\\[color\\:(.*?)\\](.*?)\\[/color\\]");
    std::sregex_iterator it(std::begin(text), std::end(text), re), end;

    if (it == end) return super(fontSize, x, y, line_length, text);

    g_currentFontSize = fontSize;
    g_currentLineLength = line_length;
    std::unordered_map<std::string, std::string> colorTextMap;
    std::string base_text;
    std::string dummy_text;
    std::string content;
    size_t pos;
    size_t tmp_last_pos;
    size_t last_pos = 0;
    size_t origi_length = text.length();
    bool first = true;

    while (true)
    {
        auto&& m = *it;

        std::string color = adjustColorHex(m.str(1));
        content = m.str(2);
        pos = m.position();
        tmp_last_pos = pos + m.length();

        ++it;

        if (colorTextMap.count(color) == 0)
        {
            colorTextMap[color] = dummy_text;
        }

        if (it == end)
        {
            if (first)
            {
                if (pos == 0)
                {
                    if (tmp_last_pos == origi_length)
                    {
                        base_text += replaceWithDummyCharacters(content, true, true);
                        colorTextMap[color] += content;
                    }
                    else
                    {
                        base_text += replaceWithDummyCharacters(content, true, false) + text.substr(tmp_last_pos);
                        colorTextMap[color] += content + replaceWithDummyCharacters(text.substr(tmp_last_pos), false, true);
                    }
                }
                else
                {
                    if (tmp_last_pos == origi_length)
                    {
                        base_text += text.substr(0, pos) + replaceWithDummyCharacters(content, false, true);
                        colorTextMap[color] += replaceWithDummyCharacters(text.substr(0, pos), true, false) + content;
                    }
                    else
                    {
                        base_text += text.substr(0, pos) + replaceWithDummyCharacters(content, false, false) + text.substr(tmp_last_pos);
                        colorTextMap[color] += replaceWithDummyCharacters(text.substr(0, pos), true, false) + content + replaceWithDummyCharacters(text.substr(tmp_last_pos), false, true);
                    }
                }
            }
            else
            {
                if (pos == last_pos)
                {
                    if (tmp_last_pos == origi_length)
                    {
                        for (auto item : colorTextMap)
                        {
                            if (cmpColors(color, item.first))
                            {
                                colorTextMap[item.first] += content;
                            }
                            else
                            {
                                colorTextMap[item.first] += replaceWithDummyCharacters(content, false, true);
                            }
                        }
                        base_text += replaceWithDummyCharacters(content, false, true);
                    }
                    else
                    {
                        for (auto item : colorTextMap)
                        {
                            if (cmpColors(color, item.first))
                            {
                                colorTextMap[item.first] += content + replaceWithDummyCharacters(text.substr(tmp_last_pos), false, true);
                            }
                            else
                            {
                                colorTextMap[item.first] += replaceWithDummyCharacters(content + text.substr(tmp_last_pos), false, true);
                            }
                        }
                        base_text += replaceWithDummyCharacters(content, false, false) + text.substr(tmp_last_pos);
                    }
                }
                else
                {
                    if (tmp_last_pos == origi_length)
                    {
                        for (auto item : colorTextMap)
                        {
                            if (cmpColors(color, item.first))
                            {
                                colorTextMap[item.first] += replaceWithDummyCharacters(text.substr(last_pos, pos - last_pos), false, false) + content;
                            }
                            else
                            {
                                colorTextMap[item.first] += replaceWithDummyCharacters(text.substr(last_pos, pos - last_pos) + content, false, true);
                            }
                        }
                        base_text += text.substr(last_pos, pos - last_pos) + replaceWithDummyCharacters(content, false, true);
                    }
                    else
                    {
                        for (auto item : colorTextMap)
                        {
                            if (cmpColors(color, item.first))
                            {
                                colorTextMap[item.first] += replaceWithDummyCharacters(text.substr(last_pos, pos - last_pos), false, false) + content + replaceWithDummyCharacters(text.substr(tmp_last_pos), false, true);
                            }
                            else
                            {
                                colorTextMap[item.first] += replaceWithDummyCharacters(text.substr(last_pos, pos - last_pos) + content + text.substr(tmp_last_pos), false, true);
                            }
                        }
                        base_text += text.substr(last_pos, pos - last_pos) + replaceWithDummyCharacters(content, false, false) + text.substr(tmp_last_pos);
                    }
                }
            }
            break;
        }
        else
        {
            if (first)
            {
                if (pos == 0)
                {
                    base_text += replaceWithDummyCharacters(content, true, false);
                    colorTextMap[color] += content;
                    dummy_text += replaceWithDummyCharacters(content, true, false);
                }
                else
                {
                    base_text += text.substr(0, pos) + replaceWithDummyCharacters(content, false, false);
                    colorTextMap[color] += replaceWithDummyCharacters(text.substr(0, pos), true, false) + content;
                    dummy_text += replaceWithDummyCharacters(text.substr(0, pos) + content, true, false);
                }
            }
            else
            {
                if (pos == last_pos)
                {
                    for (auto item : colorTextMap)
                    {
                        if (cmpColors(color, item.first))
                        {
                            colorTextMap[item.first] += content;
                        }
                        else
                        {
                            colorTextMap[item.first] += replaceWithDummyCharacters(content, false, false);
                        }
                    }
                    base_text += replaceWithDummyCharacters(content, false, false);
                    dummy_text += replaceWithDummyCharacters(content, false, false);
                }
                else
                {
                    for (auto item : colorTextMap)
                    {
                        if (cmpColors(color, item.first))
                        {
                            colorTextMap[item.first] += replaceWithDummyCharacters(text.substr(last_pos, pos - last_pos), false, false) + content;
                        }
                        else
                        {
                            colorTextMap[item.first] += replaceWithDummyCharacters(text.substr(last_pos, pos - last_pos) + content, false, false);
                        }
                    }
                    base_text += text.substr(last_pos, pos - last_pos) + replaceWithDummyCharacters(content, false, false);
                    dummy_text += replaceWithDummyCharacters(text.substr(last_pos, pos - last_pos) + content, false, false);
                }
            }
        }
        first = false;
        last_pos = tmp_last_pos;
    }

    ColorTextCacheMap[text] = new ColorTextCache(base_text, colorTextMap);

    GL_Color originalColor = CSurface::GL_GetColor();
    Pointf ret = super(fontSize, x, y, line_length, base_text);
    for (auto item : colorTextMap)
    {
        CSurface::GL_SetColor(getColorFromHex(item.first));
        super(fontSize, x, y, line_length, item.second);
    }
    CSurface::GL_SetColor(originalColor);

    return ret;
}