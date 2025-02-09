#include "Global.h"
#include "CustomEvents.h"
#include "CustomMap.h"
#include "CustomOptions.h"
#include <unordered_set>

HOOK_METHOD(StarMap, OnRender, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> StarMap::OnRender -> Begin (CustomMap.cpp)\n")
    return super();
    if (!bChoosingNewSector)
    {
        CSurface::GL_PushMatrix();
        CSurface::GL_Translate(position.x, position.y, 0.f);
        if (arrivedAtBase)
        {
            std::string txt = G_->GetTextLibrary()->GetText("boss_jumps");
            Pointf pos = Pointf();

            float unk3;
            for (unk3 = 200; ; unk3 += 10)
            {
                pos = freetype::easy_measurePrintLines(52, 0, 0, unk3 + 12, txt);
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

static bool g_firstTimeConnection = false;
static std::vector<std::unordered_set<Location*>> g_locConnections;
static bool g_useNonColorVertices = false;


HOOK_STATIC(CSurface, GL_BlitMultiColorImage, (GL_Texture *tex, const std::vector<GL_ColorTexVertex>& texVertices, bool antialias) -> void)
{
    LOG_HOOK("HOOK_STATIC -> CSurface::GL_BlitMultiColorImage -> Begin (CustomMap.cpp)\n")
    if (g_useNonColorVertices)
    {
        auto newVec = std::vector<GL_TexVertex>();

        for (auto i : texVertices)
        {
            GL_TexVertex newVertex;
            newVertex.x = i.x;
            newVertex.y = i.y;
            newVertex.u = i.u;
            newVertex.v = i.v;

            newVec.push_back(newVertex);
        }

        CSurface::GL_BlitMultiImage(tex, newVec, antialias);

        return;
    }

    super(tex, texVertices, antialias);
}

HOOK_METHOD(StarMap, DrawConnection, (const Pointf& pos1, const Pointf& pos2, const GL_Color& color) -> void)
{
    LOG_HOOK("HOOK_METHOD -> StarMap::DrawConnection -> Begin (CustomMap.cpp)\n")
    if (g_firstTimeConnection && CustomOptionsManager::GetInstance()->showAllConnections.currentValue == true)
    {
        for (auto i : g_locConnections)
        {
            std::vector<Location*> vec = std::vector<Location*>(i.begin(), i.end());

            if (vec[0] != hoverLoc && vec[1] != hoverLoc && vec[0] != currentLoc && vec[1] != currentLoc)
            {
                g_useNonColorVertices = true;
                super(vec[0]->loc, vec[1]->loc, GL_Color(255.f, 255.f, 255.f, 1.f));
                g_useNonColorVertices = false;
            }
        }

        g_firstTimeConnection = false;
    }

    super(pos1, pos2, color);
}

HOOK_METHOD(StarMap, OnRender, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> StarMap::OnRender -> Begin (CustomMap.cpp)\n")
    g_firstTimeConnection = true;
    super();
    g_firstTimeConnection = false;
}

HOOK_METHOD(StarMap, Open, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> StarMap::Open -> Begin (CustomMap.cpp)\n")
    super();

    g_locConnections.clear();

    for (auto i : locations)
    {
        for (auto x : i->connectedLocations)
        {
            auto newSet = std::unordered_set<Location*>({ i, x });
            if (std::find(g_locConnections.begin(), g_locConnections.end(), newSet) == g_locConnections.end())
            {
                g_locConnections.push_back(newSet);
            }
        }
    }
}

HOOK_METHOD(StarMap, MouseMove, (int x, int y) -> void)
{
    LOG_HOOK("HOOK_METHOD -> StarMap::MouseMove -> Begin (CustomMap.cpp)\n")

    super(x, y);

    if (bChoosingNewSector || outOfFuel)
    {
        potentialLoc = (Location *)NULL; 
        return;
    }
    
    bool canJump = false;
    for (auto i : locations)
    {   
        if (i->loc.x + 35.f + position.x  <= x &&
        i->loc.x + 55.f + position.x >= x && 
        i->loc.y + 33.f + position.y <= y && 
        i->loc.y + 53.f + position.y >= y)
        {
            hoverLoc = i;

            ShipManager *ship = G_->GetShipManager(0);
            if (hoverLoc->visited != 0 && ship->HasAugmentation("FTL_JUMPER")) canJump = hoverLoc != currentLoc;

            for (auto x : currentLoc->connectedLocations)
            {
                if (x == hoverLoc)
                {
                    canJump = true;
                    break;
                }
            }

            if (canJump) potentialLoc = hoverLoc;
            break;
        }
    }
}
 
bool forceWait = false;
HOOK_METHOD_PRIORITY(StarMap, OnLoop, 9999, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> StarMap::OnLoop -> Begin (CustomMap.cpp)\n")
    if (!bOpen) return;
    bossJumpingWarning->OnLoop();
    outOfFuel = (this->shipManager->fuel_count < 1) || forceWait;
    if (bChoosingNewSector && NeighboringSector(finalSectorChoice))
    { 
        SelectNewSector(finalSectorChoice);
        AdvanceWorldLevel();
        readyToTravel = true;
        finalSectorChoice = -1;
        potentialLoc = &dummyNewSector;
        Close();
    }
    G_->GetSoundControl()->UpdateSoundLoop("distress", outOfFuel && distressButton.state == true ? 1.0 : 0.0);
    distressAnim.Update();

    if (waiting.running) UpdateDangerZone();
  
    if (potentialLoc != nullptr || endButton.Hovering()) 
    {
        G_->GetMouseControl()->SetValid(true, false);
    }
    distressButton.SetActive(outOfFuel);
    bool endButtonActive = false;
    if (!outOfFuel && !bossLevel && currentLoc != nullptr) 
    {
        endButtonActive = this->currentLoc->beacon;
    }
    endButton.SetActive(endButtonActive);

    bool jumpButtonActive;
    if (!bChoosingNewSector) 
    {
        if (potentialLoc == nullptr) jumpButtonActive = false;
        else jumpButtonActive = currentLoc != potentialLoc;
    }
    else jumpButtonActive = NeighboringSector(potentialSectorChoice);
    jumpButton.SetActive(jumpButtonActive);

    bool waitButtonActive;
    if (outOfFuel) waitButtonActive = true;
    else if (!bossLevel) waitButtonActive = false;
    else waitButtonActive = !bEnemyShip;
    waitButton.SetActive(waitButtonActive);

    if (waiting.running) 
    {
        waitButton.SetActive(false);
        closeButton.SetActive(false);
    }

    if (!outOfFuel) 
    {
        if (hoverLoc != nullptr) 
        {
            std::string hoverText = GetLocationText(hoverLoc);
            G_->GetMouseControl()->SetTooltip(hoverText);
        }
        G_->GetMouseControl()->InstantTooltip();
    }
    else 
    {
        std::string tooltip;
        if (waitButton.Hovering()) tooltip = "map_wait";
        else if (distressButton.Hovering()) tooltip = "map_distress";
        else tooltip = "";

        if (!tooltip.empty())
        {
            G_->GetMouseControl()->LoadTooltip(tooltip);
        }
    }
    for (auto location : locations)
    {
        location->flashTracker.Update();
    }
    targetBoxTimer.Update();
}
