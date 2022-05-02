#ifndef LUASCRIPTINIT_H
#define LUASCRIPTINIT_H

extern "C"
{
    #include "lua5.3/lua.h"
    #include "lua5.3/lauxlib.h"
    #include "lua5.3/lualib.h"
}

class LuaScriptInit
{
    public:
        /** Default constructor */
        LuaScriptInit();
        /** Default destructor */
        virtual ~LuaScriptInit();

        /** Access m_Lua
         * \return The current value of m_Lua
         */
        lua_State* GetLua() { return m_Lua; }
        /** Set m_Lua
         * \param val New value to set
         */
        void SetLua(lua_State* val) { m_Lua = val; }

    protected:

    private:
        lua_State* m_Lua; //!< Member variable "m_Lua"
};

#endif // LUASCRIPTINIT_H
