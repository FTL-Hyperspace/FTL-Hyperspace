#include "CustomBackgroundObject.h"
#include "CustomEvents.h"
#include <boost/lexical_cast.hpp>

CustomBackgroundObjectManager* CustomBackgroundObjectManager::instance = new CustomBackgroundObjectManager();

CustomBackgroundObjectDefinition* CustomBackgroundObjectManager::ParseCustomBackgroundObject(rapidxml::xml_node<char> *node)
{
    CustomBackgroundObjectDefinition* def;

    if (node->first_attribute("load"))
    {
        def = namedDefs.at(node->first_attribute("load")->value());
        return def;
    }

    def = NewDef();
    if (node->first_attribute("name"))
    {
        def->name = node->first_attribute("name")->value();
        namedDefs[def->name] = def;
    }

    def->tooltip.data = "";
    def->inactiveTooltip.data = "";

    for (auto child = node->first_node(); child; child = child->next_sibling())
    {
        if (strcmp(child->name(), "layer") == 0)
        {
            if (strcmp(child->value(), "background") == 0)
            {
                def->layer = CustomBackgroundObjectDefinition::LAYER::LAYER_BACKGROUND;
            }
            else if (strcmp(child->value(), "foreground") == 0)
            {
                def->layer = CustomBackgroundObjectDefinition::LAYER::LAYER_FOREGROUND;
            }
            else if (strcmp(child->value(), "asteroids") == 0)
            {
                def->layer = CustomBackgroundObjectDefinition::LAYER::LAYER_ASTEROIDS;
            }
            else if (strcmp(child->value(), "player") == 0 || strcmp(child->value(), "playerback") == 0)
            {
                def->layer = CustomBackgroundObjectDefinition::LAYER::LAYER_PLAYER;
            }
            else if (strcmp(child->value(), "playerfront"))
            {
                def->layer = CustomBackgroundObjectDefinition::LAYER::LAYER_PLAYERFRONT;
            }
            else if (strcmp(child->value(), "front"))
            {
                def->layer = CustomBackgroundObjectDefinition::LAYER::LAYER_FRONT;
            }

            if (child->first_attribute("z"))
            {
                def->z = boost::lexical_cast<int>(child->first_attribute("z")->value());
            }
        }
        else if (strcmp(child->name(), "spawnArea") == 0)
        {
            if (child->first_attribute("x"))
            {
                def->spawnArea.x = boost::lexical_cast<int>(child->first_attribute("x")->value());
            }
            if (child->first_attribute("y"))
            {
                def->spawnArea.y = boost::lexical_cast<int>(child->first_attribute("y")->value());
            }
            if (child->first_attribute("w"))
            {
                def->spawnArea.w = boost::lexical_cast<int>(child->first_attribute("w")->value());
            }
            if (child->first_attribute("h"))
            {
                def->spawnArea.h = boost::lexical_cast<int>(child->first_attribute("h")->value());
            }
            if (child->first_attribute("center"))
            {
                def->centerAnim = EventsParser::ParseBoolean(child->first_attribute("center")->value());
            }
        }
        else if (strcmp(child->name(), "hitbox") == 0)
        {
            if (child->first_attribute("x"))
            {
                def->hitbox.x = boost::lexical_cast<int>(child->first_attribute("x")->value());
            }
            if (child->first_attribute("y"))
            {
                def->hitbox.y = boost::lexical_cast<int>(child->first_attribute("y")->value());
            }
            if (child->first_attribute("w"))
            {
                def->hitbox.w = boost::lexical_cast<int>(child->first_attribute("w")->value());
            }
            if (child->first_attribute("h"))
            {
                def->hitbox.h = boost::lexical_cast<int>(child->first_attribute("h")->value());
            }
            if (child->first_attribute("center"))
            {
                def->centerHitbox = EventsParser::ParseBoolean(child->first_attribute("center")->value());
            }
        }
        else if (strcmp(child->name(), "anim") == 0)
        {
            def->anim.anim = child->value();
            if (child->first_attribute("play")) def->anim.play = EventsParser::ParseBoolean(child->first_attribute("play")->value());
            if (child->first_attribute("loop")) def->anim.loop = EventsParser::ParseBoolean(child->first_attribute("loop")->value());
            if (child->first_attribute("random")) def->anim.random = EventsParser::ParseBoolean(child->first_attribute("random")->value());
        }
        else if (strcmp(child->name(), "tooltip") == 0)
        {
            def->tooltip.data = child->value();
            if (child->first_attribute("id"))
            {
                def->tooltip.data = child->first_attribute("id")->value();
                def->tooltip.isLiteral = false;
            }
        }
        else if (strcmp(child->name(), "inactiveTooltip") == 0)
        {
            def->inactiveTooltip.data = child->value();
            if (child->first_attribute("id"))
            {
                def->inactiveTooltip.data = child->first_attribute("id")->value();
                def->inactiveTooltip.isLiteral = false;
            }
        }
        else if (strcmp(child->name(), "req") == 0)
        {
            def->req = child->value();
            if (child->first_attribute("max_lvl"))
            {
                def->max_lvl = boost::lexical_cast<int>(child->first_attribute("max_lvl")->value());
                def->lvl = -2147483647;
            }
            if (child->first_attribute("lvl"))
            {
                def->lvl = boost::lexical_cast<int>(child->first_attribute("lvl")->value());
            }
        }
        else if (strcmp(child->name(), "active") == 0)
        {
            def->active = EventsParser::ParseBoolean(child->value());
        }
        else if (strcmp(child->name(), "jumpClear") == 0)
        {
            def->jumpClear = EventsParser::ParseBoolean(child->value());
        }
        else if (strcmp(child->name(), "disableCombat") == 0)
        {
            def->disableCombat = EventsParser::ParseBoolean(child->value());
        }
        else if (strcmp(child->name(), "clickAction") == 0)
        {
            def->hasClickAction = true;
            def->clickAction = ParseCustomBackgroundObjectAction(child);
        }
        else if (strcmp(child->name(), "animAction") == 0)
        {
            def->hasAnimAction = true;
            def->animAction = ParseCustomBackgroundObjectAction(child);
        }
        else if (strcmp(child->name(), "timerAction") == 0)
        {
            def->timerActions.emplace_back();
            CustomBackgroundObjectTimer &timerAction = def->timerActions.back();

            timerAction.action = ParseCustomBackgroundObjectAction(child);
            if (child->first_attribute("time")) timerAction.time = boost::lexical_cast<float>(child->first_attribute("time")->value());
            if (child->first_attribute("minTime")) timerAction.minTime = boost::lexical_cast<float>(child->first_attribute("minTime")->value())*1000;
            if (child->first_attribute("maxTime")) timerAction.maxTime = boost::lexical_cast<float>(child->first_attribute("maxTime")->value())*1000;
            if (child->first_attribute("loop")) timerAction.loop = EventsParser::ParseBoolean(child->first_attribute("loop")->value());
            if (child->first_attribute("requireActive")) timerAction.requireActive = EventsParser::ParseBoolean(child->first_attribute("requireActive")->value());
            if (child->first_attribute("requireHover")) timerAction.requireHover = EventsParser::ParseBoolean(child->first_attribute("requireHover")->value());
            if (child->first_attribute("triggerActiveOnly")) timerAction.triggerActiveOnly = EventsParser::ParseBoolean(child->first_attribute("triggerActiveOnly")->value());
        }
    }

    def->hoverAnim.play = def->anim.play;
    def->hoverAnim.loop = def->anim.loop;
    def->hoverAnim.random = def->anim.random;
    def->inactiveAnim.play = def->anim.play;
    def->inactiveAnim.loop = def->anim.loop;
    def->inactiveAnim.random = def->anim.random;

    for (auto child = node->first_node(); child; child = child->next_sibling())
    {
        if (strcmp(child->name(), "hoverAnim") == 0)
        {
            def->hoverAnim.anim = child->value();
            if (child->first_attribute("play")) def->hoverAnim.play = EventsParser::ParseBoolean(child->first_attribute("play")->value());
            if (child->first_attribute("loop")) def->hoverAnim.loop = EventsParser::ParseBoolean(child->first_attribute("loop")->value());
            if (child->first_attribute("random")) def->hoverAnim.random = EventsParser::ParseBoolean(child->first_attribute("random")->value());
        }
        else if (strcmp(child->name(), "inactiveAnim") == 0)
        {
            def->inactiveAnim.anim = child->value();
            if (child->first_attribute("hide")) def->hideInactive = EventsParser::ParseBoolean(child->first_attribute("hide")->value());
            if (child->first_attribute("play")) def->inactiveAnim.play = EventsParser::ParseBoolean(child->first_attribute("play")->value());
            if (child->first_attribute("loop")) def->inactiveAnim.loop = EventsParser::ParseBoolean(child->first_attribute("loop")->value());
            if (child->first_attribute("random")) def->inactiveAnim.random = EventsParser::ParseBoolean(child->first_attribute("random")->value());
        }
    }

    return def;
}

CustomBackgroundObjectAction CustomBackgroundObjectManager::ParseCustomBackgroundObjectAction(rapidxml::xml_node<char> *node)
{
    CustomBackgroundObjectAction ret;

    for (auto child = node->first_node(); child; child = child->next_sibling())
    {
        if (strcmp(child->name(), "event") == 0)
        {
            ret.event = G_->GetEventsParser()->ProcessEvent(child, "__customBackgroundObjectAction");
        }
        else if (strcmp(child->name(), "activate") == 0)
        {
            ret.selfOp = CustomBackgroundObjectAction::SELFOP::ACTIVATE;
        }
        else if (strcmp(child->name(), "deactivate") == 0)
        {
            ret.selfOp = CustomBackgroundObjectAction::SELFOP::DEACTIVATE;
        }
        else if (strcmp(child->name(), "toggle") == 0)
        {
            ret.selfOp = CustomBackgroundObjectAction::SELFOP::TOGGLEACTIVE;
        }
        else if (strcmp(child->name(), "destroy") == 0)
        {
            ret.selfOp = CustomBackgroundObjectAction::SELFOP::DESTROY;
        }
        else if (strcmp(child->name(), "transform") == 0)
        {
            ret.newDef.emplace_back();
            auto &transformDef = ret.newDef.back();

            transformDef.first = ParseCustomBackgroundObject(child);
            transformDef.second = child->first_attribute("chance") ? boost::lexical_cast<int>(child->first_attribute("chance")->value()) : 1;
            ret.newDefChance += transformDef.second;
        }
        else if (strcmp(child->name(), "noTransform") == 0)
        {
            ret.newDefChance += child->first_attribute("chance") ? boost::lexical_cast<int>(child->first_attribute("chance")->value()) : 1;
        }
        else if (strcmp(child->name(), "spawnObject") == 0)
        {
            std::pair<CustomBackgroundObjectDefinition*,Globals::Rect> spawnObject;

            spawnObject.first = ParseCustomBackgroundObject(child);

            if (child->first_attribute("x"))
            {
                spawnObject.second.x = boost::lexical_cast<int>(child->first_attribute("x")->value());
            }
            if (child->first_attribute("y"))
            {
                spawnObject.second.y = boost::lexical_cast<int>(child->first_attribute("y")->value());
            }
            if (child->first_attribute("w"))
            {
                spawnObject.second.w = boost::lexical_cast<int>(child->first_attribute("w")->value());
            }
            if (child->first_attribute("h"))
            {
                spawnObject.second.h = boost::lexical_cast<int>(child->first_attribute("h")->value());
            }
            ret.spawnObjects.push_back(spawnObject);
        }
    }

    return ret;
}

HOOK_METHOD(WorldManager, ClearLocation, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> WorldManager::ClearLocation -> Begin (CustomBackgroundObject.cpp)\n")
    super();

    auto &backgroundObjects = CustomBackgroundObjectManager::instance->backgroundObjects[CustomBackgroundObjectManager::instance->currentLocationIndex];

    backgroundObjects.erase(std::remove_if(backgroundObjects.begin(),
                                           backgroundObjects.end(),
                                           [](CustomBackgroundObject& obj) { return obj.def->jumpClear; }),
                                           backgroundObjects.end());

    CustomBackgroundObjectManager::instance->currentLocationIndex = -1;
}

HOOK_METHOD(WorldManager, CreateLocation, (Location *location) -> void)
{
    LOG_HOOK("HOOK_METHOD -> WorldManager::CreateLocation -> Begin (CustomBackgroundObject.cpp)\n")
    for (int i=0; i<starMap.locations.size(); ++i)
    {
        if (starMap.locations[i] == location)
        {
            CustomBackgroundObjectManager::instance->currentLocationIndex = i;
            break;
        }
    }
    super(location);
}

void CustomBackgroundObject::Load(int fh)
{
    int n;

    def = CustomBackgroundObjectManager::instance->defs[FileHelper::readInteger(fh)];

    position.x = FileHelper::readInteger(fh);
    position.y = FileHelper::readInteger(fh);
    OnInit();

    reqActive = FileHelper::readInteger(fh);
    bActive = FileHelper::readInteger(fh);

    anim.currentFrame = FileHelper::readInteger(fh);
    anim.tracker.time = FileHelper::readFloat(fh);
    anim.tracker.current_time = FileHelper::readFloat(fh);
    anim.tracker.running = FileHelper::readInteger(fh);
    anim.tracker.done = FileHelper::readInteger(fh);
    anim.tracker.loopDelay = FileHelper::readFloat(fh);
    anim.tracker.currentDelay = FileHelper::readFloat(fh);

    if (hasHoverAnim)
    {
        hoverAnim.currentFrame = FileHelper::readInteger(fh);
        hoverAnim.tracker.time = FileHelper::readFloat(fh);
        hoverAnim.tracker.current_time = FileHelper::readFloat(fh);
        hoverAnim.tracker.running = FileHelper::readInteger(fh);
        hoverAnim.tracker.done = FileHelper::readInteger(fh);
        hoverAnim.tracker.loopDelay = FileHelper::readFloat(fh);
        hoverAnim.tracker.currentDelay = FileHelper::readFloat(fh);
    }

    if (hasInactiveAnim)
    {
        inactiveAnim.currentFrame = FileHelper::readInteger(fh);
        inactiveAnim.tracker.time = FileHelper::readFloat(fh);
        inactiveAnim.tracker.current_time = FileHelper::readFloat(fh);
        inactiveAnim.tracker.running = FileHelper::readInteger(fh);
        inactiveAnim.tracker.done = FileHelper::readInteger(fh);
        inactiveAnim.tracker.loopDelay = FileHelper::readFloat(fh);
        inactiveAnim.tracker.currentDelay = FileHelper::readFloat(fh);
    }

    n = FileHelper::readInteger(fh);
    for (int i=0; i<n; ++i)
    {
        if (i < actionTimers.size())
        {
            TimerHelper &timer = actionTimers[i];

            timer.maxTime = FileHelper::readInteger(fh);
            timer.minTime = FileHelper::readInteger(fh);
            timer.currTime = FileHelper::readFloat(fh);
            timer.currGoal = FileHelper::readFloat(fh);
            timer.loop = FileHelper::readInteger(fh);
            timer.running = FileHelper::readInteger(fh);
        }
    }
}

void CustomBackgroundObject::Save(int fh)
{
    FileHelper::writeInt(fh, def->idx);
    FileHelper::writeInt(fh, position.x);
    FileHelper::writeInt(fh, position.y);
    FileHelper::writeInt(fh, reqActive);
    FileHelper::writeInt(fh, bActive);

    FileHelper::writeInt(fh, anim.currentFrame);
    FileHelper::writeFloat(fh, anim.tracker.time);
    FileHelper::writeFloat(fh, anim.tracker.current_time);
    FileHelper::writeInt(fh, anim.tracker.running);
    FileHelper::writeInt(fh, anim.tracker.done);
    FileHelper::writeFloat(fh, anim.tracker.loopDelay);
    FileHelper::writeFloat(fh, anim.tracker.currentDelay);

    if (hasHoverAnim)
    {
        FileHelper::writeInt(fh, hoverAnim.currentFrame);
        FileHelper::writeFloat(fh, hoverAnim.tracker.time);
        FileHelper::writeFloat(fh, hoverAnim.tracker.current_time);
        FileHelper::writeInt(fh, hoverAnim.tracker.running);
        FileHelper::writeInt(fh, hoverAnim.tracker.done);
        FileHelper::writeFloat(fh, hoverAnim.tracker.loopDelay);
        FileHelper::writeFloat(fh, hoverAnim.tracker.currentDelay);
    }

    if (hasInactiveAnim)
    {
        FileHelper::writeInt(fh, inactiveAnim.currentFrame);
        FileHelper::writeFloat(fh, inactiveAnim.tracker.time);
        FileHelper::writeFloat(fh, inactiveAnim.tracker.current_time);
        FileHelper::writeInt(fh, inactiveAnim.tracker.running);
        FileHelper::writeInt(fh, inactiveAnim.tracker.done);
        FileHelper::writeFloat(fh, inactiveAnim.tracker.loopDelay);
        FileHelper::writeFloat(fh, inactiveAnim.tracker.currentDelay);
    }

    FileHelper::writeInt(fh, actionTimers.size());
    for (TimerHelper &timer : actionTimers)
    {
        FileHelper::writeInt(fh, timer.maxTime);
        FileHelper::writeInt(fh, timer.minTime);
        FileHelper::writeFloat(fh, timer.currTime);
        FileHelper::writeFloat(fh, timer.currGoal);
        FileHelper::writeInt(fh, timer.loop);
        FileHelper::writeInt(fh, timer.running);
    }
}

void CustomBackgroundObjectManager::CreateObject(CustomBackgroundObjectDefinition *def)
{
    CreateObject(def, def->spawnArea);
}

void CustomBackgroundObjectManager::CreateObject(CustomBackgroundObjectDefinition *def, Globals::Rect rect)
{
    if (currentLocationIndex != -1)
    {
        backgroundObjects[currentLocationIndex].emplace_back(def);

        CustomBackgroundObject &backgroundObject = backgroundObjects[currentLocationIndex].back();

        if (rect.w == 0)
        {
            backgroundObject.position.x = rect.x;
        }
        else
        {
            backgroundObject.position.x = rect.x + random32()%(rect.w+1);
        }

        if (rect.h == 0)
        {
            backgroundObject.position.y = rect.y;
        }
        else
        {
            backgroundObject.position.y = rect.y + random32()%(rect.h+1);
        }

        backgroundObject.bActive = def->active;

        backgroundObject.OnInit();

        CustomBackgroundObjectManager::instance->needSort = true;
    }
}

void CustomBackgroundObjectManager::ClearObjects(const std::string &name)
{
    if (name.empty())
    {
        backgroundObjects[currentLocationIndex].clear();
    }
    else
    {
        backgroundObjects[currentLocationIndex].erase(std::remove_if(backgroundObjects[currentLocationIndex].begin(),
                                                      backgroundObjects[currentLocationIndex].end(),
                                                      [&name](CustomBackgroundObject& obj) { return obj.def->name == name; }),
                                                      backgroundObjects[currentLocationIndex].end());
    }
}

void CustomBackgroundObjectManager::TransformObjects(const std::string &name1, const std::string &name2)
{
    CustomBackgroundObjectDefinition *newDef = namedDefs[name2];
    if (newDef)
    {
        for (CustomBackgroundObject &obj : backgroundObjects[currentLocationIndex])
        {
            if (obj.def->name == name1)
            {
                obj.Transform(newDef);
            }
        }
        CustomBackgroundObjectManager::instance->needSort = true;
    }
}

void CustomBackgroundObjectManager::Sort()
{
    std::stable_sort(backgroundObjects[currentLocationIndex].begin(), backgroundObjects[currentLocationIndex].end(),
    [](const CustomBackgroundObject &a, const CustomBackgroundObject &b) -> bool
    {
        if (a.def->layer == b.def->layer)
        {
            return a.def->z < b.def->z;
        }
        return a.def->layer < b.def->layer;
    });
    needSort = false;
}

void CustomBackgroundObject::Transform(CustomBackgroundObjectDefinition *_def)
{
    def = _def;
    OnInit();
}

void CustomBackgroundObject::OnInit()
{
    anim = G_->GetAnimationControl()->GetAnimation(def->anim.anim);
    anim.position = def->centerAnim ? Pointf(position.x - anim.info.frameWidth / 2, position.y - anim.info.frameHeight / 2) : Pointf(position.x, position.y);
    anim.tracker.loop = def->anim.loop;
    if (def->anim.random)
    {
        anim.RandomStart();
    }
    else
    {
        anim.Start(true);
    }

    hitbox.w = def->hitbox.w == -1 ? anim.info.frameWidth : def->hitbox.w;
    hitbox.h = def->hitbox.h == -1 ? anim.info.frameHeight : def->hitbox.h;

    hitbox.x = anim.position.x + def->hitbox.x;
    hitbox.y = anim.position.y + def->hitbox.y;
    if (def->centerHitbox) // align center of hitbox to center of anim
    {
        hitbox.x += (anim.info.frameWidth - hitbox.w)/2;
        hitbox.y += (anim.info.frameHeight - hitbox.h)/2;
    }

    hasHoverAnim = !def->hoverAnim.anim.empty();

    if (hasHoverAnim)
    {
        hoverAnim = G_->GetAnimationControl()->GetAnimation(def->hoverAnim.anim);
        hoverAnim.position = def->centerAnim ? Pointf(position.x - hoverAnim.info.frameWidth / 2, position.y - hoverAnim.info.frameHeight / 2) : Pointf(position.x, position.y);
        hoverAnim.tracker.loop = def->hoverAnim.loop;
        if (def->hoverAnim.random)
        {
            hoverAnim.RandomStart();
        }
        else
        {
            hoverAnim.Start(true);
        }
    }

    hasInactiveAnim = !def->inactiveAnim.anim.empty();

    if (hasInactiveAnim)
    {
        inactiveAnim = G_->GetAnimationControl()->GetAnimation(def->inactiveAnim.anim);
        inactiveAnim.position = def->centerAnim ? Pointf(position.x - inactiveAnim.info.frameWidth / 2, position.y - inactiveAnim.info.frameHeight / 2) : Pointf(position.x, position.y);
        inactiveAnim.tracker.loop = def->inactiveAnim.loop;
        if (def->inactiveAnim.random)
        {
            inactiveAnim.RandomStart();
        }
        else
        {
            inactiveAnim.Start(true);
        }
    }

    actionTimers.clear();
    for (CustomBackgroundObjectTimer &timerDef : def->timerActions)
    {
        actionTimers.emplace_back();
        TimerHelper &timer = actionTimers.back();
        if (timerDef.time != -1.f)
        {
            timer.minTime = timerDef.time * 1000;
            timer.maxTime = timer.minTime;
        }
        else
        {
            timer.minTime = timerDef.minTime;
            timer.maxTime = timerDef.maxTime;
        }
        timer.loop = timerDef.loop;
        timer.Start(timerDef.time);
    }
}

bool CustomBackgroundObject::OnLoop()
{
    if (!def->req.empty())
    {
        ShipManager* player = G_->GetShipManager(0);

        if (player)
        {
            advancedCheckEquipment[3] = true;
            int reqLvl = player->HasEquipment(def->req);
            reqActive = (reqLvl >= def->lvl && reqLvl <= def->max_lvl);
            advancedCheckEquipment[3] = false;
        }
    }
    else
    {
        reqActive = true;
    }

    bool play;

    if (!IsActive())
    {
        play = def->inactiveAnim.play;
    }
    else if (bHover)
    {
        play = def->hoverAnim.play;
    }
    else
    {
        play = def->anim.play;
    }

    if (play)
    {
        anim.Update();

        if (hasHoverAnim)
        {
            hoverAnim.Update();
        }
        if (hasInactiveAnim)
        {
            inactiveAnim.Update();
        }

        if (def->hasAnimAction && anim.tracker.done)
        {
            int8_t status = Activate(def->animAction);
            if (status == CustomBackgroundObjectAction::RESULT::DESTROYED) return true;
            if (status == CustomBackgroundObjectAction::RESULT::RESET) return false;
        }
    }

    for (int i=0; i<actionTimers.size(); ++i)
    {
        TimerHelper &timer = actionTimers[i];
        CustomBackgroundObjectTimer &timerDef = def->timerActions[i];

        if ((timerDef.requireActive == -1 || IsActive() == timerDef.requireActive) &&
            (timerDef.requireHover == -1 || bHover == timerDef.requireHover))
        {
            timer.Update();
            if (timer.Done())
            {
                int8_t status = Activate(def->timerActions[i].action);
                if (status == CustomBackgroundObjectAction::RESULT::DESTROYED) return true;
                if (status == CustomBackgroundObjectAction::RESULT::RESET) break;
            }
        }
    }

    return false;
}

void CustomBackgroundObjectManager::OnLoop()
{
    if (needSort) Sort();
    for (auto it = backgroundObjects[currentLocationIndex].begin(); it != backgroundObjects[currentLocationIndex].end(); )
    {
        bool destroyed = it->OnLoop();
        if (destroyed)
        {
            it = backgroundObjects[currentLocationIndex].erase(it);
        }
        else
        {
            ++it;
        }
    }
}

HOOK_METHOD(SpaceManager, OnLoop, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> SpaceManager::OnLoop -> Begin (CustomBackgroundObject.cpp)\n")
    super();

    CustomBackgroundObjectManager *bgM = CustomBackgroundObjectManager::instance;
    if (bgM->currentLocationIndex != -1 && !bgM->backgroundObjects[bgM->currentLocationIndex].empty())
    {
        bgM->OnLoop();
    }
}

void CustomBackgroundObject::OnRender(int layer, GL_Color &tint)
{
    if (layer == def->layer)
    {
        if (!IsActive())
        {
            if (def->hideInactive)
            {

            }
            else if (hasInactiveAnim)
            {
                inactiveAnim.OnRender(1.f, tint, false);
            }
            else
            {
                anim.OnRender(1.f, tint, false);
            }
        }
        else if (hasHoverAnim && bHover)
        {
            hoverAnim.OnRender(1.f, tint, false);
        }
        else
        {
            anim.OnRender(1.f, tint, false);
        }
    }
}

void CustomBackgroundObjectManager::OnRender(SpaceManager *space, int layer)
{
    float shipDamage = 1.f - space->shipHealth;
    GL_Color tint;
    if (space->gamePaused)
    {
        tint.r = shipDamage * 0.4f + 0.4f;
        tint.g = 0.4f;
    }
    else
    {
        tint.r = 1.f;
        tint.g = 1.f - shipDamage*shipDamage*0.5f;
    }
    tint.b = tint.g;
    tint.a = 1.f;

    for (CustomBackgroundObject &backgroundObject : backgroundObjects[currentLocationIndex])
    {
        backgroundObject.OnRender(layer, tint);
    }
}

HOOK_METHOD(SpaceManager, OnRenderBackground, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> SpaceManager::OnRenderBackground -> Begin (CustomBackgroundObject.cpp)\n")
    super();

    CustomBackgroundObjectManager *bgM = CustomBackgroundObjectManager::instance;
    if (bgM->currentLocationIndex != -1 && !bgM->backgroundObjects[bgM->currentLocationIndex].empty())
    {
        bgM->OnRender(this, CustomBackgroundObjectDefinition::LAYER::LAYER_BACKGROUND);
    }
}

HOOK_METHOD(SpaceManager, OnRenderForeground, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> SpaceManager::OnRenderForeground -> Begin (CustomBackgroundObject.cpp)\n")
    super();

    CustomBackgroundObjectManager *bgM = CustomBackgroundObjectManager::instance;
    if (bgM->currentLocationIndex != -1 && !bgM->backgroundObjects[bgM->currentLocationIndex].empty())
    {
        bgM->OnRender(this, CustomBackgroundObjectDefinition::LAYER::LAYER_FOREGROUND);
    }
}

HOOK_METHOD(SpaceManager, OnRenderAsteroids, (int layers, float alpha) -> void)
{
    LOG_HOOK("HOOK_METHOD -> SpaceManager::OnRenderAsteroids -> Begin (CustomBackgroundObject.cpp)\n")
    super(layers, alpha);

    CustomBackgroundObjectManager *bgM = CustomBackgroundObjectManager::instance;
    if (bgM->currentLocationIndex != -1 && !bgM->backgroundObjects[bgM->currentLocationIndex].empty())
    {
        bgM->OnRender(this, layers == 3 ? CustomBackgroundObjectDefinition::LAYER::LAYER_ASTEROIDS : CustomBackgroundObjectDefinition::LAYER::LAYER_FRONT);
    }
}

HOOK_METHOD(CommandGui, RenderPlayerShip, (Point &shipCenter, float jumpScale) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CommandGui::RenderPlayerShip -> Begin (CustomBackgroundObject.cpp)\n")
    CustomBackgroundObjectManager *bgM = CustomBackgroundObjectManager::instance;
    if (bgM->currentLocationIndex != -1 && !bgM->backgroundObjects[bgM->currentLocationIndex].empty())
    {
        // LAYER_PLAYER
        CSurface::GL_PushMatrix();
        if (jumpScale != 1.f)
        {
            CSurface::GL_Translate(shipCenter.x, shipCenter.y, 0.f);
            CSurface::GL_Scale(jumpScale, jumpScale, 1.f);
            CSurface::GL_Translate(-shipCenter.x, -shipCenter.y, 0.f);
        }
        CSurface::GL_Translate(shipPosition.x, shipPosition.y, 0.f);
        bgM->OnRender(space, CustomBackgroundObjectDefinition::LAYER::LAYER_PLAYER);
        CSurface::GL_PopMatrix();

        super(shipCenter, jumpScale);

        // LAYER_PLAYERFRONT
        CSurface::GL_PushMatrix();
        if (jumpScale != 1.f)
        {
            CSurface::GL_Translate(shipCenter.x, shipCenter.y, 0.f);
            CSurface::GL_Scale(jumpScale, jumpScale, 1.f);
            CSurface::GL_Translate(-shipCenter.x, -shipCenter.y, 0.f);
        }
        CSurface::GL_Translate(shipPosition.x, shipPosition.y, 0.f);
        bgM->OnRender(space, CustomBackgroundObjectDefinition::LAYER::LAYER_PLAYERFRONT);
        CSurface::GL_PopMatrix();
    }
    else
    {
        super(shipCenter, jumpScale);
    }
}

bool CustomBackgroundObject::MouseMove(CombatControl *combatControl, int mX, int mY)
{
    if (def->layer == CustomBackgroundObjectDefinition::LAYER::LAYER_PLAYER || def->layer == CustomBackgroundObjectDefinition::LAYER::LAYER_PLAYERFRONT)
    {
        mX -= combatControl->playerShipPosition.x;
        mY -= combatControl->playerShipPosition.y;
    }

    bool ret = mX > hitbox.x && mX < hitbox.x + hitbox.w && mY > hitbox.y && mY < hitbox.y + hitbox.h;
    bHover = ret && IsActive();
    return ret;
}

bool CustomBackgroundObjectManager::MouseMove(CombatControl *combatControl, int mX, int mY)
{
    if (needSort) Sort();

    int ret = false;

    auto it = backgroundObjects[currentLocationIndex].rbegin();

    // Loop to find the first object that is either clickable or has a hover tooltip
    for (; it != backgroundObjects[currentLocationIndex].rend(); ++it)
    {
        if (it->MouseMove(combatControl, mX, mY))
        {
            ret = it->bHover && it->def->hasClickAction;
            TextString &tooltip = it->IsActive() ? it->def->tooltip : it->def->inactiveTooltip;
            if (!tooltip.data.empty())
            {
                G_->GetMouseControl()->SetTooltip(tooltip.GetText());
                ++it;
                break;
            }
            if (ret)
            {
                ++it;
                break;
            }
        }
    }

    // If we already found a hover tooltip but not a clickable object, loop for the first clickable object
    if (!ret)
    {
        for (; it != backgroundObjects[currentLocationIndex].rend(); ++it)
        {
            if (it->MouseMove(combatControl, mX, mY))
            {
                if (it->bHover && it->def->hasClickAction)
                {
                    ret = true;
                    TextString &tooltip = it->IsActive() ? it->def->tooltip : it->def->inactiveTooltip;
                    if (!tooltip.data.empty())
                    {
                        G_->GetMouseControl()->SetTooltip(tooltip.GetText());
                    }
                    ++it;
                    break;
                }
            }
        }
    }

    // Any objects behind the clickable object are masked
    for (; it != backgroundObjects[currentLocationIndex].rend(); ++it)
    {
        it->bHover = false;
    }

    return ret;
}

HOOK_METHOD(CombatControl, MouseMove, (int mX, int mY) -> bool)
{
    LOG_HOOK("HOOK_METHOD -> CombatControl::MouseMove -> Begin (CustomBackgroundObject.cpp)\n")
    bool ret = super(mX, mY);

    if (!ret)
    {
        CustomBackgroundObjectManager *bgM = CustomBackgroundObjectManager::instance;
        if (bgM->currentLocationIndex != -1 && !bgM->backgroundObjects[bgM->currentLocationIndex].empty())
        {
            bgM->mouseActive = true;
            return bgM->MouseMove(this, mX, mY);
        }
    }
    else
    {
        CustomBackgroundObjectManager::instance->mouseActive = false;
    }

    return ret;
}

int8_t CustomBackgroundObject::Activate(CustomBackgroundObjectAction &action)
{

    if (!action.event.empty() && !G_->GetWorld()->playerShip->shipManager->bJumping)
    {
        // todo: seeded
        eventQueue.push_back({action.event, -1});
    }

    int8_t status = CustomBackgroundObjectAction::RESULT::NOCHANGE;

    switch (action.selfOp)
    {
    case CustomBackgroundObjectAction::SELFOP::DESTROY:
        status = CustomBackgroundObjectAction::RESULT::DESTROYED;
        break;
    case CustomBackgroundObjectAction::SELFOP::ACTIVATE:
        bActive = true;
        break;
    case CustomBackgroundObjectAction::SELFOP::DEACTIVATE:
        bActive = false;
        break;
    case CustomBackgroundObjectAction::SELFOP::TOGGLEACTIVE:
        bActive = !bActive;
        break;
    }

    for (auto &spawnObject : action.spawnObjects)
    {
        CustomBackgroundObjectManager::instance->CreateObject(spawnObject.first, spawnObject.second);
    }

    if (status != CustomBackgroundObjectAction::RESULT::DESTROYED)
    {
        CustomBackgroundObjectDefinition *newDef = action.GetRandomNewDef();
        if (newDef)
        {
            status = CustomBackgroundObjectAction::RESULT::RESET;
            Transform(newDef);
            CustomBackgroundObjectManager::instance->needSort = true;
        }
    }

    return status;
}

void CustomBackgroundObjectManager::MouseClick()
{
    int ret = false;

    for (auto it = backgroundObjects[currentLocationIndex].begin(); it != backgroundObjects[currentLocationIndex].end(); ++it)
    {
        if (it->bHover && it->def->hasClickAction && it->IsActive())
        {
            int8_t status = it->Activate(it->def->clickAction);
            if (status == CustomBackgroundObjectAction::RESULT::DESTROYED)
            {
                backgroundObjects[currentLocationIndex].erase(it);
            }
            break;
        }
    }

    if (needSort) Sort();
}

HOOK_METHOD(CombatControl, MouseClick, (int mX, int mY, bool shift) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CombatControl::MouseClick -> Begin (CustomBackgroundObject.cpp)\n")
    super(mX, mY, shift);

    CustomBackgroundObjectManager *bgM = CustomBackgroundObjectManager::instance;
    if (bgM->mouseActive)
    {
        bool isHover = bgM->MouseMove(this, mX, mY);
        if (isHover) bgM->MouseClick();
    }
}
