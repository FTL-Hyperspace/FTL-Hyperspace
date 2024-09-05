#pragma once
#include "rapidxml.hpp"
#include "Global.h"
#include <string>
#include <unordered_map>
#include <vector>

class HullNumbers
{
public:
    struct IndicatorInfo
    {
        int x;
        int y;
        int type;
        std::string align;
    };

    void ParseHullNumbersNode(rapidxml::xml_node<char> *node);

    IndicatorInfo playerIndicator;
    IndicatorInfo enemyIndicator;
    std::unordered_map<std::string, IndicatorInfo> enemyIndicatorLoc;
    IndicatorInfo bossIndicator;
    std::unordered_map<std::string, IndicatorInfo> bossIndicatorLoc;

    bool enabled;

    static void PrintAlignment(int font, int x, int y, std::string str, std::string align);
    static HullNumbers *GetInstance() { return &instance; }
private:

    IndicatorInfo& ParseIndicatorInfo(IndicatorInfo& indicatorInfo, rapidxml::xml_node<char> *node);

    static HullNumbers instance;
};

class HullBars
{
public:

    void ParseHullBarsNode(rapidxml::xml_node<char> *node);
    void ParseHullBarsColorsNode(rapidxml::xml_node<char> *node);

    void RefreshPosition(bool BossBox)
    {
        if (hullBarImage == nullptr) return;
        if (BossBox)
        {
            hullBarImage->x = 764;
            hullBarImage->y = 47;
        }
        else
        {
            hullBarImage->x = 889;
            hullBarImage->y = 90;
        }
    }
    GL_Color GetBarColor(int index)
    {
        return barColor[index % barColor.size()];
    }

    // 0: disabled
    // 1: stacking hp bars
    // 2: fixed bar width scaling with max hp
    int enabledType = 2;
    int barWidth = 22; // 22 Hp is vanilla "max" hp

    CachedImage* hullBarImage = nullptr;
    std::vector<GL_Color> barColor = { GL_Color(0.47f, 1.f, 0.47f, 1.f) }; // Unless we offer customization of the base HP bar color in the future, this is fine

    static HullBars *GetInstance() { return &instance; }
private:
    static HullBars instance;
};
