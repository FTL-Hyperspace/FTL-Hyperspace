#include "Global.h"

class CustomOptionsManager
{
public:
    CustomOptionsManager()
    {
        rightClickDoorOpening.defaultValue = true;
        rightClickDoorOpening.currentValue = true;

        dismissSound.defaultValue = "airLoss";
        dismissSound.currentValue ="airLoss";
    }

    static CustomOptionsManager *GetInstance()
    {
        return &instance;
    }

    template<typename T> struct Setting
    {
        T defaultValue = T();
        T currentValue = T();
    };

    struct Defaults
    {
        bool beaconType_hideVanillaLabel = true;
        bool checkCargo = false;
        bool choiceRequiresCrew = false;
        bool instantEscape_removeShipBox = false;
    };

    bool altMode = true;
    bool altModeChanged = true;

    bool showAllNodeConnections = true; // If split is enabled then this will automatically be enabled too (can be changed in the future)
    bool showAllNodeConnectionsChanged = true;

//    Setting holdButton;

//    Setting hullNumbers;
    Setting<bool> upgradeRevisitFix;

    Setting<bool> droneIonDodgeFix;
    Setting<bool> combatDroneRapidFireFix;

    Setting<bool> redesignedWeaponTooltips;
    Setting<bool> redesignedCrewTooltips;
    Setting<bool> redesignedDroneTooltips;
    Setting<bool> redesignedAugmentTooltips;

    Setting<bool> advancedCrewTooltips;
    Setting<bool> showAllyPowers;
    Setting<bool> showEnemyPowers;
    Setting<int> advancedCrewTooltipRounding;

    Setting<bool> eventTooltips;

    Setting<bool> alternateCrewMovement;
    Setting<bool> rightClickDoorOpening;

    Setting<bool> showWeaponCooldown;

    Setting<bool> showReactor;

    Setting<bool> showMissileCount;
    Setting<bool> showDroneCount;
    Setting<bool> showCrewLimit;

    Setting<bool> showAllConnections;

    struct ConnectionDistanceSettings
    {
        float min = 0.f;
        float max = 165.f;
        int gridRange = 1;
        int minJumps = 4;
        int maxJumps = 100;
        int minJumpsToBase = 3;
        int maxJumpsToBase = 5;
        int hardMinJumpsToBase = 4;
        int hardMaxJumpsToBase = 7;
        int bossMinJumps = 3;
        int bossMaxJumps = 7;
        int exitXMin = 4;
        int baseXMin = 2;
        int hardBaseXMin = 3;
        int bossXMin = 4;
        int xVariants = 2;
    };
    Setting<std::map<std::string, ConnectionDistanceSettings>> sectorCDSMap;

    Setting<bool> alternateOxygenRendering;

    Setting<bool> showScrapCollectorScrap;

    Setting<bool> preIgniteChargers;

    Setting<bool> altLockedMiniships;

    Setting<bool> altCreditSystem;

    Setting<bool> allowRenameInputSpecialCharacters;

    Setting<bool> insertNewlineForMultipleCrewTooltips;

    Setting<bool> disableDefaultTutorial;

    Setting<std::string> dismissSound;

    Setting<bool> targetableArtillery;

    Setting<bool> oxygenWithoutSystem;

    Setting<bool> shieldWithoutSystem;

    Setting<bool> droneSaveStations;

    Setting<bool> droneSelectHotkeys;

    Setting<bool> cloakRenderFix;

    Setting<bool> dualMedical;

    Setting<bool> enhancedCloneUI;

    Setting<bool> scaleSlugGel;

    Setting<bool> splitAllNodeView;

    Setting<bool> multiShipFix;

    Setting<bool> teleporterHackFix;

    Setting<bool> energyBypassTeleportRecall;

    Setting<bool> oxygenRefillFix;

    Setting<bool> disableLazyImageLoading;

    Defaults defaults;

//    Setting hackingDroneFix;

//    Setting infiniteMode;

//    Setting discordIntegration;

private:
    static CustomOptionsManager instance;
};
