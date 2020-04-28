#include "Global.h"
#include "freetype.h"
#include "CustomEvents.h"

GL_Texture* boxCustom[3];

HOOK_METHOD(StarMap, constructor, () -> void)
{
    super();
    boxCustom[0] = G_->GetResources()->GetImageId("map/map_box_custom_1.png");
    boxCustom[1] = G_->GetResources()->GetImageId("map/map_box_custom_2.png");
    boxCustom[2] = G_->GetResources()->GetImageId("map/map_box_custom_3.png");
}

HOOK_METHOD(StarMap, RenderLabels, () -> void)
{
    super();

    CSurface::GL_PushMatrix();
    CSurface::GL_Translate(position.x, position.y, 0.f);
    CSurface::GL_Translate(translation.x, translation.y, 0.f);



    if (!outOfFuel)
    {
        for (auto i : locations)
        {
            BeaconType* beaconType = CustomEventsParser::GetInstance()->GetBeaconType(i->event->eventName);

            if (!i->beacon && beaconType && (bMapRevealed || beaconType->global || i->known))
            {
                std::string text = std::string();
                TextLibrary::GetText(text, G_->GetTextLibrary(), beaconType->id, G_->GetTextLibrary()->currentLanguage);

                Pointf printLines = freetype_hack::easy_measurePrintLines(51, 0, 0, 999, text);
                float x = i->loc.x - 1.f;
                float y = i->loc.y - 33.f;

                float x2 = 0.f;
                float y2 = 0.f;

                GL_Color color = beaconType->color;
                color.a = color.a * (i->flashTracker.GetAlphaLevel(false) * 0.5 + 0.5);

                GL_Texture** box;

                if (color.r == 255.f && color.g == 255.f && color.b == 255.f)
                {
                    box = boxWhite;
                }
                else
                {
                    box = boxCustom;
                }

                if (box[0])
                {
                    x2 = box[0]->width_;
                    y2 = box[0]->height_;
                }


                CSurface::GL_BlitPixelImage(box[0], x, y, x2, y2, 0.f, color, false);

                CSurface::GL_BlitPixelImage(box[1], x + box[0]->width_, y, printLines.x - 8, box[1]->height_, 0.f, color, false);

                CSurface::GL_BlitPixelImage(box[2], x + box[0]->width_ + printLines.x - 8, y, box[2]->width_, box[2]->height_, 0.f, color, false);

                CSurface::GL_SetColor(color);
                freetype::easy_print(51, i->loc.x + 14.f, i->loc.y - 25.f, text);

            }
        }
    }

    CSurface::GL_PopMatrix();
}



HOOK_METHOD(StarMap, OnRender, () -> void)
{
    return super();
    if (!bChoosingNewSector)
    {
        Pointf locPos = currentLoc->loc;
        CSurface::GL_PushMatrix();
        CSurface::GL_Translate(position.x, position.y, 0.f);
        if (arrivedAtBase)
        {
            std::string txt;
            TextLibrary::GetText(txt, G_->GetTextLibrary(), "boss_jumps", G_->GetTextLibrary()->currentLanguage);
            Pointf pos = Pointf();

            float unk3;
            for (unk3 = 200; ; unk3 += 10)
            {
                pos = freetype_hack::easy_measurePrintLines(52, 0, 0, unk3 + 12, txt);
                if (pos.y <= 50.f)
                    break;
            }

            float unk1 = 1.f;
            float unk2 = 26.f;

            if (boss_jumps_box)
            {
                unk1 = boss_jumps_box->width_;
                unk2 = 26.f / unk1;
            }

            CSurface::GL_BlitImagePartial(boss_jumps_box, 629.f - unk3, -82.f, 26.f, 78.f, 0.f, unk2, 0.f, 1.f, 1.f, COLOR_WHITE, false);
            CSurface::GL_BlitImagePartial(boss_jumps_box, 655.f - unk3, -82.f, unk3, 78.f, unk2, 27.f / unk1, 0.f, 1.f, 1.f, COLOR_WHITE, false);
            CSurface::GL_BlitImagePartial(boss_jumps_box, 655.f, -82.f, unk1 - 27.f, 78.f, 27.f / unk1, 1.f, 0.f, 1.f, 1.f, COLOR_WHITE, false);
            freetype::easy_printNewlinesCentered(52, 655.f - unk3 + unk3 / 2, -65.f, unk3 + 12, "boss_jumps");

            bool unk4 = (4 - arrivedAtBase) == 1;
            freetype::easy_print(24, unk4 * 4 + 696.f, -68.f, 0);
        }

        mapBorder.DrawMask(8);
        CSurface::GL_SetStencilMode(GL_StencilMode::STENCIL_USE, 8, 8);
        GL_Color tint(0.75f, 0.75f, 0.75f, 1.f);
        CSurface::GL_SetColorTint(tint);
        CSurface::GL_RenderPrimitive(mapsBottom[worldLevel % 3]);
        CSurface::GL_RemoveColorTint();


        CSurface::GL_PushMatrix();
        CSurface::GL_Translate(translation.x, translation.y, 0.f);
        for (auto const &x: currentNebulas)
        {
            CSurface::GL_RenderPrimitive(x.primitive);
        }


        Location* hover = hoverLoc;
        Location* current = currentLoc;
        if (hover)
        {
            if (hover != current)
            {
                if (*G_->showBeaconPath)
                {
                    for (auto const &x: hover->connectedLocations)
                    {
                        if (x != current)
                        {
                            GL_Color color(255.f, 255.f, 0.f, 1.f);
                            DrawConnection(hover->loc, x->loc, &color);
                        }
                    }
                }
            }
        }

        for (auto const &x: currentLoc->connectedLocations)
        {
            GL_Color color(120.f, 255.f, 120.f, 1.f);
            DrawConnection(x->loc, currentLoc->loc, &color);
        }

        if (this->bossLevel)
        {
            // do stuff
        }

        for (auto const &i: this->locations)
        {
            CSurface::GL_PushMatrix();
            CSurface::GL_Translate(i->loc.x, i->loc.y, 0.f);

            if (i->fleetChanging)
            {
                CSurface::GL_PushMatrix();
                CSurface::GL_Translate(-15.f, -14.f, 0.f);
                CSurface::GL_Scale(0.75f, 0.75f, 1.f);
                CSurface::GL_RenderPrimitiveWithAlpha(this->dangerFlash, i->flashTracker.GetAlphaLevel(false));
                CSurface::GL_PopMatrix();
            }

            if (i->nebula)
            {
                CSurface::GL_RenderPrimitive(this->nebula_circle);
            }

            bool advScanners = shipManager->HasAugmentation("ADV_SCANNERS");

            GL_Primitive *locPrimitive = 0;
            GL_Primitive *shadowPrimitive = 0;


            if (!i->event)
            {
                shadowPrimitive = shadow;
            }

            if (i->visited)
            {
                if (i->event && (i->dangerZone || i->event->ship.present && i->event->ship.hostile))
                {
                    locPrimitive = danger;
                    shadowPrimitive = warning_shadow;
                }
                else
                {
                    locPrimitive = explored;
                }
            }
            else
            {
                if (bMapRevealed || (i->known && advScanners))
                {
                    if (i->event && i->event->ship.present)
                    {
                        locPrimitive = yellow_warning;
                        shadowPrimitive = warning_shadow;
                    }
                    if (i->dangerZone)
                    {
                        locPrimitive = warning;
                        shadowPrimitive = warning_shadow;
                    }
                }
                else
                {
                    locPrimitive = unexplored;
                }
            }

            if (locPrimitive == 0)
            {
                locPrimitive = unexplored;
            }

            CSurface::GL_RenderPrimitive(shadowPrimitive);

            if (potentialLoc && (potentialLoc->loc.x == i->loc.x && potentialLoc->loc.y == i->loc.y))
            {
                for (int i = 0; i < 3; i++)
                {
                    CSurface::GL_RenderPrimitive(locPrimitive);
                }
            }
            else
            {
                CSurface::GL_RenderPrimitive(locPrimitive);
            }


            CSurface::GL_PopMatrix();
        }


        if (dangerZone.x <= 59 && GetNextDangerMove())
        {
            float dangerOffset = dangerZone.x;
            if (waiting.running)
            {
                dangerOffset = dangerWaitStart;
            }

            CSurface::GL_PushMatrix();

            float newX = std::floor((GetNextDangerMove() + dangerOffset) + 767.f);
            float newX2 = translation.x + newX;


            if (newX2 > 181.f)
            {
                GL_Color color(0.96f, 0.51f, 0.49f, 0.08f);
                CSurface::GL_DrawRect(0.f, translation.y, newX2 - 181.f, 534.f, color);
            }


            CSurface::GL_Translate(newX, dangerZone.y, 0.f);
            CSurface::GL_RenderPrimitive(dangerZoneAdvance);


            CSurface::GL_PopMatrix();
        }

        CSurface::GL_PushMatrix();
        CSurface::GL_Translate(dangerZone.x + 767.f, dangerZone.y, 0.f);
        CSurface::GL_RenderPrimitive(dangerZoneEdge);
        CSurface::GL_PopMatrix();

        CSurface::GL_SetStencilMode(GL_StencilMode::STENCIL_IGNORE, 0, 0);
        CSurface::GL_PopMatrix();


        CSurface::GL_PopMatrix();


    }
}
