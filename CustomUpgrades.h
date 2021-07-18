#include "Global.h"

class CustomUpgrades
{
public:
    CustomUpgrades()
    {

    };

    std::vector<UpgradeBox*> GetPage(int page)
    {
        return systemUpgradeBoxes[page];
    }

    int GetNumPages()
    {
        return systemUpgradeBoxes.size();
    }

    void OnInit(Upgrades *upgrades, ShipManager *ship);
    void MouseClick(int mX, int mY);
    void MouseMove(int mX, int mY);
    void MouseRightClick(int mX, int mY);
    void OnRender();
    void Close();
    void OnLoop();
    void AddSystemBox(UpgradeBox* box);
    void ConfirmUpgrades();

    std::vector<std::vector<UpgradeBox*>> systemUpgradeBoxes;

    static CustomUpgrades* GetInstance()
    {
        return &instance;
    }
private:
    Upgrades *orig = nullptr;
    Button *leftButton = nullptr;
    Button *rightButton = nullptr;


    int currentPage = 0;

    static CustomUpgrades instance;
};
