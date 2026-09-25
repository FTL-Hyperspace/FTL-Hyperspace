#include "Global.h"
#include "SystemBox_Extend.h"
#include "CustomOptions.h"


HOOK_METHOD_PRIORITY(CloneBox, OnRender, 9999, (bool ignoreStatus) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> CloneBox::OnRender -> Begin (CloneQueue.cpp)\n")

    std::vector<CrewMember*> cloneQueue;
    G_->GetCrewFactory()->GetCloneReadyList(cloneQueue, cloneSys->_shipObj.iShipId == 0);

    for (CrewMember* crew : cloneQueue)
    {
        /*inline void CrewMember::SetCloneDying(CrewMember* this, float val)*/
        crew->fCloneDying = 0;
    }
    /*inline void CrewMember::SetCloneDying(CrewMember* this, float val)*/
    if (!cloneQueue.empty()) cloneQueue.back()->fCloneDying = cloneSys->GetDeathProgress();
    CooldownSystemBox::OnRender(ignoreStatus);
    if (cloneQueue.empty() || cloneSys->Functioning() || cloneSys->_shipObj.HasEquipment("BACKUP_DNA"))
    {
        dyingCrewWarning->Stop();
    }
    else
    {
        CSurface::GL_PushMatrix();
        CSurface::GL_Translate(0.0, topPower - location.y);
        dyingCrewWarning->Start();
        dyingCrewWarning->OnLoop();
        dyingCrewWarning->OnRender();
        CSurface::GL_PopMatrix();
    }

    int maxPower = cloneSys->powerState.second;
    
    int xOffset = 35;
    int yOffset = std::max(maxPower, 1) * -8;

    Point loc = location + Point(xOffset, yOffset);

    switch (cloneQueue.size())
    {
        case 0: return;
        case 1:
        {
            G_->GetResources()->RenderImage(boxSolo, loc.x - 29, loc.y - 20, 0, GL_Color(1.0, 1.0, 1.0, 1.0), 1.0, false);
            break;
        }
        case 2:
        {
            G_->GetResources()->RenderImage(boxBottom, loc.x - 29, loc.y - 14, 0, GL_Color(1.0, 1.0, 1.0, 1.0), 1.0, false);
            G_->GetResources()->RenderImage(boxTop, loc.x - 29, loc.y - 43, 0, GL_Color(1.0, 1.0, 1.0, 1.0), 1.0, false);
            break;
        }
        case 3:
        default:
        {
            G_->GetResources()->RenderImage(boxBottom, loc.x - 29, loc.y - 14, 0, GL_Color(1.0, 1.0, 1.0, 1.0), 1.0, false);
            G_->GetResources()->RenderImage(boxMiddle, loc.x - 29, loc.y - 37, 0, GL_Color(1.0, 1.0, 1.0, 1.0), 1.0, false);
            G_->GetResources()->RenderImage(boxTop, loc.x - 29, loc.y - 66, 0, GL_Color(1.0, 1.0, 1.0, 1.0), 1.0, false);
            break;
        }
    }

    CloneBox_Extend* extend = static_cast<CloneBox_Extend*>(SB_EX(this));
    if (extend->displayShift > cloneQueue.size() - 3) extend->displayShift = cloneQueue.size() - 3;
    if (CustomOptionsManager::GetInstance()->enhancedCloneUI.currentValue && cloneQueue.size() > 3)
    {
        int xPos = loc.x - 10;
        int yPos = loc.y - 77;

        extend->pageDown.SetLocation(Point(xPos - 7, yPos));
        extend->pageUp.SetLocation(Point(xPos + 7, yPos));

        if (extend->displayShift > 0)
        {
            extend->pageDown.bActive = true;
            extend->pageDown.OnRender();
        }
        else
        {
            extend->pageDown.bActive = false;
        }

        if (extend->displayShift < cloneQueue.size() - 3)
        {
            extend->pageUp.bActive = true;
            extend->pageUp.OnRender();
        }
        else
        {
            extend->pageUp.bActive = false;
        }
    }
    else
    {
        extend->pageDown.bActive = false;
        extend->pageUp.bActive = false;
        extend->displayShift = 0;
    }
    
    loc.x -= 3;
    loc.y -= 1;

    int crewToRender = cloneQueue.size() > 3 ? 3 : cloneQueue.size();
    int yShift = 0;
    for (int crewIdx = extend->displayShift; crewIdx < extend->displayShift + crewToRender; ++crewIdx)
    {
        CSurface::GL_PushMatrix();
        CSurface::GL_Translate(loc.x, loc.y + yShift);
        yShift -= 23;
        CrewMember* crew = cloneQueue[crewIdx];
        if (crewIdx == 0) 
        {   
            int progressRender = cloneSys->GetProgress() * 20.0;
            CSurface::GL_BlitImagePartial(boxFill, -17.0, (10 - progressRender), 34.0, progressRender, 0.0, 1.0, (20.0 - progressRender) / 20.0,1.0,1.0, GL_Color(0.0, 1.0, 0.0, 1.0), false);
        }
       
        if (crewIdx < cloneQueue.size() - 1 && crewIdx - extend->displayShift == 2)
        {
            CSurface::GL_SetColor(COLOR_WHITE);
            freetype::easy_printCenter(10, 0.0, -7.0, "+" + std::to_string(cloneQueue.size() - 2));
        }
        else if (crew != extend->selectedCrew)
        {
            CSurface::GL_PushMatrix();
            CSurface::GL_Translate(1.0, 2.0);
            /*inline void CrewMember::RenderIcon(CrewMember* this, bool border)*/
            crew->crewAnim->RenderIcon(false);
            CSurface::GL_PopMatrix();     
        }

        if (crewIdx == extend->displayShift + crewToRender - 1 && 0 < cloneSys->GetDeathProgress()) 
        {
            float deathProgressRender = cloneSys->GetDeathProgress() * 20.0;
            CSurface::GL_BlitImagePartial(boxFill, -17.0, -10.0, 34.0, deathProgressRender, 0.0, 1.0, 0.0, deathProgressRender / 20.0, 1.0, GL_Color(1.0, 0.3, 0.3, 1.0), false);
        }
        CSurface::GL_PopMatrix();
    }

    if (extend->selectedCrew != nullptr)
    {
        CSurface::GL_PushMatrix();
        CSurface::GL_LoadIdentity();
        MouseControl* mouseControl = G_->GetMouseControl();
        Point offset(-10, -10);
        G_->GetResources()->RenderImage(boxSolo, mouseControl->position.x + offset.x, mouseControl->position.y + offset.y, 0, GL_Color(1.0, 1.0, 1.0, 1.0), 1.0, false);
        
        CSurface::GL_Translate(mouseControl->position.x + 27 + offset.x, mouseControl->position.y + 21 + offset.y);
        /*inline void CrewMember::RenderIcon(CrewMember* this, bool border)*/
        extend->selectedCrew->crewAnim->RenderIcon(false);
        CSurface::GL_PopMatrix();
    }
}

HOOK_METHOD(CloneBox, constructor, (Point pos, CloneSystem* sys) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CloneBox::constructor -> Begin (CloneQueue.cpp)\n")
    super(pos, sys);
    CloneBox_Extend* extend = static_cast<CloneBox_Extend*>(SB_EX(this));

    extend->pageDown.OnInit("statusUI/button_crew_down", Point(0, 0));
    extend->pageUp.OnInit("statusUI/button_crew_up", Point(0, 0));
}

HOOK_METHOD(SystemBox, MouseMove, (int x, int y) -> void)
{
    LOG_HOOK("HOOK_METHOD -> SystemBox::MouseMove -> Begin (CloneQueue.cpp)\n")
    super(x, y);
   
    CloneBox_Extend* extend = dynamic_cast<CloneBox_Extend*>(SB_EX(this));
    if (extend && CustomOptionsManager::GetInstance()->enhancedCloneUI.currentValue)
    {
        int maxPower = pSystem->powerState.second;

        Point bottomLeft = location + Point(15, (std::max(maxPower, 1) - 1) * -8);
        Point bottomRight = bottomLeft + Point(34, 0);


        std::vector<CrewMember*> cloneQueue;
        G_->GetCrewFactory()->GetCloneReadyList(cloneQueue, pSystem->_shipObj.iShipId == 0);
        int crewToRender = cloneQueue.size() > 3 ? 3 : cloneQueue.size();

        int newCrewIdx;
        int boxIdx = (bottomLeft.y - y + 12) / 23;
        if (boxIdx < 0) newCrewIdx = extend->displayShift;
        else if (boxIdx > crewToRender) newCrewIdx = extend->displayShift + crewToRender - 1;
        else newCrewIdx = extend->displayShift + boxIdx;

        CrewMember* lastCloningCrew = nullptr;
        if (!cloneQueue.empty()) lastCloningCrew = cloneQueue[0];
        

        if (extend->selectedCrew != nullptr)
        {
            for (int idx = 0; idx < cloneQueue.size(); ++idx)
            {
                cloneQueue[idx]->iDeathNumber = idx;
            }
            extend->selectedCrew->iDeathNumber = newCrewIdx;
            for (int idx = newCrewIdx; idx < cloneQueue.size(); ++idx)
            {
                if (cloneQueue[idx] != extend->selectedCrew)
                {
                    cloneQueue[idx]->iDeathNumber++;
                }
            }
        }
        //If the currently cloning crew is different, reset clone prgoress
        std::vector<CrewMember*> cloneQueueNew;
        G_->GetCrewFactory()->GetCloneReadyList(cloneQueueNew, pSystem->_shipObj.iShipId == 0);
        CrewMember* newCloningCrew = nullptr;
        if (!cloneQueueNew.empty()) newCloningCrew = cloneQueueNew[0];
        if (lastCloningCrew != newCloningCrew)
        {
            CloneSystem* cloneSys = static_cast<CloneSystem*>(pSystem);
            cloneSys->fTimeToClone = 0;  
        }
        

        if (x >= bottomLeft.x && x <= bottomRight.x && y <= bottomLeft.y)
        {
            int crewIdxOffset = (bottomLeft.y - y) / 23;
            if (crewIdxOffset >= crewToRender)
            {
                extend->hoverCrew = -1;
            }
            //Hovering over +N crew box
            else if (crewIdxOffset == 2 && extend->displayShift + 3 < cloneQueue.size())
            {
                extend->hoverCrew = -1;
            }
            else
            {
                extend->hoverCrew = extend->displayShift + crewIdxOffset;
            }
        }
        else
        {
            extend->hoverCrew = -1;
        }

        extend->pageDown.MouseMove(x, y, false);
        extend->pageUp.MouseMove(x, y, false);
    }
    
}

HOOK_METHOD(SystemBox, MouseClick, (bool shift) -> bool)
{
    LOG_HOOK("HOOK_METHOD -> SystemBox::MouseClick -> Begin (CloneQueue.cpp)\n")
    bool ret = super(shift);
    CloneBox_Extend* extend = dynamic_cast<CloneBox_Extend*>(SB_EX(this));
    if (extend && CustomOptionsManager::GetInstance()->enhancedCloneUI.currentValue)
    {
        if (extend->pageDown.Hovering()) extend->displayShift -= 1;
        if (extend->pageUp.Hovering()) extend->displayShift += 1;
    }

    return ret;
}

HOOK_METHOD(SystemBox, MouseRightClick, (bool force) -> void)
{
    LOG_HOOK("HOOK_METHOD -> SystemBox::MouseRightClick -> Begin (CloneQueue.cpp)\n")
    super(force);
    CloneBox_Extend* extend = dynamic_cast<CloneBox_Extend*>(SB_EX(this));
    if (extend && CustomOptionsManager::GetInstance()->enhancedCloneUI.currentValue)
    {
        if (extend->selectedCrew == nullptr && extend->hoverCrew != -1)
        {
            std::vector<CrewMember*> cloneQueue;
            G_->GetCrewFactory()->GetCloneReadyList(cloneQueue, pSystem->_shipObj.iShipId == 0);
            extend->selectedCrew = cloneQueue[extend->hoverCrew];
        }
    }
}


void CloneBox_Extend::OnScrollWheel(float direction)
{
    SystemBox_Extend::OnScrollWheel(direction);
    
    std::vector<CrewMember*> cloneQueue;
    G_->GetCrewFactory()->GetCloneReadyList(cloneQueue, orig->pSystem->_shipObj.iShipId == 0);

    if (CustomOptionsManager::GetInstance()->enhancedCloneUI.currentValue)
    {
        if (direction == 1.f && displayShift > 0)
        {
            displayShift -= 1;
        }
        else if (direction == -1.f && displayShift < cloneQueue.size() - 3)
        {
            displayShift += 1;
        }

    }
}

void CloneBox_Extend::RButtonUp(int mX, int mY, bool shiftHeld)
{
    SystemBox_Extend::RButtonUp(mX, mY, shiftHeld);
    selectedCrew = nullptr;
}

HOOK_METHOD(CrewMember, Clone, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewMember::Clone -> Begin (CloneQueue.cpp)\n")
    super();
    SystemBox* sys_box = G_->GetCApp()->gui->sysControl.GetSystemBox(SYS_CLONEBAY);
    if (sys_box != nullptr)
    {
        CloneBox_Extend* extend = static_cast<CloneBox_Extend*>(SB_EX(sys_box));
        if (extend->selectedCrew == this)
        {
            extend->selectedCrew = nullptr;
        }
    }
}

HOOK_METHOD(CloneBox, GetHeightModifier, () -> int)
{
    LOG_HOOK("HOOK_METHOD -> CloneBox::GetHeightModifier -> Begin (CloneQueue.cpp)\n")
    int ret = super();
    if (G_->GetCrewFactory()->CountCloneReadyCrew(pSystem->_shipObj.iShipId == 0) > 3 && CustomOptionsManager::GetInstance()->enhancedCloneUI.currentValue)
    {
        ret += 15;
    }
    return ret;
}
