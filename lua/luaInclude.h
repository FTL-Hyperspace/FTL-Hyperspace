#ifndef LUAINCLUDE_H_INCLUDED
#define LUAINCLUDE_H_INCLUDED

extern "C"
{
    #include "lua.h"
    #include "lauxlib.h"
    #include "lualib.h"
}

typedef int LuaFunctionRef;

#define HS_MAKE_TABLE(pointer)\
    auto L = G_->getLuaContext()->GetLua();\
    lua_newtable(L);\
    lua_rawsetp(L, LUA_REGISTRYINDEX, pointer);\


#define HS_BREAK_TABLE(pointer)\
    auto L = G_->getLuaContext()->GetLua();\
    lua_pushnil(L);\
    lua_rawsetp(L, LUA_REGISTRYINDEX, pointer);\ 


#endif // LUAINCLUDE_H_INCLUDED
