#include "LuaState.h"
#include "LuaFunction.h"
#include "LuaClass.h"
#include "Global.h"
#include "FilePath.h"

#define HOOKCALL_REF -1

#define LUAPATH "lua/"

LuaState *g_Lua = NULL;
LuaState *g_CurrentLua = NULL;

extern void LoadLuaEnums();

LuaState::LuaState()
{
	luaL_openlibs(this);

	lua_pushnil(this);
	lua_setglobal(this, "os");
	lua_pushnil(this);
	lua_setglobal(this, "package");

	LuaClass::LoadAll(this);
	LuaFunction::LoadAll(this);
	DoFile(LUAPATH "init.lua");

	lua_getglobal(this, "hook");
	lua_getfield(this, -1, "Call");
	lua_rawseti(this, LUA_REGISTRYINDEX, HOOKCALL_REF);
	Pop();

	LoadLuaEnums();
}

LuaState::~LuaState()
{
}

std::string LuaState::GetCurrentFile()
{
	lua_Debug dbg;
	if(lua_getstack(this, 1, &dbg))
	{
		lua_getinfo(this, "Sl", &dbg);
		if(dbg.currentline > 0 && dbg.source[0] == '@')
			return dbg.source+1;
	}

	return "";
}

void LuaState::PrintError(const char *err)
{
	printf("%s\n", err);
}

void LuaState::Print(const char *str)
{
	printf("%s\n", str);
}

int LuaState::LoadFile(const std::string &path)
{
	int size;
	char *data;

    int file = FileHelper::readBinaryFile(path.c_str());


	if(file == -1)
	{
		printf("Could not load file '%s'\n", path);
		return -1;
	}

	size = FileHelper::fileLength(file);
	data = new char[size+1];
    data = FileHelper::readBuffer(file, size, true);
	data[size] = 0;
    FileHelper::closeBinaryFile(file);

	std::string cname = "@";
	cname.append(path);

	return luaL_loadbuffer(this, data, size, cname.c_str());
}

int LuaState::LoadFile(const std::string &path, const std::string &source)
{
	FilePath fp(source);
	fp.RemoveLast();

	fp.Append(path);
	if(!fp.IsValid()) return -1;

	return LoadFile(fp.ToString().c_str());
}

int LuaState::DoFile(const std::string &path, bool protect, int *outEnv)
{
	g_CurrentLua = this;

	int err = LoadFile(path);
	if(err != 0)
	{
		if(err > 0)
		{
			PrintError(lua_tostring(this, -1));
			lua_pop(this, 1);
		}
		return err;
	}

	// Create a new environment for this file
	if(outEnv)
	{
		lua_newtable(this);

		lua_newtable(this);
		lua_pushstring(this, "__index");
		lua_pushvalue(this, LUA_GLOBALSINDEX);
		lua_rawset(this, -3);

		lua_setmetatable(this, -2);
		lua_pushvalue(this, -1);
		*outEnv = luaL_ref(this, LUA_REGISTRYINDEX);
		lua_setfenv(this, -2);
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

int LuaState::DoFile(const std::string &path, const std::string &source, bool protect, int *outEnv)
{
	g_CurrentLua = this;

	FilePath fp(source);
	fp.RemoveLast();

	fp.Append(path);
	if(!fp.IsValid()) return -1;

	return DoFile(fp.ToString().c_str(), protect, outEnv);
}

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

bool LuaState::Require(const std::string &path)
{
	static const int sentinel_ = 0;
	static void *sentinel = ((void*)&sentinel_);

	GetField(LUA_REGISTRYINDEX, "_LOADED");
	int loaded = Top();

	// Check if the module was already loaded
	GetField(loaded, path.c_str());
	if(GetBool(-1))
		return true;
	Pop();

	// Load Lua file
	if(LoadFile(path + ".lua", LUAPATH "modules/_"))
		return false;

	// _LOADED[name] = <sentinel>
	lua_pushlightuserdata(this, sentinel);
	SetField(loaded, path.c_str());

	// Call the loaded module
	Push(path); // pass the module path as the first argument
	lua_call(this, 1, 1);
	if(!lua_isnil(this, -1)) // Module returned a value
		SetField(loaded, path.c_str());

	// Module didn't set a value
	GetField(loaded, path.c_str());
	if(lua_touserdata(this, -1) == sentinel)
	{
		// Set to true
		Push(true);
		SetField(loaded, path.c_str());

		// Return true
		Push(true);
	}

	return true;
}

bool LuaState::PushHook(const std::string &name)
{
	lua_rawgeti(this, LUA_REGISTRYINDEX, HOOKCALL_REF);
	Push(name);
	return true;
}

void LuaState::CallHook(int nargs, int nres)
{
	g_CurrentLua = this;

	if(lua_pcall(this, nargs+1, nres, 0))
	{
		PrintError(lua_tostring(this, -1));
		lua_pop(this, 1);
	}
}

LuaState *LuaState::GetCurrent()
{
	return g_CurrentLua;
}

//===========================================================================

