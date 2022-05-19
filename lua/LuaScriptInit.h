#ifndef LUASCRIPTINIT_H
#define LUASCRIPTINIT_H

#include "luaInclude.h"
#include "luaDefines.h"
#include "LuaLibScript.h"
#include <string>

extern "C"
{
    int luaopen_Hyperspace(lua_State* L);
    int luaopen_Graphics(lua_State* L);
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
        
        LuaLibScript* getLibScript() { return m_libScript; };
        
        void runLuaString(std::string code);
        
        void runLuaFileFromDat(std::string filename);

    protected:

    private:
        lua_State* m_Lua; //!< Member variable "m_Lua"
        LuaLibScript* m_libScript;
        
        //friend class LuaLibScript;
};

#endif // LUASCRIPTINIT_H
