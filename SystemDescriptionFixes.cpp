#include "Global.h"
#include "CustomSystems.h"
#include <boost/algorithm/string.hpp>
#include <sstream>
#include <iomanip>

// eventually this will have to be partially rewritten with custom system value support

static std::string RemoveTrailingZeros(std::string str)
{
    boost::trim_right_if(str, boost::is_any_of("0"));
    boost::trim_right_if(str, boost::is_any_of("."));

    return str;
}

HOOK_STATIC(ShipSystem, GetLevelDescription, (int systemId, int level, bool tooltip) -> std::string)
{
    LOG_HOOK("HOOK_STATIC -> ShipSystem::GetLevelDescription -> Begin (SystemDescriptionFixes.cpp)\n")
    std::string ret = super(systemId, level, tooltip);

    if (systemId == SYS_MEDBAY)
    {
        float multiplier = 1.f;

        if (level > 0)
        {
            multiplier = level * 1.5f;
        }

        std::string text = G_->GetTextLibrary()->GetText("medbay_healing");

        std::stringstream stream;

        stream << std::fixed << std::setprecision(3) << multiplier;
        std::string valueStr = RemoveTrailingZeros(stream.str());

        boost::algorithm::replace_all(text, "\\1", valueStr);
        ret = text;
    }

    if (systemId == SYS_TELEPORTER)
    {
        if (level == 3)
        {
            ret = G_->GetTextLibrary()->GetText("teleporter_instant");
        }
    }

    if (systemId == SYS_CLONEBAY)
    {
        if (level == 3)
        {
            ret = G_->GetTextLibrary()->GetText("clonebay_instant_fullheal");
        }
    }
 
    if (systemId == SYS_ENGINES && level != -1)
    {
        std::string text = G_->GetTextLibrary()->GetText("engine");

        const std::vector<std::pair<int,int>>& dodgeVector = CustomSystemManager::GetInstance()->engineDodgeLevels.systemLevels;
        int dodge = dodgeVector[level].first;

        if (level >= dodgeVector.size() || dodge == -2147483648)
        {
            const std::vector<int>& defaultVector = CustomSystemManager::GetInstance()->engineDodgeLevels.defaultLevels;
            if (level >= defaultVector.size())
            {
                dodge = 0;
            }
            else
            {
                dodge = defaultVector[level];
            }
        }

        std::stringstream stream;
        stream << std::fixed << std::setprecision(0) << dodge;
        boost::algorithm::replace_all(text, "\\1", stream.str());
        

        const std::vector<std::pair<float,float>>& chargeVector = CustomSystemManager::GetInstance()->engineChargeLevels.systemLevels;
        float jumpCharge = chargeVector[level].first;

        if (level >= chargeVector.size() || jumpCharge == -2147483648.f)
        {
            jumpCharge = 1.f + (level * 0.25f);
        }


    
        std::stringstream stream2;
        stream2 << std::fixed << std::setprecision(2) << jumpCharge;
        std::string valueStr = RemoveTrailingZeros(stream2.str());
        boost::algorithm::replace_all(text, "\\2", valueStr);
        ret = text;
    }
    

    
    return ret;
}
