#include <vector>
#include <map>
#include "LuaLibScript.h"
#include "../Global.h"

static std::vector<LuaFunctionRef> m_on_load_callbacks;
static std::vector<LuaFunctionRef> m_on_init_callbacks;
static std::multimap<std::string, LuaFunctionRef> m_on_game_event_callbacks;
static std::multimap<std::string, LuaFunctionRef> m_on_game_event_loading_callbacks;

int LuaLibScript::l_on_load(lua_State* lua)
{
    assert(lua_isfunction(lua, 1));
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
            printf("Failed to call the callback!\n %s\n", lua_tostring(lua, -1)); // TODO: Log to HS log?
            return;
        }
    }
}

int LuaLibScript::l_on_init(lua_State* lua)
{
    assert(lua_isfunction(lua, 1));
    LuaFunctionRef callbackReference = luaL_ref(lua, LUA_REGISTRYINDEX);
    m_on_init_callbacks.push_back(callbackReference);
    return 0;
}

void LuaLibScript::call_on_init_callbacks()
{
    lua_State* lua = this->m_Lua;
    // Load the callback by reference number
    printf("Fetching %u on_init callbacks\n", m_on_init_callbacks.size());
    for(auto i = m_on_init_callbacks.cbegin(); i != m_on_init_callbacks.cend(); ++i)
    {
        LuaFunctionRef refL = *i;
        lua_rawgeti(lua, LUA_REGISTRYINDEX, refL);
        if(lua_pcall(lua, 0, 0, 0) != 0) {
            printf("Failed to call the callback!\n %s\n", lua_tostring(lua, -1)); // TODO: Log to HS log?
            return;
        }
    }
}

int LuaLibScript::l_on_game_event(lua_State* lua)
{
    assert(lua_isstring(lua, 1));
    assert(lua_isboolean(lua, 2));
    assert(lua_isfunction(lua, 3));
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
    if(mmap.count(key) == 0)
        return; // No registered callbacks

    printf("Fetching %u on_game_event callbacks for %s\n", mmap.count(key), key.c_str()); // TODO: Remove or add to debugging logs?
    for(std::pair<std::multimap<std::string, LuaFunctionRef>::iterator, std::multimap<std::string, LuaFunctionRef>::iterator> range(mmap.equal_range(key)); range.first != range.second; ++range.first)
    {
        LuaFunctionRef refL = range.first->second;
        lua_rawgeti(lua, LUA_REGISTRYINDEX, refL);
        if(lua_pcall(lua, 0, 0, 0) != 0) {
            printf("Failed to call the callback for %s!\n %s\n", key.c_str(), lua_tostring(lua, -1)); // TODO: Log to HS log?
            return;
        }
    }
}

void LuaLibScript::call_on_game_event_callbacks(std::string eventName, bool isLoading)
{
    call_all_functions_from_multimap(this->m_Lua, isLoading ? m_on_game_event_loading_callbacks : m_on_game_event_callbacks, eventName);
}

// TODO: This hook to kick it off, could potentially move if needed? Or maybe we should of done a singleton pattern initialized by LuaScriptInit instead of passing the object back to LuaScriptInit and getting it from the global context there?
HOOK_METHOD(AchievementTracker, LoadAchievementDescriptions, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> AchievementTracker::LoadAchievementDescriptions -> Begin (LuaLibScript.cpp)\n")
    super();
    Global::GetInstance()->getLuaContext()->getLibScript()->call_on_load_callbacks();
}

HOOK_METHOD(ScoreKeeper, LoadGame, (int fh) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ScoreKeeper::LoadGame -> Begin (LuaLibScript.cpp)\n")
    super(fh);
    // TODO: Probably need LoadGame, Opening the ship editor & game restart hooks to all call this
    // TODO: Or maybe we can use StarMap::NewGame ?
    // TODO: Or maybe WorldManager::StartGame or WorldManager::CreateNewGame? (Note, WOrldManager::CreateNewGame might be ideal)
    Global::GetInstance()->getLuaContext()->getLibScript()->call_on_init_callbacks();
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
    printf("CreateLocation - LocationEvent Seen, name: %s\n", location->event->eventName.c_str());
    Global::GetInstance()->getLuaContext()->getLibScript()->call_on_game_event_callbacks(location->event->eventName.c_str(), Global::GetInstance()->GetWorld()->bLoadingGame);
    super(location);
   // TODO: Also call lua scripting for entering a location? (In addition to when the event is loaded) Maybe this is like Events.OnLocation and the other is the special LocationEvent that takes a name to hook to.
}

static const struct luaL_Reg slib_funcs[] = {
   { "on_load", LuaLibScript::l_on_load },
   { "on_init", LuaLibScript::l_on_init },
   { "on_game_event", LuaLibScript::l_on_game_event },
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
}
