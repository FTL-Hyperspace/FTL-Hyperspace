%module Hyperspace
%include "stl.i"
%include "constraints.i"


%{
#include "Global.h"
%}

%rename("FPS") Global_CFPS_FPSControl;
%rename("ScoreKeeper") Global_ScoreKeeper_Keeper;

%immutable;
static CFPS* Global_CFPS_FPSControl;
static ScoreKeeper* Global_ScoreKeeper_Keeper;
%mutable;

float font_text_width(freetype::font_data &fontData, const char *str, float size);
float getSkillBonus(int skill, int level);
int random32();
void srandom32(unsigned int seed);

struct CFPS
{
    %immutable;
    float RunningTime;
    double OldTime;
    double LastTime;
    float SpeedFactor;
    int NumFrames;
    int Frames;
    %mutable;
    /*** Game simulation speed
    @tparam int speedLevel
    This adjusts the game's simulation rate, a value of 0 is normal speed. Higher values will cause the game to speedup so that 1 in-game second is faster than 1 real-world second.
    the console `SPEED` command sets this value and the speed hotkey just toggles this between 0 and whatever value was set.
    This is currently **read-only** but if there's a use case reach out to the hyperspace devs and we can make this settable.
    */
    int speedLevel;
};


%luacode {
    print "Hyperspace SWIG Lua loaded"
}
