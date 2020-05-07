#include "Global.h"




class ShipEditor
{
public:
    static ShipEditor* GetInstance()
    {
        return &instance;
    }

    bool enabled = true;

private:
    static ShipEditor instance;
};
