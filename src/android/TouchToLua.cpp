// Lua scripts take clicks through Hyperspace's ON_MOUSE_* events, which it raises from
// CApp's mouse handlers. FTL for iPad only gets touches, so those never fired and buttons
// that mods draw from Lua (Multiverse's speed controls and addon icons, for one) did
// nothing. This raises them for the first finger on the screen: the cursor moves to the
// touch straight away, Lua gets that frame's ON_TICK to work out what is under it (mods
// set their buttons' hover state there), then ON_MOUSE_L_BUTTON_DOWN. A touch that Lua
// takes (preempts) doesn't reach the game; the others reach it one frame later than
// before. Touches pass straight through when no script listens for clicks.

#include "Global.h"
#include "LuaLibScript.h"
#include "InternalEvents.h"
#include <deque>
#include <set>

namespace
{
    enum class TouchKind { Down, Move, Up, Cancel };

    struct HeldTouch
    {
        TouchKind kind;
        int id, x, y, initialX, initialY;
    };

    std::deque<HeldTouch> g_held;   // touches waiting for Lua's tick, in order
    std::set<int> g_takenByLua;     // touches Lua preempted; the game doesn't see them
    int g_luaTouch = -1;            // the touch moving Lua's cursor
    bool g_forwarding = false;      // handing a held touch to the game

    bool LuaWantsClicks()
    {
        auto script = Global::GetInstance()->getLuaContext()->getLibScript();
        return script->has_internal_event_callbacks(InternalEvents::ON_MOUSE_L_BUTTON_DOWN) ||
               script->has_internal_event_callbacks(InternalEvents::ON_MOUSE_L_BUTTON_UP);
    }

    // Returns true if a script preempted it
    bool LuaButton(InternalEvents::Identifiers event, Point pos)
    {
        auto context = Global::GetInstance()->getLuaContext();
        lua_pushinteger(context->GetLua(), pos.x);
        lua_pushinteger(context->GetLua(), pos.y);
        bool preempt = context->getLibScript()->call_on_internal_chain_event_callbacks(event, 2, 0);
        lua_pop(context->GetLua(), 2);
        return preempt;
    }

    void LuaCursorTo(Point pos, bool holding)
    {
        MouseControl *mouse = G_->GetMouseControl();
        Point last = mouse->position;
        mouse->lastPosition = last;
        mouse->position = pos;

        auto context = Global::GetInstance()->getLuaContext();
        lua_pushinteger(context->GetLua(), pos.x);
        lua_pushinteger(context->GetLua(), pos.y);
        lua_pushinteger(context->GetLua(), pos.x - last.x);
        lua_pushinteger(context->GetLua(), pos.y - last.y);
        lua_pushboolean(context->GetLua(), holding);
        lua_pushboolean(context->GetLua(), false);
        lua_pushboolean(context->GetLua(), false);
        context->getLibScript()->call_on_internal_chain_event_callbacks(InternalEvents::ON_MOUSE_MOVE, 7, 0);
        lua_pop(context->GetLua(), 7);
    }

    void Forward(CApp *app, const HeldTouch &t)
    {
        g_forwarding = true;
        switch (t.kind)
        {
        case TouchKind::Down: app->OnTouchDown(t.id, t.x, t.y); break;
        case TouchKind::Move: app->OnTouchMove(t.id, t.x, t.y, t.initialX, t.initialY); break;
        case TouchKind::Up: app->OnTouchUp(t.id, t.x, t.y, t.initialX, t.initialY); break;
        case TouchKind::Cancel: app->OnTouchCancel(t.id, t.x, t.y, t.initialX, t.initialY); break;
        }
        g_forwarding = false;
    }

    // A touch as it arrives: move Lua's cursor now, hold the touch for after ON_TICK
    void Hold(CApp *app, const HeldTouch &t)
    {
        if (t.kind == TouchKind::Down && g_luaTouch == -1) g_luaTouch = t.id;
        if (t.id == g_luaTouch) LuaCursorTo(app->TranslateMouse(t.x, t.y), t.kind != TouchKind::Up && t.kind != TouchKind::Cancel);
        g_held.push_back(t);
    }

    // After ON_TICK: give Lua the button events, and the game whatever Lua didn't take
    void Release(CApp *app)
    {
        while (!g_held.empty())
        {
            HeldTouch t = g_held.front();
            g_held.pop_front();
            bool luaTouch = t.id == g_luaTouch;

            if (t.kind == TouchKind::Down)
            {
                if (luaTouch && LuaButton(InternalEvents::ON_MOUSE_L_BUTTON_DOWN, app->TranslateMouse(t.x, t.y)))
                {
                    g_takenByLua.insert(t.id);
                    continue;
                }
            }
            else if (t.kind == TouchKind::Up || t.kind == TouchKind::Cancel)
            {
                if (luaTouch)
                {
                    LuaButton(InternalEvents::ON_MOUSE_L_BUTTON_UP, app->TranslateMouse(t.x, t.y));
                    g_luaTouch = -1;
                }
                if (g_takenByLua.erase(t.id)) continue;
            }
            else if (g_takenByLua.count(t.id))
            {
                continue;
            }
            Forward(app, t);
        }
    }
}

HOOK_METHOD_PRIORITY(CApp, OnTouchDown, -1000, (int id, int x, int y) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> CApp::OnTouchDown -> Begin (TouchToLua.cpp)\n")
    if (g_forwarding || (g_held.empty() && !LuaWantsClicks())) return super(id, x, y);
    Hold(this, {TouchKind::Down, id, x, y, x, y});
}

HOOK_METHOD_PRIORITY(CApp, OnTouchMove, -1000, (int id, int x, int y, int initialX, int initialY) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> CApp::OnTouchMove -> Begin (TouchToLua.cpp)\n")
    if (g_forwarding) return super(id, x, y, initialX, initialY);
    if (g_held.empty() && g_takenByLua.empty() && g_luaTouch == -1) return super(id, x, y, initialX, initialY);
    Hold(this, {TouchKind::Move, id, x, y, initialX, initialY});
}

HOOK_METHOD_PRIORITY(CApp, OnTouchUp, -1000, (int id, int x, int y, int initialX, int initialY) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> CApp::OnTouchUp -> Begin (TouchToLua.cpp)\n")
    if (g_forwarding) return super(id, x, y, initialX, initialY);
    if (g_held.empty() && g_takenByLua.empty() && g_luaTouch == -1) return super(id, x, y, initialX, initialY);
    Hold(this, {TouchKind::Up, id, x, y, initialX, initialY});
}

HOOK_METHOD_PRIORITY(CApp, OnTouchCancel, -1000, (int id, int x, int y, int initialX, int initialY) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> CApp::OnTouchCancel -> Begin (TouchToLua.cpp)\n")
    if (g_forwarding) return super(id, x, y, initialX, initialY);
    if (g_held.empty() && g_takenByLua.empty() && g_luaTouch == -1) return super(id, x, y, initialX, initialY);
    Hold(this, {TouchKind::Cancel, id, x, y, initialX, initialY});
}

// Outside lua/InternalEvents.cpp's CApp::OnLoop hook, so this runs after its ON_TICK
HOOK_METHOD_PRIORITY(CApp, OnLoop, -1000, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> CApp::OnLoop -> Begin (TouchToLua.cpp)\n")
    super();
    Release(this);
}
