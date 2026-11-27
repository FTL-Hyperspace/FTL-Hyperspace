#pragma once

#include "rapidxml.hpp"

/**
 * Pixel-perfect scaling of FTL's 1280x720 frame to the window.
 *
 * Vanilla FTL stretches its 1280x720 framebuffer to the window with linear filtering unless
 * the whole window is an exact multiple of 1280x720. Borderless fullscreen makes the window
 * one pixel taller than the display, and ultrawide widths are never a multiple of 1280, so
 * in practice the game is almost always blurred.
 *
 * Enabled from hyperspace.xml:
 *   <pixelScaling enabled="true" mode="sharp" snap="0.97"/>
 *
 * mode="sharp"   Fill the window like vanilla. Exact integer scales are drawn with nearest
 *                filtering; other scales are pre-scaled with nearest to the next integer and
 *                then smoothed down once ("sharp bilinear"), so pixels stay crisp with only a
 *                one-pixel soft seam. If an integer scale reaches at least `snap` of the fit
 *                scale it is used instead (e.g. 2560x1440 inside a 3440x1441 window).
 * mode="integer" Largest whole-number scale that fits, nearest filtering only.
 *
 * Only affects modes that use the framebuffer (windowed and "On (Stretch)").
 */
namespace PixelScaling
{
    enum class Mode { Sharp, Integer };

    struct Config
    {
        bool enabled = false;
        Mode mode = Mode::Sharp;
        float snap = 0.97f;
    };

    extern Config config;

    void ParseSettings(rapidxml::xml_node<char> *node);
}
