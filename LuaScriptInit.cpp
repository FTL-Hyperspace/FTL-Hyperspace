#include "LuaScriptInit.h"
#include <string>

std::string luaTest = "print(\"hello\")\nfunction helloWorld()\n\tprint(\"Hello World\")\nend\n";

LuaScriptInit::LuaScriptInit()
{
    printf("Initializing Lua\n");
    lua_State* lua = luaL_newstate(); // Open Lua
    this->SetLua(lua);
    luaL_openlibs(lua); // Load Lua libraries
    // TODO: Figure out how to unload and/or replace certain library functions (like math.random!, threads! & other things unsafe for a single-threaded deterministic environment)
    printf("Loading Lua string\n");
    int iErr = 0;
    if((iErr = luaL_loadbuffer(lua, luaTest.c_str(), luaTest.size(), "=luaTest")) != 0)
    {
        printf("Lua loadbuffer error\n");
    }
    else
    {    
        // call Lua's Main from the script (note: still need to load script before this)
        if((iErr = lua_pcall(lua, 0, LUA_MULTRET, 0)) == 0)
        {
            lua_getglobal(lua, "helloWorld");
            lua_pcall(lua, 0, 0, 0); // Call function (pop's from stack name + arguments but we say no arguments and no returns here)
        }
        else
        {
            printf("Lua pcall error\n");
            printf(lua_tostring(lua, -1));
            printf("\n");
            lua_pop(lua, 1);
        }
    }
    printf("Lua initialized!\n");
}

LuaScriptInit::~LuaScriptInit()
{
    printf("Lua destruct\n");
    lua_State* lua = this->GetLua();
    lua_close(lua);
    this->SetLua(nullptr);
    printf("Lua destroyed\n");
}

// TODO: Math.random must be reimplemented to be based on FTL's internal random state/seed
// TODO: See other things Factorio decided to disable in Lua (like threads) because they're a problem for determinism
// TODO: Disable os.execute & io.write & other potentially dangerous interactions with the system.

/*
int LuaState::DoString(const std::string &str, bool protect)
{
	g_CurrentLua = this;

	int err = luaL_loadbuffer(this, str.c_str(), str.length(), "=lua_run");
	if(err != 0)
	{
		if(err > 0)
		{
			PrintError(lua_tostring(this, -1));
			lua_pop(this, 1);
		}
		return err;
	}

	if(protect)
	{
		if(err = lua_pcall(this, 0, LUA_MULTRET, 0))
		{
			PrintError(lua_tostring(this, -1));
			lua_pop(this, 1);
			return err;
		}
	}
	else
		lua_call(this, 0, LUA_MULTRET);

	return 0;
}
*/
