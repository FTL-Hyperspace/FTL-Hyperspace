#include "Global.h"

struct ScrollingChoiceBox
{
    static int renderingEventBoxState;
    static float scrollAmount;
    static int dragging;

    static Button *scrollUpButton;
    static Button *scrollDownButton;

    static int scrollBarOption;

    static int scrollButtonX;
    static int scrollButtonY1;
    static int scrollButtonY2;
    static int scrollBarHeight;
    static int scrollBarX;
    static int scrollBarY1;
    static int scrollBarY2;

    static void OnInit();
    static bool OnScrollWheel(float direction);
    static float GetMaxScroll();
    static void Scroll(float amount);
    static void ScrollTo(float amount);
    static Globals::Rect GetScrollRect();
};
