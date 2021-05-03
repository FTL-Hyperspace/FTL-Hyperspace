#include "Global.h"

class OverclockerBox : public CooldownSystemBox
{
    ShipManager *shipManager;

    Button* overclockButton = nullptr;
    Point buttonOffset;
    GL_Texture *box = nullptr;

public:
    OverclockerSystem_Wrapper *overclockerSystem;

    OverclockerBox(Point pos, ShipSystem *sys, ShipManager *ship);

    void RenderBox(bool ignoreStatus);
    void NewMouseMove(int x, int y);
    void LeftMouseClick(bool unk);
};
