#pragma once
#include "Global.h"
#include "CustomShipSelect.h"

struct ShipUnlock
{
    enum class UnlockType
    {
        DEFEAT_FLAGSHIP,
        REACH_SECTOR,
        VICTORY_ANY,
        UNLOCK_OTHER,
        EVENT
    };

    std::string unlocksShip;
    UnlockType type;
    std::vector<std::string> otherRequiredShips;
    int value;
    std::string shipReq;
    bool silent;
};

class CustomShipUnlocks
{
public:
    void ParseUnlockNode(rapidxml::xml_node<char> *node, const std::string& shipName);

    void Save(int file);
    void LoadVersionOne(int file);
    void UnlockShip(const std::string& shipBlueprint, bool silent, bool checkMultiUnlocks=true);
    void CreateUnlockAchievements();
    bool ValidUnlock(const ShipUnlock& unlock, const std::string& currentShip, ShipUnlock::UnlockType type);
    void CheckSectorUnlocks(const std::string& currentShip, int sector);
    void CheckMultiUnlocks();
    void CheckBasicUnlock(const std::string& currentShip, ShipUnlock::UnlockType type);
    bool CheckVanillaUnlocks(const ShipUnlock& unlock, const std::string& currentShip);
    void UnlockAllShips();

    void LoadCurrent(int file)
    {
        LoadVersionOne(file);
    }

    bool GetCustomShipUnlocked(const std::string& name, int variant = 0)
    {
        std::string finalName = name;

        if (variant == 1) finalName.append("_2");
        else if (variant == 2) finalName.append("_3");

        return !CustomShipHasUnlock(finalName) || std::find(customUnlockedShips.begin(), customUnlockedShips.end(), finalName) != customUnlockedShips.end();
    }

    bool CustomShipHasUnlock(const std::string& name)
    {
        return customShipUnlocks.find(name) != customShipUnlocks.end();
    }

    void RemoveShipUnlock(const std::string& name)
    {
        auto it = std::find(customUnlockedShips.begin(), customUnlockedShips.end(), name);

        if (it != customUnlockedShips.end())
        {
            customUnlockedShips.erase(it);
        }

        G_->GetScoreKeeper()->Save(false);
    }

    void WipeProfile();

    int loadVersion = 0;

    static CustomShipUnlocks* instance;
    std::vector<std::string> customUnlockedShips;

private:
    std::unordered_map<std::string, std::vector<ShipUnlock>> customShipUnlocks;
    std::unordered_map<std::string, CAchievement*> customShipUnlockAchievements;
};
