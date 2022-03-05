#pragma once
#include "Global.h"
#include "CustomColors.h"
#include <memory>

struct EventButtonDefinition
{
    EventButtonDefinition()
    {
        inactiveColor = g_defaultTextButtonColors[0];
        activeColor = g_defaultTextButtonColors[1];
        selectedColor = g_defaultTextButtonColors[2];
        textColor = g_defaultTextButtonColors[3];
    }

    int idx = -1;
    std::string name = "";

    std::string event = "";

    TextString text;
    std::string image = "";
    int location = 0;

    GL_Color inactiveColor;
    GL_Color activeColor;
    GL_Color selectedColor;
    GL_Color textColor;

    int margin_border = 12;
    int margin_text = 3;

    bool jumpClear = false;
    bool once = false;
    bool hideInactive = false;
    bool noDanger = false;

    TextString tooltip;
    TextString inactiveTooltip;
};

struct EventButton
{
    EventButton()
    {
        button = std::unique_ptr<GenericButton>(new Button);
    }

    EventButton(EventButtonDefinition *_def) :
        def(_def)
    {
        if (def->text.data.empty())
        {
            OnInitImage();
        }
        else
        {
            OnInitText();
        }
    }

    void OnInitImage();
    void OnInitText();
    void OnLanguageChange();

    EventButtonDefinition *def = nullptr;

    std::unique_ptr<GenericButton> button = nullptr;
    Point offset = {0,0};
    Point dimension = {0,0};
};

class EventButtonManager
{
public:
    std::vector<EventButtonDefinition*> defs;
    std::unordered_map<std::string, EventButtonDefinition*> namedDefs;

    std::vector<EventButton> buttons;

    EventButtonDefinition* ParseEventButton(rapidxml::xml_node<char> *node);

    void CreateButton(EventButtonDefinition *def);
    void ClearButtons(const std::string &name);
    void Sort();

    void Load(int fh);
    void Save(int fh);

    EventButtonDefinition* NewDef()
    {
        EventButtonDefinition *ret = new EventButtonDefinition();
        ret->idx = defs.size();
        defs.push_back(ret);
        return ret;
    }

    static EventButtonManager* instance;
};
