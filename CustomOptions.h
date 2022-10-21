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
        dismissSound.defaultString = "airLoss";
        dismissSound.currentString ="airLoss";
    }

    static CustomOptionsManager *GetInstance()
    {
        return &instance;
    }

    struct Setting
    {
        bool defaultValue = false;
        int defaultAmount = 0;
        std::string defaultString = "";
        bool currentValue = false;
        int currentAmount = 0;
        std::string currentString = "";
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
    Setting redesignedWeaponTooltips;
    Setting redesignedCrewTooltips;
    Setting redesignedDroneTooltips;
    Setting redesignedAugmentTooltips;

    Setting advancedCrewTooltips;
    Setting showAllyPowers;
    Setting showEnemyPowers;
    Setting advancedCrewTooltipRounding;

    Setting eventTooltips;

    Setting alternateCrewMovement;
    Setting rightClickDoorOpening;

    Setting showWeaponCooldown;

    Setting showReactor;

    Setting showAllConnections;

    Setting alternateOxygenRendering;

    Setting showScrapCollectorScrap;

    Setting dismissSound;

    Defaults defaults;

//    Setting hackingDroneFix;

//    Setting infiniteMode;

//    Setting discordIntegration;

private:
    static CustomOptionsManager instance;
};
