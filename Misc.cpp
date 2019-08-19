#include "Global.h"
#include "ASMHooks.h"

HOOK_METHOD(CrewEquipBox, RemoveItem, () -> int)
{
    int ret = super();
    std::string soundName("airLoss");
    G_->GetSoundControl()->PlaySoundMix(soundName, -1.f, false);
    return ret;
}
