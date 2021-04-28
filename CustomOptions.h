#include "Global.h"

class CustomOptionsManager
{
public:
    CustomOptionsManager()
    {

    }

    static CustomOptionsManager *GetInstance()
    {
        return &instance;
    }

    struct Setting
    {
        bool defaultValue = false;
        int defaultAmount = 0;
        bool currentValue = false;
        int currentAmount = 0;
    };

    bool altMode = false;
    bool altModeChanged = false;

//    Setting holdButton;

//    Setting hullNumbers;
    Setting redesignedWeaponTooltips;

    Setting advancedCrewTooltips;
    Setting showAllyPowers;
    Setting showEnemyPowers;
    Setting advancedCrewTooltipRounding;

    Setting eventTooltips;

    Setting showWeaponCooldown;

//    Setting hackingDroneFix;

//    Setting infiniteMode;

//    Setting discordIntegration;

private:
    static CustomOptionsManager instance;
};
