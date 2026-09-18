#include "Global.h"
template<unsigned int PageSize>
class UpgradeBoxSet
{
public:
    void OnInit(Upgrades* upgrades, int leftOffset, int rightOffset, int verticalOffset);
    void OnRender();
    void MouseMove(int mX, int mY);
    void MouseClick(int mX, int mY);
    void MouseRightClick(int mX, int mY);
    void AddUpgradeBox(UpgradeBox* box);
    bool OnLoop();
    void Accept();
private:
    int GetNumPages()
    {
        return boxes.size();
    }
    std::vector<std::vector<UpgradeBox*>> boxes;
    std::unique_ptr<Button> leftButton = nullptr;
    std::unique_ptr<Button> rightButton = nullptr;
    int currentPage = 0;
    Upgrades* orig = nullptr;
};

class CustomUpgrades
{
public:
    CustomUpgrades()
    {

    };
    void OnInit(Upgrades *upgrades, ShipManager *ship);
    void MouseClick(int mX, int mY);
    void MouseMove(int mX, int mY);
    void MouseRightClick(int mX, int mY);
    void OnRender();
    void Close();
    void OnLoop();
    void AddSystemBox(UpgradeBox* box, bool subSystem);
    void ConfirmUpgrades();

    Upgrades *orig = nullptr;
    TextInput *renameInput = nullptr;
    bool allowRename = false;
    bool allowButton = false;

    static CustomUpgrades* GetInstance()
    {
        return &instance;
    }
private:
    UpgradeBoxSet<8> systemBoxes;
    UpgradeBoxSet<4> subSystemBoxes;
    Button *renameButton = nullptr;
    static CustomUpgrades instance;
};

struct SystemNoPurchaseThreshold
{
    static std::string to_string(int cost)
    {
        if (!enabled || cost < threshold) return std::to_string(cost);
        return replace;
    }

    static bool enabled;
    static int threshold;
    static std::string replace;
};
