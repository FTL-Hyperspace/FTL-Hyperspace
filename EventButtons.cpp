#include "EventButtons.h"
#include "CustomEvents.h"
#include "Resources.h"
#include <boost/lexical_cast.hpp>
#include <algorithm>

EventButtonManager* EventButtonManager::instance = new EventButtonManager();

EventButtonDefinition* EventButtonManager::ParseEventButton(rapidxml::xml_node<char> *node)
{
    EventButtonDefinition* def;

    if (node->first_attribute("load"))
    {
        def = namedDefs.at(node->first_attribute("load")->value());
        return def;
    }

    def = NewDef();
    if (node->first_attribute("name"))
    {
        def->name = node->first_attribute("name")->value();
        namedDefs[def->name] = def;
    }

    def->tooltip.data = "";
    def->inactiveTooltip.data = "";

    for (auto child = node->first_node(); child; child = child->next_sibling())
    {
        if (strcmp(child->name(), "event") == 0)
        {
            def->event = G_->GetEventsParser()->ProcessEvent(child, "__eventButton");
        }
        else if (strcmp(child->name(), "image") == 0)
        {
            def->image = child->value();
            if (child->first_attribute("border"))
            {
                def->margin_border = boost::lexical_cast<int>(child->first_attribute("border")->value());
            }
        }
        else if (strcmp(child->name(), "text") == 0)
        {
            def->text.data = child->value();
            if (child->first_attribute("id"))
            {
                def->text.data = child->first_attribute("id")->value();
                def->text.isLiteral = false;
            }
            if (child->first_attribute("border"))
            {
                def->margin_text = boost::lexical_cast<int>(child->first_attribute("border")->value());
            }
        }
        else if (strcmp(child->name(), "location") == 0)
        {
            def->location = boost::lexical_cast<int>(child->value());
        }
        else if (strcmp(child->name(), "tooltip") == 0)
        {
            def->tooltip.data = child->value();
            if (child->first_attribute("id"))
            {
                def->tooltip.data = child->first_attribute("id")->value();
                def->tooltip.isLiteral = false;
            }
        }
        else if (strcmp(child->name(), "inactiveTooltip") == 0)
        {
            def->inactiveTooltip.data = child->value();
            if (child->first_attribute("id"))
            {
                def->inactiveTooltip.data = child->first_attribute("id")->value();
                def->inactiveTooltip.isLiteral = false;
            }
        }
        else if (strcmp(child->name(), "color") == 0)
        {
            ParseColorNode(def->activeColor, child);
        }
        else if (strcmp(child->name(), "activeColor") == 0)
        {
            ParseColorNode(def->activeColor, child);
        }
        else if (strcmp(child->name(), "inactiveColor") == 0)
        {
            ParseColorNode(def->inactiveColor, child);
        }
        else if (strcmp(child->name(), "selectedColor") == 0)
        {
            ParseColorNode(def->selectedColor, child);
        }
        else if (strcmp(child->name(), "textColor") == 0)
        {
            ParseColorNode(def->textColor, child);
        }
        else if (strcmp(child->name(), "jumpClear") == 0)
        {
            def->jumpClear = EventsParser::ParseBoolean(child->value());
        }
        else if (strcmp(child->name(), "once") == 0)
        {
            def->once = EventsParser::ParseBoolean(child->value());
        }
        else if (strcmp(child->name(), "noDanger") == 0)
        {
            def->noDanger = EventsParser::ParseBoolean(child->value());
        }
        else if (strcmp(child->name(), "hideInactive") == 0)
        {
            def->hideInactive = EventsParser::ParseBoolean(child->value());
        }
    }

    return def;
}

void EventButtonManager::CreateButton(EventButtonDefinition *def)
{
    buttons.emplace_back(def);
}

void EventButtonManager::ClearButtons(const std::string &name)
{
    if (name.empty())
    {
        buttons.clear();
    }
    else
    {
        buttons.erase(std::remove_if(buttons.begin(), buttons.end(),
                                     [&name](EventButton& obj) { return obj.def->name == name; }),
                                     buttons.end());
    }
}

void EventButtonManager::Sort()
{
    std::stable_sort(buttons.begin(), buttons.end(),
    [](const EventButton &a, const EventButton &b) -> bool
    {
        return a.def->location < b.def->location;
    });
}

void EventButtonManager::Load(int fh)
{
    buttons.clear();
    int n = FileHelper::readInteger(fh);
    for (int i=0; i<n; ++i)
    {
        int idx = FileHelper::readInteger(fh);
        if (idx < defs.size()) buttons.emplace_back(defs.at(idx));
    }
}

void EventButtonManager::Save(int fh)
{
    FileHelper::writeInt(fh, buttons.size());
    for (EventButton& i : buttons)
    {
        FileHelper::writeInt(fh, i.def->idx);
    }
}

void EventButton::OnInitImage()
{
    button = std::unique_ptr<GenericButton>(new Button);
    ((Button*)button.get())->OnInit(def->image, -1024, -1024);
    dimension.x = button->hitbox.w;
    dimension.y = button->hitbox.h;
    button->hitbox.x += def->margin_border;
    button->hitbox.y += def->margin_border;
    button->hitbox.w -= 2*def->margin_border;
    button->hitbox.h -= 2*def->margin_border;
}

void EventButton::OnInitText()
{
    button = std::unique_ptr<GenericButton>(new TextButton);
    GL_Texture *tex = G_->GetResources()->GetImageId(def->image + ".png");
    ((TextButton*)button.get())->SetBaseImage(def->image + ".png", Point(-def->margin_border, -def->margin_border), tex->width_-2*def->margin_border);
    ((TextButton*)button.get())->OnInit(-1024, -1024, tex->width_-2*def->margin_border, tex->height_-2*def->margin_border, def->margin_text, &def->text, 62);
    ((TextButton*)button.get())->SetInactiveColor(def->inactiveColor);
    ((TextButton*)button.get())->SetActiveColor(def->activeColor);
    ((TextButton*)button.get())->SetSelectedColor(def->selectedColor);
    ((TextButton*)button.get())->SetTextColor(def->textColor);
    ((TextButton*)button.get())->SetAutoWidth(true, false, 3, 0);
    ((TextButton*)button.get())->UpdateAutoWidth();
    ((TextButton*)button.get())->ResetPrimitives();
    ((TextButton*)button.get())->InitPrimitives();
    offset.x = def->margin_border;
    offset.y = def->margin_border;
    dimension.x = button->hitbox.w + 2*def->margin_border;
    dimension.y = button->hitbox.h + 2*def->margin_border;
}

void EventButton::OnLanguageChange()
{
    if (!def->text.data.empty() && !def->text.isLiteral)
    {
        OnInitText();
    }
}

HOOK_METHOD(AchievementTracker, OnLanguageChange, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> AchievementTracker::OnLanguageChange -> Begin (EventButtons.cpp)\n")
    super();
    for (EventButton &button : EventButtonManager::instance->buttons)
    {
        button.OnLanguageChange();
    }
}

HOOK_METHOD(WorldManager, ClearLocation, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> WorldManager::ClearLocation -> Begin (EventButtons.cpp)\n")
    super();

    auto &buttons = EventButtonManager::instance->buttons;

    buttons.erase(std::remove_if(buttons.begin(), buttons.end(),
                                 [](EventButton& obj) { return obj.def->jumpClear; }),
                                 buttons.end());
}

HOOK_METHOD(ShipStatus, OnLoop, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipStatus::OnLoop -> Begin (EventButtons.cpp)\n")
    auto &customButtons = EventButtonManager::instance->buttons;

    if (!customButtons.empty())
    {
        CommandGui *gui = G_->GetWorld()->commandGui;

        for (EventButton &button : customButtons)
        {
            if (button.def->noDanger)
            {
                button.button->bActive = gui->upgradeButton.bActive;
            }
        }

        auto it = customButtons.begin();

        int x = gui->ftlButton.position.x + gui->ftlButton.hitbox.w + 16;

        for (; it != customButtons.end(); ++it)
        {
            if (it->def->location > 0) break;
            if (!it->button->bActive && it->def->hideInactive) continue;
            it->button->SetLocation(Point(x + it->offset.x, 80 + it->offset.y));
            x += it->dimension.x + 3;
        }

        x = gui->ftlButton.position.x + gui->ftlButton.hitbox.w + 16;

        for (; it != customButtons.end(); ++it)
        {
            if (it->def->location > 1) break;
            if (!it->button->bActive && it->def->hideInactive) continue;
            it->button->SetLocation(Point(x + it->offset.x, 22 + it->offset.y));
            x += it->dimension.x + 3;
        }

        gui->upgradeButton.SetLocation(Point(x, gui->upgradeButton.position.y));
        x += gui->upgradeButton.hitbox.w + 15;

        for (; it != customButtons.end(); ++it)
        {
            if (it->def->location > 2) break;
            if (!it->button->bActive && it->def->hideInactive) continue;
            it->button->SetLocation(Point(x + it->offset.x, 22 + it->offset.y));
            x += it->dimension.x + 3;
        }

        if (gui->storeButton.bActive)
        {
            x += 12;
            gui->storeButton.SetLocation(Point(x, gui->storeButton.position.y));
            x += gui->storeButton.hitbox.w + 3;
        }

        for (; it != customButtons.end(); ++it)
        {
            if (it->def->location > 3) break;
            if (!it->button->bActive && it->def->hideInactive) continue;
            it->button->SetLocation(Point(x + it->offset.x, 22 + it->offset.y));
            x += it->dimension.x + 3;
        }

        if (gui->optionsButton.bActive)
        {
            gui->optionsButton.SetLocation(Point(x, gui->optionsButton.position.y));
            x += gui->optionsButton.hitbox.w + 3;
        }

        for (; it != customButtons.end(); ++it)
        {
            if (!it->button->bActive && it->def->hideInactive) continue;
            it->button->SetLocation(Point(x + it->offset.x, 22 + it->offset.y));
            x += it->dimension.x + 3;
        }
    }

    super();
}

HOOK_METHOD(FTLButton, OnRender, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> FTLButton::OnRender -> Begin (EventButtons.cpp)\n")
    super();

    auto &customButtons = EventButtonManager::instance->buttons;
    for (EventButton &button : customButtons)
    {
        if (!button.button->bActive && button.def->hideInactive) continue;
        button.button->OnRender();
    }
}

HOOK_METHOD(FTLButton, MouseMove, (int mX, int mY, bool silent) -> void)
{
    LOG_HOOK("HOOK_METHOD -> FTLButton::MouseMove -> Begin (EventButtons.cpp)\n")
    super(mX, mY, silent);

    for (EventButton &button : EventButtonManager::instance->buttons)
    {
        button.button->MouseMove(mX, mY, silent);
        if (button.button->bHover)
        {
            if (button.button->bActive)
            {
                G_->GetMouseControl()->SetTooltip(button.def->tooltip.GetText());
            }
            else
            {
                G_->GetMouseControl()->SetTooltip(button.def->inactiveTooltip.GetText());
            }
        }
    }
}

HOOK_METHOD(CommandGui, LButtonDown, (int mX, int mY, bool shiftHeld) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CommandGui::LButtonDown -> Begin (EventButtons.cpp)\n")
    super(mX, mY, shiftHeld);

    for (auto it = EventButtonManager::instance->buttons.begin(); it != EventButtonManager::instance->buttons.end(); )
    {
        if (it->button->bActive && it->button->bHover)
        {
            // todo: seeded
            eventQueue.push_back({it->def->event, -1});
            if (it->def->once)
            {
                it = EventButtonManager::instance->buttons.erase(it);
                continue;
            }
        }
        it++;
    }
}
