#include "CustomAchievements.h"

#include <boost/lexical_cast.hpp>

CustomAchievementTracker* CustomAchievementTracker::instance = new CustomAchievementTracker();

void CustomAchievementTracker::ParseAchievements(rapidxml::xml_node<char> *node)
{
    if (smallOutline == nullptr) smallOutline = CSurface::GL_CreateRectOutlinePrimitive(0, 0, 32, 32, GL_Color(1.f, 1.f, 1.f, 1.f), 2.f);
    if (largeOutline == nullptr) largeOutline = CSurface::GL_CreateRectOutlinePrimitive(0, 0, 64, 64, GL_Color(1.f, 1.f, 1.f, 1.f), 2.f);
    if (largeOverlay == nullptr) largeOverlay = CSurface::GL_CreateRectPrimitive(0, 0, 64, 64, GL_Color(0.f, 0.f, 0.f, 0.75f));

    for (auto achNode = node->first_node(); achNode; achNode = achNode->next_sibling())
    {
        std::string achName = achNode->first_attribute("name")->value();
        std::string varName = "";

        CustomAchievement &ach = customAchievements[achName];
        ach.ach.name_id = achName;

        ach.ach.multiDifficulty = false;
        ach.ach.dimension = 64;
        ach.ach.outline = largeOutline;
        ach.ach.mini_outline = smallOutline;
        ach.ach.lockOverlay = largeOverlay;

        for (auto child = achNode->first_node(); child; child = child->next_sibling())
        {
            std::string name = child->name();
            std::string value = child->value();

            if (name == "name")
            {
                if (child->first_attribute("id"))
                {
                    ach.name.data = child->first_attribute("id")->value();
                    ach.name.isLiteral = false;
                }
                if (!value.empty())
                {
                    ach.name.data = value;
                    ach.name.isLiteral = true;
                }
            }
            if (name == "description")
            {
                if (child->first_attribute("id"))
                {
                    ach.description.data = child->first_attribute("id")->value();
                    ach.description.isLiteral = false;
                }
                if (!value.empty())
                {
                    ach.description.data = value;
                    ach.description.isLiteral = true;
                }
            }
            if (name == "header")
            {
                if (child->first_attribute("id"))
                {
                    ach.ach.header.data = child->first_attribute("id")->value();
                    ach.ach.header.isLiteral = false;
                }
                if (!value.empty())
                {
                    ach.ach.header.data = value;
                    ach.ach.header.isLiteral = true;
                }
            }
            if (name == "secretName")
            {
                if (child->first_attribute("id"))
                {
                    ach.secretName.data = child->first_attribute("id")->value();
                    ach.secretName.isLiteral = false;
                }
                if (!value.empty())
                {
                    ach.secretName.data = value;
                    ach.secretName.isLiteral = true;
                }
            }
            if (name == "secretDescription")
            {
                if (child->first_attribute("id"))
                {
                    ach.secretDescription.data = child->first_attribute("id")->value();
                    ach.secretDescription.isLiteral = false;
                }
                if (!value.empty())
                {
                    ach.secretDescription.data = value;
                    ach.secretDescription.isLiteral = true;
                }
            }
            if (name == "icon")
            {
                ach.ach.icon.SetImagePath("achievements/"+value+".png");
            }
            if (name == "lockImage")
            {
                ach.ach.lockImage.SetImagePath("achievements/"+value+".png");
            }
            if (name == "variable" && child->first_attribute("name") && child->first_attribute("amount"))
            {
                varName = child->first_attribute("name")->value();

                ach.ach.progress.second = boost::lexical_cast<int>(child->first_attribute("amount")->value());
                ach.ach.progress.first = 0;
            }
        }

        customAchievements[achName] = ach;
        if (!varName.empty())
        {
            variableAchievements[varName].push_back(&customAchievements[achName]);
        }
        UpdateAchievement(ach);
    }
}

void CustomAchievementTracker::LoadVersionThree(int file)
{
    // achievementUnlocks

    int length = FileHelper::readInteger(file);

    for (int i = 0; i < length; i++)
    {
        std::string k = FileHelper::readString(file);
        int v = FileHelper::readInteger(file);
        if (v != -1) achievementUnlocks[k] = v;
    }

    UpdateAchievements();
}

void CustomAchievementTracker::Save(int file)
{
    // achievementUnlocks

    int length = achievementUnlocks.size();

    FileHelper::writeInt(file, length);

    for (auto &i : achievementUnlocks)
    {
        FileHelper::writeString(file, i.first);
        FileHelper::writeInt(file, i.second);
    }
}

CustomAchievement &CustomAchievementTracker::GetAchievement(const std::string &name)
{
    return customAchievements[name];
}

int CustomAchievementTracker::GetAchievementStatus(const std::string &name)
{
    auto it = achievementUnlocks.find(name);
    if (it != achievementUnlocks.end()) return it->second;
    return -1;
}

void CustomAchievementTracker::UpdateAchievement(CustomAchievement &ach)
{
    ach.ach.difficulty = GetAchievementStatus(ach.ach.name_id);
    ach.ach.unlocked = ach.ach.difficulty != -1;

    if (ach.ach.unlocked)
    {
        ach.ach.name = ach.name;
        ach.ach.description = ach.description;
    }
    else
    {
        ach.ach.name = ach.secretName.data.empty() ? ach.name : ach.secretName;
        ach.ach.description = ach.secretDescription.data.empty() ? ach.name : ach.secretDescription;
    }
}

void CustomAchievementTracker::UpdateAchievements()
{
    for (auto &it : customAchievements)
    {
        UpdateAchievement(it.second);
    }
}

void CustomAchievementTracker::UpdateVariableAchievements(const std::string &varName, int varValue, bool inGame)
{
    auto vAchievements = variableAchievements.find(varName);
    if (vAchievements != variableAchievements.end())
    {
        for (CustomAchievement *ach : vAchievements->second)
        {
            ach->ach.progress.first = varValue;
            if (ach->ach.progress.first >= ach->ach.progress.second)
            {
                if (inGame)
                {
                    SetAchievement(ach->ach.name_id, false);
                }
                else
                {
                    // if not in game then set the achievement to EASY
                    int diff = *Global::difficulty;
                    *Global::difficulty = 0;
                    SetAchievement(ach->ach.name_id, false);
                    *Global::difficulty = diff;
                }
            }
        }
    }
}

void CustomAchievementTracker::SetAchievement(const std::string &name, bool noPopup)
{
    int oldDiff = GetAchievementStatus(name);
    int newDiff = *Global::difficulty;

    if (newDiff > oldDiff)
    {
        achievementUnlocks[name] = newDiff;

        CustomAchievement &ach = GetAchievement(name);
        UpdateAchievement(ach);
        ach.ach.newAchievement = newDiff != -1;

        if (!noPopup && G_->GetSettings()->achPopups)
        {
            G_->GetAchievementTracker()->recentlyUnlocked.push_back(&ach.ach);
        }
    }
}

void CustomAchievementTracker::ResetFlags()
{
    for (auto &it : customAchievements)
    {
        it.second.ach.newAchievement = false;
    }
}

void CustomAchievementTracker::WipeProfile()
{
    achievementUnlocks.clear();

    UpdateAchievements();
    ResetFlags();
}

// Fix invalid memory access

static bool inSetSectorEight = false;

HOOK_METHOD(AchievementTracker, SetSectorEight, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> AchievementTracker::SetSectorEight -> Begin (CustomAchievements.cpp)\n")
    inSetSectorEight = true;
    super();
    inSetSectorEight = false;
}

HOOK_METHOD(ScoreKeeper, GetShipId, (const std::string &blueprintName) -> std::pair<int, int>)
{
    LOG_HOOK("HOOK_METHOD -> ScoreKeeper::GetShipId -> Begin (CustomAchievements.cpp)\n")
    std::pair<int, int> ret = super(blueprintName);
    if (ret.first == -1 && inSetSectorEight) ret.first = 9; // dummy valid ship id, this affects type C unlock and lanius cruiser doesn't have a type C
    return ret;
}

HOOK_METHOD(AchievementTracker, CheckShipAchievements, (int shipId, bool hidePopups) -> void)
{
    LOG_HOOK("HOOK_METHOD -> AchievementTracker::CheckShipAchievements -> Begin (CustomAchievements.cpp)\n")
    if (shipId == -1) return;
    super(shipId, hidePopups);
}
