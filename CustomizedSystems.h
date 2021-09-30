#include "Global.h
#include <array>






struct customizedSystem
{
    customizedSystem(int startVal, int overValSize, int valInc, int startCost, int overCostSize, int costInc): valueIncrement(valInc), costIncrement(costInc) {

    }

    customizedSystem(int startCost, int overCostSize, int costInc): costIncrement(costInc) {

    }

    int valueIncrement = 0;
    vector<int> valueOverride;

    int costIncrement = 0;
    vector<int> costOverride;

};

