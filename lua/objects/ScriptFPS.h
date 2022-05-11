#ifndef SCRIPTFPS_H
#define SCRIPTFPS_H

#include "../luaInclude.h"

/*** Global game timing information
@classmod FPS
Provides the global timing information.
All fields of this class are currently **read-only**.

@usage
myOncePerSecondValue = 128
myOncePerFrameStepValue = FPS.SpeedFactor * myOncePerSecondValue
print(myOncePerFrameStepValue)
*/
/***
@field float RunningTime
*/
/***
@tparam double OldTime
*/
/***
@tparam double LastTime
*/
/*** 1/fps inverse of framerate.
@tparam float SpeedFactor 
Simulation speed of the game. Can be used to compute a stable timestep. Basically the faster the game is running the closer this number is to 0, it's the inverse of the current framerate (1/fps) so if you have a method that runs every frame you can use this to adjust values appropriately.
*/
/***
@tparam int NumFrames
*/
/***
@tparam int Frames
*/
/*** Game simulation speed
@tparam int speedLevel
This adjusts the game's simulation rate, a value of 0 is normal speed. Higher values will cause the game to speedup so that 1 in-game second is faster than 1 real-world second.
the console `SPEED` command sets this value and the speed hotkey just toggles this between 0 and whatever value was set.
This is currently **read-only** but if there's a use case reach out to the hyperspace devs and we can make this settable.
*/
class ScriptFPS
{
    public:
        ScriptFPS(lua_State* lua);
        virtual ~ScriptFPS();

        // Getter function for the "table"
        static int lua_index(lua_State* lua);
        // Setter function for the "table"
        static int lua_newindex(lua_State* lua);

        static const luaL_Reg lib[];

    protected:

    private:
        lua_State* m_Lua;
};

#endif // SCRIPTFPS_H
