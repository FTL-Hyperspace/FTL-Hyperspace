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

struct CustomVictoryAchievement
{
    std::string victoryName = "";
    TextString name;
    TextString description;
    std::string icon = "S_V";
    GL_Color color = {235.f/255.f, 245.f/255.f, 229.f/255.f, 1.f};
    bool quiet = false;
    bool secret = false;

    std::unordered_map<std::string, CAchievement*> achievements;

    CAchievement *GetVictoryAchievement(std::string shipName);
    CAchievement *SetupVictoryAchievement(std::string shipName);
    void SetupVictoryAchievementText(CAchievement* ach);
};

class CustomShipUnlocks
{
public:
    GL_Primitive *smallOutline = nullptr;
    GL_Primitive *smallOverlay = nullptr;

    static void LockAchievement(CAchievement *ach);

    void ParseUnlockNode(rapidxml::xml_node<char> *node, const std::string& shipName);
    void ParseVictoryAchievements(rapidxml::xml_node<char> *node);

    void OnLanguageChange();
    void Save(int file);
    void LoadVersionOne(int file);
    void UnlockShip(const std::string& shipBlueprint, bool silent, bool checkMultiUnlocks=true, bool isEvent=false);
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

    int CheckCustomShipUnlockQuest(const std::string& name, int variant = 0)
    {
        std::string finalName = name;

        if (variant == 1) finalName.append("_2");
        else if (variant == 2) finalName.append("_3");

        auto it = customUnlockQuestShips.find(finalName);
        if (it != customUnlockQuestShips.end())
        {
            return it->second;
        }

        return -1;
    }

    bool CustomShipHasUnlockQuest(const std::string& name)
    {
        auto it = customShipUnlocks.find(name);
        if (customShipUnlocks.find(name) != customShipUnlocks.end())
        {
            for (ShipUnlock &unlock : it->second)
            {
                if (unlock.type == ShipUnlock::UnlockType::EVENT)
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool CustomShipHasUnlockQuestAnyLayout(const std::string& name)
    {
        return CustomShipHasUnlockQuest(name) || CustomShipHasUnlockQuest(name + "_2") || CustomShipHasUnlockQuest(name + "_3");
    }

    int CheckCustomShipVictory(const std::string& name, int variant = 0)
    {
        std::string finalName = name;

        if (variant == 1) finalName.append("_2");
        else if (variant == 2) finalName.append("_3");

        auto it = shipVictories.find(finalName);
        if (it != shipVictories.end())
        {
            return it->second;
        }

        return -1;
    }

    int CheckCustomShipVictory(const std::string& name, const std::string& type, int variant = 0)
    {
        std::string finalName = name;

        if (variant == 1) finalName.append("_2");
        else if (variant == 2) finalName.append("_3");

        auto it = customShipVictories[type].find(finalName);
        if (it != customShipVictories[type].end())
        {
            return it->second;
        }

        return -1;
    }

    void ResetFlags();
    void WipeProfile();

    // Unlock Quest Achievements
    CAchievement *GetQuestAchievement(std::string name);
    CAchievement *SetupQuestAchievement(std::string name);
    void SetupQuestAchievementText(CAchievement* ach);

    // Victory Achievements
    CAchievement *GetVictoryAchievement(std::string name);
    CAchievement *SetupVictoryAchievement(std::string name);
    void SetupVictoryAchievementText(CAchievement* ach);

    std::string setCustomVictoryType = "flagship";
    void SetVictoryAchievement(const std::string& ship);
    void SetVictoryAchievement(const std::string& ship, const std::string& type);

    int loadVersion = 0;

    static CustomShipUnlocks* instance;
    std::vector<std::string> customUnlockedShips;
    std::unordered_map<std::string, int> customUnlockQuestShips;
    std::unordered_map<std::string, int> shipVictories;
    std::unordered_map<std::string, std::unordered_map<std::string, int>> customShipVictories;

    std::vector<std::string> customVictoryTypes;
    std::unordered_map<std::string, CustomVictoryAchievement> customVictories;

private:
    std::unordered_map<std::string, std::vector<ShipUnlock>> customShipUnlocks;
    std::unordered_map<std::string, CAchievement*> customShipUnlockAchievements;

    std::unordered_map<std::string, CAchievement*> customShipQuestAchievements;
    std::unordered_map<std::string, CAchievement*> customShipVictoryAchievements;
};
