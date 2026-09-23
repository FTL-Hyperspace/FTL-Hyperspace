#pragma once
#include "Global.h"

extern TemporalArmState g_iTemporal;

extern int g_dilationAmount;

extern std::map<int, int> g_crewDilationRooms;
extern std::map<int, int> g_envDilationRooms;
extern std::map<int, int> g_sysDilationRooms;
extern std::map<int, int> g_shardDilationRooms;

int GetRoomDilationAmount(std::map<int, int> roomMap, int roomId);

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

class TemporalSystem : public ShipSystem
{
public:
    void _HS_Jump();
    void _HS_OnLoop();
    void _HS_ShipDestroyed();
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

    int _HS_GetCooldownLevel();
    float _HS_GetCooldownFraction();
    bool _HS_HasButton();
    void _HS_OnRender(bool ignoreStatus);
    void _HS_MouseMove(int x, int y);
    bool _HS_MouseClick(bool shift);
    void _HS_KeyDown(SDLKey key, bool shift);
};
