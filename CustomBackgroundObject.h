#pragma once
#include "Global.h"

struct CustomBackgroundObjectDefinition;

struct CustomBackgroundObjectAction
{
    enum SELFOP
    {
        NONE,
        ACTIVATE,
        DEACTIVATE,
        TOGGLEACTIVE,
        DESTROY
    };

    enum RESULT
    {
        NOCHANGE,
        RESET,
        DESTROYED
    };

    std::string event = "";

    int selfOp = SELFOP::NONE;

    std::vector<std::pair<CustomBackgroundObjectDefinition*,Globals::Rect>> spawnObjects;

    int newDefChance = 0;
    std::vector<std::pair<CustomBackgroundObjectDefinition*,int>> newDef;

    CustomBackgroundObjectDefinition *GetRandomNewDef()
    {
        int rng = random32()%newDefChance;
        for (auto &def : newDef)
        {
            if (rng < def.second) return def.first;
            rng -= def.second;
        }
        return nullptr;
    }
};

struct CustomBackgroundObjectTimer
{
    CustomBackgroundObjectAction action;

    float time = -1.f;
    int minTime = -1;
    int maxTime = -1;

    bool loop = false;
    int8_t requireActive = -1;
    int8_t requireHover = -1;
    bool triggerActiveOnly = false;
};

struct CustomBackgroundObjectDefinition
{
    enum LAYER
    {
        LAYER_BACKGROUND,
        LAYER_FOREGROUND,
        LAYER_ASTEROIDS,
        LAYER_PLAYER,
        LAYER_PLAYERFRONT,
        LAYER_FRONT
    };

    struct AnimationDef
    {
        std::string anim = "";
        bool play = true; // play animations when this animation is visible
        bool loop = true; // loop this animation
        bool random = false; // start on random frame
    };

    int idx = -1;
    std::string name = "";
    int layer = LAYER_BACKGROUND;
    int z = 0;
    Globals::Rect spawnArea = {0,0,0,0};
    Globals::Rect hitbox = {0,0,-1,-1};
    bool centerAnim = false;
    bool centerHitbox = false;
    AnimationDef anim;
    AnimationDef hoverAnim;
    AnimationDef inactiveAnim;
    TextString tooltip;
    TextString inactiveTooltip;

    std::string req = "";
    int lvl = 1;
    int max_lvl = 2147483647;

    bool active = true;
    bool jumpClear = false;
    bool hideInactive = false;
    bool disableCombat = false;
    bool hasClickAction = false;
    bool hasAnimAction = false;

    CustomBackgroundObjectAction clickAction;
    CustomBackgroundObjectAction animAction;
    std::vector<CustomBackgroundObjectTimer> timerActions;
};

struct CustomBackgroundObject
{
    CustomBackgroundObject()
    {

    }

    CustomBackgroundObject(CustomBackgroundObjectDefinition *_def) :
        def(_def)
    {

    }

    CustomBackgroundObjectDefinition *def;

    Point position;
    Globals::Rect hitbox;

    bool hasHoverAnim;
    bool hasInactiveAnim;

    bool reqActive = true;

    bool bActive = true;
    bool bHover = false;

    Animation anim;
    Animation hoverAnim;
    Animation inactiveAnim;

    std::vector<TimerHelper> actionTimers;

    void Load(int fh);
    void Save(int fh);

    void Transform(CustomBackgroundObjectDefinition *_def);
    void OnInit();
    bool OnLoop();
    void OnRender(int layer, GL_Color &tint);
    bool MouseMove(CombatControl *combatControl, int mX, int mY);
    int8_t Activate(CustomBackgroundObjectAction &action);

    bool IsActive()
    {
        return bActive && reqActive && (!def->disableCombat || !G_->GetWorld()->commandGui->dangerLocation);
    }
};

struct CustomBackgroundObjectManager
{
    std::vector<CustomBackgroundObjectDefinition*> defs;
    std::unordered_map<std::string, CustomBackgroundObjectDefinition*> namedDefs;

    std::unordered_map<int,std::vector<CustomBackgroundObject>> backgroundObjects;
    int currentLocationIndex = -1;
    bool mouseActive = false;
    bool needSort = false;

    void CreateObject(CustomBackgroundObjectDefinition *def);
    void CreateObject(CustomBackgroundObjectDefinition *def, Globals::Rect rect);
    void ClearObjects(const std::string &name);
    void TransformObjects(const std::string &name1, const std::string &name2);
    void Sort();

    void OnLoop();
    void OnRender(SpaceManager *space, int layer);
    bool MouseMove(CombatControl *combatControl, int mX, int mY);
    void MouseClick();

    CustomBackgroundObjectDefinition* ParseCustomBackgroundObject(rapidxml::xml_node<char> *node);
    CustomBackgroundObjectAction ParseCustomBackgroundObjectAction(rapidxml::xml_node<char> *node);

    CustomBackgroundObjectDefinition* NewDef()
    {
        CustomBackgroundObjectDefinition *ret = new CustomBackgroundObjectDefinition();
        ret->idx = defs.size();
        defs.push_back(ret);
        return ret;
    }

    static CustomBackgroundObjectManager* instance;
};
