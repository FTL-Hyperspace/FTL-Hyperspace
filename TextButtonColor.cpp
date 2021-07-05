#include "TextButtonColor.h"
#include "Resources.h"

GL_Color g_defaultTextButtonColors[4] = { GL_Color(164.f / 255.f, 171.f / 255.f, 160.f / 255.f, 1.f),
                                        GL_Color(235.f / 255.f, 245 / 255.f, 229.f / 255.f, 1.f),
                                        GL_Color(235.f / 255.f, 230.f / 255.f, 94.f / 255.f, 1.f),
                                        GL_Color(25.f / 255.f, 49.f / 255.f, 51.f / 255.f, 1.f) };

void ParseTextButtonColorsNode(rapidxml::xml_node<char>* node)
{
    for (auto child = node->first_node(); child; child = child->next_sibling())
    {
        std::string name = child->name();

        int arrayIndex = 0;

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
        else
        {
            arrayIndex = -1;
        }

        if (arrayIndex != -1)
        {
            ParseColorNode(g_defaultTextButtonColors[arrayIndex], child);
        }
    }
}

void SetTextButtonDefaultColors(TextButton *btn)
{
    if (!btn->colorsSet)
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
    SetTextButtonDefaultColors(this);
    super();
}

HOOK_METHOD(TextButton, SetInactiveColor, (GL_Color color) -> void)
{
    SetTextButtonDefaultColors(this);
    super(color);
}

HOOK_METHOD(TextButton, SetActiveColor, (GL_Color color) -> void)
{
    SetTextButtonDefaultColors(this);
    super(color);
}

HOOK_METHOD(TextButton, SetSelectedColor, (GL_Color color) -> void)
{
    SetTextButtonDefaultColors(this);
    super(color);
}

HOOK_METHOD(TextButton, SetTextColor, (GL_Color color) -> void)
{
    SetTextButtonDefaultColors(this);
    super(color);
}
