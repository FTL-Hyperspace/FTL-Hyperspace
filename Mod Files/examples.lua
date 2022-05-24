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
    tideMode_seconds = tideMode_seconds + Hyperspace.FPS.speedFactor
    if tideMode_seconds > 10 then
        tideMode_seconds = 0
    end

    if tideMode_seconds > 5 then
        Graphics.CSurface:GL_PushMatrix()
        Graphics.CSurface:GL_Scale(0.5, 0.5, 1.0)
    elseif tideMode_seconds > 5 then
    end
end
function tidePod_renderEffects_after()
    if tideMode_seconds > 5 then
        Graphics.CSurface:GL_PopMatrix()
    end
end
script.on_render_event(Defines.RenderEvents.LAYER_BACKGROUND, tidePod_renderEffects_before, tidePod_renderEffects_after)
