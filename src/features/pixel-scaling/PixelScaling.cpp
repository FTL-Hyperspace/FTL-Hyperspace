#include "PixelScaling.h"
#include "Global.h"

#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>

namespace PixelScaling
{
    Config config;

    static const int BASE_W = 1280;
    static const int BASE_H = 720;
    static const int MAX_PRESCALE = 6;

    // Where the frame goes in the window, and how it gets there.
    struct Layout
    {
        int x, y, w, h;
        int prescale; // 0: draw directly with nearest (integer scale); >1: nearest pass at this scale, then linear
    };

    // One intermediate framebuffer per pre-scale factor, created on first use. There is no
    // destroy hook, and the factor only changes when the window changes size class.
    static GL_FrameBuffer *intermediates[MAX_PRESCALE + 1] = {};
    static bool intermediateFailed[MAX_PRESCALE + 1] = {};

    static bool ComputeLayout(int screenW, int screenH, Layout &out)
    {
        if (screenW < BASE_W || screenH < BASE_H) return false;

        float fit = std::min((float)screenW / BASE_W, (float)screenH / BASE_H);
        int whole = (int)std::floor(fit + 1e-4f);

        bool integer = config.mode == Mode::Integer || (whole >= 1 && (float)whole / fit >= config.snap);
        if (integer)
        {
            out.w = BASE_W * whole;
            out.h = BASE_H * whole;
            out.prescale = 0;
        }
        else
        {
            // Same 16:9 fit as vanilla.
            if ((float)screenW / screenH > 16.f / 9.f)
            {
                out.h = screenH;
                out.w = (int)std::lround(screenH * 16.f / 9.f);
            }
            else
            {
                out.w = screenW;
                out.h = (int)std::lround(screenW * 9.f / 16.f);
            }
            out.prescale = std::min(MAX_PRESCALE, whole + 1);
        }
        out.x = (screenW - out.w) / 2;
        out.y = (screenH - out.h) / 2;
        return true;
    }

    static GL_FrameBuffer *GetIntermediate(int scale)
    {
        if (scale < 2 || scale > MAX_PRESCALE || intermediateFailed[scale]) return nullptr;
        if (!intermediates[scale])
        {
            intermediates[scale] = CSurface::GL_CreateFrameBuffer(BASE_W * scale, BASE_H * scale);
            if (!intermediates[scale])
            {
                intermediateFailed[scale] = true;
                hs_log_file("PixelScaling: could not create a %dx%d framebuffer, falling back to linear\n", BASE_W * scale, BASE_H * scale);
            }
        }
        return intermediates[scale];
    }

    void ParseSettings(rapidxml::xml_node<char> *node)
    {
        if (auto attr = node->first_attribute("enabled"))
            config.enabled = strcmp(attr->value(), "true") == 0 || strcmp(attr->value(), "1") == 0;
        if (auto attr = node->first_attribute("mode"))
            config.mode = strcmp(attr->value(), "integer") == 0 ? Mode::Integer : Mode::Sharp;
        if (auto attr = node->first_attribute("snap"))
        {
            float snap = (float)atof(attr->value());
            if (snap > 0.f && snap <= 1.f) config.snap = snap;
        }
        hs_log_file("PixelScaling: %s, mode %s, snap %.2f\n", config.enabled ? "enabled" : "disabled",
                    config.mode == Mode::Integer ? "integer" : "sharp", config.snap);
    }
}

using namespace PixelScaling;

static bool ActiveLayout(CApp *app, Layout &layout)
{
    return config.enabled && app && app->useFrameBuffer && ComputeLayout(app->screen_x, app->screen_y, layout);
}

// Keep the mouse mapping in step with where the frame is actually drawn.
HOOK_METHOD(CApp, UpdateWindowSettings, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CApp::UpdateWindowSettings -> Begin (PixelScaling.cpp)\n")
    super();

    Layout layout;
    if (!ActiveLayout(this, layout)) return;
    x_bar = layout.x;
    y_bar = layout.y;
    mouseModifier_x = (float)BASE_W / layout.w;
    mouseModifier_y = (float)BASE_H / layout.h;
}

HOOK_STATIC(CSurface, GL_BlitFrameBuffer, (GL_FrameBuffer *fb, float size_x, float size_y, bool aa) -> void)
{
    LOG_HOOK("HOOK_STATIC -> CSurface::GL_BlitFrameBuffer -> Begin (PixelScaling.cpp)\n")

    CApp *app = G_->GetCApp();
    Layout layout;
    if (!app || fb != app->framebuffer || !ActiveLayout(app, layout))
    {
        super(fb, size_x, size_y, aa);
        return;
    }

    // The caller set a viewport for vanilla's layout; clear the whole window so nothing from
    // a previous frame is left around the (possibly smaller) frame.
    CSurface::GL_ClearColor();

    // layout.y is the top gap (what the mouse mapping uses), but viewport y counts from the
    // bottom. When the leftover height is odd the spare row goes at the bottom: borderless
    // fullscreen makes the window one row taller than the display, so that row is off-screen.
    int viewportY = app->screen_y - layout.h - layout.y;

    GL_FrameBuffer *intermediate = layout.prescale ? GetIntermediate(layout.prescale) : nullptr;
    if (!intermediate)
    {
        CSurface::GL_SetViewPort(layout.x, viewportY, layout.w, layout.h);
        super(fb, size_x, size_y, layout.prescale != 0);
        return;
    }

    // Nearest-neighbour up to a whole multiple, then one linear step down to the window.
    CSurface::GL_BindFrameBuffer(intermediate);
    CSurface::GL_SetViewPort(0, 0, BASE_W * layout.prescale, BASE_H * layout.prescale);
    super(fb, size_x, size_y, false);

    CSurface::GL_BindFrameBuffer(nullptr);
    CSurface::GL_SetViewPort(layout.x, viewportY, layout.w, layout.h);
    super(intermediate, size_x, size_y, true);
}
