#include "CustomCommandGui.h"

CustomCommandGui CustomCommandGui::instance = CustomCommandGui();

static int lastCrewPage = -1;
static int lastCrewCount = -1;
static int lastMindCrewCount = -1;

void CustomCommandGui::OnScrollWheel(float direction)
{
    int crewCount = G_->GetCrewFactory()->GetCrewCount(0);

    if (currentCrewPage > 0 && direction == -1.f)
    {
        currentCrewPage--;
    }
    if (currentCrewPage < maxPage && direction == 1.f)
    {
        currentCrewPage++;
    }
}

void CustomCommandGui::OnInit()
{
    crewDownButton = new Button();
    crewDownButton->OnInit("statusUI/button_crew_down", 39, 140);

    crewUpButton = new Button();
    crewUpButton->OnInit("statusUI/button_crew_up", 55, 140);
}

void CustomCommandGui::MouseMove(int mX, int mY)
{
    int crewCount = G_->GetCrewFactory()->GetCrewCount(0);

    if (maxPage > currentCrewPage)
    {
        crewDownButton->MouseMove(mX, mY, false);

        if (crewDownButton->bHover)
        {
            G_->GetMouseControl()->bForceTooltip = true;
            G_->GetMouseControl()->SetTooltip(G_->GetTextLibrary()->GetText("tooltip_crew_page_down"));
        }
    }

    if (currentCrewPage > 0)
    {
        crewUpButton->MouseMove(mX, mY, false);
        if (crewUpButton->bHover)
        {
            G_->GetMouseControl()->bForceTooltip = true;
            G_->GetMouseControl()->SetTooltip(G_->GetTextLibrary()->GetText("tooltip_crew_page_up"));
        }
    }
}

void CustomCommandGui::LButtonDown(int mX, int mY, bool shiftHeld)
{
    if (crewUpButton->bActive && crewUpButton->bHover)
    {
        currentCrewPage--;
    }
    if (crewDownButton->bActive && crewDownButton->bHover)
    {
        currentCrewPage++;
    }
}


HOOK_METHOD(CrewBox, OnRender, () -> void)
{
    super();
}

HOOK_METHOD(CrewBox, OnRenderSkillLevel, () -> void)
{
    super();
}

HOOK_METHOD(CrewControl, OnRender, () -> void)
{
    super();

    auto gui = CustomCommandGui::GetInstance();

    int crewCount = G_->GetCrewFactory()->GetCrewCount(0);

    int numPages = gui->maxPage;

    gui->crewDownButton->bActive = false;
    gui->crewUpButton->bActive = false;

    if (numPages > gui->currentCrewPage)
    {
        gui->crewDownButton->bActive = true;
        gui->crewDownButton->OnRender();

    }
    if (gui->currentCrewPage > 0)
    {
        gui->crewUpButton->bActive = true;
        gui->crewUpButton->OnRender();
    }
}

HOOK_METHOD(CrewControl, LinkShip, (ShipManager *ship) -> void)
{
    super(ship);
    CustomCommandGui::GetInstance()->currentCrewPage = 0;
}

HOOK_METHOD(CrewControl, UpdateCrewBoxes, () -> void)
{
    auto crewList = std::vector<CrewMember*>();
    auto mindCrewList = std::vector<CrewMember*>();

    G_->GetCrewFactory()->GetCrewPortraitList(&crewList, 0);
    int currentCrewPage = CustomCommandGui::GetInstance()->currentCrewPage;

    CustomCommandGui::GetInstance()->maxPage = std::floor(std::max((int)crewList.size() - 1, 0) / 8.f);

    if (currentCrewPage > CustomCommandGui::GetInstance()->maxPage)
    {
        CustomCommandGui::GetInstance()->currentCrewPage = CustomCommandGui::GetInstance()->maxPage;
    }

    if (shipManager && G_->GetShipManager(0) == shipManager && shipManager->HasAugmentation("MIND_ORDER"))
    {
        for (CrewMember* i : shipManager->vCrewList)
        {
            if (i->iShipId == 1 && i->bMindControlled)
            {
                mindCrewList.push_back(i);
            }
        }
        if (shipManager->current_target)
        {
            for (CrewMember* i : shipManager->current_target->vCrewList)
            {
                if (i->iShipId == 1 && i->bMindControlled)
                {
                    mindCrewList.push_back(i);
                }
            }
        }
    }

    if (lastCrewPage == currentCrewPage && lastCrewCount == crewList.size() && !(crewList.size() > 0 && crewBoxes.size() == 0) && lastMindCrewCount == mindCrewList.size())
    {
        return;
    }


    ClearCrewBoxes();

    int counter = 0;
    int boxY = 155;
    for (CrewMember* i : crewList)
    {
        if (std::floor(counter / 8) == currentCrewPage)
        {
            crewBoxes.push_back(new CrewBox(Point(10, boxY), i, counter % 8));
            boxY += 30;
        }

        counter++;
    }

    counter = crewBoxes.size();

    for (CrewMember* i : mindCrewList)
    {
        crewBoxes.push_back(new CrewBox(Point(10, boxY), i, counter));
        boxY += 30;
        counter++;
    }

    lastCrewPage = currentCrewPage;
    lastCrewCount = crewList.size();
    lastMindCrewCount = mindCrewList.size();
}

HOOK_METHOD(CommandGui, MouseMove, (int mX, int mY) -> void)
{
    super(mX, mY);

    CustomCommandGui::GetInstance()->MouseMove(mX, mY);

}
HOOK_METHOD(CommandGui, LButtonDown, (int mX, int mY, bool shiftHeld) -> void)
{
    super(mX, mY, shiftHeld);

    CustomCommandGui::GetInstance()->LButtonDown(mX, mY, shiftHeld);
}

HOOK_METHOD(CommandGui, constructor, () -> void)
{
    super();
    CustomCommandGui::GetInstance()->gui = this;
}

HOOK_METHOD(CommandGui, OnInit, () -> void)
{
    super();
    CustomCommandGui::GetInstance()->OnInit();
}

HOOK_METHOD(WorldManager, ModifyResources, (LocationEvent *event) -> LocationEvent*)
{
    LocationEvent *ret = super(event);

    commandGui->crewControl.UpdateCrewBoxes();

    return ret;
}
