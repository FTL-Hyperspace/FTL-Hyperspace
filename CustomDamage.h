#include "FTLGame.h"
#include <stack>

struct CustomDamage
{
    int timeDilation = 0;
};




class CustomDamageManager
{
public:
    CustomDamage* GetCustomDamage()
    {
        auto ret = dmgQueue.top();
        dmgQueue.pop();
        return ret;
    }

    void SetCustomDamage(CustomDamage* dmg)
    {
        dmgQueue.push(dmg);
    }

private:
    std::stack<CustomDamage*> dmgQueue;
};
