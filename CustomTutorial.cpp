#include "CustomTutorial.h"
#include "CustomOptions.h"

bool CustomTutorialState::allowJumping = false;
bool CustomTutorialState::allowUpgrades = false;

void TutorialArrow::OnRender()
{
    CSurface::GL_BlitPixelImage(arrow, position.x, position.y, blitSize.x, blitSize.y, rotation, arrow_color, false);
    arrow2_color.a = G_->GetTutorialManager()->tracker.GetAlphaLevel(false);
    CSurface::GL_BlitPixelImage(arrow2, position.x, position.y, blitSize.x, blitSize.y, rotation, arrow2_color, false);
}

// HOOK_METHOD_PRIORITY(TutorialManager, LoadTutorial, 1000, () -> void)
// {
//     LOG_HOOK("HOOK_METHOD_PRIORITY -> TutorialManager::LoadTutorial -> Begin (CustomTutorial.cpp)\n")
//     if (CustomOptionsManager::GetInstance()->disableDefaultTutorial.currentValue)
//     {
//         return;
//     }
//     super();
// }

HOOK_METHOD_PRIORITY(TutorialManager, OnLoop, 1000, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> TutorialManager::OnLoop -> Begin (CustomTutorial.cpp)\n")
    if (CustomOptionsManager::GetInstance()->disableDefaultTutorial.currentValue)
    {
        if (!bRunning) return;

        float speed = G_->GetCFPS()->GetSpeedFactor() * 0.0625f + timerOpen;
        timerOpen = (speed > 1.0f) ? 0.0f : floorf(speed);
        // shipInfo->bTutorialMode = true;

        return;
    }
    super();
}

HOOK_METHOD_PRIORITY(TutorialManager, OnRender, 1000, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> TutorialManager::OnRender -> Begin (CustomTutorial.cpp)\n")
    if (CustomOptionsManager::GetInstance()->disableDefaultTutorial.currentValue)
    {
        if (!bRunning) return;

        tracker.Update();

        return;
    }
    super();
}

HOOK_METHOD_PRIORITY(TutorialManager, MouseMove, 1000, (int mX, int mY) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> TutorialManager::MouseMove -> Begin (CustomTutorial.cpp)\n")
    if (CustomOptionsManager::GetInstance()->disableDefaultTutorial.currentValue)
    {
        return;
    }
    super(mX, mY);
}

HOOK_METHOD_PRIORITY(TutorialManager, MouseClick, 1000, () -> bool)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> TutorialManager::MouseClick -> Begin (CustomTutorial.cpp)\n")
    if (CustomOptionsManager::GetInstance()->disableDefaultTutorial.currentValue)
    {
        return false;
    }
    return super();
}

HOOK_METHOD_PRIORITY(TutorialManager, AllowJumping, 1000, () -> bool)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> TutorialManager::AllowJumping -> Begin (CustomTutorial.cpp)\n")
    if (CustomOptionsManager::GetInstance()->disableDefaultTutorial.currentValue)
    {
        return CustomTutorialState::allowJumping;
    }
    return super();
}

HOOK_METHOD_PRIORITY(TutorialManager, AllowUpgrades, 1000, () -> bool)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> TutorialManager::AllowUpgrades -> Begin (CustomTutorial.cpp)\n")
    if (CustomOptionsManager::GetInstance()->disableDefaultTutorial.currentValue)
    {
        return CustomTutorialState::allowUpgrades;
    }
    return super();
}
