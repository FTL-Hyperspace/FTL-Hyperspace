#include "CustomCommandGui.h"

CustomCommandGui CustomCommandGui::instance = CustomCommandGui();

static int lastCrewPage = -1;
static int lastCrewCount = -1;

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

HOOK_METHOD(CrewControl, RButton, (int mX, int mY, bool shiftHeld) -> void)
{
    super(mX, mY, shiftHeld);
    for (auto box : crewBoxes)
    {
        if (mX > box->box.x && mY > box->box.y && mX < box->box.x + box->box.w && mY < box->box.y + box->box.h)
        {
            CustomCommandGui::GetInstance()->draggingCrewMember = box->pCrew;
        }
    }
}

HOOK_METHOD(CrewControl, MouseMove, (int mX, int mY, int wX, int wY) -> void)
{
    super(mX, mY, wX, wY);

    CrewMember *draggingCrewMember = CustomCommandGui::GetInstance()->draggingCrewMember;

    if (draggingCrewMember != nullptr && !crewBoxes.empty())
    {
        int index = (mY-155)/30;
        int draggingIndex = 9999;
        if (index < 0) index = 0;
        if (index >= crewBoxes.size()) index = crewBoxes.size()-1;
        if (crewBoxes[index]->pCrew == draggingCrewMember) return;
        G_->GetCrewFactory()->MoveCrewMemberToSpot(draggingCrewMember,crewBoxes[index]->pCrew);

        ClearCrewBoxes();
        UpdateCrewBoxes();
    }
}

void CustomCommandGui::RButtonUp(int mX, int mY, bool shiftHeld)
{
    draggingCrewMember = nullptr;
}

HOOK_METHOD(CApp, OnRButtonUp, (int x, int y) -> void)
{
    if (!langChooser.bOpen && !menu.bOpen)
    {
        Point pos = Point((int)((x - x_bar)*mouseModifier_x) - modifier_x, (int)((y - y_bar)*mouseModifier_y) - modifier_y);
        CustomCommandGui::GetInstance()->RButtonUp(pos.x, pos.y, shift_held);
    }
}

HOOK_METHOD(CrewBox, OnRender, () -> void)
{
    if (CustomCommandGui::GetInstance()->draggingCrewMember == pCrew)
    {
        MouseControl *mouseControl = G_->GetMouseControl();
        CSurface::GL_PushMatrix();
        CSurface::GL_Translate(mouseControl->position.x - box.x - box.w/2, mouseControl->position.y - box.y - box.h/2);
        mouseHover = false;
        super();
        CSurface::GL_PopMatrix();
    }
    else
    {
        super();
    }
}

HOOK_METHOD(CrewBox, RenderIcon, () -> void)
{
    if (CustomCommandGui::GetInstance()->draggingCrewMember == pCrew)
    {
        MouseControl *mouseControl = G_->GetMouseControl();
        CSurface::GL_PushMatrix();
        CSurface::GL_Translate(mouseControl->position.x - box.x - box.w/2, mouseControl->position.y - box.y - box.h/2);
        mouseHover = false;
        super();
        CSurface::GL_PopMatrix();
    }
    else
    {
        super();
    }
}

HOOK_METHOD(CrewBox, RenderLabels, () -> void)
{
    if (CustomCommandGui::GetInstance()->draggingCrewMember == pCrew)
    {
        MouseControl *mouseControl = G_->GetMouseControl();
        CSurface::GL_PushMatrix();
        CSurface::GL_Translate(mouseControl->position.x - box.x - box.w/2, mouseControl->position.y - box.y - box.h/2);
        mouseHover = false;
        super();
        CSurface::GL_PopMatrix();
    }
    else
    {
        super();
    }
}

HOOK_METHOD(CrewBox, RenderCloneDying, () -> void)
{
    if (CustomCommandGui::GetInstance()->draggingCrewMember == pCrew)
    {
        MouseControl *mouseControl = G_->GetMouseControl();
        CSurface::GL_PushMatrix();
        CSurface::GL_Translate(mouseControl->position.x - box.x - box.w/2, mouseControl->position.y - box.y - box.h/2);
        mouseHover = false;
        super();
        CSurface::GL_PopMatrix();
    }
    else
    {
        super();
    }
}

HOOK_METHOD(CrewBox, OnRenderSkillLevel, () -> void)
{
    if (CustomCommandGui::GetInstance()->draggingCrewMember == pCrew)
    {
        MouseControl *mouseControl = G_->GetMouseControl();
        CSurface::GL_PushMatrix();
        CSurface::GL_Translate(mouseControl->position.x - box.x - box.w/2, mouseControl->position.y - box.y - box.h/2);
        mouseHover = false;
        super();
        CSurface::GL_PopMatrix();
    }
    else
    {
        super();
    }
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
    static std::vector<CrewMember*> crewList = std::vector<CrewMember*>();

    crewList.clear();

    CrewMemberFactory *factory = G_->GetCrewFactory();

    bool hasMindOrder = shipManager && G_->GetShipManager(0) == shipManager && shipManager->HasAugmentation("MIND_ORDER");
    bool hasMindCrew = false;

    for (auto crew : factory->crewMembers)
    {
        if (crew->CountForVictory())
        {
            if (crew->iShipId == 0)
            {
                crewList.push_back(crew);
            }
            else if (crew->bMindControlled && hasMindOrder)
            {
                crewList.push_back(crew);
                hasMindCrew = true;
            }
        }
    }

    int currentCrewPage = CustomCommandGui::GetInstance()->currentCrewPage;

    int maxCrewBoxes = 8;

    CustomCommandGui::GetInstance()->maxPage = ((int)crewList.size() - 1) / 8; // always rounds towards 0
    if (hasMindCrew && crewList.size() <= 9)
    {
        CustomCommandGui::GetInstance()->maxPage = 0;
        maxCrewBoxes = 9;
    }

    if (currentCrewPage > CustomCommandGui::GetInstance()->maxPage)
    {
        currentCrewPage = CustomCommandGui::GetInstance()->maxPage;
    }

    if (lastCrewPage == currentCrewPage && lastCrewCount == crewList.size() && !(crewList.size() > 0 && crewBoxes.size() == 0))
    {
        return;
    }

    CustomCommandGui::GetInstance()->currentCrewPage = currentCrewPage;
    ClearCrewBoxes();

    int counter = 0;
    int boxY = 155;
    for (auto it = crewList.begin() + (8*currentCrewPage); it != crewList.end(); ++it)
    {
        crewBoxes.push_back(new CrewBox(Point(10, boxY), *it, counter++));
        if (counter ==  maxCrewBoxes) break;
        boxY += 30;
    }

    lastCrewPage = currentCrewPage;
    lastCrewCount = crewList.size();
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
