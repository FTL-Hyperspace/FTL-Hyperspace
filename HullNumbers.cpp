#include "HullNumbers.h"
#include "Global.h"
#include <boost/lexical_cast.hpp>

HullNumbers HullNumbers::instance = HullNumbers();


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

        if (child)
        {
            ParseIndicatorInfo(enemyIndicator, child);
        }

        child = node->first_node("bossText");

        if (child)
        {
            ParseIndicatorInfo(bossIndicator, child);
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


HOOK_METHOD(ShipStatus, RenderShields, (bool renderText) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipStatus::RenderShields -> Begin (HullNumbers.cpp)\n")
    super(renderText);

    HullNumbers *manager = HullNumbers::GetInstance();
    if (manager && manager->enabled)
    {
        char buffer[64];
        sprintf(buffer, "%d", this->ship->ship.hullIntegrity.first);
        auto textInfo = manager->playerIndicator;
        HullNumbers::PrintAlignment(textInfo.type, textInfo.x, textInfo.y, buffer, textInfo.align);
    }
}

static GL_Primitive* enemyHullNumbersBox = nullptr;

HOOK_METHOD(CombatControl, constructor, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CombatControl::constructor -> Begin (HullNumbers.cpp)\n")
    super();
    enemyHullNumbersBox = G_->GetResources()->CreateImagePrimitiveString("combatUI/enemy_hull_numbers_box.png", 0, 0, 0, COLOR_WHITE, 1.f, false);
}

HOOK_METHOD(CombatControl, RenderTarget, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CombatControl::RenderTarget -> Begin (HullNumbers.cpp)\n")
    super();

    HullNumbers *manager = HullNumbers::GetInstance();


    if (GetCurrentTarget() && manager && manager->enabled)
    {
        char buffer[64];
        sprintf(buffer, "%d", this->GetCurrentTarget()->ship.hullIntegrity.first);

        HullNumbers::IndicatorInfo textInfo;
        if (boss_visual)
        {
            textInfo = manager->bossIndicator;
        }
        else
        {
            textInfo = manager->enemyIndicator;
        }

        std::string textEnglish = G_->GetTextLibrary()->GetText("target_window", "");
        std::string textCurrent = G_->GetTextLibrary()->GetText("target_window");
        int xOffsetFont = freetype::easy_measurePrintLines(62, 0, 0, 999, textCurrent).x - freetype::easy_measurePrintLines(62, 0, 0, 999, textEnglish).x;

        CSurface::GL_PushMatrix();
        int xOffsetBox, yOffsetBox;
        if (boss_visual)
        {
            xOffsetBox = 94;
            yOffsetBox = 2;
        }
        else
        {
            xOffsetBox = 98;
            yOffsetBox = 7;
        }
        CSurface::GL_Translate(position.x + boxPosition.x + xOffsetBox + xOffsetFont, position.y + boxPosition.y + yOffsetBox, 0.0);
        CSurface::GL_RenderPrimitiveWithColor(enemyHullNumbersBox, GetCurrentTarget()->_targetable.hostile ? GL_Color(1.f, 0.7f, 0.7f, 1.f) : COLOR_WHITE);
        CSurface::GL_PopMatrix();

        if (GetCurrentTarget()->_targetable.hostile)
        {
            CSurface::GL_SetColor(GL_Color(1.f, 0.2f, 0.2f, 1.f));
        }
        else
        {
            CSurface::GL_SetColor(COLOR_WHITE);
        }
        HullNumbers::PrintAlignment(textInfo.type, textInfo.x + xOffsetFont, textInfo.y, buffer, textInfo.align);
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
