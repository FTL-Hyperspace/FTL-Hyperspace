#include "Global.h"

class CustomStore
{
public:
    void ParseStoreNode(rapidxml::xml_node<char> *node);
    std::vector<std::string> freeDrones = std::vector<std::string>();

    static CustomStore instance;
};
