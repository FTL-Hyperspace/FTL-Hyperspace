#include "CustomStore.h"

void CustomStoreBox::OnRender()
{
    orig->button.OnRender();

    if (orig->bEquipmentBox)
    {
        if (orig->count > 0)
        {
            GL_Color textColor;

            if (orig->button.bActive && orig->button.bHover || orig->button.bSelected)
            {
                textColor = GL_Color(0.9608f, 0.9333f, 0.6392f, 1.f);
            }
            else
            {
                textColor = GL_Color(0.9216f, 0.9608f, 0.8980f, 1.f);
            }

            CSurface::GL_SetColor(textColor);
            CSurface::GL_PushMatrix();
            CSurface::GL_Translate(orig->button.position.x, orig->button.position.y);

            if (orig->pBlueprint)
            {
                std::string text = orig->pBlueprint->GetNameShort();
                if (orig->pBlueprint->GetType() == 2)
                {
                    text = ((CrewBlueprint*)orig->pBlueprint)->GetNameShort();
                }
                if (mysteryItem)
                {
                    text = "?";
                }

                freetype::easy_printCenter(6, 59.f, 58.f, text);
            }

            /* TODO: Sale price display
            if (showSale)
            {
                int saleWidth = freetype::easy_measureWidth(5, std::to_string(originalPrice));
                int priceWidth = freetype::easy_measureWidth(0, std::to_string(orig->desc.cost));

                float sX = 42.f + priceWidth + 4.f;

                auto redColor = GL_Color(235.f / 255.f, 114.f / 255.f, 106.f / 255.f, 1.f);


                CSurface::GL_SetColor(textColor);
                freetype::easy_print(5, sX, 86.f, std::to_string(originalPrice));

                CSurface::GL_SetColor(redColor);
                CSurface::GL_DrawLine(sX - 1, 94.f, sX + saleWidth + 1.f, 94.f, 1.f, redColor);

                CSurface::GL_SetColor(textColor);
            }
            */

            freetype::easy_print(0, 42.f, 86.f, std::to_string(orig->desc.cost));

            CSurface::GL_Translate(orig->pushIcon.x + 60.f, orig->pushIcon.y + 34.f);
            if (orig->pBlueprint)
            {
                if (mysteryItem)
                {
                    CSurface::GL_SetColor(COLOR_BUTTON_ON);
                    freetype::easy_printCenter(24, 0.f, -26.f, "?");
                }
                else
                {
                    orig->pBlueprint->RenderIcon(orig->fIconScale);
                }
            }

            CSurface::GL_PopMatrix();
        }

        return;
    }

    if (orig->count <= 0) return;

    if (orig->symbol && !mysteryItem)
    {
        CSurface::GL_PushMatrix();
        CSurface::GL_Translate(orig->button.position.x, orig->button.position.y);
        CSurface::GL_RenderPrimitive(orig->symbol);
        CSurface::GL_PopMatrix();
    }

    if (orig->button.bActive && orig->button.bHover || orig->button.bSelected)
    {
        CSurface::GL_SetColor(0.9608f, 0.9333f, 0.6392f, 1.f);
    }
    else
    {
        CSurface::GL_SetColor(0.9216f, 0.9608f, 0.8980f, 1.f);
    }

    if (orig->itemBox > 0)
    {
        freetype::easy_print(0, orig->button.position.x + 70.f, orig->button.position.y + 14.f, std::to_string(orig->count));
        freetype::easy_print(0, orig->button.position.x + 130.f, orig->button.position.y + 14.f, std::to_string(orig->desc.cost));
    }
    else
    {
        if (orig->desc.cost != -1)
        {
            std::string txt = orig->desc.title.GetText();

            if (mysteryItem) txt = "?";

            freetype::easy_print(14,orig-> button.position.x + 48.f, orig->button.position.y + 2.f, txt);
            freetype::easy_print(0, orig->button.position.x + 345.f, orig->button.position.y + 14.f, std::to_string(orig->desc.cost));
        }
    }
}

HOOK_METHOD(SystemStoreBox, CanHold, () -> bool)
{
    return super() && !shopper->HasSystem(type);
}
