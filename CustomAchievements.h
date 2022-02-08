#pragma once

#include "Global.h"

struct CustomAchievement
{
    CAchievement ach;

    TextString name;
	TextString description;

	TextString secretName;
	TextString secretDescription;
};

class CustomAchievementTracker
{
public:
    GL_Primitive *smallOutline = nullptr;
    GL_Primitive *largeOutline = nullptr;
    GL_Primitive *largeOverlay = nullptr;

    void ParseAchievements(rapidxml::xml_node<char> *node);
    CustomAchievement &GetAchievement(const std::string &name);
    int GetAchievementStatus(const std::string &name);
    void UpdateAchievement(CustomAchievement &ach);
    void UpdateAchievements();
    void UpdateVariableAchievements(const std::string &varName, int varValue, bool inGame=true);
    void SetAchievement(const std::string &name, bool noPopup);

    void Save(int file);
    void LoadVersionThree(int file);

    void LoadCurrent(int file)
    {
        LoadVersionThree(file);
    }

    void ResetFlags();
    void WipeProfile();

    static CustomAchievementTracker* instance;
private:
    std::unordered_map<std::string, CustomAchievement> customAchievements;
    std::unordered_map<std::string, std::vector<CustomAchievement*>> variableAchievements;
    std::unordered_map<std::string, int> achievementUnlocks;
};
