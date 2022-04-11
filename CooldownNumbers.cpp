#include "CooldownNumbers.h"
#include "CustomOptions.h"

HOOK_METHOD(WeaponBox, RenderBox, (bool dragging, bool flashPowerBox) -> void)
{
    LOG_HOOK("HOOK_METHOD -> WeaponBox::RenderBox -> Begin (CooldownNumbers.cpp)\n")
    super(dragging, flashPowerBox);
    if (pWeapon && CustomOptionsManager::GetInstance()->showWeaponCooldown.currentValue)
    {
        if (pWeapon->powered)
        {
            if (!pWeapon->targets.empty())
            {
                if (pWeapon->autoFiring)
                {
                    CSurface::GL_SetColor(GL_Color(255.f / 255.f, 255.f / 255.f, 50.f / 255.f, 1.f));
                }
                else
                {
                    CSurface::GL_SetColor(GL_Color(255.f / 255.f, 120.f / 255.f, 120.f / 255.f, 1.f));
                }
            }
            else
            {
                CSurface::GL_SetColor(GL_Color(243.f / 255.f, 255.f / 255.f, 230.f / 255.f, 1.f));
            }
        }
        else
        {
            CSurface::GL_SetColor(GL_Color(150.f / 255.f, 150.f / 255.f, 150.f / 255.f, 1.f));
        }
        std::stringstream stream;
        if (pWeapon->cooldown.first < 0)
        {
            CSurface::GL_SetColor(GL_Color(150.f / 255.f, 150.f / 255.f, 150.f / 255.f, 1.f));
            stream << G_->GetTextLibrary()->GetText("weapon_cooldown_negative");
        }
        else
        {
            stream << std::fixed <<std::setprecision(1) << pWeapon->cooldown.first / (1 + pWeapon->GetAugmentationValue("AUTO_COOLDOWN")) << "/" << pWeapon->cooldown.second / (1 + pWeapon->GetAugmentationValue("AUTO_COOLDOWN"));
        }
        freetype::easy_printCenter(51, location.x - (hotKey * 98) + 132, location.y - 34, stream.str());

        if (pWeapon->blueprint->boostPower.type == 2)
        {
            std::stringstream stream2;
            int boostLevel = std::min(pWeapon->boostLevel, pWeapon->blueprint->boostPower.count);
            int damage = pWeapon->blueprint->damage.iDamage;
            if (damage < 1)
            {
                damage = pWeapon->blueprint->damage.iIonDamage;
                if (damage < 1)
                {
                    damage = pWeapon->blueprint->damage.iPersDamage;
                    if (damage < 1)
                    {
                        damage = pWeapon->blueprint->damage.iSystemDamage;
                    }
                }
            }
            stream2 << std::setprecision(3) << damage + boostLevel * pWeapon->blueprint->boostPower.amount << " " + G_->GetTextLibrary()->GetText("damage_word");
            freetype::easy_printCenter(51, location.x - (hotKey * 98) + 132, location.y - 44, stream2.str());
        }
    }
}

//HOOK_METHOD(ArtillerySystem, OnLoop, () -> void)
//{
//    super();
//    if (this->GetWeapon() && this->GetWeapon()->blueprint && CustomOptionsManager::GetInstance()->showWeaponCooldown.currentValue)
//    {
//        std::stringstream stream;
//        if (this->GetWeapon()->blueprint->cooldown.first < 0)
//        {
//            stream << G_->GetTextLibrary()->GetText("weapon_cooldown_negative");
//        }
//        else
//        {
//            stream << std::fixed <<std::setprecision(1) << this->GetWeapon()->blueprint->cooldown.first << "/" << this->GetWeapon()->blueprint->cooldown.second;
//        }
//        freetype::easy_printCenter(52, 500, 200, stream.str());
//    }
//}
