#include "ProjectileFactory_Extend.h"


HOOK_METHOD_PRIORITY(ProjectileFactory, constructor, 900, (const WeaponBlueprint *bp, int shipId) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> ProjectileFactory::constructor -> Begin (ProjectileFactory_Extend.cpp)\n")


	super(bp, shipId);

	auto ex = new ProjectileFactory_Extend();

    uintptr_t dEx = (uintptr_t)ex;

#ifdef __amd64__
    this->gap_ex_1[2] = (dEx >> 56) & 0xFF;
    this->gap_ex_1[3] = (dEx >> 48) & 0xFF;
    this->gap_ex_2[2] = (dEx >> 40) & 0xFF;
    this->gap_ex_2[3] = (dEx >> 32) & 0xFF;
#endif // __amd64__
	this->gap_ex_1[0] = (dEx >> 24) & 0xFF;
	this->gap_ex_1[1] = (dEx >> 16) & 0xFF;
	this->gap_ex_2[0] = (dEx >> 8) & 0xFF;
	this->gap_ex_2[1] = dEx & 0xFF;
	ex->orig = this;

    HS_MAKE_TABLE(this)

    auto context = G_->getLuaContext();
    SWIG_NewPointerObj(context->GetLua(), this, context->getLibScript()->types.pProjectileFactory, 0);
    context->getLibScript()->call_on_internal_event_callbacks(InternalEvents::CONSTRUCT_PROJECTILE_FACTORY, 1);
    lua_pop(context->GetLua(), 1);
}

HOOK_METHOD(ProjectileFactory, destructor, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ProjectileFactory::destructor -> Begin (ProjectileFactory_Extend.cpp)\n")
    HS_BREAK_TABLE(this)
    delete PF_EX(this);

    return super();
}

ProjectileFactory_Extend* Get_ProjectileFactory_Extend(ProjectileFactory* c)
{
    if (!c) return nullptr;

    uintptr_t dEx = 0;

#ifdef __amd64__
    dEx <<= 8;
    dEx |= c->gap_ex_1[2];
    dEx <<= 8;
    dEx |= c->gap_ex_1[3];
    dEx <<= 8;
    dEx |= c->gap_ex_2[2];
    dEx <<= 8;
    dEx |= c->gap_ex_2[3];
#endif // __amd64__
    dEx <<= 8;
    dEx |= c->gap_ex_1[0];
    dEx <<= 8;
    dEx |= c->gap_ex_1[1];
    dEx <<= 8;
    dEx |= c->gap_ex_2[0];
    dEx <<= 8;
    dEx |= c->gap_ex_2[1];

    return (ProjectileFactory_Extend*)dEx;
}
