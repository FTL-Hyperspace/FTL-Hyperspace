#pragma once
#include "Global.h"

class CustomTabbedWindow
{
public:
    struct Tab
    {
        FocusWindow* window;
        Point butPos;

        GL_Texture* background;
        std::string name;
        bool hasUndo = false;
    };

    static CustomTabbedWindow* GetInstance()
    {
        return &instance;
    }

    Tab GetTab(int index)
    {
        return tabs[index - 3];
    }

    void PopulateWindow(TabbedWindow* window);
    void ParseWindowNode(rapidxml::xml_node<char>* node);
    void InitialiseButton(CustomTabbedWindow::Tab &tab, Button *newButton);

    TextButton* undoButton = nullptr;
    int xPos = 240;
    const int hitboxWidth = 77; // 97

    int enabled = false;
private:
    std::vector<Tab> tabs;

    static CustomTabbedWindow instance;
};
