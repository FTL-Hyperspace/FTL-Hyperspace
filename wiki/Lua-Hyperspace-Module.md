Available calls

All calls are under `Hyperspace`

-----
- `:Name` indicates it is a member method and must be called with the colon, for example `Hyperspace.ships.player:GetRandomRoomCenter()`
- `.Name` indicates it is a static method or field value and must be called with the period, for example `Hyperspace.ships.enemy.shipId`
-----

- `.ships.player` (See [`ShipManager`](#shipmanager) below)
- `.ships.enemy` (See [`ShipManager`](#shipmanager) below)


## Global

### Methods
- `Global .GetInstance()`
   - Returns the main instance of `Global`. Always use this to access any members and methods belonging to this class.
- `ShipManager :GetShipManager(int iShipId)`
   - Returns the instance of `ShipManager` associated with the given ID (can be 0 or 1). If a ship does not exist for the given ID, returns `nil`.
- `CApp :GetCApp()`
   - Returns the main instance of `CApp`. Always use this to access any members and methods belonging to the `CApp` class.
- `BlueprintManager :GetBlueprints()`
   - Returns the main instance of `BlueprintManager`. Always use this to access any members and methods belonging to the `BlueprintManager` class.
- `SoundControl :GetSoundControl()`
   - Returns the main instance of `SoundControl`. Always use this to access any members and methods belonging to the `SoundControl` class.
- `AnimationControl :GetAnimationControl()`
   - Returns the main instance of `AnimationControl`. Always use this to access any members and methods belonging to the `AnimationControl` class.
- `MouseControl :GetMouseControl()`
   - Returns the main instance of [`MouseControl`](#MouseControl). Always use this to access any members and methods belonging to the [`MouseControl`](#MouseControl) class.

### Fields
- `int` `.currentSeed`
   - **Read-only**
   - The seed for the run.

## MouseControl

### Methods

- `void :InstantTooltip()`
- `Point :MeasureTooltip(int width)`
- `void :OnLoop()`
- `void :OnRender()`
- `void :QueueStaticTooltip(Point pos)`
- `void :RenderTooltip(Point tooltipPoint, bool staticPos)`
- `void :Reset()`
- `void :ResetArmed()`
- `void :SetDoor(int state)`
- `void :SetTooltip(const std::string &tooltip)`
- `void :SetTooltipTitle(const std::string &tooltip)`
	
### Members
- `Point` `.position`
- `Point` `.lastPosition`
- `int` `.aiming_required`
- `int` `.iTeleporting`
- `int` `.iMindControlling`
- `bool` `.bSellingStuff`
- `bool` `.valid`
- `bool` `.newHover`
- `bool` `.lastValid`
- `int` `.animateDoor`
- `GL_Texture*` `.validPointer`
- `GL_Texture*` `.invalidPointer`
- `GL_Texture*` `.selling`
- `Animation` `.openDoor`
- `std::string` `.tooltip`
- `float` `.tooltipTimer`
- `bool` `.bMoving`
- `bool` `.bHideMouse`
- `GL_Texture*` `.lastIcon`
- `GL_Texture*` `.lastAddition`
- `bool` `.bForceTooltip`
- `std::string` `.tooltipTitle`
- `std::string` `.lastTooltipText`
- `int` `.iHacking`
- `int` `.overrideTooltipWidth`
- `Point` `.staticTooltip`



## PrintHelper
The members held by this class determine how the `print` function displays messages.

### Methods
- `PrintHelper .GetInstance()`
   - Returns the main instance of `PrintHelper`. Always use this to access any members belonging to this class.

### Fields
- `int` `.x`
   - The x coordinate of messages. Default is 100.
- `int` `.y`
   - The y coordinate of messages. Default is 100.
- `int` `.font`
   - The size of the font used. Default is 10.
- `int` `.lineLength`
   - Width (in pixels) before automatic newline. Default is 400.
- `int` `.messageLimit`
   - How many messages may be displayed at once. Default is 10.
- `int` `.duration`
   - How long (in seconds) each message lasts. Default is 5.
- `bool` `.useSpeed`
   - Whether the speed at which messages are cleared scales with game speed. Default is `false`.

## ShipObject

### Methods
- `void :AddAugmentation(string augmentName)`
   - Adds the specified augment to the ship. Note that adding hidden augments is bugged right now.
- `void :RemoveAugmentation(string augmentName)`
   - Removes the specified augment from the ship. Does nothing if the augment isn't present. Works properly with hidden augments.
- `void :ClearShipInfo()`
- `int :GetAugmentationCount()`
   - Returns the number of augments on the ship.
- `string[] :GetAugmentationList()`
   - Returns a `std::vector<std::string>` of augments, in Lua you can handle this as if it was an array of strings.
- `float :GetAugmentationValue(string augmentName)`
   - Returns the value of the augment, this corresponds to the value defined in blueprints.xml. If the ship has multiple, their values are added together.
- `int :HasAugmentation(string augmentName)`
   - Returns the number of the given augment you have, NOT a bool.
- ~~`void :AddEquipment(string equipmentName)`~~
- ~~`void :RemoveEquipment(string equipmentName, bool completely)`~~
- `bool :HasEquipment(string equipmentName)`
   - Returns a bool indicating whether you have the blue options for the specified equipment.

## ShipManager
Extends [ShipObject](#shipobject)

As ShipManager extends ShipObject, the methods of ShipObject can be called from ShipManager.

### Methods
- `Pointf :GetRandomRoomCenter()`
   - Chooses a random room on the ship and returns the center point of that room
- `Pointf :GetRoomCenter(int roomId)`
   - Gets the room center point of a specific room id.
- `std::pair<int, int> :GetAvailablePower()`
   - First element of the pair is the maximum reactor power, the second element is the available reactor power.
- ~~`:AddCrewMemberFromBlueprint`~~
- ~~`:AddCrewMemberFromString`~~
- ~~`:AddDrone`~~
- ~~`:AddEquipmentFromList`~~
- ~~`:AddInitialCrew`~~
- `int :AddSystem(int systemId)`
- ~~`int :AddWeapon(WeaponBlueprint weapon, int slot)`~~
- `bool :CanFitSubsystem(int systemId)`
- `bool :CanFitSystem(int systemId)`
- `int :CanUpgrade(int systemId, int amount)`
- `void :ClearStatusAll()`
- `void :ClearStatusSystem(int system)`
- ~~`CollisionResponse :CollisionMoving(Pointf start, Pointf finish, DamageParameter damage, bool raytrace)`~~ (Not yet available, CollisionResponse is not exposed yet)
- ~~`bool :CommandCrewMoveRoom(CrewMember *crew, int roomId)`~~
- `int :CountCrew(bool boarders)`
   - return count of crew on this ship, true for boarders false for regular crewmembers.
- `int :CountCrewShipId(int roomId, int shipId)`
   - Counts crew in a room. shipId corresponds to which ship owns the crewmembers, 0 being the player and 1 being the enemy.
- ~~`CrewDrone* :CreateCrewDrone(const DroneBlueprint *bp)`~~ Use Events
- ~~`SpaceDrone* :CreateSpaceDrone(const DroneBlueprint *bp)`~~ Use Events
- `bool :DamageArea(Pointf location, DamageParameter dmg, bool force)`
   - I think this causes damage to a area like when a projectile hits but it's not tested yet, could possibly be used for bursts?
   - `force` ignores room resistances.
- `bool :DamageBeam(Pointf location1, Pointf location2, DamageParameter dmg)`
   - I think this cuts a beam across the ship but not sure if it renders a beam or not, could possibly be used for bursts?
###### Example
```lua
local damage = Hyperspace.Damage()
damage.iDamage = 1
Hyperspace.ships.player:DamageBeam(Hyperspace.ships.player:GetRandomRoomCenter(), Hyperspace.ships.player:GetRandomRoomCenter(), damage)
```
- ~~`bool :DamageCrew(CrewMember *crew, DamageParameter dmg)`~~
- `int :DamageHull(int amount, bool force)`
   - It directly damages the hull? What's more to say, I think negative numbers heal the hull. Could be cool for some random lifesaving or lifetaking mechanics that run mid-battle instead of during an event. Imagine if you could dump all power into hull integrity or something and lose 10% power for the rest of the fight but gain 10% hull, could be fun!
   - `force` ignores whether or not the ship is jumping. If it is false and the ship is jumping, the damage will not be applied.
- `void :DamageSystem(int systemId, DamageParameter damage)`
- `bool :DoSensorsProvide(int vision)`
   - `vision` is the sensor level.
- `bool :DoorsFunction()`
   - Do the doors work or not
- ~~`CrewMember* :FindCrew(const CrewBlueprint *bp)`~~ Not currently available, might choose never to make available because it might be better to lookup crew by name or something rather than their full CrewBlueprint
- `bool :ForceDecreaseSystemPower(int systemId)`
- `CrewMember* :GetCrewmember(int slot, bool present)`
- `int :GetDodgeFactor()`
- `bool :GetDodged()`
   - Calculates whether a projectile should be dodged or not.
   - Note: 5 calls of this method that return false while the player has fully upgraded, fully powered engines will unlock the achievement 'Astronomically Low Odds'.
- `int :GetDroneCount()`
   - Returns the number of drone parts the ship has.
- [`Drone*[]`](#drone) `:GetDroneList()`
   - Returns the list of Drones for this ship, the `std::vector` it returns can be accessed like an array in Lua
- `int :GetFireCount(int roomId)` Get number of fires in a room, could be quite useful for computing damage of multiple fires
- ~~`std::vector<CrewMember*> :GetLeavingCrew(bool intruders)`~~
- `int :GetOxygenPercentage()` Ship's overall oxygen percentage (not per-room)
- `CrewMember* :GetSelectedCrewPoint(int x, int y, bool intruder)`
- `ShieldPower :GetShieldPower()`
- [`ShipSystem*`](#shipsystem) `:GetSystem(int systemId)`
   - You can also just access the system directly with fields below if it's one of the vanilla systems like `oxygenSystem` `medbaySystem` etc... but custom systems like Temporal currently need to be accessed by id.
- [`ShipSystem*`](#shipsystem) `:GetSystemInRoom(int roomId)`
   - Returns the system in a specific room id. If there is no system in the room, returns 0.
- `int :GetSystemPower(int systemId)`
   - How much power is assigned to this system
- `int :GetSystemPowerMax(int systemId)`
   - What is the max power level of this system, functionally this is the same as the system's "level"
- `int :GetSystemRoom(int systemId)`
   - Find what roomId a system is in, could be useful for AI targeting mechanics or some cheesy player weapon that can only attack one system or something.
- `string :GetTooltip(int x, int y)`
- `ProjectileFactory*[] :GetWeaponList()`
   - Return a vector of weapons on this ship, can be treated like an array in Lua.
- `bool :HasSystem(int systemId)`
   - Does the ship have a specific system, true/false
- `void :InstantPowerShields()`
- `bool :IsCrewFull()`
- `bool :IsCrewOverFull()`
- `int :IsSystemHacked(int systemId)`
   - Returns the "hacking level" of the system. 0 means there is no hacking drone on the system, 1 means there is a hacking drone attached but is not currently being hacked, 2 means there is a hacking drone and the system is being hacked.
- `void :ModifyDroneCount(int drones)`
- `void :ModifyMissileCount(int missiles)`
- `void :ModifyScrapCount(int scrap, bool income)`
   - `income` determines whether or not augments should be activated (e.g. Scrap Recovery Arm and Repair Arm).
- `void :PrepareSuperBarrage()`
   - I do not know if this is safe to call
- `void :PrepareSuperDrones()`
   - I do not know if this is safe to call
- `void :RemoveItem(string name)`
   - Remove an item by name (equivalent to removing via an event).
- `void :ResetScrapLevel()`
- `bool :RestoreCrewPositions()`
   - Same as hitting the button to return crew to their original positions.
- `CrewBlueprint :SelectRandomCrew(int seed, string racePreference)`
   - Select random crew from the ship *for ~~execution~~ selection of your diabolical plans*.
   - Not sure why there is a seed option, not sure if you should give it a fixed number or call `Hyperspace.random32()` for a nice random number.
- `void :SetDestroyed()`
   - *Blow up the damn ship Jean-Luc!*
- `void :SetSystemPowerLoss(int systemId, int powerLoss)`
   - Sets a power loss level, like from an event except can be done at any time regardless of an event.
- `void :StartFire(int roomId)`
   - Yeah, it does *exactly what you think it does* [you monster](https://gfycat.com/complexcarefulant).
- `bool :SystemFunctions(int systemId)`
   - Returns whether the system has any power assigned to it.
- `CrewMember*[] :TeleportCrew(int roomId, bool intruders)`
   - Teleport crew & get back the list of CrewMembers.
   - I think there might be something more you need to do to give them a destination so they don't simply get teleport-ed to space, *unless you know... that was the intention*.

### Fields
- [`Targetable`](#targetable) `._targetable`
   - **Read-only**
- `int` `.iShipId`
   - **Read-only**
   - The ship's ID (0 is player, 1 is enemy)
- [`ShipSystem*[]`](#shipsystem) `.vSystemList`
   - **Read-only** currently, however we might need to explore if this would be a safe way to remove a system
   - Fields under this object may still be mutable (see their docs).
   - Holds a vector (array in lua) of ship systems that you can iterate over
- [`OxygenSystem*`](#oxygensystem) `.oxygenSystem`
   - Field is **read-only** but fields under this object may still be mutable.
- [`TeleportSystem*`](#teleportsystem) `.teleportSystem`
   - Field is **read-only** but fields under this object may still be mutable.
- [`CloakingSystem*`](#cloakingsystem) `.cloakSystem`
   - Field is **read-only** but fields under this object may still be mutable.
- [`BatterySystem*`](#batterysystem) `.batterySystem` Backup Battery System
   - Field is **read-only** but fields under this object may still be mutable.
- [`MindSystem*`](#mindsystem) `.mindSystem` Mind Control System
   - Field is **read-only** but fields under this object may still be mutable.
- [`CloneSystem*`](#clonesystem) `.cloneSystem` Clonebay System
   - **Note:** shares system with Medbay system and both cannot exist at the same time
   - Field is **read-only** but fields under this object may still be mutable.
- [`HackingSystem*`](#hackingsystem) `.hackingSystem`
   - Field is **read-only** but fields under this object may still be mutable.
- [`Shields*`](#shieldsystem) `.shieldSystem`
   - Field is **read-only** but fields under this object may still be mutable.
- [`WeaponSystem*`](#weaponsystem) `.weaponSystem`
   - Field is **read-only** but fields under this object may still be mutable.
- [`DroneSystem*`](#dronesystem) `.droneSystem`
   - Field is **read-only** but fields under this object may still be mutable.
- [`EngineSystem*`](#enginesystem) `.engineSystem`
   - Field is **read-only** but fields under this object may still be mutable.
- [`MedbaySystem*`](#medbaysystem) `.medbaySystem`
   - **Note:** shares system with Clonebay system and both cannot exist at the same time
   - Field is **read-only** but fields under this object may still be mutable.
- [`ArtillerySystem*[]`](#artillerysystem) `.artillerySystems`
   - Array (vector) of artillery systems on this ship, you will need to check for length
   - **Note:** Unlike Lua arrays, because this is a C vector internally it will start at index `0` not index `1` so `.artillerySystems[0]` is the first artillery system.
   - Field is **read-only** but fields under this object may still be mutable.
- ~~`bool` `.showNetwork`~~
   - No clue what this does
- ~~`bool` `.addedSystem`~~
   - No clue what this does
- [`CrewMember*[]`](#crewmember) `.vCrewList`
   - Array (vector) of crew members on this ship
   - **Note:** Vectors are 0 indexed unlike lua's normal arrays
   - Field is **read-only** but fields under this object may still be mutable.
- ~~`Spreader_Fire` `.fireSpreader`~~
- `Ship` `.ship`
   - Field is **read-only** but fields under this object may still be mutable.
- ~~`char` `.statusMessages[80]`~~
- ~~`bool` `.bGameOver`~~
- ~~`ShipManager*` `.current_target`~~ Just use `Hyperspace.ships.enemy` or `Hyperspace.ships.player` depending on the ship you're currently looking at instead.
- `std::pair<float, float>` `.jump_timer`
   - **read-only** (not sure if it's safe to make this editable)
- `int` `.fuel_count`
   - Unlike other resources, fuel is mutable and should be modified directly instead of with a modify method
- ~~`bool` `.hostile_ship`~~
- `bool` `.bDestroyed`
   - **Since 1.4.0**
- `int` `.iLastDamage`
   - **read-only** (not sure if it's safe to make this editable)
- ~~`AnimationTracker` `.jumpAnimation`~~
- ~~`DamageMessage*[]` `.damMessages`~~
   - Is a vector, indexed at 0.
- ~~`int[]` `.systemKey`~~
- `int` `.currentScrap`
   - **read-only** use the modify method if you really want to change this
- `bool` `.bJumping`
   - **read-only**
- `bool` `.bAutomated`
   - **read-only**
- `int` `.shipLevel`
   - **read-only**
- `ShipBlueprint` `.myBlueprint`
   - **read-only**
- `bool` `.lastEngineStatus`
   - **read-only**
- `bool` `.lastJumpReady`
   - **read-only**
- `bool` `.bContainsPlayerCrew`
   - **read-only**
- `int` `.iIntruderCount`
   - **read-only**
- `int[][]` `.crewCounts`
   - Note: Double vector, both indices start at 0
   - Field is **read-only** but fields under this object may still be mutable.
- `int` `.tempDroneCount`
   - **read-only**
- `int` `.tempMissileCount`
   - **read-only**
- ~~`Animation[]` `.explosions`~~
- `bool[]` `.tempVision`
   - **read-only**
   - Note: Vectors start at index 0, unlike normal arrays in Lua
- ~~[`Drone*[]`](#drone) `.droneTrash`~~
- ~~`SpaceDrone*[]` `.spaceDrones`~~
- ~~`SpaceDrone*[]` `.newDroneArrivals`~~
- ~~`int` `.bpCount`~~
- `int` `.iCustomizeMode`
   - **read-only**
   - 2 while in the hangar, 0 while in a run
- `bool` `.bShowRoom`
- `Projectile*[]` `.superBarrage`
   - Note: Vectors start at index 0, unlike normal arrays in Lua
- `bool` `.bInvincible`
- `SpaceDrone*[]` `.superDrones`
   - Note: Vectors start at index 0, unlike normal arrays in Lua
- ~~`GL_Primitive*` `.highlight`~~
- `int` `.failedDodgeCounter`
- ~~`float[]` `.hitByBeam`~~
- `bool` `.enemyDamagedUncloaked`
- `int` `.damageCloaked`
- ~~`std::map<int, int>` `.killedByBeam`~~
- ~~`int` `.minBeaconHealth`~~
- ~~`ParticleEmitter*[]` `.fireExtinguishers`~~
- ~~`bool` `.bWasSafe`~~
- `ShipManager_Extend` `.extend`
  - **Since 1.4.0**
- LUA table `.table`
  - **Since 1.4.0**
  - A modifiable table of arbitrary data which exists and long as the object it belongs to

## Targetable

### Methods
- `Pointf :GetWorldCenterPoint()`
- `Pointf :GetRandomTargettingPoint(bool unk)`
- `std::vector<Pointf> :GetAllTargettingPoints()`
- `Globals::Ellipse :GetShieldShape()`
- `ShieldPower :GetShieldPower()`
- `int :GetSpaceId()`
- `Pointf :GetSpeed()`
- `int :GetOwnerId()`
- `int :GetSelfId()`
- `bool :IsCloaked()`
- `void :DamageTarget(Pointf pos, DamageParameter damage)`
- `bool :GetIsDying()`
- `bool :GetIsJumping()`
- `bool :ValidTarget()`
- `Globals::Rect :GetShape()`

### Fields
- `int` `.type`
- `bool` `.hostile`
- `bool` `.targeted`

## Ship
Extends ShipObject

### Methods

-  `bool :BreachRandomHull(int roomId)`
   -  Breaches a random tile in the room with `roomId` as its id. This can select an already breached tile, in which case nothing will happen.
-  `int :EmptySlots(int roomId)`
   -  Returns the number of tiles within the room (Equivalent to the area of the room). I think this marks all tiles in the room as empty, so you can use this to fit more crew than you should in a given room.
-  `bool :FullRoom(int roomId, bool intruder)`
   -  Returns true if the room cannot fit any more crew of the allegiance specifies by the `intruder` arg. If `intruder` is false, counts player crew when on the player ship, and enemy crew when on the enemy ship. If `intruder` is true, counts enemy crew when on the player ship, and player crew when on the enemy ship.
-  `int :GetAvailableRoomSlot(int roomId, bool intruder)`
-  `Globals::Ellipse GetBaseEllipse()`
   -  Return `baseEllipse` member by value.
- `int GetSelectedRoomId(int x, int y, bool bIncludeWalls)`
   -  Returns the id of the room at the selected point, or -1 if no valid room would be selected at that point. bIncludeWalls specifies that walls count as part of the room.
-  `void LockdownRoom(int roomId, Pointf pos)` 
   -  Locks down the room, and spawns the crystal animation at `pos`. Does not play the lockdown sound. Note: For a "normal" animation, `pos` can be set to the room's center, but it can be set outside of the room as well.
-  `bool RoomLocked(int roomId)`
   -  Returns true if the room is locked down.
-  `void SetRoomBlackout(int roomId, bool blackout)`
   -  When `blackout` is true, hide the room's interior (As if sensors were disabled). When it is false, show the room's interior. Note: This must be done every tick to have an effect.
-  `void SetSelectedRoom(int roomId)`
   -  Sets the room to be selected (Yellow outline). Note: Must be done every tick to have an effect.

### Fields
-  `int` `.iShipId` 
-  `std::vector<Room*>` `.vRoomList`
-  `std::vector<Door*>` `.vDoorList`
-  `std::vector<OuterHull*>` `.vOuterWalls`
-  `std::vector<OuterHull*>` `.vOuterWalls`
-  `std::vector<Door*>` `.vOuterAirlocks`
-  `std::pair<int, int>` `.hullIntegrity`
-  `std::vector<WeaponMount>` `.weaponMounts`
-  `std::string` `.floorImageName`
-  `ImageDesc ` `.shipFloor`
-  `GL_Primitive*` `.floorPrimitive`
-  `std::string` `.shipImageName`
-  `ImageDesc` `.shipImage`
-  `Point` `.glowOffset`
-  `GL_Primitive*` `.shipImagePrimitive`
-  `std::string` `.cloakImageName`
-  `ImageDesc` `.shipImageCloak`
-  `GL_Primitive*` `.cloakPrimitive`
-  `GL_Primitive*` `.gridPrimitive`
-  `GL_Primitive*` `.wallsPrimitive`
-  `GL_Primitive*` `.doorsPrimitive`
-  `std::vector<DoorState>` `.doorState`
-  `bool` `.lastDoorControlMode`
-  `GL_Texture*` `.thrustersImage`
-  `GL_Texture*` `.jumpGlare`
-  `int` `.vertical_shift`
-  `int` `.horizontal_shift`
-  `std::string` `.shipName`
-  `~~ExplosionAnimation` `.explosion`~~
-  `bool` `.bDestroyed`
-  `Globals::Ellipse` `.baseEllipse`
-  `Animation[2]` `.engineAnim`
-  `AnimationTracker` `.cloakingTracker`
-  `bool` `.bCloaked`
-  `bool` `.bExperiment`
-  `bool` `.bShowEngines`
-  ~~`std::vector<LockdownShard>` `.lockdowns`~~
### Hyperspace Fields
-  `std::vector<std::pair<Animation, int8_t>>` 
`extraEngineAnim`
   -  Engine animations defined in Hyperspace for the ship. The first member of the pair is the animation. The second member of the pair is an integer indicating rotation of the animation. 
   
   |Value | Rotation                     |
   | ---: | :--------------------------- |
   | -1   | 90 Degrees Clockwise         |
   |  0   | No Rotation                  |
   |  1   | 90 Degrees Counterclockwise  |

   Note: Pairs are returned by value, and not by reference.
## ShipSystem

### Static methods
These are called either under `Hyperspace.ShipSystem` or an existing object (for example you could call `Hyperspace.ShipSystem.GetLevelDescription(` or `Hyperspace.ships.player.oxygenSystem.GetLevelDescription(` with the same effect (although constructors probably don't make any sense to call in the second manner)
- `Hyperspace.ShipSystem.ShipSystem()` Default Constructor
- ~~`Hyperspace.ShipSystem.ShipSystem(int systemId, int roomId, int shipId, int startingPower)` Constructor~~
- `string .GetLevelDescription(int systemId, int level, bool tooltip)`
- `bool .IsSubsystem(int systemType)`
- `int .NameToSystemId(string name)`
- `string .SystemIdToName(int systemId)`

### Methods
- `void :SetSelected(int selectedState)`
- `int :GetSelected()`
- `bool :CompletelyDestroyed()`
- `string* :GetName()`
- `void :SetName(string name)`
- `void :Repair()`
   - Not sure if this is a function called every tick to cause repairs or what, probably not useful to lua
- `bool :PartialRepair(float speed, bool autoRepair)`
   - Cause a partial repair of a system (opposite of partialDamage) must be called every tick or else you will not see any change
- `bool :PartialDamage(float amount)`
   - Must be called every tick or else you will not see any change
- `bool :NeedsRepairing()`
- `bool :Functioning()`
- `bool :CanBeSabotaged()`
- `float :GetDamage()`
- ~~`Location* :GetLocation()`~~
- ~~`Location* :GetGridLocation()`~~
- `void :SetDamage(float damage)`
- `void :SetMaxDamage(float maxDamage)`
- `void :SetLocation(Point position)`
- `int :GetId()`
- `bool :IsRoomBased()`
- `int :GetRoomId()`
- `bool :Ioned()`
- `void :SetRoomId()`
- `void :SetHackingLevel(int level)`
- `void :ForceBatteryPower(int power)`
- `void :RemoveBatteryPower()`
- ~~`WeaponBlueprint* :GetWeaponInfo()`~~
- ~~`string* :GetOverrideTooltip()`~~
- `void :CheckMaxPower()`
- `void :CheckForRepower()`
  - **Since 1.4.0**
- `void :SetBonusPower(int amount, int permanentPower)`
- `void :AddDamage(int amount)`
- `bool :ForceDecreasePower(int powerLoss)`
- `bool :ForceIncreasePower(int power)`
- `void :StopHacking()`
- `bool :GetNeedsPower()`
- `bool :Clickable()`
- `bool :Powered()`
- ~~`void :ShipDestroyed()`~~
- `void :AddLock(int lock)`
- `void :ClearStatus()`
- `bool :DamageOverTime(float damageIncrement)`
- `bool :DecreasePower(bool force)`
- `int :GetEffectivePower()`
- `bool :GetLocked()`
- `int :GetMaxPower()`
- `int :GetPowerCap()`
- `bool :IncreasePower(int amount, bool force)`
- ~~`bool :Ioned(int num)`~~
- `int :IsMannedBoost()`
- `void :LockSystem(int lock)`
- `void SetPowerCap(int cap)`
- `int SetPowerLoss(int power)`
- `bool UpgradeSystem(int amount)`
   - Upgrading a system is basically the same as changing the max power of a system although I think max power might reset after a jump? Not sure haven't tested.
   - I think negative upgrades (downgrades) are allowed, please report if they are not.

### Fields

- ~~`int` `.selectedState`~~
- ~~`ShipObject` `._shipObj`~~
- `float` `.fDamage`
- `Point` `.pLoc`
- `float` `.fMaxDamage`
- `string` `.name`
- `int` `.roomId`
- `int` `.iRepairCount`
- `int` `.iSystemType`
- `bool` `.bNeedsManned`
- `bool` `.bManned`
- `int` `.iActiveManned`
- `bool` `.bBoostable`
- `std::pair<int, int>` `.powerState`
- `int` `.iRequiredPower`
- ~~`GL_Texture*` `.imageIcon`~~
- ~~`GL_Primitive*` `.iconPrimitive`~~
- ~~`GL_Primitive*` `.iconBorderPrimitive`~~
- ~~`GL_Primitive*` `.iconPrimitives[20]`~~
- ~~`CachedRect` `.partialDamageRect`~~
- ~~`CachedRectOutline` `.lockOutline`~~
- ~~`Globals::Rect` `.roomShape`~~
- `bool` `.bOnFire`
- `bool` `.bBreached`
- `std::pair<int, int>` `.healthState`
- `float` `.fDamageOverTime`
- `float` `.fRepairOverTime`
- `bool` `.damagedLastFrame`
   - I don't know if this can be set to true per-frame to hold the damage over time progression counter, it might be able to freeze the graphic so it doesn't count down.
- `bool` `.repairedLastFrame`
   - I don't know if this can be set to true per-frame to hold the repair over time progression counter, it might be able to freeze the graphic so it doesn't count down.
- `int` `.originalPower`
- `bool` `.bNeedsPower`
- `int` `.iTempPowerCap`
- `int` `.iTempPowerLoss`
- `int` `.iTempDividePower`
- `int` `.iLockCount`
- [`TimerHelper`](#timerhelper) `.lockTimer`
- `bool` `.bExploded`
- `bool` `.bOccupied`
- `bool` `.bFriendlies`
- `string` `.interiorImageName`
- `GL_Primitive*` `.interiorImage`
- `GL_Primitive*` `.interiorImageOn`
- `GL_Primitive*` `.interiorImageManned`
- `GL_Primitive*` `.interiorImageMannedFancy`
- `int` `.lastUserPower`
- `int` `.iBonusPower`
- `int` `.iLastBonusPower`
- `Pointf` `.location`
- `int` `.bpCost`
- [`AnimationTracker`](#animationtracker) `.flashTracker`
- `int` `.maxLevel`
- `int` `.iBatteryPower`
- `int` `.iHackEffect`
- `bool` `.bUnderAttack`
- `bool` `.bLevelBoostable`
- `bool` `.bTriggerIon`
- ~~`std::vector<Animation>` `.damagingEffects`~~
- `int` `.computerLevel`
- `ShipSystem_Extend` `.extend`
  - **Since 1.4.0**
- LUA table `.table`
  - **Since 1.4.0**
  - A modifiable table of arbitrary data which exists and long as the object it belongs to

## ArtillerySystem
**Extends [`ShipSystem`](#shipsystem)**

### Fields
- [`ProjectileFactory*`](#projectilefactory) `.projectileFactory`
- [`Targetable*`](#targetable) `.target`
- `bool` `.bCloaked`

## EngineSystem
**Extends [`ShipSystem`](#shipsystem)**
No additional items over base `ShipSystem`

## MedbaySystem
**Extends [`ShipSystem`](#shipsystem)**
No additional items over base `ShipSystem`

## CloneSystem
**Extends [`ShipSystem`](#shipsystem)**

### Fields
- `float` `.fTimeToClone`
- [`CrewMember*`](#crewmember) `.clone`
- `float` `.fTimeGoal`
- `float` `.fDeathTime`
- `GL_Texture*` `.bottom`
- `GL_Texture*` `.top`
- `GL_Texture*` `.gas`
- `int` `.slot`

## DroneSystem
**Extends [`ShipSystem`](#shipsystem)**

### Methods
- `bool` `:DePowerDrone(Drone* drone, bool unknown)`
- `void` `:RemoveDrone(int slot)`
- `void` `:SetBonusPower(int amount, int permanentPower)`

### Fields
- [`Drone*[]`](#drone) `.drones`
   - Vector starts at index 0 not 1.
- `int` `.drone_count`
- `int` `.drone_start`
- [`Targetable*`](#targetable) `.targetShip`
- `bool[]` `.userPowered`
   - Vector starts at index 0 not 1.
- `int` `.slot_count`
- `int` `.iStartingBatteryPower`
- `bool[]` `.repowerList`
   - Vector starts at index 0 not 1.

## Drone

### Methods
- `void OnInit()`
- `void OnLoop()`
- `void OnDestroy()`
- `void SetPowered(bool _powered)`
- `void SetInstantPowered()`
- `bool GetPowered()`
- `void SetCurrentShip(int shipId)`
- `void SetDeployed(bool _deployed)`
- `void SetDestroyed(bool dead, bool setTimer)`
- `void SetHacked(int level)`
- `bool GetDeployed()`
- `bool NeedsRoom()`
- `void SetSlot(int room, int slot)`
- `bool Destroyed()`
- `Point GetWorldLocation()`
- `void SetWorldLocation(Point point)`
- `Slot *GetDroneSlot(Drone *drone)`
- `int GetDroneHealth()`
- `int GetRequiredPower()`
- `void RenderIcon()`
- `std::string *GetName(Drone *drone)`
- `bool CanBeDeployed()`
- `bool RecallOnJump()`
- `bool CanBeRecovered()`
- `void SaveState(int fh)`
- `void LoadState(int fh)`
- `void BlowUp(bool silent)`
- `bool GetStunned()`

### Fields
- `int` `.iShipId`
   - **Read-only**
- `int` `.selfId`
- `bool` `.powered`
- `int` `.powerRequired`
- `bool` `.deployed`
- `int` `.type`
- [`DroneBlueprint`](#droneblueprint) `.blueprint`
   - **Read-only**
- `bool` `.bDead`
- `int` `.iBonusPower`
- `bool` `.poweredAtLocation`
- `float` `.destroyedTimer`
- `int` `.iHackLevel`
- `float` `.hackTime`

## SpaceDrone
**Extends [`Drone`](#drone)**

### Methods
- `void PickDestination()`
- `void PickTarget()`
- `bool HasTarget()`
- `bool ValidTarget()`
- `float GetWeaponCooldown()`
- `void RandomizeStartingPosition()`
- `bool HideUnderOwner()`
- `Projectile *GetNextProjectile()`
- `void SetMovementTarget(Targetable *target)`
- `void SetWeaponTarget(Targetable *target)`
- `bool ValidTargetObject(Targetable *target)`
- `void OnRender(int space)`
- `void RenderDrone()`
- `std::string *GetTooltip(SpaceDrone *drone)`
- `Pointf GetWorldCenterPoint()`
- `void SetCurrentLocation(Pointf pos)`
- `void MouseMove(int mX, int mY)`
- `Pointf GetRandomTargettingPoint(bool unk)`
- [`Globals::Ellipse`](#globals) `*GetShieldShape(SpaceDrone *drone)`
- `int GetSpaceId()`
- `Pointf GetSpeed()`
- `int GetOwnerId()`
- `int GetSelfId()`
- `CollisionResponse CollisionMoving(Pointf start, Pointf finish, Damage damage, bool raytrace)`
- `bool DamageBeam(Pointf pos1, Pointf pos2, Damage damage)`
- `bool DamageArea(Pointf pos, Damage damage, bool unk)`
- `BoarderDrone *GetBoardingDrone()`
- `void SetDeployed(bool deployed)`
- `float UpdateAimingAngle(Pointf location, float percentage, float forceDesired)`

### Fields
- [`Targetable`](#targetable) `._targetable`
- `Collideable` `._collideable`
- `int` `.currentSpace`
- `int` `.destinationSpace`
- `Pointf` `.currentLocation`
- `Pointf` `.lastLocation`
- `Pointf` `.destinationLocation`
- `Pointf` `.pointTarget`
- `Animation` `.explosion`
- [`Targetable`](#targetable) `.*weaponTarget`
- `Pointf` `.targetLocation`
- `Pointf` `.targetSpeed`
- [`Targetable`](#targetable) `.*movementTarget`
- `Pointf` `.speedVector`
- `bool` `.poweredLastFrame`
- `bool` `.deployedLastFrame`
- `bool` `.bFire`
- `float` `.pause`
- `float` `.additionalPause`
- `float` `.weaponCooldown`
- `float` `.current_angle`
- `float` `.aimingAngle`
- `float` `.lastAimingAngle`
- `float` `.desiredAimingAngle`
- `DamageMessage` `.message`
- `Animation` `.weapon_animation`
- `WeaponBlueprint` `.weaponBlueprint`
   - **Read-only**
- `int` `.lifespan`
- `bool` `.bLoadedPosition`
- `bool` `.bDisrupted`
- `float` `.hackAngle`
- `float` `.ionStun`
- `Pointf` `.beamCurrentTarget`
- `Pointf` `.beamFinalTarget`
- `float` `.beamSpeed`
- `Animation` `.hackSparks`

## DroneBlueprint
**Extends [`Blueprint`](#blueprint)**

### Fields
**All fields are read-only**
- `std::string` `.typeName`
- `int` `.level`
- `int` `.targetType`
- `int` `.power`
- `float` `.cooldown`
- `int` `.speed`
- `int` `.dodge`
- `std::string` `.weaponBlueprint`
- `std::string` `.droneImage`
- `std::string` `.combatIcon`

## CrewStat

### Fields
- `int` `.MAX_HEALTH`
- `int` `.STUN_MULTIPLIER`
- `int` `.MOVE_SPEED_MULTIPLIER`
- `int` `.REPAIR_SPEED_MULTIPLIER`
- `int` `.DAMAGE_MULTIPLIER`
- `int` `.RANGED_DAMAGE_MULTIPLIER`
- `int` `.DOOR_DAMAGE_MULTIPLIER`
- `int` `.FIRE_REPAIR_MULTIPLIER`
- `int` `.SUFFOCATION_MODIFIER`
- `int` `.FIRE_DAMAGE_MULTIPLIER`
- `int` `.OXYGEN_CHANGE_SPEED`
- `int` `.DAMAGE_TAKEN_MULTIPLIER`
- `int` `.CLONE_SPEED_MULTIPLIER`
- `int` `.PASSIVE_HEAL_AMOUNT`
- `int` `.TRUE_PASSIVE_HEAL_AMOUNT`
- `int` `.TRUE_HEAL_AMOUNT`
- `int` `.PASSIVE_HEAL_DELAY`
- `int` `.ACTIVE_HEAL_AMOUNT`
- `int` `.SABOTAGE_SPEED_MULTIPLIER`
- `int` `.ALL_DAMAGE_TAKEN_MULTIPLIER`
- `int` `.HEAL_SPEED_MULTIPLIER`
- `int` `.HEAL_CREW_AMOUNT`
- `int` `.DAMAGE_ENEMIES_AMOUNT`
- `int` `.BONUS_POWER`
- `int` `.POWER_DRAIN`
- `int` `.ESSENTIAL`
- `int` `.CAN_FIGHT`
- `int` `.CAN_REPAIR`
- `int` `.CAN_SABOTAGE`
- `int` `.CAN_MAN`
- `int` `.CAN_TELEPORT`
- `int` `.CAN_SUFFOCATE`
- `int` `.CONTROLLABLE`
- `int` `.CAN_BURN`
- `int` `.IS_TELEPATHIC`
- `int` `.RESISTS_MIND_CONTROL`
- `int` `.IS_ANAEROBIC`
- `int` `.CAN_PHASE_THROUGH_DOORS`
- `int` `.DETECTS_LIFEFORMS`
- `int` `.CLONE_LOSE_SKILLS`
- `int` `.POWER_DRAIN_FRIENDLY`
- `int` `.DEFAULT_SKILL_LEVEL`
- `int` `.POWER_RECHARGE_MULTIPLIER`
- `int` `.HACK_DOORS`
- `int` `.NO_CLONE`
- `int` `.NO_SLOT`
- `int` `.NO_AI`
- `int` `.VALID_TARGET`
- `int` `.CAN_MOVE`
- `int` `.TELEPORT_MOVE`
- `int` `.TELEPORT_MOVE_OTHER_SHIP`
- `int` `.SILENCED`
- `int` `.LOW_HEALTH_THRESHOLD`
- `int` `.NO_WARNING`
- `int` `.CREW_SLOTS`
- `int` `.ACTIVATE_WHEN_READY`
- `int` `.STAT_BOOST`
- `int` `.DEATH_EFFECT`
- `int` `.POWER_EFFECT`
- `int` `.POWER_MAX_CHARGES`
- `int` `.POWER_CHARGES_PER_JUMP`
- `int` `.POWER_COOLDOWN`
- `int` `.TRANSFORM_RACE`

## StatBoostDefinition

### Fields
- `CrewStat` `.stat`
- `float` `.amount`
- `BoostType` `.boostType`
    - Valid values:
        - `Hyperspace.StatBoostDefinition.BoostType.MULT`
        - `Hyperspace.StatBoostDefinition.BoostType.FLAT`
        - `Hyperspace.StatBoostDefinition.BoostType.ADD`
        - `Hyperspace.StatBoostDefinition.BoostType.SET`
        - `Hyperspace.StatBoostDefinition.BoostType.FLIP`
        - `Hyperspace.StatBoostDefinition.BoostType.SET_VALUE`
        - `Hyperspace.StatBoostDefinition.BoostType.MIN`
        - `Hyperspace.StatBoostDefinition.BoostType.MAX`
        - `Hyperspace.StatBoostDefinition.BoostType.REPLACE_GROUP`
        - `Hyperspace.StatBoostDefinition.BoostType.REPLACE_POWER`
- `BoostSource` `.boostSource`
    - Valid values:
        - `Hyperspace.StatBoostDefinition.BoostSource.CREW`
        - `Hyperspace.StatBoostDefinition.BoostSource.AUGMENT`
- `ShipTarget` `.shipTarget`
    - Valid values:
        - `Hyperspace.StatBoostDefinition.ShipTarget.PLAYER_SHIP`
        - `Hyperspace.StatBoostDefinition.ShipTarget.ENEMY_SHIP`
        - `Hyperspace.StatBoostDefinition.ShipTarget.CURRENT_ALL`
        - `Hyperspace.StatBoostDefinition.ShipTarget.CURRENT_ROOM`
        - `Hyperspace.StatBoostDefinition.ShipTarget.OTHER_ALL`
        - `Hyperspace.StatBoostDefinition.ShipTarget.ORIGINAL_SHIP`
        - `Hyperspace.StatBoostDefinition.ShipTarget.ORIGINAL_OTHER_SHIP`
        - `Hyperspace.StatBoostDefinition.ShipTarget.CREW_TARGET`
        - `Hyperspace.StatBoostDefinition.ShipTarget.TARGETS_ME`
        - `Hyperspace.StatBoostDefinition.ShipTarget.ALL`
- `SystemRoomTarget` `.systemRoomTarget`
    - Valid values:
        - `Hyperspace.StatBoostDefinition.SystemRoomTarget.ALL`
        - `Hyperspace.StatBoostDefinition.SystemRoomTarget.NONE`
- `CrewTarget` `.crewTarget`
    - Valid values:
        - `Hyperspace.StatBoostDefinition.CrewTarget.ALLIES`
        - `Hyperspace.StatBoostDefinition.CrewTarget.ENEMIES`
        - `Hyperspace.StatBoostDefinition.CrewTarget.SELF`
        - `Hyperspace.StatBoostDefinition.CrewTarget.ALL`
        - `Hyperspace.StatBoostDefinition.CrewTarget.CURRENT_ALLIES`
        - `Hyperspace.StatBoostDefinition.CrewTarget.CURRENT_ENEMIES`
        - `Hyperspace.StatBoostDefinition.CrewTarget.ORIGINAL_ALLIES`
        - `Hyperspace.StatBoostDefinition.CrewTarget.ORIGINAL_ENEMIES`
- `DroneTarget` `.droneTarget`
    - Valid values:
        - `Hyperspace.StatBoostDefinition.DroneTarget.DRONES`
        - `Hyperspace.StatBoostDefinition.DroneTarget.CREW`
        - `Hyperspace.StatBoostDefinition.DroneTarget.ALL`
- `bool` `.value`
- `std::string` `.stringValue`
- `bool` `.isBool`
- `int` `.priority`
- `float` `.duration`
- `bool` `.jumpClear`
- `bool` `.cloneClear`
- `std::string` `.boostAnim`
- `RoomAnimDef` `.roomAnim`
- `bool` `.affectsSelf`
- `std::vector<std::string>` `.whiteList`
- `std::vector<std::string>` `.blackList`
- `std::vector<std::string>` `.systemRoomReqs`
- `std::vector<std::string>` `.systemList`
- `std::vector<StatBoostDefinition*>` `.providedStatBoosts`
- `ActivatedPowerDefinition` `.powerChange`
- `std::unordered_set<ActivatedPowerDefinition*>` `.powerWhitelist`
- `std::unordered_set<ActivatedPowerDefinition*>` `.powerBlacklist`
- `std::unordered_set<ActivatedPowerDefinition*>` `.powerResourceWhitelist`
- `std::unordered_set<ActivatedPowerDefinition*>` `.powerResourceBlacklist`
- `std::unordered_set<unsigned int>` `.powerGroupWhitelist`
- `std::unordered_set<unsigned int>` `.powerGroupBlacklist`
- `bool` `.hasPowerList`
- `ExplosionDefinition*` `.deathEffectChange`
- `std::vector<float>` `.powerScaling`
- `float` `.powerScalingNoSys`
- `float` `.powerScalingHackedSys`
- `std::vector<int>` `.systemPowerScaling`
- `std::vector<std::pair<CrewExtraCondition, bool>>` `.extraConditions`
- `std::vector<std::pair<CrewExtraCondition, bool>>` `.extraOrConditions`
- `bool` `.extraConditionsReq`
- `bool` `.systemRoomReq`
- `bool` `.isRoomBased`
- `bool` `.functionalTarget`
- `std::pair<float, float>` `.healthReq`
- `std::pair<float, float>` `.healthFractionReq`
- `std::pair<float, float>` `.oxygenReq`
- `std::pair<int, int>` `.fireCount`
- `float` `.dangerRating`
- `int` `.realBoostId`
- `int` `.stackId`
- `int` `.maxStacks`
- `static` `std::vector<StatBoostDefinition*>` `.statBoostDefs`
- `static` `std::unordered_map<std::string, StatBoostDefinition*> ` `.savedStatBoostDefs`

## StatBoostManager

### Methods
- `StatBoostManager .GetInstance()`
    - Returns the main instance of `StatBoostManager`. Always use this to access any members and methods belonging to this class.
- `void :CreateTimedAugmentBoost(StatBoost, CrewMember)`
    - Apply a stat boost to a crew member.
###### Example
```lua
-- Function to apply a 10 second health boost to every crew member on a ship
local def = Hyperspace.StatBoostDefinition()
def.stat = Hyperspace.CrewStat.MAX_HEALTH
def.amount = 100
def.boostType = Hyperspace.StatBoostDefinition.BoostType.FLAT
def.boostSource = Hyperspace.StatBoostDefinition.BoostSource.AUGMENT
def.shipTarget = Hyperspace.StatBoostDefinition.ShipTarget.ALL
def.crewTarget = Hyperspace.StatBoostDefinition.CrewTarget.ALL
def.duration = 10
def.realBoostId = Hyperspace.StatBoostDefinition.statBoostDefs:size()
Hyperspace.StatBoostDefinition.statBoostDefs:push_back(def)
function player_crew_health_boost()
	local crewList = Hyperspace.ships.player.vCrewList
	for i = 0, crewList:size() - 1 do
		local crew = crewList[i]
		Hyperspace.StatBoostManager.GetInstance():CreateTimedAugmentBoost(Hyperspace.StatBoost(def), crew)
	end
end
```

## CrewMember_Extend
Accessed via `CrewMember`'s `.extend` field

### Methods
- `float, bool :CalculateStat(CrewStat)`
    - Returns the current `float` and `bool` value for the given `CrewStat`.
###### Example
```lua
local crew = Hyperspace.ships.player.vCrewList[0]
local maxHealth, _ = crew.extend:CalculateStat(Hyperspace.CrewStat.MAX_HEALTH)
-- This will return maxHealth, false. As this CrewStat is numerical, the value false is discarded.
local _, canMove = crew.extend:CalculateStat(Hyperspace.CrewStat.CAN_MOVE)
-- This will return 0, canMove. Since this is a boolean stat, the value 0 is discarded.
```
- `CrewDefinition* :GetDefinition()`
    - Returns the CrewMember's [`CrewDefinition`](#CrewDefinition)

   
## CrewDefinition
   
### Fields
   NOTE: All fields under this object are immutable.
- `std::string` `.race`
- `std::vector<std::string>` `.deathSounds`
- `std::vector<std::string>` `.deathSoundsFemale`
- `std::vector<std::string>` `.shootingSounds`
- `std::vector<std::string>` `.repairSounds`
- `int` `.repairSoundFrame`
- `bool` `.canFight`
- `bool` `.canRepair`
- `bool` `.canSabotage`
- `bool` `.canMan`
- `bool` `.canTeleport`
- `bool` `.canSuffocate`
- `bool` `.controllable`
- `bool` `.selectable`
- `bool` `.canBurn`
- `int` `.maxHealth`
- `float` `.stunMultiplier`
- `float` `.moveSpeedMultiplier`
- `float` `.repairSpeed`
- `float` `.damageMultiplier`
- `float` `.cloneSpeedMultiplier`
- `float` `.rangedDamageMultiplier`
- `float` `.doorDamageMultiplier`
- `bool` `.providesPower`
- `int` `.bonusPower`
- `float` `.fireRepairMultiplier`
- `float` `.suffocationModifier`
- `bool` `.isTelepathic`
- `bool` `.resistsMindControl`
- `bool` `.isAnaerobic`
- `float` `.fireDamageMultiplier`
- `bool` `.canPhaseThroughDoors`
- `float` `.oxygenChangeSpeed`
- `float` `.damageTakenMultiplier`
- `float` `.passiveHealAmount`
- `float` `.truePassiveHealAmount`
- `float` `.healAmount`
- `float` `.trueHealAmount`
- `int` `.passiveHealDelay`
- `bool` `.detectsLifeforms`
- `bool` `.hasCustomDeathAnimation`
- `bool` `.hasDeathExplosion`
- `std::string` `.animBase`
- `std::string` `.animSheet[2]`
- `float` `.sabotageSpeedMultiplier`
- `float` `.allDamageTakenMultiplier`
- `int` `.defaultSkillLevel`
- `float` `.healSpeed`
- `bool` `.cloneLoseSkills`
- `float` `.healCrewAmount`
- `DroneAI` `.droneAI`
- `bool` `.droneMoveFromManningSlot`
- `int` `.powerDrain`
- `bool` `.powerDrainFriendly`
- `float` `.damageEnemiesAmount`
- `bool` `.hackDoors`
- `float` `.powerRechargeMultiplier`
- `float` `.crewSlots`
- `bool` `.noSlot`
- `bool` `.noClone`
- `bool` `.noAI`
- `bool` `.validTarget`
- `ToggleValue<bool>` `.canPunch`
- `bool` `.canMove`
- `bool` `.snapToSlot`
- `bool` `.teleportMove`
- `bool` `.teleportMoveOtherShip`
- `float` `.essential`
- `bool` `.silenced`
- `float` `.lowHealthThreshold`
- `float` `.lowHealthThresholdPercentage`
- `bool` `.noWarning`
- `std::pair<int,int>` `.shootTimer`
- `std::pair<int,int>` `.punchTimer`
- `ExplosionDefinition` `.explosionDef`
- `std::vector<ActivatedPowerDefinition*>` `.powerDefs`
- `std::vector<StatBoostDefinition*>` `.passiveStatBoosts`
- `std::vector<std::string>` `.nameRace`
- `std::vector<std::string>` `.transformName`
- `bool` `.changeIfSame`
- `SkillsDefinition` `.skillsDef`
## GenericButton

### Methods

- `void :Reset()` 
- `void :SetLocation(Point pos)`
- `void :SetHitBox(Globals::Rect rect)`
- `void :SetActive(bool active)`
- `void :OnLoop()`
- `void :OnRender()`
- `void :MouseMove(int x, int y, bool silent)`
- `void :OnClick()`
- `void :OnRightClick()`
- `void :OnTouch()`
- `void :ResetPrimitives()`

### Fields

- `Point` `.position`
   - Field is **read-only** but fields under this object may still be mutable.
- `Globals::Rect` `.hitbox` 
   - Field is **read-only** but fields under this object may still be mutable.
- `bool` `.allowAnyTouch`
- `bool` `.touchSelectable`
- `bool` `.bRenderOff`
- `bool` `.bRenderSelected`
- `bool` `.bFlashing`
- `AnimationTracker` `.flashing`
- `bool` `.bActive`
- `bool` `.bHover`
- `bool` `.bActivated`
- `bool` `.bSelected`
- `int` `.activeTouch`

## Button

### Methods

**Extends [`GenericButton`](#GenericButton)**
- `void :OnInit(const std::string &img, Point pos)`
- `void :OnRender()`
- `void :SetActiveImage(GL_Texture *texture)`
- `void :SetImageBase(const std::string &imageBase)`
- `void :SetInactiveImage(GL_Texture *texture)`
- `void :SetLocation(const Point pos)`

### Fields
- `GL_Texture*[3]` `.images`
- `GL_Primitive*[3]` `.primitives`
- `Point` `.imageSize`
- `bool` `.bMirror`

## EffectsBlueprint

### Fields
- `std::vector<std::string>` `.launchSounds`
- `std::vector<std::string>` `.hitShipSounds`
- `std::vector<std::string>` `.hitShieldSounds`
- `std::vector<std::string>` `.missSounds`
- `string` `.image`

## LocationEvent

### Fields
- [`TextString`](#TextString) `.text`
- `int` `.environment`
- `int` `.environmentTarget`
- `bool` `.store`
- `bool` `.gap_ex_cleared`
- `int` `.fleetPosition`
- `bool` `.beacon`
- `bool` `.reveal_map`
- `bool` `.distressBeacon`
- `bool` `.repair`
- `int` `.modifyPursuit`
- `std::string` `.quest`
- `std::string` `.spaceImage`
- `std::string` `.planetImage`
- `std::string` `.eventName`
- [`BoardingEvent`](#BoardingEvent) `.boarders`
- `int` `.unlockShip`
- [`TextString`](#TextString) `.unlockShipText`
- `bool` `.secretSector`
- [`std::vector<Choice>`](#Choice) `.choices`

## Choice

**Internal Struct Of [`LocationEvent`](#LocationEvent)**

### Fields
- [`LocationEvent`](#LocationEvent) `.event`
- [`TextString`](#TextString) `.text`
- `bool` `.hiddenReward`

## FocusWindow

### Fields
- `bool` `.bOpen`
- `bool` `.bFullFocus`
- `bool` `.bCloseButtonSelected`

## ChoiceBox

**Extends [`FocusWindow`](#FocusWindow)**

### Fields
- `std::string` `.mainText`
- [`std::vector<ChoiceText>`](#ChoiceText) `.choices`
- `int` `.columnSize`
- [`std::vector<Globals::Rect>`](#Globals) `.choiceBoxes`
- `int` `.potentialChoice`
- `int` `.selectedChoice`
- `int` `.fontSize`
- `bool` `.centered`
- `int` `.gap_size`
- `float` `.openTime`
- [`GL_Color`](#GL_Color) `.currentTextColor`
- `Pointf` `.lastChoice`

## ChoiceText

### Fields
- `int` `.type`
- `std::string` `.text`

## CommandGui

### Fields
- [`ShipStatus`](#ShipStatus) `.shipStatus`
- [`CrewControl`](#CrewControl) `.crewControl`
- [`SystemControl`](#SystemControl) `.sysControl`
- [`CombatControl`](#CombatControl) `.combatControl`
- [`FTLButton`](#FTLButton) `.ftlButton`
- [`SpaceStatus`](#SpaceStatus) `.spaceStatus`
- [`Point`](#Point) `.pauseTextLoc`
- [`Point`](#Point) `.shipPosition`
- `bool` `.outOfFuel`
   - **Read-Only**
- `bool` `.bPaused`
   - **Read-Only**
- `bool` `.bAutoPaused`
   - **Read-Only**
- `bool` `.menu_pause`
   - **Read-Only**
- `bool` `.event_pause`
   - **Read-Only**
- `Button` `.upgradeButton`
   - **Read-Only**
- `bool` `.dangerLocation`
   - **Read-Only**`
- `bool` `.bHideUI`
- [`ChoiceBox`](#ChoiceBox) `.choiceBox`
- `bool` `.jumpComplete`
   - **Read-Only**
- `int` `.mapId`
   - **Read-Only**
- `bool` `.secretSector`
   - **Read-Only**
- `bool` `.choiceBoxOpen`
   - **Read-Only**

## TextString

### Method
- `std::string :GetText()`

### Fields
- `bool` `.data`
- `uint8_t` `.isLiteral`