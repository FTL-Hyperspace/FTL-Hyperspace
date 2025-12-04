--[[
Custom system lua implementation example (by Arc)
This example demonstrates how to create a custom system that can absorb ion damage from other systems.

-- Inside blueprints.xml.append --
<systemBlueprint name="absorber">
	<type>absorber</type>
	<title>Ion Absorber</title>
	<desc>Absorbers any Ion damage from a target system, Ion damage is transfered to the absorber system.</desc>
	<startPower>1</startPower>
	<maxPower>3</maxPower>
	<rarity>1</rarity>
	<upgradeCost>
		<level>40</level> <!-- level 2 -->
		<level>80</level> <!-- level 3 -->
		<level>120</level> <!-- level 4 - Normally inaccessible -->
	</upgradeCost>
	<cost>30</cost>
</systemBlueprint>
-- Inside blueprints.xml.append --

-- Inside hyperspace.xml --
<scripts>
    <script>data/example_system.lua</script>
</scripts>

<customSystems>
    <customSystem id="absorber"/>
</customSystems>
-- Inside hyperspace.xml --
]]

-- helper method to iterate through cvector
local function vter(cvec)
    local i = -1
    local n = cvec:size()
    return function()
        i = i + 1
        if i < n then return cvec[i] end
    end
end

--Handles tooltips and mousever descriptions per level
local function get_level_description_absorber(systemId, level, tooltip)
    if systemId == Hyperspace.ShipSystem.NameToSystemId("absorber") then
        return string.format("Takes %i Extra Ion Damage", 3 - level)
    end
end

script.on_internal_event(Defines.InternalEvents.GET_LEVEL_DESCRIPTION, get_level_description_absorber)

--Utility function to check if the SystemBox instance is for our customs system
local function is_absorber(systemBox)
    local systemName = Hyperspace.ShipSystem.SystemIdToName(systemBox.pSystem.iSystemType)
    return systemName == "absorber" 
end
--Offsets of the button
local absorberButtonOffset_x = 37
local absorberButtonOffset_y = -50
--Handles initialization of custom system box
local function absorber_construct_system_box(systemBox)
    if is_absorber(systemBox) then
        systemBox.extend.xOffset = 54 --NOTE: SystemBox_Extend::xOffset is depreciated and should instead use ShipSystem_Extend::xOffset

        local activateButton = Hyperspace.Button()
        activateButton:OnInit("systemUI/button_cloaking2", Hyperspace.Point(absorberButtonOffset_x, absorberButtonOffset_y))
        activateButton.hitbox.x = 11
        activateButton.hitbox.y = 36
        activateButton.hitbox.w = 20
        activateButton.hitbox.h = 30
        systemBox.table.activateButton = activateButton

        systemBox.pSystem.bBoostable = false -- make the system unmannable
    end
end

script.on_internal_event(Defines.InternalEvents.CONSTRUCT_SYSTEM_BOX, absorber_construct_system_box)

--Handles mouse movement
local function absorber_mouse_move(systemBox, x, y)
    if is_absorber(systemBox) then
        local activateButton = systemBox.table.activateButton
        activateButton:MouseMove(x - absorberButtonOffset_x, y - absorberButtonOffset_y, false)
    end
    return Defines.Chain.CONTINUE
end
script.on_internal_event(Defines.InternalEvents.SYSTEM_BOX_MOUSE_MOVE, absorber_mouse_move)

local absorber_targetting = false
local roomAtMouse = -1
local cursorImage = Hyperspace.Resources:CreateImagePrimitiveString("mouse/pointer_absorber.png", 0, 0, 0, Graphics.GL_Color(1, 1, 1, 1), 1.0, false)

--Handles click events 
local function absorber_click(systemBox, shift)
    if is_absorber(systemBox) then
        local activateButton = systemBox.table.activateButton
        if activateButton.bHover and activateButton.bActive then
            absorber_targetting = true --Indicate that we are now targetting the system
        elseif Hyperspace.Global.GetInstance():GetCApp().world.bStartedGame and absorber_targetting == true then 
            absorber_targetting = false 
            if roomAtMouse >= 0 then
                local shipManager = Hyperspace.ships.player
                local system = shipManager:GetSystemInRoom(roomAtMouse) --Get the system we're targetting
                if system and system.iLockCount > 0 then
                    local lockAmount = 3 - systemBox.pSystem:GetEffectivePower()
                    lockAmount = lockAmount + system.iLockCount
                    system:LockSystem(0) -- remove ionization
                    if lockAmount > 0 then
                        Hyperspace.Sounds:PlaySoundMix("ionHit3", -1, false) --play sound and lock the system
                        systemBox.pSystem:LockSystem(lockAmount)
                    end
                end
            end
            roomAtMouse = -1
        end
    end
    return Defines.Chain.CONTINUE
end
script.on_internal_event(Defines.InternalEvents.SYSTEM_BOX_MOUSE_CLICK, absorber_click)

--handle rendering while targetting the system
script.on_render_event(Defines.RenderEvents.MOUSE_CONTROL, function()
    if absorber_targetting == true then
        local mousePos = Hyperspace.Mouse.position 
        local combatControl = Hyperspace.App.gui.combatControl
        roomAtMouse = combatControl.selectedSelfRoom -- get the room we're hoving over

        Graphics.CSurface.GL_PushMatrix()
        Graphics.CSurface.GL_Translate(mousePos.x,mousePos.y,0) -- render mouse icon for absorber system
        Graphics.CSurface.GL_RenderPrimitive(cursorImage)
        Graphics.CSurface.GL_PopMatrix()
    end
end, function() end)

script.on_render_event(Defines.RenderEvents.SHIP_FLOOR, function() end, function(ship)
    if ship.iShipId == 0 then
        for room in vter(ship.vRoomList) do
            if room.iRoomId == roomAtMouse then
                Graphics.CSurface.GL_RenderPrimitive(room.highlightPrimitive) -- highlight the room
                Graphics.CSurface.GL_RenderPrimitive(room.highlightPrimitive2)
            end
        end
    end
end)

--handle cancelling targetting by right clicking
script.on_internal_event(Defines.InternalEvents.ON_MOUSE_R_BUTTON_DOWN, function(x,y) 
    if absorber_targetting == true then
        absorber_targetting = false
        roomAtMouse = -1
    end
    return Defines.Chain.CONTINUE
end)

--Utility function to see if the system is ready for use
local function absorber_ready(shipSystem)
   return not shipSystem:GetLocked() and shipSystem:Functioning()
end
--Initializes primitive for UI elements
local buttonBase
script.on_init(function()
    buttonBase = Hyperspace.Resources:CreateImagePrimitiveString("systemUI/button_cloaking2_base.png", absorberButtonOffset_x, absorberButtonOffset_y, 0, Graphics.GL_Color(1, 1, 1, 1), 1, false)
end)

--Handles custom rendering
local function absorber_render(systemBox, ignoreStatus)
    if is_absorber(systemBox) then
        local activateButton = systemBox.table.activateButton
        activateButton.bActive = absorber_ready(systemBox.pSystem)
        Graphics.CSurface.GL_RenderPrimitive(buttonBase)
        systemBox.table.activateButton:OnRender()
    end
end
script.on_render_event(Defines.RenderEvents.SYSTEM_BOX, 
function(systemBox, ignoreStatus) 
    return Defines.Chain.CONTINUE
end, absorber_render)