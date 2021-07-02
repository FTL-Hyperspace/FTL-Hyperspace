#include "CustomAugments.h"
#include "Global.h"
#include "freetype.h"
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>

CustomAugmentManager CustomAugmentManager::instance = CustomAugmentManager();

void CustomAugmentManager::ParseCustomAugmentNode(rapidxml::xml_node<char>* node)
{
    try
    {
        for (auto child = node->first_node(); child; child = child->next_sibling())
        {
            if (strcmp(child->name(), "aug") == 0)
            {
                const std::string& augName = child->first_attribute("name")->value();
                AugmentDefinition* augDef = new AugmentDefinition();

                augDef->name = augName;
                augDef->functions = std::map<std::string, AugmentFunction>();

                for (auto functionNode = child->first_node(); functionNode; functionNode = functionNode->next_sibling())
                {
                    std::string functionNodeName = functionNode->name();

                    if (functionNodeName == "function")
                    {
                        auto func = AugmentFunction();

                        const std::string& functionName = functionNode->first_attribute("name")->value();

                        if (functionName != augName)
                        {
                            func.value = G_->GetBlueprints()->GetAugmentValue(functionName);
                            bool preferHigher = true;

                            if (functionNode->first_attribute("value")) // Value of sub-augment
                            {
                                func.value = boost::lexical_cast<float>(functionNode->first_attribute("value")->value());
                            }
                            if (functionNode->first_attribute("preferHigher")) // Use higher or lower value for non-stackable augments?
                            {
                                func.preferHigher = EventsParser::ParseBoolean(functionNode->first_attribute("preferHigher")->value());
                            }
                            if (functionNode->first_attribute("useForReqs")) // Used for blue options?
                            {
                                func.useForReqs = EventsParser::ParseBoolean(functionNode->first_attribute("useForReqs")->value());
                            }
                            if (functionNode->first_attribute("warning")) // Display warning about which augments will have no effect with it?
                            {
                                func.warning = EventsParser::ParseBoolean(functionNode->first_attribute("warning")->value());
                            }
                            if (functionNode->first_attribute("sys")) // System must be installed, functional, and powered
                            {
                                func.sys = ShipSystem::NameToSystemId(functionNode->first_attribute("sys")->value());
                            }

                            augDef->functions[functionName] = func;
                        }
                    }
                    if (functionNodeName == "locked")
                    {
                        augDef->locked = true;
                    }

                    if (functionNodeName == "statBoosts")
                    {
                        for (auto statBoostNode = functionNode->first_node(); statBoostNode; statBoostNode = statBoostNode->next_sibling())
                        {
                            if (strcmp(statBoostNode->name(), "statBoost") == 0)
                            {
                                augDef->statBoosts.push_back(ParseStatBoostNode(statBoostNode));
                            }
                        }
                    }
                }

                augDefs[augName] = augDef;
            }
        }
    }
    catch (...)
    {
        MessageBoxA(NULL, "Error parsing <augments> in hyperspace.xml", "Error", MB_ICONERROR);
    }
}

std::map<std::string, AugmentFunction> CustomAugmentManager::GetPotentialAugments(const std::string& name, int shipId, bool req)
{
    auto ret = std::map<std::string, AugmentFunction>();


    for (auto const& i: augDefs)
    {
        if (i.second)
        {
            if (!i.second->functions.empty())
            {
                auto val = i.second->functions.find(name);

                if (val != i.second->functions.end())
                {
                    if (!req)
                    {
                        if (val->second.sys == -1)
                        {
                            ret[i.second->name] = val->second;
                        }
                        else
                        {
                            ShipManager* shipManager = G_->GetShipManager(shipId);
                            if (shipManager != nullptr && shipManager->GetSystemRoom(val->second.sys) != -1)
                            {
                                ShipSystem* sys = shipManager->GetSystem(val->second.sys);
                                if (sys != nullptr && sys->iHackEffect < 2 && sys->GetEffectivePower() > 0)
                                {
                                    ret[i.second->name] = val->second;
                                }
                            }
                        }
                    }
                    else if (i.second->functions[name].useForReqs)
                    {
                        ret[i.second->name] = val->second;
                    }
                }
            }
        }
    }

    return ret;
}

std::map<std::string, int> CustomAugmentManager::CheckHiddenAugments(const std::map<std::string, int>& augList)
{
    std::map<std::string, int> newList = std::map<std::string, int>();

    for (auto i : augList)
    {
        if (boost::algorithm::starts_with(i.first, "HIDDEN "))
        {
            newList[i.first.substr(7)] = i.second;
        }
        else
        {
            newList[i.first] = i.second;
        }
    }

    return newList;
}

std::vector<std::string> CustomAugmentManager::RemoveHiddenAugments(const std::vector<std::string>& augList)
{
    auto newList = std::vector<std::string>();

    for (auto i : augList)
    {
        if (!boost::algorithm::starts_with(i, "HIDDEN "))
        {
            newList.push_back(i);
        }
    }

    return newList;
}


//======================

HOOK_METHOD_PRIORITY(ShipObject, HasAugmentation, 2000, (const std::string& name) -> int)
{
    CustomAugmentManager* customAug = CustomAugmentManager::GetInstance();

    std::map<std::string, int> augList = CustomAugmentManager::CheckHiddenAugments(G_->GetShipInfo(iShipId)->augList);

    int augCount = 0;

    if (augList.count(name) > 0)
    {
        augCount = augList.at(name);
    }

    std::map<std::string, AugmentFunction> potentialAugs = customAug->GetPotentialAugments(name, iShipId);



    for (auto const& x: potentialAugs)
    {
        if (augList.count(x.first))
        {
            augCount += augList.at(x.first);
        }
    }


    return augCount;
}

static bool useAugmentReq = false;

HOOK_METHOD(WorldManager, CreateChoiceBox, (LocationEvent *event) -> void)
{
    useAugmentReq = true;

    super(event);

    useAugmentReq = false;
}


// Replaced ShipObject::HasEquipment function for Hyperspace augments

HOOK_METHOD_PRIORITY(ShipObject, HasEquipment, 2000, (const std::string& name) -> int)
{
    auto ship = G_->GetShipManager(iShipId);
    std::map<std::string, int> augList = CustomAugmentManager::CheckHiddenAugments(G_->GetShipInfo(iShipId)->augList);

    int augCount = 0;
    if (augList.count(name) > 0)
    {
        augCount = augList.at(name);
    }

    CustomAugmentManager* customAug = CustomAugmentManager::GetInstance();
    std::map<std::string, AugmentFunction> potentialAugs = customAug->GetPotentialAugments(name, iShipId, useAugmentReq);



    for (auto const& x: potentialAugs)
    {
        if (augList.count(x.first))
        {
            augCount += augList.at(x.first);
        }
    }

    if (augCount > 0)
        return augCount;

    return super(name);


}



// Replaced ShipObject::GetAugmentationValue function for custom Hyperspace augments

HOOK_METHOD_PRIORITY(ShipObject, GetAugmentationValue, 1000, (const std::string& name) -> float)
{
    AugmentBlueprint* augBlueprint = G_->GetBlueprints()->GetAugmentBlueprint(name);

    auto ship = G_->GetShipManager(iShipId);
    std::map<std::string, int> augList = CustomAugmentManager::CheckHiddenAugments(G_->GetShipInfo(iShipId)->augList);
    int augCount = 0;

    if (augList.count(name) > 0)
    {
        augCount = augList.at(name);
    }


    float augValue = augBlueprint->value * augCount;

    CustomAugmentManager* customAug = CustomAugmentManager::GetInstance();
    std::map<std::string, AugmentFunction> potentialAugs = customAug->GetPotentialAugments(name, iShipId);


    float highestValue = augValue;
    for (auto const& x: potentialAugs)
    {
        if (augList.count(x.first))
        {
            augCount += augList.at(x.first);
            augValue += x.second.value * augList.at(x.first);

            if ((x.second.preferHigher && x.second.value > highestValue) || (!x.second.preferHigher && x.second.value < highestValue))
            {
                highestValue = x.second.value;
            }
        }
    }

    if (augCount <= 0)
    {
        return 0.f;
    }

    auto ret = augBlueprint->stacking ? augValue : highestValue;

    return ret;
}

// Locked augments

static GL_Texture* augLockTexture = nullptr;

HOOK_METHOD(Equipment, MouseClick, (int mX, int mY) -> void)
{
    super(mX, mY);
    CustomAugmentManager* customAug = CustomAugmentManager::GetInstance();

    if (draggingEquipBox != -1)
    {
        auto box = vEquipmentBoxes[draggingEquipBox];
        if (box->CanHoldAugment() && box->slot != 4)
        {
            if (box->item.augment && customAug->IsAugment(box->item.augment->name))
            {
                if (customAug->GetAugmentDefinition(box->item.augment->name)->locked)
                {
                    draggingEquipBox = -1;
                    bDragging = false;
                }
            }
        }
    }
}

HOOK_METHOD(EquipmentBox, OnRender, (bool isEmpty) -> void)
{
    super(isEmpty);

    if (CanHoldAugment())
    {
        CustomAugmentManager* customAug = CustomAugmentManager::GetInstance();

        if (!augLockTexture)
        {
            augLockTexture = G_->GetResources()->GetImageId("upgradeUI/Equipment/aug_lock.png");
        }

        if (item.augment && customAug->IsAugment(item.augment->name) && customAug->GetAugmentDefinition(item.augment->name)->locked && augLockTexture)
        {
            float xPos = slot == 4 ? location.x - 36.f : location.x - 24.f;

            G_->GetResources()->RenderImage(augLockTexture, xPos, location.y + 7.f, 0.f, COLOR_WHITE, 1.f, false);
        }
    }
}

HOOK_METHOD(Equipment, OnLoop, () -> void)
{
    super();
    CustomAugmentManager* customAug = CustomAugmentManager::GetInstance();

    EquipmentBox *firstSlot;
    EquipmentBox *fullSlot;
    bool swapSlots = false;

    for (auto i : vEquipmentBoxes)
    {
        if (i->CanHoldAugment())
        {
            if (i->item.augment && i->slot == 0)
            {
                firstSlot = i;
            }

            if (i->item.augment && customAug->IsAugment(i->item.augment->name) && customAug->GetAugmentDefinition(i->item.augment->name)->locked)
            {
                i->bBlocked = true;

                if (i->slot == 4)
                {
                    fullSlot = i;
                    swapSlots = true;
                }
            }
        }
    }

    if (swapSlots)
    {
        EquipmentBoxItem item1 = fullSlot->item;
        EquipmentBoxItem item2 = firstSlot->item;
        fullSlot->RemoveItem();
        firstSlot->RemoveItem();
        fullSlot->AddItem(item2);
        firstSlot->AddItem(item1);
    }
}



// Hidden augments

static bool exportingShip = false;

HOOK_METHOD(ShipManager, ExportShip, (int fileHelper) -> void)
{
    super(fileHelper);

    std::vector<std::string> hiddenList = std::vector<std::string>();

    auto augList = G_->GetShipInfo(iShipId)->augList;

    for (auto i : augList)
    {
        if (boost::algorithm::starts_with(i.first, "HIDDEN "))
        {
            for (int j = 0; j < i.second; j++)
            {
                hiddenList.push_back(i.first);
            }
        }
    }

    FileHelper::writeInt(fileHelper, hiddenList.size());

    for (auto i : hiddenList)
    {
        FileHelper::writeString(fileHelper, i);
    }
}

HOOK_METHOD(ShipManager, ImportShip, (int fileHelper) -> void)
{
    super(fileHelper);

    int hiddenCount = FileHelper::readInteger(fileHelper);
    auto augList = G_->GetShipInfo(iShipId)->augList;

    for (int i = 0; i < hiddenCount; i++)
    {
        auto aug = FileHelper::readString(fileHelper);

        if (augList.find(aug) != augList.end())
        {
            augList[aug]++;
        }
        else
        {
            augList[aug] = 1;
        }
    }

    G_->GetShipInfo(iShipId)->augList = augList;
}

HOOK_STATIC(ShipObject, GetAugmentationList, (std::vector<std::string>& vec, ShipObject *shipObj) -> std::vector<std::string>&)
{
    super(vec, shipObj);

    vec = CustomAugmentManager::RemoveHiddenAugments(vec);

    return vec;
}

HOOK_METHOD(ShipObject, GetAugmentationCount, () -> int)
{
    int count = 0;

    for (auto i : G_->GetShipInfo(iShipId)->augList)
    {
        if (!boost::algorithm::starts_with(i.first, "HIDDEN "))
        {
            count += i.second;
        }
    }

    return count;
}
HOOK_METHOD(ShipObject, RemoveAugmentation, (const std::string& name) -> void)
{
    super(name);

    int augCount = 0;

    for (auto i : G_->GetShipInfo(iShipId)->augList)
    {

        if (!boost::algorithm::starts_with(i.first, "HIDDEN "))
        {
            augCount += i.second;
        }
    }

    G_->GetShipInfo(iShipId)->augCount = augCount;

    /*
    ShipManager* ship = G_->GetShipManager(this);
    if (ship != nullptr)
    {
        auto sm = SM_EX(ship);
    }
    */
}
