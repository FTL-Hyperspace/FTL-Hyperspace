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
    int speedLevel;
};


%luacode {
    print "Hyperspace SWIG Lua loaded"
}
