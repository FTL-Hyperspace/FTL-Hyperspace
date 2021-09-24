#include "CustomAugments.h"
#include "CustomOptions.h"
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
                augDef->functions = std::unordered_map<std::string, AugmentFunction>();

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
                            if (functionNode->first_attribute("modifyChoiceTextScrap")) // For scrap recovery arm, modifies the scrap values in choice dialogs (does not modify scrap collected in score/stats)
                            {
                                func.modifyChoiceTextScrap = EventsParser::ParseBoolean(functionNode->first_attribute("modifyChoiceTextScrap")->value());
                            }

                            augDef->functions[functionName] = func;
                            augDefsByFunction[functionName][augName] = &(augDef->functions[functionName]);
                            if (func.useForReqs)
                            {
                                augDefsByReq[functionName][augName] = &(augDef->functions[functionName]);
                            }
                        }
                    }
                    if (functionNodeName == "superShield")
                    {
                        augDef->superShield.present = true;
                        for (auto child = functionNode->first_node(); child; child = child->next_sibling())
                        {
                            if (strcmp(child->name(), "value") == 0)
                            {
                                augDef->superShield.value = boost::lexical_cast<int>(child->value());
                            }
                            if (strcmp(child->name(), "add") == 0)
                            {
                                augDef->superShield.add = boost::lexical_cast<int>(child->value());
                            }
                            if (strcmp(child->name(), "color") == 0)
                            {
                                augDef->superShield.customRender = true;
                                if (child->first_attribute("r"))
                                {
                                    augDef->superShield.shieldColor.r = boost::lexical_cast<float>(child->first_attribute("r")->value()) / 255.f;
                                }
                                if (child->first_attribute("g"))
                                {
                                    augDef->superShield.shieldColor.g = boost::lexical_cast<float>(child->first_attribute("g")->value()) / 255.f;
                                }
                                if (child->first_attribute("b"))
                                {
                                    augDef->superShield.shieldColor.b = boost::lexical_cast<float>(child->first_attribute("b")->value()) / 255.f;
                                }
                                if (child->first_attribute("a"))
                                {
                                    augDef->superShield.shieldColor.a = boost::lexical_cast<float>(child->first_attribute("a")->value());
                                }
                            }
                            if (strcmp(child->name(), "shieldImage") == 0)
                            {
                                augDef->superShield.customRender = true;
                                augDef->superShield.shieldTexture[0] = child->value();
                                augDef->superShield.shieldTexture[1] = child->value();
                            }
                            if (strcmp(child->name(), "playerImage") == 0)
                            {
                                augDef->superShield.customRender = true;
                                augDef->superShield.shieldTexture[0] = child->value();
                            }
                            if (strcmp(child->name(), "enemyImage") == 0)
                            {
                                augDef->superShield.customRender = true;
                                augDef->superShield.shieldTexture[1] = child->value();
                            }
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
                                augDef->statBoosts.push_back(StatBoostManager::GetInstance()->ParseStatBoostNode(statBoostNode, StatBoostDefinition::BoostSource::AUGMENT));
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

bool AugmentFunction::Functional(int iShipId)
{
    if (sys != -1)
    {
        ShipManager* shipManager = G_->GetShipManager(iShipId);
        if (shipManager != nullptr && shipManager->GetSystemRoom(sys) != -1)
        {
            ShipSystem* shipSystem = shipManager->GetSystem(sys);
            if (shipSystem != nullptr && shipSystem->iHackEffect < 2 && shipSystem->GetEffectivePower() > 0)
            {
                return true;
            }
        }
        return false;
    }
    return true;
}

std::unordered_map<std::string, AugmentFunction*>* CustomAugmentManager::GetPotentialAugments(const std::string& name, bool req)
{
    return req ? &augDefsByReq[name] : &augDefsByFunction[name];
}

std::unordered_map<std::string, int>* CustomAugmentManager::GetShipAugments(int iShipId)
{
    return &(augListWithHidden[iShipId]);
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

void CustomAugmentManager::UpdateAugments(int iShipId)
{
    std::unordered_map<std::string, int>& hiddenList = augListWithHidden[iShipId];
    std::vector<std::string>& notHiddenList = augListNoHidden[iShipId];

    hiddenList.clear();
    notHiddenList.clear();

    for (auto i : G_->GetShipInfo(iShipId)->augList)
    {
        if (boost::algorithm::starts_with(i.first, "HIDDEN "))
        {
            hiddenList[i.first.substr(7)] = i.second;
        }
        else
        {
            hiddenList[i.first] = i.second;
            notHiddenList.push_back(i.first);
        }
    }
}


//======================

HOOK_METHOD_PRIORITY(ShipObject, HasAugmentation, 2000, (const std::string& name) -> int)
{
    CustomAugmentManager* customAug = CustomAugmentManager::GetInstance();

    std::unordered_map<std::string, int> *augList = customAug->GetShipAugments(iShipId);

    int augCount = 0;

    if (augList->count(name) > 0)
    {
        augCount = augList->at(name);
    }

    std::unordered_map<std::string, AugmentFunction*> *potentialAugs = customAug->GetPotentialAugments(name);



    for (auto const& x: *potentialAugs)
    {
        if (augList->count(x.first) && x.second->Functional(iShipId))
        {
            augCount += augList->at(x.first);
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
    CustomAugmentManager* customAug = CustomAugmentManager::GetInstance();

    auto ship = G_->GetShipManager(iShipId);
    std::unordered_map<std::string, int> *augList = customAug->GetShipAugments(iShipId);

    int augCount = 0;
    if (augList->count(name) > 0)
    {
        augCount = augList->at(name);
    }

    std::unordered_map<std::string, AugmentFunction*> *potentialAugs = customAug->GetPotentialAugments(name, useAugmentReq);



    for (auto const& x: *potentialAugs)
    {
        if (augList->count(x.first) && x.second->Functional(iShipId))
        {
            augCount += augList->at(x.first);
        }
    }

    return augCount + super(name);


}



// Replaced ShipObject::GetAugmentationValue function for custom Hyperspace augments

HOOK_METHOD_PRIORITY(ShipObject, GetAugmentationValue, 1000, (const std::string& name) -> float)
{
    CustomAugmentManager* customAug = CustomAugmentManager::GetInstance();

    AugmentBlueprint* augBlueprint = G_->GetBlueprints()->GetAugmentBlueprint(name);

    auto ship = G_->GetShipManager(iShipId);
    std::unordered_map<std::string, int> *augList = customAug->GetShipAugments(iShipId);
    int augCount = 0;

    if (augList->count(name) > 0)
    {
        augCount = augList->at(name);
    }


    float augValue = augBlueprint->value * augCount;

    std::unordered_map<std::string, AugmentFunction*> *potentialAugs = customAug->GetPotentialAugments(name);


    float highestValue = augValue;
    for (auto const& x: *potentialAugs)
    {
        if (augList->count(x.first) && x.second->Functional(iShipId))
        {
            augCount += augList->at(x.first);
            augValue += x.second->value * augList->at(x.first);

            if ((x.second->preferHigher && x.second->value > highestValue) || (!x.second->preferHigher && x.second->value < highestValue))
            {
                highestValue = x.second->value;
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
    CustomAugmentManager::GetInstance()->UpdateAugments(iShipId);
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
HOOK_METHOD(ShipObject, AddAugmentation, (const std::string& name) -> bool)
{
    auto ret = super(name);
    CustomAugmentManager::GetInstance()->UpdateAugments(iShipId);
    return ret;
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

    CustomAugmentManager::GetInstance()->UpdateAugments(iShipId);

    /*
    ShipManager* ship = G_->GetShipManager(this);
    if (ship != nullptr)
    {
        auto sm = SM_EX(ship);
    }
    */
}
HOOK_METHOD(ShipObject, ClearShipInfo, () -> void)
{
    super();
    CustomAugmentManager::GetInstance()->UpdateAugments(iShipId);
}

// Super Shields

int CustomAugmentManager::GetSuperShieldValue(int shipId)
{
    CustomAugmentManager* customAug = CustomAugmentManager::GetInstance();
    std::unordered_map<std::string, int> *augList = customAug->GetShipAugments(shipId);

    int superShieldValue = 0;
    int superShieldAdd = 0;
    int superShieldRenderValue = -1;
    bool customRender = false;
    bool hasEnergyShield = false;
    bool hasCustomShield = false;
    std::string shieldTexture = "";
    GL_Color shieldColor = GL_Color(0.0, 0.0, 0.0, 0.0);

    for (auto& aug : *augList)
    {
        if (aug.second > 0)
        {
            if (customAug->IsAugment(aug.first))
            {
                auto augDef = customAug->GetAugmentDefinition(aug.first);
                auto& superShield = augDef->superShield;

                if (superShield.present)
                {
                    hasCustomShield = true;
                    if (superShield.value > superShieldValue)
                    {
                        superShieldValue = superShield.value;
                    }
                    if (superShield.add > 0)
                    {
                        superShieldAdd += superShield.add * aug.second;
                    }
                    if (superShield.customRender && superShield.value > superShieldRenderValue)
                    {
                        superShieldRenderValue = superShield.value;
                        customRender = true;
                        shieldTexture = superShield.shieldTexture[shipId];
                        shieldColor = superShield.shieldColor;
                    }
                }
                else
                {
                    auto it = augDef->functions.find("ENERGY_SHIELD");
                    if (it != augDef->functions.end() && it->second.Functional(shipId))
                    {
                        hasEnergyShield = true;
                    }
                }
            }
            else if (aug.first == "ENERGY_SHIELD")
            {
                hasEnergyShield = true;
            }
        }
    }

    customAug->superShieldCustomRender[shipId] = customRender;
    customAug->superShieldTexture[shipId] = shieldTexture;
    customAug->superShieldColor[shipId] = shieldColor;

    if (!hasCustomShield) return 0;
    if (hasEnergyShield && superShieldValue < 5) superShieldValue = 5;

    return superShieldValue + superShieldAdd;
}

HOOK_METHOD(Shields, AddSuperShield, (Point pos) -> void)
{
    auto currentSuper = shields.power.super;

    super(pos);

    int customSuper = CustomAugmentManager::GetSuperShieldValue(_shipObj.iShipId);
    if (customSuper > 5)
    {
        shields.power.super.second = customSuper;
        shields.power.super.first = std::min(currentSuper.first+1,customSuper);
    }
}

HOOK_METHOD(Shields, InstantCharge, () -> void)
{
    super();

    int customSuper = CustomAugmentManager::GetSuperShieldValue(_shipObj.iShipId);
    if (customSuper > 0)
    {
        shields.power.super.second = customSuper;
        shields.power.super.first = customSuper;
    }
}

HOOK_METHOD(Shields, Jump, () -> void)
{
    super();

    int customSuper = CustomAugmentManager::GetSuperShieldValue(_shipObj.iShipId);
    if (customSuper > 0)
    {
        shields.power.super.second = customSuper;
        shields.power.super.first = customSuper;
    }
}

HOOK_METHOD(Shields, OnLoop, () -> void)
{
    bool noSuper = shields.power.super.second < 1;

    super();

    int customSuper = CustomAugmentManager::GetSuperShieldValue(_shipObj.iShipId);
    if (customSuper > 0)
    {
        shields.power.super.second = std::max(customSuper, std::min(shields.power.super.second, 5));

        if (noSuper) shields.power.super.first = customSuper;
    }
}

/*
HOOK_METHOD(Shields, CollisionReal, (float x, float y, Damage damage, bool unk) -> void)
{
    super(x, y, damage, unk);

    if (CustomAugmentManager::GetInstance()->superShieldCustomRender[_shipObj.iShipId] && !damMessages.empty())
    {
        DamageMessage* damMessage = damMessages.back();
        if (damMessage->color.r == 0.1568628f && damMessage->color.g == 0.9411765f && damMessage->color.b == 0.1568628f) // r=40 g=240 b=40
        {
            damMessage->color = CustomAugmentManager::GetInstance()->superShieldColor[_shipObj.iShipId];
            damMessage->color.a = 1.0;
        }
    }
}
*/

int numSuperShieldBars = 0;
std::vector<GL_Primitive*> superShieldBars = std::vector<GL_Primitive*>();

HOOK_METHOD(ShipStatus, RenderShields, (bool renderText) -> void)
{
    if (!ship) return super(renderText);

    auto superShield = ship->GetShieldPower().super;

    if (superShield.first > 0)
    {
        if (superShield.second != 5 || CustomAugmentManager::GetInstance()->superShieldCustomRender[0])
        {
            float charger = ship->shieldSystem->shields.charger;

            ship->shieldSystem->shields.power.super.first = 0;
            ship->shieldSystem->shields.charger = 0.0;

            super(renderText);

            ship->shieldSystem->shields.power.super.first = superShield.first;
            ship->shieldSystem->shields.charger = charger;

            if (superShield.second != numSuperShieldBars)
            {
                numSuperShieldBars = superShield.second;

                for (auto bar : superShieldBars)
                {
                    CSurface::GL_DestroyPrimitive(bar);
                }

                superShieldBars.clear();
                superShieldBars.reserve(superShield.second);

                float x = 33.5;
                int y = 79;
                float width = 92;
                int height = 6;

                float gap = superShield.second > 10 ? 1 : 2;
                float bar_space = (width+gap) / superShield.second;
                float bar_width = bar_space - gap;

                for (int i=0; i<superShield.second; ++i)
                {
                    int x1 = x;
                    int x2 = x + bar_width;
                    GL_Primitive* prim = CSurface::GL_CreateRectPrimitive(x1,y,x2-x1,height,GL_Color(1.0,1.0,1.0,1.0));
                    superShieldBars.push_back(prim);
                    x = x + bar_space;
                }
            }

            GL_Color color = CustomAugmentManager::GetInstance()->superShieldCustomRender[0] ? CustomAugmentManager::GetInstance()->superShieldColor[0] : GL_Color(0.392156862f, 1.f, 0.392156862f, 1.f);
            color.a = 1.0;

            for (int i=0; i<superShield.first; ++i)
            {
                if (i == superShieldBars.size()) break;

                CSurface::GL_RenderPrimitiveWithColor(superShieldBars[i],color);
            }

            return;
        }

        if (superShield.first > 5 && ship->shieldSystem != nullptr)
        {
            ship->shieldSystem->shields.power.super.first = 5;
            super(renderText);
            ship->shieldSystem->shields.power.super.first = superShield.first;
            return;
        }
    }

    super(renderText);
}

CachedImage extend_shieldCircleCharged[5];
CachedImage extend_shieldCircleUncharged[5];
CachedImage extend_shieldCircleHacked[5];
CachedImage extend_shieldCircleHackedCharged[5];

HOOK_METHOD(CombatControl, constructor, () -> void)
{
    super();

    for (int i=0; i<5; ++i)
    {
        extend_shieldCircleCharged[i] = this->shieldCircleCharged[0];
        extend_shieldCircleCharged[i].x += 23*(5+i);

        extend_shieldCircleUncharged[i] = this->shieldCircleUncharged[0];
        extend_shieldCircleUncharged[i].x += 23*(5+i);

        extend_shieldCircleHacked[i] = this->shieldCircleHacked[0];
        extend_shieldCircleHacked[i].x += 23*(5+i);

        extend_shieldCircleHackedCharged[i] = this->shieldCircleHackedCharged[0];
        extend_shieldCircleHackedCharged[i].x += 23*(5+i);
    }
}

HOOK_METHOD(CombatControl, RenderShipStatus, (Pointf pos, GL_Color color) -> void)
{
    auto enemyShield = currentTarget->shipManager->GetShieldPower();

    if (enemyShield.second > 5 && currentTarget->shipManager->shieldSystem != nullptr)
    {
        if (currentTarget->shipManager->shieldSystem->shields.power.first > 5)
        {
            currentTarget->shipManager->shieldSystem->shields.power.first = 5;
        }
        if (currentTarget->shipManager->shieldSystem->shields.power.second > 5)
        {
            currentTarget->shipManager->shieldSystem->shields.power.second = 5;
        }
        currentTarget->shipManager->shieldSystem->shields.power.super.first = 0;

        super(pos, color);

        currentTarget->shipManager->shieldSystem->shields.power = enemyShield;

        CSurface::GL_PushMatrix();
        CSurface::GL_Translate(pos.x, pos.y, 0.0);

        bool isHacked = currentTarget->shipManager->IsSystemHacked(0) > 1;

        for (int i=5; i<enemyShield.second; ++i)
        {
            if (i >= 10) break;
            if (enemyShield.first > i)
            {
                if (isHacked)
                {
                    extend_shieldCircleHackedCharged[i-5].OnRender(GL_Color(1.0, 1.0, 1.0, 1.0));
                }
                else
                {
                    extend_shieldCircleCharged[i-5].OnRender(GL_Color(1.0, 1.0, 1.0, 1.0));
                }
            }
            else
            {
                if (isHacked)
                {
                    extend_shieldCircleHacked[i-5].OnRender(GL_Color(1.0, 1.0, 1.0, 1.0));
                }
                else
                {
                    extend_shieldCircleUncharged[i-5].OnRender(GL_Color(1.0, 1.0, 1.0, 1.0));
                }
            }
        }

        if (enemyShield.super.first > 0)
        {
            GL_Color superColor = GL_Color(100.0/255.0, 255.0/255.0, 100.0/255.0, 1.0);

            if (CustomAugmentManager::GetInstance()->superShieldCustomRender[1])
            {
                    superColor = CustomAugmentManager::GetInstance()->superShieldColor[1];
                    superColor.a = 1.0;
            }

            int superBar_x = enemyShield.second * 23;

            if (enemyShield.super.second == 5)
            {
                superShieldBox5.SetPosition(superBar_x + 13, 35);
                superShieldBox5.OnRender(GL_Color(1.0, 1.0, 1.0, 1.0));
            }
            else if (enemyShield.super.second == 12)
            {
                superShieldBox12.SetPosition(superBar_x + 13, 35);
                superShieldBox12.OnRender(GL_Color(1.0, 1.0, 1.0, 1.0));
            }
            else
            {
                CSurface::GL_DrawRect(superBar_x + 13.f, 35.f, enemyShield.super.second*10+6, 13.f, GL_Color(0.0, 0.0, 0.0, 0.5));
                CSurface::GL_DrawRectOutline(superBar_x + 13, 35, enemyShield.super.second*10+6, 13, GL_Color(1.0, 1.0, 1.0, 1.0), 2.f);
            }
            CSurface::GL_DrawRect(superBar_x + 16.f, 38.f, enemyShield.super.first*10, 7.f, superColor);
        }

        CSurface::GL_PopMatrix();
    }
    else
    {
        super(pos, color);

        if (CustomAugmentManager::GetInstance()->superShieldCustomRender[1])
        {
            if (enemyShield.super.first > 0)
            {
                GL_Color superColor = CustomAugmentManager::GetInstance()->superShieldColor[1];
                superColor.a = 1.0;

                CSurface::GL_PushMatrix();
                CSurface::GL_Translate(pos.x, pos.y, 0.0);

                CSurface::GL_DrawRect(enemyShield.second*23.f + 16.f, 38.f, enemyShield.super.first*10, 7.f, superColor);

                CSurface::GL_PopMatrix();
            }
        }
    }
}

bool override_GL_RenderPrimitiveWithColor = false;
Shields* Shields_GL_RenderPrimitiveWithColor = nullptr;
GL_Primitive* customSuperShieldPrimitives[2] = {nullptr, nullptr};

HOOK_METHOD(Shields, RenderBase, (float alpha, float superShieldOverwrite) -> void)
{
    int customSuper = CustomAugmentManager::GetSuperShieldValue(_shipObj.iShipId);
    if (customSuper > 0)
    {
        override_GL_RenderPrimitiveWithColor = true;
        Shields_GL_RenderPrimitiveWithColor = this;
    }

    super(alpha, superShieldOverwrite);
    override_GL_RenderPrimitiveWithColor = false;
    Shields_GL_RenderPrimitiveWithColor = nullptr;
}

HOOK_METHOD(CSurface, GL_RenderPrimitiveWithColor, (GL_Primitive *primitive, GL_Color color) -> void)
{
    if (!override_GL_RenderPrimitiveWithColor) return super(primitive, color);
    if (Shields_GL_RenderPrimitiveWithColor != nullptr)
    {
        auto& shields = Shields_GL_RenderPrimitiveWithColor;
        if (color.r < 0.4 && CustomAugmentManager::GetInstance()->superShieldCustomRender[shields->_shipObj.iShipId])
        {
            std::string imageId = CustomAugmentManager::GetInstance()->superShieldTexture[shields->_shipObj.iShipId];

            if (imageId.empty())
            {
                GL_Color customColor = CustomAugmentManager::GetInstance()->superShieldColor[shields->_shipObj.iShipId];
                customColor.a *= color.a;

                return super(primitive, customColor);
            }
            else
            {
                GL_Texture* shieldTex = G_->GetResources()->GetImageId(imageId);
                GL_Color customColor = CustomAugmentManager::GetInstance()->superShieldColor[shields->_shipObj.iShipId];
                customColor.a *= color.a;

                float width = shieldTex->width_;
                float height = shieldTex->height_;

                //GL_Primitive* shieldPrim = GL_CreatePixelImagePrimitive(shieldTex,0.0,0.0,width,height,0.0,GL_Color(1.0,1.0,1.0,1.0),false);
                GL_Primitive* shieldPrim = GL_CreateImagePrimitive(shieldTex,0.0,0.0,width,height,0.0,GL_Color(1.0,1.0,1.0,1.0));

                GL_DestroyPrimitive(customSuperShieldPrimitives[shields->_shipObj.iShipId]);
                customSuperShieldPrimitives[shields->_shipObj.iShipId] = shieldPrim;

                GL_PopMatrix();

                GL_PushMatrix();
                GL_Translate(shields->baseShield.center.x - shields->baseShield.a, shields->baseShield.center.y - shields->baseShield.b, 0.0);
                GL_Scale((2.0*shields->baseShield.a) / width, (2.0*shields->baseShield.b) / height, 1.0);

                return super(shieldPrim, customColor);
            }
        }
    }

    return super(primitive, color);
}

HOOK_METHOD(ShipManager, OnLoop, () -> void)
{
    super();

    if (current_target != nullptr)
    {
        bool has_defense = false;
        bool scrambled = false;
        for (auto drone : spaceDrones)
        {
            if (drone->type == 0)
            {
                if (!has_defense)
                {
                    has_defense = true;
                    scrambled = current_target->HasEquipment("DEFENSE_SCRAMBLER");
                }
                drone->bDisrupted = scrambled;
            }
        }
    }
}

HOOK_METHOD(WorldManager, CreateChoiceBox, (LocationEvent *event) -> void)
{
    super(event);

    float augValue = 0.f;

    if (CustomOptionsManager::GetInstance()->showScrapCollectorScrap.currentValue == false)
    {
        AugmentBlueprint* augBlueprint = G_->GetBlueprints()->GetAugmentBlueprint("SCRAP_COLLECTOR");
        CustomAugmentManager* customAug = CustomAugmentManager::GetInstance();

        std::unordered_map<std::string, int> *augList = customAug->GetShipAugments(0);
        std::unordered_map<std::string, AugmentFunction*> *potentialAugs = customAug->GetPotentialAugments("SCRAP_COLLECTOR");

        float highestValue = 0.f;
        for (auto const& x: *potentialAugs)
        {
            if (augList->count(x.first) && x.second->Functional(0))
            {
                augValue += x.second->value * augList->at(x.first);

                if ((x.second->preferHigher && x.second->value > highestValue) || (!x.second->preferHigher && x.second->value < highestValue))
                {
                    highestValue = x.second->value;
                }
            }
        }

        if (!augBlueprint->stacking) augValue = highestValue;
    }
    else
    {
        augValue = G_->GetShipManager(0)->GetAugmentationValue("SCRAP_COLLECTOR");
    }

    if (augValue != 0.f)
    {
        if (commandGui->choiceBox.rewards.scrap > 0)
        {
            commandGui->choiceBox.rewards.scrap = commandGui->choiceBox.rewards.scrap + commandGui->choiceBox.rewards.scrap * augValue;
        }
        for (auto& choice : commandGui->choiceBox.choices)
        {
            if (choice.rewards.scrap > 0)
            {
                choice.rewards.scrap = choice.rewards.scrap + choice.rewards.scrap * augValue;
            }
        }
    }
}
