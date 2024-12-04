#include "Global.h"

struct ScrollingTooltip
{
    static bool OnScrollWheel(float direction);
    
    static std::string tooltip;
    static float scrollAmount;
    static float maxScroll;
};
