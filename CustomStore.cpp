#include "CustomStore.h"
#include "CustomEvents.h"
#include "Store_Extend.h"
#include <boost/lexical_cast.hpp>
#include <array>

CustomStore* CustomStore::instance = new CustomStore();

static ItemPrice ParsePriceNode(rapidxml::xml_node<char>* node)
{
    ItemPrice def;

    for (auto cNode = node->first_node(); cNode; cNode = cNode->next_sibling())
    {
        std::string name = cNode->name();
        std::string val = cNode->value();

        if (name == "price")
        {
            if (cNode->first_attribute("min") && cNode->first_attribute("max"))
            {
                def.minMaxPrice.first = boost::lexical_cast<int>(cNode->first_attribute("min")->value());
                def.minMaxPrice.second = boost::lexical_cast<int>(cNode->first_attribute("max")->value());
                def.useMinMax = true;

                if (def.minMaxPrice.first > def.minMaxPrice.second)
                {
                    def.minMaxPrice.second = def.minMaxPrice.first;
                }
            }

            if (!val.empty())
            {
                def.price = boost::lexical_cast<int>(val);
            }
        }
        if (name == "sectorScaled")
        {
            def.sectorScaled = true;
        }
        if (name == "modifier")
        {
            if (cNode->first_attribute("min") && cNode->first_attribute("max"))
            {
                def.minMaxModifier.first = boost::lexical_cast<float>(cNode->first_attribute("min")->value());
                def.minMaxModifier.second = boost::lexical_cast<float>(cNode->first_attribute("max")->value());

                if (def.minMaxModifier.first > def.minMaxModifier.second)
                {
                    def.minMaxModifier.second = def.minMaxModifier.first;
                }
            }

            if (!val.empty())
            {
                def.minMaxModifier.first = boost::lexical_cast<float>(val);
                def.minMaxModifier.second = boost::lexical_cast<float>(val);
            }

            def.hasModifier = true;
        }
    }

    return def;
}

static HullRepair ParseHullRepairNode(rapidxml::xml_node<char>* node)
{
    HullRepair def;
    def.price = ParsePriceNode(node);

    for (auto cNode = node->first_node(); cNode; cNode = cNode->next_sibling())
    {
        std::string name = cNode->name();
        std::string val = cNode->value();
    }

    return def;
}

static ResourceItem ParseResourceNode(rapidxml::xml_node<char>* node)
{
    ResourceItem def;
    def.price = ParsePriceNode(node);

    for (auto cNode = node->first_node(); cNode; cNode = cNode->next_sibling())
    {
        std::string name = cNode->name();
        std::string val = cNode->value();

        if (name == "type")
        {
            def.type = val;
        }
        if (name == "count")
        {
            if (cNode->first_attribute("min") && cNode->first_attribute("max"))
            {
                def.minMaxCount.first = boost::lexical_cast<int>(cNode->first_attribute("min"));
                def.minMaxCount.second = boost::lexical_cast<int>(cNode->first_attribute("max"));
            }

            if (!val.empty())
            {
                def.minMaxCount.first = boost::lexical_cast<int>(val);
                def.minMaxCount.second = boost::lexical_cast<int>(val);
            }
        }
    }

    return def;
}

static StoreItem ParseStoreItemNode(rapidxml::xml_node<char>* node)
{
    StoreItem def;
    def.price = ParsePriceNode(node);

    for (auto cNode = node->first_node(); cNode; cNode = cNode->next_sibling())
    {
        std::string name = cNode->name();
        std::string val = cNode->value();

        if (name == "blueprint")
        {
            def.blueprint = val;

        }
    }

    return def;
}

static StoreCategory ParseCategoryNode(rapidxml::xml_node<char>* node)
{
    StoreCategory def;

    if (node->first_attribute("type"))
    {
        std::array<std::string, 5> categories = {"WEAPONS", "DRONES", "AUGMENTS", "CREW", "SYSTEMS"};

        auto it = std::find(categories.begin(), categories.end(), node->first_attribute("type")->value());
        if (it != categories.end())
        {
            def.categoryType = static_cast<CategoryType>(it - categories.begin());
        }
    }

    for (auto cNode = node->first_node(); cNode; cNode = cNode->next_sibling())
    {
        std::string name = cNode->name();
        std::string val = cNode->value();


        if (name == "item")
        {
            auto item = ParseStoreItemNode(cNode);
            def.items.push_back(item);
        }
    }

    return def;
}

void CustomStore::ParseStoreNode(rapidxml::xml_node<char>* node)
{
    for (auto storeNode = node->first_node(); storeNode; storeNode = storeNode->next_sibling())
    {
        std::string name = storeNode->name();
        std::string val = storeNode->value();
        if (name == "freeDrones")
        {
            for (auto droneNode = storeNode->first_node(); droneNode; droneNode = droneNode->next_sibling())
            {
                freeDrones.push_back(droneNode->name());
            }
        }
        if (name == "customStore")
        {
            std::string id = storeNode->first_attribute("id")->value();
            StoreDefinition def = StoreDefinition();

            for (auto cStoreNode = storeNode->first_node(); cStoreNode; cStoreNode = cStoreNode->next_sibling())
            {
                // do xml parsing for custom stores here
                std::string cStoreName = cStoreNode->name();

                if (cStoreName == "hullRepair")
                {
                    def.hullRepair = ParseHullRepairNode(cStoreNode);
                    def.hullRepair.visible = true;
                }

                if (cStoreName == "resource")
                {
                    def.resources.push_back(ParseResourceNode(cStoreNode));
                }

                if (cStoreName == "category")
                {
                    auto cat = ParseCategoryNode(cStoreNode);

                    def.categories.push_back(cat);
                }
            }

            storeDefs[id] = def;
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

    if (CustomStore::instance->freeDrones.size() <= 0)
        return;

    auto bp = G_->GetBlueprints()->GetDroneBlueprint(freeBlueprint);

    int oldPrice = bp->desc.cost / 2;

    DroneBlueprint *newBlueprint = G_->GetBlueprints()->GetDroneBlueprint(CustomStore::instance->freeDrones[random32() % CustomStore::instance->freeDrones.size()]);
    freeBlueprint = newBlueprint->name;

    desc.cost -= oldPrice;
    desc.cost += newBlueprint->desc.cost / 2;
}

static int GetItemPricing(const ItemPrice& price, int defaultCost, int worldLevel)
{
    printf("%d\n", worldLevel);

    int finalPrice = price.price;

    if (finalPrice == -1)
    {
        finalPrice = defaultCost;
    }

    if (price.useMinMax)
    {
        if (price.sectorScaled)
        {
            finalPrice = std::floor((float)(price.minMaxPrice.second - price.minMaxPrice.first) * ((float)worldLevel / 7.f) + price.minMaxPrice.first);
        }
        else
        {
            finalPrice = random32() % (price.minMaxPrice.second - price.minMaxPrice.first + 1) + price.minMaxPrice.first;
        }
    }

    if (price.hasModifier)
    {
        float modifier;

        if (price.minMaxModifier.first == price.minMaxModifier.second)
        {
            modifier = price.minMaxModifier.first;
        }
        else
        {
            int rng = random32() % RAND_MAX;

            float random = (float)rng / (float)RAND_MAX;
            float range = price.minMaxModifier.second - price.minMaxModifier.first;
            modifier = (random * range) + price.minMaxModifier.first;
        }

        if (price.flatModifier)
        {
            finalPrice += modifier;
        }
        else
        {
            finalPrice *= modifier;
        }
    }

    return finalPrice;
}

std::vector<StoreBox*> StoreComplete::CreateCustomStoreBoxes(const StoreCategory& category, ShipManager *ship, Equipment *equip)
{
    auto vec = std::vector<StoreBox*>();

    for (auto i : orig->vStoreBoxes)
    {
        delete i;
    }

    orig->vStoreBoxes.clear();

    if (category.categoryType == CategoryType::WEAPONS)
    {
        orig->CreateStoreBoxes(0, equip);
        for (auto i : category.items)
        {
            WeaponStoreBox* box;

            if (i.blueprint.empty())
            {
                box = (WeaponStoreBox*)orig->vStoreBoxes.back();
                orig->vStoreBoxes.pop_back();

                box->desc.cost = GetItemPricing(i.price, box->blueprint->desc.cost, orig->worldLevel);

                vec.push_back(box);
            }
            else
            {
                WeaponBlueprint* bp;

                auto potentialList = G_->GetBlueprints()->GetBlueprintList(i.blueprint);

                if (potentialList.empty())
                {
                    bp = G_->GetBlueprints()->GetWeaponBlueprint(i.blueprint);
                }
                else
                {
                    bp = G_->GetBlueprints()->GetWeaponBlueprint(potentialList[random32() % potentialList.size()]);
                }

                if (bp)
                {
                    box = new WeaponStoreBox(ship, equip, bp);

                    box->desc.cost = GetItemPricing(i.price, bp->desc.cost, orig->worldLevel);

                    vec.push_back(box);
                }
            }
        }
    }
    else if (category.categoryType == CategoryType::DRONES)
    {
        orig->CreateStoreBoxes(1, equip);

        for (auto i : category.items)
        {
            DroneStoreBox* box;

            if (i.blueprint.empty())
            {
                box = (DroneStoreBox*)orig->vStoreBoxes.back();
                orig->vStoreBoxes.pop_back();

                box->desc.cost = GetItemPricing(i.price, box->blueprint->desc.cost, orig->worldLevel);

                vec.push_back(box);
            }
            else
            {
                DroneBlueprint* bp;

                auto potentialList = G_->GetBlueprints()->GetBlueprintList(i.blueprint);

                if (potentialList.empty())
                {
                    bp = G_->GetBlueprints()->GetDroneBlueprint(i.blueprint);
                }
                else
                {
                    bp = G_->GetBlueprints()->GetDroneBlueprint(potentialList[random32() % potentialList.size()]);
                }

                if (bp)
                {
                    box = new DroneStoreBox(ship, equip, bp);

                    box->desc.cost = GetItemPricing(i.price, bp->desc.cost, orig->worldLevel);

                    vec.push_back(box);
                }
            }
        }
    }
    else if (category.categoryType == CategoryType::AUGMENTS)
    {
        orig->CreateStoreBoxes(2, equip);

        for (auto i : category.items)
        {
            AugmentStoreBox* box;

            if (i.blueprint.empty())
            {
                box = (AugmentStoreBox*)orig->vStoreBoxes.back();
                orig->vStoreBoxes.pop_back();

                box->desc.cost = GetItemPricing(i.price, box->blueprint->desc.cost, orig->worldLevel);

                vec.push_back(box);
            }
            else
            {
                AugmentBlueprint* bp;

                auto potentialList = G_->GetBlueprints()->GetBlueprintList(i.blueprint);

                if (potentialList.empty())
                {
                    bp = G_->GetBlueprints()->GetAugmentBlueprint(i.blueprint);
                }
                else
                {
                    bp = G_->GetBlueprints()->GetAugmentBlueprint(potentialList[random32() % potentialList.size()]);
                }

                if (bp)
                {
                    box = new AugmentStoreBox(ship, bp);

                    box->desc.cost = GetItemPricing(i.price, box->blueprint->desc.cost, orig->worldLevel);

                    vec.push_back(box);

                    delete bp;
                }
            }
        }
    }
    else if (category.categoryType == CategoryType::CREW)
    {
        orig->CreateStoreBoxes(3, equip);

        for (auto i : category.items)
        {
            CrewStoreBox* box;

            if (i.blueprint.empty())
            {
                box = (CrewStoreBox*)orig->vStoreBoxes.back();
                orig->vStoreBoxes.pop_back();

                box->desc.cost = GetItemPricing(i.price, box->blueprint.desc.cost, orig->worldLevel);

                vec.push_back(box);
            }
            else
            {
                std::string species = i.blueprint;

                auto potentialList = G_->GetBlueprints()->GetBlueprintList(i.blueprint);

                if (!potentialList.empty())
                {
                    species = potentialList[random32() % potentialList.size()];
                }

                auto bp = G_->GetBlueprints()->GetCrewBlueprint(species);

                if (bp)
                {
                    box = new CrewStoreBox(ship, orig->worldLevel, species);

                    box->desc.cost = GetItemPricing(i.price, bp->desc.cost, orig->worldLevel);

                    vec.push_back(box);

                    delete bp;
                }
            }
        }
    }
    else if (category.categoryType == CategoryType::SYSTEMS)
    {
        orig->CreateStoreBoxes(4, equip);

        for (auto i : category.items)
        {
            SystemStoreBox* box;

            if (i.blueprint.empty())
            {
                box = (SystemStoreBox*)orig->vStoreBoxes.back();
                orig->vStoreBoxes.pop_back();

                box->desc.cost = GetItemPricing(i.price, box->desc.cost, orig->worldLevel);

                vec.push_back(box);
            }
            else
            {
                auto bp = G_->GetBlueprints()->GetSystemBlueprint(i.blueprint);

                if (bp)
                {
                    box = new SystemStoreBox(ship, equip, ShipSystem::NameToSystemId(i.blueprint));

                    box->desc.cost = GetItemPricing(i.price, box->desc.cost, orig->worldLevel);

                    vec.push_back(box);

                    delete bp;
                }

            }
        }
    }

    orig->vStoreBoxes.clear();


    return vec;

}

void StoreComplete::OnInit(const StoreDefinition& def, ShipManager *ship, Equipment *equip, int level)
{
    orig->worldLevel = level;
    orig->shopper = ship;

    for (auto i : def.resources)
    {
        ItemStoreBox* box = new ItemStoreBox(ship, i.type);

        box->count = i.minMaxCount.first + (random32() % (i.minMaxCount.second - i.minMaxCount.first + 1));
        box->blueprint->desc.cost = GetItemPricing(i.price, box->blueprint->desc.cost, level);

        resourceBoxes.push_back(box);
    }

    if (def.hullRepair.visible)
    {
        int price = 2;
        if (level > 5)
        {
            price = 4;
        }
        else if (level > 2)
        {
            price = 3;
        }

        price = GetItemPricing(def.hullRepair.price, price, level);

        RepairStoreBox* repairOne = new RepairStoreBox(ship, false, price);
        RepairStoreBox* repairAll = new RepairStoreBox(ship, true, price);

        repairBoxes.push_back(repairOne);
        repairBoxes.push_back(repairAll);
    }

    StorePage currPage = StorePage();

    for (int i = 0; i < def.categories.size(); i++)
    {
        auto cat = def.categories[i];
        StoreSection sec = StoreSection();
        sec.category = cat.categoryType;

        auto newBoxes = CreateCustomStoreBoxes(cat, ship, equip);

        int currentSec = -1;
        for (int boxIdx = 0; boxIdx < newBoxes.size(); boxIdx++)
        {
            if (boxIdx % 3 == 0)
            {
                currentSec++;

                sec.storeBoxes.push_back(std::vector<CustomStoreBox*>());
            }

            auto customBox = new CustomStoreBox();
            customBox->orig = newBoxes[boxIdx];

            sec.storeBoxes[currentSec].push_back(customBox);
        }

        currPage.sections.push_back(sec);

        if (i % 2 == 1 || i == def.categories.size() - 1)
        {
            pages.push_back(currPage);
            currPage = StorePage();
        }
    }

    SetPositions();
}

std::string StoreComplete::GetHeadingText(CategoryType type)
{
    std::string base = "store_title_";

    switch (type)
    {
    case CategoryType::WEAPONS:
        return base + "weapons";
    case CategoryType::DRONES:
        return base + "drones";
    case CategoryType::AUGMENTS:
        return base + "augments";
    case CategoryType::CREW:
        return base + "crew";
    case CategoryType::SYSTEMS:
        return base + "systems";
    }
}

void StoreComplete::InitHeadings()
{
    for (auto& page : pages)
    {
        for (auto& sec : page.sections)
        {
            sec.headingTitle = GetHeadingText(sec.category);
        }
    }
}

void StoreComplete::SetPositions()
{
    orig->box = G_->GetResources()->GetImageId("storeUI/store_buy_main.png");

    orig->infoBoxLoc.x = orig->position.x + 600;
    orig->infoBoxLoc.y = orig->position.y;
    orig->infoBox.location = orig->infoBoxLoc;

    int resourceBoxOffsets[3] = {0, 50, 99};

    for (int i = 0; i < resourceBoxes.size(); i++)
    {
        auto box = resourceBoxes[i];

        box->SetPosition(orig->position.x + 18, orig->position.y + 83 + resourceBoxOffsets[i]);
    }

    int repairBoxOffsets[3] = {291, 346};

    for (int i = 0; i < repairBoxes.size(); i++)
    {
        auto box = repairBoxes[i];
        box->SetPosition(orig->position.x + 18, orig->position.y + repairBoxOffsets[i]);
    }

    InitHeadings();

    for (auto page : pages)
    {
        for (int secIndex = 0; secIndex < page.sections.size(); secIndex++)
        {
            auto section = page.sections[secIndex];

            Point boxPos(208, 103 + secIndex * 209);
            Point altBoxPos(203, 83 + secIndex * 209);

            for (auto boxList : section.storeBoxes)
            {
                for (int boxIndex = 0; boxIndex < boxList.size(); boxIndex++)
                {
                    auto box = boxList[boxIndex];

                    if (section.category != CategoryType::AUGMENTS && section.category != CategoryType::SYSTEMS)
                    {
                        box->orig->SetPosition(boxPos.x + orig->position.x, boxPos.y + orig->position.y);

                        boxPos.x += 125;
                    }
                    else
                    {
                        box->orig->SetPosition(altBoxPos.x + orig->position.x, altBoxPos.y + orig->position.y);

                        altBoxPos.y += 53;
                    }
                }
            }
        }
    }
}

void StoreComplete::OnRender()
{
    CSurface::GL_PushMatrix();
    if (orig->confirmBuy)
    {
        CSurface::GL_SetColorTint(COLOR_TINT);
    }

    CSurface::GL_Translate(orig->position.x, orig->position.y);

    if (orig->box)
    {
        CSurface::GL_BlitPixelImage(orig->box, 0, 0, orig->box->width_, orig->box->height_, 0, COLOR_WHITE, false);
    }

    CSurface::GL_SetColor(COLOR_BUTTON_TEXT);

    orig->DrawBuySellTabText();
    freetype::easy_print(62, 18.f, 45.f, G_->GetTextLibrary()->GetText("store_title_items"));
    freetype::easy_print(62, 18.f, 254.f, G_->GetTextLibrary()->GetText("store_title_repair"));

    CSurface::GL_SetColor(COLOR_BUTTON_ON);

    std::string currentHullText = G_->GetTextLibrary()->GetText("store_current_hull");

    float currentHullY = 419.f;

    if (currentHullText.find('\n') == std::string::npos)
    {
        currentHullY = 427.f;
    }

    freetype::easy_printCenter(59, 73.f, currentHullY, currentHullText);

    CSurface::GL_SetColor(COLOR_BUTTON_TEXT);

    CSurface::GL_PopMatrix();

    CSurface::GL_SetColor(COLOR_BUTTON_ON);

    std::string unavailableText = G_->GetTextLibrary()->GetText("store_unavailable");

    if (pages.size() > 0)
    {
        Point headingPos = Point(206, 45);
        for (auto section : pages[currentPage].sections)
        {
            CSurface::GL_SetColor(COLOR_BUTTON_TEXT);
            freetype::easy_print(62, orig->position.x + headingPos.x, orig->position.y + headingPos.y, G_->GetTextLibrary()->GetText(section.headingTitle));

            for (auto box : section.storeBoxes[section.currentSection])
            {
                box->orig->OnRender();
            }

            headingPos.y += 209;
        }

        if (pages[currentPage].sections.size() == 1)
        {
            CSurface::GL_SetColor(COLOR_BUTTON_ON);

            freetype::easy_printCenter(52, orig->position.x + 394, orig->position.y + 358, unavailableText);
        }
    }
    else
    {
        CSurface::GL_SetColor(COLOR_BUTTON_ON);

        freetype::easy_printCenter(52, orig->position.x + 394, orig->position.y + 148, unavailableText);
        freetype::easy_printCenter(52, orig->position.x + 394, orig->position.y + 358, unavailableText);
    }

    for (auto i : resourceBoxes)
    {
        i->OnRender();
    }

    if (resourceBoxes.empty())
    {
        CSurface::GL_SetColor(COLOR_BUTTON_ON);

        freetype::easy_printCenter(52, orig->position.x + 102, orig->position.y + 148, unavailableText);
    }

    for (auto i : repairBoxes)
    {
        i->OnRender();
    }

    if (repairBoxes.empty())
    {
        CSurface::GL_SetColor(COLOR_BUTTON_ON);

        freetype::easy_printCenter(52, orig->position.x + 102, orig->position.y + 332, unavailableText);
    }

    CSurface::GL_SetColor(COLOR_BUTTON_ON);

    char buffer[64];
    sprintf(buffer, "%d", orig->shopper->ship.hullIntegrity.first);
    freetype::easy_print(0, orig->position.x + 143, orig->position.y + 432, buffer);
    orig->infoBox.OnRender();
    if (orig->confirmBuy)
    {
        CSurface::GL_RemoveColorTint();
        orig->confirmDialog.OnRender();
    }
}

void StoreComplete::NextPage()
{
    currentPage++;

    if (currentPage >= pages.size())
    {
        currentPage = 0;
    }
}

void StoreComplete::PreviousPage()
{
    currentPage--;
    if (currentPage < 0)
    {
        currentPage = pages.size() - 1;
    }
}

void StoreComplete::KeyDown(SDLKey key)
{
    if (key == SDLKey::SDLK_RIGHT)
    {
        NextPage();
    }
    if (key == SDLKey::SDLK_LEFT)
    {
        PreviousPage();
    }
}

void StoreComplete::OnLoop()
{
    for (auto i : resourceBoxes)
    {
        i->OnLoop();
    }

    for (auto i : repairBoxes)
    {
        i->OnLoop();
    }

    if (pages.size() > 0)
    {
        for (auto sec : pages[currentPage].sections)
        {
            if (sec.storeBoxes.size() > 0)
            {
                for (auto i : sec.storeBoxes[sec.currentSection])
                {
                    i->orig->OnLoop();
                }
            }
        }
    }

}

void StoreComplete::MouseClick(int x, int y)
{
    if (orig->confirmBuy)
    {
        orig->confirmDialog.MouseClick(x, y);

        if (!orig->confirmDialog.bOpen)
        {
            orig->confirmBuy->Confirm(orig->confirmDialog.result);
            orig->confirmBuy = nullptr;
        }

    }

    for (auto i : resourceBoxes)
    {
        i->MouseClick(x, y);
    }

    for (auto i : repairBoxes)
    {
        i->MouseClick(x, y);
    }

    if (pages.size() > 0)
    {
        for (auto sec : pages[currentPage].sections)
        {
            if (sec.storeBoxes.size() > 0)
            {
                for (auto i : sec.storeBoxes[sec.currentSection])
                {
                    i->orig->MouseClick(x, y);


                    if (i->orig->RequiresConfirm())
                    {
                        orig->confirmBuy = i->orig;

                        TextString yes;
                        yes.data = "confirm_yes";
                        yes.isLiteral = false;
                        TextString no;
                        no.data = "confirm_no";
                        no.isLiteral = false;

                        orig->confirmDialog.SetText(i->orig->GetConfirmText(), 300, true, yes, no);
                        orig->confirmDialog.Open();
                    }
                }
            }
        }
    }
}

void StoreComplete::MouseMove(int x, int y)
{
    orig->infoBox.Clear();

    for (auto i : resourceBoxes)
    {
        i->MouseMove(x, y);

        if ((i->button.bHover || i->button.bSelected) && i->count > 0)
        {
            i->SetInfoBox(orig->infoBox, 347);
        }
    }

    for (auto i : repairBoxes)
    {
        i->MouseMove(x, y);
    }

    if (pages.size() > 0)
    {
        for (auto sec : pages[currentPage].sections)
        {
            if (sec.storeBoxes.size() > 0)
            {
                for (auto i : sec.storeBoxes[sec.currentSection])
                {
                    i->orig->MouseMove(x, y);


                    if ((i->orig->button.bHover || i->orig->button.bSelected) && i->orig->count > 0)
                    {
                        i->orig->SetInfoBox(orig->infoBox, 347);
                    }
                }
            }
        }
    }
}

HOOK_METHOD(Store, KeyDown, (SDLKey key) -> void)
{
    STORE_EX(this)->customStore->KeyDown(key);

    return;
    super(key);
}

HOOK_METHOD(Store, OnRender, () -> void)
{
    if (STORE_EX(this)->isCustomStore)
    {
        STORE_EX(this)->customStore->OnRender();
        return;
    }

    return super();

    // Unused rewritten code - could have some use in the future
    CSurface::GL_PushMatrix();
    if (confirmBuy)
    {
        CSurface::GL_SetColorTint(COLOR_TINT);
    }

    CSurface::GL_Translate(position.x, position.y);


    CSurface::GL_BlitPixelImage(box, 0, 0, box->width_, box->height_, 0, COLOR_WHITE, false);
    CSurface::GL_SetColor(COLOR_BUTTON_TEXT);

    DrawBuySellTabText();
    freetype::easy_print(62, 18.f, 45.f, G_->GetTextLibrary()->GetText("store_title_items"));
    freetype::easy_print(62, 18.f, 254.f, G_->GetTextLibrary()->GetText("store_title_repair"));

    CSurface::GL_SetColor(COLOR_BUTTON_ON);

    std::string currentHullText = G_->GetTextLibrary()->GetText("store_current_hull");

    float currentHullY = 419.f;

    if (currentHullText.find('\n') == std::string::npos)
    {
        currentHullY = 427.f;
    }

    freetype::easy_printCenter(59, 73.f, currentHullY, currentHullText);

    CSurface::GL_SetColor(COLOR_BUTTON_TEXT);

    int headingIndex = bShowPage2 ? 2 : 0;

    Point pos1 = Point(198, 42);
    freetype::easy_print(62, pos1.x + 7, pos1.y + 3, headingTitle[headingIndex].GetText());

    int heading2Index = bShowPage2 ? 3 : 1;

    Point pos2 = Point(198, 251);
    freetype::easy_print(62, pos2.x + 7, pos2.y + 3, headingTitle[heading2Index].GetText());

    CSurface::GL_PopMatrix();

    if (sectionCount > 2)
    {
        Pointf pos3 = Pointf(currentButton->position.x, currentButton->position.y + 7);

        currentButton->OnRender();
        CSurface::GL_SetColor(COLOR_BUTTON_TEXT);

        freetype::easy_printCenter(62, pos3.x + 65, pos3.y, G_->GetTextLibrary()->GetText("store_tab_page1"));
        freetype::easy_printCenter(62, pos3.x + 171, pos3.y, G_->GetTextLibrary()->GetText("store_tab_page2"));
    }

    if (bShowPage2)
    {
        for (int i = 6; i < sectionCount * 3; i++)
        {
            vStoreBoxes[i]->OnRender();
        }
    }
    else
    {
        for (int i = 0; i < 6; i++)
        {
            vStoreBoxes[i]->OnRender();
        }
    }

    // appears to be for items/repair, but it's weird??
    if (3 * sectionCount + 5 > 3 * sectionCount)
    {
        for (int i = 3 * sectionCount; i < 3 * sectionCount + 5; i++)
        {
            vStoreBoxes[i]->OnRender();
        }
    }

    CSurface::GL_SetColor(COLOR_BUTTON_ON);

    char buffer[64];
    sprintf(buffer, "%d", shopper->ship.hullIntegrity.first);
    freetype::easy_print(0, position.x + 143, position.y + 432, buffer);
    infoBox.OnRender();
    if (confirmBuy)
    {
        CSurface::GL_RemoveColorTint();
        confirmDialog.OnRender();
    }
}

std::string customStoreId;

HOOK_METHOD(WorldManager, CreateStore, (LocationEvent *event) -> void)
{
    auto customEvent = CustomEventsParser::GetInstance()->GetCustomEvent(event->eventName);

    customStoreId = "";


    if (customEvent)
    {
        customStoreId = customEvent->customStore;
    }

    super(event);
}

HOOK_METHOD(Store, OnInit, (ShipManager *shopper, Equipment *equip, int worldLevel) -> void)
{
    //return super(shopper, equip, worldLevel);
    if (!customStoreId.empty())
    {
        auto def = CustomStore::instance->GetStoreDefinition(customStoreId);

        if (def)
        {
            StoreComplete* newStore = new StoreComplete(this);

            newStore->OnInit(*def, shopper, equip, worldLevel);

            STORE_EX(this)->isCustomStore = true;
            STORE_EX(this)->customStore = newStore;

            return;
        }
    }

    super(shopper, equip, worldLevel);
}

HOOK_METHOD(Store, RelinkShip, (ShipManager *ship, Equipment *equip) -> void)
{
    if (STORE_EX(this)->isCustomStore)
    {
        // do stuff
        return;
    }

    super(ship, equip);
}

HOOK_METHOD(Store, LoadStore, (int file, int worldLevel) -> void)
{
    if (STORE_EX(this)->isCustomStore)
    {
        // load custom store
        return;
    }

    super(file, worldLevel);
}

HOOK_METHOD(Store, OnLoop, () -> void)
{
    if (STORE_EX(this)->isCustomStore)
    {
        STORE_EX(this)->customStore->OnLoop();
        return;
    }

    super();
}

HOOK_METHOD(Store, SetPositions, () -> void)
{
    if (STORE_EX(this)->isCustomStore)
    {
        STORE_EX(this)->customStore->SetPositions();
        return;
    }

    super();
}

HOOK_METHOD(Store, MouseMove, (int x, int y) -> void)
{
    if (STORE_EX(this)->isCustomStore)
    {
        STORE_EX(this)->customStore->MouseMove(x, y);
        return;
    }

    super(x, y);
}

HOOK_METHOD(Store, MouseClick, (int x, int y) -> void)
{
    if (STORE_EX(this)->isCustomStore)
    {
        STORE_EX(this)->customStore->MouseClick(x, y);
        return;
    }

    super(x, y);
}
