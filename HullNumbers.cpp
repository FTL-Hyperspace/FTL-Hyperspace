#include "HullNumbers.h"


HullNumbers HullNumbers::instance = HullNumbers();


HOOK_METHOD(ShipStatus, RenderHealth, (bool unk) -> void)
{

    super(unk);

    HullNumbers *manager = HullNumbers::GetInstance();
    if (unk == false && manager && manager->enabled) {

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
