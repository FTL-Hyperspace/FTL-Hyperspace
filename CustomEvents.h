#pragma once
#include "Global.h"
#include "ToggleValue.h"
#include <algorithm>
#include <memory>
#include <unordered_set>

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

class TriggeredEventDefinition
{
public:
    static std::vector<TriggeredEventDefinition> defs;
    static unsigned int PushDef(TriggeredEventDefinition& def);
public:
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
    std::unique_ptr<GL_Primitive, GL_Primitive_Deleter> backgroundIconRed;

    int x;
    int y;
    int width;

    /*~TriggeredEventBox() noexcept
    {
        CSurface::GL_DestroyPrimitive(backgroundIcon);
        CSurface::GL_DestroyPrimitive(backgroundIconRed);
    }*/

    TriggeredEventBox(const TriggeredEventBox&) = delete;
    TriggeredEventBox(TriggeredEventBox&& other) noexcept = default; /*:
        event{std::move(other.event)},
        backgroundIcon{other.backgroundIcon},
        backgroundIconRed{other.backgroundIconRed},
        x{std::move(other.x)},
        y{std::move(other.y)},
        width{std::move(other.width)}
    {
        other.backgroundIcon = nullptr;
        other.backgroundIconRed = nullptr;
    };*/
    TriggeredEventBox& operator=(const TriggeredEventBox&) = delete;
    //TriggeredEventBox& operator=(TriggeredEventBox&&) noexcept = default;

    TriggeredEventBox(TriggeredEvent* e, int x_, int y_) :
        event{e},
        x{x_},
        y{y_}
    {
        backgroundIcon.reset(G_->GetResources()->CreateImagePrimitiveString("statusUI/top_stopwatch.png", x, y, 0, GL_Color(1.f,1.f,1.f,1.f), 1.f, false));
        backgroundIconRed.reset(G_->GetResources()->CreateImagePrimitiveString("statusUI/top_stopwatch_red.png", x, y, 0, GL_Color(1.f,1.f,1.f,1.f), 1.f, false));
        width = backgroundIcon->texture->width_;
    }

    void OnRender()
    {
        CSurface::GL_RenderPrimitive(backgroundIcon.get());
        CSurface::GL_SetColor(GL_Color(243.f / 255.f, 255.f / 255.f, 230.f / 255.f, 1.f));
        //freetype::easy_printCenter(0, x+83, y+23, "1:00:00"); // big stopwatch
        freetype::easy_printCenter(0, x+51, y+15, "1:00"); // small stopwatch
    }
};

class TriggeredEventGui
{
public:
    std::vector<TriggeredEventBox> boxes;

    bool reset = true;

    void CreateBoxes()
    {
        boxes.clear();
        // 126,71 for big stopwatch
        // 122,75 for small
        int x = 122;
        int y = 75;

        for (int i=0; i<6; ++i)
        {
            boxes.emplace_back(nullptr, x, y);
            x += boxes.back().width;
        }
        reset = false;
    }

    void OnRender()
    {
        if (reset) CreateBoxes();

        for (auto& box: boxes)
        {
            box.OnRender();
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
