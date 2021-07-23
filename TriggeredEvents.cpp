#include "CustomEvents.h"
#include "Seeds.h"

std::vector<TriggeredEventDefinition> TriggeredEventDefinition::defs = std::vector<TriggeredEventDefinition>();
std::unordered_map<std::string, TriggeredEvent> TriggeredEvent::eventList = std::unordered_map<std::string, TriggeredEvent>();

TriggeredEventGui *TriggeredEventGui::instance = new TriggeredEventGui();

bool locationUpdated;

unsigned int TriggeredEventDefinition::PushDef(TriggeredEventDefinition& def)
{
    unsigned int ret = defs.size();
    def.idx = ret;
    defs.push_back(def);
    return ret;
}

void TriggeredEvent::NewEvent(TriggeredEventDefinition* def)
{
    if (def->seeded && SeedInputBox::seedsEnabled) srandom32(Global::questSeed);

    auto it = eventList.find(def->name);
    if (it != eventList.end())
    {
        eventList.erase(it);
    }
    eventList.emplace(std::piecewise_construct, std::forward_as_tuple(def->name), std::forward_as_tuple(def));

    if (def->seeded && SeedInputBox::seedsEnabled) Global::questSeed = random32();
}

void TriggeredEvent::DestroyEvent(const std::string& name)
{
    auto it = eventList.find(name);
    if (it != eventList.end())
    {
        eventList.erase(it);
    }
}

void TriggeredEvent::UpdateAll()
{
    for (auto it=eventList.begin(); it!=eventList.end(); ++it)
    {
        it->second.Update();
    }
}

void TriggeredEvent::JumpAll()
{
    for (auto it=eventList.begin(); it!=eventList.end(); )
    {
        it->second.Jump();
        if (it->second.def->clearOnJump)
        {
            it = eventList.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

void TriggeredEvent::TriggerCheck()
{
    for (auto it=eventList.begin(); it!=eventList.end(); ++it)
    {
        if (it->second.triggered)
        {
            std::string eventName = it->second.def->event;
            unsigned int seed = it->second.seed;
            int level = G_->GetWorld()->starMap.currentSector->level;

            if (--(it->second.loops) <= 0)
            {
                eventList.erase(it);
            }
            else
            {
                it->second.triggered = false;
                it->second.Reset();
            }

            G_->GetWorld()->UpdateLocation(G_->GetEventGenerator()->GetBaseEvent(eventName, level, true, seed));
            break;
        }
    }
}

void TriggeredEvent::Reset()
{
    if (triggerTimer != nullptr)
    {
        float goal = def->triggerMinTime;
        if (def->triggerMaxTime > def->triggerMinTime)
        {
            int minTime = def->triggerMinTime * 1000.f;
            int maxTime = def->triggerMaxTime * 1000.f;
            goal = (minTime + random32()%(maxTime-minTime+1)) / 1000;
        }
        triggerTimer->currTime = 0.f;
        triggerTimer->currGoal = goal;
        triggerTimer->running = true;
    }

    if (def->triggerMaxJumps > def->triggerMinJumps)
    {
        triggerJumps = def->triggerMinJumps + random32()%(def->triggerMaxJumps-def->triggerMinJumps+1);
    }
    else
    {
        triggerJumps = def->triggerMinJumps;
    }
}

void TriggeredEvent::Update()
{
    if (triggerTimer != nullptr)
    {
        triggerTimer->Update();
        if (triggerTimer->Done())
        {
            triggered = true;
        }
    }
}

void TriggeredEvent::Jump()
{
    if (triggerJumps > 0)
    {
        if (--triggerJumps == 0)
        {
            triggered = true;
        }
    }
}

void TriggeredEvent::SaveAll(int file)
{
    FileHelper::writeInt(file, eventList.size());
    for (auto it=eventList.begin(); it!=eventList.end(); ++it)
    {
        FileHelper::writeString(file, it->first);
        it->second.Save(file);
    }
}

void TriggeredEvent::LoadAll(int file)
{
    TriggeredEvent::eventList.clear();
    TriggeredEventGui::GetInstance()->reset = true;

    int n = FileHelper::readInteger(file);

    for (unsigned int i=0; i<n; ++i)
    {
        std::string name = FileHelper::readString(file);
        TriggeredEventDefinition* def = &(TriggeredEventDefinition::defs.at(FileHelper::readInteger(file)));
        auto it = eventList.emplace(std::piecewise_construct, std::forward_as_tuple(def->name), std::forward_as_tuple(def));
        it.first->second.Load(file);
    }
}

void TriggeredEvent::Save(int file)
{
    FileHelper::writeInt(file, def->idx);
    FileHelper::writeInt(file, seed);
    FileHelper::writeInt(file, loops);
    if (triggerTimer != nullptr)
    {
        FileHelper::writeFloat(file, triggerTimer->currTime);
        FileHelper::writeFloat(file, triggerTimer->currGoal);
    }
    FileHelper::writeInt(file, triggerJumps);
    FileHelper::writeInt(file, triggered);
}

void TriggeredEvent::Load(int file)
{
    // def is read in LoadAll
    seed = FileHelper::readInteger(file);
    loops = FileHelper::readInteger(file);
    if (triggerTimer != nullptr)
    {
        triggerTimer->currTime = FileHelper::readFloat(file);
        triggerTimer->currGoal = FileHelper::readFloat(file);
    }
    triggerJumps = FileHelper::readInteger(file);
    triggered = FileHelper::readInteger(file);
}

HOOK_METHOD(WorldManager, CreateNewGame, () -> void)
{
    TriggeredEvent::eventList.clear();
    TriggeredEventGui::GetInstance()->reset = true;
    super();
}

HOOK_METHOD_PRIORITY(StarMap, LoadGame, 100, (int file) -> Location*)
{
    auto ret = super(file);
    TriggeredEvent::LoadAll(file);
    return ret;
}

HOOK_METHOD_PRIORITY(StarMap, SaveGame, 100, (int file) -> void)
{
    super(file);
    TriggeredEvent::SaveAll(file);
}

HOOK_METHOD(WorldManager, OnLoop, () -> void)
{
    locationUpdated = false;
    TriggeredEvent::UpdateAll();

    super();

    if (!locationUpdated && (playerShip && !playerShip->shipManager->bJumping)) TriggeredEvent::TriggerCheck();
}

HOOK_METHOD(WorldManager, UpdateLocation, (LocationEvent *loc) -> void)
{
    super(loc);
    locationUpdated = true;
}

HOOK_METHOD(StarMap, UpdateDangerZone, () -> void)
{
    TriggeredEvent::JumpAll();
    super();
}

HOOK_METHOD(ShipStatus, OnRender, () -> void)
{
    super();
    TriggeredEventGui::GetInstance()->OnRender();
}
