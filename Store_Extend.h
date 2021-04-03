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
    CREW,
    AUGMENTATIONS,
    SYSTEMS
};

struct ResourceItem
{
    std::string type; // fuel, missiles or drones
    int minCount;
    int maxCount;

    bool modifiedPrice = false;
    bool flatModifier = false;
    float modifier = 1.f; // multiplies the price by 1 by default
    int price = -1;
};

struct HullRepair
{
    int maxRepairs = -1; // infinite
    int price; // sector-scaled by default
    bool visible;
};

struct StoreItem
{
    std::string itemName;
    std::string iconFileName;

    std::vector<StoreItem> bundledItems;
    std::vector<ResourceItem> bundledResources;

    bool modifiedPrice = false;
    bool flatModifier = false;
    bool setPrice = false;
    float modifier = 1.f; // multiplies the price by 1 by default

    float bundleChance;
    float bundlePriceIncrease;

    int price; // item's xml price by default
    int stock = -1; // infinite by default
    Currency individualCurrency; // uses the store's currency by default
};

struct StoreCategory
{
    std::vector<StoreItem> items;
    std::string blueprintList;

    CategoryType categoryType;
    std::vector<SystemId> allowedSystems; // contains all by default
    std::string categoryName;
    std::string iconFileName;

    int categoryStock; // infinite by default
};

struct StoreDefinition
{
    std::vector<StoreCategory> categories;
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

class CustomStoreBox : public StoreBox
{
    CustomStoreBox(const std::string& buttonImage, ShipManager *shopper, Equipment *ship) : StoreBox(buttonImage, shopper, ship)
    {

    }
};

class StoreSection
{
public:
    std::vector<std::vector<CustomStoreBox*>> storeBoxes;

    int currentSection;
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

    StoreComplete(Store* original)
    {
        orig = original;
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
