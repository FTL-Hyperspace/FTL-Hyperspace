%module Hyperspace
%include "stl.i"
%include "constraints.i"


%{
#include "../../Global.h"
#include "../../HSVersion.h"
%}

%rename("FPS") Global_CFPS_FPSControl;
%rename("Score") Global_ScoreKeeper_Keeper;

%immutable;
static CFPS* Global_CFPS_FPSControl;
static ScoreKeeper* Global_ScoreKeeper_Keeper;
%mutable;

%rename("setRandomSeed") srandom32;

float font_text_width(freetype::font_data &fontData, const char *str, float size);
float getSkillBonus(int skill, int level);
int random32();
void srandom32(unsigned int seed);

%rename("version") HS_Version; 
%extend HyperspaceVersion {
    const char* __str__() const {
        return $self->toVersionString().c_str();
    }
};
%include "HSVersion.h"

%nodefaultctor;
%nodefaultdtor;
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
    */
    int speedLevel;
};
%clearnodefaultctor;
%clearnodefaultdtor;


%luacode {
    print "Hyperspace SWIG Lua loaded"
}

%ignore "";
/* %rename("%s") ScoreKeeper; */
/* %rename("%s") ScoreKeeper::AddScrapCollected; */
/* %rename("%s") ScoreKeeper::gamesPlayed; */
/* %rename("%(regex:/^ScoreKeeper::(.*)$/\\1/)s", regextarget=1, fullname=1) "ScoreKeeper::.*"; */

/*
    By default in Codeblocks SWIG settings we don't get the regular preprocessor defines, ideally we should switch between which FTLGame we import.
    To avoid having to change codeblocks compiler settings (that don't save/share between our installs) we're going to just try to use the
    Linux64 file for now. Since SWIG only uses this for method & field names but not for actual access to the address (the regular headers are
    loaded at compile time) unless we want to access a field in Lua not available to the other versions there is no concern.
*/
%include "FTLGameELF64.h"
