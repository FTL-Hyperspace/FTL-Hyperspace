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
        BoarderDrone *drone = boarderDrone;
        drone->droneRoom = roomId;
        drone->SetRoom(roomId);
        drone->SetPosition(Point(posX, posY));
        drone->MoveToRoom(roomId, slotId, true);
        drone->health.first = droneHealth;
        drone->SetPowered(drone->GetPowered());

        if (drone->GetPowered())
        {
            SetInstantPowered();
        }
    }
    // End of orig code
}

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
