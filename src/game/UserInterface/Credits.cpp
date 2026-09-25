#include "Global.h"
#include "CustomEvents.h"

HOOK_METHOD_PRIORITY(GameOver, OnLoop, 9999, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> GameOver::OnLoop -> Begin (Credits.cpp)\n")
    openedTimer += G_->GetCFPS()->GetSpeedFactor() * 0.0625f;
    if (openedTimer >= 25.f && bVictory)
    {
        std::vector<std::string> music = std::vector<std::string>();
        if (replaceCreditsMusic.empty())
        {
            music.push_back("title");
        }
        else
        {
            music.push_back(replaceCreditsMusic);
        }
        G_->GetSoundControl()->StartPlaylist(music);
    }
    if (bShowingCredits && credits.Done())
    {
        bShowingCredits = false;
    }
}
