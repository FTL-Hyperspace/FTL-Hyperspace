#ifndef LUAINCLUDE_H_INCLUDED
#define LUAINCLUDE_H_INCLUDED

extern "C"
{
    #include "lua.h"
    #include "lauxlib.h"
    #include "lualib.h"
}

typedef int LuaFunctionRef;

#endif // LUAINCLUDE_H_INCLUDED
