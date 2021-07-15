#pragma once
#include "Global.h"

#include <boost/algorithm/string.hpp>

struct CustomScrapReward
{
    int minimum = 0;
    int maximum = 0;
    float baseAmount = 15.0;
    float sectorAmount = 6.0;

    int GetReward(int worldLevel)
    {
        float randomScrap = (float)(minimum + random32()%(maximum-minimum+1));
        return (int)(randomScrap / 1000.0 * (sectorAmount*worldLevel + baseAmount));
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
};

struct ResourceRewards
{
    // Defines scrap and resource ranges for each reward level

    std::unordered_map<int,CustomScrapReward> scrap;
    std::unordered_map<int,CustomResourceReward> fuel;
    std::unordered_map<int,CustomResourceReward> missiles;
    std::unordered_map<int,CustomResourceReward> drones;

    bool GetReward(ResourceEvent &resourceEvent, const std::string &type, int level, int worldLevel);
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

    CustomRewardGenerator defaultRewardGenerator;

    std::unordered_map<int,CustomRewardGenerator> rewardGenerators;

    bool skipIfWeapon = false;
    bool skipIfDrone = false;
    bool skipIfAugment = false;

    bool weapon = false;
    bool drone = false;
    bool augment = false;

    std::string GetReward(ResourceEvent &resourceEvent, int level, int worldLevel);
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

    std::unordered_map<std::string,CustomRewardType> rewards;

    void ParseRewardsNode(rapidxml::xml_node<char> *node);
    void ParseResourceRewardNode(rapidxml::xml_node<char> *node, ResourceRewards& rewards);
    void ParseBonusRewardNode(rapidxml::xml_node<char> *node, CustomBonusReward& rewards);
    void ParseRewardGenerator(rapidxml::xml_node<char> *node, CustomRewardType& rewards);

    static CustomRewardsManager *GetInstance()
    {
        return instance;
    }

private:
    static CustomRewardsManager *instance;
};
