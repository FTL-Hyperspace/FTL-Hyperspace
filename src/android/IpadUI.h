#pragma once
// Small helpers for FTL for iPad's UI, used by the HS_ANDROID code
#include "Global.h"

namespace IpadUI
{
    // The BUY and SELL buttons beside an item's info, as FTL for iPad's store and equipment
    // make them
    inline void InitPriceButton(TextButton &button, Point at, const char *label)
    {
        TextString text(label, false);
        button.OnInit(at, Point(77, 34), 3, &text, 63);
        button.SetAutoWidth(true, false, 4, 0);
        button.SetActive(false);
    }

    // ...drawn with the price in a box to their left
    inline void RenderPriceButton(TextButton &button, Point at, const std::string &price)
    {
        ResourceControl *resources = G_->GetResources();
        resources->RenderImage(resources->GetImageId("ipad/upgradeUI/get_box_scrap.png"), at.x - 79, at.y - 2, 0, COLOR_WHITE, 1.f, false);
        freetype::easy_printCenter(0, at.x - 25, at.y + 13, price);
        CSurface::GL_BlitPixelImageWide(resources->GetImageId("ipad/upgradeUI/get_box_button.png"), at.x + 3, at.y - 2, button.GetSize().x + 10, 0, 1.f, COLOR_WHITE, false);
        button.OnRender();
    }

    // ...and placed on the lower edge of the info box's main frame, where FTL for iPad's
    // InfoBox::OnRender draws it (detailed crew info 40 higher, its skills below). The game
    // works this out from its own, shorter info boxes.
    inline int PriceButtonY(InfoBox &info, int fallback)
    {
        WindowFrame *frame = info.primaryBox;
        if (!frame) return fallback;
        int y = info.location.y + info.primaryBoxOffset + frame->rect.y + frame->rect.h - 6;
        if (info.pCrewBlueprint && info.bDetailed) y -= 40;
        return y;
    }

    // Whether (x, y) is in the rectangle (its right and bottom edges are outside)
    inline bool Contains(const Globals::Rect &rect, int x, int y)
    {
        return x >= rect.x && x < rect.x + rect.w && y >= rect.y && y < rect.y + rect.h;
    }

    // Whether one of the HUD's windows (upgrades, crew, a store, the map...) is open over it
    inline bool WindowOpen()
    {
        for (FocusWindow *window : G_->GetCApp()->gui->focusWindows)
        {
            if (window->bOpen) return true;
        }
        return false;
    }

    // The page after a touch on a pair of page buttons; the pages wrap around
    inline int TurnPage(int page, int pages, Button *left, Button *right)
    {
        if (left->bActive && left->bActivated) page = page == 0 ? pages - 1 : page - 1;
        if (right->bActive && right->bActivated) page = page == pages - 1 ? 0 : page + 1;
        return page;
    }

    // Somewhere off the screen, for boxes and buttons that aren't on show
    const Point offscreen(-10000, -10000);

    // The screen's right edge in HUD coordinates: the HUD is 1024 by 768, centred on screens
    // wider than 4:3
    inline int ScreenRight()
    {
        CApp *app = G_->GetCApp();
        return app->screen_y > 0 ? 512 + app->screen_x * 384 / app->screen_y : 1024;
    }
}
