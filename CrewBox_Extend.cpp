#include "Global.h"
#include "CrewBox_Extend.h"

HOOK_METHOD_PRIORITY(CrewBox, constructor, 900, (Point pos_, CrewMember *crew_, int number_) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> CrewBox::constructor -> Begin (CrewBox_Extend.cpp)\n")
	super(pos_, crew_, number_);

	auto ex = new CrewBox_Extend();
    uintptr_t dEx = (uintptr_t)ex;

#ifdef __amd64__
    gap_ex_1[2] = (dEx >> 56) & 0xFF;
    gap_ex_1[3] = (dEx >> 48) & 0xFF;
    gap_ex_2[2] = (dEx >> 40) & 0xFF;
    gap_ex_2[3] = (dEx >> 32) & 0xFF;
#endif // __amd64__
	gap_ex_1[0] = (dEx >> 24) & 0xFF;
	gap_ex_1[1] = (dEx >> 16) & 0xFF;
	gap_ex_2[0] = (dEx >> 8) & 0xFF;
	gap_ex_2[1] = dEx & 0xFF;
	ex->orig = this;
}

void CrewBox::DestroyCustom()
{
    delete CBOX_EX(this);
}

HOOK_METHOD(CrewBox, destructor, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewBox::destructor -> Begin (CrewBox_Extend.cpp)\n")
    DestroyCustom();
    super();
}

CrewBox_Extend* Get_CrewBox_Extend(const CrewBox* c)
{
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

    return (CrewBox_Extend*)dEx;
}

void CrewAbilityCooldownBar::OnRender()
{
    bool powerActive = power->temporaryPowerActive;

    std::pair<float, float> &cooldown = powerActive ? power->temporaryPowerDuration : power->powerCooldown;
    int cooldownHeight = (cooldown.first / cooldown.second) * box.h;

    // check if bar has changed since last render
    if (barActive != powerActive || cooldownHeight != lastCooldownHeight)
    {
        CSurface::GL_DestroyPrimitive(prim);
        barActive = powerActive;
        lastCooldownHeight = cooldownHeight;

        if (cooldownHeight > 0)
        {
            GL_Color &barColor = powerActive ? power->def->tempPower.cooldownColor : power->def->cooldownColor;
            prim = CSurface::GL_CreateRectPrimitive(box.x, (box.h - cooldownHeight) + box.y, box.w, cooldownHeight, barColor);
        }
        else
        {
            prim = nullptr;
        }
    }

    if (prim)
    {
        CSurface::GL_RenderPrimitive(prim);
    }
}

void CrewAbilityChargesBar::OnRender()
{
    // check if bar has changed since last render
    if (power->powerCharges.first != charges.first || power->powerCharges.second != charges.second)
    {
        CSurface::GL_DestroyPrimitive(prim);
        charges = power->powerCharges;

        if (charges.first > 0 && charges.second > 0)
        {
            // if height is less than enough for 2 pixel large blocks then render as a continuous bar
            if (charges.second*3-1 > box.h)
            {
                int chargesHeight = std::max(1, box.h * charges.first / charges.second);
                prim = CSurface::GL_CreateRectPrimitive(box.x, (box.h - chargesHeight) + box.y, box.w, chargesHeight, power->def->cooldownColor);
            }
            else
            {
                int chargesGap = 1;
                int chargesMaxHeight = box.h - (chargesGap * (charges.second - 1));

                int segmentHeight = chargesMaxHeight / charges.second;
                int segmentRemainder = chargesMaxHeight % charges.second;

                int y0 = 0;
                int y1 = 0;

                int iMax = std::min(charges.first,charges.second+1); // add a maximum to prevent hangs while still revealing bugs

                std::vector<Globals::Rect> rects;
                rects.reserve(iMax);

                for (int i=0; i<iMax; ++i)
                {
                    y1 = y0 + segmentHeight;
                    if (i < segmentRemainder) y1++;
                    rects.emplace_back(Globals::Rect({box.x, box.y + box.h - y1, box.w, y1 - y0}));
                    y0 = y1 + chargesGap;
                }
                prim = CSurface::GL_CreateMultiRectPrimitive(rects, power->def->cooldownColor);
            }
        }
        else
        {
            prim = nullptr;
        }
    }

    if (prim)
    {
        CSurface::GL_RenderPrimitive(prim);
    }
}
