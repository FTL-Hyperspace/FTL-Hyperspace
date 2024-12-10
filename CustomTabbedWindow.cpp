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

        if (tabNode->first_attribute("buttonPath");) {
            std::string buttonPath = tabNode->first_attribute("buttonPath");->value();

            newTab.button = new Button();
            newTab.button->OnInit(buttonPath, Point(xPos, -7));
            newTab.button->SetHitBox(Globals::Rect({xPos + 15, 0, 100, 38})) // might make it an xml parameter instead, there are slight shift in value in the decomp
            xPos += 100
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
        window->AddWindow(tab->name, tab->button, tab->window)
    }
}

HOOK_METHOD(CommandGui, constructor, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CommandGui::constructor -> Begin (CustomTabbedWindow.cpp)\n")
    super();
    CustomTabbedWindow::GetInstance()->populateWindow(this->shipScreens);
}

HOOK_METHOD(TabbedWindow, OnRender, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> TabbedWindow::OnRender -> Begin (CustomTabbedWindow.cpp)\n")
    auto context = Global::GetInstance()->getLuaContext();

    lua_pushinteger(context->GetLua(), currentTab);

    int idx = context->getLibScript()->call_on_render_event_pre_callbacks(RenderEvents::TABBED_WINDOW, 1);
    
    if (idx >= 0)
    {
        super();

        if (currentTab > 2)
            G_->GetResources()->RenderImage(CustomTabbedWindow::GetInstance()->GetTab(currentTab).background, 0, 0, 0, COLOR_WHITE, 1.f, false);
    }

    context->getLibScript()->call_on_render_event_post_callbacks(RenderEvents::TABBED_WINDOW, std::abs(idx), 1);

    lua_pop(context->GetLua(), 1);
}

HOOK_METHOD(TabbedWindow, Close, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> TabbedWindow::Close -> Begin (CustomTabbedWindow.cpp)\n")

    auto context = Global::GetInstance()->getLuaContext();
    lua_pushinteger(context->GetLua(), currentTab);
    context->getLibScript()->call_on_internal_event_callbacks(InternalEvents::TABBED_WINDOW_CONFIRM, 1);
    lua_pop(context->GetLua(), 1);

    super();
}

HOOK_METHOD(CommandGui, LButtonDown, (int mX, int mY, bool shiftHeld) -> void)
{
    LOG_HOOK("HOOK_METHOD -> TabbedWindow::LButtonDown -> Begin (CustomTabbedWindow.cpp)\n")

    if (shipScreens->doneButton->bActive && shipScreens->doneButton->bHover)
    {
        auto context = Global::GetInstance()->getLuaContext();
        lua_pushinteger(context->GetLua(), currentTab);
        context->getLibScript()->call_on_internal_event_callbacks(InternalEvents::TABBED_WINDOW_CONFIRM, 1);
        lua_pop(context->GetLua(), 1);
    }

    super(mX, mY, shiftHeld);
}

// handle TABBED_WINDOW_CONFIRM when switching tab as well
// still some missing sigs that I need to implement
// apart from that, it is theorically implemented, just need to test those when I can
