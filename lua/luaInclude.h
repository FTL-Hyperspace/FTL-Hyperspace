#ifndef LUAINCLUDE_H_INCLUDED
#define LUAINCLUDE_H_INCLUDED

extern "C"
{
    #include "lua5.3/lua.h"
    #include "lua5.3/lauxlib.h"
    #include "lua5.3/lualib.h"
}

typedef int LuaFunctionRef;

#endif // LUAINCLUDE_H_INCLUDED
