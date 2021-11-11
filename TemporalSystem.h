#pragma once
#include "Global.h"

class TemporalSystemParser
{
public:
    struct TemporalLevel
    {
        int duration;
        int cooldown;
        float strength;
    };

    static int GetDilationDuration(int systemLevel);
    static int GetDilationCooldown(int systemLevel);
    static float GetDilationStrength(int effectStrength); // negative for slow
    static void ParseSystemNode(rapidxml::xml_node<char>* node);

private:
    static std::map<int, TemporalLevel> levelSpeed;
    static std::map<int, TemporalLevel> levelSlow;
};

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
    ~TemporalBox();

    void RenderBox(bool ignoreStatus);
    void NewMouseMove(int x, int y);
    void LeftMouseClick(bool unk);
    void OnKeyDown(SDLKey key, bool shift);
};
