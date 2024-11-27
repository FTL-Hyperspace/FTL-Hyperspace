#pragma once
#include "Global.h"

extern GL_Color g_defaultTextButtonColors[4];
extern GL_Color g_autofireButtonColors[4];
extern GL_Color g_jumpButtonColors[8];

void ParseCustomColorsNode(rapidxml::xml_node<char>* node);

extern GL_Color COLOR_CHOICE_YELLOW;
extern GL_Color COLOR_CHOICE_GRAY;
extern GL_Color COLOR_CHOICE_CYAN;

struct ChoiceColor
{
    ChoiceColor()
    {
        normal = COLOR_WHITE;
        hover = COLOR_CHOICE_YELLOW;
        disabled = COLOR_CHOICE_GRAY;
        blue_option = COLOR_CHOICE_CYAN;
    }
    
    GL_Color normal;
    GL_Color hover;
    GL_Color disabled;
    GL_Color blue_option;
};

void ParseChoiceColorNode(rapidxml::xml_node<char>* node);

extern std::unordered_map<std::string, ChoiceColor*> ChoiceColorMap;
