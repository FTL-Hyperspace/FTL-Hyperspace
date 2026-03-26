#include "CustomCrewManifest.h"
#include "CustomShipSelect.h"
#include "CustomCrew.h"
#include <algorithm>
#include <boost/lexical_cast.hpp>

CustomCrewManifest CustomCrewManifest::instance = CustomCrewManifest();

void CrewMemberFactory::SwapCrewMembers(CrewMember *_first, CrewMember *_second)
{
    unsigned int i,j;
    unsigned int n = crewMembers.size();
    for (i=0; i<n; ++i)
    {
        if (crewMembers[i] == _first)
        {
            j = i;
            break;
        }
        else if (crewMembers[i] == _second)
        {
            j = i;
            _second = _first;
            _first = crewMembers[i];
            break;
        }
    }
    for (++i; i<n; ++i)
    {
        if (crewMembers[i] == _second)
        {
            std::swap(crewMembers[j], crewMembers[i]);
            return;
        }
    }
}
void CrewMemberFactory::MoveCrewMemberToEnd(CrewMember *crew)
{
    for (auto it = crewMembers.end()-1; ; --it)
    {
        if (*it == crew)
        {
            std::rotate(it, it+1, crewMembers.end());
            return;
        }
        if (it == crewMembers.begin()) break;
    }
}

void CrewMemberFactory::MoveCrewMemberBefore(CrewMember *crew, CrewMember *other)
{
    unsigned int i,j;
    unsigned int n = crewMembers.size();
    for (i=0; i<n; ++i)
    {
        if (crewMembers[i] == crew)
        {
            j = i;
            for (++i; i<n; ++i)
            {
                if (crewMembers[i] == other)
                {
                    std::rotate(crewMembers.begin()+j, crewMembers.begin()+j+1, crewMembers.begin()+i);
                    return;
                }
            }
            break;
        }
        else if (crewMembers[i] == other)
        {
            j = i;
            for (++i; i<n; ++i)
            {
                if (crewMembers[i] == crew)
                {
                    std::rotate(crewMembers.rend()-i-1, crewMembers.rend()-i, crewMembers.rend()-j);
                    return;
                }
            }
            break;
        }
    }
}

void CrewMemberFactory::MoveCrewMemberAfter(CrewMember *crew, CrewMember *other)
{
    unsigned int i,j;
    unsigned int n = crewMembers.size();
    for (i=0; i<n; ++i)
    {
        if (crewMembers[i] == crew)
        {
            j = i;
            for (++i; i<n; ++i)
            {
                if (crewMembers[i] == other)
                {
                    std::rotate(crewMembers.begin()+j, crewMembers.begin()+j+1, crewMembers.begin()+i+1);
                    return;
                }
            }
            break;
        }
        else if (crewMembers[i] == other)
        {
            j = i;
            for (++i; i<n; ++i)
            {
                if (crewMembers[i] == crew)
                {
                    std::rotate(crewMembers.rend()-i-1, crewMembers.rend()-i, crewMembers.rend()-j-1);
                    return;
                }
            }
            break;
        }
    }
}

void CrewMemberFactory::MoveCrewMemberToSpot(CrewMember *crew, CrewMember *other)
{
    unsigned int i,j;
    unsigned int n = crewMembers.size();
    for (i=0; i<n; ++i)
    {
        if (crewMembers[i] == crew)
        {
            j = i;
            for (++i; i<n; ++i)
            {
                if (crewMembers[i] == other)
                {
                    std::rotate(crewMembers.begin()+j, crewMembers.begin()+j+1, crewMembers.begin()+i+1);
                    return;
                }
            }
            break;
        }
        else if (crewMembers[i] == other)
        {
            j = i;
            for (++i; i<n; ++i)
            {
                if (crewMembers[i] == crew)
                {
                    std::rotate(crewMembers.rend()-i-1, crewMembers.rend()-i, crewMembers.rend()-j);
                    return;
                }
            }
            break;
        }
    }
}

int CustomCrewManifest::GetEffectiveCrewLimit(ShipManager *ship)
{
    CrewMemberFactory *crewFactory = G_->GetCrewFactory();
    int shipLimit = CustomShipSelect::GetInstance()->GetDefinition(ship->myBlueprint.blueprintName).crewLimit;
    int crewCount = crewFactory->GetCrewCount(0);
    float crewCapacityUsed = crewFactory->GetCrewCapacityUsed();

    if (crewCapacityUsed > shipLimit) // over capacity
    {
        int overSlots = std::ceil(crewCapacityUsed - shipLimit);
        return crewCount - overSlots;
    }
    else
    {
        int usedSlots = crewCapacityUsed + 0.001f; // add 0.001 before rounding down to allow for rounding shenanigans
        return crewCount + shipLimit - usedSlots;
    }
}

void CustomCrewManifest::OnInit(CrewManifest *manifest, ShipManager *ship)
{
    currentPage = 0;
    crewManifest = manifest;

    std::string buttonImg("upgradeUI/Equipment/button_crew_arrow");
    if (!leftButton)
    {
        leftButton = new Button();
        leftButton->OnInit(buttonImg, Point(crewManifest->position.x + 515, crewManifest->position.y + 54));
    }

    if (!rightButton)
    {
        rightButton = new Button();
        rightButton->OnInit(buttonImg, Point(crewManifest->position.x + 550, crewManifest->position.y + 54));

        rightButton->bMirror = true;
    }



    if (crewLimit < 0) crewLimit = GetEffectiveCrewLimit(ship);

    for (auto& page : crewEquipBoxes)
    {
        for (auto& i : page)
        {
            delete i;
        }
    }

    crewEquipBoxes.clear();

    int boxX = crewManifest->position.x + 75;
    int boxY = crewManifest->position.y - 45;

    for (int i = 0; i < crewLimit; i++)
    {
        if (i % 8 == 0)
        {
            boxX = crewManifest->position.x + 75;
            boxY = crewManifest->position.y - 45;
            crewEquipBoxes.push_back(std::vector<CrewEquipBox*>());
        }

        if ((i % 8) % 3 == 0)
        {
            boxX = crewManifest->position.x + 75;
            boxY += 133;
        }

        if (i == crewLimit - ((crewLimit % 8) % 3))
        {
            if (crewLimit == i + 1)
            {
                boxX += 170;
            }
            else if (crewLimit == i + 2)
            {
                boxX += 86;
            }
        }
        else
        {
            if (i % 8 == 6)
            {
                boxX += 86;
            }
        }



        CrewEquipBox* box = new CrewEquipBox(Point(boxX, boxY), ship, i);

        crewEquipBoxes[std::floor(i / 8)].push_back(box);

        boxX += 170;
    }

    delete overCrewBox;
    overCrewBox = new CrewEquipBox(Point(146, crewManifest->position.y + crewManifest->overBox.GetHeight() + crewManifest->overBox.position.y), ship, crewLimit);
}

void CustomCrewManifest::OnRender()
{
    CSurface::GL_PushMatrix();
    if (crewManifest->confirmingDelete >= 0)
    {
        CSurface::GL_SetColorTint(GL_Color(0.25f, 0.25f, 0.25f, 1.0f));
    }


    CSurface::GL_Translate(crewManifest->position.x, crewManifest->position.y);

    CSurface::GL_RenderPrimitive(crewManifest->box);


    TextLibrary* lib = G_->GetTextLibrary();
    freetype::easy_print(10, 25.f, 55.f, lib->GetText("rename_note"));




    if (!overCrewBox->IsEmpty())
    {
        crewManifest->overBox.OnRender();
    }

    CSurface::GL_PopMatrix();
    CSurface::GL_PushMatrix();

    int slot = 0;

    for (CrewEquipBox* i : GetPage(currentPage))
    {
        if (!i->IsEmpty())
        {
            if (crewManifest->confirmingDelete == slot)
            {
                CSurface::GL_RemoveColorTint();
            }
        }

        if (draggingCrewMember != nullptr && i->IsEmpty() && i->bMouseHovering && !i->bGlow)
        {
            i->bGlow = true;
            i->OnRender(draggingCrewMember && draggingCrewMember == i->item.pCrew);
            i->RenderLabels(draggingCrewMember && draggingCrewMember == i->item.pCrew, false);
            i->bGlow = false;
        }
        else
        {
            i->OnRender(draggingCrewMember && draggingCrewMember == i->item.pCrew);
            i->RenderLabels(draggingCrewMember && draggingCrewMember == i->item.pCrew, false);
        }

        if (i->GetConfirmDelete())
        {
            crewManifest->confirmingDelete = slot;

            auto text = TextString();
            text.data = "confirm_dismiss";
            text.isLiteral = false;

            auto noText = TextString();
            noText.data = "";
            noText.isLiteral = true;

            crewManifest->deleteDialog.SetText(text, 300, false, noText, noText);
            crewManifest->deleteDialog.SetPosition(Point(i->location.x - 53, i->location.y + 86));
            crewManifest->deleteDialog.Open();
        }

        if (crewManifest->confirmingDelete == slot)
        {
            CSurface::GL_SetColorTint(GL_Color(0.25f, 0.25f, 0.25f, 1.f));
        }
        slot++;
    }

    if (!overCrewBox->IsEmpty())
    {
        if (crewManifest->confirmingDelete == crewLimit)
        {
            CSurface::GL_RemoveColorTint();
        }

        if (draggingCrewMember != nullptr && overCrewBox->IsEmpty() && overCrewBox->bMouseHovering && !overCrewBox->bGlow)
        {
            overCrewBox->bGlow = true;
            overCrewBox->OnRender(draggingCrewMember && draggingCrewMember == overCrewBox->item.pCrew);
            overCrewBox->RenderLabels(draggingCrewMember && draggingCrewMember == overCrewBox->item.pCrew, false);
            overCrewBox->bGlow = false;
        }
        else
        {
            overCrewBox->OnRender(draggingCrewMember && draggingCrewMember == overCrewBox->item.pCrew);
            overCrewBox->RenderLabels(draggingCrewMember && draggingCrewMember == overCrewBox->item.pCrew, false);
        }


        if (overCrewBox->GetConfirmDelete())
        {
            crewManifest->confirmingDelete = crewLimit;

            auto text = TextString();
            text.data = "confirm_dismiss";
            text.isLiteral = false;

            auto noText = TextString();
            noText.data = "";
            noText.isLiteral = true;

            crewManifest->deleteDialog.SetText(text, 300, false, noText, noText);
            crewManifest->deleteDialog.SetPosition(Point(overCrewBox->location.x - 53, overCrewBox->location.y + 86));
            crewManifest->deleteDialog.Open();
        }

        if (crewManifest->confirmingDelete == crewLimit)
        {
            CSurface::GL_SetColorTint(GL_Color(0.25f, 0.25f, 0.25f, 1.f));
        }
    }

    CSurface::GL_PopMatrix();


    if (crewLimit > 8)
    {
        leftButton->OnRender();
        rightButton->OnRender();
    }

    crewManifest->infoBox.OnRender();

    if (crewManifest->confirmingDelete >= 0)
    {
        CSurface::GL_RemoveColorTint();
        crewManifest->deleteDialog.OnRender();
    }

    if (draggingCrewMember != nullptr)
    {
        MouseControl *mouseControl = G_->GetMouseControl();
        CSurface::GL_PushMatrix();
        CSurface::GL_Translate(mouseControl->position.x, mouseControl->position.y);
        CSurface::GL_Scale(2.f,2.f,0.f);
        draggingCrewMember->crewAnim->RenderIcon(false);
        CSurface::GL_PopMatrix();
    }
}

void CustomCrewManifest::Update()
{
    if (crewManifest->shipManager)
    {
        float newCrewLimit = GetEffectiveCrewLimit(crewManifest->shipManager);
        if (newCrewLimit != crewLimit)
        {
            crewLimit = newCrewLimit;
            OnInit(crewManifest, crewManifest->shipManager);
        }
    }
    else if (crewLimit == -1)
    {
        return;
    }

    std::vector<CrewMember*> crewList = std::vector<CrewMember*>();

    G_->GetCrewFactory()->GetCrewList(&crewList, 0, false);

    crewList.erase(std::remove_if(crewList.begin(), crewList.end(),[](CrewMember* crew)
                                  {
                                      bool noSlot;
                                      CM_EX(crew)->CalculateStat(CrewStat::NO_SLOT, CustomCrewManager::GetInstance()->GetDefinition(crew->species), &noSlot);
                                      return noSlot;
                                  }), crewList.end());

    int slot = 0;

    for (auto i : crewEquipBoxes)
    {
        for (auto box : i)
        {
            box->Restart();

            if (slot < crewList.size())
            {
                EquipmentBoxItem item = EquipmentBoxItem();
                item.pCrew = crewList[slot];

                box->AddItem(item);
                box->bDead = false;
            }

            slot++;
        }
    }

    overCrewBox->Restart();
    if (crewList.size() > crewLimit)
    {
        EquipmentBoxItem item = EquipmentBoxItem();
        item.pCrew = crewList[crewLimit];

        overCrewBox->AddItem(item);
        overCrewBox->bDead = false;
    }
}

void CustomCrewManifest::OnTextInput(SDLKey key)
{
    for (auto i : GetPage(currentPage))
    {
        if (!i->IsEmpty())
        {
            i->OnTextInput(key);
        }
    }

    if (!overCrewBox->IsEmpty())
    {
        overCrewBox->OnTextInput(key);
    }
}

void CustomCrewManifest::OnTextEvent(CEvent::TextEvent event)
{
    for (auto i : GetPage(currentPage))
    {
        if (!i->IsEmpty())
        {
            i->OnTextEvent(event);
        }
    }

    if (!overCrewBox->IsEmpty())
    {
        overCrewBox->OnTextEvent(event);
    }
}

void CustomCrewManifest::Close()
{
    for (auto i : GetPage(currentPage))
    {
        if (!i->IsEmpty())
        {
            i->CloseRename();
        }
    }

    if (!overCrewBox->IsEmpty())
    {
        overCrewBox->CloseRename();
    }

    draggingCrewMember = nullptr;
}

void CustomCrewManifest::OnScrollWheel(float direction)
{
    if (crewLimit > 8)
    {
        if (direction == -1.f)
        {
            if (currentPage == 0)
            {
                currentPage = crewEquipBoxes.size() - 1;
            }
            else
            {
                currentPage--;
            }
        }

        if (direction == 1.f)
        {
            if (currentPage == crewEquipBoxes.size() - 1)
            {
                currentPage = 0;
            }
            else
            {
                currentPage++;
            }
        }
    }

    if (currentPage < 0)
    {
        currentPage = 0;
    }
    if (currentPage > crewEquipBoxes.size() - 1)
    {
        currentPage = crewEquipBoxes.size() - 1;
    }
}

void CustomCrewManifest::MouseClick(int mX, int mY)
{
    if (crewManifest->confirmingDelete < 0)
    {
        for (auto i : GetPage(currentPage))
        {
            i->MouseClick();
            if (i->bMouseHovering && !i->IsEmpty() &&
                (!i->bShowDelete || !i->deleteButton.bActive || !i->deleteButton.bHover) &&
                (!i->bShowRename || !i->renameButton.bActive || !i->renameButton.bHover))
            {
                draggingCrewMember = i->item.pCrew;
            }
        }
        if (!overCrewBox->IsEmpty())
        {
            overCrewBox->MouseClick();
            if (overCrewBox->bMouseHovering &&
                (!overCrewBox->bShowDelete || !overCrewBox->deleteButton.bActive || !overCrewBox->deleteButton.bHover) &&
                (!overCrewBox->bShowRename || !overCrewBox->renameButton.bActive || !overCrewBox->renameButton.bHover))
            {
                draggingCrewMember = overCrewBox->item.pCrew;
            }
        }
    }
    else
    {
        crewManifest->deleteDialog.MouseClick(mX, mY);

        if (!crewManifest->deleteDialog.bOpen)
        {
            if (crewManifest->deleteDialog.result)
            {
                if (crewManifest->confirmingDelete == crewLimit)
                {
                    overCrewBox->RemoveItem();
                }
                else
                {
                    GetPage(currentPage)[crewManifest->confirmingDelete]->RemoveItem();
                }
            }
            crewManifest->confirmingDelete = -1;
        }
    }

    if (crewLimit > 8)
    {
        if (leftButton->bActive && leftButton->bHover)
        {
            if (currentPage == 0)
            {
                currentPage = crewEquipBoxes.size() - 1;
            }
            else
            {
                currentPage--;
            }
        }

        if (rightButton->bActive && rightButton->bHover)
        {
            if (currentPage == crewEquipBoxes.size() - 1)
            {
                currentPage = 0;
            }
            else
            {
                currentPage++;
            }
        }
    }

    if (currentPage < 0)
    {
        currentPage = 0;
    }
    if (currentPage > crewEquipBoxes.size() - 1)
    {
        currentPage = crewEquipBoxes.size() - 1;
    }




    Update();
}

void CustomCrewManifest::MouseUp(int mX, int mY)
{
    CrewEquipBox *targetBox = nullptr;
    if (draggingCrewMember != nullptr)
    {
        for (auto i : GetPage(currentPage))
        {
            if (i->bMouseHovering)
            {
                targetBox = i;
                break;
            }
        }
        if (!overCrewBox->IsEmpty())
        {
            if (overCrewBox->bMouseHovering)
            {
                targetBox = overCrewBox;
            }
        }

        if (targetBox != nullptr)
        {
            CrewMemberFactory *factory = G_->GetCrewFactory();
            CrewControl *crewControl = &G_->GetCApp()->gui->crewControl;
            if (targetBox->IsEmpty())
            {
                factory->MoveCrewMemberToEnd(draggingCrewMember);
            }
            else if (draggingCrewMember != targetBox->item.pCrew)
            {
                factory->SwapCrewMembers(draggingCrewMember, targetBox->item.pCrew);
            }
            crewControl->ClearCrewBoxes();
            crewControl->UpdateCrewBoxes();
            Update();
        }

        draggingCrewMember = nullptr;
    }
}

void CustomCrewManifest::MouseMove(int mX, int mY)
{
    crewManifest->infoBox.Clear();

    if (crewManifest->confirmingDelete >= 0)
    {
        crewManifest->deleteDialog.MouseMove(mX, mY);
    }
    else
    {
        for (auto i : GetPage(currentPage))
        {
            i->MouseMove(mX, mY);

            if (i->bMouseHovering && !i->IsEmpty())
            {
                i->bGlow = true;
                i->SetBlueprint(&crewManifest->infoBox, true);
            }
            else
            {
                i->bGlow = false;
            }
        }

        if (!overCrewBox->IsEmpty())
        {
            overCrewBox->MouseMove(mX, mY);

            if (overCrewBox->bMouseHovering)
            {
                overCrewBox->bGlow = true;
                overCrewBox->SetBlueprint(&crewManifest->infoBox, true);
            }
            else
            {
                overCrewBox->bGlow = false;
            }
        }
    }

    if (crewLimit > 8)
    {
        leftButton->MouseMove(mX, mY, false);
        rightButton->MouseMove(mX, mY, false);
    }
}

HOOK_METHOD(CrewManifest, OnInit, (ShipManager *ship) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewManifest::OnInit -> Begin (CustomCrewManifest.cpp)\n")
    super(ship);
    CustomCrewManifest::GetInstance()->OnInit(this, ship);
}

HOOK_METHOD(CrewManifest, OnRender, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewManifest::OnRender -> Begin (CustomCrewManifest.cpp)\n")
    //super();

    CustomCrewManifest::GetInstance()->OnRender();
}

HOOK_METHOD(CrewManifest, Update, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewManifest::Update -> Begin (CustomCrewManifest.cpp)\n")
    CustomCrewManifest::GetInstance()->Update();
}

HOOK_METHOD(CrewManifest, OnTextInput, (SDLKey key) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewManifest::OnTextInput -> Begin (CustomCrewManifest.cpp)\n")
    CustomCrewManifest::GetInstance()->OnTextInput(key);
}


HOOK_METHOD(CrewManifest, OnTextEvent, (CEvent::TextEvent event) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewManifest::OnTextEvent -> Begin (CustomCrewManifest.cpp)\n")
    CustomCrewManifest::GetInstance()->OnTextEvent(event);
}

HOOK_METHOD(CrewManifest, Close, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewManifest::Close -> Begin (CustomCrewManifest.cpp)\n")
    super();
    CustomCrewManifest::GetInstance()->Close();
}


HOOK_METHOD(CrewManifest, MouseClick, (int mX, int mY) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewManifest::MouseClick -> Begin (CustomCrewManifest.cpp)\n")
    CustomCrewManifest::GetInstance()->MouseClick(mX, mY);
}

HOOK_METHOD(CrewManifest, MouseMove, (int mX, int mY) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewManifest::MouseMove -> Begin (CustomCrewManifest.cpp)\n")
    CustomCrewManifest::GetInstance()->MouseMove(mX, mY);
}

static bool forceNextSlot = false;

HOOK_METHOD(CrewStoreBox, Purchase, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CrewStoreBox::Purchase -> Begin (CustomCrewManifest.cpp)\n")
    forceNextSlot = true;
    super();
    forceNextSlot = false;
}

HOOK_METHOD(ShipManager, AddCrewMemberFromBlueprint, (CrewBlueprint* bp, int slot, bool init, int roomId, bool intruder) -> CrewMember*)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::AddCrewMemberFromBlueprint -> Begin (CustomCrewManifest.cpp)\n")
    if (forceNextSlot)
    {
        slot = -1;
    }

    auto ret = super(bp, slot, init, roomId, intruder);

    return ret;
}

//Allow dismissal of last crew member where appropriate
HOOK_METHOD_PRIORITY(CrewEquipBox, OnRender, 9999, (bool dragging) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> CrewEquipBox::OnRender -> Begin (CustomCrewManifest.cpp)\n")
    int playerCrewCount = G_->GetCrewFactory()->GetPlayerCrewCount();
    bool canDismissLastCrew = ship->bAutomated || CustomCrewManifest::GetInstance()->IsOverCrewBox(this);
    deleteButton.SetActive(playerCrewCount > 1 || canDismissLastCrew);
    if (bQuickRenaming)
    {
        nameInput.OnLoop();
        if (!nameInput.GetActive())
        {
            bQuickRenaming = false;
            nameInput.Stop();
            TextString name(nameInput.GetText(), true);
            item.pCrew->SetName(&name, false);
        }
    }
    if (!IsEmpty() && !dragging && bShowDelete)
    {
        CSurface::GL_RenderPrimitive(bGlow ? box_on : box);
        deleteButton.OnRender();
    }
    EquipmentBox::OnRender(dragging);
}

HOOK_METHOD_PRIORITY(CrewEquipBox, MouseClick, 9999, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> CrewEquipBox::MouseClick -> Begin (CustomCrewManifest.cpp)\n")
    if (!IsEmpty())
    {
        int playerCrewCount = G_->GetCrewFactory()->GetPlayerCrewCount();
        bool canDismissLastCrew = ship->bAutomated || CustomCrewManifest::GetInstance()->IsOverCrewBox(this);
        if (bShowDelete && deleteButton.Hovering() && (playerCrewCount > 1 || canDismissLastCrew))
        {
            bConfirmDelete = true;
        }
        if (bQuickRenaming)
        {
            bQuickRenaming = false;
            nameInput.Stop();
            TextString name(nameInput.GetText(), true);
            item.pCrew->SetName(&name, false);
        }
        else if (renameButton.Hovering())
        {
            bQuickRenaming = true;
            nameInput.Start();
        }
    }
}
