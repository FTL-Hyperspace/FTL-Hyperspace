#include "Global.h"

class CustomOptionsManager
{
public:
    CustomOptionsManager()
    {
        rightClickDoorOpening.defaultValue = true;
        rightClickDoorOpening.currentValue = true;
        
        dismissSound.defaultValue = true;
        dismissSound.currentValue = true;
        dismissSound.defaultAmount = "airLoss";
        dismissSound.currentAmount ="airLoss";
    }

    static CustomOptionsManager *GetInstance()
    {
        return &instance;
    }

    template<typename T> struct Setting
    {
        T defaultAmount = T();
        bool defaultValue = false;
        T currentAmount = T();
        bool currentValue = false;
    };

    struct Defaults
    {
        bool beaconType_hideVanillaLabel = true;
        bool checkCargo = false;
        bool choiceRequiresCrew = false;
    };

    bool altMode = true;
    bool altModeChanged = true;

//    Setting holdButton;

//    Setting hullNumbers;
    Setting<int> redesignedWeaponTooltips;
    Setting<int> redesignedCrewTooltips;
    Setting<int> redesignedDroneTooltips;
    Setting<int> redesignedAugmentTooltips;

    Setting<int> advancedCrewTooltips;
    Setting<int> showAllyPowers;
    Setting<int> showEnemyPowers;
    Setting<int> advancedCrewTooltipRounding;

    Setting<int> eventTooltips;

    Setting<int> alternateCrewMovement;
    Setting<int> rightClickDoorOpening;

    Setting<int> showWeaponCooldown;

    Setting<int> showReactor;

    Setting<int> showAllConnections;

    Setting<int> alternateOxygenRendering;

    Setting<int> showScrapCollectorScrap;

    Setting<std::string> dismissSound;

    Defaults defaults;

//    Setting hackingDroneFix;

//    Setting infiniteMode;

//    Setting discordIntegration;

private:
    static CustomOptionsManager instance;
};
