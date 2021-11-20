#include "Global.h"
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
    
    return ret;
}
