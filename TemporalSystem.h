#include "Global.h"

class TemporalBox : public CooldownSystemBox
{
    ShipManager *shipManager;

    Button* speedUpButton = nullptr;
    Button* slowDownButton = nullptr;
    Point buttonOffset;
    GL_Texture *box = nullptr;

public:
    TemporalSystem_Wrapper *temporalSystem;

    TemporalBox(Point pos, ShipSystem *sys, ShipManager *ship);

    void RenderBox(bool ignoreStatus);
    void NewMouseMove(int x, int y);
    void LeftMouseClick(bool unk);
};
