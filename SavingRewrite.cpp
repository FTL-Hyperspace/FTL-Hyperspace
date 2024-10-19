#include "Global.h"

HOOK_METHOD_PRIORITY(Animation, LoadState, 9999, (int fd) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> Animation::LoadState -> Begin (SavingRewrite.cpp)\n")
    
    // Reverse engineered Vanilla code by Dino
    if (FileHelper::readInteger(fd) != 0)
    {
        Start(true);
    }
    if (FileHelper::readInteger(fd) != 0)
    {
        tracker.loop = true;
        tracker.loopDelay = 0.f;
        tracker.currentDelay = 0.f;
    }
    currentFrame = FileHelper::readInteger(fd);
    tracker.current_time = FileHelper::readFloat(fd) * tracker.time;
    fScale = FileHelper::readFloat(fd);
    position.x = FileHelper::readFloat(fd);
    position.y = FileHelper::readFloat(fd);
    // End of orig code
}

HOOK_METHOD_PRIORITY(Animation, SaveState, 9999, (int fd) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> Animation::SaveState -> Begin (SavingRewrite.cpp)\n")
    
    // Reverse engineered Vanilla code by Dino
    FileHelper::writeInt(fd, tracker.running);
    FileHelper::writeInt(fd, tracker.loop);
    FileHelper::writeInt(fd, currentFrame);
    float val = 0.f;
    if ((tracker.running) && (val = tracker.current_time / tracker.time, val <= 0.f))
    {
        val = 0.f;
    }
    FileHelper::writeFloat(fd, val);
    FileHelper::writeFloat(fd, fScale);
    FileHelper::writeFloat(fd, position.x);
    FileHelper::writeFloat(fd, position.y);
    // End of orig code
}

/*
HOOK_METHOD_PRIORITY(BoarderPodDrone, LoadState, 9999, (int fd) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> BoarderPodDrone::LoadState -> Begin (SavingRewrite.cpp)\n")

    // Reverse engineered Vanilla code by Dino
    SpaceDrone::LoadState(fd);
    // BoarderPodDrone Values
    diedInSpace = FileHelper::readInteger(fd) != 0;
    bDeliveredDrone = FileHelper::readInteger(fd) != 0;
    startingPosition.x = FileHelper::readFloat(fd);
    startingPosition.y = FileHelper::readFloat(fd);

    // BoarderDrone specific values
    int droneHealth = FileHelper::readInteger(fd);
    int posX = FileHelper::readInteger(fd);
    int posY = FileHelper::readInteger(fd);
    int roomId = FileHelper::readInteger(fd);
    int slotId = FileHelper::readInteger(fd);

    if (bDeliveredDrone)
    {
        boarderDrone->droneRoom = roomId;
        boarderDrone->SetRoom(roomId);
        boarderDrone->SetPosition(Point(posX, posY));
        boarderDrone->MoveToRoom(roomId, slotId, true);
        boarderDrone->health.first = droneHealth;
        boarderDrone->SetPowered(boarderDrone->GetPowered());

        if (boarderDrone->GetPowered())
        {
            SetInstantPowered();
        }
    }
    // End of orig code
}
*/

HOOK_METHOD_PRIORITY(BoarderPodDrone, SaveState, 9999, (int fd) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> BoarderPodDrone::SaveState -> Begin (SavingRewrite.cpp)\n")

    // Reverse engineered Vanilla code by Dino
    SpaceDrone::SaveState(fd);
    FileHelper::writeInt(fd, diedInSpace);
    FileHelper::writeInt(fd, bDeliveredDrone);
    FileHelper::writeFloat(fd, startingPosition.x);
    FileHelper::writeFloat(fd, startingPosition.y);
    FileHelper::writeInt(fd, boarderDrone->GetIntegerHealth());
    FileHelper::writeInt(fd, boarderDrone->GetLocation().x);
    FileHelper::writeInt(fd, boarderDrone->GetLocation().y);
    FileHelper::writeInt(fd, boarderDrone->currentSlot.roomId);
    FileHelper::writeInt(fd, boarderDrone->currentSlot.slotId);
    // End of orig code
}

HOOK_METHOD_PRIORITY(CombatControl, SaveState, 9999, (int fd) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> CombatControl::SaveState -> Begin (SavingRewrite.cpp)\n")

    // Reverse engineered Vanilla code by Dino
    FileHelper::writeInt(fd, weapControl.autoFiring);
    // End of orig code
}

HOOK_METHOD_PRIORITY(CombatControl, LoadState, 9999, (int fd) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> CombatControl::LoadState -> Begin (SavingRewrite.cpp)\n")

    // Reverse engineered Vanilla code by Dino
    if (G_->GetSettings()->loadingSaveVersion < 7) return;
    weapControl.SetAutofiring(FileHelper::readInteger(fd) != 0, true);
    // End of orig code
}

HOOK_METHOD_PRIORITY(CombatDrone, SaveState, 9999, (int fd) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> CombatDrone::SaveState -> Begin (SavingRewrite.cpp)\n")

    // Reverse engineered Vanilla code by Dino
    SpaceDrone::SaveState(fd);
    FileHelper::writeFloat(fd, lastDestination.x);
    FileHelper::writeFloat(fd, lastDestination.y);
    FileHelper::writeFloat(fd, progressToDestination);
    FileHelper::writeFloat(fd, heading);
    FileHelper::writeFloat(fd, oldHeading);
    // End of orig code
}

HOOK_METHOD_PRIORITY(CombatDrone, LoadState, 9999, (int fd) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> CombatDrone::LoadState -> Begin (SavingRewrite.cpp)\n")

    // Reverse engineered Vanilla code by Dino
    SpaceDrone::LoadState(fd);
    lastDestination.x = FileHelper::readFloat(fd);
    lastDestination.y = FileHelper::readFloat(fd);
    progressToDestination = FileHelper::readFloat(fd);
    heading = FileHelper::readFloat(fd);
    oldHeading = FileHelper::readFloat(fd);
    // End of orig code
}

HOOK_METHOD_PRIORITY(CompleteShip, SaveState, 9999, (int fd) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> CompleteShip::SaveState -> Begin (SavingRewrite.cpp)\n")

    // Reverse engineered Vanilla code by Dino
    FileHelper::writeInt(fd, teleTargetRoom);
    // End of orig code
}

HOOK_METHOD_PRIORITY(CompleteShip, LoadState, 9999, (int fd) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> CompleteShip::LoadState -> Begin (SavingRewrite.cpp)\n")

    // Reverse engineered Vanilla code by Dino
    teleTargetRoom = FileHelper::readInteger(fd);

    shipManager->GetLeavingCrew(false);
    if (!leavingParty.empty()) leavingParty.clear();

    if (enemyShip != nullptr)
    {
        enemyShip->shipManager->GetLeavingCrew(true);
        if (!arrivingParty.empty()) arrivingParty.clear();
    }
    // End of orig code
}

// CrewDrone class has saving functions which simply return thus not actually doing anything.

HOOK_METHOD_PRIORITY(CrewMember, SaveState, 9999, (int fd) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> CrewMember::SaveState -> Begin (SavingRewrite.cpp)\n")

    // Save basic state variables
    FileHelper::writeFloat(fd, fStunTime);
    FileHelper::writeInt(fd, healthBoost);
    FileHelper::writeInt(fd, iDeathNumber);
    FileHelper::writeFloat(fd, fMindDamageBoost);
    FileHelper::writeInt(fd, static_cast<int>(fCloneDying));
    FileHelper::writeInt(fd, iDeathCount);

    // There are 6 skills, each having two bits storing level 1 & 2
    for (int8_t skillIndex = 0; skillIndex < 6; ++skillIndex)
    {
        // Make sure the vector has at least 6 elements
        if (skillIndex < skillsEarned.size())
        {
            // Save level 1
            FileHelper::writeInt(fd, static_cast<int>(skillsEarned[skillIndex][0]));
            // Save level 2
            FileHelper::writeInt(fd, static_cast<int>(skillsEarned[skillIndex][1]));
        }
        else
        {
            // If the skill doesn't exist, default to false
            FileHelper::writeInt(fd, 0);
            FileHelper::writeInt(fd, 0);
        }
    }

    crewAnim->SaveState(fd);

    // End of save logic
}

HOOK_METHOD_PRIORITY(CrewMember, LoadState, 9999, (int fd) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> CrewMember::LoadState -> Begin (SavingRewrite.cpp)\n")

    // Reverse engineered Vanilla code by Dino

    // Load basic state variables
    fStunTime = FileHelper::readFloat(fd);
    healthBoost = FileHelper::readInteger(fd);
    iDeathNumber = FileHelper::readInteger(fd);
    fMindDamageBoost = FileHelper::readFloat(fd);
    fCloneDying = static_cast<float>(FileHelper::readInteger(fd));
    iDeathCount = FileHelper::readInteger(fd);

    // Check the save to know if the skill level should be loaded (loading legacy saves)
    if (G_->GetSettings()->loadingSaveVersion > 7)
    {
        // There are 6 skills, each having two bits storing level 1 & 2
        for (int8_t skillIndex = 0; skillIndex < 6; ++skillIndex)
        {
            // Prepare skill vector for use
            if (skillIndex >= skillsEarned.size()) skillsEarned.emplace_back(std::vector<bool>(2, false));

            // Load the first chunk (level 1)
            skillsEarned[skillIndex][0] = (FileHelper::readInteger(fd) != 0);
            // Load the second chunk (level 2)
            skillsEarned[skillIndex][1] = (FileHelper::readInteger(fd) != 0);
        }
    }

    // Load crew animation state if the save version is above 4 (loading legacy saves)
    if (G_->GetSettings()->loadingSaveVersion > 4) crewAnim->LoadState(fd);

    // End of orig code
}

HOOK_METHOD_PRIORITY(CrewAnimation, SaveState, 9999, (int fd) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> CrewAnimation::SaveState -> Begin (SavingRewrite.cpp)\n")

    // Reverse engineered Vanilla code by Dino

    // Write the weird bool I don't understand the use of
    FileHelper::writeInt(fd, static_cast<int>(status == 6));

    // Save the state of the actual animation
    anims[0][6].SaveState(fd);

    // Save whether the animation is running in reverse
    FileHelper::writeInt(fd, static_cast<int>(anims[0][6].tracker.reverse));

    // End of orig code
}

HOOK_METHOD_PRIORITY(CrewAnimation, LoadState, 9999, (int fd) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> CrewAnimation::LoadState -> Begin (SavingRewrite.cpp)\n")

    // Reverse engineered Vanilla code by Dino

    // Checks some weird bool that was written if status == 6
    if (FileHelper::readInteger(fd) != 0)
    {
        status = 6;
        direction = 0;

        anims[0][6].tracker.SetLoop(false, 0.f);
        anims[0][6].Start(true);
    }
    
    // Load the animation itself
    anims[0][6].LoadState(fd);

    // Check if animation should be running in reverse (didn't even know FTL has this option?)
    if (FileHelper::readInteger(fd) != 0 && status == 6)
    {
        anims[0][6].StartReverse(false);
    }
    // End of orig code
}

// CrystalAlien Save/Load actually never runs (tested)
// Thus both functions won't need any lua support
HOOK_METHOD_PRIORITY(CrystalAlien, SaveState, 9999, (int fd) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> CrystalAlien::SaveState -> Begin (SavingRewrite.cpp)\n")

    // Reverse engineered Vanilla code by Dino
    CrewMember::SaveState(fd);
    FileHelper::writeFloat(fd, powerCooldown.first);
    FileHelper::writeFloat(fd, powerCooldown.second);
    FileHelper::writeInt(fd, static_cast<int>(bCloned));
    // End of orig code
}

HOOK_METHOD_PRIORITY(CrystalAlien, LoadState, 9999, (int fd) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> CrystalAlien::LoadState -> Begin (SavingRewrite.cpp)\n")

    // Reverse engineered Vanilla code by Dino
    CrewMember::LoadState(fd);
    powerCooldown.first = FileHelper::readFloat(fd);
    powerCooldown.second = FileHelper::readFloat(fd);
    bCloned = FileHelper::readInteger(fd) != 0;
    // End of orig code
}

HOOK_METHOD_PRIORITY(Door, SaveState, 9999, (int fd) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> Door::SaveState -> Begin (SavingRewrite.cpp)\n")

    // Reverse engineered Vanilla code by Dino
    FileHelper::writeInt(fd, baseHealth);
    FileHelper::writeInt(fd, health);
    FileHelper::writeInt(fd, static_cast<int>(lastbase));
    FileHelper::writeInt(fd, static_cast<int>(bOpen));
    FileHelper::writeInt(fd, static_cast<int>(bFakeOpen));
    FileHelper::writeInt(fd, iBlast);
    FileHelper::writeInt(fd, iHacked);
    // End of orig code
}

HOOK_METHOD_PRIORITY(Door, LoadState, 9999, (int fd) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> Door::LoadState -> Begin (SavingRewrite.cpp)\n")

    // Reverse engineered Vanilla code by Dino
    baseHealth = FileHelper::readInteger(fd);
    health = FileHelper::readInteger(fd);
    lastbase = static_cast<float>(FileHelper::readInteger(fd));
    bOpen = FileHelper::readInteger(fd) != 0;
    bFakeOpen = FileHelper::readInteger(fd) != 0;

    if (G_->GetSettings()->loadingSaveVersion > 4)
    {
        iBlast = FileHelper::readInteger(fd);
        iHacked = FileHelper::readInteger(fd);
    }

    if (!bOpen && !bFakeOpen)
    {
        doorAnim.SetCurrentFrame(0);
        doorAnimLarge.SetCurrentFrame(0);
        return;
    }

    doorAnim.SetCurrentFrame(4);
    doorAnimLarge.SetCurrentFrame(4);
    // End of orig code
}

HOOK_METHOD_PRIORITY(Drone, SaveState, 9999, (int fd) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> Drone::SaveState -> Begin (SavingRewrite.cpp)\n")

    // Reverse engineered Vanilla code by Dino
    FileHelper::writeFloat(fd, destroyedTimer);
    // End of orig code
}

HOOK_METHOD_PRIORITY(Drone, LoadState, 9999, (int fd) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> Drone::LoadState -> Begin (SavingRewrite.cpp)\n")

    // Reverse engineered Vanilla code by Dino
    destroyedTimer = FileHelper::readFloat(fd);
    // End of orig code
}

HOOK_METHOD_PRIORITY(HackingDrone, SaveState, 9999, (int fd) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> HackingDrone::SaveState -> Begin (SavingRewrite.cpp)\n")

    // Reverse engineered Vanilla code by Dino
    SpaceDrone::SaveState(fd);
    FileHelper::writeFloat(fd, finalDestination.x);
    FileHelper::writeFloat(fd, finalDestination.y);
    FileHelper::writeInt(fd, static_cast<int>(arrived));
    FileHelper::writeInt(fd, static_cast<int>(finishedSetup));
    flying.SaveState(fd);
    extending.SaveState(fd);
    // End of orig code
}

HOOK_METHOD_PRIORITY(HackingDrone, LoadState, 9999, (int fd) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> HackingDrone::LoadState -> Begin (SavingRewrite.cpp)\n")

    // Reverse engineered Vanilla code by Dino
    SpaceDrone::LoadState(fd);
    finalDestination.x = FileHelper::readFloat(fd);
    finalDestination.y = FileHelper::readFloat(fd);
    arrived = FileHelper::readInteger(fd) != 0;
    finishedSetup = FileHelper::readInteger(fd) != 0;
    flying.LoadState(fd);
    extending.LoadState(fd);
    // End of orig code
}

HOOK_METHOD_PRIORITY(HackingSystem, SaveState, 9999, (int fd) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> HackingSystem::SaveState -> Begin (SavingRewrite.cpp)\n")

    // Reverse engineered Vanilla code by Dino
    FileHelper::writeInt(fd, static_cast<int>(drone.powered));
    FileHelper::writeInt(fd, static_cast<int>(drone.deployed));
    FileHelper::writeInt(fd, static_cast<int>(bHacking));
    FileHelper::writeFloat(fd, effectTimer.first);
    FileHelper::writeFloat(fd, effectTimer.second);
    FileHelper::writeInt(fd, static_cast<int>(iLockCount == -1)); // Inlines function call GetLockCount()
    drone.SaveState(fd);
    // End of orig code
}

HOOK_METHOD_PRIORITY(HackingSystem, LoadState, 9999, (int fd) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> HackingSystem::LoadState -> Begin (SavingRewrite.cpp)\n")

    // Reverse engineered Vanilla code by Dino
    drone.powered = FileHelper::readInteger(fd) != 0;
    drone.SetDeployed(FileHelper::readInteger(fd) != 0);
    bHacking = FileHelper::readInteger(fd) != 0;
    effectTimer.first = FileHelper::readFloat(fd);
    effectTimer.second = FileHelper::readFloat(fd);
    if (FileHelper::readInteger(fd) != 0) ShipSystem::LockSystem(-1);
    drone.LoadState(fd);
    // End of orig code
}

HOOK_METHOD_PRIORITY(LockdownShard, LoadState, 9999, (int fd) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> LockdownShard::SaveState -> Begin (SavingRewrite.cpp)\n")

    // Initialize the shard's animation
    shard.animationStrip = nullptr;
    shard.info.numFrames = 0;
    shard.info.imageWidth = 0;
    shard.info.imageHeight = 0;
    shard.info.stripStartY = 0;
    shard.info.stripStartX = 0;
    shard.info.frameWidth = 0;
    shard.info.frameHeight = 0;
    // Initialize the animation tracker
    shard.tracker.currentDelay = -1.0f;
    shard.tracker.time = 0.0f;
    shard.tracker.loop = false;
    shard.tracker.current_time = 0.0f;
    shard.tracker.running = false;
    shard.tracker.reverse = false;
    shard.tracker.done = true;
    shard.tracker.loopDelay = 0.0f;
    // Set the shard position
    shard.position = Pointf(-1.0f, -1.0f);
    // Initialize sound-related strings
    shard.soundForward.clear(); // previously shard.soundForward = "";
    shard.soundReverse.clear(); // previously shard.soundReverse = "";
    // Other initializations
    shard.randomizeFrames = false;
    shard.fScale = 1.0f;
    shard.fYStretch = 0.0f;
    shard.currentFrame = 0;
    shard.bAlwaysMirror = false;
    shard.soundQueue.clear();
    shard.fadeOut = 0.0f;
    shard.startFadeOut = 0.0f;
    shard.animName.clear(); // previously shard.animName = "";
    // Mask initializations
    shard.mask_x_pos = 0;
    shard.mask_x_size = 0;
    shard.mask_y_pos = 0;
    shard.mask_y_size = 0;
    // Initialize Primitives empty
    shard.primitive = nullptr;
    shard.mirroredPrimitive = nullptr;
    // Initialize LockdownShard members
    position = Pointf(); // Default constructor initializes to (0,0)
    goal = Pointf(); // Default constructor initializes to (0,0)

    // Generate a random animation number based on FTL's RNG
    uint8_t animNumber = (superFreeze) ? 1 : ((Globals_RNG ? rand() : random32()) % 2 + 1);
    // Build the animation name directly
    std::string animName = "crystal_" + std::to_string(animNumber);
    // Retrieve the animation and assign it to the shard
    shard = G_->GetAnimationControl()->GetAnimation(animName);

    // Read the shard's state from the file
    position.x = FileHelper::readFloat(fd);
    position.y = FileHelper::readFloat(fd);
    goal.x = FileHelper::readFloat(fd);
    goal.y = FileHelper::readFloat(fd);
    speed = FileHelper::readFloat(fd);
    bArrived = FileHelper::readInteger(fd) != 0;
    bDone = FileHelper::readInteger(fd) != 0;
    lifeTime = FileHelper::readFloat(fd);
    superFreeze = FileHelper::readInteger(fd) != 0;
    lockingRoom = FileHelper::readInteger(fd);

    // Handle the animation state
    if (FileHelper::readInteger(fd) == 0)
    {
        shard.Start(true);  // Start normally
    }
    else
    {
        shard.tracker.time = 12.0f - lifeTime;
        shard.StartReverse(true);  // Start in reverse
    }

    // Set the animation progress
    shard.SetProgress(FileHelper::readFloat(fd));
}

HOOK_METHOD_PRIORITY(LockdownShard, SaveState, 9999, (int fd) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> LockdownShard::SaveState -> Begin (SavingRewrite.cpp)\n")

    // Reverse engineered Vanilla code by Dino
    FileHelper::writeFloat(fd, position.x);
    FileHelper::writeFloat(fd, position.y);
    FileHelper::writeFloat(fd, goal.x);
    FileHelper::writeFloat(fd, goal.y);
    FileHelper::writeFloat(fd, speed);
    FileHelper::writeInt(fd, static_cast<int>(bArrived));
    FileHelper::writeInt(fd, static_cast<int>(bDone));
    FileHelper::writeFloat(fd, lifeTime);
    FileHelper::writeInt(fd, static_cast<int>(superFreeze));
    FileHelper::writeInt(fd, lockingRoom);
    FileHelper::writeInt(fd, static_cast<int>(shard.tracker.reverse));
    FileHelper::writeFloat(fd, shard.tracker.Progress(-1.0));
    // End of orig code
}

HOOK_METHOD_PRIORITY(ProjectileFactory, SaveState, 9999, (int fd) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> ProjectileFactory::SaveState -> Begin (SavingRewrite.cpp)\n")

    // Reverse engineered Vanilla code by Dino
    
    // Saving cooldown and subCooldown
    FileHelper::writeFloat(fd, cooldown.first);
    FileHelper::writeFloat(fd, cooldown.second);
    FileHelper::writeFloat(fd, subCooldown.first);
    FileHelper::writeFloat(fd, subCooldown.second);

    // Save boost and charge levels
    FileHelper::writeInt(fd, boostLevel);
    FileHelper::writeInt(fd, chargeLevel);

    // Save targets
    int8_t numTargets = (targets.end() - targets.begin());
    FileHelper::writeInt(fd, numTargets);
    for (Pointf target : targets)
    {
        FileHelper::writeInt(fd, static_cast<int>(target.x));
        FileHelper::writeInt(fd, static_cast<int>(target.y));
    }

    // Save lastTargets
    int8_t numLastTargets = (lastTargets.end() - lastTargets.begin());
    FileHelper::writeInt(fd, numLastTargets);
    for (Pointf lastTarget : lastTargets)
    {
        FileHelper::writeInt(fd, static_cast<int>(lastTarget.x));
        FileHelper::writeInt(fd, static_cast<int>(lastTarget.y));
    }

    FileHelper::writeInt(fd, static_cast<int>(autoFiring));
    FileHelper::writeInt(fd, static_cast<int>(fireWhenReady));
    FileHelper::writeInt(fd, targetId);
    weaponVisual.SaveState(fd);
    FileHelper::writeInt(fd, lastProjectileId);

    // Write queued projectile amount
    int8_t numQueuedProjectiles = (queuedProjectiles.end() - queuedProjectiles.begin());
    FileHelper::writeInt(fd, numQueuedProjectiles);
    for (Projectile* projectile : queuedProjectiles)
    {
        int8_t projectileType = projectile->GetType();
        FileHelper::writeInt(fd, projectileType);

        if (projectileType != 0)
        {
            projectile->SaveProjectile(fd); 
        }
    }
    // End of orig code
}

HOOK_METHOD_PRIORITY(ProjectileFactory, LoadState, 9999, (int fd) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> ProjectileFactory::LoadState -> Begin (SavingRewrite.cpp)\n")

    // Reverse engineered Vanilla code by Dino

    // Read cooldown and subCooldown
    cooldown.first = FileHelper::readFloat(fd);
    cooldown.second = FileHelper::readFloat(fd);
    subCooldown.first = FileHelper::readFloat(fd);
    subCooldown.second = FileHelper::readFloat(fd);

    // Read boost and charge levels
    boostLevel = FileHelper::readInteger(fd);
    chargeLevel = FileHelper::readInteger(fd);

    // Read and process targets
    int8_t targetCount = FileHelper::readInteger(fd);
    for (int8_t i = 0; i < targetCount; ++i)
    {
        float x = static_cast<float>(FileHelper::readInteger(fd));
        float y = static_cast<float>(FileHelper::readInteger(fd));
        Pointf target = Pointf(x, y);

        // Add the target to the vector
        targets.emplace_back(target);
    }

    // Read and process last targets
    int8_t lastTargetCount = FileHelper::readInteger(fd);
    for (int8_t i = 0; i < lastTargetCount; ++i)
    {
        float x = static_cast<float>(FileHelper::readInteger(fd));
        float y = static_cast<float>(FileHelper::readInteger(fd));
        Pointf lastTarget = Pointf(x, y);

        // Add the last target to the vector
        lastTargets.emplace_back(lastTarget);
    }

    // Read autofiring and firing readiness states
    autoFiring = FileHelper::readInteger(fd) != 0;
    fireWhenReady = FileHelper::readInteger(fd) != 0;

    // Read target ID and load the weapon animation state
    targetId = FileHelper::readInteger(fd);
    weaponVisual.LoadState(fd);

    // Read last projectile ID
    lastProjectileId = FileHelper::readInteger(fd);

    // Load queued projectiles
    int8_t projectileCount = FileHelper::readInteger(fd);
    for (int8_t i = 0; i < projectileCount; ++i)
    {
        Projectile* projectile = LoadProjectile(fd);
        if (projectile != nullptr)
        {
            // Add the projectile to the queued projectiles vector
            queuedProjectiles.emplace_back(projectile);

            // Set weapon animation for the projectile
            projectile->SetWeaponAnimation(weaponVisual);

            // If there's a current ship target, set the moving target
            if (currentShipTarget != nullptr)
            {
                projectile->SetMovingTarget(currentShipTarget);
            }
        }
    }
    // End of orig code
}

HOOK_STATIC_PRIORITY(ProjectileFactory, SaveProjectile, 9999, (Projectile *projectile, int fd) -> void)
{
    LOG_HOOK("HOOK_STATIC_PRIORITY -> ProjectileFactory::SaveProjectile -> Begin (SavingRewrite.cpp)\n")

    // Reverse engineered Vanilla code by Dino
    int8_t projectileType = projectile->GetType();
    FileHelper::writeInt(fd, projectileType);

    if (projectileType != 0)
    {
        projectile->SaveProjectile(fd); 
    }
    // End of orig code
}

HOOK_STATIC_PRIORITY(ProjectileFactory, LoadProjectile, 9999, (int fd) -> Projectile*)
{
    LOG_HOOK("HOOK_STATIC_PRIORITY -> ProjectileFactory::LoadProjectile -> Begin (SavingRewrite.cpp)\n")

    Projectile* projectile = nullptr;
    int8_t projectileType = FileHelper::readInteger(fd);
    switch (projectileType)
    {
        case 1: // LaserBlast
        {
            LaserBlast* laserBlast = new LaserBlast(Pointf(), 0, 1, Pointf());
            laserBlast->movingTarget = nullptr;
            laserBlast->spinAngle = 0.f;
            laserBlast->spinSpeed = 0.f;
            laserBlast->heading = -1.f;
            laserBlast->OnInit();
            laserBlast->LoadProjectile(fd);
            projectile = laserBlast;
            break;
        }
        case 2: // Asteroid
        {
            Asteroid* asteroid = new Asteroid(Pointf(), 1);
            asteroid->LoadProjectile(fd);
            projectile = asteroid;
            break;
        }
        case 3: // Missile
        {
            Missile* missile = new Missile(Pointf(), 0, 1, Pointf(), 0.f);
            missile->LoadProjectile(fd);
            projectile = missile;
            break;
        }
        case 4: // BombProjectile
        {
            BombProjectile* bombProjectile = new BombProjectile(Pointf(), 0, 1, Pointf());
            bombProjectile->LoadProjectile(fd);
            projectile = bombProjectile;
            break;
        }
        case 5: // BeamWeapon
        {
            BeamWeapon* beamWeapon = new BeamWeapon(Pointf(), 0, 1, Pointf(), Pointf(), 10, nullptr, 0.f);
            beamWeapon->LoadProjectile(fd);
            projectile = beamWeapon;
            break;
        }
        case 6: // PDSFire
        {
            projectile->RandomSidePoint(0);
            PDSFire* pdsFire = new PDSFire(Point(), 0, Pointf());
            pdsFire->LoadProjectile(fd);
            projectile = pdsFire;
            break;
        }
    }
    return projectile;
}

HOOK_METHOD_PRIORITY(Ship, SaveState, 9999, (int fd) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> Ship::SaveState -> Begin (SavingRewrite.cpp)\n")

    // Reverse engineered Vanilla code by Dino
    for (Door* door : vDoorList)
    {
        door->SaveState(fd);
    }
    for (Door* airlock : vOuterAirlocks)
    {
        airlock->SaveState(fd);
    }
    FileHelper::writeFloat(fd, cloakingTracker.current_time);
    FileHelper::writeInt(fd, lockdowns.size());
    for (LockdownShard& shard : lockdowns)
    {
        shard.SaveState(fd);
    }
    // End of orig code
}

HOOK_METHOD_PRIORITY(Ship, LoadState, 9999, (int fd) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> Ship::LoadState -> Begin (SavingRewrite.cpp)\n")

    // Reverse engineered Vanilla code by Dino
    if (G_->GetSettings()->loadingSaveVersion < 3)
    {
        // Legacy loading doors from older saves
        for (size_t i = 0; i < vDoorList.size(); ++i)
        {
            if (FileHelper::readInteger(fd) == 1)
            {
                vDoorList[i]->Open();
            }

            if (FileHelper::readInteger(fd) == 1)
            {
                vDoorList[i]->FakeOpen();
            }

            vDoorList[i]->AccelerateAnimation();
        }
        for (size_t i = 0; i < vOuterAirlocks.size(); ++i)
        {
            if (FileHelper::readInteger(fd) == 1)
            {
                vOuterAirlocks[i]->Open();
            }

            if (FileHelper::readInteger(fd) == 1)
            {
                vOuterAirlocks[i]->FakeOpen();
            }

            vOuterAirlocks[i]->AccelerateAnimation();
        }
    }
    else
    {
        // Current way of loading doors
        for (Door* door : vDoorList)
        {
            door->LoadState(fd);
        }
        for (Door* airlock : vOuterAirlocks)
        {
            airlock->LoadState(fd);
        }
    }

    if (G_->GetSettings()->loadingSaveVersion > 4)
    {
        // Loading Cloak Time
        float cloakTime = FileHelper::readFloat(fd);
        if (cloakTime < 0.f) 
        {
            cloakTime = 0.f;
        }
        if (cloakTime > cloakingTracker.time) 
        {
            cloakTime = cloakingTracker.time;
        }
        cloakingTracker.current_time = cloakTime;

        // Load lockdown shards (crystal bomb/crew)
        if (G_->GetSettings()->loadingSaveVersion > 7) 
        {
            int lockdownCount = FileHelper::readInteger(fd);
            if (lockdownCount > 0) 
            {
                for (int i = 0; i < lockdownCount; ++i)
                {
                    LockdownShard shard;
                    shard.LoadState(fd);
                    lockdowns.push_back(shard);
                }
            }
        }
    }
    // End of orig code
}

HOOK_METHOD_PRIORITY(ShipSystem, SaveState, 9999, (int fd) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> ShipSystem::SaveState -> Begin (SavingRewrite.cpp)\n")

    // Reverse engineered Vanilla code by Dino
    FileHelper::writeInt(fd, iTempPowerCap);
    FileHelper::writeInt(fd, iTempPowerLoss);
    FileHelper::writeInt(fd, iTempDividePower);
    // End of orig code
}

HOOK_METHOD_PRIORITY(ShipSystem, LoadState, 9999, (int fd) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> ShipSystem::LoadState -> Begin (SavingRewrite.cpp)\n")

    // Reverse engineered Vanilla code by Dino
    iTempPowerCap = FileHelper::readInteger(fd);
    iTempPowerLoss = FileHelper::readInteger(fd);
    iTempDividePower = FileHelper::readInteger(fd);
    // End of orig code
}

HOOK_METHOD_PRIORITY(SpaceDrone, SaveState, 9999, (int fd) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> SpaceDrone::SaveState -> Begin (SavingRewrite.cpp)\n")

    // Reverse engineered Vanilla code by Dino
    Drone::SaveState(fd);
    FileHelper::writeInt(fd, currentSpace);
    FileHelper::writeInt(fd, destinationSpace);
    FileHelper::writeFloat(fd, currentLocation.x);
    FileHelper::writeFloat(fd, currentLocation.y);
    FileHelper::writeFloat(fd, lastLocation.x);
    FileHelper::writeFloat(fd, lastLocation.y);
    FileHelper::writeFloat(fd, destinationLocation.x);
    FileHelper::writeFloat(fd, destinationLocation.y);
    FileHelper::writeFloat(fd, pointTarget.x);
    FileHelper::writeFloat(fd, pointTarget.y);
    FileHelper::writeFloat(fd, targetLocation.x);
    FileHelper::writeFloat(fd, targetLocation.y);
    FileHelper::writeFloat(fd, targetSpeed.x);
    FileHelper::writeFloat(fd, targetSpeed.y);
    FileHelper::writeFloat(fd, pause);
    FileHelper::writeFloat(fd, additionalPause);
    FileHelper::writeFloat(fd, weaponCooldown);
    FileHelper::writeFloat(fd, current_angle);
    FileHelper::writeFloat(fd, aimingAngle);
    FileHelper::writeFloat(fd, lastAimingAngle);
    FileHelper::writeInt(fd, lifespan);
    FileHelper::writeInt(fd, static_cast<int>(bDisrupted));
    FileHelper::writeInt(fd, static_cast<int>(poweredLastFrame));
    FileHelper::writeFloat(fd, ionStun);
    FileHelper::writeFloat(fd, desiredAimingAngle);
    FileHelper::writeInt(fd, static_cast<int>(deployedLastFrame));
    FileHelper::writeFloat(fd, speedVector.x);
    FileHelper::writeFloat(fd, speedVector.y);
    explosion.SaveState(fd);
    // End of orig code
}

HOOK_METHOD_PRIORITY(SpaceDrone, LoadState, 9999, (int fd) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> SpaceDrone::LoadState -> Begin (SavingRewrite.cpp)\n")

    // Reverse engineered Vanilla code by Dino
    Drone::LoadState(fd);
    currentSpace = FileHelper::readInteger(fd);
    destinationSpace = FileHelper::readInteger(fd);
    currentLocation.x = FileHelper::readFloat(fd);
    currentLocation.y = FileHelper::readFloat(fd);
    lastLocation.x = FileHelper::readFloat(fd);
    lastLocation.y = FileHelper::readFloat(fd);
    destinationLocation.x = FileHelper::readFloat(fd);
    destinationLocation.y = FileHelper::readFloat(fd);
    pointTarget.x = FileHelper::readFloat(fd);
    pointTarget.y = FileHelper::readFloat(fd);
    targetLocation.x = FileHelper::readFloat(fd);
    targetLocation.y = FileHelper::readFloat(fd);
    targetSpeed.x = FileHelper::readFloat(fd);
    targetSpeed.y = FileHelper::readFloat(fd);
    pause = FileHelper::readFloat(fd);
    additionalPause = FileHelper::readFloat(fd);
    weaponCooldown = FileHelper::readFloat(fd);
    current_angle = FileHelper::readFloat(fd);
    aimingAngle = FileHelper::readFloat(fd);
    lastAimingAngle = FileHelper::readFloat(fd);
    lifespan = FileHelper::readInteger(fd);
    bDisrupted = FileHelper::readInteger(fd) != 0;
    poweredLastFrame = FileHelper::readInteger(fd) != 0;
    ionStun = FileHelper::readFloat(fd);
    desiredAimingAngle = FileHelper::readFloat(fd);
    deployedLastFrame = FileHelper::readInteger(fd) != 0;
    speedVector.x = FileHelper::readFloat(fd);
    speedVector.y = FileHelper::readFloat(fd);
    explosion.LoadState(fd);
    // End of orig code
}

HOOK_METHOD_PRIORITY(SuperShieldDrone, SaveState, 9999, (int fd) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> SuperShieldDrone::SaveState -> Begin (SavingRewrite.cpp)\n")

    // Reverse engineered Vanilla code by Dino
    SpaceDrone::SaveState(fd);
    FileHelper::writeFloat(fd, glowAnimation);
    // End of orig code
}

HOOK_METHOD_PRIORITY(SuperShieldDrone, LoadState, 9999, (int fd) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> SuperShieldDrone::LoadState -> Begin (SavingRewrite.cpp)\n")

    // Reverse engineered Vanilla code by Dino
    SpaceDrone::LoadState(fd);
    glowAnimation = FileHelper::readFloat(fd);
    // End of orig code
}

HOOK_METHOD_PRIORITY(WeaponAnimation, SaveState, 9999, (int fd) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> WeaponAnimation::SaveState -> Begin (SavingRewrite.cpp)\n")

    // Reverse engineered Vanilla code by Dino
    anim.SaveState(fd);
    FileHelper::writeFloat(fd, slideTracker.Progress(-1.0));
    FileHelper::writeInt(fd, static_cast<int>(bFiring));
    FileHelper::writeInt(fd, static_cast<int>(bFireShot));
    FileHelper::writeInt(fd, boostLevel);
    boostAnim.SaveState(fd);
    // End of orig code
}

HOOK_METHOD_PRIORITY(WeaponAnimation, LoadState, 9999, (int fd) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> WeaponAnimation::LoadState -> Begin (SavingRewrite.cpp)\n")

    // Reverse engineered Vanilla code by Dino
    anim.LoadState(fd);
    slideTracker.SetProgress(FileHelper::readFloat(fd));
    bFiring = FileHelper::readInteger(fd) != 0;
    bFireShot = FileHelper::readInteger(fd) != 0;
    if (G_->GetSettings()->loadingSaveVersion < 9) return;
    boostLevel = FileHelper::readInteger(fd);
    boostAnim.LoadState(fd);
    // End of orig code
}
