#include "Global.h"

LaserBlast::LaserBlast(Pointf _position, int _ownerId, int _targetId, Pointf _target)
{
    this->constructor(_position, _ownerId, _targetId, _target);
    this->vptr = G_->GetVTable_LaserBlast();
    this->movingTarget = nullptr;
    this->spinAngle = 0;
    this->spinSpeed = 0;
}
