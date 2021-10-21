#include "Global.h
#include <array>






struct customizedSystem
{
    customizedSystem(int startVal, int overValSize, int valInc, int startCost, int overCostSize, int costInc): valueIncrement(valInc), costIncrement(costInc) {
        valueOverride.pushback(startVal);
        valueOverride.resize(overValSize + 1, -1);
        costOverride.pushback(startCost);
        costOverride.resize(overCostSize + 1, -1);
    }

    customizedSystem(int startCost, int overCostSize, int costInc): costIncrement(costInc) {
        costOverride.pushback(startCost);
        costOverride.resize(overCostSize + 1, -1);
    }

    int valueIncrement = 0;
    vector<int> valueOverride;

    int costIncrement = 0;
    vector<int> costOverride;

};

struct allCustomizedSystems
{

};

