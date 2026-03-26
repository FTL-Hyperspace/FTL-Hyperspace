#ifdef __APPLE__
/**
 * macOS cursor visibility management.
 *
 * Hides the system cursor when hovering over the game window (FTL draws its own),
 * but shows it near window edges so users can access the dock/menu bar to exit.
 */

#include "Global.h"

// CoreGraphics cursor API
extern "C" {
    typedef uint32_t CGDirectDisplayID;
    CGDirectDisplayID CGMainDisplayID(void);
    int CGDisplayHideCursor(CGDirectDisplayID display);
    int CGDisplayShowCursor(CGDirectDisplayID display);
}

static bool g_cursorHidden = false;

HOOK_METHOD(CApp, OnMouseMove, (int mX, int mY, int relX, int relY, bool holdingLeft, bool holdingRight, bool holdingMiddle) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CApp::OnMouseMove -> Begin (CursorHide.cpp)\n")

    // Show cursor near edges so user can resize and exit the game with the cursor
    const int edgeMargin = 10;
    bool nearEdge = (mX < edgeMargin || mY < edgeMargin ||
                     mX > screen_x - edgeMargin || mY > screen_y - edgeMargin);

    if (nearEdge && g_cursorHidden)
    {
        CGDisplayShowCursor(CGMainDisplayID());
        g_cursorHidden = false;
    }
    else if (!nearEdge && !g_cursorHidden)
    {
        CGDisplayHideCursor(CGMainDisplayID());
        g_cursorHidden = true;
    }

    super(mX, mY, relX, relY, holdingLeft, holdingRight, holdingMiddle);
}

// Ensure cursor is visible when window loses focus (e.g. Cmd+Tab)
HOOK_METHOD(CApp, OnInputBlur, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CApp::OnInputBlur -> Begin (CursorHide.cpp)\n")
    super();
    if (g_cursorHidden)
    {
        CGDisplayShowCursor(CGMainDisplayID());
        g_cursorHidden = false;
    }
}

#endif // __APPLE__
