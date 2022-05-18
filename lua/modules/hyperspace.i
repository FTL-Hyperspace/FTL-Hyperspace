%module Hyperspace
%include "stl.i"
%include "constraints.i"


%{
#include "../../Global.h"
#include "../../HSVersion.h"
%}

%rename("FPS") Global_CFPS_FPSControl;
%rename("Score") Global_ScoreKeeper_Keeper;
%rename("Resources") Global_ResourceControl_GlobalResources;

%immutable Global_CFPS_FPSControl;
%immutable Global_ScoreKeeper_Keeper;
%immutable Global_ResourceControl_GlobalResources;

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

/*
 TODO: We may want to hide CApp in the metatable so it looks like just a getter/global variable of the Hyperspace module
 TODO: We may want to hide Global::GetShipManager(0) as `ships.player` in the metatable so it looks like a getter global variable
 TODO: We may want to do the same with Global::GetShipManager(1) as `ships.enemy`
 ^^^^ Note all of the above require doing this with the Lua C API (Rather than some SWIG shortcut) although it may be simnpler to just do it in Lua while still having it secretly accessible under another path
 Maybe at some point we make most of the `Hyperspace` module internal and just pull out various functions & expose them to a different table in Lua so we can control the final naming of everything, and then we can hide the `Hyperspace` table after our rewrite code has run.
*/
/* We didn't import Global.h but we could have and just renamed just these specific functions.
   Although Global.h has a couple C++ variable argument functions SWIG can't handle unless the syntax was changed as it can't handle the `const char *str...` style of varargs
*/
%nodefaultctor Global;
class Global
{
public:
    static Global* GetInstance();
    ShipManager* GetShipManager(int iShipId);
    CApp* GetCApp();
};

/* Create Hyperspace.ships metatable that contains:
    Hyperspace.ships.player (ShipManager)
    Hyperspace.ships.enemy (ShipManager)
    
    Note this might need to extend the table returned by player & enemy so it has access to the contents of `CompleteShip` or `BossShip`? Since those are two completely flipping unrelated classes that have to be gotten via a completely different path of CApp->World->playerShip (CompleteShip) and CApp->World->bossShip (BossShip) and can't be retreived from the damn ShipManager?
    That is assuming we actually need to expose anything from those... like CompleteShip:KillRandomCrew() or maybe we make some new table and just bring in methods from both.
    We could totally return another metatable so that things like `ships.player:KillRandomCrew()` could access `CompleteShip` while `ships.player:DamageHull()` could route to `ShipManager`'s function internally (kinda a manual multiple inheritance)
*/
%luacode {
    Hyperspace.ships = setmetatable({}, {
        __index = function(ships, key)
            if key == "player" then
                return Hyperspace.Global.GetInstance():GetShipManager(0)
            elseif key == "enemy" then
                return Hyperspace.Global.GetInstance():GetShipManager(1)
            else
                error("Unknown ship " .. key)
            end
        end,
        __newindex = function(ships, key, value)
            error("ships is immutable")
        end
    })
}

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
    
    --function fixTheHangar()
    --    local world = Hyperspace.Global.GetInstance():GetCApp().world
    --    world.starMap.currentLoc.space = world.space:SwitchBackground(world.starMap.currentLoc.spaceImage)
    --end
    --script.on_game_event("START_BEACON", true, fixTheHangar)

    function runStarted()
        print("OH MY GOD THE RUN STARTED")
    end
    script.on_game_event("START_BEACON", false, runStarted)
}

%ignore "";

/* %rename("%s") ScoreKeeper; */
/* %rename("%s") ScoreKeeper::AddScrapCollected; */
/* %rename("%s") ScoreKeeper::gamesPlayed; */
/* %rename("%(regex:/^ScoreKeeper::(.*)$/\\1/)s", regextarget=1, fullname=1) "ScoreKeeper::.*"; */

%nodefaultctor ResourceControl;
%rename("%s") ResourceControl;
%rename("%s") ResourceControl::GetImageId;
%newobject ResourceControl::GetImageId;

%nodefaultctor CApp;
//%rename("%s") CEvent::TextEvent;
//%rename("%s") CEvent::OnEvent;
%rename("%s") CApp;
// TODO: Maybe the CApp input functions become like `input.keyDown` etc... so it makes sense for people to call them and maybe `input.onKeyDown(callback)` is a function for registering handlers?
// TODO: We could even use metatables to set __call of `input.onKeyDown` table to be the register function and `__getitem__` & `__setitem__` to allow `input.onKeyDown[index]` to access & delete registered handlers and then repeat the pattern for other event handlers? Or maybe just the __index & __newindex of it for named event handlers although representing the ordered nature of it might be harder that way.
/*
%rename("%s") CApp::OnKeyDown;
%rename("%s") CApp::OnKeyUp;
%rename("%s") CApp::OnLButtonDown;
%rename("%s") CApp::OnLButtonUp;
%rename("%s") CApp::OnMButtonDown;
//%rename("%s") CApp::OnMButtonUp; // OnMButtonUp only exists in CEvent and is referenced in the vtable, maybe it could be extended and made available if needed, same with OnMouseWheel & OnWindowResize
%rename("%s") CApp::OnMouseMove;
%rename("%s") CApp::OnRButtonDown;
%rename("%s") CApp::OnRButtonUp;
//%rename("%s") CApp::OnRequestExit; // Maybe use this for game cleanup? Not sure if this is called right before exiting the game
%rename("%s") CApp::OnTextEvent;
%rename("%s") CApp::OnTextInput;
%rename("%s") CApp::TranslateMouse;
*/
%rename("%s") CApp::gui; // Maybe we only allow access to the command gui via WorldManager and just hide the CApp implementation by something that gives us access to WorldManager like below?
%rename("%s") CApp::world;
// TODO: It might be nice to hide away CApp entirely for access to global things like `CommandGui` or `WorldManager` and hide other functions to do clicks & button presses & stuff under `input` as described above
/* Potential example for a Hyperspace.world
%luacode {
    Hyperspace.world = setmetatable({}, {
        __index = function(world, key)
            return Hyperspace.Global.GetInstance():GetCApp().world[key]
        end,
        __newindex = function(world, key, value)
            Hyperspace.Global.GetInstance():GetCApp().world[key] = value
        end
    })
}
*/

/*
%nodefaultctor CommandGui;
%rename("%s") CommandGui;
////%rename("%s") CommandGui::AddEnemyShip;
////%rename("%s") CommandGui::CreateNewStore;
////%newobject CommandGui::CreateNewStore;
////%rename("%s") CommandGui::GetWorldCoordinates;
////%rename("%s") CommandGui::NewLocation;
%rename("%s") CommandGui::shipStatus;
%rename("%s") CommandGui::crewControl;
%rename("%s") CommandGui::sysControl;
%rename("%s") CommandGui::combatControl;
%rename("%s") CommandGui::ftlButton;
%rename("%s") CommandGui::spaceStatus;
////%rename("%s") CommandGui::starMap // Part of WorldManager's actual object rather than using a reference ideally don't expose this one in CommandGui
////%rename("%s") CommandGui::shipComplete; // Part of WorldManager also, maybe use that one?
%rename("%s") CommandGui::pauseTextLoc;
%rename("%s") CommandGui::shipPosition;
//%rename("%s") CommandGui::locationText; // Not sure if this is allowed to be updated/what this will cause yet
//%rename("%s") CommandGui::loadEvent; // Not sure what this will cause yet or if it's immutable
//%rename("%s") CommandGui::loadSector; // Not sure what this will cause yet or if it's immutable
%rename("%s") CommandGui::outOfFuel;
%immutable CommandGui::outOfFuel;
%rename("%s") CommandGui::bPaused;
%immutable CommandGui::bPaused;
%rename("%s") CommandGui::bAutoPaused;
%immutable CommandGui::bAutoPaused;
%rename("%s") CommandGui::menu_pause;
%immutable CommandGui::menu_pause;
%rename("%s") CommandGui::event_pause;
%immutable CommandGui::event_pause;

//%rename("%s") CommandGui::equipScreen;
//%immutable CommandGui::equipScreen;
//
//%rename("%s") Equipment::AddAugment;
//%rename("%s") Equipment::AddDrone;
//%rename("%s") Equipment::AddToCargo;
//%rename("%s") Equipment::AddWeapon;
//%rename("%s") Equipment::GetCargoHold;

%rename("%s") CommandGui::bHideUI; // Not sure if we should disallow setting this
%rename("%s") CommandGui::jumpComplete;
%immutable CommandGui::jumpComplete;
%rename("%s") CommandGui::mapId;
%immutable CommandGui::mapId;
%rename("%s") CommandGui::secretSector;
%immutable CommandGui::secretSector;
%rename("%s") CommandGui::choiceBoxOpen;
%immutable CommandGui::choiceBoxOpen;
*/

%nodefaultctor WorldManager;
%rename("%s") WorldManager;
////%rename("%s") WorldManager::AddBoarders; // Might make more sense under the player's ship or something?
////%rename("%s") WorldManager::ModifyEnvironment;
////%rename("%s") WorldManager::HostileEnvironment;
////%rename("%s") WorldManager::ModifyStatusEffect;
//%rename("%s") WorldManager::playerShip; // TODO: See above, maybe want to extract functionality of this into proxied calls from `ships.player`?
//%rename("%s") WorldManager::bossShip; // TODO: Same as above except proxied calls from `ships.enemy` maybe and only if the boss ship is available?
%rename("%s") WorldManager::space;
%immutable WorldManager::space;

%rename("%s") WorldManager::currentDifficulty;
%immutable WorldManager::currentDifficulty;

%rename("%s") WorldManager::starMap;
%immutable WorldManager::starMap;

////%rename("%s") WorldManager::commandGui;
////%rename("%s") WorldManager::currentShipEvent; // Not sure if this should be writeable
////%rename("%s") WorldManager::currentEffects; // Vector of StatusEffect, maybe allow? Not sure if it should be writeable
////%rename("%s") WorldManager::newLocation; // Setting will cause a switch to a new location on the next frame/run of WorldManager::OnLoop, but we probably want people loading events and not location objects directly.
%rename("%s") WorldManager::bStartedGame;
%immutable WorldManager::bStartedGame;
%rename("%s") WorldManager::bLoadingGame; // Indicates game is reloading from a save file rather than an initial encounter, the on_game_event hook uses this internally (but it doesn't need to be exposed to lua for that function as that's in C)
%immutable WorldManager::bLoadingGame;
////%rename("%s") WorldManager::choiceHistory;
////%rename("%s") WorldManager::generatedEvent;
%rename("%s") WorldManager::playerCrewCount; // statistic for game over screen I think
%rename("%s") WorldManager::killedCrew; // statistic for game over screen I think
%rename("%s") WorldManager::playerHull; // statistic for game over screen I think

%nodefaultctor SpaceManager;
%rename("%s") SpaceManager;
//%rename("%s") SpaceManager::AddProjectile; // Could be useful for simulating new projectile types on screen?
////%rename("%s") SpaceManager::ClearEnvironment;
////%rename("%s") SpaceManager::ClearProjectiles; // Could be useful to test what happens if we call this right after an event's completion or enemy ship's death?
%rename("%s") SpaceManager::DangerousEnvironment; // Kinda annoying that HostileEnvironment is part of WorldManager but DangerousEnvironment is SpaceManager? WTF subset, these classes are all over the place.
////%rename("%s") SpaceManager::GetSelectedDrone; // TODO: Check if this creates a new object and if we need %newobject to clean it up.
%rename("%s") SpaceManager::SwitchBackground; // Could be useful for rendering background/starfield animations
//%rename("%s") SpaceManager::SwitchImages;
%rename("%s") SpaceManager::SwitchPlanet; // Could be useful for rendering planet animations
%rename("%s") SpaceManager::UpdatePlanetImage; // Maybe needed if planet texture is messed with directly and then this updates the cached image?

%rename("%s") SpaceManager::currentBack;
%rename("%s") SpaceManager::currentPlanet; // might be able to set .rot on this and then call UpdatePlanetImage to spin the planet
//%nodefaultctor SpaceManager::FleetShip;
//%rename("%s") SpaceManager::FleetShip;
//%rename("%s") SpaceManager::FleetShip::location;
//%rename("%s") SpaceManager::fleetShips; // Might be able to move the positions around of the various 9 fleet ships and allow for some cool animations?
//%rename("%s") SpaceManager::shipPosition; // Not sure what will happen if we mess with this, worth exploring.
////%rename("%s") SpaceManager::nebulaClouds; // Could maybe allow messing with the nebula clouds for some cool animations & movements of them, at least in high graphics mode.
////%rename("%s") SpaceManager::shipHealth; // Not sure if this is player health or WHY THE HELL IT'S HERE (or possibly duplicated) and not part of the SHIP.
%rename("%s") SpaceManager::gamePaused; // Not sure how this differs from CommandGui's pause information.
%immutable SpaceManager::gamePaused;

//%rename("%s") ImageDesc;
//%rename("%s") ImageDesc:rot;

// TODO: Maybe draggable windows could be implemented if we allowed updating of FocusWindow's position?

%nodefaultctor StarMap;
%rename("%s") StarMap;
////%rename("%s") StarMap::ConnectLocations; // Could be interesting to allow like a direct connection/wormhole between points.
////%rename("%s") StarMap::Dijkstra; // Could be interesting to allow computing how many jumps away a quest is, and maybe adding a wormhole or something if it's too far away that it would be always consumed by the fleet before exiting.
////%rename("%s") StarMap::AtBeacon; // Are we at an exit beacon, true/false.
////%rename("%s") StarMap::ForceBossJump;
////%rename("%s") StarMap::ForceExitBeacon;
////%rename("%s") StarMap::GetLocationText; // Not sure what this does, maybe it could be used to allow exploring nodes we haven't jumped to yet? Not sure
////%rename("%s") StarMap::GetNewLocation; // Not sure what this does, maybe this allows generating a new location event if waiting?
////%rename("%s") StarMap::GetWaitLocation; // Not sure
////%rename("%s") StarMap::LocationsConnected; // Might be useful with Dijkstra or ConnectLocations to make sure it's not already connected
%rename("%s") StarMap::ModifyPursuit; // We can also allow them to directly modify StarMap.pursuitDelay, all this function does is add it to the existing pursuitDelay but setting it directly could be funny or simpler than this call.
%rename("%s") StarMap::PointToGrid;
////%rename("%s") StarMap::PopClosestLoc; // Not sure if this would be useful or safe
////%rename("%s") StarMap::SelectNewSector; // Not sure if safe
//%rename("%s") StarMap::TurnIntoFleetLocation; // Could be interesting to allow something like 1. Delaying the pursuit for many many turns, 2. having every node you jump out of (or random nodes you've already visited or that do not line up with the path to the exit) convert to a fleet location as if they were chasing your path rather than the whole sector. 

//%rename("%s") StarMap::visual_size; // Not sure
%rename("%s") StarMap::currentLoc; // Current location always, even after load, this is the gold source for location after a load best I can figure out. Oh and in the base game it doesn't load backgrounds properly but does load the planet texture so then `WorldManager::CreateLocation` doesn't bother to update the texture because not both are null.
////%rename("%s") StarMap::position; // umm... FocusWindow has a position too, which position is this going to map to?
// TODO: Maybe one of the members in StarMap (that are not exposed) could help to determine how many free event locations are left so an event can be chosen to spawn in the current sector or next sector?
////%rename("%s") StarMap::dangerZone; // Messing with this might be interesting, imagine if the fleet didn't proceed directly from the left? lol
////%rename("%s") StarMap::dangerZoneRadius;
//%rename("%s") StarMap::bMapRevealed; // Not sure if setting this is okay
%rename("%s") StarMap::pursuitDelay;
//%rename("%s") StarMap::outOfFuel;
//%immutable StarMap::outOfFuel;
// TODO: We might be able to allow access to the `sectors` vector and maybe allow rendering secret sectors onto the map but instead just jumping to them when they're clicked?
////%rename("%s") StarMap::sectors; // also there is lastSectors, not sure what they're for yet
// TODO: Not sure what scrapCollected, dronesCollected, fuelCollected, weaponFound, droneFound maps do, does the game record what was found at each node? Can't find calls to it internally.

/*
////%rename("%s") StarMap::ReverseBossPath;
////%rename("%s") StarMap::UpdateBoss; // Could be interesting for allowing the boss to move manually *although* maybe this is dangerous on non-boss levels, maybe UpdateDangerZone is safer to call?
////%rename("%s") StarMap::UpdateDangerZone;
%rename("%s") StarMap::bossLoc;
%rename("%s") StarMap::arrivedAtBase;
%rename("%s") StarMap::reversedPath;
%rename("%s") StarMap::bossJumping;
%rename("%s") StarMap::boss_path;
%rename("%s") StarMap::bossLevel;
%rename("%s") StarMap::boss_wait;
%rename("%s") StarMap::bossPosition;
%rename("%s") StarMap::waitedLast;
%rename("%s") StarMap::bossStage;
*/
/* Could be cool data to expose for statistics or run purposes.
%rename("%s") StarMap::sectorMapSeed;
%immutable StarMap::sectorMapSeed;
%rename("%s") StarMap::currentSectorSeed;
%immutable StarMap::currentSectorSeed;
%rename("%s") StarMap::fuelEventSeed;
%immutable StarMap::fuelEventSeed;
*/
////%rename("%s") StarMap::foundMap; // Not sure what this map of location/bool does but maybe this is for marking what nodes have information, like if you find the sector map & scan???

/*
%nodefaultctor ShipEvent;
%rename("%s") ShipEvent;
%rename("%s") ShipEvent::present;
%rename("%s") ShipEvent::name;
%rename("%s") ShipEvent::blueprint;
%rename("%s") ShipEvent::auto_blueprint;
%rename("%s") ShipEvent::blueprintList;
%rename("%s") ShipEvent::actualBlueprint;
%rename("%s") ShipEvent::hostile;
%rename("%s") ShipEvent::surrender;
%rename("%s") ShipEvent::escape;
%rename("%s") ShipEvent::destroyed;
%rename("%s") ShipEvent::deadCrew;
%rename("%s") ShipEvent::gotaway;
%rename("%s") ShipEvent::escapeTimer;
%rename("%s") ShipEvent::surrenderThreshold;
%rename("%s") ShipEvent::escapeThreshold;
%rename("%s") ShipEvent::crewOverride;
%rename("%s") ShipEvent::weaponOverride;
%rename("%s") ShipEvent::weaponOverCount;
%rename("%s") ShipEvent::droneOverride;
%rename("%s") ShipEvent::droneOverCount;
%rename("%s") ShipEvent::shipSeed;

//%nodefaultctor RandomAmount;
%rename("%s") RandomAmount;
%rename("%s") RandomAmount::min;
%rename("%s") RandomAmount::max;
%rename("%s") RandomAmount::chanceNone;
*/

/*
%nodefaultctor StatusEffect;
%rename("%s") StatusEffect;
%rename("%s") StatusEffect::type;
%rename("%s") StatusEffect::system;
%rename("%s") StatusEffect::amount;
%rename("%s") StatusEffect::target;
*/

%rename("%s") Point;
%rename("%s") Point::Point;
// TODO: Figure out how to unignore operator overloads
%rename("%s") Point::Distance;
%rename("%s") Point::RelativeDistance;
%rename("%s") Point::x;
%rename("%s") Point::y;

/*
%nodefaultctor NebulaCloud;
%rename("%s") NebulaCloud;
%rename("%s") NebulaCloud::pos;
%rename("%s") NebulaCloud::currAlpha;
%rename("%s") NebulaCloud::currScale;
%rename("%s") NebulaCloud::deltaAlpha;
%rename("%s") NebulaCloud::deltaScale;
%rename("%s") NebulaCloud::newTrigger;
%rename("%s") NebulaCloud::newCloud;
%rename("%s") NebulaCloud::bLightning;
%rename("%s") NebulaCloud::flashTimer;
%rename("%s") NebulaCloud::lightningRotation;
*/

%nodefaultctor Location;
%rename("%s") Location;
%rename("%s") Location::space;
%rename("%s") Location::spaceImage;
//%rename("%s") Location::planet;
%rename("%s") Location::planetImage;

/*
    By default in Codeblocks SWIG settings we don't get the regular preprocessor defines, ideally we should switch between which FTLGame we import.
    To avoid having to change codeblocks compiler settings (that don't save/share between our installs) we're going to just try to use the
    Linux64 file for now. Since SWIG only uses this for method & field names but not for actual access to the address (the regular headers are
    loaded at compile time) unless we want to access a field in Lua not available to the other versions there is no concern.
*/
%include "FTLGameELF64.h"
