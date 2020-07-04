#include <string>
#include <vector>
#include <map>
#include "rapidxml.hpp"

struct AugmentDefinition
{
    std::string name;
    std::map<std::string, std::pair<float, bool>> functions = std::map<std::string, std::pair<float, bool>>();
    bool locked = false;
};


class CustomAugmentManager
{
public:
    CustomAugmentManager()
    {

    }

    void ParseCustomAugmentNode(rapidxml::xml_node<char>* node);

    std::map<std::string, std::pair<float, bool>> GetPotentialAugments(const std::string& name);

    AugmentDefinition* GetAugmentDefinition(const std::string& name)
    {
        return augDefs[name];
    }

    bool IsAugment(const std::string& name)
    {
        return augDefs.find(name) != augDefs.end();
    }

    static std::map<std::string, int> CheckHiddenAugments(const std::map<std::string, int>& augList);
    static std::vector<std::string> RemoveHiddenAugments(const std::vector<std::string>& augList);

    static CustomAugmentManager* GetInstance()
    {
        return &instance;
    }

private:
    std::map<std::string, AugmentDefinition*> augDefs;
    static CustomAugmentManager instance;

};

