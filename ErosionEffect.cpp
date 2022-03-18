#include "Global.h"

HOOK_METHOD(ShipManager, DamageArea, (Pointf location, DamageParameter dmgParam, bool forceHit) -> bool)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::DamageArea -> Begin (ErosionEffect.cpp)\n")
    Damage* dmg = (Damage*)&dmgParam;

    auto custom = CustomDamageManager::currentWeaponDmg;

    if (custom)
    {
        int rng = random32() % 10;

        if (rng < custom->def->erosionChance)
        {
            int roomId = ship.GetSelectedRoomId(location.x, location.y, true);

            if (roomId != -1)
            {
                auto ex = RM_EX(ship.vRoomList[roomId]);
                ex->StartErosion(custom->def->erosionEffect);
            }
        }
    }

    return super(location, dmgParam, forceHit);
}

void Room_Extend::StartErosion(const ErosionEffect& effect)
{
    if (currentErosion == nullptr)
    {
        if (effect.erosionTime > 0)
        {
            erosionTimer.Start(effect.erosionTime);
        }

        currentErosion = new ErosionEffect(effect);
    }
    else
    {
        erosionTimer.currGoal += effect.erosionTime;
    }
}

void Room_Extend::StopErosion()
{
    erosionTimer.Stop();

    currentErosion = nullptr;
    if (erosionAnim)
    {
        erosionAnim->destructor();
        erosionAnim = nullptr;
    }
}

HOOK_METHOD(ShipManager, UpdateEnvironment, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::UpdateEnvironment -> Begin (ErosionEffect.cpp)\n")
    super();

    for (auto i : ship.vRoomList)
    {
        auto ex = RM_EX(i);

        if (ex->currentErosion != nullptr)
        {
            auto sys = GetSystemInRoom(i->iRoomId);
            if (sys != nullptr && sys->healthState.first > 0)
            {
                sys->PartialDamage(ex->currentErosion->systemDamageSpeed);
            }

            ex->erosionTimer.Update();

            if (ex->erosionTimer.Done())
            {
                ex->StopErosion();
            }
        }
    }
}

HOOK_METHOD(Ship, OnRenderBreaches, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> Ship::OnRenderBreaches -> Begin (ErosionEffect.cpp)\n")
    for (auto i : vRoomList)
    {
        auto ex = RM_EX(i);

        if (ex->currentErosion != nullptr)
        {
            if (!ex->erosionAnim)
            {
                ex->erosionAnim = new Animation(G_->GetAnimationControl()->GetAnimation(ex->currentErosion->animation));

                ex->erosionAnim->SetCurrentFrame(0);
                ex->erosionAnim->tracker.SetLoop(true, 0);
                ex->erosionAnim->Start(true);
            }

            CSurface::GL_PushMatrix();

            // top

            for (int xPos = 0; xPos < i->rect.w / 35; xPos++)
            {
                CSurface::GL_PushMatrix();

                CSurface::GL_Translate(i->rect.x + xPos * 35, i->rect.y + i->rect.h - 35);
                ex->erosionAnim->OnRender(1.f, COLOR_WHITE, false);

                CSurface::GL_PopMatrix();
            }

            // bottom

            for (int xPos = 0; xPos < i->rect.w / 35; xPos++)
            {
                CSurface::GL_PushMatrix();

                CSurface::GL_Translate(i->rect.x + xPos * 35 + 35, i->rect.y + 35.f);
                CSurface::GL_Rotate(180.f, 0.f, 0.f, 1.f);
                ex->erosionAnim->OnRender(1.f, COLOR_WHITE, false);

                CSurface::GL_PopMatrix();
            }

            // left

            for (int yPos = 0; yPos < i->rect.h / 35; yPos++)
            {
                CSurface::GL_PushMatrix();

                CSurface::GL_Translate(i->rect.x + 35, i->rect.y + yPos * 35.f);
                CSurface::GL_Rotate(90.f, 0.f, 0.f, 1.f);
                ex->erosionAnim->OnRender(1.f, COLOR_WHITE, false);

                CSurface::GL_PopMatrix();
            }

            // right

            for (int yPos = 0; yPos < i->rect.h / 35; yPos++)
            {
                CSurface::GL_PushMatrix();

                CSurface::GL_Translate(i->rect.x + i->rect.w - 35.f, i->rect.y + yPos * 35.f + 35.f);
                CSurface::GL_Rotate(-90.f, 0.f, 0.f, 1.f);
                ex->erosionAnim->OnRender(1.f, COLOR_WHITE, false);

                CSurface::GL_PopMatrix();
            }

            CSurface::GL_PopMatrix();
        }
    }

    super();
}
