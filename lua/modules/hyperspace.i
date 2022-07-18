%module Hyperspace
%include "stl.i"
%include "constraints.i"

%{
#include "../../Global.h"
#include "../../HSVersion.h"
%}

namespace std {
    %template(vector_int) vector<int>;
    %template(vector_float) vector<float>;
    %template(vector_ArtillerySystem) vector<ArtillerySystem*>;
    %template(vector_ProjectileFactory) vector<ProjectileFactory*>;
    %template(vector_CrewMember) vector<CrewMember*>;
    %template(vector_ShipSystem) vector<ShipSystem*>;
    %template(vector_Drone) vector<Drone*>;
    %template(vector_Room) vector<Room*>;
	%template(vector_Door) vector<Door*>;
	%template(vector_OuterHull) vector<OuterHull*>;
	%template(vector_WeaponMount) vector<WeaponMount>;
	%template(vector_DamageMessage) vector<DamageMessage*>;
	%template(vector_ShieldAnimation) vector<ShieldAnimation>;
}

%apply const std::string& {std::string* GetName()};

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
        static std::string ret;
        ret = $self->toVersionString();
        return ret.c_str();
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

void ErrorMessage(const char* msg);

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

%rename("%s") metaVariables;
%rename("%s") playerVariables;

%luacode {
    print "Hyperspace SWIG Lua loaded"
    _G["mods"] = {}
}

%contract ShipSystem::AddLock(int lock) {
    require:
        lock >= -1;
        lock < 6;
}

%ignore "";

%rename("setWindowTitle") sys_graphics_set_window_title;

/* %rename("%s") ScoreKeeper; */
/* %rename("%s") ScoreKeeper::AddScrapCollected; */
/* %rename("%s") ScoreKeeper::gamesPlayed; */
/* %rename("%(regex:/^ScoreKeeper::(.*)$/\\1/)s", regextarget=1, fullname=1) "ScoreKeeper::.*"; */

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
%rename("%s") WorldManager::AddBoarders; // Might make more sense under the player's ship or something?
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


%rename("%s") BoardingEvent;
%rename("%s") BoardingEvent::type;
%rename("%s") BoardingEvent::min;
%rename("%s") BoardingEvent::max;
%rename("%s") BoardingEvent::amount;
%rename("%s") BoardingEvent::breach;


// TODO: Expose ShipManager
%rename("%s") ShipManager;
%nodefaultctor ShipManager;
%nodefaultdtor ShipManager;
//%rename("%s") ShipManager::AddAugmentation; // Might prefer this be done via an event? Not sure.
//%rename("%s") ShipManager::ClearShipInfo;
%rename("%s") ShipManager::GetAugmentationCount;
%rename("%s") ShipManager::GetAugmentationList;
%rename("%s") ShipManager::GetAugmentationValue;
%rename("%s") ShipManager::HasAugmentation;
%rename("%s") ShipManager::HasEquipment;
//%rename("%s") ShipManager::RemoveAugmentation; // Might prefer this be done via an event? Not sure.
%immutable ShipManager::iShipId;
%rename("%s") ShipManager::iShipId;
%rename("%s") ShipManager::GetRandomRoomCenter;
%rename("%s") ShipManager::GetRoomCenter;
%rename("%s") ShipManager::GetAvailablePower;
//%rename("%s") ShipManager::AddCrewMemberFromBlueprint; // Might prefer via event. Might need to specify that this creates a new object for cleanup?
//%rename("%s") ShipManager::AddCrewMemberFromString; // Might prefer via event. Might need to specify that this creates a new object for cleanup?
//%rename("%s") ShipManager::AddDrone; // Might prefer via event. Might need to specify that this creates a new object for cleanup?
//%rename("%s") ShipManager::AddEquipmentFromList; // Might prefer via event?
//%rename("%s") ShipManager::AddInitialCrew;
%rename("%s") ShipManager::AddSystem;
//%rename("%s") ShipManager::AddWeapon; // Might prefer via event?
%rename("%s") ShipManager::CanFitSubsystem;
%rename("%s") ShipManager::CanFitSystem;
%rename("%s") ShipManager::CanUpgrade;
%rename("%s") ShipManager::ClearStatusAll;
%rename("%s") ShipManager::ClearStatusSystem;
//%rename("%s") ShipManager::CollisionMoving; // TODO: Expose CollisionResponse
//%rename("%s") ShipManager::CommandCrewMoveRoom; // TODO: Needs CrewMember first maybe?
%rename("%s") ShipManager::CountCrew; // Count crew on this ship, true for boarders false for regular crewmembers.
%rename("%s") ShipManager::CountCrewShipId; // Count crew on the specific ship & room
//%rename("%s") ShipManager::CreateCrewDrone; // Use Events
//%rename("%s") ShipManager::CreateSpaceDrone; // Use Events
%rename("%s") ShipManager::DamageArea;
%rename("%s") ShipManager::DamageBeam;
//%rename("%s") ShipManager::DamageCrew;
%rename("%s") ShipManager::DamageHull;
%rename("%s") ShipManager::DamageSystem;
%rename("%s") ShipManager::DoSensorsProvide;
%rename("%s") ShipManager::DoorsFunction;
//%rename("%s") ShipManager::FindCrew; // TODO: requires exposing the CrewBlueprint, this might be better solved with a different method like finding a crew by name?
%rename("%s") ShipManager::ForceDecreaseSystemPower;
%rename("%s") ShipManager::GetCrewmember;
%rename("%s") ShipManager::GetDodgeFactor;
%rename("%s") ShipManager::GetDodged; // Don't know what this represents
%rename("%s") ShipManager::GetDroneCount;
%rename("%s") ShipManager::GetDroneList;
%rename("%s") ShipManager::GetFireCount; // Get number of fires in a room, could be quite useful for computing damage
%rename("%s") ShipManager::GetOxygenPercentage; // Ship's oxygen (not per-room)
%rename("%s") ShipManager::GetSelectedCrewPoint;
%rename("%s") ShipManager::GetShieldPower;
%rename("%s") ShipManager::GetSystem; // Get a system by its id
%rename("%s") ShipManager::GetSystemInRoom;
%rename("%s") ShipManager::GetSystemPower;
%rename("%s") ShipManager::GetSystemPowerMax;
%rename("%s") ShipManager::GetSystemRoom;
%rename("%s") ShipManager::GetTooltip;
%rename("%s") ShipManager::GetWeaponList;
%rename("%s") ShipManager::HasSystem;
%rename("%s") ShipManager::InstantPowerShields;
%rename("%s") ShipManager::IsCrewFull;
%rename("%s") ShipManager::IsCrewOverFull;
%rename("%s") ShipManager::IsSystemHacked;
%rename("%s") ShipManager::ModifyDroneCount;
%rename("%s") ShipManager::ModifyMissileCount;
%rename("%s") ShipManager::ModifyScrapCount;
%rename("%s") ShipManager::PrepareSuperBarrage;
%rename("%s") ShipManager::PrepareSuperDrones;
%rename("%s") ShipManager::RemoveItem;
%rename("%s") ShipManager::ResetScrapLevel;
%rename("%s") ShipManager::RestoreCrewPositions;
%rename("%s") ShipManager::SelectRandomCrew;
%rename("%s") ShipManager::SetDestroyed;
%rename("%s") ShipManager::SetSystemPowerLoss;
%rename("%s") ShipManager::StartFire; // TODO: add this to examples for fun Hyperspace.ships.player:StartFire(1)
%rename("%s") ShipManager::SystemFunctions;
%rename("%s") ShipManager::TeleportCrew; // Teleport crew & get back the list of CrewMembers.
%immutable ShipManager::vSystemList;
%rename("%s") ShipManager::vSystemList;
%immutable ShipManager::oxygenSystem;
%rename("%s") ShipManager::oxygenSystem;
%immutable ShipManager::teleportSystem;
%rename("%s") ShipManager::teleportSystem;
%immutable ShipManager::cloakSystem;
%rename("%s") ShipManager::cloakSystem;
%immutable ShipManager::batterySystem;
%rename("%s") ShipManager::batterySystem;
%immutable ShipManager::mindSystem;
%rename("%s") ShipManager::mindSystem;
%immutable ShipManager::cloneSystem;
%rename("%s") ShipManager::cloneSystem;
%immutable ShipManager::hackingSystem;
%rename("%s") ShipManager::hackingSystem;
//%rename("%s") ShipManager::showNetwork;
//%rename("%s") ShipManager::addedSystem;
%immutable ShipManager::shieldSystem;
%rename("%s") ShipManager::shieldSystem;
%immutable ShipManager::weaponSystem;
%rename("%s") ShipManager::weaponSystem;
%immutable ShipManager::droneSystem;
%rename("%s") ShipManager::droneSystem;
%immutable ShipManager::engineSystem;
%rename("%s") ShipManager::engineSystem;
%immutable ShipManager::medbaySystem;
%rename("%s") ShipManager::medbaySystem;
%immutable ShipManager::artillerySystems;
%rename("%s") ShipManager::artillerySystems;
%immutable ShipManager::vCrewList;
%rename("%s") ShipManager::vCrewList;
//%rename("%s") ShipManager::fireSpreader;
//%rename("%s") ShipManager::ship;
//%rename("%s") ShipManager::statusMessages;
//%rename("%s") ShipManager::bGameOver;
////%rename("%s") ShipManager::current_target; // Probably just use `Hyperspace.ships.enemy` instead?
%immutable ShipManager::jump_timer;
%rename("%s") ShipManager::jump_timer;
%immutable ShipManager::fuel_count;
%rename("%s") ShipManager::fuel_count;
//%immutable ShipManager::hostile_ship;
//%rename("%s") ShipManager::hostile_ship;
//%rename("%s") ShipManager::bDestroyed;
%immutable ShipManager::iLastDamage;
%rename("%s") ShipManager::iLastDamage;
//%rename("%s") ShipManager::damMessages;
//%rename("%s") ShipManager::systemKey;
%immutable ShipManager::currentScrap;
%rename("%s") ShipManager::currentScrap;
%immutable ShipManager::bJumping;
%rename("%s") ShipManager::bJumping;
%immutable ShipManager::bAutomated;
%rename("%s") ShipManager::bAutomated;
%immutable ShipManager::shipLevel;
%rename("%s") ShipManager::shipLevel;
%immutable ShipManager::myBlueprint;
%rename("%s") ShipManager::myBlueprint;
%immutable ShipManager::lastEngineStatus;
%rename("%s") ShipManager::lastEngineStatus;
%immutable ShipManager::lastJumpReady;
%rename("%s") ShipManager::lastJumpReady;
%immutable ShipManager::bContainsPlayerCrew;
%rename("%s") ShipManager::bContainsPlayerCrew;
%immutable ShipManager::iIntruderCount;
%rename("%s") ShipManager::iIntruderCount;
%immutable ShipManager::crewCounts;
%rename("%s") ShipManager::crewCounts;
%immutable ShipManager::tempDroneCount;
%rename("%s") ShipManager::tempDroneCount;
%immutable ShipManager::tempMissileCount;
%rename("%s") ShipManager::tempMissileCount;
%immutable ShipManager::tempVision;
%rename("%s") ShipManager::tempVision;
%rename("%s") ShipManager::bHighlightCrew;
%rename("%s") ShipManager::bShowRoom;
%rename("%s") ShipManager::superBarrage;
%rename("%s") ShipManager::bInvincible;
%rename("%s") ShipManager::superDrones;
%rename("%s") ShipManager::failedDodgeCounter;
//%immutable ShipManager::hitByBeam;
//%rename("%s") ShipManager::hitByBeam;
%rename("%s") ShipManager::enemyDamagedUncloaked;
%rename("%s") ShipManager::damageCloaked;
//%immutable ShipManager::killedByBeam;
//%rename("%s") ShipManager::killedByBeam;
//%rename("%s") ShipManager::minBeaconHealth;
//%immutable ShipManager::fireExtinguishers;
//%rename("%s") ShipManager::fireExtinguishers;
//%rename("%s") ShipManager::bWasSafe;

%nodefaultctors OxygenSystem;
%nodefaultdtors OxygenSystem;
%rename("%s") OxygenSystem;
%rename("%s") OxygenSystem::EmptyOxygen;
%rename("%s") OxygenSystem::GetRefillSpeed;
%rename("%s") OxygenSystem::ModifyRoomOxygen;
%rename("%s") OxygenSystem::max_oxygen;
%rename("%s") OxygenSystem::oxygenLevels;
%rename("%s") OxygenSystem::fTotalOxygen;
%immutable OxygenSystem::bLeakingO2;
%rename("%s") OxygenSystem::bLeakingO2;

%nodefaultctors TeleportSystem;
%nodefaultdtors TeleportSystem;
%rename("%s") TeleportSystem;
%rename("%s") TeleportSystem::CanReceive;
%rename("%s") TeleportSystem::CanSend;
%rename("%s") TeleportSystem::Charged;
%rename("%s") TeleportSystem::ForceReady;
%rename("%s") TeleportSystem::GetChargedPercent;
%rename("%s") TeleportSystem::InitiateTeleport;
%rename("%s") TeleportSystem::SetArmed;
%rename("%s") TeleportSystem::SetHackingLevel;
%rename("%s") TeleportSystem::chargeLevel;
%rename("%s") TeleportSystem::bCanSend;
%rename("%s") TeleportSystem::bCanReceive;
%rename("%s") TeleportSystem::iArmed;
%rename("%s") TeleportSystem::crewSlots;
%rename("%s") TeleportSystem::iPreparedCrew;
%rename("%s") TeleportSystem::iNumSlots;
%rename("%s") TeleportSystem::bSuperShields;

%nodefaultctors CloakingSystem;
%nodefaultdtors CloakingSystem;
%rename("%s") CloakingSystem;
%rename("%s") CloakingSystem::bTurnedOn;
%rename("%s") CloakingSystem::soundeffect;

%nodefaultctors BatterySystem;
%nodefaultdtors BatterySystem;
%rename("%s") BatterySystem;
%rename("%s") BatterySystem::bTurnedOn;
%rename("%s") BatterySystem::soundeffect;

%nodefaultctors MindSystem;
%nodefaultdtors MindSystem;
%rename("%s") MindSystem;
%rename("%s") MindSystem::SetArmed;
%rename("%s") MindSystem::controlTimer;
%rename("%s") MindSystem::bCanUse;
%rename("%s") MindSystem::iArmed;
%rename("%s") MindSystem::controlledCrew;
%rename("%s") MindSystem::bSuperShields;
%rename("%s") MindSystem::bBlocked;
%rename("%s") MindSystem::iQueuedTarget;
%rename("%s") MindSystem::iQueuedShip;
%rename("%s") MindSystem::queuedCrew;

%nodefaultctors CloneSystem;
%nodefaultdtors CloneSystem;
%rename("%s") CloneSystem;
%rename("%s") CloneSystem::fTimeToClone;
%rename("%s") CloneSystem::clone;
%rename("%s") CloneSystem::fTimeGoal;
%rename("%s") CloneSystem::fDeathTime;
%rename("%s") CloneSystem::slot;

%nodefaultctors HackingSystem;
%nodefaultdtors HackingSystem;
%rename("%s") HackingSystem;
%rename("%s") HackingSystem::BlowHackingDrone;
%rename("%s") HackingSystem::bHacking;
//%rename("%s") HackingSystem::drone;
%rename("%s") HackingSystem::bBlocked;
%rename("%s") HackingSystem::bArmed;
%rename("%s") HackingSystem::currentSystem;
%rename("%s") HackingSystem::effectTimer;
%rename("%s") HackingSystem::bCanHack;
%rename("%s") HackingSystem::queuedSystem;
%rename("%s") HackingSystem::spendDrone;

%nodefaultctors Shields;
%nodefaultdtors Shields;
%rename("%s") Shields;
/*
%nodefaultctors Shields::Shield;
%nodefaultdtors Shields::Shield;
%rename("%s") Shields::Shield;
%rename("%s") Shields::Shield::charger;
%rename("%s") Shields::Shield::power;
%rename("%s") Shields::Shield::superTimer;
*/
/*
%nodefaultctors Shields::ShieldAnimation;
%nodefaultdtors Shields::ShieldAnimation;
%rename("%s") Shields::ShieldAnimation;
%rename("%s") Shields::ShieldAnimation::location;
%rename("%s") Shields::ShieldAnimation::current_size;
%rename("%s") Shields::ShieldAnimation::end_size;
%rename("%s") Shields::ShieldAnimation::current_thickness;
%rename("%s") Shields::ShieldAnimation::end_thickness;
%rename("%s") Shields::ShieldAnimation::length;
%rename("%s") Shields::ShieldAnimation::dx;
%rename("%s") Shields::ShieldAnimation::side;
%rename("%s") Shields::ShieldAnimation::ownerId;
%rename("%s") Shields::ShieldAnimation::damage;
*/
%rename("%s") Shields::AddSuperShield;
%rename("%s") Shields::CollisionReal;
%rename("%s") Shields::InstantCharge;
%rename("%s") Shields::SetBaseEllipse;
%rename("%s") Shields::ellipseRatio;
%rename("%s") Shields::center;
%rename("%s") Shields::baseShield;
%rename("%s") Shields::iHighlightedSide;
%rename("%s") Shields::shields;
%rename("%s") Shields::shields_shutdown;
%rename("%s") Shields::shieldHits;
%rename("%s") Shields::shieldsDown;
%rename("%s") Shields::superShieldDown;
%rename("%s") Shields::shieldsDownPoint;
%rename("%s") Shields::shieldsUp;
%rename("%s") Shields::shieldImage;
%rename("%s") Shields::shieldPrimitive;
%rename("%s") Shields::shieldImageName;
%rename("%s") Shields::bEnemyPresent;
//%rename("%s") Shields::damMessages;
%rename("%s") Shields::bBarrierMode;
%rename("%s") Shields::lastHitTimer;
%rename("%s") Shields::chargeTime;
%rename("%s") Shields::lastHitShieldLevel;
%rename("%s") Shields::superShieldUp;
%rename("%s") Shields::superUpLoc;
%rename("%s") Shields::bExcessChargeHack;

%nodefaultctors WeaponSystem;
%nodefaultdtors WeaponSystem;
%rename("%s") WeaponSystem;
%rename("%s") WeaponSystem::RemoveWeapon;
%rename("%s") WeaponSystem::SetBonusPower;
%rename("%s") WeaponSystem::target;
%rename("%s") WeaponSystem::weapons;
%rename("%s") WeaponSystem::weaponsTrashList;
%rename("%s") WeaponSystem::shot_timer;
%rename("%s") WeaponSystem::shot_count;
%rename("%s") WeaponSystem::missile_count;
%rename("%s") WeaponSystem::missile_start;
%rename("%s") WeaponSystem::userPowered;
%rename("%s") WeaponSystem::slot_count;
%rename("%s") WeaponSystem::iStartingBatteryPower;
%rename("%s") WeaponSystem::repowerList;

%nodefaultctors DroneSystem;
%nodefaultdtors DroneSystem;
%rename("%s") DroneSystem;
%rename("%s") DroneSystem::DePowerDrone;
%rename("%s") DroneSystem::RemoveDrone;
%rename("%s") DroneSystem::SetBonusPower;
%rename("%s") DroneSystem::drones;
%rename("%s") DroneSystem::drone_count;
%rename("%s") DroneSystem::drone_start;
%rename("%s") DroneSystem::targetShip;
%rename("%s") DroneSystem::userPowered;
%rename("%s") DroneSystem::slot_count;
%rename("%s") DroneSystem::iStartingBatteryPower;
%rename("%s") DroneSystem::repowerList;

%nodefaultctor EngineSystem;
%nodefaultdtor EngineSystem;
%rename("%s") EngineSystem;
%nodefaultctor MedbaySystem;
%nodefaultdtor MedbaySystem;
%rename("%s") MedbaySystem;

%nodefaultctors ArtillerySystem;
%nodefaultdtors ArtillerySystem;
%rename("%s") ArtillerySystem;
%rename("%s") ArtillerySystem::projectileFactory;
%rename("%s") ArtillerySystem::target;
%rename("%s") ArtillerySystem::bCloaked;

//%nodefaultctors ShipSystem;
//%nodefaultdtors ShipSystem;
%rename("%s") ShipSystem;
%rename("%s") ShipSystem::SetSelected;
%rename("%s") ShipSystem::GetSelected;
%rename("%s") ShipSystem::CompletelyDestroyed;
%rename("%s") ShipSystem::GetName;
%rename("%s") ShipSystem::SetName;
%rename("%s") ShipSystem::Repair;
%rename("%s") ShipSystem::PartialRepair;
%rename("%s") ShipSystem::PartialDamage;
%rename("%s") ShipSystem::NeedsRepairing;
%rename("%s") ShipSystem::Functioning;
%rename("%s") ShipSystem::CanBeSabotaged;
%rename("%s") ShipSystem::GetDamage;
//%rename("%s") ShipSystem::GetLocation; // TODO: Is this a new object?
//%rename("%s") ShipSystem::GetGridLocation; // TODO: Is this a new object?
%rename("%s") ShipSystem::SetDamage;
%rename("%s") ShipSystem::SetMaxDamage;
%rename("%s") ShipSystem::SetLocation;
%rename("%s") ShipSystem::GetId;
%rename("%s") ShipSystem::IsRoomBased;
%rename("%s") ShipSystem::GetRoomId;
%rename("%s") ShipSystem::Ioned;
%rename("%s") ShipSystem::SetRoomId;
%rename("%s") ShipSystem::SetHackingLevel;
%rename("%s") ShipSystem::ForceBatteryPower;
%rename("%s") ShipSystem::RemoveBatteryPower;
//%rename("%s") ShipSystem::GetWeaponInfo; // New object needs cleanup?
//%rename("%s") ShipSystem::GetOverrideTooltip; // New object needs cleanup?
%rename("%s") ShipSystem::CheckMaxPower;
%rename("%s") ShipSystem::SetBonusPower;
%rename("%s") ShipSystem::AddDamage;
%rename("%s") ShipSystem::ForceDecreasePower;
%rename("%s") ShipSystem::ForceIncreasePower;
%rename("%s") ShipSystem::StopHacking;
%rename("%s") ShipSystem::GetNeedsPower;
%rename("%s") ShipSystem::Clickable;
%rename("%s") ShipSystem::Powered;
%rename("%s") ShipSystem::AddLock;
%rename("%s") ShipSystem::ClearStatus;
%rename("%s") ShipSystem::DamageOverTime;
%rename("%s") ShipSystem::DecreasePower;
%rename("%s") ShipSystem::GetEffectivePower;
%rename("%s") ShipSystem::GetLevelDescription;
%rename("%s") ShipSystem::GetLocked;
%rename("%s") ShipSystem::GetMaxPower;
%rename("%s") ShipSystem::GetPowerCap;
%rename("%s") ShipSystem::IncreasePower;
%rename("%s") ShipSystem::IsMannedBoost;
%rename("%s") ShipSystem::IsSubsystem;
%rename("%s") ShipSystem::LockSystem;
%rename("%s") ShipSystem::NameToSystemId;
%rename("%s") ShipSystem::SetPowerCap;
%rename("%s") ShipSystem::SetPowerLoss;
%rename("%s") ShipSystem::SystemIdToName;
%rename("%s") ShipSystem::UpgradeSystem;
//%rename("%s") ShipSystem::selectedState;
//%rename("%s") ShipSystem::_shipObj;
%rename("%s") ShipSystem::fDamage;
%rename("%s") ShipSystem::pLoc;
%rename("%s") ShipSystem::fMaxDamage;
%rename("%s") ShipSystem::name;
%rename("%s") ShipSystem::roomId;
%rename("%s") ShipSystem::iRepairCount;
%rename("%s") ShipSystem::iSystemType;
%rename("%s") ShipSystem::bNeedsManned;
%rename("%s") ShipSystem::bManned;
%rename("%s") ShipSystem::iActiveManned;
%rename("%s") ShipSystem::bBoostable;
%rename("%s") ShipSystem::powerState;
%rename("%s") ShipSystem::iRequiredPower;
//%rename("%s") ShipSystem::imageIcon;
//%rename("%s") ShipSystem::iconPrimitive;
//%rename("%s") ShipSystem::iconBorderPrimitive;
//%rename("%s") ShipSystem::iconPrimitives;
//%rename("%s") ShipSystem::partialDamageRect;
//%rename("%s") ShipSystem::lockOutline;
//%rename("%s") ShipSystem::roomShape;
%rename("%s") ShipSystem::bOnFire;
%rename("%s") ShipSystem::bBreached;
%rename("%s") ShipSystem::healthState;
%rename("%s") ShipSystem::fDamageOverTime;
%rename("%s") ShipSystem::fRepairOverTime;
%rename("%s") ShipSystem::damagedLastFrame;
%rename("%s") ShipSystem::repairedLastFrame;
%rename("%s") ShipSystem::originalPower;
%rename("%s") ShipSystem::bNeedsPower;
%rename("%s") ShipSystem::iTempPowerCap;
%rename("%s") ShipSystem::iTempPowerLoss;
%rename("%s") ShipSystem::iTempDividePower;
%rename("%s") ShipSystem::iLockCount;
%rename("%s") ShipSystem::lockTimer;
%rename("%s") ShipSystem::bExploded;
%rename("%s") ShipSystem::bOccupied;
%rename("%s") ShipSystem::bFriendlies;
%rename("%s") ShipSystem::interiorImageName;
%rename("%s") ShipSystem::interiorImage;
%rename("%s") ShipSystem::interiorImageOn;
%rename("%s") ShipSystem::interiorImageManned;
%rename("%s") ShipSystem::interiorImageMannedFancy;
%rename("%s") ShipSystem::lastUserPower;
%rename("%s") ShipSystem::iBonusPower;
%rename("%s") ShipSystem::iLastBonusPower;
%rename("%s") ShipSystem::location;
%rename("%s") ShipSystem::bpCost;
%rename("%s") ShipSystem::flashTracker;
%rename("%s") ShipSystem::maxLevel;
%rename("%s") ShipSystem::iBatteryPower;
%rename("%s") ShipSystem::iHackEffect;
%rename("%s") ShipSystem::bUnderAttack;
%rename("%s") ShipSystem::bLevelBoostable;
%rename("%s") ShipSystem::bTriggerIon;
//%rename("%s") ShipSystem::damagingEffects;
%rename("%s") ShipSystem::computerLevel;

%nodefaultctors ProjectileFactory;
%nodefaultdtors ProjectileFactory;
%rename("%s") ProjectileFactory;
%rename("%s") ProjectileFactory::Fire;
%rename("%s") ProjectileFactory::FireNextShot;
%rename("%s") ProjectileFactory::ForceCoolup;
%rename("%s") ProjectileFactory::GetProjectile;
%rename("%s") ProjectileFactory::IsChargedGoal;
%rename("%s") ProjectileFactory::NumTargetsRequired;
%rename("%s") ProjectileFactory::SetCooldownModifier;
%rename("%s") ProjectileFactory::SetCurrentShip;
%rename("%s") ProjectileFactory::SetHacked;
//%rename("%s") ProjectileFactory::SpendMissiles;
//%rename("%s") ProjectileFactory::StringToWeapon;
%rename("%s") ProjectileFactory::cooldown;
%rename("%s") ProjectileFactory::subCooldown;
%rename("%s") ProjectileFactory::baseCooldown;
%rename("%s") ProjectileFactory::blueprint;
%rename("%s") ProjectileFactory::localPosition;
%rename("%s") ProjectileFactory::flight_animation;
%rename("%s") ProjectileFactory::autoFiring;
%rename("%s") ProjectileFactory::fireWhenReady;
%rename("%s") ProjectileFactory::powered;
%rename("%s") ProjectileFactory::requiredPower;
%rename("%s") ProjectileFactory::targets;
%rename("%s") ProjectileFactory::lastTargets;
%rename("%s") ProjectileFactory::targetId;
%rename("%s") ProjectileFactory::iAmmo;
%rename("%s") ProjectileFactory::name;
%rename("%s") ProjectileFactory::numShots;
%rename("%s") ProjectileFactory::currentFiringAngle;
%rename("%s") ProjectileFactory::currentEntryAngle;
%rename("%s") ProjectileFactory::currentShipTarget;
%rename("%s") ProjectileFactory::weaponVisual;
%rename("%s") ProjectileFactory::mount;
%rename("%s") ProjectileFactory::queuedProjectiles;
%rename("%s") ProjectileFactory::iBonusPower;
%rename("%s") ProjectileFactory::bFiredOnce;
%rename("%s") ProjectileFactory::iSpendMissile;
%rename("%s") ProjectileFactory::cooldownModifier;
%rename("%s") ProjectileFactory::shotsFiredAtTarget;
%rename("%s") ProjectileFactory::radius;
%rename("%s") ProjectileFactory::boostLevel;
%rename("%s") ProjectileFactory::lastProjectileId;
%rename("%s") ProjectileFactory::chargeLevel;
%rename("%s") ProjectileFactory::iHackLevel;
%rename("%s") ProjectileFactory::goalChargeLevel;
%rename("%s") ProjectileFactory::isArtillery;

%nodefaultctors WeaponMount;
%nodefaultdtors WeaponMount;
%rename("%s") WeaponMount;
%rename("%s") WeaponMount::position;
%rename("%s") WeaponMount::mirror;
%rename("%s") WeaponMount::rotate;
%rename("%s") WeaponMount::slide;
%rename("%s") WeaponMount::gib;

%nodefaultctors WeaponAnimation;
%nodefaultdtors WeaponAnimation;
%rename("%s") WeaponAnimation;
%rename("%s") WeaponAnimation::SetFireTime;
%rename("%s") WeaponAnimation::anim;
%rename("%s") WeaponAnimation::bFireShot;
%rename("%s") WeaponAnimation::bFiring;
%rename("%s") WeaponAnimation::fChargeLevel;
%rename("%s") WeaponAnimation::iChargedFrame;
%rename("%s") WeaponAnimation::iFireFrame;
%rename("%s") WeaponAnimation::bMirrored;
%rename("%s") WeaponAnimation::bRotation;
%rename("%s") WeaponAnimation::fireLocation;
%rename("%s") WeaponAnimation::bPowered;
%rename("%s") WeaponAnimation::mountPoint;
%rename("%s") WeaponAnimation::renderPoint;
%rename("%s") WeaponAnimation::fireMountVector;
%rename("%s") WeaponAnimation::slideTracker;
%rename("%s") WeaponAnimation::slideDirection;
//%rename("%s") WeaponAnimation::iChargeImage;
%rename("%s") WeaponAnimation::explosionAnim;
%rename("%s") WeaponAnimation::mount;
%rename("%s") WeaponAnimation::fDelayChargeTime;
%rename("%s") WeaponAnimation::boostAnim;
%rename("%s") WeaponAnimation::boostLevel;
%rename("%s") WeaponAnimation::bShowCharge;
%rename("%s") WeaponAnimation::fActualChargeLevel;
%rename("%s") WeaponAnimation::iChargeOffset;
%rename("%s") WeaponAnimation::iChargeLevels;
%rename("%s") WeaponAnimation::currentOffset;
//%rename("%s") WeaponAnimation::chargeBox;
//%rename("%s") WeaponAnimation::chargeBar;
%rename("%s") WeaponAnimation::iHackLevel;
%rename("%s") WeaponAnimation::hackSparks;
%rename("%s") WeaponAnimation::playerShip;

%nodefaultctors Ship;
%nodefaultdtors Ship;
%rename("%s") Ship;
%rename("%s") Ship::DoorStateType;
%rename("%s") Ship::GetRoomCenter;
/*
%nodefaultctors Ship::DoorState;
%nodefaultdtors Ship::DoorState;
%rename("%s") Ship::DoorState;
%rename("%s") Ship::DoorState::state;
%rename("%s") Ship::DoorState::hacked;
%rename("%s") Ship::DoorState::level;
*/
%rename("%s") Ship::BreachRandomHull;
%rename("%s") Ship::EmptySlots;
%rename("%s") Ship::FullRoom;
%rename("%s") Ship::GetAvailableRoomSlot;
%rename("%s") Ship::GetBaseEllipse;
%rename("%s") Ship::GetSelectedRoomId;
%rename("%s") Ship::LockdownRoom;
%rename("%s") Ship::RoomLocked;
%rename("%s") Ship::SetRoomBlackout;
%rename("%s") Ship::SetSelectedRoom;
//%rename("%s") Ship::vRoomList; // TODO: Expose Room
//%rename("%s") Ship::vDoorList; // TODO: Expose Door
//%rename("%s") Ship::vOuterWalls; // TODO: Expose OuterHull
//%rename("%s") Ship::vOuterAirlocks;
%rename("%s") Ship::hullIntegrity;
%rename("%s") Ship::weaponMounts;
%rename("%s") Ship::floorImageName;
%rename("%s") Ship::shipFloor;
%rename("%s") Ship::floorPrimitive;
%rename("%s") Ship::shipImageName;
%rename("%s") Ship::shipImage;
%rename("%s") Ship::glowOffset;
%rename("%s") Ship::shipImagePrimitive;
%rename("%s") Ship::cloakImageName;
%rename("%s") Ship::shipImageCloak;
%rename("%s") Ship::cloakPrimitive;
%rename("%s") Ship::gridPrimitive;
%rename("%s") Ship::wallsPrimitive;
%rename("%s") Ship::doorsPrimitive;
%rename("%s") Ship::doorState;
%rename("%s") Ship::lastDoorControlMode;
%rename("%s") Ship::thrustersImage;
%rename("%s") Ship::jumpGlare;
%rename("%s") Ship::vertical_shift;
%rename("%s") Ship::horizontal_shift;
%rename("%s") Ship::shipName;
//%rename("%s") Ship::explosion; // TODO: Expose ExplosionAnimation
%rename("%s") Ship::bDestroyed;
%rename("%s") Ship::baseEllipse;
%rename("%s") Ship::engineAnim;
%rename("%s") Ship::cloakingTracker;
%rename("%s") Ship::bCloaked;
%rename("%s") Ship::bExperiment;
%rename("%s") Ship::bShowEngines;
//%rename("%s") Ship::lockdowns; // TODO: Expose LockdownShard

// TODO: Make most if not all of ShipBlueprint immutable
%nodefaultctors ShipBlueprint;
%nodefaultdtors ShipBlueprint;
%rename("%s") ShipBlueprint;
/*
%nodefaultctors ShipBlueprint::SystemTemplate;
%nodefaultdtors ShipBlueprint::SystemTemplate;
%rename("%s") ShipBlueprint::SystemTemplate;
%rename("%s") ShipBlueprint::SystemTemplate::systemId;
%rename("%s") ShipBlueprint::SystemTemplate::powerLevel;
%rename("%s") ShipBlueprint::SystemTemplate::location;
%rename("%s") ShipBlueprint::SystemTemplate::bp;
%rename("%s") ShipBlueprint::SystemTemplate::maxPower;
%rename("%s") ShipBlueprint::SystemTemplate::image;
%rename("%s") ShipBlueprint::SystemTemplate::slot;
%rename("%s") ShipBlueprint::SystemTemplate::direction;
%rename("%s") ShipBlueprint::SystemTemplate::weapon;
*/
%rename("%s") ShipBlueprint::desc; // TODO: Expose Description
%rename("%s") ShipBlueprint::blueprintName;
%rename("%s") ShipBlueprint::name;
%rename("%s") ShipBlueprint::shipClass;
%rename("%s") ShipBlueprint::layoutFile;
%rename("%s") ShipBlueprint::imgFile;
%rename("%s") ShipBlueprint::cloakFile;
%rename("%s") ShipBlueprint::shieldFile;
%rename("%s") ShipBlueprint::floorFile;
%rename("%s") ShipBlueprint::systemInfo; // TODO: Expose SystemTemplate
%rename("%s") ShipBlueprint::systems;
%rename("%s") ShipBlueprint::droneCount;
%rename("%s") ShipBlueprint::originalDroneCount;
%rename("%s") ShipBlueprint::droneSlots;
%rename("%s") ShipBlueprint::loadDrones;
%rename("%s") ShipBlueprint::drones;
%rename("%s") ShipBlueprint::augments;
%rename("%s") ShipBlueprint::weaponCount;
%rename("%s") ShipBlueprint::originalWeaponCount;
%rename("%s") ShipBlueprint::weaponSlots;
%rename("%s") ShipBlueprint::loadWeapons;
%rename("%s") ShipBlueprint::weapons;
%rename("%s") ShipBlueprint::missiles;
%rename("%s") ShipBlueprint::drone_count;
%rename("%s") ShipBlueprint::health;
%rename("%s") ShipBlueprint::originalCrewCount;
%rename("%s") ShipBlueprint::defaultCrew;
%rename("%s") ShipBlueprint::customCrew; // TODO: Expose CrewBlueprint
%rename("%s") ShipBlueprint::maxPower;
%rename("%s") ShipBlueprint::boardingAI;
%rename("%s") ShipBlueprint::bp_count;
%rename("%s") ShipBlueprint::maxCrew;
%rename("%s") ShipBlueprint::maxSector;
%rename("%s") ShipBlueprint::minSector;
%rename("%s") ShipBlueprint::unlock;

//%nodefaultctors Blueprint;
//%nodefaultdtors Blueprint;
%rename("%s") Blueprint;
%rename("%s") Blueprint::GetNameLong;
%rename("%s") Blueprint::GetNameShort;
%rename("%s") Blueprint::GetType;
%rename("%s") Blueprint::name;
%rename("%s") Blueprint::desc;
%rename("%s") Blueprint::type;

%nodefaultctor ShieldPower;
%rename("%s") ShieldPower;
%rename("%s") ShieldPower::first;
%rename("%s") ShieldPower::second;
%rename("%s") ShieldPower::super;

%rename("%s") Damage;
%rename("%s") Damage::iDamage;
%rename("%s") Damage::iShieldPiercing;
%rename("%s") Damage::fireChance;
%rename("%s") Damage::breachChance;
%rename("%s") Damage::stunChance;
%rename("%s") Damage::iIonDamage;
%rename("%s") Damage::iSystemDamage;
%rename("%s") Damage::iPersDamage;
%rename("%s") Damage::bHullBuster;
%rename("%s") Damage::ownerId;
%rename("%s") Damage::selfId;
%rename("%s") Damage::bLockdown;
%rename("%s") Damage::crystalShard;
%rename("%s") Damage::bFriendlyFire;
%rename("%s") Damage::iStun;

%rename("%s") AnimationTracker;
%rename("%s") AnimationTracker::GetAlphaLevel;
%rename("%s") AnimationTracker::Progress;
%rename("%s") AnimationTracker::SetLoop;
%rename("%s") AnimationTracker::SetProgress;
%rename("%s") AnimationTracker::Start;
%rename("%s") AnimationTracker::StartReverse;
%rename("%s") AnimationTracker::Stop;
%rename("%s") AnimationTracker::time;
%rename("%s") AnimationTracker::loop;
%rename("%s") AnimationTracker::current_time;
%rename("%s") AnimationTracker::running;
%rename("%s") AnimationTracker::reverse;
%rename("%s") AnimationTracker::done;
%rename("%s") AnimationTracker::loopDelay;
%rename("%s") AnimationTracker::currentDelay;

%rename("%s") TimerHelper;
%rename("%s") TimerHelper::TimerHelper;
%rename("%s") TimerHelper::Done;
%rename("%s") TimerHelper::ResetMinMax;
%rename("%s") TimerHelper::Running;
%rename("%s") TimerHelper::SetMaxTime;
//%rename("%s") TimerHelper::Start; // TODO: Figure out how to allow this since it's overloaded?
%rename("%s") TimerHelper::Stop;
%rename("%s") TimerHelper::Update;
%rename("%s") TimerHelper::maxTime;
%rename("%s") TimerHelper::minTime;
%rename("%s") TimerHelper::currTime;
%rename("%s") TimerHelper::currGoal;
%rename("%s") TimerHelper::loop;
%rename("%s") TimerHelper::running;

%nodefaultctors ResourceControl;
%nodefaultdtors ResourceControl;
%rename("%s") ResourceControl;
/*
%rename("%s") ResourceControl::ImageSwappingMode;
%rename("%s") ResourceControl::DynamicImageInfo;
%rename("%s") ResourceControl::DynamicImageInfo::name;
%rename("%s") ResourceControl::DynamicImageInfo::resid;
%rename("%s") ResourceControl::LogicalTexInfo;
%rename("%s") ResourceControl::LogicalTexInfo::physName;
%rename("%s") ResourceControl::LogicalTexInfo::x;
%rename("%s") ResourceControl::LogicalTexInfo::y;
%rename("%s") ResourceControl::LogicalTexInfo::w;
%rename("%s") ResourceControl::LogicalTexInfo::h;
*/
//%newobject ResourceControl::CreateImagePrimitive; // Not sure if needed
%rename("%s") ResourceControl::CreateImagePrimitive;
//%newobject ResourceControl::CreateImagePrimitiveString; // Not sure if needed
%rename("%s") ResourceControl::CreateImagePrimitiveString;
%rename("%s") ResourceControl::GetFontData;
//%newobject ResourceControl::GetImageId;
%rename("%s") ResourceControl::GetImageId;
%rename("%s") ResourceControl::ImageExists;
%rename("%s") ResourceControl::RenderImage;
%rename("%s") ResourceControl::RenderImageString;

%rename("%s") Point;
%rename("%(regex:/^Point::(.*)$/\\1/)s", regextarget=1, fullname=1) "Point::.*";
%rename("%s") Pointf;
%rename("%(regex:/^Pointf::(.*)$/\\1/)s", regextarget=1, fullname=1) "Pointf::.*";

/*
    By default in Codeblocks SWIG settings we don't get the regular preprocessor defines, ideally we should switch between which FTLGame we import.
    To avoid having to change codeblocks compiler settings (that don't save/share between our installs) we're going to just try to use the
    Linux64 file for now. Since SWIG only uses this for method & field names but not for actual access to the address (the regular headers are
    loaded at compile time) unless we want to access a field in Lua not available to the other versions there is no concern.
*/
%include "FTLGameELF64.h"
