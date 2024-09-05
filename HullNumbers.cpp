#include "HullNumbers.h"
#include <boost/lexical_cast.hpp>

HullNumbers HullNumbers::instance = HullNumbers();
HullBars HullBars::instance = HullBars();
bool g_overrideHullBar = false;

// TODO: 
// xml options, with colour selection for each bar
// xml options to select the lenght of the bar
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

        auto child = node->first_node("barColor");
        while (child)
        {
            ParseHullBarsColorsNode(child);
            child = child->next_sibling("barColor");
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
    if(HBManager->enabledType == 1 && this->GetCurrentTarget()->ship.hullIntegrity.first > HBManager->barWidth)
    {
        int ibar = std::floor(this->GetCurrentTarget()->ship.hullIntegrity.first / HBManager->barWidth);

        HBManager->RefreshPosition(boss_visual);
        float x1 = HBManager->barWidth / 22.f;
        float x2 = ((float)(this->GetCurrentTarget()->ship.hullIntegrity.first % (HBManager->barWidth))/HBManager->barWidth)*(HBManager->barWidth / 22.f);

        HBManager->hullBarImage->SetPartial(0.0,0.0,x1,1.0);
        HBManager->hullBarImage->OnRender(HBManager->GetBarColor(ibar - 1));

        HBManager->hullBarImage->SetPartial(0.0,0.0,x2,1.0);
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
        HullBars::GetInstance()->hullBarImage = new CachedImage("combatUI/box_hostiles_hull2.png",889 ,90);
    }
}

HOOK_METHOD(CachedImage, SetPartial, (float x_start, float y_start, float x_size, float y_size) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CachedPrimitive::SetPartial -> Begin (HullNumbers.cpp)\n")
    
    if (g_overrideHullBar && y_size == 1.0)
    {
        HullBars *HBManager = HullBars::GetInstance();
        std::pair<int, int> shipHp = G_->GetShipManager(1)->ship.hullIntegrity;

        if (HBManager->enabledType == 1 && shipHp.first > HBManager->barWidth)
        {
            x_size = 0.0;
        }
        else if (HBManager->enabledType == 2 && shipHp.second > HBManager->barWidth)
        {
            x_size = ((float) shipHp.first / (float) shipHp.second) * (HBManager->barWidth / 22.f);
        }
    }

    super(x_start, y_start, x_size, y_size);
}
