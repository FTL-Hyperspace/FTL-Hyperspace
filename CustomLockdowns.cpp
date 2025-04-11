#include "Global.h"
#include "CustomLockdowns.h"
#include "Resources.h"
#include <boost/lexical_cast.hpp>
/*
    TODO:
        Lua exposures and LockdownRoom overload
*/

CustomLockdownDefinition CustomLockdownDefinition::defaultLockdown(12.f, 50, GL_Color(1.f, 1.f, 1.f, 1.f), {"crystal_1", "crystal_2"}); //Default lockdown value from vanilla
CustomLockdownDefinition* CustomLockdownDefinition::currentLockdown = &CustomLockdownDefinition::defaultLockdown; //Default lockdown value from vanilla

void CustomLockdownDefinition::ParseNode(rapidxml::xml_node<char> *node)
{
    for (auto child = node->first_node(); child; child = child->next_sibling())
    {
        std::string nodeName = child->name();
        if (nodeName == "duration")
        {
            duration = boost::lexical_cast<float>(child->value());
        }
        else if (nodeName == "health")
        {
            health = boost::lexical_cast<int>(child->value());
        }
        else if (nodeName == "color")
        {
            ParseColorNode(color, child, true);
        }
        else if (nodeName == "anims")
        {
            anims.clear();
            for (auto animChild = child->first_node(); animChild; animChild = animChild->next_sibling())
            {
                anims.emplace_back(animChild->value());
            }
        }
    }
}
//Extend classes
HOOK_METHOD_PRIORITY(Door, constructor, 900, (int roomId1, int roomId2, int locX, int locY, bool bVertical, int doorId, int shipId) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> Door::constructor -> Begin (CustomLockdowns.cpp)\n")
	super(roomId1, roomId2, locX, locY, bVertical, doorId, shipId);

	auto ex = new Door_Extend();


    uintptr_t dEx = (uintptr_t)ex;

#ifdef __amd64__
    gap_ex_1[2] = (dEx >> 56) & 0xFF;
    gap_ex_1[3] = (dEx >> 48) & 0xFF;
    gap_ex_2[2] = (dEx >> 40) & 0xFF;
    gap_ex_2[3] = (dEx >> 32) & 0xFF;
#endif // __amd64__
	gap_ex_1[0] = (dEx >> 24) & 0xFF;
	gap_ex_1[1] = (dEx >> 16) & 0xFF;
	gap_ex_2[0] = (dEx >> 8) & 0xFF;
	gap_ex_2[1] = dEx & 0xFF;
	ex->orig = this;


}

HOOK_METHOD_PRIORITY(Door, destructor, 900, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> Door::destructor -> Begin (CustomLockdowns.cpp)\n")
    delete DOOR_EX(this);
    super();
}

Door_Extend* Get_Door_Extend(Door* c)
{
    uintptr_t dEx = 0;
#ifdef __amd64__
    dEx <<= 8;
    dEx |= c->gap_ex_1[2];
    dEx <<= 8;
    dEx |= c->gap_ex_1[3];
    dEx <<= 8;
    dEx |= c->gap_ex_2[2];
    dEx <<= 8;
    dEx |= c->gap_ex_2[3];
#endif // __amd64__
    dEx <<= 8;
    dEx |= c->gap_ex_1[0];
    dEx <<= 8;
    dEx |= c->gap_ex_1[1];
    dEx <<= 8;
    dEx |= c->gap_ex_2[0];
    dEx <<= 8;
    dEx |= c->gap_ex_2[1];

    return (Door_Extend*)dEx;
}
void LockdownShard::Initialize(bool loading, bool superFreeze)
{
    auto ex = new LockdownShard_Extend();
    uintptr_t dEx = (uintptr_t)ex;

    #ifdef __amd64__
        gap_ex_1[0] = (dEx >> 56) & 0xFF;
        gap_ex_1[1] = (dEx >> 48) & 0xFF;
        gap_ex_2[0] = (dEx >> 40) & 0xFF;
        gap_ex_2[1] = (dEx >> 32) & 0xFF;
        gap_ex_2[2] = (dEx >> 24) & 0xFF;
        gap_ex_3[0] = (dEx >> 16) & 0xFF;
        gap_ex_3[1] = (dEx >> 8) & 0xFF;
        gap_ex_3[2] = dEx & 0xFF;
    #else
        gap_ex_1[0] = (dEx >> 24) & 0xFF;
        gap_ex_1[1] = (dEx >> 16) & 0xFF;
        gap_ex_2[0] = (dEx >> 8) & 0xFF;
        gap_ex_2[1] = dEx & 0xFF;
    #endif // __amd64__

    if (!loading)
    {
        lifeTime = CustomLockdownDefinition::currentLockdown->duration;
        ex->color = CustomLockdownDefinition::currentLockdown->color;
        const auto& anims = CustomLockdownDefinition::currentLockdown->anims;
        if (!anims.empty()) ex->anim = anims[superFreeze ? 0 : random32() % anims.size()];
        else //Default vanilla anims
        {
            if (superFreeze) ex->anim = "crystal_1";
            else ex->anim = random32() % 2 == 0 ? "crystal_1" : "crystal_2";
        }
        shard = G_->GetAnimationControl()->GetAnimation(ex->anim);
    }
}

void LockdownShard::LinkDoor(Door* door)
{
    LockdownShard_Extend* ex = LD_EX(this);
    ex->door = door;
    if (door != nullptr) ex->doorId = door->iDoorId;
}

HOOK_METHOD_PRIORITY(LockdownShard, constructor, 900, (int lockingRoom, Pointf start, Point goal, bool superFreeze) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> LockdownShard::constructor -> Begin (CustomLockdowns.cpp)\n")
	super(lockingRoom, start, goal, superFreeze);

	Initialize(false, superFreeze);
}

HOOK_METHOD_PRIORITY(LockdownShard, constructor2, 900, (int lockingRoom, Pointf start, Point goal, bool superFreeze) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> LockdownShard::constructor2 -> Begin (CustomLockdowns.cpp)\n")
	super(lockingRoom, start, goal, superFreeze);

	Initialize(false, superFreeze);
}

HOOK_METHOD_PRIORITY(LockdownShard, constructor3, 900, (int fd) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> LockdownShard::constructor3 -> Begin (CustomLockdowns.cpp)\n")
	super(fd);

	Initialize(true, this->superFreeze);
}

LockdownShard_Extend* Get_LockdownShard_Extend(LockdownShard* c)
{
    uintptr_t dEx = 0;

#ifdef __amd64__
    dEx <<= 8;
    dEx |= c->gap_ex_1[0];
    dEx <<= 8;
    dEx |= c->gap_ex_1[1];
    dEx <<= 8;
    dEx |= c->gap_ex_2[0];
    dEx <<= 8;
    dEx |= c->gap_ex_2[1];
    dEx <<= 8;
    dEx |= c->gap_ex_2[2];
    dEx <<= 8;
    dEx |= c->gap_ex_3[0];
    dEx <<= 8;
    dEx |= c->gap_ex_3[1];
    dEx <<= 8;
    dEx |= c->gap_ex_3[2];
#else
    dEx <<= 8;
    dEx |= c->gap_ex_1[0];
    dEx <<= 8;
    dEx |= c->gap_ex_1[1];
    dEx <<= 8;
    dEx |= c->gap_ex_2[0];
    dEx <<= 8;
    dEx |= c->gap_ex_2[1];
#endif // __amd64__
    return (LockdownShard_Extend*)dEx;
}


//Vanilla code starts lifeTime at 0 and counts up, but we will start at the duration and count down
HOOK_METHOD_PRIORITY(LockdownShard, Update, 9999, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> LockdownShard::Update -> Begin (CustomLockdowns.cpp)\n")
    lifeTime -= G_->GetCFPS()->GetSpeedFactor() / 16;
    if (position != goal)
    {
        position = Globals::GetNextPoint(position, speed, goal);
        if (position == goal)
        {
            bArrived = true;
            shard.Start(true);
        }
    }

    if (bArrived)
    {
        shard.Update();
        if (shard.Done() && (!superFreeze || lifeTime <= 0.5))
        {
            if (shard.tracker.reverse)
            {
                bDone = true;
            }
            else
            {
                shard.tracker.time = lifeTime;
                shard.StartReverse(true);
            }
        }
    }
}

HOOK_METHOD_PRIORITY(Ship, LockdownRoom, 9999, (int roomId, Pointf pos) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> Ship::LockdownRoom -> Begin (CustomLockdowns.cpp)\n")

    CustomLockdownDefinition* old = CustomLockdownDefinition::currentLockdown;
    if (CustomDamageManager::currentWeaponDmg != nullptr)
    {
        CustomLockdownDefinition::currentLockdown = &CustomDamageManager::currentWeaponDmg->def->customLockdown;
    }

    ShipGraph* graph = ShipGraph::GetShipInfo(iShipId);
    Globals::Rect shape = graph->GetRoomShape(roomId);
    for (int idx = 0; idx < (shape.w / 35) * 3; ++idx)
    {
        int baseX = shape.x + idx * 12;
        Point topGoal(baseX + random32() % 12, shape.y);
        Point bottomGoal(baseX + random32() % 12, shape.y + shape.h);

        //Add shards and link to doors if appropriate
        lockdowns.emplace_back(roomId, pos, topGoal, false);
        lockdowns.back().LinkDoor(HS_GetSelectedDoor(topGoal.x, topGoal.y, 1.f, true));
        lockdowns.emplace_back(roomId, pos, bottomGoal, false);
        lockdowns.back().LinkDoor(HS_GetSelectedDoor(bottomGoal.x, bottomGoal.y, 1.f, true));
    }

    for (int idx = 0; idx < (shape.h / 35) * 3; ++idx)
    {
        int baseY = shape.y + idx * 12;
        Point leftGoal(shape.x, baseY + random32() % 12);
        Point rightGoal(shape.x + shape.w, baseY + random32() % 12);
        //Add shards and link to doors if appropriate
        lockdowns.emplace_back(roomId, pos, leftGoal, false);
        lockdowns.back().LinkDoor(HS_GetSelectedDoor(leftGoal.x, leftGoal.y, 1.f, true));
        lockdowns.emplace_back(roomId, pos, rightGoal, false);
        lockdowns.back().LinkDoor(HS_GetSelectedDoor(rightGoal.x, rightGoal.y, 1.f, true));
    }

    for (Door* door : vDoorList)
    {
        if (door->ConnectsRooms(roomId, -1))
        {
            door->SetLockdown(true);
            Point doorGoal = door->GetCenterPoint();
            lockdowns.emplace_back(roomId, pos, doorGoal, true);
            //lockdowns.back().superFreeze = true; //Constructor does not use superFreeze argument to actaully set superFreeze for some reason so we set it here so the shards do not fade

            LockdownShard_Extend* ld = LD_EX(&lockdowns.back());
            ld->health = CustomLockdownDefinition::currentLockdown->health; //Door shards will keep track of health, lifeTime is handled for all shards in the constructor
            lockdowns.back().LinkDoor(door);
        }
    }

    CustomLockdownDefinition::currentLockdown = old;
}


//We have to rewrite Ship::OnLoop because the vanilla doesnt keep the padding bytes when moving LockdownShards during vector reallocations
HOOK_METHOD_PRIORITY(Ship, OnLoop, 9999, (std::vector<float> &oxygenLevels) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> Ship::OnLoop -> Begin (CustomLockdowns.cpp)\n")
    cloakingTracker.Update();
    if (cloakingTracker.done) cloakingTracker.Stop(true);
    if (!explosion.bJumpOut || explosion.Progress(-1.f) <= 0.75)
    {
        explosion.Update();
        if (explosion.bJumpOut && explosion.Progress(-1.f) > 0.75)
        {
            shipImage = explosion.GetFinalGib();
            CSurface::GL_DestroyPrimitive(shipImagePrimitive);
            shipImagePrimitive = CSurface::GL_CreatePixelImagePrimitive(shipImage.tex, shipImage.x, shipImage.y, shipImage.w, shipImage.h, 0.f, GL_Color(1.f, 1.f, 1.f, 1.f), false);

        }
    }
    else
    {
        explosion.Update();
    }

    int hull = std::min(hullIntegrity.first, hullIntegrity.second);
    hull = std::max(hull, 0);
    hullIntegrity.first = hull;

    engineAnim[0].Update();
    engineAnim[1].Update();

    for (Door* door : vDoorList)
    {
        door->OnLoop();
        door->lockedDown.running = false; //Doors not locked down unless they have a locking shard
    }

    for (Door* door : vOuterAirlocks)
    {
        door->OnLoop();
    }

    for (int idx = 0; idx < vRoomList.size(); ++idx)
    {
        Room* room = vRoomList[idx];
        room->OnLoop();
        float oxygenLevel = oxygenLevels.empty() ? 0.f : oxygenLevels[idx];
        /* Begin: inline void SetO2Level(Room * this, float val) */
        room->lastO2 = oxygenLevel;
    }

    for (LockdownShard& shard : lockdowns)
    {
        shard.Update();
        LockdownShard_Extend* ex = LD_EX(&shard);
        if (ex->door != nullptr)
        {
            if (ex->health <= 0) shard.bDone = true; //Mark destroyed door shards for termination
            else ex->door->lockedDown.running = true; //If any shards are alive, the door is locked down
        }
    }

    //Move finished shards to the end of the vector
    auto it = std::partition(lockdowns.begin(), lockdowns.end(), [](const LockdownShard& shard){ return !shard.bDone;});
    //Manually delete extend objects here as LockdownShard does not have a destructor
    std::for_each(it, lockdowns.end(), [](LockdownShard& shard){
        delete LD_EX(&shard);
    });
    //Remove finished shards
    lockdowns.erase(it, lockdowns.end());

    //Doors that have been freed from lockdown have their health reset
    for (Door* door : vDoorList)
    {
        Door_Extend* ex = DOOR_EX(door);
        if (ex->wasLockedDown && !door->lockedDown.running) //If the door was locked down and is no longer locked down, reset the health
        {
            door->SetLockdown(false);
        }
    }

    for (OuterHull* hull : vOuterWalls)
    {
        hull->OnLoop();
    }
}


//References to SetLockdown:
//Door::OnLoop
//Ship::LockdownRoom
//Door::ApplyDamage
//Vanilla code uses an AnimationTracker to indicate lockdown state, but with multiple lockdown types this approach no longer works
//SetLockdown has been entirely rewritten as lockdown health is now tracked in LockdownShards
HOOK_METHOD_PRIORITY(Door, SetLockdown, 9999, (bool val) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> Door::SetLockdown -> Begin (CustomLockdowns.cpp)\n")
    /*
    Vanilla code:
    if (val)
    {
        lockedDown.Start(0.0);
        baseHealth = 50;
        health = 50;
    }
    else
    {
        lockedDown.Stop(false);
        baseHealth = lastbase;
        health = lastbase;
    }
    */
   if (val)
   {
        lockedDown.running = true;
        DOOR_EX(this)->wasLockedDown = true;
        //Health is handled by individual shards now
        baseHealth = INT_MAX;
        health = INT_MAX;
   }
   else
   {
        lockedDown.running = false;
        DOOR_EX(this)->wasLockedDown = false;
        baseHealth = lastbase;
        health = lastbase;
   }
}

HOOK_METHOD_PRIORITY(Door, OnLoop, 9999, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> Door::OnLoop -> Begin (CustomLockdowns.cpp)\n")
    if (iHacked < 1)
    {
        SetBlastDoor(doorLevel);
    }
    else
    {
        SetBlastDoor(iHacked + 2);
        bOpen = false;
        StartAnimIfNecessary();
    }
    forcedOpen.Update();
    if (forcedOpen.done) forcedOpen.Stop(false);

    /*Vanilla code
        lockedDown.Update();
        if (lockedDown.running && lockedDown.done) SetLockdown(false);

    */

    fakeOpenTimer += G_->GetCFPS()->GetSpeedFactor() / 16;
    if (fakeOpenTimer > 1.f) bFakeOpen = false;
    UpdateAnimations();
}

HOOK_METHOD_PRIORITY(LockdownShard, OnRender, 9999, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> LockdownShard::OnRender -> Begin (CustomLockdowns.cpp)\n")
    CSurface::GL_PushMatrix();
    CSurface::GL_Translate(position.x - 9.0, position.y - 14.0);
    shard.OnRender(1.f, LD_EX(this)->color, false);
    CSurface::GL_PopMatrix();
}

//Reverse inlining of LockdownShard::OnRender
HOOK_METHOD_PRIORITY(Ship, OnRenderWalls, 9999, (bool forceView, bool doorControlMode) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> Ship::OnRenderWalls -> Begin (CustomLockdowns.cpp)\n")
    for (Room* room : vRoomList)
    {
        float alpha = GetCloakAlpha(false);
        room->OnRenderWalls(alpha);
    }
    CSurface::GL_RenderPrimitive(wallsPrimitive);
    UpdateDoorsPrimitive(doorControlMode);
    float alpha = GetCloakAlpha(doorControlMode);
    CSurface::GL_RenderPrimitiveWithAlpha(doorsPrimitive, alpha);
    for (int idx = 0; idx < vDoorList.size(); ++idx)
    {
        if (doorState[idx].state == DOOR_ANIMATING)
        {
            float alpha = GetCloakAlpha(false);
            vDoorList[idx]->OnRender(alpha, forceView, doorControlMode);
        }
    }

    for (int idx = 0; idx < vOuterAirlocks.size(); ++idx)
    {
        if (doorState[idx + vDoorList.size()].state == DOOR_ANIMATING)
        {
            float alpha = GetCloakAlpha(false);
            vOuterAirlocks[idx]->OnRender(alpha, forceView, doorControlMode);
        }
    }

    for (LockdownShard& shard : lockdowns)
    {
        shard.OnRender();
    }
}


//Save/Load support
HOOK_METHOD(LockdownShard, SaveState, (int fd) -> void)
{
    LOG_HOOK("HOOK_METHOD -> LockdownShard::SaveState -> Begin (CustomLockdowns.cpp)\n")
    super(fd);
    shard.tracker.SaveState(fd);

    LockdownShard_Extend* ex = LD_EX(this);
    FileHelper::writeInt(fd, ex->health);
    FileHelper::writeInt(fd, ex->doorId);
    ex->color.SaveState(fd);
    FileHelper::writeString(fd, ex->anim);
}

HOOK_METHOD(LockdownShard, constructor3, (int fd) -> void)
{
    LOG_HOOK("HOOK_METHOD -> LockdownShard::constructor3 -> Begin (CustomLockdowns.cpp)\n")
	super(fd);

    //Vanilla code for animation setup has assumptions about the duration of a lockdown so we just load the AnimationTracker state here
    shard.tracker.LoadState(fd);

    LockdownShard_Extend* ex = LD_EX(this);
    ex->health = FileHelper::readInteger(fd);
    ex->doorId = FileHelper::readInteger(fd);
    ex->color.LoadState(fd);
    ex->anim = FileHelper::readString(fd);
    shard = G_->GetAnimationControl()->GetAnimation(ex->anim);
}


//Ship::LoadState rewrite is necessary because of vector reallocations for lockdowns messing with the extend bytes in native code
HOOK_METHOD_PRIORITY(Ship, LoadState, 9999, (int fd) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> Ship::LoadState -> Begin (CustomLockdowns.cpp)\n")

    if (G_->GetSettings()->loadingSaveVersion < 3)
    {
        for (Door* door : vDoorList)
        {
            bool doorOpen = FileHelper::readInteger(fd) == 1;
            bool doorFakeOpen = FileHelper::readInteger(fd) == 1;
            if (doorOpen) door->Open();
            if (doorFakeOpen) door->FakeOpen();
            door->AccelerateAnimation();
        }

        for (Door* door : vOuterAirlocks)
        {
            bool doorOpen = FileHelper::readInteger(fd) == 1;
            bool doorFakeOpen = FileHelper::readInteger(fd) == 1;
            if (doorOpen) door->Open();
            if (doorFakeOpen) door->FakeOpen();
            door->AccelerateAnimation();
        }
    }
    else
    {
        for (Door* door : vDoorList)
        {
            door->LoadState(fd);
        }
        for (Door* door : vOuterAirlocks)
        {
            door->LoadState(fd);
        }
    }

    if (G_->GetSettings()->loadingSaveVersion > 4)
    {
        float cloakTime = FileHelper::readFloat(fd);
        cloakingTracker.SetCurrentTime(cloakTime);
    }
    if (G_->GetSettings()->loadingSaveVersion > 7)
    {
        int lockdownCount = FileHelper::readInteger(fd);
        lockdowns.reserve(lockdownCount);
        for (int i = 0; i < lockdownCount; ++i)
        {
            lockdowns.emplace_back(fd);
            LockdownShard_Extend* ex = LD_EX(&lockdowns.back());
            if (ex->doorId != -1) //If the shard is attached to a door, relink it
            {
                ex->door = GetDoorById(ex->doorId);
                ex->door->SetLockdown(true);
            }

        }
    }
}

void AnimationTracker::SaveState(int fd)
{
    FileHelper::writeFloat(fd, time);
    FileHelper::writeInt(fd, loop);
    FileHelper::writeFloat(fd, current_time);
    FileHelper::writeInt(fd, running);
    FileHelper::writeInt(fd, reverse);
    FileHelper::writeInt(fd, done);
    FileHelper::writeFloat(fd, loopDelay);
    FileHelper::writeFloat(fd, currentDelay);
};

void AnimationTracker::LoadState(int fd)
{
    time = FileHelper::readFloat(fd);
    loop = FileHelper::readInteger(fd);
    current_time = FileHelper::readFloat(fd);
    running = FileHelper::readInteger(fd);
    reverse = FileHelper::readInteger(fd);
    done = FileHelper::readInteger(fd);
    loopDelay = FileHelper::readFloat(fd);
    currentDelay = FileHelper::readFloat(fd);
};
