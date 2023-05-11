#include "Global.h"


LaserBlast::LaserBlast(Pointf _position, int _ownerId, int _targetId, Pointf _target)
{
    this->constructor(_position, _ownerId, _targetId, _target);
    *(void**)this = VTable_LaserBlast;
    *(void**)(&this->_targetable) = VTable_Targetable_LaserBlast;
    this->movingTarget = nullptr;
    this->spinAngle = 0;
    this->spinSpeed = 0;
}

HOOK_METHOD(Projectile, ForceRenderLayer, () -> int)
{
    LOG_HOOK("HOOK_METHOD -> Projectile::ForceRenderLayer -> Begin (ProjectileVTable.cpp)\n")
    return damage.crystalShard ? 1 : -1;
}
