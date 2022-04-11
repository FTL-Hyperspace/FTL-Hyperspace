#pragma once
#include "Global.h"

#include <boost/algorithm/string.hpp>

struct CustomScrapScaling
{
    float baseAmount = 15.0;
    float sectorAmount = 6.0;

    int difficultyAmount = 0;

    std::vector<float> amounts;

    int GetReward(int worldLevel, float resourceAmount)
    {
        worldLevel = std::max(0, worldLevel + difficultyAmount);

        if (amounts.empty()) // Not piecewise
        {
            return (int)(resourceAmount / 1000.0 * (sectorAmount*worldLevel + baseAmount));
        }
        else if (worldLevel >= amounts.size()) // Extrapolate
        {
            return (int)(resourceAmount / 1000.0 * (amounts.back() + sectorAmount*(worldLevel-amounts.size()+1)));
        }
        else // Piecewise
        {
            return (int)(resourceAmount / 1000.0 * amounts[worldLevel]);
        }
    }

    void SetDefault()
    {
        baseAmount = 15.0;
        sectorAmount = 6.0;
        difficultyAmount = 1 - *G_->difficulty;
        amounts.clear();
    }
};

struct CustomResourceReward
{
    int minimum = 0;
    int maximum = 0;

    int GetReward()
    {
        return minimum + random32()%(maximum-minimum+1);
    }

    void SetDefault(const std::string& type, int level)
    {
        if (type == "scrap")
        {
            switch(level)
            {
            case 0:
                minimum = 500;
                maximum = 700;
                break;
            case 1:
                minimum = 800;
                maximum = 1300;
                break;
            case 2:
                minimum = 1300;
                maximum = 1550;
                break;
            }
        }
        else if (type == "fuel")
        {
            switch(level)
            {
            case 0:
                minimum = 1;
                maximum = 2;
                break;
            case 1:
                minimum = 2;
                maximum = 4;
                break;
            case 2:
                minimum = 3;
                maximum = 6;
                break;
            }
        }
        else if (type == "missiles")
        {
            switch(level)
            {
            case 0:
                minimum = 1;
                maximum = 2;
                break;
            case 1:
                minimum = 2;
                maximum = 4;
                break;
            case 2:
                minimum = 4;
                maximum = 8;
                break;
            }
        }
        else if (type == "droneparts")
        {
            switch(level)
            {
            case 0:
                minimum = 1;
                maximum = 1;
                break;
            case 1:
                minimum = 1;
                maximum = 1;
                break;
            case 2:
                minimum = 1;
                maximum = 2;
                break;
            }
        }
    }
};

struct RewardScaling
{
    CustomScrapScaling scrap;
};

struct ResourceRewards
{
    // Defines scrap and resource ranges for each reward level

    std::unordered_map<int,CustomResourceReward> scrap;
    std::unordered_map<int,CustomResourceReward> fuel;
    std::unordered_map<int,CustomResourceReward> missiles;
    std::unordered_map<int,CustomResourceReward> drones;

    std::unordered_map<int,CustomScrapScaling> scrapScaling;
};

struct CustomReward
{
    int overrideLevel = -1;
};

struct CustomBonusReward
{
    // Determines whether to add an additional bonus reward

    int roll = 0;

    std::vector<std::pair<std::string,int>> bonusRewards;

    std::string GetBonusReward()
    {
        int rng = random32()%roll;
        for (auto bonusReward : bonusRewards)
        {
            rng -= bonusReward.second;
            if (rng < 0) return bonusReward.first;
        }
        return "";
    }
};

struct CustomRewardGenerator
{
    // Defines a reward generator, which rolls for scrap and resources and determines whether to add a bonus reward

    std::unordered_map<std::string,CustomReward> rewards;
    std::vector<std::string> resources;

    int minResources = 3;
    int maxResources = 3;

    CustomBonusReward bonus;

    std::string GetReward(ResourceEvent &resourceEvent, int level, int worldLevel, ResourceRewards& resourceRewards);
};

struct CustomRewardType
{
    // Defines the entirety of a reward type

    ResourceRewards rewards;
    std::unordered_map<int,RewardScaling> scaling;

    CustomRewardGenerator defaultRewardGenerator;

    std::unordered_map<int,CustomRewardGenerator> rewardGenerators;

    bool skipIfWeapon = false;
    bool skipIfDrone = false;
    bool skipIfAugment = false;

    bool weapon = false;
    bool drone = false;
    bool augment = false;

    std::string GetReward(ResourceEvent &resourceEvent, int level, int worldLevel);

    bool GetCustomScrapScaling(CustomScrapScaling& ret, const std::string& type, int level)
    {
        auto it = rewards.scrapScaling.find(level);
        if (it != rewards.scrapScaling.end())
        {
            ret = it->second;
            ret.difficultyAmount += (1 - *G_->difficulty);
            return true;
        }

        auto scaling_it = scaling.find(*G_->difficulty);
        if (scaling_it != scaling.end())
        {
            ret = scaling_it->second.scrap;
            return true;
        }

        scaling_it = scaling.find(1);
        if (scaling_it != scaling.end())
        {
            ret = scaling_it->second.scrap;
            ret.difficultyAmount += (1 - *G_->difficulty);
            return true;
        }

        return false;
    }

    bool GetCustomResourceReward(CustomResourceReward& ret, const std::string& type, int level)
    {
        if (type == "scrap")
        {
            auto it = rewards.scrap.find(level);
            if (it != rewards.scrap.end())
            {
                ret = it->second;
                return true;
            }
        }
        else if (type == "fuel")
        {
            auto it = rewards.fuel.find(level);
            if (it != rewards.fuel.end())
            {
                ret = it->second;
                return true;
            }
        }
        else if (type == "missiles")
        {
            auto it = rewards.missiles.find(level);
            if (it != rewards.missiles.end())
            {
                ret = it->second;
                return true;
            }
        }
        else if (type == "droneparts")
        {
            auto it = rewards.drones.find(level);
            if (it != rewards.drones.end())
            {
                ret = it->second;
                return true;
            }
        }
        return false;
    }
};

class CustomRewardsManager
{
public:
    CustomRewardsManager()
    {
        rewardLevels["LOW"] = 0;
        rewardLevels["MED"] = 1;
        rewardLevels["HIGH"] = 2;
        rewardLevels["RANDOM"] = 3;
        nextRewardLevel = 4;
    }

    int GetRewardLevel(std::string s)
    {
        boost::algorithm::to_upper(s);
        auto it = rewardLevels.find(s);
        if (it == rewardLevels.end())
        {
            rewardLevels[s] = nextRewardLevel;
            return nextRewardLevel++;
        }
        return it->second;
    }

    std::unordered_map<std::string,int> rewardLevels;
    int nextRewardLevel;

    ResourceRewards defaultRewards;
    std::unordered_map<int,RewardScaling> defaultScaling;

    std::unordered_map<std::string,CustomRewardType> rewards;

    CustomRewardType* GenerateReward_LocalType = nullptr;

    bool GetCustomScrapScaling(CustomScrapScaling& ret, const std::string& type, int level);
    bool GetCustomResourceReward(CustomResourceReward& ret, const std::string& type, int level);

    void ParseRewardsNode(rapidxml::xml_node<char> *node);
    void ParseResourceRewardsNode(rapidxml::xml_node<char> *node, ResourceRewards& rewards);
    int ParseRewardScalingNode(rapidxml::xml_node<char> *node, RewardScaling& rewards);
    bool ParseScrapScaling(rapidxml::xml_node<char> *node, CustomScrapScaling& scaling);
    bool ParseResourceNode(rapidxml::xml_node<char> *node, CustomResourceReward& reward);
    void ParseBonusRewardNode(rapidxml::xml_node<char> *node, CustomBonusReward& rewards);
    void ParseRewardGenerator(rapidxml::xml_node<char> *node, CustomRewardType& rewards);

    static CustomRewardsManager *GetInstance()
    {
        return instance;
    }

private:
    static CustomRewardsManager *instance;
};
