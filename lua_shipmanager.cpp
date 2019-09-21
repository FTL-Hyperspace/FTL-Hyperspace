#include "Global.h"
#include "LuaCommon.h"

LUA_CLASS(LuaClass::TYPE_SHIPMANAGER, ShipManager);

ShipManager &Get_ShipManager(int i)
{
	LuaState *L = LuaState::GetCurrent();
	ShipManager ship = *(ShipManager*)LC(ShipManager).Check(LuaState::GetCurrent(), i);

	return ship;
}

void Push_ShipManager(ShipManager *ship)
{
    LC(ShipManager).Push(LuaState::GetCurrent(), ship);
}

LUA_CLASSFUNC(ShipManager, __index)
{
	// Get metatable field
	if(luaL_getmetafield(L, 1, "__index0"))
	{
		lua_pushvalue(L, 2);
		lua_gettable(L, -2);
		if(!lua_isnil(L, -1))
			return 1;

		lua_pop(L, 2);
	}

	// Get data field
	ShipManager &self = Get_ShipManager(1);

	lua_rawgeti(L, LUA_REGISTRYINDEX, LC(ShipManager)._tableRef);
	lua_pushvalue(L, 2);
	lua_rawget(L, -2);
    return 1;
}

LUA_CLASSFUNC(Entity, __newindex)
{
	ShipManager *self = Get_Entity(1);

	lua_rawgeti(L, LUA_REGISTRYINDEX, LD(self)->_tableRef);
	lua_pushvalue(L, 2);
	lua_pushvalue(L, 3);
	lua_rawset(L, -3);
	return 0;
}


LUA_CLASSFUNC(ShipManager, GetHull)
{
    printf("%08X\n", Get_ShipManager(1));
    Push_Int(0);
    return 1;
}

LUA_CLASSFUNC(ShipManager, GetMaxHull)
{
    Push_Int(0);
    return 1;
}

