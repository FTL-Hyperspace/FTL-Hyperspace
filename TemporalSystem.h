#pragma once
#include "Global.h"

class TemporalSystemParser
{
public:
    static float GetLevelDuration(int systemLevel);
    static int GetLevelCooldown(int systemLevel);
    static float GetDilationStrength(int effectStrength); // negative for slow
    static void ParseSystemNode(rapidxml::xml_node<char>* node);

private:
    static std::map<int, float> levelSpeed;
    static std::map<int, float> levelSlow;
    static std::map<int, float> levelDurations;
    static std::map<int, int> levelCooldowns;
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

    void RenderBox(bool ignoreStatus);
    void NewMouseMove(int x, int y);
    void LeftMouseClick(bool unk);
};
