#include "Global.h"
#include "LuaLibScript.h"
#include "InternalEvents.h"
#include "android/HyperspaceHost.h"
#include <atomic>
#include <deque>
#include <mutex>
#include <set>
#include <vector>

enum class TouchKind { Down, Move, Up, Cancel, RightDown, RightUp };

struct HeldTouch
{
    TouchKind kind;
    int id, x, y, initialX, initialY;
    bool ticked;
};

static std::deque<HeldTouch> g_held;
static std::set<int> g_takenByLua;
static int g_luaTouch = -1;
static bool g_forwarding = false;
static bool g_luaTick = false;
static bool g_onLuaButton = false;

struct RightButtonEvent
{
    int action, x, y;
};
static std::mutex g_rightLock;
static std::vector<RightButtonEvent> g_rightQueue;
static std::atomic<bool> g_luaWantsRight{false};

static bool LuaWantsRightClicks()
{
    auto script = Global::GetInstance()->getLuaContext()->getLibScript();
    return script->has_internal_event_callbacks(InternalEvents::ON_MOUSE_R_BUTTON_DOWN) ||
           script->has_internal_event_callbacks(InternalEvents::ON_MOUSE_R_BUTTON_UP);
}

static bool LuaWantsClicks()
{
    auto script = Global::GetInstance()->getLuaContext()->getLibScript();
    return script->has_internal_event_callbacks(InternalEvents::ON_MOUSE_L_BUTTON_DOWN) ||
           script->has_internal_event_callbacks(InternalEvents::ON_MOUSE_L_BUTTON_UP);
}

static bool LuaButton(InternalEvents::Identifiers event, Point pos)
{
    auto context = Global::GetInstance()->getLuaContext();
    lua_pushinteger(context->GetLua(), pos.x);
    lua_pushinteger(context->GetLua(), pos.y);
    bool preempt = context->getLibScript()->call_on_internal_chain_event_callbacks(event, 2, 0);
    lua_pop(context->GetLua(), 2);
    return preempt;
}

static void LuaCursorTo(Point pos, bool holdingLeft, bool holdingRight = false)
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
    lua_pushboolean(context->GetLua(), holdingLeft);
    lua_pushboolean(context->GetLua(), holdingRight);
    lua_pushboolean(context->GetLua(), false);
    context->getLibScript()->call_on_internal_chain_event_callbacks(InternalEvents::ON_MOUSE_MOVE, 7, 0);
    lua_pop(context->GetLua(), 7);
}

static void Forward(CApp *app, const HeldTouch &t)
{
    g_forwarding = true;
    switch (t.kind)
    {
    case TouchKind::Down: app->OnTouchDown(t.id, t.x, t.y); break;
    case TouchKind::Move: app->OnTouchMove(t.id, t.x, t.y, t.initialX, t.initialY); break;
    case TouchKind::Up: app->OnTouchUp(t.id, t.x, t.y, t.initialX, t.initialY); break;
    case TouchKind::Cancel: app->OnTouchCancel(t.id, t.x, t.y, t.initialX, t.initialY); break;
    case TouchKind::RightDown: case TouchKind::RightUp: break;
    }
    g_forwarding = false;
}

static void Hold(CApp *app, const HeldTouch &t)
{
    if (t.kind == TouchKind::Down && g_luaTouch == -1) g_luaTouch = t.id;
    if (t.id == g_luaTouch) LuaCursorTo(app->TranslateMouse(t.x, t.y), t.kind != TouchKind::Up && t.kind != TouchKind::Cancel);
    g_held.push_back(t);
}

static void Release(CApp *app)
{
    while (!g_held.empty() && g_held.front().ticked)
    {
        HeldTouch t = g_held.front();
        g_held.pop_front();
        if (t.kind == TouchKind::RightDown || t.kind == TouchKind::RightUp)
        {
            LuaButton(t.kind == TouchKind::RightDown ? InternalEvents::ON_MOUSE_R_BUTTON_DOWN : InternalEvents::ON_MOUSE_R_BUTTON_UP,
                      app->TranslateMouse(t.x, t.y));
            continue;
        }
        bool luaTouch = t.id == g_luaTouch;

        if (t.kind == TouchKind::Down)
        {
            if (luaTouch && (LuaButton(InternalEvents::ON_MOUSE_L_BUTTON_DOWN, app->TranslateMouse(t.x, t.y)) || g_onLuaButton))
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

HOOK_METHOD_PRIORITY(CApp, OnTouchDown, -1000, (int id, int x, int y) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> CApp::OnTouchDown -> Begin (TouchToLua.cpp)\n")
    if (g_forwarding || (g_held.empty() && !LuaWantsClicks())) return super(id, x, y);
    Hold(this, {TouchKind::Down, id, x, y, x, y, false});
}

HOOK_METHOD_PRIORITY(CApp, OnTouchMove, -1000, (int id, int x, int y, int initialX, int initialY) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> CApp::OnTouchMove -> Begin (TouchToLua.cpp)\n")
    if (g_forwarding) return super(id, x, y, initialX, initialY);
    if (g_held.empty() && g_takenByLua.empty() && g_luaTouch == -1) return super(id, x, y, initialX, initialY);
    Hold(this, {TouchKind::Move, id, x, y, initialX, initialY, false});
}

HOOK_METHOD_PRIORITY(CApp, OnTouchUp, -1000, (int id, int x, int y, int initialX, int initialY) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> CApp::OnTouchUp -> Begin (TouchToLua.cpp)\n")
    if (g_forwarding) return super(id, x, y, initialX, initialY);
    if (g_held.empty() && g_takenByLua.empty() && g_luaTouch == -1) return super(id, x, y, initialX, initialY);
    Hold(this, {TouchKind::Up, id, x, y, initialX, initialY, false});
}

HOOK_METHOD_PRIORITY(CApp, OnTouchCancel, -1000, (int id, int x, int y, int initialX, int initialY) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> CApp::OnTouchCancel -> Begin (TouchToLua.cpp)\n")
    if (g_forwarding) return super(id, x, y, initialX, initialY);
    if (g_held.empty() && g_takenByLua.empty() && g_luaTouch == -1) return super(id, x, y, initialX, initialY);
    Hold(this, {TouchKind::Cancel, id, x, y, initialX, initialY, false});
}

extern "C" __attribute__((visibility("default"))) int hs_android_wants_right_click(void)
{
    return g_luaWantsRight.load();
}

extern "C" __attribute__((visibility("default"))) void hs_android_right_button(int action, int x, int y)
{
    std::lock_guard<std::mutex> lock(g_rightLock);
    g_rightQueue.push_back({action, x, y});
}

static void TakeRightButtonEvents(CApp *app)
{
    std::vector<RightButtonEvent> events;
    {
        std::lock_guard<std::mutex> lock(g_rightLock);
        events.swap(g_rightQueue);
    }
    for (const RightButtonEvent &e : events)
    {
        LuaCursorTo(app->TranslateMouse(e.x, e.y), false, e.action != HS_RIGHT_BUTTON_DOWN);
        if (e.action == HS_RIGHT_BUTTON_MOVE) continue;
        g_held.push_back({e.action == HS_RIGHT_BUTTON_DOWN ? TouchKind::RightDown : TouchKind::RightUp, -1, e.x, e.y, e.x, e.y, false});
    }
}

HOOK_METHOD_PRIORITY(CApp, OnLoop, -1000, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> CApp::OnLoop -> Begin (TouchToLua.cpp)\n")
    g_luaWantsRight = LuaWantsRightClicks();
    TakeRightButtonEvents(this);
    Release(this);
    g_onLuaButton = false;
    super();
    g_luaTick = false;
    for (HeldTouch &t : g_held) t.ticked = true;
}

HOOK_METHOD_PRIORITY(CApp, OnLoop, 1000, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> CApp::OnLoop -> Begin (TouchToLua.cpp)\n")
    g_luaTick = false;
    super();
    g_luaTick = true;
}

HOOK_METHOD(GenericButton, MouseMove, (int x, int y, bool silent) -> void)
{
    LOG_HOOK("HOOK_METHOD -> GenericButton::MouseMove -> Begin (TouchToLua.cpp)\n")
    super(x, y, silent);
    if (g_luaTick && g_luaTouch != -1 && bHover)
    {
        Point cursor = G_->GetMouseControl()->position;
        if (x == cursor.x && y == cursor.y) g_onLuaButton = true;
    }
}
