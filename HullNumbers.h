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
        { // If you see this it means I forgot to put the boss hp coord, do not accept this PR
            hullBarImage->x = 0;
            hullBarImage->y = 0;
        }
        else
        {
            hullBarImage->x = 889;
            hullBarImage->y = 90;
        }
    }
    GL_Color GetBarColor(int index)
    {
        return debugColor[index % debugColor.size()];
    }

    // 0: disabled
    // 1: stacking hp bars
    // 2: fixed bar width scaling with max hp
    int enabledType = 2;
    int barWidth = 12; // 22 Hp is vanilla "max" hp

    CachedImage* hullBarImage = nullptr;
    std::vector<GL_Color> debugColor = {
        GL_Color(120.f/255.f, 255.f/255.f, 120.f/255.f, 1.f),
        GL_Color(255.f/255.f, 255.f/255.f, 0.f/255.f, 1.f),
        GL_Color(255.f/255.f, 180.f/255.f, 0.f/255.f, 1.f),
        GL_Color(255.f/255.f, 120.f/255.f, 0.f/255.f, 1.f),
        GL_Color(255.f/255.f, 80.f/255.f, 0.f/255.f, 1.f),
        GL_Color(255.f/255.f, 40.f/255.f, 0.f/255.f, 1.f),
        GL_Color(255.f/255.f, 0.f/255.f, 0.f/255.f, 1.f),
    };

    static HullBars *GetInstance() { return &instance; }
private:
    static HullBars instance;
};
