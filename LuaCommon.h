#pragma once

#include "LuaState.h"
#include "LuaFunction.h"
#include "LuaClass.h"
#include <typeinfo>

inline bool Get_Bool(int i) {return lua_toboolean(LuaState::GetCurrent(), i) != 0;}
inline void Push_Bool(bool x) {return lua_pushboolean(LuaState::GetCurrent(), (int)x);}

inline int Get_Int(int i) {return luaL_checkint(LuaState::GetCurrent(), i);}
inline int Get_Int(int i, int d) {return luaL_optint(LuaState::GetCurrent(), i, d);}
inline void Push_Int(int x) {return lua_pushinteger(LuaState::GetCurrent(), x);}

inline double Get_Float(int i) {return luaL_checknumber(LuaState::GetCurrent(), i);}
inline double Get_Float(int i, float d) {return luaL_optnumber(LuaState::GetCurrent(), i, d);}
inline void Push_Float(double x) {return lua_pushnumber(LuaState::GetCurrent(), x);}

inline const char *Get_String(int i) {return luaL_checkstring(LuaState::GetCurrent(), i);}
inline const char *Get_String(int i, const char *d) {return luaL_optstring(LuaState::GetCurrent(), i, d);}
inline void Push_String(const char *x) {return lua_pushstring(LuaState::GetCurrent(), x);}

ShipManager &Get_ShipManager(int i);
void Push_ShipManager(ShipManager *ship);
