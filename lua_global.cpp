#include "Global.h"
#include "LuaCommon.h"

LUA_FUNCTION(include)
{
	int top = L->Top();
	if(L->DoFile(L->GetString(1), L->GetCurrentFile(), false) == 0)
		return L->Top() - top;
	else
		return 0;
}

LUA_FUNCTION(require)
{
	std::string path = L->GetString(1);

	for(auto it = path.begin() ; it != path.end() ; ++it) *it = tolower(*it);

	if(L->Require(path))
		return 1;
	else
		return 0;
}

LUA_FUNCTION(print)
{
	int n = L->Top();

	lua_getglobal(L, "tostring");

	for(int i=1 ; i<=n ; ++i)
	{
		lua_pushvalue(L, -1);	// tostring
		lua_pushvalue(L, i);	// arg
		lua_call(L, 1, 1);

		if(i > 1)
			L->Print(" ");

		const char *s = lua_tolstring(L, -1, NULL);
		if(s)
		{
			L->Print(s);
		}

		L->Pop();
	}

	L->Print("\n");
	return 0;
}

LUA_FUNCTION(type)
{
	luaL_checkany(L, 1);
	if(lua_isuserdata(L, 1))
		Push_String(LuaClass::GetTypeName(L, 1));
	else
		Push_String(luaL_typename(L, 1));

	return 1;
}

LUA_FUNCTION(CurFrame)
{
	Push_Int(G_->GetCFPS()->Frames);
	return 1;
}


