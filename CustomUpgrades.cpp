#include "CustomSystems.h"
#include "CustomUpgrades.h"
#include "CustomShipSelect.h"
#include <boost/lexical_cast.hpp>

CustomUpgrades CustomUpgrades::instance = CustomUpgrades();
bool blockShipNameRendering = false;

void CustomUpgrades::OnInit(Upgrades *upgrades, ShipManager *ship)
{
    currentPage = 0;
    orig = upgrades;

    delete leftButton;
    delete rightButton;

    std::string buttonImg("upgradeUI/buttons_system_arrow");
    leftButton = new Button();
    leftButton->OnInit(buttonImg, Point(upgrades->position.x + 18, upgrades->position.y + 182));

    rightButton = new Button();
    rightButton->OnInit(buttonImg, Point(upgrades->position.x + 572, upgrades->position.y + 182));

    rightButton->bMirror = true;

    systemUpgradeBoxes.clear();
    systemUpgradeBoxes.push_back(std::vector<UpgradeBox*>());

    if (allowRename)
    {
        if (allowButton)
        {
            delete renameButton;

            renameButton = new Button();
            renameButton->OnInit("upgradeUI/buttons_system_rename", Point(upgrades->position.x + 477, upgrades->position.y + 46));
        }

        TextString *shipName = &G_->GetShipManager(0)->myBlueprint.name;
        if (shipName->isLiteral == false)
        {
            shipName->data = shipName->GetText();
            shipName->isLiteral = true;
        }

        delete renameInput;

        renameInput = new TextInput(16, TextInput::AllowedCharType::ALLOW_ANY, "");
        renameInput->bActive = false;
        renameInput->SetText(shipName->data);
    }
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

    // Draw the ship name
    Point pos = Point(orig->position.x + 310, orig->position.y + 39);
    CSurface::GL_SetColor(COLOR_WHITE);
    if (allowRename) 
    {
        if (allowButton) renameButton->OnRender();
        renameInput->OnRender(24, pos);
        renameInput->OnLoop();
    }
    else
    {
        freetype::easy_printCenter(24, pos.x, pos.y, G_->GetShipManager(0)->myBlueprint.name.data);
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

    if (allowRename && allowButton)
        renameButton->MouseMove(mX, mY, false);
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
    if (allowRename)
        G_->GetMouseControl()->bHideMouse = renameInput->GetActive();
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
    if (allowRename)
    {
        if (((
            !allowButton &&
            mX > orig->position.x + 155 && mX < orig->position.x + 465 && 
            mY > orig->position.y + 46 && mY < orig->position.y + 86) ||
            (allowButton && renameButton->bHover)) &&
            !renameInput->GetActive())
        {
            renameInput->Start();
        }
        else
        {
            renameInput->Stop();
            if (renameInput->GetText().empty())
            {
                std::string namelessOne = G_->GetTextLibrary()->GetText("nameless_one");
                renameInput->SetText(namelessOne);
                G_->GetShipManager(0)->myBlueprint.name.data = namelessOne;
                G_->GetScoreKeeper()->currentScore.name = namelessOne;
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

    if (allowRename)
    {
        renameInput->Stop();
        if (renameInput->GetText().empty())
        {
            std::string namelessOne = G_->GetTextLibrary()->GetText("nameless_one");
            renameInput->SetText(namelessOne);
            G_->GetShipManager(0)->myBlueprint.name.data = namelessOne;
            G_->GetScoreKeeper()->currentScore.name = namelessOne;
        }
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

    undoButton.OnInit(Point(position.x + 33, position.y + 471), Point(97, 32), 4, &buttonLabel, 63);
    undoButton.SetBaseImage("upgradeUI/buttons_undo_base.png", Point(-23, -7), 97);
    undoButton.SetAutoWidth(true, false, 3, 0);

    reactorButton.OnInit("upgradeUI/Equipment/equipment_reactor", Point(position.x + 305, position.y + 327));
    reactorButton.allowAnyTouch = true;
    reactorButton.touchSelectable = true;
    reactorButton.ship = ship;

    box = G_->GetResources()->GetImageId("upgradeUI/Equipment/upgrades_main.png");

    auto def = CustomShipSelect::GetInstance()->GetDefinition(ship->myBlueprint.blueprintName);

    int sysLimit = def.systemLimit;
    int subsystemLimit = def.subsystemLimit;

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

    //Custom systems
    //TODO: Allow full user control over systemBox ordering?
    for (int systemId = SYS_CUSTOM_FIRST; systemId <= CustomUserSystems::GetLastSystemId(); ++systemId)
    {
        auto sys = ship->GetSystem(systemId);
        if (sys)
        {
            AddUpgradeBox(this, sys, systemXPos, subsystemXPos, numSystems, numSubsystems);
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
    if (CustomUpgrades::GetInstance()->allowRename && CustomUpgrades::GetInstance()->renameInput->GetActive())
        return;

    super(mX, mY);

    CustomUpgrades::GetInstance()->MouseMove(mX, mY);
}

HOOK_METHOD(Upgrades, OnRender, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> Upgrades::OnRender -> Begin (CustomUpgrades.cpp)\n")
    blockShipNameRendering = true;
    super();
    blockShipNameRendering = false;

    CustomUpgrades::GetInstance()->OnRender();
}

// Override the regular ship name rendering
HOOK_STATIC(freetype, easy_printCenter, (int fontSize, float x, float y, const std::string& text) -> Pointf)
{
    LOG_HOOK("HOOK_STATIC -> freetype::easy_printCenter -> Begin (CustomUpgrades.cpp)\n")
    if (blockShipNameRendering)
    {
        blockShipNameRendering = false;
        return super(fontSize, x, y, "");
    }

    return super(fontSize, x, y, text);
}

HOOK_METHOD(Upgrades, OnLoop, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> Upgrades::OnLoop -> Begin (CustomUpgrades.cpp)\n")
    super();

    if (bOpen) CustomUpgrades::GetInstance()->OnLoop();
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

HOOK_METHOD(CApp, OnTextInput, (int charCode) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CApp::OnTextInput -> Begin (CustomUpgrades.cpp)\n")
    
    if (G_->GetWorld()->commandGui->upgradeScreen.bOpen)
    {
        CustomUpgrades *upgrade = CustomUpgrades::GetInstance();
        if (upgrade->allowRename && upgrade->renameInput && upgrade->renameInput->GetActive())
        {
            upgrade->renameInput->OnTextInput(charCode);
            G_->GetShipManager(0)->myBlueprint.name.data = upgrade->renameInput->GetText();
            G_->GetScoreKeeper()->currentScore.name = upgrade->renameInput->GetText();
            return;
        }
    }

    super(charCode);
}

HOOK_METHOD(CApp, OnTextEvent, (CEvent::TextEvent te) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CApp::OnTextEvent -> Begin (CustomUpgrades.cpp)\n")
    if (G_->GetWorld()->commandGui->upgradeScreen.bOpen)
    {
        CustomUpgrades *upgrade = CustomUpgrades::GetInstance();
        if (upgrade->allowRename && upgrade->renameInput && upgrade->renameInput->GetActive())
        {
            upgrade->renameInput->OnTextEvent(te);
            std::string currentName = upgrade->renameInput->GetText();
            if ((te == CEvent::TEXT_CONFIRM || te == CEvent::TEXT_CANCEL) && currentName.empty())
            {
                currentName = G_->GetTextLibrary()->GetText("nameless_one");
                upgrade->renameInput->SetText(currentName);
            }
            G_->GetShipManager(0)->myBlueprint.name.data = currentName;
            G_->GetScoreKeeper()->currentScore.name = currentName;
            return;
        }
    }

    super(te);
}

HOOK_METHOD(CApp, OnKeyDown, (SDLKey key) -> void)
{
    LOG_HOOK("HOOK_METHOD -> CApp::OnKeyDown -> Begin (CustomUpgrades.cpp)\n")
    if (G_->GetWorld()->commandGui->upgradeScreen.bOpen)
    {
        CustomUpgrades *upgrade = CustomUpgrades::GetInstance();
        if (upgrade->allowRename && upgrade->renameInput && upgrade->renameInput->GetActive()) return;
    }
    super(key);
}


bool SystemNoPurchaseThreshold::enabled = false;
int SystemNoPurchaseThreshold::threshold;
std::string SystemNoPurchaseThreshold::replace;

// Separate the upgrade power bars into two columns if the max value is above 8.

bool g_upgradeBarsSecondColumn = false;

HOOK_METHOD(Upgrades, OnRender, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> Upgrades::OnRender -> Begin (CustomUpgrades.cpp)\n")
    g_upgradeBarsSecondColumn = true;
    super();
    g_upgradeBarsSecondColumn = false;
}

// scrolling info box and system upgrade cost upper limit visual fix

bool g_infoBoxRenderFix = false;
bool g_upgradeCostThresholdRewrite = false;
bool g_force_easy_print = false;
Pointf infoBoxUpgradeCostPos;
std::vector<int> upgradeCosts;

HOOK_METHOD(InfoBox, OnRender, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> InfoBox::OnRender -> Begin (CustomUpgrades.cpp)\n")
    g_infoBoxRenderFix = maxPower > 8 && blueprint;
    if (g_infoBoxRenderFix)
    {
        infoBoxUpgradeCostPos.x = (float)(location.x + 105);
        infoBoxUpgradeCostPos.y = (float)(location.y + yShift + 224);
        upgradeCosts = std::vector<int>(blueprint->upgradeCosts);
    }
    g_upgradeCostThresholdRewrite = SystemNoPurchaseThreshold::enabled;
    // if g_infoBoxRenderFix is true, upgrade costs rendering is prevented in this method. Instead they are rendered within ShipSystem::RenderPowerBoxesPlain hook, taking scrolling into account
    super();
    g_infoBoxRenderFix = false;
    g_upgradeCostThresholdRewrite = false;
}

HOOK_METHOD(UpgradeBox, OnRender, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> UpgradeBox::OnRender -> Begin (CustomUpgrades.cpp)\n")
    g_upgradeCostThresholdRewrite = SystemNoPurchaseThreshold::enabled;
    super();
    g_upgradeCostThresholdRewrite = false;
}

int barIndex = 0;

bool g_startTranslatePowerBars = false;
int barLeftColumnIndex = 0;

bool g_startScrollInfoBox = false;
int barIncrement = 0;

// called within InfoBox::OnRender
// called within Upgrades::OnRender
HOOK_STATIC(ShipSystem, RenderPowerBoxesPlain, (int x, int y, int width, int height, int gap, int current, int temp, int max) -> int)
{
    LOG_HOOK("HOOK_STATIC -> ShipSystem::RenderPowerBoxesPlain -> Begin (CustomUpgrades.cpp)\n")
    if (g_infoBoxRenderFix && max > 8) // from InfoBox::OnRender hook
    {
        barIndex = 0;
        barIncrement = current + temp - 4;
        if (max - current - temp < 4) barIncrement -= 4 - (max - current - temp);
        if (barIncrement < 0) barIncrement = 0;

        g_startScrollInfoBox = true;
        int ret = super(x, y, width, height, gap, current, temp, max);
        g_startScrollInfoBox = false;

        // rewrite upgrade costs rendering
        g_force_easy_print = true;
        GL_Color originalColor = CSurface::GL_GetColor();
        CSurface::GL_SetColor(COLOR_WHITE);
        for (int i = 0; i < 8; i++)
        {
            if (current - barIncrement < 8 - i)
            {
                freetype::easy_print(0, infoBoxUpgradeCostPos.x, infoBoxUpgradeCostPos.y + (float)(i * 26), SystemNoPurchaseThreshold::to_string(upgradeCosts[6 - i + barIncrement]));
            }
        }
        CSurface::GL_SetColor(originalColor);
        g_force_easy_print = false;

        return ret;
    }
    else if (g_upgradeBarsSecondColumn && max > 8) // from Upgrades::OnRender hook
    {
        barIndex = 0;
        barLeftColumnIndex = ((current + temp) / 8) > 0 ? ((current + temp) / 8) - 1 : 0;
        if ((current + temp) % 8 == 0 && current + temp == max && barLeftColumnIndex > 0) barLeftColumnIndex--;
        if (barLeftColumnIndex > 0)
        {
            freetype::easy_printCenter(5, (float)(x + 21), (float)(y - 62), std::to_string((barLeftColumnIndex + 1) * 8));
            freetype::easy_printCenter(5, (float)(x + 42), (float)(y - 62), std::to_string((barLeftColumnIndex + 2) * 8));
        }

        g_startTranslatePowerBars = true;
        int ret = super(x, y, width, height, gap, current, temp, max);
        g_startTranslatePowerBars = false;

        return ret;
    }
    else return super(x, y, width, height, gap, current, temp, max);
}

// called within ShipSystem::RenderPowerBoxesPlain
// this function is called inside ShipSystem::RenderPowerBoxesPlain within the for statement, so you can keep track of the bar index.
HOOK_STATIC(CSurface, GL_RenderPrimitiveWithColor, (GL_Primitive *primitive, GL_Color color) -> void)
{
    LOG_HOOK("HOOK_STATIC -> CSurface::GL_RenderPrimitiveWithColor -> Begin (CustomUpgrades.cpp)\n")
    if (g_startTranslatePowerBars) // upgrade bar second column
    {
        int currentColumn = barIndex / 8;
        if (currentColumn == barLeftColumnIndex)
        {
            CSurface::GL_Translate(-10.f, (float)currentColumn * 64.f);
            super(primitive, color);
            CSurface::GL_Translate(10.f, (float)currentColumn * -64.f);
        }
        else if (currentColumn == barLeftColumnIndex + 1)
        {
            CSurface::GL_Translate(11.f, (float)currentColumn * 64.f);
            super(primitive, color);
            CSurface::GL_Translate(-11.f, (float)currentColumn * -64.f);
        }
        barIndex++;
    }
    else if (g_startScrollInfoBox) // info box render fix
    {
        if (barIndex - barIncrement < 8 && -1 < barIndex - barIncrement)
        {
            CSurface::GL_Translate(0.f, (float)barIncrement * 26.f);
            super(primitive, color);
            CSurface::GL_Translate(0.f, (float)barIncrement * -26.f);
        }
        barIndex++;
    }
    else return super(primitive, color);
}

HOOK_STATIC(ShipSystem, GetLevelDescription, (int systemId, int level, bool tooltip) -> std::string)
{
    LOG_HOOK("HOOK_STATIC -> ShipSystem::GetLevelDescription -> Begin (CustomUpgrades.cpp)\n")
    if (!g_infoBoxRenderFix) return super(systemId, level, tooltip);
    return super(systemId, level + barIncrement, tooltip);
}

HOOK_STATIC(freetype, easy_print, (int fontSize, float x, float y, const std::string &text) -> Pointf)
{
    LOG_HOOK("HOOK_STATIC -> freetype::easy_print -> Begin (CustomUpgrades.cpp)\n")
    if (g_force_easy_print) return super(fontSize, x, y, text);
    else if (g_infoBoxRenderFix && fontSize == 0) return  super(fontSize, x, y, "");
    else if (g_upgradeCostThresholdRewrite && fontSize == 0 && text != " -") return super(fontSize, x, y, SystemNoPurchaseThreshold::to_string(boost::lexical_cast<int>(text)));
    else return super(fontSize, x, y, text);
}
