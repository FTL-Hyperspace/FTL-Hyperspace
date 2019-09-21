#pragma once

#pragma warning (disable: 4530)

#include "lua.hpp"
#include <string>

// A replica of the lua_State struct from LuaJIT
struct lua_State
{
	unsigned int _nextgc;
	unsigned char _marked;
	unsigned char _gct;
	unsigned char _dummy_ffid;	/* Fake FF_C for curr_funcisL() on dummy frames. */
	unsigned char _status;		/* Thread status. */
	unsigned int _glref;		/* Link to global state. */
	unsigned int _gclist;		/* GC chain. */
	void *_base;				/* Base of currently executing function. */
	void *_top;					/* First free slot in the stack. */
	unsigned int _maxstack;		/* Last free slot in the stack. */
	unsigned int _stack;		/* Stack base. */
	unsigned int _openupval;	/* List of open upvalues in the stack. */
	unsigned int _env;			/* Thread environment (table of globals). */
	void *_cframe;				/* End of C stack frame chain. */
	unsigned int _stacksize;	/* True stack size (incl. LJ_STACK_EXTRA). */
};

//===========================================================================

class LuaState : public lua_State
{
public:
	static void *operator new(size_t n)
	{
		return lua_open();
	}

	static void operator delete(void *ptr)
	{
		lua_close((lua_State*)ptr);
	}

public:
	LuaState();
	~LuaState();

	static LuaState *GetCurrent();

	std::string GetCurrentFile();

	void PrintError(const char *err);
	void Print(const char *str);

	int Top() {return lua_gettop(this);}
	void Pop(int n = 1) {lua_pop(this, n);}

	void Push(int n) {lua_pushinteger(this, n);}
	void Push(double n) {lua_pushnumber(this, n);}
	void Push(bool n) {lua_pushboolean(this, n);}
	void Push(const std::string &n) {lua_pushstring(this, n.c_str());}
	void PushNil() {lua_pushnil(this);}

	void PushStackValue(int i) {lua_pushvalue(this, i);}

	void GetField(int idx, const char *k) {lua_getfield(this, idx, k);}
	void SetField(int idx, const char *k) {lua_setfield(this, idx, k);}
	bool GetBool(int i) {return lua_toboolean(this, i) != 0;}
	int GetInt(int i) {return luaL_checkinteger(this, i);}
	double GetFloat(int i) {return luaL_checknumber(this, i);}
	std::string GetString(int i) {return luaL_checkstring(this, i);}

	int LoadFile(const std::string &path);
	int LoadFile(const std::string &path, const std::string &source);

	int DoFile(const std::string &path, bool protect = true, int *outEnv = NULL);
	int DoFile(const std::string &path, const std::string &source, bool protect = true, int *outEnv = NULL);

	int DoString(const std::string &str, bool protect = true);

	bool Require(const std::string &path);

	void Call(int nargs, int nres) {lua_call(this, nargs, nres);}
	void PCall(int nargs, int nres) {lua_pcall(this, nargs, nres, 0);}

	bool PushHook(const std::string &name);
	void CallHook(int nargs, int nres);
};


#define LUA_ENUM(a) lua_pushinteger( LuaState::GetCurrent(), a ); lua_setglobal( LuaState::GetCurrent(), #a );
