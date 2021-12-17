#include "Global.h"

/*
HOOK_METHOD(ShipManager, AddInitialCrew, (std::vector<CrewBlueprint>& blueprints) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::AddInitialCrew -> Begin (Captain.cpp)\n")
    super(blueprints);

    if (this->iShipId == 0)
    {
        auto ex = SM_EX(this);
        auto cap = this->vCrewList.front();

        if (cap)
        {
            auto c_ex = CM_EX(cap);
            c_ex->isCaptain = true;
            ex->captain = cap;
        }
    }


}

HOOK_METHOD(CrewMember, OnRender, (bool unk) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewMember::OnRender -> Begin (Captain.cpp)\n")
    super(unk);

    if (CM_EX(this)->isCaptain)
    {
        auto graph = ShipGraph::GetShipInfo(this->currentShipId);

        Pointf point = graph->ConvertToWorldPosition(Pointf(this->x, this->y));
        Pointf* pointptr = &point;

        CSurface::GL_SetColor(1.f, 1.f, 0.f, 1.f);

        std::string str("C");
        freetype::easy_printCenter(0, this->x, this->y - 30.f, str);
    }
}

HOOK_METHOD(ShipManager, GetDodgeFactor, () -> int)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::GetDodgeFactor -> Begin (Captain.cpp)\n")
    int ret = super();

    for (auto const& x: this->vCrewList)
    {
        if (CM_EX(x)->isCaptain)
        {
            if (x->iManningId == SystemId::PILOT && x->bActiveManning)
            {
                ret += 10;
            }
        }
    }

    return ret;
}
*/
