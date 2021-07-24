#include "Global.h"

class InternalTabDefinition
{
    std::vector<std::string> validAugments;
    std::string categoryName = "";
};








class InternalAugmentWindow : public FocusWindow
{
public:
    void Open();
    void OnInit(ShipManager *ship);
    void Close();
    void OnRender();
    void MouseMove(int mX, int mY);
    void MouseClick(int mX, int mY);

    static InternalAugmentWindow *GetInstance()
    {
        return instance;
    }

    InternalAugmentWindow() : FocusWindow()
    {

    }



    static InternalAugmentWindow* instance;

private:
    GL_Texture *box = nullptr;
    ShipManager *ship = nullptr;
    InfoBox infoBox;
    Point infoBoxLoc;

    Button tabLeftButton;
    Button tabRightButton;

    Button upButton;
    Button downButton;


    int currentTab = 0;

    std::vector<InternalTabDefinition> tabs;
    std::vector<AugmentEquipBox*> equipBoxes;

};
