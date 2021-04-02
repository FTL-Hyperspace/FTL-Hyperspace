#pragma once
#include "Global.h"
#include "Store_Extend.h"

class CustomStore
{
public:
    void ParseStoreNode(rapidxml::xml_node<char> *node);
    std::vector<std::string> freeDrones = std::vector<std::string>();

    static CustomStore* instance;
private:
    std::unordered_map<std::string, StoreDefinition> storeDefs;
};
