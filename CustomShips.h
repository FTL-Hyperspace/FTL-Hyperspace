#include "Global.h"
#include <array>
#include <algorithm>
#include <boost/algorithm/string/predicate.hpp>


struct ShipButtonDefinition
{
    std::string name;
    bool typeB;
    bool typeC;
};

struct CustomShipDefinition
{
    std::string name;
    std::map<std::string, int> hiddenAugs = std::map<std::string, int>();
};



class ShipButtonList
{
public:
    ShipButtonList(int _page, int _id, ShipButton* _a, ShipButton* _b=NULL, ShipButton* _c=NULL)
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

    void AddShip(std::string&, bool, bool);
    std::string GetShipBlueprint(int shipId);

    void Close();
    void Open();

    bool CycleShipNext(ShipBuilder *builder);
    bool CycleShipPrevious(ShipBuilder *builder);

    void ParseShipsNode(rapidxml::xml_node<char> *node);


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
        return selectedShip + 100;
    }

    int GetLastSelected()
    {
        return lastSelectedShip;
    }

    void ClearSelection()
    {
        selectedShip = -1;
    }



    ShipButtonDefinition& GetShipButtonDefinition(int id)
    {
        return shipButtonDefs[id];
    }

    CustomShipDefinition& GetDefinition(const std::string& name)
    {
        return this->shipDefs[name];
    }

    int GetRandomShipIndex()
    {
        return (rand() % shipButtonDefs.size());
    }

    int ShipCount(int type=0)
    {
        if (type == 0) return shipButtonDefs.size();
        if (type == 1) return std::count_if(shipButtonDefs.begin(), shipButtonDefs.end(), [](ShipButtonDefinition i) { return i.typeB; } );
        if (type == 2) return std::count_if(shipButtonDefs.begin(), shipButtonDefs.end(), [](ShipButtonDefinition i) { return i.typeC; } );
    }

    bool IsCustomShip(std::string& id)
    {
        return std::count_if(shipButtonDefs.begin(), shipButtonDefs.end(), [id](ShipButtonDefinition i) { return boost::starts_with(id, i.name); }) > 0;
    }

    bool HasCustomDef(std::string& id)
    {
        return std::count_if(shipDefs.begin(),
                         shipDefs.end(),
                         [id](std::pair<std::string, CustomShipDefinition> i) { return i.first == id; } )
                          > 0;
    }


    bool Initialized()
    {
        return initialized;
    }

    static CustomShipSelect* GetInstance()
    {
        return &instance;
    }



private:
    ShipSelect* shipSelect;
    Button* leftButton;
    Button* rightButton;

    std::vector<ShipButton*> oldShipButtons;
    std::vector<ShipButtonList*> shipButtons = std::vector<ShipButtonList*>();
    std::vector<ShipButtonDefinition> shipButtonDefs = std::vector<ShipButtonDefinition> ();
    std::map<std::string, CustomShipDefinition> shipDefs = std::map<std::string, CustomShipDefinition>();

    int shipPage = 0;
    int maxShipPage;
    bool initialized;
    int selectedShip = -1;
    int lastSelectedShip = -1;

    bool open;

    static CustomShipSelect instance;

};
