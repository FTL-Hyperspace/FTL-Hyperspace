#include "HullNumbers.h"
#include <boost/lexical_cast.hpp>

HullNumbers HullNumbers::instance = HullNumbers();
HullBars HullBars::instance = HullBars();
static bool g_overrideHullBar = false;
bool g_playerHpColorFix = true;

// TODO: 
// sig for linux CacheImage::SetPartial

HullNumbers::IndicatorInfo& HullNumbers::ParseIndicatorInfo(HullNumbers::IndicatorInfo& indicatorInfo, rapidxml::xml_node<char> *node)
{
    if (node->first_attribute("x"))
    {
        indicatorInfo.x = boost::lexical_cast<int>(node->first_attribute("x")->value());
    }
    if (node->first_attribute("y"))
    {
        indicatorInfo.y = boost::lexical_cast<int>(node->first_attribute("y")->value());
    }
    if (node->first_attribute("type"))
    {
        indicatorInfo.type = boost::lexical_cast<int>(node->first_attribute("type")->value());
    }
    if (node->first_attribute("align"))
    {
        indicatorInfo.align = node->first_attribute("align")->value();
    }

    return indicatorInfo;
}

void HullNumbers::ParseHullNumbersNode(rapidxml::xml_node<char>* node)
{
    try
    {
        playerIndicator = HullNumbers::IndicatorInfo();
        playerIndicator.x = 335;
        playerIndicator.y = 50;
        playerIndicator.type = 0;
        playerIndicator.align = "left";
        enemyIndicator = HullNumbers::IndicatorInfo();
        enemyIndicator.x = 988;
        enemyIndicator.y = 59;
        enemyIndicator.type = 0;
        enemyIndicator.align = "center";
        bossIndicator = HullNumbers::IndicatorInfo();
        bossIndicator.x = 864;
        bossIndicator.y = 16;
        bossIndicator.type = 0;
        bossIndicator.align = "center";


        auto child = node->first_node("playerText");
        if (child)
        {
            ParseIndicatorInfo(playerIndicator, child);
        }

        child = node->first_node("enemyText");
        while (child)
        {
            auto langAttr = child->first_attribute("language");
            if (langAttr)
            {
                IndicatorInfo locIndicator = HullNumbers::IndicatorInfo();
                locIndicator.x = 988;
                locIndicator.y = 59;
                locIndicator.type = 0;
                locIndicator.align = "center";
                ParseIndicatorInfo(locIndicator, child);
                enemyIndicatorLoc.insert({langAttr->value(), locIndicator});
            }
            else
            {
                ParseIndicatorInfo(enemyIndicator, child);
            }
            child = child->next_sibling("enemyText");
        }

        child = node->first_node("bossText");
        while (child)
        {
            auto langAttr = child->first_attribute("language");
            if (langAttr)
            {
                IndicatorInfo locIndicator = HullNumbers::IndicatorInfo();
                locIndicator.x = 864;
                locIndicator.y = 16;
                locIndicator.type = 0;
                locIndicator.align = "center";
                ParseIndicatorInfo(locIndicator, child);
                bossIndicatorLoc.insert({langAttr->value(), locIndicator});
            }
            else
            {
                ParseIndicatorInfo(bossIndicator, child);
            }
            child = child->next_sibling("bossText");
        }


    }
    catch (rapidxml::parse_error& e)
    {
        ErrorMessage(std::string("Error parsing <hullNumbers> in hyperspace.xml\n") + std::string(e.what()));
    }
    catch (std::exception &e)
    {
        ErrorMessage(std::string("Error parsing <hullNumbers> in hyperspace.xml\n") + std::string(e.what()));
    }
    catch (const char* e)
    {
        ErrorMessage(std::string("Error parsing <hullNumbers> in hyperspace.xml\n") + std::string(e));
    }
    catch (...)
    {
        ErrorMessage("Error parsing <hullNumbers> in hyperspace.xml\n");
    }
}

void HullNumbers::PrintAlignment(int font, int x, int y, std::string str, std::string align)
{
    if (align == "center")
    {
        freetype::easy_printCenter(font, x, y, str);
    }
    else if (align == "right")
    {
        freetype::easy_printRightAlign(font, x, y, str);
    }
    else
    {
        freetype::easy_print(font, x, y, str);
    }
}

void HullBars::ParseHullBarsNode(rapidxml::xml_node<char> *node)
{
    try
    {
        if (node->first_attribute("type"))
        {
            enabledType = boost::lexical_cast<int>(node->first_attribute("type")->value());
        }
        if (node->first_attribute("maxHull"))
        {
            barWidth = boost::lexical_cast<int>(node->first_attribute("maxHull")->value());
        }
        if (node->first_attribute("maxHullBoss"))
        {
            barWidthBoss = boost::lexical_cast<int>(node->first_attribute("maxHullBoss")->value());
        }

        for (auto child = node->first_node("barColor"); child; child = child->next_sibling("barColor"))
        {
            ParseHullBarsColorsNode(child);
        }
    }
    catch (rapidxml::parse_error& e)
    {
        ErrorMessage(std::string("Error parsing <hullBars> in hyperspace.xml\n") + std::string(e.what()));
    }
    catch (std::exception &e)
    {
        ErrorMessage(std::string("Error parsing <hullBars> in hyperspace.xml\n") + std::string(e.what()));
    }
    catch (const char* e)
    {
        ErrorMessage(std::string("Error parsing <hullBars> in hyperspace.xml\n") + std::string(e));
    }
    catch (...)
    {
        ErrorMessage("Error parsing <hullBars> in hyperspace.xml\n");
    }
}

void HullBars::ParseHullBarsColorsNode(rapidxml::xml_node<char> *node)
{
    float r = 1.f;
    float g = 1.f;
    float b = 1.f;
    float a = 1.f;

    if (node->first_attribute("r"))
    {
        r = boost::lexical_cast<float>(node->first_attribute("r")->value()) / 255.f;
    }
    if (node->first_attribute("g"))
    {
        g = boost::lexical_cast<float>(node->first_attribute("g")->value()) / 255.f;
    }
    if (node->first_attribute("b"))
    {
        b = boost::lexical_cast<float>(node->first_attribute("b")->value()) / 255.f;
    }
    if (node->first_attribute("a"))
    {
        a = boost::lexical_cast<float>(node->first_attribute("a")->value()) / 255.f;
    }
    barColor.push_back(GL_Color(r, g, b ,a));
}

HOOK_METHOD(ShipStatus, RenderShields, (bool renderText) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipStatus::RenderShields -> Begin (HullNumbers.cpp)\n")
    super(renderText);

    HullNumbers *HNManager = HullNumbers::GetInstance();
    if (HNManager && HNManager->enabled)
    {
        char buffer[64];
        sprintf(buffer, "%d", this->ship->ship.hullIntegrity.first);
        auto textInfo = HNManager->playerIndicator;
        HullNumbers::PrintAlignment(textInfo.type, textInfo.x, textInfo.y, buffer, textInfo.align);
    }
}

HOOK_METHOD(ResourceControl, GetImageId, (std::string& path) -> GL_Texture*)
{
    LOG_HOOK("HOOK_METHOD -> ResourceControl::GetImageId -> Begin (HullNumbers.cpp)\n")
    if (path == "combatUI/box_hostiles2.png" && HullNumbers::GetInstance() && HullNumbers::GetInstance()->enabled)
    {
        path.assign("combatUI/box_hostiles2_numbers.png");
    }
    if (path == "combatUI/box_hostiles_boss.png" && HullNumbers::GetInstance() && HullNumbers::GetInstance()->enabled)
    {
        path.assign("combatUI/box_hostiles_boss_numbers.png");
    }


    return super(path);
}

HOOK_METHOD(CombatControl, RenderTarget, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CombatControl::RenderTarget -> Begin (HullNumbers.cpp)\n")
    
    g_overrideHullBar = true;
    super();
    g_overrideHullBar = false;

    HullBars *HBManager = HullBars::GetInstance();
    int barWidth = boss_visual ? HBManager->barWidthBoss : HBManager->barWidth;
    if(HBManager->enabledType == 1 && this->GetCurrentTarget()->ship.hullIntegrity.first > barWidth)
    {
        int ibar = std::floor(this->GetCurrentTarget()->ship.hullIntegrity.first / barWidth);

        HBManager->RefreshPosition(boss_visual);
        float x1 = barWidth / 22.f;
        float x2 = ((float)(this->GetCurrentTarget()->ship.hullIntegrity.first % (barWidth))/barWidth)*(barWidth / 22.f);

        HBManager->hullBarImage->SetPartial(0.0, 0.0, x1, 1.0);
        HBManager->hullBarImage->OnRender(HBManager->GetBarColor(ibar - 1));

        HBManager->hullBarImage->SetPartial(0.0, 0.0, x2, 1.0);
        HBManager->hullBarImage->OnRender(HBManager->GetBarColor(ibar));
    }

    HullNumbers *HNManager = HullNumbers::GetInstance();

    if (this->GetCurrentTarget() && HNManager && HNManager->enabled)
    {
        bool hostile = this->GetCurrentTarget()->_targetable.hostile;
        if (hostile)
        {
            GL_Color color = GL_Color(1.f, 0.2f, 0.2f, 1.f);
            CSurface::GL_SetColor(color);

        }
        else
        {
            GL_Color color = GL_Color(1.f, 1.f, 1.f, 1.f);
            CSurface::GL_SetColor(color);
        }

        char buffer[64];
        sprintf(buffer, "%d", this->GetCurrentTarget()->ship.hullIntegrity.first);

        HullNumbers::IndicatorInfo textInfo;
        if (boss_visual)
        {
            auto it = HNManager->bossIndicatorLoc.find(G_->GetTextLibrary()->currentLanguage);
            if (it != std::end(HNManager->bossIndicatorLoc))
            {
                textInfo = it->second;
            }
            else
            {
                textInfo = HNManager->bossIndicator;
            }
        }
        else
        {
            auto it = HNManager->enemyIndicatorLoc.find(G_->GetTextLibrary()->currentLanguage);
            if (it != std::end(HNManager->enemyIndicatorLoc))
            {
                textInfo = it->second;
            }
            else
            {
                textInfo = HNManager->enemyIndicator;
            }
        }

        HullNumbers::PrintAlignment(textInfo.type, textInfo.x, textInfo.y, buffer, textInfo.align);
    }
}

HOOK_METHOD(ShipStatus, OnInit, (Point unk, float unk2) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipStatus::OnInit -> Begin (HullNumbers.cpp)\n")
    super(unk, unk2);

    if (HullNumbers::GetInstance() && HullNumbers::GetInstance()->enabled)
    {
        hullBox = G_->GetResources()->CreateImagePrimitiveString("statusUI/top_hull_numbers.png", 0, 0, 0, COLOR_WHITE, 1.f, false);
        hullBox_Red = G_->GetResources()->CreateImagePrimitiveString("statusUI/top_hull_numbers_red.png", 0, 0, 0, COLOR_WHITE, 1.f, false);
    }
}

HOOK_METHOD(CombatControl, constructor, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CombatControl::constructor -> Begin (HullNumbers.cpp)\n")
    super();
    if (HullBars::GetInstance() && HullBars::GetInstance()->enabledType == 1)
    {
        HullBars::GetInstance()->hullBarImage = new CachedImage("combatUI/box_hostiles_hull2.png", 889, 90);
    }
}

HOOK_METHOD(CachedImage, SetPartial, (float x_start, float y_start, float x_size, float y_size) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CachedImage::SetPartial -> Begin (HullNumbers.cpp)\n")
    
    ShipManager *enemyShip;
    if (g_overrideHullBar && y_size == 1.0 && (enemyShip = G_->GetShipManager(1)))
    {
        HullBars *HBManager = HullBars::GetInstance();
        std::pair<int, int> shipHp = enemyShip->ship.hullIntegrity;
        int barWidth = G_->GetCApp()->gui->combatControl.boss_visual ? HBManager->barWidthBoss : HBManager->barWidth;

        if (HBManager->enabledType == 2 && shipHp.second > barWidth)
        {
            x_size = ((float) shipHp.first / (float) shipHp.second) * (barWidth / 22.f);
        }
        else if (HBManager->enabledType == 1 && shipHp.first > barWidth)
        {
            x_size = 0.0;
        }
    }

    super(x_start, y_start, x_size, y_size);
}


HOOK_METHOD_PRIORITY(ShipStatus, OnRender, 9999, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> ShipStatus::OnRender -> Begin (TouchScreen.cpp)\n")

    // Rewritten to fix the HP bar color not being based off percent but instead 10HP steps.

    CSurface::GL_PushMatrix();
    CSurface::GL_Translate(static_cast<float>(this->location.x), static_cast<float>(this->location.y));

    // Render hull status
    GL_Primitive* renderHullBox = this->hullBox;
    GL_Texture* renderHullLabel = this->hullLabel;

    // Check for red damage blinking
    if (!this->hullMessage->tracker.done && this->hullMessage->tracker.running && (!this->hullMessage->flash || this->hullMessage->flashTracker.Progress(-1.f) <= 0.5f))
    {
        renderHullBox = this->hullBox_Red;
        renderHullLabel = this->hullLabel_Red;
    }
    // Render the primitive
    CSurface::GL_RenderPrimitive(renderHullBox);

    // Render hull label
    std::string hullText = G_->GetTextLibrary()->GetText("status_hull", G_->GetTextLibrary()->currentLanguage);
    Pointf textSize = freetype::easy_measurePrintLines(62, 0.f, 0.f, 999, hullText);

    float textWidth = roundf(textSize.x);
    float textureWidth = 1.f;
    float textureHeight = 1.f;
    float scaleFactor = 16.f;

    // Check for primitive
    if (renderHullLabel == nullptr)
    {
        textureWidth = 1.f;
        scaleFactor = 16.f;
    }
    else
    {
        textureWidth = static_cast<float>(renderHullLabel->width_);
        textureHeight = static_cast<float>(renderHullLabel->height_);
        scaleFactor = 16.f / textureWidth;
    }

    // Modify the box under the "HULL" text based on the text size of the current language
    CSurface::GL_BlitImagePartial(renderHullLabel, 0.f, 0.f, 16.f, textureHeight, 0.f, scaleFactor, 0.f, 1.f, 1.f, COLOR_WHITE, false);
    CSurface::GL_BlitImagePartial(renderHullLabel, 16.f, 0.f, textWidth - 15.f, textureHeight, scaleFactor, 17.f / textureWidth, 0.f, 1.f, 1.f, COLOR_WHITE, false);
    CSurface::GL_BlitImagePartial(renderHullLabel, textWidth + 1.f, 0.f, 34.f, textureHeight, 17.f / textureWidth, 51.f / textureWidth, 0.f, 1.f, 1.f, COLOR_WHITE, false);
    CSurface::GL_BlitImagePartial(renderHullLabel, textWidth + 35.f, 0.f, 121.f - (textWidth + 35.f), textureHeight, 51.f / textureWidth, 52.f / textureWidth, 0.f, 1.f, 1.f, COLOR_WHITE, false);

    // Render health mask
    int currentHealth = this->ship->ship.hullIntegrity.first;
    int maxHealth = this->ship->ship.hullIntegrity.second;

    if (currentHealth != this->lastHealth || !this->healthMask)
    {
        this->lastHealth = currentHealth;

        float healthRatio = static_cast<float>(currentHealth) / static_cast<float>(maxHealth);
        // Fix is here, reworked the original if/else logic with my own that used the health ratio which was already being provided for the HP-Bar lenght
        float red, green, blue;
        if (!g_playerHpColorFix)
        {
            if (currentHealth > 19)
            {
                red = 120.f;
                green = 255.f;
                blue = 120.f;
            }
            else if (currentHealth > 9)
            {
                red = 255.f;
                green = 230.f;
                blue = 92.f;
            }
            else
            {
                red = 255.f;
                green = 92.f;
                blue = 92.f;
            }
        }
        else
        {
            if (healthRatio > 0.65f)
            {
                red = 120.f;
                green = 255.f;
                blue = 120.f;
            }
            else if (healthRatio > 0.32f)
            {
                red = 255.f;
                green = 230.f;
                blue = 92.f;
            }
            else
            {
                red = 255.f;
                green = 92.f;
                blue = 92.f;
            }
        }

        CSurface::GL_DestroyPrimitive(this->healthMask);

        GL_Color healthColor = GL_Color(red / 255, green / 255, blue / 255, 1.f);

        this->healthMask = CSurface::GL_CreateImagePartialPrimitive(this->healthMaskTexture, 11.f, 0.f, healthRatio * 360.f, 65.f, 0.f, healthRatio, 0.f, 1.f, 1.f, healthColor, false);
    }
    CSurface::GL_RenderPrimitive(this->healthMask);

    // Render shields
    this->RenderShields(false);

    // Render evade and oxygen
    GL_Primitive *currentEvadeOxygenBox;
    if (this->ship->GetNetDodgeFactor() == 0)
    {
        if (oxygenMessage->tracker.done || !oxygenMessage->tracker.running || (oxygenMessage->flash && (oxygenMessage->flashTracker.Progress(-1.f) > 0.5f)))
        {
            currentEvadeOxygenBox = this->evadeOxygenBox_topRed;
        }
        else
        {
            currentEvadeOxygenBox = this->evadeOxygenBox_bothRed;
        }
    }
    else if (oxygenMessage->tracker.done || !oxygenMessage->tracker.running || (oxygenMessage->flash && (oxygenMessage->flashTracker.Progress(-1.f) > 0.5f)))
    {
        currentEvadeOxygenBox = this->evadeOxygenBox;
    }
    else
    {
        currentEvadeOxygenBox = this->evadeOxygenBox_bottomRed;
    }

    CSurface::GL_RenderPrimitive(currentEvadeOxygenBox);

    // Render hacked systems
    if ((1 < this->ship->IsSystemHacked(SYS_OXYGEN)) && (this->flashTracker.Progress(-1.0) <= 0.5f))
    {
        CSurface::GL_RenderPrimitive(this->oxygenPurple);
    }
    if (((1 < this->ship->IsSystemHacked(SYS_ENGINES)) || (1 < this->ship->IsSystemHacked(SYS_PILOT))) && (this->flashTracker.Progress(-1.0) <= 0.5f))
    {
        CSurface::GL_RenderPrimitive(this->evadePurple);
    }

    // Render oxygen warning
    this->oxygenMessage->OnRender();

    // Render fuel, missiles, drones, and scrap icons
    if (this->ship->fuel_count < 4)
    {
        CSurface::GL_RenderPrimitive(this->fuelIcon_red);
    }
    else
    {
        CSurface::GL_RenderPrimitive(this->fuelIcon);
    }

    if (this->ship->GetMissileCount() < 1)
    {
        CSurface::GL_RenderPrimitive(this->missilesIcon_red);
    }
    else
    {
        CSurface::GL_RenderPrimitive(this->missilesIcon);
    }

    if (this->ship->GetDroneCount() < 1)
    {
        CSurface::GL_RenderPrimitive(this->dronesIcon_red);
    }
    else
    {
        CSurface::GL_RenderPrimitive(this->dronesIcon);
    }

    if (!this->noMoneyTracker.running || this->flashTracker.Progress(-1.f) > 0.5f)
    {
        CSurface::GL_RenderPrimitive(this->scrapIcon);
    }
    else
    {
        CSurface::GL_RenderPrimitive(this->scrapIcon_red);
    }

    // Render hull text
    CSurface::GL_SetColor(COLOR_BUTTON_TEXT);
    freetype::easy_print(62, 9.f, 9.f, hullText);

    // Render evade and oxygen details
    this->RenderEvadeOxygen(true);
    this->RenderResources(true);

    // Render hull warning if critically low
    this->hullMessage->OnRender();

    if (!this->bBossFight)
    {
        if (!this->bEnemyShip)
        {
            CSurface::GL_Translate(static_cast<float>(this->noShipShift.x), static_cast<float>(this->noShipShift.y));
        }
    }
    else
    {
        CSurface::GL_Translate(-120.f, 0.f);
    }

    CSurface::GL_Translate(0.f, static_cast<float>(this->intruderShift.y));
    CSurface::GL_Translate(static_cast<float>(this->intruderPos.x), static_cast<float>(this->intruderPos.y));
    this->boardingMessage->OnRender();

    CSurface::GL_PopMatrix();
}
