#include "CustomUpgrades.h"
#include "CustomShipSelect.h"

CustomUpgrades CustomUpgrades::instance = CustomUpgrades();

void CustomUpgrades::OnInit(Upgrades *upgrades, ShipManager *ship)
{
    currentPage = 0;
    orig = upgrades;

    delete leftButton;
    delete rightButton;

    std::string buttonImg("upgradeUI/buttons_system_arrow");
    leftButton = new Button();
    leftButton->OnInit(buttonImg, upgrades->position.x + 18, upgrades->position.y + 182);

    rightButton = new Button();
    rightButton->OnInit(buttonImg, upgrades->position.x + 572, upgrades->position.y + 182);

    rightButton->bMirror = true;

    systemUpgradeBoxes.clear();
    systemUpgradeBoxes.push_back(std::vector<UpgradeBox*>());
}

void CustomUpgrades::OnRender()
{
    for (auto i : systemUpgradeBoxes[currentPage])
    {
        i->OnRender();
    }

    if (GetNumPages() > 1)
    {
        leftButton->OnRender();
        rightButton->OnRender();
    }
}

void CustomUpgrades::MouseMove(int mX, int mY)
{
    for (auto i : systemUpgradeBoxes[currentPage])
    {
        i->MouseMove(mX, mY);
    }

    if (GetNumPages() > 1)
    {
        leftButton->MouseMove(mX, mY, false);
        rightButton->MouseMove(mX, mY, false);
    }
}

void CustomUpgrades::OnLoop()
{
    for (auto i : systemUpgradeBoxes[currentPage])
    {
        if (i->system != nullptr)
        {
            ShipSystem* system = i->system;
            int maxPower = system->powerState.second;
            int maxLevel = system->maxLevel;
            int currUpgrade = maxPower + i->tempUpgrade;

            if (currUpgrade == maxLevel && i->tempUpgrade > 0)
            {
                i->currentButton = &i->maxButton;
            }
            else
            {
                i->currentButton = &i->boxButton;
                i->boxButton.SetActive(maxPower != maxLevel);
            }

            if (i->currentButton != nullptr && (i->currentButton->bHover || i->currentButton->bSelected))
            {
                orig->infoBox.SetSystem(i->system, i->tempUpgrade, 0, orig->forceSystemInfoWidth);
            }
        }
    }

    bool undoActive = orig->reactorButton.tempUpgrade > 0;

    for (auto page : systemUpgradeBoxes)
    {
        for (auto i : page)
        {
            undoActive = undoActive || i->tempUpgrade > 0;
        }
    }

    orig->undoButton.SetActive(undoActive);
}

void CustomUpgrades::MouseClick(int mX, int mY)
{
    for (auto i : systemUpgradeBoxes[currentPage])
    {
        i->MouseClick(mX, mY);
    }

    if (orig->undoButton.bActive && orig->undoButton.bHover)
    {
        for (auto page : systemUpgradeBoxes)
        {
            for (auto i : page)
            {
                i->Undo();
            }
        }
    }

    int pages = GetNumPages();
    if (pages > 1)
    {
        if (leftButton->bActive && leftButton->bHover)
        {
            currentPage--;
            if (currentPage < 0)
            {
                currentPage = pages - 1;
            }
        }

        if (rightButton->bActive && rightButton->bHover)
        {
            currentPage++;
            if (currentPage >= pages)
            {
                currentPage = 0;
            }
        }
    }
}

void CustomUpgrades::MouseRightClick(int mX, int mY)
{
    for (auto i : systemUpgradeBoxes[currentPage])
    {
        i->MouseRightClick(mX, mY);
    }
}

void CustomUpgrades::Close()
{
    if (orig->bOpen)
    {
        for (auto page : systemUpgradeBoxes)
        {
            for (auto i : page)
            {
                i->Accept();
            }
        }

        for (auto i : orig->vUpgradeBoxes)
        {
            i->Accept();
        }

        orig->reactorButton.Accept();
        orig->bOpen = false;
        G_->GetEventSystem()->AddEvent(13);
    }
}

void CustomUpgrades::ConfirmUpgrades()
{
    for (auto page : systemUpgradeBoxes)
    {
        for (auto i : page)
        {
            i->Accept();
        }
    }
}

void CustomUpgrades::AddSystemBox(UpgradeBox* box)
{
    if (systemUpgradeBoxes[systemUpgradeBoxes.size() - 1].size() == 8)
    {
        systemUpgradeBoxes.push_back(std::vector<UpgradeBox*>());
    }

    systemUpgradeBoxes[systemUpgradeBoxes.size() - 1].push_back(box);
}

/*
WHY is this crashing I don't understand it's literally doing the same thing the game does
but no it has to crash on a function unrelated to it for some bizarre reason

Fixed
*/

void AddUpgradeBox(Upgrades *upgrades, ShipSystem *sys, int& systemXPos, int& subsystemXPos, int& numSystems, int& numSubsystems)
{
    auto custom = CustomUpgrades::GetInstance();

    int yPos = upgrades->position.y + 115;
    bool isSubsystem = !sys->bNeedsPower;

    if (isSubsystem)
    {
        subsystemXPos += 66;
        yPos = upgrades->position.y + 330;
        numSubsystems++;
    }
    else
    {
        systemXPos += 66;
        numSystems++;
    }

    auto box = new UpgradeBox(upgrades->shipManager, sys, Point(isSubsystem ? subsystemXPos : systemXPos, yPos), isSubsystem);

    if (!isSubsystem)
    {
        custom->AddSystemBox(box);
        if (numSystems % 8 == 0)
        {
            systemXPos = upgrades->position.x - 27;
        }
    }
    else
    {
        upgrades->vUpgradeBoxes.push_back(box);
    }

    upgrades->systemCount++;
}

void AddEmptyUpgradeBox(Upgrades *upgrades, bool isSubsystem, int& systemXPos, int& subsystemXPos, int& numSystems, int& numSubsystems)
{
    auto custom = CustomUpgrades::GetInstance();

    int yPos = upgrades->position.y + 115;

    if (isSubsystem)
    {
        subsystemXPos += 66;
        yPos = upgrades->position.y + 330;
        numSubsystems++;
    }
    else
    {
        systemXPos += 66;
        numSystems++;
    }

    auto box = new UpgradeBox(Point(isSubsystem ? subsystemXPos : systemXPos, yPos), isSubsystem);

    if (!isSubsystem)
    {
        custom->AddSystemBox(box);
        if (numSystems % 8 == 0)
        {
            systemXPos = upgrades->position.x - 27;
        }
    }
    else
    {
        upgrades->vUpgradeBoxes.push_back(box);
    }
}


HOOK_METHOD(Upgrades, OnInit, (ShipManager *ship) -> void)
{
    LOG_HOOK("HOOK_METHOD -> Upgrades::OnInit -> Begin (CustomUpgrades.cpp)\n")
    bFullFocus = true;
    shipManager = ship;
    infoBoxLoc = Point(position.x + 600, position.y);
    infoBox.location = infoBoxLoc;

    TextString buttonLabel = TextString();
    buttonLabel.isLiteral = false;
    buttonLabel.data = "button_undo";

    undoButton.OnInit(position.x + 33, position.y + 471, 97, 32, 4, &buttonLabel, 63);
    undoButton.SetBaseImage("upgradeUI/buttons_undo_base.png", Point(-23, -7), 97);
    undoButton.SetAutoWidth(true, false, 3, 0);

    reactorButton.OnInit("upgradeUI/Equipment/equipment_reactor", position.x + 305, position.y + 327);
    reactorButton.allowAnyTouch = true;
    reactorButton.touchSelectable = true;
    reactorButton.ship = ship;

    box = G_->GetResources()->GetImageId("upgradeUI/Equipment/upgrades_main.png");

    int sysLimit = CustomShipSelect::GetInstance()->GetDefaultDefinition().systemLimit;

    if (CustomShipSelect::GetInstance()->HasCustomDef(ship->myBlueprint.blueprintName))
    {
        sysLimit = CustomShipSelect::GetInstance()->GetDefinition(ship->myBlueprint.blueprintName).systemLimit;
    }

    int subsystemLimit = CustomShipSelect::GetInstance()->GetDefaultDefinition().subsystemLimit;

    if (CustomShipSelect::GetInstance()->HasCustomDef(ship->myBlueprint.blueprintName))
    {
        subsystemLimit = CustomShipSelect::GetInstance()->GetDefinition(ship->myBlueprint.blueprintName).subsystemLimit;
    }


    ClearUpgradeBoxes();

    std::vector<int> systemOrder = { 0, 1, 5, 13, 2, 3, 4, 6, 7, 8, 9, 10, 11, 12, 14, 15, 20 };

    int systemXPos = position.x - 27;
    int subsystemXPos = position.x - 50;

    int numSystems = 0;
    int numSubsystems = 0;

    auto custom = CustomUpgrades::GetInstance();

    custom->OnInit(this, ship);

    systemCount = 0;
    int currPage = 0;

    for (auto i : systemOrder)
    {
        if (i == SYS_ARTILLERY)
        {
            for (auto sys : ship->artillerySystems)
            {
                AddUpgradeBox(this, sys, systemXPos, subsystemXPos, numSystems, numSubsystems);
            }
        }
        else
        {
            auto sys = ship->GetSystem(i);
            if (sys)
            {
                AddUpgradeBox(this, sys, systemXPos, subsystemXPos, numSystems, numSubsystems);
            }
        }
    }

    for (int i = numSystems; i < sysLimit; i++)
    {
        AddEmptyUpgradeBox(this, false, systemXPos, subsystemXPos, numSystems, numSubsystems);
    }
    for (int i = numSubsystems; i < subsystemLimit; i++)
    {
        AddEmptyUpgradeBox(this, true, systemXPos, subsystemXPos, numSystems, numSubsystems);
    }
}

HOOK_METHOD(Upgrades, MouseMove, (int mX, int mY) -> void)
{
    LOG_HOOK("HOOK_METHOD -> Upgrades::MouseMove -> Begin (CustomUpgrades.cpp)\n")
    super(mX, mY);

    CustomUpgrades::GetInstance()->MouseMove(mX, mY);
}

HOOK_METHOD(Upgrades, OnRender, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> Upgrades::OnRender -> Begin (CustomUpgrades.cpp)\n")
    super();

    CustomUpgrades::GetInstance()->OnRender();
}

HOOK_METHOD(Upgrades, OnLoop, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> Upgrades::OnLoop -> Begin (CustomUpgrades.cpp)\n")
    super();

    CustomUpgrades::GetInstance()->OnLoop();
}

HOOK_METHOD(Upgrades, MouseClick, (int mX, int mY) -> void)
{
    LOG_HOOK("HOOK_METHOD -> Upgrades::MouseClick -> Begin (CustomUpgrades.cpp)\n")
    super(mX, mY);

    CustomUpgrades::GetInstance()->MouseClick(mX, mY);
}

HOOK_METHOD(Upgrades, MouseRightClick, (int mX, int mY) -> void)
{
    LOG_HOOK("HOOK_METHOD -> Upgrades::MouseRightClick -> Begin (CustomUpgrades.cpp)\n")
    super(mX, mY);

    CustomUpgrades::GetInstance()->MouseRightClick(mX, mY);
}

HOOK_METHOD(Upgrades, Close, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> Upgrades::Close -> Begin (CustomUpgrades.cpp)\n")
    CustomUpgrades::GetInstance()->Close();
}

HOOK_METHOD(Upgrades, ConfirmUpgrades, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> Upgrades::ConfirmUpgrades -> Begin (CustomUpgrades.cpp)\n")
    super();

    CustomUpgrades::GetInstance()->ConfirmUpgrades();
}

