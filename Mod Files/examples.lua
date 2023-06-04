mods.hsFun = {}

print("Hyperspace version from Lua: " .. tostring(Hyperspace.version))
print(Hyperspace.version)
print(Hyperspace.version:toVersionString()) -- same as Hyperspace.version's tostring
print(Hyperspace.version:toIdentifierString())
print(Hyperspace.version.major)
print(Hyperspace.version.minor)
print(Hyperspace.version.patch)
print(Hyperspace.version:isFeatureBuild())
print(Hyperspace.version:getFeatureName())
print(Hyperspace.version:getDeprecatedIntegerVersion())

-- Run stuff when START_BEACON event is loaded from a save to re-render the background hangar
function fixTheHangar()
    local background = Hyperspace.world.space.currentBack
    background.w = 0
    background.h = 0
    background.x = 0
    background.y = 0
    background.rot = 0
    background.tex = Hyperspace.resources:GetImageId("stars_sectors/bg_start.png")
end
script.on_game_event("START_BEACON", true, fixTheHangar)

-- Run stuff on DETERGENT_MODE initialization to start the world spinning
mods.hsFun.tideMode = false -- TODO: In the future this would need to be in currentRun.tideMode to save for the entire run
function tidePod_eat()
    mods.hsFun.tideMode = true
end
script.on_game_event("DETERGENT_MODE", false, tidePod_eat)

local tideMode_seconds = 0
function tidePod_renderEffects_before()
    if mods.hsFun.tideMode then
        tideMode_seconds = tideMode_seconds + (Hyperspace.FPS.SpeedFactor / 16)
        if tideMode_seconds > 10 then
            tideMode_seconds = 0
        end

        if tideMode_seconds > 5 then
            Graphics.CSurface.GL_PushMatrix()
            Graphics.CSurface.GL_Scale(1.1, 1.1, 1.0)
        end
    else
end
function tidePod_renderEffects_after()
    if mods.hsFun.tideMode then
        if tideMode_seconds > 5 then
            Graphics.CSurface.GL_PopMatrix()
        end
    end
end
script.on_render_event(Defines.RenderEvents.LAYER_BACKGROUND, tidePod_renderEffects_before, tidePod_renderEffects_after)

-----
-- Damage the second artillery system on a ship (or repair with a negative number)
-- Note! Even though Lua uses arrays indexed at 1, things passed over from C start with indexes of 0! So 1 is actually the second artillerySystem here!
Hyperspace.ships.player.artillerySystems[1]:AddDamage(1) -- Add one bar of damage, -1 would repair one bar

-- Lose 50% power on artillery system #2 when hitting this event (you could easily use random32 to do this to choose between artilleries, or to choose between which system you select)
-- NOTE: It looks like `SetPowerLoss` and `SetPowerCap` are similar, not sure the difference yet.
function loseArty2()
    local artillery = Hyperspace.ships.player.artillerySystems
    if artillery then
        if artillery:size() > 1 then
            local curMaxPower = artillery[1]:GetMaxPower()
            artillery[1]:SetPowerLoss(curMaxPower / 2)
        end
    end
end
script.on_game_event("SOME_EVENT_WHERE_WE_LOSE_ARTY_2", false, loseArty2)

-- Upgrade a system 2 levels, by force (does not pay attention to the max levels declared in the XML, you can exceed what you normally allow the ship to upgrade to)
Hyperspace.ships.player.oxygenSystem:UpgradeSystem(2)


-- Haven't figured the corect image path for this one yet (or if x & y need to be values other than 0) but this should set the floor image texture of ArtillerySystem #2 assuming it loaded a correct texture
Hyperspace.ships.player.artillerySystems[1].interiorImage = Hyperspace.Resources:CreateImagePrimitiveString("img/ship/interior/room_battery_orchid_2.png", 0, 0, 0, Graphics.GL_Color(0.5, 0.5, 0.5, 1.0), 1.0, false)
