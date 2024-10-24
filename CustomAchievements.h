#pragma once

#include "Global.h"

struct CustomAchievement
{
    CAchievement ach;

    TextString name;
    TextString description;

    TextString secretName;
    TextString secretDescription;

    std::string sound;

    bool hidden = false;

    void ParseAchievement(rapidxml::xml_node<char> *node, std::string *varName=nullptr);
};

class CustomAchievementSection
{
public:
    void OnRender(Point pos);
    void MouseMove(int mX, int mY);
    int GetHeight();
    int GetMaxHeight();
    int GetVisibleAchievements();
    int GetUnlockedAchievements();
    bool Visible();

    TextString heading;
    TextString secretHeading;
    std::vector<CustomAchievement*> achievements;
    bool hidden = false;
    CustomAchievement* selectedAch = nullptr;
};

class CustomAchievementPage
{
public:
    void OnRender(Point pos);
    bool RenderBackground(Point pos);
    void MouseMove(int mX, int mY);
    bool Visible();

    std::vector<CustomAchievementSection> achievements;
};

class CustomAchievementTracker
{
public:
    GL_Primitive *smallOutline = nullptr;
    GL_Primitive *largeOutline = nullptr;
    GL_Primitive *largeOverlay = nullptr;

    void ParseAchievements(rapidxml::xml_node<char> *node);
    void ParseAchievement(rapidxml::xml_node<char> *node);
    CustomAchievement &ParseShipAchievement(rapidxml::xml_node<char> *node, const std::string &ship);
    CustomAchievement &GetAchievement(const std::string &name);
    int GetAchievementStatus(const std::string &name);
    void UpdateAchievement(CustomAchievement &ach);
    void UpdateAchievements();
    void UpdateVariableAchievements(const std::string &varName, int varValue, bool inGame=true);
    bool CheckShipAchievement(CustomAchievement &ach);
    void SetAchievement(const std::string &name, bool noPopup);
    void RemoveAchievement(const std::string &name);
    std::vector<CAchievement*> GetShipAchievementsCustom(const std::string &ship, int layout, bool showHidden);
    std::vector<CAchievement*> GetShipAchievementsCustom(int shipId, int layout, bool showHidden);

    void OnInitStats();

    void Save(int file);
    void LoadVersionThree(int file);

    void LoadCurrent(int file)
    {
        LoadVersionThree(file);
    }

    void ResetFlags();
    void WipeProfile();

    void MouseMove(int page, int mX, int mY)
    {
        achievementPages[page-1].MouseMove(mX, mY);
    }
    void RenderPage(int page, Point pos)
    {
        achievementPages[page-1].OnRender(pos);
    }
    bool RenderBackgroundPage(int page, Point pos)
    {
        return achievementPages[page-1].RenderBackground(pos);
    }
    int NextPage(int page);
    int PrevPage(int page);
    bool HasCustomAchievementPage()
    {
        return !achievementPages.empty();
    }
    int CountCustomAchievementPages()
    {
        return achievementPages.size();
    }

    GL_Color achievementPagesBoxTextColor = GL_Color(255.f/255.f, 255.f/255.f, 255.f/255.f, 1.f);
    GL_Color achievementPagesBoxOutlineColor = GL_Color(235.f/255.f, 245.f/255.f, 229.f/255.f, 1.f);

    Button *achievementButtonLeft = nullptr;
    Button *achievementButtonRight = nullptr;
    GL_Texture *statsBack1 = nullptr;
    GL_Texture *statsBack2 = nullptr;
    GL_Texture *statsBorder = nullptr;
    bool statsInitTextures = false;

    static CustomAchievementTracker* instance;
private:
    std::unordered_map<std::string, CustomAchievement> customAchievements;
    std::unordered_map<std::string, std::vector<CustomAchievement*>> variableAchievements;
    std::unordered_map<std::string, int> achievementUnlocks;
    std::vector<CustomAchievementPage> achievementPages;
};
