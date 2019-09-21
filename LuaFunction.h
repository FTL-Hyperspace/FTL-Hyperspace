#pragma once

#include "lua.hpp"

class LuaState;
class LuaClass;

class LuaFunction
{
public:
	typedef int (*Function)(LuaState *L);
	LuaFunction(const char *libname, const char *name, Function f);
	LuaFunction(LuaClass *lc, const char *name, Function f);

	static void LoadAll(LuaState *L);

public:
	const char *_libname;
	const char *_name;
	Function _func;
};

#define LUA_FUNCTION(name) \
	static int _l_##name (LuaState *L); \
	static LuaFunction _lf_##name ( "", #name, &_l_##name ); \
	int _l_##name (LuaState *L)

#define LUA_LIBFUNC(libname, name) \
	static int _l_##libname##_##name (LuaState *L); \
	static LuaFunction _lf_##libname##_##name ( #libname, #name, &_l_##libname##_##name ); \
	int _l_##libname##_##name (LuaState *L)

#define LUA_CLASSFUNC(classname, name) \
	static int _l_##classname##_##name (LuaState *L); \
	static LuaFunction _lf_##classname##_##name ( &_lc_##classname, #name, &_l_##classname##_##name ); \
	int _l_##classname##_##name (LuaState *L)
