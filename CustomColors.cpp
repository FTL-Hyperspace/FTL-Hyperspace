#pragma once
#include "CustomColors.h"
#include "Resources.h"
#include "PALMemoryProtection.h"
#include "CustomOptions.h"
#include <regex>
#include <boost/lexical_cast.hpp>

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


// ---Custom Choice Colors---
// NOTE: this feature should be re-coded once ChoiceBox re-written.

std::unordered_map<std::string, ChoiceColor*> ChoiceColorMap;

void ParseChoiceColorNode(rapidxml::xml_node<char>* node)
{
    if (node->first_attribute("name") == nullptr) return;

    std::string name = std::string(node->first_attribute("name")->value());
    if (ChoiceColorMap[name] != nullptr) return;

    ChoiceColor* choiceColor = new ChoiceColor;
    if(node->first_node("normal") != nullptr)
    {
        choiceColor->normal.r = boost::lexical_cast<float>(node->first_node("normal")->first_attribute("r")->value()) / 255.f;
        choiceColor->normal.g = boost::lexical_cast<float>(node->first_node("normal")->first_attribute("g")->value()) / 255.f;
        choiceColor->normal.b = boost::lexical_cast<float>(node->first_node("normal")->first_attribute("b")->value()) / 255.f;
        if (node->first_node("normal")->first_attribute("a") != nullptr) choiceColor->normal.a = boost::lexical_cast<float>(node->first_node("normal")->first_attribute("a")->value()) / 255.f;
    }
    if(node->first_node("hover") != nullptr)
    {
        choiceColor->hover.r = boost::lexical_cast<float>(node->first_node("hover")->first_attribute("r")->value()) / 255.f;
        choiceColor->hover.g = boost::lexical_cast<float>(node->first_node("hover")->first_attribute("g")->value()) / 255.f;
        choiceColor->hover.b = boost::lexical_cast<float>(node->first_node("hover")->first_attribute("b")->value()) / 255.f;
        if (node->first_node("hover")->first_attribute("a") != nullptr) choiceColor->hover.a = boost::lexical_cast<float>(node->first_node("hover")->first_attribute("a")->value()) / 255.f;
    }
    if(node->first_node("disabled") != nullptr)
    {
        choiceColor->disabled.r = boost::lexical_cast<float>(node->first_node("disabled")->first_attribute("r")->value()) / 255.f;
        choiceColor->disabled.g = boost::lexical_cast<float>(node->first_node("disabled")->first_attribute("g")->value()) / 255.f;
        choiceColor->disabled.b = boost::lexical_cast<float>(node->first_node("disabled")->first_attribute("b")->value()) / 255.f;
        if (node->first_node("disabled")->first_attribute("a") != nullptr) choiceColor->disabled.a = boost::lexical_cast<float>(node->first_node("disabled")->first_attribute("a")->value()) / 255.f;
    }
    if(node->first_node("blue_option") != nullptr)
    {
        choiceColor->blue_option.r = boost::lexical_cast<float>(node->first_node("blue_option")->first_attribute("r")->value()) / 255.f;
        choiceColor->blue_option.g = boost::lexical_cast<float>(node->first_node("blue_option")->first_attribute("g")->value()) / 255.f;
        choiceColor->blue_option.b = boost::lexical_cast<float>(node->first_node("blue_option")->first_attribute("b")->value()) / 255.f;
        if (node->first_node("blue_option")->first_attribute("a") != nullptr) choiceColor->blue_option.a = boost::lexical_cast<float>(node->first_node("blue_option")->first_attribute("a")->value()) / 255.f;
    }
    
    ChoiceColorMap[name] = choiceColor;
}


std::string EncodeChoicecColorName(char* name)
{
    std::string info = "[[#C:" + std::string(name) + "]]";
    return info;
}

GL_Color DecodeChoiceColorName(std::string text, GL_Color currentColor)
{
    ChoiceColor* choiceColor = ChoiceColorMap[text];
    if (choiceColor == nullptr)
    {
        return currentColor;
    }

    GL_Color ret(currentColor.r, currentColor.g, currentColor.b, currentColor.a);
    if (currentColor.r == 1.f && currentColor.g == 1.f && currentColor.b == 1.f && currentColor.a == 1.f)
    {
        // normal; white
        ret.r = choiceColor->normal.r;
        ret.g = choiceColor->normal.g;
        ret.b = choiceColor->normal.b;
        if (choiceColor->normal.a != NULL) ret.a = choiceColor->normal.a;
    }
    else if (currentColor.r == 0.9529412f && currentColor.g == 1.f && currentColor.b == 0.3137255f && currentColor.a == 1.f)
    {
        // hover; yellow
        ret.r = choiceColor->hover.r;
        ret.g = choiceColor->hover.g;
        ret.b = choiceColor->hover.b;
        if (choiceColor->hover.a != NULL) ret.a = choiceColor->hover.a;
    }
    else if (currentColor.r == 0.5882353f && currentColor.g == 0.5882353f && currentColor.b == 0.5882353f && currentColor.a == 1.f)
    {
        // disabled; gray
        ret.r = choiceColor->disabled.r;
        ret.g = choiceColor->disabled.g;
        ret.b = choiceColor->disabled.b;
        if (choiceColor->disabled.a != NULL) ret.a = choiceColor->disabled.a;
    }
    else if (currentColor.r == 0.f && currentColor.g == 0.7647059f && currentColor.b == 1.f && currentColor.a == 1.f)
    {
        // blue_option; cyan
        ret.r = choiceColor->blue_option.r;
        ret.g = choiceColor->blue_option.g;
        ret.b = choiceColor->blue_option.b;
        if (choiceColor->blue_option.a != NULL) ret.a = choiceColor->blue_option.a;
    }
    return ret;
}

HOOK_METHOD(EventsParser, ProcessChoice, (EventTemplate *event, rapidxml::xml_node<char> *node, const std::string &eventName) -> void)
{
    if (CustomOptionsManager::GetInstance()->enableCustomChoiceColors.currentValue && node->first_node("text")->first_attribute("color") != nullptr)
    {
        node->first_node("text")->value(std::strcat(node->first_node("text")->value(), EncodeChoicecColorName(node->first_node("text")->first_attribute("color")->value()).c_str()));
    }
    super(event, node, eventName);
}


HOOK_STATIC(freetype, easy_printAutoNewlines, (int fontSize, float x, float y, int line_length, const std::string &text) -> Pointf)
{
    if (!CustomOptionsManager::GetInstance()->enableCustomChoiceColors.currentValue) return super(fontSize, x, y, line_length, text);

    std::regex re("^(.*)\\[\\[#C\\:(.*)\\]\\]$");
    std::smatch match;
    std::string new_text = text;
    GL_Color currentColor = CSurface::GL_GetColor();
    if (std::regex_match(new_text, match, re))
    {
        new_text = match[1];
        CSurface::GL_SetColor(DecodeChoiceColorName(match[2], currentColor));
    }

    return super(fontSize, x, y, line_length, new_text);
    CSurface::GL_SetColor(currentColor);
}

HOOK_STATIC(freetype, easy_measurePrintLines, (int fontSize, float x, float y, int line_length, const std::string &text) -> Pointf)
{
    if (!CustomOptionsManager::GetInstance()->enableCustomChoiceColors.currentValue) return super(fontSize, x, y, line_length, text);

    std::regex re("^(.*)\\[\\[#C\\:.*\\]\\]$");
    std::smatch match;
    std::string new_text = text;
    if (std::regex_match(new_text, match, re))
    {
        new_text = match[1];
    }
    return super(fontSize, x, y, line_length, new_text);
}