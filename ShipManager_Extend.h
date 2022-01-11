#pragma once
#include "FTLGame.h"

struct ShipIcon
{
    GL_Texture* icon;
    GL_Texture* box;
    std::string tooltip;
    int index;

    ShipIcon()
    {

    }

    ~ShipIcon()
    {
        //delete icon;
        //delete box;
    }

    void OnInit(const std::string& texture, const std::string& tip, int index);
    void OnRender(GL_Color color, bool boss, int idx=0);
    void MouseMove(int x, int y, bool boss, int idx=0);
};

struct ShipManager_Extend
{
    ShipManager *orig;
    bool isNewShip = false;
    bool hasCustomDef = false;
    std::map<std::string, int> hiddenAugs = std::map<std::string, int>();

    std::map<std::string, int> GetAugmentList();

    std::vector<ShipIcon*> icons;

    void Initialize(bool restarting=false);

    ~ShipManager_Extend()
    {
        for (auto i : icons)
        {
            delete i;
        }
    }

    //CrewMember *captain;
};

ShipManager_Extend* Get_ShipManager_Extend(ShipManager* c);

#define SM_EX Get_ShipManager_Extend
