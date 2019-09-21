#include "LuaFunction.h"
#include "LuaState.h"
#include "LuaClass.h"

#include <vector>
#include <string>
#include <unordered_map>

static std::unordered_map<std::string, std::list<LuaFunction*>> g_luaFunctions;

LuaFunction::LuaFunction(const char *libname, const char *name, Function f) : _libname(libname), _name(name), _func(f)
{
	auto it = g_luaFunctions.find(libname);
	if(it == g_luaFunctions.end())
		it = g_luaFunctions.insert(std::make_pair(libname, std::list<LuaFunction*>())).first;

	it->second.push_back(this);
}

LuaFunction::LuaFunction(LuaClass *lc, const char *name, Function f) : _libname(""), _name(name), _func(f)
{
	lc->AddFunction(this);
}

void LuaFunction::LoadAll(LuaState *L)
{
	for(auto it = g_luaFunctions.begin() ; it != g_luaFunctions.end() ; ++it)
	{
		const char *libname = it->first.c_str();
		bool isGlobal = !libname[0];
		bool isExistingTable = false;

		if(!isGlobal)
		{
			lua_getglobal(L, libname);
			if(lua_istable(L, -1))
				isExistingTable = true;
			else
			{
				lua_pop(L, 1);
				lua_newtable(L);
			}
		}

		for(auto it2 = it->second.begin() ; it2 != it->second.end() ; ++it2)
		{
			LuaFunction *lf = *it2;
			lua_pushcfunction(L, (lua_CFunction)lf->_func);

			if(isGlobal)
				lua_setglobal(L, lf->_name);
			else
				lua_setfield(L, -2, lf->_name);
		}

		if(!isGlobal)
		{
			if(!isExistingTable)
				lua_setglobal(L, libname);
			else
				lua_pop(L, 1);
		}
	}
}
