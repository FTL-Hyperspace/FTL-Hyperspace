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
        tracker.loopDelay = 0.0;
        tracker.currentDelay = 0.0;
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
    float val = 0.0;
    if ((tracker.running) && (val = tracker.current_time / tracker.time, val <= 0.0))
    {
        val = 0.0;
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

        anims[0][6].tracker.SetLoop(false, 0.0f);
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
