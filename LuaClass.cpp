#include "LuaClass.h"
#include "LuaState.h"
#include "LuaFunction.h"
#include <unordered_map>
#include <cstring>

static std::unordered_map<std::string, LuaClass*> g_classes;

static const char *g_typeNames[] = {
    "ShipManager"
};

struct udata_t
{
	LuaClass::Type _type;
	void *_ptr;
};

const char *LuaClass::GetTypeName(Type luatype)
{
	return g_typeNames[luatype];
}

const char *LuaClass::GetTypeName(LuaState *L, int idx)
{
	udata_t *d = (udata_t*)lua_touserdata(L, idx);
	if(d)
		return GetTypeName(d->_type);
	else
		return "null";
}

LuaClass::LuaClass(Type luatype, const char *name, const char *baseClass) : _luaType(luatype), _name(name), _baseClass(baseClass)
{
	g_classes.insert(std::make_pair(std::string(name), this));
	_loaded = false;
	_hasCustomIndex = false;
}

LuaClass::~LuaClass()
{
}

static void DeriveMetaFunction(LuaState *L, const char *name, int thisMeta, int baseMeta)
{
	lua_getfield(L, thisMeta, name);
	bool shouldDerive = lua_isnil(L, -1);
	lua_pop(L, 1);
	if(shouldDerive)
	{
		lua_getfield(L, baseMeta, name);
		lua_setfield(L, thisMeta-1, name);
	}
}

void LuaClass::Load(LuaState *L)
{
	if(_loaded) return; // already loaded

	LuaClass *base = NULL;
	if(_baseClass)
	{
		auto it = g_classes.find(_baseClass);
		if(it == g_classes.end())
			printf("ERROR: Lua class %s derives from invalid class %s\n", _name, _baseClass);
		else
		{
			base = it->second;
			base->Load(L);
		}
	}

	luaL_newmetatable(L, _name);

	// Write class type as a metatable field
	lua_pushstring(L, _name);
	lua_setfield(L, -2, "__type");

	// Write metatable functions
	lua_newtable(L);
	_hasCustomIndex = false;
	if(base) _hasCustomIndex = base->_hasCustomIndex;

	for(auto it = _functions.begin() ; it != _functions.end() ; ++it)
	{
		LuaFunction *f = *it;
		lua_pushcfunction(L, (lua_CFunction)f->_func);

		if(f->_name[0] == '_' && f->_name[1] == '_')
		{
			// Metatable event function (write to metatable)
			lua_setfield(L, -3, f->_name);

			if(!strcmp(f->_name, "__index"))
				_hasCustomIndex = true;
		}
		else
		{
			// Regular metatable function (write to __index)
			lua_setfield(L, -2, f->_name);
		}
	}

	lua_setfield(L, -2, _hasCustomIndex ? "__index0" : "__index");

	// Base class
	if(base)
	{
		// Derive
		base->PushMetatable(L);

		DeriveMetaFunction(L, "__index", -2, -1);
		DeriveMetaFunction(L, "__newindex", -2, -1);
		DeriveMetaFunction(L, "__tostring", -2, -1);
		DeriveMetaFunction(L, "__gc", -2, -1);

		if(_hasCustomIndex)
		{
			lua_getfield(L, -2, "__index0"); // __index0 from current meta
			lua_newtable(L);
			lua_getfield(L, -3, "__index0"); // __index0 from base meta
			if(!lua_isnil(L, -1))
			{
				lua_setfield(L, -2, "__index");
				lua_setmetatable(L, -2); // metatable of __index0 from current meta = {__index = __index0 from base meta}
			}
			else
				lua_pop(L, 2);

			lua_pop(L, 1);
		}
		else
			DeriveMetaFunction(L, "__index0", -2, -1);

		lua_pop(L, 1); // base meta
	}

	lua_pop(L, 1); // current meta
	_loaded = true;
}

void LuaClass::Push(LuaState *L, void *ud)
{
	udata_t *d = (udata_t*)lua_newuserdata(L, sizeof(udata_t));
	d->_type = _luaType;
	d->_ptr = ud;
	luaL_getmetatable(L, _name);
	lua_setmetatable(L, -2);
}

void *LuaClass::Check(LuaState *L, int idx)
{
	udata_t *d = (udata_t*)lua_touserdata(L, idx);
	if(d)
	{
		if(d->_type == _luaType)
			return d->_ptr;

		static char buf[256];
		sprintf(buf, "%s expected, got %s", GetTypeName(_luaType), GetTypeName(d->_type));
	}
	else
		luaL_typerror(L, idx, GetTypeName(_luaType));

	return NULL;
}

void LuaClass::PushMetatable(LuaState *L)
{
	luaL_getmetatable(L, _name);
}

void LuaClass::ReplaceMetatable(LuaState *L, int idx)
{
	PushMetatable(L);
	lua_setmetatable(L, idx-1);
}

void LuaClass::LoadAll(LuaState *L)
{
	for(auto it = g_classes.begin() ; it != g_classes.end() ; ++it)
		it->second->_loaded = false;

	for(auto it = g_classes.begin() ; it != g_classes.end() ; ++it)
		it->second->Load(L);
}
