#pragma once
#include "FTLGame.h"
#include "Systems.h"

enum class Currency
{
    SCRAP,
    FUEL,
    MISSILES,
    DRONE_PARTS,
    WEAPONS,
    DRONES,
    AUGMENTS,
    CREW,
    SYSTEMS,
    REACTOR,
    HULL
};

enum class CategoryType
{
    WEAPONS,
    DRONES,
    AUGMENTS,
    CREW,
    SYSTEMS
};

struct ItemPrice
{
    int price = -1;
    std::pair<int, int> minMaxPrice;

    bool useMinMax = false;
    bool sectorScaled = false;



    std::pair<float, float> minMaxModifier;
    bool flatModifier = false;
    bool hasModifier = false;
};

struct ResourceItem
{
    std::string type; // fuel, missiles or drones
    std::pair<int, int> minMaxCount;

    ItemPrice price;
};

struct HullRepair
{
    int maxRepairs = -1; // infinite
    ItemPrice price;
    bool visible;
};

struct StoreItem
{
    std::string blueprint;

    std::vector<StoreItem> bundledItems;
    std::vector<ResourceItem> bundledResources;

    ItemPrice price;
    float bundleChance;
    float bundlePriceIncrease;

    int stock = -1; // infinite by default
    Currency individualCurrency; // uses the store's currency by default
};

struct StoreCategory
{
    std::vector<StoreItem> items;

    CategoryType categoryType;
    std::vector<SystemId> allowedSystems; // contains all by default

    std::string customTitle;

    int categoryStock; // infinite by default
    int chance = 100;
    int groupChance = 0;
    bool preventDuplicates = true;
};

struct StoreDefinition
{
    std::unordered_map<int, std::vector<StoreCategory>> categories;
    std::vector<ResourceItem> resources;
    HullRepair hullRepair;

    Currency buyCurrency = Currency::SCRAP; // all stores use scrap by default
    Currency sellCurrency = Currency::SCRAP;
    float sellToBuyRatio = 0.5; // selling at half the price of buying for an item's currency value
    bool canBuy = true;
    bool canSell = true;
    std::vector<Currency> validSells; // is weapons, drones, augments by default
    std::vector<std::string> validItemSells;

    int totalItemStock = -1; // infinite by default
    int sellLimit = -1;

    int storeNum; // for when multiple stores are created at once
};

class CustomStoreBox
{
public:
    void OnRender();

    StoreBox *orig;
    bool showSale = false;
    int originalPrice = -1;

    ~CustomStoreBox()
    {
        delete orig;
    }
};

class StoreSection
{
public:
    std::vector<std::vector<CustomStoreBox*>> storeBoxes;

    int currentSection;
    CategoryType category;
    std::string headingTitle;
    std::string customTitle;
};

class StorePage
{
public:
    std::vector<StoreSection> sections;
};

class StoreComplete
{
    Store *orig;
    StoreDefinition def;

    std::vector<StorePage> pages;
    std::vector<ItemStoreBox*> resourceBoxes;
    std::vector<RepairStoreBox*> repairBoxes;

    Button* leftButton;
    Button* rightButton;

    int currentPage = 0;

public:
    void OnRender();
    void OnInit(const StoreDefinition& def, ShipManager* ship, Equipment* equip, int worldLevel);
    void MouseClick(int x, int y);
    void MouseMove(int x, int y);
    void KeyDown(SDLKey key);
    void OnLoop();
    void SetPositions();
    void NextPage();
    void PreviousPage();
    void CreateStoreBoxes();
    void InitHeadings();
    std::vector<StoreBox*> CreateCustomStoreBoxes(const StoreCategory& category, ShipManager *ship, Equipment *equip);
    std::string GetHeadingText(CategoryType type);

    StoreComplete(Store* original)
    {
        orig = original;
    }

    ~StoreComplete()
    {
        for (auto i : resourceBoxes)
        {
            delete i;
        }
        for (auto i : repairBoxes)
        {
            delete i;
        }
        for (auto page : pages)
        {
            for (auto section : page.sections)
            {
                for (auto i : section.storeBoxes)
                {
                    for (auto j : i)
                    {
                        delete j;
                    }
                }
            }
        }

        delete leftButton;
        delete rightButton;
    }
};

struct Store_Extend
{
    Store *orig;
    bool isCustomStore = false;
    StoreComplete* customStore;


    ~Store_Extend()
    {
        delete customStore;
    }
};

Store_Extend* Get_Store_Extend(Store* c);

#define STORE_EX Get_Store_Extend
