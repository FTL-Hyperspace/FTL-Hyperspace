#include "CustomWeapons.h"
#include "CustomOptions.h"
#include "CustomDamage.h"
#include "CrewMember_Extend.h"
#include "Projectile_Extend.h"
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>
#include <iomanip>
#include <float.h>

CustomWeaponManager *CustomWeaponManager::instance = new CustomWeaponManager();
CustomWeaponDefinition *CustomWeaponManager::currentWeapon = nullptr;

HOOK_METHOD(BlueprintManager, ProcessWeaponBlueprint, (rapidxml::xml_node<char>* node) -> WeaponBlueprint)
{
    LOG_HOOK("HOOK_METHOD -> BlueprintManager::ProcessWeaponBlueprint -> Begin (CustomWeapons.cpp)\n")
    WeaponBlueprint ret = super(node);

    auto weaponDef = CustomWeaponDefinition();
    weaponDef.name = node->first_attribute("name")->value();

    weaponDef.customDamage = new CustomDamageDefinition();
    weaponDef.customDamage->erosionEffect = ErosionEffect::defaultErosionEffect; // copy assignment
    bool hasCustomDamage = false;
    bool hasErosion = false;

    for (auto child = node->first_node(); child; child = child->next_sibling())
    {
        std::string name = child->name();
        std::string val = child->value();
        if (name == "shotLimit")
        {
            weaponDef.shotLimit = boost::lexical_cast<int>(val);
        }
        if (name == "freeMissileChance")
        {
            weaponDef.freeMissileChance = boost::lexical_cast<int>(val);
        }
        if (name == "descriptionOverride")
        {
            weaponDef.descriptionOverride.data = val;
            weaponDef.descriptionOverride.isLiteral = true;
            if (child->first_attribute("id"))
            {
                weaponDef.descriptionOverride.data = child->first_attribute("id")->value();
                weaponDef.descriptionOverride.isLiteral = false;
            }
        }
        if (name == "advancedDescriptionOverride")
        {
            weaponDef.advancedDescriptionOverride.data = val;
            weaponDef.advancedDescriptionOverride.isLiteral = true;
            if (child->first_attribute("id"))
            {
                weaponDef.advancedDescriptionOverride.data = child->first_attribute("id")->value();
                weaponDef.advancedDescriptionOverride.isLiteral = false;
            }
        }
        if (name == "tooltipOverride")
        {
            weaponDef.tooltipOverride.data = val;
            weaponDef.tooltipOverride.isLiteral = true;
            if (child->first_attribute("id"))
            {
                weaponDef.tooltipOverride.data = child->first_attribute("id")->value();
                weaponDef.tooltipOverride.isLiteral = false;
            }
        }
        if (name == "advancedTooltipOverride")
        {
            weaponDef.advancedTooltipOverride.data = val;
            weaponDef.advancedTooltipOverride.isLiteral = true;
            if (child->first_attribute("id"))
            {
                weaponDef.advancedTooltipOverride.data = child->first_attribute("id")->value();
                weaponDef.advancedTooltipOverride.isLiteral = false;
            }
        }
        if (name == "hideEventTooltip")
        {
            weaponDef.hideEventTooltip = EventsParser::ParseBoolean(val);
        }
        if (name == "accuracyMod")
        {
            hasCustomDamage = true;
            weaponDef.customDamage->accuracyMod = boost::lexical_cast<int>(val);
        }
        if (name == "droneAccuracyMod")
        {
            hasCustomDamage = true;
            weaponDef.customDamage->droneAccuracyMod = boost::lexical_cast<int>(val);
        }
        if (name == "noSysDamage")
        {
            hasCustomDamage = true;
            weaponDef.customDamage->noSysDamage = EventsParser::ParseBoolean(val);
        }
        if (name == "noPersDamage")
        {
            hasCustomDamage = true;
            weaponDef.customDamage->noPersDamage = EventsParser::ParseBoolean(val);
        }
        if (name == "ionBeamFix" && ret.type == 2) // Ion beam fix only valid for beams
        {
            hasCustomDamage = true;
            weaponDef.customDamage->ionBeamFix = EventsParser::ParseBoolean(val);
        }
        if (name == "invisibleBeam")
        {
            weaponDef.invisibleBeam = EventsParser::ParseBoolean(val);
        }
        if (name == "simultaneousFire")
        {
            weaponDef.simultaneousFire = EventsParser::ParseBoolean(val);
        }
        if (name == "fireTime")
        {
            weaponDef.fireTime = boost::lexical_cast<float>(val);
        }
        if (name == "angularRadius") // affects flak drones
        {
            weaponDef.angularRadius = boost::lexical_cast<float>(val);
        }
        if (name == "statBoostChance")
        {
            hasCustomDamage = true;
            weaponDef.customDamage->statBoostChance = boost::lexical_cast<int>(val);
        }
        if (name == "statBoosts")
        {
            hasCustomDamage = true;
            for (auto statBoostNode = child->first_node(); statBoostNode; statBoostNode = statBoostNode->next_sibling())
            {
                if (strcmp(statBoostNode->name(), "statBoost") == 0)
                {
                    weaponDef.customDamage->statBoosts.push_back(StatBoostManager::GetInstance()->ParseStatBoostNode(statBoostNode, StatBoostDefinition::BoostSource::AUGMENT, false));
                }
            }
        }
        if (name == "roomStatBoostChance")
        {
            hasCustomDamage = true;
            weaponDef.customDamage->roomStatBoostChance = boost::lexical_cast<int>(val);
        }
        if (name == "roomStatBoosts")
        {
            hasCustomDamage = true;
            for (auto statBoostNode = child->first_node(); statBoostNode; statBoostNode = statBoostNode->next_sibling())
            {
                if (strcmp(statBoostNode->name(), "statBoost") == 0)
                {
                    weaponDef.customDamage->roomStatBoosts.push_back(StatBoostManager::GetInstance()->ParseStatBoostNode(statBoostNode, StatBoostDefinition::BoostSource::AUGMENT, true));
                }
            }
        }
        if (name == "crewSpawnChance")
        {
            hasCustomDamage = true;
            weaponDef.customDamage->crewSpawnChance = boost::lexical_cast<int>(val);
        }
        if (name == "spawnCrew")
        {
            hasCustomDamage = true;
            CrewSpawn *newSpawn = CrewSpawn::ParseCrewSpawn(child, false);
            if (!newSpawn->race.empty())
            {
                weaponDef.customDamage->crewSpawns.push_back(newSpawn);
            }
        }

        if (name == "erosion")
        {
            hasCustomDamage = true;
            hasErosion = true;
            weaponDef.customDamage->erosionEffect.ParseErosionEffect(child);
        }
        if (name == "erosionChance")
        {
            hasCustomDamage = true;
            weaponDef.customDamage->erosionChance = boost::lexical_cast<int>(val);
        }

        if (name == "iconReplace")
        {
            weaponDef.iconReplace = val;
        }
        if (name == "iconScale")
        {
            weaponDef.iconScale = boost::lexical_cast<float>(val);
        }

        if (name == "projectiles")
        {
            for (auto projectileNode = child->first_node(); projectileNode; projectileNode = projectileNode->next_sibling())
            {
                if (strcmp(projectileNode->name(), "projectile") == 0)
                {
                    if (projectileNode->first_attribute("blueprint"))
                    {
                        weaponDef.miniProjectileOverride[projectileNode->value()] = projectileNode->first_attribute("blueprint")->value();
                    }
                }
            }
        }
    }

    // Default chance if tag not specified (100% if tags specified, 0% otherwise)
    if (weaponDef.customDamage->statBoostChance == -1)
    {
        weaponDef.customDamage->statBoostChance = weaponDef.customDamage->statBoosts.empty() ? 0 : 10;
    }
    if (weaponDef.customDamage->roomStatBoostChance == -1)
    {
        weaponDef.customDamage->roomStatBoostChance = weaponDef.customDamage->roomStatBoosts.empty() ? 0 : 10;
    }
    if (weaponDef.customDamage->crewSpawnChance == -1)
    {
        weaponDef.customDamage->crewSpawnChance = weaponDef.customDamage->crewSpawns.empty() ? 0 : 10;
    }
    if (weaponDef.customDamage->erosionChance == -1)
    {
        weaponDef.customDamage->erosionChance = hasErosion ? 10 : 0;
    }

    if (hasCustomDamage)
    {
        weaponDef.customDamage->GiveId();
    }
    else
    {
        delete weaponDef.customDamage;
        weaponDef.customDamage = &CustomDamageDefinition::defaultDef;
    }

    CustomWeaponManager::instance->AddWeaponDefinition(weaponDef);

    return ret;
}

HOOK_METHOD(ShipManager, OnRender, (bool showInterior, bool doorControlMode) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::OnRender -> Begin (CustomWeapons.cpp)\n")
    if (bJumping)
    {
        auto time = jumpAnimation.current_time;
        if (time >= 1.0)
        {
            CSurface::GL_SetColorTint(GL_Color(255.f, 255.f, 255.f, 1.f - ((time - 1.f) * 2.f)));
            RenderWeapons();
            CSurface::GL_RemoveColorTint();
        }
        else
        {
            RenderWeapons();
        }
    }
    super(showInterior, doorControlMode);

}

static bool artillery = false;

HOOK_METHOD(ProjectileFactory, NumTargetsRequired, () -> int)
{
    LOG_HOOK("HOOK_METHOD -> ProjectileFactory::NumTargetsRequired -> Begin (CustomWeapons.cpp)\n")

    if (blueprint->type == 2)
    {
        if (blueprint->length>1) // regular beam
        {
            return 2; //fix for charge beams crashing the game
        }
        else // pinpoint beam
        {
            return 1;
        }
    }
    else if (blueprint->type == 3 && targetId == iShipId) //self-targetting bomb
    {
        return 1; // fix for self-targeting bomb with multiple shots being unable to change the target
    }

    int ret = super();

    if (artillery)
    {
        int rooms = ShipGraph::GetShipInfo(!iShipId)->rooms.size();
        if (ret > rooms)
        {
            return rooms;
        }
    }

    return ret;
}
//Rewrite to fix hang when an enemy fires a weapon with more shots than the ship has rooms
//NOTE: Native game implementation of generating non-repeating targets is inefficient, should rework when implementing custom AI
HOOK_METHOD_PRIORITY(CombatAI, UpdateWeapons, 9999, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> CombatAI::UpdateWeapons -> Begin (CustomWeapons.cpp)\n")

    if (bFiringWhileCloaked || !self->ship.bCloaked)
    {
        weapons = self->GetWeaponList();
        for (ProjectileFactory* weapon : weapons)
        {
            if (weapon->ReadyToFire() && weapon->IsChargedGoal() && target != nullptr && !target->IsCloaked())
            {
                int chargeLevels = weapon->blueprint->chargeLevels;
                bool earlyFire = random32() % (chargeLevels - weapon->chargeLevel + 1) == 0;
                if (chargeLevels < 2 || chargeLevels == weapon->chargeLevel || earlyFire)
                {
                    std::vector<Pointf> targets;
                    while (targets.size() < weapon->NumTargetsRequired())
                    {
                        Pointf temp_target(0, 0);
                        int systemTarget = PrioritizeSystem(weapon->blueprint->type);
                        if (systemTarget == -1) temp_target = target->GetRandomRoomCenter();
                        else temp_target = target->GetRoomCenter(target->GetSystemRoom(systemTarget));

                        //Only remove repeated targets if it is possible to add a non-repeated one
                        if (ShipGraph::GetShipInfo(target->iShipId)->RoomCount() > targets.size())
                        {
                            targets.erase(std::remove_if(targets.begin(), targets.end(), [&](Pointf potentialTarget) { return potentialTarget == temp_target; }), targets.end());
                        }

                        targets.push_back(temp_target);
                    }
                    weapon->Fire(targets, target->iShipId);
                    weapon->SelectChargeGoal();
                }
            }
        }
    }
}

//Reverse inlining of NumTargetsRequired
HOOK_METHOD_PRIORITY(ProjectileFactory, ClearAiming, 9999, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> ProjectileFactory::ClearAiming -> Begin (CustomWeapons.cpp)\n")

    if (targets.size() > 0 && targets.size() < NumTargetsRequired()) return;

    fireWhenReady = false;
    targets.clear();
    lastTargets.clear();

    targetId = -1;
}

HOOK_METHOD(ProjectileFactory, GetProjectile, () -> Projectile*)
{
    LOG_HOOK("HOOK_METHOD -> ProjectileFactory::GetProjectile -> Begin (CustomWeapons.cpp)\n")
    Projectile* ret = super();
    if (!QueuedShots() && HitShotLimit()) ClearAiming();
    return ret;
}
// Pinpoint targeting
HOOK_METHOD(ProjectileFactory, Fire, (std::vector<Pointf> &points, int target) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ProjectileFactory::Fire -> Begin (CustomWeapons.cpp)\n")
    if (blueprint->type==2 && blueprint->length<=1)
    {
        if (points.size() < 2) points.emplace_back(); // construct second targeting point (only if needed; arty will give two points)
        Point grid;

        if (target == 1 && !artillery) // targeting enemy ship (TODO: change to detect weapon's owner if we expand this targeting mode beyond just beams, in case of self-targeting)
        {
            grid = ShipGraph::TranslateToGrid(points[0].x, points[0].y);
        }
        else //enemy/artillery targetting picks a random slot
        {
            int roomNumber = G_->GetShipManager(target)->ship.GetSelectedRoomId(points[0].x, points[0].y, true);
            if (roomNumber != -1)
            {
                ShipGraph *shipInfo = ShipGraph::GetShipInfo(target);
                int numSlots = shipInfo->GetNumSlots(roomNumber);
                int randomSlot = random32() % numSlots;
                Point gridPos = shipInfo->GetSlotWorldPosition(randomSlot, roomNumber);
                grid = ShipGraph::TranslateToGrid(gridPos.x, gridPos.y);
            }
        }

        points[0].x=(grid.x * 35.f + 17.0f);
        points[0].y=(grid.y * 35.f + 17.5f);

        points[1].x=points[0].x+1.0f;
        points[1].y=points[0].y;
    }
    super(points, target);
    // Untargets preemptive weapons after they're done firing (or anything with negative cooldown)
    if ((cooldown.second < 0) && iShipId == 0)
    {
        targets.clear();
    }
}

HOOK_METHOD(CombatDrone, PickTarget, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CombatDrone::PickTarget -> Begin (CustomWeapons.cpp)\n")

    // NOTE: original implementation called HasTarget, but it was a pain to expose so I just used the same conditions
    if (weaponTarget != nullptr && weaponTarget->hostile && (targetLocation.x == -FLT_MAX || targetLocation.y == -FLT_MAX)) {
        float angle = aimingAngle;
        if (angle <= 180.0)
        {
            if (angle < -180.0)
            {
                angle += 360.0;
                aimingAngle = angle;
            }
        }
        else
        {
            angle -= 360.0;
            aimingAngle = angle;
        }
        lastAimingAngle = angle;
        targetLocation = weaponTarget->GetRandomTargettingPoint(false);

        // check that drone uses pinpoint beam
        if (weaponBlueprint->type == 2 && weaponBlueprint->length <= 1)
        {
            ShipManager *ship = G_->GetShipManager(currentSpace);

            // check that expected ship is actually the target
            if (&ship->_targetable == weaponTarget)
            {
                // move target point to random tile in the room
                int roomNumber = ship->ship.GetSelectedRoomId(targetLocation.x, targetLocation.y, true);
                if (roomNumber != -1)
                {
                    ShipGraph *shipInfo = ShipGraph::GetShipInfo(ship->iShipId);
                    int numSlots = shipInfo->GetNumSlots(roomNumber);
                    int randomSlot = random32() % numSlots;
                    Point gridPos = shipInfo->GetSlotWorldPosition(randomSlot, roomNumber);
                    Point grid = ShipGraph::TranslateToGrid(gridPos.x, gridPos.y);

                    targetLocation.x = (grid.x * 35.f + 17.5f);
                    targetLocation.y = (grid.y * 35.f + 17.5f);
                }
            }
        }
    }
}

HOOK_METHOD(ArtillerySystem, OnLoop, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ArtillerySystem::OnLoop -> Begin (CustomWeapons.cpp)\n")
    artillery = true;
    super();
    artillery = false;
}

HOOK_METHOD(ProjectileFactory, SpendMissiles, () -> int)
{
    LOG_HOOK("HOOK_METHOD -> ProjectileFactory::SpendMissiles -> Begin (CustomWeapons.cpp)\n")
    if (iSpendMissile > 0)
    {
        int randomNum = random32() % 100;

        if (randomNum < CustomWeaponManager::instance->GetWeaponDefinition(blueprint->name)->freeMissileChance)
        {
            iSpendMissile = 0;
            if (iShipId == 0) G_->GetEventSystem()->AddEvent(12);
        }
    }

    return super();
}

// Charger pre-ignition
HOOK_METHOD(ProjectileFactory, ForceCoolup, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ProjectileFactory::ForceCoolup -> Begin (CustomWeapons.cpp)\n")

    if (CustomOptionsManager::GetInstance()->preIgniteChargers.currentValue)
    {
        if (powered) {
            cooldown.first = cooldown.second;
            chargeLevel = std::max(1, this->blueprint->chargeLevels);
        }
        return;
    }

    super();
}

// Weapon Types:
// 0: LASER
// 1: MISSILES
// 2: BEAM
// 3: BOMB
// 4: BURST

static Button* smallAutoFireButton;

HOOK_METHOD(WeaponControl, constructor, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> WeaponControl::constructor -> Begin (CustomWeapons.cpp)\n")
    super();

    smallAutoFireButton = new Button();
    smallAutoFireButton->OnInit("button_small_autofireOn", Point(0, 0));
    smallAutoFireButton->hitbox.w = 28;
    smallAutoFireButton->hitbox.h = 28;
}

HOOK_METHOD(WeaponControl, LinkShip, (ShipManager *ship) -> void)
{
    LOG_HOOK("HOOK_METHOD -> WeaponControl::LinkShip -> Begin (CustomWeapons.cpp)\n")
    super(ship);

    if(autoFiring){
        smallAutoFireButton->SetImageBase("button_small_autofireOn");
        smallAutoFireButton->bRenderOff = true;
    }
    else {
        smallAutoFireButton->SetImageBase("button_small_autofireOff");
        smallAutoFireButton->bRenderOff = true;
    }
}

HOOK_METHOD(WeaponControl, OnRender, (bool unk) -> void)
{
    LOG_HOOK("HOOK_METHOD -> WeaponControl::OnRender -> Begin (CustomWeapons.cpp)\n")
    super(unk);

    if (this->shipManager->myBlueprint.weaponSlots <= 2 && this->shipManager->myBlueprint.weaponSlots > 0 && this->shipManager->HasSystem(3))
    {
        smallAutoFireButton->hitbox.x = this->location.x + 97 * this->shipManager->myBlueprint.weaponSlots - 10;
        smallAutoFireButton->hitbox.y = this->location.y + 61;

        CSurface::GL_PushMatrix();
        CSurface::GL_Translate(this->location.x + 97 * this->shipManager->myBlueprint.weaponSlots - 10, this->location.y + 61, 0.0);
        smallAutoFireButton->OnRender();
        CSurface::GL_PopMatrix();
    }
}

HOOK_METHOD(WeaponControl, MouseMove, (int x, int y) -> void)
{
    LOG_HOOK("HOOK_METHOD -> WeaponControl::MouseMove -> Begin (CustomWeapons.cpp)\n")
    super(x, y);

    if (this->shipManager->myBlueprint.weaponSlots <= 2 && this->shipManager->myBlueprint.weaponSlots > 0 && this->shipManager->HasSystem(3) && !Dragging())
    {
        smallAutoFireButton->MouseMove(x, y, false);
        if(smallAutoFireButton->bHover){
            smallAutoFireButton->bRenderOff = false;
            smallAutoFireButton->bRenderSelected = true;

            std::string replaceWith;
            std::string tooltip = G_->GetTextLibrary()->GetText("tooltip_autofire");

            replaceWith = Settings::GetHotkeyName("autofire");
            boost::algorithm::replace_all(tooltip, "\\1", replaceWith);

            replaceWith = Settings::GetHotkeyName("force_autofire");
            boost::algorithm::replace_all(tooltip, "\\2", replaceWith);

            G_->GetMouseControl()->bForceTooltip = true;
            G_->GetMouseControl()->SetTooltip(tooltip);
        }
        else {
            smallAutoFireButton->bRenderOff = true;
            smallAutoFireButton->bRenderSelected = false;

        }

    }
}

HOOK_METHOD(WeaponControl, LButton, (int x, int y, bool holdingShift) -> bool)
{
    LOG_HOOK("HOOK_METHOD -> WeaponControl::LButton -> Begin (CustomWeapons.cpp)\n")
    bool ret = super(x, y, holdingShift);

    if (this->shipManager->myBlueprint.weaponSlots <= 2 && this->shipManager->myBlueprint.weaponSlots > 0 && this->shipManager->HasSystem(3))
    {
        if (smallAutoFireButton->bActive && smallAutoFireButton->bHover)
        {
            SetAutofiring(!autoFiring, false);
            if (autoFiring) {
                smallAutoFireButton->SetImageBase("button_small_autofireOn");
                smallAutoFireButton->bRenderSelected = false;
                smallAutoFireButton->bRenderOff = true;
            }
            else {
                smallAutoFireButton->SetImageBase("button_small_autofireOff");
                smallAutoFireButton->bRenderSelected = false;
                smallAutoFireButton->bRenderOff = true;
            }
            return autoFiring;
        }
    }

    return ret;
}

HOOK_METHOD(WeaponControl, KeyDown, (SDLKey key) -> bool)
{
    LOG_HOOK("HOOK_METHOD -> WeaponControl::KeyDown -> Begin (CustomWeapons.cpp)\n")
    bool ret = super(key);

    if (this->shipManager->myBlueprint.weaponSlots <= 2 && this->shipManager->myBlueprint.weaponSlots > 0 && this->shipManager->HasSystem(3))
    {
        if (key == Settings::GetHotkey("autofire"))
        {
            if (smallAutoFireButton->bActive)
            {
                SetAutofiring(!autoFiring, false);
                if (autoFiring)
                {
                    smallAutoFireButton->SetImageBase("button_small_autofireOn");
                    smallAutoFireButton->bRenderSelected = false;
                    smallAutoFireButton->bRenderOff = true;
                }
                else
                {
                    smallAutoFireButton->SetImageBase("button_small_autofireOff");
                    smallAutoFireButton->bRenderSelected = false;
                    smallAutoFireButton->bRenderOff = true;
                }
                return autoFiring;
            }
        }
    }

    return ret;
}

static ProjectileFactory *simultaneousFireWeapon = nullptr;
HOOK_METHOD(ProjectileFactory, GetProjectile, () -> Projectile*)
{
    LOG_HOOK("HOOK_METHOD -> ProjectileFactory::GetProjectile -> Begin (CustomWeapons.cpp)\n")
    bool fireShot = weaponVisual.bFireShot;
    Projectile* ret = super();

    if (!queuedProjectiles.empty())
    {
        if (fireShot && CustomWeaponManager::instance->GetWeaponDefinition(blueprint->name)->simultaneousFire)
        {
            simultaneousFireWeapon = this;
        }

        if (blueprint->type == 4 && !blueprint->miniProjectiles.empty())
        {
            if (!fireShot && ret == nullptr)
            {
                if (queuedProjectiles.size() % blueprint->miniProjectiles.size() != 0)
                {
                    ret = queuedProjectiles.back();
                    queuedProjectiles.pop_back();
                    return ret;
                }
                else if (simultaneousFireWeapon == this)
                {
                    ret = queuedProjectiles.back();
                    queuedProjectiles.pop_back();
                }
            }

            if (ret != nullptr)
            {
                // Offset fix for charge flak
                int i = (queuedProjectiles.size() / blueprint->miniProjectiles.size()) * blueprint->miniProjectiles.size();
                if (i < queuedProjectiles.size())
                {
                    for (int j=i+1; j<queuedProjectiles.size(); ++j)
                    {
                        queuedProjectiles[j]->position = queuedProjectiles[i]->position;
                        queuedProjectiles[j]->last_position = queuedProjectiles[i]->last_position;
                    }
                    ret->position = queuedProjectiles[i]->position;
                    ret->last_position = queuedProjectiles[i]->last_position;
                }
            }
        }
        else
        {
            if (simultaneousFireWeapon == this && !fireShot && ret == nullptr)
            {
                ret = queuedProjectiles.back();
                queuedProjectiles.pop_back();
            }
        }
    }
    else
    {
        if (simultaneousFireWeapon == this) simultaneousFireWeapon = nullptr;
    }

    return ret;
}

HOOK_METHOD(WeaponAnimation, StartFire, () -> bool)
{
    LOG_HOOK("HOOK_METHOD -> WeaponAnimation::StartFire -> Begin (CustomWeapons.cpp)\n")
    bool ret = super();

    if (ret && iChargeLevels > 1 && CustomWeaponManager::currentWeapon && CustomWeaponManager::currentWeapon->simultaneousFire)
    {
        int chargeLength = (anim.info.numFrames - iChargedFrame) / iChargeLevels;
        anim.SetCurrentFrame(iChargedFrame + chargeLength * boostLevel);
    }
    return ret;
}

HOOK_METHOD(ProjectileFactory, constructor, (const WeaponBlueprint* bp, int shipId) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ProjectileFactory::constructor -> Begin (CustomWeapons.cpp)\n")
    if (bp->type == -1) // If the blueprint doesn't exist, revert to the default laser
    {
        bp = G_->GetBlueprints()->GetWeaponBlueprint("LASER_BURST_1");
    }

    super(bp, shipId);
    HS_MAKE_TABLE(this)
    if (bp->type != 2)
    {
        auto def = CustomWeaponManager::instance->GetWeaponDefinition(blueprint->name);
        if (def->fireTime)
        {
            weaponVisual.SetFireTime(def->fireTime);
        }
    }

    auto context = G_->getLuaContext();
    SWIG_NewPointerObj(context->GetLua(), this, context->getLibScript()->types.pProjectileFactory, 0);
    context->getLibScript()->call_on_internal_event_callbacks(InternalEvents::CONSTRUCT_PROJECTILE_FACTORY, 1);
    lua_pop(context->GetLua(), 1);
}

HOOK_METHOD(ProjectileFactory, destructor, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ProjectileFactory::destructor -> Begin (CustomWeapons.cpp)\n")
    HS_BREAK_TABLE(this)
    super();
}

// Fix for weapon animations with many frames.
HOOK_METHOD(WeaponAnimation, Update, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> WeaponAnimation::Update -> Begin (CustomWeapons.cpp)\n")
    if (bFiring)
    {
        auto cFPS = G_->GetCFPS();
        float speedFactor = cFPS->SpeedFactor;
        float speed = speedFactor * 0.0625f * anim.info.numFrames/anim.tracker.time; // frame length * anim FPS
        if (speed > 1.f)
        {
            speed = std::ceil(speed);
            int iSpeed = speed;
            cFPS->SpeedFactor = speedFactor / speed;
            for (int i=1; i<iSpeed; ++i)
            {
                super();
            }
            cFPS->SpeedFactor = speedFactor;
        }
        else
        {
            super();
        }
    }
    else
    {
        super();
    }
}

// Invisible beams
HOOK_METHOD(BeamWeapon, OnRenderSpecific, (int spaceId) -> void)
{
    LOG_HOOK("HOOK_METHOD -> BeamWeapon::OnRenderSpecific -> Begin (CustomWeapons.cpp)\n")
    if (!CustomWeaponManager::instance->GetWeaponDefinition(Get_Projectile_Extend(this)->name)->invisibleBeam)
    {
        super(spaceId);
    }
}

// Icon Replace
HOOK_METHOD(WeaponBlueprint, RenderIcon, (float scale) -> void)
{
    LOG_HOOK("HOOK_METHOD -> WeaponBlueprint::RenderIcon -> Begin (CustomWeapons.cpp)\n")
    std::string iconReplaceName = CustomWeaponManager::instance->GetWeaponDefinition(name)->iconReplace;
    if (iconReplaceName != "")
    {
        Animation iconReplace = G_->GetAnimationControl()->GetAnimation(iconReplaceName);
        iconReplace.SetCurrentFrame(0);
        CSurface::GL_Translate(-(float)(iconReplace.info.frameWidth/2), -(float)(iconReplace.info.frameHeight/2), 0.0);
        iconReplace.OnRender(1.f, COLOR_WHITE, false);
        CSurface::GL_Translate((float)(iconReplace.info.frameWidth/2), (float)(iconReplace.info.frameHeight/2), 0.0);
    }
    else
    {
        super(scale);
    }
}
HOOK_METHOD(WeaponBlueprint, GetDimensions, () -> Point)
{
    LOG_HOOK("HOOK_METHOD -> WeaponBlueprint::GetDimensions -> Begin (CustomWeapons.cpp)\n")
    std::string iconReplaceName = CustomWeaponManager::instance->GetWeaponDefinition(name)->iconReplace;
    if (iconReplaceName != "")
    {
        Animation iconReplace = G_->GetAnimationControl()->GetAnimation(iconReplaceName);
        return Point(iconReplace.info.frameWidth, iconReplace.info.frameHeight);
    }
    else
    {
        return super();
    }
}

// Icon Scale
HOOK_METHOD(WeaponBlueprint, RenderIcon, (float scale) -> void)
{
    LOG_HOOK("HOOK_METHOD -> WeaponBlueprint::RenderIcon -> Begin (CustomWeapons.cpp)\n")
    scale *= CustomWeaponManager::instance->GetWeaponDefinition(name)->iconScale;
    if (scale != 1.f)
    {
        CSurface::GL_PushMatrix();
        CSurface::GL_Scale(scale,scale,0.f);
        super(scale);
        CSurface::GL_PopMatrix();
    }
    else
    {
        super(scale);
    }
}

// Flak stuff
HOOK_METHOD_PRIORITY(ProjectileFactory, GetProjectile, -1000, () -> Projectile*)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> ProjectileFactory::GetProjectile -> Begin (CustomWeapons.cpp)\n")

    Projectile* ret = super();

    if (ret)
    {
        if (blueprint->type == 4 && !blueprint->miniProjectiles.empty())
        {
            CustomWeaponManager::ProcessMiniProjectile(ret, blueprint, boostLevel);
        }

        // Callback with Projectile and ProjectileFactory
        auto context = Global::GetInstance()->getLuaContext();
        SWIG_NewPointerObj(context->GetLua(), ret, context->getLibScript()->types.pProjectile[ret->GetType()], 0);
        SWIG_NewPointerObj(context->GetLua(), this, context->getLibScript()->types.pProjectileFactory, 0);
        context->getLibScript()->call_on_internal_chain_event_callbacks(InternalEvents::PROJECTILE_FIRE, 2, 0);
        lua_pop(context->GetLua(), 2);
    }

    return ret;
}

void CustomWeaponManager::ProcessMiniProjectile(Projectile *proj, const WeaponBlueprint *bp, int boostLevel)
{
    if (proj->death_animation.fScale == 0.25f) // fake projectile
    {
        PR_EX(proj)->customDamage.Clear();
    }
    else
    {
        auto &miniProjectileOverride = instance->GetWeaponDefinition(bp->name)->miniProjectileOverride;
        if (!miniProjectileOverride.empty())
        {
            auto it = miniProjectileOverride.find(proj->flight_animation.animName);
            if (it != miniProjectileOverride.end())
            {
                WeaponBlueprint *newBp = G_->GetBlueprints()->GetWeaponBlueprint(it->second);
                proj->Initialize(*newBp);
                proj->flight_animation = G_->GetAnimationControl()->GetAnimation(it->first);

                // apply new blueprint chain effect
                if (newBp->boostPower.type == 2 && boostLevel > 0)
                {
                    int boostAmount = (boostLevel-1)*newBp->boostPower.amount;
                    if (proj->damage.iDamage > 0)
                    {
                        proj->damage.iDamage += boostAmount;
                    }
                    else if (proj->damage.iIonDamage > 0)
                    {
                        proj->damage.iIonDamage += boostAmount;
                    }
                    else if (proj->damage.iPersDamage > 0)
                    {
                        proj->damage.iPersDamage += boostAmount;
                    }
                    else
                    {
                        proj->damage.iSystemDamage += boostAmount;
                    }
                }
            }
        }
    }
}
bool ProjectileFactory::HitShotLimit()
{
    auto def = CustomWeaponManager::instance->GetWeaponDefinition(blueprint->name);
    return def->shotLimit >=0 && def->shotLimit <= shotsFiredAtTarget;
}
//Shot limit is implemented in the same context as checks on WeaponBlueprint::missiles as a way of implementing a requirement on weapon usage
//TODO: Possibly add callback for arbitrary requirements on weapon usage

//Handle powering/depowering of weapons

//Rewrite to reverse inlining of PowerWeapon(userDriven=false, force=false) so hook is run
HOOK_METHOD_PRIORITY(WeaponSystem, ForceIncreasePower, 9999, (int power) -> bool)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> WeaponSystem::ForceIncreasePower -> Begin (CustomWeapons.cpp)\n")
    for (auto weapon : weapons)
    {
        if (!weapon->powered && PowerWeapon(weapon, false, false)) return true;
    }
    return false;
}
HOOK_METHOD(WeaponSystem, OnLoop, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> WeaponSystem::OnLoop -> Begin (CustomWeapons.cpp)\n")
    super();
    if (_shipObj.iShipId == 1)
    {
        for (auto weapon : weapons)
        {
            if (weapon->HitShotLimit() && !weapon->QueuedShots()) DePowerWeapon(weapon, false);
        }
    }
}
HOOK_METHOD(WeaponSystem, PowerWeapon, (ProjectileFactory* weapon, bool userDriven, bool force) -> bool)
{
    LOG_HOOK("HOOK_METHOD -> WeaponSystem::PowerWeapon -> Begin (CustomWeapons.cpp)\n")
    if (weapon->HitShotLimit()  && !weapon->QueuedShots() && _shipObj.iShipId == 1) return false;
    return super(weapon, userDriven, force);

}
HOOK_METHOD(ProjectileFactory, FireNextShot, () -> bool)
{
    LOG_HOOK("HOOK_METHOD -> ProjectileFactory::FireNextShot -> Begin (CustomWeapons.cpp)\n")
    if (HitShotLimit()) return false;
    return super();
}
HOOK_METHOD(ProjectileFactory, ReadyToFire, () -> bool)
{
    LOG_HOOK("HOOK_METHOD -> ProjectileFactory::ReadyToFire -> Begin (CustomWeapons.cpp)\n")
    if (HitShotLimit()) return false;
    return super();
}

enum WeaponType
{
    INVALID = -1,
    LASER = 0,
    MISSILES = 1,
    BEAM = 2,
    BOMB = 3,
    BURST = 4,
};


HOOK_METHOD_PRIORITY(ProjectileFactory, Update, 9999, () -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> ProjectileFactory::Update -> Begin (CustomWeapons.cpp)\n")
    if (FireNextShot())
    {
        if (NumTargetsRequired() <= targets.size())
        {
            if (blueprint->missiles > 0 && blueprint->type != BEAM) iSpendMissile = blueprint->missiles;
            shotsFiredAtTarget++;
            if (blueprint->boostPower.amount > 0.f)
            {
                boostLevel++;
                int boostLevelCap = blueprint->boostPower.type == 2 ? blueprint->boostPower.count + 1 : blueprint->boostPower.count;
                boostLevel = std::min(boostLevel, boostLevelCap);
            }
            std::vector<Pointf> currTargets;

            if (blueprint->type == BEAM)
            {
                Pointf target = targets.back();
                targets.pop_back();

                currTargets.push_back(target);

                Pointf sub_target = targets.back();
                targets.pop_back();

                currTargets.push_back(sub_target);

            }
            else if (blueprint->type == BURST)
            {

                for (Pointf& target : targets)
                {
                    for (int i = 0; i < blueprint->miniProjectiles.size(); ++i)
                    {
                        float r = sqrt(random32() / 2147483648.f) * blueprint->radius;
                        float theta = random32() % 360 * 0.01745329f;
                        Pointf offset(r * cos(theta), r * sin(theta));
                        Pointf flakTarget = target + offset;
                        currTargets.push_back(flakTarget);
                        bool manualAiming = iShipId == 0 && (CustomOptionsManager::GetInstance()->targetableArtillery.currentValue || HasAugmentation("ARTILLERY_ORDER"));
                        if (isArtillery && !manualAiming) break;
                    }
                }
            }
            else
            {
                currTargets = std::move(targets);
            }
            targets.clear();

            fireWhenReady = false;
            cooldown.first = 0.0;
            chargeLevel = 0;
            if (iShipId == 0)
            {
                G_->GetEventSystem()->AddEvent(9);
            }

            Point fireLoc = weaponVisual.GetFireLocation() + localPosition;
            if (blueprint->type == MISSILES)
            {
                if (currentFiringAngle == 0.0) fireLoc.x += 16;
                else if (currentFiringAngle == 270.0) fireLoc.y -= 16;
            }

            for (int idx = 0; idx < currTargets.size(); ++idx)
            {
                Pointf pos(fireLoc.x, fireLoc.y);

                int chargeOffset = weaponVisual.iChargeOffset * idx;
                if (weaponVisual.bRotation)
                {
                    if (weaponVisual.bMirrored) pos.y += chargeOffset;
                    else pos.y -= chargeOffset;
                }
                else
                {
                    if (weaponVisual.bMirrored) pos.x += chargeOffset;
                    else pos.x -= chargeOffset;
                }

                Projectile* proj = nullptr;

                switch (blueprint->type)
                {
                    case LASER:
                        proj = new LaserBlast(pos, iShipId, targetId, currTargets[idx]);
                        static_cast<LaserBlast*>(proj)->OnInit();
                        break;
                    case MISSILES:
                        proj = new Missile(pos, iShipId, targetId, currTargets[idx], currentFiringAngle);
                        break;
                    case BEAM:
                        proj = new BeamWeapon(pos, iShipId, targetId, currTargets[0], currTargets[1], blueprint->length, currentShipTarget, currentFiringAngle);
                        proj->SetWeaponAnimation(weaponVisual);
                        break;
                    case BOMB:
                        proj = new BombProjectile(pos, iShipId, targetId, currTargets[idx]);
                        static_cast<BombProjectile*>(proj)->superShieldBypass = HasAugmentation("ZOLTAN_BYPASS");
                        break;
                    case BURST:
                        proj = new LaserBlast(pos, iShipId, targetId, currTargets[idx]);
                        static_cast<LaserBlast*>(proj)->OnInit();
                        break;
                    default:
                        ftl_log("Invalid factory type\n");
                        break;
                }

                proj->entryAngle = currentEntryAngle; //TODO: Hook or reimplement inlined function SetEntryAngle
                proj->Initialize(*blueprint);
                proj->heading = currentFiringAngle;

                if (blueprint->boostPower.type == 2 && boostLevel > 0)
                {
                    int damageBoost = (boostLevel - 1) * blueprint->boostPower.amount;
                    if (proj->damage.iDamage > 0)
                    {
                        proj->damage.iDamage += damageBoost;
                    }
                    else if (proj->damage.iIonDamage > 0)
                    {
                        proj->damage.iIonDamage += damageBoost;
                    }
                    else if (proj->damage.iPersDamage > 0)
                    {
                        proj->damage.iPersDamage += damageBoost;
                    }
                    else if (proj->damage.iSystemDamage > 0)
                    {
                        proj->damage.iSystemDamage += damageBoost;
                    }
                }

                if (blueprint->type == BURST)
                {
                    proj->flight_animation = G_->GetAnimationControl()->GetAnimation(blueprint->miniProjectiles[idx % blueprint->miniProjectiles.size()].image);
                    proj->flight_animation.SetCurrentFrame(random32() % proj->flight_animation.info.numFrames);
                    proj->flight_animation.Stop();

                    if (!blueprint->miniProjectiles[idx % blueprint->miniProjectiles.size()].fake)
                    {
                        proj->bBroadcastTarget = iShipId == 0;
                    }
                    else
                    {
                        proj->damage.iDamage = 0;
                        proj->damage.iShieldPiercing = 0;
                        proj->damage.fireChance = 0;
                        proj->damage.breachChance = 0;
                        proj->damage.stunChance = 0;
                        proj->damage.iIonDamage = 0;
                        proj->damage.iSystemDamage = 0;
                        proj->damage.iPersDamage = 0;
                        proj->damage.bHullBuster = false;
                        proj->damage.ownerId = -1;
                        proj->damage.selfId = -1;
                        proj->damage.bLockdown = false;
                        proj->damage.crystalShard = false;
                        proj->damage.bFriendlyFire = true;
                        proj->damage.iStun = 0;
                        proj->death_animation.fScale = 0.25;
                    }
                }
                else
                {
                    proj->flight_animation = flight_animation;
                }

                if (blueprint->type == BOMB)
                {
                    //TODO: Hook EffectsBlueprint::RandomSoundChoice
                    std::string sound = blueprint->effects.launchSounds[random32() % blueprint->effects.launchSounds.size()];
                    G_->GetSoundControl()->PlaySoundMix(sound, -1.0, false);
                }

                if (autoFiring && targets.empty())
                {
                    targets = lastTargets;
                    if (blueprint->chargeLevels > 1) targets.resize(1);
                }
                queuedProjectiles.push_back(proj);
                if (blueprint->type == BEAM) break;
            }
        }
    }

    baseCooldown = blueprint->cooldown;
    if (blueprint->boostPower.type == 1 && boostLevel > 0)
    {
        baseCooldown = blueprint->cooldown - boostLevel * blueprint->boostPower.amount;
    }
    if (!powered)
    {
        if (cooldown.first <= 0.f)
        {
            chargeLevel = 0;
            cooldown.first = 0;
            boostLevel = 0;
        }
        else
        {
            if (cooldown.second <= cooldown.first && chargeLevel > 0)
            {
                chargeLevel -= 1;
            }
            cooldown.first -= G_->GetCFPS()->GetSpeedFactor() * 0.375;
            cooldown.first = std::max( 0.f, cooldown.first);
        }
        fireWhenReady = false;
        targets.clear();
        lastTargets.clear();
        for (Projectile* queuedProjectile : queuedProjectiles)
        {
            delete queuedProjectile;
        }
        queuedProjectiles.clear();
        ClearAiming();
    }
    else if (iHackLevel < 2 || subCooldown.first < subCooldown.second)
    {
        if (currentShipTarget == nullptr || !currentShipTarget->IsCloaked())
        {
            if (subCooldown.second <= subCooldown.first)
            {
                float oldFirst = cooldown.first;
                float oldSecond = cooldown.second;

                float reloaders = GetAugmentationValue("AUTO_COOLDOWN");
                cooldown.first += G_->GetCFPS()->GetSpeedFactor() * 0.0625 * (1 + reloaders);
                cooldown.first = std::min(cooldown.second, cooldown.first);
                if (cooldown.second == cooldown.first && (oldFirst < oldSecond || oldSecond == 0) && chargeLevel < blueprint->chargeLevels)
                {
                    chargeLevel += 1;
                    if (chargeLevel < blueprint->chargeLevels) cooldown.first = 0;
                }
                else
                {
                    subCooldown.first += G_->GetCFPS()->GetSpeedFactor() * 0.0625;
                    subCooldown.first = std::min(subCooldown.first, subCooldown.second);
                }

            }
        }
    }
    else
    {
        if (cooldown.second <= cooldown.first && chargeLevel > 0) chargeLevel -= 1;
        cooldown.first -= G_->GetCFPS()->GetSpeedFactor() * 0.0625;
        cooldown.first = std::max(cooldown.first, 0.f);
    }

    weaponVisual.SetChargedLevel(cooldown.second == 0 ? 1.f : cooldown.first / cooldown.second);
    weaponVisual.Update();
    weaponVisual.SetPowered(powered);
    if (!queuedProjectiles.empty())
    {
        weaponVisual.StartFire();
    }
    if (blueprint->chargeLevels < 2)
    {
        if (blueprint->boostPower.count > 0) weaponVisual.SetBoostLevel(boostLevel - 1);
    }
    else
    {
        weaponVisual.SetBoostLevel(chargeLevel - 1);
    }
}
//Handle WarningMessage for power attempts
static WarningMessage* shotLimitMessage = nullptr;

HOOK_METHOD(WeaponControl, constructor, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> WeaponControl::constructor -> Begin (CustomWeapons.cpp)\n")
    super();

    shotLimitMessage = new WarningMessage();
    GL_Color warningColor = COLOR_BUTTON_ON;
    //Not sure why this adjustment is necessary
    warningColor.r *= 255.f;
    warningColor.g *= 255.f;
    warningColor.b *= 255.f;
    shotLimitMessage->InitText(TextString("warning_shot_limit", false), Point(203, -25), 2.0, warningColor, true, false);
}

HOOK_METHOD(WeaponControl, RenderWarnings, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> WeaponControl::RenderWarnings -> Begin (CustomWeapons.cpp)\n")
    super();
    CSurface::GL_Translate(location.x, location.y);
    shotLimitMessage->OnRender();
    CSurface::GL_Translate(-location.x, -location.y);
}
HOOK_METHOD(WeaponControl, OnLoop, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> WeaponControl::OnLoop -> Begin (CustomWeapons.cpp)\n")
    super();
    shotLimitMessage->OnLoop();
}

HOOK_METHOD(WeaponControl, SelectArmament, (unsigned int armamentSlot) -> void)
{
    LOG_HOOK("HOOK_METHOD -> WeaponControl::SelectArmament -> Begin (CustomWeapons.cpp)\n")
    shotLimitMessage->Stop();

    WeaponBox* box = static_cast<WeaponBox*>(boxes[armamentSlot]);

    if (box->pWeapon->HitShotLimit() && box->pWeapon->powered)
    {
        shotLimitMessage->Start();
        missileMessage.Stop();
        systemMessage.Stop();
    }
    else
    {
        super(armamentSlot);
    }
}

//Vanilla doesn't save shotsFiredAtTarget so we handle this here
HOOK_METHOD(ProjectileFactory, SaveState, (int fd) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ProjectileFactory::SaveState -> Begin (CustomWeapons.cpp)\n")
    super(fd);
    FileHelper::writeInt(fd, shotsFiredAtTarget);
}
HOOK_METHOD(ProjectileFactory, LoadState, (int fd) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ProjectileFactory::LoadState -> Begin (CustomWeapons.cpp)\n")
    super(fd);
    shotsFiredAtTarget = FileHelper::readInteger(fd);
}


// Prevent enemy charge bar (sensor lvl 3+ ability) from framing off the right, top and bottom side of the screen.
Point g_enemyShipCorner;

HOOK_METHOD(WeaponAnimation, RenderChargeBar, (float alpha) -> void)
{
    LOG_HOOK("HOOK_METHOD -> WeaponAnimation::RenderChargeBar -> Begin (CustomWeapons.cpp)\n")
    int bar_x = bMirrored ? g_enemyShipCorner.x + renderPoint.x + mountPoint.x - (int)(anim.info.frameWidth * anim.fScale) - 18
                            : g_enemyShipCorner.x + renderPoint.x - mountPoint.x + (int)(anim.info.frameWidth * anim.fScale) + 10;
    int bar_y = g_enemyShipCorner.y + renderPoint.y - mountPoint.y;

    // charge box size is 8 x 35
    if (bar_x < 1274 && -1 < bar_y && bar_y < 687) return super(alpha);

    int x = 1273 < bar_x ? 1273 - bar_x : 0;
    int y = 0;
    if (bar_y < 0) y = -bar_y;
    else if (686 < bar_y) y = 686 - bar_y;

    CSurface::GL_Translate(x, y);
    super(alpha);
    CSurface::GL_Translate(-x, -y);
}

HOOK_METHOD(ShipManager, RenderChargeBars, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::RenderChargeBars -> Begin (CustomWeapons.cpp)\n")
    g_enemyShipCorner = G_->GetCApp()->gui->combatControl.position + G_->GetCApp()->gui->combatControl.targetPosition + ship.GetShipCorner();
    super();
}

