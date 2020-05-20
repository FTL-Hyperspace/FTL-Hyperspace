#ifndef SYS_EX
#include "FTLGame.h"

struct ShipSystem_Extend
{
public:
    ShipSystem *orig;

    void SetTemporaryPowerCap(int cap)
    {
        oldPowerCap = orig->GetPowerCap();
        orig->SetPowerCap(cap);
    }

    void ClearTemporaryPowerCap()
    {
        orig->SetPowerCap(oldPowerCap);
    }

private:
    int oldPowerCap;
};

ShipSystem_Extend* Get_ShipSystem_Extend(ShipSystem* c);

#define SYS_EX Get_ShipSystem_Extend
#endif
