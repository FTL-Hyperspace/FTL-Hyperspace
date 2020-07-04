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
                augDef->functions = std::map<std::string, std::pair<float, bool>>();

                for (auto functionNode = child->first_node(); functionNode; functionNode = functionNode->next_sibling())
                {
                    if (strcmp(functionNode->name(), "function") == 0)
                    {
                        const std::string& functionName = functionNode->first_attribute("name")->value();

                        if (functionName != augName)
                        {
                            float functionValue = G_->GetBlueprints()->GetAugmentValue(functionName);
                            bool preferHigher = true;

                            if (functionNode->first_attribute("value"))
                            {
                                functionValue = boost::lexical_cast<float>(functionNode->first_attribute("value")->value());
                            }
                            if (functionNode->first_attribute("preferHigher"))
                            {
                                preferHigher = EventsParser::ParseBoolean(functionNode->first_attribute("preferHigher")->value());
                            }


                            augDef->functions[functionName] = std::pair<float, bool>(functionValue, preferHigher);
                        }
                    }
                    if (strcmp(functionNode->name(), "locked") == 0)
                    {
                        augDef->locked = true;
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

std::map<std::string, std::pair<float, bool>> CustomAugmentManager::GetPotentialAugments(const std::string& name)
{
    auto ret = std::map<std::string, std::pair<float, bool>>();


    for (auto const& i: augDefs)
    {
        if (i.second)
        {
            if (!i.second->functions.empty())
            {
                auto val = i.second->functions.find(name);
                if (val != i.second->functions.end())
                {
                    ret[i.second->name] = val->second;
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

    AugmentBlueprint* augBlueprint = G_->GetBlueprints()->GetAugmentBlueprint(name);

    int augCount = 0;

    if (augList.count(name) > 0)
    {
        augCount = augList.at(name);
    }

    std::map<std::string, std::pair<float, bool>> potentialAugs = customAug->GetPotentialAugments(name);



    for (auto const& x: potentialAugs)
    {
        if (augList.count(x.first))
        {
            augCount += augList.at(x.first);
        }
    }


    return augCount;
}

HOOK_METHOD_PRIORITY(ShipObject, HasEquipment, 2000, (const std::string& name) -> int)
{
    ItemBlueprint* bp = G_->GetBlueprints()->GetItemBlueprint(name);


    auto ship = G_->GetShipManager(iShipId);
    std::map<std::string, int> augList = CustomAugmentManager::CheckHiddenAugments(G_->GetShipInfo(iShipId)->augList);

    int augCount = 0;
    if (augList.count(name) > 0)
    {
        augCount = augList.at(name);
    }

    CustomAugmentManager* customAug = CustomAugmentManager::GetInstance();
    std::map<std::string, std::pair<float, bool>> potentialAugs = customAug->GetPotentialAugments(name);



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
    std::map<std::string, std::pair<float, bool>> potentialAugs = customAug->GetPotentialAugments(name);


    float highestValue = augValue;
    for (auto const& x: potentialAugs)
    {
        if (augList.count(x.first))
        {
            augCount += augList.at(x.first);
            augValue += x.second.first * augList.at(x.first);

            if ((x.second.second && x.second.first > highestValue) || (!x.second.second && x.second.first < highestValue))
            {
                highestValue = x.second.first;
            }
        }
    }

    if (augCount <= 0)
    {
        return 0.f;
    }

    return augBlueprint->stacking ? augValue : highestValue;
}


HOOK_METHOD(InfoBox, SetBlueprintAugment, (const AugmentBlueprint* bp) -> void)
{
    desc.title.data.assign(bp->desc.title.data);
    desc.title.isLiteral = bp->desc.title.isLiteral;

    desc.shortTitle.data.assign(bp->desc.shortTitle.data);
    desc.shortTitle.isLiteral = bp->desc.shortTitle.isLiteral;


    desc.description.data.assign(bp->desc.description.data);
    desc.description.isLiteral = bp->desc.description.isLiteral;

    desc.cost = bp->desc.cost;
    desc.rarity = bp->desc.rarity;
    desc.baseRarity = bp->desc.baseRarity;
    desc.bp = bp->desc.bp;
    desc.locked = bp->desc.locked;

    descBoxSize.x = 305;
    descBoxSize.y = 266;
    primaryBoxOffset = 67;

    CustomAugmentManager* customAug = CustomAugmentManager::GetInstance();

    if (customAug->IsAugment(bp->name))
    {
        std::string warn = G_->GetTextLibrary()->GetText("augment_no_effect");
        warn.append("\n");

        BlueprintManager* blueprints = G_->GetBlueprints();
        int counter = 0;
        for (auto const &x: customAug->GetAugmentDefinition(bp->name)->functions)
        {
            auto bp = blueprints->GetAugmentBlueprint(x.first);

            if (((x.second.second && bp->value <= x.second.first) || (!x.second.second && bp->value >= x.second.first)) && !bp->stacking)
            {
                warn += bp->desc.title.GetText() + "\n";
                counter++;
            }
        }

        if (counter > 0)
            warning.assign(warn);
    }

    Pointf s = freetype_hack::easy_measurePrintLines(10, 0, 0, descBoxSize.x, warning + "\n" + desc.description.GetText());
    descBoxSize.y = s.y;

    primaryBox = new WindowFrame(7, 7, 323, s.y + 58);

    bDetailed = false;
}

static GL_Texture* augLockTexture = NULL;

HOOK_METHOD(Equipment, OnInit, (ShipManager* ship) -> void)
{
    super(ship);

    augLockTexture = G_->GetResources()->GetImageId("upgradeUI/Equipment/aug_lock.png");
}

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

    for (auto i : vEquipmentBoxes)
    {
        if (i->CanHoldAugment())
        {
            if (i->item.augment && customAug->IsAugment(i->item.augment->name) && customAug->GetAugmentDefinition(i->item.augment->name)->locked)
            {
                i->bBlocked = true;
            }
        }
    }
}


HOOK_STATIC(ShipObject, GetAugmentationList, (std::vector<std::string>& vec, ShipObject *shipObj) -> std::vector<std::string>&)
{
    super(vec, shipObj);

    vec = CustomAugmentManager::RemoveHiddenAugments(vec);

    return vec;
}
