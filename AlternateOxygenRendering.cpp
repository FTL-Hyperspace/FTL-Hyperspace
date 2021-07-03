#pragma GCC push_options
#pragma GCC optimize ("O3")

#include "AlternateOxygenRendering.h"
#include "CustomOptions.h"

#include <boost/lexical_cast.hpp>

AlternateOxygenManager AlternateOxygenManager::instance = AlternateOxygenManager();

void AlternateOxygenManager::ParseGradientNode(rapidxml::xml_node<char> *node)
{
    oxygenGradient.clear();
    for (auto child = node->first_node(); child; child = child->next_sibling())
    {
        std::string label = child->name();

        if (label == "color")
        {
            GradientColor color;
            color.first = -1.0;

            if (child->first_attribute("r"))
            {
                color.second.r = boost::lexical_cast<float>(child->first_attribute("r")->value()) / 255.f;
            }
            if (child->first_attribute("g"))
            {
                color.second.g = boost::lexical_cast<float>(child->first_attribute("g")->value()) / 255.f;
            }
            if (child->first_attribute("b"))
            {
                color.second.b = boost::lexical_cast<float>(child->first_attribute("b")->value()) / 255.f;
            }
            if (child->first_attribute("oxygen"))
            {
                color.first = boost::lexical_cast<float>(child->first_attribute("oxygen")->value());
            }
            oxygenGradient.push_back(color);
        }
    }
    SetMissingGradientPoints();
}

void AlternateOxygenManager::SetMissingGradientPoints()
{
    if (oxygenGradient.empty()) return;

    if (oxygenGradient.front().first == -1.0)
    {
        oxygenGradient.front().first = 0.0;
    }
    if (oxygenGradient.back().first == -1.0)
    {
        oxygenGradient.back().first = 100.0;
    }

    int a = 0;
    for (int i=1; i<oxygenGradient.size(); ++i)
    {
        if (oxygenGradient[i].first != -1.0)
        {
            for (int j=a+1; j<i; ++j)
            {
                oxygenGradient[j].first = oxygenGradient[a].first * (i-j) / (i-a) + oxygenGradient[i].first * (j-a) / (i-a);
            }
            a = i;
        }
    }
}

void AlternateOxygenManager::CreateDefaultGradient()
{
    oxygenGradient.clear();

    GradientColor color;

    color.first = 0.0;
    color.second.r = 0.f/255.f;
    color.second.g = 0.f/255.f;
    color.second.b = 219.f/255.f;
    oxygenGradient.push_back(color);

    color.first = 100.0;
    color.second.r = 230.f/255.f;
    color.second.g = 226.f/255.f;
    color.second.b = 219.f/255.f;
    oxygenGradient.push_back(color);
}

GL_Color AlternateOxygenManager::CalculateGradient(float value)
{
    for (auto it = oxygenGradient.rbegin(); it != oxygenGradient.rend(); ++it)
    {
        if (value >= it->first)
        {
            if (it == oxygenGradient.rbegin()) return it->second;
            auto it2 = it-1;

            GL_Color color;
            float x = (value - it->first) / (it2->first - it->first);
            color.r = it->second.r * (1-x) + it2->second.r * x;
            color.g = it->second.g * (1-x) + it2->second.g * x;
            color.b = it->second.b * (1-x) + it2->second.b * x;
            return color;
        }
    }
    return oxygenGradient.front().second;
}

HOOK_METHOD(Room, OnRenderFloor, (float alpha, bool experimental) -> void)
{
    if (CustomOptionsManager::GetInstance()->alternateOxygenRendering.currentValue == true)
    {
        return CSurface::GL_RenderPrimitiveWithColor(this->floorPrimitive, AlternateOxygenManager::GetInstance()->CalculateGradient(this->lastO2));
    }
    else
    {
        super(alpha, experimental);
    }
}

#pragma GCC pop_options
