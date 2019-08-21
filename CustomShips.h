#include "Global.h"

class CustomShipSelect
{
public:
    CustomShipSelect(int maxShips)
    {
        maxShipPage = std::ceil(maxShips / 10.f);

        if (maxShipPage <= 0) maxShipPage = 1;
    }

    void OnInit(ShipSelect*);
    void OnRender(bool renderSelect=false);
    void MouseMove(int x, int y);
    void MouseClick();
    void SwitchPage(int page);

    bool ShouldRenderButton(ShipButton *button);
    bool ShouldRenderArrow();

    void LeaveFirstPage();
    void EnterFirstPage();

    int GetCurrentPage()
    {
        return shipPage;
    }

    int GetMaxPages()
    {
        return maxShipPage;
    }

    bool FirstPage()
    {
        return shipPage == 0;
    }

    static CustomShipSelect* GetInstance()
    {
        return &instance;
    }


private:
    ShipSelect* shipSelect;
    Button* leftButton;
    Button* rightButton;

    std::vector<ShipButton*>* oldShipButtons;

    int shipPage = 0;
    int maxShipPage;
    static CustomShipSelect instance;
};
