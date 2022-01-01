#include "CustomAugments.h"
#include "Global.h"
#include <cmath>

// Super Shields

int CustomAugmentManager::GetSuperShieldValue(int shipId)
{
    CustomAugmentManager* customAug = CustomAugmentManager::GetInstance();
    std::unordered_map<std::string, int> *augList = customAug->GetShipAugments(shipId);

    int superShieldValue = 0;
    int superShieldAdd = 0;
    int superShieldRenderValue = -1;
    bool customRender = false;
    bool hasEnergyShield = false;
    bool hasCustomShield = false;
    std::string shieldTexture = "";
    GL_Color shieldColor = GL_Color(0.0, 0.0, 0.0, 0.0);

    for (auto& aug : *augList)
    {
        if (aug.second > 0)
        {
            if (customAug->IsAugment(aug.first))
            {
                auto augDef = customAug->GetAugmentDefinition(aug.first);
                auto& superShield = augDef->superShield;

                if (superShield.present)
                {
                    hasCustomShield = true;
                    if (superShield.value > superShieldValue)
                    {
                        superShieldValue = superShield.value;
                    }
                    if (superShield.add > 0)
                    {
                        superShieldAdd += superShield.add * aug.second;
                    }
                    if (superShield.customRender && superShield.value > superShieldRenderValue)
                    {
                        superShieldRenderValue = superShield.value;
                        customRender = true;
                        shieldTexture = superShield.shieldTexture[shipId];
                        shieldColor = superShield.shieldColor;
                    }
                }
                else
                {
                    auto it = augDef->functions.find("ENERGY_SHIELD");
                    if (it != augDef->functions.end() && it->second.Functional(shipId))
                    {
                        hasEnergyShield = true;
                    }
                }
            }
            else if (aug.first == "ENERGY_SHIELD")
            {
                hasEnergyShield = true;
            }
        }
    }

    customAug->superShieldCustomRender[shipId] = customRender;
    customAug->superShieldTexture[shipId] = shieldTexture;
    customAug->superShieldColor[shipId] = shieldColor;

    if (!hasCustomShield) return 0;
    if (hasEnergyShield && superShieldValue < 5) superShieldValue = 5;

    return superShieldValue + superShieldAdd;
}

HOOK_METHOD(Shields, AddSuperShield, (Point pos) -> void)
{
    auto currentSuper = shields.power.super;

    super(pos);

    int customSuper = CustomAugmentManager::GetSuperShieldValue(_shipObj.iShipId);
    if (customSuper > 5)
    {
        shields.power.super.second = customSuper;
        shields.power.super.first = std::min(currentSuper.first+1,customSuper);
    }
}

HOOK_METHOD(Shields, InstantCharge, () -> void)
{
    super();

    int customSuper = CustomAugmentManager::GetSuperShieldValue(_shipObj.iShipId);
    if (customSuper > 0)
    {
        shields.power.super.second = customSuper;
        shields.power.super.first = customSuper;
    }
}

HOOK_METHOD(Shields, Jump, () -> void)
{
    super();

    int customSuper = CustomAugmentManager::GetSuperShieldValue(_shipObj.iShipId);
    if (customSuper > 0)
    {
        shields.power.super.second = customSuper;
        shields.power.super.first = customSuper;
    }
}

HOOK_METHOD(Shields, OnLoop, () -> void)
{
    bool noSuper = shields.power.super.second < 1;

    super();

    int customSuper = CustomAugmentManager::GetSuperShieldValue(_shipObj.iShipId);
    if (customSuper > 0)
    {
        shields.power.super.second = std::max(customSuper, std::min(shields.power.super.second, 5));

        if (noSuper) shields.power.super.first = customSuper;
    }
}

/*
HOOK_STATIC(Shields, CollisionReal, (CollisionResponse &_ret, Shields *shields, Pointf pos, DamageParameter damage, bool unk) -> CollisionResponse*)
{
    auto ret = super(_ret, shields, pos, damage, unk);

    if (CustomAugmentManager::GetInstance()->superShieldCustomRender[shields->_shipObj.iShipId] && !shields->damMessages.empty())
    {
        DamageMessage* damMessage = shields->damMessages.back();
        if (damMessage->color.r == 0.156862750649f && damMessage->color.g == 0.941176474094f && damMessage->color.b == 0.156862750649f) // r=40 g=240 b=40
        {
            damMessage->color = CustomAugmentManager::GetInstance()->superShieldColor[shields->_shipObj.iShipId];
            damMessage->color.a = 1.0;
        }
    }

    return ret;
}
*/

int numSuperShieldBars = 0;
std::vector<GL_Primitive*> superShieldBars = std::vector<GL_Primitive*>();

HOOK_METHOD(ShipStatus, RenderShields, (bool renderText) -> void)
{
    if (!ship) return super(renderText);

    auto superShield = ship->GetShieldPower().super;

    if (superShield.first > 0)
    {
        if (superShield.second != 5 || CustomAugmentManager::GetInstance()->superShieldCustomRender[0])
        {
            float charger = ship->shieldSystem->shields.charger;

            ship->shieldSystem->shields.power.super.first = 0;
            ship->shieldSystem->shields.charger = 0.0;

            super(renderText);

            ship->shieldSystem->shields.power.super.first = superShield.first;
            ship->shieldSystem->shields.charger = charger;

            if (superShield.second != numSuperShieldBars)
            {
                numSuperShieldBars = superShield.second;

                for (auto bar : superShieldBars)
                {
                    CSurface::GL_DestroyPrimitive(bar);
                }

                superShieldBars.clear();
                superShieldBars.reserve(superShield.second);

                float x = 33.5;
                int y = 79;
                float width = 92;
                int height = 6;

                float gap = superShield.second > 10 ? 1 : 2;
                float bar_space = (width+gap) / superShield.second;
                float bar_width = bar_space - gap;

                for (int i=0; i<superShield.second; ++i)
                {
                    int x1 = x;
                    int x2 = x + bar_width;
                    GL_Primitive* prim = CSurface::GL_CreateRectPrimitive(x1,y,x2-x1,height,GL_Color(1.0,1.0,1.0,1.0));
                    superShieldBars.push_back(prim);
                    x = x + bar_space;
                }
            }

            GL_Color color = CustomAugmentManager::GetInstance()->superShieldCustomRender[0] ? CustomAugmentManager::GetInstance()->superShieldColor[0] : GL_Color(0.392156862f, 1.f, 0.392156862f, 1.f);
            color.a = 1.0;

            for (int i=0; i<superShield.first; ++i)
            {
                if (i == superShieldBars.size()) break;

                CSurface::GL_RenderPrimitiveWithColor(superShieldBars[i],color);
            }

            return;
        }

        if (superShield.first > 5 && ship->shieldSystem != nullptr)
        {
            ship->shieldSystem->shields.power.super.first = 5;
            super(renderText);
            ship->shieldSystem->shields.power.super.first = superShield.first;
            return;
        }
    }

    super(renderText);
}

CachedImage extend_shieldCircleCharged[5];
CachedImage extend_shieldCircleUncharged[5];
CachedImage extend_shieldCircleHacked[5];
CachedImage extend_shieldCircleHackedCharged[5];

HOOK_METHOD(CombatControl, constructor, () -> void)
{
    super();

    for (int i=0; i<5; ++i)
    {
        extend_shieldCircleCharged[i] = this->shieldCircleCharged[0];
        extend_shieldCircleCharged[i].x += 23*(5+i);

        extend_shieldCircleUncharged[i] = this->shieldCircleUncharged[0];
        extend_shieldCircleUncharged[i].x += 23*(5+i);

        extend_shieldCircleHacked[i] = this->shieldCircleHacked[0];
        extend_shieldCircleHacked[i].x += 23*(5+i);

        extend_shieldCircleHackedCharged[i] = this->shieldCircleHackedCharged[0];
        extend_shieldCircleHackedCharged[i].x += 23*(5+i);
    }
}

HOOK_METHOD(CombatControl, RenderShipStatus, (Pointf pos, GL_Color color) -> void)
{
    auto enemyShield = currentTarget->shipManager->GetShieldPower();

    if (enemyShield.second > 5 && currentTarget->shipManager->shieldSystem != nullptr)
    {
        if (currentTarget->shipManager->shieldSystem->shields.power.first > 5)
        {
            currentTarget->shipManager->shieldSystem->shields.power.first = 5;
        }
        if (currentTarget->shipManager->shieldSystem->shields.power.second > 5)
        {
            currentTarget->shipManager->shieldSystem->shields.power.second = 5;
        }
        currentTarget->shipManager->shieldSystem->shields.power.super.first = 0;

        super(pos, color);

        currentTarget->shipManager->shieldSystem->shields.power = enemyShield;

        CSurface::GL_PushMatrix();
        CSurface::GL_Translate(pos.x, pos.y, 0.0);

        bool isHacked = currentTarget->shipManager->IsSystemHacked(0) > 1;

        for (int i=5; i<enemyShield.second; ++i)
        {
            if (i >= 10) break;
            if (enemyShield.first > i)
            {
                if (isHacked)
                {
                    extend_shieldCircleHackedCharged[i-5].OnRender(GL_Color(1.0, 1.0, 1.0, 1.0));
                }
                else
                {
                    extend_shieldCircleCharged[i-5].OnRender(GL_Color(1.0, 1.0, 1.0, 1.0));
                }
            }
            else
            {
                if (isHacked)
                {
                    extend_shieldCircleHacked[i-5].OnRender(GL_Color(1.0, 1.0, 1.0, 1.0));
                }
                else
                {
                    extend_shieldCircleUncharged[i-5].OnRender(GL_Color(1.0, 1.0, 1.0, 1.0));
                }
            }
        }

        if (enemyShield.super.first > 0)
        {
            GL_Color superColor = GL_Color(100.0/255.0, 255.0/255.0, 100.0/255.0, 1.0);

            if (CustomAugmentManager::GetInstance()->superShieldCustomRender[1])
            {
                    superColor = CustomAugmentManager::GetInstance()->superShieldColor[1];
                    superColor.a = 1.0;
            }

            int superBar_x = enemyShield.second * 23;

            if (enemyShield.super.second == 5)
            {
                superShieldBox5.SetPosition(superBar_x + 13, 35);
                superShieldBox5.OnRender(GL_Color(1.0, 1.0, 1.0, 1.0));
            }
            else if (enemyShield.super.second == 12)
            {
                superShieldBox12.SetPosition(superBar_x + 13, 35);
                superShieldBox12.OnRender(GL_Color(1.0, 1.0, 1.0, 1.0));
            }
            else
            {
                CSurface::GL_DrawRect(superBar_x + 13.f, 35.f, enemyShield.super.second*10+6, 13.f, GL_Color(0.0, 0.0, 0.0, 0.5));
                CSurface::GL_DrawRectOutline(superBar_x + 13, 35, enemyShield.super.second*10+6, 13, GL_Color(1.0, 1.0, 1.0, 1.0), 2.f);
            }
            CSurface::GL_DrawRect(superBar_x + 16.f, 38.f, enemyShield.super.first*10, 7.f, superColor);
        }

        CSurface::GL_PopMatrix();
    }
    else
    {
        super(pos, color);

        if (CustomAugmentManager::GetInstance()->superShieldCustomRender[1])
        {
            if (enemyShield.super.first > 0)
            {
                GL_Color superColor = CustomAugmentManager::GetInstance()->superShieldColor[1];
                superColor.a = 1.0;

                CSurface::GL_PushMatrix();
                CSurface::GL_Translate(pos.x, pos.y, 0.0);

                CSurface::GL_DrawRect(enemyShield.second*23.f + 16.f, 38.f, enemyShield.super.first*10, 7.f, superColor);

                CSurface::GL_PopMatrix();
            }
        }
    }
}

GL_Primitive* customSuperShieldPrimitives[2] = {nullptr, nullptr};

HOOK_METHOD_PRIORITY(Shields, RenderBase, 9999, (float alpha, float superShieldOverwrite) -> void)
{
    if (((shields.power.first != 0 || _shipObj.iShipId == 0) && shields.power.second != 0) || shields.power.super.first != 0)
    {
        if (shieldImage == nullptr)
        {
            shieldImage = G_->GetResources()->GetImageId(shieldImageName);
            if (shieldImage)
            {
                shieldPrimitive = CSurface::GL_CreatePixelImagePrimitive(shieldImage, 0.f, 0.f, shieldImage->width_, shieldImage->height_, 0.f, {1.f,1.f,1.f,1.f}, false);
            }
        }

        float width_;
        float height_;
        float scale_x;
        float scale_y;

//        if (_shipObj.iShipId == 0)
//        {
//            if (shieldImage)
//            {
//                width_ = shieldImage->width_;
//                height_ = shieldImage->height_;
//            }
//            else
//            {
//                width_ = 1.f;
//                height_ = 1.f;
//            }
//            scale_x = 1.f;
//            scale_y = 1.f;
//        }
//        else
        {
            width_ = baseShield.a * 2;
            height_ = baseShield.b * 2;

            if (shieldImage)
            {
                scale_x = width_ / shieldImage->width_;
                scale_y = height_ / shieldImage->height_;
            }
            else
            {
                scale_x = width_;
                scale_y = height_;
            }
        }

        CSurface::GL_PushMatrix();
        CSurface::GL_Translate(baseShield.center.x - 0.5f * width_, baseShield.center.y - 0.5f * height_, 0.f);
        CSurface::GL_Scale(scale_x, scale_y, 1.f);

        float shieldsUpProgress = shieldsUp.Progress(-1.f);
        if (shieldsUpProgress < 1.f)
        {
            CSurface::GL_PushMatrix();
            CSurface::GL_Translate(0.5f * shieldImage->width_, 0.5f * shieldImage->height_, 0.f);
            CSurface::GL_Scale(shieldsUpProgress, shieldsUpProgress, 1.f);
            CSurface::GL_Translate(-0.5f * shieldImage->width_, -0.5f * shieldImage->height_, 0.f);
        }

        GL_Color shieldColor;

        if (bBarrierMode)
        {
            shieldColor.r = 255.f / 255.f;
            shieldColor.g = 176.f / 255.f;
            shieldColor.b = 224.f / 255.f;
        }
        else
        {
            shieldColor.r = 1.f;
            shieldColor.g = 1.f;
            shieldColor.b = 1.f;
        }

        shieldColor.a = _shipObj.iShipId == 0 ? 3.5f : 4.f;

        if (shields.power.second != 0)
        {
            shieldColor.a = shields.power.first / shieldColor.a * alpha;
            if (shieldColor.a <= 0.f)
            {
                shieldColor.a = 0.f;
            }
            else
            {
                shieldColor.a = shieldColor.a * 0.6f + alpha * 0.4f;
            }

            CSurface::GL_RenderPrimitiveWithColor(shieldPrimitive, shieldColor);
        }

        if (shieldsUpProgress < 1.f)
        {
            CSurface::GL_PopMatrix();
        }

        int superShield = shields.power.super.first;
        if (!superShieldUp.running && superShield < 0)
        {
            superShield = 0;
        }

        if (superShield > 0 || superShieldOverwrite > -1.f)
        {
            int superMax = std::max(shields.power.super.second, 5);
            shieldColor.a = ((float)superShield / (float)superMax) * alpha;
            if (shields.power.first == 0)
            {
                shieldColor.a = shieldColor.a * 0.6f + alpha * 0.4f;
            }
            if (superShieldOverwrite > -1.f) shieldColor.a = superShieldOverwrite;

            // Custom super shield color
            if (CustomAugmentManager::GetSuperShieldValue(_shipObj.iShipId) > 0 && CustomAugmentManager::GetInstance()->superShieldCustomRender[_shipObj.iShipId])
            {
                GL_Color customColor = CustomAugmentManager::GetInstance()->superShieldColor[_shipObj.iShipId];
                customColor.a *= shieldColor.a;

                std::string imageId = CustomAugmentManager::GetInstance()->superShieldTexture[_shipObj.iShipId];

                if (imageId.empty()) // No custom image; use standard
                {
                    CSurface::GL_RenderPrimitiveWithColor(shieldPrimitive, customColor);
                }
                else // Custom image specified; use custom
                {
                    GL_Texture* shieldTex = G_->GetResources()->GetImageId(imageId);

                    width_ = baseShield.a * 2;
                    height_ = baseShield.b * 2;
                    scale_x = width_ / shieldTex->width_;
                    scale_y = height_ / shieldTex->height_;

                    GL_Primitive* shieldPrim = CSurface::GL_CreatePixelImagePrimitive(shieldTex, 0.f, 0.f, shieldTex->width_, shieldTex->height_, 0.f, {1.f,1.f,1.f,1.f}, false);

                    CSurface::GL_DestroyPrimitive(customSuperShieldPrimitives[_shipObj.iShipId]);
                    customSuperShieldPrimitives[_shipObj.iShipId] = shieldPrim;

                    CSurface::GL_PopMatrix();

                    CSurface::GL_PushMatrix();
                    CSurface::GL_Translate(baseShield.center.x - 0.5f * width_, baseShield.center.y - 0.5f * height_, 0.f);
                    CSurface::GL_Scale(scale_x, scale_y, 1.f);

                    CSurface::GL_RenderPrimitiveWithColor(shieldPrim, customColor);
                }
            }
            else // Vanilla super shield render
            {
                shieldColor.r = 100.f / 255.f;
                shieldColor.g = 255.f / 255.f;
                shieldColor.b = 100.f / 255.f;
                CSurface::GL_RenderPrimitiveWithColor(shieldPrimitive, shieldColor);
            }
        }

        CSurface::GL_PopMatrix();
    }

    if (!shields_shutdown)
    {
        for (ShieldAnimation &hit : shieldHits)
        {
            Pointf pos = Pointf(hit.location.x - baseShield.center.x, hit.location.y - baseShield.center.y);

//            float angle = pos.x / baseShield.a;
//            if (angle > 1.f) angle = 1.f;
//            else if (angle < -1.f) angle = -1.f;
//
//            angle = acosf(angle) * 180.f / 3.141592654f;
//
//            if (pos.y < 0.f) angle = -angle;

            float angle = atan2f(pos.y/(ellipseRatio*baseShield.a), pos.x/baseShield.a) * 180.f / 3.141592654f;

            CSurface::GL_DrawShield(baseShield.center.x, baseShield.center.y, baseShield.a, ellipseRatio*baseShield.a, angle - hit.end_size, hit.end_size + angle, {1.f,1.f,1.f,1.f}, hit.current_thickness);
        }
    }
}
