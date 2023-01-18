%module Hyperspace
%include "stl.i"
%include "constraints.i"

%{
#include "Global.h"
#include "HSVersion.h"
#include "CustomAchievements.h"
#include "CustomCrew.h"
#include "CustomEvents.h"
#include "CustomScoreKeeper.h"
#include "CrewMember_Extend.h"
#include "Projectile_Extend.h"
%}

namespace std {
    // shamelessly copied from the SWIG library and modified (the SWIG library code is unrestricted)
    template<class K, class T, class H = std::hash<K>, class E = std::equal_to<K> > class unordered_map {
        // add typemaps here
    public:
        typedef size_t size_type;
        typedef ptrdiff_t difference_type;
        typedef K key_type;
        typedef T mapped_type;
        typedef std::pair< const K, T > value_type;
        typedef value_type* pointer;
        typedef const value_type* const_pointer;
        typedef value_type& reference;
        typedef const value_type& const_reference;

        unordered_map();
        unordered_map(const unordered_map& other);

        unsigned int size() const;
        bool empty() const;
        void clear();
        %extend {
            const T& get(const K& key) throw (std::out_of_range) {
                std::unordered_map< K, T, H, E >::iterator i = self->find(key);
                if (i != self->end())
                    return i->second;
                else
                    throw std::out_of_range("key not found");
            }
            void set(const K& key, const T& x) {
                (*self)[key] = x;
            }
            void del(const K& key) throw (std::out_of_range) {
                std::unordered_map< K, T, H, E >::iterator i = self->find(key);
                if (i != self->end())
                    self->erase(i);
                else
                    throw std::out_of_range("key not found");
            }
            bool has_key(const K& key) {
                std::unordered_map< K, T, H, E >::iterator i = self->find(key);
                return i != self->end();
            }
            // more stuff
			const T& __getitem__(const K& key) throw (std::out_of_range)
			{
				std::unordered_map< K, T, H, E >::iterator i = self->find(key);
                if (i != self->end())
                    return i->second;
                else
                    throw std::out_of_range("key not found");
			}
			void __setitem__(const K& key, const T& x)
			{
				(*self)[key] = x;
			}
        }
    };

    // extend the map as well
    %extend map {
        const T& __getitem__(const K& key) throw (std::out_of_range) {
            std::map< K, T, C >::iterator i = self->find(key);
            if (i != self->end())
                return i->second;
            else
                throw std::out_of_range("key not found");
        }
        void __setitem__(const K& key, const T& x) {
            (*self)[key] = x;
        }
    }

    %template(vector_int) vector<int>;
    %template(vector_float) vector<float>;
    %template(vector_ArtillerySystem) vector<ArtillerySystem*>;
    %template(vector_ProjectileFactory) vector<ProjectileFactory*>;
    %template(vector_CrewMember) vector<CrewMember*>;
    %template(vector_ShipSystem) vector<ShipSystem*>;
    %template(vector_Drone) vector<Drone*>;
    %template(vector_SpaceDrone) vector<SpaceDrone*>;
    %template(vector_Room) vector<Room*>;
	%template(vector_Door) vector<Door*>;
	%template(vector_OuterHull) vector<OuterHull*>;
	%template(vector_WeaponMount) vector<WeaponMount>;
	%template(vector_DamageMessage) vector<DamageMessage*>;
	%template(vector_Projectile) vector<Projectile*>;
//	%template(vector_ShieldAnimation) vector<ShieldAnimation>;
    %template(pair_int_int) pair<int, int>;
    %template(pair_float_float) pair<float, float>;
    %template(vector_Pointf) vector<Pointf>;
    %template(vector_Point) vector<Point>;
    %template(map_int_SystemTemplate) std::map<int,ShipBlueprint::SystemTemplate>;
    %template(unordered_map_string_int) unordered_map<string,int>;
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
    BlueprintManager* GetBlueprints();
    SoundControl* GetSoundControl();
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

// make player variables and metavariables look like a different class
%{
typedef std::unordered_map<std::string,int> playerVariableType;
%}

class playerVariableType {
    // add typemaps here
public:
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef std::string key_type;
    typedef int mapped_type;
    typedef std::pair< const std::string, int > value_type;
    typedef value_type* pointer;
    typedef const value_type* const_pointer;
    typedef value_type& reference;
    typedef const value_type& const_reference;

    playerVariableType();
    playerVariableType(const playerVariableType& other);

    unsigned int size() const;
    bool empty() const;
    void clear();
    %extend {
        int get(const std::string& key) {
            playerVariableType::iterator i = self->find(key);
            if (i != self->end())
                return i->second;
            else
                return 0;
        }
        void set(const std::string& key, int x) {
            (*self)[key] = x;
            CustomAchievementTracker::instance->UpdateVariableAchievements(key, x, G_->GetWorld()->bStartedGame);
        }
        void del(const std::string& key) {
            playerVariableType::iterator i = self->find(key);
            if (i != self->end())
                self->erase(i);
        }
        bool has_key(const std::string& key) {
            playerVariableType::iterator i = self->find(key);
            return i != self->end();
        }
        // more stuff
        int __getitem__(const std::string& key)
        {
            playerVariableType::iterator i = self->find(key);
            if (i != self->end())
                return i->second;
            else
                return 0;
        }
        void __setitem__(const std::string& key, int x)
        {
            (*self)[key] = x;
            CustomAchievementTracker::instance->UpdateVariableAchievements(key, x, G_->GetWorld()->bStartedGame);
        }
    }
};

playerVariableType metaVariables;
playerVariableType playerVariables;

%rename("%s") metaVariables;
%rename("%s") playerVariables;

%nodefaultctor CustomAchievementTracker;
%rename("%s") CustomAchievementTracker;
%rename("%s") CustomAchievementTracker::UpdateVariableAchievements;

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
%rename("%s") CApp::OnExit; // close game, autosave profile and settings but not current run (current run will be on previous autosave)
%rename("%s") CApp::OnRequestExit; // close game, autosave run, profile, and settings
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
%nodefaultdtor CommandGui;
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
%rename("%s") SpaceManager::UpdateProjectile;

// hyperspace projectile creation methods
%rename("%s") SpaceManager::CreateLaserBlast;
%rename("%s") SpaceManager::CreateAsteroid;
%rename("%s") SpaceManager::CreateMissile;
%rename("%s") SpaceManager::CreateBomb;
%rename("%s") SpaceManager::CreateBeam;
%rename("%s") SpaceManager::CreateBurstProjectile;
%rename("%s") SpaceManager::CreatePDSFire;

%rename("%s") SpaceManager::projectiles;
%immutable SpaceManager::projectiles;
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

%rename("%s") ShipObject;
%nodefaultctor ShipObject;
%nodefaultdtor ShipObject;
%rename("%s") ShipObject::AddAugmentation;
%rename("%s") ShipObject::ClearShipInfo;
%rename("%s") ShipObject::GetAugmentationCount;
%rename("%s") ShipObject::GetAugmentationList;
%rename("%s") ShipObject::GetAugmentationValue;
%rename("%s") ShipObject::HasAugmentation;
%rename("HasEquipment") ShipObject::HS_HasEquipment;
%rename("%s") ShipObject::RemoveAugmentation;
%immutable ShipObject::iShipId;
%rename("%s") ShipObject::iShipId;

// TODO: Expose ShipManager
%rename("%s") ShipManager;
%nodefaultctor ShipManager;
%nodefaultdtor ShipManager;
//%rename("%s") ShipManager::AddAugmentation; // Might prefer this be done via an event? Not sure.
//%rename("%s") ShipManager::ClearShipInfo;
//%rename("%s") ShipManager::GetAugmentationCount;
//%rename("%s") ShipManager::GetAugmentationList;
//%rename("%s") ShipManager::GetAugmentationValue;
//%rename("%s") ShipManager::HasAugmentation;
//%rename("%s") ShipManager::HasEquipment;
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
%rename("%s") ShipManager::ship;
%immutable ShipManager::ship;
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
%rename("%s") ShipManager::spaceDrones;
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

%nodefaultctor Ship;
%nodefaultdtor Ship;
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
%rename("%s") Ship::vDoorList;
//%rename("%s") Ship::vOuterWalls; // TODO: Expose OuterHull
%rename("%s") Ship::vOuterAirlocks;
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

%nodefaultctor Door;
%nodefaultdtor Door;
%rename("%s") Door;

%rename("%s") Door::ApplyDamage;

%rename("%s") Door::iRoom1;
%immutable Door::iRoom1;
%rename("%s") Door::iRoom2;
%immutable Door::iRoom2;
%rename("%s") Door::bOpen;
%rename("%s") Door::iBlast;
%rename("%s") Door::bFakeOpen;
%rename("%s") Door::width;
%immutable Door::width;
%rename("%s") Door::height;
%immutable Door::height;
%rename("%s") Door::outlinePrimitive;
%rename("%s") Door::highlightPrimitive;
%rename("%s") Door::doorAnim;
%rename("%s") Door::doorAnimLarge;
%rename("%s") Door::iDoorId;
%immutable Door::iDoorId;
%rename("%s") Door::baseHealth;
%rename("%s") Door::health;
%rename("%s") Door::forcedOpen;
%rename("%s") Door::gotHit;
%rename("%s") Door::doorLevel;
%rename("%s") Door::bIoned;
%rename("%s") Door::fakeOpenTimer;
%rename("%s") Door::lockedDown;
%rename("%s") Door::lastbase;
%rename("%s") Door::iHacked;
%rename("%s") Door::x;
%immutable Door::x;
%rename("%s") Door::y;
%immutable Door::y;
%rename("%s") Door::bVertical;
%immutable Door::bVertical;

%nodefaultctor BlueprintManager;
%nodefaultdtor BlueprintManager;
%rename("%s") BlueprintManager;
%rename("%s") BlueprintManager::GetWeaponBlueprint;

%rename("%s") WeaponBlueprint;

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

%nodefaultctor Collideable;
%rename("%s") Collideable;

%rename("%s") Collideable::CollisionMoving; // checks if a moving object collides with this object
%rename("%s") Collideable::DamageBeam; // damage from a beam swipe (two points)
%rename("%s") Collideable::DamageArea; // damage from a projectile/effect (one point)
%rename("%s") Collideable::DamageShield; // damage to the shield
%rename("%s") Collideable::GetDodged; // checks whether a projectile should miss this object
%rename("%s") Collideable::GetSuperShield;
%rename("%s") Collideable::SetTempVision;
%rename("%s") Collideable::GetSpaceId; // which space the object is in
%rename("%s") Collideable::GetSelfId; // self ID of this object
%rename("%s") Collideable::GetOwnerId; // who owns the object
%rename("%s") Collideable::ValidTargetLocation;

%nodefaultctor Targetable;
%rename("%s") Targetable;

%rename("%s") Targetable::GetWorldCenterPoint; // centre of this object
%rename("%s") Targetable::GetRandomTargettingPoint; // random point that can be targeted (e.g. random room)
%rename("%s") Targetable::GetAllTargettingPoints; // list of all points that can be targeted
%rename("%s") Targetable::GetShieldShape;
%rename("%s") Targetable::GetShieldPower;
%rename("%s") Targetable::GetSpaceId; // which space the object is in
%rename("%s") Targetable::GetSpeed;
%rename("%s") Targetable::GetOwnerId; // who owns the object
%rename("%s") Targetable::GetSelfId; // self ID of this object
%rename("%s") Targetable::IsCloaked;
%rename("%s") Targetable::DamageTarget;
%rename("%s") Targetable::GetIsDying;
%rename("%s") Targetable::GetIsJumping;
%rename("%s") Targetable::ValidTarget;
%rename("%s") Targetable::GetShape;

%rename("%s") Targetable::type;
%rename("%s") Targetable::hostile;
%rename("%s") Targetable::targeted;

%rename("%s") CollisionResponse;
%rename("%s") CollisionResponse::collision_type;
%rename("%s") CollisionResponse::point;
%rename("%s") CollisionResponse::damage;
%rename("%s") CollisionResponse::superDamage;

%nodefaultctor Projectile; // users should only construct subclasses
%rename("%s") Projectile;

%rename("%s") Projectile::CollisionMoving; // checks if a moving object collides with the projectile
%rename("%s") Projectile::GetSpaceId; // which space the projectile is in
%rename("%s") Projectile::GetSelfId; // self ID of this projectile
%rename("%s") Projectile::GetOwnerId; // who owns the projectile

%rename("%s") Projectile::SetWeaponAnimation; // does nothing except for beams, used to link weapon animation to beam progress
%rename("%s") Projectile::OnRenderSpecific; // virtual method for rendering the specific projectile
%rename("CollisionCheck") Projectile::HS_CollisionCheck; // checks if this object is colliding with other object, calls CollisionMoving
%rename("OnUpdate") Projectile::HS_OnUpdate; // updates the projectile position by one frame
%rename("%s") Projectile::GetWorldCenterPoint; // returns the position of the projectile
%rename("%s") Projectile::GetRandomTargettingPoint; // returns the position of the projectile
%rename("%s") Projectile::ComputeHeading; // calculates the correct heading to get from its current position to the target point
%rename("%s") Projectile::SetDestinationSpace; // exactly what it says on the tin
%rename("%s") Projectile::EnterDestinationSpace; // actually transfers the projectile to the destination space
%rename("%s") Projectile::Dead; // checks if the projectile is dead, if death animation is playing then advance a frame and check if it's done
%rename("%s") Projectile::ValidTarget; // can this projectile be targeted (if not destroyed)
%rename("%s") Projectile::Kill; // sets the projectile to be dead; this should skip the animation
%rename("%s") Projectile::GetSpeed; // returns the speed
%rename("%s") Projectile::SetDamage; // sets the Damage
%rename("%s") Projectile::ForceRenderLayer; // this checks if the projectile is forced to render on a certain layer (e.g. ASB rendering behind/in front)
%rename("%s") Projectile::SetSpin; // sets spin (for flak)
%rename("%s") Projectile::SaveProjectile; // saves the projectile state to file
%rename("%s") Projectile::LoadProjectile; // loads the projectile state from file
%rename("%s") Projectile::GetType; // gets projectile type: 1 = laser, 2 = asteroid, 3 = missile, 4 = bomb, 5 = beam, 6 = asb
%rename("%s") Projectile::SetMovingTarget; // sets moving target (for beams), most likely only used when loading (it saves the movingtarget's selfId)

%rename("%s") Projectile::AtTarget; // checks if we're hitting the target point (based on distance from projectile to target). Returns false if missed.
%rename("%s") Projectile::Initialize; // updates a projectile's attributes from a weapon blueprint
%rename("%s") Projectile::OnRender; // renders the projectile and also the target dot for flak
%rename("%s") Projectile::RandomSidePoint; // picks a random side point (e.g. for missed ASB) - static method
%contract Projectile::RandomSidePoint(int side) {
    require:
        side >= 0;
        side < 4;
}
%rename("%s") Projectile::SetTarget; // sets a new target point and changes the heading, in vanilla only really used when generating asteroids
%rename("%s") Projectile::StartedDeath; // checks if the projectile has started its death, but also changes it to false if it has, in vanilla only used for checking when crew lasers should do damage

%rename("%s") Projectile::_targetable; //todo: abstract away _targetable
%rename("%s") Projectile::position;
%rename("%s") Projectile::last_position;
%rename("%s") Projectile::speed_magnitude;
%rename("%s") Projectile::target;
%rename("%s") Projectile::heading;
%rename("%s") Projectile::ownerId;
%rename("%s") Projectile::selfId;
%immutable Projectile::selfId;
%rename("%s") Projectile::damage;
%rename("%s") Projectile::lifespan;
%rename("%s") Projectile::destinationSpace;
%rename("%s") Projectile::currentSpace;
%rename("%s") Projectile::targetId;
%rename("%s") Projectile::dead;
%rename("%s") Projectile::death_animation;
%rename("%s") Projectile::flight_animation;
%rename("%s") Projectile::speed;
%rename("%s") Projectile::missed;
%rename("%s") Projectile::hitTarget;
%rename("%s") Projectile::hitSolidSound;
%rename("%s") Projectile::hitShieldSound;
%rename("%s") Projectile::entryAngle;
%rename("%s") Projectile::startedDeath;
%rename("%s") Projectile::passedTarget;
%rename("%s") Projectile::bBroadcastTarget;
%rename("%s") Projectile::flashTracker;
%rename("%s") Projectile::color;

%rename("%s") Get_Projectile_Extend;
%nodefaultctor Projectile_Extend;
%nodefaultdtor Projectile_Extend;
%rename("%s") Projectile_Extend;
%rename("%s") Projectile_Extend::orig;
%immutable Projectile_Extend::orig;
%rename("%s") Projectile_Extend::name;
%rename("%s") Projectile_Extend::customDamage;
%rename("%s") Projectile_Extend::missedDrones; // list of selfId of drones that have dodged this projectile

%nodefaultctor LaserBlast;
%rename("%s") LaserBlast;
%rename("%s") LaserBlast::LaserBlast;
%rename("%s") LaserBlast::movingTarget;
%rename("%s") LaserBlast::spinAngle;
%rename("%s") LaserBlast::spinSpeed;

%nodefaultctor Asteroid;
%rename("%s") Asteroid;
%rename("%s") Asteroid::Asteroid;
%rename("%s") Asteroid::imageId;
%rename("%s") Asteroid::angle;

%nodefaultctor Missile;
%rename("%s") Missile;
%rename("%s") Missile::Missile;

%nodefaultctor BombProjectile;
%rename("%s") BombProjectile;
%rename("%s") BombProjectile::BombProjectile;
%rename("%s") BombProjectile::bMissed;
%rename("%s") BombProjectile::missMessage;
%rename("%s") BombProjectile::explosiveDelay;
%rename("%s") BombProjectile::bSuperShield;
%rename("%s") BombProjectile::superShieldBypass;

%nodefaultctor BeamWeapon;
%rename("%s") BeamWeapon;
%rename("%s") BeamWeapon::BeamWeapon;
%rename("%s") BeamWeapon::sub_end;
%rename("%s") BeamWeapon::sub_start;
%rename("%s") BeamWeapon::shield_end;
%rename("%s") BeamWeapon::final_end;
%rename("%s") BeamWeapon::target2;
%rename("%s") BeamWeapon::target1;
%rename("%s") BeamWeapon::lifespan;
%rename("%s") BeamWeapon::length;
%rename("%s") BeamWeapon::dh;
%rename("%s") BeamWeapon::last_collision;
%rename("%s") BeamWeapon::soundChannel;
%rename("%s") BeamWeapon::contactAnimations;
%rename("%s") BeamWeapon::animationTimer;
%rename("%s") BeamWeapon::lastDamage;
%rename("%s") BeamWeapon::movingTarget;
%rename("%s") BeamWeapon::start_heading;
%rename("%s") BeamWeapon::timer;
%rename("%s") BeamWeapon::weapAnimation;
%rename("%s") BeamWeapon::piercedShield;
%rename("%s") BeamWeapon::oneSpace;
%rename("%s") BeamWeapon::bDamageSuperShield;
%rename("%s") BeamWeapon::movingTargetId;
%rename("%s") BeamWeapon::checkedCollision;
%rename("%s") BeamWeapon::smokeAnims;
%rename("%s") BeamWeapon::lastSmokeAnim;

%nodefaultctor PDSFire;
%rename("%s") PDSFire;
%rename("%s") PDSFire::PDSFire;
%rename("%s") PDSFire::startPoint;
%rename("%s") PDSFire::passedTarget;
%rename("%s") PDSFire::currentScale;
%rename("%s") PDSFire::missed;
%rename("%s") PDSFire::explosionAnimation;


%rename("%s") Drone;
%nodefaultctor Drone;
%nodefaultdtor Drone;

%rename("%s") Drone::OnInit;
%rename("%s") Drone::OnLoop;
%rename("%s") Drone::OnDestroy;
%rename("%s") Drone::SetPowered;
%rename("%s") Drone::SetInstantPowered;
%rename("%s") Drone::GetPowered;
%rename("%s") Drone::SetCurrentShip;
%rename("%s") Drone::SetDeployed;
%rename("%s") Drone::SetDestroyed;
%rename("%s") Drone::SetHacked;
%rename("%s") Drone::GetDeployed;
%rename("%s") Drone::NeedsRoom;
%rename("%s") Drone::SetSlot;
%rename("%s") Drone::Destroyed;
%rename("%s") Drone::GetWorldLocation;
%rename("%s") Drone::SetWorldLocation;
%rename("%s") Drone::GetDroneSlot;
%rename("%s") Drone::GetDroneHealth;
%rename("%s") Drone::GetRequiredPower;
%rename("%s") Drone::RenderIcon;
%rename("%s") Drone::GetName;
%rename("%s") Drone::CanBeDeployed;
%rename("%s") Drone::RecallOnJump;
%rename("%s") Drone::CanBeRecovered;
%rename("%s") Drone::SaveState;
%rename("%s") Drone::LoadState;
%rename("%s") Drone::BlowUp;
%rename("%s") Drone::GetStunned;

%rename("%s") Drone::iShipId;
%immutable Drone::selfId;
%rename("%s") Drone::selfId;
%rename("%s") Drone::powered;
%rename("%s") Drone::powerRequired;
%rename("%s") Drone::deployed;
%rename("%s") Drone::type;
%immutable Drone::blueprint;
%rename("%s") Drone::blueprint;
%rename("%s") Drone::bDead;
%rename("%s") Drone::iBonusPower;
%rename("%s") Drone::poweredAtLocation;
%rename("%s") Drone::destroyedTimer;
%rename("%s") Drone::iHackLevel;
%rename("%s") Drone::hackTime;


%rename("%s") SpaceDrone;
%nodefaultctor SpaceDrone;
%nodefaultdtor SpaceDrone;

%rename("%s") SpaceDrone::PickDestination;
%rename("%s") SpaceDrone::PickTarget;
%rename("%s") SpaceDrone::HasTarget;
%rename("%s") SpaceDrone::ValidTarget;
%rename("%s") SpaceDrone::GetWeaponCooldown;
%rename("%s") SpaceDrone::RandomizeStartingPosition;
%rename("%s") SpaceDrone::HideUnderOwner;
%rename("%s") SpaceDrone::GetNextProjectile;
%rename("%s") SpaceDrone::SetMovementTarget;
%rename("%s") SpaceDrone::SetWeaponTarget;
%rename("%s") SpaceDrone::ValidTargetObject;
%rename("%s") SpaceDrone::OnRender;
%rename("%s") SpaceDrone::RenderDrone;
%rename("%s") SpaceDrone::GetTooltip;
%rename("%s") SpaceDrone::GetWorldCenterPoint;
%rename("%s") SpaceDrone::SetCurrentLocation;
%rename("%s") SpaceDrone::MouseMove;
%rename("%s") SpaceDrone::GetRandomTargettingPoint;
%rename("%s") SpaceDrone::GetShieldShape;
%rename("%s") SpaceDrone::GetSpaceId;
%rename("%s") SpaceDrone::GetSpeed;
%rename("%s") SpaceDrone::GetOwnerId;
%rename("%s") SpaceDrone::GetSelfId;
%rename("%s") SpaceDrone::CollisionMoving;
%rename("%s") SpaceDrone::DamageBeam;
%rename("%s") SpaceDrone::DamageArea;
%rename("%s") SpaceDrone::GetBoardingDrone;
%rename("%s") SpaceDrone::SetDeployed;
%rename("%s") SpaceDrone::UpdateAimingAngle;
	
%rename("%s") SpaceDrone::_targetable;
%rename("%s") SpaceDrone::_collideable;
%rename("%s") SpaceDrone::currentSpace;
%rename("%s") SpaceDrone::destinationSpace;
%rename("%s") SpaceDrone::currentLocation;
%rename("%s") SpaceDrone::lastLocation;
%rename("%s") SpaceDrone::destinationLocation;
%rename("%s") SpaceDrone::pointTarget;
%rename("%s") SpaceDrone::explosion;
%rename("%s") SpaceDrone::weaponTarget;
%rename("%s") SpaceDrone::targetLocation;
%rename("%s") SpaceDrone::targetSpeed;
%rename("%s") SpaceDrone::movementTarget;
%rename("%s") SpaceDrone::speedVector;
%rename("%s") SpaceDrone::poweredLastFrame;
%rename("%s") SpaceDrone::deployedLastFrame;
%rename("%s") SpaceDrone::bFire;
%rename("%s") SpaceDrone::pause;
%rename("%s") SpaceDrone::additionalPause;
%rename("%s") SpaceDrone::weaponCooldown;
%rename("%s") SpaceDrone::current_angle;
%rename("%s") SpaceDrone::aimingAngle;
%rename("%s") SpaceDrone::lastAimingAngle;
%rename("%s") SpaceDrone::desiredAimingAngle;
%rename("%s") SpaceDrone::message;
%rename("%s") SpaceDrone::weapon_animation;
%immutable SpaceDrone::weaponBlueprint;
%rename("%s") SpaceDrone::weaponBlueprint;
%rename("%s") SpaceDrone::lifespan;
%rename("%s") SpaceDrone::bLoadedPosition;
%rename("%s") SpaceDrone::bDisrupted;
%rename("%s") SpaceDrone::hackAngle;
%rename("%s") SpaceDrone::ionStun;
%rename("%s") SpaceDrone::beamCurrentTarget;
%rename("%s") SpaceDrone::beamFinalTarget;
%rename("%s") SpaceDrone::beamSpeed;
%rename("%s") SpaceDrone::hackSparks;


%rename("%s") DroneBlueprint;
%nodefaultctor DroneBlueprint;
%nodefaultdtor DroneBlueprint;

%immutable DroneBlueprint::typeName;
%rename("%s") DroneBlueprint::typeName;
%immutable DroneBlueprint::level;
%rename("%s") DroneBlueprint::level;
%immutable DroneBlueprint::targetType;
%rename("%s") DroneBlueprint::targetType;
%immutable DroneBlueprint::power;
%rename("%s") DroneBlueprint::power;
%immutable DroneBlueprint::cooldown;
%rename("%s") DroneBlueprint::cooldown;
%immutable DroneBlueprint::speed;
%rename("%s") DroneBlueprint::speed;
%immutable DroneBlueprint::dodge;
%rename("%s") DroneBlueprint::dodge;
%immutable DroneBlueprint::weaponBlueprint;
%rename("%s") DroneBlueprint::weaponBlueprint;
%immutable DroneBlueprint::droneImage;
%rename("%s") DroneBlueprint::droneImage;
%immutable DroneBlueprint::combatIcon;
%rename("%s") DroneBlueprint::combatIcon;


%nodefaultctor CrewMember;
%nodefaultdtor CrewMember;
%rename("%s") CrewMember;

%rename("%s") Get_CrewMember_Extend;
%nodefaultctor CrewMember_Extend;
%nodefaultdtor CrewMember_Extend;
%rename("%s") CrewMember_Extend;
%rename("%s") CrewMember_Extend::orig;
%immutable CrewMember_Extend::orig;

%nodefaultctor ActivatedPower;
%nodefaultdtor ActivatedPower;
%rename("%s") ActivatedPower;
%rename("%s") ActivatedPower::def;
%immutable ActivatedPower::def;
%rename("%s") ActivatedPower::crew;
%immutable ActivatedPower::crew;
%rename("%s") ActivatedPower::crew_ex;
%immutable ActivatedPower::crew_ex;
%rename("%s") ActivatedPower::powerRoom;
%rename("%s") ActivatedPower::powerShip;

%nodefaultctor ActivatedPowerDefinition;
%nodefaultdtor ActivatedPowerDefinition;
%rename("%s") ActivatedPowerDefinition;
%rename("%s") ActivatedPowerDefinition::name;
%immutable ActivatedPowerDefinition::name;

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

%nodefaultctors SoundControl;
%nodefaultdtors SoundControl;
%rename("%s") SoundControl;
%rename("%s") SoundControl::PlaySoundMix;

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

//%rename("%s") FileHelper;
//%rename("%s") FileHelper::deleteAllSaveFiles;

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
%include "CustomAchievements.h"
%include "CustomCrew.h"
%include "CustomEvents.h"
%include "CustomScoreKeeper.h"
%include "CrewMember_Extend.h"
%include "Projectile_Extend.h"
