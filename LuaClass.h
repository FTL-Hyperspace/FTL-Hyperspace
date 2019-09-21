#pragma once

#include "LuaState.h"
#include <list>

class LuaFunction;
class LuaState;

class LuaClass
{
public:
	enum Type
	{
		TYPE_SHIPMANAGER = 0,
	};

	LuaClass(Type luatype, const char *name, const char *baseClass = NULL);
	~LuaClass();

	static void LoadAll(LuaState *L);

	void AddFunction(LuaFunction *f) {_functions.push_back(f);}
	void Load(LuaState *L);
	void Push(LuaState *L, void *ud);
	void *Check(LuaState *L, int idx);
	void PushMetatable(LuaState *L);
	void ReplaceMetatable(LuaState *L, int idx);

	static const char *GetTypeName(Type t);
	static const char *GetTypeName(LuaState *L, int idx);

private:
	const char *_name;
	std::list<LuaFunction*> _functions;
	const char *_baseClass;
	bool _loaded;
	bool _hasCustomIndex;
	Type _luaType;
};

#define LC(classname) _lc_##classname
#define LC_EXTERN(classname) extern LuaClass _lc_##classname
#define LUA_CLASS(luatype, classname) LuaClass _lc_##classname(luatype, #classname)
#define LUA_CLASS_DERIVED(luatype, classname, baseclass) LuaClass _lc_##classname(luatype, #classname, #baseclass)
