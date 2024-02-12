#include <sstream>
#include <vector>
#include <map>
#include "LuaLibScript.h"
#include "../Global.h"
#include "swigluarun.h"

#include "EnumClassHash.h"

#include "TemporalSystem.h"

static std::vector<LuaFunctionRef> m_on_load_callbacks;
static std::vector<LuaFunctionRef> m_on_init_callbacks;
static std::multimap<std::string, LuaFunctionRef> m_on_game_event_callbacks;
static std::multimap<std::string, LuaFunctionRef> m_on_game_event_loading_callbacks;
static std::unordered_map<InternalEvents::Identifiers, std::vector<std::pair<LuaFunctionRef, int>>, EnumClassHash> m_on_internal_event_callbacks;
static std::unordered_map<RenderEvents::Identifiers, std::vector<std::pair<std::pair<LuaFunctionRef, LuaFunctionRef>, int>>, EnumClassHash> m_on_render_event_callbacks; // Holds before & after function ref in the pair

void LuaLibScript::LoadTypeInfo()
{
    types.pActivatedPower = SWIG_TypeQuery(this->m_Lua, "ActivatedPower *");
    types.pActivatedPowerRequirements = SWIG_TypeQuery(this->m_Lua, "ActivatedPowerRequirements *");
    types.pActivatedPowerResource = SWIG_TypeQuery(this->m_Lua, "ActivatedPowerResource *");
    types.pCollideable = SWIG_TypeQuery(this->m_Lua, "Collideable *");
    types.pCollisionResponse = SWIG_TypeQuery(this->m_Lua, "CollisionResponse *");
    types.pCrewMember = SWIG_TypeQuery(this->m_Lua, "CrewMember *");
    types.pDamage = SWIG_TypeQuery(this->m_Lua, "Damage *");
    types.pPointf = SWIG_TypeQuery(this->m_Lua, "Pointf *");
    types.pProjectile[0] = SWIG_TypeQuery(this->m_Lua, "Projectile *");
    types.pProjectile[1] = SWIG_TypeQuery(this->m_Lua, "LaserBlast *");
    types.pProjectile[2] = SWIG_TypeQuery(this->m_Lua, "Asteroid *");
    types.pProjectile[3] = SWIG_TypeQuery(this->m_Lua, "Missile *");
    types.pProjectile[4] = SWIG_TypeQuery(this->m_Lua, "BombProjectile *");
    types.pProjectile[5] = SWIG_TypeQuery(this->m_Lua, "BeamWeapon *");
    types.pProjectile[6] = SWIG_TypeQuery(this->m_Lua, "PDSFire *");
    types.pProjectileFactory = SWIG_TypeQuery(this->m_Lua, "ProjectileFactory *");
    types.pShip = SWIG_TypeQuery(this->m_Lua, "Ship *");
    types.pShipBlueprint = SWIG_TypeQuery(this->m_Lua, "ShipBlueprint *");
    types.pShipEvent = SWIG_TypeQuery(this->m_Lua, "ShipEvent *");
    types.pShipManager = SWIG_TypeQuery(this->m_Lua, "ShipManager *");
    types.pShipSystem = SWIG_TypeQuery(this->m_Lua, "ShipSystem *");
    types.pWeaponBlueprint = SWIG_TypeQuery(this->m_Lua, "WeaponBlueprint *");
    types.pRoom = SWIG_TypeQuery(this->m_Lua, "Room *");

    types.pSpaceDrone = SWIG_TypeQuery(this->m_Lua, "SpaceDrone *");
    // todo: fix the derived types to make them work (probably need to expose them in hyperspace.i)
    types.pSpaceDroneTypes[0] = SWIG_TypeQuery(this->m_Lua, "DefenseDrone *");
    types.pSpaceDroneTypes[1] = SWIG_TypeQuery(this->m_Lua, "CombatDrone *");
    types.pSpaceDroneTypes[2] = nullptr;
    types.pSpaceDroneTypes[3] = nullptr;
    types.pSpaceDroneTypes[4] = SWIG_TypeQuery(this->m_Lua, "BoarderPodDrone *");
    types.pSpaceDroneTypes[5] = SWIG_TypeQuery(this->m_Lua, "ShipRepairDrone *");
    types.pSpaceDroneTypes[6] = SWIG_TypeQuery(this->m_Lua, "HackingDrone *");
    types.pSpaceDroneTypes[7] = SWIG_TypeQuery(this->m_Lua, "SuperShieldDrone *");

    types.pShipSystemTypes[SYS_SHIELDS] = SWIG_TypeQuery(this->m_Lua, "Shields *");
    types.pShipSystemTypes[SYS_ENGINES] = SWIG_TypeQuery(this->m_Lua, "ShipSystem *"); // todo: add EngineSystem struct and expose in lua
    types.pShipSystemTypes[SYS_OXYGEN] = SWIG_TypeQuery(this->m_Lua, "OxygenSystem *");
    types.pShipSystemTypes[SYS_WEAPONS] = SWIG_TypeQuery(this->m_Lua, "WeaponSystem *");
    types.pShipSystemTypes[SYS_DRONES] = SWIG_TypeQuery(this->m_Lua, "DroneSystem *");
    types.pShipSystemTypes[SYS_MEDBAY] = SWIG_TypeQuery(this->m_Lua, "MedbaySystem *");
    types.pShipSystemTypes[SYS_PILOT] = SWIG_TypeQuery(this->m_Lua, "ShipSystem *");
    types.pShipSystemTypes[SYS_SENSORS] = SWIG_TypeQuery(this->m_Lua, "ShipSystem *");
    types.pShipSystemTypes[SYS_DOORS] = SWIG_TypeQuery(this->m_Lua, "ShipSystem *");
    types.pShipSystemTypes[SYS_TELEPORTER] = SWIG_TypeQuery(this->m_Lua, "TeleportSystem *");
    types.pShipSystemTypes[SYS_CLOAKING] = SWIG_TypeQuery(this->m_Lua, "CloakingSystem *");
    types.pShipSystemTypes[SYS_ARTILLERY] = SWIG_TypeQuery(this->m_Lua, "ArtillerySystem *");
    types.pShipSystemTypes[SYS_BATTERY] = SWIG_TypeQuery(this->m_Lua, "BatterySystem *");
    types.pShipSystemTypes[SYS_CLONEBAY] = SWIG_TypeQuery(this->m_Lua, "CloneSystem *");
    types.pShipSystemTypes[SYS_MIND] = SWIG_TypeQuery(this->m_Lua, "MindSystem *");
    types.pShipSystemTypes[SYS_HACKING] = SWIG_TypeQuery(this->m_Lua, "HackingSystem *");
    types.pShipSystemTypes[16] = SWIG_TypeQuery(this->m_Lua, "ShipSystem *");
    types.pShipSystemTypes[17] = SWIG_TypeQuery(this->m_Lua, "ShipSystem *");
    types.pShipSystemTypes[18] = SWIG_TypeQuery(this->m_Lua, "ShipSystem *");
    types.pShipSystemTypes[19] = SWIG_TypeQuery(this->m_Lua, "ShipSystem *");
    types.pShipSystemTypes[SYS_TEMPORAL] = SWIG_TypeQuery(this->m_Lua, "ShipSystem *"); // eventually reimplement temporal as TemporalSystem class?
}

int LuaLibScript::l_on_load(lua_State* lua)
{
    luaL_argcheck(lua, lua_isfunction(lua, 1), 1, "function expected!");
    LuaFunctionRef callbackReference = luaL_ref(lua, LUA_REGISTRYINDEX);
    m_on_load_callbacks.push_back(callbackReference);
    return 0;
}

void LuaLibScript::call_on_load_callbacks()
{
    lua_State* lua = this->m_Lua;
    // Load the callback by reference number
    printf("Fetching %u on_load callbacks\n", m_on_load_callbacks.size());
    for(auto i = m_on_load_callbacks.cbegin(); i != m_on_load_callbacks.cend(); ++i)
    {
        LuaFunctionRef refL = *i;
        lua_rawgeti(lua, LUA_REGISTRYINDEX, refL);
        if(lua_pcall(lua, 0, 0, 0) != 0) {
            hs_log_file("Failed to call the callback!\n %s\n", lua_tostring(lua, -1));
            lua_pop(lua, 1);
            return;
        }
    }
}

int LuaLibScript::l_on_init(lua_State* lua)
{
    luaL_argcheck(lua, lua_isfunction(lua, 1), 1, "function expected!");
    LuaFunctionRef callbackReference = luaL_ref(lua, LUA_REGISTRYINDEX);
    m_on_init_callbacks.push_back(callbackReference);
    return 0;
}

void LuaLibScript::call_on_init_callbacks(bool newGame)
{
    lua_State* lua = this->m_Lua;
    // Load the callback by reference number
    printf("Fetching %u on_init callbacks\n", m_on_init_callbacks.size());
    for(auto i = m_on_init_callbacks.cbegin(); i != m_on_init_callbacks.cend(); ++i)
    {
        LuaFunctionRef refL = *i;
        lua_rawgeti(lua, LUA_REGISTRYINDEX, refL);
        lua_pushboolean(lua, newGame);
        if(lua_pcall(lua, 1, 0, 0) != 0) {
            hs_log_file("Failed to call the callback!\n %s\n", lua_tostring(lua, -1));
            lua_pop(lua, 1);
            return;
        }
    }
}

int LuaLibScript::l_on_game_event(lua_State* lua)
{
    luaL_argcheck(lua, lua_isstring(lua, 1), 1, "string expected!");
    luaL_argcheck(lua, lua_isboolean(lua, 2), 2, "boolean expected!");
    luaL_argcheck(lua, lua_isfunction(lua, 3), 3, "function expected!");
    const std::string eventName = std::string(lua_tostring(lua, 1));
    const bool onLoad = lua_toboolean(lua, 2);
    lua_pushvalue(lua, 3);
    LuaFunctionRef callbackReference = luaL_ref(lua, LUA_REGISTRYINDEX); // Not sure if maybe we can move this above the tostring & toboolean? Since it pops off the Lua stack anyways rather than doing the pushvalue above this.
    if(onLoad)
        m_on_game_event_loading_callbacks.emplace(eventName, callbackReference);
    else
        m_on_game_event_callbacks.emplace(eventName, callbackReference);

    return 0;
}

// TODO: Maybe tell the compiler to always inline this
void call_all_functions_from_multimap(lua_State* lua, std::multimap<std::string, LuaFunctionRef> mmap, std::string key)
{
//    if(mmap.count(key) == 0)
//        return; // No registered callbacks

    printf("Fetching %u on_game_event callbacks for %s\n", mmap.count(key), key.c_str()); // TODO: Remove or add to debugging logs?
    for(std::pair<std::multimap<std::string, LuaFunctionRef>::iterator, std::multimap<std::string, LuaFunctionRef>::iterator> range(mmap.equal_range(key)); range.first != range.second; ++range.first)
    {
        LuaFunctionRef refL = range.first->second;
        lua_rawgeti(lua, LUA_REGISTRYINDEX, refL);
        if(lua_pcall(lua, 0, 0, 0) != 0) {
            hs_log_file("Failed to call the callback for %s!\n %s\n", key.c_str(), lua_tostring(lua, -1));
            lua_pop(lua, 1);
            return;
        }
    }
}

void LuaLibScript::call_on_game_event_callbacks(std::string eventName, bool isLoading)
{
    call_all_functions_from_multimap(this->m_Lua, isLoading ? m_on_game_event_loading_callbacks : m_on_game_event_callbacks, eventName);
}

int LuaLibScript::l_on_render_event(lua_State* lua)
{
    luaL_argcheck(lua, lua_isinteger(lua, 1), 1, "integer expected!");
    luaL_argcheck(lua, lua_isfunction(lua, 2), 2, "function expected!"); // TODO: Allow one or both functions to be nil
    luaL_argcheck(lua, lua_isfunction(lua, 3), 3, "function expected!");
    const int callbackHookId = lua_tointeger(lua, 1);
    luaL_argcheck(lua, callbackHookId > RenderEvents::UNKNOWN && callbackHookId < RenderEvents::UNKNOWN_MAX, 1, "Unknown RenderEvent!");
    // TODO: Print a nice pretty message to the logs maybe if event was not a known value?
    lua_pushvalue(lua, 2);
    LuaFunctionRef callbackBeforeRef = luaL_ref(lua, LUA_REGISTRYINDEX);
    lua_pushvalue(lua, 3);
    LuaFunctionRef callbackAfterRef = luaL_ref(lua, LUA_REGISTRYINDEX);

    int priority = 0;
    if (lua_gettop(lua) >= 4)
    {
        luaL_argcheck(lua, lua_isinteger(lua, 4), 4, "integer expected!");
        priority = lua_tointeger(lua, 4);
    }

    RenderEvents::Identifiers id = static_cast<RenderEvents::Identifiers>(callbackHookId);

    std::vector<std::pair<std::pair<LuaFunctionRef, LuaFunctionRef>, int>> &vec = m_on_render_event_callbacks[id];
    vec.emplace_back(std::make_pair(callbackBeforeRef,callbackAfterRef), priority);
    std::stable_sort(vec.begin(), vec.end(),
        [](const std::pair<std::pair<LuaFunctionRef, LuaFunctionRef>, int> &a, const std::pair<std::pair<LuaFunctionRef, LuaFunctionRef>, int> &b) -> bool
        {
            return a.second > b.second; // higher priority first
        }
    );

    return 0;
}

// Pre callback calls from highest priority to lowest priority, can return chain to stop the loop, returns index of last callback called plus 1.
// If pre-empt is signalled then returns a negative index.
// Absolute value of the pre_callbacks return is passed to the post_callbacks method.
int LuaLibScript::call_on_render_event_pre_callbacks(RenderEvents::Identifiers id, int nArg)
{
    assert(id > RenderEvents::UNKNOWN);
    assert(id < RenderEvents::UNKNOWN_MAX);

    auto vecIt = m_on_render_event_callbacks.find(id);
    if (vecIt == m_on_render_event_callbacks.end()) return 0;

    std::vector<std::pair<std::pair<LuaFunctionRef, LuaFunctionRef>, int>> &vec = vecIt->second;

    unsigned int idx;
    for (idx = 0; idx < vec.size(); ++idx)
    {
        LuaFunctionRef refL = vec[idx].first.first;
        lua_rawgeti(this->m_Lua, LUA_REGISTRYINDEX, refL);
        for (int i=0; i<nArg; ++i)
        {
            lua_pushvalue(this->m_Lua, -1-nArg);
        }
        if(lua_pcall(this->m_Lua, nArg, 1, 0) != 0) {
            hs_log_file("Failed to call the before callback for RenderEvent %u!\n %s\n", id, lua_tostring(this->m_Lua, -1)); // TODO: Maybe map RenderEvents to a readable string also?
            lua_pop(this->m_Lua, 1);
            continue;
        }
        int chain;
        if (lua_isinteger(this->m_Lua, -1))
        {
            chain = lua_tointeger(this->m_Lua, -1);
        }
        else
        {
            chain = Chain::CONTINUE;
        }
        lua_pop(this->m_Lua, 1);

        if (chain != Chain::CONTINUE)
        {
            int ret = idx+1;
            return chain == Chain::PREEMPT ? -ret : ret;
        }
    }

    return idx;
}
void LuaLibScript::call_on_render_event_post_callbacks(RenderEvents::Identifiers id, int idx, int nArg)
{
    assert(id > RenderEvents::UNKNOWN);
    assert(id < RenderEvents::UNKNOWN_MAX);

    auto vecIt = m_on_render_event_callbacks.find(id);
    if (vecIt == m_on_render_event_callbacks.end()) return;

    std::vector<std::pair<std::pair<LuaFunctionRef, LuaFunctionRef>, int>> &vec = vecIt->second;

    for (--idx; idx >= 0; --idx)
    {
        LuaFunctionRef refL = vec[idx].first.second;
        lua_rawgeti(this->m_Lua, LUA_REGISTRYINDEX, refL);
        for (int i=0; i<nArg; ++i)
        {
            lua_pushvalue(this->m_Lua, -1-nArg);
        }
        if(lua_pcall(this->m_Lua, nArg, 0, 0) != 0) {
            hs_log_file("Failed to call the after callback for RenderEvent %u!\n %s\n", id, lua_tostring(this->m_Lua, -1)); // TODO: Maybe map RenderEvents to a readable string also?
            lua_pop(this->m_Lua, 1);
            continue;
        }
    }
}

int LuaLibScript::l_on_internal_event(lua_State* lua)
{
    luaL_argcheck(lua, lua_isinteger(lua, 1), 1, "integer expected!");
    luaL_argcheck(lua, lua_isfunction(lua, 2), 2, "function expected!");
    const int callbackHookId = lua_tointeger(lua, 1);
    luaL_argcheck(lua, callbackHookId > InternalEvents::UNKNOWN && callbackHookId < InternalEvents::UNKNOWN_MAX, 1, "Unknown InternalEvent!"); 
    // TODO: Print a nice pretty message to the logs maybe if event was not a known value?
    lua_pushvalue(lua, 2);
    LuaFunctionRef callbackReference = luaL_ref(lua, LUA_REGISTRYINDEX);

    int priority = 0;
    if (lua_gettop(lua) >= 3)
    {
        luaL_argcheck(lua, lua_isinteger(lua, 3), 3, "integer expected!");
        priority = lua_tointeger(lua, 3);
    }

    /*
    // TODO: Check that the number of arguments needed matches those for the internal event
    lua_Debug ar;
    lua_rawgeti(lua, LUA_REGISTRYINDEX, callbackReference);
    lua_getinfo(lua, ">u", &ar);
    printf("Registered Lua Function: that accepts '%u' arguments and is variable arguments: %s\n", ar.nparams, ar.isvararg ? "TRUE" : "FALSE");
    */

    InternalEvents::Identifiers id = static_cast<InternalEvents::Identifiers>(callbackHookId);

    std::vector<std::pair<LuaFunctionRef, int>> &vec = m_on_internal_event_callbacks[id];
    vec.emplace_back(callbackReference, priority);
    std::stable_sort(vec.begin(), vec.end(),
        [](const std::pair<LuaFunctionRef, int> &a, const std::pair<LuaFunctionRef, int> &b) -> bool
        {
            return a.second > b.second; // higher priority first
        }
    );

    return 0;
}

// TODO: This might need to be a varargs in the future to allow calling with the arguments from the hook & also passing that infromation via the enum so we can check at registration time above if the function has the correct number of arguments and if the correct number were passed here.
int LuaLibScript::call_on_internal_event_callbacks(InternalEvents::Identifiers id, int nArg, int nRet)
{
    assert(id > InternalEvents::UNKNOWN);
    assert(id < InternalEvents::UNKNOWN_MAX);

    auto vecIt = m_on_internal_event_callbacks.find(id);
    if (vecIt == m_on_internal_event_callbacks.end()) return 0;

    std::vector<std::pair<LuaFunctionRef, int>> &vec = vecIt->second;

    for (unsigned int idx = 0; idx < vec.size(); ++idx)
    {
        LuaFunctionRef refL = vec[idx].first;
        lua_rawgeti(this->m_Lua, LUA_REGISTRYINDEX, refL);
        for (int i=0; i<nArg; ++i)
        {
            lua_pushvalue(this->m_Lua, -1-nArg);
        }
        if(lua_pcall(this->m_Lua, nArg, nRet, 0) != 0) {
            hs_log_file("Failed to call the callback for InternalEvent %u!\n %s\n", id, lua_tostring(this->m_Lua, -1)); // Also TODO: Maybe map RenderEvents to a readable string also?
            lua_pop(this->m_Lua, 1);
            continue;
        }
        if (nRet > 0)
        {
            if (!lua_isnil(this->m_Lua, -nRet))
            {
                return nRet;
            }
            // If the return value is nil then we pop them before trying the next callback function
            lua_pop(this->m_Lua, nRet);
        }
    }
    return 0;
}

// version of internal event for chaining
// calling function is expected to push nArg values onto the stack
// first return value from lua function controls program flow
// Chain::CONTINUE will run the next callback
// Chain::HALT or Chain::PREEMPT will break out of the callback loop
// Remaining nRet return values will overwrite the last nRet arguments from nArg (unless nil is returned)
// bool return true if pre-empt requested
// The lua stack will be in the same configuration as when this function was called, except with argument values potentially replaced
bool LuaLibScript::call_on_internal_chain_event_callbacks(InternalEvents::Identifiers id, int nArg, int nRet)
{
    assert(id > InternalEvents::UNKNOWN);
    assert(id < InternalEvents::UNKNOWN_MAX);

    auto vecIt = m_on_internal_event_callbacks.find(id);
    if (vecIt == m_on_internal_event_callbacks.end()) return false;

    std::vector<std::pair<LuaFunctionRef, int>> &vec = vecIt->second;

    for (unsigned int idx = 0; idx < vec.size(); ++idx)
    {
        LuaFunctionRef refL = vec[idx].first;
        lua_rawgeti(this->m_Lua, LUA_REGISTRYINDEX, refL);
        for (int i=0; i<nArg; ++i)
        {
            lua_pushvalue(this->m_Lua, -1-nArg);
        }
        if(lua_pcall(this->m_Lua, nArg, nRet+1, 0) != 0) {
            // if the pcall fails then we just continue
            hs_log_file("Failed to call the callback for InternalEvent %u!\n %s\n", id, lua_tostring(this->m_Lua, -1)); // Also TODO: Maybe map RenderEvents to a readable string also?
            lua_pop(this->m_Lua, 1);
            continue;
        }
        if (nRet > 0)
        {
            for (int i=0; i<nRet; ++i)
            {
                // replace the last nRet arguments from nArg with non-nil values from nRet
                if (!lua_isnil(this->m_Lua, -1))
                {
                    lua_replace(this->m_Lua, -nRet-2);
                }
                else
                {
                    lua_pop(this->m_Lua, 1);
                }
            }
        }

        int chain;
        if (lua_isinteger(this->m_Lua, -1))
        {
            chain = lua_tointeger(this->m_Lua, -1);
        }
        else
        {
            chain = Chain::CONTINUE;
            // maybe add error handling code here? For now just silently use Chain::CONTINUE
        }
        lua_pop(this->m_Lua, 1);

        if (chain != Chain::CONTINUE)
        {
            return chain == Chain::PREEMPT;
        }
    }
    return false;
}


// TODO: This hook to kick it off, could potentially move if needed? Or maybe we should of done a singleton pattern initialized by LuaScriptInit instead of passing the object back to LuaScriptInit and getting it from the global context there?
HOOK_METHOD(AchievementTracker, LoadAchievementDescriptions, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> AchievementTracker::LoadAchievementDescriptions -> Begin (LuaLibScript.cpp)\n")
    super();
    Global::GetInstance()->getLuaContext()->getLibScript()->call_on_load_callbacks();
}

//On selecting Continue and loading up a run.
HOOK_METHOD(ScoreKeeper, LoadGame, (int fh) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ScoreKeeper::LoadGame -> Begin (LuaLibScript.cpp)\n")
    super(fh);
    Global::GetInstance()->getLuaContext()->getLibScript()->call_on_init_callbacks(false);
}
//On restarting run or starting a new run from the hanger
HOOK_METHOD(WorldManager, CreateNewGame, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> WorldManager::CreateNewGame -> Begin (LuaLibScript.cpp)\n")
    super();
    Global::GetInstance()->getLuaContext()->getLibScript()->call_on_init_callbacks(true);
}

HOOK_METHOD(WorldManager, UpdateLocation, (LocationEvent* locationEvent) -> void)
{
    LOG_HOOK("HOOK_METHOD -> WorldManager::UpdateLocation -> Begin (LuaLibScript.cpp)\n")
    printf("UpdateLocation - LocationEvent Seen, name: %s\n", locationEvent->eventName.c_str());
    Global::GetInstance()->getLuaContext()->getLibScript()->call_on_game_event_callbacks(locationEvent->eventName.c_str(), false);
    super(locationEvent);
}

HOOK_METHOD(WorldManager, CreateLocation, (Location* location) -> void)
{
    LOG_HOOK("HOOK_METHOD -> WorldManager::CreateLocation -> Begin (LuaLibScript.cpp)\n")

    std::string eventName;

    if (location->boss)
    {
        std::stringstream s;
        s << "BOSS_TEXT_" << bossShip->nextStage;

        eventName = s.str();
    }
    else
    {
        eventName = location->event->eventName;
    }

    printf("CreateLocation - LocationEvent Seen, name: %s\n", eventName.c_str());
    Global::GetInstance()->getLuaContext()->getLibScript()->call_on_game_event_callbacks(eventName.c_str(), bLoadingGame);
    super(location);
   // TODO: Also call lua scripting for entering a location? (In addition to when the event is loaded) Maybe this is like Events.OnLocation and the other is the special LocationEvent that takes a name to hook to.
}

static const struct luaL_Reg slib_funcs[] = {
   { "on_load", LuaLibScript::l_on_load },
   { "on_init", LuaLibScript::l_on_init },
   { "on_game_event", LuaLibScript::l_on_game_event },
   { "on_render_event", LuaLibScript::l_on_render_event },
   { "on_internal_event", LuaLibScript::l_on_internal_event },
   { NULL, NULL }
};

static int luaopen_scriptlib(lua_State* lua)
{
   luaL_newlib(lua, slib_funcs);
   return 1;
}

LuaLibScript::LuaLibScript(lua_State* lua)
{
   this->m_Lua = lua;
   luaL_requiref(lua, "script", luaopen_scriptlib, 1);
   lua_pop(lua, 1);
}
