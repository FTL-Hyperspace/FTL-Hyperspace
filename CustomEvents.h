#pragma once
#include "Global.h"
#include "ToggleValue.h"
#include <algorithm>
#include <memory>
#include <unordered_set>
#include <boost/format.hpp>

struct BeaconType
{
    std::string eventName;
    GL_Color color;
    bool global = false;
    TextString beaconText;
    TextString undiscoveredTooltip;
    TextString unvisitedTooltip;
    TextString visitedTooltip;
    std::string equipmentReq;
};

struct EventGameOver
{
    bool enabled = false;
    bool victory = false;
    std::string text = "";
    std::string creditsText = "";
    std::string creditsBackground = "";
};

struct CustomQuest
{
    ToggleValue<bool> nonNebulaBeacon;
    ToggleValue<bool> nebulaBeacon;
    ToggleValue<bool> createNebula;
    ToggleValue<std::string> nebulaEvent;
    ToggleValue<bool> currentSector;
    ToggleValue<bool> nextSector;
    ToggleValue<int> aggressive;
    ToggleValue<bool> sectorEight;
    ToggleValue<bool> lastStand;

    CustomQuest()
    {
        nonNebulaBeacon.value = true;
        nebulaBeacon.value = false;
        createNebula.value = true;
        nebulaEvent.value = "";
        currentSector.value = true;
        nextSector.value = true;
        aggressive.value = 0;
        sectorEight.value = false;
        lastStand.value = false;
    }

    void add(CustomQuest *other)
    {
        if (other->nonNebulaBeacon.enabled) nonNebulaBeacon = other->nonNebulaBeacon;
        if (other->nebulaBeacon.enabled) nebulaBeacon = other->nebulaBeacon;
        if (other->createNebula.enabled) createNebula = other->createNebula;
        if (other->nebulaEvent.enabled) nebulaEvent = other->nebulaEvent;
        if (other->currentSector.enabled) currentSector = other->currentSector;
        if (other->nextSector.enabled) nextSector = other->nextSector;
        if (other->aggressive.enabled) aggressive = other->aggressive;
        if (other->sectorEight.enabled) sectorEight = other->sectorEight;
        if (other->lastStand.enabled) lastStand = other->lastStand;
    }
};

class TriggeredEventBoxDefinition
{
public:
    enum class TextType
    {
        TIME_AUTO,
        TIME_CLOCK,
        TIME_SECONDS,
        JUMPS
    };

    std::string image = "";
    std::string image2 = "";
    int x = 0;
    int y = 0;
    int w = 0;
    int h = 0;

    int left = 0;
    int right = 0;
    int top = 0;
    int bottom = 0;

    TextType textType = TextType::TIME_AUTO;
    GL_Color textColor = GL_Color(1.f, 1.f, 1.f, 1.f);
    GL_Color textColor2 = GL_Color(1.f, 1.f, 1.f, 1.f);
    int text_x = 0;
    int text_y = 0;

    float warningTime = -999.f;
    int warningJumps = -999;
    bool flash = false;
};

class TriggeredEventDefinition
{
public:
    static std::vector<TriggeredEventDefinition> defs;
    static unsigned int PushDef(TriggeredEventDefinition& def);
public:
    TriggeredEventBoxDefinition* box = nullptr;
    unsigned int idx = -1;

    std::string name = "";
    std::string event = "";
    bool seeded = true;
    int minLoops = 1;
    int maxLoops = 1;
    float triggerMinTime = -1.f;
    float triggerMaxTime = -1.f;
    int triggerMinJumps = -1;
    int triggerMaxJumps = -1;
    bool clearOnJump = false;
};

class TriggeredEvent
{
public:
    static std::unordered_map<std::string, TriggeredEvent> eventList;

    static void NewEvent(TriggeredEventDefinition* def);
    static void DestroyEvent(const std::string& name);
    static void UpdateAll();
    static void JumpAll();
    static void TriggerCheck();
    static void SaveAll(int file);
    static void LoadAll(int file);

public:
    TriggeredEventDefinition* def;

    unsigned int seed = -1;
    int loops;
    TimerHelper* triggerTimer = nullptr;
    int triggerJumps;

    bool triggered = false;

    TriggeredEvent(TriggeredEventDefinition* newDef) : def{newDef}
    {
        if (def->seeded) seed = random32();

        if (def->maxLoops > def->minLoops)
        {
            loops = def->minLoops + random32()%(def->maxLoops-def->minLoops+1);
        }
        else
        {
            loops = def->minLoops;
        }

        if (def->triggerMinTime != -1.f)
        {
            triggerTimer = new TimerHelper();
        }

        Reset();
    }

    ~TriggeredEvent()
    {
        delete triggerTimer;
    }

    float GetTimeLeft()
    {
        if (triggerTimer == nullptr) return 0.0;
        if (triggerTimer->currTime >= triggerTimer->currGoal) return 0.0;
        return triggerTimer->currGoal - triggerTimer->currTime;
    }

    void Reset();
    void Update();
    void Jump();
    void Save(int file);
    void Load(int file);
};

struct GL_Primitive_Deleter {
    void operator()(GL_Primitive* p) {
        hs_log_file("Destroy primitive %d\n", p);
        CSurface::GL_DestroyPrimitive(p);
    }
};

class TriggeredEventBox
{
public:
    TriggeredEvent* event;

    std::unique_ptr<GL_Primitive, GL_Primitive_Deleter> backgroundIcon;
    std::unique_ptr<GL_Primitive, GL_Primitive_Deleter> backgroundIcon2;

    int x;
    int y;
    int width;
    int height;
    int text_x;
    int text_y;

    ~TriggeredEventBox() noexcept = default;
    TriggeredEventBox(const TriggeredEventBox&) = delete;
    TriggeredEventBox(TriggeredEventBox&& other) noexcept = default;
    TriggeredEventBox& operator=(const TriggeredEventBox&) = delete;
    TriggeredEventBox& operator=(TriggeredEventBox&&) noexcept = default;



    TriggeredEventBox(TriggeredEvent* e, int x_, int y_) :
        event{e},
        x{x_},
        y{y_}
    {
        backgroundIcon.reset(G_->GetResources()->CreateImagePrimitiveString(e->def->box->image, x - e->def->box->x, y - e->def->box->y, 0, GL_Color(1.f,1.f,1.f,1.f), 1.f, false));
        backgroundIcon2.reset(G_->GetResources()->CreateImagePrimitiveString(e->def->box->image2, x - e->def->box->x, y - e->def->box->y, 0, GL_Color(1.f,1.f,1.f,1.f), 1.f, false));
        width = e->def->box->w;
        height = e->def->box->h;
        text_x = x + e->def->box->text_x;
        text_y = y + e->def->box->text_y;
    }

    static std::string GetTimeTextClock(int t)
    {
        if (t >= 3600)
        {
            int h = t/3600;
            int m = (t/60)%60;
            int s = t%60;
            return boost::str(boost::format("%d:%02d:%02d") % h % m % s);
        }
        else
        {
            int m = t/60;
            int s = t%60;
            return boost::str(boost::format("%d:%02d") % m % s);
        }
    }

    std::string GetTimeTextSeconds(float t)
    {
        return boost::str(boost::format("%.1f") % t);
    }

    void OnRender(bool flash)
    {
        std::string text;

        bool useIcon2 = (event->triggerTimer != nullptr && event->GetTimeLeft() < event->def->box->warningTime) || (event->triggerJumps <= event->def->box->warningJumps);
        if (event->def->box->flash) useIcon2 = useIcon2 && flash;

        CSurface::GL_RenderPrimitive(useIcon2 ? backgroundIcon2.get() : backgroundIcon.get());
        CSurface::GL_SetColor(useIcon2 ? event->def->box->textColor2 : event->def->box->textColor);

        if (event->def->box->textType == TriggeredEventBoxDefinition::TextType::JUMPS)
        {
            text = std::to_string(event->triggerJumps);
        }
        else
        {
            float t = event->GetTimeLeft();
            if (event->def->box->textType == TriggeredEventBoxDefinition::TextType::TIME_CLOCK || t >= 60.f)
            {
                text = GetTimeTextClock(t);
            }
            else
            {
                text = GetTimeTextSeconds(t);
            }
        }

        freetype::easy_printCenter(0, text_x, text_y, text);
    }
};

class TriggeredEventGui
{
public:
    std::vector<TriggeredEventBox> boxes;
    std::unordered_map<std::string, TriggeredEventBoxDefinition> boxDefs;

    AnimationTracker flashTracker;

    bool reset = true;

    TriggeredEventGui()
    {
        flashTracker.time = 1.f;
        flashTracker.loop = true;
        flashTracker.current_time = 0.f;
        flashTracker.running = true;
        flashTracker.reverse = false;
        flashTracker.done = false;
        flashTracker.loopDelay = 0.f;
        flashTracker.currentDelay = 0.f;
    }

    void CreateBoxes()
    {
        boxes.clear();
        int x = 132;
        int y = 82;

        int i=0;

        for (auto& event: TriggeredEvent::eventList)
        {
            TriggeredEventBoxDefinition* box = event.second.def->box;
            if (box != nullptr)
            {
                if (i>0) x += box->left;
                boxes.emplace_back(&event.second, x, y);
                x += box->w + box->right;
                i++;
            }
        }

        reset = false;
    }

    void OnRender()
    {
        if (reset) CreateBoxes();

        flashTracker.Update();
        bool flash = flashTracker.current_time < 0.5f;

        for (auto& box: boxes)
        {
            box.OnRender(flash);
        }
    }

    static TriggeredEventGui *GetInstance()
    {
        return instance;
    }

private:
    static TriggeredEventGui *instance;
};

struct EventFleet
{
    std::string fleetDefName;
    bool firing;
    bool autoDarkening;
};

struct CustomEvent
{
    std::string eventName;
    std::string unlockShip;
    bool unlockShipSilent;
    std::string unlockShipReq;
    BeaconType *beacon;
    bool hasCustomBeacon = false;
    bool checkCargo = false;
    bool recursive = true;
    bool preventQuest = false;
    bool noQuestText = false;
    CustomQuest *customQuest;
    std::vector<unsigned int> triggeredEvents;
    std::vector<std::string> clearTriggeredEvents;
    int preventBossFleet = 0;
    int runFromFleet = 0;
    bool removeHazards = false;
    bool removeNebula = false;
    std::string secretSectorWarp = "";
    std::string eventLoad = "";
    bool eventLoadSeeded = true;
    EventGameOver gameOver = EventGameOver();
    bool disableScrapScore = false;
    std::string customStore;
    std::string jumpEvent = "";
    bool resetFtl = false;

    EventFleet leftFleet;
    EventFleet rightFleet;
    bool clearCustomFleet;

    std::vector<std::string> hiddenAugs = std::vector<std::string>();
    std::vector<std::string> removeItems = std::vector<std::string>();
    std::string playSound = "";
    std::string changeBackground = "";

};

struct SectorExit
{
    std::string event = "";
    std::string rebelEvent = "";
    std::string nebulaEvent = "";
};

struct SectorFleet
{
    std::string event = "";
    std::string nebulaEvent = "";
};

struct CustomSector
{
    std::string sectorName;
    SectorExit exitBeacons;
    SectorFleet fleetBeacons;
    bool removeFirstBeaconNebula = false;
    ToggleValue<bool> nebulaSector;
};

struct BossShipDefinition
{
    std::string shipId;
    int yOffset = 120;
};

class CustomReq
{
public:
    static int HasEquipment_Any(ShipObject& ship, const std::vector<std::string>& blueprintList)
    {
        int ret = 0;

        for (auto const& blueprint : blueprintList)
        {
            ret = std::max(ret, ship.HasEquipment(blueprint));
        }
        return ret;
    }

    static int HasEquipment_All(ShipObject& ship, const std::vector<std::string>& blueprintList)
    {
        int ret = 2147483647;

        for (auto const& blueprint : blueprintList)
        {
            ret = std::min(ret, ship.HasEquipment(blueprint));
        }
        return ret;
    }

    static int HasEquipment_Sum(ShipObject& ship, const std::vector<std::string>& blueprintList)
    {
        int ret = 0;

        for (auto const& blueprint : blueprintList)
        {
            ret += ship.HasEquipment(blueprint);
        }
        return ret;
    }

    enum REQ_TYPE
    {
        TYPE_ANY,
        TYPE_ALL,
        TYPE_SUM
    };

    std::string name = "";
    int type = TYPE_ANY;
    std::vector<std::string> blueprints = std::vector<std::string>();
    std::vector<CustomReq> children = std::vector<CustomReq>();
    int lvl = -1;
    int max_lvl = -1;
    int mult = 1;
    int constant = 0;

    int HasEquipment(ShipObject& ship)
    {
        int ret;

        switch(type)
        {
        case TYPE_ANY:
            ret = HasEquipment_Any(ship, blueprints);
            for (auto& child : children)
            {
                ret = std::max(ret, child.HasEquipment(ship));
            }
            break;
        case TYPE_ALL:
            ret = HasEquipment_All(ship, blueprints);
            for (auto& child : children)
            {
                ret = std::min(ret, child.HasEquipment(ship));
            }
            break;
        case TYPE_SUM:
            ret = HasEquipment_Sum(ship, blueprints);
            for (auto& child : children)
            {
                ret += child.HasEquipment(ship);
            }
            break;
        }

        if (lvl > -1 || max_lvl > -1)
        {
            int counter = ret;
            ret = counter >= lvl;
            if (max_lvl > -1) ret &= counter <= max_lvl;
        }

        return ret * mult + constant;
    }
};

class CustomEventsParser
{
public:
    CustomEventsParser()
    {

    }

    void ParseCustomEventNode(rapidxml::xml_node<char> *node);
    void ParseCustomQuestNode(rapidxml::xml_node<char> *node, CustomQuest *quest);
    void ParseCustomReqNode(rapidxml::xml_node<char> *node, CustomReq *req);
    void ParseCustomTriggeredEventBoxNode(rapidxml::xml_node<char> *node, TriggeredEventBoxDefinition *box);

    static CustomEventsParser *GetInstance()
    {
        return instance;
    }

    BossShipDefinition *GetBossShipDefinition(const std::string& shipId)
    {
        if (bossShipIds.find(shipId) != bossShipIds.end())
        {
            return &bossShipIds[shipId];
        }

        return nullptr;
    }

    CustomEvent *GetCustomEvent(const std::string& event);
    CustomSector *GetCustomSector(const std::string& sectorName);
    CustomReq *GetCustomReq(const std::string& blueprint);

    static std::string GetBaseEventName(const std::string& event)
    {
        if (event.find(' ') == std::string::npos)
        {
            return event;
        }
        else
        {
            return event.substr(0, event.find(' '));
        }
    }

    std::vector<std::string> eventFiles;
    CustomEvent *defaultVictory = new CustomEvent();
    CustomQuest *defaultQuest = new CustomQuest();

private:
    std::vector<CustomSector*> customSectors;
    std::unordered_map<std::string, CustomEvent*> customEvents;
    std::unordered_map<std::string, BossShipDefinition> bossShipIds;
    std::unordered_map<std::string, CustomReq*> customReqs;
    static CustomEventsParser *instance;
};

class BossFleetPrevention
{
public:
    StarMap* starMap;
    std::unordered_map<Location*, int> potentialFleetLocs = std::unordered_map<Location*, int>();
    std::unordered_set<Location*> fleetBlockedLocs = std::unordered_set<Location*>();

    void Clear()
    {
        for (auto i : fleetBlockedLocs)
        {
            if (i->beacon || !i->boss)
            {
                i->dangerZone = false;
            }
        }
        potentialFleetLocs.clear();
        fleetBlockedLocs.clear();
    }

    void Set()
    {
        bool hasVulnerableLoc = false;

        for (auto i : starMap->locations)
        {
            if (!i->dangerZone && !i->fleetChanging && !i->beacon)
            {
                if (i->visited)
                {
                    potentialFleetLocs[i] = 0;
                    hasVulnerableLoc = true;
                }
                else
                {
                    auto locEvent = i->event;
                    auto customEvents = CustomEventsParser::GetInstance();
                    auto customEvent = customEvents->GetCustomEvent(locEvent->eventName);

                    if (customEvent && customEvent->preventBossFleet)
                    {
                        potentialFleetLocs[i] = customEvent->preventBossFleet;
                    }
                    else
                    {
                        potentialFleetLocs[i] = 0;
                        hasVulnerableLoc = true;
                    }
                }
            }
        }

        for (auto i : potentialFleetLocs)
        {
            if (i.second && (hasVulnerableLoc || i.second == 2))
            {
                fleetBlockedLocs.insert(i.first);
                i.first->dangerZone = true;
            }
        }
    }
};
