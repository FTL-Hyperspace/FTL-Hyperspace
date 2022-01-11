#include "CustomCrystalShard.h"
#include "CustomAugments.h"
#include "Global.h"
#include <math.h>
#include <algorithm>

bool g_crystalShardFix = true;

void ShipManager_CheckCustomCrystalAugment(ShipManager* _this, std::string weapon, float chance, Pointf pos)
{
    if (random32()%100 < chance*100.f)
    {
        int targetId = _this->current_target->iShipId;

        SoundControl* soundControl = G_->GetSoundControl();

        std::vector<Pointf> bombTargets = std::vector<Pointf>();
        unsigned int bombTargetIdx = 0;

        WeaponBlueprint *bp = G_->GetBlueprints()->GetWeaponBlueprint(weapon);
        if (bp == nullptr) return;

        int numShots = bp->type == 2 ? 1 : bp->shots;

        for (int j = 0; j < numShots; j++)
        {
            switch (bp->type)
            {
            case 0:
                {
                    Pointf targetPos = _this->current_target->GetRandomRoomCenter();
                    float heading = random32()%360;

                    LaserBlast *projectile = new LaserBlast(pos,_this->iShipId,targetId,targetPos);
                    projectile->heading = heading;
                    projectile->OnInit();
                    projectile->Initialize(*bp);

                    projectile->damage.crystalShard = true;
                    if (!g_crystalShardFix) projectile->ownerId = -1;

                    _this->superBarrage.push_back(projectile);
                }
                break;
            case 1:
                {
                    Pointf targetPos = _this->current_target->GetRandomRoomCenter();
                    float heading = random32()%360;

                    Missile *projectile = new Missile(pos,_this->iShipId,targetId,targetPos,heading);
                    projectile->Initialize(*bp);

                    projectile->damage.crystalShard = true;
                    if (!g_crystalShardFix) projectile->ownerId = -1;

                    _this->superBarrage.push_back(projectile);
                }
                break;
            case 2:
                {
                    Pointf targetPos = _this->current_target->GetRandomRoomCenter();
                    Pointf finalPos;
                    do
                    {
                        finalPos = _this->current_target->GetRandomRoomCenter();
                    }
                    while (finalPos.x == targetPos.x && finalPos.y == targetPos.y);
                    float heading = random32()%360;

                    BeamWeapon *projectile = new BeamWeapon(pos,_this->iShipId,targetId,targetPos,finalPos,bp->length,&_this->current_target->_targetable);
                    projectile->heading = heading;
                    projectile->entryAngle = random32()%360;

                    float theta = heading * 0.01745329f;
                    projectile->sub_end.x = pos.x + 2000.f*cos(theta);
                    projectile->sub_end.y = pos.y + 2000.f*sin(theta);

                    projectile->damage.crystalShard = true;
                    if (!g_crystalShardFix) projectile->ownerId = -1;

                    projectile->Initialize(*bp);

                    _this->superBarrage.push_back(projectile);
                }
                break;
            case 3:
                {
                    if (bombTargetIdx >= bombTargets.size())
                    {
                        bombTargets.clear();
                        int numRooms = ShipGraph::GetShipInfo(targetId)->RoomCount();
                        bombTargets.reserve(numRooms);
                        for (int k=0; k<numRooms; ++k) bombTargets.push_back(_this->current_target->GetRoomCenter(k));

                        std::random_shuffle(bombTargets.begin(), bombTargets.end(), [](int i){return random32()%i;});
                        bombTargetIdx = 0;
                    }

                    BombProjectile *projectile = new BombProjectile(pos,_this->iShipId,targetId,bombTargets[bombTargetIdx++]);
                    projectile->superShieldBypass = _this->HasEquipment("ZOLTAN_BYPASS");
                    projectile->Initialize(*bp);
                    projectile->flight_animation.tracker.loop = false;

                    projectile->damage.crystalShard = true;
                    if (!g_crystalShardFix) projectile->ownerId = -1;

                    _this->superBarrage.push_back(projectile);
                }
                break;
            case 4:
                {
                    Pointf targetPos = _this->current_target->GetRandomRoomCenter();
                    float heading = random32()%360;
                    float entryAngle = random32()%360;

                    for (auto &k : bp->miniProjectiles)
                    {
                        float r = sqrt(random32()/2147483648.f) * bp->radius;
                        float theta = random32()%360 * 0.01745329f;
                        Pointf ppos = {targetPos.x + r*cos(theta), targetPos.y + r*sin(theta)};
                        LaserBlast *projectile = new LaserBlast(pos,_this->iShipId,targetId,ppos);
                        projectile->heading = heading;
                        projectile->OnInit();
                        projectile->entryAngle = entryAngle;
                        projectile->Initialize(*bp);

                        projectile->flight_animation = G_->GetAnimationControl()->GetAnimation(k.image);

                        if (k.fake)
                        {
                            projectile->damage.iDamage = 0;
                            projectile->damage.iShieldPiercing = 0;
                            projectile->damage.fireChance = 0;
                            projectile->damage.breachChance = 0;
                            projectile->damage.stunChance = 0;
                            projectile->damage.iIonDamage = 0;
                            projectile->damage.iSystemDamage = 0;
                            projectile->damage.iPersDamage = 0;
                            projectile->damage.bHullBuster = false;
                            projectile->damage.ownerId = -1;
                            projectile->damage.selfId = -1;
                            projectile->damage.bLockdown = false;
                            projectile->damage.crystalShard = false;
                            projectile->damage.bFriendlyFire = true;
                            projectile->damage.iStun = 0;
                            projectile->death_animation.fScale = 0.25;
                        }
                        else
                        {
                            projectile->bBroadcastTarget = _this->iShipId == 0;
                        }

                        projectile->damage.crystalShard = true;
                        if (!g_crystalShardFix) projectile->ownerId = -1;

                        _this->superBarrage.push_back(projectile);
                    }

                }
                break;
            }
            if (!bp->effects.launchSounds.empty())
            {
                soundControl->PlaySoundMix(bp->effects.launchSounds[random32()%bp->effects.launchSounds.size()], -1.f, false);
            }
        }
    }
}

HOOK_METHOD(ShipManager, CheckCrystalAugment, (Pointf pos) -> void)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::CheckCrystalAugment -> Begin (CustomCrystalShard.cpp)\n")
    if (g_crystalShardFix)
    {
        int n = superBarrage.size();
        super(pos);
        if (superBarrage.size() > n)
        {
            superBarrage.back()->ownerId = iShipId;
        }
    }
    else
    {
        super(pos);
    }

    if (current_target == nullptr) return;

    std::unordered_map<std::string, std::pair<float,float>> shardList = std::unordered_map<std::string, std::pair<float,float>>(); // weapon, nostack, stack

    CustomAugmentManager* customAug = CustomAugmentManager::GetInstance();
    std::unordered_map<std::string, int> *augList = customAug->GetShipAugments(iShipId);

    for (auto& aug : *augList)
    {
        if (aug.second > 0)
        {
            if (customAug->IsAugment(aug.first))
            {
                auto augDef = customAug->GetAugmentDefinition(aug.first);

                for (AugmentCrystalShard& shard : augDef->crystalShard)
                {
                    std::pair<float,float>& shardChancePair = shardList[shard.weapon];
                    switch (shard.stacking)
                    {
                    case 0:
                        shardChancePair.first = std::max(shardChancePair.first, shard.chance);
                        break;
                    case 1:
                        shardChancePair.second += aug.second * shard.chance;
                        break;
                    case 2:
                        for (int i=0; i<aug.second; ++i)
                        {
                            ShipManager_CheckCustomCrystalAugment(this, shard.weapon, shard.chance, pos);
                        }
                        break;
                    }
                }
            }
        }
    }

    for (auto& it : shardList)
    {
        ShipManager_CheckCustomCrystalAugment(this, it.first, it.second.first + it.second.second, pos);
    }
}
