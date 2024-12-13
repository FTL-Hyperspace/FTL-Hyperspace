#include "CustomTabbedWindow.h"

CustomTabbedWindow CustomTabbedWindow::instance = CustomTabbedWindow();

void CustomTabbedWindow::ParseWindowNode(rapidxml::xml_node<char>* node)
{
    for (rapidxml::xml_node<char>* tabNode = node->first_node("tab"); tabNode; tabNode = tabNode->next_sibling("tab")) 
    {
        Tab newTab;
        
        rapidxml::xml_attribute<char>* nameAttr = tabNode->first_attribute("name");
        if(tabNode->first_attribute("name")){
            newTab.name = tabNode->first_attribute("name")->value();
        }
        if (tabNode->first_attribute("buttonPath")) {
            std::string buttonPath = tabNode->first_attribute("buttonPath")->value();
            newTab.button = new Button();
            newTab.button->OnInit(buttonPath, Point(xPos, -7));
            Globals::Rect rect = Globals::Rect();
            rect.x = xPos + 15;
            rect.y = 0;
            rect.w = 100;
            rect.h = 38;
            newTab.button->hitbox = rect; // might make it an xml parameter instead, there are slight shift in value in the decomp
            xPos += 100;
        }
        if (tabNode->first_attribute("windowPath")) {
            std::string windowPath = tabNode->first_attribute("windowPath")->value();
            newTab.background = G_->GetResources()->GetImageId(windowPath + ".png");
        }
        newTab.window = new FocusWindow();
        tabs.push_back(newTab);
    }
}

void CustomTabbedWindow::populateWindow(TabbedWindow* window)
{
    for (auto tab : tabs)
    {
        bool skip = false;
        for (auto name : window->names)
        {
            if (tab.name == name)
            {
                skip = true;
            }
        }
        if (skip)
            continue;
        window->AddWindow(tab.name, tab.button, tab.window);
    }
}

HOOK_METHOD(CommandGui, OnLoop, () -> void) // should be linksip when chrono finally find the right sig
{
    LOG_HOOK("HOOK_METHOD -> CommandGui::LinkShip -> Begin (CustomTabbedWindow.cpp)\n")

    super();
    CustomTabbedWindow::GetInstance()->populateWindow(&(this->shipScreens));
}

HOOK_METHOD(TabbedWindow, OnRender, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> TabbedWindow::OnRender -> Begin (CustomTabbedWindow.cpp)\n")

    auto context = Global::GetInstance()->getLuaContext();

    lua_pushinteger(context->GetLua(), currentTab);

    CSurface::GL_PushMatrix();
    CSurface::GL_Translate(position.x, 78);

    int idx = context->getLibScript()->call_on_render_event_pre_callbacks(RenderEvents::TABBED_WINDOW, 1);
    
    if (idx >= 0)
    {
        CSurface::GL_Translate(-position.x, -78);
        super();
        CSurface::GL_Translate(position.x, 78);
        if (currentTab > 2)
            G_->GetResources()->RenderImage(CustomTabbedWindow::GetInstance()->GetTab(currentTab).background, 0, 0, 0, COLOR_WHITE, 1.f, false);
    }

    context->getLibScript()->call_on_render_event_post_callbacks(RenderEvents::TABBED_WINDOW, std::abs(idx), 1);

    CSurface::GL_PopMatrix();

    lua_pop(context->GetLua(), 1);
}

HOOK_METHOD(CommandGui, LButtonDown, (int mX, int mY, bool shiftHeld) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CommandGui::LButtonDown -> Begin (CustomTabbedWindow.cpp)\n")

    if (shipScreens.doneButton.bActive && shipScreens.doneButton.bHover)
    {
        auto context = Global::GetInstance()->getLuaContext();
        lua_pushinteger(context->GetLua(), shipScreens.currentTab);
        context->getLibScript()->call_on_internal_event_callbacks(InternalEvents::TABBED_WINDOW_CONFIRM, 1);
        lua_pop(context->GetLua(), 1);
    }

    super(mX, mY, shiftHeld);
}

HOOK_METHOD(TabbedWindow, SetTab, (unsigned int tab) -> void)
{
    LOG_HOOK("HOOK_METHOD -> TabbedWindow::SetTab -> Begin (CustomTabbedWindow.cpp)\n")

    auto context = Global::GetInstance()->getLuaContext();
    lua_pushinteger(context->GetLua(), currentTab);
    context->getLibScript()->call_on_internal_event_callbacks(InternalEvents::TABBED_WINDOW_CONFIRM, 1);
    lua_pop(context->GetLua(), 1);

    super(tab);
}
