#include "Global.h"
#include "LuaLibScript.h"
#include "InternalEvents.h"
#include "swigluarun.h"

#include <stack>

/** All the hook code for the various InternalEvents belongs here **/

HOOK_METHOD(CApp, OnLoop, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CApp::OnLoop -> Begin (InternalEvents.cpp)\n")
    super();
    Global::GetInstance()->getLuaContext()->getLibScript()->call_on_internal_event_callbacks(InternalEvents::ON_TICK);
}

HOOK_METHOD(MainMenu, Open, () -> bool)
{
    LOG_HOOK("HOOK_METHOD -> MainMenu::Open -> Begin (InternalEvents.cpp)\n")
    bool ret = super();
    Global::GetInstance()->getLuaContext()->getLibScript()->call_on_internal_event_callbacks(InternalEvents::MAIN_MENU);
    return ret;
}

HOOK_METHOD(SpaceManager, DangerousEnvironment, () -> bool)
{
    LOG_HOOK("HOOK_METHOD -> SpaceManager::DangerousEnvironment -> Begin (InternalEvents.cpp)\n")

    auto context = Global::GetInstance()->getLuaContext();
    bool res = super();

    lua_pushboolean(context->GetLua(), res);
    if (context->getLibScript()->call_on_internal_event_callbacks(InternalEvents::DANGEROUS_ENVIRONMENT, 1, 1) == 1)
    {
        res = lua_toboolean(context->GetLua(), -1);
        lua_pop(context->GetLua(), 2);
    }
    else // No return from callback
    {
        lua_pop(context->GetLua(), 1);
    }

    return res;
}

static std::string g_customHazardText = "";
HOOK_METHOD_PRIORITY(StarMap, GetLocationText, -100, (const Location* loc) -> std::string)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> StarMap::GetLocationText -> Begin (InternalEvents.cpp)\n")

    auto context = Global::GetInstance()->getLuaContext();

    SWIG_NewPointerObj(context->GetLua(), loc, context->getLibScript()->types.pLocation, 0);
    if (context->getLibScript()->call_on_internal_event_callbacks(InternalEvents::GET_BEACON_HAZARD, 1, 1) == 1 && lua_isstring(context->GetLua(), -1))
    {
        int originalEnv = loc->event->environment;
        g_customHazardText = lua_tostring(context->GetLua(), -1);
        loc->event->environment = 1;
        std::string ret = super(loc);
        loc->event->environment = originalEnv;
        g_customHazardText = "";
        lua_pop(context->GetLua(), 2);
        return ret;
    }
    else // No return from callback
    {
        lua_pop(context->GetLua(), 1);
        return super(loc);
    }
}
HOOK_METHOD(TextLibrary, GetText, (const std::string& name, const std::string& lang) -> std::string)
{
    LOG_HOOK("HOOK_METHOD -> TextLibrary::GetText -> Begin (InternalEvents.cpp)\n")
    return (!g_customHazardText.empty() && name == "map_asteroid_loc") ? g_customHazardText : super(name, lang);
}
HOOK_METHOD(StarMap, OnRender, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> StarMap::OnRender -> Begin (InternalEvents.cpp)\n")

    auto context = Global::GetInstance()->getLuaContext();

    std::stack<std::pair<int, int>> originalEnvs;
    for (int i = 0; i < locations.size(); ++i)
    {
        Location *loc = locations[i];

        SWIG_NewPointerObj(context->GetLua(), loc, context->getLibScript()->types.pLocation, 0);
        if (context->getLibScript()->call_on_internal_event_callbacks(InternalEvents::GET_BEACON_HAZARD, 1, 1) == 1)
        {
            originalEnvs.push({i, loc->event->environment});
            loc->event->environment = 1;
            lua_pop(context->GetLua(), 2);
        }
        else // No return from callback
        {
            lua_pop(context->GetLua(), 1);
        }

    }

    super();

    while (!originalEnvs.empty())
    {
        locations[originalEnvs.top().first]->event->environment = originalEnvs.top().second;
        originalEnvs.pop();
    }
}

static GL_Color g_flashColor = GL_Color(0.f, 0.f, 0.f, 0.f);
HOOK_METHOD(SpaceManager, GetFlashOpacity, () -> float)
{
    LOG_HOOK("HOOK_METHOD -> SpaceManager::GetFlashOpacity -> Begin (InternalEvents.cpp)\n")

    auto context = Global::GetInstance()->getLuaContext();

    float opacity = super();
    lua_pushnumber(context->GetLua(), opacity);
    if (context->getLibScript()->call_on_internal_event_callbacks(InternalEvents::GET_HAZARD_FLASH, 1, 4) == 4)
    {
        g_flashColor.r = lua_tonumber(context->GetLua(), -4);
        g_flashColor.g = lua_tonumber(context->GetLua(), -3);
        g_flashColor.b = lua_tonumber(context->GetLua(), -2);
        g_flashColor.a = lua_tonumber(context->GetLua(), -1);
        opacity = g_flashColor.a;
        lua_pop(context->GetLua(), 5);
    }
    else // No return from callback
    {
        lua_pop(context->GetLua(), 1);
    }

    return opacity;
}
HOOK_STATIC(CSurface, GL_RenderPrimitiveWithColor, (GL_Primitive *primitive, GL_Color color) -> void)
{
    LOG_HOOK("HOOK_STATIC -> CSurface::GL_RenderPrimitiveWithColor -> Begin (InternalEvents.cpp)\n")

    if (g_flashColor.a > 0.f)
    {
        g_flashColor.a = color.a;
        super(primitive, g_flashColor);
        g_flashColor.a = 0.f;
    }
    else
    {
        super(primitive, color);
    }
}

HOOK_METHOD(CApp, OnKeyDown, (SDLKey key) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CApp::OnKeyDown -> Begin (InternalEvents.cpp)\n")

    auto context = Global::GetInstance()->getLuaContext();

    lua_pushinteger(context->GetLua(), key);
    bool preempt = context->getLibScript()->call_on_internal_chain_event_callbacks(InternalEvents::ON_KEY_DOWN, 1, 0);
    lua_pop(context->GetLua(), 1);

    if (!preempt) super(key);
}

HOOK_METHOD(CApp, OnKeyUp, (SDLKey key) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CApp::OnKeyUp -> Begin (InternalEvents.cpp)\n")

    auto context = Global::GetInstance()->getLuaContext();

    lua_pushinteger(context->GetLua(), key);
    bool preempt = context->getLibScript()->call_on_internal_chain_event_callbacks(InternalEvents::ON_KEY_UP, 1, 0);
    lua_pop(context->GetLua(), 1);

    if (!preempt) super(key);
}

HOOK_METHOD(CApp, OnMouseMove, (int x, int y, int xdiff, int ydiff, bool holdingLMB, bool holdingRMB, bool holdingMMB) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CApp::OnMouseMove -> Begin (InternalEvents.cpp)\n")

    auto context = Global::GetInstance()->getLuaContext();

    lua_pushinteger(context->GetLua(), x);
    lua_pushinteger(context->GetLua(), y);
    lua_pushinteger(context->GetLua(), xdiff);
    lua_pushinteger(context->GetLua(), ydiff);
    lua_pushboolean(context->GetLua(), holdingLMB);
    lua_pushboolean(context->GetLua(), holdingRMB);
    lua_pushboolean(context->GetLua(), holdingMMB);
    bool preempt = context->getLibScript()->call_on_internal_chain_event_callbacks(InternalEvents::ON_MOUSE_MOVE, 7, 0);
    lua_pop(context->GetLua(), 7);

    if (!preempt) super(x, y, xdiff, ydiff, holdingLMB, holdingRMB, holdingMMB);
}

HOOK_METHOD(CApp, OnLButtonDown, (int x, int y) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CApp::OnLButtonDown -> Begin (InternalEvents.cpp)\n")

    auto context = Global::GetInstance()->getLuaContext();

    lua_pushinteger(context->GetLua(), x);
    lua_pushinteger(context->GetLua(), y);
    bool preempt = context->getLibScript()->call_on_internal_chain_event_callbacks(InternalEvents::ON_MOUSE_L_BUTTON_DOWN, 2, 0);
    lua_pop(context->GetLua(), 2);

    if (!preempt) super(x, y);
}

HOOK_METHOD(CApp, OnLButtonUp, (int x, int y) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CApp::OnLButtonUp -> Begin (InternalEvents.cpp)\n")

    auto context = Global::GetInstance()->getLuaContext();

    lua_pushinteger(context->GetLua(), x);
    lua_pushinteger(context->GetLua(), y);
    bool preempt = context->getLibScript()->call_on_internal_chain_event_callbacks(InternalEvents::ON_MOUSE_L_BUTTON_UP, 2, 0);
    lua_pop(context->GetLua(), 2);

    if (!preempt) super(x, y);
}

HOOK_METHOD(CApp, OnRButtonDown, (int x, int y) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CApp::OnRButtonDown -> Begin (InternalEvents.cpp)\n")

    auto context = Global::GetInstance()->getLuaContext();

    lua_pushinteger(context->GetLua(), x);
    lua_pushinteger(context->GetLua(), y);
    bool preempt = context->getLibScript()->call_on_internal_chain_event_callbacks(InternalEvents::ON_MOUSE_R_BUTTON_DOWN, 2, 0);
    lua_pop(context->GetLua(), 2);

    if (!preempt) super(x, y);
}

HOOK_METHOD_PRIORITY(CApp, OnRButtonUp, -100, (int x, int y) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> CApp::OnRButtonUp -> Begin (InternalEvents.cpp)\n")

    auto context = Global::GetInstance()->getLuaContext();

    lua_pushinteger(context->GetLua(), x);
    lua_pushinteger(context->GetLua(), y);
    bool preempt = context->getLibScript()->call_on_internal_chain_event_callbacks(InternalEvents::ON_MOUSE_R_BUTTON_UP, 2, 0);
    lua_pop(context->GetLua(), 2);

    if (!preempt) super(x, y);
}

HOOK_METHOD(CApp, OnMButtonDown, (int x, int y) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CApp::OnMButtonDown -> Begin (InternalEvents.cpp)\n")

    auto context = Global::GetInstance()->getLuaContext();

    lua_pushinteger(context->GetLua(), x);
    lua_pushinteger(context->GetLua(), y);
    bool preempt = context->getLibScript()->call_on_internal_chain_event_callbacks(InternalEvents::ON_MOUSE_M_BUTTON_DOWN, 2, 0);
    lua_pop(context->GetLua(), 2);

    if (!preempt) super(x, y);
}

HOOK_METHOD_PRIORITY(CrewMember, OnLoop, -100, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> CrewMember::OnLoop -> Begin (InternalEvents.cpp)\n")

    super();

    auto context = Global::GetInstance()->getLuaContext();

    SWIG_NewPointerObj(context->GetLua(), this, context->getLibScript()->types.pCrewMember, 0);
    context->getLibScript()->call_on_internal_event_callbacks(InternalEvents::CREW_LOOP, 1);
    lua_pop(context->GetLua(), 1);
}
//Priority was necessary to make this run after the hook for calculating stuff with additionalPowerLoss, so user can do stuff like modify that for weapon effects here.
HOOK_METHOD_PRIORITY(ShipManager, OnLoop, -100, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> ShipManager::OnLoop -> Begin (InternalEvents.cpp)\n")
    super();

    auto context = G_->getLuaContext();
    SWIG_NewPointerObj(context->GetLua(), this, context->getLibScript()->types.pShipManager, 0);
    context->getLibScript()->call_on_internal_event_callbacks(InternalEvents::SHIP_LOOP, 1);
    lua_pop(context->GetLua(), 1);
}

HOOK_METHOD_PRIORITY(WeaponControl, SelectArmament, -100, (unsigned int armamentSlot) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> WeaponControl::SelectArmament -> Begin (InternalEvents.cpp)\n")

    auto context = Global::GetInstance()->getLuaContext();

    lua_pushinteger(context->GetLua(), armamentSlot);
    bool preempt = context->getLibScript()->call_on_internal_chain_event_callbacks(InternalEvents::SELECT_ARMAMENT_PRE, 1, 1);
    if (lua_isnumber(context->GetLua(), -1))
    {
        armamentSlot = static_cast<unsigned int>(lua_tonumber(context->GetLua(), -1));
        if (armamentSlot >= boxes.size() || armamentSlot < 0 || boxes[armamentSlot]->Empty()) preempt = true;
    }
    lua_pop(context->GetLua(), 1);

    if (!preempt) {
        super(armamentSlot);

        lua_pushinteger(context->GetLua(), armamentSlot);
        context->getLibScript()->call_on_internal_chain_event_callbacks(InternalEvents::SELECT_ARMAMENT_POST, 1, 0);
        lua_pop(context->GetLua(), 1);
    }
}

//Priority to run after callback in CustomDrones.cpp
HOOK_METHOD_PRIORITY(SpaceDrone, GetNextProjectile, -100, () -> Projectile*)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> SpaceDrone::GetNextProjectile -> Begin (InternalEvents.cpp)\n")

    Projectile* ret = super();
    if (ret != nullptr)
    {
        auto context = G_->getLuaContext();
        SWIG_NewPointerObj(context->GetLua(), ret, context->getLibScript()->types.pProjectile[ret->GetType()], 0);
        SWIG_NewPointerObj(context->GetLua(), this, context->getLibScript()->types.pSpaceDroneTypes[this->type], 0);
        bool preempt = context->getLibScript()->call_on_internal_chain_event_callbacks(InternalEvents::DRONE_FIRE, 2, 0);
        lua_pop(context->GetLua(), 2);
        //preempt prevents projectile from firing
        if (preempt)
        {
            delete ret;
            return nullptr;
        }
    }
    return ret;
}

HOOK_METHOD(ShipManager, GetDodgeFactor, () -> int)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::GetDodgeFactor -> Begin (InternalEvents.cpp)\n")
    int ret = super();

    auto context = G_->getLuaContext();
    SWIG_NewPointerObj(context->GetLua(), this, context->getLibScript()->types.pShipManager, 0);
    lua_pushinteger(context->GetLua(), ret);
    context->getLibScript()->call_on_internal_chain_event_callbacks(InternalEvents::GET_DODGE_FACTOR, 2, 1);
    if (lua_isnumber(context->GetLua(), -1)) //Round floats and account for values like 1.0
    {
        ret = static_cast<int>(lua_tonumber(context->GetLua(), -1));
    }
    lua_pop(context->GetLua(), 2);
    return ret;
}

HOOK_METHOD(ShipSystem, SetBonusPower, (int amount, int permanentPower) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipSystem::SetBonusPower -> Begin (InternalEvents.cpp)\n")

    auto context = G_->getLuaContext();
    SWIG_NewPointerObj(context->GetLua(), this, context->getLibScript()->types.pShipSystem, 0);
    lua_pushinteger(context->GetLua(), amount);
    bool preempt = context->getLibScript()->call_on_internal_chain_event_callbacks(InternalEvents::SET_BONUS_POWER, 2, 1);
    if (lua_isnumber(context->GetLua(), -1)) amount = static_cast<int>(lua_tonumber(context->GetLua(), -1));
    lua_pop(context->GetLua(), 2);

    if (!preempt) super(amount, permanentPower);
}
HOOK_METHOD(WeaponSystem, SetBonusPower, (int amount, int permanentPower) -> void)
{
    LOG_HOOK("HOOK_METHOD -> WeaponSystem::SetBonusPower -> Begin (InternalEvents.cpp)\n")

    auto context = G_->getLuaContext();
    SWIG_NewPointerObj(context->GetLua(), this, context->getLibScript()->types.pWeaponSystem, 0);
    lua_pushinteger(context->GetLua(), amount);
    bool preempt = context->getLibScript()->call_on_internal_chain_event_callbacks(InternalEvents::SET_BONUS_POWER, 2, 1);
    if (lua_isnumber(context->GetLua(), -1)) amount = static_cast<int>(lua_tonumber(context->GetLua(), -1));
    lua_pop(context->GetLua(), 2);

    if (!preempt) super(amount, permanentPower);
}
HOOK_METHOD(DroneSystem, SetBonusPower, (int amount, int permanentPower) -> void)
{
    LOG_HOOK("HOOK_METHOD -> DroneSystem::SetBonusPower -> Begin (InternalEvents.cpp)\n")

    auto context = G_->getLuaContext();
    SWIG_NewPointerObj(context->GetLua(), this, context->getLibScript()->types.pDroneSystem, 0);
    lua_pushinteger(context->GetLua(), amount);
    bool preempt = context->getLibScript()->call_on_internal_chain_event_callbacks(InternalEvents::SET_BONUS_POWER, 2, 1);
    if (lua_isnumber(context->GetLua(), -1)) amount = static_cast<int>(lua_tonumber(context->GetLua(), -1));
    lua_pop(context->GetLua(), 2);

    if (!preempt) super(amount, permanentPower);
}

static bool inArtilleryLoop = false;
HOOK_METHOD(ArtillerySystem, OnLoop, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ArtillerySystem::OnLoop -> Begin (InternalEvents.cpp)\n")

    inArtilleryLoop = true;
    super();
    inArtilleryLoop = false;
}
HOOK_METHOD(ProjectileFactory, SetCooldownModifier, (float mod) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ProjectileFactory::SetCooldownModifier -> Begin (InternalEvents.cpp)\n")

    auto context = G_->getLuaContext();
    SWIG_NewPointerObj(context->GetLua(), this, context->getLibScript()->types.pProjectileFactory, 0);
    lua_pushnumber(context->GetLua(), mod);
    lua_pushboolean(context->GetLua(), inArtilleryLoop);
    bool preempt = context->getLibScript()->call_on_internal_chain_event_callbacks(InternalEvents::WEAPON_COOLDOWN_MOD, 3, 1);
    if (lua_isnumber(context->GetLua(), -1))
    {
        mod = std::max(0.f, static_cast<float>(lua_tonumber(context->GetLua(), -1)));
        if (!inArtilleryLoop)
        {
            mod = std::min(mod, 1.f);
        }
    }
    lua_pop(context->GetLua(), 3);

    if (!preempt) super(mod);
}

HOOK_METHOD(ShipManager, JumpArrive, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::JumpArrive -> Begin (InternalEvents.cpp)\n")
    super();
    auto context = G_->getLuaContext();
    SWIG_NewPointerObj(context->GetLua(), this, context->getLibScript()->types.pShipManager, 0);
    context->getLibScript()->call_on_internal_event_callbacks(InternalEvents::JUMP_ARRIVE, 1);
    lua_pop(context->GetLua(), 1);
}

HOOK_METHOD(ShipManager, JumpLeave, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::JumpLeave -> Begin (InternalEvents.cpp)\n")
    super();
    auto context = G_->getLuaContext();
    SWIG_NewPointerObj(context->GetLua(), this, context->getLibScript()->types.pShipManager, 0);
    context->getLibScript()->call_on_internal_event_callbacks(InternalEvents::JUMP_LEAVE, 1);
    lua_pop(context->GetLua(), 1);
}
//To be used for button MouseMove functions as to create proper beep sounds and mouse pointer animation changes.
HOOK_METHOD(CommandGui, MouseMove, (int mX, int mY) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CommandGui::MouseMove -> Begin (InternalEvents.cpp)\n")
    auto context = Global::GetInstance()->getLuaContext();
    lua_pushinteger(context->GetLua(), mX);
    lua_pushinteger(context->GetLua(), mY);
    bool preempt = context->getLibScript()->call_on_internal_chain_event_callbacks(InternalEvents::GUI_MOUSE_MOVE, 2, 0);
    lua_pop(context->GetLua(), 2);

    if (!preempt) super(mX, mY);
}

HOOK_METHOD(ShipManager, Wait, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::Wait -> Begin (InternalEvents.cpp)\n")
    super();
    auto context = G_->getLuaContext();
    SWIG_NewPointerObj(context->GetLua(), this, context->getLibScript()->types.pShipManager, 0);
    context->getLibScript()->call_on_internal_event_callbacks(InternalEvents::ON_WAIT, 1);
    lua_pop(context->GetLua(), 1);
}

HOOK_METHOD(SystemBox, MouseMove, (int x, int y) -> void)
{
    LOG_HOOK("HOOK_METHOD -> SystemBox::MouseMove -> Begin (InternalEvents.cpp)\n")
    auto context = Global::GetInstance()->getLuaContext();

    SWIG_NewPointerObj(context->GetLua(), this, context->getLibScript()->types.pSystemBox, 0);
    //Coordinates are relative to the SystemBox
    lua_pushinteger(context->GetLua(), x - location.x);
    lua_pushinteger(context->GetLua(), y - location.y);
    bool preempt = context->getLibScript()->call_on_internal_chain_event_callbacks(InternalEvents::SYSTEM_BOX_MOUSE_MOVE, 3, 0);

    lua_pop(context->GetLua(), 3);

    if (!preempt) super(x, y);
}
//NOTE: Return seems to indicate if the click was successful, so it will be false if preempted. If this needs to be true in some preempt cases allow user to optionally provide their own return value.
HOOK_METHOD(SystemBox, MouseClick, (bool shift) -> bool)
{
    LOG_HOOK("HOOK_METHOD -> SystemBox::MouseClick -> Begin (InternalEvents.cpp)\n")
    auto context = Global::GetInstance()->getLuaContext();

    SWIG_NewPointerObj(context->GetLua(), this, context->getLibScript()->types.pSystemBox, 0);
    lua_pushboolean(context->GetLua(), shift);
    bool preempt = context->getLibScript()->call_on_internal_chain_event_callbacks(InternalEvents::SYSTEM_BOX_MOUSE_CLICK, 2, 0);

    lua_pop(context->GetLua(), 2);
    if (!preempt) return super(shift);
    else return false;
}
HOOK_METHOD(SystemBox, KeyDown, (SDLKey key, bool shift) -> void)
{
    LOG_HOOK("HOOK_METHOD -> SystemBox::KeyDown -> Begin (InternalEvents.cpp)\n")
    auto context = Global::GetInstance()->getLuaContext();

    SWIG_NewPointerObj(context->GetLua(), this, context->getLibScript()->types.pSystemBox, 0);
    lua_pushinteger(context->GetLua(), key);
    lua_pushboolean(context->GetLua(), shift);
    bool preempt = context->getLibScript()->call_on_internal_chain_event_callbacks(InternalEvents::SYSTEM_BOX_KEY_DOWN, 3, 0);

    lua_pop(context->GetLua(), 3);
    if (!preempt) super(key, shift);
}
//Might make more sense for this to be structured to have one function per custom system id but we'll use regular callbacks for now
HOOK_STATIC(ShipSystem, GetLevelDescription, (int systemId, int level, bool tooltip) -> std::string)
{
    LOG_HOOK("HOOK_STATIC -> ShipSystem::GetLevelDescription -> Begin (InternalEvents.cpp)\n")

    auto context = Global::GetInstance()->getLuaContext();

    lua_pushinteger(context->GetLua(), systemId);
    lua_pushinteger(context->GetLua(), level + 1); //Push true level
    lua_pushboolean(context->GetLua(), tooltip);
    if (context->getLibScript()->call_on_internal_event_callbacks(InternalEvents::GET_LEVEL_DESCRIPTION, 3, 1) == 1 && lua_isstring(context->GetLua(), -1))
    {
        std::string ret = lua_tostring(context->GetLua(), -1);
        lua_pop(context->GetLua(), 4);
        return ret;
    }
    else // No return from callback
    {
        lua_pop(context->GetLua(), 3);
        return super(systemId, level, tooltip);
    }
}
