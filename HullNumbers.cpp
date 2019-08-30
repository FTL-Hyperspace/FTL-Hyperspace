#include "HullNumbers.h"
#include <boost/lexical_cast.hpp>

HullNumbers HullNumbers::instance = HullNumbers();

void HullNumbers::ParseHullNumbersNode(rapidxml::xml_node<char>* node)
{
    try
    {
        auto child = node->first_node("playerText");

        auto playerX = boost::lexical_cast<int>(child->first_attribute("x")->value());
        auto playerY = boost::lexical_cast<int>(child->first_attribute("y")->value());
        auto playerType = boost::lexical_cast<int>(child->first_attribute("type")->value());

        child = node->first_node("enemyText");

        auto enemyX = boost::lexical_cast<int>(child->first_attribute("x")->value());
        auto enemyY = boost::lexical_cast<int>(child->first_attribute("y")->value());
        auto enemyType = boost::lexical_cast<int>(child->first_attribute("type")->value());

        child = node->first_node("bossText");

        auto bossX = boost::lexical_cast<int>(child->first_attribute("x")->value());
        auto bossY = boost::lexical_cast<int>(child->first_attribute("y")->value());
        auto bossType = boost::lexical_cast<int>(child->first_attribute("type")->value());


        this->playerIndicator = { playerX, playerY, playerType };
        this->enemyIndicator = { enemyX, enemyY, enemyType };
        this->bossIndicator = { bossX, bossY, bossType };
    }
    catch (boost::bad_lexical_cast const &e)
    {
        MessageBoxA(NULL, "boost::bad_lexical_cast in hyperspace.xml", "Error", MB_ICONERROR);
    }
    catch (...)
    {
        MessageBoxA(NULL, "error parsing <hullNumbers> in hyperspace.xml", "Error", MB_ICONERROR);
    }
}


HOOK_METHOD(ShipStatus, RenderHealth, (bool unk) -> void)
{

    super(unk);

    HullNumbers *manager = HullNumbers::GetInstance();
    if (unk == false && manager && manager->enabled)
    {

        char buffer[64];
        sprintf(buffer, "%d", this->ship->ship.hullIntegrity.first);
        std::string str(buffer);
        auto textInfo = manager->playerIndicator;
        freetype::easy_print(textInfo.type, textInfo.x, textInfo.y, str);
    }
}

HOOK_METHOD(CombatControl, RenderTarget, () -> void)
{
    super();

    HullNumbers *manager = HullNumbers::GetInstance();




    if (this->GetCurrentTarget() && manager && manager->enabled)
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
        std::string str(buffer);

        HullNumbers::IndicatorInfo textInfo;
        if (this->CurrentTargetIsBoss())
        {
            textInfo = manager->bossIndicator;
        }
        else
        {
            textInfo = manager->enemyIndicator;
        }

        freetype::easy_printCenter(textInfo.type, textInfo.x, textInfo.y, str);
    }
}
