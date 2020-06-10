#include "rapidxml.hpp"
#include <string>

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
    IndicatorInfo bossIndicator;

    bool enabled;

    static void PrintAlignment(int font, int x, int y, std::string str, std::string align);
    static HullNumbers *GetInstance() { return &instance; }
private:

    IndicatorInfo& ParseIndicatorInfo(IndicatorInfo& indicatorInfo, rapidxml::xml_node<char> *node);

    static HullNumbers instance;
};

