#pragma once
#include "Global.h"

class CustomTabbedWindow
{
public:
    struct Tab
    {
        FocusWindow* window;
        Button* button;
        GL_Texture* background;
        std::string name;
    };

    static CustomTabbedWindow* GetInstance()
    {
        return &instance;
    }

    Tab GetTab(int index)
    {
        return tabs[index - 2];
    }

    void populateWindow(TabbedWindow* window);
    void ParseWindowNode(rapidxml::xml_node<char>* node);

    int xPos = 282;

private:
    std::vector<Tab> tabs;

    static CustomTabbedWindow instance;
};
