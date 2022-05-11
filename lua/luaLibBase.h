#ifndef LUALIBBASE_H
#define LUALIBBASE_H

#include "luaInclude.h"

class luaLibBase
{
    public:
        luaLibBase(lua_State* lua) : m_Lua(lua) {};
        virtual ~luaLibBase();
        virtual void initialize();

    protected:
        lua_State* m_Lua;

    private:
};

#endif // LUALIBBASE_H
