#include "Global.h"
#include "Environments.h"
#include "LuaLibScript.h"
#include "RenderEvents.h"
#include "swigluarun.h"

//Neutral ASB text
static GL_Primitive* warningPdsAll = nullptr;
static std::vector<int> g_hazards;

HOOK_METHOD(SpaceStatus, OnInit, (SpaceManager *space, Point pos) -> void)
{
    LOG_HOOK("HOOK_METHOD -> SpaceStatus::OnInit -> Begin (CustomSpaceStatus.cpp)\n")
    super(space, pos);
    warningPdsAll = G_->GetResources()->CreateImagePrimitiveString("warnings/danger_pds_neutral.png", position.x - 30, position.y, 0, GL_Color(1.f, 1.f, 1.f, 1.f), 1.f, false);
}

HOOK_METHOD_PRIORITY(SpaceStatus, OnLoop, 9999, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> SpaceStatus::OnLoop -> Begin (CustomSpaceStatus.cpp)\n")
    // Rewrite to remove asteroid's early return that prevents other warnings from displaying when asteroids and other environemts are combined

    std::string warnStr;

    currentEffect = ENV_NONE;
    currentEffect2 = ENV_NONE;
    g_hazards.clear();

    if (space->asteroidGenerator.bRunning)
    {
        g_hazards.push_back(ENV_ASTEROIDS);
    }
    if (space->sunLevel)
    {
        warnStr = "warning_solar_flare";
        g_hazards.push_back(ENV_SUN);
    }
    if (space->pulsarLevel)
    {
        warnStr = "warning_ion_pulse";
        g_hazards.push_back(ENV_PULSAR);
    }
    if (space->bPDS)
    {
        warnStr = "warning_pds_locked";
        g_hazards.push_back(space->envTarget == 1 ? ENV_PDS_FRIENDLY : ENV_PDS);
    }
    if (space->bNebula)
    {
        g_hazards.push_back(ENV_NEBULA);
        if (space->bStorm)
        {
            g_hazards.push_back(ENV_STORM);
        }
    }

    if (!warnStr.empty())
    {
        if (5.f <= space->flashTimer.currGoal - space->flashTimer.currTime)
        {
            warningMessage->tracker.Stop(false);
        }
        else
        {
            TextString text(warnStr, false);
            warningMessage->SetText(text);
            warningMessage->Start();
        }
    }

    // We should take over the role of currentEffect and currentEffect2 completely to g_hazards. This is just for safety of compatibility.
    if (g_hazards.size() > 0)
    {
        currentEffect = g_hazards[0];
        if (g_hazards.size() > 1)
        {
            currentEffect2 = g_hazards[1];
        }
    }

    warningMessage->OnLoop();
    incomingFire->OnLoop();
}

HOOK_METHOD(SpaceStatus, OnRender, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> SpaceStatus::OnRender -> Begin (CustomSpaceStatus.cpp)\n")

    int idx = G_->getLuaContext()->getLibScript()->call_on_render_event_pre_callbacks(RenderEvents::SPACE_STATUS, 0);

    if (idx >= 0)
    {
        incomingFire->OnRender();
        if (g_hazards.empty())
        {
            G_->getLuaContext()->getLibScript()->call_on_render_event_post_callbacks(RenderEvents::SPACE_STATUS, std::abs(idx), 0);
            return;
        }

        // Render hazard icons
        CSurface::GL_PushMatrix();
        int iconsOffsetToLeft = g_hazards.size() > 2 ? (2 - g_hazards.size()) * 72 : 0;
        CSurface::GL_Translate(iconsOffsetToLeft, 0.f);
        for (int hazard : g_hazards)
        {
            bool neutralAsb = (hazard == ENV_PDS || hazard == ENV_PDS_FRIENDLY) && space->envTarget == 2; // Special case for neutral ASB
            CSurface::GL_RenderPrimitive(neutralAsb ? warningPdsAll : warningImages[hazard]);
            CSurface::GL_Translate(72.f, 0.f, 0.f);
        }
        CSurface::GL_PopMatrix();

        // Render warning text below the icons
        RenderWarningText(currentEffect, g_hazards.size() > 1 ? (3 - g_hazards.size()) * 36 : 0);

        if (touchedTooltip == 1)
        {
            int mX = hitbox.w / 2 + hitbox.x;
            int mY = hitbox.y + hitbox.h;
            MouseMove(mX, mY + -1);
            G_->GetMouseControl()->QueueStaticTooltip(Point(mX - 80, mY + 20));
        }
        if (((space->sunLevel == false) && (space->pulsarLevel == false)) && (space->bPDS == false))
        {
            G_->getLuaContext()->getLibScript()->call_on_render_event_post_callbacks(RenderEvents::SPACE_STATUS, std::abs(idx), 0);
            return;
        }
        warningMessage->OnRender();
    }

    G_->getLuaContext()->getLibScript()->call_on_render_event_post_callbacks(RenderEvents::SPACE_STATUS, std::abs(idx), 0);
}

HOOK_METHOD_PRIORITY(SpaceStatus, RenderWarningText, 9999, (int effect, int textOffset) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> SpaceStatus::RenderWarningText -> Begin (CustomSpaceStatus.cpp)\n")
    GL_Texture *tex;
    GL_Color color;
    std::string text;

    color.g = 1.0;
    color.a = 1.0;
    if ((effect == ENV_PDS || effect == ENV_PDS_FRIENDLY) && space->envTarget == 2) // ASB and targeting both ships
    {
        color.b = 90.f / 255.f;
        color.g = 255.f / 255.f;
        color.r = 255.f / 255.f;

        tex = G_->GetResources()->GetImageId("warnings/backglow_warning_yellow.png");
        text = G_->GetTextLibrary()->GetText("warning_pds_all");
    }
    else if (effect == ENV_PDS_FRIENDLY)
    {
        color.r = 0.4705882;
        color.b = 0.4705882;
        tex = G_->GetResources()->GetImageId("warnings/backglow_warning_green.png");
        text = G_->GetTextLibrary()->GetText("warning_pds_allies");
    }
    else
    {
        //TODO: Hook Global COLOR_RED_WARNING
        /*
        color.b = COLOR_RED_WARNING.b / 255.0;
        color.g = COLOR_RED_WARNING.g / 255.0;
        color.r = COLOR_RED_WARNING.r / 255.0;
        */
        color.b = 50.f / 255.f;
        color.g = 50.f / 255.f;
        color.r = 255.f / 255.f;

        tex = G_->GetResources()->GetImageId("warnings/backglow_warning_red.png");
        text = G_->GetTextLibrary()->GetText("warning_environment_danger");
    }

    Point textPos = Point(textOffset + position.x, position.y + 51);
    Pointf textSize = freetype::easy_measurePrintLines(52, 0.0, 0.0, 999, text);
    CSurface::GL_BlitImage(tex, textPos.x - (int)textSize.x / 2, textPos.y - 1, (int)textSize.x, (int)textSize.y, 0.0, COLOR_WHITE, false);
    CSurface::GL_SetColor(color);
    freetype::easy_printCenter(52, textPos.x, textPos.y, text);
    CSurface::GL_SetColor(COLOR_WHITE);
    return;
}

HOOK_METHOD_PRIORITY(SpaceStatus, MouseMove, 9999, (int mX, int mY) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> SpaceStatus::MouseMove -> Begin (CustomSpaceStatus.cpp)\n")

    int effect = ENV_NONE;
    int iconsOffsetToLeft = g_hazards.size() > 2 ? (2 - g_hazards.size()) * 72 : 0;
    for (int i = 0; i < g_hazards.size(); ++i)
    {
        if (hitbox.x + i * 72 + iconsOffsetToLeft < mX && mX < hitbox.x + i * 72 + iconsOffsetToLeft + hitbox.w && hitbox.y < mY && mY < hitbox.y + hitbox.h)
        {
            effect = g_hazards[i];
            break;
        }
    }
    if (effect == ENV_NONE)
    {
        return;
    }

    std::string tip;

    switch (effect)
    {
    case ENV_ASTEROIDS:
        tip = "asteroids";
        break;
    case ENV_SUN:
        tip = "sun";
        break;
    case ENV_NEBULA:
        tip = "nebula";
        break;
    case ENV_STORM:
        tip = "storm";
        break;
    case ENV_PULSAR:
        tip = "pulsar";
        break;
    case ENV_PDS:
    case ENV_PDS_FRIENDLY:
        bool inFleet = space->dangerZone;
        if (space->envTarget == 0)
        {
            tip = inFleet ? "PDS_FLEET" : "PDS_PLAYER";
        }
        else if (space->envTarget == 1)
        {
            tip = inFleet ? "PDS_FLEET_ENEMY" : "PDS_ENEMY";
        }
        else
        {
            tip = inFleet ? "PDS_FLEET_ALL" : "PDS_ALL";
        }
        break;
    }

    G_->GetMouseControl()->LoadTooltip(tip);
}
