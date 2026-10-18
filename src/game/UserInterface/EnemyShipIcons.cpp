#include "EnemyShipIcons.h"
#include "CustomShipSelect.h"
#include "CustomAugments.h"
#include <boost/lexical_cast.hpp>
#ifdef HS_ANDROID
#include "android/IpadUI.h"
#endif

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
                    if (iconChild->first_attribute("id"))
                    {
                        def.tooltip.data = iconChild->first_attribute("id")->value();
                        def.tooltip.isLiteral = false;
                    }
                    else
                    {
                        def.tooltip.data = iconValue;
                        def.tooltip.isLiteral = true;
                    }
                }
                shipIcons[def.name] = def;
            }
        }
    }
}

void ShipIcon::OnInit(const std::string& texture, const TextString& tip, int idx)
{
    box = G_->GetResources()->GetImageId("combatUI/box_hostiles_icon.png");
    icon = G_->GetResources()->GetImageId("combatUI/icons/" + texture + ".png");

    tooltip = tip;
    index = idx;
}

#ifdef HS_ANDROID
// FTL for iPad's hostile box is narrower than the PC one and elsewhere, so the icons go up its
// right edge from the bottom (RenderTarget below works out where)
static Point g_iconsCorner;
#endif

// The bottom left corner of the column of icons
static Point IconsCorner(bool boss)
{
#ifdef HS_ANDROID
    return g_iconsCorner;
#else
    return boss ? ShipIconManager::instance->bossBoxPos : ShipIconManager::instance->normalBoxPos;
#endif
}

void ShipIcon::OnRender(GL_Color color, bool boss, int idx)
{
    auto pos = IconsCorner(boss);

    G_->GetResources()->RenderImage(box, pos.x, pos.y - ((box->height_) * (index + idx + 1)), 0, color, 1.f, false);
    G_->GetResources()->RenderImage(icon, pos.x + box->width_ / 2 - icon->width_ / 2 + 1, pos.y - ((box->height_) * (index + idx + + 1)) + box->height_ / 2 - icon->height_ / 2, 0, COLOR_WHITE, 1.f, false);
}

void ShipIcon::MouseMove(int x, int y, bool boss, int idx)
{
    auto pos = IconsCorner(boss);

    if (x > pos.x && x < pos.x + box->width_)
    {
        if (y > pos.y - ((box->height_) * (index + idx + 1)) &&
            y < pos.y - ((box->height_) * (index + idx)))
        {
            G_->GetMouseControl()->SetTooltip(tooltip.GetText());
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

#ifdef HS_ANDROID
static int g_iconTouch = -1;   // the finger on an icon, if any
static Point g_iconTouchPos;

// The icon and its place in the column (idx as for OnRender) at a point, if any
static ShipIcon *IconAt(CombatControl *combat, int x, int y, int &idxOut)
{
    if (!combat->currentTarget) return nullptr;
    auto iconList = SM_EX(combat->currentTarget->shipManager)->icons;
    auto augIcons = CustomAugmentManager::GetInstance()->GetAugIconList(combat->currentTarget->iShipId);
    for (int list = 0; list < 2; ++list)
    {
        int idx = list == 0 ? 0 : (int)iconList.size();
        for (ShipIcon *i : list == 0 ? iconList : augIcons)
        {
            if (!i->box) continue;
            int top = g_iconsCorner.y - i->box->height_ * (i->index + idx + 1);
            if (IpadUI::Contains(Globals::Rect(g_iconsCorner.x, top, i->box->width_, i->box->height_), x, y))
            {
                idxOut = idx;
                return i;
            }
        }
    }
    return nullptr;
}
#endif

HOOK_METHOD(CombatControl, RenderTarget, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CombatControl::RenderTarget -> Begin (EnemyShipIcons.cpp)\n")
    super();

#ifdef HS_ANDROID
    // Outside the box where the screen reaches past it (the HUD is 1024 wide, centred), as on
    // PC; otherwise just inside it
    if (hostileBoxFrame)
    {
        const Globals::Rect &box = hostileBoxFrame->rect;
        int iconWidth = 34; // an icon's box
        int x = box.x + box.w + 3;
        if (x + iconWidth > IpadUI::ScreenRight()) x = box.x + box.w - iconWidth - 8;
        g_iconsCorner = Point(x, box.y + box.h - 3);
    }
#endif

    auto iconList = SM_EX(currentTarget->shipManager)->icons;

    for (auto i : iconList)
    {
        i->OnRender(renderColor, boss_visual);
    }

    for (auto i : CustomAugmentManager::GetInstance()->GetAugIconList(currentTarget->iShipId))
    {
        i->OnRender(renderColor, boss_visual, iconList.size());
    }

#ifdef HS_ANDROID
    // The tooltip of the icon under a finger, to its left
    int idx;
    ShipIcon *touched = g_iconTouch != -1 ? IconAt(this, g_iconTouchPos.x, g_iconTouchPos.y, idx) : nullptr;
    if (touched)
    {
        auto mouse = G_->GetMouseControl();
        mouse->SetTooltip(touched->tooltip.GetText());
        // to the left of the icons, about a tooltip's width away, as the PC puts it by the mouse
        mouse->QueueStaticTooltip(Point(g_iconsCorner.x - 290, g_iconsCorner.y - touched->box->height_ * 2));
        mouse->InstantTooltip();
    }
#endif
}

#ifdef HS_ANDROID
// FTL for iPad has no mouse to hover the icons with: a finger on one shows its tooltip, and
// doesn't reach the game (it may be over the enemy ship's rooms)
HOOK_METHOD(CommandGui, OnTouch, (TouchAction action, int id, int x, int y, int initialX, int initialY) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CommandGui::OnTouch -> Begin (EnemyShipIcons.cpp)\n")
    if (id == g_iconTouch)
    {
        g_iconTouchPos = Point(x, y);
        if (action != TOUCH_DOWN && action != TOUCH_MOVE) g_iconTouch = -1;
        return;
    }

    bool windowOpen = IpadUI::WindowOpen();
    int idx;
    if (action == TOUCH_DOWN && g_iconTouch == -1 && !windowOpen && IconAt(&combatControl, x, y, idx))
    {
        g_iconTouch = id;
        g_iconTouchPos = Point(x, y);
        return;
    }
    super(action, id, x, y, initialX, initialY);
}
#endif

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

        for (auto i : CustomAugmentManager::GetInstance()->GetAugIconList(combatControl.currentTarget->iShipId))
        {
            i->MouseMove(x, y, combatControl.boss_visual, iconList.size());
        }
    }
}
