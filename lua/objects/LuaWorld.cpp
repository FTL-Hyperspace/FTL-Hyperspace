#include "LuaWorld.h"

#include "../../Global.h"

LuaWorld::LuaWorld(lua_State* lua)
{
    this->m_Lua = lua;
//    this->m_WorldManager = Global::GetInstance()->GetWorld();
}

LuaWorld::~LuaWorld()
{
    //dtor
}
