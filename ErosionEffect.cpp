#include "Global.h"
#include "Room_Extend.h"
#include "CustomDamage.h"
#include "TemporalSystem.h"

#include <boost/lexical_cast.hpp>

ErosionEffect ErosionEffect::defaultErosionEffect = ErosionEffect();

float ErosionEffect::growBreachMultiplier = 1.f;
float ErosionEffect::newBreachDamage = 100.f;
float ErosionEffect::newBreachRequirement = 100.f;
bool ErosionEffect::canDilate = false;

void ErosionEffect::ParseErosionEffect(rapidxml::xml_node<char>* node)
{
    for (auto child = node->first_node(); child; child = child->next_sibling())
    {
        std::string name = child->name();
        std::string val = child->value();
        if (name == "speed")
        {
            this->erosionSpeed = boost::lexical_cast<float>(val);
        }
        if (name == "maxSpeed")
        {
            this->erosionSpeedMax = boost::lexical_cast<float>(val);
        }
        if (name == "time")
        {
            this->erosionTime = boost::lexical_cast<float>(val);
        }
        if (name == "maxTime")
        {
            this->erosionTimeMax = boost::lexical_cast<float>(val);
        }
        if (name == "systemRepairMultiplier")
        {
            this->systemRepairMultiplier = boost::lexical_cast<float>(val);
        }
        if (name == "erodeShields")
        {
            this->erodeShields = EventsParser::ParseBoolean(val);
        }
        if (name == "roomAnim")
        {
            this->animation = new RoomAnimDef();
            this->animation->ParseRoomAnimNode(child);
        }
    }
}

HOOK_METHOD_PRIORITY(ShipManager, DamageArea, 500, (Pointf location, Damage dmg, bool forceHit) -> bool)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::DamageArea -> Begin (ErosionEffect.cpp)\n")

    bool ret = super(location, dmg, forceHit);

    if (ret)
    {
        auto custom = CustomDamageManager::currentWeaponDmg;

        if (custom)
        {
            int rng = random32() % 10;

            if (rng < custom->def->erosionChance)
            {
                int roomId = ship.GetSelectedRoomId(location.x, location.y, true);

                if (roomId != -1)
                {
                    auto ex = RM_EX(ship.vRoomList[roomId]);
                    ex->StartErosion(custom->def->erosionEffect);
                }
            }
        }
    }

    return ret;
}

HOOK_METHOD(Shields, CollisionReal, (float x, float y, Damage damage, bool force) -> CollisionResponse)
{
    LOG_HOOK("HOOK_METHOD -> Shields::CollisionReal -> Begin (ErosionEffect.cpp)\n")
    CollisionResponse ret = super(x, y, damage, force);

    // todo: check this hook when merging into lua-callbacks

    if (ret.collision_type == 2) // 2 is a shield hit, 0 is no collision, 3 is a miss
    {
        auto custom = CustomDamageManager::currentWeaponDmg;

        if (custom && custom->def->erosionEffect.erodeShields)
        {
            // check for ion beam fix to check erosion proc
            if (!custom->def->ionBeamFix || !CustomDamageManager::currentProjectile || CustomDamageManager::currentProjectile->GetType() != 5 || ((BeamWeapon*)CustomDamageManager::currentProjectile)->bDamageSuperShield)
            {
                int rng = random32() % 10;

                if (rng < custom->def->erosionChance)
                {
                    int roomId = GetRoomId(); // get room ID of shields

                    if (roomId != -1)
                    {
                        ShipManager *shipManager = G_->GetShipManager(_shipObj.iShipId);
                        if (shipManager)
                        {
                            Room_Extend *ex = RM_EX(shipManager->ship.vRoomList[roomId]);
                            ex->StartErosion(custom->def->erosionEffect);
                        }
                    }
                }
            }
        }
    }

    return ret;
}

void Room_Extend::StartErosion(const ErosionEffect& effect)
{
    if (effect.erosionTime > 0.f) // erosion increase
    {
        if (effect.erosionTimeMax > erosion.timer)
        {
            erosion.timer = std::min(erosion.timer + effect.erosionTime, effect.erosionTimeMax);
        }
    }
    else // erosion reduction
    {
        erosion.timer = std::max(0.f, erosion.timer + effect.erosionTime);
    }

    if (effect.erosionSpeed > 0.f) // erosion increase
    {
        if (effect.erosionSpeedMax > erosion.speed)
        {
            erosion.speed = std::min(erosion.speed + effect.erosionSpeed, effect.erosionSpeedMax);
        }
    }
    else // erosion reduction
    {
        erosion.speed = std::max(0.f, erosion.speed + effect.erosionSpeed);
    }

    erosion.systemRepairMultiplier = std::min(erosion.systemRepairMultiplier, effect.systemRepairMultiplier);

    if (effect.animation && !erosion.anim)
    {
        //delete erosion.anim;
        erosion.anim = new RoomAnim(*effect.animation, orig);
    }
}

void Room_Extend::StopErosion()
{
    erosion.timer = 0.f;
    erosion.speed = 0.f;
    erosion.systemRepairMultiplier = 1.f;
    delete erosion.anim;
    erosion.anim = nullptr;
    erosion.amount = 0.f;
}

HOOK_METHOD(ShipManager, UpdateEnvironment, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::UpdateEnvironment -> Begin (ErosionEffect.cpp)\n")
    super();

    for (Room *i : ship.vRoomList)
    {
        Room_Extend *ex = RM_EX(i);

        if (ex->erosion.timer > 0.f)
        {
            if (ErosionEffect::canDilate) g_dilationAmount = GetRoomDilationAmount(g_sysDilationRooms, i->iRoomId);

            float speedFactor = G_->GetCFPS()->GetSpeedFactor();
            float erosionAmount = ex->erosion.speed * speedFactor;

            ShipSystem *sys = GetSystemInRoom(i->iRoomId);
            if (sys != nullptr)
            {
                // first counter any system repair
                if (sys->fRepairOverTime >= erosionAmount)
                {
                    sys->fRepairOverTime -= erosionAmount;
                    erosionAmount = 0.f;
                }
                else
                {
                    // counter system repair when it is less than erosion amount
                    if (sys->fRepairOverTime > 0.f)
                    {
                        erosionAmount -= sys->fRepairOverTime;
                        sys->fRepairOverTime = 0.f;
                    }
                    // damage the system
                    if (sys->healthState.first > 0)
                    {
                        sys->fDamageOverTime += erosionAmount;
                        erosionAmount = 0.f;
                    }
                }
                sys->PartialDamage(0.f); // to perform the usual checks and set damagedLastFrame
            }
            if (erosionAmount > 0.f)
            {
                // check for breaches
                std::vector<OuterHull*> breaches;
                for (OuterHull* breach : ship.vOuterWalls)
                {
                    if (breach->roomId == i->iRoomId && breach->fDamage > 0.f) // breached tiles
                    {
                        breaches.push_back(breach);
                    }
                }
                // expand any existing partial breaches
                for (OuterHull* breach : breaches)
                {
                    float diff = breach->fDamage < breach->fMaxDamage;
                    if (diff > 0.f)
                    {
                        if (diff >= erosionAmount * ErosionEffect::growBreachMultiplier)
                        {
                            breach->fDamage += erosionAmount * ErosionEffect::growBreachMultiplier;
                            erosionAmount = 0.f;
                            break;
                        }
                        else
                        {
                            breach->fDamage = breach->fMaxDamage;
                            erosionAmount -= diff / ErosionEffect::growBreachMultiplier;
                        }
                    }
                }
                // check unbreached tiles
                if (erosionAmount > 0.f)
                {
                    ex->erosion.amount += erosionAmount;
                    breaches.clear();
                    for (OuterHull* breach : ship.vOuterWalls)
                    {
                        if (breach->roomId == i->iRoomId && breach->fDamage <= 0.f) // unbreached tiles
                        {
                            breaches.push_back(breach);
                        }
                    }
                    // every tile is fully breached already; don't add any more erosion amount
                    if (breaches.empty())
                    {
                        ex->erosion.amount = 0.f;
                    }
                    // open a new breach
                    else if (ex->erosion.amount >= ErosionEffect::newBreachRequirement)
                    {
                        int j = random32()%breaches.size();
                        OuterHull *breach = breaches[j];
                        Point breach_pos = ShipGraph::TranslateToGrid(breach->pLoc.x, breach->pLoc.y);
                        ship.BreachSpecificHull(breach_pos.x, breach_pos.y);
                        breach->fDamage = std::min(ErosionEffect::newBreachDamage, breach->fMaxDamage);
                        ex->erosion.amount = 0.f;
                    }
                }
            }

            ex->erosion.timer -= speedFactor * 0.0625f;

            if (ex->erosion.timer <= 0.f)
            {
                ex->StopErosion();
            }

            g_dilationAmount = 0;
        }
    }
}

HOOK_METHOD(ShipSystem, PartialRepair, (float speed, bool autoRepair) -> bool)
{
    LOG_HOOK("HOOK_METHOD -> ShipSystem::PartialRepair -> Begin (ErosionEffect.cpp)\n")

    if (roomId > -1)
    {
        ShipManager *shipManager = G_->GetShipManager(_shipObj.iShipId);
        if (shipManager && roomId < shipManager->ship.vRoomList.size())
        {
            Room *room = shipManager->ship.vRoomList[roomId];
            Room_Extend *ex = RM_EX(room);

            if (ex->erosion.timer > 0.f)
            {
                speed *= ex->erosion.systemRepairMultiplier;
            }
        }
    }

    return super(speed, autoRepair);
}

/*
HOOK_METHOD(Ship, OnRenderBreaches, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> Ship::OnRenderBreaches -> Begin (ErosionEffect.cpp)\n")
    for (auto i : vRoomList)
    {
        auto ex = RM_EX(i);

        if (ex->currentErosion != nullptr)
        {
            if (!ex->erosionAnim)
            {
                ex->erosionAnim = new Animation(G_->GetAnimationControl()->GetAnimation(ex->currentErosion->animation));

                ex->erosionAnim->SetCurrentFrame(0);
                ex->erosionAnim->tracker.SetLoop(true, 0);
                ex->erosionAnim->Start(true);
            }

            CSurface::GL_PushMatrix();

            // top

            for (int xPos = 0; xPos < i->rect.w / 35; xPos++)
            {
                CSurface::GL_PushMatrix();

                CSurface::GL_Translate(i->rect.x + xPos * 35, i->rect.y + i->rect.h - 35);
                ex->erosionAnim->OnRender(1.f, COLOR_WHITE, false);

                CSurface::GL_PopMatrix();
            }

            // bottom

            for (int xPos = 0; xPos < i->rect.w / 35; xPos++)
            {
                CSurface::GL_PushMatrix();

                CSurface::GL_Translate(i->rect.x + xPos * 35 + 35, i->rect.y + 35.f);
                CSurface::GL_Rotate(180.f, 0.f, 0.f, 1.f);
                ex->erosionAnim->OnRender(1.f, COLOR_WHITE, false);

                CSurface::GL_PopMatrix();
            }

            // left

            for (int yPos = 0; yPos < i->rect.h / 35; yPos++)
            {
                CSurface::GL_PushMatrix();

                CSurface::GL_Translate(i->rect.x + 35, i->rect.y + yPos * 35.f);
                CSurface::GL_Rotate(90.f, 0.f, 0.f, 1.f);
                ex->erosionAnim->OnRender(1.f, COLOR_WHITE, false);

                CSurface::GL_PopMatrix();
            }

            // right

            for (int yPos = 0; yPos < i->rect.h / 35; yPos++)
            {
                CSurface::GL_PushMatrix();

                CSurface::GL_Translate(i->rect.x + i->rect.w - 35.f, i->rect.y + yPos * 35.f + 35.f);
                CSurface::GL_Rotate(-90.f, 0.f, 0.f, 1.f);
                ex->erosionAnim->OnRender(1.f, COLOR_WHITE, false);

                CSurface::GL_PopMatrix();
            }

            CSurface::GL_PopMatrix();
        }
    }

    super();
}
*/
