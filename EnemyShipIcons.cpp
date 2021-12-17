#include "EnemyShipIcons.h"
#include "CustomShipSelect.h"
#include <boost/lexical_cast.hpp>

ShipIconManager* ShipIconManager::instance = new ShipIconManager();

void ShipIconManager::ParseShipIconNode(rapidxml::xml_node<char>* node)
{
    for (auto child = node->first_node(); child; child = child->next_sibling())
    {
        std::string name = child->name();

        if (name == "normalPos")
        {
            normalBoxPos.x = boost::lexical_cast<float>(child->first_attribute("x")->value());
            normalBoxPos.y = boost::lexical_cast<float>(child->first_attribute("y")->value());
        }
        if (name == "bossPos")
        {
            bossBoxPos.x = boost::lexical_cast<float>(child->first_attribute("x")->value());
            bossBoxPos.y = boost::lexical_cast<float>(child->first_attribute("y")->value());
        }

        if (name == "shipIcon")
        {
            ShipIconDefinition def = ShipIconDefinition();

            for (auto iconChild = child->first_node(); iconChild; iconChild = iconChild->next_sibling())
            {
                std::string iconName = iconChild->name();
                std::string iconValue = iconChild->value();

                if (iconName == "name")
                {
                    def.name = iconValue;
                }
                if (iconName == "tooltip")
                {
                    def.tooltip = iconValue;
                }
                shipIcons[def.name] = def;
            }
        }
    }
}

void ShipIcon::OnInit(const std::string& texture, const std::string& tip, int idx)
{
    box = G_->GetResources()->GetImageId("combatUI/box_hostiles_icon.png");
    icon = G_->GetResources()->GetImageId("combatUI/icons/" + texture + ".png");

    tooltip = tip;
    index = idx;
}

void ShipIcon::OnRender(GL_Color color, bool boss)
{
    auto pos = boss ? ShipIconManager::instance->bossBoxPos : ShipIconManager::instance->normalBoxPos;

    G_->GetResources()->RenderImage(box, pos.x, pos.y - ((box->height_) * (index + 1)), 0, color, 1.f, false);
    G_->GetResources()->RenderImage(icon, pos.x + box->width_ / 2 - icon->width_ / 2 + 1, pos.y - ((box->height_) * (index + 1)) + box->height_ / 2 - icon->height_ / 2, 0, COLOR_WHITE, 1.f, false);
}

void ShipIcon::MouseMove(int x, int y, bool boss)
{
    auto pos = boss ? ShipIconManager::instance->bossBoxPos : ShipIconManager::instance->normalBoxPos;

    if (x > pos.x && x < pos.x + box->width_)
    {
        if (y > pos.y - ((box->height_) * (index + 1)) &&
            y < pos.y - ((box->height_) * (index)))
        {
            G_->GetMouseControl()->SetTooltip(tooltip);
            G_->GetMouseControl()->InstantTooltip();
        }
    }
}

static GL_Color renderColor;

HOOK_METHOD(CombatControl, DrawHostileBox, (GL_Color color, int stencilBit) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CombatControl::DrawHostileBox -> Begin (EnemyShipIcons.cpp)\n")
    super(color, stencilBit);

    renderColor = color;
}

HOOK_METHOD(CombatControl, RenderTarget, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CombatControl::RenderTarget -> Begin (EnemyShipIcons.cpp)\n")
    super();

    auto iconList = SM_EX(currentTarget->shipManager)->icons;

    for (auto i : iconList)
    {
        i->OnRender(renderColor, boss_visual);
    }
}

HOOK_METHOD(CommandGui, MouseMove, (int x, int y) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CommandGui::MouseMove -> Begin (EnemyShipIcons.cpp)\n")
    super(x, y);

    if (combatControl.currentTarget)
    {
        auto iconList = SM_EX(combatControl.currentTarget->shipManager)->icons;

        for (auto i : iconList)
        {
            i->MouseMove(x, y, combatControl.boss_visual);
        }
    }
}
