#include "Global.h"

HOOK_STATIC(BlueprintManager, ProcessWeaponBlueprint, (WeaponBlueprint* bp, BlueprintManager *bpM, rapidxml::xml_node<char>* node) -> WeaponBlueprint*)
{
    super(bp, bpM, node);

    auto ex = BP_EX(bp)->weapon;

    for (auto child = node->first_node(); child = child->next_sibling(); child)
    {
        std::string name = child->name();
        std::string val = child->value();

        if (name == "rainbow")
        {

        }
    }

    return bp;
}

