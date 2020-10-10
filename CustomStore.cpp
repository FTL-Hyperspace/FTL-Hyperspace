#include "CustomStore.h"

CustomStore CustomStore::instance = CustomStore();

void CustomStore::ParseStoreNode(rapidxml::xml_node<char>* node)
{
    for (auto storeNode = node->first_node(); storeNode; storeNode = storeNode->next_sibling())
    {
        std::string nodeName = storeNode->name();

        if (nodeName == "freeDrones")
        {
            for (auto droneNode = storeNode->first_node(); droneNode; droneNode = droneNode->next_sibling())
            {
                freeDrones.push_back(droneNode->name());
            }
        }
    }
}

HOOK_METHOD(SystemStoreBox, constructor, (ShipManager *shopper, Equipment *equip, int sys) -> void)
{
    super(shopper, equip, sys);

    if (itemId != 4)
    {
        return;
    }

    if (CustomStore::instance.freeDrones.size() <= 0)
        return;

    int oldPrice = G_->GetBlueprints()->GetDroneBlueprint(freeBlueprint)->desc.cost / 2;

    DroneBlueprint *newBlueprint = G_->GetBlueprints()->GetDroneBlueprint(CustomStore::instance.freeDrones[random32() % CustomStore::instance.freeDrones.size()]);
    freeBlueprint = newBlueprint->name;

    desc.cost -= oldPrice;
    desc.cost += newBlueprint->desc.cost / 2;
}
