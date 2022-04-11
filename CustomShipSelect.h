#pragma once
#include "Global.h"
#include "ToggleValue.h"
#include <array>
#include <algorithm>
#include <boost/algorithm/string/predicate.hpp>

struct CustomUnlockArrow
{
    std::string ship = "";
    std::string targetShip = "";
    int variant = -1;
    TextString tooltip;
    CachedImage *image[3] = {nullptr, nullptr, nullptr};

    void OnRender(int x, int y, int enabled)
    {
        CSurface::GL_PushMatrix();
        CSurface::GL_Translate(x, y, 0.f);
        image[enabled]->OnRender(GL_Color(1.f,1.f,1.f,1.f));
        CSurface::GL_PopMatrix();
    }

    void MouseMove(int x, int y, int enabled);
};

struct ShipButtonDefinition
{
    std::string name;
    int8_t typeA = 1;
    int8_t typeB = 0;
    int8_t typeC = 0;

    bool secretCruiser = false;
    bool noAppend = false;
    bool splitUnlockQuestAchievement = false;
    bool splitVictoryAchievement = false;

    std::vector<CustomUnlockArrow> unlockArrows;

    bool VariantExists(int variant)
    {
        return (variant == 0 && typeA) || (variant == 1 && typeB) || (variant == 2 && typeC);
    }

    bool VariantNeedsDlc(int variant)
    {
        return (variant == 0 && typeA == 2) || (variant == 1 && typeB == 2) || (variant == 2 && typeC == 2);
    }
};

struct RoomAnimDef
{
    int renderLayer;
    std::string animName;
};

struct RoomDefinition
{
    int roomId;
    std::vector<RoomAnimDef> roomAnims;
    bool sensorBlind = false;

    float sysDamageResistChance = 0.f;
    float ionDamageResistChance = 0.f;
};

struct CrewPlacementDefinition
{
    std::string species;
    int roomId;
    std::string name;
    bool isList;
};

struct CustomShipDefinition
{
    std::string name = "";
    std::map<std::string, int> hiddenAugs = std::map<std::string, int>();
    std::vector<CrewPlacementDefinition> crewList = std::vector<CrewPlacementDefinition>();
    bool noJump = false;
    bool noFuelStalemate = false;
    int hpCap = 20;
    int startingFuel = -1;
    int startingScrap = -1;

    std::unordered_map<int, RoomDefinition*> roomDefs;
    std::vector<std::string> shipIcons;
    ToggleValue<bool> forceAutomated;

    int crewLimit = 8;
    int systemLimit = 8;
    int subsystemLimit = 4;

    std::vector<int> reactorPrices{15, 30, -1, -1, -1, -1};
    int reactorPriceIncrement = 5;
    int maxReactorLevel = 25;

    std::string shipGenerator = "";

    CustomShipDefinition()
    {

    }
};



class ShipButtonList
{
public:
    ShipButtonList(int _page, int _id, ShipButton* _a, ShipButton* _b=NULL, ShipButton* _c=nullptr)
    : page(_page),
      id(_id),
      a(_a),
      b(_b),
      c(_c)
    {

    }

    ShipButton *GetButton(int variant)
    {
        if (variant == 0) return a;
        if (variant == 1) return b;
        if (variant == 2) return c;
    }

    int GetPage()
    {
        return page;
    }

    int GetId()
    {
        return id;
    }

    int GetIndex()
    {
        return id - 100;
    }

private:
    int page;
    int id;
    ShipButton* a;
    ShipButton* b;
    ShipButton* c;
};

class CustomShipSelect
{
public:
    CustomShipSelect()
    {

    }

    static std::string GetVariantName(const std::string& name, int variant = 0)
    {
        switch (variant)
        {
        case 1:
            return name + "_2";
        case 2:
            return name + "_3";
        default:
            return name;
        }
    }

    void OnInit(ShipSelect*);
    void OnRender(bool renderSelect=false);
    void MouseMove(int x, int y);
    void MouseClick();
    void SwitchPage(int page);

    bool ShouldRenderButton(ShipButton *button);
    bool ShouldRenderArrow();
    bool ShouldRenderButtonLower();

    void LeaveFirstPage();
    void EnterFirstPage();

    void SwitchShip(ShipBuilder *builder, int type, int variant, bool force=false);

    std::string GetShipBlueprint(int shipId);

    void Close();
    void Open();

    int CycleShipNext(int currentShipId, int currentType);
    int CycleShipPrevious(int currentShipId, int currentType);

    void EarlyParseShipsNode(rapidxml::xml_node<char> *node);
    void ParseShipsNode(rapidxml::xml_node<char> *node);
    void ParseVanillaShipNode(rapidxml::xml_node<char> *node);
    bool ParseCustomShipNode(rapidxml::xml_node<char> *node, CustomShipDefinition &def);
    int CountUnlockedShips(int variant);

    void UpdateFilteredAchievements();


    bool IsOpen()
    {
        return open;
    }

    int GetCurrentPage()
    {
        return shipPage;
    }

    int GetMaxPages()
    {
        return maxShipPage;
    }

    bool FirstPage()
    {
        return shipPage == 0;
    }

    int GetSelection()
    {
        return selectedShip;
    }

    int GetSelectedId()
    {
        return selectedShip == -1 ? -1 : selectedShip + 100;
    }

    int GetLastSelected()
    {
        return lastSelectedShip;
    }

    void ClearSelection()
    {
        selectedShip = -1;
    }

    int GetShipButtonIdFromName(const std::string& name)
    {
        if (name == "empty")
        {
            return -1;
        }
        else
        {
            std::string finalName = name;

            if (boost::ends_with(name, "_2") || boost::ends_with(name, "_3"))
            {
                finalName = name.substr(0, name.size() - 2);
            }

            auto it = std::find_if(shipButtonDefs.begin(), shipButtonDefs.end(), [&finalName](const ShipButtonDefinition& def) { return def.name == finalName; });

            if (it != shipButtonDefs.end())
            {
                return std::distance(shipButtonDefs.begin(), it);
            }
            else
            {
                return -1;
            }
        }
    }

    ShipButtonDefinition* GetOrderedShipButtonDefinition(int id)
    {
        if (id > customShipOrder.size()) return nullptr;

        id = GetShipButtonIdFromName(customShipOrder[id]);

        if (id == -1) return nullptr;

        return &shipButtonDefs[id];
    }

    int GetShipButtonOrderIndex(int id)
    {
        auto name = shipButtonDefs[id].name;
        auto it = std::find(customShipOrder.begin(), customShipOrder.end(), name);

        if (it != customShipOrder.end())
        {
            return std::distance(customShipOrder.begin(), it);
        }
        else
        {
            return -1;
        }

    }

    ShipButtonDefinition& GetShipButtonDefinition(int id)
    {
        return shipButtonDefs[id];
    }

    CustomShipDefinition& GetDefinition(const std::string& name)
    {
        auto it = shipDefs.find(name);
        if (it != shipDefs.end())
        {
            return it->second;
        }
        return this->defaultShipDef;
    }

    CustomShipDefinition& GetDefaultDefinition()
    {
        return this->defaultShipDef;
    }

    int GetRandomShipIndex();

    int ShipCount(int type=0)
    {
        if (type == 0) return std::count_if(shipButtonDefs.begin(), shipButtonDefs.end(), [](ShipButtonDefinition i) { return i.typeA; } );
        if (type == 1) return std::count_if(shipButtonDefs.begin(), shipButtonDefs.end(), [](ShipButtonDefinition i) { return i.typeB; } );
        if (type == 2) return std::count_if(shipButtonDefs.begin(), shipButtonDefs.end(), [](ShipButtonDefinition i) { return i.typeC; } );
    }

    bool IsCustomShip(const std::string& id)
    {
        return std::count_if(shipButtonDefs.begin(), shipButtonDefs.end(), [id](ShipButtonDefinition i) { return id == i.name || (id.size() > 3 && id.substr(0, id.size() - 2) == i.name); }) > 0;
    }

    bool HasCustomDef(std::string& id)
    {
        return !(shipDefs.find(id) == shipDefs.end());
    }

    bool Initialized()
    {
        return initialized;
    }

    static CustomShipSelect* GetInstance()
    {
        return &instance;
    }

    void AddShipVictoryFilter(const std::string &s)
    {
        shipVictoryFilters.push_back(s);
    }

    std::vector<std::string> customShipOrder = std::vector<std::string>();
    bool hideFirstPage;

    std::vector<std::pair<Point, std::string>> customAnimDefs = std::vector<std::pair<Point, std::string>>();
    std::vector<std::pair<Point, Animation*>> customAnims = std::vector<std::pair<Point, Animation*>>();

private:
    ShipSelect* shipSelect;
    Button* leftButton;
    Button* rightButton;

    std::vector<ShipButton*> oldShipButtons;
    std::vector<ShipButtonList*> shipButtons = std::vector<ShipButtonList*>();
    std::vector<ShipButtonDefinition> shipButtonDefs = std::vector<ShipButtonDefinition> ();
    std::unordered_map<std::string, CustomShipDefinition> shipDefs = std::unordered_map<std::string, CustomShipDefinition>();

    CustomShipDefinition defaultShipDef = CustomShipDefinition();

    int shipPage = 0;
    int maxShipPage;
    bool initialized;
    int selectedShip = -1;
    int lastSelectedShip = -1;

    bool open;

    int selectedVictoryFilter = -1;
    std::vector<std::string> shipVictoryFilters;

    static CustomShipSelect instance;

};

