#ifndef LUAWORLD_H
#define LUAWORLD_H

#include "../luaInclude.h"

class LuaWorld
{
    public:
        LuaWorld(lua_State* lua);
        virtual ~LuaWorld();
        
        // TODO: LuaWorld's table should have a metatable to support the following functions:
        // _G.World.playerShip should actually lead to the same instance as _G.Ships[playerShipId] maybe?
        // _G.World.bossShip should lead to _G.Ships[bossShipId]?
        // ShipEvent currentShipEvent ?
        // SpaceManager space;
        // StarMap starMap;
        // Location *newLocation; ?
        
        // TODO: Add the following to the table holding LuaWorld
        // int currentDifficulty (maybe have metatable update this value in the game? Or force it to be read-only?)
        // bool bExtraChoice;
        // std::vector<int> choiceHistory -> Should probably be an array/table of integers? (or maybe this field is not important) (read-only maybe?)
        // std::string generatedEvent
        // TextString lastMainText -> Should be represented as a string maybe and hide the TextString fact
        // int playerCrewCount -> I think this is total crew the player had added to their ship, (make read-only?), maybe rename to "stat_totalPlayerCrewCount" or maybe make a "stats" table to hold this?
        // int killedCrew -> stat.totalKilledCrew?
        // int playerHull -> stat.totalPlayerHull? 
        
        // TODO Maybe allow calling:
        // bool CheckRequirements(LocationEvent *event, bool hidden);
        // bool AddBoarders(BoardingEvent &boardingEvent);
        // CompleteShip* CreateShip(ShipEvent *shipEvent, bool boss); // ? Or maybe this is only as part of events and not directly from Lua?
        // void CreateStore(LocationEvent* event);
        // LocationEvent* ModifyResources(LocationEvent* event); // ?
        // Maybe allow the CheckStatusEffects & ModifyStatusEffect ?
        // Maybe allow void UpdateLocation(LocationEvent* event); ?

    protected:

    private:
        lua_State* m_Lua;
//        WorldManager* m_WorldManager;
};

#endif // LUAWORLD_H
